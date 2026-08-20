
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32

#define FULL_MASK 0xffffffff

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#include "scale_compat.h"
#include "pushJ_vlo_split.cuh"
#define IDX_LOCAL_XLEN 1
__global__ void cuda_geo_nr_Bfield_pushJ_vlo(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR int *xoffset, __DDR int *yoffset,
    __DDR int *zoffset, __DDR double *fieldE, __DDR double *fieldB,
    __DDR double *fieldB1, __DDR double *FoutJ, long XLEN, long YLEN, long ZLEN,
    int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0,
    double zmid) {

  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  long numgrid = (XLEN * (YLEN * ZLEN));

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  __shared__ double shE0[375];
  __shared__ double shB0[375];
  __shared__ double shB1[375];
  __shared__ double shJ0[375];
  __shared__ v8fp64 shJ_incf_simdp[375];
  __shared__ pushJ_vlo_state_t st;
  __shared__ v8fp64 leaf_scr[PUSHJ_LEAF_SCRATCH_LEN];
  using barrier_t = SCALE::barrier<cuda::thread_scope_block>;
  __shared__ barrier_t bar;
  if (__idx == 0) {
    init(&bar, static_cast<std::size_t>(__xlen));
  }
  __syncthreads();
  auto block = cooperative_groups::this_thread_block();
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      long load0 = 1;

      (use_local_particle_position = 1);
      if (load0) {

        long i_idy = __idy;

        double XO = (xoffset)[i_idy];

        double YO = (yoffset)[i_idy];

        double ZO = (zoffset)[i_idy];

        double Midx =
            ((use_local_particle_position)
                 ? (floor(((cu_cache +
                            ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[0]))
                 : (mdx));

        double Midy =
            ((use_local_particle_position)
                 ? (floor(((cu_cache +
                            ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[1]))
                 : (mdy));

        double Midz =
            ((use_local_particle_position)
                 ? (floor(((cu_cache +
                            ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[2]))
                 : (mdz));

        if (Midx < 0) {
          (Midx = 0);
        }

        if (Midy < 0) {
          (Midy = 0);
        }

        if (Midz < 0) {
          (Midz = 0);
        }

        if (Midx > (XLEN - 1)) {
          (Midx = (XLEN - 1));
        }

        if (Midy > (YLEN - 1)) {
          (Midy = (YLEN - 1));
        }

        if (Midz > (ZLEN - 1)) {
          (Midz = (ZLEN - 1));
        }

        int bBidx = (Midx - 2);

        int bBidy = (Midy - 2);

        int bBidz = (Midz - 2);

        double QE_MASS = (Charge0 / Mass0);

        double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

        double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

        double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));
        __DDR double *particle_buf =
            (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6)));
        pushJ_vlo_K1_load_shared_5x5x5(shE0, shB0, shB1, shJ0, fieldE, fieldB,
                                       fieldB1, FoutJ, __idy, __idx, __xlen,
                                       bBidx, bBidy, bBidz, XLEN, YLEN, ZLEN,
                                       ovlp, num_ele, block, bar);
        pushJ_vlo_zero_shJ_incf(shJ_incf_simdp);
        {
          int g_inner;

          for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 8))) {
            pushJ_vlo_K1_setup_weights_x0x1(&st, particle_buf, g_inner, load0,
                                            Midx, Midy, Midz, Deltat);
            pushJ_vlo_K2_push_weights_x2x3(leaf_scr, &st, shE0, shB0, shB1,
                                           DELTA_X, DELTA_Y, DELTA_Z, Deltat,
                                           Tori_X0, QE_MASS, XO, YO, ZO, zmid,
                                           Midx, Midy, Midz);
            pushJ_vlo_K3_deposit_writeback_particle(
                leaf_scr, &st, shJ_incf_simdp, particle_buf, Deltat, g_inner,
                load0, Charge0, Tori_X0, grid_geo_x, grid_geo_y, grid_geo_z,
                XO, YO, ZO, zmid, bBidx, bBidy, bBidz);
          }
        }
        pushJ_vlo_collapse_shJ_incf_to_shJ0(shJ0, shJ_incf_simdp);
        __syncthreads();
        pushJ_vlo_K3_write_FoutJ_from_shared(shJ0, FoutJ, __idy, __idx, __xlen,
                                             bBidx, bBidy, bBidz, XLEN, YLEN,
                                             ZLEN, ovlp, num_ele, block, bar);
      }
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      int load0 = new_load_tmp;

      int new_load = new_load_tmp;

      if (load0) {

        long i_idy = __idy;

        double XO = (xoffset)[i_idy];

        double YO = (yoffset)[i_idy];

        double ZO = (zoffset)[i_idy];

        double Midx =
            ((use_local_particle_position)
                 ? (floor(((inoutput + (grid_base_offset +
                                        (6 * (allgid * grid_cache_len)))))[0]))
                 : (mdx));

        double Midy =
            ((use_local_particle_position)
                 ? (floor(((inoutput + (grid_base_offset +
                                        (6 * (allgid * grid_cache_len)))))[1]))
                 : (mdy));

        double Midz =
            ((use_local_particle_position)
                 ? (floor(((inoutput + (grid_base_offset +
                                        (6 * (allgid * grid_cache_len)))))[2]))
                 : (mdz));

        if (Midx < 0) {
          (Midx = 0);
        }

        if (Midy < 0) {
          (Midy = 0);
        }

        if (Midz < 0) {
          (Midz = 0);
        }

        if (Midx > (XLEN - 1)) {
          (Midx = (XLEN - 1));
        }

        if (Midy > (YLEN - 1)) {
          (Midy = (YLEN - 1));
        }

        if (Midz > (ZLEN - 1)) {
          (Midz = (ZLEN - 1));
        }

        int bBidx = (Midx - 2);

        int bBidy = (Midy - 2);

        int bBidz = (Midz - 2);

        double QE_MASS = (Charge0 / Mass0);

        double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

        double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

        double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));
        __DDR double *particle_buf =
            (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len))));
        pushJ_vlo_K1_load_shared_5x5x5(shE0, shB0, shB1, shJ0, fieldE, fieldB,
                                       fieldB1, FoutJ, __idy, __idx, __xlen,
                                       bBidx, bBidy, bBidz, XLEN, YLEN, ZLEN,
                                       ovlp, num_ele, block, bar);
        pushJ_vlo_zero_shJ_incf(shJ_incf_simdp);
        {
          int g_inner;

          for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 8))) {
            pushJ_vlo_K1_setup_weights_x0x1(&st, particle_buf, g_inner, load0,
                                            Midx, Midy, Midz, Deltat);
            pushJ_vlo_K2_push_weights_x2x3(leaf_scr, &st, shE0, shB0, shB1,
                                           DELTA_X, DELTA_Y, DELTA_Z, Deltat,
                                           Tori_X0, QE_MASS, XO, YO, ZO, zmid,
                                           Midx, Midy, Midz);
            pushJ_vlo_K3_deposit_writeback_particle(
                leaf_scr, &st, shJ_incf_simdp, particle_buf, Deltat, g_inner,
                load0, Charge0, Tori_X0, grid_geo_x, grid_geo_y, grid_geo_z,
                XO, YO, ZO, zmid, bBidx, bBidy, bBidz);
          }
        }
        pushJ_vlo_collapse_shJ_incf_to_shJ0(shJ0, shJ_incf_simdp);
        __syncthreads();
        pushJ_vlo_K3_write_FoutJ_from_shared(shJ0, FoutJ, __idy, __idx, __xlen,
                                             bBidx, bBidy, bBidz, XLEN, YLEN,
                                             ZLEN, ovlp, num_ele, block, bar);
      }

      if (load0 != new_load) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);
      }
    }
  }
}

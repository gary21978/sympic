#define IDX_OPT_MAX 1
#ifndef _MAPU_SIMD_BASE_FUN
#define _MAPU_SIMD_BASE_FUN
static __device__ KERNEL_M KERNEL_S double mapu_log_df(double p) {
  long long s = p;
  if (s < p) {
    return s;
  } else {
    return s + 1;
  }
}

static __device__ KERNEL_M KERNEL_S double mapu_floor_df(double p) {
  long long s = (long long)p;
  return (s > p) ? (double)(s - 1) : (double)s;
}

__device__ static KERNEL_M v8fp64 v8fp64_setr(double a0, double a1, double a2,
                                              double a3, double a4, double a5,
                                              double a6, double a7) {

  v8fp64 ret = {a0, a1, a2, a3, a4, a5, a6, a7};
  return ret;
}
#define floor mapu_floor_df
#define log mapu_log_df
__device__ static KERNEL_M v8fp64 geo_floor_simd(v8fp64 input) {
  v8fp64 ret;
  double *pret = (double *)&(ret);
  double *pinput = (double *)&(input);
  int g;
  for ((g = 0); (g < 8); (g = (g + 1))) {
    ((pret)[g] = floor((pinput)[g]));
  }
  return ret;
}
#endif
#define IDX_OPT_MAX 1
#include <stdio.h>
static int mapu_counter_for_debug = 0;
__device__ static int mapu_isfinite_o(double input) { return 1; }
__device__ static double mapu_rand01_k(double x0, double x1) { return 0; }
__device__ static double mapu_maxwell_dist_k(double ava, double sig) {
  return 0;
}

__global__ void mapu_dump_ene_num(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR double *fieldE, __DDR double *fieldB,
    __DDR double *FoutJ, __DDR double *FoutEN, MAPU_LONG XLEN, MAPU_LONG YLEN,
    MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec, int num_ele,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length, double Mass,
    double Charge, int SPEC, int NUM_SPEC, double DELTA_X, double DELTA_Y,
    double DELTA_Z, double Deltat) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG pscmc_compute_unit_id = 0;
  const MAPU_LONG pscmc_num_compute_units = 1;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));

#ifdef __PSCMC_TIMER_PROF
  __mem1__ MAPU_LONG __pscmc_clock_default;
  __pscmc_clock_default = 0;
  __mem1__ MAPU_LONG __pscmc_clock_pushJ_shJ;
  __pscmc_clock_pushJ_shJ = 0;

#else
  0;

#endif

#ifdef __PSCMC_TIMER_PROF
  __mem1__ MAPU_LONG __pscmc_clock_tmp_default;
  __pscmc_clock_tmp_default = clock64();

#else
  0;

#endif
  __mem1__ MAPU_LONG numgrid;
  numgrid = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG numallgrid;
  numallgrid = ((XLEN + (ovlp + ovlp)) *
                ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));
  __mem1__ MAPU_LONG blk_len;
  blk_len = (numallgrid * num_ele);
  __mem1__ MAPU_LONG blk_len_x;
  blk_len_x = (XLEN + (ovlp + ovlp));
  __mem1__ MAPU_LONG blk_len_y;
  blk_len_y = (YLEN + (ovlp + ovlp));
  __mem1__ MAPU_LONG blk_len_z;
  blk_len_z = (ZLEN + (ovlp + ovlp));
  __mem1__ MAPU_LONG numgrid_cu;
  numgrid_cu = (numgrid * numvec);
  __mem1__ MAPU_LONG grid_base_offset;
  grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));
  __shared__ barrier_t cuload_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(cuload_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  } else {
    {
      0;
    }
  }
  __shared__ barrier_t get_sync_block_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_block_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  } else {
    {
      0;
    }
  }
  __mem1__ int cu_load;
  cu_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ int call_sort;
  call_sort = 1;
  __mem1__ int cr_allgid;
  cr_allgid = 0;
  __mem1__ int use_local_particle_position;
  use_local_particle_position = 1;
  __mem1__ int mdx;
  __mem1__ int mdy;
  __mem1__ int mdz;
  __mem0__ double enevec[IDX_OPT_MAX * 3];
  __mem0__ double avvvec[IDX_OPT_MAX * 3];
  __mem0__ int numcpvec[IDX_OPT_MAX];
  {
    __mem1__ MAPU_LONG l1;
    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      __mem1__ MAPU_LONG load0;
      load0 = 1;
      __mem1__ MAPU_LONG new_load;
      new_load = load0;
      const MAPU_LONG global_idy_tmp = __idy;
      (use_local_particle_position = 1);

      if (load0) {
        {
          __mem1__ int Midx;
          Midx = ((use_local_particle_position) ? (({
            floor(
                ((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[0]);
          }))
                                                : (({ mdx; })));
          __mem1__ int Midy;
          Midy = ((use_local_particle_position) ? (({
            floor(
                ((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[1]);
          }))
                                                : (({ mdy; })));
          __mem1__ int Midz;
          Midz = ((use_local_particle_position) ? (({
            floor(
                ((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[2]);
          }))
                                                : (({ mdz; })));
          __mem1__ MAPU_LONG lg;
          lg = 0;
          __mem1__ double allene0_x;
          allene0_x = 0.00000000000000000e+00;
          __mem1__ double allene0_y;
          allene0_y = 0.00000000000000000e+00;
          __mem1__ double allene0_z;
          allene0_z = 0.00000000000000000e+00;
          __mem1__ double allavv_x;
          allavv_x = 0.00000000000000000e+00;
          __mem1__ double allavv_y;
          allavv_y = 0.00000000000000000e+00;
          __mem1__ double allavv_z;
          allavv_z = 0.00000000000000000e+00;
          __mem1__ int allnumcp;
          allnumcp = 0;
          {
            __mem1__ MAPU_LONG g;
            for ((g = 0); (g < 3); (g = (g + 1))) {
              ((enevec)[(g + (3 * __idx))] = 0);
              ((avvvec)[(g + (3 * __idx))] = 0);
            }
          }
          ((numcpvec)[(1 * __idx)] = 0);
          for (0; (((__idx * 64) + lg) < load0); (lg = (lg + (__xlen * 64)))) {
            __mem0__ double a_rva[(64 * 6)];
            __mem1__ int __idx_all_base;
            __idx_all_base = ((__idx * 64) + lg);
            __mem1__ int numcp;
            numcp = ((((__idx_all_base + 64) >= load0))
                         ? (({ (load0 - __idx_all_base); }))
                         : (({ 64; })));

            if ((numcp * 6)) {
              {
                const size_t data_size = sizeof((
                    ((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))) +
                     (__idx_all_base * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(a_rva + (0 * 6))),
                    ((__DDR unsigned *)((cu_cache +
                                         ((__idy * (6 * cu_cache_length)) +
                                          (l1 * 6))) +
                                        (__idx_all_base * 6))),
                    ((uint64_t)(6 * (numcp * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            } else {
              {
                0;
              }
            }
            __mem1__ double ene0_x;
            ene0_x = 0.00000000000000000e+00;
            __mem1__ double ene0_y;
            ene0_y = 0.00000000000000000e+00;
            __mem1__ double ene0_z;
            ene0_z = 0.00000000000000000e+00;
            __mem1__ double aver_vx;
            aver_vx = 0.00000000000000000e+00;
            __mem1__ double aver_vy;
            aver_vy = 0.00000000000000000e+00;
            __mem1__ double aver_vz;
            aver_vz = 0.00000000000000000e+00;
            {
              __mem1__ MAPU_LONG g;
              for ((g = 0); (g < numcp); (g = (g + 1))) {
                __mem1__ double vx;
                vx = ((a_rva + (g * 6)))[3];
                __mem1__ double vy;
                vy = ((a_rva + (g * 6)))[4];
                __mem1__ double vz;
                vz = ((a_rva + (g * 6)))[5];
                __mem1__ double curene_x;
                curene_x = (Mass * (5.00000000000000000e-01 * +((vx * vx))));
                __mem1__ double curene_y;
                curene_y = (Mass * (5.00000000000000000e-01 * +((vy * vy))));
                __mem1__ double curene_z;
                curene_z = (Mass * (5.00000000000000000e-01 * +((vz * vz))));
                (ene0_x = (ene0_x + curene_x));
                (ene0_y = (ene0_y + curene_y));
                (ene0_z = (ene0_z + curene_z));
                (aver_vx = (aver_vx + vx));
                (aver_vy = (aver_vy + vy));
                (aver_vz = (aver_vz + vz));
              }
            }
            ((enevec)[(3 * __idx)] = ((enevec)[(3 * __idx)] + ene0_x));
            ((enevec)[((3 * __idx) + 1)] =
                 ((enevec)[((3 * __idx) + 1)] + ene0_y));
            ((enevec)[((3 * __idx) + 2)] =
                 ((enevec)[((3 * __idx) + 2)] + ene0_z));
            ((avvvec)[(3 * __idx)] = ((avvvec)[(3 * __idx)] + aver_vx));
            ((avvvec)[((3 * __idx) + 1)] =
                 ((avvvec)[((3 * __idx) + 1)] + aver_vy));
            ((avvvec)[((3 * __idx) + 2)] =
                 ((avvvec)[((3 * __idx) + 2)] + aver_vz));
            ((numcpvec)[__idx] = ((numcpvec)[__idx] + numcp));
          }
          if ((__idx == 0)) {
            {
              {
                __mem1__ MAPU_LONG g;
                for ((g = 0); (g < __xlen); (g = (g + 1))) {
                  (allene0_x = (allene0_x + (enevec)[((3 * g) + 0)]));
                  (allene0_y = (allene0_y + (enevec)[((3 * g) + 1)]));
                  (allene0_z = (allene0_z + (enevec)[((3 * g) + 2)]));
                  (allavv_x = (allavv_x + (avvvec)[((3 * g) + 0)]));
                  (allavv_y = (allavv_y + (avvvec)[((3 * g) + 1)]));
                  (allavv_z = (allavv_z + (avvvec)[((3 * g) + 2)]));
                  (allnumcp = (allnumcp + (numcpvec)[g]));
                }
              }
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[0] += (allene0_x));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[1] += (allene0_y));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[2] += (allene0_z));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[3] += (allavv_x));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[4] += (allavv_y));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[5] += (allavv_z));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[6] += (allnumcp));
            }
          }
        }
      }
    }
  }
  {
    __mem1__ MAPU_LONG allgid;
    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      __mem1__ int new_load_tmp;
      new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];
      __mem1__ MAPU_LONG c_gid;
      c_gid = allgid;
      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      __mem1__ int load0;
      load0 = new_load_tmp;
      __mem1__ int new_load;
      new_load = new_load_tmp;
      const MAPU_LONG global_idy_tmp = __idy;

      if (load0) {
        {
          __mem1__ int Midx;
          Midx = ((use_local_particle_position) ? (({
            floor(((inoutput +
                    (grid_base_offset + (6 * (allgid * grid_cache_len)))))[0]);
          }))
                                                : (({ mdx; })));
          __mem1__ int Midy;
          Midy = ((use_local_particle_position) ? (({
            floor(((inoutput +
                    (grid_base_offset + (6 * (allgid * grid_cache_len)))))[1]);
          }))
                                                : (({ mdy; })));
          __mem1__ int Midz;
          Midz = ((use_local_particle_position) ? (({
            floor(((inoutput +
                    (grid_base_offset + (6 * (allgid * grid_cache_len)))))[2]);
          }))
                                                : (({ mdz; })));
          __mem1__ MAPU_LONG lg;
          lg = 0;
          __mem1__ double allene0_x;
          allene0_x = 0.00000000000000000e+00;
          __mem1__ double allene0_y;
          allene0_y = 0.00000000000000000e+00;
          __mem1__ double allene0_z;
          allene0_z = 0.00000000000000000e+00;
          __mem1__ double allavv_x;
          allavv_x = 0.00000000000000000e+00;
          __mem1__ double allavv_y;
          allavv_y = 0.00000000000000000e+00;
          __mem1__ double allavv_z;
          allavv_z = 0.00000000000000000e+00;
          __mem1__ int allnumcp;
          allnumcp = 0;
          {
            __mem1__ MAPU_LONG g;
            for ((g = 0); (g < 3); (g = (g + 1))) {
              ((enevec)[(g + (3 * __idx))] = 0);
              ((avvvec)[(g + (3 * __idx))] = 0);
            }
          }
          ((numcpvec)[(1 * __idx)] = 0);
          for (0; (((__idx * 64) + lg) < load0); (lg = (lg + (__xlen * 64)))) {
            __mem0__ double a_rva[(64 * 6)];
            __mem1__ int __idx_all_base;
            __idx_all_base = ((__idx * 64) + lg);
            __mem1__ int numcp;
            numcp = ((((__idx_all_base + 64) >= load0))
                         ? (({ (load0 - __idx_all_base); }))
                         : (({ 64; })));

            if ((numcp * 6)) {
              {
                const size_t data_size =
                    sizeof((((inoutput + (grid_base_offset +
                                          (6 * (allgid * grid_cache_len)))) +
                             (__idx_all_base * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(a_rva + (0 * 6))),
                    ((__DDR unsigned *)((inoutput +
                                         (grid_base_offset +
                                          (6 * (allgid * grid_cache_len)))) +
                                        (__idx_all_base * 6))),
                    ((uint64_t)(6 * (numcp * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            } else {
              {
                0;
              }
            }
            __mem1__ double ene0_x;
            ene0_x = 0.00000000000000000e+00;
            __mem1__ double ene0_y;
            ene0_y = 0.00000000000000000e+00;
            __mem1__ double ene0_z;
            ene0_z = 0.00000000000000000e+00;
            __mem1__ double aver_vx;
            aver_vx = 0.00000000000000000e+00;
            __mem1__ double aver_vy;
            aver_vy = 0.00000000000000000e+00;
            __mem1__ double aver_vz;
            aver_vz = 0.00000000000000000e+00;
            {
              __mem1__ MAPU_LONG g;
              for ((g = 0); (g < numcp); (g = (g + 1))) {
                __mem1__ double vx;
                vx = ((a_rva + (g * 6)))[3];
                __mem1__ double vy;
                vy = ((a_rva + (g * 6)))[4];
                __mem1__ double vz;
                vz = ((a_rva + (g * 6)))[5];
                __mem1__ double curene_x;
                curene_x = (Mass * (5.00000000000000000e-01 * +((vx * vx))));
                __mem1__ double curene_y;
                curene_y = (Mass * (5.00000000000000000e-01 * +((vy * vy))));
                __mem1__ double curene_z;
                curene_z = (Mass * (5.00000000000000000e-01 * +((vz * vz))));
                (ene0_x = (ene0_x + curene_x));
                (ene0_y = (ene0_y + curene_y));
                (ene0_z = (ene0_z + curene_z));
                (aver_vx = (aver_vx + vx));
                (aver_vy = (aver_vy + vy));
                (aver_vz = (aver_vz + vz));
              }
            }
            ((enevec)[(3 * __idx)] = ((enevec)[(3 * __idx)] + ene0_x));
            ((enevec)[((3 * __idx) + 1)] =
                 ((enevec)[((3 * __idx) + 1)] + ene0_y));
            ((enevec)[((3 * __idx) + 2)] =
                 ((enevec)[((3 * __idx) + 2)] + ene0_z));
            ((avvvec)[(3 * __idx)] = ((avvvec)[(3 * __idx)] + aver_vx));
            ((avvvec)[((3 * __idx) + 1)] =
                 ((avvvec)[((3 * __idx) + 1)] + aver_vy));
            ((avvvec)[((3 * __idx) + 2)] =
                 ((avvvec)[((3 * __idx) + 2)] + aver_vz));
            ((numcpvec)[__idx] = ((numcpvec)[__idx] + numcp));
          }
          if ((__idx == 0)) {
            {
              {
                __mem1__ MAPU_LONG g;
                for ((g = 0); (g < __xlen); (g = (g + 1))) {
                  (allene0_x = (allene0_x + (enevec)[((3 * g) + 0)]));
                  (allene0_y = (allene0_y + (enevec)[((3 * g) + 1)]));
                  (allene0_z = (allene0_z + (enevec)[((3 * g) + 2)]));
                  (allavv_x = (allavv_x + (avvvec)[((3 * g) + 0)]));
                  (allavv_y = (allavv_y + (avvvec)[((3 * g) + 1)]));
                  (allavv_z = (allavv_z + (avvvec)[((3 * g) + 2)]));
                  (allnumcp = (allnumcp + (numcpvec)[g]));
                }
              }
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[0] += (allene0_x));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[1] += (allene0_y));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[2] += (allene0_z));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[3] += (allavv_x));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[4] += (allavv_y));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[5] += (allavv_z));
              (((FoutEN +
                 ((((NUM_SPEC * 7) *
                    (__idy * ((XLEN + (2 * ovlp)) *
                              ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                   (0 +
                    ((NUM_SPEC * 7) *
                     ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                       ((Midy + ovlp) + ((YLEN + (2 * ovlp)) *
                                                         (Midz + ovlp)))))))) +
                  (SPEC * 7))))[6] += (allnumcp));
            }
          }
        }
      }

      if ((load0 != new_load)) {
        {
          ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);
        }
      }
    }
  }
#ifdef __PSCMC_TIMER_PROF
  (__pscmc_clock_default =
       (__pscmc_clock_default + (clock64() - __pscmc_clock_tmp_default)));

#else
  0;

#endif

#ifdef __PSCMC_TIMER_PROF

  if ((__global_idx == 0)) {
    {
      printf("default %f\n",
             ((__pscmc_clock_default * 1.00000000000000000e+00) / 1));
    }
  }

  if ((__global_idx == 0)) {
    {
      printf("pushJ_shJ %f\n",
             ((__pscmc_clock_pushJ_shJ * 1.00000000000000000e+00) /
              __pscmc_clock_default));
    }
  }

#else
  0;

#endif

#endif
}

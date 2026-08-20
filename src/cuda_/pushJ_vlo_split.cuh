/* pushJ_vlo K1 split - extracted from cuda_geo_nr_Bfield_pushJ_vlo Pass A */
#ifndef PUSHJ_VLO_SPLIT_CUH
#define PUSHJ_VLO_SPLIT_CUH

#include "scale_compat.h"

#ifndef IDX_LOCAL_XLEN
#define IDX_LOCAL_XLEN 1
#endif
#ifndef PUSHJ_LEAF_SCRATCH_LEN
#define PUSHJ_LEAF_SCRATCH_LEN 20
#endif
#ifndef FULL_MASK
#define FULL_MASK 0xffffffffu
#endif

#include "pushJ_weights.cuh"

typedef struct {
  v8fp64 simd_mask;
  v8fp64 xx1, xy1, xz1, vx0, vy0, vz0;
  v8fp64 xx0, xy0, xz0;
  v8fp64 s_rx0x, s_rx0y, s_rx0z, s_rx1x, s_rx1y, s_rx1z;
  v8fp64 s_rx2x, s_rx2y, s_rx2z, s_rx3x, s_rx3y, s_rx3z;
  v8fp64 s_dix0x, s_dix0y, s_dix0z, s_dix1x, s_dix1y, s_dix1z;
  v8fp64 s_dix2x, s_dix2y, s_dix2z, s_dix3x, s_dix3y, s_dix3z;
  v8fp64 x2, y2, z2, x3, y3, z3;
} pushJ_vlo_state_t;


static __device__ __noinline__ void
pushJ_vlo_deposit_Jx12(v8fp64 *scr, v8fp64 rx1x, v8fp64 dix1x, v8fp64 rx2x,
                       v8fp64 dix2x, v8fp64 rx1y, v8fp64 dix1y, v8fp64 rx1z,
                       v8fp64 dix1z, v8fp64 simd_mask, v8fp64 *shJ_incf,
                       double grid_geo_x, double Charge0, double Tori_X0,
                       double XO, int bBidx) {
  v8fp64 *if1_x1 = scr + 0;
  v8fp64 *if1_x2 = scr + 5;
  v8fp64 *f0_y1 = scr + 10;
  v8fp64 *f0_z1 = scr + 15;
  eval_if1(rx1x, dix1x, if1_x1);
  eval_if1(rx2x, dix2x, if1_x2);
  eval_f0(rx1y, dix1y, f0_y1);
  eval_f0(rx1z, dix1z, f0_z1);
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (simd_mask * (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                    ((f0_y1)[xyzy] * (f0_z1)[xyzz])));
        shJ_incf[((allidx * 3) + 0)] =
            shJ_incf[((allidx * 3) + 0)] +
            ((grid_geo_x *
              ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) * Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ __noinline__ void
pushJ_vlo_deposit_Jy12(v8fp64 *scr, v8fp64 rx1y, v8fp64 dix1y, v8fp64 rx2y,
                       v8fp64 dix2y, v8fp64 rx2x, v8fp64 dix2x, v8fp64 rx1z,
                       v8fp64 dix1z, v8fp64 simd_mask, v8fp64 *shJ_incf,
                       double grid_geo_y, double Charge0, double Tori_X0,
                       double XO, int bBidx) {
  v8fp64 *if1_y1 = scr + 0;
  v8fp64 *if1_y2 = scr + 5;
  v8fp64 *f0_x2 = scr + 10;
  v8fp64 *f0_z1 = scr + 15;
  eval_if1(rx1y, dix1y, if1_y1);
  eval_if1(rx2y, dix2y, if1_y2);
  eval_f0(rx2x, dix2x, f0_x2);
  eval_f0(rx1z, dix1z, f0_z1);
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (simd_mask * (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                    ((f0_x2)[xyzx] * (f0_z1)[xyzz])));
        shJ_incf[((allidx * 3) + 1)] =
            shJ_incf[((allidx * 3) + 1)] +
            ((grid_geo_y *
              (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) * Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ __noinline__ void
pushJ_vlo_deposit_Jz13(v8fp64 *scr, v8fp64 rx1z, v8fp64 dix1z, v8fp64 rx3z,
                       v8fp64 dix3z, v8fp64 rx2x, v8fp64 dix2x, v8fp64 rx2y,
                       v8fp64 dix2y, v8fp64 simd_mask, v8fp64 *shJ_incf,
                       double grid_geo_z, double Charge0, double Tori_X0,
                       double XO, int bBidx) {
  v8fp64 *if1_z1 = scr + 0;
  v8fp64 *if1_z3 = scr + 5;
  v8fp64 *f0_x2 = scr + 10;
  v8fp64 *f0_y2 = scr + 15;
  eval_if1(rx1z, dix1z, if1_z1);
  eval_if1(rx3z, dix3z, if1_z3);
  eval_f0(rx2x, dix2x, f0_x2);
  eval_f0(rx2y, dix2y, f0_y2);
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (simd_mask * (((if1_z3)[xyzz] - (if1_z1)[xyzz]) *
                                    ((f0_x2)[xyzx] * (f0_y2)[xyzy])));
        shJ_incf[((allidx * 3) + 2)] =
            shJ_incf[((allidx * 3) + 2)] +
            ((grid_geo_z *
              ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) * Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ __noinline__ void
pushJ_vlo_deposit_Jy23(v8fp64 *scr, v8fp64 rx2y, v8fp64 dix2y, v8fp64 rx3y,
                       v8fp64 dix3y, v8fp64 rx2x, v8fp64 dix2x, v8fp64 rx3z,
                       v8fp64 dix3z, v8fp64 simd_mask, v8fp64 *shJ_incf,
                       double grid_geo_y, double Charge0, double Tori_X0,
                       double XO, int bBidx) {
  v8fp64 *if1_y2 = scr + 0;
  v8fp64 *if1_y3 = scr + 5;
  v8fp64 *f0_x2 = scr + 10;
  v8fp64 *f0_z3 = scr + 15;
  eval_if1(rx2y, dix2y, if1_y2);
  eval_if1(rx3y, dix3y, if1_y3);
  eval_f0(rx2x, dix2x, f0_x2);
  eval_f0(rx3z, dix3z, f0_z3);
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (simd_mask * (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                    ((f0_x2)[xyzx] * (f0_z3)[xyzz])));
        shJ_incf[((allidx * 3) + 1)] =
            shJ_incf[((allidx * 3) + 1)] +
            ((grid_geo_y *
              (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) * Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ __noinline__ void
pushJ_vlo_deposit_Jx23(v8fp64 *scr, v8fp64 rx2x, v8fp64 dix2x, v8fp64 rx3x,
                       v8fp64 dix3x, v8fp64 rx3y, v8fp64 dix3y, v8fp64 rx3z,
                       v8fp64 dix3z, v8fp64 simd_mask, v8fp64 *shJ_incf,
                       double grid_geo_x, double Charge0, double Tori_X0,
                       double XO, int bBidx) {
  v8fp64 *if1_x2 = scr + 0;
  v8fp64 *if1_x3 = scr + 5;
  v8fp64 *f0_y3 = scr + 10;
  v8fp64 *f0_z3 = scr + 15;
  eval_if1(rx2x, dix2x, if1_x2);
  eval_if1(rx3x, dix3x, if1_x3);
  eval_f0(rx3y, dix3y, f0_y3);
  eval_f0(rx3z, dix3z, f0_z3);
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (simd_mask * (((if1_x3)[xyzx] - (if1_x2)[xyzx]) *
                                    ((f0_y3)[xyzy] * (f0_z3)[xyzz])));
        shJ_incf[((allidx * 3) + 0)] =
            shJ_incf[((allidx * 3) + 0)] +
            ((grid_geo_x *
              ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) * Charge0)) *
             Jtmp);
      }
    }
  }
}
static __device__ __forceinline__ long pushJ_vlo_field_ddr_elem_offset(
    long __idy, int bBidx, int bBidy, int bBidz, int xyzy, int xyzz, long XLEN,
    long YLEN, long ZLEN, int ovlp, int num_ele) {
  return ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                               ((YLEN + (2 * ovlp)) *
                                (ZLEN + (2 * ovlp)))))) +
          (0 + (num_ele *
                ((bBidx + ovlp) +
                 ((XLEN + (2 * ovlp)) *
                  (((xyzy + bBidy) + ovlp) +
                   ((YLEN + (2 * ovlp)) *
                    ((xyzz + bBidz) + ovlp))))))));
}

static __device__ __forceinline__ void pushJ_vlo_K1_load_shared_5x5x5(
    double *shE0, double *shB0, double *shB1, double *shJ0, __DDR double *fieldE,
    __DDR double *fieldB, __DDR double *fieldB1, __DDR double *FoutJ, long __idy,
    long __idx, long __xlen, int bBidx, int bBidy, int bBidz, long XLEN, long YLEN,
    long ZLEN, int ovlp, int num_ele, cooperative_groups::thread_block block,
    SCALE::barrier<cuda::thread_scope_block> &bar) {
  const std::size_t tile_bytes =
      static_cast<std::size_t>(3 * 5) * sizeof(double);

  for (long xyzz = 0; xyzz < 5; xyzz++) {
    for (long xyzy = 0; xyzy < 5; xyzy++) {
      const int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));
      const long ddr_off = pushJ_vlo_field_ddr_elem_offset(
          __idy, bBidx, bBidy, bBidz, xyzy, xyzz, XLEN, YLEN, ZLEN, ovlp,
          num_ele);

      memcpy_async(block, shE0 + total_idx, fieldE + ddr_off, tile_bytes, bar);
      memcpy_async(block, shB0 + total_idx, fieldB + ddr_off, tile_bytes, bar);
      memcpy_async(block, shB1 + total_idx, fieldB1 + ddr_off, tile_bytes, bar);
      memcpy_async(block, shJ0 + total_idx, FoutJ + ddr_off, tile_bytes, bar);
      bar.arrive_and_wait();
    }
  }
}


static __device__ __noinline__ void
pushJ_vlo_K1_setup_weights_x0x1(pushJ_vlo_state_t *st, double *particle_buf,
                                int g_inner, long load0, double Midx,
                                double Midy, double Midz, double Deltat) {
  v8fp64 head[6];
  for (int f = 0; f < 6; f++) {
    for (int lane = 0; lane < 8; lane++) {
      int cid = g_inner + lane;
      int src = (cid < load0) ? cid : 0;
      head[f].v[lane] = particle_buf[f + 6 * src];
    }
  }

  st->simd_mask = vbroadcast(0.0);
  for (int lane = 0; lane < 8; lane++) {
    st->simd_mask.v[lane] = ((g_inner + lane) < load0) ? 1.0 : 0.0;
  }

  st->xx1 = head[0] - vbroadcast(5.00000000000000000e-01);
  st->xy1 = head[1] - vbroadcast(5.00000000000000000e-01);
  st->xz1 = head[2] - vbroadcast(5.00000000000000000e-01);
  st->vx0 = head[3];
  st->vy0 = head[4];
  st->vz0 = head[5];

  st->xx0 = (st->xx1 - (Deltat * st->vx0));
  st->xy0 = (st->xy1 - (Deltat * st->vy0));
  st->xz0 = (st->xz1 - (Deltat * st->vz0));

  v8fp64 Midx0 = geo_floor_simd(st->xx0);
  v8fp64 Midx1 = geo_floor_simd(st->xx1);
  v8fp64 Midy0 = geo_floor_simd(st->xy0);
  v8fp64 Midy1 = geo_floor_simd(st->xy1);
  v8fp64 Midz0 = geo_floor_simd(st->xz0);
  v8fp64 Midz1 = geo_floor_simd(st->xz1);

  st->s_rx0x = (st->xx0 - Midx0);
  st->s_rx0y = (st->xy0 - Midy0);
  st->s_rx0z = (st->xz0 - Midz0);
  st->s_rx1x = (st->xx1 - Midx1);
  st->s_rx1y = (st->xy1 - Midy1);
  st->s_rx1z = (st->xz1 - Midz1);
  st->s_dix0x = (Midx0 - vbroadcast(Midx));
  st->s_dix0y = (Midy0 - vbroadcast(Midy));
  st->s_dix0z = (Midz0 - vbroadcast(Midz));
  st->s_dix1x = (Midx1 - vbroadcast(Midx));
  st->s_dix1y = (Midy1 - vbroadcast(Midy));
  st->s_dix1z = (Midz1 - vbroadcast(Midz));
}
/* -------------------------------------------------------------------------- */
/* K2 push split helpers (Step C) */
/* -------------------------------------------------------------------------- */

static __device__ __noinline__ void
pushJ_vlo_K2_push_x2(pushJ_vlo_state_t *st, v8fp64 x0, v8fp64 x1,
                     v8fp64 allincfvx, double DELTA_X, double Deltat,
                     double QE_MASS, double XO, double Midx) {
  st->x2 = (((-1.00000000000000000e+00 * x0) + (2.00000000000000000e+00 * x1)) +
            ((1.00000000000000000e+00 / ({
                v8fp64 tmppowvar = vbroadcast(DELTA_X);
                (tmppowvar * tmppowvar);
              })) *
             (QE_MASS * (Deltat * (allincfvx + (-1.00000000000000000e+00 *
                                                0.00000000000000000e+00))))));

  st->s_rx2x = ((st->x2 - vbroadcast(XO)) - geo_floor_simd(st->x2 - vbroadcast(XO)));
  st->s_dix2x = (geo_floor_simd(st->x2 - vbroadcast(XO)) - vbroadcast(Midx));
}

static __device__ __noinline__ void
pushJ_vlo_K2_push_y2(pushJ_vlo_state_t *st, v8fp64 x0, v8fp64 y0, v8fp64 y1,
                     v8fp64 iBy, v8fp64 allincfvy, double TX0, double DELTA_Y,
                     double Deltat, double QE_MASS, double YO, double Midy) {
  st->y2 =
      (((1.00000000000000000e+00 / ({
           v8fp64 tmppowvar = ((({
                                  v8fp64 tmppowvar = vbroadcast(TX0);
                                  (tmppowvar * tmppowvar);
                                }) +
                                ((2.00000000000000000e+00 * (TX0 * st->x2)) + ({
                                   v8fp64 tmppowvar = st->x2;
                                   (tmppowvar * tmppowvar);
                                 }))));
           tmppowvar;
         })) *
        ((((-1.00000000000000000e+00 * ({
             v8fp64 tmppowvar = vbroadcast(TX0);
             (tmppowvar * tmppowvar);
           })) +
           ((-2.00000000000000000e+00 * (TX0 * x0)) +
            (-1.00000000000000000e+00 * ({
              v8fp64 tmppowvar = x0;
              (tmppowvar * tmppowvar);
            })))) *
          y0) +
         (((2.00000000000000000e+00 * ({
              v8fp64 tmppowvar = vbroadcast(TX0);
              (tmppowvar * tmppowvar);
            })) +
           ((2.00000000000000000e+00 * (TX0 * x0)) +
            (({
               v8fp64 tmppowvar = x0;
               (tmppowvar * tmppowvar);
             }) +
             ((2.00000000000000000e+00 * (TX0 * st->x2)) + ({
                v8fp64 tmppowvar = st->x2;
                (tmppowvar * tmppowvar);
              }))))) *
          y1))) +
       (({
          v8fp64 tmppowvar = vbroadcast(TX0);
          (tmppowvar * tmppowvar);
        }) *
        ((QE_MASS * (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
         (1.00000000000000000e+00 / ({
            v8fp64 tmppowvar =
                ((({
                    v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                    (tmppowvar * tmppowvar);
                  }) *
                  ({
                    v8fp64 tmppowvar = vbroadcast(TX0);
                    (tmppowvar * tmppowvar);
                  })) +
                 ((2.00000000000000000e+00 * (({
                                                v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                (tmppowvar * tmppowvar);
                                              }) *
                                              (TX0 * st->x2))) +
                  (({
                     v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                     (tmppowvar * tmppowvar);
                   }) *
                   ({
                     v8fp64 tmppowvar = st->x2;
                     (tmppowvar * tmppowvar);
                   }))));
            tmppowvar;
          })))));

  st->s_rx2y = ((st->y2 - vbroadcast(YO)) - geo_floor_simd(st->y2 - vbroadcast(YO)));
  st->s_dix2y = (geo_floor_simd(st->y2 - vbroadcast(YO)) - vbroadcast(Midy));
}

static __device__ __noinline__ void
pushJ_vlo_K2_push_z2_z3(pushJ_vlo_state_t *st, v8fp64 z0, v8fp64 z1, v8fp64 iBz,
                        v8fp64 allincfvz, double DELTA_Z, double Deltat,
                        double QE_MASS, double ZO, double zmid, double Midz) {
  st->z2 =
      (((-1.00000000000000000e+00 * z0) + (2.00000000000000000e+00 * z1)) +
       ((1.00000000000000000e+00 / ({
           v8fp64 tmppowvar = vbroadcast(DELTA_Z);
           (tmppowvar * tmppowvar);
         })) *
        (QE_MASS * (Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

  st->s_rx2z = ((st->z2 - vbroadcast(ZO - zmid)) - geo_floor_simd(st->z2 - vbroadcast(ZO - zmid)));
  st->s_dix2z = (geo_floor_simd(st->z2 - vbroadcast(ZO - zmid)) - vbroadcast(Midz));

  /* Keep historical behavior: iBz is zeroed before z3 */
  st->z3 =
      (((-1.00000000000000000e+00 * z1) + (2.00000000000000000e+00 * st->z2)) +
       ((1.00000000000000000e+00 / ({
           v8fp64 tmppowvar = vbroadcast(DELTA_Z);
           (tmppowvar * tmppowvar);
         })) *
        (-1 * (Deltat * (QE_MASS * 0.00000000000000000e+00)))));

  st->s_rx3z = ((st->z3 - vbroadcast(ZO - zmid)) - geo_floor_simd(st->z3 - vbroadcast(ZO - zmid)));
  st->s_dix3z = (geo_floor_simd(st->z3 - vbroadcast(ZO - zmid)) - vbroadcast(Midz));
}

static __device__ __noinline__ void
pushJ_vlo_K2_push_y3(pushJ_vlo_state_t *st, v8fp64 y1, v8fp64 iBy, double TX0,
                     double DELTA_Y, double Deltat, double QE_MASS, double YO,
                     double Midy) {
  st->y3 =
      (((-1.00000000000000000e+00 * y1) + (2.00000000000000000e+00 * st->y2)) +
       (({
          v8fp64 tmppowvar = vbroadcast(TX0);
          (tmppowvar * tmppowvar);
        }) *
        ((-1 * (Deltat * (QE_MASS * iBy))) *
         (1.00000000000000000e+00 / ({
            v8fp64 tmppowvar =
                ((({
                    v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                    (tmppowvar * tmppowvar);
                  }) *
                  ({
                    v8fp64 tmppowvar = vbroadcast(TX0);
                    (tmppowvar * tmppowvar);
                  })) +
                 ((2.00000000000000000e+00 * (({
                                                v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                (tmppowvar * tmppowvar);
                                              }) *
                                              (TX0 * st->x2))) +
                  (({
                     v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                     (tmppowvar * tmppowvar);
                   }) *
                   ({
                     v8fp64 tmppowvar = st->x2;
                     (tmppowvar * tmppowvar);
                   }))));
            tmppowvar;
          })))));

  st->s_rx3y = ((st->y3 - vbroadcast(YO)) - geo_floor_simd(st->y3 - vbroadcast(YO)));
  st->s_dix3y = (geo_floor_simd(st->y3 - vbroadcast(YO)) - vbroadcast(Midy));
}

static __device__ __noinline__ void
pushJ_vlo_K2_push_x3(pushJ_vlo_state_t *st, v8fp64 x1, v8fp64 y1, v8fp64 iBx,
                     double TX0, double DELTA_X, double DELTA_Y, double Deltat,
                     double QE_MASS, double XO, double Midx) {
  st->x3 = (((1.00000000000000000e+00 / ({
                v8fp64 tmppowvar = vbroadcast(DELTA_X);
                (tmppowvar * tmppowvar);
              })) *
             ((1.00000000000000000e+00 / ({
                 v8fp64 tmppowvar = vbroadcast(TX0);
                 (tmppowvar * tmppowvar);
               })) *
              ((-1.00000000000000000e+00 * (({
                                              v8fp64 tmppowvar = vbroadcast(DELTA_X);
                                              (tmppowvar * tmppowvar);
                                            }) *
                                            (({
                                               v8fp64 tmppowvar = vbroadcast(TX0);
                                               (tmppowvar * tmppowvar);
                                             }) *
                                             x1))) +
               ((2.00000000000000000e+00 * (({
                                              v8fp64 tmppowvar = vbroadcast(DELTA_X);
                                              (tmppowvar * tmppowvar);
                                            }) *
                                            (({
                                               v8fp64 tmppowvar = vbroadcast(TX0);
                                               (tmppowvar * tmppowvar);
                                             }) *
                                             st->x2))) +
                ((((({
                      v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                      (tmppowvar * tmppowvar);
                    }) *
                    TX0) +
                   (({
                      v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                      (tmppowvar * tmppowvar);
                    }) *
                    st->x2)) *
                  ({
                    v8fp64 tmppowvar = y1;
                    (tmppowvar * tmppowvar);
                  })) +
                 ((((-2.00000000000000000e+00 * (({
                                                   v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 TX0)) +
                    (-2.00000000000000000e+00 * (({
                                                   v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 st->x2))) *
                   (y1 * st->y2)) +
                  ((((2.00000000000000000e+00 * (({
                                                   v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 TX0)) +
                     (2.00000000000000000e+00 * (({
                                                   v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 st->x2))) *
                    ({
                      v8fp64 tmppowvar = st->y2;
                      (tmppowvar * tmppowvar);
                    })) +
                   ((((-2.00000000000000000e+00 * (({
                                                     v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   TX0)) +
                      (-2.00000000000000000e+00 * (({
                                                     v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   st->x2))) *
                     (st->y2 * st->y3)) +
                    (((({
                         v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                         (tmppowvar * tmppowvar);
                       }) *
                       TX0) +
                      (({
                         v8fp64 tmppowvar = vbroadcast(DELTA_Y);
                         (tmppowvar * tmppowvar);
                       }) *
                       st->x2)) *
                     ({
                       v8fp64 tmppowvar = st->y3;
                       (tmppowvar * tmppowvar);
                     })))))))))) +
            ((1.00000000000000000e+00 / ({
                v8fp64 tmppowvar = vbroadcast(DELTA_X);
                (tmppowvar * tmppowvar);
              })) *
             (-1 * (Deltat * (QE_MASS * iBx)))));

  st->s_rx3x = ((st->x3 - vbroadcast(XO)) - geo_floor_simd(st->x3 - vbroadcast(XO)));
  st->s_dix3x = (geo_floor_simd(st->x3 - vbroadcast(XO)) - vbroadcast(Midx));
}

/* -------------------------------------------------------------------------- */
/* K2 B-integral combination wrappers (Step F: split K2 call chain) */
/* Each returns one corrected B integral; math/order preserved bit-exact. */
/* -------------------------------------------------------------------------- */

static __device__ __noinline__ v8fp64
pushJ_vlo_K2_compute_iBy(v8fp64 *scr, const pushJ_vlo_state_t *st,
                         const double *shB0, const double *shB1) {
  v8fp64 iBy_term0 = pushJ_B_integralS_comp2_f0z_dif1x_f1y(
      scr, shB0, st->s_rx1z, st->s_dix1z, st->s_rx1x, st->s_dix1x, st->s_rx0x,
      st->s_dix0x, st->s_rx1y, st->s_dix1y);
  v8fp64 iBy_term1 = pushJ_B_integralS_comp2_f0z_dif1x_f1y(
      scr, shB1, st->s_rx1z, st->s_dix1z, st->s_rx2x, st->s_dix2x, st->s_rx1x,
      st->s_dix1x, st->s_rx1y, st->s_dix1y);
  return (iBy_term0 + iBy_term1);
}

static __device__ __noinline__ v8fp64
pushJ_vlo_K2_compute_iBz(v8fp64 *scr, const pushJ_vlo_state_t *st,
                         const double *shB0, const double *shB1) {
  v8fp64 iBz_term1 = pushJ_B_integralS_comp0_f0x_dif1y_f1z(
      scr, shB0, st->s_rx0x, st->s_dix0x, st->s_rx1y, st->s_dix1y, st->s_rx0y,
      st->s_dix0y, st->s_rx1z, st->s_dix1z);
  v8fp64 iBz_term2 = pushJ_B_integralS_comp1_f0y_dif1x_f1z(
      scr, shB0, st->s_rx1y, st->s_dix1y, st->s_rx1x, st->s_dix1x, st->s_rx0x,
      st->s_dix0x, st->s_rx1z, st->s_dix1z);
  v8fp64 iBz_term3 = pushJ_B_integralS_comp0_f0x_dif1y_f1z(
      scr, shB1, st->s_rx2x, st->s_dix2x, st->s_rx2y, st->s_dix2y, st->s_rx1y,
      st->s_dix1y, st->s_rx1z, st->s_dix1z);
  v8fp64 iBz_term4 = pushJ_B_integralS_comp1_f0y_dif1x_f1z(
      scr, shB1, st->s_rx1y, st->s_dix1y, st->s_rx2x, st->s_dix2x, st->s_rx1x,
      st->s_dix1x, st->s_rx1z, st->s_dix1z);
  v8fp64 inner = ((-1.00000000000000000e+00 * iBz_term1) + iBz_term2 +
                  (-1.00000000000000000e+00 * iBz_term3) + iBz_term4);
  return (-1.00000000000000000e+00 * inner);
}

static __device__ __noinline__ v8fp64
pushJ_vlo_K2_compute_iBy23(v8fp64 *scr, const pushJ_vlo_state_t *st,
                          const double *shB1) {
  return ((-1.00000000000000000e+00 *
           pushJ_B_integralS_comp0_f0x_dif1z_f1y(
               scr, shB1, st->s_rx2x, st->s_dix2x, st->s_rx2z, st->s_dix2z,
               st->s_rx1z, st->s_dix1z, st->s_rx2y, st->s_dix2y)) +
          (-1.00000000000000000e+00 *
           pushJ_B_integralS_comp0_f0x_dif1z_f1y(
               scr, shB1, st->s_rx2x, st->s_dix2x, st->s_rx3z, st->s_dix3z,
               st->s_rx2z, st->s_dix2z, st->s_rx2y, st->s_dix2y)));
}

static __device__ __noinline__ v8fp64
pushJ_vlo_K2_compute_iBx(v8fp64 *scr, const pushJ_vlo_state_t *st,
                         const double *shB1) {
  return (pushJ_B_integralS_comp1_f0y_dif1z_f1x(
              scr, shB1, st->s_rx2y, st->s_dix2y, st->s_rx2z, st->s_dix2z,
              st->s_rx1z, st->s_dix1z, st->s_rx2x, st->s_dix2x) +
          pushJ_B_integralS_comp1_f0y_dif1z_f1x(
              scr, shB1, st->s_rx2y, st->s_dix2y, st->s_rx3z, st->s_dix3z,
              st->s_rx2z, st->s_dix2z, st->s_rx2x, st->s_dix2x) +
          (-1.00000000000000000e+00) *
              pushJ_B_integralS_comp2_f0z_dif1y_f1x(
                  scr, shB1, st->s_rx1z, st->s_dix1z, st->s_rx2y, st->s_dix2y,
                  st->s_rx1y, st->s_dix1y, st->s_rx2x, st->s_dix2x) +
          (-1.00000000000000000e+00) *
              pushJ_B_integralS_comp2_f0z_dif1y_f1x(
                  scr, shB1, st->s_rx3z, st->s_dix3z, st->s_rx3y, st->s_dix3y,
                  st->s_rx2y, st->s_dix2y, st->s_rx2x, st->s_dix2x));
}

/* -------------------------------------------------------------------------- */
/* K2 Verlet stage splits (Step G/H): shorten live range per stage callee */
/* -------------------------------------------------------------------------- */

static __device__ __noinline__ void
pushJ_vlo_K2_stage1a_E(v8fp64 *scr, const pushJ_vlo_state_t *st,
                       const double *shE0, double Deltat, v8fp64 *allincfvx_out,
                       v8fp64 *allincfvy_out, v8fp64 *allincfvz_out) {
  const v8fp64 AllEx =
      pushJ_E_interp_Ex(scr, shE0, st->s_rx1x, st->s_dix1x, st->s_rx1y,
                        st->s_dix1y, st->s_rx1z, st->s_dix1z);
  const v8fp64 AllEy =
      pushJ_E_interp_Ey(scr, shE0, st->s_rx1x, st->s_dix1x, st->s_rx1y,
                        st->s_dix1y, st->s_rx1z, st->s_dix1z);
  const v8fp64 AllEz =
      pushJ_E_interp_Ez(scr, shE0, st->s_rx1x, st->s_dix1x, st->s_rx1y,
                        st->s_dix1y, st->s_rx1z, st->s_dix1z);
  *allincfvx_out = (2.00000000000000000e+00 * (Deltat * AllEx));
  *allincfvy_out = (2.00000000000000000e+00 * (Deltat * AllEy));
  *allincfvz_out = (2.00000000000000000e+00 * (Deltat * AllEz));
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage1b_x2y2(
    v8fp64 *scr, pushJ_vlo_state_t *st, const double *shB0, const double *shB1,
    v8fp64 x0, v8fp64 x1, v8fp64 y0, v8fp64 y1, v8fp64 allincfvx,
    v8fp64 allincfvy, double DELTA_X, double DELTA_Y, double Deltat,
    double TX0, double QE_MASS, double XO, double YO, double Midx,
    double Midy) {
  pushJ_vlo_K2_push_x2(st, x0, x1, allincfvx, DELTA_X, Deltat, QE_MASS, XO,
                       Midx);

  const v8fp64 iBy = pushJ_vlo_K2_compute_iBy(scr, st, shB0, shB1);

  pushJ_vlo_K2_push_y2(st, x0, y0, y1, iBy, allincfvy, TX0, DELTA_Y, Deltat,
                       QE_MASS, YO, Midy);
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage2_z2z3(v8fp64 *scr, pushJ_vlo_state_t *st, const double *shB0,
                         const double *shB1, v8fp64 z0, v8fp64 z1,
                         v8fp64 allincfvz, double DELTA_Z, double Deltat,
                         double QE_MASS, double ZO, double zmid, double Midz) {
  const v8fp64 iBz = pushJ_vlo_K2_compute_iBz(scr, st, shB0, shB1);

  pushJ_vlo_K2_push_z2_z3(st, z0, z1, iBz, allincfvz, DELTA_Z, Deltat, QE_MASS,
                          ZO, zmid, Midz);
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage3a_y3(v8fp64 *scr, pushJ_vlo_state_t *st, const double *shB1,
                        v8fp64 y1, double TX0, double DELTA_Y, double Deltat,
                        double QE_MASS, double YO, double Midy) {
  const v8fp64 iBy23 = pushJ_vlo_K2_compute_iBy23(scr, st, shB1);

  pushJ_vlo_K2_push_y3(st, y1, iBy23, TX0, DELTA_Y, Deltat, QE_MASS, YO, Midy);
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage3b_x3(v8fp64 *scr, pushJ_vlo_state_t *st, const double *shB1,
                        v8fp64 x1, v8fp64 y1, double TX0, double DELTA_X,
                        double DELTA_Y, double Deltat, double QE_MASS, double XO,
                        double Midx) {
  const v8fp64 iBx = pushJ_vlo_K2_compute_iBx(scr, st, shB1);

  pushJ_vlo_K2_push_x3(st, x1, y1, iBx, TX0, DELTA_X, DELTA_Y, Deltat, QE_MASS,
                       XO, Midx);
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage1_E_x2y2(
    v8fp64 *scr, pushJ_vlo_state_t *st, const double *shE0, const double *shB0,
    const double *shB1, v8fp64 x0, v8fp64 x1, v8fp64 y0, v8fp64 y1,
    double DELTA_X, double DELTA_Y, double Deltat, double TX0, double QE_MASS,
    double XO, double YO, double Midx, double Midy, v8fp64 *allincfvz_out) {
  v8fp64 allincfvx, allincfvy;
  pushJ_vlo_K2_stage1a_E(scr, st, shE0, Deltat, &allincfvx, &allincfvy,
                         allincfvz_out);
  pushJ_vlo_K2_stage1b_x2y2(scr, st, shB0, shB1, x0, x1, y0, y1, allincfvx,
                            allincfvy, DELTA_X, DELTA_Y, Deltat, TX0, QE_MASS,
                            XO, YO, Midx, Midy);
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage3_y3x3(v8fp64 *scr, pushJ_vlo_state_t *st, const double *shB1,
                         v8fp64 x1, v8fp64 y1, double TX0, double DELTA_X,
                         double DELTA_Y, double Deltat, double QE_MASS, double XO,
                         double YO, double Midx, double Midy) {
  pushJ_vlo_K2_stage3a_y3(scr, st, shB1, y1, TX0, DELTA_Y, Deltat, QE_MASS, YO,
                          Midy);
  pushJ_vlo_K2_stage3b_x3(scr, st, shB1, x1, y1, TX0, DELTA_X, DELTA_Y, Deltat,
                          QE_MASS, XO, Midx);
}

static __device__ __noinline__ void
pushJ_vlo_K2_push_weights_x2x3(
    v8fp64 *scr, pushJ_vlo_state_t *st, const double *shE0, const double *shB0,
    const double *shB1, double DELTA_X, double DELTA_Y, double DELTA_Z,
    double Deltat, double Tori_X0, double QE_MASS, double XO, double YO,
    double ZO, double zmid, double Midx, double Midy, double Midz) {
  const double TX0 = Tori_X0;
  const v8fp64 x0 = (st->xx0 + vbroadcast(XO));
  const v8fp64 y0 = (st->xy0 + vbroadcast(YO));
  const v8fp64 z0 = (st->xz0 + vbroadcast(ZO - zmid));
  const v8fp64 x1 = (st->xx1 + vbroadcast(XO));
  const v8fp64 y1 = (st->xy1 + vbroadcast(YO));
  const v8fp64 z1 = (st->xz1 + vbroadcast(ZO - zmid));

  v8fp64 allincfvz;
  pushJ_vlo_K2_stage1_E_x2y2(scr, st, shE0, shB0, shB1, x0, x1, y0, y1, DELTA_X,
                             DELTA_Y, Deltat, TX0, QE_MASS, XO, YO, Midx, Midy,
                             &allincfvz);
  pushJ_vlo_K2_stage2_z2z3(scr, st, shB0, shB1, z0, z1, allincfvz, DELTA_Z,
                           Deltat, QE_MASS, ZO, zmid, Midz);
  pushJ_vlo_K2_stage3_y3x3(scr, st, shB1, x1, y1, TX0, DELTA_X, DELTA_Y, Deltat,
                           QE_MASS, XO, YO, Midx, Midy);
}


static __device__ __noinline__ void pushJ_vlo_K3_deposit_writeback_particle(
    v8fp64 *scr, pushJ_vlo_state_t *st, v8fp64 *shJ_incf, double *particle_buf,
    double Deltat, int g_inner, long load0, double Charge0, double Tori_X0,
    double grid_geo_x, double grid_geo_y, double grid_geo_z, double XO,
    double YO, double ZO, double zmid, int bBidx, int bBidy, int bBidz) {
  pushJ_vlo_deposit_Jx12(scr, st->s_rx1x, st->s_dix1x, st->s_rx2x, st->s_dix2x,
                         st->s_rx1y, st->s_dix1y, st->s_rx1z, st->s_dix1z,
                         st->simd_mask, shJ_incf, grid_geo_x, Charge0, Tori_X0,
                         XO, bBidx);
  pushJ_vlo_deposit_Jy12(scr, st->s_rx1y, st->s_dix1y, st->s_rx2y, st->s_dix2y,
                         st->s_rx2x, st->s_dix2x, st->s_rx1z, st->s_dix1z,
                         st->simd_mask, shJ_incf, grid_geo_y, Charge0, Tori_X0,
                         XO, bBidx);
  pushJ_vlo_deposit_Jz13(scr, st->s_rx1z, st->s_dix1z, st->s_rx3z, st->s_dix3z,
                         st->s_rx2x, st->s_dix2x, st->s_rx2y, st->s_dix2y,
                         st->simd_mask, shJ_incf, grid_geo_z, Charge0, Tori_X0,
                         XO, bBidx);
  pushJ_vlo_deposit_Jy23(scr, st->s_rx2y, st->s_dix2y, st->s_rx3y, st->s_dix3y,
                         st->s_rx2x, st->s_dix2x, st->s_rx3z, st->s_dix3z,
                         st->simd_mask, shJ_incf, grid_geo_y, Charge0, Tori_X0,
                         XO, bBidx);
  pushJ_vlo_deposit_Jx23(scr, st->s_rx2x, st->s_dix2x, st->s_rx3x, st->s_dix3x,
                         st->s_rx3y, st->s_dix3y, st->s_rx3z, st->s_dix3z,
                         st->simd_mask, shJ_incf, grid_geo_x, Charge0, Tori_X0,
                         XO, bBidx);

  v8fp64 newvx = ((st->x3 - st->x2) / Deltat);
  v8fp64 newvy = ((st->y3 - st->y2) / Deltat);
  v8fp64 newvz = ((st->z3 - st->z2) / Deltat);
  v8fp64 newxx = (st->x3 - vbroadcast(XO));
  v8fp64 newxy = (st->y3 - vbroadcast(YO));
  v8fp64 newxz = ((st->z3 + vbroadcast(zmid)) - vbroadcast(ZO));
  newxx = (newxx + vbroadcast(5.00000000000000000e-01));
  newxy = (newxy + vbroadcast(5.00000000000000000e-01));
  newxz = (newxz + vbroadcast(5.00000000000000000e-01));
  {
    long stmpg1;
    for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
      for (int lane = 0; lane < 8; lane++) {
        int cid = g_inner + lane;
        if (cid < load0) {
          const int poff = stmpg1 + cid * 6;
          if (stmpg1 == 0) {
            particle_buf[poff] = newxx.v[lane];
          } else if (stmpg1 == 1) {
            particle_buf[poff] = newxy.v[lane];
          } else if (stmpg1 == 2) {
            particle_buf[poff] = newxz.v[lane];
          } else if (stmpg1 == 3) {
            particle_buf[poff] = newvx.v[lane];
          } else if (stmpg1 == 4) {
            particle_buf[poff] = newvy.v[lane];
          } else {
            particle_buf[poff] = newvz.v[lane];
          }
        }
      }
    }
  }
}

static __device__ __forceinline__ void
pushJ_vlo_zero_shJ_incf(v8fp64 *shJ_incf) {
  for (int k = 0; k < 375; k++) {
    shJ_incf[k] = vbroadcast(0.0);
  }
}

static __device__ __forceinline__ void
pushJ_vlo_collapse_shJ_incf_to_shJ0(double *shJ0, const v8fp64 *shJ_incf) {
  for (int k = 0; k < 375; k++) {
    double sum = 0.0;
#pragma unroll
    for (int lane = 0; lane < 8; lane++) {
      sum += shJ_incf[k].v[lane];
    }
    shJ0[k] += sum;
  }
}
static __device__ __forceinline__ void
pushJ_vlo_K3_write_FoutJ_from_shared(double *shJ0, __DDR double *FoutJ, long __idy,
                                     long __idx, long __xlen, int bBidx,
                                     int bBidy, int bBidz, long XLEN, long YLEN,
                                     long ZLEN, int ovlp, int num_ele,
                                     cooperative_groups::thread_block block,
                                     SCALE::barrier<cuda::thread_scope_block> &bar) {
  const std::size_t tile_bytes =
      static_cast<std::size_t>(3 * 5) * sizeof(double);

  for (long xyzz = 0; xyzz < 5; xyzz++) {
    for (long xyzy = 0; xyzy < 5; xyzy++) {
      const int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));
      const long ddr_off = pushJ_vlo_field_ddr_elem_offset(
          __idy, bBidx, bBidy, bBidz, xyzy, xyzz, XLEN, YLEN, ZLEN, ovlp,
          num_ele);

      memcpy_async(block, FoutJ + ddr_off, shJ0 + total_idx, tile_bytes, bar);
      bar.arrive_and_wait();
    }
  }
}

#endif

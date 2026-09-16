/* pushJ_vlo K1 split - extracted from cuda_geo_nr_Bfield_pushJ_vlo Pass A */
#ifndef PUSHJ_VLO_SPLIT_CUH
#define PUSHJ_VLO_SPLIT_CUH

#ifndef IDX_LOCAL_XLEN
#define IDX_LOCAL_XLEN 32
#endif
#ifndef FULL_MASK
#define FULL_MASK 0xffffffffu
#endif

#include "pushJ_weights.cuh"

typedef struct {
  double simd_mask;
  int g;
  int _gen_long_for_opt_loop_already_idx_0;
  double xx1, xy1, xz1, vx0, vy0, vz0;
  double xx0, xy0, xz0;
  double s_rx0x, s_rx0y, s_rx0z, s_rx1x, s_rx1y, s_rx1z;
  double s_rx2x, s_rx2y, s_rx2z, s_rx3x, s_rx3y, s_rx3z;
  double s_dix0x, s_dix0y, s_dix0z, s_dix1x, s_dix1y, s_dix1z;
  double s_dix2x, s_dix2y, s_dix2z, s_dix3x, s_dix3y, s_dix3z;

  /* K2 */
  double x2, y2, z2, x3, y3, z3;
} pushJ_vlo_state_t;

static __device__ __forceinline__ double pushJ_vlo_reduce_Jtmp(double Jtmp, double *Jtmp_shd, long __idx) {

  Jtmp_shd[__idx] = Jtmp;
  __syncthreads();

  // 2. 动态步长的二叉树折叠规约 (支持任意大小的 IDX_LOCAL_XLEN)
  // 假设 IDX_LOCAL_XLEN=64，offset 会经历 32 -> 16 -> 8 -> 4 -> 2 -> 1
  for (int offset = IDX_LOCAL_XLEN / 2; offset > 0; offset >>= 1) {
    if (__idx < offset) {
      Jtmp_shd[__idx] += Jtmp_shd[__idx + offset];
    }
    __syncthreads();
  }

  // 3. 0号线程提取最终结果
  double sum = 0.0;
  if (__idx == 0) {
    sum = Jtmp_shd[0];
  }
  return sum;
}

static __device__ __noinline__ void pushJ_vlo_deposit_Jx12(double rx1x, double dix1x, double rx2x, double dix2x,
                                                           double rx1y, double dix1y, double rx1z, double dix1z,
                                                           double simd_mask, int oob, long __idx, double *shJ0,
                                                           double *Jtmp_shd, double grid_geo_x, double Charge0,
                                                           double Tori_X0, double XO, int bBidx) {
  double if1_x1[5], if1_x2[5], f0_y1[5], f0_z1[5];
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
        double Jtmp = (simd_mask * (((if1_x2)[xyzx] - (if1_x1)[xyzx]) * ((f0_y1)[xyzy] * (f0_z1)[xyzz])));
        if (oob) {
          Jtmp = 0;
        }
        double Jsum = pushJ_vlo_reduce_Jtmp(Jtmp, Jtmp_shd, __idx);
        if (__idx == 0) {
          ((shJ0)[((allidx * 3) + 0)] =
               ((shJ0)[((allidx * 3) + 0)] +
                ((grid_geo_x * ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) * Charge0)) * Jsum)));
        }
      }
    }
  }
}

static __device__ __noinline__ void pushJ_vlo_deposit_Jy12(double rx1y, double dix1y, double rx2y, double dix2y,
                                                           double rx2x, double dix2x, double rx1z, double dix1z,
                                                           double simd_mask, int oob, long __idx, double *shJ0,
                                                           double *Jtmp_shd, double grid_geo_y, double Charge0,
                                                           double Tori_X0, double XO, int bBidx) {
  double if1_y1[5], if1_y2[5], f0_x2[5], f0_z1[5];
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
        double Jtmp = (simd_mask * (((if1_y2)[xyzy] - (if1_y1)[xyzy]) * ((f0_x2)[xyzx] * (f0_z1)[xyzz])));
        if (oob) {
          Jtmp = 0;
        }
        double Jsum = pushJ_vlo_reduce_Jtmp(Jtmp, Jtmp_shd, __idx);
        if (__idx == 0) {
          ((shJ0)[((allidx * 3) + 1)] =
               ((shJ0)[((allidx * 3) + 1)] +
                ((grid_geo_y * (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) * Charge0)) * Jsum)));
        }
      }
    }
  }
}

static __device__ __noinline__ void pushJ_vlo_deposit_Jz13(double rx1z, double dix1z, double rx3z, double dix3z,
                                                           double rx2x, double dix2x, double rx2y, double dix2y,
                                                           double simd_mask, int oob, long __idx, double *shJ0,
                                                           double *Jtmp_shd, double grid_geo_z, double Charge0,
                                                           double Tori_X0, double XO, int bBidx) {
  double if1_z1[5], if1_z3[5], f0_x2[5], f0_y2[5];
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
        double Jtmp = (simd_mask * (((if1_z3)[xyzz] - (if1_z1)[xyzz]) * ((f0_x2)[xyzx] * (f0_y2)[xyzy])));
        if (oob) {
          Jtmp = 0;
        }
        double Jsum = pushJ_vlo_reduce_Jtmp(Jtmp, Jtmp_shd, __idx);
        if (__idx == 0) {
          ((shJ0)[((allidx * 3) + 2)] =
               ((shJ0)[((allidx * 3) + 2)] +
                ((grid_geo_z * ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) * Charge0)) * Jsum)));
        }
      }
    }
  }
}

static __device__ __noinline__ void pushJ_vlo_deposit_Jy23(double rx2y, double dix2y, double rx3y, double dix3y,
                                                           double rx2x, double dix2x, double rx3z, double dix3z,
                                                           double simd_mask, int oob, long __idx, double *shJ0,
                                                           double *Jtmp_shd, double grid_geo_y, double Charge0,
                                                           double Tori_X0, double XO, int bBidx) {
  double if1_y2[5], if1_y3[5], f0_x2[5], f0_z3[5];
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
        double Jtmp = (simd_mask * (((if1_y3)[xyzy] - (if1_y2)[xyzy]) * ((f0_x2)[xyzx] * (f0_z3)[xyzz])));
        if (oob) {
          Jtmp = 0;
        }
        double Jsum = pushJ_vlo_reduce_Jtmp(Jtmp, Jtmp_shd, __idx);
        if (__idx == 0) {
          ((shJ0)[((allidx * 3) + 1)] =
               ((shJ0)[((allidx * 3) + 1)] +
                ((grid_geo_y * (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) * Charge0)) * Jsum)));
        }
      }
    }
  }
}

static __device__ __noinline__ void pushJ_vlo_deposit_Jx23(double rx2x, double dix2x, double rx3x, double dix3x,
                                                           double rx3y, double dix3y, double rx3z, double dix3z,
                                                           double simd_mask, int oob, long __idx, double *shJ0,
                                                           double *Jtmp_shd, double grid_geo_x, double Charge0,
                                                           double Tori_X0, double XO, int bBidx) {
  double if1_x2[5], if1_x3[5], f0_y3[5], f0_z3[5];
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
        double Jtmp = (simd_mask * (((if1_x3)[xyzx] - (if1_x2)[xyzx]) * ((f0_y3)[xyzy] * (f0_z3)[xyzz])));
        if (oob) {
          Jtmp = 0;
        }
        double Jsum = pushJ_vlo_reduce_Jtmp(Jtmp, Jtmp_shd, __idx);
        if (__idx == 0) {
          ((shJ0)[((allidx * 3) + 0)] =
               ((shJ0)[((allidx * 3) + 0)] +
                ((grid_geo_x * ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) * Charge0)) * Jsum)));
        }
      }
    }
  }
}

static __device__ __forceinline__ void
pushJ_vlo_K1_load_shared_5x5x5(double *shE0, double *shB0, double *shB1, double *shJ0, double *fieldE, double *fieldB,
                               double *fieldB1, double *FoutJ, long __idy, long __idx, long __xlen, int bBidx,
                               int bBidy, int bBidz, long XLEN, long YLEN, long ZLEN, int ovlp, int num_ele) {
  {
    long xyzz;

    for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
      {
        long xyzy;

        for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
          {
            long xyzx;

            for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
              int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

              {
                long MYGEN1286 = 0;

                for (; (MYGEN1286 < (3 * 5)); (MYGEN1286 = (MYGEN1286 + __xlen))) {
                  int ridx = (MYGEN1286 + __idx);

                  if (ridx < (3 * 5)) {
                    (((shE0 + total_idx))[ridx] =
                         ((fieldE +
                           ((num_ele * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                            (0 + (num_ele *
                                  ((bBidx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                     (((xyzy + bBidy) + ovlp) +
                                                      ((YLEN + (2 * ovlp)) * ((xyzz + bBidz) + ovlp))))))))))[ridx]);
                  }
                }
              }
              {
                long MYGEN1288 = 0;

                for (; (MYGEN1288 < (3 * 5)); (MYGEN1288 = (MYGEN1288 + __xlen))) {
                  int ridx = (MYGEN1288 + __idx);

                  if (ridx < (3 * 5)) {
                    (((shB0 + total_idx))[ridx] =
                         ((fieldB +
                           ((num_ele * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                            (0 + (num_ele *
                                  ((bBidx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                     (((xyzy + bBidy) + ovlp) +
                                                      ((YLEN + (2 * ovlp)) * ((xyzz + bBidz) + ovlp))))))))))[ridx]);
                  }
                }
              }
              {
                long MYGEN1290 = 0;

                for (; (MYGEN1290 < (3 * 5)); (MYGEN1290 = (MYGEN1290 + __xlen))) {
                  int ridx = (MYGEN1290 + __idx);

                  if (ridx < (3 * 5)) {
                    (((shB1 + total_idx))[ridx] =
                         ((fieldB1 +
                           ((num_ele * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                            (0 + (num_ele *
                                  ((bBidx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                     (((xyzy + bBidy) + ovlp) +
                                                      ((YLEN + (2 * ovlp)) * ((xyzz + bBidz) + ovlp))))))))))[ridx]);
                  }
                }
              }
              {
                long MYGEN1292 = 0;

                for (; (MYGEN1292 < (3 * 5)); (MYGEN1292 = (MYGEN1292 + __xlen))) {
                  int ridx = (MYGEN1292 + __idx);

                  if (ridx < (3 * 5)) {
                    (((shJ0 + total_idx))[ridx] =
                         ((FoutJ +
                           ((num_ele * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                            (0 + (num_ele *
                                  ((bBidx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                     (((xyzy + bBidy) + ovlp) +
                                                      ((YLEN + (2 * ovlp)) * ((xyzz + bBidz) + ovlp))))))))))[ridx]);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

static __device__ __noinline__ void pushJ_vlo_K1_setup_weights_x0x1(pushJ_vlo_state_t *st, double *particle_buf,
                                                                    long __idx, long __xlen, int g_inner, long load0,
                                                                    double Midx, double Midy, double Midz,
                                                                    double Deltat) {
  st->simd_mask = 1;

  st->g = (g_inner + __idx);

  st->_gen_long_for_opt_loop_already_idx_0 = (st->g >= load0);

  {
    int cid = (g_inner + __idx);
    const int pbase = (((cid < load0)) ? (cid * 6) : (g_inner * 6));
    st->xx1 = particle_buf[pbase + 0];
    st->xy1 = particle_buf[pbase + 1];
    st->xz1 = particle_buf[pbase + 2];
    st->vx0 = particle_buf[pbase + 3];
    st->vy0 = particle_buf[pbase + 4];
    st->vz0 = particle_buf[pbase + 5];
  }

  (st->xx1 = (st->xx1 + -5.00000000000000000e-01));
  (st->xy1 = (st->xy1 + -5.00000000000000000e-01));
  (st->xz1 = (st->xz1 + -5.00000000000000000e-01));
  st->xx0 = (st->xx1 - (Deltat * st->vx0));

  st->xy0 = (st->xy1 - (Deltat * st->vy0));

  st->xz0 = (st->xz1 - (Deltat * st->vz0));

  {
    double Midx0 = floor(st->xx0);
    double Midx1 = floor(st->xx1);
    double Midy0 = floor(st->xy0);
    double Midy1 = floor(st->xy1);
    double Midz0 = floor(st->xz0);
    double Midz1 = floor(st->xz1);

    st->s_rx0x = (st->xx0 - Midx0);
    st->s_rx0y = (st->xy0 - Midy0);
    st->s_rx0z = (st->xz0 - Midz0);
    st->s_rx1x = (st->xx1 - Midx1);
    st->s_rx1y = (st->xy1 - Midy1);
    st->s_rx1z = (st->xz1 - Midz1);
    st->s_dix0x = (Midx0 - Midx);
    st->s_dix0y = (Midy0 - Midy);
    st->s_dix0z = (Midz0 - Midz);
    st->s_dix1x = (Midx1 - Midx);
    st->s_dix1y = (Midy1 - Midy);
    st->s_dix1z = (Midz1 - Midz);
  }
}

/* -------------------------------------------------------------------------- */
/* K2 push split helpers (Step C) */
/* -------------------------------------------------------------------------- */

static __device__ __noinline__ void pushJ_vlo_K2_push_x2(pushJ_vlo_state_t *st, double x0, double x1, double allincfvx,
                                                         double DELTA_X, double Deltat, double QE_MASS, double XO,
                                                         double Midx) {
  st->x2 = (((-1.00000000000000000e+00 * x0) + (2.00000000000000000e+00 * x1)) +
            ((1.00000000000000000e+00 / ({
                double tmppowvar = DELTA_X;
                (tmppowvar * tmppowvar);
              })) *
             (QE_MASS * (Deltat * (allincfvx + (-1.00000000000000000e+00 * 0.00000000000000000e+00))))));

  st->s_rx2x = ((st->x2 - XO) - floor((st->x2 - XO)));
  st->s_dix2x = (floor((st->x2 - XO)) - Midx);
}

static __device__ __noinline__ void pushJ_vlo_K2_push_y2(pushJ_vlo_state_t *st, double x0, double y0, double y1,
                                                         double iBy, double allincfvy, double TX0, double DELTA_Y,
                                                         double Deltat, double QE_MASS, double YO, double Midy) {
  st->y2 = (((1.00000000000000000e+00 / ({
                double tmppowvar = ((({
                                       double tmppowvar = TX0;
                                       (tmppowvar * tmppowvar);
                                     }) +
                                     ((2.00000000000000000e+00 * (TX0 * st->x2)) + ({
                                        double tmppowvar = st->x2;
                                        (tmppowvar * tmppowvar);
                                      }))));
                tmppowvar;
              })) *
             ((((-1.00000000000000000e+00 * ({
                  double tmppowvar = TX0;
                  (tmppowvar * tmppowvar);
                })) +
                ((-2.00000000000000000e+00 * (TX0 * x0)) + (-1.00000000000000000e+00 * ({
                   double tmppowvar = x0;
                   (tmppowvar * tmppowvar);
                 })))) *
               y0) +
              (((2.00000000000000000e+00 * ({
                   double tmppowvar = TX0;
                   (tmppowvar * tmppowvar);
                 })) +
                ((2.00000000000000000e+00 * (TX0 * x0)) + (({
                                                             double tmppowvar = x0;
                                                             (tmppowvar * tmppowvar);
                                                           }) +
                                                           ((2.00000000000000000e+00 * (TX0 * st->x2)) + ({
                                                              double tmppowvar = st->x2;
                                                              (tmppowvar * tmppowvar);
                                                            }))))) *
               y1))) +
            (({
               double tmppowvar = TX0;
               (tmppowvar * tmppowvar);
             }) *
             ((QE_MASS * (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
              (1.00000000000000000e+00 / ({
                 double tmppowvar = ((({
                                        double tmppowvar = DELTA_Y;
                                        (tmppowvar * tmppowvar);
                                      }) *
                                      ({
                                        double tmppowvar = TX0;
                                        (tmppowvar * tmppowvar);
                                      })) +
                                     ((2.00000000000000000e+00 * (({
                                                                    double tmppowvar = DELTA_Y;
                                                                    (tmppowvar * tmppowvar);
                                                                  }) *
                                                                  (TX0 * st->x2))) +
                                      (({
                                         double tmppowvar = DELTA_Y;
                                         (tmppowvar * tmppowvar);
                                       }) *
                                       ({
                                         double tmppowvar = st->x2;
                                         (tmppowvar * tmppowvar);
                                       }))));
                 tmppowvar;
               })))));

  st->s_rx2y = ((st->y2 - YO) - floor((st->y2 - YO)));
  st->s_dix2y = (floor((st->y2 - YO)) - Midy);
}

static __device__ __noinline__ void pushJ_vlo_K2_push_z2_z3(pushJ_vlo_state_t *st, double z0, double z1, double iBz,
                                                            double allincfvz, double DELTA_Z, double Deltat,
                                                            double QE_MASS, double ZO, double zmid, double Midz) {
  st->z2 = (((-1.00000000000000000e+00 * z0) + (2.00000000000000000e+00 * z1)) +
            ((1.00000000000000000e+00 / ({
                double tmppowvar = DELTA_Z;
                (tmppowvar * tmppowvar);
              })) *
             (QE_MASS * (Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

  st->s_rx2z = ((st->z2 - (ZO - zmid)) - floor((st->z2 - (ZO - zmid))));
  st->s_dix2z = (floor((st->z2 - (ZO - zmid))) - Midz);

  /* Keep historical behavior: iBz is zeroed before z3 */
  st->z3 = (((-1.00000000000000000e+00 * z1) + (2.00000000000000000e+00 * st->z2)) +
            ((1.00000000000000000e+00 / ({
                double tmppowvar = DELTA_Z;
                (tmppowvar * tmppowvar);
              })) *
             (-1 * (Deltat * (QE_MASS * 0.00000000000000000e+00)))));

  st->s_rx3z = ((st->z3 - (ZO - zmid)) - floor((st->z3 - (ZO - zmid))));
  st->s_dix3z = (floor((st->z3 - (ZO - zmid))) - Midz);
}

static __device__ __noinline__ void pushJ_vlo_K2_push_y3(pushJ_vlo_state_t *st, double y1, double iBy, double TX0,
                                                         double DELTA_Y, double Deltat, double QE_MASS, double YO,
                                                         double Midy) {
  st->y3 = (((-1.00000000000000000e+00 * y1) + (2.00000000000000000e+00 * st->y2)) +
            (({
               double tmppowvar = TX0;
               (tmppowvar * tmppowvar);
             }) *
             ((-1 * (Deltat * (QE_MASS * iBy))) * (1.00000000000000000e+00 / ({
                                                     double tmppowvar =
                                                         ((({
                                                             double tmppowvar = DELTA_Y;
                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           ({
                                                             double tmppowvar = TX0;
                                                             (tmppowvar * tmppowvar);
                                                           })) +
                                                          ((2.00000000000000000e+00 * (({
                                                                                         double tmppowvar = DELTA_Y;
                                                                                         (tmppowvar * tmppowvar);
                                                                                       }) *
                                                                                       (TX0 * st->x2))) +
                                                           (({
                                                              double tmppowvar = DELTA_Y;
                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            ({
                                                              double tmppowvar = st->x2;
                                                              (tmppowvar * tmppowvar);
                                                            }))));
                                                     tmppowvar;
                                                   })))));

  st->s_rx3y = ((st->y3 - YO) - floor((st->y3 - YO)));
  st->s_dix3y = (floor((st->y3 - YO)) - Midy);
}

static __device__ __noinline__ void pushJ_vlo_K2_push_x3(pushJ_vlo_state_t *st, double x1, double y1, double iBx,
                                                         double TX0, double DELTA_X, double DELTA_Y, double Deltat,
                                                         double QE_MASS, double XO, double Midx) {
  st->x3 = (((1.00000000000000000e+00 / ({
                double tmppowvar = DELTA_X;
                (tmppowvar * tmppowvar);
              })) *
             ((1.00000000000000000e+00 / ({
                 double tmppowvar = TX0;
                 (tmppowvar * tmppowvar);
               })) *
              ((-1.00000000000000000e+00 * (({
                                              double tmppowvar = DELTA_X;
                                              (tmppowvar * tmppowvar);
                                            }) *
                                            (({
                                               double tmppowvar = TX0;
                                               (tmppowvar * tmppowvar);
                                             }) *
                                             x1))) +
               ((2.00000000000000000e+00 * (({
                                              double tmppowvar = DELTA_X;
                                              (tmppowvar * tmppowvar);
                                            }) *
                                            (({
                                               double tmppowvar = TX0;
                                               (tmppowvar * tmppowvar);
                                             }) *
                                             st->x2))) +
                ((((({
                      double tmppowvar = DELTA_Y;
                      (tmppowvar * tmppowvar);
                    }) *
                    TX0) +
                   (({
                      double tmppowvar = DELTA_Y;
                      (tmppowvar * tmppowvar);
                    }) *
                    st->x2)) *
                  ({
                    double tmppowvar = y1;
                    (tmppowvar * tmppowvar);
                  })) +
                 ((((-2.00000000000000000e+00 * (({
                                                   double tmppowvar = DELTA_Y;
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 TX0)) +
                    (-2.00000000000000000e+00 * (({
                                                   double tmppowvar = DELTA_Y;
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 st->x2))) *
                   (y1 * st->y2)) +
                  ((((2.00000000000000000e+00 * (({
                                                   double tmppowvar = DELTA_Y;
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 TX0)) +
                     (2.00000000000000000e+00 * (({
                                                   double tmppowvar = DELTA_Y;
                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 st->x2))) *
                    ({
                      double tmppowvar = st->y2;
                      (tmppowvar * tmppowvar);
                    })) +
                   ((((-2.00000000000000000e+00 * (({
                                                     double tmppowvar = DELTA_Y;
                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   TX0)) +
                      (-2.00000000000000000e+00 * (({
                                                     double tmppowvar = DELTA_Y;
                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   st->x2))) *
                     (st->y2 * st->y3)) +
                    (((({
                         double tmppowvar = DELTA_Y;
                         (tmppowvar * tmppowvar);
                       }) *
                       TX0) +
                      (({
                         double tmppowvar = DELTA_Y;
                         (tmppowvar * tmppowvar);
                       }) *
                       st->x2)) *
                     ({
                       double tmppowvar = st->y3;
                       (tmppowvar * tmppowvar);
                     })))))))))) +
            ((1.00000000000000000e+00 / ({
                double tmppowvar = DELTA_X;
                (tmppowvar * tmppowvar);
              })) *
             (-1 * (Deltat * (QE_MASS * iBx)))));

  st->s_rx3x = ((st->x3 - XO) - floor((st->x3 - XO)));
  st->s_dix3x = (floor((st->x3 - XO)) - Midx);
}

/* -------------------------------------------------------------------------- */
/* K2 B-integral combination wrappers (Step F: split K2 call chain) */
/* Each returns one corrected B integral; math/order preserved bit-exact. */
/* -------------------------------------------------------------------------- */

static __device__ __noinline__ double pushJ_vlo_K2_compute_iBy(const pushJ_vlo_state_t *st, const double *shB0,
                                                               const double *shB1) {
  double iBy_term0 = pushJ_B_integralS_comp2_f0z_dif1x_f1y(shB0, st->s_rx1z, st->s_dix1z, st->s_rx1x, st->s_dix1x,
                                                           st->s_rx0x, st->s_dix0x, st->s_rx1y, st->s_dix1y);
  double iBy_term1 = pushJ_B_integralS_comp2_f0z_dif1x_f1y(shB1, st->s_rx1z, st->s_dix1z, st->s_rx2x, st->s_dix2x,
                                                           st->s_rx1x, st->s_dix1x, st->s_rx1y, st->s_dix1y);
  return (iBy_term0 + iBy_term1);
}

static __device__ __noinline__ double pushJ_vlo_K2_compute_iBz(const pushJ_vlo_state_t *st, const double *shB0,
                                                               const double *shB1) {
  double iBz_term1 = pushJ_B_integralS_comp0_f0x_dif1y_f1z(shB0, st->s_rx0x, st->s_dix0x, st->s_rx1y, st->s_dix1y,
                                                           st->s_rx0y, st->s_dix0y, st->s_rx1z, st->s_dix1z);
  double iBz_term2 = pushJ_B_integralS_comp1_f0y_dif1x_f1z(shB0, st->s_rx1y, st->s_dix1y, st->s_rx1x, st->s_dix1x,
                                                           st->s_rx0x, st->s_dix0x, st->s_rx1z, st->s_dix1z);
  double iBz_term3 = pushJ_B_integralS_comp0_f0x_dif1y_f1z(shB1, st->s_rx2x, st->s_dix2x, st->s_rx2y, st->s_dix2y,
                                                           st->s_rx1y, st->s_dix1y, st->s_rx1z, st->s_dix1z);
  double iBz_term4 = pushJ_B_integralS_comp1_f0y_dif1x_f1z(shB1, st->s_rx1y, st->s_dix1y, st->s_rx2x, st->s_dix2x,
                                                           st->s_rx1x, st->s_dix1x, st->s_rx1z, st->s_dix1z);
  double inner =
      ((-1.00000000000000000e+00 * iBz_term1) + iBz_term2 + (-1.00000000000000000e+00 * iBz_term3) + iBz_term4);
  return (-1.00000000000000000e+00 * inner);
}

static __device__ __noinline__ double pushJ_vlo_K2_compute_iBy23(const pushJ_vlo_state_t *st, const double *shB1) {
  return ((-1.00000000000000000e+00 * pushJ_B_integralS_comp0_f0x_dif1z_f1y(shB1, st->s_rx2x, st->s_dix2x, st->s_rx2z,
                                                                            st->s_dix2z, st->s_rx1z, st->s_dix1z,
                                                                            st->s_rx2y, st->s_dix2y)) +
          (-1.00000000000000000e+00 * pushJ_B_integralS_comp0_f0x_dif1z_f1y(shB1, st->s_rx2x, st->s_dix2x, st->s_rx3z,
                                                                            st->s_dix3z, st->s_rx2z, st->s_dix2z,
                                                                            st->s_rx2y, st->s_dix2y)));
}

static __device__ __noinline__ double pushJ_vlo_K2_compute_iBx(const pushJ_vlo_state_t *st, const double *shB1) {
  return (pushJ_B_integralS_comp1_f0y_dif1z_f1x(shB1, st->s_rx2y, st->s_dix2y, st->s_rx2z, st->s_dix2z, st->s_rx1z,
                                                st->s_dix1z, st->s_rx2x, st->s_dix2x) +
          pushJ_B_integralS_comp1_f0y_dif1z_f1x(shB1, st->s_rx2y, st->s_dix2y, st->s_rx3z, st->s_dix3z, st->s_rx2z,
                                                st->s_dix2z, st->s_rx2x, st->s_dix2x) +
          (-1.00000000000000000e+00) * pushJ_B_integralS_comp2_f0z_dif1y_f1x(shB1, st->s_rx1z, st->s_dix1z, st->s_rx2y,
                                                                             st->s_dix2y, st->s_rx1y, st->s_dix1y,
                                                                             st->s_rx2x, st->s_dix2x) +
          (-1.00000000000000000e+00) * pushJ_B_integralS_comp2_f0z_dif1y_f1x(shB1, st->s_rx3z, st->s_dix3z, st->s_rx3y,
                                                                             st->s_dix3y, st->s_rx2y, st->s_dix2y,
                                                                             st->s_rx2x, st->s_dix2x));
}

/* -------------------------------------------------------------------------- */
/* K2 Verlet stage splits (Step G/H): shorten live range per stage callee */
/* -------------------------------------------------------------------------- */

static __device__ __noinline__ void pushJ_vlo_K2_stage1a_E(const pushJ_vlo_state_t *st, const double *shE0,
                                                           double Deltat, double *allincfvx_out, double *allincfvy_out,
                                                           double *allincfvz_out) {
  const double AllEx =
      pushJ_E_interp_Ex(shE0, st->s_rx1x, st->s_dix1x, st->s_rx1y, st->s_dix1y, st->s_rx1z, st->s_dix1z);
  const double AllEy =
      pushJ_E_interp_Ey(shE0, st->s_rx1x, st->s_dix1x, st->s_rx1y, st->s_dix1y, st->s_rx1z, st->s_dix1z);
  const double AllEz =
      pushJ_E_interp_Ez(shE0, st->s_rx1x, st->s_dix1x, st->s_rx1y, st->s_dix1y, st->s_rx1z, st->s_dix1z);
  *allincfvx_out = (2.00000000000000000e+00 * (Deltat * AllEx));
  *allincfvy_out = (2.00000000000000000e+00 * (Deltat * AllEy));
  *allincfvz_out = (2.00000000000000000e+00 * (Deltat * AllEz));
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage1b_x2y2(pushJ_vlo_state_t *st, const double *shB0, const double *shB1, double x0, double x1,
                          double y0, double y1, double allincfvx, double allincfvy, double DELTA_X, double DELTA_Y,
                          double Deltat, double TX0, double QE_MASS, double XO, double YO, double Midx, double Midy) {
  pushJ_vlo_K2_push_x2(st, x0, x1, allincfvx, DELTA_X, Deltat, QE_MASS, XO, Midx);

  const double iBy = pushJ_vlo_K2_compute_iBy(st, shB0, shB1);

  pushJ_vlo_K2_push_y2(st, x0, y0, y1, iBy, allincfvy, TX0, DELTA_Y, Deltat, QE_MASS, YO, Midy);
}

static __device__ __noinline__ void pushJ_vlo_K2_stage2_z2z3(pushJ_vlo_state_t *st, const double *shB0,
                                                             const double *shB1, double z0, double z1, double allincfvz,
                                                             double DELTA_Z, double Deltat, double QE_MASS, double ZO,
                                                             double zmid, double Midz) {
  const double iBz = pushJ_vlo_K2_compute_iBz(st, shB0, shB1);

  pushJ_vlo_K2_push_z2_z3(st, z0, z1, iBz, allincfvz, DELTA_Z, Deltat, QE_MASS, ZO, zmid, Midz);
}

static __device__ __noinline__ void pushJ_vlo_K2_stage3a_y3(pushJ_vlo_state_t *st, const double *shB1, double y1,
                                                            double TX0, double DELTA_Y, double Deltat, double QE_MASS,
                                                            double YO, double Midy) {
  const double iBy23 = pushJ_vlo_K2_compute_iBy23(st, shB1);

  pushJ_vlo_K2_push_y3(st, y1, iBy23, TX0, DELTA_Y, Deltat, QE_MASS, YO, Midy);
}

static __device__ __noinline__ void pushJ_vlo_K2_stage3b_x3(pushJ_vlo_state_t *st, const double *shB1, double x1,
                                                            double y1, double TX0, double DELTA_X, double DELTA_Y,
                                                            double Deltat, double QE_MASS, double XO, double Midx) {
  const double iBx = pushJ_vlo_K2_compute_iBx(st, shB1);

  pushJ_vlo_K2_push_x3(st, x1, y1, iBx, TX0, DELTA_X, DELTA_Y, Deltat, QE_MASS, XO, Midx);
}

static __device__ __noinline__ void
pushJ_vlo_K2_stage1_E_x2y2(pushJ_vlo_state_t *st, const double *shE0, const double *shB0, const double *shB1, double x0,
                           double x1, double y0, double y1, double DELTA_X, double DELTA_Y, double Deltat, double TX0,
                           double QE_MASS, double XO, double YO, double Midx, double Midy, double *allincfvz_out) {
  double allincfvx, allincfvy;
  pushJ_vlo_K2_stage1a_E(st, shE0, Deltat, &allincfvx, &allincfvy, allincfvz_out);
  pushJ_vlo_K2_stage1b_x2y2(st, shB0, shB1, x0, x1, y0, y1, allincfvx, allincfvy, DELTA_X, DELTA_Y, Deltat, TX0,
                            QE_MASS, XO, YO, Midx, Midy);
}

static __device__ __noinline__ void pushJ_vlo_K2_stage3_y3x3(pushJ_vlo_state_t *st, const double *shB1, double x1,
                                                             double y1, double TX0, double DELTA_X, double DELTA_Y,
                                                             double Deltat, double QE_MASS, double XO, double YO,
                                                             double Midx, double Midy) {
  pushJ_vlo_K2_stage3a_y3(st, shB1, y1, TX0, DELTA_Y, Deltat, QE_MASS, YO, Midy);
  pushJ_vlo_K2_stage3b_x3(st, shB1, x1, y1, TX0, DELTA_X, DELTA_Y, Deltat, QE_MASS, XO, Midx);
}

static __device__ __noinline__ void pushJ_vlo_K2_push_weights_x2x3(pushJ_vlo_state_t *st, const double *shE0,
                                                                   const double *shB0, const double *shB1,
                                                                   double DELTA_X, double DELTA_Y, double DELTA_Z,
                                                                   double Deltat, double Tori_X0, double QE_MASS,
                                                                   double XO, double YO, double ZO, double zmid,
                                                                   double Midx, double Midy, double Midz) {
  const double TX0 = Tori_X0;
  const double x0 = (st->xx0 + XO);
  const double y0 = (st->xy0 + YO);
  const double z0 = ((st->xz0 + ZO) - zmid);
  const double x1 = (st->xx1 + XO);
  const double y1 = (st->xy1 + YO);
  const double z1 = ((st->xz1 + ZO) - zmid);

  double allincfvz;
  pushJ_vlo_K2_stage1_E_x2y2(st, shE0, shB0, shB1, x0, x1, y0, y1, DELTA_X, DELTA_Y, Deltat, TX0, QE_MASS, XO, YO, Midx,
                             Midy, &allincfvz);
  pushJ_vlo_K2_stage2_z2z3(st, shB0, shB1, z0, z1, allincfvz, DELTA_Z, Deltat, QE_MASS, ZO, zmid, Midz);
  pushJ_vlo_K2_stage3_y3x3(st, shB1, x1, y1, TX0, DELTA_X, DELTA_Y, Deltat, QE_MASS, XO, YO, Midx, Midy);
}

static __device__ __noinline__ void
pushJ_vlo_K3_deposit_writeback_particle(pushJ_vlo_state_t *st, double *shJ0, double *Jtmp_shd, double *particle_buf,
                                        double Deltat, long __idx, long __xlen, int g_inner, long load0, double Charge0,
                                        double Tori_X0, double grid_geo_x, double grid_geo_y, double grid_geo_z,
                                        double XO, double YO, double ZO, double zmid, int bBidx, int bBidy, int bBidz) {
  pushJ_vlo_deposit_Jx12(st->s_rx1x, st->s_dix1x, st->s_rx2x, st->s_dix2x, st->s_rx1y, st->s_dix1y, st->s_rx1z,
                         st->s_dix1z, st->simd_mask, st->_gen_long_for_opt_loop_already_idx_0, __idx, shJ0, Jtmp_shd,
                         grid_geo_x, Charge0, Tori_X0, XO, bBidx);
  pushJ_vlo_deposit_Jy12(st->s_rx1y, st->s_dix1y, st->s_rx2y, st->s_dix2y, st->s_rx2x, st->s_dix2x, st->s_rx1z,
                         st->s_dix1z, st->simd_mask, st->_gen_long_for_opt_loop_already_idx_0, __idx, shJ0, Jtmp_shd,
                         grid_geo_y, Charge0, Tori_X0, XO, bBidx);
  pushJ_vlo_deposit_Jz13(st->s_rx1z, st->s_dix1z, st->s_rx3z, st->s_dix3z, st->s_rx2x, st->s_dix2x, st->s_rx2y,
                         st->s_dix2y, st->simd_mask, st->_gen_long_for_opt_loop_already_idx_0, __idx, shJ0, Jtmp_shd,
                         grid_geo_z, Charge0, Tori_X0, XO, bBidx);
  pushJ_vlo_deposit_Jy23(st->s_rx2y, st->s_dix2y, st->s_rx3y, st->s_dix3y, st->s_rx2x, st->s_dix2x, st->s_rx3z,
                         st->s_dix3z, st->simd_mask, st->_gen_long_for_opt_loop_already_idx_0, __idx, shJ0, Jtmp_shd,
                         grid_geo_y, Charge0, Tori_X0, XO, bBidx);
  pushJ_vlo_deposit_Jx23(st->s_rx2x, st->s_dix2x, st->s_rx3x, st->s_dix3x, st->s_rx3y, st->s_dix3y, st->s_rx3z,
                         st->s_dix3z, st->simd_mask, st->_gen_long_for_opt_loop_already_idx_0, __idx, shJ0, Jtmp_shd,
                         grid_geo_x, Charge0, Tori_X0, XO, bBidx);

  double newvx = ((st->x3 - st->x2) / Deltat);
  double newvy = ((st->y3 - st->y2) / Deltat);
  double newvz = ((st->z3 - st->z2) / Deltat);
  double newxx = (st->x3 - XO);
  double newxy = (st->y3 - YO);
  double newxz = ((st->z3 + zmid) - ZO);
  (newxx = (newxx + 5.00000000000000000e-01));
  (newxy = (newxy + 5.00000000000000000e-01));
  (newxz = (newxz + 5.00000000000000000e-01));
  {
    long stmpg1;
    for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
      int cid = (g_inner + __idx);
      if (cid < load0) {
        const int poff = stmpg1 + cid * 6;
        if (stmpg1 == 0) {
          particle_buf[poff] = newxx;
        } else if (stmpg1 == 1) {
          particle_buf[poff] = newxy;
        } else if (stmpg1 == 2) {
          particle_buf[poff] = newxz;
        } else if (stmpg1 == 3) {
          particle_buf[poff] = newvx;
        } else if (stmpg1 == 4) {
          particle_buf[poff] = newvy;
        } else {
          particle_buf[poff] = newvz;
        }
      }
    }
  }
}

static __device__ __forceinline__ void pushJ_vlo_K3_write_FoutJ_from_shared(double *shJ0, double *FoutJ, long __idy,
                                                                            long __idx, long __xlen, int bBidx,
                                                                            int bBidy, int bBidz, long XLEN, long YLEN,
                                                                            long ZLEN, int ovlp, int num_ele) {
  long xyzz;

  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    {
      long xyzy;

      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
        {
          long xyzx;

          for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
            int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

            {
              long lgGG817621_1 = 0;

              for (; (lgGG817621_1 < (3 * 5)); (lgGG817621_1 = (lgGG817621_1 + __xlen))) {
                int ridx = (lgGG817621_1 + __idx);

                if (ridx < (3 * 5)) {
                  (((FoutJ +
                     ((num_ele * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                      (0 + (num_ele *
                            ((bBidx + ovlp) +
                             ((XLEN + (2 * ovlp)) *
                              (((xyzy + bBidy) + ovlp) + ((YLEN + (2 * ovlp)) * ((xyzz + bBidz) + ovlp))))))))))[ridx] =
                       ((shJ0 + total_idx))[ridx]);
                }
              }
            }
          }
        }
      }
    }
  }
}

#endif

/* Whitney 1D weight evaluators — bit-exact with inlined pushJ_vlo_split.cuh logic */
#ifndef PUSHJ_WEIGHTS_CUH
#define PUSHJ_WEIGHTS_CUH

#include "scale_simd.h"

__device__ __noinline__ void eval_f0(v8fp64 rx, v8fp64 dix, v8fp64 f0[5]) {
  long i;
  for (i = 0; i < 5; i++) {
    f0[i] = vbroadcast(0.0);
  }
  {
    v8fp64 tmppowvar = (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx));
    f0[1] = (2.50000000000000000e-01 * (tmppowvar * tmppowvar));
  }
  f0[0] = (f0[0] * (dix + 1.00000000000000000e+00) + f0[1] * -(dix));
  {
    v8fp64 tmppowvar = (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx));
    f0[2] = (-2.50000000000000000e-01 *
             (-1.00000000000000000e+00 +
              ((tmppowvar * tmppowvar) +
               (-2.00000000000000000e+00 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx))))));
  }
  f0[1] = (f0[1] * (dix + 1.00000000000000000e+00) + f0[2] * -(dix));
  {
    v8fp64 tmppowvar = rx;
    f0[3] = (-2.50000000000000000e-01 *
             (-1.00000000000000000e+00 +
              ((-2.00000000000000000e+00 * rx) + (tmppowvar * tmppowvar))));
  }
  f0[2] = (f0[2] * (dix + 1.00000000000000000e+00) + f0[3] * -(dix));
  {
    v8fp64 tmppowvar = rx;
    f0[4] = (2.50000000000000000e-01 * (tmppowvar * tmppowvar));
  }
  f0[3] = (f0[3] * (dix + 1.00000000000000000e+00) + f0[4] * -(dix));
  f0[4] = (f0[4] * (dix + 1.00000000000000000e+00));
}

__device__ __noinline__ void eval_f1(v8fp64 rx, v8fp64 dix, v8fp64 f1[5]) {
  long i;
  for (i = 0; i < 5; i++) {
    f1[i] = vbroadcast(0.0);
  }
  f1[1] =
      (5.00000000000000000e-01 *
       (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx)));
  f1[0] = (f1[0] * (dix + 1.00000000000000000e+00) + f1[1] * -(dix));
  f1[2] =
      ((2.50000000000000000e-01 *
        (2.00000000000000000e+00 +
         (-2.00000000000000000e+00 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx))))) +
       (5.00000000000000000e-01 *
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx))));
  f1[1] = (f1[1] * (dix + 1.00000000000000000e+00) + f1[2] * -(dix));
  f1[3] = (5.00000000000000000e-01 * rx);
  f1[2] = (f1[2] * (dix + 1.00000000000000000e+00) + f1[3] * -(dix));
  f1[3] = (f1[3] * (dix + 1.00000000000000000e+00));
}

__device__ __noinline__ void eval_if1(v8fp64 rx, v8fp64 dix, v8fp64 if1[5]) {
  if1[0] = vbroadcast(1.0);
  if1[1] = vbroadcast(1.0);
  if1[3] = vbroadcast(0.0);
  if1[4] = vbroadcast(0.0);
  {
    v8fp64 tmppowvar = (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx));
    if1[1] =
        (1.00000000000000000e+00 + (-2.50000000000000000e-01 * (tmppowvar * tmppowvar)));
  }
  if1[0] = (if1[0] * (dix + 1.00000000000000000e+00) + if1[1] * -(dix));
  {
    v8fp64 tmppowvar = rx;
    if1[2] =
        ((2.50000000000000000e-01 * (tmppowvar * tmppowvar)) +
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 +
           ((-2.00000000000000000e+00 * rx) + (tmppowvar * tmppowvar)))));
  }
  if1[1] = (if1[1] * (dix + 1.00000000000000000e+00) + if1[2] * -(dix));
  {
    v8fp64 tmppowvar = rx;
    if1[3] = (2.50000000000000000e-01 * (tmppowvar * tmppowvar));
  }
  if1[2] = (if1[2] * (dix + 1.00000000000000000e+00) + if1[3] * -(dix));
  if1[3] = (if1[3] * (dix + 1.00000000000000000e+00));
}

/* -------------------------------------------------------------------------- */
/* 3D B-field integral helpers (bit-exact loop order)                          */
/*                                                                             */
/* Each helper matches one of the inline K2 tmpBfd triple-loop patterns in   */
/* cuda_/pushJ_vlo_split.cuh, so we can move the big live `[5]` weight arrays */
/* into the callee frame and (critically) release them on `ret`.             */
/*                                                                             */
/* Notes:                                                                     */
/* - Field layout: field[(allidx*3) + comp], where allidx= x + 5*(y + 5*z)  */
/* - Loop order preserved: z(0..4) -> y(0..4) -> x(0..4) inside allidx computation */
/* -------------------------------------------------------------------------- */

__device__ __noinline__ double
pushJ_B_integral_comp2_f0z_dif1x_f1y(const double *field, const double *f0z,
                                      const double *if1x_hi,
                                      const double *if1x_lo,
                                      const double *f1y) {
  double sum = 0.0;
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 2)] *
                       (f0z[xyzz] *
                        (((if1x_hi[xyzx] - if1x_lo[xyzx]) * f1y[xyzy])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ double
pushJ_B_integral_comp0_f0x_dif1y_f1z(const double *field, const double *f0x,
                                      const double *if1y_hi,
                                      const double *if1y_lo,
                                      const double *f1z) {
  double sum = 0.0;
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 0)] *
                       (f0x[xyzx] *
                        (((if1y_hi[xyzy] - if1y_lo[xyzy]) * f1z[xyzz])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ double
pushJ_B_integral_comp1_f0y_dif1x_f1z(const double *field, const double *f0y,
                                      const double *if1x_hi,
                                      const double *if1x_lo,
                                      const double *f1z) {
  double sum = 0.0;
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 1)] *
                       (f0y[xyzy] *
                        (((if1x_hi[xyzx] - if1x_lo[xyzx]) * f1z[xyzz])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ double
pushJ_B_integral_comp0_f0x_dif1z_f1y(const double *field, const double *f0x,
                                      const double *if1z_hi,
                                      const double *if1z_lo,
                                      const double *f1y) {
  double sum = 0.0;
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 0)] *
                       (f0x[xyzx] *
                        (((if1z_hi[xyzz] - if1z_lo[xyzz]) * f1y[xyzy])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ double
pushJ_B_integral_comp1_f0y_dif1z_f1x(const double *field, const double *f0y,
                                      const double *if1z_hi,
                                      const double *if1z_lo,
                                      const double *f1x) {
  double sum = 0.0;
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 1)] *
                       (f0y[xyzy] *
                        (((if1z_hi[xyzz] - if1z_lo[xyzz]) * f1x[xyzx])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ double
pushJ_B_integral_comp2_f0z_dif1y_f1x(const double *field, const double *f0z,
                                      const double *if1y_hi,
                                      const double *if1y_lo,
                                      const double *f1x) {
  double sum = 0.0;
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 2)] *
                       (f0z[xyzz] *
                        (((if1y_hi[xyzy] - if1y_lo[xyzy]) * f1x[xyzx])))));
      }
    }
  }
  return sum;
}

/* Scalar-input variants: recompute `[5]` weights inside the callee */

__device__ __noinline__ v8fp64
pushJ_B_integralS_comp2_f0z_dif1x_f1y(v8fp64 *scr, const double *field,
                                       v8fp64 rx_f0z, v8fp64 dix_f0z,
                                       v8fp64 rx_if1x_hi, v8fp64 dix_if1x_hi,
                                       v8fp64 rx_if1x_lo, v8fp64 dix_if1x_lo,
                                       v8fp64 rx_f1y, v8fp64 dix_f1y) {
  v8fp64 *wF0z = scr + 0;
  v8fp64 *wHiX = scr + 5;
  v8fp64 *wLoX = scr + 10;
  v8fp64 *wF1y = scr + 15;
  eval_f0(rx_f0z, dix_f0z, wF0z);
  eval_if1(rx_if1x_hi, dix_if1x_hi, wHiX);
  eval_if1(rx_if1x_lo, dix_if1x_lo, wLoX);
  eval_f1(rx_f1y, dix_f1y, wF1y);

  v8fp64 sum = vbroadcast(0.0);
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 2)] *
                       (wF0z[xyzz] *
                        (((wHiX[xyzx] - wLoX[xyzx]) * wF1y[xyzy])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ v8fp64
pushJ_B_integralS_comp0_f0x_dif1y_f1z(v8fp64 *scr, const double *field,
                                       v8fp64 rx_f0x, v8fp64 dix_f0x,
                                       v8fp64 rx_if1y_hi, v8fp64 dix_if1y_hi,
                                       v8fp64 rx_if1y_lo, v8fp64 dix_if1y_lo,
                                       v8fp64 rx_f1z, v8fp64 dix_f1z) {
  v8fp64 *wF0x = scr + 0;
  v8fp64 *wHiY = scr + 5;
  v8fp64 *wLoY = scr + 10;
  v8fp64 *wF1z = scr + 15;
  eval_f0(rx_f0x, dix_f0x, wF0x);
  eval_if1(rx_if1y_hi, dix_if1y_hi, wHiY);
  eval_if1(rx_if1y_lo, dix_if1y_lo, wLoY);
  eval_f1(rx_f1z, dix_f1z, wF1z);

  v8fp64 sum = vbroadcast(0.0);
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 0)] *
                       (wF0x[xyzx] *
                        (((wHiY[xyzy] - wLoY[xyzy]) * wF1z[xyzz])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ v8fp64
pushJ_B_integralS_comp1_f0y_dif1x_f1z(v8fp64 *scr, const double *field,
                                       v8fp64 rx_f0y, v8fp64 dix_f0y,
                                       v8fp64 rx_if1x_hi, v8fp64 dix_if1x_hi,
                                       v8fp64 rx_if1x_lo, v8fp64 dix_if1x_lo,
                                       v8fp64 rx_f1z, v8fp64 dix_f1z) {
  v8fp64 *wF0y = scr + 0;
  v8fp64 *wHiX = scr + 5;
  v8fp64 *wLoX = scr + 10;
  v8fp64 *wF1z = scr + 15;
  eval_f0(rx_f0y, dix_f0y, wF0y);
  eval_if1(rx_if1x_hi, dix_if1x_hi, wHiX);
  eval_if1(rx_if1x_lo, dix_if1x_lo, wLoX);
  eval_f1(rx_f1z, dix_f1z, wF1z);

  v8fp64 sum = vbroadcast(0.0);
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 1)] *
                       (wF0y[xyzy] *
                        (((wHiX[xyzx] - wLoX[xyzx]) * wF1z[xyzz])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ v8fp64
pushJ_B_integralS_comp0_f0x_dif1z_f1y(v8fp64 *scr, const double *field,
                                       v8fp64 rx_f0x, v8fp64 dix_f0x,
                                       v8fp64 rx_if1z_hi, v8fp64 dix_if1z_hi,
                                       v8fp64 rx_if1z_lo, v8fp64 dix_if1z_lo,
                                       v8fp64 rx_f1y, v8fp64 dix_f1y) {
  v8fp64 *wF0x = scr + 0;
  v8fp64 *wHiZ = scr + 5;
  v8fp64 *wLoZ = scr + 10;
  v8fp64 *wF1y = scr + 15;
  eval_f0(rx_f0x, dix_f0x, wF0x);
  eval_if1(rx_if1z_hi, dix_if1z_hi, wHiZ);
  eval_if1(rx_if1z_lo, dix_if1z_lo, wLoZ);
  eval_f1(rx_f1y, dix_f1y, wF1y);

  v8fp64 sum = vbroadcast(0.0);
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 0)] *
                       (wF0x[xyzx] *
                        (((wHiZ[xyzz] - wLoZ[xyzz]) * wF1y[xyzy])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ v8fp64
pushJ_B_integralS_comp1_f0y_dif1z_f1x(v8fp64 *scr, const double *field,
                                       v8fp64 rx_f0y, v8fp64 dix_f0y,
                                       v8fp64 rx_if1z_hi, v8fp64 dix_if1z_hi,
                                       v8fp64 rx_if1z_lo, v8fp64 dix_if1z_lo,
                                       v8fp64 rx_f1x, v8fp64 dix_f1x) {
  v8fp64 *wF0y = scr + 0;
  v8fp64 *wHiZ = scr + 5;
  v8fp64 *wLoZ = scr + 10;
  v8fp64 *wF1x = scr + 15;
  eval_f0(rx_f0y, dix_f0y, wF0y);
  eval_if1(rx_if1z_hi, dix_if1z_hi, wHiZ);
  eval_if1(rx_if1z_lo, dix_if1z_lo, wLoZ);
  eval_f1(rx_f1x, dix_f1x, wF1x);

  v8fp64 sum = vbroadcast(0.0);
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 1)] *
                       (wF0y[xyzy] *
                        (((wHiZ[xyzz] - wLoZ[xyzz]) * wF1x[xyzx])))));
      }
    }
  }
  return sum;
}

__device__ __noinline__ v8fp64
pushJ_B_integralS_comp2_f0z_dif1y_f1x(v8fp64 *scr, const double *field,
                                       v8fp64 rx_f0z, v8fp64 dix_f0z,
                                       v8fp64 rx_if1y_hi, v8fp64 dix_if1y_hi,
                                       v8fp64 rx_if1y_lo, v8fp64 dix_if1y_lo,
                                       v8fp64 rx_f1x, v8fp64 dix_f1x) {
  v8fp64 *wF0z = scr + 0;
  v8fp64 *wHiY = scr + 5;
  v8fp64 *wLoY = scr + 10;
  v8fp64 *wF1x = scr + 15;
  eval_f0(rx_f0z, dix_f0z, wF0z);
  eval_if1(rx_if1y_hi, dix_if1y_hi, wHiY);
  eval_if1(rx_if1y_lo, dix_if1y_lo, wLoY);
  eval_f1(rx_f1x, dix_f1x, wF1x);

  v8fp64 sum = vbroadcast(0.0);
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum = sum + ((field[((allidx * 3) + 2)] *
                       (wF0z[xyzz] *
                        (((wHiY[xyzy] - wLoY[xyzy]) * wF1x[xyzx])))));
      }
    }
  }
  return sum;
}

/* E-field interpolation helpers (K2, t1) — one component per callee to shorten
 * [5] weight live range (SCALE 4KB / register pressure). */

__device__ __noinline__ v8fp64
pushJ_E_interp_Ex(v8fp64 *scr, const double *shE0, v8fp64 rx1x, v8fp64 dix1x,
                  v8fp64 rx1y, v8fp64 dix1y, v8fp64 rx1z, v8fp64 dix1z) {
  v8fp64 *f1_x1 = scr + 0;
  v8fp64 *f0_y1 = scr + 5;
  v8fp64 *f0_z1 = scr + 10;
  eval_f1(rx1x, dix1x, f1_x1);
  eval_f0(rx1y, dix1y, f0_y1);
  eval_f0(rx1z, dix1z, f0_z1);

  v8fp64 AllEx = vbroadcast(0.0);
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            (vbroadcast(((shE0)[(0 + (3 * (idx + (5 * (idy + (idz * 5))))))] + 0)) *
             ((f1_x1)[idx] * ((f0_y1)[idy] * (f0_z1)[idz])));
        AllEx = (AllEx + term);
      }
    }
  }
  return AllEx;
}

__device__ __noinline__ v8fp64
pushJ_E_interp_Ey(v8fp64 *scr, const double *shE0, v8fp64 rx1x, v8fp64 dix1x,
                  v8fp64 rx1y, v8fp64 dix1y, v8fp64 rx1z, v8fp64 dix1z) {
  v8fp64 *f1_y1 = scr + 0;
  v8fp64 *f0_z1 = scr + 5;
  v8fp64 *f0_x1 = scr + 10;
  eval_f1(rx1y, dix1y, f1_y1);
  eval_f0(rx1z, dix1z, f0_z1);
  eval_f0(rx1x, dix1x, f0_x1);

  v8fp64 AllEy = vbroadcast(0.0);
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            (vbroadcast(((shE0)[(1 + (3 * (idz + (5 * (idx + (idy * 5))))))] + 0)) *
             ((f1_y1)[idx] * ((f0_z1)[idy] * (f0_x1)[idz])));
        AllEy = (AllEy + term);
      }
    }
  }
  return AllEy;
}

__device__ __noinline__ v8fp64
pushJ_E_interp_Ez(v8fp64 *scr, const double *shE0, v8fp64 rx1x, v8fp64 dix1x,
                  v8fp64 rx1y, v8fp64 dix1y, v8fp64 rx1z, v8fp64 dix1z) {
  v8fp64 *f1_z1 = scr + 0;
  v8fp64 *f0_x1 = scr + 5;
  v8fp64 *f0_y1 = scr + 10;
  eval_f1(rx1z, dix1z, f1_z1);
  eval_f0(rx1x, dix1x, f0_x1);
  eval_f0(rx1y, dix1y, f0_y1);

  v8fp64 AllEz = vbroadcast(0.0);
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            (vbroadcast(((shE0)[(2 + (3 * (idy + (5 * (idz + (idx * 5))))))] + 0)) *
             ((f1_z1)[idx] * ((f0_x1)[idy] * (f0_y1)[idz])));
        AllEz = (AllEz + term);
      }
    }
  }
  return AllEz;
}

#endif /* PUSHJ_WEIGHTS_CUH */

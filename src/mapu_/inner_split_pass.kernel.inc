#include "cooperative_groups.h"
#include "local_header.h"
#include <maps_runtime.h>
#include <scale.h>
#include <scale/barrier>

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif

#ifndef MAPU_LONG
#define MAPU_LONG long long
#endif

/* All helpers in this header are MPU-internal. Keeping them static is legal
 * because no SPU function calls them directly after the K1 entry refactor.
 */

static __device__ KERNEL_M __noinline__ void eval_f0(v8fp64 rx, v8fp64 dix,
                                                     v8fp64 f0[5]) {
  long i;
  for (i = 0; i < 5; i++) {
    f0[i] = (v8fp64){};
  }
  {
    v8fp64 tmppowvar =
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx));
    f0[1] = (2.50000000000000000e-01 * (tmppowvar * tmppowvar));
  }
  f0[0] = (f0[0] * (dix + 1.00000000000000000e+00) + f0[1] * -(dix));
  {
    v8fp64 tmppowvar =
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx));
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

static __device__ KERNEL_M __noinline__ void eval_f1(v8fp64 rx, v8fp64 dix,
                                                     v8fp64 f1[5]) {
  long i;
  for (i = 0; i < 5; i++) {
    f1[i] = (v8fp64){};
  }
  f1[1] = (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx)));
  f1[0] = (f1[0] * (dix + 1.00000000000000000e+00) + f1[1] * -(dix));
  f1[2] = ((2.50000000000000000e-01 *
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

static __device__ KERNEL_M __noinline__ void eval_if1(v8fp64 rx, v8fp64 dix,
                                                      v8fp64 if1[5]) {
  if1[0] = (1.00000000000000000e+00 - (v8fp64){});
  if1[1] = (1.00000000000000000e+00 - (v8fp64){});
  if1[3] = (v8fp64){};
  if1[4] = (v8fp64){};
  {
    v8fp64 tmppowvar =
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx));
    if1[1] = (1.00000000000000000e+00 +
              (-2.50000000000000000e-01 * (tmppowvar * tmppowvar)));
  }
  if1[0] = (if1[0] * (dix + 1.00000000000000000e+00) + if1[1] * -(dix));
  {
    v8fp64 tmppowvar = rx;
    if1[2] = ((2.50000000000000000e-01 * (tmppowvar * tmppowvar)) +
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
/* Precomputed weight bank — DM2 __mem2__ __fix2__ (REPORT §3.2) */
/* 4 positions × 9 arrays (f0/f1/if1 × x/y/z) = 36 slots × [5] v8fp64        */
/* -------------------------------------------------------------------------- */

#define PUSHJ_WT_SLOTS_PER_POS 9
#define PUSHJ_WT_POS_COUNT 4
#define PUSHJ_WT_SLOT_COUNT (PUSHJ_WT_POS_COUNT * PUSHJ_WT_SLOTS_PER_POS)

#define pjw_pos_base(p) ((p) * PUSHJ_WT_SLOTS_PER_POS)
#define pjw_f0_x(p) (pjw_pos_base(p) + 0)
#define pjw_f1_x(p) (pjw_pos_base(p) + 1)
#define pjw_if1_x(p) (pjw_pos_base(p) + 2)
#define pjw_f0_y(p) (pjw_pos_base(p) + 3)
#define pjw_f1_y(p) (pjw_pos_base(p) + 4)
#define pjw_if1_y(p) (pjw_pos_base(p) + 5)
#define pjw_f0_z(p) (pjw_pos_base(p) + 6)
#define pjw_f1_z(p) (pjw_pos_base(p) + 7)
#define pjw_if1_z(p) (pjw_pos_base(p) + 8)
#define pushJ_wt_slot(bank, slot_idx) ((bank)->slot[slot_idx])

typedef struct {
  v8fp64 slot[PUSHJ_WT_SLOT_COUNT][5];
} pushJ_weight_bank_t;

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_axis_f0(v8fp64 *dst, v8fp64 rx, v8fp64 dix) {
  eval_f0(rx, dix, dst);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_axis_f1(v8fp64 *dst, v8fp64 rx, v8fp64 dix) {
  eval_f1(rx, dix, dst);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_axis_if1(v8fp64 *dst, v8fp64 rx, v8fp64 dix) {
  eval_if1(rx, dix, dst);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_xyz(pushJ_weight_bank_t *bank, int pos, v8fp64 rx_x,
                      v8fp64 dix_x, v8fp64 rx_y, v8fp64 dix_y, v8fp64 rx_z,
                      v8fp64 dix_z) {
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_x(pos)), rx_x, dix_x);
  pushJ_wt_fill_axis_f1(pushJ_wt_slot(bank, pjw_f1_x(pos)), rx_x, dix_x);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_x(pos)), rx_x, dix_x);
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_y(pos)), rx_y, dix_y);
  pushJ_wt_fill_axis_f1(pushJ_wt_slot(bank, pjw_f1_y(pos)), rx_y, dix_y);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_y(pos)), rx_y, dix_y);
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_z(pos)), rx_z, dix_z);
  pushJ_wt_fill_axis_f1(pushJ_wt_slot(bank, pjw_f1_z(pos)), rx_z, dix_z);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_z(pos)), rx_z, dix_z);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_x(pushJ_weight_bank_t *bank, int pos, v8fp64 rx, v8fp64 dix) {
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_x(pos)), rx, dix);
  pushJ_wt_fill_axis_f1(pushJ_wt_slot(bank, pjw_f1_x(pos)), rx, dix);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_x(pos)), rx, dix);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_y(pushJ_weight_bank_t *bank, int pos, v8fp64 rx, v8fp64 dix) {
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_y(pos)), rx, dix);
  pushJ_wt_fill_axis_f1(pushJ_wt_slot(bank, pjw_f1_y(pos)), rx, dix);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_y(pos)), rx, dix);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_z(pushJ_weight_bank_t *bank, int pos, v8fp64 rx, v8fp64 dix) {
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_z(pos)), rx, dix);
  pushJ_wt_fill_axis_f1(pushJ_wt_slot(bank, pjw_f1_z(pos)), rx, dix);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_z(pos)), rx, dix);
}

/* Narrow fills: only slots consumed by downstream deposit/K2 helpers. */
static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos0_deposit(pushJ_weight_bank_t *bank, v8fp64 rx_x, v8fp64 dix_x,
                           v8fp64 rx_y, v8fp64 dix_y) {
  pushJ_wt_fill_axis_f0(pushJ_wt_slot(bank, pjw_f0_x(0)), rx_x, dix_x);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_x(0)), rx_x, dix_x);
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_y(0)), rx_y, dix_y);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_x_if1(pushJ_weight_bank_t *bank, int pos, v8fp64 rx,
                        v8fp64 dix) {
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_x(pos)), rx, dix);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_y_if1(pushJ_weight_bank_t *bank, int pos, v8fp64 rx,
                        v8fp64 dix) {
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_y(pos)), rx, dix);
}

static __device__ KERNEL_M __noinline__ void
pushJ_wt_fill_pos_z_if1(pushJ_weight_bank_t *bank, int pos, v8fp64 rx,
                        v8fp64 dix) {
  pushJ_wt_fill_axis_if1(pushJ_wt_slot(bank, pjw_if1_z(pos)), rx, dix);
}

/* Bank-indexed B-field integrals (no eval_* recompute) */

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_B_integralS_comp2_f0z_dif1x_f1y_bank(const pushJ_weight_bank_t *bank,
                                           const double *field, int slot_f0z,
                                           int slot_if1x_hi, int slot_if1x_lo,
                                           int slot_f1y) {
  const v8fp64 *wF0z = bank->slot[slot_f0z];
  const v8fp64 *wHiX = bank->slot[slot_if1x_hi];
  const v8fp64 *wLoX = bank->slot[slot_if1x_lo];
  const v8fp64 *wF1y = bank->slot[slot_f1y];
  v8fp64 sum = (v8fp64){};
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum =
            sum + ((field[((allidx * 3) + 2)] *
                    (wF0z[xyzz] * (((wHiX[xyzx] - wLoX[xyzx]) * wF1y[xyzy])))));
      }
    }
  }
  return sum;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_B_integralS_comp0_f0x_dif1y_f1z_bank(const pushJ_weight_bank_t *bank,
                                           const double *field, int slot_f0x,
                                           int slot_if1y_hi, int slot_if1y_lo,
                                           int slot_f1z) {
  const v8fp64 *wF0x = bank->slot[slot_f0x];
  const v8fp64 *wHiY = bank->slot[slot_if1y_hi];
  const v8fp64 *wLoY = bank->slot[slot_if1y_lo];
  const v8fp64 *wF1z = bank->slot[slot_f1z];
  v8fp64 sum = (v8fp64){};
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum =
            sum + ((field[((allidx * 3) + 0)] *
                    (wF0x[xyzx] * (((wHiY[xyzy] - wLoY[xyzy]) * wF1z[xyzz])))));
      }
    }
  }
  return sum;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_B_integralS_comp1_f0y_dif1x_f1z_bank(const pushJ_weight_bank_t *bank,
                                           const double *field, int slot_f0y,
                                           int slot_if1x_hi, int slot_if1x_lo,
                                           int slot_f1z) {
  const v8fp64 *wF0y = bank->slot[slot_f0y];
  const v8fp64 *wHiX = bank->slot[slot_if1x_hi];
  const v8fp64 *wLoX = bank->slot[slot_if1x_lo];
  const v8fp64 *wF1z = bank->slot[slot_f1z];
  v8fp64 sum = (v8fp64){};
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum =
            sum + ((field[((allidx * 3) + 1)] *
                    (wF0y[xyzy] * (((wHiX[xyzx] - wLoX[xyzx]) * wF1z[xyzz])))));
      }
    }
  }
  return sum;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_B_integralS_comp0_f0x_dif1z_f1y_bank(const pushJ_weight_bank_t *bank,
                                           const double *field, int slot_f0x,
                                           int slot_if1z_hi, int slot_if1z_lo,
                                           int slot_f1y) {
  const v8fp64 *wF0x = bank->slot[slot_f0x];
  const v8fp64 *wHiZ = bank->slot[slot_if1z_hi];
  const v8fp64 *wLoZ = bank->slot[slot_if1z_lo];
  const v8fp64 *wF1y = bank->slot[slot_f1y];
  v8fp64 sum = (v8fp64){};
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum =
            sum + ((field[((allidx * 3) + 0)] *
                    (wF0x[xyzx] * (((wHiZ[xyzz] - wLoZ[xyzz]) * wF1y[xyzy])))));
      }
    }
  }
  return sum;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_B_integralS_comp1_f0y_dif1z_f1x_bank(const pushJ_weight_bank_t *bank,
                                           const double *field, int slot_f0y,
                                           int slot_if1z_hi, int slot_if1z_lo,
                                           int slot_f1x) {
  const v8fp64 *wF0y = bank->slot[slot_f0y];
  const v8fp64 *wHiZ = bank->slot[slot_if1z_hi];
  const v8fp64 *wLoZ = bank->slot[slot_if1z_lo];
  const v8fp64 *wF1x = bank->slot[slot_f1x];
  v8fp64 sum = (v8fp64){};
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum =
            sum + ((field[((allidx * 3) + 1)] *
                    (wF0y[xyzy] * (((wHiZ[xyzz] - wLoZ[xyzz]) * wF1x[xyzx])))));
      }
    }
  }
  return sum;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_B_integralS_comp2_f0z_dif1y_f1x_bank(const pushJ_weight_bank_t *bank,
                                           const double *field, int slot_f0z,
                                           int slot_if1y_hi, int slot_if1y_lo,
                                           int slot_f1x) {
  const v8fp64 *wF0z = bank->slot[slot_f0z];
  const v8fp64 *wHiY = bank->slot[slot_if1y_hi];
  const v8fp64 *wLoY = bank->slot[slot_if1y_lo];
  const v8fp64 *wF1x = bank->slot[slot_f1x];
  v8fp64 sum = (v8fp64){};
  for (long xyzz = 0; xyzz < 5; xyzz = (xyzz + 1)) {
    for (long xyzy = 0; xyzy < 5; xyzy = (xyzy + 1)) {
      for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        sum =
            sum + ((field[((allidx * 3) + 2)] *
                    (wF0z[xyzz] * (((wHiY[xyzy] - wLoY[xyzy]) * wF1x[xyzx])))));
      }
    }
  }
  return sum;
}

/* Bank-indexed E-field interpolation */

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_E_interp_Ex_bank(const pushJ_weight_bank_t *bank, const double *shE0) {
  const v8fp64 *f1_x1 = bank->slot[pjw_f1_x(1)];
  const v8fp64 *f0_y1 = bank->slot[pjw_f0_y(1)];
  const v8fp64 *f0_z1 = bank->slot[pjw_f0_z(1)];
  v8fp64 AllEx = (v8fp64){};
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            ((((shE0)[(0 + (3 * (idx + (5 * (idy + (idz * 5))))))] + 0)) *
             ((f1_x1)[idx] * ((f0_y1)[idy] * (f0_z1)[idz])));
        AllEx = (AllEx + term);
      }
    }
  }
  return AllEx;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_E_interp_Ey_bank(const pushJ_weight_bank_t *bank, const double *shE0) {
  const v8fp64 *f1_y1 = bank->slot[pjw_f1_y(1)];
  const v8fp64 *f0_z1 = bank->slot[pjw_f0_z(1)];
  const v8fp64 *f0_x1 = bank->slot[pjw_f0_x(1)];
  v8fp64 AllEy = (v8fp64){};
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            ((((shE0)[(1 + (3 * (idz + (5 * (idx + (idy * 5))))))] + 0)) *
             ((f1_y1)[idx] * ((f0_z1)[idy] * (f0_x1)[idz])));
        AllEy = (AllEy + term);
      }
    }
  }
  return AllEy;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_E_interp_Ez_bank(const pushJ_weight_bank_t *bank, const double *shE0) {
  const v8fp64 *f1_z1 = bank->slot[pjw_f1_z(1)];
  const v8fp64 *f0_x1 = bank->slot[pjw_f0_x(1)];
  const v8fp64 *f0_y1 = bank->slot[pjw_f0_y(1)];
  v8fp64 AllEz = (v8fp64){};
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            ((((shE0)[(2 + (3 * (idy + (5 * (idz + (idx * 5))))))] + 0)) *
             ((f1_z1)[idx] * ((f0_x1)[idy] * (f0_y1)[idz])));
        AllEz = (AllEz + term);
      }
    }
  }
  return AllEz;
}

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

/* Read-only geometry/step constants in DM (SCALE MPU Context, watchlist §5.2)
 */
typedef struct {
  double DELTA_X, DELTA_Y, DELTA_Z;
  double Deltat;
  double Tori_X0;
  double TX0;
  double QE_MASS;
  double grid_geo_x, grid_geo_y, grid_geo_z;
  double XO, YO, ZO;
  double zmid;
  double Midx, Midy, Midz;
  int bBidx, bBidy, bBidz;
  double Charge0;
} pushJ_ctx_t;

static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_ctx_init(pushJ_ctx_t *ctx, double DELTA_X, double DELTA_Y,
                   double DELTA_Z, double Deltat, double Tori_X0,
                   double Charge0, double Mass0, double XO, double YO,
                   double ZO, double zmid, double Midx, double Midy,
                   double Midz, int bBidx, int bBidy, int bBidz) {
  ctx->DELTA_X = DELTA_X;
  ctx->DELTA_Y = DELTA_Y;
  ctx->DELTA_Z = DELTA_Z;
  ctx->Deltat = Deltat;
  ctx->Tori_X0 = Tori_X0;
  ctx->TX0 = Tori_X0;
  ctx->QE_MASS = (Charge0 / Mass0);
  ctx->grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));
  ctx->grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));
  ctx->grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));
  ctx->XO = XO;
  ctx->YO = YO;
  ctx->ZO = ZO;
  ctx->zmid = zmid;
  ctx->Midx = Midx;
  ctx->Midy = Midy;
  ctx->Midz = Midz;
  ctx->bBidx = bBidx;
  ctx->bBidy = bBidy;
  ctx->bBidz = bBidz;
  ctx->Charge0 = Charge0;
}

static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_clamp_grid_idx(double *Midx, double *Midy, double *Midz,
                         MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN) {
  if (*Midx < 0) {
    *Midx = 0;
  }
  if (*Midy < 0) {
    *Midy = 0;
  }
  if (*Midz < 0) {
    *Midz = 0;
  }
  if (*Midx > (XLEN - 1)) {
    *Midx = (XLEN - 1);
  }
  if (*Midy > (YLEN - 1)) {
    *Midy = (YLEN - 1);
  }
  if (*Midz > (ZLEN - 1)) {
    *Midz = (ZLEN - 1);
  }
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_Jx12(const pushJ_weight_bank_t *bank,
                       const pushJ_vlo_state_t *st, const pushJ_ctx_t *ctx,
                       v8fp64 *shJ_incf) {
  const v8fp64 *if1_x1 = bank->slot[pjw_if1_x(1)];
  const v8fp64 *if1_x2 = bank->slot[pjw_if1_x(2)];
  const v8fp64 *f0_y1 = bank->slot[pjw_f0_y(1)];
  const v8fp64 *f0_z1 = bank->slot[pjw_f0_z(1)];
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (st->simd_mask * (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                        ((f0_y1)[xyzy] * (f0_z1)[xyzz])));
        shJ_incf[((allidx * 3) + 0)] =
            shJ_incf[((allidx * 3) + 0)] +
            ((ctx->grid_geo_x *
              ((ctx->Tori_X0 /
                (ctx->Tori_X0 + (ctx->XO + (ctx->bBidx + xyzx)))) *
               ctx->Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_Jy12(const pushJ_weight_bank_t *bank,
                       const pushJ_vlo_state_t *st, const pushJ_ctx_t *ctx,
                       v8fp64 *shJ_incf) {
  const v8fp64 *if1_y1 = bank->slot[pjw_if1_y(1)];
  const v8fp64 *if1_y2 = bank->slot[pjw_if1_y(2)];
  const v8fp64 *f0_x2 = bank->slot[pjw_f0_x(2)];
  const v8fp64 *f0_z1 = bank->slot[pjw_f0_z(1)];
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (st->simd_mask * (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                        ((f0_x2)[xyzx] * (f0_z1)[xyzz])));
        shJ_incf[((allidx * 3) + 1)] =
            shJ_incf[((allidx * 3) + 1)] +
            ((ctx->grid_geo_y *
              (((ctx->Tori_X0 + (ctx->XO + (ctx->bBidx + xyzx))) /
                ctx->Tori_X0) *
               ctx->Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_Jz13(const pushJ_weight_bank_t *bank,
                       const pushJ_vlo_state_t *st, const pushJ_ctx_t *ctx,
                       v8fp64 *shJ_incf) {
  const v8fp64 *if1_z1 = bank->slot[pjw_if1_z(1)];
  const v8fp64 *if1_z3 = bank->slot[pjw_if1_z(3)];
  const v8fp64 *f0_x2 = bank->slot[pjw_f0_x(2)];
  const v8fp64 *f0_y2 = bank->slot[pjw_f0_y(2)];
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (st->simd_mask * (((if1_z3)[xyzz] - (if1_z1)[xyzz]) *
                                        ((f0_x2)[xyzx] * (f0_y2)[xyzy])));
        shJ_incf[((allidx * 3) + 2)] =
            shJ_incf[((allidx * 3) + 2)] +
            ((ctx->grid_geo_z *
              ((ctx->Tori_X0 /
                (ctx->Tori_X0 + (ctx->XO + (ctx->bBidx + xyzx)))) *
               ctx->Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_Jy23(const pushJ_weight_bank_t *bank,
                       const pushJ_vlo_state_t *st, const pushJ_ctx_t *ctx,
                       v8fp64 *shJ_incf) {
  const v8fp64 *if1_y2 = bank->slot[pjw_if1_y(2)];
  const v8fp64 *if1_y3 = bank->slot[pjw_if1_y(3)];
  const v8fp64 *f0_x2 = bank->slot[pjw_f0_x(2)];
  const v8fp64 *f0_z3 = bank->slot[pjw_f0_z(3)];
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (st->simd_mask * (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                        ((f0_x2)[xyzx] * (f0_z3)[xyzz])));
        shJ_incf[((allidx * 3) + 1)] =
            shJ_incf[((allidx * 3) + 1)] +
            ((ctx->grid_geo_y *
              (((ctx->Tori_X0 + (ctx->XO + (ctx->bBidx + xyzx))) /
                ctx->Tori_X0) *
               ctx->Charge0)) *
             Jtmp);
      }
    }
  }
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_Jx23(const pushJ_weight_bank_t *bank,
                       const pushJ_vlo_state_t *st, const pushJ_ctx_t *ctx,
                       v8fp64 *shJ_incf) {
  const v8fp64 *if1_x2 = bank->slot[pjw_if1_x(2)];
  const v8fp64 *if1_x3 = bank->slot[pjw_if1_x(3)];
  const v8fp64 *f0_y3 = bank->slot[pjw_f0_y(3)];
  const v8fp64 *f0_z3 = bank->slot[pjw_f0_z(3)];
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      long xyzx;
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 Jtmp = (st->simd_mask * (((if1_x3)[xyzx] - (if1_x2)[xyzx]) *
                                        ((f0_y3)[xyzy] * (f0_z3)[xyzz])));
        shJ_incf[((allidx * 3) + 0)] =
            shJ_incf[((allidx * 3) + 0)] +
            ((ctx->grid_geo_x *
              ((ctx->Tori_X0 /
                (ctx->Tori_X0 + (ctx->XO + (ctx->bBidx + xyzx)))) *
               ctx->Charge0)) *
             Jtmp);
      }
    }
  }
}
static __device__ __attribute__((always_inline)) inline MAPU_LONG
pushJ_vlo_field_ddr_elem_offset(MAPU_LONG __idy, int bBidx, int bBidy,
                                int bBidz, int xyzy, int xyzz, MAPU_LONG XLEN,
                                MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp,
                                int num_ele) {
  return ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                               ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
          (0 + (num_ele * ((bBidx + ovlp) + ((XLEN + (2 * ovlp)) *
                                             (((xyzy + bBidy) + ovlp) +
                                              ((YLEN + (2 * ovlp)) *
                                               ((xyzz + bBidz) + ovlp))))))));
}

static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_K1_load_shared_5x5x5(double *shE0, double *shB0, double *shB1,
                               double *shJ0, __DDR double *fieldE,
                               __DDR double *fieldB, __DDR double *fieldB1,
                               __DDR double *FoutJ, MAPU_LONG __idy,
                               MAPU_LONG __idx, MAPU_LONG __xlen, int bBidx,
                               int bBidy, int bBidz, MAPU_LONG XLEN,
                               MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp,
                               int num_ele,
                               cooperative_groups::thread_block block,
                               scale::barrier<scale::thread_scope_block> &bar) {
  const size_t tile_bytes = (size_t)(3 * 5) * sizeof(double);

  for (long xyzz = 0; xyzz < 5; xyzz++) {
    for (long xyzy = 0; xyzy < 5; xyzy++) {
      const int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));
      const MAPU_LONG ddr_off = pushJ_vlo_field_ddr_elem_offset(
          __idy, bBidx, bBidy, bBidz, xyzy, xyzz, XLEN, YLEN, ZLEN, ovlp,
          num_ele);

      memcpy_async(block, (unsigned *)(shE0 + total_idx),
                   (__DDR unsigned *)(fieldE + ddr_off), (uint64_t)tile_bytes,
                   bar);
      memcpy_async(block, (unsigned *)(shB0 + total_idx),
                   (__DDR unsigned *)(fieldB + ddr_off), (uint64_t)tile_bytes,
                   bar);
      memcpy_async(block, (unsigned *)(shB1 + total_idx),
                   (__DDR unsigned *)(fieldB1 + ddr_off), (uint64_t)tile_bytes,
                   bar);
      memcpy_async(block, (unsigned *)(shJ0 + total_idx),
                   (__DDR unsigned *)(FoutJ + ddr_off), (uint64_t)tile_bytes,
                   bar);
      bar.arrive_and_wait();
    }
  }
}

/* SPU-visible MPU entry: keep external linkage (no static).
 * K1 consumes one DMA-staged batch at particle_dm[0..load0), so the old
 * g_inner/Midx/Midy/Midz/Deltat scalar argument pack is unnecessary.
 * Geometry comes from ctx and x0/x1 weights are filled inside MPU.
 */
__device__ KERNEL_M __noinline__ void
pushJ_vlo_K1_setup_weights_x0x1(pushJ_weight_bank_t *bank,
                                pushJ_vlo_state_t *st,
                                double *particle_dm /* DM staging, not DDR */,
                                int load0, const pushJ_ctx_t *ctx) {
  __mem0__ v8fp64 head[6];
  double (*head_l)[8] = (double (*)[8])head;
  for (int f = 0; f < 6; f++) {
    for (int lane = 0; lane < 8; lane++) {
      const int src = (lane < load0) ? lane : 0;
      head_l[f][lane] = particle_dm[f + 6 * src];
    }
  }

  st->simd_mask = (v8fp64){};
  double *simd_mask_l = (double *)&st->simd_mask;
  for (int lane = 0; lane < 8; lane++) {
    simd_mask_l[lane] = (lane < load0) ? 1.0 : 0.0;
  }

  st->xx1 = head[0] - 5.00000000000000000e-01;
  st->xy1 = head[1] - 5.00000000000000000e-01;
  st->xz1 = head[2] - 5.00000000000000000e-01;
  st->vx0 = head[3];
  st->vy0 = head[4];
  st->vz0 = head[5];

  st->xx0 = (st->xx1 - (ctx->Deltat * st->vx0));
  st->xy0 = (st->xy1 - (ctx->Deltat * st->vy0));
  st->xz0 = (st->xz1 - (ctx->Deltat * st->vz0));

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
  st->s_dix0x = (Midx0 - ctx->Midx);
  st->s_dix0y = (Midy0 - ctx->Midy);
  st->s_dix0z = (Midz0 - ctx->Midz);
  st->s_dix1x = (Midx1 - ctx->Midx);
  st->s_dix1y = (Midy1 - ctx->Midy);
  st->s_dix1z = (Midz1 - ctx->Midz);

  /* MPU -> MPU calls are legal; keeping these here removes two SPU -> MPU
   * calls and keeps the SPU-visible K1 entry well below the argument limit.
   */
  pushJ_wt_fill_pos_xyz(bank, 0, st->s_rx0x, st->s_dix0x, st->s_rx0y,
                        st->s_dix0y, st->s_rx0z, st->s_dix0z);
  pushJ_wt_fill_pos_xyz(bank, 1, st->s_rx1x, st->s_dix1x, st->s_rx1y,
                        st->s_dix1y, st->s_rx1z, st->s_dix1z);
}
/* -------------------------------------------------------------------------- */
/* K2 push split helpers (Step C) */
/* -------------------------------------------------------------------------- */

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_x2(pushJ_vlo_state_t *st, v8fp64 x0, v8fp64 x1,
                     v8fp64 allincfvx, const pushJ_ctx_t *ctx) {
  st->x2 = (((-1.00000000000000000e+00 * x0) + (2.00000000000000000e+00 * x1)) +
            ((1.00000000000000000e+00 / (ctx->DELTA_X * ctx->DELTA_X)) *
             (ctx->QE_MASS *
              (ctx->Deltat * (allincfvx + (-1.00000000000000000e+00 *
                                           0.00000000000000000e+00))))));

  st->s_rx2x = ((st->x2 - ctx->XO) - geo_floor_simd(st->x2 - ctx->XO));
  st->s_dix2x = (geo_floor_simd(st->x2 - ctx->XO) - ctx->Midx);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_y2(pushJ_vlo_state_t *st, v8fp64 x0, v8fp64 y0, v8fp64 y1,
                     v8fp64 iBy, v8fp64 allincfvy, const pushJ_ctx_t *ctx) {
  const double TX0 = ctx->TX0;
  const double DELTA_Y = ctx->DELTA_Y;
  const double Deltat = ctx->Deltat;
  const double QE_MASS = ctx->QE_MASS;
  st->y2 =
      (((1.00000000000000000e+00 /
         ((TX0 * TX0) +
          ((2.00000000000000000e+00 * (TX0 * st->x2)) + (st->x2 * st->x2)))) *
        ((((-1.00000000000000000e+00 * (TX0 * TX0)) +
           ((-2.00000000000000000e+00 * (TX0 * x0)) +
            (-1.00000000000000000e+00 * (x0 * x0)))) *
          y0) +
         (((2.00000000000000000e+00 * (TX0 * TX0)) +
           ((2.00000000000000000e+00 * (TX0 * x0)) +
            ((x0 * x0) + ((2.00000000000000000e+00 * (TX0 * st->x2)) +
                          (st->x2 * st->x2))))) *
          y1))) +
       ((TX0 * TX0) *
        ((QE_MASS * (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
         (1.00000000000000000e+00 /
          (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
           ((2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * (TX0 * st->x2))) +
            ((DELTA_Y * DELTA_Y) * (st->x2 * st->x2))))))));

  st->s_rx2y = ((st->y2 - ctx->YO) - geo_floor_simd(st->y2 - ctx->YO));
  st->s_dix2y = (geo_floor_simd(st->y2 - ctx->YO) - ctx->Midy);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_z2_z3(pushJ_vlo_state_t *st, v8fp64 z0, v8fp64 z1, v8fp64 iBz,
                        v8fp64 allincfvz, const pushJ_ctx_t *ctx) {
  st->z2 = (((-1.00000000000000000e+00 * z0) + (2.00000000000000000e+00 * z1)) +
            ((1.00000000000000000e+00 / (ctx->DELTA_Z * ctx->DELTA_Z)) *
             (ctx->QE_MASS *
              (ctx->Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

  st->s_rx2z = ((st->z2 - (ctx->ZO - ctx->zmid)) -
                geo_floor_simd(st->z2 - (ctx->ZO - ctx->zmid)));
  st->s_dix2z = (geo_floor_simd(st->z2 - (ctx->ZO - ctx->zmid)) - ctx->Midz);

  /* Keep historical behavior: iBz is zeroed before z3 */
  st->z3 =
      (((-1.00000000000000000e+00 * z1) + (2.00000000000000000e+00 * st->z2)) +
       ((1.00000000000000000e+00 / (ctx->DELTA_Z * ctx->DELTA_Z)) *
        (-1 * (ctx->Deltat * (ctx->QE_MASS * 0.00000000000000000e+00)))));

  st->s_rx3z = ((st->z3 - (ctx->ZO - ctx->zmid)) -
                geo_floor_simd(st->z3 - (ctx->ZO - ctx->zmid)));
  st->s_dix3z = (geo_floor_simd(st->z3 - (ctx->ZO - ctx->zmid)) - ctx->Midz);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_y3(pushJ_vlo_state_t *st, v8fp64 y1, v8fp64 iBy,
                     const pushJ_ctx_t *ctx) {
  const double TX0 = ctx->TX0;
  const double DELTA_Y = ctx->DELTA_Y;
  const double Deltat = ctx->Deltat;
  const double QE_MASS = ctx->QE_MASS;
  st->y3 =
      (((-1.00000000000000000e+00 * y1) + (2.00000000000000000e+00 * st->y2)) +
       ((TX0 * TX0) *
        ((-1 * (Deltat * (QE_MASS * iBy))) *
         (1.00000000000000000e+00 /
          (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
           ((2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * (TX0 * st->x2))) +
            ((DELTA_Y * DELTA_Y) * (st->x2 * st->x2))))))));

  st->s_rx3y = ((st->y3 - ctx->YO) - geo_floor_simd(st->y3 - ctx->YO));
  st->s_dix3y = (geo_floor_simd(st->y3 - ctx->YO) - ctx->Midy);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_x3(pushJ_vlo_state_t *st, v8fp64 x1, v8fp64 y1, v8fp64 iBx,
                     const pushJ_ctx_t *ctx) {
  const double TX0 = ctx->TX0;
  const double DELTA_X = ctx->DELTA_X;
  const double DELTA_Y = ctx->DELTA_Y;
  const double Deltat = ctx->Deltat;
  const double QE_MASS = ctx->QE_MASS;
  st->x3 =
      (((1.00000000000000000e+00 / (DELTA_X * DELTA_X)) *
        ((1.00000000000000000e+00 / (TX0 * TX0)) *
         ((-1.00000000000000000e+00 *
           ((DELTA_X * DELTA_X) * ((TX0 * TX0) * x1))) +
          ((2.00000000000000000e+00 *
            ((DELTA_X * DELTA_X) * ((TX0 * TX0) * st->x2))) +
           (((((DELTA_Y * DELTA_Y) * TX0) + ((DELTA_Y * DELTA_Y) * st->x2)) *
             (y1 * y1)) +
            ((((-2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * TX0)) +
               (-2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * st->x2))) *
              (y1 * st->y2)) +
             ((((2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * TX0)) +
                (2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * st->x2))) *
               (st->y2 * st->y2)) +
              ((((-2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * TX0)) +
                 (-2.00000000000000000e+00 * ((DELTA_Y * DELTA_Y) * st->x2))) *
                (st->y2 * st->y3)) +
               ((((DELTA_Y * DELTA_Y) * TX0) + ((DELTA_Y * DELTA_Y) * st->x2)) *
                (st->y3 * st->y3)))))))))) +
       ((1.00000000000000000e+00 / (DELTA_X * DELTA_X)) *
        (-1 * (Deltat * (QE_MASS * iBx)))));

  st->s_rx3x = ((st->x3 - ctx->XO) - geo_floor_simd(st->x3 - ctx->XO));
  st->s_dix3x = (geo_floor_simd(st->x3 - ctx->XO) - ctx->Midx);
}

/* -------------------------------------------------------------------------- */
/* K2 B-integral combination wrappers (Step F: split K2 call chain) */
/* Each returns one corrected B integral; math/order preserved bit-exact. */
/* -------------------------------------------------------------------------- */

static __device__ KERNEL_M __noinline__ v8fp64 pushJ_vlo_K2_compute_iBy(
    const pushJ_weight_bank_t *bank, const pushJ_vlo_state_t *st,
    const double *shB0, const double *shB1) {
  v8fp64 iBy_term0 = pushJ_B_integralS_comp2_f0z_dif1x_f1y_bank(
      bank, shB0, pjw_f0_z(1), pjw_if1_x(1), pjw_if1_x(0), pjw_f1_y(1));
  v8fp64 iBy_term1 = pushJ_B_integralS_comp2_f0z_dif1x_f1y_bank(
      bank, shB1, pjw_f0_z(1), pjw_if1_x(2), pjw_if1_x(1), pjw_f1_y(1));
  return (iBy_term0 + iBy_term1);
}

static __device__ KERNEL_M __noinline__ v8fp64 pushJ_vlo_K2_compute_iBz(
    const pushJ_weight_bank_t *bank, const pushJ_vlo_state_t *st,
    const double *shB0, const double *shB1) {
  v8fp64 iBz_term1 = pushJ_B_integralS_comp0_f0x_dif1y_f1z_bank(
      bank, shB0, pjw_f0_x(0), pjw_if1_y(1), pjw_if1_y(0), pjw_f1_z(1));
  v8fp64 iBz_term2 = pushJ_B_integralS_comp1_f0y_dif1x_f1z_bank(
      bank, shB0, pjw_f0_y(1), pjw_if1_x(1), pjw_if1_x(0), pjw_f1_z(1));
  v8fp64 iBz_term3 = pushJ_B_integralS_comp0_f0x_dif1y_f1z_bank(
      bank, shB1, pjw_f0_x(2), pjw_if1_y(2), pjw_if1_y(1), pjw_f1_z(1));
  v8fp64 iBz_term4 = pushJ_B_integralS_comp1_f0y_dif1x_f1z_bank(
      bank, shB1, pjw_f0_y(1), pjw_if1_x(2), pjw_if1_x(1), pjw_f1_z(1));
  v8fp64 inner = ((-1.00000000000000000e+00 * iBz_term1) + iBz_term2 +
                  (-1.00000000000000000e+00 * iBz_term3) + iBz_term4);
  return (-1.00000000000000000e+00 * inner);
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_vlo_K2_compute_iBy23(const pushJ_weight_bank_t *bank,
                           const pushJ_vlo_state_t *st, const double *shB1) {
  v8fp64 t0 = pushJ_B_integralS_comp0_f0x_dif1z_f1y_bank(
      bank, shB1, pjw_f0_x(2), pjw_if1_z(2), pjw_if1_z(1), pjw_f1_y(2));
  v8fp64 t1 = pushJ_B_integralS_comp0_f0x_dif1z_f1y_bank(
      bank, shB1, pjw_f0_x(2), pjw_if1_z(3), pjw_if1_z(2), pjw_f1_y(2));
  return ((-1.00000000000000000e+00 * t0) + (-1.00000000000000000e+00 * t1));
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_vlo_K2_compute_iBx(const pushJ_weight_bank_t *bank,
                         const pushJ_vlo_state_t *st, const double *shB1) {
  return (
      pushJ_B_integralS_comp1_f0y_dif1z_f1x_bank(
          bank, shB1, pjw_f0_y(2), pjw_if1_z(2), pjw_if1_z(1), pjw_f1_x(2)) +
      pushJ_B_integralS_comp1_f0y_dif1z_f1x_bank(
          bank, shB1, pjw_f0_y(2), pjw_if1_z(3), pjw_if1_z(2), pjw_f1_x(2)) +
      (-1.00000000000000000e+00) * pushJ_B_integralS_comp2_f0z_dif1y_f1x_bank(
                                       bank, shB1, pjw_f0_z(1), pjw_if1_y(2),
                                       pjw_if1_y(1), pjw_f1_x(2)) +
      (-1.00000000000000000e+00) * pushJ_B_integralS_comp2_f0z_dif1y_f1x_bank(
                                       bank, shB1, pjw_f0_z(3), pjw_if1_y(3),
                                       pjw_if1_y(2), pjw_f1_x(2)));
}

/* -------------------------------------------------------------------------- */
/* K2 Verlet stage splits (Step G/H): shorten live range per stage callee */
/* -------------------------------------------------------------------------- */

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage1a_E(const pushJ_weight_bank_t *bank,
                       const pushJ_vlo_state_t *st, const double *shE0,
                       const pushJ_ctx_t *ctx, v8fp64 *allincfvx_out,
                       v8fp64 *allincfvy_out, v8fp64 *allincfvz_out) {
  const v8fp64 AllEx = pushJ_E_interp_Ex_bank(bank, shE0);
  const v8fp64 AllEy = pushJ_E_interp_Ey_bank(bank, shE0);
  const v8fp64 AllEz = pushJ_E_interp_Ez_bank(bank, shE0);
  *allincfvx_out = (2.00000000000000000e+00 * (ctx->Deltat * AllEx));
  *allincfvy_out = (2.00000000000000000e+00 * (ctx->Deltat * AllEy));
  *allincfvz_out = (2.00000000000000000e+00 * (ctx->Deltat * AllEz));
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage1b_x2y2(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                          const double *shB0, const double *shB1, v8fp64 x0,
                          v8fp64 x1, v8fp64 y0, v8fp64 y1, v8fp64 allincfvx,
                          v8fp64 allincfvy, const pushJ_ctx_t *ctx) {
  pushJ_vlo_K2_push_x2(st, x0, x1, allincfvx, ctx);
  pushJ_wt_fill_pos_x(bank, 2, st->s_rx2x, st->s_dix2x);

  const v8fp64 iBy = pushJ_vlo_K2_compute_iBy(bank, st, shB0, shB1);

  pushJ_vlo_K2_push_y2(st, x0, y0, y1, iBy, allincfvy, ctx);
  pushJ_wt_fill_pos_y(bank, 2, st->s_rx2y, st->s_dix2y);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage2_z2z3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                         const double *shB0, const double *shB1, v8fp64 z0,
                         v8fp64 z1, v8fp64 allincfvz, const pushJ_ctx_t *ctx) {
  const v8fp64 iBz = pushJ_vlo_K2_compute_iBz(bank, st, shB0, shB1);

  pushJ_vlo_K2_push_z2_z3(st, z0, z1, iBz, allincfvz, ctx);
  pushJ_wt_fill_pos_z(bank, 2, st->s_rx2z, st->s_dix2z);
  pushJ_wt_fill_pos_z(bank, 3, st->s_rx3z, st->s_dix3z);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage3a_y3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                        const double *shB1, v8fp64 y1, const pushJ_ctx_t *ctx) {
  const v8fp64 iBy23 = pushJ_vlo_K2_compute_iBy23(bank, st, shB1);

  pushJ_vlo_K2_push_y3(st, y1, iBy23, ctx);
  pushJ_wt_fill_pos_y(bank, 3, st->s_rx3y, st->s_dix3y);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage3b_x3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                        const double *shB1, v8fp64 x1, v8fp64 y1,
                        const pushJ_ctx_t *ctx) {
  const v8fp64 iBx = pushJ_vlo_K2_compute_iBx(bank, st, shB1);

  pushJ_vlo_K2_push_x3(st, x1, y1, iBx, ctx);
  pushJ_wt_fill_pos_x(bank, 3, st->s_rx3x, st->s_dix3x);
}

static __device__ KERNEL_M __noinline__ void pushJ_vlo_K2_stage1_E_x2y2(
    pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st, const double *shE0,
    const double *shB0, const double *shB1, v8fp64 x0, v8fp64 x1, v8fp64 y0,
    v8fp64 y1, const pushJ_ctx_t *ctx, v8fp64 *allincfvz_out) {
  v8fp64 allincfvx, allincfvy;
  pushJ_vlo_K2_stage1a_E(bank, st, shE0, ctx, &allincfvx, &allincfvy,
                         allincfvz_out);
  pushJ_vlo_K2_stage1b_x2y2(bank, st, shB0, shB1, x0, x1, y0, y1, allincfvx,
                            allincfvy, ctx);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage3_y3x3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                         const double *shB1, v8fp64 x1, v8fp64 y1,
                         const pushJ_ctx_t *ctx) {
  pushJ_vlo_K2_stage3a_y3(bank, st, shB1, y1, ctx);
  pushJ_vlo_K2_stage3b_x3(bank, st, shB1, x1, y1, ctx);
}

/* SPU-visible MPU entry: keep external linkage (no static). */
__device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_weights_x2x3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                               const double *shE0, const double *shB0,
                               const double *shB1, const pushJ_ctx_t *ctx) {
  const v8fp64 x0 = (st->xx0 + ctx->XO);
  const v8fp64 y0 = (st->xy0 + ctx->YO);
  const v8fp64 z0 = (st->xz0 + (ctx->ZO - ctx->zmid));
  const v8fp64 x1 = (st->xx1 + ctx->XO);
  const v8fp64 y1 = (st->xy1 + ctx->YO);
  const v8fp64 z1 = (st->xz1 + (ctx->ZO - ctx->zmid));

  v8fp64 allincfvz;
  pushJ_vlo_K2_stage1_E_x2y2(bank, st, shE0, shB0, shB1, x0, x1, y0, y1, ctx,
                             &allincfvz);
  pushJ_vlo_K2_stage2_z2z3(bank, st, shB0, shB1, z0, z1, allincfvz, ctx);
  pushJ_vlo_K2_stage3_y3x3(bank, st, shB1, x1, y1, ctx);
}

/* SPU-visible MPU entry: keep external linkage (no static).
 * particle_dm is already the current DMA-staged batch, so g_inner is always 0
 * and is intentionally removed from the SPU -> MPU argument list.
 */
__device__ KERNEL_M __noinline__ void pushJ_vlo_K3_deposit_writeback_particle(
    const pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
    const pushJ_ctx_t *ctx, v8fp64 *shJ_incf,
    double *particle_dm /* DM staging, not DDR */, int load0) {
  pushJ_vlo_deposit_Jx12(bank, st, ctx, shJ_incf);
  pushJ_vlo_deposit_Jy12(bank, st, ctx, shJ_incf);
  pushJ_vlo_deposit_Jz13(bank, st, ctx, shJ_incf);
  pushJ_vlo_deposit_Jy23(bank, st, ctx, shJ_incf);
  pushJ_vlo_deposit_Jx23(bank, st, ctx, shJ_incf);

  __mem0__ v8fp64 newvx[1];
  __mem0__ v8fp64 newvy[1];
  __mem0__ v8fp64 newvz[1];
  __mem0__ v8fp64 newxx[1];
  __mem0__ v8fp64 newxy[1];
  __mem0__ v8fp64 newxz[1];
  double *newvx_l = (double *)newvx;
  double *newvy_l = (double *)newvy;
  double *newvz_l = (double *)newvz;
  double *newxx_l = (double *)newxx;
  double *newxy_l = (double *)newxy;
  double *newxz_l = (double *)newxz;
  newvx[0] = ((st->x3 - st->x2) / ctx->Deltat);
  newvy[0] = ((st->y3 - st->y2) / ctx->Deltat);
  newvz[0] = ((st->z3 - st->z2) / ctx->Deltat);
  newxx[0] = (st->x3 - ctx->XO);
  newxy[0] = (st->y3 - ctx->YO);
  newxz[0] = ((st->z3 + ctx->zmid) - ctx->ZO);
  newxx[0] = (newxx[0] + 5.00000000000000000e-01);
  newxy[0] = (newxy[0] + 5.00000000000000000e-01);
  newxz[0] = (newxz[0] + 5.00000000000000000e-01);
  {
    long stmpg1;
    for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
      for (int lane = 0; lane < 8; lane++) {
        const int cid = lane;
        if (cid < load0) {
          const int poff = stmpg1 + cid * 6;
          if (stmpg1 == 0) {
            particle_dm[poff] = newxx_l[lane];
          } else if (stmpg1 == 1) {
            particle_dm[poff] = newxy_l[lane];
          } else if (stmpg1 == 2) {
            particle_dm[poff] = newxz_l[lane];
          } else if (stmpg1 == 3) {
            particle_dm[poff] = newvx_l[lane];
          } else if (stmpg1 == 4) {
            particle_dm[poff] = newvy_l[lane];
          } else {
            particle_dm[poff] = newvz_l[lane];
          }
        }
      }
    }
  }
}

static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_zero_shJ_incf(v8fp64 *shJ_incf) {
  double *shJ_incf_l = (double *)shJ_incf;
  for (int k = 0; k < 375 * 8; k++) {
    shJ_incf_l[k] = 0.0;
  }
}

static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_collapse_shJ_incf_to_shJ0(double *shJ0, const v8fp64 *shJ_incf) {
  const double (*shJ_incf_l)[8] = (const double (*)[8])shJ_incf;
  for (int k = 0; k < 375; k++) {
    double sum = 0.0;
#pragma unroll
    for (int lane = 0; lane < 8; lane++) {
      sum += shJ_incf_l[k][lane];
    }
    shJ0[k] += sum;
  }
}
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_K3_write_FoutJ_from_shared(
    double *shJ0, __DDR double *FoutJ, MAPU_LONG __idy, MAPU_LONG __idx,
    MAPU_LONG __xlen, int bBidx, int bBidy, int bBidz, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, int num_ele,
    cooperative_groups::thread_block block,
    scale::barrier<scale::thread_scope_block> &bar) {
  const size_t tile_bytes = (size_t)(3 * 5) * sizeof(double);

  for (long xyzz = 0; xyzz < 5; xyzz++) {
    for (long xyzy = 0; xyzy < 5; xyzy++) {
      const int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));
      const MAPU_LONG ddr_off =
          ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
           (0 + (num_ele * ((bBidx + ovlp) + ((XLEN + (2 * ovlp)) *
                                              (((xyzy + bBidy) + ovlp) +
                                               ((YLEN + (2 * ovlp)) *
                                                ((xyzz + bBidz) + ovlp))))))));

      memcpy_async(block, (__DDR unsigned *)(FoutJ + ddr_off),
                   (unsigned *)(shJ0 + total_idx), (uint64_t)tile_bytes, bar);
      bar.arrive_and_wait();
    }
  }
}

/* Shared orchestration for cu_cache (l1) and inoutput (allgid) paths. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_process_tile(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                       pushJ_ctx_t *ctx, double *shE0, double *shB0,
                       double *shB1, double *shJ0, v8fp64 *shJ_incf_simdp,
                       double *shParticle, __DDR double *particle_buf,
                       int load0, double Midx, double Midy, double Midz,
                       double Deltat, int bBidx, int bBidy, int bBidz,
                       __DDR double *fieldE, __DDR double *fieldB,
                       __DDR double *fieldB1, __DDR double *FoutJ,
                       MAPU_LONG __idy, MAPU_LONG __idx, MAPU_LONG __xlen,
                       MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp,
                       int num_ele, cooperative_groups::thread_block block,
                       scale::barrier<scale::thread_scope_block> &bar) {

  pushJ_vlo_K1_load_shared_5x5x5(
      shE0, shB0, shB1, shJ0, fieldE, fieldB, fieldB1, FoutJ, __idy, __idx,
      __xlen, bBidx, bBidy, bBidz, XLEN, YLEN, ZLEN, ovlp, num_ele, block, bar);

  pushJ_vlo_zero_shJ_incf(shJ_incf_simdp);

  for (int g_inner = 0; g_inner < load0; g_inner = (g_inner + 8)) {
    int numcp = 8;
    if ((g_inner + numcp) > load0) {
      numcp = load0 - g_inner;
    }
    const size_t particle_batch_bytes = (size_t)numcp * 6u * sizeof(double);
    memcpy_async(block, (unsigned *)shParticle,
                 (__DDR unsigned *)(particle_buf + (g_inner * 6)),
                 (uint64_t)particle_batch_bytes, bar);
    bar.arrive_and_wait();

    pushJ_vlo_K1_setup_weights_x0x1(bank, st, shParticle, numcp, ctx);

    // MPU_SYNC();
    pushJ_vlo_K2_push_weights_x2x3(bank, st, shE0, shB0, shB1, ctx);
    // MPU_SYNC();
    pushJ_vlo_K3_deposit_writeback_particle(bank, st, ctx, shJ_incf_simdp,
                                            shParticle, numcp);
    __aurora_s_getStatB();
    __aurora_s_fenceI();
    memcpy_async(block, (__DDR unsigned *)(particle_buf + (g_inner * 6)),
                 (unsigned *)shParticle, (uint64_t)particle_batch_bytes, bar);
    bar.arrive_and_wait();
  }
  pushJ_vlo_collapse_shJ_incf_to_shJ0(shJ0, shJ_incf_simdp);
  __syncthreads();
  pushJ_vlo_K3_write_FoutJ_from_shared(shJ0, FoutJ, __idy, __idx, __xlen, bBidx,
                                       bBidy, bBidz, XLEN, YLEN, ZLEN, ovlp,
                                       num_ele, block, bar);
}

#define IDX_LOCAL_XLEN 1
__global__ void mapu_geo_nr_Bfield_pushJ_vlo(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR int *xoffset, __DDR int *yoffset,
    __DDR int *zoffset, __DDR double *fieldE, __DDR double *fieldE_ext,
    __DDR double *fieldB, __DDR double *fieldB1, __DDR double *FoutJ,
    MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    int num_ele, MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length,
    int use_g_e, double DELTA_X, double DELTA_Y, double DELTA_Z, double Mass0,
    double Charge0, double Deltat, double Tori_X0, double r0, double MIN_R0,
    double Q0, double b0, double zmid) {

  // performance analyze
  // __aurora_s_startCounter(f_Clear);

  const MAPU_LONG __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const MAPU_LONG __xlen = (blockDim.x * blockDim.y);

  MAPU_LONG numgrid = (XLEN * (YLEN * ZLEN));

  MAPU_LONG grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  /* DM1: E/B field staging (REPORT §3.2) */
  __mem1__ __fix1__ double shE0[375];
  __mem1__ __fix1__ double shB0[375];
  __mem1__ __fix1__ double shB1[375];
  /* DM3: J accumulator cohort */
  __mem3__ __fix3__ double shJ0[375];
  __mem3__ __fix3__ v8fp64 shJ_incf_simdp[375];
  /* DM4: per-batch particle staging (8 particles × 6 doubles = 384 B) */
  __mem4__ __fix4__ double shParticle[48];
  /* DM6: particle state + read-only Context */
  __shared__ __fix5__ pushJ_vlo_state_t st;
  __shared__ __fix5__ pushJ_ctx_t pushJ_ctx;
  /* DM2: precomputed weight bank (static; no CUDA dynamic-shim path in SCALE)
   */
  __mem2__ __fix2__ pushJ_weight_bank_t pushJ_wt_bank;
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ __fix5__ barrier_t bar;
  if (__idx == 0) {
    init(&bar, __xlen);
  }
  __syncthreads();
  auto block = cooperative_groups::this_thread_block();
  {
    MAPU_LONG l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      const int load0 = 1;

      (use_local_particle_position = 1);
      if (load0) {
        double XO = (xoffset)[__idy];
        if (r0) {
          double xnum_off = XO / r0;
          XO = r0 * (xnum_off - floor(xnum_off));
        }
        const double YO = (yoffset)[__idy];
        const double ZO = (zoffset)[__idy];
        __DDR double *const particle_base =
            (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6)));

        double Midx =
            ((use_local_particle_position) ? (floor(particle_base[0])) : (mdx));
        double Midy =
            ((use_local_particle_position) ? (floor(particle_base[1])) : (mdy));
        double Midz =
            ((use_local_particle_position) ? (floor(particle_base[2])) : (mdz));

        pushJ_vlo_clamp_grid_idx(&Midx, &Midy, &Midz, XLEN, YLEN, ZLEN);

        const int bBidx = (Midx - 2);
        const int bBidy = (Midy - 2);
        const int bBidz = (Midz - 2);
        pushJ_vlo_ctx_init(&pushJ_ctx, DELTA_X, DELTA_Y, DELTA_Z, Deltat,
                           Tori_X0, Charge0, Mass0, XO, YO, ZO, zmid, Midx,
                           Midy, Midz, bBidx, bBidy, bBidz);
        pushJ_vlo_process_tile(
            &pushJ_wt_bank, &st, &pushJ_ctx, shE0, shB0, shB1, shJ0,
            shJ_incf_simdp, shParticle, particle_base, load0, Midx, Midy, Midz,
            Deltat, bBidx, bBidy, bBidz, fieldE, fieldB, fieldB1, FoutJ, __idy,
            __idx, __xlen, XLEN, YLEN, ZLEN, ovlp, num_ele, block, bar);
      }
    }
  }
  {
    MAPU_LONG allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      const int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];
      const MAPU_LONG c_gid = allgid;

      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      const int load0 = new_load_tmp;
      const int new_load = new_load_tmp;

      if (load0) {
        double XO = (xoffset)[__idy];
        if (r0) {
          double xnum_off = XO / r0;
          XO = r0 * (xnum_off - floor(xnum_off));
        }
        const double YO = (yoffset)[__idy];
        const double ZO = (zoffset)[__idy];
        __DDR double *const particle_base =
            (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len))));

        double Midx =
            ((use_local_particle_position) ? (floor(particle_base[0])) : (mdx));
        double Midy =
            ((use_local_particle_position) ? (floor(particle_base[1])) : (mdy));
        double Midz =
            ((use_local_particle_position) ? (floor(particle_base[2])) : (mdz));

        pushJ_vlo_clamp_grid_idx(&Midx, &Midy, &Midz, XLEN, YLEN, ZLEN);

        const int bBidx = (Midx - 2);
        const int bBidy = (Midy - 2);
        const int bBidz = (Midz - 2);

        pushJ_vlo_ctx_init(&pushJ_ctx, DELTA_X, DELTA_Y, DELTA_Z, Deltat,
                           Tori_X0, Charge0, Mass0, XO, YO, ZO, zmid, Midx,
                           Midy, Midz, bBidx, bBidy, bBidz);
        pushJ_vlo_process_tile(
            &pushJ_wt_bank, &st, &pushJ_ctx, shE0, shB0, shB1, shJ0,
            shJ_incf_simdp, shParticle, particle_base, load0, Midx, Midy, Midz,
            Deltat, bBidx, bBidy, bBidz, fieldE, fieldB, fieldB1, FoutJ, __idy,
            __idx, __xlen, XLEN, YLEN, ZLEN, ovlp, num_ele, block, bar);
      }

      if (load0 != new_load) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);
      }
    }
  }
  // __aurora_s_stopCounter();
  // int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
  // printf("spu counter: %d\n", spuCounter0);
}
#ifndef MAPU_RUNTIME_USE_DIRECT_D_DATA
#define MAPU_DDR_PTR(T, PM)                                                    \
  ((__DDR T *)({                                                               \
    uint64_t __mapu_runtime_addr = 0;                                          \
    mapsMemobjGetPhysicalAddress((PM)->d_data, &__mapu_runtime_addr);          \
    __mapu_runtime_addr;                                                       \
  }))
#else
#define MAPU_DDR_PTR(T, PM) ((__DDR T *)((PM)->d_data))
#endif

#define MAPU_HVAL(T, PM) (((T *)((PM)->h_data))[0])
#define MAPU_HVAL_OR(T, PM, DEFAULT_VALUE)                                     \
  ((PM) ? MAPU_HVAL(T, (PM)) : (T)(DEFAULT_VALUE))

static inline void mapu_geo_nr_Bfield_pushJ_vlo_set_device(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr) {
  if (kerstr != NULL && kerstr->pe != NULL) {
    mapsSetDevice((kerstr->pe)->device_id);
  }
}

#define MAPU_DEFINE_SET_PARAM(NAME)                                            \
  int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_##NAME(                  \
      mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm) {       \
    mapu_geo_nr_Bfield_pushJ_vlo_set_device(kerstr);                           \
    kerstr->NAME = pm;                                                         \
    return 0;                                                                  \
  }
#include "cooperative_groups.h"
#include "local_header.h"
#include <maps_runtime.h>
#include <scale.h>
#include <aurora.h>
#include <scale/barrier>

#ifndef MAPU_LONG
#define MAPU_LONG long long
#endif

#ifndef PUSHJ_VLO_REAL_PARALLEL_N
#define PUSHJ_VLO_REAL_PARALLEL_N 1
#endif
#ifndef IDX_LOCAL_XLEN
#define IDX_LOCAL_XLEN PUSHJ_VLO_REAL_PARALLEL_N
#endif
#if (PUSHJ_VLO_REAL_PARALLEL_N < 1) || (PUSHJ_VLO_REAL_PARALLEL_N > 4)
#error "multi supports 1 to 4 threads per block"
#endif
#if IDX_LOCAL_XLEN != PUSHJ_VLO_REAL_PARALLEL_N
#error "IDX_LOCAL_XLEN must equal PUSHJ_VLO_REAL_PARALLEL_N"
#endif
// #ifndef FULL_MASK
// #define FULL_MASK 0xffffffffu
// #endif


/* Fused evaluator for positions that consume all three Whitney families.
 * omrx, rx2, the quadratic quarter terms and the shifted-index factors are
 * formed once for f0/f1/if1. */
static __device__ KERNEL_M __noinline__ void
eval_f0_f1_if1(v8fp64 rx, v8fp64 dix, v8fp64 f0[5], v8fp64 f1[5],
                v8fp64 if1[5]) {
  const v8fp64 omrx = (1.00000000000000000e+00 - rx);
  const v8fp64 rx2 = (rx * rx);
  const v8fp64 dix_p1 = (dix + 1.00000000000000000e+00);
  const v8fp64 neg_dix = -dix;
  const v8fp64 quarter_omrx2 =
      (2.50000000000000000e-01 * (omrx * omrx));
  const v8fp64 quarter_rx2 = (2.50000000000000000e-01 * rx2);
  const v8fp64 linear =
      (2.50000000000000000e-01 +
       (5.00000000000000000e-01 * rx));

  const v8fp64 f0_b1 = quarter_omrx2;
  const v8fp64 f0_b2 = (5.00000000000000000e-01 - quarter_rx2);
  const v8fp64 f0_b3 = (linear - quarter_rx2);
  const v8fp64 f0_b4 = quarter_rx2;

  f0[0] = (f0_b1 * neg_dix);
  f0[1] = (f0_b1 * dix_p1) + (f0_b2 * neg_dix);
  f0[2] = (f0_b2 * dix_p1) + (f0_b3 * neg_dix);
  f0[3] = (f0_b3 * dix_p1) + (f0_b4 * neg_dix);
  f0[4] = (f0_b4 * dix_p1);

  const v8fp64 f1_b1 = (5.00000000000000000e-01 * omrx);
  const v8fp64 f1_b2 = (5.00000000000000000e-01 + (v8fp64){});
  const v8fp64 f1_b3 = (5.00000000000000000e-01 * rx);

  f1[0] = (f1_b1 * neg_dix);
  f1[1] = (f1_b1 * dix_p1) + (f1_b2 * neg_dix);
  f1[2] = (f1_b2 * dix_p1) + (f1_b3 * neg_dix);
  f1[3] = (f1_b3 * dix_p1);
  f1[4] = (v8fp64){};

  const v8fp64 if1_b1 =
      (1.00000000000000000e+00 - quarter_omrx2);
  const v8fp64 if1_b2 = linear;
  const v8fp64 if1_b3 = quarter_rx2;

  if1[0] = dix_p1 + (if1_b1 * neg_dix);
  if1[1] = (if1_b1 * dix_p1) + (if1_b2 * neg_dix);
  if1[2] = (if1_b2 * dix_p1) + (if1_b3 * neg_dix);
  if1[3] = (if1_b3 * dix_p1);
  if1[4] = (v8fp64){};
}

/* Narrow fused evaluator used where only f0 and if1 survive downstream. */
static __device__ KERNEL_M __noinline__ void
eval_f0_if1(v8fp64 rx, v8fp64 dix, v8fp64 f0[5], v8fp64 if1[5]) {
  const v8fp64 omrx = (1.00000000000000000e+00 - rx);
  const v8fp64 rx2 = (rx * rx);
  const v8fp64 dix_p1 = (dix + 1.00000000000000000e+00);
  const v8fp64 neg_dix = -dix;
  const v8fp64 quarter_omrx2 =
      (2.50000000000000000e-01 * (omrx * omrx));
  const v8fp64 quarter_rx2 = (2.50000000000000000e-01 * rx2);
  const v8fp64 linear =
      (2.50000000000000000e-01 +
       (5.00000000000000000e-01 * rx));

  const v8fp64 f0_b1 = quarter_omrx2;
  const v8fp64 f0_b2 = (5.00000000000000000e-01 - quarter_rx2);
  const v8fp64 f0_b3 = (linear - quarter_rx2);
  const v8fp64 f0_b4 = quarter_rx2;

  f0[0] = (f0_b1 * neg_dix);
  f0[1] = (f0_b1 * dix_p1) + (f0_b2 * neg_dix);
  f0[2] = (f0_b2 * dix_p1) + (f0_b3 * neg_dix);
  f0[3] = (f0_b3 * dix_p1) + (f0_b4 * neg_dix);
  f0[4] = (f0_b4 * dix_p1);

  const v8fp64 if1_b1 =
      (1.00000000000000000e+00 -
       quarter_omrx2);
  const v8fp64 if1_b2 = linear;
  const v8fp64 if1_b3 = quarter_rx2;

  if1[0] = dix_p1 + (if1_b1 * neg_dix);
  if1[1] = (if1_b1 * dix_p1) + (if1_b2 * neg_dix);
  if1[2] = (if1_b2 * dix_p1) + (if1_b3 * neg_dix);
  if1[3] = (if1_b3 * dix_p1);
  if1[4] = (v8fp64){};
}

/* Single-family evaluator retained for narrow if1-only positions. */
static __device__ KERNEL_M __noinline__ void
eval_if1(v8fp64 rx, v8fp64 dix, v8fp64 if1[5]) {
  const v8fp64 omrx = (1.00000000000000000e+00 - rx);
  const v8fp64 rx2 = (rx * rx);
  const v8fp64 dix_p1 = (dix + 1.00000000000000000e+00);
  const v8fp64 neg_dix = -dix;
  const v8fp64 if1_b1 =
      (1.00000000000000000e+00 -
       (2.50000000000000000e-01 * (omrx * omrx)));
  const v8fp64 if1_b2 =
      (2.50000000000000000e-01 +
       (5.00000000000000000e-01 * rx));
  const v8fp64 if1_b3 = (2.50000000000000000e-01 * rx2);

  if1[0] = dix_p1 + (if1_b1 * neg_dix);
  if1[1] = (if1_b1 * dix_p1) + (if1_b2 * neg_dix);
  if1[2] = (if1_b2 * dix_p1) + (if1_b3 * neg_dix);
  if1[3] = (if1_b3 * dix_p1);
  if1[4] = (v8fp64){};
}

/* -------------------------------------------------------------------------- */
/* Precomputed weight/path bank split by axis across private DM regions.      */
/* x → __mem1__, y → __mem2__, z → __mem3__; state moves to __mem4__.         */
/* Each axis remains 4 positions × 3 slots × [5] v8fp64 = 3840 bytes.         */
/* -------------------------------------------------------------------------- */

#define PUSHJ_WT_POS_COUNT 4
#define PUSHJ_WT_KIND_COUNT 3
#define PUSHJ_WT_AXIS_SLOT_COUNT (PUSHJ_WT_POS_COUNT * PUSHJ_WT_KIND_COUNT)

enum pushJ_wt_kind_t {
  PUSHJ_WT_F0 = 0,
  PUSHJ_WT_F1 = 1,
  PUSHJ_WT_IF1 = 2
};

typedef struct {
  v8fp64 slot[PUSHJ_WT_AXIS_SLOT_COUNT][5];
} pushJ_wt_axis_bank_t;

typedef struct {
  pushJ_wt_axis_bank_t *x;
  pushJ_wt_axis_bank_t *y;
  pushJ_wt_axis_bank_t *z;
} pushJ_weight_bank_t;

/* SCALE native: x/y/z/st are static __mem1__/__mem2__/__mem3__/__mem4__;
 * no CUDA dynamic-shared sizing shims. */

/* SPU-only: bind the OPT-6 axis banks for the serial tile owner. */
static __device__ __attribute__((always_inline)) inline void
pushJ_wt_bank_bind(pushJ_weight_bank_t *bank, pushJ_wt_axis_bank_t *x,
                   pushJ_wt_axis_bank_t *y, pushJ_wt_axis_bank_t *z) {
  bank->x = x;
  bank->y = y;
  bank->z = z;
}

static __device__ KERNEL_M __attribute__((always_inline)) inline int
pushJ_wt_axis_slot(int pos, int kind) {
  return (pos * PUSHJ_WT_KIND_COUNT) + kind;
}

#define PUSHJ_WT_AXIS_ACCESSORS(axis_name, member)                            \
  static __device__ KERNEL_M __attribute__((always_inline)) inline v8fp64 *  \
  pushJ_wt_##axis_name(pushJ_weight_bank_t *bank, int pos, int kind) {       \
    return bank->member->slot[pushJ_wt_axis_slot(pos, kind)];                \
  }                                                                          \
  static __device__ KERNEL_M __attribute__((always_inline)) inline           \
      const v8fp64 *                                                         \
      pushJ_wt_##axis_name##_c(const pushJ_weight_bank_t *bank, int pos,     \
                               int kind) {                                    \
    return bank->member->slot[pushJ_wt_axis_slot(pos, kind)];                \
  }

PUSHJ_WT_AXIS_ACCESSORS(x, x)
PUSHJ_WT_AXIS_ACCESSORS(y, y)
PUSHJ_WT_AXIS_ACCESSORS(z, z)

#undef PUSHJ_WT_AXIS_ACCESSORS

/* Path differences occupy weight slots that are provably dead for the whole
 * K1/K2/K3 particle path.  This gives a persistent path bank with zero extra
 * private-DM footprint:
 *   x: pos0/f1, pos3/f0, pos3/f1 -> X01, X12, X23
 *   y: pos0/f0, pos0/f1, pos3/f1 -> Y01, Y12, Y23
 *   z: pos0/f0, pos0/f1, pos0/if1 -> Z12, Z23, Z13
 */
#define PUSHJ_PATH_ACCESSORS(path_name, member, pos, kind)                   \
  static __device__ KERNEL_M __attribute__((always_inline)) inline v8fp64 * \
  pushJ_path_##path_name(pushJ_weight_bank_t *bank) {                       \
    return bank->member->slot[pushJ_wt_axis_slot(pos, kind)];               \
  }                                                                          \
  static __device__ KERNEL_M __attribute__((always_inline)) inline           \
      const v8fp64 *                                                         \
      pushJ_path_##path_name##_c(const pushJ_weight_bank_t *bank) {          \
    return bank->member->slot[pushJ_wt_axis_slot(pos, kind)];               \
  }

PUSHJ_PATH_ACCESSORS(x01, x, 0, PUSHJ_WT_F1)
PUSHJ_PATH_ACCESSORS(x12, x, 3, PUSHJ_WT_F0)
PUSHJ_PATH_ACCESSORS(x23, x, 3, PUSHJ_WT_F1)
PUSHJ_PATH_ACCESSORS(y01, y, 0, PUSHJ_WT_F0)
PUSHJ_PATH_ACCESSORS(y12, y, 0, PUSHJ_WT_F1)
PUSHJ_PATH_ACCESSORS(y23, y, 3, PUSHJ_WT_F1)
PUSHJ_PATH_ACCESSORS(z12, z, 0, PUSHJ_WT_F0)
PUSHJ_PATH_ACCESSORS(z23, z, 0, PUSHJ_WT_F1)
PUSHJ_PATH_ACCESSORS(z13, z, 0, PUSHJ_WT_IF1)

#undef PUSHJ_PATH_ACCESSORS

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_path_fill(v8fp64 *dst, const v8fp64 *hi, const v8fp64 *lo) {
#pragma clang loop unroll(full)
  for (long i = 0; i < 5; i++) {
    dst[i] = hi[i] - lo[i];
  }
}

/* opt_stage51-3: every caller uses a compile-time position.  Keep the three
 * evaluator bodies out of line, but inline these small routing wrappers so
 * pos*3+kind and bank slot addresses fold to constants.  This removes two
 * layers of MPU helper calls without duplicating the evaluator arithmetic. */

/* Position 0: only slots consumed by downstream deposit/K2 helpers. */
static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos0_deposit(pushJ_weight_bank_t *bank, v8fp64 rx_x,
                           v8fp64 dix_x, v8fp64 rx_y, v8fp64 dix_y) {
  eval_f0_if1(rx_x, dix_x, pushJ_wt_x(bank, 0, PUSHJ_WT_F0),
               pushJ_wt_x(bank, 0, PUSHJ_WT_IF1));
  eval_if1(rx_y, dix_y, pushJ_wt_y(bank, 0, PUSHJ_WT_IF1));
}

/* Position 1: all three families are consumed on all three axes. */
static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos1_xyz(pushJ_weight_bank_t *bank, v8fp64 rx_x,
                       v8fp64 dix_x, v8fp64 rx_y, v8fp64 dix_y,
                       v8fp64 rx_z, v8fp64 dix_z) {
  eval_f0_f1_if1(rx_x, dix_x, pushJ_wt_x(bank, 1, PUSHJ_WT_F0),
                  pushJ_wt_x(bank, 1, PUSHJ_WT_F1),
                  pushJ_wt_x(bank, 1, PUSHJ_WT_IF1));
  eval_f0_f1_if1(rx_y, dix_y, pushJ_wt_y(bank, 1, PUSHJ_WT_F0),
                  pushJ_wt_y(bank, 1, PUSHJ_WT_F1),
                  pushJ_wt_y(bank, 1, PUSHJ_WT_IF1));
  eval_f0_f1_if1(rx_z, dix_z, pushJ_wt_z(bank, 1, PUSHJ_WT_F0),
                  pushJ_wt_z(bank, 1, PUSHJ_WT_F1),
                  pushJ_wt_z(bank, 1, PUSHJ_WT_IF1));
}

/* Position 2 fixed-axis helpers. */
static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos2_x(pushJ_weight_bank_t *bank, v8fp64 rx, v8fp64 dix) {
  eval_f0_f1_if1(rx, dix, pushJ_wt_x(bank, 2, PUSHJ_WT_F0),
                  pushJ_wt_x(bank, 2, PUSHJ_WT_F1),
                  pushJ_wt_x(bank, 2, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos2_y(pushJ_weight_bank_t *bank, v8fp64 rx, v8fp64 dix) {
  eval_f0_f1_if1(rx, dix, pushJ_wt_y(bank, 2, PUSHJ_WT_F0),
                  pushJ_wt_y(bank, 2, PUSHJ_WT_F1),
                  pushJ_wt_y(bank, 2, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos2_z_if1(pushJ_weight_bank_t *bank, v8fp64 rx, v8fp64 dix) {
  eval_if1(rx, dix, pushJ_wt_z(bank, 2, PUSHJ_WT_IF1));
}

/* Position 3 narrow helpers: only live downstream families are generated. */
static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos3_x_if1(pushJ_weight_bank_t *bank, v8fp64 rx, v8fp64 dix) {
  eval_if1(rx, dix, pushJ_wt_x(bank, 3, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos3_y_f0_if1(pushJ_weight_bank_t *bank, v8fp64 rx,
                            v8fp64 dix) {
  eval_f0_if1(rx, dix, pushJ_wt_y(bank, 3, PUSHJ_WT_F0),
               pushJ_wt_y(bank, 3, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_wt_fill_pos3_z_f0_if1(pushJ_weight_bank_t *bank, v8fp64 rx,
                            v8fp64 dix) {
  eval_f0_if1(rx, dix, pushJ_wt_z(bank, 3, PUSHJ_WT_F0),
               pushJ_wt_z(bank, 3, PUSHJ_WT_IF1));
}

/* OPT-4: fused B-field integrals. Every mathematical output keeps its own
 * accumulator and the original z->y->x update order. Only loop control,
 * address generation, and common weight routing are shared. */

static __device__ KERNEL_M __noinline__ void pushJ_B_fused_iBy_bank(
    const pushJ_weight_bank_t *__restrict__ bank,
    const double *__restrict__ shB0, const double *__restrict__ shB1,
    int tile_xlen,
    v8fp64 *__restrict__ term0_out, v8fp64 *__restrict__ term1_out) {
  const v8fp64 *wF0z = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *wF1y = pushJ_wt_y_c(bank, 1, PUSHJ_WT_F1);
  const v8fp64 *difX01 = pushJ_path_x01_c(bank);
  const v8fp64 *difX12 = pushJ_path_x12_c(bank);
  __mem0__ v8fp64 tx01[5], tx12[5];
  v8fp64 sum0 = (v8fp64){};
  v8fp64 sum1 = (v8fp64){};
  for (long z = 0; z < 5; z++) {
    for (long y = 0; y < 5; y++) {
#pragma clang loop unroll(full)
      for (long x = 0; x < 5; x++) {
        tx01[x] = difX01[x] * wF1y[y];
        tx12[x] = difX12[x] * wF1y[y];
      }
#pragma clang loop unroll(full)
      for (long x = 0; x < 5; x++) {
        const int allidx = x + tile_xlen * (y + 5 * z);
        sum0 = sum0 +
               (shB0[allidx * 3 + 2] * (wF0z[z] * tx01[x]));
        sum1 = sum1 +
               (shB1[allidx * 3 + 2] * (wF0z[z] * tx12[x]));
      }
    }
  }
  *term0_out = sum0;
  *term1_out = sum1;
}

/* One traversal for the comp0+comp1 pair belonging to one B snapshot.
 * Called once for shB0 and once for shB1: four old traversals -> two. */
static __device__ KERNEL_M __noinline__ void pushJ_B_fused_iBz_pair_bank(
    const pushJ_weight_bank_t *__restrict__ bank,
    const double *__restrict__ field, int f0x_pos,
    const v8fp64 *difY, const v8fp64 *difX,
    int tile_xlen,
    v8fp64 *__restrict__ comp0_out, v8fp64 *__restrict__ comp1_out) {
  const v8fp64 *wF0x = pushJ_wt_x_c(bank, f0x_pos, PUSHJ_WT_F0);
  const v8fp64 *wF0y = pushJ_wt_y_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *wF1z = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F1);
  __mem0__ v8fp64 tx[5];
  v8fp64 sum0 = (v8fp64){};
  v8fp64 sum1 = (v8fp64){};
  for (long z = 0; z < 5; z++) {
#pragma clang loop unroll(full)
    for (long x = 0; x < 5; x++) {
      tx[x] = difX[x] * wF1z[z];
    }
    for (long y = 0; y < 5; y++) {
      const v8fp64 tyz = difY[y] * wF1z[z];
#pragma clang loop unroll(full)
      for (long x = 0; x < 5; x++) {
        const int allidx = x + tile_xlen * (y + 5 * z);
        sum0 = sum0 +
               (field[allidx * 3 + 0] * (wF0x[x] * tyz));
        sum1 = sum1 +
               (field[allidx * 3 + 1] * (wF0y[y] * tx[x]));
      }
    }
  }
  *comp0_out = sum0;
  *comp1_out = sum1;
}

static __device__ KERNEL_M __noinline__ void pushJ_B_fused_iBy23_bank(
    const pushJ_weight_bank_t *__restrict__ bank,
    const double *__restrict__ shB1, int tile_xlen,
    v8fp64 *__restrict__ term0_out,
    v8fp64 *__restrict__ term1_out) {
  const v8fp64 *wF0x = pushJ_wt_x_c(bank, 2, PUSHJ_WT_F0);
  const v8fp64 *wF1y = pushJ_wt_y_c(bank, 2, PUSHJ_WT_F1);
  const v8fp64 *difZ12 = pushJ_path_z12_c(bank);
  const v8fp64 *difZ23 = pushJ_path_z23_c(bank);
  v8fp64 sum0 = (v8fp64){};
  v8fp64 sum1 = (v8fp64){};
  for (long z = 0; z < 5; z++) {
    for (long y = 0; y < 5; y++) {
      const v8fp64 tyz0 = difZ12[z] * wF1y[y];
      const v8fp64 tyz1 = difZ23[z] * wF1y[y];
#pragma clang loop unroll(full)
      for (long x = 0; x < 5; x++) {
        const int allidx = x + tile_xlen * (y + 5 * z);
        const double field0 = shB1[allidx * 3 + 0];
        sum0 = sum0 + (field0 * (wF0x[x] * tyz0));
        sum1 = sum1 + (field0 * (wF0x[x] * tyz1));
      }
    }
  }
  *term0_out = sum0;
  *term1_out = sum1;
}

/* Four independent accumulators share one z/y/x traversal. Their individual
 * update sequence and multiplication nesting match the four old integrals. */
static __device__ KERNEL_M __noinline__ void pushJ_B_fused_iBx_bank(
    const pushJ_weight_bank_t *__restrict__ bank,
    const double *__restrict__ shB1, int tile_xlen,
    v8fp64 *__restrict__ z12_out,
    v8fp64 *__restrict__ z23_out, v8fp64 *__restrict__ y12_out,
    v8fp64 *__restrict__ y23_out) {
  const v8fp64 *wF0y2 = pushJ_wt_y_c(bank, 2, PUSHJ_WT_F0);
  const v8fp64 *wF0z1 = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *wF0z3 = pushJ_wt_z_c(bank, 3, PUSHJ_WT_F0);
  const v8fp64 *wF1x2 = pushJ_wt_x_c(bank, 2, PUSHJ_WT_F1);
  const v8fp64 *difZ12 = pushJ_path_z12_c(bank);
  const v8fp64 *difZ23 = pushJ_path_z23_c(bank);
  const v8fp64 *difY12 = pushJ_path_y12_c(bank);
  const v8fp64 *difY23 = pushJ_path_y23_c(bank);
  __mem0__ v8fp64 txZ12[5], txZ23[5], txY12[5], txY23[5];
  v8fp64 sumZ12 = (v8fp64){};
  v8fp64 sumZ23 = (v8fp64){};
  v8fp64 sumY12 = (v8fp64){};
  v8fp64 sumY23 = (v8fp64){};
  for (long z = 0; z < 5; z++) {
#pragma clang loop unroll(full)
    for (long x = 0; x < 5; x++) {
      txZ12[x] = difZ12[z] * wF1x2[x];
      txZ23[x] = difZ23[z] * wF1x2[x];
    }
    for (long y = 0; y < 5; y++) {
#pragma clang loop unroll(full)
      for (long x = 0; x < 5; x++) {
        txY12[x] = difY12[y] * wF1x2[x];
        txY23[x] = difY23[y] * wF1x2[x];
      }
#pragma clang loop unroll(full)
      for (long x = 0; x < 5; x++) {
        const int allidx = x + tile_xlen * (y + 5 * z);
        const double field1 = shB1[allidx * 3 + 1];
        const double field2 = shB1[allidx * 3 + 2];
        sumZ12 = sumZ12 + (field1 * (wF0y2[y] * txZ12[x]));
        sumZ23 = sumZ23 + (field1 * (wF0y2[y] * txZ23[x]));
        sumY12 = sumY12 + (field2 * (wF0z1[z] * txY12[x]));
        sumY23 = sumY23 + (field2 * (wF0z3[z] * txY23[x]));
      }
    }
  }
  *z12_out = sumZ12;
  *z23_out = sumZ23;
  *y12_out = sumY12;
  *y23_out = sumY23;
}

/* Bank-indexed E-field interpolation */

/* Medium FMA: cache 2D weights per (idy,idz); keep f1*(f0*f0) nesting. */
static __device__ KERNEL_M __noinline__ v8fp64
pushJ_E_interp_Ex_bank(const pushJ_weight_bank_t *__restrict__ bank,
                       const double *__restrict__ shE0, int tile_xlen) {
  const v8fp64 *f1_x1 = pushJ_wt_x_c(bank, 1, PUSHJ_WT_F1);
  const v8fp64 *f0_y1 = pushJ_wt_y_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *f0_z1 = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F0);
  v8fp64 AllEx = (v8fp64){};
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      const v8fp64 wyz = ((f0_y1)[idy] * (f0_z1)[idz]);
      #pragma clang loop unroll(full)
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            ((((shE0)[(0 + (3 * (idx + (tile_xlen * (idy + (idz * 5))))))] +
                         0)) *
             ((f1_x1)[idx] * wyz));
        AllEx = (AllEx + term);
      }
    }
  }
  return AllEx;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_E_interp_Ey_bank(const pushJ_weight_bank_t *__restrict__ bank,
                       const double *__restrict__ shE0, int tile_xlen) {
  const v8fp64 *f1_y1 = pushJ_wt_y_c(bank, 1, PUSHJ_WT_F1);
  const v8fp64 *f0_z1 = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *f0_x1 = pushJ_wt_x_c(bank, 1, PUSHJ_WT_F0);
  v8fp64 AllEy = (v8fp64){};
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      const v8fp64 wzx = ((f0_z1)[idy] * (f0_x1)[idz]);
      #pragma clang loop unroll(full)
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            ((((shE0)[(1 + (3 * (idz + (tile_xlen * (idx + (idy * 5))))))] +
                         0)) *
             ((f1_y1)[idx] * wzx));
        AllEy = (AllEy + term);
      }
    }
  }
  return AllEy;
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_E_interp_Ez_bank(const pushJ_weight_bank_t *__restrict__ bank,
                       const double *__restrict__ shE0, int tile_xlen) {
  const v8fp64 *f1_z1 = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F1);
  const v8fp64 *f0_x1 = pushJ_wt_x_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *f0_y1 = pushJ_wt_y_c(bank, 1, PUSHJ_WT_F0);
  v8fp64 AllEz = (v8fp64){};
  for (long idz = 0; idz < 5; idz = (idz + 1)) {
    for (long idy = 0; idy < 5; idy = (idy + 1)) {
      const v8fp64 wxy = ((f0_x1)[idy] * (f0_y1)[idz]);
      #pragma clang loop unroll(full)
      for (long idx = 0; idx < 4; idx = (idx + 1)) {
        v8fp64 term =
            ((((shE0)[(2 + (3 * (idy + (tile_xlen * (idz + (idx * 5))))))] +
                         0)) *
             ((f1_z1)[idx] * wxy));
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
  double Deltat, TWO_DELTAT;
  double Tori_X0;
  double X_PUSH_SCALE, Y_FORCE_SCALE, Z_PUSH_SCALE;
  double X_GEOMETRY_SCALE;
  double J_GEO_X_SCALE, J_GEO_Y_SCALE, J_GEO_Z_SCALE;
  double XO, YO, ZO;
  double zmid;
  double Midx, Midy, Midz;
  int bBidx, bBidy, bBidz;
  /* Tile-only deposit geometry.  These five-point factors are independent of
   * the particle batch and are therefore formed once by the SPU tile setup,
   * then reused by every MPU K3 call. */
  double deposit_geo_x[5];
  double deposit_geo_y[5];
  double deposit_geo_z[5];
} pushJ_ctx_t;

/* OPT-1: kernel-invariant fields — call once at kernel entry. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_ctx_init_const(pushJ_ctx_t *ctx, double DELTA_X, double DELTA_Y,
                         double DELTA_Z, double Deltat, double Tori_X0,
                         double Charge0, double Mass0) {
  const double DELTA_X2 = (DELTA_X * DELTA_X);
  const double DELTA_Y2 = (DELTA_Y * DELTA_Y);
  const double DELTA_Z2 = (DELTA_Z * DELTA_Z);
  const double INV_DELTA_X2 =
      (1.00000000000000000e+00 / DELTA_X2);
  const double INV_DELTA_Z2 =
      (1.00000000000000000e+00 / DELTA_Z2);
  const double TX02 = (Tori_X0 * Tori_X0);
  const double INV_TX02 = (1.00000000000000000e+00 / TX02);
  const double QE_MASS = (Charge0 / Mass0);
  const double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));
  const double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));
  const double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

  ctx->Deltat = Deltat;
  ctx->TWO_DELTAT = (2.00000000000000000e+00 * Deltat);
  ctx->Tori_X0 = Tori_X0;
  ctx->X_PUSH_SCALE =
      INV_DELTA_X2 * (Deltat * QE_MASS);
  ctx->Y_FORCE_SCALE =
      TX02 *
      (QE_MASS *
       (Deltat * (1.00000000000000000e+00 / DELTA_Y2)));
  ctx->Z_PUSH_SCALE =
      INV_DELTA_Z2 * (Deltat * QE_MASS);
  ctx->X_GEOMETRY_SCALE =
      DELTA_Y2 * (INV_DELTA_X2 * INV_TX02);
  ctx->J_GEO_X_SCALE =
      grid_geo_x * (Tori_X0 * Charge0);
  ctx->J_GEO_Y_SCALE =
      grid_geo_y * (Charge0 / Tori_X0);
  ctx->J_GEO_Z_SCALE =
      grid_geo_z * (Tori_X0 * Charge0);
}

/* OPT-1: per-tile fields only (XO/YO/ZO/Mid/bB). */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_ctx_init_tile(pushJ_ctx_t *ctx, double XO, double YO, double ZO,
                        double zmid, double Midx, double Midy, double Midz,
                        int bBidx, int bBidy, int bBidz) {
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

  /* opt_stage51-1: Jx/Jy/Jz geometry depends only on the current field tile.
   * Jx and Jz share the same reciprocal radius, so only five divisions are
   * performed per tile instead of ten divisions per SIMD8 particle batch. */
#pragma clang loop unroll(full)
  for (int x = 0; x < 5; ++x) {
    const double radius = ctx->Tori_X0 + (XO + (bBidx + x));
    const double inv_radius = 1.00000000000000000e+00 / radius;
    ctx->deposit_geo_x[x] = ctx->J_GEO_X_SCALE * inv_radius;
    ctx->deposit_geo_y[x] = ctx->J_GEO_Y_SCALE * radius;
    ctx->deposit_geo_z[x] = ctx->J_GEO_Z_SCALE * inv_radius;
  }
}

static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_ctx_init(pushJ_ctx_t *ctx, double DELTA_X, double DELTA_Y,
                   double DELTA_Z, double Deltat, double Tori_X0,
                   double Charge0, double Mass0, double XO, double YO,
                   double ZO, double zmid, double Midx, double Midy,
                   double Midz, int bBidx, int bBidy, int bBidz) {
  pushJ_vlo_ctx_init_const(ctx, DELTA_X, DELTA_Y, DELTA_Z, Deltat, Tori_X0,
                           Charge0, Mass0);
  pushJ_vlo_ctx_init_tile(ctx, XO, YO, ZO, zmid, Midx, Midy, Midz, bBidx, bBidy,
                          bBidz);
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

/* Merge the 12/23 deposits by output component.  Jx preserves the original
 * two-step accumulation sequence.  opt_stage42 intentionally factors the
 * common Jy x term and combines its 12/23 yz terms before one accumulation;
 * this is algebraically equivalent but not IEEE-754 bitwise identical. */
static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_Jx(const pushJ_weight_bank_t *__restrict__ bank,
                     const pushJ_vlo_state_t *st, const pushJ_ctx_t *ctx,
                     v8fp64 *__restrict__ shJ_incf, int full_batch) {
  const v8fp64 *difX12 = pushJ_path_x12_c(bank);
  const v8fp64 *difX23 = pushJ_path_x23_c(bank);
  const v8fp64 *f0_y1 = pushJ_wt_y_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *f0_z1 = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *f0_y3 = pushJ_wt_y_c(bank, 3, PUSHJ_WT_F0);
  const v8fp64 *f0_z3 = pushJ_wt_z_c(bank, 3, PUSHJ_WT_F0);
  __mem0__ v8fp64 pathX12[5];
  __mem0__ v8fp64 pathX23[5];
  /* Branch once before the five-entry preparation.  Keeping the predicate
   * outside the unrolled loop avoids five repeated scalar tests. */
  if (full_batch) {
#pragma clang loop unroll(full)
    for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
      const double geo_x = ctx->deposit_geo_x[xyzx];
      pathX12[xyzx] = geo_x * difX12[xyzx];
      pathX23[xyzx] = geo_x * difX23[xyzx];
    }
  } else {
#pragma clang loop unroll(full)
    for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
      const double geo_x = ctx->deposit_geo_x[xyzx];
      pathX12[xyzx] = geo_x * (st->simd_mask * difX12[xyzx]);
      pathX23[xyzx] = geo_x * (st->simd_mask * difX23[xyzx]);
    }
  }
  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      const v8fp64 wyz12 = ((f0_y1)[xyzy] * (f0_z1)[xyzz]);
      const v8fp64 wyz23 = ((f0_y3)[xyzy] * (f0_z3)[xyzz]);
      long xyzx;
      #pragma clang loop unroll(full)
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 accum = shJ_incf[((allidx * 3) + 0)];
        accum = accum + (pathX12[xyzx] * wyz12);
        accum = accum + (pathX23[xyzx] * wyz23);
        shJ_incf[((allidx * 3) + 0)] = accum;
      }
    }
  }
}

/* opt_stage52: Jy and Jz have the same z/y/x domain and both consume
 * f0_x2[x].  Fuse their grid traversal while preserving each component's
 * original per-node arithmetic and accumulation order. */
static __device__ KERNEL_M __noinline__ void
pushJ_vlo_deposit_JyJz(const pushJ_weight_bank_t *__restrict__ bank,
                       const pushJ_vlo_state_t *st,
                       const pushJ_ctx_t *ctx,
                       v8fp64 *__restrict__ shJ_incf, int full_batch) {
  const v8fp64 *pathY12 = pushJ_path_y12_c(bank);
  const v8fp64 *pathY23 = pushJ_path_y23_c(bank);
  const v8fp64 *pathZ13 = pushJ_path_z13_c(bank);
  const v8fp64 *f0_x2 = pushJ_wt_x_c(bank, 2, PUSHJ_WT_F0);
  const v8fp64 *f0_z1 = pushJ_wt_z_c(bank, 1, PUSHJ_WT_F0);
  const v8fp64 *f0_z3 = pushJ_wt_z_c(bank, 3, PUSHJ_WT_F0);
  const v8fp64 *f0_y2 = pushJ_wt_y_c(bank, 2, PUSHJ_WT_F0);
  __mem0__ v8fp64 xFactorY[5];
  __mem0__ v8fp64 xFactorZ[5];

  if (full_batch) {
#pragma clang loop unroll(full)
    for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
      const v8fp64 base_x = f0_x2[xyzx];
      xFactorY[xyzx] = ctx->deposit_geo_y[xyzx] * base_x;
      xFactorZ[xyzx] = ctx->deposit_geo_z[xyzx] * base_x;
    }
  } else {
#pragma clang loop unroll(full)
    for (long xyzx = 0; xyzx < 5; xyzx = (xyzx + 1)) {
      const v8fp64 base_x = st->simd_mask * f0_x2[xyzx];
      xFactorY[xyzx] = ctx->deposit_geo_y[xyzx] * base_x;
      xFactorZ[xyzx] = ctx->deposit_geo_z[xyzx] * base_x;
    }
  }

  long xyzz;
  for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
    long xyzy;
    for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
      const v8fp64 yzFactorY =
          (pathY12[xyzy] * f0_z1[xyzz]) +
          (pathY23[xyzy] * f0_z3[xyzz]);
      const v8fp64 yzFactorZ = pathZ13[xyzz] * f0_y2[xyzy];
      long xyzx;
#pragma clang loop unroll(full)
      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
        const int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));
        v8fp64 accum_y = shJ_incf[((allidx * 3) + 1)];
        v8fp64 accum_z = shJ_incf[((allidx * 3) + 2)];
        accum_y = accum_y + (xFactorY[xyzx] * yzFactorY);
        accum_z = accum_z + (xFactorZ[xyzx] * yzFactorZ);
        shJ_incf[((allidx * 3) + 1)] = accum_y;
        shJ_incf[((allidx * 3) + 2)] = accum_z;
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

  /* OPT-2: issue all memcpy_async first; one barrier at end (targets disjoint).
   */
  /* Each thread owns disjoint y-z rows.  DMA completion is tracked per
   * thread; the block barrier waits for every thread's submitted rows. */
  for (int line = (int)__idx; line < 25; line += (int)__xlen) {
    const int xyzy = line % 5;
    const int xyzz = line / 5;
    const int total_idx = 3 * 5 * line;
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
  }
  bar.arrive_and_wait();
}

/* opt_stage55: four adjacent dense x cells share only the read-only fields.
 * FoutJ deliberately remains on the stage52 per-cell read/modify/write path. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_K1_load_fields_shared_8x5x5(
    double *shE0, double *shB0, double *shB1,
    __DDR double *fieldE, __DDR double *fieldB, __DDR double *fieldB1,
    MAPU_LONG __idy, MAPU_LONG __idx, MAPU_LONG __xlen,
    int bBidx, int bBidy, int bBidz,
    MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, int num_ele,
    cooperative_groups::thread_block block,
    scale::barrier<scale::thread_scope_block> &bar) {
  const size_t row_bytes = (size_t)(3 * 8) * sizeof(double);
  for (int line = (int)__idx; line < 25; line += (int)__xlen) {
    const int y = line % 5;
    const int z = line / 5;
    const int local = 3 * 8 * line;
    const MAPU_LONG ddr = pushJ_vlo_field_ddr_elem_offset(
        __idy, bBidx, bBidy, bBidz, y, z, XLEN, YLEN, ZLEN, ovlp,
        num_ele);
    memcpy_async(block, (unsigned *)(shE0 + local),
                 (__DDR unsigned *)(fieldE + ddr), (uint64_t)row_bytes, bar);
    memcpy_async(block, (unsigned *)(shB0 + local),
                 (__DDR unsigned *)(fieldB + ddr), (uint64_t)row_bytes, bar);
    memcpy_async(block, (unsigned *)(shB1 + local),
                 (__DDR unsigned *)(fieldB1 + ddr), (uint64_t)row_bytes, bar);
  }
  bar.arrive_and_wait();
}

/* Keep the exact stage52 J transaction boundary: every active cell reloads
 * its current 5x5x5 J tile after the previous cell has completed its store. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_K1_load_J_shared_5x5x5(
    double *shJ0, __DDR double *FoutJ, MAPU_LONG __idy,
    MAPU_LONG __idx, MAPU_LONG __xlen,
    int bBidx, int bBidy, int bBidz, MAPU_LONG XLEN, MAPU_LONG YLEN,
    MAPU_LONG ZLEN, int ovlp, int num_ele,
    cooperative_groups::thread_block block,
    scale::barrier<scale::thread_scope_block> &bar) {
  const size_t row_bytes = (size_t)(3 * 5) * sizeof(double);
  for (int line = (int)__idx; line < 25; line += (int)__xlen) {
    const int y = line % 5;
    const int z = line / 5;
    const int local = 3 * 5 * line;
    const MAPU_LONG ddr = pushJ_vlo_field_ddr_elem_offset(
        __idy, bBidx, bBidy, bBidz, y, z, XLEN, YLEN, ZLEN, ovlp,
        num_ele);
    memcpy_async(block, (unsigned *)(shJ0 + local),
                 (__DDR unsigned *)(FoutJ + ddr), (uint64_t)row_bytes, bar);
  }
  bar.arrive_and_wait();
}

/* SPU-visible MPU entry: keep external linkage (no static).
 * Geometry/time scalars come from pushJ_ctx_t; x0/x1 weight filling is MPU→MPU.
 */
__device__ KERNEL_M __noinline__ void pushJ_vlo_K1_setup_weights_x0x1(
    pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
    double *particle_dm /* DM staging, not DDR */, int g_inner, long load0,
    const pushJ_ctx_t *ctx) {
  __mem0__ v8fp64 head[6];
  double(*head_l)[8] = (double(*)[8])head;
  const int full_batch = ((g_inner + 8) <= load0);

  /* opt_stage51-2: the common eight-particle batch has no lane predicate and
   * no field-selection branch.  The original masked gather remains the sole
   * path for a 1..7-particle tail. */
  if (full_batch) {
#pragma clang loop unroll(full)
    for (int lane = 0; lane < 8; lane++) {
      const int src = g_inner + lane;
      head_l[0][lane] = particle_dm[0 + 6 * src];
      head_l[1][lane] = particle_dm[1 + 6 * src];
      head_l[2][lane] = particle_dm[2 + 6 * src];
      head_l[3][lane] = particle_dm[3 + 6 * src];
      head_l[4][lane] = particle_dm[4 + 6 * src];
      head_l[5][lane] = particle_dm[5 + 6 * src];
    }
    st->simd_mask = (1.00000000000000000e+00 + (v8fp64){});
  } else {
    for (int f = 0; f < 6; f++) {
#pragma clang loop unroll(full)
      for (int lane = 0; lane < 8; lane++) {
        const int cid = g_inner + lane;
        const int src = (cid < load0) ? cid : 0;
        head_l[f][lane] = particle_dm[f + 6 * src];
      }
    }

    st->simd_mask = (v8fp64){};
    double *simd_mask_l = (double *)&st->simd_mask;
#pragma clang loop unroll(full)
    for (int lane = 0; lane < 8; lane++) {
      simd_mask_l[lane] = ((g_inner + lane) < load0) ? 1.0 : 0.0;
    }
  }

  st->xx1 = head[0] - (5.00000000000000000e-01);
  st->xy1 = head[1] - (5.00000000000000000e-01);
  st->xz1 = head[2] - (5.00000000000000000e-01);
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
  st->s_dix0x = (Midx0 - (ctx->Midx));
  st->s_dix0y = (Midy0 - (ctx->Midy));
  st->s_dix0z = (Midz0 - (ctx->Midz));
  st->s_dix1x = (Midx1 - (ctx->Midx));
  st->s_dix1y = (Midy1 - (ctx->Midy));
  st->s_dix1z = (Midz1 - (ctx->Midz));

  /* Position 0 only feeds f0_x0, if1_x0 and if1_y0 downstream.  Keep the
   * state layout and coordinate setup unchanged, but avoid building the six
   * weight arrays that have no consumer. */
  pushJ_wt_fill_pos0_deposit(bank, st->s_rx0x, st->s_dix0x, st->s_rx0y,
                             st->s_dix0y);
  pushJ_wt_fill_pos1_xyz(bank, st->s_rx1x, st->s_dix1x, st->s_rx1y,
                         st->s_dix1y, st->s_rx1z, st->s_dix1z);
  pushJ_path_fill(pushJ_path_x01(bank),
                  pushJ_wt_x_c(bank, 1, PUSHJ_WT_IF1),
                  pushJ_wt_x_c(bank, 0, PUSHJ_WT_IF1));
  pushJ_path_fill(pushJ_path_y01(bank),
                  pushJ_wt_y_c(bank, 1, PUSHJ_WT_IF1),
                  pushJ_wt_y_c(bank, 0, PUSHJ_WT_IF1));
}
/* -------------------------------------------------------------------------- */
/* K2 push split helpers (Step C) */
/* -------------------------------------------------------------------------- */

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_x2(pushJ_vlo_state_t *st, v8fp64 x0, v8fp64 x1,
                     v8fp64 allincfvx, const pushJ_ctx_t *ctx) {
  const v8fp64 drift = (2.00000000000000000e+00 * x1) - x0;
  st->x2 = drift + (ctx->X_PUSH_SCALE * allincfvx);

  /* Evaluate floor once and reuse the identical value for rx/dix. */
  const v8fp64 x2_rel = (st->x2 - ctx->XO);
  const v8fp64 x2_floor = geo_floor_simd(x2_rel);
  st->s_rx2x = (x2_rel - x2_floor);
  st->s_dix2x = (x2_floor - ctx->Midx);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_y2(pushJ_vlo_state_t *st, v8fp64 x0, v8fp64 y0, v8fp64 y1,
                     v8fp64 iBy, v8fp64 allincfvy, const pushJ_ctx_t *ctx) {
  const double TX0 = ctx->Tori_X0;
  const double cy_scale = ctx->Y_FORCE_SCALE;

  /* Stage-2 algebraic simplification:
   *
   *   G  = 1 / (TX0 + x2)^2
   *   Cy = (q/m) * dt * TX0^2 / DELTA_Y^2 * G
   *   y2 = y1 + (TX0 + x0)^2 * G * (y1 - y0)
   *             + Cy * (allincfvy - iBy)
   *
   * allincfvy is already 2*dt*Ey.  Store Cy in st->vy0: the original vy0 is
   * dead after K1 has reconstructed xy0, so this reuses existing __mem4__
   * storage instead of extending pushJ_vlo_state_t. */
  const v8fp64 tx0_plus_x0 = (TX0 + x0);
  const v8fp64 tx0_plus_x2 = (TX0 + st->x2);
  const v8fp64 metric_x0 = (tx0_plus_x0 * tx0_plus_x0);
  const v8fp64 metric_x2 = (tx0_plus_x2 * tx0_plus_x2);
  const v8fp64 G = (1.00000000000000000e+00 / metric_x2);
  st->vy0 = (cy_scale * G);

  const v8fp64 advect =
      y1 + ((metric_x0 * G) * (y1 - y0));
  const v8fp64 force = st->vy0 * (allincfvy - iBy);
  st->y2 = advect + force;

  const v8fp64 y2_rel = (st->y2 - ctx->YO);
  const v8fp64 y2_floor = geo_floor_simd(y2_rel);
  st->s_rx2y = (y2_rel - y2_floor);
  st->s_dix2y = (y2_floor - ctx->Midy);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_z2_z3(pushJ_vlo_state_t *st, v8fp64 z0, v8fp64 z1, v8fp64 iBz,
                        v8fp64 allincfvz, const pushJ_ctx_t *ctx) {
  const v8fp64 drift_z2 = (2.00000000000000000e+00 * z1) - z0;
  st->z2 = drift_z2 + (ctx->Z_PUSH_SCALE * (allincfvz - iBz));

  const v8fp64 z2_rel = (st->z2 - (ctx->ZO - ctx->zmid));
  const v8fp64 z2_floor = geo_floor_simd(z2_rel);
  st->s_rx2z = (z2_rel - z2_floor);
  st->s_dix2z = (z2_floor - ctx->Midz);

  /* Theory Eq. (63): the second-stage z subflow has no field term.  This is
   * structural and remains valid when fieldB/fieldB1 contain external B. */
  st->z3 = (2.00000000000000000e+00 * st->z2) - z1;

  const v8fp64 z3_rel = (st->z3 - (ctx->ZO - ctx->zmid));
  const v8fp64 z3_floor = geo_floor_simd(z3_rel);
  st->s_rx3z = (z3_rel - z3_floor);
  st->s_dix3z = (z3_floor - ctx->Midz);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_y3(pushJ_vlo_state_t *st, v8fp64 y1, v8fp64 iBy,
                     const pushJ_ctx_t *ctx) {
  /* Reuse the Cy produced by pushJ_vlo_K2_push_y2.  No reciprocal or metric
   * reconstruction is needed in the y3 stage. */
  st->y3 =
      ((2.00000000000000000e+00 * st->y2) - y1) - (st->vy0 * iBy);

  const v8fp64 y3_rel = (st->y3 - ctx->YO);
  const v8fp64 y3_floor = geo_floor_simd(y3_rel);
  st->s_rx3y = (y3_rel - y3_floor);
  st->s_dix3y = (y3_floor - ctx->Midy);
}

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_x3(pushJ_vlo_state_t *st, v8fp64 x1, v8fp64 y1, v8fp64 iBx,
                     const pushJ_ctx_t *ctx) {
  const double TX0 = ctx->Tori_X0;

  /*
   * y1^2 - 2*y1*y2 + 2*y2^2 - 2*y2*y3 + y3^2
   *   = (y1 - y2)^2 + (y2 - y3)^2
   */
  const v8fp64 dy12 = (y1 - st->y2);
  const v8fp64 dy23 = (st->y2 - st->y3);
  const v8fp64 y_geometry = (dy12 * dy12) + (dy23 * dy23);
  const v8fp64 drift = (2.00000000000000000e+00 * st->x2) - x1;
  const v8fp64 geometry =
      ctx->X_GEOMETRY_SCALE * ((TX0 + st->x2) * y_geometry);
  st->x3 = (drift + geometry) - (ctx->X_PUSH_SCALE * iBx);

  const v8fp64 x3_rel = (st->x3 - ctx->XO);
  const v8fp64 x3_floor = geo_floor_simd(x3_rel);
  st->s_rx3x = (x3_rel - x3_floor);
  st->s_dix3x = (x3_floor - ctx->Midx);
}

/* -------------------------------------------------------------------------- */
/* K2 B-integral combination wrappers (Step F: split K2 call chain) */
/* Each returns one corrected B integral; math/order preserved bit-exact. */
/* -------------------------------------------------------------------------- */

static __device__ KERNEL_M __noinline__ v8fp64 pushJ_vlo_K2_compute_iBy(
    const pushJ_weight_bank_t *bank, const double *shB0,
    const double *shB1, int tile_xlen) {
  v8fp64 iBy_term0, iBy_term1;
  pushJ_B_fused_iBy_bank(bank, shB0, shB1, tile_xlen, &iBy_term0,
                         &iBy_term1);
  return (iBy_term0 + iBy_term1);
}

static __device__ KERNEL_M __noinline__ v8fp64 pushJ_vlo_K2_compute_iBz(
    const pushJ_weight_bank_t *bank, const double *shB0,
    const double *shB1, int tile_xlen) {
  v8fp64 iBz_term1, iBz_term2, iBz_term3, iBz_term4;
  pushJ_B_fused_iBz_pair_bank(
      bank, shB0, 0, pushJ_path_y01_c(bank), pushJ_path_x01_c(bank),
      tile_xlen,
      &iBz_term1, &iBz_term2);
  pushJ_B_fused_iBz_pair_bank(
      bank, shB1, 2, pushJ_path_y12_c(bank), pushJ_path_x12_c(bank),
      tile_xlen,
      &iBz_term3, &iBz_term4);
  return ((iBz_term1 - iBz_term2) + (iBz_term3 - iBz_term4));
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_vlo_K2_compute_iBy23(const pushJ_weight_bank_t *bank,
                           const double *shB1, int tile_xlen) {
  v8fp64 t0, t1;
  pushJ_B_fused_iBy23_bank(bank, shB1, tile_xlen, &t0, &t1);
  return (-1.00000000000000000e+00 * (t0 + t1));
}

static __device__ KERNEL_M __noinline__ v8fp64
pushJ_vlo_K2_compute_iBx(const pushJ_weight_bank_t *bank,
                         const double *shB1, int tile_xlen) {
  v8fp64 z12, z23, y12, y23;
  pushJ_B_fused_iBx_bank(bank, shB1, tile_xlen, &z12, &z23, &y12, &y23);
  return ((z12 + z23) - (y12 + y23));
}

/* -------------------------------------------------------------------------- */
/* K2 Verlet stage splits (Step G/H): shorten live range per stage callee */
/* -------------------------------------------------------------------------- */

static __device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_stage1a_E(const pushJ_weight_bank_t *bank,
                       const double *shE0, const pushJ_ctx_t *ctx,
                       int tile_xlen,
                       v8fp64 *allincfvx_out,
                       v8fp64 *allincfvy_out, v8fp64 *allincfvz_out) {
  const v8fp64 AllEx = pushJ_E_interp_Ex_bank(bank, shE0, tile_xlen);
  const v8fp64 AllEy = pushJ_E_interp_Ey_bank(bank, shE0, tile_xlen);
  const v8fp64 AllEz = pushJ_E_interp_Ez_bank(bank, shE0, tile_xlen);
  *allincfvx_out = (ctx->TWO_DELTAT * AllEx);
  *allincfvy_out = (ctx->TWO_DELTAT * AllEy);
  *allincfvz_out = (ctx->TWO_DELTAT * AllEz);
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_vlo_K2_stage1b_x2y2(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                          const double *shB0, const double *shB1, v8fp64 x0,
                          v8fp64 x1, v8fp64 y0, v8fp64 y1, v8fp64 allincfvx,
                          v8fp64 allincfvy, const pushJ_ctx_t *ctx,
                          int tile_xlen) {
  pushJ_vlo_K2_push_x2(st, x0, x1, allincfvx, ctx);
  pushJ_wt_fill_pos2_x(bank, st->s_rx2x, st->s_dix2x);
  pushJ_path_fill(pushJ_path_x12(bank),
                  pushJ_wt_x_c(bank, 2, PUSHJ_WT_IF1),
                  pushJ_wt_x_c(bank, 1, PUSHJ_WT_IF1));

  const v8fp64 iBy = pushJ_vlo_K2_compute_iBy(bank, shB0, shB1, tile_xlen);

  pushJ_vlo_K2_push_y2(st, x0, y0, y1, iBy, allincfvy, ctx);
  pushJ_wt_fill_pos2_y(bank, st->s_rx2y, st->s_dix2y);
  pushJ_path_fill(pushJ_path_y12(bank),
                  pushJ_wt_y_c(bank, 2, PUSHJ_WT_IF1),
                  pushJ_wt_y_c(bank, 1, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_vlo_K2_stage2_z2z3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                         const double *shB0, const double *shB1, v8fp64 z0,
                         v8fp64 z1, v8fp64 allincfvz, const pushJ_ctx_t *ctx,
                         int tile_xlen) {
  const v8fp64 iBz = pushJ_vlo_K2_compute_iBz(bank, shB0, shB1, tile_xlen);

  pushJ_vlo_K2_push_z2_z3(st, z0, z1, iBz, allincfvz, ctx);
  pushJ_wt_fill_pos2_z_if1(bank, st->s_rx2z, st->s_dix2z);
  pushJ_wt_fill_pos3_z_f0_if1(bank, st->s_rx3z, st->s_dix3z);
  pushJ_path_fill(pushJ_path_z12(bank),
                  pushJ_wt_z_c(bank, 2, PUSHJ_WT_IF1),
                  pushJ_wt_z_c(bank, 1, PUSHJ_WT_IF1));
  pushJ_path_fill(pushJ_path_z23(bank),
                  pushJ_wt_z_c(bank, 3, PUSHJ_WT_IF1),
                  pushJ_wt_z_c(bank, 2, PUSHJ_WT_IF1));
  pushJ_path_fill(pushJ_path_z13(bank),
                  pushJ_wt_z_c(bank, 3, PUSHJ_WT_IF1),
                  pushJ_wt_z_c(bank, 1, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_vlo_K2_stage3a_y3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                        const double *shB1, v8fp64 y1, const pushJ_ctx_t *ctx,
                        int tile_xlen) {
  const v8fp64 iBy23 = pushJ_vlo_K2_compute_iBy23(bank, shB1, tile_xlen);

  pushJ_vlo_K2_push_y3(st, y1, iBy23, ctx);
  pushJ_wt_fill_pos3_y_f0_if1(bank, st->s_rx3y, st->s_dix3y);
  pushJ_path_fill(pushJ_path_y23(bank),
                  pushJ_wt_y_c(bank, 3, PUSHJ_WT_IF1),
                  pushJ_wt_y_c(bank, 2, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_vlo_K2_stage3b_x3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                        const double *shB1, v8fp64 x1, v8fp64 y1,
                        const pushJ_ctx_t *ctx, int tile_xlen) {
  const v8fp64 iBx = pushJ_vlo_K2_compute_iBx(bank, shB1, tile_xlen);

  pushJ_vlo_K2_push_x3(st, x1, y1, iBx, ctx);
  pushJ_wt_fill_pos3_x_if1(bank, st->s_rx3x, st->s_dix3x);
  pushJ_path_fill(pushJ_path_x23(bank),
                  pushJ_wt_x_c(bank, 3, PUSHJ_WT_IF1),
                  pushJ_wt_x_c(bank, 2, PUSHJ_WT_IF1));
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_vlo_K2_stage1_E_x2y2(
    pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st, const double *shE0,
    const double *shB0, const double *shB1, v8fp64 x0, v8fp64 x1, v8fp64 y0,
    v8fp64 y1, const pushJ_ctx_t *ctx, int tile_xlen,
    v8fp64 *allincfvz_out) {
  v8fp64 allincfvx, allincfvy;
  pushJ_vlo_K2_stage1a_E(bank, shE0, ctx, tile_xlen,
                         &allincfvx, &allincfvy,
                         allincfvz_out);
  pushJ_vlo_K2_stage1b_x2y2(bank, st, shB0, shB1, x0, x1, y0, y1, allincfvx,
                            allincfvy, ctx, tile_xlen);
}

static __device__ KERNEL_M __attribute__((always_inline)) inline void
pushJ_vlo_K2_stage3_y3x3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                         const double *shB1, v8fp64 x1, v8fp64 y1,
                         const pushJ_ctx_t *ctx, int tile_xlen) {
  pushJ_vlo_K2_stage3a_y3(bank, st, shB1, y1, ctx, tile_xlen);
  pushJ_vlo_K2_stage3b_x3(bank, st, shB1, x1, y1, ctx, tile_xlen);
}

/* SPU-visible MPU entry: keep external linkage (no static). */
__device__ KERNEL_M __noinline__ void
pushJ_vlo_K2_push_weights_x2x3(pushJ_weight_bank_t *bank, pushJ_vlo_state_t *st,
                               const double *shE0, const double *shB0,
                               const double *shB1, const pushJ_ctx_t *ctx,
                               int tile_xlen) {
  const v8fp64 x0 = (st->xx0 + (ctx->XO));
  const v8fp64 y0 = (st->xy0 + (ctx->YO));
  const v8fp64 z0 = (st->xz0 + (ctx->ZO - ctx->zmid));
  const v8fp64 x1 = (st->xx1 + (ctx->XO));
  const v8fp64 y1 = (st->xy1 + (ctx->YO));
  const v8fp64 z1 = (st->xz1 + (ctx->ZO - ctx->zmid));

  v8fp64 allincfvz;
  pushJ_vlo_K2_stage1_E_x2y2(bank, st, shE0, shB0, shB1, x0, x1, y0, y1, ctx,
                             tile_xlen, &allincfvz);
  pushJ_vlo_K2_stage2_z2z3(bank, st, shB0, shB1, z0, z1, allincfvz, ctx,
                           tile_xlen);
  pushJ_vlo_K2_stage3_y3x3(bank, st, shB1, x1, y1, ctx, tile_xlen);
}

/* SPU-visible MPU entry: keep external linkage (no static). */
__device__ KERNEL_M __noinline__ void pushJ_vlo_K3_deposit_writeback_particle(
    const pushJ_weight_bank_t *__restrict__ bank, pushJ_vlo_state_t *st,
    const pushJ_ctx_t *ctx, v8fp64 *__restrict__ shJ_incf,
    double *particle_dm /* DM staging, not DDR */, int g_inner, long load0) {
  const int full_batch = ((g_inner + 8) <= load0);
  pushJ_vlo_deposit_Jx(bank, st, ctx, shJ_incf, full_batch);
  pushJ_vlo_deposit_JyJz(bank, st, ctx, shJ_incf, full_batch);

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
  if (full_batch) {
    /* opt_stage51-2 full batch: fixed six-field scatter, no bounds check and
     * no six-way field branch. */
#pragma clang loop unroll(full)
    for (int lane = 0; lane < 8; lane++) {
      const int poff = (g_inner + lane) * 6;
      particle_dm[poff + 0] = newxx_l[lane];
      particle_dm[poff + 1] = newxy_l[lane];
      particle_dm[poff + 2] = newxz_l[lane];
      particle_dm[poff + 3] = newvx_l[lane];
      particle_dm[poff + 4] = newvy_l[lane];
      particle_dm[poff + 5] = newvz_l[lane];
    }
  } else {
    long stmpg1;
    for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
#pragma clang loop unroll(full)
      for (int lane = 0; lane < 8; lane++) {
        const int cid = g_inner + lane;
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
pushJ_vlo_zero_shJ_incf(v8fp64 *__restrict__ shJ_incf) {
  double *shJ_incf_l = (double *)shJ_incf;
  for (int k = 0; k < 375 * 8; k++) {
    shJ_incf_l[k] = 0.0;
  }
}

/* Collapse the eight SIMD lanes of the one logical J accumulator. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_collapse_shJ_incf_to_shJ0(double *shJ0,
                                    const v8fp64 *shJ_incf) {
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

/* Reduce the N thread-private SIMD accumulators into the shared scalar J tile.
 * Threads process contiguous batch ranges and are reduced in thread order,
 * which keeps the floating-point order closer to the serial SIMD8 path than
 * the former round-robin batch assignment. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_reduce_privJ_to_shJ0(
    double *shJ0, const v8fp64 (*shJ_incf_priv)[375]) {
  for (int k = 0; k < 375; ++k) {
    double sum = 0.0;
#pragma unroll
    for (int simd_lane = 0; simd_lane < 8; ++simd_lane) {
#pragma unroll
      for (int thread = 0; thread < PUSHJ_VLO_REAL_PARALLEL_N; ++thread) {
        const double *simd_values =
            (const double *)&shJ_incf_priv[thread][k];
        sum += simd_values[simd_lane];
      }
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

  /* OPT-2 store: issue all memcpy_async first; one barrier at end
   * (FoutJ targets disjoint by (xyzy,xyzz); no RAW dependency). */
  for (int line = (int)__idx; line < 25; line += (int)__xlen) {
    const int xyzy = line % 5;
    const int xyzz = line / 5;
    const int total_idx = 3 * 5 * line;
    const MAPU_LONG ddr_off = pushJ_vlo_field_ddr_elem_offset(
        __idy, bBidx, bBidy, bBidz, xyzy, xyzz, XLEN, YLEN, ZLEN, ovlp,
        num_ele);

    memcpy_async(block, (__DDR unsigned *)(FoutJ + ddr_off),
                 (unsigned *)(shJ0 + total_idx), (uint64_t)tile_bytes, bar);
  }
  bar.arrive_and_wait();
}

/* Process one tile's particle batches on N threads.  Each thread receives one
 * contiguous batch range (rather than every Nth batch), so the private-J
 * reduction follows the original batch order as closely as possible.
 *
 * All threads execute the same number of barrier phases.  A thread with no
 * batch in the current wave submits no DMA but still arrives at the barrier. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_process_particle_batches_multi(
    pushJ_wt_axis_bank_t *bank_x, pushJ_wt_axis_bank_t *bank_y,
    pushJ_wt_axis_bank_t *bank_z, pushJ_vlo_state_t *st,
    v8fp64 (*shJ_incf_priv)[375], pushJ_ctx_t *ctx,
    double *shE0, double *shB0, double *shB1, int tile_xlen, double *shJ0,
    double *shParticle, __DDR double *particle_buf, int load0,
    MAPU_LONG __idx, MAPU_LONG __xlen,
    cooperative_groups::thread_block block,
    scale::barrier<scale::thread_scope_block> &bar) {
  (void)__xlen;
  pushJ_weight_bank_t bank;
  pushJ_wt_bank_bind(&bank, bank_x, bank_y, bank_z);
  pushJ_vlo_zero_shJ_incf(shJ_incf_priv[__idx]);
  __syncthreads();

  const int num_batches = (load0 + 7) / 8;
  const int batches_per_thread =
      num_batches / PUSHJ_VLO_REAL_PARALLEL_N;
  const int batch_remainder =
      num_batches % PUSHJ_VLO_REAL_PARALLEL_N;
  const int thread = (int)__idx;
  const int prefix_extra =
      (thread < batch_remainder) ? thread : batch_remainder;
  const int first_batch = thread * batches_per_thread + prefix_extra;
  const int local_batches =
      batches_per_thread + ((thread < batch_remainder) ? 1 : 0);
  const int max_waves = batches_per_thread + (batch_remainder != 0);
  double *const particle_dm = shParticle + thread * 48;

  for (int wave = 0; wave < max_waves; ++wave) {
    const bool active = wave < local_batches;
    const int batch = first_batch + wave;
    const int g_inner = active ? (batch * 8) : 0;
    int numcp = active ? 8 : 0;
    if (active && ((g_inner + numcp) > load0)) {
      numcp = load0 - g_inner;
    }
    const size_t particle_bytes = (size_t)numcp * 6u * sizeof(double);

    if (active) {
      memcpy_async(block, (unsigned *)particle_dm,
                   (__DDR unsigned *)(particle_buf + (g_inner * 6)),
                   (uint64_t)particle_bytes, bar);
    }
    bar.arrive_and_wait();

    if (active) {
      pushJ_vlo_K1_setup_weights_x0x1(&bank, st, particle_dm, 0, numcp, ctx);
      MPU_SYNC();
      pushJ_vlo_K2_push_weights_x2x3(
          &bank, st, shE0, shB0, shB1, ctx, tile_xlen);
      MPU_SYNC();
      pushJ_vlo_K3_deposit_writeback_particle(
          &bank, st, ctx, shJ_incf_priv[__idx], particle_dm, 0, numcp);
      MPU_SYNC();
    }

    if (active) {
      memcpy_async(block, (__DDR unsigned *)(particle_buf + (g_inner * 6)),
                   (unsigned *)particle_dm, (uint64_t)particle_bytes, bar);
    }
    bar.arrive_and_wait();
  }

  if (__idx == 0) {
    pushJ_vlo_reduce_privJ_to_shJ0(shJ0, shJ_incf_priv);
  }
  __syncthreads();
}

/* Process one cell using an already resident stride-8 E/B/B1 window.  J is a
 * normal contiguous stride-5 tile loaded and stored by the caller. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_process_loaded_fields_x8_cell_multi(
    pushJ_wt_axis_bank_t *bank_x, pushJ_wt_axis_bank_t *bank_y,
    pushJ_wt_axis_bank_t *bank_z, pushJ_vlo_state_t *st,
    v8fp64 (*shJ_incf_priv)[375], pushJ_ctx_t *ctx,
    double *shE0, double *shB0, double *shB1, double *shJ0,
    double *shParticle, __DDR double *particle_buf, int load0, int cell_x,
    MAPU_LONG __idx, MAPU_LONG __xlen,
    cooperative_groups::thread_block block,
    scale::barrier<scale::thread_scope_block> &bar) {
  pushJ_vlo_process_particle_batches_multi(
      bank_x, bank_y, bank_z, st, shJ_incf_priv, ctx,
      shE0 + 3 * cell_x, shB0 + 3 * cell_x, shB1 + 3 * cell_x, 8, shJ0,
      shParticle, particle_buf, load0, __idx, __xlen, block, bar);
}

/* Standard stride-5 field/J tile path with true particle-batch parallelism. */
static __device__ __attribute__((always_inline)) inline void
pushJ_vlo_process_tile_multi(
    pushJ_wt_axis_bank_t *bank_x, pushJ_wt_axis_bank_t *bank_y,
    pushJ_wt_axis_bank_t *bank_z, pushJ_vlo_state_t *st,
    v8fp64 (*shJ_incf_priv)[375], pushJ_ctx_t *ctx,
    double *shE0, double *shB0, double *shB1, double *shJ0,
    double *shParticle, __DDR double *particle_buf, int load0,
    double Midx, double Midy, double Midz, double Deltat,
    int bBidx, int bBidy, int bBidz,
    __DDR double *fieldE, __DDR double *fieldB, __DDR double *fieldB1,
    __DDR double *FoutJ, MAPU_LONG __idy, MAPU_LONG __idx, MAPU_LONG __xlen,
    MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, int num_ele,
    cooperative_groups::thread_block block,
    scale::barrier<scale::thread_scope_block> &bar) {
  (void)Midx;
  (void)Midy;
  (void)Midz;
  (void)Deltat;
  pushJ_vlo_K1_load_shared_5x5x5(
      shE0, shB0, shB1, shJ0, fieldE, fieldB, fieldB1, FoutJ, __idy, __idx,
      __xlen, bBidx, bBidy, bBidz, XLEN, YLEN, ZLEN, ovlp, num_ele, block,
      bar);

  pushJ_vlo_process_particle_batches_multi(
      bank_x, bank_y, bank_z, st, shJ_incf_priv, ctx,
      shE0, shB0, shB1, 5, shJ0, shParticle, particle_buf, load0,
      __idx, __xlen, block, bar);

  pushJ_vlo_K3_write_FoutJ_from_shared(shJ0, FoutJ, __idy, __idx, __xlen, bBidx,
                                       bBidy, bBidz, XLEN, YLEN, ZLEN, ovlp,
                                       num_ele, block, bar);
}

/*
 * SCALE-native pushJ multi (opt_stage55 arithmetic + N-thread particle-batch
 * parallelism + accuracy-preserving x4 reuse of read-only E/B/B1 fields).
 *
 * Public argument ABI matches scale-gptv2-work / generated runtime
 * (mapu_geo_nr_Bfield_pushJ_vlo). Unused ABI slots fieldE_ext / use_g_e
 * are retained as (void) stubs for host linkage compatibility.
 *
 * Default launch is <<<numvec,4>>>.  Every thread owns a contiguous range of
 * SIMD8 particle batches, a private particle staging slice, and a private J
 * accumulator.  Thread 0 reduces private J only after all batch waves finish.
 *
 * DM layout (block-shared = single physical DM; private = per-APE):
 *   __shared__ __fix5__: fields, J, N particle batches, ctx, barrier,
 *                        N SIMD8 J accumulators
 *   __mem1__ __fix1__:     x-axis weight bank
 *   __mem2__ __fix2__:     y-axis weight bank
 *   __mem3__ __fix3__:     z-axis weight bank
 *   __mem4__ __fix4__:     pushJ_vlo_state_t
 */
__global__ void mapu_geo_nr_Bfield_pushJ_vlo(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR int *xoffset, __DDR int *yoffset,
    __DDR int *zoffset, __DDR double *fieldE,
    __DDR double *fieldE_ext, __DDR double *fieldB,
    __DDR double *fieldB1, __DDR double *FoutJ, MAPU_LONG XLEN, MAPU_LONG YLEN,
    MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec, int num_ele,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length, int use_g_e,
    double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0,
    double zmid) {

  /* Keep the generated runtime ABI even though these arguments are unused. */
  (void)fieldE_ext;
  (void)use_g_e;
  (void)r0;
  (void)MIN_R0;
  (void)Q0;
  (void)b0;

  const MAPU_LONG __physical_idx =
      threadIdx.x + blockDim.x * (threadIdx.y + blockDim.y * threadIdx.z);

  const MAPU_LONG __idy =
      blockIdx.x + gridDim.x * (blockIdx.y + gridDim.y * blockIdx.z);

  const MAPU_LONG __block_threads =
      blockDim.x * blockDim.y * blockDim.z;
  const MAPU_LONG __idx = __physical_idx;
  const MAPU_LONG __xlen = __block_threads;

  /* Both predicates are block-uniform, so returning before barrier init is
   * safe.  The __idy guard also handles the runtime's padded 2-D grid when
   * numvec exceeds the x-dimension launch limit. */
  if ((__xlen != PUSHJ_VLO_REAL_PARALLEL_N) || (__idy >= numvec)) {
    if ((__idy == 0) && (__idx == 0) &&
        (__xlen != PUSHJ_VLO_REAL_PARALLEL_N)) {
      printf("multi launch mismatch: block_threads=%lld compile_N=%d\n",
             (long long)__xlen, PUSHJ_VLO_REAL_PARALLEL_N);
    }
    return;
  }

  /* Per-APE SPU cycle counter (device-only). Start after local ids exist. */
  // spu counter
  // __aurora_s_fenceI();
  // __aurora_s_startCounter(f_Clear);

  MAPU_LONG numgrid = (XLEN * (YLEN * ZLEN));

  MAPU_LONG grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  /* Block-shared cohort.  Field/J tiles are shared; particle staging and
   * vector J accumulation are disjoint by thread. */
  __shared__ __fix5__ double shE0[600];
  __shared__ __fix5__ double shB0[600];
  __shared__ __fix5__ double shB1[600];
  __shared__ __fix5__ double shJ0[375];
  __shared__ __fix5__
      v8fp64 shJ_incf_priv[PUSHJ_VLO_REAL_PARALLEL_N][375];
  __shared__ __fix5__
      double shParticle[PUSHJ_VLO_REAL_PARALLEL_N * 48];
  __shared__ __fix5__ pushJ_ctx_t pushJ_ctx;

  /* Private per-thread/per-APE cohorts — no shared array is required. */
  __mem1__ __fix1__ pushJ_wt_axis_bank_t pushJ_bank_x;
  __mem2__ __fix2__ pushJ_wt_axis_bank_t pushJ_bank_y;
  __mem3__ __fix3__ pushJ_wt_axis_bank_t pushJ_bank_z;
  __mem4__ __fix4__ pushJ_vlo_state_t pushJ_st;

  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ __fix5__ barrier_t bar;
  if (__idx == 0) {
    init(&bar, __block_threads);
    pushJ_vlo_ctx_init_const(&pushJ_ctx, DELTA_X, DELTA_Y, DELTA_Z, Deltat,
                             Tori_X0, Charge0, Mass0);
  }
  __syncthreads();
  auto block = cooperative_groups::this_thread_block();
  {
    MAPU_LONG l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      const int load0 = 1;

      (use_local_particle_position = 1);
      if (load0) {
        const double XO = (xoffset)[__idy];
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

        if (__idx == 0) {
          pushJ_vlo_ctx_init_tile(&pushJ_ctx, XO, YO, ZO, zmid, Midx, Midy,
                                  Midz, bBidx, bBidy, bBidz);
        }
        __syncthreads();
        pushJ_vlo_process_tile_multi(
            &pushJ_bank_x, &pushJ_bank_y, &pushJ_bank_z, &pushJ_st,
            shJ_incf_priv, &pushJ_ctx, shE0, shB0, shB1, shJ0, shParticle,
            particle_base,
            load0, Midx, Midy, Midz, Deltat, bBidx, bBidy, bBidz, fieldE,
            fieldB, fieldB1, FoutJ, __idy, __idx, __xlen, XLEN, YLEN, ZLEN,
            ovlp, num_ele, block, bar);
      }
    }
  }
  {
    /* Dense allgid loop (legacy active-gid compaction omitted on SCALE —
     * see package README / aiKnowledge/projects/wiki/07_DECISIONS.md). */
    MAPU_LONG allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      const int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];
      const MAPU_LONG c_gid = allgid;

      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      const int load0 = new_load_tmp;

      /* Accuracy-first supertile: reuse only immutable field inputs.  Each
       * cell reloads and immediately stores its own J tile, exactly matching
       * the stage52 read/modify/write ordering for overlapping stencils. */
      if (load0 && num_ele == 3 && (mdx + 3) < XLEN) {
        const int load1 = (xyzw)[4 * ((__idy * numgrid) + allgid + 1)];
        const int load2 = (xyzw)[4 * ((__idy * numgrid) + allgid + 2)];
        const int load3 = (xyzw)[4 * ((__idy * numgrid) + allgid + 3)];
        if (load1 && load2 && load3) {
          const double XO = (xoffset)[__idy];
          const double YO = (yoffset)[__idy];
          const double ZO = (zoffset)[__idy];
          const int base_bx = mdx - 2;
          const int base_by = mdy - 2;
          const int base_bz = mdz - 2;

          pushJ_vlo_K1_load_fields_shared_8x5x5(
              shE0, shB0, shB1, fieldE, fieldB, fieldB1, __idy,
              __idx, __xlen, base_bx, base_by, base_bz, XLEN, YLEN, ZLEN,
              ovlp, num_ele, block, bar);

          const int loads[4] = {load0, load1, load2, load3};
          for (int cell = 0; cell < 4; ++cell) {
            const double Midx = (double)(mdx + cell);
            const double Midy = (double)mdy;
            const double Midz = (double)mdz;
            const int bBidx = (int)Midx - 2;
            const int bBidy = (int)Midy - 2;
            const int bBidz = (int)Midz - 2;
            __DDR double *const particle_base =
                inoutput + grid_base_offset +
                6 * ((allgid + cell) * grid_cache_len);

            pushJ_vlo_K1_load_J_shared_5x5x5(
                shJ0, FoutJ, __idy, __idx, __xlen, bBidx, bBidy, bBidz,
                XLEN, YLEN, ZLEN, ovlp, num_ele, block, bar);

            if (__idx == 0) {
              pushJ_vlo_ctx_init_tile(&pushJ_ctx, XO, YO, ZO, zmid, Midx,
                                      Midy, Midz, bBidx, bBidy, bBidz);
            }
            __syncthreads();

            pushJ_vlo_process_loaded_fields_x8_cell_multi(
                &pushJ_bank_x, &pushJ_bank_y, &pushJ_bank_z, &pushJ_st,
                shJ_incf_priv, &pushJ_ctx, shE0, shB0, shB1, shJ0,
                shParticle, particle_base, loads[cell], cell,
                __idx, __xlen, block, bar);

            pushJ_vlo_K3_write_FoutJ_from_shared(
                shJ0, FoutJ, __idy, __idx, __xlen,
                bBidx, bBidy, bBidz, XLEN, YLEN, ZLEN, ovlp, num_ele,
                block, bar);
          }
          allgid += 3;
          continue;
        }
      }

      if (load0) {
        const double XO = (xoffset)[__idy];
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

        if (__idx == 0) {
          pushJ_vlo_ctx_init_tile(&pushJ_ctx, XO, YO, ZO, zmid, Midx, Midy,
                                  Midz, bBidx, bBidy, bBidz);
        }
        __syncthreads();
        pushJ_vlo_process_tile_multi(
            &pushJ_bank_x, &pushJ_bank_y, &pushJ_bank_z, &pushJ_st,
            shJ_incf_priv, &pushJ_ctx, shE0, shB0, shB1, shJ0, shParticle,
            particle_base,
            load0, Midx, Midy, Midz, Deltat, bBidx, bBidy, bBidz, fieldE,
            fieldB, fieldB1, FoutJ, __idy, __idx, __xlen, XLEN, YLEN, ZLEN,
            ovlp, num_ele, block, bar);
      }
    }
  }

  // spu counter
  // __aurora_s_stopCounter();
  // /* Report every physical worker so thread-level load balance is visible. */
  // {
  //   const int c = __aurora_s_readCounter(f_NoFlag);
  //   printf("spu counter: block=%lld thread=%lld counter=%d\n", (long long)__idy,
  //          (long long)__idx, c);
  // }
}



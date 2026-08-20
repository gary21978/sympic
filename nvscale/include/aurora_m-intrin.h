/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE header.
 * It maps a subset of SCALE/MAPS/Aurora APIs to NVIDIA CUDA for local
 * compilation and functional bring-up.
 */
#pragma once

#include "scale.h"

enum {
  mf_MASK = 0,
  mf_M0 = 0,
  mf_M1 = 1,
  mf_M2 = 2,
  mf_M3 = 3,
  mf_WB = 1,
  fu_BIU0 = 0,
  fu_BIU1 = 1,
  fu_BIU2 = 2,
  fu_BIU3 = 3
};

__device__ static inline v16s32 aurora_m_load_restrict_postinc(v16u32 cfg,
                                                               int, int, int,
                                                               int, int) {
  uintptr_t addr = (uintptr_t)cfg.lane[0];
  v16s32 r = {};
  if (addr) {
    const int *p = (const int *)addr;
#pragma unroll
    for (int i = 0; i < 16; ++i) r.lane[i] = p[i];
  }
  return r;
}

__device__ static inline void aurora_m_store_postinc(v16s32 value, v16u32 cfg,
                                                     int, int, int, int, int) {
  uintptr_t addr = (uintptr_t)cfg.lane[0];
  if (addr) {
    int *p = (int *)addr;
#pragma unroll
    for (int i = 0; i < 16; ++i) p[i] = value.lane[i];
  }
}

__device__ static inline v8fp64 __aurora_m_reduceAdd16Vec_v8fp64(v8fp64 value,
                                                                 int, int, int,
                                                                 int) {
  double sum = 0.0;
#pragma unroll
  for (int i = 0; i < 8; ++i) sum += value.lane[i];
  return scale_make_v8fp64(sum);
}

__device__ static inline v16s32 __aurora_m_reduceAdd16Vec_v16s32(v16s32 value,
                                                                 int, int, int,
                                                                 int) {
  int sum = 0;
#pragma unroll
  for (int i = 0; i < 16; ++i) sum += value.lane[i];
  v16s32 r = {};
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = sum;
  return r;
}

__device__ static inline v8fp64 __aurora_m_compSel2_v8fp64(v8fp64 a, v8fp64 b,
                                                           v8fp64 c, v8fp64 d,
                                                           int) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) r.lane[i] = (b.lane[i] < a.lane[i]) ? c.lane[i] : d.lane[i];
  return r;
}

__device__ static inline v16s32 __aurora_m_compSel2_v16s32(v16s32 a, v16s32 b,
                                                           v16s32 c, v16s32 d,
                                                           int) {
  v16s32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = (b.lane[i] < a.lane[i]) ? c.lane[i] : d.lane[i];
  return r;
}

__device__ static inline v16s32 __aurora_m_indexShort(v8fp64 a, v8fp64,
                                                      v16u32, int) {
  return (v16s32)a;
}

__device__ static inline void __aurora_m_setSM1(int) {}

#define profile_print_char(a) do { (void)(a); } while (0)
#define profile_print_unsigned_char(a) do { (void)(a); } while (0)
#define profile_print_short(a) do { (void)(a); } while (0)
#define profile_print_unsigned_short(a) do { (void)(a); } while (0)
#define profile_print_int(a) do { (void)(a); } while (0)
#define profile_print_unsigned_int(a) do { (void)(a); } while (0)
#define profile_print_float(a) do { (void)(a); } while (0)
#define profile_print_double(a) do { (void)(a); } while (0)
#define profile_print_v8fp64(a) do { (void)(a); } while (0)
#define profile_print_v16fp32(a) do { (void)(a); } while (0)
#define profile_print_v16s32(a) do { (void)(a); } while (0)
#define mpu_printf_int(a) do { (void)(a); } while (0)
#define mpu_printf_double(a) do { (void)(a); } while (0)
#define mpu_printf_v8fp64(a) do { (void)(a); } while (0)

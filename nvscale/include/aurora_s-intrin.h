/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE header.
 * It maps a subset of SCALE/MAPS/Aurora APIs to NVIDIA CUDA for local
 * compilation and functional bring-up.
 */
#pragma once

#include "scale.h"

enum Flags {
  f_NoFlag = 0,
  f_W = 1,
  f_DW = 2,
  f_2DW = 3,
  f_3DW = 4,
  f_4DW = 5,
  f_B = 6,
  f_S = 7,
  f_F = 8,
  f_D = 9,
  f_LB = 10,
  f_HB = 11,
  f_Clear = 100,
  f_FetchMiss,
  f_DPStall,
  f_ExeStall,
  f_AGU0Stall,
  f_AGU1Stall,
  f_PipelineStall,
  f_AGUStall,
  f_AllInst
};

#define CALL_DYNAMIC_MPU(FUNC, SVR) do { (void)(FUNC); (void)(SVR); } while (0)

__device__ static inline unsigned __aurora_s_get_core_id(void) {
  return (unsigned)(blockIdx.x * blockDim.x + threadIdx.x);
}
__device__ static inline void __aurora_s_setMReg_var(int, v16u32) {}

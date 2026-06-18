#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "move_back.kernel_inc.h"

#include "move_back.kernel.cu"

#include "cuda_/pscmc_runtime_macros.h"

#define CUDA_MOVE_BACK_KERNEL_8_ARGS                                                                                   \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0],      \
      (((long *)kerstr->ZLEN->h_data))[0], (((long *)kerstr->grid_cache_len->h_data))[0],                              \
      (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_MOVE_BACK_KERNEL_8_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MOVE_BACK_KERNEL_8_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_MOVE_BACK_KERNEL_6_ARGS                                                                                   \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0],      \
      (((long *)kerstr->ZLEN->h_data))[0], (((long *)kerstr->grid_cache_len->h_data))[0],                              \
      (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_MOVE_BACK_KERNEL_6_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MOVE_BACK_KERNEL_6_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

extern "C" {
DEFINE_CUDA_MOVE_BACK_KERNEL_8_KERNEL(cuda_move_back_kernel_8)
DEFINE_CUDA_MOVE_BACK_KERNEL_6_KERNEL(cuda_move_back_kernel_6)
}

#undef DEFINE_CUDA_MOVE_BACK_KERNEL_8_KERNEL
#undef CUDA_MOVE_BACK_KERNEL_8_ARGS
#undef DEFINE_CUDA_MOVE_BACK_KERNEL_6_KERNEL
#undef CUDA_MOVE_BACK_KERNEL_6_ARGS

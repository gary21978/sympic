#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

#define DECL_CUDA_MOVE_BACK_KERNEL_8_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_MOVE_BACK_KERNEL_6_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

DECL_CUDA_MOVE_BACK_KERNEL_8_KERNEL(cuda_move_back_kernel_8)
DECL_CUDA_MOVE_BACK_KERNEL_6_KERNEL(cuda_move_back_kernel_6)

#undef DECL_CUDA_MOVE_BACK_KERNEL_8_KERNEL
#undef DECL_CUDA_MOVE_BACK_KERNEL_6_KERNEL

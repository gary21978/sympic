#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

#define DECL_CUDA_DUMP_ENE_NUM_KERNEL(P)                                                                               \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldE)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldB)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, FoutJ)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, FoutEN)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Mass)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Charge)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, SPEC)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, NUM_SPEC)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_X)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Y)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Z)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Deltat)

DECL_CUDA_DUMP_ENE_NUM_KERNEL(cuda_dump_ene_num)

#undef DECL_CUDA_DUMP_ENE_NUM_KERNEL

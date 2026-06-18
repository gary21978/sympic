#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

#define DECL_CUDA_RECT_YEE_CURL_L_KERNEL(P)                                                                            \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutE1)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inB0)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DT)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_X)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Y)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Z)

DECL_CUDA_RECT_YEE_CURL_L_KERNEL(cuda_RECT_YEE_CURL_L)

#undef DECL_CUDA_RECT_YEE_CURL_L_KERNEL

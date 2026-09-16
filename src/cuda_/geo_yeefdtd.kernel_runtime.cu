#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "geo_yeefdtd.kernel_inc.h"

#include "geo_yeefdtd.kernel.cu"

#include "cuda_/pscmc_runtime_macros.h"

#define CUDA_YEE_CURL_R_ARGS                                                                                           \
  ((double *)kerstr->inoutE1->d_data), ((double *)kerstr->inB0->d_data), ((int *)kerstr->xoffset->d_data),             \
      ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_CURL_R_KERNEL(P)                                                                               \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_CURL_R_ARGS)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutE1)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inB0)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y_cpu_core)                                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DT)

#define CUDA_GEO_YEE_CURL_L_ARGS                                                                                       \
  ((double *)kerstr->inoutE1->d_data), ((double *)kerstr->inB0->d_data), ((int *)kerstr->xoffset->d_data),             \
      ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0],                                      \
      (((double *)kerstr->DELTA_Z->h_data))[0], (((double *)kerstr->DELTA_Y->h_data))[0],                              \
      (((double *)kerstr->DELTA_X->h_data))[0], (((double *)kerstr->x0->h_data))[0]

#define DEFINE_CUDA_GEO_YEE_CURL_L_KERNEL(P)                                                                           \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GEO_YEE_CURL_L_ARGS)                                                                \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutE1)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inB0)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y_cpu_core)                                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DT)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_Z)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_Y)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_X)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x0)

extern "C" {
DEFINE_CUDA_YEE_CURL_R_KERNEL(cuda_YEE_CURL_R)
DEFINE_CUDA_GEO_YEE_CURL_L_KERNEL(cuda_GEO_YEE_CURL_L)
}

#undef DEFINE_CUDA_YEE_CURL_R_KERNEL
#undef CUDA_YEE_CURL_R_ARGS
#undef DEFINE_CUDA_GEO_YEE_CURL_L_KERNEL
#undef CUDA_GEO_YEE_CURL_L_ARGS

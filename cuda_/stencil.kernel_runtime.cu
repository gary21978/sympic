#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "stencil.kernel_inc.h"

#include "stencil.kernel.cu"

#include "cuda_/pscmc_runtime_macros.h"

#define CUDA_YEE_FDTD_W04_2_ARGS                                                                                       \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_W04_2_KERNEL(P)                                                                           \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_W04_2_ARGS)                                                                \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
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

#define CUDA_YEE_FDTD_W04_1_ARGS                                                                                       \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_W04_1_KERNEL(P)                                                                           \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_W04_1_ARGS)                                                                \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
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

#define CUDA_YEE_FDTD_W04_0_ARGS                                                                                       \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_W04_0_KERNEL(P)                                                                           \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_W04_0_ARGS)                                                                \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
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

extern "C" {
DEFINE_CUDA_YEE_FDTD_W04_2_KERNEL(cuda_Yee_FDTD_W04_2)
DEFINE_CUDA_YEE_FDTD_W04_1_KERNEL(cuda_Yee_FDTD_W04_1)
DEFINE_CUDA_YEE_FDTD_W04_0_KERNEL(cuda_Yee_FDTD_W04_0)
}

#undef DEFINE_CUDA_YEE_FDTD_W04_2_KERNEL
#undef CUDA_YEE_FDTD_W04_2_ARGS
#undef DEFINE_CUDA_YEE_FDTD_W04_1_KERNEL
#undef CUDA_YEE_FDTD_W04_1_ARGS
#undef DEFINE_CUDA_YEE_FDTD_W04_0_KERNEL
#undef CUDA_YEE_FDTD_W04_0_ARGS

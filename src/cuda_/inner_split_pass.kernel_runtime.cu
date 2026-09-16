#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "inner_split_pass.kernel_inc.h"

#include "inner_split_pass.kernel.cu"

#include "cuda_/pscmc_runtime_macros.h"

#define CUDA_GEO_NR_BFIELD_PUSHJ_VLO_ARGS                                                                              \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),            \
      ((int *)kerstr->zoffset->d_data), ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),        \
      ((double *)kerstr->fieldB1->d_data), ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],     \
      (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],    \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0],                   \
      (((double *)kerstr->DELTA_X->h_data))[0], (((double *)kerstr->DELTA_Y->h_data))[0],                              \
      (((double *)kerstr->DELTA_Z->h_data))[0], (((double *)kerstr->Mass0->h_data))[0],                                \
      (((double *)kerstr->Charge0->h_data))[0], (((double *)kerstr->Deltat->h_data))[0],                               \
      (((double *)kerstr->Tori_X0->h_data))[0], (((double *)kerstr->r0->h_data))[0],                                   \
      (((double *)kerstr->MIN_R0->h_data))[0], (((double *)kerstr->Q0->h_data))[0],                                    \
      (((double *)kerstr->b0->h_data))[0], (((double *)kerstr->zmid->h_data))[0]

#define DEFINE_CUDA_GEO_NR_BFIELD_PUSHJ_VLO_KERNEL(P)                                                                  \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GEO_NR_BFIELD_PUSHJ_VLO_ARGS)                                                       \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zoffset)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, fieldE)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, fieldB)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, fieldB1)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, FoutJ)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_X)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_Y)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_Z)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Mass0)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Charge0)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Deltat)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Tori_X0)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, r0)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, MIN_R0)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Q0)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, b0)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zmid)

extern "C" {
DEFINE_CUDA_GEO_NR_BFIELD_PUSHJ_VLO_KERNEL(cuda_geo_nr_Bfield_pushJ_vlo)
}

#undef DEFINE_CUDA_GEO_NR_BFIELD_PUSHJ_VLO_KERNEL
#undef CUDA_GEO_NR_BFIELD_PUSHJ_VLO_ARGS

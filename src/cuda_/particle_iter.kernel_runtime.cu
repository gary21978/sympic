#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "particle_iter.kernel_inc.h"

#include "particle_iter.kernel.cu"

#include "pscmc_runtime_macros.h"

#define CUDA_DUMP_ENE_NUM_ARGS                                                                                         \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),        \
      ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data), (((long *)kerstr->XLEN->h_data))[0],      \
      (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],    \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0],                   \
      (((double *)kerstr->Mass->h_data))[0], (((double *)kerstr->Charge->h_data))[0],                                  \
      (((int *)kerstr->SPEC->h_data))[0], (((int *)kerstr->NUM_SPEC->h_data))[0],                                      \
      (((double *)kerstr->DELTA_X->h_data))[0], (((double *)kerstr->DELTA_Y->h_data))[0],                              \
      (((double *)kerstr->DELTA_Z->h_data))[0], (((double *)kerstr->Deltat->h_data))[0]

#define DEFINE_CUDA_DUMP_ENE_NUM_KERNEL(P)                                                                             \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_DUMP_ENE_NUM_ARGS)                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, fieldE)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, fieldB)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, FoutJ)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, FoutEN)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Mass)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Charge)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, SPEC)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, NUM_SPEC)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_X)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_Y)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DELTA_Z)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Deltat)

extern "C" {
DEFINE_CUDA_DUMP_ENE_NUM_KERNEL(cuda_dump_ene_num)
}

#undef DEFINE_CUDA_DUMP_ENE_NUM_KERNEL
#undef CUDA_DUMP_ENE_NUM_ARGS

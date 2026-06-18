#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "yeefdtd.kernel_inc.h"

#include "yeefdtd.kernel.cu"

#include "cuda_/pscmc_runtime_macros.h"

#define CUDA_KGM_EQN_CORE_ARGS                                                                                         \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), ((double *)kerstr->extA0->d_data),              \
      ((double *)kerstr->extA1->d_data), ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),           \
      ((int *)kerstr->zoffset->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],                                     \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],  \
      (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0], (((double *)kerstr->GEXT->h_data))[0],  \
      (((double *)kerstr->rfz0->h_data))[0], (((double *)kerstr->g_beg->h_data))[0],                                   \
      (((int *)kerstr->swap_input->h_data))[0]

#define DEFINE_CUDA_KGM_EQN_CORE_KERNEL(P)                                                                             \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_KGM_EQN_CORE_ARGS)                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, extA0)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, extA1)                                                                              \
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
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, M)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Q)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DX)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, GEXT)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rfz0)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, g_beg)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, swap_input)

#define CUDA_KGM_CALC_RHO_ARGS                                                                                         \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), ((int *)kerstr->xoffset->d_data),               \
      ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],  \
      (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0], (((double *)kerstr->refz0->h_data))[0], \
      (((double *)kerstr->q->h_data))[0], (((double *)kerstr->dtodx->h_data))[0], (((int *)kerstr->mode->h_data))[0],  \
      (((int *)kerstr->swap_input->h_data))[0]

#define DEFINE_CUDA_KGM_CALC_RHO_KERNEL(P)                                                                             \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_KGM_CALC_RHO_ARGS)                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
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
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, M)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Q)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DX)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, refz0)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, q)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, dtodx)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, mode)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, swap_input)

#define CUDA_PML_FDTD_CURL_BWD_ARGS                                                                                    \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), ((double *)kerstr->outPMLEB->d_data),           \
      ((double *)kerstr->inPMLEB->d_data), ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),         \
      ((int *)kerstr->zoffset->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],                                     \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],  \
      (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0], (((double *)kerstr->DY->h_data))[0],    \
      (((double *)kerstr->DZ->h_data))[0], (((int *)kerstr->abc_dir->h_data))[0], (((int *)kerstr->level->h_data))[0], \
      (((int *)kerstr->pml_m->h_data))[0], (((double *)kerstr->max_sigma->h_data))[0],                                 \
      (((long *)kerstr->allxmax->h_data))[0], (((long *)kerstr->allymax->h_data))[0],                                  \
      (((long *)kerstr->allzmax->h_data))[0]

#define DEFINE_CUDA_PML_FDTD_CURL_BWD_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_PML_FDTD_CURL_BWD_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outPMLEB)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inPMLEB)                                                                            \
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
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, M)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Q)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DX)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DY)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DZ)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, abc_dir)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, level)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, pml_m)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, max_sigma)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, allxmax)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, allymax)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, allzmax)

#define CUDA_PML_FDTD_CURL_FWD_ARGS                                                                                    \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), ((double *)kerstr->outPMLEB->d_data),           \
      ((double *)kerstr->inPMLEB->d_data), ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),         \
      ((int *)kerstr->zoffset->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],                                     \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],  \
      (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0], (((double *)kerstr->DY->h_data))[0],    \
      (((double *)kerstr->DZ->h_data))[0], (((int *)kerstr->abc_dir->h_data))[0], (((int *)kerstr->level->h_data))[0], \
      (((int *)kerstr->pml_m->h_data))[0], (((double *)kerstr->max_sigma->h_data))[0],                                 \
      (((long *)kerstr->allxmax->h_data))[0], (((long *)kerstr->allymax->h_data))[0],                                  \
      (((long *)kerstr->allzmax->h_data))[0]

#define DEFINE_CUDA_PML_FDTD_CURL_FWD_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_PML_FDTD_CURL_FWD_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outEB)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inEB)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, outPMLEB)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inPMLEB)                                                                            \
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
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, M)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, Q)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DX)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DY)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, DZ)                                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, abc_dir)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, level)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, pml_m)                                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, max_sigma)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, allxmax)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, allymax)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, allzmax)

#define CUDA_MERGE_CURRENT_ARGS                                                                                        \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_MERGE_CURRENT_KERNEL(P)                                                                            \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_CURRENT_ARGS)                                                                 \
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
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)

#define CUDA_MERGE_CURRENT_2_ARGS                                                                                      \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_MERGE_CURRENT_2_KERNEL(P)                                                                          \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_CURRENT_2_ARGS)                                                               \
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
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)

#define CUDA_YEE_FDTD_DIV_FWD_4TH_ARGS                                                                                 \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_DIV_FWD_4TH_KERNEL(P)                                                                     \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_DIV_FWD_4TH_ARGS)                                                          \
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

#define CUDA_YEE_FDTD_DIV_FWD_ARGS                                                                                     \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_DIV_FWD_KERNEL(P)                                                                         \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_DIV_FWD_ARGS)                                                              \
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

#define CUDA_YEE_FDTD_DIV_BWD_4TH_ARGS                                                                                 \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_DIV_BWD_4TH_KERNEL(P)                                                                     \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_DIV_BWD_4TH_ARGS)                                                          \
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

#define CUDA_YEE_FDTD_DIV_BWD_ARGS                                                                                     \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_DIV_BWD_KERNEL(P)                                                                         \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_DIV_BWD_ARGS)                                                              \
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

#define CUDA_YEE_FDTD_CURL_FWD_4TH_ARGS                                                                                \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_FWD_4TH_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_FWD_4TH_ARGS)                                                         \
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

#define CUDA_YEE_FDTD_CURL_FWD_ARGS                                                                                    \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_FWD_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_FWD_ARGS)                                                             \
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

#define CUDA_YEE_FDTD_CURL_BWD_4TH_ARGS                                                                                \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_BWD_4TH_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_BWD_4TH_ARGS)                                                         \
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

#define CUDA_YEE_FDTD_CURL_BWD_ARGS                                                                                    \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_BWD_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_BWD_ARGS)                                                             \
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

#define CUDA_YEE_FDTD_GRAD_FWD_4TH_ARGS                                                                                \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_GRAD_FWD_4TH_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_GRAD_FWD_4TH_ARGS)                                                         \
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

#define CUDA_YEE_FDTD_GRAD_FWD_ARGS                                                                                    \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_GRAD_FWD_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_GRAD_FWD_ARGS)                                                             \
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

#define CUDA_YEE_FDTD_GRAD_BWD_4TH_ARGS                                                                                \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_GRAD_BWD_4TH_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_GRAD_BWD_4TH_ARGS)                                                         \
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

#define CUDA_YEE_FDTD_GRAD_BWD_ARGS                                                                                    \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_GRAD_BWD_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_GRAD_BWD_ARGS)                                                             \
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

#define CUDA_YEE_FDTD_CURL_B_4TH_ARGS                                                                                  \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_B_4TH_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_B_4TH_ARGS)                                                           \
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

#define CUDA_YEE_FDTD_CURL_B_ARGS                                                                                      \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_B_KERNEL(P)                                                                          \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_B_ARGS)                                                               \
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

#define CUDA_YEE_FDTD_CURL_E_4TH_ARGS                                                                                  \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_E_4TH_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_E_4TH_ARGS)                                                           \
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

#define CUDA_YEE_FDTD_CURL_E_ARGS                                                                                      \
  ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]

#define DEFINE_CUDA_YEE_FDTD_CURL_E_KERNEL(P)                                                                          \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_YEE_FDTD_CURL_E_ARGS)                                                               \
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
DEFINE_CUDA_KGM_EQN_CORE_KERNEL(cuda_kgm_eqn_core)
DEFINE_CUDA_KGM_CALC_RHO_KERNEL(cuda_kgm_calc_rho)
DEFINE_CUDA_PML_FDTD_CURL_BWD_KERNEL(cuda_PML_FDTD_CURL_BWD)
DEFINE_CUDA_PML_FDTD_CURL_FWD_KERNEL(cuda_PML_FDTD_CURL_FWD)
DEFINE_CUDA_MERGE_CURRENT_KERNEL(cuda_merge_current)
DEFINE_CUDA_MERGE_CURRENT_2_KERNEL(cuda_merge_current_2)
DEFINE_CUDA_YEE_FDTD_DIV_FWD_4TH_KERNEL(cuda_Yee_FDTD_Div_FWD_4th)
DEFINE_CUDA_YEE_FDTD_DIV_FWD_KERNEL(cuda_Yee_FDTD_Div_FWD)
DEFINE_CUDA_YEE_FDTD_DIV_BWD_4TH_KERNEL(cuda_Yee_FDTD_Div_BWD_4th)
DEFINE_CUDA_YEE_FDTD_DIV_BWD_KERNEL(cuda_Yee_FDTD_Div_BWD)
DEFINE_CUDA_YEE_FDTD_CURL_FWD_4TH_KERNEL(cuda_Yee_FDTD_Curl_FWD_4th)
DEFINE_CUDA_YEE_FDTD_CURL_FWD_KERNEL(cuda_Yee_FDTD_Curl_FWD)
DEFINE_CUDA_YEE_FDTD_CURL_BWD_4TH_KERNEL(cuda_Yee_FDTD_Curl_BWD_4th)
DEFINE_CUDA_YEE_FDTD_CURL_BWD_KERNEL(cuda_Yee_FDTD_Curl_BWD)
DEFINE_CUDA_YEE_FDTD_GRAD_FWD_4TH_KERNEL(cuda_Yee_FDTD_Grad_FWD_4th)
DEFINE_CUDA_YEE_FDTD_GRAD_FWD_KERNEL(cuda_Yee_FDTD_Grad_FWD)
DEFINE_CUDA_YEE_FDTD_GRAD_BWD_4TH_KERNEL(cuda_Yee_FDTD_Grad_BWD_4th)
DEFINE_CUDA_YEE_FDTD_GRAD_BWD_KERNEL(cuda_Yee_FDTD_Grad_BWD)
DEFINE_CUDA_YEE_FDTD_CURL_B_4TH_KERNEL(cuda_Yee_FDTD_Curl_B_4th)
DEFINE_CUDA_YEE_FDTD_CURL_B_KERNEL(cuda_Yee_FDTD_Curl_B)
DEFINE_CUDA_YEE_FDTD_CURL_E_4TH_KERNEL(cuda_Yee_FDTD_Curl_E_4th)
DEFINE_CUDA_YEE_FDTD_CURL_E_KERNEL(cuda_Yee_FDTD_Curl_E)
}

#undef DEFINE_CUDA_KGM_EQN_CORE_KERNEL
#undef CUDA_KGM_EQN_CORE_ARGS
#undef DEFINE_CUDA_KGM_CALC_RHO_KERNEL
#undef CUDA_KGM_CALC_RHO_ARGS
#undef DEFINE_CUDA_PML_FDTD_CURL_BWD_KERNEL
#undef CUDA_PML_FDTD_CURL_BWD_ARGS
#undef DEFINE_CUDA_PML_FDTD_CURL_FWD_KERNEL
#undef CUDA_PML_FDTD_CURL_FWD_ARGS
#undef DEFINE_CUDA_MERGE_CURRENT_KERNEL
#undef CUDA_MERGE_CURRENT_ARGS
#undef DEFINE_CUDA_MERGE_CURRENT_2_KERNEL
#undef CUDA_MERGE_CURRENT_2_ARGS
#undef DEFINE_CUDA_YEE_FDTD_DIV_FWD_4TH_KERNEL
#undef CUDA_YEE_FDTD_DIV_FWD_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_DIV_FWD_KERNEL
#undef CUDA_YEE_FDTD_DIV_FWD_ARGS
#undef DEFINE_CUDA_YEE_FDTD_DIV_BWD_4TH_KERNEL
#undef CUDA_YEE_FDTD_DIV_BWD_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_DIV_BWD_KERNEL
#undef CUDA_YEE_FDTD_DIV_BWD_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_FWD_4TH_KERNEL
#undef CUDA_YEE_FDTD_CURL_FWD_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_FWD_KERNEL
#undef CUDA_YEE_FDTD_CURL_FWD_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_BWD_4TH_KERNEL
#undef CUDA_YEE_FDTD_CURL_BWD_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_BWD_KERNEL
#undef CUDA_YEE_FDTD_CURL_BWD_ARGS
#undef DEFINE_CUDA_YEE_FDTD_GRAD_FWD_4TH_KERNEL
#undef CUDA_YEE_FDTD_GRAD_FWD_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_GRAD_FWD_KERNEL
#undef CUDA_YEE_FDTD_GRAD_FWD_ARGS
#undef DEFINE_CUDA_YEE_FDTD_GRAD_BWD_4TH_KERNEL
#undef CUDA_YEE_FDTD_GRAD_BWD_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_GRAD_BWD_KERNEL
#undef CUDA_YEE_FDTD_GRAD_BWD_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_B_4TH_KERNEL
#undef CUDA_YEE_FDTD_CURL_B_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_B_KERNEL
#undef CUDA_YEE_FDTD_CURL_B_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_E_4TH_KERNEL
#undef CUDA_YEE_FDTD_CURL_E_4TH_ARGS
#undef DEFINE_CUDA_YEE_FDTD_CURL_E_KERNEL
#undef CUDA_YEE_FDTD_CURL_E_ARGS

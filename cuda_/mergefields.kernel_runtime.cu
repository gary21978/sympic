#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "mergefields.kernel_inc.h"

#include "mergefields.kernel.cu"

#include "cuda_/pscmc_runtime_macros.h"

#define CUDA_MERGE_OVLP_M2O_ONCE_ARGS                                                                                  \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp0->d_data), ((double *)kerstr->vecovlp1->d_data),     \
      ((double *)kerstr->vecovlp2->d_data), ((double *)kerstr->vecovlp3->d_data),                                      \
      ((double *)kerstr->vecovlp4->d_data), ((double *)kerstr->vecovlp5->d_data),                                      \
      ((double *)kerstr->vecovlp6->d_data), ((double *)kerstr->vecovlp7->d_data),                                      \
      ((double *)kerstr->vecovlp8->d_data), ((double *)kerstr->vecovlp9->d_data),                                      \
      ((double *)kerstr->vecovlp10->d_data), ((double *)kerstr->vecovlp11->d_data),                                    \
      ((double *)kerstr->vecovlp12->d_data), ((double *)kerstr->vecovlp14->d_data),                                    \
      ((double *)kerstr->vecovlp15->d_data), ((double *)kerstr->vecovlp16->d_data),                                    \
      ((double *)kerstr->vecovlp17->d_data), ((double *)kerstr->vecovlp18->d_data),                                    \
      ((double *)kerstr->vecovlp19->d_data), ((double *)kerstr->vecovlp20->d_data),                                    \
      ((double *)kerstr->vecovlp21->d_data), ((double *)kerstr->vecovlp22->d_data),                                    \
      ((double *)kerstr->vecovlp23->d_data), ((double *)kerstr->vecovlp24->d_data),                                    \
      ((double *)kerstr->vecovlp25->d_data), ((double *)kerstr->vecovlp26->d_data),                                    \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_MERGE_OVLP_M2O_ONCE_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_OVLP_M2O_ONCE_ARGS)                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp0)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp1)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp2)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp3)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp4)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp5)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp6)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp7)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp8)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp9)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp10)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp11)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp12)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp14)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp15)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp16)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp17)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp18)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp19)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp20)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp21)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp22)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp23)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp24)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp25)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp26)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_ARGS                                                                            \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlps->d_data), (((long *)kerstr->numvec->h_data))[0],    \
      (((int *)kerstr->num_ele->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                    \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlps)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_MERGE_OVLP_M2O_ARGS                                                                                       \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp->d_data), (((int *)kerstr->ovlpindex->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_MERGE_OVLP_M2O_KERNEL(P)                                                                           \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_OVLP_M2O_ARGS)                                                                \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlpindex)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_MERGE_OVLP_O2M_ONCE_ARGS                                                                                  \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp0->d_data), ((double *)kerstr->vecovlp1->d_data),     \
      ((double *)kerstr->vecovlp2->d_data), ((double *)kerstr->vecovlp3->d_data),                                      \
      ((double *)kerstr->vecovlp4->d_data), ((double *)kerstr->vecovlp5->d_data),                                      \
      ((double *)kerstr->vecovlp6->d_data), ((double *)kerstr->vecovlp7->d_data),                                      \
      ((double *)kerstr->vecovlp8->d_data), ((double *)kerstr->vecovlp9->d_data),                                      \
      ((double *)kerstr->vecovlp10->d_data), ((double *)kerstr->vecovlp11->d_data),                                    \
      ((double *)kerstr->vecovlp12->d_data), ((double *)kerstr->vecovlp14->d_data),                                    \
      ((double *)kerstr->vecovlp15->d_data), ((double *)kerstr->vecovlp16->d_data),                                    \
      ((double *)kerstr->vecovlp17->d_data), ((double *)kerstr->vecovlp18->d_data),                                    \
      ((double *)kerstr->vecovlp19->d_data), ((double *)kerstr->vecovlp20->d_data),                                    \
      ((double *)kerstr->vecovlp21->d_data), ((double *)kerstr->vecovlp22->d_data),                                    \
      ((double *)kerstr->vecovlp23->d_data), ((double *)kerstr->vecovlp24->d_data),                                    \
      ((double *)kerstr->vecovlp25->d_data), ((double *)kerstr->vecovlp26->d_data),                                    \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_MERGE_OVLP_O2M_ONCE_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_OVLP_O2M_ONCE_ARGS)                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp0)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp1)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp2)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp3)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp4)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp5)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp6)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp7)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp8)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp9)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp10)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp11)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp12)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp14)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp15)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp16)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp17)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp18)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp19)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp20)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp21)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp22)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp23)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp24)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp25)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp26)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_ARGS                                                                            \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlps->d_data), (((long *)kerstr->numvec->h_data))[0],    \
      (((int *)kerstr->num_ele->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                    \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlps)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_MERGE_OVLP_O2M_ARGS                                                                                       \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp->d_data), (((int *)kerstr->ovlpindex->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_MERGE_OVLP_O2M_KERNEL(P)                                                                           \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_MERGE_OVLP_O2M_ARGS)                                                                \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlpindex)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_SYNC_OVLP_M2O_ONCE_ARGS                                                                                   \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp0->d_data), ((double *)kerstr->vecovlp1->d_data),     \
      ((double *)kerstr->vecovlp2->d_data), ((double *)kerstr->vecovlp3->d_data),                                      \
      ((double *)kerstr->vecovlp4->d_data), ((double *)kerstr->vecovlp5->d_data),                                      \
      ((double *)kerstr->vecovlp6->d_data), ((double *)kerstr->vecovlp7->d_data),                                      \
      ((double *)kerstr->vecovlp8->d_data), ((double *)kerstr->vecovlp9->d_data),                                      \
      ((double *)kerstr->vecovlp10->d_data), ((double *)kerstr->vecovlp11->d_data),                                    \
      ((double *)kerstr->vecovlp12->d_data), ((double *)kerstr->vecovlp14->d_data),                                    \
      ((double *)kerstr->vecovlp15->d_data), ((double *)kerstr->vecovlp16->d_data),                                    \
      ((double *)kerstr->vecovlp17->d_data), ((double *)kerstr->vecovlp18->d_data),                                    \
      ((double *)kerstr->vecovlp19->d_data), ((double *)kerstr->vecovlp20->d_data),                                    \
      ((double *)kerstr->vecovlp21->d_data), ((double *)kerstr->vecovlp22->d_data),                                    \
      ((double *)kerstr->vecovlp23->d_data), ((double *)kerstr->vecovlp24->d_data),                                    \
      ((double *)kerstr->vecovlp25->d_data), ((double *)kerstr->vecovlp26->d_data),                                    \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_SYNC_OVLP_M2O_ONCE_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SYNC_OVLP_M2O_ONCE_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp0)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp1)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp2)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp3)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp4)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp5)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp6)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp7)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp8)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp9)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp10)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp11)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp12)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp14)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp15)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp16)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp17)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp18)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp19)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp20)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp21)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp22)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp23)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp24)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp25)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp26)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_ARGS                                                                             \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlps->d_data), (((long *)kerstr->numvec->h_data))[0],    \
      (((int *)kerstr->num_ele->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                    \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_KERNEL(P)                                                                 \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_ARGS)                                                      \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlps)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_SYNC_OVLP_M2O_ARGS                                                                                        \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp->d_data), (((int *)kerstr->ovlpindex->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_SYNC_OVLP_M2O_KERNEL(P)                                                                            \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SYNC_OVLP_M2O_ARGS)                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlpindex)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_SYNC_OVLP_O2M_ONCE_ARGS                                                                                   \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp0->d_data), ((double *)kerstr->vecovlp1->d_data),     \
      ((double *)kerstr->vecovlp2->d_data), ((double *)kerstr->vecovlp3->d_data),                                      \
      ((double *)kerstr->vecovlp4->d_data), ((double *)kerstr->vecovlp5->d_data),                                      \
      ((double *)kerstr->vecovlp6->d_data), ((double *)kerstr->vecovlp7->d_data),                                      \
      ((double *)kerstr->vecovlp8->d_data), ((double *)kerstr->vecovlp9->d_data),                                      \
      ((double *)kerstr->vecovlp10->d_data), ((double *)kerstr->vecovlp11->d_data),                                    \
      ((double *)kerstr->vecovlp12->d_data), ((double *)kerstr->vecovlp14->d_data),                                    \
      ((double *)kerstr->vecovlp15->d_data), ((double *)kerstr->vecovlp16->d_data),                                    \
      ((double *)kerstr->vecovlp17->d_data), ((double *)kerstr->vecovlp18->d_data),                                    \
      ((double *)kerstr->vecovlp19->d_data), ((double *)kerstr->vecovlp20->d_data),                                    \
      ((double *)kerstr->vecovlp21->d_data), ((double *)kerstr->vecovlp22->d_data),                                    \
      ((double *)kerstr->vecovlp23->d_data), ((double *)kerstr->vecovlp24->d_data),                                    \
      ((double *)kerstr->vecovlp25->d_data), ((double *)kerstr->vecovlp26->d_data),                                    \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_SYNC_OVLP_O2M_ONCE_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SYNC_OVLP_O2M_ONCE_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp0)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp1)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp2)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp3)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp4)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp5)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp6)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp7)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp8)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp9)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp10)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp11)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp12)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp14)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp15)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp16)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp17)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp18)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp19)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp20)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp21)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp22)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp23)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp24)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp25)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp26)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_ARGS                                                                             \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlps->d_data), (((long *)kerstr->numvec->h_data))[0],    \
      (((int *)kerstr->num_ele->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                    \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_KERNEL(P)                                                                 \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_ARGS)                                                      \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlps)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

#define CUDA_SYNC_OVLP_O2M_ARGS                                                                                        \
  ((double *)kerstr->vecmain->d_data), ((double *)kerstr->vecovlp->d_data), (((int *)kerstr->ovlpindex->h_data))[0],   \
      (((long *)kerstr->numvec->h_data))[0], (((int *)kerstr->num_ele->h_data))[0],                                    \
      (((long *)kerstr->xblock->h_data))[0], (((long *)kerstr->yblock->h_data))[0],                                    \
      (((long *)kerstr->zblock->h_data))[0], (((int *)kerstr->ovlp->h_data))[0]

#define DEFINE_CUDA_SYNC_OVLP_O2M_KERNEL(P)                                                                            \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SYNC_OVLP_O2M_ARGS)                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecmain)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, vecovlp)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlpindex)                                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, num_ele)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, yblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, zblock)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)

extern "C" {
DEFINE_CUDA_MERGE_OVLP_M2O_ONCE_KERNEL(cuda_merge_ovlp_m2o_once)
DEFINE_CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_KERNEL(cuda_merge_ovlp_m2o_all_in_one)
DEFINE_CUDA_MERGE_OVLP_M2O_KERNEL(cuda_merge_ovlp_m2o)
DEFINE_CUDA_MERGE_OVLP_O2M_ONCE_KERNEL(cuda_merge_ovlp_o2m_once)
DEFINE_CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_KERNEL(cuda_merge_ovlp_o2m_all_in_one)
DEFINE_CUDA_MERGE_OVLP_O2M_KERNEL(cuda_merge_ovlp_o2m)
DEFINE_CUDA_SYNC_OVLP_M2O_ONCE_KERNEL(cuda_sync_ovlp_m2o_once)
DEFINE_CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_KERNEL(cuda_sync_ovlp_m2o_all_in_one)
DEFINE_CUDA_SYNC_OVLP_M2O_KERNEL(cuda_sync_ovlp_m2o)
DEFINE_CUDA_SYNC_OVLP_O2M_ONCE_KERNEL(cuda_sync_ovlp_o2m_once)
DEFINE_CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_KERNEL(cuda_sync_ovlp_o2m_all_in_one)
DEFINE_CUDA_SYNC_OVLP_O2M_KERNEL(cuda_sync_ovlp_o2m)
}

#undef DEFINE_CUDA_MERGE_OVLP_M2O_ONCE_KERNEL
#undef CUDA_MERGE_OVLP_M2O_ONCE_ARGS
#undef DEFINE_CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_KERNEL
#undef CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_ARGS
#undef DEFINE_CUDA_MERGE_OVLP_M2O_KERNEL
#undef CUDA_MERGE_OVLP_M2O_ARGS
#undef DEFINE_CUDA_MERGE_OVLP_O2M_ONCE_KERNEL
#undef CUDA_MERGE_OVLP_O2M_ONCE_ARGS
#undef DEFINE_CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_KERNEL
#undef CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_ARGS
#undef DEFINE_CUDA_MERGE_OVLP_O2M_KERNEL
#undef CUDA_MERGE_OVLP_O2M_ARGS
#undef DEFINE_CUDA_SYNC_OVLP_M2O_ONCE_KERNEL
#undef CUDA_SYNC_OVLP_M2O_ONCE_ARGS
#undef DEFINE_CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_KERNEL
#undef CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_ARGS
#undef DEFINE_CUDA_SYNC_OVLP_M2O_KERNEL
#undef CUDA_SYNC_OVLP_M2O_ARGS
#undef DEFINE_CUDA_SYNC_OVLP_O2M_ONCE_KERNEL
#undef CUDA_SYNC_OVLP_O2M_ONCE_ARGS
#undef DEFINE_CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_KERNEL
#undef CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_ARGS
#undef DEFINE_CUDA_SYNC_OVLP_O2M_KERNEL
#undef CUDA_SYNC_OVLP_O2M_ARGS

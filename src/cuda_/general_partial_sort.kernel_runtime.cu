#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "general_partial_sort.kernel_inc.h"

#include "general_partial_sort.kernel.cu"

#include "pscmc_runtime_macros.h"

#define CUDA_CU_SWAP_R_8_ARGS                                                                                          \
  ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),  \
      (((long *)kerstr->cu_cache_length->h_data))[0], (((int *)kerstr->the_dir_num->h_data))[0],                       \
      (((long *)kerstr->XYZLEN->h_data))[0]

#define DEFINE_CUDA_CU_SWAP_R_8_KERNEL(P)                                                                              \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_CU_SWAP_R_8_ARGS)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, the_dir_num)                                                                        \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XYZLEN)

#define CUDA_CU_SWAP_L_8_ARGS                                                                                          \
  ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),  \
      (((long *)kerstr->cu_cache_length->h_data))[0], (((int *)kerstr->the_dir_num->h_data))[0],                       \
      (((long *)kerstr->XYZLEN->h_data))[0]

#define DEFINE_CUDA_CU_SWAP_L_8_KERNEL(P)                                                                              \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_CU_SWAP_L_8_ARGS)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, the_dir_num)                                                                        \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XYZLEN)

#define CUDA_CU_SWAP_R_6_ARGS                                                                                          \
  ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),  \
      (((long *)kerstr->cu_cache_length->h_data))[0], (((int *)kerstr->the_dir_num->h_data))[0],                       \
      (((long *)kerstr->XYZLEN->h_data))[0]

#define DEFINE_CUDA_CU_SWAP_R_6_KERNEL(P)                                                                              \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_CU_SWAP_R_6_ARGS)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, the_dir_num)                                                                        \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XYZLEN)

#define CUDA_CU_SWAP_L_6_ARGS                                                                                          \
  ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),  \
      (((long *)kerstr->cu_cache_length->h_data))[0], (((int *)kerstr->the_dir_num->h_data))[0],                       \
      (((long *)kerstr->XYZLEN->h_data))[0]

#define DEFINE_CUDA_CU_SWAP_L_6_KERNEL(P)                                                                              \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_CU_SWAP_L_6_ARGS)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, the_dir_num)                                                                        \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XYZLEN)

#define CUDA_SORT_ONE_GRID_Z_VLO_8_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Z_VLO_8_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Z_VLO_8_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_ARGS                                                                            \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Y_VLO_8_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Y_VLO_8_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Y_VLO_8_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_ARGS                                                                            \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_X_VLO_8_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_X_VLO_8_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_X_VLO_8_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_X_VLO_8_ARGS                                                                            \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_X_VLO_8_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_X_VLO_8_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Z_8_ARGS                                                                                    \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Z_8_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Z_8_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Z_8_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_8_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Z_8_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Y_8_ARGS                                                                                    \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Y_8_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Y_8_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Y_8_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_8_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Y_8_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_X_8_ARGS                                                                                    \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_X_8_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_X_8_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_X_8_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_X_8_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_X_8_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Z_VLO_6_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Z_VLO_6_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Z_VLO_6_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_ARGS                                                                            \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Y_VLO_6_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Y_VLO_6_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Y_VLO_6_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_ARGS                                                                            \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_X_VLO_6_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_X_VLO_6_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_X_VLO_6_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_X_VLO_6_ARGS                                                                            \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_X_VLO_6_KERNEL(P)                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_X_VLO_6_ARGS)                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Z_6_ARGS                                                                                    \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Z_6_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Z_6_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Z_6_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_6_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Z_6_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_Y_6_ARGS                                                                                    \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_Y_6_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_Y_6_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_Y_6_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_6_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_Y_6_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_SORT_ONE_GRID_X_6_ARGS                                                                                    \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_SORT_ONE_GRID_X_6_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_SORT_ONE_GRID_X_6_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

#define CUDA_GPU_SORT_ONE_GRID_X_6_ARGS                                                                                \
  ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data), ((double *)kerstr->cu_cache->d_data),           \
      ((int *)kerstr->cu_xyzw->d_data), ((long *)kerstr->adjoint_vec_pids->d_data),                                    \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                       \
      (((long *)kerstr->grid_cache_len->h_data))[0], (((long *)kerstr->cu_cache_length->h_data))[0]

#define DEFINE_CUDA_GPU_SORT_ONE_GRID_X_6_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, 32)                                                                                  \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_GPU_SORT_ONE_GRID_X_6_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, inoutput)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, xyzw)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache)                                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_xyzw)                                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                   \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, XLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, YLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ZLEN)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, ovlp)                                                                               \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, numvec)                                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, grid_cache_len)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, cu_cache_length)

extern "C" {
DEFINE_CUDA_CU_SWAP_R_8_KERNEL(cuda_cu_swap_r_8)
DEFINE_CUDA_CU_SWAP_L_8_KERNEL(cuda_cu_swap_l_8)
DEFINE_CUDA_CU_SWAP_R_6_KERNEL(cuda_cu_swap_r_6)
DEFINE_CUDA_CU_SWAP_L_6_KERNEL(cuda_cu_swap_l_6)
DEFINE_CUDA_SORT_ONE_GRID_Z_VLO_8_KERNEL(cuda_sort_one_grid_z_vlo_8)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_KERNEL(cuda_gpu_sort_one_grid_z_vlo_8)
DEFINE_CUDA_SORT_ONE_GRID_Y_VLO_8_KERNEL(cuda_sort_one_grid_y_vlo_8)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_KERNEL(cuda_gpu_sort_one_grid_y_vlo_8)
DEFINE_CUDA_SORT_ONE_GRID_X_VLO_8_KERNEL(cuda_sort_one_grid_x_vlo_8)
DEFINE_CUDA_GPU_SORT_ONE_GRID_X_VLO_8_KERNEL(cuda_gpu_sort_one_grid_x_vlo_8)
DEFINE_CUDA_SORT_ONE_GRID_Z_8_KERNEL(cuda_sort_one_grid_z_8)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_8_KERNEL(cuda_gpu_sort_one_grid_z_8)
DEFINE_CUDA_SORT_ONE_GRID_Y_8_KERNEL(cuda_sort_one_grid_y_8)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_8_KERNEL(cuda_gpu_sort_one_grid_y_8)
DEFINE_CUDA_SORT_ONE_GRID_X_8_KERNEL(cuda_sort_one_grid_x_8)
DEFINE_CUDA_GPU_SORT_ONE_GRID_X_8_KERNEL(cuda_gpu_sort_one_grid_x_8)
DEFINE_CUDA_SORT_ONE_GRID_Z_VLO_6_KERNEL(cuda_sort_one_grid_z_vlo_6)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_KERNEL(cuda_gpu_sort_one_grid_z_vlo_6)
DEFINE_CUDA_SORT_ONE_GRID_Y_VLO_6_KERNEL(cuda_sort_one_grid_y_vlo_6)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_KERNEL(cuda_gpu_sort_one_grid_y_vlo_6)
DEFINE_CUDA_SORT_ONE_GRID_X_VLO_6_KERNEL(cuda_sort_one_grid_x_vlo_6)
DEFINE_CUDA_GPU_SORT_ONE_GRID_X_VLO_6_KERNEL(cuda_gpu_sort_one_grid_x_vlo_6)
DEFINE_CUDA_SORT_ONE_GRID_Z_6_KERNEL(cuda_sort_one_grid_z_6)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_6_KERNEL(cuda_gpu_sort_one_grid_z_6)
DEFINE_CUDA_SORT_ONE_GRID_Y_6_KERNEL(cuda_sort_one_grid_y_6)
DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_6_KERNEL(cuda_gpu_sort_one_grid_y_6)
DEFINE_CUDA_SORT_ONE_GRID_X_6_KERNEL(cuda_sort_one_grid_x_6)
DEFINE_CUDA_GPU_SORT_ONE_GRID_X_6_KERNEL(cuda_gpu_sort_one_grid_x_6)
}

#undef DEFINE_CUDA_CU_SWAP_R_8_KERNEL
#undef CUDA_CU_SWAP_R_8_ARGS
#undef DEFINE_CUDA_CU_SWAP_L_8_KERNEL
#undef CUDA_CU_SWAP_L_8_ARGS
#undef DEFINE_CUDA_CU_SWAP_R_6_KERNEL
#undef CUDA_CU_SWAP_R_6_ARGS
#undef DEFINE_CUDA_CU_SWAP_L_6_KERNEL
#undef CUDA_CU_SWAP_L_6_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Z_VLO_8_KERNEL
#undef CUDA_SORT_ONE_GRID_Z_VLO_8_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Y_VLO_8_KERNEL
#undef CUDA_SORT_ONE_GRID_Y_VLO_8_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_X_VLO_8_KERNEL
#undef CUDA_SORT_ONE_GRID_X_VLO_8_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_X_VLO_8_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_X_VLO_8_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Z_8_KERNEL
#undef CUDA_SORT_ONE_GRID_Z_8_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_8_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Z_8_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Y_8_KERNEL
#undef CUDA_SORT_ONE_GRID_Y_8_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_8_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Y_8_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_X_8_KERNEL
#undef CUDA_SORT_ONE_GRID_X_8_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_X_8_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_X_8_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Z_VLO_6_KERNEL
#undef CUDA_SORT_ONE_GRID_Z_VLO_6_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Y_VLO_6_KERNEL
#undef CUDA_SORT_ONE_GRID_Y_VLO_6_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_X_VLO_6_KERNEL
#undef CUDA_SORT_ONE_GRID_X_VLO_6_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_X_VLO_6_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_X_VLO_6_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Z_6_KERNEL
#undef CUDA_SORT_ONE_GRID_Z_6_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Z_6_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Z_6_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_Y_6_KERNEL
#undef CUDA_SORT_ONE_GRID_Y_6_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_Y_6_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_Y_6_ARGS
#undef DEFINE_CUDA_SORT_ONE_GRID_X_6_KERNEL
#undef CUDA_SORT_ONE_GRID_X_6_ARGS
#undef DEFINE_CUDA_GPU_SORT_ONE_GRID_X_6_KERNEL
#undef CUDA_GPU_SORT_ONE_GRID_X_6_ARGS

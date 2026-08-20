#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "miniblas.kernel_inc.h"

#include "miniblas.kernel.cu"

#include "pscmc_runtime_macros.h"

#define CUDA_BLAS_AXPBY_ENLARGE_ARGS                                                                                   \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((double *)kerstr->b->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],                                   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPBY_ENLARGE_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPBY_ENLARGE_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, b)                                                                                  \
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

#define CUDA_BLAS_AXPBY_SHRINK_ARGS                                                                                    \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((double *)kerstr->b->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],                                   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPBY_SHRINK_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPBY_SHRINK_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, b)                                                                                  \
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

#define CUDA_BLAS_AXPY_ENLARGE_ARGS                                                                                    \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPY_ENLARGE_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPY_ENLARGE_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_AXPY_SHRINK_ARGS                                                                                     \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPY_SHRINK_KERNEL(P)                                                                         \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPY_SHRINK_ARGS)                                                              \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_YISAX_ENLARGE_ARGS                                                                                   \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISAX_ENLARGE_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISAX_ENLARGE_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_YISAX_SHRINK_ARGS                                                                                    \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISAX_SHRINK_KERNEL(P)                                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISAX_SHRINK_ARGS)                                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_SUM_FULL_BLOCK_ARGS                                                                                  \
  ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_sum->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_SUM_FULL_BLOCK_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_SUM_FULL_BLOCK_ARGS)                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rdcd_sum)                                                                           \
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

#define CUDA_BLAS_SUM_ARGS                                                                                             \
  ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_sum->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_SUM_KERNEL(P)                                                                                 \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_SUM_ARGS)                                                                      \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rdcd_sum)                                                                           \
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

#define CUDA_BLAS_DOT_FULL_BLOCK_ARGS                                                                                  \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), ((double *)kerstr->rdcd_sum->d_data),                  \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_DOT_FULL_BLOCK_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_DOT_FULL_BLOCK_ARGS)                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rdcd_sum)                                                                           \
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

#define CUDA_BLAS_DOT_ARGS                                                                                             \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), ((double *)kerstr->rdcd_sum->d_data),                  \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_DOT_KERNEL(P)                                                                                 \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_DOT_ARGS)                                                                      \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rdcd_sum)                                                                           \
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

#define CUDA_BLAS_FINDMAX_FULL_BLOCK_ARGS                                                                              \
  ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_max->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_FINDMAX_FULL_BLOCK_KERNEL(P)                                                                  \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_FINDMAX_FULL_BLOCK_ARGS)                                                       \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rdcd_max)                                                                           \
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

#define CUDA_BLAS_FINDMAX_ARGS                                                                                         \
  ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_max->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_FINDMAX_KERNEL(P)                                                                             \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_FINDMAX_ARGS)                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, rdcd_max)                                                                           \
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

#define CUDA_BLAS_MULXY_FULL_BLOCK_ARGS                                                                                \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],             \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_MULXY_FULL_BLOCK_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_MULXY_FULL_BLOCK_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
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

#define CUDA_BLAS_MULXY_ARGS                                                                                           \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],             \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_MULXY_KERNEL(P)                                                                               \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_MULXY_ARGS)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
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

#define CUDA_BLAS_AXPBY_FULL_BLOCK_ARGS                                                                                \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((double *)kerstr->b->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],                                   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPBY_FULL_BLOCK_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPBY_FULL_BLOCK_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, b)                                                                                  \
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

#define CUDA_BLAS_AXPBY_ARGS                                                                                           \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((double *)kerstr->b->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],                                   \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPBY_KERNEL(P)                                                                               \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPBY_ARGS)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, b)                                                                                  \
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

#define CUDA_BLAS_AXPY_FULL_BLOCK_ARGS                                                                                 \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPY_FULL_BLOCK_KERNEL(P)                                                                     \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPY_FULL_BLOCK_ARGS)                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_AXPY_ARGS                                                                                            \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_AXPY_KERNEL(P)                                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_AXPY_ARGS)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_YISAX_FULL_BLOCK_ARGS                                                                                \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISAX_FULL_BLOCK_KERNEL(P)                                                                    \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISAX_FULL_BLOCK_ARGS)                                                         \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_YISAX_ARGS                                                                                           \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((double *)kerstr->a->h_data))[0],                    \
      (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],                                \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISAX_KERNEL(P)                                                                               \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISAX_ARGS)                                                                    \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_INVY_FULL_BLOCK_ARGS                                                                                 \
  ((double *)kerstr->y->d_data), (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],     \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_INVY_FULL_BLOCK_KERNEL(P)                                                                     \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_INVY_FULL_BLOCK_ARGS)                                                          \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
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

#define CUDA_BLAS_INVY_ARGS                                                                                            \
  ((double *)kerstr->y->d_data), (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],     \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_INVY_KERNEL(P)                                                                                \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_INVY_ARGS)                                                                     \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
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

#define CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_ARGS                                                                    \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), ((double *)kerstr->u->d_data),                         \
      (((double *)kerstr->minus_over_q_e->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],                      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_KERNEL(P)                                                        \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_ARGS)                                             \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, u)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, minus_over_q_e)                                                                     \
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

#define CUDA_BLAS_GET_ITG_POTENTIAL_ARGS                                                                               \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), ((double *)kerstr->u->d_data),                         \
      (((double *)kerstr->minus_over_q_e->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],                      \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_GET_ITG_POTENTIAL_KERNEL(P)                                                                   \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_GET_ITG_POTENTIAL_ARGS)                                                        \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, u)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, minus_over_q_e)                                                                     \
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

#define CUDA_BLAS_YISCONST_FULL_BLOCK_ARGS                                                                             \
  ((double *)kerstr->y->d_data), (((double *)kerstr->a->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],        \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISCONST_FULL_BLOCK_KERNEL(P)                                                                 \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISCONST_FULL_BLOCK_ARGS)                                                      \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_YISCONST_ARGS                                                                                        \
  ((double *)kerstr->y->d_data), (((double *)kerstr->a->h_data))[0], (((long *)kerstr->y_cpu_core->h_data))[0],        \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISCONST_KERNEL(P)                                                                            \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISCONST_ARGS)                                                                 \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, a)                                                                                  \
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

#define CUDA_BLAS_YISZERO_FULL_BLOCK_ARGS                                                                              \
  ((double *)kerstr->y->d_data), (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],     \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISZERO_FULL_BLOCK_KERNEL(P)                                                                  \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISZERO_FULL_BLOCK_ARGS)                                                       \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
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

#define CUDA_BLAS_YISZERO_ARGS                                                                                         \
  ((double *)kerstr->y->d_data), (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],     \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISZERO_KERNEL(P)                                                                             \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISZERO_ARGS)                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
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

#define CUDA_BLAS_MULXY_NUMELE3_ARGS                                                                                   \
  ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data), (((long *)kerstr->y_cpu_core->h_data))[0],             \
      (((long *)kerstr->numvec->h_data))[0], (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], \
      (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],  \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_MULXY_NUMELE3_KERNEL(P)                                                                       \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_MULXY_NUMELE3_ARGS)                                                            \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, x)                                                                                  \
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

#define CUDA_BLAS_YISZERO_SYNCED_ARGS                                                                                  \
  ((double *)kerstr->y->d_data), (((long *)kerstr->y_cpu_core->h_data))[0], (((long *)kerstr->numvec->h_data))[0],     \
      (((long *)kerstr->XLEN->h_data))[0], (((long *)kerstr->YLEN->h_data))[0], (((long *)kerstr->ZLEN->h_data))[0],   \
      (((int *)kerstr->ovlp->h_data))[0], (((long *)kerstr->xblock->h_data))[0],                                       \
      (((long *)kerstr->yblock->h_data))[0], (((long *)kerstr->zblock->h_data))[0],                                    \
      (((int *)kerstr->num_ele->h_data))[0]

#define DEFINE_CUDA_BLAS_YISZERO_SYNCED_KERNEL(P)                                                                      \
  PSCMC_DEFINE_KERNEL_INIT(P)                                                                                          \
  PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(P)                                                                                \
  PSCMC_DEFINE_KERNEL_GET_XLEN(P, IDX_OPT_MAX)                                                                         \
  PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(P, 64)                                                                     \
  PSCMC_DEFINE_KERNEL_EXEC(P, CUDA_BLAS_YISZERO_SYNCED_ARGS)                                                           \
  PSCMC_DEFINE_KERNEL_SET_PARAM(P, y)                                                                                  \
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

extern "C" {
DEFINE_CUDA_BLAS_AXPBY_ENLARGE_KERNEL(cuda_blas_axpby_enlarge)
DEFINE_CUDA_BLAS_AXPBY_SHRINK_KERNEL(cuda_blas_axpby_shrink)
DEFINE_CUDA_BLAS_AXPY_ENLARGE_KERNEL(cuda_blas_axpy_enlarge)
DEFINE_CUDA_BLAS_AXPY_SHRINK_KERNEL(cuda_blas_axpy_shrink)
DEFINE_CUDA_BLAS_YISAX_ENLARGE_KERNEL(cuda_blas_yisax_enlarge)
DEFINE_CUDA_BLAS_YISAX_SHRINK_KERNEL(cuda_blas_yisax_shrink)
DEFINE_CUDA_BLAS_SUM_FULL_BLOCK_KERNEL(cuda_blas_sum_full_block)
DEFINE_CUDA_BLAS_SUM_KERNEL(cuda_blas_sum)
DEFINE_CUDA_BLAS_DOT_FULL_BLOCK_KERNEL(cuda_blas_dot_full_block)
DEFINE_CUDA_BLAS_DOT_KERNEL(cuda_blas_dot)
DEFINE_CUDA_BLAS_FINDMAX_FULL_BLOCK_KERNEL(cuda_blas_findmax_full_block)
DEFINE_CUDA_BLAS_FINDMAX_KERNEL(cuda_blas_findmax)
DEFINE_CUDA_BLAS_MULXY_FULL_BLOCK_KERNEL(cuda_blas_mulxy_full_block)
DEFINE_CUDA_BLAS_MULXY_KERNEL(cuda_blas_mulxy)
DEFINE_CUDA_BLAS_AXPBY_FULL_BLOCK_KERNEL(cuda_blas_axpby_full_block)
DEFINE_CUDA_BLAS_AXPBY_KERNEL(cuda_blas_axpby)
DEFINE_CUDA_BLAS_AXPY_FULL_BLOCK_KERNEL(cuda_blas_axpy_full_block)
DEFINE_CUDA_BLAS_AXPY_KERNEL(cuda_blas_axpy)
DEFINE_CUDA_BLAS_YISAX_FULL_BLOCK_KERNEL(cuda_blas_yisax_full_block)
DEFINE_CUDA_BLAS_YISAX_KERNEL(cuda_blas_yisax)
DEFINE_CUDA_BLAS_INVY_FULL_BLOCK_KERNEL(cuda_blas_invy_full_block)
DEFINE_CUDA_BLAS_INVY_KERNEL(cuda_blas_invy)
DEFINE_CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_KERNEL(cuda_blas_get_ITG_Potential_full_block)
DEFINE_CUDA_BLAS_GET_ITG_POTENTIAL_KERNEL(cuda_blas_get_ITG_Potential)
DEFINE_CUDA_BLAS_YISCONST_FULL_BLOCK_KERNEL(cuda_blas_yisconst_full_block)
DEFINE_CUDA_BLAS_YISCONST_KERNEL(cuda_blas_yisconst)
DEFINE_CUDA_BLAS_YISZERO_FULL_BLOCK_KERNEL(cuda_blas_yiszero_full_block)
DEFINE_CUDA_BLAS_YISZERO_KERNEL(cuda_blas_yiszero)
DEFINE_CUDA_BLAS_MULXY_NUMELE3_KERNEL(cuda_blas_mulxy_numele3)
DEFINE_CUDA_BLAS_YISZERO_SYNCED_KERNEL(cuda_blas_yiszero_synced)
}

#undef DEFINE_CUDA_BLAS_AXPBY_ENLARGE_KERNEL
#undef CUDA_BLAS_AXPBY_ENLARGE_ARGS
#undef DEFINE_CUDA_BLAS_AXPBY_SHRINK_KERNEL
#undef CUDA_BLAS_AXPBY_SHRINK_ARGS
#undef DEFINE_CUDA_BLAS_AXPY_ENLARGE_KERNEL
#undef CUDA_BLAS_AXPY_ENLARGE_ARGS
#undef DEFINE_CUDA_BLAS_AXPY_SHRINK_KERNEL
#undef CUDA_BLAS_AXPY_SHRINK_ARGS
#undef DEFINE_CUDA_BLAS_YISAX_ENLARGE_KERNEL
#undef CUDA_BLAS_YISAX_ENLARGE_ARGS
#undef DEFINE_CUDA_BLAS_YISAX_SHRINK_KERNEL
#undef CUDA_BLAS_YISAX_SHRINK_ARGS
#undef DEFINE_CUDA_BLAS_SUM_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_SUM_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_SUM_KERNEL
#undef CUDA_BLAS_SUM_ARGS
#undef DEFINE_CUDA_BLAS_DOT_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_DOT_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_DOT_KERNEL
#undef CUDA_BLAS_DOT_ARGS
#undef DEFINE_CUDA_BLAS_FINDMAX_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_FINDMAX_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_FINDMAX_KERNEL
#undef CUDA_BLAS_FINDMAX_ARGS
#undef DEFINE_CUDA_BLAS_MULXY_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_MULXY_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_MULXY_KERNEL
#undef CUDA_BLAS_MULXY_ARGS
#undef DEFINE_CUDA_BLAS_AXPBY_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_AXPBY_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_AXPBY_KERNEL
#undef CUDA_BLAS_AXPBY_ARGS
#undef DEFINE_CUDA_BLAS_AXPY_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_AXPY_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_AXPY_KERNEL
#undef CUDA_BLAS_AXPY_ARGS
#undef DEFINE_CUDA_BLAS_YISAX_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_YISAX_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_YISAX_KERNEL
#undef CUDA_BLAS_YISAX_ARGS
#undef DEFINE_CUDA_BLAS_INVY_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_INVY_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_INVY_KERNEL
#undef CUDA_BLAS_INVY_ARGS
#undef DEFINE_CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_GET_ITG_POTENTIAL_KERNEL
#undef CUDA_BLAS_GET_ITG_POTENTIAL_ARGS
#undef DEFINE_CUDA_BLAS_YISCONST_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_YISCONST_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_YISCONST_KERNEL
#undef CUDA_BLAS_YISCONST_ARGS
#undef DEFINE_CUDA_BLAS_YISZERO_FULL_BLOCK_KERNEL
#undef CUDA_BLAS_YISZERO_FULL_BLOCK_ARGS
#undef DEFINE_CUDA_BLAS_YISZERO_KERNEL
#undef CUDA_BLAS_YISZERO_ARGS
#undef DEFINE_CUDA_BLAS_MULXY_NUMELE3_KERNEL
#undef CUDA_BLAS_MULXY_NUMELE3_ARGS
#undef DEFINE_CUDA_BLAS_YISZERO_SYNCED_KERNEL
#undef CUDA_BLAS_YISZERO_SYNCED_ARGS

#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

#define DECL_CUDA_BLAS_AXPBY_ENLARGE_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, b)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPBY_SHRINK_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, b)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPY_ENLARGE_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPY_SHRINK_KERNEL(P)                                                                           \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISAX_ENLARGE_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISAX_SHRINK_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_SUM_FULL_BLOCK_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rdcd_sum)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_SUM_KERNEL(P)                                                                                   \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rdcd_sum)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_DOT_FULL_BLOCK_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rdcd_sum)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_DOT_KERNEL(P)                                                                                   \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rdcd_sum)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_FINDMAX_FULL_BLOCK_KERNEL(P)                                                                    \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rdcd_max)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_FINDMAX_KERNEL(P)                                                                               \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rdcd_max)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_MULXY_FULL_BLOCK_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_MULXY_KERNEL(P)                                                                                 \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPBY_FULL_BLOCK_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, b)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPBY_KERNEL(P)                                                                                 \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, b)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPY_FULL_BLOCK_KERNEL(P)                                                                       \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_AXPY_KERNEL(P)                                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISAX_FULL_BLOCK_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISAX_KERNEL(P)                                                                                 \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_INVY_FULL_BLOCK_KERNEL(P)                                                                       \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_INVY_KERNEL(P)                                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_KERNEL(P)                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, u)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, minus_over_q_e)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_GET_ITG_POTENTIAL_KERNEL(P)                                                                     \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, u)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, minus_over_q_e)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISCONST_FULL_BLOCK_KERNEL(P)                                                                   \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISCONST_KERNEL(P)                                                                              \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, a)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISZERO_FULL_BLOCK_KERNEL(P)                                                                    \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISZERO_KERNEL(P)                                                                               \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_MULXY_NUMELE3_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

#define DECL_CUDA_BLAS_YISZERO_SYNCED_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)

DECL_CUDA_BLAS_AXPBY_ENLARGE_KERNEL(cuda_blas_axpby_enlarge)
DECL_CUDA_BLAS_AXPBY_SHRINK_KERNEL(cuda_blas_axpby_shrink)
DECL_CUDA_BLAS_AXPY_ENLARGE_KERNEL(cuda_blas_axpy_enlarge)
DECL_CUDA_BLAS_AXPY_SHRINK_KERNEL(cuda_blas_axpy_shrink)
DECL_CUDA_BLAS_YISAX_ENLARGE_KERNEL(cuda_blas_yisax_enlarge)
DECL_CUDA_BLAS_YISAX_SHRINK_KERNEL(cuda_blas_yisax_shrink)
DECL_CUDA_BLAS_SUM_FULL_BLOCK_KERNEL(cuda_blas_sum_full_block)
DECL_CUDA_BLAS_SUM_KERNEL(cuda_blas_sum)
DECL_CUDA_BLAS_DOT_FULL_BLOCK_KERNEL(cuda_blas_dot_full_block)
DECL_CUDA_BLAS_DOT_KERNEL(cuda_blas_dot)
DECL_CUDA_BLAS_FINDMAX_FULL_BLOCK_KERNEL(cuda_blas_findmax_full_block)
DECL_CUDA_BLAS_FINDMAX_KERNEL(cuda_blas_findmax)
DECL_CUDA_BLAS_MULXY_FULL_BLOCK_KERNEL(cuda_blas_mulxy_full_block)
DECL_CUDA_BLAS_MULXY_KERNEL(cuda_blas_mulxy)
DECL_CUDA_BLAS_AXPBY_FULL_BLOCK_KERNEL(cuda_blas_axpby_full_block)
DECL_CUDA_BLAS_AXPBY_KERNEL(cuda_blas_axpby)
DECL_CUDA_BLAS_AXPY_FULL_BLOCK_KERNEL(cuda_blas_axpy_full_block)
DECL_CUDA_BLAS_AXPY_KERNEL(cuda_blas_axpy)
DECL_CUDA_BLAS_YISAX_FULL_BLOCK_KERNEL(cuda_blas_yisax_full_block)
DECL_CUDA_BLAS_YISAX_KERNEL(cuda_blas_yisax)
DECL_CUDA_BLAS_INVY_FULL_BLOCK_KERNEL(cuda_blas_invy_full_block)
DECL_CUDA_BLAS_INVY_KERNEL(cuda_blas_invy)
DECL_CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_KERNEL(cuda_blas_get_ITG_Potential_full_block)
DECL_CUDA_BLAS_GET_ITG_POTENTIAL_KERNEL(cuda_blas_get_ITG_Potential)
DECL_CUDA_BLAS_YISCONST_FULL_BLOCK_KERNEL(cuda_blas_yisconst_full_block)
DECL_CUDA_BLAS_YISCONST_KERNEL(cuda_blas_yisconst)
DECL_CUDA_BLAS_YISZERO_FULL_BLOCK_KERNEL(cuda_blas_yiszero_full_block)
DECL_CUDA_BLAS_YISZERO_KERNEL(cuda_blas_yiszero)
DECL_CUDA_BLAS_MULXY_NUMELE3_KERNEL(cuda_blas_mulxy_numele3)
DECL_CUDA_BLAS_YISZERO_SYNCED_KERNEL(cuda_blas_yiszero_synced)

#undef DECL_CUDA_BLAS_AXPBY_ENLARGE_KERNEL
#undef DECL_CUDA_BLAS_AXPBY_SHRINK_KERNEL
#undef DECL_CUDA_BLAS_AXPY_ENLARGE_KERNEL
#undef DECL_CUDA_BLAS_AXPY_SHRINK_KERNEL
#undef DECL_CUDA_BLAS_YISAX_ENLARGE_KERNEL
#undef DECL_CUDA_BLAS_YISAX_SHRINK_KERNEL
#undef DECL_CUDA_BLAS_SUM_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_SUM_KERNEL
#undef DECL_CUDA_BLAS_DOT_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_DOT_KERNEL
#undef DECL_CUDA_BLAS_FINDMAX_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_FINDMAX_KERNEL
#undef DECL_CUDA_BLAS_MULXY_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_MULXY_KERNEL
#undef DECL_CUDA_BLAS_AXPBY_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_AXPBY_KERNEL
#undef DECL_CUDA_BLAS_AXPY_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_AXPY_KERNEL
#undef DECL_CUDA_BLAS_YISAX_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_YISAX_KERNEL
#undef DECL_CUDA_BLAS_INVY_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_INVY_KERNEL
#undef DECL_CUDA_BLAS_GET_ITG_POTENTIAL_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_GET_ITG_POTENTIAL_KERNEL
#undef DECL_CUDA_BLAS_YISCONST_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_YISCONST_KERNEL
#undef DECL_CUDA_BLAS_YISZERO_FULL_BLOCK_KERNEL
#undef DECL_CUDA_BLAS_YISZERO_KERNEL
#undef DECL_CUDA_BLAS_MULXY_NUMELE3_KERNEL
#undef DECL_CUDA_BLAS_YISZERO_SYNCED_KERNEL

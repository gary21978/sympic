#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

#define DECL_CUDA_CU_SWAP_R_8_KERNEL(P)                                                                                \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, the_dir_num)                                                                          \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XYZLEN)

#define DECL_CUDA_CU_SWAP_L_8_KERNEL(P)                                                                                \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, the_dir_num)                                                                          \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XYZLEN)

#define DECL_CUDA_CU_SWAP_R_6_KERNEL(P)                                                                                \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, the_dir_num)                                                                          \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XYZLEN)

#define DECL_CUDA_CU_SWAP_L_6_KERNEL(P)                                                                                \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, the_dir_num)                                                                          \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XYZLEN)

#define DECL_CUDA_SORT_ONE_GRID_Z_VLO_8_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Y_VLO_8_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_X_VLO_8_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_X_VLO_8_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Z_8_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Z_8_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Y_8_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Y_8_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_X_8_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_X_8_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Z_VLO_6_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Y_VLO_6_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_X_VLO_6_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_X_VLO_6_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Z_6_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Z_6_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_Y_6_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_Y_6_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_SORT_ONE_GRID_X_6_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_GPU_SORT_ONE_GRID_X_6_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, adjoint_vec_pids)                                                                     \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

DECL_CUDA_CU_SWAP_R_8_KERNEL(cuda_cu_swap_r_8)
DECL_CUDA_CU_SWAP_L_8_KERNEL(cuda_cu_swap_l_8)
DECL_CUDA_CU_SWAP_R_6_KERNEL(cuda_cu_swap_r_6)
DECL_CUDA_CU_SWAP_L_6_KERNEL(cuda_cu_swap_l_6)
DECL_CUDA_SORT_ONE_GRID_Z_VLO_8_KERNEL(cuda_sort_one_grid_z_vlo_8)
DECL_CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_KERNEL(cuda_gpu_sort_one_grid_z_vlo_8)
DECL_CUDA_SORT_ONE_GRID_Y_VLO_8_KERNEL(cuda_sort_one_grid_y_vlo_8)
DECL_CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_KERNEL(cuda_gpu_sort_one_grid_y_vlo_8)
DECL_CUDA_SORT_ONE_GRID_X_VLO_8_KERNEL(cuda_sort_one_grid_x_vlo_8)
DECL_CUDA_GPU_SORT_ONE_GRID_X_VLO_8_KERNEL(cuda_gpu_sort_one_grid_x_vlo_8)
DECL_CUDA_SORT_ONE_GRID_Z_8_KERNEL(cuda_sort_one_grid_z_8)
DECL_CUDA_GPU_SORT_ONE_GRID_Z_8_KERNEL(cuda_gpu_sort_one_grid_z_8)
DECL_CUDA_SORT_ONE_GRID_Y_8_KERNEL(cuda_sort_one_grid_y_8)
DECL_CUDA_GPU_SORT_ONE_GRID_Y_8_KERNEL(cuda_gpu_sort_one_grid_y_8)
DECL_CUDA_SORT_ONE_GRID_X_8_KERNEL(cuda_sort_one_grid_x_8)
DECL_CUDA_GPU_SORT_ONE_GRID_X_8_KERNEL(cuda_gpu_sort_one_grid_x_8)
DECL_CUDA_SORT_ONE_GRID_Z_VLO_6_KERNEL(cuda_sort_one_grid_z_vlo_6)
DECL_CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_KERNEL(cuda_gpu_sort_one_grid_z_vlo_6)
DECL_CUDA_SORT_ONE_GRID_Y_VLO_6_KERNEL(cuda_sort_one_grid_y_vlo_6)
DECL_CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_KERNEL(cuda_gpu_sort_one_grid_y_vlo_6)
DECL_CUDA_SORT_ONE_GRID_X_VLO_6_KERNEL(cuda_sort_one_grid_x_vlo_6)
DECL_CUDA_GPU_SORT_ONE_GRID_X_VLO_6_KERNEL(cuda_gpu_sort_one_grid_x_vlo_6)
DECL_CUDA_SORT_ONE_GRID_Z_6_KERNEL(cuda_sort_one_grid_z_6)
DECL_CUDA_GPU_SORT_ONE_GRID_Z_6_KERNEL(cuda_gpu_sort_one_grid_z_6)
DECL_CUDA_SORT_ONE_GRID_Y_6_KERNEL(cuda_sort_one_grid_y_6)
DECL_CUDA_GPU_SORT_ONE_GRID_Y_6_KERNEL(cuda_gpu_sort_one_grid_y_6)
DECL_CUDA_SORT_ONE_GRID_X_6_KERNEL(cuda_sort_one_grid_x_6)
DECL_CUDA_GPU_SORT_ONE_GRID_X_6_KERNEL(cuda_gpu_sort_one_grid_x_6)

#undef DECL_CUDA_CU_SWAP_R_8_KERNEL
#undef DECL_CUDA_CU_SWAP_L_8_KERNEL
#undef DECL_CUDA_CU_SWAP_R_6_KERNEL
#undef DECL_CUDA_CU_SWAP_L_6_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Z_VLO_8_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Z_VLO_8_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Y_VLO_8_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Y_VLO_8_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_X_VLO_8_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_X_VLO_8_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Z_8_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Z_8_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Y_8_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Y_8_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_X_8_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_X_8_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Z_VLO_6_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Z_VLO_6_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Y_VLO_6_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Y_VLO_6_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_X_VLO_6_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_X_VLO_6_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Z_6_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Z_6_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_Y_6_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_Y_6_KERNEL
#undef DECL_CUDA_SORT_ONE_GRID_X_6_KERNEL
#undef DECL_CUDA_GPU_SORT_ONE_GRID_X_6_KERNEL

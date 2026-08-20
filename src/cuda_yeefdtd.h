#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

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
#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

#define DECL_CUDA_YEE_CURL_R_KERNEL(P)                                                                                 \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutE1)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inB0)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DT)

#define DECL_CUDA_GEO_YEE_CURL_L_KERNEL(P)                                                                             \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutE1)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inB0)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, y_cpu_core)                                                                           \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DT)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Z)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Y)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_X)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, x0)

DECL_CUDA_YEE_CURL_R_KERNEL(cuda_YEE_CURL_R)
DECL_CUDA_GEO_YEE_CURL_L_KERNEL(cuda_GEO_YEE_CURL_L)

#undef DECL_CUDA_YEE_CURL_R_KERNEL
#undef DECL_CUDA_GEO_YEE_CURL_L_KERNEL
#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

#define DECL_CUDA_GEO_NR_BFIELD_PUSHJ_VLO_KERNEL(P)                                                                    \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zoffset)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldE)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldB)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldB1)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, FoutJ)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_X)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Y)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Z)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Mass0)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Charge0)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Deltat)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Tori_X0)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, r0)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, MIN_R0)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Q0)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, b0)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zmid)

DECL_CUDA_GEO_NR_BFIELD_PUSHJ_VLO_KERNEL(cuda_geo_nr_Bfield_pushJ_vlo)

#undef DECL_CUDA_GEO_NR_BFIELD_PUSHJ_VLO_KERNEL
#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

#define DECL_CUDA_MERGE_OVLP_M2O_ONCE_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp0)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp1)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp2)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp3)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp4)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp5)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp6)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp7)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp8)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp9)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp10)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp11)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp12)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp14)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp15)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp16)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp17)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp18)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp19)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp20)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp21)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp22)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp23)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp24)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp25)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp26)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlps)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_MERGE_OVLP_M2O_KERNEL(P)                                                                             \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlpindex)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_MERGE_OVLP_O2M_ONCE_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp0)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp1)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp2)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp3)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp4)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp5)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp6)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp7)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp8)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp9)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp10)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp11)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp12)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp14)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp15)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp16)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp17)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp18)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp19)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp20)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp21)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp22)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp23)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp24)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp25)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp26)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_KERNEL(P)                                                                  \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlps)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_MERGE_OVLP_O2M_KERNEL(P)                                                                             \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlpindex)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_SYNC_OVLP_M2O_ONCE_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp0)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp1)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp2)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp3)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp4)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp5)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp6)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp7)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp8)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp9)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp10)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp11)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp12)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp14)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp15)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp16)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp17)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp18)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp19)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp20)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp21)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp22)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp23)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp24)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp25)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp26)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_KERNEL(P)                                                                   \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlps)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_SYNC_OVLP_M2O_KERNEL(P)                                                                              \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlpindex)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_SYNC_OVLP_O2M_ONCE_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp0)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp1)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp2)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp3)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp4)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp5)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp6)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp7)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp8)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp9)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp10)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp11)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp12)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp14)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp15)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp16)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp17)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp18)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp19)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp20)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp21)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp22)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp23)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp24)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp25)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp26)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_KERNEL(P)                                                                   \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlps)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

#define DECL_CUDA_SYNC_OVLP_O2M_KERNEL(P)                                                                              \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecmain)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, vecovlp)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlpindex)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, yblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, zblock)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)

DECL_CUDA_MERGE_OVLP_M2O_ONCE_KERNEL(cuda_merge_ovlp_m2o_once)
DECL_CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_KERNEL(cuda_merge_ovlp_m2o_all_in_one)
DECL_CUDA_MERGE_OVLP_M2O_KERNEL(cuda_merge_ovlp_m2o)
DECL_CUDA_MERGE_OVLP_O2M_ONCE_KERNEL(cuda_merge_ovlp_o2m_once)
DECL_CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_KERNEL(cuda_merge_ovlp_o2m_all_in_one)
DECL_CUDA_MERGE_OVLP_O2M_KERNEL(cuda_merge_ovlp_o2m)
DECL_CUDA_SYNC_OVLP_M2O_ONCE_KERNEL(cuda_sync_ovlp_m2o_once)
DECL_CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_KERNEL(cuda_sync_ovlp_m2o_all_in_one)
DECL_CUDA_SYNC_OVLP_M2O_KERNEL(cuda_sync_ovlp_m2o)
DECL_CUDA_SYNC_OVLP_O2M_ONCE_KERNEL(cuda_sync_ovlp_o2m_once)
DECL_CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_KERNEL(cuda_sync_ovlp_o2m_all_in_one)
DECL_CUDA_SYNC_OVLP_O2M_KERNEL(cuda_sync_ovlp_o2m)

#undef DECL_CUDA_MERGE_OVLP_M2O_ONCE_KERNEL
#undef DECL_CUDA_MERGE_OVLP_M2O_ALL_IN_ONE_KERNEL
#undef DECL_CUDA_MERGE_OVLP_M2O_KERNEL
#undef DECL_CUDA_MERGE_OVLP_O2M_ONCE_KERNEL
#undef DECL_CUDA_MERGE_OVLP_O2M_ALL_IN_ONE_KERNEL
#undef DECL_CUDA_MERGE_OVLP_O2M_KERNEL
#undef DECL_CUDA_SYNC_OVLP_M2O_ONCE_KERNEL
#undef DECL_CUDA_SYNC_OVLP_M2O_ALL_IN_ONE_KERNEL
#undef DECL_CUDA_SYNC_OVLP_M2O_KERNEL
#undef DECL_CUDA_SYNC_OVLP_O2M_ONCE_KERNEL
#undef DECL_CUDA_SYNC_OVLP_O2M_ALL_IN_ONE_KERNEL
#undef DECL_CUDA_SYNC_OVLP_O2M_KERNEL
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
#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

#define DECL_CUDA_MOVE_BACK_KERNEL_8_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

#define DECL_CUDA_MOVE_BACK_KERNEL_6_KERNEL(P)                                                                         \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)

DECL_CUDA_MOVE_BACK_KERNEL_8_KERNEL(cuda_move_back_kernel_8)
DECL_CUDA_MOVE_BACK_KERNEL_6_KERNEL(cuda_move_back_kernel_6)

#undef DECL_CUDA_MOVE_BACK_KERNEL_8_KERNEL
#undef DECL_CUDA_MOVE_BACK_KERNEL_6_KERNEL
#include "pubdefs.h"

#include "pscmc_runtime_macros.h"

#define DECL_CUDA_DUMP_ENE_NUM_KERNEL(P)                                                                               \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inoutput)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, xyzw)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_xyzw)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldE)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, fieldB)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, FoutJ)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, FoutEN)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, XLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, YLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ZLEN)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, ovlp)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, numvec)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, num_ele)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, grid_cache_len)                                                                       \
  PSCMC_DECL_KERNEL_SET_PARAM(P, cu_cache_length)                                                                      \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Mass)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Charge)                                                                               \
  PSCMC_DECL_KERNEL_SET_PARAM(P, SPEC)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, NUM_SPEC)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_X)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Y)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DELTA_Z)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Deltat)

DECL_CUDA_DUMP_ENE_NUM_KERNEL(cuda_dump_ene_num)

#undef DECL_CUDA_DUMP_ENE_NUM_KERNEL
#include "pubdefs.h"

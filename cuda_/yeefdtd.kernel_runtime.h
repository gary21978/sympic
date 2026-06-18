#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

#define DECL_CUDA_KGM_EQN_CORE_KERNEL(P)                                                                               \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, extA0)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, extA1)                                                                                \
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
  PSCMC_DECL_KERNEL_SET_PARAM(P, M)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Q)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DX)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, GEXT)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, rfz0)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, g_beg)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, swap_input)

#define DECL_CUDA_KGM_CALC_RHO_KERNEL(P)                                                                               \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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
  PSCMC_DECL_KERNEL_SET_PARAM(P, M)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Q)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DX)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, refz0)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, q)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, dtodx)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, mode)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, swap_input)

#define DECL_CUDA_PML_FDTD_CURL_BWD_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outPMLEB)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inPMLEB)                                                                              \
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
  PSCMC_DECL_KERNEL_SET_PARAM(P, M)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Q)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DX)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DY)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DZ)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, abc_dir)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, level)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, pml_m)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, max_sigma)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, allxmax)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, allymax)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, allzmax)

#define DECL_CUDA_PML_FDTD_CURL_FWD_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outPMLEB)                                                                             \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inPMLEB)                                                                              \
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
  PSCMC_DECL_KERNEL_SET_PARAM(P, M)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, Q)                                                                                    \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DX)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DY)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, DZ)                                                                                   \
  PSCMC_DECL_KERNEL_SET_PARAM(P, abc_dir)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, level)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, pml_m)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, max_sigma)                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, allxmax)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, allymax)                                                                              \
  PSCMC_DECL_KERNEL_SET_PARAM(P, allzmax)

#define DECL_CUDA_MERGE_CURRENT_KERNEL(P)                                                                              \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_MERGE_CURRENT_2_KERNEL(P)                                                                            \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_DIV_FWD_4TH_KERNEL(P)                                                                       \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_DIV_FWD_KERNEL(P)                                                                           \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_DIV_BWD_4TH_KERNEL(P)                                                                       \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_DIV_BWD_KERNEL(P)                                                                           \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_FWD_4TH_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_FWD_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_BWD_4TH_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_BWD_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_GRAD_FWD_4TH_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_GRAD_FWD_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_GRAD_BWD_4TH_KERNEL(P)                                                                      \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_GRAD_BWD_KERNEL(P)                                                                          \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_B_4TH_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_B_KERNEL(P)                                                                            \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_E_4TH_KERNEL(P)                                                                        \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

#define DECL_CUDA_YEE_FDTD_CURL_E_KERNEL(P)                                                                            \
  PSCMC_DECL_KERNEL_INIT(P)                                                                                            \
  PSCMC_DECL_KERNEL_GET_STRUCT_LEN(P)                                                                                  \
  PSCMC_DECL_KERNEL_GET_XLEN(P)                                                                                        \
  PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(P)                                                                           \
  PSCMC_DECL_KERNEL_EXEC(P)                                                                                            \
  PSCMC_DECL_KERNEL_SET_PARAM(P, outEB)                                                                                \
  PSCMC_DECL_KERNEL_SET_PARAM(P, inEB)                                                                                 \
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

DECL_CUDA_KGM_EQN_CORE_KERNEL(cuda_kgm_eqn_core)
DECL_CUDA_KGM_CALC_RHO_KERNEL(cuda_kgm_calc_rho)
DECL_CUDA_PML_FDTD_CURL_BWD_KERNEL(cuda_PML_FDTD_CURL_BWD)
DECL_CUDA_PML_FDTD_CURL_FWD_KERNEL(cuda_PML_FDTD_CURL_FWD)
DECL_CUDA_MERGE_CURRENT_KERNEL(cuda_merge_current)
DECL_CUDA_MERGE_CURRENT_2_KERNEL(cuda_merge_current_2)
DECL_CUDA_YEE_FDTD_DIV_FWD_4TH_KERNEL(cuda_Yee_FDTD_Div_FWD_4th)
DECL_CUDA_YEE_FDTD_DIV_FWD_KERNEL(cuda_Yee_FDTD_Div_FWD)
DECL_CUDA_YEE_FDTD_DIV_BWD_4TH_KERNEL(cuda_Yee_FDTD_Div_BWD_4th)
DECL_CUDA_YEE_FDTD_DIV_BWD_KERNEL(cuda_Yee_FDTD_Div_BWD)
DECL_CUDA_YEE_FDTD_CURL_FWD_4TH_KERNEL(cuda_Yee_FDTD_Curl_FWD_4th)
DECL_CUDA_YEE_FDTD_CURL_FWD_KERNEL(cuda_Yee_FDTD_Curl_FWD)
DECL_CUDA_YEE_FDTD_CURL_BWD_4TH_KERNEL(cuda_Yee_FDTD_Curl_BWD_4th)
DECL_CUDA_YEE_FDTD_CURL_BWD_KERNEL(cuda_Yee_FDTD_Curl_BWD)
DECL_CUDA_YEE_FDTD_GRAD_FWD_4TH_KERNEL(cuda_Yee_FDTD_Grad_FWD_4th)
DECL_CUDA_YEE_FDTD_GRAD_FWD_KERNEL(cuda_Yee_FDTD_Grad_FWD)
DECL_CUDA_YEE_FDTD_GRAD_BWD_4TH_KERNEL(cuda_Yee_FDTD_Grad_BWD_4th)
DECL_CUDA_YEE_FDTD_GRAD_BWD_KERNEL(cuda_Yee_FDTD_Grad_BWD)
DECL_CUDA_YEE_FDTD_CURL_B_4TH_KERNEL(cuda_Yee_FDTD_Curl_B_4th)
DECL_CUDA_YEE_FDTD_CURL_B_KERNEL(cuda_Yee_FDTD_Curl_B)
DECL_CUDA_YEE_FDTD_CURL_E_4TH_KERNEL(cuda_Yee_FDTD_Curl_E_4th)
DECL_CUDA_YEE_FDTD_CURL_E_KERNEL(cuda_Yee_FDTD_Curl_E)

#undef DECL_CUDA_KGM_EQN_CORE_KERNEL
#undef DECL_CUDA_KGM_CALC_RHO_KERNEL
#undef DECL_CUDA_PML_FDTD_CURL_BWD_KERNEL
#undef DECL_CUDA_PML_FDTD_CURL_FWD_KERNEL
#undef DECL_CUDA_MERGE_CURRENT_KERNEL
#undef DECL_CUDA_MERGE_CURRENT_2_KERNEL
#undef DECL_CUDA_YEE_FDTD_DIV_FWD_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_DIV_FWD_KERNEL
#undef DECL_CUDA_YEE_FDTD_DIV_BWD_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_DIV_BWD_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_FWD_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_FWD_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_BWD_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_BWD_KERNEL
#undef DECL_CUDA_YEE_FDTD_GRAD_FWD_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_GRAD_FWD_KERNEL
#undef DECL_CUDA_YEE_FDTD_GRAD_BWD_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_GRAD_BWD_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_B_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_B_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_E_4TH_KERNEL
#undef DECL_CUDA_YEE_FDTD_CURL_E_KERNEL

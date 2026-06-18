#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

#define DECL_CUDA_YEE_FDTD_W04_2_KERNEL(P)                                                                             \
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

#define DECL_CUDA_YEE_FDTD_W04_1_KERNEL(P)                                                                             \
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

#define DECL_CUDA_YEE_FDTD_W04_0_KERNEL(P)                                                                             \
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

DECL_CUDA_YEE_FDTD_W04_2_KERNEL(cuda_Yee_FDTD_W04_2)
DECL_CUDA_YEE_FDTD_W04_1_KERNEL(cuda_Yee_FDTD_W04_1)
DECL_CUDA_YEE_FDTD_W04_0_KERNEL(cuda_Yee_FDTD_W04_0)

#undef DECL_CUDA_YEE_FDTD_W04_2_KERNEL
#undef DECL_CUDA_YEE_FDTD_W04_1_KERNEL
#undef DECL_CUDA_YEE_FDTD_W04_0_KERNEL

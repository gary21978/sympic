#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

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

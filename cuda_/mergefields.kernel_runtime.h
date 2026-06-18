#include "pubdefs.h"

#include "cuda_/pscmc_runtime_macros.h"

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

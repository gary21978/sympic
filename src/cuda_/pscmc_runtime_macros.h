#ifndef PSCMC_RUNTIME_MACROS_H
#define PSCMC_RUNTIME_MACROS_H

// ============================================================================
// Common CUDA PSCMC runtime wrapper macros.
// These generate the repetitive init/get/exec/set_parameter boilerplate for
// each kernel variant from a prefix and a per-file kernel argument list.
// ============================================================================

// ---------------------------------------------------------------------------
// Function definitions (used in .cu files)
// ---------------------------------------------------------------------------
#define PSCMC_DEFINE_KERNEL_INIT(PREFIX)                                                                               \
  int PREFIX##_init(cuda_pscmc_env *pe, PREFIX##_struct *kerstr) {                                                     \
    kerstr->pe = pe;                                                                                                   \
    return 0;                                                                                                          \
  }

#define PSCMC_DEFINE_KERNEL_GET_STRUCT_LEN(PREFIX)                                                                     \
  void PREFIX##_get_struct_len(size_t *len) {                                                                          \
    len[0] = sizeof(PREFIX##_struct);                                                                                  \
  }

#define PSCMC_DEFINE_KERNEL_GET_XLEN(PREFIX, XLEN)                                                                     \
  int PREFIX##_get_xlen() {                                                                                            \
    return XLEN;                                                                                                       \
  }

#define PSCMC_DEFINE_KERNEL_GET_NUM_COMPUTE_UNITS(PREFIX, N)                                                           \
  int PREFIX##_get_num_compute_units(PREFIX##_struct *kerstr) {                                                        \
    (void)kerstr;                                                                                                      \
    return N;                                                                                                          \
  }

#define PSCMC_DEFINE_KERNEL_EXEC(PREFIX, KERNEL_ARGS)                                                                  \
  int PREFIX##_exec(PREFIX##_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {                   \
    cudaSetDevice(kerstr->pe->device_id);                                                                              \
    if (scmc_internal_g_ylen < 65536) {                                                                                \
      PREFIX<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(KERNEL_ARGS);                                             \
    } else {                                                                                                           \
      dim3 multiylen = 1;                                                                                              \
      multiylen.x = 64;                                                                                                \
      multiylen.y = scmc_internal_g_ylen / 64;                                                                         \
      int rest = scmc_internal_g_ylen % 64;                                                                            \
      if (rest != 0) {                                                                                                 \
        fprintf(stderr,                                                                                                \
                "Warning: if __ylen>=65536 then __ylen must be "                                                       \
                "divisible by 64, __ylen=%ld\n",                                                                       \
                scmc_internal_g_ylen);                                                                                 \
      }                                                                                                                \
      PREFIX<<<multiylen, scmc_internal_g_xlen>>>(KERNEL_ARGS);                                                        \
    }                                                                                                                  \
    cudaError_t err = cudaGetLastError();                                                                              \
    ERROPT(err, "Error in exec" #PREFIX);                                                                              \
    return 0;                                                                                                          \
  }

#define PSCMC_DEFINE_KERNEL_SET_PARAM(PREFIX, FIELD)                                                                   \
  int PREFIX##_scmc_set_parameter_##FIELD(PREFIX##_struct *kerstr, cuda_pscmc_mem *pm) {                               \
    kerstr->FIELD = pm;                                                                                                \
    return 0;                                                                                                          \
  }

// ---------------------------------------------------------------------------
// Function declarations (used in .h files)
// ---------------------------------------------------------------------------
#define PSCMC_DECL_KERNEL_INIT(PREFIX) int PREFIX##_init(cuda_pscmc_env *pe, PREFIX##_struct *kerstr);

#define PSCMC_DECL_KERNEL_GET_STRUCT_LEN(PREFIX) void PREFIX##_get_struct_len(size_t *len);

#define PSCMC_DECL_KERNEL_GET_XLEN(PREFIX) int PREFIX##_get_xlen();

#define PSCMC_DECL_KERNEL_GET_NUM_COMPUTE_UNITS(PREFIX) int PREFIX##_get_num_compute_units(PREFIX##_struct *kerstr);

#define PSCMC_DECL_KERNEL_EXEC(PREFIX)                                                                                 \
  int PREFIX##_exec(PREFIX##_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen);

#define PSCMC_DECL_KERNEL_SET_PARAM(PREFIX, FIELD)                                                                     \
  int PREFIX##_scmc_set_parameter_##FIELD(PREFIX##_struct *kerstr, cuda_pscmc_mem *pm);

#endif // PSCMC_RUNTIME_MACROS_H

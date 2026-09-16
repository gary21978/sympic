typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

} cuda_move_back_kernel_8_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

} cuda_move_back_kernel_6_struct;

typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_dump_ene_num_struct;

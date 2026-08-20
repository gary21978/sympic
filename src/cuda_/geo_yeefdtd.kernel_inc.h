typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutE1;

  cuda_pscmc_mem *inB0;

  cuda_pscmc_mem *xoffset;

  cuda_pscmc_mem *yoffset;

  cuda_pscmc_mem *zoffset;

  cuda_pscmc_mem *y_cpu_core;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *xblock;

  cuda_pscmc_mem *yblock;

  cuda_pscmc_mem *zblock;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *DT;

} cuda_YEE_CURL_R_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutE1;

  cuda_pscmc_mem *inB0;

  cuda_pscmc_mem *xoffset;

  cuda_pscmc_mem *yoffset;

  cuda_pscmc_mem *zoffset;

  cuda_pscmc_mem *y_cpu_core;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *xblock;

  cuda_pscmc_mem *yblock;

  cuda_pscmc_mem *zblock;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *DT;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *x0;

} cuda_GEO_YEE_CURL_L_struct;

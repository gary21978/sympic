typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

  cuda_pscmc_mem *extA0;

  cuda_pscmc_mem *extA1;

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

  cuda_pscmc_mem *M;

  cuda_pscmc_mem *Q;

  cuda_pscmc_mem *DX;

  cuda_pscmc_mem *GEXT;

  cuda_pscmc_mem *rfz0;

  cuda_pscmc_mem *g_beg;

  cuda_pscmc_mem *swap_input;

} cuda_kgm_eqn_core_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

  cuda_pscmc_mem *M;

  cuda_pscmc_mem *Q;

  cuda_pscmc_mem *DX;

  cuda_pscmc_mem *refz0;

  cuda_pscmc_mem *q;

  cuda_pscmc_mem *dtodx;

  cuda_pscmc_mem *mode;

  cuda_pscmc_mem *swap_input;

} cuda_kgm_calc_rho_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

  cuda_pscmc_mem *outPMLEB;

  cuda_pscmc_mem *inPMLEB;

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

  cuda_pscmc_mem *M;

  cuda_pscmc_mem *Q;

  cuda_pscmc_mem *DX;

  cuda_pscmc_mem *DY;

  cuda_pscmc_mem *DZ;

  cuda_pscmc_mem *abc_dir;

  cuda_pscmc_mem *level;

  cuda_pscmc_mem *pml_m;

  cuda_pscmc_mem *max_sigma;

  cuda_pscmc_mem *allxmax;

  cuda_pscmc_mem *allymax;

  cuda_pscmc_mem *allzmax;

} cuda_PML_FDTD_CURL_BWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

  cuda_pscmc_mem *outPMLEB;

  cuda_pscmc_mem *inPMLEB;

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

  cuda_pscmc_mem *M;

  cuda_pscmc_mem *Q;

  cuda_pscmc_mem *DX;

  cuda_pscmc_mem *DY;

  cuda_pscmc_mem *DZ;

  cuda_pscmc_mem *abc_dir;

  cuda_pscmc_mem *level;

  cuda_pscmc_mem *pml_m;

  cuda_pscmc_mem *max_sigma;

  cuda_pscmc_mem *allxmax;

  cuda_pscmc_mem *allymax;

  cuda_pscmc_mem *allzmax;

} cuda_PML_FDTD_CURL_FWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_merge_current_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_merge_current_2_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Div_FWD_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Div_FWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Div_BWD_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Div_BWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_FWD_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_FWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_BWD_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_BWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Grad_FWD_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Grad_FWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Grad_BWD_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Grad_BWD_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_B_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_B_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_E_4th_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *outEB;

  cuda_pscmc_mem *inEB;

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

} cuda_Yee_FDTD_Curl_E_struct;

typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

  cuda_pscmc_mem *b;

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

} cuda_blas_axpby_enlarge_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

  cuda_pscmc_mem *b;

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

} cuda_blas_axpby_shrink_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_axpy_enlarge_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_axpy_shrink_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_yisax_enlarge_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_yisax_shrink_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *rdcd_sum;

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

} cuda_blas_sum_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *rdcd_sum;

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

} cuda_blas_sum_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *rdcd_sum;

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

} cuda_blas_dot_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *rdcd_sum;

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

} cuda_blas_dot_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *rdcd_max;

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

} cuda_blas_findmax_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *rdcd_max;

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

} cuda_blas_findmax_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

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

} cuda_blas_mulxy_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

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

} cuda_blas_mulxy_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

  cuda_pscmc_mem *b;

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

} cuda_blas_axpby_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

  cuda_pscmc_mem *b;

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

} cuda_blas_axpby_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_axpy_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_axpy_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_yisax_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *a;

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

} cuda_blas_yisax_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

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

} cuda_blas_invy_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

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

} cuda_blas_invy_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *u;

  cuda_pscmc_mem *minus_over_q_e;

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

} cuda_blas_get_ITG_Potential_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

  cuda_pscmc_mem *u;

  cuda_pscmc_mem *minus_over_q_e;

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

} cuda_blas_get_ITG_Potential_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *a;

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

} cuda_blas_yisconst_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *a;

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

} cuda_blas_yisconst_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

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

} cuda_blas_yiszero_full_block_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

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

} cuda_blas_yiszero_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

  cuda_pscmc_mem *x;

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

} cuda_blas_mulxy_numele3_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *y;

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

} cuda_blas_yiszero_synced_struct;

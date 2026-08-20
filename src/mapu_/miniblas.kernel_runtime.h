#pragma once
#include "mapu_pscmc.h"

typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpby_enlarge_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpby_shrink_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpy_enlarge_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpy_shrink_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisax_enlarge_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisax_shrink_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_sum_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_sum_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_sum_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_sum_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_dot_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_dot_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_dot_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *rdcd_sum;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_dot_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_max;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_findmax_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_max;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_findmax_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_max;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_findmax_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *rdcd_max;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_findmax_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_mulxy_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_mulxy_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_mulxy_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_mulxy_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpby_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpby_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpby_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpby_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpy_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpy_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpy_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_axpy_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *z;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisaxsinbpzpy_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *z;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisaxsinbpzpy_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *z;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisaxsinbpzpy_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *z;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *b;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisaxsinbpzpy_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisax_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisax_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisax_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisax_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_invy_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_invy_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_invy_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_invy_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *u;
  mapu_pscmc_mem *minus_over_q_e;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_get_ITG_Potential_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *u;
  mapu_pscmc_mem *minus_over_q_e;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_get_ITG_Potential_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *u;
  mapu_pscmc_mem *minus_over_q_e;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_get_ITG_Potential_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *u;
  mapu_pscmc_mem *minus_over_q_e;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_get_ITG_Potential_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisconst_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisconst_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisconst_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *a;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yisconst_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yiszero_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yiszero_large_block_full_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yiszero_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yiszero_large_block_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *x;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_mulxy_numele3_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *y;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
} mapu_blas_yiszero_synced_struct;

#ifdef __cplusplus
extern "C" {
#endif

void mapu_blas_yiszero_get_struct_len(size_t *len);
int mapu_blas_yiszero_get_xlen();
int mapu_blas_yiszero_get_num_compute_units(mapu_blas_yiszero_struct *kerstr);
int mapu_blas_yiszero_exec(mapu_blas_yiszero_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int mapu_blas_yiszero_scmc_set_parameter_y(mapu_blas_yiszero_struct *kerstr,
                                           mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_y_cpu_core(
    mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_numvec(
    mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_XLEN(mapu_blas_yiszero_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_YLEN(mapu_blas_yiszero_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_ZLEN(mapu_blas_yiszero_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_ovlp(mapu_blas_yiszero_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_xblock(
    mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_yblock(
    mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_zblock(
    mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_num_ele(
    mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);

void mapu_blas_axpy_get_struct_len(size_t *len);
int mapu_blas_axpy_get_xlen();
int mapu_blas_axpy_get_num_compute_units(mapu_blas_axpy_struct *kerstr);
int mapu_blas_axpy_exec(mapu_blas_axpy_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_blas_axpy_scmc_set_parameter_y(mapu_blas_axpy_struct *kerstr,
                                        mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_x(mapu_blas_axpy_struct *kerstr,
                                        mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_a(mapu_blas_axpy_struct *kerstr,
                                        mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_y_cpu_core(mapu_blas_axpy_struct *kerstr,
                                                 mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_numvec(mapu_blas_axpy_struct *kerstr,
                                             mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_XLEN(mapu_blas_axpy_struct *kerstr,
                                           mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_YLEN(mapu_blas_axpy_struct *kerstr,
                                           mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_ZLEN(mapu_blas_axpy_struct *kerstr,
                                           mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_ovlp(mapu_blas_axpy_struct *kerstr,
                                           mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_xblock(mapu_blas_axpy_struct *kerstr,
                                             mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_yblock(mapu_blas_axpy_struct *kerstr,
                                             mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_zblock(mapu_blas_axpy_struct *kerstr,
                                             mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_num_ele(mapu_blas_axpy_struct *kerstr,
                                              mapu_pscmc_mem *pm);

void mapu_blas_yiszero_synced_get_struct_len(size_t *len);
int mapu_blas_yiszero_synced_get_xlen();
int mapu_blas_yiszero_synced_get_num_compute_units(
    mapu_blas_yiszero_synced_struct *kerstr);
int mapu_blas_yiszero_synced_exec(mapu_blas_yiszero_synced_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int mapu_blas_yiszero_synced_scmc_set_parameter_y(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_numvec(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_XLEN(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_YLEN(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_ZLEN(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_ovlp(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_xblock(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_yblock(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_zblock(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_num_ele(
    mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);

void mapu_blas_yisax_get_struct_len(size_t *len);
int mapu_blas_yisax_get_xlen();
int mapu_blas_yisax_get_num_compute_units(mapu_blas_yisax_struct *kerstr);
int mapu_blas_yisax_exec(mapu_blas_yisax_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_blas_yisax_scmc_set_parameter_y(mapu_blas_yisax_struct *kerstr,
                                         mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_x(mapu_blas_yisax_struct *kerstr,
                                         mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_a(mapu_blas_yisax_struct *kerstr,
                                         mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_y_cpu_core(
    mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_numvec(mapu_blas_yisax_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_XLEN(mapu_blas_yisax_struct *kerstr,
                                            mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_YLEN(mapu_blas_yisax_struct *kerstr,
                                            mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_ZLEN(mapu_blas_yisax_struct *kerstr,
                                            mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_ovlp(mapu_blas_yisax_struct *kerstr,
                                            mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_xblock(mapu_blas_yisax_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_yblock(mapu_blas_yisax_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_zblock(mapu_blas_yisax_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_num_ele(mapu_blas_yisax_struct *kerstr,
                                               mapu_pscmc_mem *pm);

void mapu_blas_yisax_enlarge_get_struct_len(size_t *len);
int mapu_blas_yisax_enlarge_get_xlen();
int mapu_blas_yisax_enlarge_get_num_compute_units(
    mapu_blas_yisax_enlarge_struct *kerstr);
int mapu_blas_yisax_enlarge_exec(mapu_blas_yisax_enlarge_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int mapu_blas_yisax_enlarge_scmc_set_parameter_y(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_x(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_a(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_numvec(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_XLEN(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_YLEN(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_ZLEN(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_ovlp(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_xblock(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_yblock(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_zblock(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_num_ele(
    mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_blas_axpby_enlarge_init(mapu_pscmc_env *pe,
                                 mapu_blas_axpby_enlarge_struct *kerstr);
int mapu_blas_axpby_shrink_init(mapu_pscmc_env *pe,
                                mapu_blas_axpby_shrink_struct *kerstr);
int mapu_blas_axpy_enlarge_init(mapu_pscmc_env *pe,
                                mapu_blas_axpy_enlarge_struct *kerstr);
int mapu_blas_axpy_shrink_init(mapu_pscmc_env *pe,
                               mapu_blas_axpy_shrink_struct *kerstr);
int mapu_blas_yisax_enlarge_init(mapu_pscmc_env *pe,
                                 mapu_blas_yisax_enlarge_struct *kerstr);
int mapu_blas_yisax_shrink_init(mapu_pscmc_env *pe,
                                mapu_blas_yisax_shrink_struct *kerstr);
int mapu_blas_sum_full_block_init(mapu_pscmc_env *pe,
                                  mapu_blas_sum_full_block_struct *kerstr);
int mapu_blas_sum_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_sum_large_block_full_block_struct *kerstr);
int mapu_blas_sum_init(mapu_pscmc_env *pe, mapu_blas_sum_struct *kerstr);
int mapu_blas_sum_large_block_init(mapu_pscmc_env *pe,
                                   mapu_blas_sum_large_block_struct *kerstr);
int mapu_blas_dot_full_block_init(mapu_pscmc_env *pe,
                                  mapu_blas_dot_full_block_struct *kerstr);
int mapu_blas_dot_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_dot_large_block_full_block_struct *kerstr);
int mapu_blas_dot_init(mapu_pscmc_env *pe, mapu_blas_dot_struct *kerstr);
int mapu_blas_dot_large_block_init(mapu_pscmc_env *pe,
                                   mapu_blas_dot_large_block_struct *kerstr);
int mapu_blas_findmax_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_findmax_full_block_struct *kerstr);
int mapu_blas_findmax_large_block_full_block_init(
    mapu_pscmc_env *pe,
    mapu_blas_findmax_large_block_full_block_struct *kerstr);
int mapu_blas_findmax_init(mapu_pscmc_env *pe,
                           mapu_blas_findmax_struct *kerstr);
int mapu_blas_findmax_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_findmax_large_block_struct *kerstr);
int mapu_blas_mulxy_full_block_init(mapu_pscmc_env *pe,
                                    mapu_blas_mulxy_full_block_struct *kerstr);
int mapu_blas_mulxy_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_mulxy_large_block_full_block_struct *kerstr);
int mapu_blas_mulxy_init(mapu_pscmc_env *pe, mapu_blas_mulxy_struct *kerstr);
int mapu_blas_mulxy_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_mulxy_large_block_struct *kerstr);
int mapu_blas_axpby_full_block_init(mapu_pscmc_env *pe,
                                    mapu_blas_axpby_full_block_struct *kerstr);
int mapu_blas_axpby_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_axpby_large_block_full_block_struct *kerstr);
int mapu_blas_axpby_init(mapu_pscmc_env *pe, mapu_blas_axpby_struct *kerstr);
int mapu_blas_axpby_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_axpby_large_block_struct *kerstr);
int mapu_blas_axpy_full_block_init(mapu_pscmc_env *pe,
                                   mapu_blas_axpy_full_block_struct *kerstr);
int mapu_blas_axpy_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_axpy_large_block_full_block_struct *kerstr);
int mapu_blas_axpy_init(mapu_pscmc_env *pe, mapu_blas_axpy_struct *kerstr);
int mapu_blas_axpy_large_block_init(mapu_pscmc_env *pe,
                                    mapu_blas_axpy_large_block_struct *kerstr);
int mapu_blas_yisaxsinbpzpy_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_yisaxsinbpzpy_full_block_struct *kerstr);
int mapu_blas_yisaxsinbpzpy_large_block_full_block_init(
    mapu_pscmc_env *pe,
    mapu_blas_yisaxsinbpzpy_large_block_full_block_struct *kerstr);
int mapu_blas_yisaxsinbpzpy_init(mapu_pscmc_env *pe,
                                 mapu_blas_yisaxsinbpzpy_struct *kerstr);
int mapu_blas_yisaxsinbpzpy_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_yisaxsinbpzpy_large_block_struct *kerstr);
int mapu_blas_yisax_full_block_init(mapu_pscmc_env *pe,
                                    mapu_blas_yisax_full_block_struct *kerstr);
int mapu_blas_yisax_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_yisax_large_block_full_block_struct *kerstr);
int mapu_blas_yisax_init(mapu_pscmc_env *pe, mapu_blas_yisax_struct *kerstr);
int mapu_blas_yisax_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_yisax_large_block_struct *kerstr);
int mapu_blas_invy_full_block_init(mapu_pscmc_env *pe,
                                   mapu_blas_invy_full_block_struct *kerstr);
int mapu_blas_invy_large_block_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_invy_large_block_full_block_struct *kerstr);
int mapu_blas_invy_init(mapu_pscmc_env *pe, mapu_blas_invy_struct *kerstr);
int mapu_blas_invy_large_block_init(mapu_pscmc_env *pe,
                                    mapu_blas_invy_large_block_struct *kerstr);
int mapu_blas_get_ITG_Potential_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_get_ITG_Potential_full_block_struct *kerstr);
int mapu_blas_get_ITG_Potential_large_block_full_block_init(
    mapu_pscmc_env *pe,
    mapu_blas_get_ITG_Potential_large_block_full_block_struct *kerstr);
int mapu_blas_get_ITG_Potential_init(
    mapu_pscmc_env *pe, mapu_blas_get_ITG_Potential_struct *kerstr);
int mapu_blas_get_ITG_Potential_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_get_ITG_Potential_large_block_struct *kerstr);
int mapu_blas_yisconst_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_yisconst_full_block_struct *kerstr);
int mapu_blas_yisconst_large_block_full_block_init(
    mapu_pscmc_env *pe,
    mapu_blas_yisconst_large_block_full_block_struct *kerstr);
int mapu_blas_yisconst_init(mapu_pscmc_env *pe,
                            mapu_blas_yisconst_struct *kerstr);
int mapu_blas_yisconst_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_yisconst_large_block_struct *kerstr);
int mapu_blas_yiszero_full_block_init(
    mapu_pscmc_env *pe, mapu_blas_yiszero_full_block_struct *kerstr);
int mapu_blas_yiszero_large_block_full_block_init(
    mapu_pscmc_env *pe,
    mapu_blas_yiszero_large_block_full_block_struct *kerstr);
int mapu_blas_yiszero_init(mapu_pscmc_env *pe,
                           mapu_blas_yiszero_struct *kerstr);
int mapu_blas_yiszero_large_block_init(
    mapu_pscmc_env *pe, mapu_blas_yiszero_large_block_struct *kerstr);
int mapu_blas_mulxy_numele3_init(mapu_pscmc_env *pe,
                                 mapu_blas_mulxy_numele3_struct *kerstr);
int mapu_blas_yiszero_synced_init(mapu_pscmc_env *pe,
                                  mapu_blas_yiszero_synced_struct *kerstr);

int mapu_blas_sum_get_num_compute_units(mapu_blas_sum_struct *kerstr);

#ifdef __cplusplus
}
#endif

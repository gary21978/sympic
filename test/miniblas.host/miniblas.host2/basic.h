#ifndef BASIC_H
#define BASIC_H
#include <stdlib.h>
#define NUM_SYNC_LAYER 27
#define NUM_SYNC_KERNEL 12

typedef struct {
  void *pe;
  long xlen;
  long ylen;
  long zlen;
  long xblock;
  long yblock;
  long zblock;
  long numvec;
  long x_num_thread_block;
  long y_num_thread_block;
  long z_num_thread_block;
  int ovlp;
  int num_ele;
  int CD_type;

  void *sync_layer_pscmc[NUM_SYNC_LAYER];
  void *swap_layer_pscmc[NUM_SYNC_LAYER];
  void *sync_kernels[NUM_SYNC_KERNEL];
  void *geo_yeefdtd_kernels[2];
  void *rdcd;

  double *rdcd_host;
  void *cur_rankx_pscmc;
  void *cur_ranky_pscmc;
  void *cur_rankz_pscmc;
  void *xoffset;
  void *yoffset;
  void *zoffset;

  long *global_x_offset;
  long *global_y_offset;
  long *global_z_offset;

  long *global_id;
  long global_pid;

  long *adj_ids;
  long *adj_processes;
  long *adj_local_tid;

  void *main_data;

  double delta_x;
  double delta_y;
  double delta_z;

  void *blas_yiszero_synced_kernel;

  void *blas_mulxy_numele3_kernel;

  void *blas_yiszero_kernel;
  void *blas_yiszero_full_block_kernel;

  void *blas_yisconst_kernel;
  void *blas_yisconst_full_block_kernel;

  void *blas_get_ITG_Potential_kernel;
  void *blas_get_ITG_Potential_full_block_kernel;

  void *blas_invy_kernel;
  void *blas_invy_full_block_kernel;

  void *blas_axpby_kernel;
  void *blas_axpby_full_block_kernel;

  void *blas_axpy_kernel;
  void *blas_axpy_full_block_kernel;

  void *blas_yisax_kernel;
  void *blas_yisax_full_block_kernel;

  void *blas_mulxy_kernel;
  void *blas_mulxy_full_block_kernel;

  void *blas_findmax_kernel;
  void *blas_findmax_full_block_kernel;

  void *blas_dot_kernel;
  void *blas_dot_full_block_kernel;

  void *blas_sum_kernel;
  void *blas_sum_full_block_kernel;

  void *blas_yisax_shrink_kernel;
  void *blas_yisax_enlarge_kernel;

  void *blas_axpy_shrink_kernel;
  void *blas_axpy_enlarge_kernel;

  void *blas_axpby_shrink_kernel;
  void *blas_axpby_enlarge_kernel;

} Field3D_Seq;

typedef struct
{
    int device_id;
    int num_dev;
} mapu_pscmc_env;

typedef struct
{
    char *h_data;
    char *d_data;
    char *d_one_mem;
    int type;
    size_t len;
    mapu_pscmc_env *pe;
    int type_len;
} mapu_pscmc_mem;

typedef enum {
  PS_INT_NUM,
  PS_LONG_NUM,
  PS_FLOAT_NUM,
  PS_DOUBLE_NUM,
  PS_CHAR,
  PS_SHORT_NUM
} pscmc_data_types;

#endif

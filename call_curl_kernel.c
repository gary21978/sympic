#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <assert.h>

#ifndef NCSPIC_SEQ_FIELD
#include <mpi.h>

#define PS_MPI_CHAR MPI_CHAR

#define PS_MPI_INT MPI_INT

#define PS_MPI_DOUBLE MPI_DOUBLE

#define PS_MPI_FLOAT MPI_FLOAT

#define PS_MPI_LONG MPI_LONG

#define PS_MPI_LONG_LONG MPI_LONG_LONG

#define PS_MPI_COMM_WORLD MPI_COMM_WORLD

typedef MPI_Comm PS_MPI_Comm;

typedef MPI_Datatype PS_MPI_Datatype;

typedef MPI_Request PS_MPI_Request;

typedef MPI_Status PS_MPI_Status;
#include "libsmallmpi.h"

#define NCSPIC_SEQ_FIELD
typedef double NUMBER_REAL;
typedef enum {
  CD_C,
  CD_OpenMP,
  CD_OpenCL,
  CD_CUDA,
  CD_COI,
  CD_HIP,
  CD_SYCL
} SEQ_FIELD_TYPES;

#define NUM_SYNC_LAYER 27

#define NUM_SYNC_KERNEL 12

#define NUM_FDTD_KERNEL 22
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
  void *fdtd_kernels[NUM_FDTD_KERNEL];
  void *dm_kernels[3];
  void *dmbihamt_kernels[7];
  void *dm8x8_kernels[4];
  void *geo_yeefdtd_kernels[2];
  void *geo_yeefdtd_rect_kernels[1];
  void *yeefdtd_stencil_kernels[3];
  void *hydroA_kernels[8];
  void *yee_abc_kernels[8];
  void *yee_pec_kernels[8];
  void *yee_damp_kernels[8];
  void *yee_setfix_kernels[8];
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
typedef struct {
  Field3D_Seq *pfield;

  Field3D_Seq *pfieldE;

  Field3D_Seq *pfieldB;

  Field3D_Seq *pfieldB1;

  Field3D_Seq *pFoutJ;

  Field3D_Seq *pLFoutJ;

  Field3D_Seq *pFoutEN;

  void *sort_kernel[24];
  void *geo_rel_1st_kernel[9];
  void *implicit_kernel[2];
  void *rel_1st_kernel[2];
  void *krook_collision_test_kernel[2];
  void *nonrel_test_kernel[28];
  void *geo_rel_slab_nr_2nd_kernel[12];
  void *boris_yee_kernel[1];
  void *cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel;

  void *move_back_kernel_6_kernel;

  void *cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel;

  void *move_back_kernel_8_kernel;

  double Mass;

  double Charge;

  double Number_particle_per_marker;

  long grid_cache_len;

  long cu_cache_length;

  void *split_pass_x_kernel;

  void *split_pass_y_kernel;

  void *split_pass_z_kernel;

  void *split_pass_x_nopush_kernel;

  void *split_pass_y_nopush_kernel;

  void *split_pass_z_nopush_kernel;

  void *split_pass_x_small_grids_kernel;

  void *split_pass_y_small_grids_kernel;

  void *split_pass_z_small_grids_kernel;

  void *split_pass_x_sg2_small_grids_kernel;

  void *split_pass_y_sg2_small_grids_kernel;

  void *split_pass_z_sg2_small_grids_kernel;

  void *split_pass_E_particle_kernel;

  void *split_pass_x_vlo_kernel;

  void *split_pass_y_vlo_kernel;

  void *split_pass_z_vlo_kernel;

  void *split_pass_x_vlo_nopush_kernel;

  void *split_pass_y_vlo_nopush_kernel;

  void *split_pass_z_vlo_nopush_kernel;

  void *split_pass_x_vlo_small_grids_kernel;

  void *split_pass_y_vlo_small_grids_kernel;

  void *split_pass_z_vlo_small_grids_kernel;

  void *split_pass_x_vlo_sg2_small_grids_kernel;

  void *split_pass_y_vlo_sg2_small_grids_kernel;

  void *split_pass_z_vlo_sg2_small_grids_kernel;

  void *split_pass_x_vlo_sg2_nopush_small_grids_kernel;

  void *split_pass_y_vlo_sg2_nopush_small_grids_kernel;

  void *split_pass_z_vlo_sg2_nopush_small_grids_kernel;

  void *split_pass_E_particle_vlo_kernel;

  void *dump_ene_num_kernel;

  void *calculate_rho_kernel;

  void *inoutput;

  void *xyzw;

  void *cu_cache;

  void *cu_xyzw;

  void *adjoint_vec_pids;

} One_Particle_Collection;
typedef struct {
  Field3D_Seq *car;

  void *cdr;

} Field3D_Seq_PAIR;
typedef struct {
  Field3D_Seq *data;

  long num_runtime;

  PS_MPI_Comm comm;

  long cur_rank;

  long num_mpi_process;

  long sync_layer_len[NUM_SYNC_LAYER];
  PS_MPI_Request **rqst;

  One_Particle_Collection *particles;

  int num_spec;

  double damp_vars;

} Field3D_MPI;
typedef struct {
  Field3D_MPI MPI_fieldE;

  Field3D_MPI MPI_fieldB;

  Field3D_MPI MPI_fieldB1;

  Field3D_MPI MPI_FoutJ;

  Field3D_MPI MPI_FoutJtmp;

  Field3D_MPI MPI_LFoutJ;

  Field3D_MPI MPI_fieldEtmp;

  Field3D_MPI MPI_fieldBtmp;

  Field3D_MPI MPI_fieldEtmp1;

  Field3D_MPI MPI_fieldEtmp2;

  Field3D_MPI MPI_fieldE1;

  Field3D_MPI MPI_fieldBtmp1;

  Field3D_MPI MPI_fieldPMLB;

  Field3D_MPI MPI_fieldPMLE;

  Field3D_MPI *pMPI_FoutJ;

  Field3D_MPI *pMPI_FoutEN;

  Field3D_MPI MPI_fieldE_ext;

  Field3D_MPI MPI_fieldB_ext;

  Field3D_MPI MPI_fieldE_filter;

  Field3D_MPI MPI_fieldB_filter;

  Field3D_MPI *pB0;

  Field3D_MPI *pB1;

  Field3D_MPI MPI_fieldE01_2x;

  Field3D_MPI MPI_fieldB0_2x;

  int use_pml_abc_dir;

  int use_pml_level;

  int use_small_grid;

  int use_rel_ncr;

  int use_vlo;

  long allxmax;

  long allymax;

  long allzmax;

  double use_pml_sigma_max;

  double dt;

  double tori_x0;

  double solve_err;

  int o_N_l;

  int o_N_M;

  double *o_pmass;

  double *o_pcharge;

  int *o_particle_type;

  int current_mask;

  int use_tori;

  void *pusher_fun;

} Particle_in_Cell_MPI;

#ifndef LINEAR_OPERATOR_PICUS_001

#define LINEAR_OPERATOR_PICUS_001
typedef int (*linear_operator_mpi)(Field3D_MPI *, Field3D_MPI *, void *);

#else

#endif

typedef struct {
  Field3D_MPI *r1;

  Field3D_MPI *ti;

  Field3D_MPI *si1;

  Field3D_MPI *si;

  Field3D_MPI *vi1;

  Field3D_MPI *pi;

  Field3D_MPI *pi1;

  Field3D_MPI *ri1;

  Field3D_MPI *ri;

  Field3D_MPI *r0h;

  linear_operator_mpi A;

  void *fv;

  int zmax;

  double solve_err;

} bicg_space;
typedef struct {
  bicg_space bs;

  linear_operator_mpi oscc;

  Field3D_MPI *x0;

  Field3D_MPI *oscc_x0;

  Field3D_MPI *res_tmp;

  void *fv;

  void *p_vfv[5];
  int newton_zmax;

  int zmax;

  double solve_err;

  double newton_solve_err;

  double epsl;

} jfnk_newton_space;

#else

#endif

#include "c_/c_pscmc_inc.h"

#include "openmp_/openmp_pscmc_inc.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "c_/inner_split_pass.kernel_inc.h"



#include "c_/yeefdtd.kernel_inc.h"

#include "c_/stencil.kernel_inc.h"

#include "c_/mergefields.kernel_inc.h"

#include "c_/miniblas.kernel_inc.h"

#include "c_/general_partial_sort.kernel_inc.h"

#include "c_/move_back.kernel_inc.h"

#include "c_/particle_iter.kernel_inc.h"

#include "c_/geo_yeefdtd_rect.kernel_inc.h"

#include "c_/geo_yeefdtd.kernel_inc.h"

#include "c_yeefdtd.h"

#include "openmp_/inner_split_pass.kernel_inc.h"



#include "openmp_/yeefdtd.kernel_inc.h"

#include "openmp_/stencil.kernel_inc.h"

#include "openmp_/mergefields.kernel_inc.h"

#include "openmp_/miniblas.kernel_inc.h"

#include "openmp_/general_partial_sort.kernel_inc.h"

#include "openmp_/move_back.kernel_inc.h"

#include "openmp_/particle_iter.kernel_inc.h"

#include "openmp_/geo_yeefdtd_rect.kernel_inc.h"

#include "openmp_/geo_yeefdtd.kernel_inc.h"

#include "openmp_yeefdtd.h"

#include "cuda_/inner_split_pass.kernel_inc.h"



#include "cuda_/yeefdtd.kernel_inc.h"

#include "cuda_/stencil.kernel_inc.h"

#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"

#include "cuda_/geo_yeefdtd_rect.kernel_inc.h"

#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

#include "space_filling_curve.h"

#include "mpifields.h"

int MPI_Yee_FDTD_Curl_E(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_E((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_B(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_B((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_E_4th(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_E_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_B_4th(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_B_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Grad_FWD(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Grad_FWD((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Grad_BWD(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Grad_BWD((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Grad_FWD_4th(Field3D_MPI *pthis, Field3D_MPI *inEB,
                              double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Grad_FWD_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Grad_BWD_4th(Field3D_MPI *pthis, Field3D_MPI *inEB,
                              double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Grad_BWD_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_FWD(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_FWD((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_BWD(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_BWD((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_FWD_4th(Field3D_MPI *pthis, Field3D_MPI *inEB,
                              double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_FWD_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Curl_BWD_4th(Field3D_MPI *pthis, Field3D_MPI *inEB,
                              double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Curl_BWD_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Div_FWD(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Div_FWD((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Div_BWD(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Div_BWD((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Div_FWD_4th(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Div_FWD_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_Yee_FDTD_Div_BWD_4th(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_Yee_FDTD_Div_BWD_4th((data0 + i), (data + i), DT);
  }
  return 0;
}
int MPI_merge_current_2(Field3D_MPI *pthis, Field3D_MPI *inEB) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_merge_current_2((data0 + i), (data + i));
  }
  return 0;
}
int MPI_merge_current(Field3D_MPI *pthis, Field3D_MPI *inEB) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_merge_current((data0 + i), (data + i));
  }
  return 0;
}
int MPI_PML_FDTD_CURL_FWD(Field3D_MPI *pthis, Field3D_MPI *inEB,
                          Field3D_MPI *outPMLEB, Field3D_MPI *inPMLEB,
                          double DT, double m, double q, double DX, double DY,
                          double DZ, int abc_dir, int level, int pml_m,
                          double max_sigma, long allxmax, long allymax,
                          long allzmax) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  sync_ovlp_mpi_field(inPMLEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI

    // Run each runtime
    Field3D_Seq_PML_FDTD_CURL_FWD((data0 + i), (data + i),
                                  ((outPMLEB)->data + i), ((inPMLEB)->data + i),
                                  DT, m, q, DX, DY, DZ, abc_dir, level, pml_m,
                                  max_sigma, allxmax, allymax, allzmax);
  }
}
int MPI_PML_FDTD_CURL_BWD(Field3D_MPI *pthis, Field3D_MPI *inEB,
                          Field3D_MPI *outPMLEB, Field3D_MPI *inPMLEB,
                          double DT, double m, double q, double DX, double DY,
                          double DZ, int abc_dir, int level, int pml_m,
                          double max_sigma, long allxmax, long allymax,
                          long allzmax) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  sync_ovlp_mpi_field(inPMLEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI

    // Run each runtime
    Field3D_Seq_PML_FDTD_CURL_BWD((data0 + i), (data + i),
                                  ((outPMLEB)->data + i), ((inPMLEB)->data + i),
                                  DT, m, q, DX, DY, DZ, abc_dir, level, pml_m,
                                  max_sigma, allxmax, allymax, allzmax);
  }
}
int MPI_kgm_calc_rho(Field3D_MPI *pthis, Field3D_MPI *inEB, double DT, double m,
                     double Q, double DX, double refz0, double q, double dtodx,
                     int mode, int swap_input) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_kgm_calc_rho((data0 + i), (data + i), DT, m, Q, DX, refz0, q,
                             dtodx, mode, swap_input);
  }
  return 0;
}
int MPI_kgm_eqn_core(Field3D_MPI *pthis, Field3D_MPI *inEB, Field3D_MPI *pextA0,
                     Field3D_MPI *pextA1, double DT, double m, double Q,
                     double DX, double extg, double refz0, double g_beg,
                     int swap_input) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;

  long cur_rank = (pthis)->cur_rank;

  long num_mpi_process = (pthis)->num_mpi_process;

  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;

  double damp_vars = (pthis)->damp_vars;

  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inEB);
  for (i = 0; (i < num_runtime); i++) {
    Field3D_Seq *data0 = data;

    // defined from class Field3D_MPI
    Field3D_Seq *data = (inEB)->data;

    long num_runtime = (inEB)->num_runtime;

    PS_MPI_Comm comm = (inEB)->comm;

    long cur_rank = (inEB)->cur_rank;

    long num_mpi_process = (inEB)->num_mpi_process;

    long *sync_layer_len = (inEB)->sync_layer_len;

    PS_MPI_Request **rqst = (inEB)->rqst;

    One_Particle_Collection *particles = (inEB)->particles;

    int num_spec = (inEB)->num_spec;

    double damp_vars = (inEB)->damp_vars;

    //====================Field3D_MPI
    Field3D_Seq_kgm_eqn_core((data0 + i), (data + i), ((pextA0)->data + i),
                             ((pextA1)->data + i), DT, m, Q, DX, extg, refz0,
                             g_beg, swap_input);
  }
  return 0;
}

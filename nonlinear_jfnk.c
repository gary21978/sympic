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

#include <cgapsio.h>

#include "space_filling_curve.h"

#include "mpifields.h"

#include "blas_shell.h"

#include "init_field3d_mpi.h"

#include "mpi_fieldio.h"

#include "call_curl_kernel.h"

#include "sync_fields.h"

#include "run_particle.h"

#include "run_particle_call_fun.h"

int MPI_choose_pusher_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                           Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                           Field3D_MPI *FoutJ, double *pmass, double *pchg,
                           double deltat, double tx0, double slove_err,
                           int mask) {

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (pthis)->MPI_fieldE;

  Field3D_MPI MPI_fieldB = (pthis)->MPI_fieldB;

  Field3D_MPI MPI_fieldB1 = (pthis)->MPI_fieldB1;

  Field3D_MPI MPI_FoutJ = (pthis)->MPI_FoutJ;

  Field3D_MPI MPI_FoutJtmp = (pthis)->MPI_FoutJtmp;

  Field3D_MPI MPI_LFoutJ = (pthis)->MPI_LFoutJ;

  Field3D_MPI MPI_fieldEtmp = (pthis)->MPI_fieldEtmp;

  Field3D_MPI MPI_fieldBtmp = (pthis)->MPI_fieldBtmp;

  Field3D_MPI MPI_fieldEtmp1 = (pthis)->MPI_fieldEtmp1;

  Field3D_MPI MPI_fieldEtmp2 = (pthis)->MPI_fieldEtmp2;

  Field3D_MPI MPI_fieldE1 = (pthis)->MPI_fieldE1;

  Field3D_MPI MPI_fieldBtmp1 = (pthis)->MPI_fieldBtmp1;

  Field3D_MPI MPI_fieldPMLB = (pthis)->MPI_fieldPMLB;

  Field3D_MPI MPI_fieldPMLE = (pthis)->MPI_fieldPMLE;

  Field3D_MPI *pMPI_FoutJ = (pthis)->pMPI_FoutJ;

  Field3D_MPI *pMPI_FoutEN = (pthis)->pMPI_FoutEN;

  Field3D_MPI MPI_fieldE_ext = (pthis)->MPI_fieldE_ext;

  Field3D_MPI MPI_fieldB_ext = (pthis)->MPI_fieldB_ext;

  Field3D_MPI MPI_fieldE_filter = (pthis)->MPI_fieldE_filter;

  Field3D_MPI MPI_fieldB_filter = (pthis)->MPI_fieldB_filter;

  Field3D_MPI *pB0 = (pthis)->pB0;

  Field3D_MPI *pB1 = (pthis)->pB1;

  Field3D_MPI MPI_fieldE01_2x = (pthis)->MPI_fieldE01_2x;

  Field3D_MPI MPI_fieldB0_2x = (pthis)->MPI_fieldB0_2x;

  int use_pml_abc_dir = (pthis)->use_pml_abc_dir;

  int use_pml_level = (pthis)->use_pml_level;

  int use_small_grid = (pthis)->use_small_grid;

  int use_rel_ncr = (pthis)->use_rel_ncr;

  int use_vlo = (pthis)->use_vlo;

  long allxmax = (pthis)->allxmax;

  long allymax = (pthis)->allymax;

  long allzmax = (pthis)->allzmax;

  double use_pml_sigma_max = (pthis)->use_pml_sigma_max;

  double dt = (pthis)->dt;

  double tori_x0 = (pthis)->tori_x0;

  double solve_err = (pthis)->solve_err;

  int o_N_l = (pthis)->o_N_l;

  int o_N_M = (pthis)->o_N_M;

  double *o_pmass = (pthis)->o_pmass;

  double *o_pcharge = (pthis)->o_pcharge;

  int *o_particle_type = (pthis)->o_particle_type;

  int current_mask = (pthis)->current_mask;

  int use_tori = (pthis)->use_tori;

  void *pusher_fun = (pthis)->pusher_fun;

  //====================Particle_in_Cell_MPI
  static void **function_pointers = NULL;

  static void **function_pointers_nopush_par = NULL;

  static void **function_pointers_nopushJ = NULL;

  if ((function_pointers == NULL)) {
    (function_pointers = malloc((sizeof(void *) * 3)));
    (function_pointers_nopush_par = malloc((sizeof(void *) * 3)));
    (function_pointers_nopushJ = malloc((sizeof(void *) * 3)));
    ((function_pointers)[0] = One_Particle_Collection_geo_nr_Bfield_pushJ);
    ((function_pointers_nopush_par)[0] =
         One_Particle_Collection_geo_nr_Bfield_pushJ);
    ((function_pointers_nopushJ)[0] =
         One_Particle_Collection_geo_nr_Bfield_pushJ);
    ((function_pointers)[1] = One_Particle_Collection_geo_nr_Bfield_pushJ_vlo);
    ((function_pointers_nopush_par)[1] =
         One_Particle_Collection_geo_nr_Bfield_pushJ_vlo);
    ((function_pointers_nopushJ)[1] =
         One_Particle_Collection_geo_nr_Bfield_pushJ_vlo);
    ((function_pointers)[2] = One_Particle_Collection_geo_nr_Bfield_pushJ_vlo);
    ((function_pointers_nopush_par)[2] =
         One_Particle_Collection_geo_nr_Bfield_pushJ_vlo);
    ((function_pointers_nopushJ)[2] =
         One_Particle_Collection_geo_nr_Bfield_pushJ_vlo);

  } else {
    0;
  }

  int num_spec = (MPI_fieldE).num_spec;

  int num_runtime = (MPI_fieldE).num_runtime;

  {
    long i;

    for ((i = 0); (i < (num_runtime * num_spec)); (i = (i + 1))) {
      int cur_spec = (i / num_runtime);

      int particle_type = (o_particle_type)[cur_spec];

      if (((o_particle_type)[cur_spec] & mask)) {
        int use_implicit = (particle_type & 16);

        int use_nopush_par = (mask & 32);

        int use_nopushJ = (mask & 64);

        int func_num = (particle_type / 1024);

        int nmrt = (i % num_runtime);

        if (use_implicit) {
          int (*func)(void *, void *, void *, void *, void *, double, double,
                      double, double, double, int, int);
          (func = (function_pointers)[func_num]);
          if (use_nopush_par) {
            (func = (function_pointers_nopush_par)[func_num]);

          } else {
            0;
          }

          if (use_nopushJ) {
            (func = (function_pointers_nopushJ)[func_num]);

          } else {
            0;
          }

          func((MPI_fieldE.particles + i), (fieldE->data + nmrt),
               (fieldB->data + nmrt), (fieldB1->data + nmrt),
               (FoutJ->data + nmrt), (pmass)[cur_spec], (pchg)[cur_spec],
               deltat, tx0, solve_err, cur_spec, num_spec);

        } else {
          int (*func)(void *, void *, void *, void *, void *, double, double,
                      double, double, double, double, double, double, double,
                      int, int);
          (func = (function_pointers)[func_num]);
          func((MPI_fieldE.particles + i), (fieldE->data + nmrt),
               (fieldB->data + nmrt), (fieldB1->data + nmrt),
               (FoutJ->data + nmrt), (pmass)[cur_spec], (pchg)[cur_spec],
               deltat, tx0, 0, 0, 0, 0, 0, cur_spec, num_spec);
        }

      } else {
        0;
      }
    }
  }
}
int set_pusher_torix0_solveerr_and_mask(Particle_in_Cell_MPI *fv,
                                        void *puser_fun, double tori_x0,
                                        double solve_err, int mask,
                                        int use_tori) {
  (fv->pusher_fun = puser_fun);
  (fv->current_mask = mask);
  (fv->tori_x0 = tori_x0);
  (fv->solve_err = solve_err);
  (fv->use_tori = use_tori);
  return 0;
}
int nonlin_fun_shell_for_mask(Field3D_MPI *pthis, Field3D_MPI *x,
                              Particle_in_Cell_MPI *fv) {

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

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (fv)->MPI_fieldE;

  Field3D_MPI MPI_fieldB = (fv)->MPI_fieldB;

  Field3D_MPI MPI_fieldB1 = (fv)->MPI_fieldB1;

  Field3D_MPI MPI_FoutJ = (fv)->MPI_FoutJ;

  Field3D_MPI MPI_FoutJtmp = (fv)->MPI_FoutJtmp;

  Field3D_MPI MPI_LFoutJ = (fv)->MPI_LFoutJ;

  Field3D_MPI MPI_fieldEtmp = (fv)->MPI_fieldEtmp;

  Field3D_MPI MPI_fieldBtmp = (fv)->MPI_fieldBtmp;

  Field3D_MPI MPI_fieldEtmp1 = (fv)->MPI_fieldEtmp1;

  Field3D_MPI MPI_fieldEtmp2 = (fv)->MPI_fieldEtmp2;

  Field3D_MPI MPI_fieldE1 = (fv)->MPI_fieldE1;

  Field3D_MPI MPI_fieldBtmp1 = (fv)->MPI_fieldBtmp1;

  Field3D_MPI MPI_fieldPMLB = (fv)->MPI_fieldPMLB;

  Field3D_MPI MPI_fieldPMLE = (fv)->MPI_fieldPMLE;

  Field3D_MPI *pMPI_FoutJ = (fv)->pMPI_FoutJ;

  Field3D_MPI *pMPI_FoutEN = (fv)->pMPI_FoutEN;

  Field3D_MPI MPI_fieldE_ext = (fv)->MPI_fieldE_ext;

  Field3D_MPI MPI_fieldB_ext = (fv)->MPI_fieldB_ext;

  Field3D_MPI MPI_fieldE_filter = (fv)->MPI_fieldE_filter;

  Field3D_MPI MPI_fieldB_filter = (fv)->MPI_fieldB_filter;

  Field3D_MPI *pB0 = (fv)->pB0;

  Field3D_MPI *pB1 = (fv)->pB1;

  Field3D_MPI MPI_fieldE01_2x = (fv)->MPI_fieldE01_2x;

  Field3D_MPI MPI_fieldB0_2x = (fv)->MPI_fieldB0_2x;

  int use_pml_abc_dir = (fv)->use_pml_abc_dir;

  int use_pml_level = (fv)->use_pml_level;

  int use_small_grid = (fv)->use_small_grid;

  int use_rel_ncr = (fv)->use_rel_ncr;

  int use_vlo = (fv)->use_vlo;

  long allxmax = (fv)->allxmax;

  long allymax = (fv)->allymax;

  long allzmax = (fv)->allzmax;

  double use_pml_sigma_max = (fv)->use_pml_sigma_max;

  double dt = (fv)->dt;

  double tori_x0 = (fv)->tori_x0;

  double solve_err = (fv)->solve_err;

  int o_N_l = (fv)->o_N_l;

  int o_N_M = (fv)->o_N_M;

  double *o_pmass = (fv)->o_pmass;

  double *o_pcharge = (fv)->o_pcharge;

  int *o_particle_type = (fv)->o_particle_type;

  int current_mask = (fv)->current_mask;

  int use_tori = (fv)->use_tori;

  void *pusher_fun = (fv)->pusher_fun;

  //====================Particle_in_Cell_MPI
  Field3D_MPI *pMPI_fieldE = &(MPI_fieldE);

  Field3D_MPI *pMPI_fieldEtmp1 = &(MPI_fieldEtmp1);

  Field3D_MPI *pMPI_FoutJtmp = &(MPI_FoutJtmp);

  Field3D_MPI *pMPI_fieldB = &(MPI_fieldB);

  Field3D_MPI *pMPI_fieldB1 = &(MPI_fieldB1);

  sync_ovlp_mpi_field(pMPI_fieldE);
  blas_yisax_Field3D_MPI(pMPI_fieldEtmp1, pMPI_fieldEtmp1,
                         5.00000000000000000e-01, pMPI_fieldE);
  blas_axpy_Field3D_MPI(pMPI_fieldEtmp1, pMPI_fieldEtmp1,
                        5.00000000000000000e-01, x);
  sync_ovlp_mpi_field(pMPI_fieldEtmp1);
  blas_yisax_Field3D_MPI(pMPI_fieldB1, pMPI_fieldB1, 1, pMPI_fieldB);
  MPI_Yee_FDTD_Curl_E(pMPI_fieldB1, pMPI_fieldEtmp1, dt);
  sync_ovlp_mpi_field(pMPI_fieldB);
  sync_ovlp_mpi_field(pMPI_fieldB1);
  blas_yiszero_synced_Field3D_MPI(pMPI_FoutJtmp, pMPI_FoutJtmp);
  int (*e_pusher_fun_mask)(Particle_in_Cell_MPI *, Field3D_MPI *, Field3D_MPI *,
                           Field3D_MPI *, Field3D_MPI *, double *, double *,
                           double, double, double, int);
  (e_pusher_fun_mask = fv->pusher_fun);
  e_pusher_fun_mask(fv, pMPI_fieldEtmp1, pMPI_fieldB, pMPI_fieldB1,
                    pMPI_FoutJtmp, o_pmass, o_pcharge, dt, tori_x0, solve_err,
                    current_mask);
  merge_ovlp_mpi_field(pMPI_FoutJtmp);
  blas_axpy_Field3D_MPI(pMPI_FoutJtmp, pMPI_FoutJtmp, 1, pMPI_FoutJ);
  blas_yisax_Field3D_MPI(pthis, pthis, -1, pMPI_FoutJtmp);
  blas_axpy_Field3D_MPI(pthis, pthis, 1, pMPI_fieldE);
  blas_axpy_Field3D_MPI(pthis, pthis, -1, x);
  {

    // defined from class Field3D_Seq
    void *pe = (MPI_fieldE.data)->pe;

    long xlen = (MPI_fieldE.data)->xlen;

    long ylen = (MPI_fieldE.data)->ylen;

    long zlen = (MPI_fieldE.data)->zlen;

    long xblock = (MPI_fieldE.data)->xblock;

    long yblock = (MPI_fieldE.data)->yblock;

    long zblock = (MPI_fieldE.data)->zblock;

    long numvec = (MPI_fieldE.data)->numvec;

    long x_num_thread_block = (MPI_fieldE.data)->x_num_thread_block;

    long y_num_thread_block = (MPI_fieldE.data)->y_num_thread_block;

    long z_num_thread_block = (MPI_fieldE.data)->z_num_thread_block;

    int ovlp = (MPI_fieldE.data)->ovlp;

    int num_ele = (MPI_fieldE.data)->num_ele;

    int CD_type = (MPI_fieldE.data)->CD_type;

    void **sync_layer_pscmc = (MPI_fieldE.data)->sync_layer_pscmc;

    void **swap_layer_pscmc = (MPI_fieldE.data)->swap_layer_pscmc;

    void **sync_kernels = (MPI_fieldE.data)->sync_kernels;

    void **fdtd_kernels = (MPI_fieldE.data)->fdtd_kernels;

    void **dm_kernels = (MPI_fieldE.data)->dm_kernels;

    void **dmbihamt_kernels = (MPI_fieldE.data)->dmbihamt_kernels;

    void **dm8x8_kernels = (MPI_fieldE.data)->dm8x8_kernels;

    void **geo_yeefdtd_kernels = (MPI_fieldE.data)->geo_yeefdtd_kernels;

    void **geo_yeefdtd_rect_kernels =
        (MPI_fieldE.data)->geo_yeefdtd_rect_kernels;

    void **yeefdtd_stencil_kernels = (MPI_fieldE.data)->yeefdtd_stencil_kernels;

    void **hydroA_kernels = (MPI_fieldE.data)->hydroA_kernels;

    void **yee_abc_kernels = (MPI_fieldE.data)->yee_abc_kernels;

    void **yee_pec_kernels = (MPI_fieldE.data)->yee_pec_kernels;

    void **yee_damp_kernels = (MPI_fieldE.data)->yee_damp_kernels;

    void **yee_setfix_kernels = (MPI_fieldE.data)->yee_setfix_kernels;

    void *rdcd = (MPI_fieldE.data)->rdcd;

    double *rdcd_host = (MPI_fieldE.data)->rdcd_host;

    void *cur_rankx_pscmc = (MPI_fieldE.data)->cur_rankx_pscmc;

    void *cur_ranky_pscmc = (MPI_fieldE.data)->cur_ranky_pscmc;

    void *cur_rankz_pscmc = (MPI_fieldE.data)->cur_rankz_pscmc;

    void *xoffset = (MPI_fieldE.data)->xoffset;

    void *yoffset = (MPI_fieldE.data)->yoffset;

    void *zoffset = (MPI_fieldE.data)->zoffset;

    long *global_x_offset = (MPI_fieldE.data)->global_x_offset;

    long *global_y_offset = (MPI_fieldE.data)->global_y_offset;

    long *global_z_offset = (MPI_fieldE.data)->global_z_offset;

    long *global_id = (MPI_fieldE.data)->global_id;

    long global_pid = (MPI_fieldE.data)->global_pid;

    long *adj_ids = (MPI_fieldE.data)->adj_ids;

    long *adj_processes = (MPI_fieldE.data)->adj_processes;

    long *adj_local_tid = (MPI_fieldE.data)->adj_local_tid;

    void *main_data = (MPI_fieldE.data)->main_data;

    double delta_x = (MPI_fieldE.data)->delta_x;

    double delta_y = (MPI_fieldE.data)->delta_y;

    double delta_z = (MPI_fieldE.data)->delta_z;

    void *blas_yiszero_synced_kernel =
        (MPI_fieldE.data)->blas_yiszero_synced_kernel;

    void *blas_mulxy_numele3_kernel =
        (MPI_fieldE.data)->blas_mulxy_numele3_kernel;

    void *blas_yiszero_kernel = (MPI_fieldE.data)->blas_yiszero_kernel;

    void *blas_yiszero_full_block_kernel =
        (MPI_fieldE.data)->blas_yiszero_full_block_kernel;

    void *blas_yisconst_kernel = (MPI_fieldE.data)->blas_yisconst_kernel;

    void *blas_yisconst_full_block_kernel =
        (MPI_fieldE.data)->blas_yisconst_full_block_kernel;

    void *blas_get_ITG_Potential_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_kernel;

    void *blas_get_ITG_Potential_full_block_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_full_block_kernel;

    void *blas_invy_kernel = (MPI_fieldE.data)->blas_invy_kernel;

    void *blas_invy_full_block_kernel =
        (MPI_fieldE.data)->blas_invy_full_block_kernel;

    void *blas_axpby_kernel = (MPI_fieldE.data)->blas_axpby_kernel;

    void *blas_axpby_full_block_kernel =
        (MPI_fieldE.data)->blas_axpby_full_block_kernel;

    void *blas_axpy_kernel = (MPI_fieldE.data)->blas_axpy_kernel;

    void *blas_axpy_full_block_kernel =
        (MPI_fieldE.data)->blas_axpy_full_block_kernel;

    void *blas_yisax_kernel = (MPI_fieldE.data)->blas_yisax_kernel;

    void *blas_yisax_full_block_kernel =
        (MPI_fieldE.data)->blas_yisax_full_block_kernel;

    void *blas_mulxy_kernel = (MPI_fieldE.data)->blas_mulxy_kernel;

    void *blas_mulxy_full_block_kernel =
        (MPI_fieldE.data)->blas_mulxy_full_block_kernel;

    void *blas_findmax_kernel = (MPI_fieldE.data)->blas_findmax_kernel;

    void *blas_findmax_full_block_kernel =
        (MPI_fieldE.data)->blas_findmax_full_block_kernel;

    void *blas_dot_kernel = (MPI_fieldE.data)->blas_dot_kernel;

    void *blas_dot_full_block_kernel =
        (MPI_fieldE.data)->blas_dot_full_block_kernel;

    void *blas_sum_kernel = (MPI_fieldE.data)->blas_sum_kernel;

    void *blas_sum_full_block_kernel =
        (MPI_fieldE.data)->blas_sum_full_block_kernel;

    void *blas_yisax_shrink_kernel =
        (MPI_fieldE.data)->blas_yisax_shrink_kernel;

    void *blas_yisax_enlarge_kernel =
        (MPI_fieldE.data)->blas_yisax_enlarge_kernel;

    void *blas_axpy_shrink_kernel = (MPI_fieldE.data)->blas_axpy_shrink_kernel;

    void *blas_axpy_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpy_enlarge_kernel;

    void *blas_axpby_shrink_kernel =
        (MPI_fieldE.data)->blas_axpby_shrink_kernel;

    void *blas_axpby_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpby_enlarge_kernel;

    //====================Field3D_Seq
    if (use_tori) {
      MPI_GEO_YEE_CURL_L(pthis, pMPI_fieldB1, tori_x0, delta_x, delta_y,
                         delta_z, (dt * 5.00000000000000000e-01));
      MPI_GEO_YEE_CURL_L(pthis, pMPI_fieldB, tori_x0, delta_x, delta_y, delta_z,
                         (dt * 5.00000000000000000e-01));

    } else {
      MPI_RECT_YEE_CURL_L(pthis, pMPI_fieldB1, delta_z, delta_y, delta_x,
                          (dt * 5.00000000000000000e-01));
      MPI_RECT_YEE_CURL_L(pthis, pMPI_fieldB, delta_z, delta_y, delta_x,
                          (dt * 5.00000000000000000e-01));
    }
  }
  return 0;
}
int nonlin_fun_midp_vlasov_maxwell(Field3D_MPI *pthis, Field3D_MPI *x,
                                   Particle_in_Cell_MPI *fv) {

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

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (fv)->MPI_fieldE;

  Field3D_MPI MPI_fieldB = (fv)->MPI_fieldB;

  Field3D_MPI MPI_fieldB1 = (fv)->MPI_fieldB1;

  Field3D_MPI MPI_FoutJ = (fv)->MPI_FoutJ;

  Field3D_MPI MPI_FoutJtmp = (fv)->MPI_FoutJtmp;

  Field3D_MPI MPI_LFoutJ = (fv)->MPI_LFoutJ;

  Field3D_MPI MPI_fieldEtmp = (fv)->MPI_fieldEtmp;

  Field3D_MPI MPI_fieldBtmp = (fv)->MPI_fieldBtmp;

  Field3D_MPI MPI_fieldEtmp1 = (fv)->MPI_fieldEtmp1;

  Field3D_MPI MPI_fieldEtmp2 = (fv)->MPI_fieldEtmp2;

  Field3D_MPI MPI_fieldE1 = (fv)->MPI_fieldE1;

  Field3D_MPI MPI_fieldBtmp1 = (fv)->MPI_fieldBtmp1;

  Field3D_MPI MPI_fieldPMLB = (fv)->MPI_fieldPMLB;

  Field3D_MPI MPI_fieldPMLE = (fv)->MPI_fieldPMLE;

  Field3D_MPI *pMPI_FoutJ = (fv)->pMPI_FoutJ;

  Field3D_MPI *pMPI_FoutEN = (fv)->pMPI_FoutEN;

  Field3D_MPI MPI_fieldE_ext = (fv)->MPI_fieldE_ext;

  Field3D_MPI MPI_fieldB_ext = (fv)->MPI_fieldB_ext;

  Field3D_MPI MPI_fieldE_filter = (fv)->MPI_fieldE_filter;

  Field3D_MPI MPI_fieldB_filter = (fv)->MPI_fieldB_filter;

  Field3D_MPI *pB0 = (fv)->pB0;

  Field3D_MPI *pB1 = (fv)->pB1;

  Field3D_MPI MPI_fieldE01_2x = (fv)->MPI_fieldE01_2x;

  Field3D_MPI MPI_fieldB0_2x = (fv)->MPI_fieldB0_2x;

  int use_pml_abc_dir = (fv)->use_pml_abc_dir;

  int use_pml_level = (fv)->use_pml_level;

  int use_small_grid = (fv)->use_small_grid;

  int use_rel_ncr = (fv)->use_rel_ncr;

  int use_vlo = (fv)->use_vlo;

  long allxmax = (fv)->allxmax;

  long allymax = (fv)->allymax;

  long allzmax = (fv)->allzmax;

  double use_pml_sigma_max = (fv)->use_pml_sigma_max;

  double dt = (fv)->dt;

  double tori_x0 = (fv)->tori_x0;

  double solve_err = (fv)->solve_err;

  int o_N_l = (fv)->o_N_l;

  int o_N_M = (fv)->o_N_M;

  double *o_pmass = (fv)->o_pmass;

  double *o_pcharge = (fv)->o_pcharge;

  int *o_particle_type = (fv)->o_particle_type;

  int current_mask = (fv)->current_mask;

  int use_tori = (fv)->use_tori;

  void *pusher_fun = (fv)->pusher_fun;

  //====================Particle_in_Cell_MPI
  double DeltaT_i = (dt * o_N_l);

  Field3D_MPI *pMPI_fieldE = &(MPI_fieldE);

  Field3D_MPI *pMPI_fieldB = &(MPI_fieldB);

  Field3D_MPI *pMPI_fieldB1 = &(MPI_fieldB1);

  sync_ovlp_mpi_field(pMPI_fieldE);
  sync_ovlp_mpi_field(x);
  blas_yisax_Field3D_MPI(pMPI_fieldB1, pMPI_fieldB1, 1, pMPI_fieldB);
  MPI_Yee_FDTD_Curl_E(pMPI_fieldB1, x, (DeltaT_i * 5.00000000000000000e-01));
  MPI_Yee_FDTD_Curl_E(pMPI_fieldB1, pMPI_fieldE,
                      (DeltaT_i * 5.00000000000000000e-01));
  sync_ovlp_mpi_field(pMPI_fieldB);
  sync_ovlp_mpi_field(pMPI_fieldB1);
  blas_yiszero_synced_Field3D_MPI(&(MPI_FoutJ), &(MPI_FoutJ));
  merge_ovlp_mpi_field(&(MPI_FoutJ));
  blas_yiszero_synced_Field3D_MPI(pthis, pthis);
  {

    // defined from class Field3D_Seq
    void *pe = (MPI_fieldE.data)->pe;

    long xlen = (MPI_fieldE.data)->xlen;

    long ylen = (MPI_fieldE.data)->ylen;

    long zlen = (MPI_fieldE.data)->zlen;

    long xblock = (MPI_fieldE.data)->xblock;

    long yblock = (MPI_fieldE.data)->yblock;

    long zblock = (MPI_fieldE.data)->zblock;

    long numvec = (MPI_fieldE.data)->numvec;

    long x_num_thread_block = (MPI_fieldE.data)->x_num_thread_block;

    long y_num_thread_block = (MPI_fieldE.data)->y_num_thread_block;

    long z_num_thread_block = (MPI_fieldE.data)->z_num_thread_block;

    int ovlp = (MPI_fieldE.data)->ovlp;

    int num_ele = (MPI_fieldE.data)->num_ele;

    int CD_type = (MPI_fieldE.data)->CD_type;

    void **sync_layer_pscmc = (MPI_fieldE.data)->sync_layer_pscmc;

    void **swap_layer_pscmc = (MPI_fieldE.data)->swap_layer_pscmc;

    void **sync_kernels = (MPI_fieldE.data)->sync_kernels;

    void **fdtd_kernels = (MPI_fieldE.data)->fdtd_kernels;

    void **dm_kernels = (MPI_fieldE.data)->dm_kernels;

    void **dmbihamt_kernels = (MPI_fieldE.data)->dmbihamt_kernels;

    void **dm8x8_kernels = (MPI_fieldE.data)->dm8x8_kernels;

    void **geo_yeefdtd_kernels = (MPI_fieldE.data)->geo_yeefdtd_kernels;

    void **geo_yeefdtd_rect_kernels =
        (MPI_fieldE.data)->geo_yeefdtd_rect_kernels;

    void **yeefdtd_stencil_kernels = (MPI_fieldE.data)->yeefdtd_stencil_kernels;

    void **hydroA_kernels = (MPI_fieldE.data)->hydroA_kernels;

    void **yee_abc_kernels = (MPI_fieldE.data)->yee_abc_kernels;

    void **yee_pec_kernels = (MPI_fieldE.data)->yee_pec_kernels;

    void **yee_damp_kernels = (MPI_fieldE.data)->yee_damp_kernels;

    void **yee_setfix_kernels = (MPI_fieldE.data)->yee_setfix_kernels;

    void *rdcd = (MPI_fieldE.data)->rdcd;

    double *rdcd_host = (MPI_fieldE.data)->rdcd_host;

    void *cur_rankx_pscmc = (MPI_fieldE.data)->cur_rankx_pscmc;

    void *cur_ranky_pscmc = (MPI_fieldE.data)->cur_ranky_pscmc;

    void *cur_rankz_pscmc = (MPI_fieldE.data)->cur_rankz_pscmc;

    void *xoffset = (MPI_fieldE.data)->xoffset;

    void *yoffset = (MPI_fieldE.data)->yoffset;

    void *zoffset = (MPI_fieldE.data)->zoffset;

    long *global_x_offset = (MPI_fieldE.data)->global_x_offset;

    long *global_y_offset = (MPI_fieldE.data)->global_y_offset;

    long *global_z_offset = (MPI_fieldE.data)->global_z_offset;

    long *global_id = (MPI_fieldE.data)->global_id;

    long global_pid = (MPI_fieldE.data)->global_pid;

    long *adj_ids = (MPI_fieldE.data)->adj_ids;

    long *adj_processes = (MPI_fieldE.data)->adj_processes;

    long *adj_local_tid = (MPI_fieldE.data)->adj_local_tid;

    void *main_data = (MPI_fieldE.data)->main_data;

    double delta_x = (MPI_fieldE.data)->delta_x;

    double delta_y = (MPI_fieldE.data)->delta_y;

    double delta_z = (MPI_fieldE.data)->delta_z;

    void *blas_yiszero_synced_kernel =
        (MPI_fieldE.data)->blas_yiszero_synced_kernel;

    void *blas_mulxy_numele3_kernel =
        (MPI_fieldE.data)->blas_mulxy_numele3_kernel;

    void *blas_yiszero_kernel = (MPI_fieldE.data)->blas_yiszero_kernel;

    void *blas_yiszero_full_block_kernel =
        (MPI_fieldE.data)->blas_yiszero_full_block_kernel;

    void *blas_yisconst_kernel = (MPI_fieldE.data)->blas_yisconst_kernel;

    void *blas_yisconst_full_block_kernel =
        (MPI_fieldE.data)->blas_yisconst_full_block_kernel;

    void *blas_get_ITG_Potential_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_kernel;

    void *blas_get_ITG_Potential_full_block_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_full_block_kernel;

    void *blas_invy_kernel = (MPI_fieldE.data)->blas_invy_kernel;

    void *blas_invy_full_block_kernel =
        (MPI_fieldE.data)->blas_invy_full_block_kernel;

    void *blas_axpby_kernel = (MPI_fieldE.data)->blas_axpby_kernel;

    void *blas_axpby_full_block_kernel =
        (MPI_fieldE.data)->blas_axpby_full_block_kernel;

    void *blas_axpy_kernel = (MPI_fieldE.data)->blas_axpy_kernel;

    void *blas_axpy_full_block_kernel =
        (MPI_fieldE.data)->blas_axpy_full_block_kernel;

    void *blas_yisax_kernel = (MPI_fieldE.data)->blas_yisax_kernel;

    void *blas_yisax_full_block_kernel =
        (MPI_fieldE.data)->blas_yisax_full_block_kernel;

    void *blas_mulxy_kernel = (MPI_fieldE.data)->blas_mulxy_kernel;

    void *blas_mulxy_full_block_kernel =
        (MPI_fieldE.data)->blas_mulxy_full_block_kernel;

    void *blas_findmax_kernel = (MPI_fieldE.data)->blas_findmax_kernel;

    void *blas_findmax_full_block_kernel =
        (MPI_fieldE.data)->blas_findmax_full_block_kernel;

    void *blas_dot_kernel = (MPI_fieldE.data)->blas_dot_kernel;

    void *blas_dot_full_block_kernel =
        (MPI_fieldE.data)->blas_dot_full_block_kernel;

    void *blas_sum_kernel = (MPI_fieldE.data)->blas_sum_kernel;

    void *blas_sum_full_block_kernel =
        (MPI_fieldE.data)->blas_sum_full_block_kernel;

    void *blas_yisax_shrink_kernel =
        (MPI_fieldE.data)->blas_yisax_shrink_kernel;

    void *blas_yisax_enlarge_kernel =
        (MPI_fieldE.data)->blas_yisax_enlarge_kernel;

    void *blas_axpy_shrink_kernel = (MPI_fieldE.data)->blas_axpy_shrink_kernel;

    void *blas_axpy_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpy_enlarge_kernel;

    void *blas_axpby_shrink_kernel =
        (MPI_fieldE.data)->blas_axpby_shrink_kernel;

    void *blas_axpby_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpby_enlarge_kernel;

    //====================Field3D_Seq
    MPI_RECT_YEE_CURL_L(pthis, pMPI_fieldB, delta_z, delta_y, delta_x,
                        (5.00000000000000000e-01 * DeltaT_i));
    MPI_RECT_YEE_CURL_L(pthis, pMPI_fieldB1, delta_z, delta_y, delta_x,
                        (5.00000000000000000e-01 * DeltaT_i));
  }
  blas_axpy_Field3D_MPI(pthis, pthis, -1, &(MPI_FoutJ));
  blas_axpy_Field3D_MPI(pthis, pthis, 1, pMPI_fieldE);
  blas_axpy_Field3D_MPI(pthis, pthis, -1, x);
  return 0;
}
int nonlin_fun_cur_min_curlB(Field3D_MPI *pthis, Field3D_MPI *x,
                             Particle_in_Cell_MPI *fv) {

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

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (fv)->MPI_fieldE;

  Field3D_MPI MPI_fieldB = (fv)->MPI_fieldB;

  Field3D_MPI MPI_fieldB1 = (fv)->MPI_fieldB1;

  Field3D_MPI MPI_FoutJ = (fv)->MPI_FoutJ;

  Field3D_MPI MPI_FoutJtmp = (fv)->MPI_FoutJtmp;

  Field3D_MPI MPI_LFoutJ = (fv)->MPI_LFoutJ;

  Field3D_MPI MPI_fieldEtmp = (fv)->MPI_fieldEtmp;

  Field3D_MPI MPI_fieldBtmp = (fv)->MPI_fieldBtmp;

  Field3D_MPI MPI_fieldEtmp1 = (fv)->MPI_fieldEtmp1;

  Field3D_MPI MPI_fieldEtmp2 = (fv)->MPI_fieldEtmp2;

  Field3D_MPI MPI_fieldE1 = (fv)->MPI_fieldE1;

  Field3D_MPI MPI_fieldBtmp1 = (fv)->MPI_fieldBtmp1;

  Field3D_MPI MPI_fieldPMLB = (fv)->MPI_fieldPMLB;

  Field3D_MPI MPI_fieldPMLE = (fv)->MPI_fieldPMLE;

  Field3D_MPI *pMPI_FoutJ = (fv)->pMPI_FoutJ;

  Field3D_MPI *pMPI_FoutEN = (fv)->pMPI_FoutEN;

  Field3D_MPI MPI_fieldE_ext = (fv)->MPI_fieldE_ext;

  Field3D_MPI MPI_fieldB_ext = (fv)->MPI_fieldB_ext;

  Field3D_MPI MPI_fieldE_filter = (fv)->MPI_fieldE_filter;

  Field3D_MPI MPI_fieldB_filter = (fv)->MPI_fieldB_filter;

  Field3D_MPI *pB0 = (fv)->pB0;

  Field3D_MPI *pB1 = (fv)->pB1;

  Field3D_MPI MPI_fieldE01_2x = (fv)->MPI_fieldE01_2x;

  Field3D_MPI MPI_fieldB0_2x = (fv)->MPI_fieldB0_2x;

  int use_pml_abc_dir = (fv)->use_pml_abc_dir;

  int use_pml_level = (fv)->use_pml_level;

  int use_small_grid = (fv)->use_small_grid;

  int use_rel_ncr = (fv)->use_rel_ncr;

  int use_vlo = (fv)->use_vlo;

  long allxmax = (fv)->allxmax;

  long allymax = (fv)->allymax;

  long allzmax = (fv)->allzmax;

  double use_pml_sigma_max = (fv)->use_pml_sigma_max;

  double dt = (fv)->dt;

  double tori_x0 = (fv)->tori_x0;

  double solve_err = (fv)->solve_err;

  int o_N_l = (fv)->o_N_l;

  int o_N_M = (fv)->o_N_M;

  double *o_pmass = (fv)->o_pmass;

  double *o_pcharge = (fv)->o_pcharge;

  int *o_particle_type = (fv)->o_particle_type;

  int current_mask = (fv)->current_mask;

  int use_tori = (fv)->use_tori;

  void *pusher_fun = (fv)->pusher_fun;

  //====================Particle_in_Cell_MPI
  double DeltaT_i = (dt * o_N_l);

  blas_yisax_Field3D_MPI(&(MPI_fieldB1), &(MPI_fieldB1), 1, &(MPI_fieldB));
  MPI_Yee_FDTD_Curl_E(&(MPI_fieldB1), x, DeltaT_i);
  blas_yisax_Field3D_MPI(&(MPI_fieldE), &(MPI_fieldE), 1, x);
  sync_ovlp_mpi_field(&(MPI_fieldE));
  sync_ovlp_mpi_field(&(MPI_fieldB));
  sync_ovlp_mpi_field(&(MPI_fieldB1));
  Field3D_MPI *pMPI_fieldE = &(MPI_fieldE);

  Field3D_MPI *pMPI_fieldB = &(MPI_fieldB);

  Field3D_MPI *pMPI_fieldB1 = &(MPI_fieldB1);

  blas_yiszero_synced_Field3D_MPI(&(MPI_FoutJ), &(MPI_FoutJ));
  merge_ovlp_mpi_field(&(MPI_FoutJ));
  blas_yiszero_synced_Field3D_MPI(pthis, pthis);
  {

    // defined from class Field3D_Seq
    void *pe = (MPI_fieldE.data)->pe;

    long xlen = (MPI_fieldE.data)->xlen;

    long ylen = (MPI_fieldE.data)->ylen;

    long zlen = (MPI_fieldE.data)->zlen;

    long xblock = (MPI_fieldE.data)->xblock;

    long yblock = (MPI_fieldE.data)->yblock;

    long zblock = (MPI_fieldE.data)->zblock;

    long numvec = (MPI_fieldE.data)->numvec;

    long x_num_thread_block = (MPI_fieldE.data)->x_num_thread_block;

    long y_num_thread_block = (MPI_fieldE.data)->y_num_thread_block;

    long z_num_thread_block = (MPI_fieldE.data)->z_num_thread_block;

    int ovlp = (MPI_fieldE.data)->ovlp;

    int num_ele = (MPI_fieldE.data)->num_ele;

    int CD_type = (MPI_fieldE.data)->CD_type;

    void **sync_layer_pscmc = (MPI_fieldE.data)->sync_layer_pscmc;

    void **swap_layer_pscmc = (MPI_fieldE.data)->swap_layer_pscmc;

    void **sync_kernels = (MPI_fieldE.data)->sync_kernels;

    void **fdtd_kernels = (MPI_fieldE.data)->fdtd_kernels;

    void **dm_kernels = (MPI_fieldE.data)->dm_kernels;

    void **dmbihamt_kernels = (MPI_fieldE.data)->dmbihamt_kernels;

    void **dm8x8_kernels = (MPI_fieldE.data)->dm8x8_kernels;

    void **geo_yeefdtd_kernels = (MPI_fieldE.data)->geo_yeefdtd_kernels;

    void **geo_yeefdtd_rect_kernels =
        (MPI_fieldE.data)->geo_yeefdtd_rect_kernels;

    void **yeefdtd_stencil_kernels = (MPI_fieldE.data)->yeefdtd_stencil_kernels;

    void **hydroA_kernels = (MPI_fieldE.data)->hydroA_kernels;

    void **yee_abc_kernels = (MPI_fieldE.data)->yee_abc_kernels;

    void **yee_pec_kernels = (MPI_fieldE.data)->yee_pec_kernels;

    void **yee_damp_kernels = (MPI_fieldE.data)->yee_damp_kernels;

    void **yee_setfix_kernels = (MPI_fieldE.data)->yee_setfix_kernels;

    void *rdcd = (MPI_fieldE.data)->rdcd;

    double *rdcd_host = (MPI_fieldE.data)->rdcd_host;

    void *cur_rankx_pscmc = (MPI_fieldE.data)->cur_rankx_pscmc;

    void *cur_ranky_pscmc = (MPI_fieldE.data)->cur_ranky_pscmc;

    void *cur_rankz_pscmc = (MPI_fieldE.data)->cur_rankz_pscmc;

    void *xoffset = (MPI_fieldE.data)->xoffset;

    void *yoffset = (MPI_fieldE.data)->yoffset;

    void *zoffset = (MPI_fieldE.data)->zoffset;

    long *global_x_offset = (MPI_fieldE.data)->global_x_offset;

    long *global_y_offset = (MPI_fieldE.data)->global_y_offset;

    long *global_z_offset = (MPI_fieldE.data)->global_z_offset;

    long *global_id = (MPI_fieldE.data)->global_id;

    long global_pid = (MPI_fieldE.data)->global_pid;

    long *adj_ids = (MPI_fieldE.data)->adj_ids;

    long *adj_processes = (MPI_fieldE.data)->adj_processes;

    long *adj_local_tid = (MPI_fieldE.data)->adj_local_tid;

    void *main_data = (MPI_fieldE.data)->main_data;

    double delta_x = (MPI_fieldE.data)->delta_x;

    double delta_y = (MPI_fieldE.data)->delta_y;

    double delta_z = (MPI_fieldE.data)->delta_z;

    void *blas_yiszero_synced_kernel =
        (MPI_fieldE.data)->blas_yiszero_synced_kernel;

    void *blas_mulxy_numele3_kernel =
        (MPI_fieldE.data)->blas_mulxy_numele3_kernel;

    void *blas_yiszero_kernel = (MPI_fieldE.data)->blas_yiszero_kernel;

    void *blas_yiszero_full_block_kernel =
        (MPI_fieldE.data)->blas_yiszero_full_block_kernel;

    void *blas_yisconst_kernel = (MPI_fieldE.data)->blas_yisconst_kernel;

    void *blas_yisconst_full_block_kernel =
        (MPI_fieldE.data)->blas_yisconst_full_block_kernel;

    void *blas_get_ITG_Potential_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_kernel;

    void *blas_get_ITG_Potential_full_block_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_full_block_kernel;

    void *blas_invy_kernel = (MPI_fieldE.data)->blas_invy_kernel;

    void *blas_invy_full_block_kernel =
        (MPI_fieldE.data)->blas_invy_full_block_kernel;

    void *blas_axpby_kernel = (MPI_fieldE.data)->blas_axpby_kernel;

    void *blas_axpby_full_block_kernel =
        (MPI_fieldE.data)->blas_axpby_full_block_kernel;

    void *blas_axpy_kernel = (MPI_fieldE.data)->blas_axpy_kernel;

    void *blas_axpy_full_block_kernel =
        (MPI_fieldE.data)->blas_axpy_full_block_kernel;

    void *blas_yisax_kernel = (MPI_fieldE.data)->blas_yisax_kernel;

    void *blas_yisax_full_block_kernel =
        (MPI_fieldE.data)->blas_yisax_full_block_kernel;

    void *blas_mulxy_kernel = (MPI_fieldE.data)->blas_mulxy_kernel;

    void *blas_mulxy_full_block_kernel =
        (MPI_fieldE.data)->blas_mulxy_full_block_kernel;

    void *blas_findmax_kernel = (MPI_fieldE.data)->blas_findmax_kernel;

    void *blas_findmax_full_block_kernel =
        (MPI_fieldE.data)->blas_findmax_full_block_kernel;

    void *blas_dot_kernel = (MPI_fieldE.data)->blas_dot_kernel;

    void *blas_dot_full_block_kernel =
        (MPI_fieldE.data)->blas_dot_full_block_kernel;

    void *blas_sum_kernel = (MPI_fieldE.data)->blas_sum_kernel;

    void *blas_sum_full_block_kernel =
        (MPI_fieldE.data)->blas_sum_full_block_kernel;

    void *blas_yisax_shrink_kernel =
        (MPI_fieldE.data)->blas_yisax_shrink_kernel;

    void *blas_yisax_enlarge_kernel =
        (MPI_fieldE.data)->blas_yisax_enlarge_kernel;

    void *blas_axpy_shrink_kernel = (MPI_fieldE.data)->blas_axpy_shrink_kernel;

    void *blas_axpy_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpy_enlarge_kernel;

    void *blas_axpby_shrink_kernel =
        (MPI_fieldE.data)->blas_axpby_shrink_kernel;

    void *blas_axpby_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpby_enlarge_kernel;

    //====================Field3D_Seq
    MPI_RECT_YEE_CURL_L(pthis, pMPI_fieldB, delta_z, delta_y, delta_x,
                        DeltaT_i);
  }
  blas_axpy_Field3D_MPI(pthis, pthis, -1, &(MPI_FoutJ));
  if (0) {
    {
      Gaps_IO_DataFile gid;

      Gaps_IO_DataFile *pgid = &(gid);

      merge_ovlp_mpi_field(&(MPI_FoutJ));
      init_parallel_file_for_mpi_fields(&(MPI_fieldB), pgid, "tmpJ1", -1, 0, 0);
      mpi_field_write_to_file(&(MPI_FoutJ), pgid, 0);
      mpi_field_write_to_file(&(MPI_fieldB), pgid, 1);
      mpi_field_write_to_file(&(MPI_fieldE), pgid, 2);
      fprintf(stderr, "otpt J2\n");
      exit(0);
    }
  } else {
    0;
  }

  return 0;
}
int one_step_calc_current(Field3D_MPI *pthis, Field3D_MPI *x,
                          Particle_in_Cell_MPI *fv) {

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

  // defined from class Particle_in_Cell_MPI
  Field3D_MPI MPI_fieldE = (fv)->MPI_fieldE;

  Field3D_MPI MPI_fieldB = (fv)->MPI_fieldB;

  Field3D_MPI MPI_fieldB1 = (fv)->MPI_fieldB1;

  Field3D_MPI MPI_FoutJ = (fv)->MPI_FoutJ;

  Field3D_MPI MPI_FoutJtmp = (fv)->MPI_FoutJtmp;

  Field3D_MPI MPI_LFoutJ = (fv)->MPI_LFoutJ;

  Field3D_MPI MPI_fieldEtmp = (fv)->MPI_fieldEtmp;

  Field3D_MPI MPI_fieldBtmp = (fv)->MPI_fieldBtmp;

  Field3D_MPI MPI_fieldEtmp1 = (fv)->MPI_fieldEtmp1;

  Field3D_MPI MPI_fieldEtmp2 = (fv)->MPI_fieldEtmp2;

  Field3D_MPI MPI_fieldE1 = (fv)->MPI_fieldE1;

  Field3D_MPI MPI_fieldBtmp1 = (fv)->MPI_fieldBtmp1;

  Field3D_MPI MPI_fieldPMLB = (fv)->MPI_fieldPMLB;

  Field3D_MPI MPI_fieldPMLE = (fv)->MPI_fieldPMLE;

  Field3D_MPI *pMPI_FoutJ = (fv)->pMPI_FoutJ;

  Field3D_MPI *pMPI_FoutEN = (fv)->pMPI_FoutEN;

  Field3D_MPI MPI_fieldE_ext = (fv)->MPI_fieldE_ext;

  Field3D_MPI MPI_fieldB_ext = (fv)->MPI_fieldB_ext;

  Field3D_MPI MPI_fieldE_filter = (fv)->MPI_fieldE_filter;

  Field3D_MPI MPI_fieldB_filter = (fv)->MPI_fieldB_filter;

  Field3D_MPI *pB0 = (fv)->pB0;

  Field3D_MPI *pB1 = (fv)->pB1;

  Field3D_MPI MPI_fieldE01_2x = (fv)->MPI_fieldE01_2x;

  Field3D_MPI MPI_fieldB0_2x = (fv)->MPI_fieldB0_2x;

  int use_pml_abc_dir = (fv)->use_pml_abc_dir;

  int use_pml_level = (fv)->use_pml_level;

  int use_small_grid = (fv)->use_small_grid;

  int use_rel_ncr = (fv)->use_rel_ncr;

  int use_vlo = (fv)->use_vlo;

  long allxmax = (fv)->allxmax;

  long allymax = (fv)->allymax;

  long allzmax = (fv)->allzmax;

  double use_pml_sigma_max = (fv)->use_pml_sigma_max;

  double dt = (fv)->dt;

  double tori_x0 = (fv)->tori_x0;

  double solve_err = (fv)->solve_err;

  int o_N_l = (fv)->o_N_l;

  int o_N_M = (fv)->o_N_M;

  double *o_pmass = (fv)->o_pmass;

  double *o_pcharge = (fv)->o_pcharge;

  int *o_particle_type = (fv)->o_particle_type;

  int current_mask = (fv)->current_mask;

  int use_tori = (fv)->use_tori;

  void *pusher_fun = (fv)->pusher_fun;

  //====================Particle_in_Cell_MPI
  double DeltaT_i = (dt * o_N_l);

  blas_yisax_Field3D_MPI(&(MPI_fieldB), &(MPI_fieldB), 1, &(MPI_fieldBtmp1));
  MPI_Yee_FDTD_Curl_E(&(MPI_fieldB), x, DeltaT_i);
  blas_yisax_Field3D_MPI(&(MPI_fieldE), &(MPI_fieldE), 1, x);
  sync_ovlp_mpi_field(&(MPI_fieldE));
  sync_ovlp_mpi_field(&(MPI_fieldB));
  blas_yiszero_synced_Field3D_MPI(&(MPI_FoutJ), &(MPI_FoutJ));
  if (0) {
    {
      Gaps_IO_DataFile gid;

      Gaps_IO_DataFile *pgid = &(gid);

      merge_ovlp_mpi_field(&(MPI_FoutJ));
      init_parallel_file_for_mpi_fields(&(MPI_fieldB), pgid, "tmpJ1", -1, 0, 0);
      mpi_field_write_to_file(&(MPI_FoutJ), pgid, 0);
      mpi_field_write_to_file(&(MPI_fieldB), pgid, 1);
      mpi_field_write_to_file(&(MPI_fieldE), pgid, 2);
      fprintf(stderr, "otpt J2\n");
      exit(0);
    }
  } else {
    0;
  }

  {
    double dt0 = (dt * (o_N_l * 5.00000000000000000e-01));

    int usevlo = 0;

    if (usevlo) {
      split_pass_E_particle_vlo_mpi(fv, (dt0 * 2));

    } else {
      split_pass_E_particle_mpi(fv, (dt0 * 2));
    }

    split_pass_x_nopush_mpi_multi_runtime(fv, dt0);
    split_pass_y_nopush_mpi_multi_runtime(fv, dt0);
    split_pass_z_nopush_mpi_multi_runtime(fv, (dt0 * 2));
    split_pass_y_nopush_mpi_multi_runtime(fv, dt0);
    split_pass_x_nopush_mpi_multi_runtime(fv, dt0);
  }
  merge_ovlp_mpi_field(&(MPI_FoutJ));
  blas_yisax_Field3D_MPI(pthis, pthis, 1, &(MPI_FoutJ));
  {

    // defined from class Field3D_Seq
    void *pe = (MPI_fieldE.data)->pe;

    long xlen = (MPI_fieldE.data)->xlen;

    long ylen = (MPI_fieldE.data)->ylen;

    long zlen = (MPI_fieldE.data)->zlen;

    long xblock = (MPI_fieldE.data)->xblock;

    long yblock = (MPI_fieldE.data)->yblock;

    long zblock = (MPI_fieldE.data)->zblock;

    long numvec = (MPI_fieldE.data)->numvec;

    long x_num_thread_block = (MPI_fieldE.data)->x_num_thread_block;

    long y_num_thread_block = (MPI_fieldE.data)->y_num_thread_block;

    long z_num_thread_block = (MPI_fieldE.data)->z_num_thread_block;

    int ovlp = (MPI_fieldE.data)->ovlp;

    int num_ele = (MPI_fieldE.data)->num_ele;

    int CD_type = (MPI_fieldE.data)->CD_type;

    void **sync_layer_pscmc = (MPI_fieldE.data)->sync_layer_pscmc;

    void **swap_layer_pscmc = (MPI_fieldE.data)->swap_layer_pscmc;

    void **sync_kernels = (MPI_fieldE.data)->sync_kernels;

    void **fdtd_kernels = (MPI_fieldE.data)->fdtd_kernels;

    void **dm_kernels = (MPI_fieldE.data)->dm_kernels;

    void **dmbihamt_kernels = (MPI_fieldE.data)->dmbihamt_kernels;

    void **dm8x8_kernels = (MPI_fieldE.data)->dm8x8_kernels;

    void **geo_yeefdtd_kernels = (MPI_fieldE.data)->geo_yeefdtd_kernels;

    void **geo_yeefdtd_rect_kernels =
        (MPI_fieldE.data)->geo_yeefdtd_rect_kernels;

    void **yeefdtd_stencil_kernels = (MPI_fieldE.data)->yeefdtd_stencil_kernels;

    void **hydroA_kernels = (MPI_fieldE.data)->hydroA_kernels;

    void **yee_abc_kernels = (MPI_fieldE.data)->yee_abc_kernels;

    void **yee_pec_kernels = (MPI_fieldE.data)->yee_pec_kernels;

    void **yee_damp_kernels = (MPI_fieldE.data)->yee_damp_kernels;

    void **yee_setfix_kernels = (MPI_fieldE.data)->yee_setfix_kernels;

    void *rdcd = (MPI_fieldE.data)->rdcd;

    double *rdcd_host = (MPI_fieldE.data)->rdcd_host;

    void *cur_rankx_pscmc = (MPI_fieldE.data)->cur_rankx_pscmc;

    void *cur_ranky_pscmc = (MPI_fieldE.data)->cur_ranky_pscmc;

    void *cur_rankz_pscmc = (MPI_fieldE.data)->cur_rankz_pscmc;

    void *xoffset = (MPI_fieldE.data)->xoffset;

    void *yoffset = (MPI_fieldE.data)->yoffset;

    void *zoffset = (MPI_fieldE.data)->zoffset;

    long *global_x_offset = (MPI_fieldE.data)->global_x_offset;

    long *global_y_offset = (MPI_fieldE.data)->global_y_offset;

    long *global_z_offset = (MPI_fieldE.data)->global_z_offset;

    long *global_id = (MPI_fieldE.data)->global_id;

    long global_pid = (MPI_fieldE.data)->global_pid;

    long *adj_ids = (MPI_fieldE.data)->adj_ids;

    long *adj_processes = (MPI_fieldE.data)->adj_processes;

    long *adj_local_tid = (MPI_fieldE.data)->adj_local_tid;

    void *main_data = (MPI_fieldE.data)->main_data;

    double delta_x = (MPI_fieldE.data)->delta_x;

    double delta_y = (MPI_fieldE.data)->delta_y;

    double delta_z = (MPI_fieldE.data)->delta_z;

    void *blas_yiszero_synced_kernel =
        (MPI_fieldE.data)->blas_yiszero_synced_kernel;

    void *blas_mulxy_numele3_kernel =
        (MPI_fieldE.data)->blas_mulxy_numele3_kernel;

    void *blas_yiszero_kernel = (MPI_fieldE.data)->blas_yiszero_kernel;

    void *blas_yiszero_full_block_kernel =
        (MPI_fieldE.data)->blas_yiszero_full_block_kernel;

    void *blas_yisconst_kernel = (MPI_fieldE.data)->blas_yisconst_kernel;

    void *blas_yisconst_full_block_kernel =
        (MPI_fieldE.data)->blas_yisconst_full_block_kernel;

    void *blas_get_ITG_Potential_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_kernel;

    void *blas_get_ITG_Potential_full_block_kernel =
        (MPI_fieldE.data)->blas_get_ITG_Potential_full_block_kernel;

    void *blas_invy_kernel = (MPI_fieldE.data)->blas_invy_kernel;

    void *blas_invy_full_block_kernel =
        (MPI_fieldE.data)->blas_invy_full_block_kernel;

    void *blas_axpby_kernel = (MPI_fieldE.data)->blas_axpby_kernel;

    void *blas_axpby_full_block_kernel =
        (MPI_fieldE.data)->blas_axpby_full_block_kernel;

    void *blas_axpy_kernel = (MPI_fieldE.data)->blas_axpy_kernel;

    void *blas_axpy_full_block_kernel =
        (MPI_fieldE.data)->blas_axpy_full_block_kernel;

    void *blas_yisax_kernel = (MPI_fieldE.data)->blas_yisax_kernel;

    void *blas_yisax_full_block_kernel =
        (MPI_fieldE.data)->blas_yisax_full_block_kernel;

    void *blas_mulxy_kernel = (MPI_fieldE.data)->blas_mulxy_kernel;

    void *blas_mulxy_full_block_kernel =
        (MPI_fieldE.data)->blas_mulxy_full_block_kernel;

    void *blas_findmax_kernel = (MPI_fieldE.data)->blas_findmax_kernel;

    void *blas_findmax_full_block_kernel =
        (MPI_fieldE.data)->blas_findmax_full_block_kernel;

    void *blas_dot_kernel = (MPI_fieldE.data)->blas_dot_kernel;

    void *blas_dot_full_block_kernel =
        (MPI_fieldE.data)->blas_dot_full_block_kernel;

    void *blas_sum_kernel = (MPI_fieldE.data)->blas_sum_kernel;

    void *blas_sum_full_block_kernel =
        (MPI_fieldE.data)->blas_sum_full_block_kernel;

    void *blas_yisax_shrink_kernel =
        (MPI_fieldE.data)->blas_yisax_shrink_kernel;

    void *blas_yisax_enlarge_kernel =
        (MPI_fieldE.data)->blas_yisax_enlarge_kernel;

    void *blas_axpy_shrink_kernel = (MPI_fieldE.data)->blas_axpy_shrink_kernel;

    void *blas_axpy_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpy_enlarge_kernel;

    void *blas_axpby_shrink_kernel =
        (MPI_fieldE.data)->blas_axpby_shrink_kernel;

    void *blas_axpby_enlarge_kernel =
        (MPI_fieldE.data)->blas_axpby_enlarge_kernel;

    //====================Field3D_Seq
    MPI_RECT_YEE_CURL_L(pthis, &(MPI_fieldB), delta_z, delta_y, delta_x, -1);
  }
  return 0;
}
double jac_pred_rat = 1.00000000000000000e+04;

int Jacobi_x(Field3D_MPI *pthis, Field3D_MPI *dx, Particle_in_Cell_MPI **fv) {

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
  double *epsl = (fv)[0];

  Particle_in_Cell_MPI *ppis = (fv)[1];

  Field3D_MPI *x = (fv)[2];

  linear_operator_mpi oscc = (fv)[3];

  Field3D_MPI *oscc_x = (fv)[4];

  if (0) {
    {
      blas_yisax_Field3D_MPI(dx, dx, 5.00000000000000000e-01, dx);
    }
  } else {
    0;
  }

  blas_yisax_Field3D_MPI(&(ppis->MPI_fieldEtmp), &(ppis->MPI_fieldEtmp),
                         (jac_pred_rat * (epsl)[0]), dx);
  blas_axpy_Field3D_MPI(&(ppis->MPI_fieldEtmp), &(ppis->MPI_fieldEtmp), 1, x);
  oscc(pthis, &(ppis->MPI_fieldEtmp), ppis);
  if (0) {
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    init_parallel_file_for_mpi_fields(&(ppis->MPI_fieldEtmp), pgid, "tmpJ1", -1,
                                      0, 0);
    mpi_field_write_to_file(pthis, pgid, 0);
    mpi_field_write_to_file(dx, pgid, 1);
    mpi_field_write_to_file(x, pgid, 2);
    mpi_field_write_to_file(oscc_x, pgid, 3);
    mpi_field_write_to_file(&(ppis->MPI_fieldEtmp), pgid, 4);
    fprintf(stderr, "otpt J2\n");
    exit(0);

  } else {
    0;
  }

  blas_axpy_Field3D_MPI(pthis, pthis, -1, oscc_x);
  blas_yisax_Field3D_MPI(pthis, pthis, (1 / (epsl)[0]), pthis);
  if (0) {
    {
      static int s = 0;

      if ((s != 2)) {
        (s = (s + 1));

      } else {
        Gaps_IO_DataFile gid;

        Gaps_IO_DataFile *pgid = &(gid);

        fprintf(stderr, "epsl=%e\n", (epsl)[0]);
        init_parallel_file_for_mpi_fields(&(ppis->MPI_fieldEtmp), pgid, "tmpJ1",
                                          -1, 0, 0);
        mpi_field_write_to_file(pthis, pgid, 0);
        mpi_field_write_to_file(dx, pgid, 1);
        mpi_field_write_to_file(x, pgid, 2);
        mpi_field_write_to_file(oscc_x, pgid, 3);
        fprintf(stderr, "otpt J2\n");
        exit(0);
      }
    }
  } else {
    0;
  }

  return 0;
}
int gen_jac_mat_x(Field3D_MPI *pthis, Field3D_MPI *dx,
                  Particle_in_Cell_MPI **fv) {

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
  Gaps_IO_DataFile gid;

  Gaps_IO_DataFile *pgid = &(gid);

  init_parallel_file_for_mpi_fields(pthis, pgid, "tmpJac", -1, 0, 0);
  {
    long i;

    for ((i = 0); (i < 11); (i = (i + 1))) {
      {
        long l;

        for ((l = 0); (l < 3); (l = (l + 1))) {
          blas_yiszero_synced_Field3D_MPI(dx, dx);
          (((((double **)(dx->data)->main_data))[0])[(
               (0 * ((dx->data)->xblock *
                     ((dx->data)->yblock *
                      ((dx->data)->zblock * (dx->data)->num_ele)))) +
               (l + ((dx->data)->num_ele *
                     ((i + (dx->data)->ovlp) +
                      ((dx->data)->xblock *
                       ((0 + (dx->data)->ovlp) +
                        ((dx->data)->yblock * (0 + (dx->data)->ovlp))))))))] =
               1);
          sync_ovlp_mpi_field(dx);
          Jacobi_x(pthis, dx, fv);
          mpi_field_write_to_file(pthis, pgid, (l + (i * 3)));
        }
      }
    }
  }
  return 0;
}
int init_jfnk_newton_space(jfnk_newton_space *pthis, Field3D_MPI *x,
                           linear_operator_mpi oscc, double newton_solve_err,
                           double solve_err, int zmax, int newton_zmax,
                           double epsl, void *fv) {
  ((pthis)->oscc = oscc);
  ((pthis)->solve_err = solve_err);
  ((pthis)->newton_solve_err = newton_solve_err);
  ((pthis)->epsl = epsl);
  ((pthis)->fv = fv);
  ((pthis)->zmax = zmax);
  ((pthis)->newton_zmax = newton_zmax);
  ((pthis)->x0 = malloc(sizeof(Field3D_MPI)));
  init_Field3D_MPI_from((pthis)->x0, x);
  ((pthis)->oscc_x0 = malloc(sizeof(Field3D_MPI)));
  init_Field3D_MPI_from((pthis)->oscc_x0, x);
  ((pthis)->res_tmp = malloc(sizeof(Field3D_MPI)));
  init_Field3D_MPI_from((pthis)->res_tmp, x);
  ((pthis->p_vfv)[0] = &(pthis->epsl));
  ((pthis->p_vfv)[1] = pthis->fv);
  ((pthis->p_vfv)[2] = pthis->x0);
  ((pthis->p_vfv)[3] = pthis->oscc);
  ((pthis->p_vfv)[4] = pthis->oscc_x0);
  mpi_init_bicg(&(pthis->bs), Jacobi_x, x, zmax, solve_err, pthis->p_vfv);
  return 0;
}
int jfnk_newton_simple_mpi(jfnk_newton_space *pthis, Field3D_MPI *inx) {

  // defined from class jfnk_newton_space
  bicg_space bs = (pthis)->bs;

  linear_operator_mpi oscc = (pthis)->oscc;

  Field3D_MPI *x0 = (pthis)->x0;

  Field3D_MPI *oscc_x0 = (pthis)->oscc_x0;

  Field3D_MPI *res_tmp = (pthis)->res_tmp;

  void *fv = (pthis)->fv;

  void **p_vfv = (pthis)->p_vfv;

  int newton_zmax = (pthis)->newton_zmax;

  int zmax = (pthis)->zmax;

  double solve_err = (pthis)->solve_err;

  double newton_solve_err = (pthis)->newton_solve_err;

  double epsl = (pthis)->epsl;

  //====================jfnk_newton_space
  blas_yisax_Field3D_MPI(x0, x0, 1, inx);
  oscc(oscc_x0, x0, fv);
  double maxv = blas_findmax_Field3D_MPI(oscc_x0, oscc_x0);

  int z = 0;

  for (0; (maxv > newton_solve_err); (z = (z + 1))) {
    fprintf(stderr, "jfnk maxv=%e\n", maxv);
    if ((z >= newton_zmax)) {
      break;

    } else {
      0;
    }

    blas_yiszero_Field3D_MPI(res_tmp, res_tmp);
    if (0) {
      Particle_in_Cell_MPI *ppis = (pthis->p_vfv)[1];

      Field3D_MPI *pf = &(ppis->MPI_fieldEtmp2);

      gen_jac_mat_x(res_tmp, pf, pthis->p_vfv);
      exit(0);

    } else {
      0;
    }

    mpi_simple_bicgstab(&(bs), res_tmp, oscc_x0);
    blas_axpy_Field3D_MPI(x0, x0, (-1 * jac_pred_rat), res_tmp);
    oscc(oscc_x0, x0, fv);
    (maxv = blas_findmax_Field3D_MPI(oscc_x0, oscc_x0));
  }
  fprintf(stderr, "jfnk done maxv=%e\n", maxv);
  blas_yisax_Field3D_MPI(inx, inx, 1, x0);
  if (0) {
    {
      Gaps_IO_DataFile gid;

      Gaps_IO_DataFile *pgid = &(gid);

      init_parallel_file_for_mpi_fields(inx, pgid, "tmpJ1", -1, 0, 0);
      mpi_field_write_to_file(x0, pgid, 0);
      mpi_field_write_to_file(oscc_x0, pgid, 1);
      mpi_field_write_to_file(inx, pgid, 2);
      fprintf(stderr, "otpt J\n");
      exit(0);
    }
  } else {
    0;
  }

  return 0;
}
int jfnk_newton_init_parameters(jfnk_newton_space *pthis, int N_l, int N_M,
                                double *pmass, double *pcharge) {

  // defined from class jfnk_newton_space
  bicg_space bs = (pthis)->bs;

  linear_operator_mpi oscc = (pthis)->oscc;

  Field3D_MPI *x0 = (pthis)->x0;

  Field3D_MPI *oscc_x0 = (pthis)->oscc_x0;

  Field3D_MPI *res_tmp = (pthis)->res_tmp;

  void *fv = (pthis)->fv;

  void **p_vfv = (pthis)->p_vfv;

  int newton_zmax = (pthis)->newton_zmax;

  int zmax = (pthis)->zmax;

  double solve_err = (pthis)->solve_err;

  double newton_solve_err = (pthis)->newton_solve_err;

  double epsl = (pthis)->epsl;

  //====================jfnk_newton_space
  Particle_in_Cell_MPI *ppis = fv;

  (ppis->o_N_l = N_l);
  (ppis->o_N_M = N_M);
  (ppis->o_pmass = pmass);
  (ppis->o_pcharge = pcharge);
  return 0;
}

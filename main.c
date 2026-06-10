#include <stdio.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include <math.h>

#include <time.h>

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

#include "genrand.h"

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

#include "init_field3d_mpi.h"

#include <cgapsio.h>

#include "mpi_fieldio.h"

#include "call_curl_kernel.h"

#include "init_particle.h"

#include "run_particle.h"

#include "run_particle_call_fun.h"

#include "pass_xyzzyx.h"

#include "sort_particle.h"

#include "seqfields.h"

#include "split_shell.h"

#include "blas_shell.h"

#include "cfgcst.h"

typedef Field3D_MPI Field3D_MPI_ALL;

#include <sys/time.h>

double wclk_now() {
  struct timeval tv1;

  struct timezone tz1;

  gettimeofday(&(tv1), &(tz1));
  double time_start1 = (((double)tv1.tv_sec) +
                        (9.99999999999999955e-07 * ((double)tv1.tv_usec)));

  return time_start1;
}
Gaps_IO_DataFile *pTEMPERATURE_DIST_gid_global_var = NULL;

double TEMPERATURE_DIST_gid_cache_var[64];
long TEMPERATURE_DIST_gid_cache_pos = -1;

double TEMPERATURE_DIST_global_procedure(long cursp, double z, double y,
                                         double x, long l) {
  if (pTEMPERATURE_DIST_gid_global_var) {
    long *pdimarray = (pTEMPERATURE_DIST_gid_global_var)->pdimarray;

    long current_cache_pos =
        (((long)l) +
         ((pdimarray)[0] *
          (((long)x) +
           ((pdimarray)[1] *
            (((long)y) +
             ((pdimarray)[2] *
              (((long)z) +
               ((pdimarray)[3] * (((long)cursp) + ((pdimarray)[4] * 0))))))))));

    long offset_pos = (current_cache_pos - TEMPERATURE_DIST_gid_cache_pos);

    if (((TEMPERATURE_DIST_gid_cache_pos == -1) ||
         ((offset_pos < 0) || (offset_pos >= 64)))) {
      GAPS_IO_DataSeek(pTEMPERATURE_DIST_gid_global_var, 0, current_cache_pos);
      GAPS_IO_FRead(pTEMPERATURE_DIST_gid_global_var,
                    TEMPERATURE_DIST_gid_cache_var, 64);
      (TEMPERATURE_DIST_gid_cache_pos = current_cache_pos);
      return (TEMPERATURE_DIST_gid_cache_var)[0];

    } else {
      return (TEMPERATURE_DIST_gid_cache_var)[offset_pos];
    }

  } else {
    return 0;
  }
}
Gaps_IO_DataFile *pDENSITY_DIST_gid_global_var = NULL;

double DENSITY_DIST_gid_cache_var[64];
long DENSITY_DIST_gid_cache_pos = -1;

double DENSITY_DIST_global_procedure(long cursp, double z, double y, double x) {
  if (pDENSITY_DIST_gid_global_var) {
    long *pdimarray = (pDENSITY_DIST_gid_global_var)->pdimarray;

    long current_cache_pos =
        (((long)x) +
         ((pdimarray)[0] *
          (((long)y) +
           ((pdimarray)[1] *
            (((long)z) +
             ((pdimarray)[2] * (((long)cursp) + ((pdimarray)[3] * 0))))))));

    long offset_pos = (current_cache_pos - DENSITY_DIST_gid_cache_pos);

    if (((DENSITY_DIST_gid_cache_pos == -1) ||
         ((offset_pos < 0) || (offset_pos >= 64)))) {
      GAPS_IO_DataSeek(pDENSITY_DIST_gid_global_var, 0, current_cache_pos);
      GAPS_IO_FRead(pDENSITY_DIST_gid_global_var, DENSITY_DIST_gid_cache_var,
                    64);
      (DENSITY_DIST_gid_cache_pos = current_cache_pos);
      return (DENSITY_DIST_gid_cache_var)[0];

    } else {
      return (DENSITY_DIST_gid_cache_var)[offset_pos];
    }

  } else {
    return 0;
  }
}
Gaps_IO_DataFile *pV0_x_gid_global_var = NULL;

double V0_x_gid_cache_var[64];
long V0_x_gid_cache_pos = -1;

double V0_x_global_procedure(long cursp, double z, double y, double x) {
  if (pV0_x_gid_global_var) {
    long *pdimarray = (pV0_x_gid_global_var)->pdimarray;

    long current_cache_pos =
        (((long)x) +
         ((pdimarray)[0] *
          (((long)y) +
           ((pdimarray)[1] *
            (((long)z) +
             ((pdimarray)[2] * (((long)cursp) + ((pdimarray)[3] * 0))))))));

    long offset_pos = (current_cache_pos - V0_x_gid_cache_pos);

    if (((V0_x_gid_cache_pos == -1) ||
         ((offset_pos < 0) || (offset_pos >= 64)))) {
      GAPS_IO_DataSeek(pV0_x_gid_global_var, 0, current_cache_pos);
      GAPS_IO_FRead(pV0_x_gid_global_var, V0_x_gid_cache_var, 64);
      (V0_x_gid_cache_pos = current_cache_pos);
      return (V0_x_gid_cache_var)[0];

    } else {
      return (V0_x_gid_cache_var)[offset_pos];
    }

  } else {
    return 0;
  }
}
Gaps_IO_DataFile *pV0_y_gid_global_var = NULL;

double V0_y_gid_cache_var[64];
long V0_y_gid_cache_pos = -1;

double V0_y_global_procedure(long cursp, double z, double y, double x) {
  if (pV0_y_gid_global_var) {
    long *pdimarray = (pV0_y_gid_global_var)->pdimarray;

    long current_cache_pos =
        (((long)x) +
         ((pdimarray)[0] *
          (((long)y) +
           ((pdimarray)[1] *
            (((long)z) +
             ((pdimarray)[2] * (((long)cursp) + ((pdimarray)[3] * 0))))))));

    long offset_pos = (current_cache_pos - V0_y_gid_cache_pos);

    if (((V0_y_gid_cache_pos == -1) ||
         ((offset_pos < 0) || (offset_pos >= 64)))) {
      GAPS_IO_DataSeek(pV0_y_gid_global_var, 0, current_cache_pos);
      GAPS_IO_FRead(pV0_y_gid_global_var, V0_y_gid_cache_var, 64);
      (V0_y_gid_cache_pos = current_cache_pos);
      return (V0_y_gid_cache_var)[0];

    } else {
      return (V0_y_gid_cache_var)[offset_pos];
    }

  } else {
    return 0;
  }
}
Gaps_IO_DataFile *pV0_z_gid_global_var = NULL;

double V0_z_gid_cache_var[64];
long V0_z_gid_cache_pos = -1;

double V0_z_global_procedure(long cursp, double z, double y, double x) {
  if (pV0_z_gid_global_var) {
    long *pdimarray = (pV0_z_gid_global_var)->pdimarray;

    long current_cache_pos =
        (((long)x) +
         ((pdimarray)[0] *
          (((long)y) +
           ((pdimarray)[1] *
            (((long)z) +
             ((pdimarray)[2] * (((long)cursp) + ((pdimarray)[3] * 0))))))));

    long offset_pos = (current_cache_pos - V0_z_gid_cache_pos);

    if (((V0_z_gid_cache_pos == -1) ||
         ((offset_pos < 0) || (offset_pos >= 64)))) {
      GAPS_IO_DataSeek(pV0_z_gid_global_var, 0, current_cache_pos);
      GAPS_IO_FRead(pV0_z_gid_global_var, V0_z_gid_cache_var, 64);
      (V0_z_gid_cache_pos = current_cache_pos);
      return (V0_z_gid_cache_var)[0];

    } else {
      return (V0_z_gid_cache_var)[offset_pos];
    }

  } else {
    return 0;
  }
}
long srand_seed = 0;

int main(int argc, char **argv) {
  main_proc(argc, argv);
  get_constants();
  PS_MPI_Init(&(argc), &(argv));
  {
    char *nm = "V0_z_file";

    FILE *fp = fopen(nm, "r");

    if (fp) {
      fprintf(stderr, "found %s for input\n", nm);
      (pV0_z_gid_global_var = malloc((sizeof(Gaps_IO_DataFile) * 1)));
      GAPS_IO_InitIFile(pV0_z_gid_global_var, nm);
      assert(((pV0_z_gid_global_var)->version == 0));
      assert(((pV0_z_gid_global_var)->dim == 4));
      (GET_INIT_V0_z_inner_procedure = V0_z_global_procedure);

    } else {
      0;
    }
  }
  {
    char *nm = "V0_y_file";

    FILE *fp = fopen(nm, "r");

    if (fp) {
      fprintf(stderr, "found %s for input\n", nm);
      (pV0_y_gid_global_var = malloc((sizeof(Gaps_IO_DataFile) * 1)));
      GAPS_IO_InitIFile(pV0_y_gid_global_var, nm);
      assert(((pV0_y_gid_global_var)->version == 0));
      assert(((pV0_y_gid_global_var)->dim == 4));
      (GET_INIT_V0_y_inner_procedure = V0_y_global_procedure);

    } else {
      0;
    }
  }
  {
    char *nm = "V0_x_file";

    FILE *fp = fopen(nm, "r");

    if (fp) {
      fprintf(stderr, "found %s for input\n", nm);
      (pV0_x_gid_global_var = malloc((sizeof(Gaps_IO_DataFile) * 1)));
      GAPS_IO_InitIFile(pV0_x_gid_global_var, nm);
      assert(((pV0_x_gid_global_var)->version == 0));
      assert(((pV0_x_gid_global_var)->dim == 4));
      (GET_INIT_V0_x_inner_procedure = V0_x_global_procedure);

    } else {
      0;
    }
  }
  {
    char *nm = "DENSITY_DIST_file";

    FILE *fp = fopen(nm, "r");

    if (fp) {
      fprintf(stderr, "found %s for input\n", nm);
      (pDENSITY_DIST_gid_global_var = malloc((sizeof(Gaps_IO_DataFile) * 1)));
      GAPS_IO_InitIFile(pDENSITY_DIST_gid_global_var, nm);
      assert(((pDENSITY_DIST_gid_global_var)->version == 0));
      assert(((pDENSITY_DIST_gid_global_var)->dim == 4));
      (GET_INIT_DENSITY_DIST_inner_procedure = DENSITY_DIST_global_procedure);

    } else {
      0;
    }
  }
  {
    char *nm = "TEMPERATURE_DIST_file";

    FILE *fp = fopen(nm, "r");

    if (fp) {
      fprintf(stderr, "found %s for input\n", nm);
      (pTEMPERATURE_DIST_gid_global_var =
           malloc((sizeof(Gaps_IO_DataFile) * 1)));
      GAPS_IO_InitIFile(pTEMPERATURE_DIST_gid_global_var, nm);
      assert(((pTEMPERATURE_DIST_gid_global_var)->version == 0));
      assert(((pTEMPERATURE_DIST_gid_global_var)->dim == 5));
      (GET_INIT_TEMPERATURE_DIST_inner_procedure =
           TEMPERATURE_DIST_global_procedure);

    } else {
      0;
    }
  }
  int n = NUM_PROCESS;

  if ((NUM_PROCESS == 0)) {
    PS_MPI_Comm_size(PS_MPI_COMM_WORLD, &(n));
    (NUM_PROCESS = n);

  } else {
    0;
  }

  long num_runtime = NUM_RUNTIME;

  long n_hilbert = NUM_N_HILBERT;

  long len_hilbert = (1 << n_hilbert);

  long numt = 1;

  {
    long g;

    for ((g = 0); (g < NUM_N_HILBERT_DIMENSION); (g = (g + 1))) {
      (numt = (numt * len_hilbert));
    }
  }
  int rank;

  PS_MPI_Comm_rank(PS_MPI_COMM_WORLD, &(rank));
  assert((rank < n));
  double M_USE_TIME_AS_RANDOM_SEED = call_GET_VAR("USE_TIME_AS_RANDOM_SEED");

  double M_RAND_SEED = call_GET_VAR("RAND_SEED");

  double M_DELTA_X = call_GET_VAR("DELTA_X");

  double M_DELTA_Y = call_GET_VAR("DELTA_Y");

  double M_DELTA_Z = call_GET_VAR("DELTA_Z");

  double M_USE_VLO = call_GET_VAR("USE_VLO");

  double M_DISABLE_TS_LOG = call_GET_VAR("DISABLE_TS_LOG");

  double M_USE_NO_CURRENT = call_GET_VAR("USE_NO_CURRENT");

  double M_USE_REDUCE_DIM = call_GET_VAR("USE_REDUCE_DIM");

  double M_USE_NOT_REDUCE_DIM_PARTICLE =
      call_GET_VAR("USE_NOT_REDUCE_DIM_PARTICLE");

  double M_REDUCE_DIM_X_RAT = call_GET_VAR("REDUCE_DIM_X_RAT");

  double M_REDUCE_DIM_Y_RAT = call_GET_VAR("REDUCE_DIM_Y_RAT");

  double M_REDUCE_DIM_Z_RAT = call_GET_VAR("REDUCE_DIM_Z_RAT");

  double M_REDUCE_DIM_RANDOM_RATE = call_GET_VAR("REDUCE_DIM_RANDOM_RATE");

  double M_USE_SAME_RANDOM_SEED = call_GET_VAR("USE_SAME_RANDOM_SEED");

  if ((M_DELTA_X == 0)) {
    (M_DELTA_X = 1);

  } else {
    0;
  }

  if ((M_DELTA_Y == 0)) {
    (M_DELTA_Y = 1);

  } else {
    0;
  }

  if ((M_DELTA_Z == 0)) {
    (M_DELTA_Z = 1);

  } else {
    0;
  }

  (srand_seed = (rank + 1));
  long local_seed =
      (rank +
       (1 + ((M_USE_TIME_AS_RANDOM_SEED) ? (time(NULL)) : (M_RAND_SEED))));

  if ((!M_USE_SAME_RANDOM_SEED)) {
    srand(srand_seed);

  } else {
    (srand_seed = local_seed);
  }

  long tids[(num_runtime * n)];
  int64_t *local_tid_array = malloc((sizeof(int64_t) * numt));

  Field3D_MPI testfield;

  Field3D_MPI *ptestfield = &(testfield);

  Field3D_MPI testfieldSPEC;

  Field3D_MPI *ptestfieldSPEC = &(testfieldSPEC);

  Field3D_Seq fstest;

  Field3D_Seq fstestSPEC;

  Field3D_Seq *pfstestSPEC = &(fstestSPEC);

  Field3D_Seq *pfstest = &(fstest);

  int cd_types[NUM_MAX_RUNTIME];
  int dev_ids[NUM_MAX_RUNTIME];
  int cd_performances[NUM_MAX_RUNTIME];
  double G_GAPSIO_VERSION = call_GET_VAR("GAPSIO_VERSION");

  double G_GAPSIO_NUM_REDUCEWRITE = call_GET_VAR("GAPSIO_NUM_REDUCEWRITE");

  double G_OVERLAP_LEN = call_GET_VAR("OVERLAP_LEN");

  double G_USE_PML_ABC_DIR = call_GET_VAR("USE_PML_ABC_DIR");

  double G_PML_LEVEL = call_GET_VAR("PML_LEVEL");

  double G_PML_SIGMA_MAX = call_GET_VAR("PML_SIGMA_MAX");

  double G_USE_DIFFERENT_DEV_PERFORMANCE =
      call_GET_VAR("USE_DIFFERENT_DEV_PERFORMANCE");

  if ((G_GAPSIO_VERSION < 2)) {
    (G_GAPSIO_NUM_REDUCEWRITE = 0);

  } else {
    0;
  }

  {
    long i = 0;

    for (i = 0; i < NUM_RUNTIME; i++) {
      ((cd_types)[i] = call_GET_DEV_TYPE(i, rank));
      ((dev_ids)[i] = call_GET_DEV_ID(i, rank));
      ((cd_performances)[i] =
           ((G_USE_DIFFERENT_DEV_PERFORMANCE)
                ? (call_CAL_FUN_ONE_PARA("GET_DEV_PERFORMANCE", i))
                : (1)));
    }
  }
  fprintf(stderr, "rank %d init, pid=%d\n", rank, getpid());
  memset(pfstest, 0, sizeof(Field3D_Seq));
  long fieldlen = 3;

  int overlap_len = 2;

  if ((G_OVERLAP_LEN != 0)) {
    (overlap_len = G_OVERLAP_LEN);

  } else {
    0;
  }

  if ((rank == 0)) {
    fprintf(stderr, "overlap=%d\n", overlap_len);

  } else {
    0;
  }

  long allxyzmax[3];
  set_Field3D_Seq(pfstest, NULL, M_DELTA_X, M_DELTA_Y, M_DELTA_Z, XMAX, YMAX,
                  ZMAX, 2, overlap_len, fieldlen, 0, len_hilbert, len_hilbert,
                  len_hilbert, rank);
  ((allxyzmax)[0] = (len_hilbert * XMAX));
  ((allxyzmax)[1] = (len_hilbert * YMAX));
  ((allxyzmax)[2] = (len_hilbert * ZMAX));
  (fstestSPEC = fstest);
  ((pfstestSPEC)->num_ele = (7 * NUM_SPEC));
  init_Field3D_MPI_ALL(ptestfield, pfstest, n_hilbert, NUM_N_HILBERT_DIMENSION,
                       0, tids, local_tid_array, cd_types, dev_ids,
                       cd_performances, num_runtime, PS_MPI_COMM_WORLD, rank,
                       n);
  init_Field3D_MPI_from_new_num_ele(ptestfieldSPEC, ptestfield, (7 * NUM_SPEC));
  double tbeg = wclk_now();

  double tend = tbeg;

  double *pnpm = malloc((sizeof(double) * NUM_SPEC));

  {
    long i;

    for ((i = 0); (i < NUM_SPEC); (i = (i + 1))) {
      ((pnpm)[i] = call_GET_NPM(i));
    }
  }
  double *pchg = malloc((sizeof(double) * NUM_SPEC));

  {
    long i;

    for ((i = 0); (i < NUM_SPEC); (i = (i + 1))) {
      ((pchg)[i] = call_GET_CHARGE(i));
    }
  }
  double *pmass = malloc((sizeof(double) * NUM_SPEC));

  {
    long i;

    for ((i = 0); (i < NUM_SPEC); (i = (i + 1))) {
      ((pmass)[i] = call_GET_MASS(i));
    }
  }
  long *pgcache = malloc((sizeof(long) * NUM_SPEC));

  {
    long i;

    for ((i = 0); (i < NUM_SPEC); (i = (i + 1))) {
      ((pgcache)[i] = call_GET_GRID_CACHE_LEN(i));
    }
  }
  long *pcucache = malloc((sizeof(long) * NUM_SPEC));

  {
    long i;

    for ((i = 0); (i < NUM_SPEC); (i = (i + 1))) {
      ((pcucache)[i] = call_GET_CU_CACHE_LEN(i));
    }
  }
  Particle_in_Cell_MPI pis;

  Particle_in_Cell_MPI *ppis = &(pis);

  double M_USE_SMALL_NUM_GRIDS = call_GET_VAR("USE_SMALL_NUM_GRIDS");

  double M_NUM_MULTI_STEP_SORT = call_GET_VAR("NUM_MULTI_STEP_SORT");

  int num_multi_step_sort =
      (((M_NUM_MULTI_STEP_SORT == 0)) ? (1) : (M_NUM_MULTI_STEP_SORT));

  assert((num_multi_step_sort > 0));
  double T_TORI_X0 = call_GET_VAR("TORI_X0");

  double T_TORI_SOLVE_ERR = call_GET_VAR("TORI_SOLVE_ERR");

  int *p_particle_type = malloc((sizeof(int) * NUM_SPEC));

  {
    long i;

    for ((i = 0); (i < NUM_SPEC); (i = (i + 1))) {
      ((p_particle_type)[i] = 0);
    }
  }
  init_global_particles(
      ppis, ptestfield, ptestfield, ptestfieldSPEC, M_USE_SMALL_NUM_GRIDS,
      G_USE_PML_ABC_DIR, G_PML_LEVEL, G_PML_SIGMA_MAX, DELTAT, NUM_SPEC,
      allxyzmax, pmass, pchg, pnpm, pgcache, pcucache, p_particle_type,
      M_USE_REDUCE_DIM, M_REDUCE_DIM_X_RAT, M_REDUCE_DIM_Y_RAT,
      M_REDUCE_DIM_Z_RAT, M_REDUCE_DIM_RANDOM_RATE, M_USE_VLO, 0);
  double M_INIT_VMAX = call_GET_VAR("INIT_VMAX");

  if ((M_INIT_VMAX == 0)) {
    (M_INIT_VMAX = 1);

  } else {
    0;
  }

  init_non_uni_particle_fmpi(&((ppis)->MPI_fieldE), M_INIT_VMAX);
  Gaps_IO_DataFile gid;

  Gaps_IO_DataFile *pgid = &(gid);

  Gaps_IO_DataFile gidj;

  Gaps_IO_DataFile *pgidj = &(gidj);

  Gaps_IO_DataFile gide;

  Gaps_IO_DataFile *pgide = &(gide);

  double M_USE_OUTPUT_PERFORMANCE = call_GET_VAR("USE_OUTPUT_PERFORMANCE");

  {
    long t = 0;

    long tsave = 0;

    fprintf(stderr, "tsave=%ld\n", tsave);
    init_parallel_file_for_mpi_fields(ptestfield, pgid, "tmpEB", -1,
                                      G_GAPSIO_VERSION,
                                      G_GAPSIO_NUM_REDUCEWRITE);
    init_parallel_file_for_mpi_fields(ptestfield, pgidj, "tmpJ", -1,
                                      G_GAPSIO_VERSION,
                                      G_GAPSIO_NUM_REDUCEWRITE);
    init_parallel_file_for_mpi_fields(ptestfieldSPEC, pgide, "tmpEN", -1,
                                      G_GAPSIO_VERSION,
                                      G_GAPSIO_NUM_REDUCEWRITE);
    double tbeg = wclk_now();

    double tend = tbeg;

    for (0; t < NUM_TIMESTEP; t++) {
      if ((0 == (t % NUM_DUMP_TIMESTEP))) {
        if ((rank == 0)) {
          fprintf(stderr, "outputing...");

        } else {
          0;
        }

        if (M_USE_OUTPUT_PERFORMANCE) {
          PS_MPI_Barrier(PS_MPI_COMM_WORLD);

        } else {
          0;
        }

        double tbeg = wclk_now();

        sync_main_data_d2h(&(ppis->MPI_fieldB));
        sync_main_data_d2h(&(ppis->MPI_fieldE));
        sync_main_data_d2h(ppis->pMPI_FoutJ);
        mpi_field_write_to_file(&(ppis->MPI_fieldE), pgid, (tsave * 2));
        mpi_field_write_to_file(&(ppis->MPI_fieldB), pgid, ((tsave * 2) + 1));
        mpi_field_write_to_file(ppis->pMPI_FoutJ, pgidj, tsave);
        blas_yiszero_Field3D_MPI(ptestfieldSPEC, ptestfieldSPEC);
        dump_ene_num_mpi(ppis, 0);
        sync_main_data_d2h(ptestfieldSPEC);
        mpi_field_write_to_file(ptestfieldSPEC, pgide, tsave);
        GAPS_IO_FileFlush(pgid);
        GAPS_IO_FileFlush(pgidj);
        GAPS_IO_FileFlush(pgide);
        if (M_USE_OUTPUT_PERFORMANCE) {
          PS_MPI_Barrier(PS_MPI_COMM_WORLD);

        } else {
          0;
        }

        (tbeg = (wclk_now() - tbeg));
        if ((rank == 0)) {
          fprintf(stderr, "done, time used=%fs\n", tbeg);

        } else {
          0;
        }

        (tsave = (tsave + 1));

      } else {
        0;
      }

      // set B1=B
      blas_yisax_Field3D_MPI(&(ppis->MPI_fieldB1), &(ppis->MPI_fieldB1),
                             1.00000000000000000e+00, &(ppis->MPI_fieldB));
      MPI_YEE_CURL_R(&(ppis->MPI_fieldB1), &(ppis->MPI_fieldE), DELTAT);
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldE), &(ppis->MPI_fieldE), 1,
                            &(ppis->MPI_fieldE_ext));
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldB), &(ppis->MPI_fieldB), 1,
                            &(ppis->MPI_fieldB_ext));
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldB1), &(ppis->MPI_fieldB1), 1,
                            &(ppis->MPI_fieldB_ext));
      sync_ovlp_mpi_field(&(ppis->MPI_fieldE));
      sync_ovlp_mpi_field(&(ppis->MPI_fieldB));
      sync_ovlp_mpi_field(&(ppis->MPI_fieldB1));
      blas_yiszero_synced_Field3D_MPI(&(ppis->MPI_FoutJ), &(ppis->MPI_FoutJ));
      {

        // defined from class Particle_in_Cell_MPI
        Field3D_MPI MPI_fieldE = (ppis)->MPI_fieldE;

        Field3D_MPI MPI_fieldB = (ppis)->MPI_fieldB;

        Field3D_MPI MPI_fieldB1 = (ppis)->MPI_fieldB1;

        Field3D_MPI MPI_FoutJ = (ppis)->MPI_FoutJ;

        Field3D_MPI MPI_FoutJtmp = (ppis)->MPI_FoutJtmp;

        Field3D_MPI MPI_LFoutJ = (ppis)->MPI_LFoutJ;

        Field3D_MPI MPI_fieldEtmp = (ppis)->MPI_fieldEtmp;

        Field3D_MPI MPI_fieldBtmp = (ppis)->MPI_fieldBtmp;

        Field3D_MPI MPI_fieldEtmp1 = (ppis)->MPI_fieldEtmp1;

        Field3D_MPI MPI_fieldEtmp2 = (ppis)->MPI_fieldEtmp2;

        Field3D_MPI MPI_fieldE1 = (ppis)->MPI_fieldE1;

        Field3D_MPI MPI_fieldBtmp1 = (ppis)->MPI_fieldBtmp1;

        Field3D_MPI MPI_fieldPMLB = (ppis)->MPI_fieldPMLB;

        Field3D_MPI MPI_fieldPMLE = (ppis)->MPI_fieldPMLE;

        Field3D_MPI *pMPI_FoutJ = (ppis)->pMPI_FoutJ;

        Field3D_MPI *pMPI_FoutEN = (ppis)->pMPI_FoutEN;

        Field3D_MPI MPI_fieldE_ext = (ppis)->MPI_fieldE_ext;

        Field3D_MPI MPI_fieldB_ext = (ppis)->MPI_fieldB_ext;

        Field3D_MPI MPI_fieldE_filter = (ppis)->MPI_fieldE_filter;

        Field3D_MPI MPI_fieldB_filter = (ppis)->MPI_fieldB_filter;

        Field3D_MPI *pB0 = (ppis)->pB0;

        Field3D_MPI *pB1 = (ppis)->pB1;

        Field3D_MPI MPI_fieldE01_2x = (ppis)->MPI_fieldE01_2x;

        Field3D_MPI MPI_fieldB0_2x = (ppis)->MPI_fieldB0_2x;

        int use_pml_abc_dir = (ppis)->use_pml_abc_dir;

        int use_pml_level = (ppis)->use_pml_level;

        int use_small_grid = (ppis)->use_small_grid;

        int use_rel_ncr = (ppis)->use_rel_ncr;

        int use_vlo = (ppis)->use_vlo;

        long allxmax = (ppis)->allxmax;

        long allymax = (ppis)->allymax;

        long allzmax = (ppis)->allzmax;

        double use_pml_sigma_max = (ppis)->use_pml_sigma_max;

        double dt = (ppis)->dt;

        double tori_x0 = (ppis)->tori_x0;

        double solve_err = (ppis)->solve_err;

        int o_N_l = (ppis)->o_N_l;

        int o_N_M = (ppis)->o_N_M;

        double *o_pmass = (ppis)->o_pmass;

        double *o_pcharge = (ppis)->o_pcharge;

        int *o_particle_type = (ppis)->o_particle_type;

        int current_mask = (ppis)->current_mask;

        int use_tori = (ppis)->use_tori;

        void *pusher_fun = (ppis)->pusher_fun;

        //====================Particle_in_Cell_MPI
        Field3D_MPI *pMPI_fieldE = &(MPI_fieldE);

        Field3D_MPI *pMPI_fieldB = &(MPI_fieldB);

        MPI_geo_nr_Bfield_pushJ_vlo(
            ppis, pMPI_fieldE, pMPI_fieldB, &(MPI_fieldB1), pMPI_FoutJ, pmass,
            pchg, (5.00000000000000000e-01 * DELTAT), T_TORI_X0, 0, 0, 0, 0, 0);
      }
      // sort particle if it is the sort time-step
      if (((t % num_multi_step_sort) == 0)) {
        call_particle_sort_mpi(ppis, 0, 0);
        call_particle_sort_mpi(ppis, 1, 0);
        call_particle_sort_mpi(ppis, 2, 0);

      } else {
        0;
      }

      merge_ovlp_mpi_field(&(ppis->MPI_FoutJ));
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldE), &(ppis->MPI_fieldE), -1,
                            &(ppis->MPI_fieldE_ext));
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldB), &(ppis->MPI_fieldB), -1,
                            &(ppis->MPI_fieldB_ext));
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldB1), &(ppis->MPI_fieldB1), -1,
                            &(ppis->MPI_fieldB_ext));

      // add current to Electric field E
      blas_axpy_Field3D_MPI(&(ppis->MPI_fieldE), &(ppis->MPI_fieldE), -1,
                            &(ppis->MPI_FoutJ));
      MPI_GEO_YEE_CURL_L(&(ppis->MPI_fieldE), &(ppis->MPI_fieldB1), T_TORI_X0,
                         M_DELTA_X, M_DELTA_Y, M_DELTA_Z, DELTAT);

      // set B=B1
      blas_yisax_Field3D_MPI(&(ppis->MPI_fieldB), &(ppis->MPI_fieldB), 1,
                             &(ppis->MPI_fieldB1));
      if (((rank == 0) && (M_DISABLE_TS_LOG == 0))) {
        {
          double tnow = wclk_now();

          double tused = (tnow - tend);

          (tend = tnow);
          fprintf(stderr, "step=%ld time used=%fs, ips=%f, allips=%f\n", t,
                  tused, (1 / tused), ((t + 1) / (tend - tbeg)));
        }
      } else {
        0;
      }
    }
    GAPS_IO_DeleteDataInfo(pgid);
    if ((rank == 0)) {
      fprintf(stderr, "task complete: ");
      {
        long i;

        for ((i = 0); (i < argc); (i = (i + 1))) {
          fprintf(stderr, "%s ", (argv)[i]);
        }
      }
      fprintf(stderr, "\n");

    } else {
      0;
    }
  }
  if ((rank == 0)) {
    fprintf(stderr, "Calling Finalize\n");

  } else {
    0;
  }

  PS_MPI_Finalize();
  return 0;
}

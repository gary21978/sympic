#ifndef NCSPIC_SEQ_FIELD
#include "smallmpi/small_mpi.h"
#include <nccl.h> /* USENCCL */

#define NCSPIC_SEQ_FIELD
typedef double NUMBER_REAL;
#define NUM_SYNC_LAYER 27

#define NUM_SYNC_KERNEL 12

typedef struct {
  void *pe;

  int cuda_device; /* USENCCL */

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

  /* USENCCL precomputed local recv lists, per layer */
  long *local_recv_tid[NUM_SYNC_LAYER];       /* destination tid in swap buf */
  long *local_recv_src[NUM_SYNC_LAYER];       /* source tid (t0id for self, src_tid for peer) */
  int  *local_recv_peer[NUM_SYNC_LAYER];      /* src_runtime, -1 = self (same device) */
  long *local_recv_tid_d[NUM_SYNC_LAYER];
  long *local_recv_src_d[NUM_SYNC_LAYER];
  long  local_recv_count[NUM_SYNC_LAYER];
  long *remote_send_tid[NUM_SYNC_LAYER];      /* remote sends, preordered for NCCL matching */
  long  remote_send_count[NUM_SYNC_LAYER];
  long *remote_recv_tid[NUM_SYNC_LAYER];      /* remote recvs, preordered for NCCL matching */
  long  remote_recv_count[NUM_SYNC_LAYER];
  int   cache_valid;
  /* USENCCL end */

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

  /* USENCCL aggregated field-halo P2P plan.  Particle exchange keeps its own path. */
  long field_halo_send_seg_count;
  long field_halo_recv_seg_count;
  long *field_halo_send_src_d;
  long *field_halo_send_dst_d;
  long *field_halo_send_len_d;
  long *field_halo_recv_src_d;
  long *field_halo_recv_dst_d;
  long *field_halo_recv_len_d;
  int field_halo_send_peer_count;
  int field_halo_recv_peer_count;
  int *field_halo_send_peer;
  int *field_halo_recv_peer;
  long *field_halo_send_peer_offset;
  long *field_halo_recv_peer_offset;
  long *field_halo_send_peer_count_elems;
  long *field_halo_recv_peer_count_elems;
  double *field_halo_send_buf;
  double *field_halo_recv_buf;
  long field_halo_send_total_elems;
  long field_halo_recv_total_elems;
  /* USENCCL end */

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
  void *nonrel_test_kernel[1];
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

  void *dump_ene_num_kernel;

  void *inoutput;

  void *xyzw;

  void *cu_cache;

  void *cu_xyzw;

  void *adjoint_vec_pids;

  void *swap_len_buf; /* USENCCL */

} One_Particle_Collection;
typedef struct {
  Field3D_Seq *data;

  long num_runtime;

  PS_MPI_Comm comm;

  ncclComm_t *nccl_comm; /* USENCCL */

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

#else

#endif

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <assert.h>

#include "pubdefs.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"

#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"

#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

#include "space_filling_curve.h"

#include "mpifields.h"

#include "sync_fields.h"


int set_Field3D_Seq(Field3D_Seq *pthis, void *pe, double delta_x, double delta_y, double delta_z, long xlen, long ylen,
                    long zlen, long numvec, int ovlp, int num_ele, int CD_type, long x_num_thread_block,
                    long y_num_thread_block, long z_num_thread_block, long global_pid) {
  ((pthis)->pe = pe);
  ((pthis)->delta_x = delta_x);
  ((pthis)->delta_y = delta_y);
  ((pthis)->delta_z = delta_z);
  ((pthis)->xlen = xlen);
  ((pthis)->ylen = ylen);
  ((pthis)->zlen = zlen);
  ((pthis)->numvec = numvec);
  ((pthis)->ovlp = ovlp);
  ((pthis)->num_ele = num_ele);
  ((pthis)->CD_type = CD_type);
  ((pthis)->x_num_thread_block = x_num_thread_block);
  ((pthis)->y_num_thread_block = y_num_thread_block);
  ((pthis)->z_num_thread_block = z_num_thread_block);
  ((pthis)->global_pid = global_pid);
  ((pthis)->xblock = (xlen + (2 * ovlp)));
  ((pthis)->yblock = (ylen + (2 * ovlp)));
  ((pthis)->zblock = (zlen + (2 * ovlp)));
  return 0;
}

int cuda_alloc_Field3D_Seq(Field3D_Seq *pthis, int is_init_kernels) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;

  long xlen = (pthis)->xlen;

  long ylen = (pthis)->ylen;

  long zlen = (pthis)->zlen;

  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;


  //====================Field3D_Seq
  ((pthis)->global_id = malloc((sizeof(long) * numvec)));
  ((pthis)->global_x_offset = malloc((sizeof(long) * numvec)));
  ((pthis)->global_y_offset = malloc((sizeof(long) * numvec)));
  ((pthis)->global_z_offset = malloc((sizeof(long) * numvec)));
  ((pthis)->adj_ids = malloc((sizeof(long) * (NUM_SYNC_LAYER * numvec))));
  ((pthis)->adj_local_tid = malloc((sizeof(long) * (NUM_SYNC_LAYER * numvec))));
  ((pthis)->adj_processes = malloc((sizeof(long) * (NUM_SYNC_LAYER * numvec))));
  /* USENCCL local recv cache */
  pthis->cache_valid = 0;
  for (int _li = 0; _li < NUM_SYNC_LAYER; _li++) {
    pthis->local_recv_tid[_li] = NULL;
    pthis->local_recv_src[_li] = NULL;
    pthis->local_recv_peer[_li] = NULL;
    pthis->local_recv_tid_d[_li] = NULL;
    pthis->local_recv_src_d[_li] = NULL;
    pthis->local_recv_count[_li] = 0;
    pthis->remote_send_tid[_li] = NULL;
    pthis->remote_send_count[_li] = 0;
    pthis->remote_recv_tid[_li] = NULL;
    pthis->remote_recv_count[_li] = 0;
  }
  /* USENCCL aggregated field-halo P2P plan */
  pthis->field_halo_send_seg_count = 0;
  pthis->field_halo_recv_seg_count = 0;
  pthis->field_halo_send_src_d = NULL;
  pthis->field_halo_send_dst_d = NULL;
  pthis->field_halo_send_len_d = NULL;
  pthis->field_halo_recv_src_d = NULL;
  pthis->field_halo_recv_dst_d = NULL;
  pthis->field_halo_recv_len_d = NULL;
  pthis->field_halo_send_peer_count = 0;
  pthis->field_halo_recv_peer_count = 0;
  pthis->field_halo_send_peer = NULL;
  pthis->field_halo_recv_peer = NULL;
  pthis->field_halo_send_peer_offset = NULL;
  pthis->field_halo_recv_peer_offset = NULL;
  pthis->field_halo_send_peer_count_elems = NULL;
  pthis->field_halo_recv_peer_count_elems = NULL;
  pthis->field_halo_send_buf = NULL;
  pthis->field_halo_recv_buf = NULL;
  pthis->field_halo_send_total_elems = 0;
  pthis->field_halo_recv_total_elems = 0;
  /* USENCCL end */
  int i;

  if (is_init_kernels) {
    ((pthis)->blas_yiszero_synced_kernel = malloc((sizeof(cuda_blas_yiszero_synced_struct))));
    cuda_blas_yiszero_synced_init(pe, (pthis)->blas_yiszero_synced_kernel);

    ((pthis)->blas_mulxy_numele3_kernel = malloc((sizeof(cuda_blas_mulxy_numele3_struct))));
    cuda_blas_mulxy_numele3_init(pe, (pthis)->blas_mulxy_numele3_kernel);

    ((pthis)->blas_yiszero_kernel = malloc((sizeof(cuda_blas_yiszero_struct))));
    cuda_blas_yiszero_init(pe, (pthis)->blas_yiszero_kernel);

    ((pthis)->blas_yiszero_full_block_kernel = malloc((sizeof(cuda_blas_yiszero_full_block_struct))));
    cuda_blas_yiszero_full_block_init(pe, (pthis)->blas_yiszero_full_block_kernel);

    ((pthis)->blas_yisconst_kernel = malloc((sizeof(cuda_blas_yisconst_struct))));
    cuda_blas_yisconst_init(pe, (pthis)->blas_yisconst_kernel);

    ((pthis)->blas_yisconst_full_block_kernel = malloc((sizeof(cuda_blas_yisconst_full_block_struct))));
    cuda_blas_yisconst_full_block_init(pe, (pthis)->blas_yisconst_full_block_kernel);

    ((pthis)->blas_get_ITG_Potential_kernel = malloc((sizeof(cuda_blas_get_ITG_Potential_struct))));
    cuda_blas_get_ITG_Potential_init(pe, (pthis)->blas_get_ITG_Potential_kernel);

    ((pthis)->blas_get_ITG_Potential_full_block_kernel =
         malloc((sizeof(cuda_blas_get_ITG_Potential_full_block_struct))));
    cuda_blas_get_ITG_Potential_full_block_init(pe, (pthis)->blas_get_ITG_Potential_full_block_kernel);

    ((pthis)->blas_invy_kernel = malloc((sizeof(cuda_blas_invy_struct))));
    cuda_blas_invy_init(pe, (pthis)->blas_invy_kernel);

    ((pthis)->blas_invy_full_block_kernel = malloc((sizeof(cuda_blas_invy_full_block_struct))));
    cuda_blas_invy_full_block_init(pe, (pthis)->blas_invy_full_block_kernel);

    ((pthis)->blas_axpby_kernel = malloc((sizeof(cuda_blas_axpby_struct))));
    cuda_blas_axpby_init(pe, (pthis)->blas_axpby_kernel);

    ((pthis)->blas_axpby_full_block_kernel = malloc((sizeof(cuda_blas_axpby_full_block_struct))));
    cuda_blas_axpby_full_block_init(pe, (pthis)->blas_axpby_full_block_kernel);

    ((pthis)->blas_axpy_kernel = malloc((sizeof(cuda_blas_axpy_struct))));
    cuda_blas_axpy_init(pe, (pthis)->blas_axpy_kernel);

    ((pthis)->blas_axpy_full_block_kernel = malloc((sizeof(cuda_blas_axpy_full_block_struct))));
    cuda_blas_axpy_full_block_init(pe, (pthis)->blas_axpy_full_block_kernel);

    ((pthis)->blas_yisax_kernel = malloc((sizeof(cuda_blas_yisax_struct))));
    cuda_blas_yisax_init(pe, (pthis)->blas_yisax_kernel);

    ((pthis)->blas_yisax_full_block_kernel = malloc((sizeof(cuda_blas_yisax_full_block_struct))));
    cuda_blas_yisax_full_block_init(pe, (pthis)->blas_yisax_full_block_kernel);

    ((pthis)->blas_mulxy_kernel = malloc((sizeof(cuda_blas_mulxy_struct))));
    cuda_blas_mulxy_init(pe, (pthis)->blas_mulxy_kernel);

    ((pthis)->blas_mulxy_full_block_kernel = malloc((sizeof(cuda_blas_mulxy_full_block_struct))));
    cuda_blas_mulxy_full_block_init(pe, (pthis)->blas_mulxy_full_block_kernel);

    ((pthis)->blas_findmax_kernel = malloc((sizeof(cuda_blas_findmax_struct))));
    cuda_blas_findmax_init(pe, (pthis)->blas_findmax_kernel);

    ((pthis)->blas_findmax_full_block_kernel = malloc((sizeof(cuda_blas_findmax_full_block_struct))));
    cuda_blas_findmax_full_block_init(pe, (pthis)->blas_findmax_full_block_kernel);

    ((pthis)->blas_dot_kernel = malloc((sizeof(cuda_blas_dot_struct))));
    cuda_blas_dot_init(pe, (pthis)->blas_dot_kernel);

    ((pthis)->blas_dot_full_block_kernel = malloc((sizeof(cuda_blas_dot_full_block_struct))));
    cuda_blas_dot_full_block_init(pe, (pthis)->blas_dot_full_block_kernel);

    ((pthis)->blas_sum_kernel = malloc((sizeof(cuda_blas_sum_struct))));
    cuda_blas_sum_init(pe, (pthis)->blas_sum_kernel);

    ((pthis)->blas_sum_full_block_kernel = malloc((sizeof(cuda_blas_sum_full_block_struct))));
    cuda_blas_sum_full_block_init(pe, (pthis)->blas_sum_full_block_kernel);

    ((pthis)->blas_yisax_shrink_kernel = malloc((sizeof(cuda_blas_yisax_shrink_struct))));
    cuda_blas_yisax_shrink_init(pe, (pthis)->blas_yisax_shrink_kernel);

    ((pthis)->blas_yisax_enlarge_kernel = malloc((sizeof(cuda_blas_yisax_enlarge_struct))));
    cuda_blas_yisax_enlarge_init(pe, (pthis)->blas_yisax_enlarge_kernel);

    ((pthis)->blas_axpy_shrink_kernel = malloc((sizeof(cuda_blas_axpy_shrink_struct))));
    cuda_blas_axpy_shrink_init(pe, (pthis)->blas_axpy_shrink_kernel);

    ((pthis)->blas_axpy_enlarge_kernel = malloc((sizeof(cuda_blas_axpy_enlarge_struct))));
    cuda_blas_axpy_enlarge_init(pe, (pthis)->blas_axpy_enlarge_kernel);

    ((pthis)->blas_axpby_shrink_kernel = malloc((sizeof(cuda_blas_axpby_shrink_struct))));
    cuda_blas_axpby_shrink_init(pe, (pthis)->blas_axpby_shrink_kernel);

    ((pthis)->blas_axpby_enlarge_kernel = malloc((sizeof(cuda_blas_axpby_enlarge_struct))));
    cuda_blas_axpby_enlarge_init(pe, (pthis)->blas_axpby_enlarge_kernel);
  }

  size_t ovleal_aio = 0;

  for (i = 0; (i < NUM_SYNC_LAYER); i++) {
    int locali = i;

    long bxyzx = (locali % 3);

    long bxyzy = ((locali / 3) % 3);

    long bxyzz = (locali / (3 * 3));

    long ovlpxmax = xlen;

    long ovlpymax = ylen;

    long ovlpzmax = zlen;

    if ((bxyzx != 1)) {
      (ovlpxmax = ovlp);
    }

    if ((bxyzy != 1)) {
      (ovlpymax = ovlp);
    }

    if ((bxyzz != 1)) {
      (ovlpzmax = ovlp);
    }

    int ismiddle = (((bxyzx == 1) && (bxyzy == 1)) && (bxyzz == 1));

    if (ismiddle) {
      (ovlpxmax = xblock);
      (ovlpymax = yblock);
      (ovlpzmax = zblock);
    }

    size_t ovlp_all_len = (ovlpxmax * (ovlpymax * (ovlpzmax * (num_ele * numvec))));

    (((pthis)->sync_layer_pscmc)[i] = malloc((sizeof(cuda_pscmc_mem) * 1)));
    (((pthis)->swap_layer_pscmc)[i] = malloc((sizeof(cuda_pscmc_mem) * 1)));
    if ((1 && (!ismiddle))) {
      (ovleal_aio = (ovleal_aio + ovlp_all_len));

    } else {
      cuda_pscmc_mem_init(pe, ((pthis)->sync_layer_pscmc)[i], PS_DOUBLE_NUM, ovlp_all_len);
      cuda_pscmc_mem_init(pe, ((pthis)->swap_layer_pscmc)[i], PS_DOUBLE_NUM, ovlp_all_len);
    }
  }
  cuda_pscmc_mem_init(pe, ((pthis)->sync_layer_pscmc)[0], PS_DOUBLE_NUM, ovleal_aio);
  cuda_pscmc_mem_init(pe, ((pthis)->swap_layer_pscmc)[0], PS_DOUBLE_NUM, ovleal_aio);
  ((pthis)->main_data = ((pthis)->sync_layer_pscmc)[(NUM_SYNC_LAYER / 2)]);
  ((pthis)->rdcd = malloc((sizeof(cuda_pscmc_mem) * 1)));
  cuda_pscmc_mem_init(pe, (pthis)->rdcd, PS_DOUBLE_NUM, numvec);
  ((pthis)->rdcd_host = cuda_pscmc_get_h_data((pthis)->rdcd, NULL));
  if (is_init_kernels) {
    {
      size_t structlen;

      cuda_YEE_CURL_R_get_struct_len(&(structlen));
      (((pthis)->geo_yeefdtd_kernels)[0] = malloc(structlen));
      cuda_YEE_CURL_R_init(pe, ((pthis)->geo_yeefdtd_kernels)[0]);
    }
    {
      size_t structlen;

      cuda_GEO_YEE_CURL_L_get_struct_len(&(structlen));
      (((pthis)->geo_yeefdtd_kernels)[1] = malloc(structlen));
      cuda_GEO_YEE_CURL_L_init(pe, ((pthis)->geo_yeefdtd_kernels)[1]);
    }
    {
      size_t structlen;

      cuda_merge_ovlp_m2o_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[0] = malloc(structlen));
    }
    cuda_merge_ovlp_m2o_init(pe, ((pthis)->sync_kernels)[0]);
    {
      size_t structlen;

      cuda_merge_ovlp_m2o_once_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[1] = malloc(structlen));
    }
    cuda_merge_ovlp_m2o_once_init(pe, ((pthis)->sync_kernels)[1]);
    {
      size_t structlen;

      cuda_merge_ovlp_m2o_all_in_one_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[2] = malloc(structlen));
    }
    cuda_merge_ovlp_m2o_all_in_one_init(pe, ((pthis)->sync_kernels)[2]);
    {
      size_t structlen;

      cuda_merge_ovlp_o2m_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[3] = malloc(structlen));
    }
    cuda_merge_ovlp_o2m_init(pe, ((pthis)->sync_kernels)[3]);
    {
      size_t structlen;

      cuda_merge_ovlp_o2m_once_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[4] = malloc(structlen));
    }
    cuda_merge_ovlp_o2m_once_init(pe, ((pthis)->sync_kernels)[4]);
    {
      size_t structlen;

      cuda_merge_ovlp_o2m_all_in_one_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[5] = malloc(structlen));
    }
    cuda_merge_ovlp_o2m_all_in_one_init(pe, ((pthis)->sync_kernels)[5]);
    {
      size_t structlen;

      cuda_sync_ovlp_m2o_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[6] = malloc(structlen));
    }
    cuda_sync_ovlp_m2o_init(pe, ((pthis)->sync_kernels)[6]);
    {
      size_t structlen;

      cuda_sync_ovlp_m2o_once_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[7] = malloc(structlen));
    }
    cuda_sync_ovlp_m2o_once_init(pe, ((pthis)->sync_kernels)[7]);
    {
      size_t structlen;

      cuda_sync_ovlp_m2o_all_in_one_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[8] = malloc(structlen));
    }
    cuda_sync_ovlp_m2o_all_in_one_init(pe, ((pthis)->sync_kernels)[8]);
    {
      size_t structlen;

      cuda_sync_ovlp_o2m_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[9] = malloc(structlen));
    }
    cuda_sync_ovlp_o2m_init(pe, ((pthis)->sync_kernels)[9]);
    {
      size_t structlen;

      cuda_sync_ovlp_o2m_once_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[10] = malloc(structlen));
    }
    cuda_sync_ovlp_o2m_once_init(pe, ((pthis)->sync_kernels)[10]);
    {
      size_t structlen;

      cuda_sync_ovlp_o2m_all_in_one_get_struct_len(&(structlen));
      (((pthis)->sync_kernels)[11] = malloc(structlen));
    }
    cuda_sync_ovlp_o2m_all_in_one_init(pe, ((pthis)->sync_kernels)[11]);
    ((pthis)->cur_rankx_pscmc = malloc((sizeof(cuda_pscmc_mem) * 1)));
    cuda_pscmc_mem_init(pe, (pthis)->cur_rankx_pscmc, PS_INT_NUM, numvec);
    ((pthis)->xoffset = malloc((sizeof(cuda_pscmc_mem) * 1)));
    cuda_pscmc_mem_init(pe, (pthis)->xoffset, PS_INT_NUM, numvec);
    ((pthis)->cur_ranky_pscmc = malloc((sizeof(cuda_pscmc_mem) * 1)));
    cuda_pscmc_mem_init(pe, (pthis)->cur_ranky_pscmc, PS_INT_NUM, numvec);
    ((pthis)->yoffset = malloc((sizeof(cuda_pscmc_mem) * 1)));
    cuda_pscmc_mem_init(pe, (pthis)->yoffset, PS_INT_NUM, numvec);
    ((pthis)->cur_rankz_pscmc = malloc((sizeof(cuda_pscmc_mem) * 1)));
    cuda_pscmc_mem_init(pe, (pthis)->cur_rankz_pscmc, PS_INT_NUM, numvec);
    ((pthis)->zoffset = malloc((sizeof(cuda_pscmc_mem) * 1)));
    cuda_pscmc_mem_init(pe, (pthis)->zoffset, PS_INT_NUM, numvec);
  }

  return 0;
}

int cuda_Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;


  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;

  void **sync_layer_pscmc = (pthis)->sync_layer_pscmc;

  void **swap_layer_pscmc = (pthis)->swap_layer_pscmc;

  void **sync_kernels = (pthis)->sync_kernels;


  void *main_data = (pthis)->main_data;


  //====================Field3D_Seq
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
      (sync_kernels)[2], (((is_sync_layer) ? (sync_layer_pscmc) : (swap_layer_pscmc)))[0]);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain((sync_kernels)[2], main_data);
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec((sync_kernels)[2], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele((sync_kernels)[2], &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock((sync_kernels)[2], &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock((sync_kernels)[2], &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock((sync_kernels)[2], &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp((sync_kernels)[2], &(cuda_alloc_prefix_ovlp));
  cuda_merge_ovlp_m2o_all_in_one_exec((sync_kernels)[2], cuda_merge_ovlp_m2o_all_in_one_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
}

int cuda_Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;


  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;

  void **sync_layer_pscmc = (pthis)->sync_layer_pscmc;

  void **swap_layer_pscmc = (pthis)->swap_layer_pscmc;

  void **sync_kernels = (pthis)->sync_kernels;


  void *main_data = (pthis)->main_data;


  //====================Field3D_Seq
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
      (sync_kernels)[5], (((is_sync_layer) ? (sync_layer_pscmc) : (swap_layer_pscmc)))[0]);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain((sync_kernels)[5], main_data);
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec((sync_kernels)[5], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele((sync_kernels)[5], &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock((sync_kernels)[5], &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock((sync_kernels)[5], &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock((sync_kernels)[5], &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp((sync_kernels)[5], &(cuda_alloc_prefix_ovlp));
  cuda_merge_ovlp_o2m_all_in_one_exec((sync_kernels)[5], cuda_merge_ovlp_o2m_all_in_one_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
}

int cuda_Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;


  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;

  void **sync_layer_pscmc = (pthis)->sync_layer_pscmc;

  void **swap_layer_pscmc = (pthis)->swap_layer_pscmc;

  void **sync_kernels = (pthis)->sync_kernels;


  void *main_data = (pthis)->main_data;


  //====================Field3D_Seq
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
      (sync_kernels)[8], (((is_sync_layer) ? (sync_layer_pscmc) : (swap_layer_pscmc)))[0]);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain((sync_kernels)[8], main_data);
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec((sync_kernels)[8], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele((sync_kernels)[8], &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock((sync_kernels)[8], &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock((sync_kernels)[8], &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock((sync_kernels)[8], &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp((sync_kernels)[8], &(cuda_alloc_prefix_ovlp));
  cuda_sync_ovlp_m2o_all_in_one_exec((sync_kernels)[8], cuda_sync_ovlp_m2o_all_in_one_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
}

int cuda_Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;


  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;

  void **sync_layer_pscmc = (pthis)->sync_layer_pscmc;

  void **swap_layer_pscmc = (pthis)->swap_layer_pscmc;

  void **sync_kernels = (pthis)->sync_kernels;


  void *main_data = (pthis)->main_data;


  //====================Field3D_Seq
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
      (sync_kernels)[11], (((is_sync_layer) ? (sync_layer_pscmc) : (swap_layer_pscmc)))[0]);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain((sync_kernels)[11], main_data);
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec((sync_kernels)[11], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele((sync_kernels)[11], &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock((sync_kernels)[11], &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock((sync_kernels)[11], &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock((sync_kernels)[11], &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp((sync_kernels)[11], &(cuda_alloc_prefix_ovlp));
  cuda_sync_ovlp_o2m_all_in_one_exec((sync_kernels)[11], cuda_sync_ovlp_o2m_all_in_one_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
}
int cuda_Field3D_Seq_YEE_CURL_R(Field3D_Seq *pthis, Field3D_Seq *inB0, double DT) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;

  long xlen = (pthis)->xlen;

  long ylen = (pthis)->ylen;

  long zlen = (pthis)->zlen;

  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;


  void **geo_yeefdtd_kernels = (pthis)->geo_yeefdtd_kernels;


  void *xoffset = (pthis)->xoffset;

  void *yoffset = (pthis)->yoffset;

  void *zoffset = (pthis)->zoffset;


  void *main_data = (pthis)->main_data;


  //====================Field3D_Seq
  cuda_YEE_CURL_R_scmc_set_parameter_inoutE1((geo_yeefdtd_kernels)[0], main_data);
  cuda_YEE_CURL_R_scmc_set_parameter_inB0((geo_yeefdtd_kernels)[0], (inB0)->main_data);
  cuda_YEE_CURL_R_scmc_set_parameter_xoffset((geo_yeefdtd_kernels)[0], xoffset);
  cuda_YEE_CURL_R_scmc_set_parameter_yoffset((geo_yeefdtd_kernels)[0], yoffset);
  cuda_YEE_CURL_R_scmc_set_parameter_zoffset((geo_yeefdtd_kernels)[0], zoffset);
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_YEE_CURL_R_scmc_set_parameter_num_ele((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_YEE_CURL_R_scmc_set_parameter_y_cpu_core((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_YEE_CURL_R_scmc_set_parameter_numvec((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_YEE_CURL_R_scmc_set_parameter_XLEN((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_YEE_CURL_R_scmc_set_parameter_YLEN((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_YEE_CURL_R_scmc_set_parameter_ZLEN((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_YEE_CURL_R_scmc_set_parameter_ovlp((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_YEE_CURL_R_scmc_set_parameter_xblock((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_YEE_CURL_R_scmc_set_parameter_yblock((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_YEE_CURL_R_scmc_set_parameter_zblock((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_DT;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DT), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DT).h_data))[0] = DT);
  cuda_YEE_CURL_R_scmc_set_parameter_DT((geo_yeefdtd_kernels)[0], &(cuda_alloc_prefix_DT));
  cuda_YEE_CURL_R_exec((geo_yeefdtd_kernels)[0], cuda_YEE_CURL_R_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DT));
  return 0;
}
int cuda_Field3D_Seq_GEO_YEE_CURL_L(Field3D_Seq *pthis, Field3D_Seq *inB0, double x0, double DELTA_X, double DELTA_Y,
                                    double DELTA_Z, double DT) {

  // defined from class Field3D_Seq
  void *pe = (pthis)->pe;

  long xlen = (pthis)->xlen;

  long ylen = (pthis)->ylen;

  long zlen = (pthis)->zlen;

  long xblock = (pthis)->xblock;

  long yblock = (pthis)->yblock;

  long zblock = (pthis)->zblock;

  long numvec = (pthis)->numvec;


  int ovlp = (pthis)->ovlp;

  int num_ele = (pthis)->num_ele;


  void **geo_yeefdtd_kernels = (pthis)->geo_yeefdtd_kernels;


  void *xoffset = (pthis)->xoffset;

  void *yoffset = (pthis)->yoffset;

  void *zoffset = (pthis)->zoffset;


  void *main_data = (pthis)->main_data;


  //====================Field3D_Seq
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1((geo_yeefdtd_kernels)[1], main_data);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_inB0((geo_yeefdtd_kernels)[1], (inB0)->main_data);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_xoffset((geo_yeefdtd_kernels)[1], xoffset);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_yoffset((geo_yeefdtd_kernels)[1], yoffset);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_zoffset((geo_yeefdtd_kernels)[1], zoffset);
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_num_ele((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_numvec((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_XLEN((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_YLEN((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_ovlp((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_xblock((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_yblock((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_zblock((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_x0;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_x0), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_x0).h_data))[0] = x0);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_x0((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_x0));
  cuda_pscmc_mem cuda_alloc_prefix_DELTA_X;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_X), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DELTA_X).h_data))[0] = DELTA_X);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_DELTA_X));
  cuda_pscmc_mem cuda_alloc_prefix_DELTA_Y;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_Y), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DELTA_Y).h_data))[0] = DELTA_Y);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_DELTA_Y));
  cuda_pscmc_mem cuda_alloc_prefix_DELTA_Z;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DELTA_Z), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DELTA_Z).h_data))[0] = DELTA_Z);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_DELTA_Z));
  cuda_pscmc_mem cuda_alloc_prefix_DT;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_DT), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_DT).h_data))[0] = DT);
  cuda_GEO_YEE_CURL_L_scmc_set_parameter_DT((geo_yeefdtd_kernels)[1], &(cuda_alloc_prefix_DT));
  cuda_GEO_YEE_CURL_L_exec((geo_yeefdtd_kernels)[1], cuda_GEO_YEE_CURL_L_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_x0));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_X));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_Y));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DELTA_Z));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_DT));
  return 0;
}

int alloc_Field3D_Seq(Field3D_Seq *pthis, int is_init_kernels) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_alloc_Field3D_Seq(pthis, is_init_kernels);

  return 0;
}

int Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one(pthis, is_sync_layer);

  return 0;
}

int Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one(pthis, is_sync_layer);

  return 0;
}

int Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one(pthis, is_sync_layer);

  return 0;
}

int Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one(pthis, is_sync_layer);

  return 0;
}

int Field3D_Seq_YEE_CURL_R(Field3D_Seq *pthis, Field3D_Seq *inB0, double DT) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_Field3D_Seq_YEE_CURL_R(pthis, inB0, DT);

  return 0;
}
int MPI_YEE_CURL_R(Field3D_MPI *pthis, Field3D_MPI *inB0, double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inB0);
  for (i = 0; (i < num_runtime); i++) {
    cudaSetDevice((data + i)->cuda_device);
    Field3D_Seq_YEE_CURL_R((data + i), ((inB0)->data + i), DT);
  }
  return 0;
}
int Field3D_Seq_GEO_YEE_CURL_L(Field3D_Seq *pthis, Field3D_Seq *inB0, double x0, double DELTA_X, double DELTA_Y,
                               double DELTA_Z, double DT) {

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  cuda_Field3D_Seq_GEO_YEE_CURL_L(pthis, inB0, x0, DELTA_X, DELTA_Y, DELTA_Z, DT);

  return 0;
}
int MPI_GEO_YEE_CURL_L(Field3D_MPI *pthis, Field3D_MPI *inB0, double x0, double DELTA_X, double DELTA_Y, double DELTA_Z,
                       double DT) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  long i = 0;

  sync_ovlp_mpi_field(inB0);
  for (i = 0; (i < num_runtime); i++) {
    cudaSetDevice((data + i)->cuda_device);
    Field3D_Seq_GEO_YEE_CURL_L((data + i), ((inB0)->data + i), x0, DELTA_X, DELTA_Y, DELTA_Z, DT);
  }
  return 0;
}

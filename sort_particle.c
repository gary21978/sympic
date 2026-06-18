#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "pubdefs.h"

#include "cuda_/cuda_pscmc_inc.h"

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

#include <assert.h>

#include <math.h>

int cuda_call_particle_sort_single_x_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput((sort_kernel)[0], inoutput);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw((sort_kernel)[0], xyzw);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache((sort_kernel)[0], cu_cache);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw((sort_kernel)[0], cu_xyzw);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[0], adjoint_vec_pids);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
  cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN((sort_kernel)[0], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN((sort_kernel)[0], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN((sort_kernel)[0], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp((sort_kernel)[0], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec((sort_kernel)[0], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len((sort_kernel)[0], &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length((sort_kernel)[0], &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_x_6_exec((sort_kernel)[0], cuda_gpu_sort_one_grid_x_6_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = XLEN;

  int the_dir_num = 0;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_6_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_y_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput((sort_kernel)[1], inoutput);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw((sort_kernel)[1], xyzw);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache((sort_kernel)[1], cu_cache);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw((sort_kernel)[1], cu_xyzw);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[1], adjoint_vec_pids);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
  cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN((sort_kernel)[1], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN((sort_kernel)[1], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN((sort_kernel)[1], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp((sort_kernel)[1], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec((sort_kernel)[1], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len((sort_kernel)[1], &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length((sort_kernel)[1], &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_y_6_exec((sort_kernel)[1], cuda_gpu_sort_one_grid_y_6_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = YLEN;

  int the_dir_num = 1;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_6_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_z_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput((sort_kernel)[2], inoutput);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw((sort_kernel)[2], xyzw);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache((sort_kernel)[2], cu_cache);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw((sort_kernel)[2], cu_xyzw);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[2], adjoint_vec_pids);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
  cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN((sort_kernel)[2], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN((sort_kernel)[2], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN((sort_kernel)[2], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp((sort_kernel)[2], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec((sort_kernel)[2], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len((sort_kernel)[2], &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length((sort_kernel)[2], &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_z_6_exec((sort_kernel)[2], cuda_gpu_sort_one_grid_z_6_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = ZLEN;

  int the_dir_num = 2;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_6_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_x_vlo_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput((sort_kernel)[3], inoutput);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw((sort_kernel)[3], xyzw);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache((sort_kernel)[3], cu_cache);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw((sort_kernel)[3], cu_xyzw);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[3], adjoint_vec_pids);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
  cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN((sort_kernel)[3], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN((sort_kernel)[3], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN((sort_kernel)[3], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp((sort_kernel)[3], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec((sort_kernel)[3], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len((sort_kernel)[3],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length((sort_kernel)[3],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_x_vlo_6_exec((sort_kernel)[3], cuda_gpu_sort_one_grid_x_vlo_6_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = XLEN;

  int the_dir_num = 0;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_6_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_y_vlo_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput((sort_kernel)[4], inoutput);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw((sort_kernel)[4], xyzw);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache((sort_kernel)[4], cu_cache);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw((sort_kernel)[4], cu_xyzw);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[4], adjoint_vec_pids);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
  cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN((sort_kernel)[4], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN((sort_kernel)[4], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN((sort_kernel)[4], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp((sort_kernel)[4], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec((sort_kernel)[4], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len((sort_kernel)[4],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length((sort_kernel)[4],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_y_vlo_6_exec((sort_kernel)[4], cuda_gpu_sort_one_grid_y_vlo_6_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = YLEN;

  int the_dir_num = 1;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_6_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_z_vlo_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput((sort_kernel)[5], inoutput);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw((sort_kernel)[5], xyzw);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache((sort_kernel)[5], cu_cache);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw((sort_kernel)[5], cu_xyzw);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[5], adjoint_vec_pids);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
  cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
  cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
  cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN((sort_kernel)[5], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN((sort_kernel)[5], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN((sort_kernel)[5], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp((sort_kernel)[5], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec((sort_kernel)[5], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len((sort_kernel)[5],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length((sort_kernel)[5],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_z_vlo_6_exec((sort_kernel)[5], cuda_gpu_sort_one_grid_z_vlo_6_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = ZLEN;

  int the_dir_num = 2;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_6_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_x_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  void *cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput((sort_kernel)[6], inoutput);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw((sort_kernel)[6], xyzw);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache((sort_kernel)[6], cu_cache);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw((sort_kernel)[6], cu_xyzw);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[6], adjoint_vec_pids);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
  cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN((sort_kernel)[6], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN((sort_kernel)[6], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN((sort_kernel)[6], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp((sort_kernel)[6], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec((sort_kernel)[6], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len((sort_kernel)[6], &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length((sort_kernel)[6], &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_x_8_exec((sort_kernel)[6], cuda_gpu_sort_one_grid_x_8_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = XLEN;

  int the_dir_num = 0;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_8_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_y_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  void *cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput((sort_kernel)[7], inoutput);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw((sort_kernel)[7], xyzw);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache((sort_kernel)[7], cu_cache);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw((sort_kernel)[7], cu_xyzw);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[7], adjoint_vec_pids);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
  cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN((sort_kernel)[7], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN((sort_kernel)[7], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN((sort_kernel)[7], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp((sort_kernel)[7], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec((sort_kernel)[7], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len((sort_kernel)[7], &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length((sort_kernel)[7], &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_y_8_exec((sort_kernel)[7], cuda_gpu_sort_one_grid_y_8_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = YLEN;

  int the_dir_num = 1;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_8_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_z_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  void *cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput((sort_kernel)[8], inoutput);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw((sort_kernel)[8], xyzw);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache((sort_kernel)[8], cu_cache);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw((sort_kernel)[8], cu_xyzw);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[8], adjoint_vec_pids);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
  cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN((sort_kernel)[8], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN((sort_kernel)[8], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN((sort_kernel)[8], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp((sort_kernel)[8], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec((sort_kernel)[8], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len((sort_kernel)[8], &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length((sort_kernel)[8], &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_z_8_exec((sort_kernel)[8], cuda_gpu_sort_one_grid_z_8_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = ZLEN;

  int the_dir_num = 2;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_8_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_x_vlo_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  void *cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput((sort_kernel)[9], inoutput);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw((sort_kernel)[9], xyzw);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache((sort_kernel)[9], cu_cache);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw((sort_kernel)[9], cu_xyzw);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[9], adjoint_vec_pids);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
  cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN((sort_kernel)[9], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN((sort_kernel)[9], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN((sort_kernel)[9], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp((sort_kernel)[9], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec((sort_kernel)[9], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len((sort_kernel)[9],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length((sort_kernel)[9],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_x_vlo_8_exec((sort_kernel)[9], cuda_gpu_sort_one_grid_x_vlo_8_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = XLEN;

  int the_dir_num = 0;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_8_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_y_vlo_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  void *cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput((sort_kernel)[10], inoutput);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw((sort_kernel)[10], xyzw);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache((sort_kernel)[10], cu_cache);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw((sort_kernel)[10], cu_xyzw);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[10], adjoint_vec_pids);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
  cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN((sort_kernel)[10], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN((sort_kernel)[10], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN((sort_kernel)[10], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp((sort_kernel)[10], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec((sort_kernel)[10], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len((sort_kernel)[10],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length((sort_kernel)[10],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_y_vlo_8_exec((sort_kernel)[10], cuda_gpu_sort_one_grid_y_vlo_8_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = YLEN;

  int the_dir_num = 1;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_8_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_particle_sort_single_z_vlo_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void **sort_kernel = (pthis)->sort_kernel;

  void *cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

  void *cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


  void *cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

  void *cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;

  void *adjoint_vec_pids = (pthis)->adjoint_vec_pids;

  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  int ovlp = (pfield)->ovlp;


  //====================Field3D_Seq

  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput((sort_kernel)[11], inoutput);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw((sort_kernel)[11], xyzw);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache((sort_kernel)[11], cu_cache);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw((sort_kernel)[11], cu_xyzw);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[11], adjoint_vec_pids);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
  cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
  cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
  cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel, adjoint_vec_pids);
  cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel, adjoint_vec_pids);
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN((sort_kernel)[11], &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN((sort_kernel)[11], &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN((sort_kernel)[11], &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp((sort_kernel)[11], &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec((sort_kernel)[11], &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len((sort_kernel)[11],
                                                                   &(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
  cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length((sort_kernel)[11],
                                                                    &(cuda_alloc_prefix_cu_cache_length));
  cuda_gpu_sort_one_grid_z_vlo_8_exec((sort_kernel)[11], cuda_gpu_sort_one_grid_z_vlo_8_get_xlen(), numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  long XYZLEN = ZLEN;

  int the_dir_num = 2;

  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_l_8_exec(cu_swap_l_6_kernel, cuda_cu_swap_l_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  (XYZLEN = -(XYZLEN));
  {
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
    ((((int *)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
    cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
    cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
    cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
  }
  return 0;
}
int cuda_call_move_back_kernel_single_6(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void *move_back_kernel_6_kernel = (pthis)->move_back_kernel_6_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;


  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  {
    cuda_move_back_kernel_6_scmc_set_parameter_inoutput(move_back_kernel_6_kernel, inoutput);
    cuda_move_back_kernel_6_scmc_set_parameter_xyzw(move_back_kernel_6_kernel, xyzw);
    cuda_move_back_kernel_6_scmc_set_parameter_cu_cache(move_back_kernel_6_kernel, cu_cache);
    cuda_move_back_kernel_6_scmc_set_parameter_cu_xyzw(move_back_kernel_6_kernel, cu_xyzw);
    cuda_pscmc_mem cuda_alloc_prefix_XLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_move_back_kernel_6_scmc_set_parameter_XLEN(move_back_kernel_6_kernel, &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_move_back_kernel_6_scmc_set_parameter_YLEN(move_back_kernel_6_kernel, &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_move_back_kernel_6_scmc_set_parameter_ZLEN(move_back_kernel_6_kernel, &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_move_back_kernel_6_scmc_set_parameter_grid_cache_len(move_back_kernel_6_kernel,
                                                              &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_move_back_kernel_6_scmc_set_parameter_cu_cache_length(move_back_kernel_6_kernel,
                                                               &(cuda_alloc_prefix_cu_cache_length));
    cuda_move_back_kernel_6_exec(move_back_kernel_6_kernel, cuda_move_back_kernel_6_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  }
  return 0;
}
int cuda_call_move_back_kernel_single_8(One_Particle_Collection *pthis) {

  // defined from class One_Particle_Collection
  Field3D_Seq *pfield = (pthis)->pfield;


  void *move_back_kernel_8_kernel = (pthis)->move_back_kernel_8_kernel;


  long grid_cache_len = (pthis)->grid_cache_len;

  long cu_cache_length = (pthis)->cu_cache_length;


  void *inoutput = (pthis)->inoutput;

  void *xyzw = (pthis)->xyzw;

  void *cu_cache = (pthis)->cu_cache;

  void *cu_xyzw = (pthis)->cu_xyzw;


  //====================One_Particle_Collection

  // defined from class Field3D_Seq
  void *pe = (pfield)->pe;

  long xlen = (pfield)->xlen;

  long ylen = (pfield)->ylen;

  long zlen = (pfield)->zlen;


  long numvec = (pfield)->numvec;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  {
    cuda_move_back_kernel_8_scmc_set_parameter_inoutput(move_back_kernel_8_kernel, inoutput);
    cuda_move_back_kernel_8_scmc_set_parameter_xyzw(move_back_kernel_8_kernel, xyzw);
    cuda_move_back_kernel_8_scmc_set_parameter_cu_cache(move_back_kernel_8_kernel, cu_cache);
    cuda_move_back_kernel_8_scmc_set_parameter_cu_xyzw(move_back_kernel_8_kernel, cu_xyzw);
    cuda_pscmc_mem cuda_alloc_prefix_XLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_move_back_kernel_8_scmc_set_parameter_XLEN(move_back_kernel_8_kernel, &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_move_back_kernel_8_scmc_set_parameter_YLEN(move_back_kernel_8_kernel, &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_move_back_kernel_8_scmc_set_parameter_ZLEN(move_back_kernel_8_kernel, &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_move_back_kernel_8_scmc_set_parameter_grid_cache_len(move_back_kernel_8_kernel,
                                                              &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long *)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    cuda_move_back_kernel_8_scmc_set_parameter_cu_cache_length(move_back_kernel_8_kernel,
                                                               &(cuda_alloc_prefix_cu_cache_length));
    cuda_move_back_kernel_8_exec(move_back_kernel_8_kernel, cuda_move_back_kernel_8_get_xlen(), numvec);
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
  }
  return 0;
}
int call_particle_sort_single(One_Particle_Collection *pthis, int dir, int use_vlo, int ptlen) {

  // defined from class One_Particle_Collection


  //====================One_Particle_Collection

  // defined from class Field3D_Seq


  //====================Field3D_Seq
  if (((dir == 0) && ((use_vlo == 0) && (ptlen == 6)))) {
    cuda_call_particle_sort_single_x_6(pthis);
  }

  if (((dir == 0) && ((use_vlo == 0) && (ptlen == 8)))) {
    cuda_call_particle_sort_single_x_8(pthis);
  }

  if (((dir == 0) && ((use_vlo == 1) && (ptlen == 6)))) {
    cuda_call_particle_sort_single_x_vlo_6(pthis);
  }

  if (((dir == 0) && ((use_vlo == 1) && (ptlen == 8)))) {
    cuda_call_particle_sort_single_x_vlo_8(pthis);
  }

  if (((dir == 1) && ((use_vlo == 0) && (ptlen == 6)))) {
    cuda_call_particle_sort_single_y_6(pthis);
  }

  if (((dir == 1) && ((use_vlo == 0) && (ptlen == 8)))) {
    cuda_call_particle_sort_single_y_8(pthis);
  }

  if (((dir == 1) && ((use_vlo == 1) && (ptlen == 6)))) {
    cuda_call_particle_sort_single_y_vlo_6(pthis);
  }

  if (((dir == 1) && ((use_vlo == 1) && (ptlen == 8)))) {
    cuda_call_particle_sort_single_y_vlo_8(pthis);
  }

  if (((dir == 2) && ((use_vlo == 0) && (ptlen == 6)))) {
    cuda_call_particle_sort_single_z_6(pthis);
  }

  if (((dir == 2) && ((use_vlo == 0) && (ptlen == 8)))) {
    cuda_call_particle_sort_single_z_8(pthis);
  }

  if (((dir == 2) && ((use_vlo == 1) && (ptlen == 6)))) {
    cuda_call_particle_sort_single_z_vlo_6(pthis);
  }

  if (((dir == 2) && ((use_vlo == 1) && (ptlen == 8)))) {
    cuda_call_particle_sort_single_z_vlo_8(pthis);
  }
}

int swap_particle_sort_host_l(Field3D_MPI *pthis, int dir, int mask) {

  // defined from class Field3D_MPI

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;


  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;


  //====================Field3D_MPI
  {
    long xyzz;

    for ((xyzz = 0); (xyzz < 1); (xyzz = (xyzz + 1))) {
      {
        long xyzy;

        for ((xyzy = 0); (xyzy < 1); (xyzy = (xyzy + 1))) {
          {
            long xyzx;

            for ((xyzx = 0); (xyzx < num_spec); (xyzx = (xyzx + 1))) {
              One_Particle_Collection *particle_spec_1 = (particles + (xyzx * num_runtime));

              int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[xyzx];

              int ptlen = (((ptype & 2)) ? (8) : (6));

              long i;

              long j;

              if (((mask == 0) || (ptype & mask))) {
                int **p_to_left_len_buffer = malloc((sizeof(int *) * num_runtime));

                for (i = 0; (i < num_runtime); i++) {

                  // defined from class One_Particle_Collection
                  Field3D_Seq *pfield = ((particle_spec_1 + i))->pfield;


                  long cu_cache_length = ((particle_spec_1 + i))->cu_cache_length;


                  void *cu_cache = ((particle_spec_1 + i))->cu_cache;

                  void *cu_xyzw = ((particle_spec_1 + i))->cu_xyzw;

                  void *adjoint_vec_pids = ((particle_spec_1 + i))->adjoint_vec_pids;

                  //====================One_Particle_Collection

                  // defined from class Field3D_Seq


                  long numvec = (pfield)->numvec;


                  long *adj_ids = (pfield)->adj_ids;

                  long *adj_processes = (pfield)->adj_processes;


                  //====================Field3D_Seq
                  double *cu_cache_host = (((double **)cu_cache))[0];

                  int *cu_xyzw_host = (((int **)cu_xyzw))[0];

                  long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

                  ((p_to_left_len_buffer)[i] = malloc((sizeof(int) * numvec)));
                  for (j = 0; (j < numvec); j++) {
                    long *cur_adj_ids = (adj_ids + (j * NUM_SYNC_LAYER));

                    long *cur_adj_procs = (adj_processes + (j * NUM_SYNC_LAYER));


                    long *cur_adjoint_vec_pids = (adjoint_vec_pids_host + (j * 6));

                    int *cur_cu_xyzw = (cu_xyzw_host + (4 * j));

                    int beg_to_left = (cur_cu_xyzw)[1];

                    int end_to_left = (cur_cu_xyzw)[2];

                    double *cur_cu_cache = (cu_cache_host + (j * (cu_cache_length * 6)));

                    long xyzarr[3];
                    ((xyzarr)[0] = 1);
                    ((xyzarr)[1] = 1);
                    ((xyzarr)[2] = 1);
                    ((xyzarr)[dir] = 0);
                    long left_pid =
                        (cur_adj_procs)[(0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))))];

                    long left_proc_id = (left_pid / (pthis)->num_runtime);

                    long cur_proc_id = ((adj_processes + (j * NUM_SYNC_LAYER)))[(NUM_SYNC_LAYER / 2)];

                    int local_xyz_all_tmp = (0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))));

                    long left_id = (cur_adj_ids)[local_xyz_all_tmp];


                    long cur_left_id_ismin1 = (cur_adjoint_vec_pids)[((2 * dir) + (0 / 2))];


                    int to_left_len = (end_to_left - beg_to_left);

                    (((p_to_left_len_buffer)[i])[j] = to_left_len);
                    if ((cur_left_id_ismin1 == -1)) {
                      if ((0 || (cur_proc_id != left_pid))) {
                        PS_MPI_Isend(((p_to_left_len_buffer)[i] + j), 1, PS_MPI_INT, left_proc_id, (left_id * 2), comm,
                                     ((rqst)[i] + j));
                        PS_MPI_Isend((cur_cu_cache + (beg_to_left * ptlen)), (to_left_len * ptlen), PS_MPI_DOUBLE,
                                     left_proc_id, (1 + (left_id * 2)), comm, ((rqst)[i] + (numvec + j)));
                      }
                    }
                  }
                }
                for (i = 0; (i < num_runtime); i++) {

                  // defined from class One_Particle_Collection
                  Field3D_Seq *pfield = ((particle_spec_1 + i))->pfield;


                  long cu_cache_length = ((particle_spec_1 + i))->cu_cache_length;


                  void *cu_cache = ((particle_spec_1 + i))->cu_cache;

                  void *cu_xyzw = ((particle_spec_1 + i))->cu_xyzw;

                  void *adjoint_vec_pids = ((particle_spec_1 + i))->adjoint_vec_pids;

                  //====================One_Particle_Collection

                  // defined from class Field3D_Seq

                  long xlen = (pfield)->xlen;

                  long ylen = (pfield)->ylen;

                  long zlen = (pfield)->zlen;


                  long numvec = (pfield)->numvec;


                  long *global_x_offset = (pfield)->global_x_offset;

                  long *global_y_offset = (pfield)->global_y_offset;

                  long *global_z_offset = (pfield)->global_z_offset;


                  long *adj_ids = (pfield)->adj_ids;

                  long *adj_processes = (pfield)->adj_processes;

                  long *adj_local_tid = (pfield)->adj_local_tid;


                  //====================Field3D_Seq
                  double *cu_cache_host = (((double **)cu_cache))[0];

                  int *cu_xyzw_host = (((int **)cu_xyzw))[0];

                  long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

                  for (j = 0; (j < numvec); j++) {
                    long *cur_adj_ids = (adj_ids + (j * NUM_SYNC_LAYER));

                    long *cur_adj_procs = (adj_processes + (j * NUM_SYNC_LAYER));

                    long *cur_local_tid = (adj_local_tid + (j * NUM_SYNC_LAYER));

                    long *cur_adjoint_vec_pids = (adjoint_vec_pids_host + (j * 6));

                    int *cur_cu_xyzw = (cu_xyzw_host + (4 * j));

                    int beg_to_left = (cur_cu_xyzw)[1];


                    double *cur_cu_cache = (cu_cache_host + (j * (cu_cache_length * 6)));

                    long xyzarr[3];
                    ((xyzarr)[0] = 1);
                    ((xyzarr)[1] = 1);
                    ((xyzarr)[2] = 1);
                    ((xyzarr)[dir] = 2);
                    long left_pid =
                        (cur_adj_procs)[(0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))))];

                    long left_proc_id = (left_pid / (pthis)->num_runtime);

                    long cur_proc_id = ((adj_processes + (j * NUM_SYNC_LAYER)))[(NUM_SYNC_LAYER / 2)];

                    int local_xyz_all_tmp = (0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))));


                    long left_local_tid = (cur_local_tid)[local_xyz_all_tmp];

                    long cur_left_id_ismin1 = (cur_adjoint_vec_pids)[((2 * dir) + (2 / 2))];

                    long cur_id = (cur_adj_ids)[(NUM_SYNC_LAYER / 2)];


                    if ((cur_left_id_ismin1 == -1)) {
                      volatile int from_right_len;

                      int cur_len = (cur_cu_xyzw)[0];

                      if ((0 || (left_pid != cur_proc_id))) {
                        PS_MPI_Recv(&(from_right_len), 1, PS_MPI_INT, left_proc_id, (2 * cur_id), comm, NULL);
                        if ((((cur_cu_xyzw)[0] + from_right_len) >= beg_to_left)) {
                          fprintf(stderr, "[%e %e %e],offs=[%ld %ld %ld]\n", (cur_cu_cache)[0], (cur_cu_cache)[1],
                                  (cur_cu_cache)[2], (global_x_offset)[j], (global_y_offset)[j], (global_z_offset)[j]);
                        }

                        assert((((cur_cu_xyzw)[0] + from_right_len) < beg_to_left));
                        PS_MPI_Recv((cur_cu_cache + (ptlen * cur_len)), (from_right_len * ptlen), PS_MPI_DOUBLE,
                                    left_proc_id, (1 + (2 * cur_id)), comm, NULL);

                      } else {
                        (from_right_len =
                             ((cu_xyzw_host)[((4 * left_local_tid) + 2)] - (cu_xyzw_host)[((4 * left_local_tid) + 1)]));
                        if ((((cur_cu_xyzw)[0] + from_right_len) >= beg_to_left)) {
                          fprintf(stderr, "[%e %e %e],offs=[%ld %ld %ld]\n", (cur_cu_cache)[0], (cur_cu_cache)[1],
                                  (cur_cu_cache)[2], (global_x_offset)[j], (global_y_offset)[j], (global_z_offset)[j]);
                        }

                        assert((((cur_cu_xyzw)[0] + from_right_len) < beg_to_left));
                        memcpy((cur_cu_cache + (ptlen * cur_len)),
                               (cu_cache_host + ((left_pid * (ptlen * cu_cache_length)) +
                                                 (ptlen * (cu_xyzw_host)[((4 * left_local_tid) + 2)]))),
                               (from_right_len * (ptlen * sizeof(double))));
                      }

                      long xyzlenarr[3];
                      ((xyzlenarr)[0] = xlen);
                      ((xyzlenarr)[1] = ylen);
                      ((xyzlenarr)[2] = zlen);
                      long XYZLEN = ((1 - 0) * (xyzlenarr)[dir]);

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 1); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 1); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < from_right_len); (xyzx = (xyzx + 1))) {
                                  ((cur_cu_cache)[((ptlen * (xyzx + cur_len)) + dir)] =
                                       ((cur_cu_cache)[((ptlen * (xyzx + cur_len)) + dir)] + XYZLEN));
                                }
                              }
                            }
                          }
                        }
                      }
                      ((cur_cu_xyzw)[0] = ((cur_cu_xyzw)[0] + from_right_len));
                    }
                  }
                }
                for (i = 0; (i < num_runtime); i++) {

                  // defined from class One_Particle_Collection
                  Field3D_Seq *pfield = ((particle_spec_1 + i))->pfield;


                  void *adjoint_vec_pids = ((particle_spec_1 + i))->adjoint_vec_pids;

                  //====================One_Particle_Collection

                  // defined from class Field3D_Seq


                  long numvec = (pfield)->numvec;


                  long *adj_processes = (pfield)->adj_processes;


                  //====================Field3D_Seq


                  long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

                  for (j = 0; (j < numvec); j++) {

                    long *cur_adj_procs = (adj_processes + (j * NUM_SYNC_LAYER));


                    long *cur_adjoint_vec_pids = (adjoint_vec_pids_host + (j * 6));


                    long xyzarr[3];
                    ((xyzarr)[0] = 1);
                    ((xyzarr)[1] = 1);
                    ((xyzarr)[2] = 1);
                    ((xyzarr)[dir] = 0);
                    long left_pid =
                        (cur_adj_procs)[(0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))))];


                    long cur_proc_id = ((adj_processes + (j * NUM_SYNC_LAYER)))[(NUM_SYNC_LAYER / 2)];


                    long cur_left_id_ismin1 = (cur_adjoint_vec_pids)[((2 * dir) + (0 / 2))];


                    if ((cur_left_id_ismin1 == -1)) {
                      if ((0 || (cur_proc_id != left_pid))) {
                        PS_MPI_Wait(((rqst)[i] + j), NULL);
                        PS_MPI_Wait(((rqst)[i] + (numvec + j)), NULL);
                      }
                    }
                  }
                }
                {
                  long i;

                  for ((i = 0); (i < num_runtime); (i = (i + 1))) {
                    free((p_to_left_len_buffer)[i]);
                  }
                }
                free(p_to_left_len_buffer);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
int swap_particle_sort_host_r(Field3D_MPI *pthis, int dir, int mask) {

  // defined from class Field3D_MPI

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;


  PS_MPI_Request **rqst = (pthis)->rqst;

  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;


  //====================Field3D_MPI
  {
    long xyzz;

    for ((xyzz = 0); (xyzz < 1); (xyzz = (xyzz + 1))) {
      {
        long xyzy;

        for ((xyzy = 0); (xyzy < 1); (xyzy = (xyzy + 1))) {
          {
            long xyzx;

            for ((xyzx = 0); (xyzx < num_spec); (xyzx = (xyzx + 1))) {
              One_Particle_Collection *particle_spec_1 = (particles + (xyzx * num_runtime));

              int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[xyzx];

              int ptlen = (((ptype & 2)) ? (8) : (6));

              long i;

              long j;

              if (((mask == 0) || (ptype & mask))) {
                int **p_to_left_len_buffer = malloc((sizeof(int *) * num_runtime));

                for (i = 0; (i < num_runtime); i++) {

                  // defined from class One_Particle_Collection
                  Field3D_Seq *pfield = ((particle_spec_1 + i))->pfield;


                  long cu_cache_length = ((particle_spec_1 + i))->cu_cache_length;


                  void *cu_cache = ((particle_spec_1 + i))->cu_cache;

                  void *cu_xyzw = ((particle_spec_1 + i))->cu_xyzw;

                  void *adjoint_vec_pids = ((particle_spec_1 + i))->adjoint_vec_pids;

                  //====================One_Particle_Collection

                  // defined from class Field3D_Seq


                  long numvec = (pfield)->numvec;


                  long *adj_ids = (pfield)->adj_ids;

                  long *adj_processes = (pfield)->adj_processes;


                  //====================Field3D_Seq
                  double *cu_cache_host = (((double **)cu_cache))[0];

                  int *cu_xyzw_host = (((int **)cu_xyzw))[0];

                  long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

                  ((p_to_left_len_buffer)[i] = malloc((sizeof(int) * numvec)));
                  for (j = 0; (j < numvec); j++) {
                    long *cur_adj_ids = (adj_ids + (j * NUM_SYNC_LAYER));

                    long *cur_adj_procs = (adj_processes + (j * NUM_SYNC_LAYER));


                    long *cur_adjoint_vec_pids = (adjoint_vec_pids_host + (j * 6));

                    int *cur_cu_xyzw = (cu_xyzw_host + (4 * j));

                    int beg_to_left = (cur_cu_xyzw)[3];

                    long end_to_left = cu_cache_length;

                    double *cur_cu_cache = (cu_cache_host + (j * (cu_cache_length * 6)));

                    long xyzarr[3];
                    ((xyzarr)[0] = 1);
                    ((xyzarr)[1] = 1);
                    ((xyzarr)[2] = 1);
                    ((xyzarr)[dir] = 2);
                    long left_pid =
                        (cur_adj_procs)[(0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))))];

                    long left_proc_id = (left_pid / (pthis)->num_runtime);

                    long cur_proc_id = ((adj_processes + (j * NUM_SYNC_LAYER)))[(NUM_SYNC_LAYER / 2)];

                    int local_xyz_all_tmp = (0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))));

                    long left_id = (cur_adj_ids)[local_xyz_all_tmp];


                    long cur_left_id_ismin1 = (cur_adjoint_vec_pids)[((2 * dir) + (2 / 2))];


                    int to_left_len = (end_to_left - beg_to_left);

                    (((p_to_left_len_buffer)[i])[j] = to_left_len);
                    if ((cur_left_id_ismin1 == -1)) {
                      if ((0 || (cur_proc_id != left_pid))) {
                        PS_MPI_Isend(((p_to_left_len_buffer)[i] + j), 1, PS_MPI_INT, left_proc_id, (left_id * 2), comm,
                                     ((rqst)[i] + j));
                        PS_MPI_Isend((cur_cu_cache + (beg_to_left * ptlen)), (to_left_len * ptlen), PS_MPI_DOUBLE,
                                     left_proc_id, (1 + (left_id * 2)), comm, ((rqst)[i] + (numvec + j)));
                      }
                    }
                  }
                }
                for (i = 0; (i < num_runtime); i++) {

                  // defined from class One_Particle_Collection
                  Field3D_Seq *pfield = ((particle_spec_1 + i))->pfield;


                  long cu_cache_length = ((particle_spec_1 + i))->cu_cache_length;


                  void *cu_cache = ((particle_spec_1 + i))->cu_cache;

                  void *cu_xyzw = ((particle_spec_1 + i))->cu_xyzw;

                  void *adjoint_vec_pids = ((particle_spec_1 + i))->adjoint_vec_pids;

                  //====================One_Particle_Collection

                  // defined from class Field3D_Seq

                  long xlen = (pfield)->xlen;

                  long ylen = (pfield)->ylen;

                  long zlen = (pfield)->zlen;


                  long numvec = (pfield)->numvec;


                  long *global_x_offset = (pfield)->global_x_offset;

                  long *global_y_offset = (pfield)->global_y_offset;

                  long *global_z_offset = (pfield)->global_z_offset;


                  long *adj_ids = (pfield)->adj_ids;

                  long *adj_processes = (pfield)->adj_processes;

                  long *adj_local_tid = (pfield)->adj_local_tid;


                  //====================Field3D_Seq
                  double *cu_cache_host = (((double **)cu_cache))[0];

                  int *cu_xyzw_host = (((int **)cu_xyzw))[0];

                  long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

                  for (j = 0; (j < numvec); j++) {
                    long *cur_adj_ids = (adj_ids + (j * NUM_SYNC_LAYER));

                    long *cur_adj_procs = (adj_processes + (j * NUM_SYNC_LAYER));

                    long *cur_local_tid = (adj_local_tid + (j * NUM_SYNC_LAYER));

                    long *cur_adjoint_vec_pids = (adjoint_vec_pids_host + (j * 6));

                    int *cur_cu_xyzw = (cu_xyzw_host + (4 * j));

                    int beg_to_left = (cur_cu_xyzw)[3];


                    double *cur_cu_cache = (cu_cache_host + (j * (cu_cache_length * 6)));

                    long xyzarr[3];
                    ((xyzarr)[0] = 1);
                    ((xyzarr)[1] = 1);
                    ((xyzarr)[2] = 1);
                    ((xyzarr)[dir] = 0);
                    long left_pid =
                        (cur_adj_procs)[(0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))))];

                    long left_proc_id = (left_pid / (pthis)->num_runtime);

                    long cur_proc_id = ((adj_processes + (j * NUM_SYNC_LAYER)))[(NUM_SYNC_LAYER / 2)];

                    int local_xyz_all_tmp = (0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))));


                    long left_local_tid = (cur_local_tid)[local_xyz_all_tmp];

                    long cur_left_id_ismin1 = (cur_adjoint_vec_pids)[((2 * dir) + (0 / 2))];

                    long cur_id = (cur_adj_ids)[(NUM_SYNC_LAYER / 2)];


                    if ((cur_left_id_ismin1 == -1)) {
                      volatile int from_right_len;

                      int cur_len = (cur_cu_xyzw)[0];

                      if ((0 || (left_pid != cur_proc_id))) {
                        PS_MPI_Recv(&(from_right_len), 1, PS_MPI_INT, left_proc_id, (2 * cur_id), comm, NULL);
                        if ((((cur_cu_xyzw)[0] + from_right_len) >= beg_to_left)) {
                          fprintf(stderr, "[%e %e %e],offs=[%ld %ld %ld]\n", (cur_cu_cache)[0], (cur_cu_cache)[1],
                                  (cur_cu_cache)[2], (global_x_offset)[j], (global_y_offset)[j], (global_z_offset)[j]);
                        }

                        assert((((cur_cu_xyzw)[0] + from_right_len) < beg_to_left));
                        PS_MPI_Recv((cur_cu_cache + (ptlen * cur_len)), (from_right_len * ptlen), PS_MPI_DOUBLE,
                                    left_proc_id, (1 + (2 * cur_id)), comm, NULL);

                      } else {
                        (from_right_len = ((cu_xyzw_host)[((4 * left_local_tid) + 3)] - cu_cache_length));
                        if ((((cur_cu_xyzw)[0] + from_right_len) >= beg_to_left)) {
                          fprintf(stderr, "[%e %e %e],offs=[%ld %ld %ld]\n", (cur_cu_cache)[0], (cur_cu_cache)[1],
                                  (cur_cu_cache)[2], (global_x_offset)[j], (global_y_offset)[j], (global_z_offset)[j]);
                        }

                        assert((((cur_cu_xyzw)[0] + from_right_len) < beg_to_left));
                        memcpy((cur_cu_cache + (ptlen * cur_len)),
                               (cu_cache_host + ((left_pid * (ptlen * cu_cache_length)) +
                                                 (ptlen * (cu_xyzw_host)[((4 * left_local_tid) + 3)]))),
                               (from_right_len * (ptlen * sizeof(double))));
                      }

                      long xyzlenarr[3];
                      ((xyzlenarr)[0] = xlen);
                      ((xyzlenarr)[1] = ylen);
                      ((xyzlenarr)[2] = zlen);
                      long XYZLEN = ((1 - 2) * (xyzlenarr)[dir]);

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 1); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 1); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < from_right_len); (xyzx = (xyzx + 1))) {
                                  ((cur_cu_cache)[((ptlen * (xyzx + cur_len)) + dir)] =
                                       ((cur_cu_cache)[((ptlen * (xyzx + cur_len)) + dir)] + XYZLEN));
                                }
                              }
                            }
                          }
                        }
                      }
                      ((cur_cu_xyzw)[0] = ((cur_cu_xyzw)[0] + from_right_len));
                    }
                  }
                }
                for (i = 0; (i < num_runtime); i++) {

                  // defined from class One_Particle_Collection
                  Field3D_Seq *pfield = ((particle_spec_1 + i))->pfield;


                  void *adjoint_vec_pids = ((particle_spec_1 + i))->adjoint_vec_pids;

                  //====================One_Particle_Collection

                  // defined from class Field3D_Seq


                  long numvec = (pfield)->numvec;


                  long *adj_processes = (pfield)->adj_processes;


                  //====================Field3D_Seq


                  long *adjoint_vec_pids_host = (((long **)adjoint_vec_pids))[0];

                  for (j = 0; (j < numvec); j++) {

                    long *cur_adj_procs = (adj_processes + (j * NUM_SYNC_LAYER));


                    long *cur_adjoint_vec_pids = (adjoint_vec_pids_host + (j * 6));


                    long xyzarr[3];
                    ((xyzarr)[0] = 1);
                    ((xyzarr)[1] = 1);
                    ((xyzarr)[2] = 1);
                    ((xyzarr)[dir] = 2);
                    long left_pid =
                        (cur_adj_procs)[(0 + (1 * ((xyzarr)[0] + (3 * ((xyzarr)[1] + (3 * (xyzarr)[2]))))))];


                    long cur_proc_id = ((adj_processes + (j * NUM_SYNC_LAYER)))[(NUM_SYNC_LAYER / 2)];


                    long cur_left_id_ismin1 = (cur_adjoint_vec_pids)[((2 * dir) + (2 / 2))];


                    if ((cur_left_id_ismin1 == -1)) {
                      if ((0 || (cur_proc_id != left_pid))) {
                        PS_MPI_Wait(((rqst)[i] + j), NULL);
                        PS_MPI_Wait(((rqst)[i] + (numvec + j)), NULL);
                      }
                    }
                  }
                }
                {
                  long i;

                  for ((i = 0); (i < num_runtime); (i = (i + 1))) {
                    free((p_to_left_len_buffer)[i]);
                  }
                }
                free(p_to_left_len_buffer);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

int call_particle_sort_mpi_mask(Field3D_MPI *pthis, int dir, int use_vlo, int mask) {

  // defined from class Field3D_MPI

  long num_runtime = (pthis)->num_runtime;


  One_Particle_Collection *particles = (pthis)->particles;

  int num_spec = (pthis)->num_spec;


  //====================Field3D_MPI
  long i = 0;

  for (i = 0; (i < (num_spec * num_runtime)); i++) {
    int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[(i / num_runtime)];

    int ptlen = (((ptype & 2)) ? (8) : (6));

    if (((mask == 0) || (mask & ptype))) {
      call_particle_sort_single((particles + i), dir, ((ptype) ? (0) : (use_vlo)), ptlen);

      // defined from class One_Particle_Collection


      void *cu_cache = ((particles + i))->cu_cache;

      void *cu_xyzw = ((particles + i))->cu_xyzw;


      //====================One_Particle_Collection

      // defined from class Field3D_Seq


      //====================Field3D_Seq
      cuda_pscmc_mem_sync_d2h(cu_cache);

      cuda_pscmc_mem_sync_d2h(cu_xyzw);
    }
  }
  swap_particle_sort_host_l(pthis, dir, mask);
  swap_particle_sort_host_r(pthis, dir, mask);
  for (i = 0; (i < (num_runtime * num_spec)); i++) {

    // defined from class One_Particle_Collection


    void *cu_cache = ((particles + i))->cu_cache;

    void *cu_xyzw = ((particles + i))->cu_xyzw;


    //====================One_Particle_Collection

    // defined from class Field3D_Seq


    //====================Field3D_Seq
    cuda_pscmc_mem_sync_h2d(cu_cache);

    cuda_pscmc_mem_sync_h2d(cu_xyzw);

    int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[(i / num_runtime)];

    int ptlen = (((ptype & 2)) ? (8) : (6));

    if (((ptype == 0) || (mask & ptype))) {
      if ((ptlen == 6)) {
        cuda_call_move_back_kernel_single_6((particles + i));

      } else {
        cuda_call_move_back_kernel_single_8((particles + i));
      }
    }
  }
  return 0;
}
int call_particle_sort_mpi(Field3D_MPI *pthis, int dir, int use_vlo) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  call_particle_sort_mpi_mask(pthis, dir, use_vlo, 0);
}

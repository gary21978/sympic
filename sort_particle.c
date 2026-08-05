#include <stdio.h>

#include <stdlib.h>

#include <string.h>

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
#include "sync_fields.h"
#include "sort_particle.h"

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

  long num_runtime = (pthis)->num_runtime;
  One_Particle_Collection *particles = (pthis)->particles;
  int num_spec = (pthis)->num_spec;

  {
    long xyzx;
    for (xyzx = 0; xyzx < num_spec; xyzx++) {
      One_Particle_Collection *particle_spec_1 = (particles + (xyzx * num_runtime));
      int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[xyzx];
      int ptlen = (((ptype & 2)) ? (8) : (6));
      long i, j;

      if (!((mask == 0) || (ptype & mask))) continue;

      /* Phase 0: D2H cu_xyzw for host-side metadata reads */
      for (i = 0; i < num_runtime; i++) {
        cudaSetDevice(((particle_spec_1 + i)->pfield)->cuda_device);
        cuda_pscmc_mem_sync_d2h(((particle_spec_1 + i)->cu_xyzw));
      }

      /* ---- Phase 1: exchange cu_xyzw rows via NCCL ---- */
      /* Step 1a: collect and post sends in (peer, left_id) order */
      ncclGroupStart();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        int *xyzw_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->d_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        /* collect eligible sends: gate=-1, cross-process, cross-rank */
        long send_count = 0;
        for (j = 0; j < numvec; j++) {
          long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
          if (send_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 0;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
          send_count++;
        }

        /* simple selection-sort by (peer, left_id) and post */
        for (long pass = 0; pass < send_count; pass++) {
          long best_j = -1;
          long best_peer = -1, best_left_id = -1;
          for (j = 0; j < numvec; j++) {
            long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
            if (send_gate == -2) continue; /* already posted */
            if (send_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 0;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
            long left_id = adj_ids[j * NUM_SYNC_LAYER + xyz_idx];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && left_id < best_left_id)) {
              best_j = j;
              best_peer = neighbor_pid;
              best_left_id = left_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir] = -2; /* mark posted */
          ncclSend(xyzw_d + 4 * best_j, 4, ncclInt, best_peer,
                   pthis->nccl_comm[i], 0);
        }
        /* restore gates */
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir] = -1;
        }
      }

      /* Step 1b: collect and post recvs in (peer, cur_id) order */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        int *len_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->d_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        long recv_count = 0;
        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
          if (recv_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 2;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          if (neighbor_pid / num_runtime != pthis->cur_rank) recv_count++;
        }

        for (long pass = 0; pass < recv_count; pass++) {
          long best_j = -1;
          long best_peer = -1, best_cur_id = -1;
          for (j = 0; j < numvec; j++) {
            long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
            if (recv_gate == -2) continue;
            if (recv_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 2;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
            long cur_id = adj_ids[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && cur_id < best_cur_id)) {
              best_j = j;
              best_peer = neighbor_pid;
              best_cur_id = cur_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir + 1] = -2;
          ncclRecv(len_d + 4 * best_j, 4, ncclInt, best_peer,
                   pthis->nccl_comm[i], 0);
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir + 1] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir + 1] = -1;
        }
      }
      ncclGroupEnd();
      for (i = 0; i < num_runtime; i++) {
        cudaSetDevice(((particle_spec_1 + i)->pfield)->cuda_device);
        cudaDeviceSynchronize();
      }

      /* ---- Compute frl (from_right_len) from received/swapped rows ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        int *xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->h_data);
        int *len_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->h_data);
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);

        cudaSetDevice(pfield->cuda_device);
        cuda_pscmc_mem_sync_d2h(((particle_spec_1 + i)->swap_len_buf));

        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
          if (recv_gate != -1) { len_h[4 * numvec + j] = 0; continue; }

          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 2;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          long REMOTE_RANK = neighbor_pid / num_runtime;
          long left_local_tid = adj_local_tid[j * NUM_SYNC_LAYER + xyz_idx];

          if (neighbor_pid == self_pid) {
            len_h[4 * numvec + j] = 0;
          } else if (REMOTE_RANK == pthis->cur_rank) {
            long src_runtime = neighbor_pid % num_runtime;
            int *src_xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + src_runtime)->cu_xyzw))->h_data);
            int n = src_xyzw_h[4 * left_local_tid + 2] - src_xyzw_h[4 * left_local_tid + 1];
            len_h[4 * numvec + j] = n;
            int cur_len = xyzw_h[4 * j];
            int beg_to_left = xyzw_h[4 * j + 1];
            assert(((cur_len + n) < beg_to_left));
          } else {
            int n = len_h[4 * j + 2] - len_h[4 * j + 1];
            len_h[4 * numvec + j] = n;
            int cur_len = xyzw_h[4 * j];
            int beg_to_left = xyzw_h[4 * j + 1];
            assert(((cur_len + n) < beg_to_left));
          }
        }
        cuda_pscmc_mem_sync_h2d(((particle_spec_1 + i)->swap_len_buf));
      }

      /* ---- Phase 2: exchange particle data via NCCL ---- */
      ncclGroupStart();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        double *cache_d = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_cache))->d_data);
        int *xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->h_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        /* collect and post sends in sorted order */
        long send_count = 0;
        for (j = 0; j < numvec; j++) {
          long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
          if (send_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 0;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
          int beg = xyzw_h[4 * j + 1];
          int end = xyzw_h[4 * j + 2];
          if (end <= beg) continue;
          send_count++;
        }

        for (long pass = 0; pass < send_count; pass++) {
          long best_j = -1, best_peer = -1, best_key = -1;
          for (j = 0; j < numvec; j++) {
            long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
            if (send_gate == -2) continue;
            if (send_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 0;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
            int beg = xyzw_h[4 * j + 1];
            int end = xyzw_h[4 * j + 2];
            if (end <= beg) continue;
            long left_id = adj_ids[j * NUM_SYNC_LAYER + xyz_idx];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && left_id < best_key)) {
              best_j = j; best_peer = neighbor_pid; best_key = left_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir] = -2;
          int beg = xyzw_h[4 * best_j + 1];
          int end = xyzw_h[4 * best_j + 2];
          int count = end - beg;
          long base = best_j * cu_cache_length * 6;
          ncclSend(cache_d + base + (long)beg * ptlen, (size_t)count * ptlen,
                   ncclDouble, best_peer, pthis->nccl_comm[i], 0);
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir] = -1;
        }
      }

      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        double *cache_d = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_cache))->d_data);
        int *xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->h_data);
        int *len_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->h_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        long recv_count = 0;
        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
          if (recv_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 2;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          int n = len_h[4 * numvec + j];
          if (n <= 0) continue;
          recv_count++;
        }

        for (long pass = 0; pass < recv_count; pass++) {
          long best_j = -1, best_peer = -1, best_key = -1;
          for (j = 0; j < numvec; j++) {
            long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
            if (recv_gate == -2) continue;
            if (recv_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 2;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            int n = len_h[4 * numvec + j];
            if (n <= 0) continue;
            long cur_id = adj_ids[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && cur_id < best_key)) {
              best_j = j; best_peer = neighbor_pid; best_key = cur_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir + 1] = -2;
          int cur_len = xyzw_h[4 * best_j];
          int from_right_len = len_h[4 * numvec + best_j];
          long base = best_j * cu_cache_length * 6;

          if (best_peer / num_runtime == pthis->cur_rank) {
            long src_runtime = best_peer % num_runtime;
            long xyzarr2[3] = {1, 1, 1};
            xyzarr2[dir] = 2;
            int xyz_idx2 = 0 + 1 * (xyzarr2[0] + 3 * (xyzarr2[1] + 3 * xyzarr2[2]));
            long left_local_tid = adj_local_tid[best_j * NUM_SYNC_LAYER + xyz_idx2];
            int *src_xyzw_h2 = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + src_runtime)->cu_xyzw))->h_data);
            double *src_cache_d2 = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + src_runtime)->cu_cache))->d_data);
            int src_dev2 = ((particle_spec_1 + src_runtime)->pfield)->cuda_device;
            int src_end2 = src_xyzw_h2[4 * left_local_tid + 2];
            long src_base2 = left_local_tid * cu_cache_length * 6;
            copy_between_devices(cache_d + base + (long)cur_len * ptlen, dev,
                                 src_cache_d2 + src_base2 + (long)src_end2 * ptlen, src_dev2,
                                 sizeof(double) * from_right_len * ptlen);
          } else {
            ncclRecv(cache_d + base + (long)cur_len * ptlen,
                     (size_t)from_right_len * ptlen,
                     ncclDouble, best_peer, pthis->nccl_comm[i], 0);
          }
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir + 1] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir + 1] = -1;
        }
      }
      ncclGroupEnd();

      /* ---- Phase 3: coordinate shift via GPU kernel ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        int dev = pfield->cuda_device;
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        long xyzlenarr[3] = {pfield->xlen, pfield->ylen, pfield->zlen};
        long XYZLEN = (1 - 0) * xyzlenarr[dir];

        cudaSetDevice(dev);
        cudaDeviceSynchronize();

        double *cache_d = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_cache))->d_data);
        int *xyzw_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->d_data);
        int *frl_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->d_data) + 4 * numvec;

        cuda_particle_shift_launch(cache_d, xyzw_d, frl_d, cu_cache_length,
                                   numvec, dir, XYZLEN, ptlen, dev);
        cudaDeviceSynchronize();
      }
    }
  }
  return 0;
}

int swap_particle_sort_host_r(Field3D_MPI *pthis, int dir, int mask) {

  long num_runtime = (pthis)->num_runtime;
  One_Particle_Collection *particles = (pthis)->particles;
  int num_spec = (pthis)->num_spec;

  {
    long xyzx;
    for (xyzx = 0; xyzx < num_spec; xyzx++) {
      One_Particle_Collection *particle_spec_1 = (particles + (xyzx * num_runtime));
      int ptype = ((((Particle_in_Cell_MPI *)pthis))->o_particle_type)[xyzx];
      int ptlen = (((ptype & 2)) ? (8) : (6));
      long i, j;

      if (!((mask == 0) || (ptype & mask))) continue;

      /* Phase 0: D2H cu_xyzw */
      for (i = 0; i < num_runtime; i++) {
        cudaSetDevice(((particle_spec_1 + i)->pfield)->cuda_device);
        cuda_pscmc_mem_sync_d2h(((particle_spec_1 + i)->cu_xyzw));
      }

      /* ---- Phase 1: exchange cu_xyzw rows ---- */
      ncclGroupStart();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        int *xyzw_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->d_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        long send_count = 0;
        for (j = 0; j < numvec; j++) {
          long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
          if (send_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 2;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
          send_count++;
        }

        for (long pass = 0; pass < send_count; pass++) {
          long best_j = -1, best_peer = -1, best_key = -1;
          for (j = 0; j < numvec; j++) {
            long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
            if (send_gate == -2) continue;
            if (send_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 2;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
            long left_id = adj_ids[j * NUM_SYNC_LAYER + xyz_idx];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && left_id < best_key)) {
              best_j = j; best_peer = neighbor_pid; best_key = left_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir + 1] = -2;
          ncclSend(xyzw_d + 4 * best_j, 4, ncclInt, best_peer,
                   pthis->nccl_comm[i], 0);
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir + 1] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir + 1] = -1;
        }
      }

      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        int *len_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->d_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        long recv_count = 0;
        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
          if (recv_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 0;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          if (neighbor_pid / num_runtime != pthis->cur_rank) recv_count++;
        }

        for (long pass = 0; pass < recv_count; pass++) {
          long best_j = -1, best_peer = -1, best_key = -1;
          for (j = 0; j < numvec; j++) {
            long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
            if (recv_gate == -2) continue;
            if (recv_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 0;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
            long cur_id = adj_ids[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && cur_id < best_key)) {
              best_j = j; best_peer = neighbor_pid; best_key = cur_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir] = -2;
          ncclRecv(len_d + 4 * best_j, 4, ncclInt, best_peer,
                   pthis->nccl_comm[i], 0);
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir] = -1;
        }
      }
      ncclGroupEnd();
      for (i = 0; i < num_runtime; i++) {
        cudaSetDevice(((particle_spec_1 + i)->pfield)->cuda_device);
        cudaDeviceSynchronize();
      }

      /* ---- Compute frl ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        int *xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->h_data);
        int *len_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->h_data);
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);

        cudaSetDevice(pfield->cuda_device);
        cuda_pscmc_mem_sync_d2h(((particle_spec_1 + i)->swap_len_buf));

        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
          if (recv_gate != -1) { len_h[4 * numvec + j] = 0; continue; }

          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 0;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          long REMOTE_RANK = neighbor_pid / num_runtime;
          long left_local_tid = adj_local_tid[j * NUM_SYNC_LAYER + xyz_idx];

          if (neighbor_pid == self_pid) {
            len_h[4 * numvec + j] = 0;
          } else if (REMOTE_RANK == pthis->cur_rank) {
            long src_runtime = neighbor_pid % num_runtime;
            int *src_xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + src_runtime)->cu_xyzw))->h_data);
            int n = cu_cache_length - src_xyzw_h[4 * left_local_tid + 3];
            len_h[4 * numvec + j] = n;
            int cur_len = xyzw_h[4 * j];
            int beg_to_left = xyzw_h[4 * j + 1];
            assert(((cur_len + n) < beg_to_left));
          } else {
            int n = cu_cache_length - len_h[4 * j + 3];
            len_h[4 * numvec + j] = n;
            int cur_len = xyzw_h[4 * j];
            int beg_to_left = xyzw_h[4 * j + 1];
            assert(((cur_len + n) < beg_to_left));
          }
        }
        cuda_pscmc_mem_sync_h2d(((particle_spec_1 + i)->swap_len_buf));
      }

      /* ---- Phase 2: exchange particle data ---- */
      ncclGroupStart();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        double *cache_d = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_cache))->d_data);
        int *xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->h_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        long send_count = 0;
        for (j = 0; j < numvec; j++) {
          long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
          if (send_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 2;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
          int count = cu_cache_length - xyzw_h[4 * j + 3];
          if (count <= 0) continue;
          send_count++;
        }

        for (long pass = 0; pass < send_count; pass++) {
          long best_j = -1, best_peer = -1, best_key = -1;
          for (j = 0; j < numvec; j++) {
            long send_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
            if (send_gate == -2) continue;
            if (send_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 2;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime == pthis->cur_rank) continue;
            int count = cu_cache_length - xyzw_h[4 * j + 3];
            if (count <= 0) continue;
            long left_id = adj_ids[j * NUM_SYNC_LAYER + xyz_idx];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && left_id < best_key)) {
              best_j = j; best_peer = neighbor_pid; best_key = left_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir + 1] = -2;
          int beg = xyzw_h[4 * best_j + 3];
          int count = cu_cache_length - beg;
          long base = best_j * cu_cache_length * 6;
          ncclSend(cache_d + base + (long)beg * ptlen, (size_t)count * ptlen,
                   ncclDouble, best_peer, pthis->nccl_comm[i], 0);
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir + 1] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir + 1] = -1;
        }
      }

      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        double *cache_d = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_cache))->d_data);
        int *xyzw_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->h_data);
        int *len_h = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->h_data);
        long *adj_ids = pfield->adj_ids;
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->adjoint_vec_pids))->h_data);
        int dev = pfield->cuda_device;

        cudaSetDevice(dev);

        long recv_count = 0;
        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
          if (recv_gate != -1) continue;
          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 0;
          int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          if (neighbor_pid == self_pid) continue;
          int n = len_h[4 * numvec + j];
          if (n <= 0) continue;
          recv_count++;
        }

        for (long pass = 0; pass < recv_count; pass++) {
          long best_j = -1, best_peer = -1, best_key = -1;
          for (j = 0; j < numvec; j++) {
            long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
            if (recv_gate == -2) continue;
            if (recv_gate != -1) continue;
            long xyzarr[3] = {1, 1, 1};
            xyzarr[dir] = 0;
            int xyz_idx = 0 + 1 * (xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]));
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            int n = len_h[4 * numvec + j];
            if (n <= 0) continue;
            long cur_id = adj_ids[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (best_j == -1 || neighbor_pid < best_peer ||
                (neighbor_pid == best_peer && cur_id < best_key)) {
              best_j = j; best_peer = neighbor_pid; best_key = cur_id;
            }
          }
          if (best_j < 0) break;
          adjoint_vec_pids_h[best_j * 6 + 2 * dir] = -2;
          int cur_len = xyzw_h[4 * best_j];
          int from_right_len = len_h[4 * numvec + best_j];
          long base = best_j * cu_cache_length * 6;

          if (best_peer / num_runtime == pthis->cur_rank) {
            long src_runtime = best_peer % num_runtime;
            long xyzarr2[3] = {1, 1, 1};
            xyzarr2[dir] = 0;
            int xyz_idx2 = 0 + 1 * (xyzarr2[0] + 3 * (xyzarr2[1] + 3 * xyzarr2[2]));
            long left_local_tid = adj_local_tid[best_j * NUM_SYNC_LAYER + xyz_idx2];
            int *src_xyzw_h2 = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + src_runtime)->cu_xyzw))->h_data);
            double *src_cache_d2 = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + src_runtime)->cu_cache))->d_data);
            int src_dev2 = ((particle_spec_1 + src_runtime)->pfield)->cuda_device;
            int src_beg2 = src_xyzw_h2[4 * left_local_tid + 3];
            long src_base2 = left_local_tid * cu_cache_length * 6;
            copy_between_devices(cache_d + base + (long)cur_len * ptlen, dev,
                                 src_cache_d2 + src_base2 + (long)src_beg2 * ptlen, src_dev2,
                                 sizeof(double) * from_right_len * ptlen);
          } else {
            ncclRecv(cache_d + base + (long)cur_len * ptlen,
                     (size_t)from_right_len * ptlen,
                     ncclDouble, best_peer, pthis->nccl_comm[i], 0);
          }
        }
        for (j = 0; j < numvec; j++) {
          if (adjoint_vec_pids_h[j * 6 + 2 * dir] == -2)
            adjoint_vec_pids_h[j * 6 + 2 * dir] = -1;
        }
      }
      ncclGroupEnd();

      /* ---- Phase 3: coordinate shift ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = ((particle_spec_1 + i)->pfield);
        int dev = pfield->cuda_device;
        long numvec = pfield->numvec;
        long cu_cache_length = ((particle_spec_1 + i)->cu_cache_length);
        long xyzlenarr[3] = {pfield->xlen, pfield->ylen, pfield->zlen};
        long XYZLEN = (1 - 2) * xyzlenarr[dir];

        cudaSetDevice(dev);
        cudaDeviceSynchronize();

        double *cache_d = (double *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_cache))->d_data);
        int *xyzw_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->cu_xyzw))->d_data);
        int *frl_d = (int *)(((cuda_pscmc_mem *)((particle_spec_1 + i)->swap_len_buf))->d_data) + 4 * numvec;

        cuda_particle_shift_launch(cache_d, xyzw_d, frl_d, cu_cache_length,
                                   numvec, dir, XYZLEN, ptlen, dev);
        cudaDeviceSynchronize();
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
    }
  }
  swap_particle_sort_host_l(pthis, dir, mask);
  swap_particle_sort_host_r(pthis, dir, mask);
  for (i = 0; (i < (num_runtime * num_spec)); i++) {

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

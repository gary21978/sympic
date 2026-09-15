#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include "pubdefs.h"
#include "kernel_includes.h"
#include "sort_particle.h"

static void sympic_particle_shift(One_Particle_Collection *particles,
                                  long numvec, int dir, long xyz_len,
                                  int ptlen, int device_id) {
  SymPIC_Device_Mem *cache = (SymPIC_Device_Mem *)particles->cu_cache;
  SymPIC_Device_Mem *xyzw = (SymPIC_Device_Mem *)particles->cu_xyzw;
  SymPIC_Device_Mem *lengths = (SymPIC_Device_Mem *)particles->swap_len_buf;
#if defined(SYMPIC_CUDA)
  cuda_particle_shift_launch((double *)cache->d_data, (int *)xyzw->d_data,
                             (int *)lengths->d_data + 4 * numvec,
                             particles->cu_cache_length, numvec, dir, xyz_len,
                             ptlen, device_id);
#elif defined(SYMPIC_MAPU)
  if (cuda_particle_shift_launch) {
    cuda_particle_shift_launch((double *)cache->d_data, (int *)xyzw->d_data,
                               (int *)lengths->d_data + 4 * numvec,
                               particles->cu_cache_length, numvec, dir,
                               xyz_len, ptlen, device_id);
    return;
  }
  mapu_pscmc_mem_sync_d2h(cache);
  mapu_pscmc_mem_sync_d2h(xyzw);
  mapu_pscmc_mem_sync_d2h(lengths);
  double *cache_h = (double *)cache->h_data;
  int *xyzw_h = (int *)xyzw->h_data;
  int *frl_h = (int *)lengths->h_data + 4 * numvec;
  for (long j = 0; j < numvec; ++j) {
    int cur_len = xyzw_h[4 * j];
    int n = frl_h[j];
    long base = j * particles->cu_cache_length * 6;
    for (int k = 0; k < n; ++k)
      cache_h[base + (cur_len + k) * ptlen + dir] += xyz_len;
    xyzw_h[4 * j] = cur_len + n;
  }
  mapu_pscmc_mem_sync_h2d(cache);
  mapu_pscmc_mem_sync_h2d(xyzw);
#endif
}

#ifdef SYMPIC_CUDA
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
int cuda_call_particle_sort_single_z_6(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;


    void** sort_kernel = (pthis)->sort_kernel;

    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


    long grid_cache_len = (pthis)->grid_cache_len;

    long cu_cache_length = (pthis)->cu_cache_length;


    void* inoutput = (pthis)->inoutput;

    void* xyzw = (pthis)->xyzw;

    void* cu_cache = (pthis)->cu_cache;

    void* cu_xyzw = (pthis)->cu_xyzw;

    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;

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
    ((((long*)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN((sort_kernel)[2], &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN((sort_kernel)[2], &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN((sort_kernel)[2], &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ovlp;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
    cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp((sort_kernel)[2], &(cuda_alloc_prefix_ovlp));
    cuda_pscmc_mem cuda_alloc_prefix_numvec;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
    cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec((sort_kernel)[2], &(cuda_alloc_prefix_numvec));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len((sort_kernel)[2], &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
        cuda_cu_swap_r_6_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_6_get_xlen(), numvec);
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
    }
    return 0;
}
int cuda_call_particle_sort_single_x_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;


    void** sort_kernel = (pthis)->sort_kernel;

    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


    void* cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

    void* cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


    long grid_cache_len = (pthis)->grid_cache_len;

    long cu_cache_length = (pthis)->cu_cache_length;


    void* inoutput = (pthis)->inoutput;

    void* xyzw = (pthis)->xyzw;

    void* cu_cache = (pthis)->cu_cache;

    void* cu_xyzw = (pthis)->cu_xyzw;

    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;

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
    ((((long*)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN((sort_kernel)[6], &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN((sort_kernel)[6], &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN((sort_kernel)[6], &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ovlp;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
    cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp((sort_kernel)[6], &(cuda_alloc_prefix_ovlp));
    cuda_pscmc_mem cuda_alloc_prefix_numvec;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
    cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec((sort_kernel)[6], &(cuda_alloc_prefix_numvec));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len((sort_kernel)[6], &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
        cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
    }
    return 0;
}
int cuda_call_particle_sort_single_y_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;


    void** sort_kernel = (pthis)->sort_kernel;

    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


    void* cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

    void* cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


    long grid_cache_len = (pthis)->grid_cache_len;

    long cu_cache_length = (pthis)->cu_cache_length;


    void* inoutput = (pthis)->inoutput;

    void* xyzw = (pthis)->xyzw;

    void* cu_cache = (pthis)->cu_cache;

    void* cu_xyzw = (pthis)->cu_xyzw;

    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;

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
    ((((long*)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN((sort_kernel)[7], &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN((sort_kernel)[7], &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN((sort_kernel)[7], &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ovlp;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
    cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp((sort_kernel)[7], &(cuda_alloc_prefix_ovlp));
    cuda_pscmc_mem cuda_alloc_prefix_numvec;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
    cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec((sort_kernel)[7], &(cuda_alloc_prefix_numvec));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len((sort_kernel)[7], &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
        cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
    }
    return 0;
}
int cuda_call_particle_sort_single_z_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;


    void** sort_kernel = (pthis)->sort_kernel;

    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;

    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;


    void* cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;

    void* cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;


    long grid_cache_len = (pthis)->grid_cache_len;

    long cu_cache_length = (pthis)->cu_cache_length;


    void* inoutput = (pthis)->inoutput;

    void* xyzw = (pthis)->xyzw;

    void* cu_cache = (pthis)->cu_cache;

    void* cu_xyzw = (pthis)->cu_xyzw;

    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;

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
    ((((long*)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
    cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN((sort_kernel)[8], &(cuda_alloc_prefix_XLEN));
    cuda_pscmc_mem cuda_alloc_prefix_YLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
    cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN((sort_kernel)[8], &(cuda_alloc_prefix_YLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN((sort_kernel)[8], &(cuda_alloc_prefix_ZLEN));
    cuda_pscmc_mem cuda_alloc_prefix_ovlp;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
    cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp((sort_kernel)[8], &(cuda_alloc_prefix_ovlp));
    cuda_pscmc_mem cuda_alloc_prefix_numvec;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
    cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec((sort_kernel)[8], &(cuda_alloc_prefix_numvec));
    cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len((sort_kernel)[8], &(cuda_alloc_prefix_grid_cache_len));
    cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

    cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(cu_swap_l_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(cu_swap_l_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
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
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
        cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(cu_swap_r_6_kernel, &(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem cuda_alloc_prefix_the_dir_num;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(cuda_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(cu_swap_r_6_kernel, &(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem cuda_alloc_prefix_XYZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel, &(cuda_alloc_prefix_XYZLEN));
        cuda_cu_swap_r_8_exec(cu_swap_r_6_kernel, cuda_cu_swap_r_8_get_xlen(), numvec);
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_cu_cache_length));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_the_dir_num));
        cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XYZLEN));
    }
    return 0;
}
int cuda_call_move_back_kernel_single_6(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;


    void* move_back_kernel_6_kernel = (pthis)->move_back_kernel_6_kernel;


    long grid_cache_len = (pthis)->grid_cache_len;

    long cu_cache_length = (pthis)->cu_cache_length;


    void* inoutput = (pthis)->inoutput;

    void* xyzw = (pthis)->xyzw;

    void* cu_cache = (pthis)->cu_cache;

    void* cu_xyzw = (pthis)->cu_xyzw;


    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;

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
        ((((long*)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
        cuda_move_back_kernel_6_scmc_set_parameter_XLEN(move_back_kernel_6_kernel, &(cuda_alloc_prefix_XLEN));
        cuda_pscmc_mem cuda_alloc_prefix_YLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
        cuda_move_back_kernel_6_scmc_set_parameter_YLEN(move_back_kernel_6_kernel, &(cuda_alloc_prefix_YLEN));
        cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
        cuda_move_back_kernel_6_scmc_set_parameter_ZLEN(move_back_kernel_6_kernel, &(cuda_alloc_prefix_ZLEN));
        cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
        cuda_move_back_kernel_6_scmc_set_parameter_grid_cache_len(move_back_kernel_6_kernel,
            &(cuda_alloc_prefix_grid_cache_len));
        cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
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
int cuda_call_move_back_kernel_single_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;


    void* move_back_kernel_8_kernel = (pthis)->move_back_kernel_8_kernel;


    long grid_cache_len = (pthis)->grid_cache_len;

    long cu_cache_length = (pthis)->cu_cache_length;


    void* inoutput = (pthis)->inoutput;

    void* xyzw = (pthis)->xyzw;

    void* cu_cache = (pthis)->cu_cache;

    void* cu_xyzw = (pthis)->cu_xyzw;


    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;

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
        ((((long*)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
        cuda_move_back_kernel_8_scmc_set_parameter_XLEN(move_back_kernel_8_kernel, &(cuda_alloc_prefix_XLEN));
        cuda_pscmc_mem cuda_alloc_prefix_YLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
        cuda_move_back_kernel_8_scmc_set_parameter_YLEN(move_back_kernel_8_kernel, &(cuda_alloc_prefix_YLEN));
        cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
        cuda_move_back_kernel_8_scmc_set_parameter_ZLEN(move_back_kernel_8_kernel, &(cuda_alloc_prefix_ZLEN));
        cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
        cuda_move_back_kernel_8_scmc_set_parameter_grid_cache_len(move_back_kernel_8_kernel,
            &(cuda_alloc_prefix_grid_cache_len));
        cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;

        cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
        ((((long*)(cuda_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
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
#endif

#ifdef SYMPIC_MAPU
int mapu_call_particle_sort_single_x_6(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void** sort_kernel = (pthis)->sort_kernel;
    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;
    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;
    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;
    int ovlp = (pfield)->ovlp;

    //====================Field3D_Seq
    long the_xlen = mapu_pscmc_get_local_len();
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    MAPU_SORT_ONE_GRID_X6_SET_INOUTPUT((sort_kernel)[0], inoutput);
    MAPU_SORT_ONE_GRID_X6_SET_XYZW((sort_kernel)[0], xyzw);
    MAPU_SORT_ONE_GRID_X6_SET_CU_CACHE((sort_kernel)[0], cu_cache);
    MAPU_SORT_ONE_GRID_X6_SET_CU_XYZW((sort_kernel)[0], cu_xyzw);
    MAPU_SORT_ONE_GRID_X6_SET_ADJOINT((sort_kernel)[0], adjoint_vec_pids);
    mapu_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
    mapu_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
    mapu_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
    mapu_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
    mapu_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel,
        adjoint_vec_pids);
    mapu_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel,
        adjoint_vec_pids);
    mapu_pscmc_mem mapu_alloc_prefix_XLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
    MAPU_SORT_ONE_GRID_X6_SET_XLEN((sort_kernel)[0], &(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem mapu_alloc_prefix_YLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
    MAPU_SORT_ONE_GRID_X6_SET_YLEN((sort_kernel)[0], &(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    MAPU_SORT_ONE_GRID_X6_SET_ZLEN((sort_kernel)[0], &(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ovlp;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
    MAPU_SORT_ONE_GRID_X6_SET_OVLP((sort_kernel)[0], &(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem mapu_alloc_prefix_numvec;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
    MAPU_SORT_ONE_GRID_X6_SET_NUMVEC((sort_kernel)[0],
        &(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    MAPU_SORT_ONE_GRID_X6_SET_GRID_CACHE_LEN((sort_kernel)[0],
        &(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    MAPU_SORT_ONE_GRID_X6_SET_CU_CACHE_LENGTH(
        (sort_kernel)[0], &(mapu_alloc_prefix_cu_cache_length));
    long sort_one_grid_xlen = MAPU_SORT_ONE_GRID_X6_GET_XLEN();
    MAPU_SORT_ONE_GRID_X6_EXEC((sort_kernel)[0], sort_one_grid_xlen, numvec);

    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    long XYZLEN = XLEN;
    int the_dir_num = 0;
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
            cu_swap_l_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_l_6_scmc_set_parameter_the_dir_num(
            cu_swap_l_6_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_l_6_exec(cu_swap_l_6_kernel, mapu_cu_swap_l_6_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    (XYZLEN = -(XYZLEN));
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
            cu_swap_r_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_r_6_scmc_set_parameter_the_dir_num(
            cu_swap_r_6_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_r_6_exec(cu_swap_r_6_kernel, mapu_cu_swap_r_6_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    return 0;
}
int mapu_call_particle_sort_single_y_6(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void** sort_kernel = (pthis)->sort_kernel;
    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;
    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;
    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;
    int ovlp = (pfield)->ovlp;

    //====================Field3D_Seq
    long the_xlen = mapu_pscmc_get_local_len();
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    MAPU_SORT_ONE_GRID_Y6_SET_INOUTPUT((sort_kernel)[1], inoutput);
    MAPU_SORT_ONE_GRID_Y6_SET_XYZW((sort_kernel)[1], xyzw);
    MAPU_SORT_ONE_GRID_Y6_SET_CU_CACHE((sort_kernel)[1], cu_cache);
    MAPU_SORT_ONE_GRID_Y6_SET_CU_XYZW((sort_kernel)[1], cu_xyzw);
    MAPU_SORT_ONE_GRID_Y6_SET_ADJOINT((sort_kernel)[1], adjoint_vec_pids);
    mapu_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
    mapu_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
    mapu_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
    mapu_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
    mapu_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel,
        adjoint_vec_pids);
    mapu_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel,
        adjoint_vec_pids);
    mapu_pscmc_mem mapu_alloc_prefix_XLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
    MAPU_SORT_ONE_GRID_Y6_SET_XLEN((sort_kernel)[1], &(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem mapu_alloc_prefix_YLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
    MAPU_SORT_ONE_GRID_Y6_SET_YLEN((sort_kernel)[1], &(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    MAPU_SORT_ONE_GRID_Y6_SET_ZLEN((sort_kernel)[1], &(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ovlp;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
    MAPU_SORT_ONE_GRID_Y6_SET_OVLP((sort_kernel)[1], &(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem mapu_alloc_prefix_numvec;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
    MAPU_SORT_ONE_GRID_Y6_SET_NUMVEC((sort_kernel)[1],
        &(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    MAPU_SORT_ONE_GRID_Y6_SET_GRID_CACHE_LEN((sort_kernel)[1],
        &(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    MAPU_SORT_ONE_GRID_Y6_SET_CU_CACHE_LENGTH(
        (sort_kernel)[1], &(mapu_alloc_prefix_cu_cache_length));
    long sort_one_grid_xlen = MAPU_SORT_ONE_GRID_Y6_GET_XLEN();
    MAPU_SORT_ONE_GRID_Y6_EXEC((sort_kernel)[1], sort_one_grid_xlen, numvec);

    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    long XYZLEN = YLEN;
    int the_dir_num = 1;
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
            cu_swap_l_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_l_6_scmc_set_parameter_the_dir_num(
            cu_swap_l_6_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_l_6_exec(cu_swap_l_6_kernel, mapu_cu_swap_l_6_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    (XYZLEN = -(XYZLEN));
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
            cu_swap_r_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_r_6_scmc_set_parameter_the_dir_num(
            cu_swap_r_6_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_r_6_exec(cu_swap_r_6_kernel, mapu_cu_swap_r_6_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    return 0;
}
int mapu_call_particle_sort_single_z_6(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void** sort_kernel = (pthis)->sort_kernel;
    void* cu_swap_l_6_kernel = (pthis)->cu_swap_l_6_kernel;
    void* cu_swap_r_6_kernel = (pthis)->cu_swap_r_6_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;
    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;
    int ovlp = (pfield)->ovlp;

    //====================Field3D_Seq
    long the_xlen = mapu_pscmc_get_local_len();
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    MAPU_SORT_ONE_GRID_Z6_SET_INOUTPUT((sort_kernel)[2], inoutput);
    MAPU_SORT_ONE_GRID_Z6_SET_XYZW((sort_kernel)[2], xyzw);
    MAPU_SORT_ONE_GRID_Z6_SET_CU_CACHE((sort_kernel)[2], cu_cache);
    MAPU_SORT_ONE_GRID_Z6_SET_CU_XYZW((sort_kernel)[2], cu_xyzw);
    MAPU_SORT_ONE_GRID_Z6_SET_ADJOINT((sort_kernel)[2], adjoint_vec_pids);
    mapu_cu_swap_l_6_scmc_set_parameter_cu_cache(cu_swap_l_6_kernel, cu_cache);
    mapu_cu_swap_r_6_scmc_set_parameter_cu_cache(cu_swap_r_6_kernel, cu_cache);
    mapu_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cu_swap_l_6_kernel, cu_xyzw);
    mapu_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cu_swap_r_6_kernel, cu_xyzw);
    mapu_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_6_kernel,
        adjoint_vec_pids);
    mapu_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_6_kernel,
        adjoint_vec_pids);
    mapu_pscmc_mem mapu_alloc_prefix_XLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
    MAPU_SORT_ONE_GRID_Z6_SET_XLEN((sort_kernel)[2], &(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem mapu_alloc_prefix_YLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
    MAPU_SORT_ONE_GRID_Z6_SET_YLEN((sort_kernel)[2], &(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    MAPU_SORT_ONE_GRID_Z6_SET_ZLEN((sort_kernel)[2], &(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ovlp;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
    MAPU_SORT_ONE_GRID_Z6_SET_OVLP((sort_kernel)[2], &(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem mapu_alloc_prefix_numvec;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
    MAPU_SORT_ONE_GRID_Z6_SET_NUMVEC((sort_kernel)[2],
        &(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    MAPU_SORT_ONE_GRID_Z6_SET_GRID_CACHE_LEN((sort_kernel)[2],
        &(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    MAPU_SORT_ONE_GRID_Z6_SET_CU_CACHE_LENGTH(
        (sort_kernel)[2], &(mapu_alloc_prefix_cu_cache_length));

    long sort_one_grid_xlen = MAPU_SORT_ONE_GRID_Z6_GET_XLEN();
    MAPU_SORT_ONE_GRID_Z6_EXEC((sort_kernel)[2], sort_one_grid_xlen, numvec);
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    long XYZLEN = ZLEN;
    int the_dir_num = 2;
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
            cu_swap_l_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_l_6_scmc_set_parameter_the_dir_num(
            cu_swap_l_6_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_l_6_scmc_set_parameter_XYZLEN(cu_swap_l_6_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_l_6_exec(cu_swap_l_6_kernel, mapu_cu_swap_l_6_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    (XYZLEN = -(XYZLEN));
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
            cu_swap_r_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_r_6_scmc_set_parameter_the_dir_num(
            cu_swap_r_6_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_r_6_scmc_set_parameter_XYZLEN(cu_swap_r_6_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_r_6_exec(cu_swap_r_6_kernel, mapu_cu_swap_r_6_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    return 0;
}
int mapu_call_particle_sort_single_x_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void** sort_kernel = (pthis)->sort_kernel;
    void* cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;
    void* cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;
    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;
    int ovlp = (pfield)->ovlp;

    //====================Field3D_Seq
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    mapu_sort_one_grid_x_8_scmc_set_parameter_inoutput((sort_kernel)[6],
        inoutput);
    mapu_sort_one_grid_x_8_scmc_set_parameter_xyzw((sort_kernel)[6], xyzw);
    mapu_sort_one_grid_x_8_scmc_set_parameter_cu_cache((sort_kernel)[6],
        cu_cache);
    mapu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw((sort_kernel)[6], cu_xyzw);
    mapu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[6],
        adjoint_vec_pids);
    mapu_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
    mapu_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
    mapu_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
    mapu_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
    mapu_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel,
        adjoint_vec_pids);
    mapu_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel,
        adjoint_vec_pids);
    mapu_pscmc_mem mapu_alloc_prefix_XLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
    mapu_sort_one_grid_x_8_scmc_set_parameter_XLEN((sort_kernel)[6],
        &(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem mapu_alloc_prefix_YLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
    mapu_sort_one_grid_x_8_scmc_set_parameter_YLEN((sort_kernel)[6],
        &(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    mapu_sort_one_grid_x_8_scmc_set_parameter_ZLEN((sort_kernel)[6],
        &(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ovlp;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
    mapu_sort_one_grid_x_8_scmc_set_parameter_ovlp((sort_kernel)[6],
        &(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem mapu_alloc_prefix_numvec;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
    mapu_sort_one_grid_x_8_scmc_set_parameter_numvec((sort_kernel)[6],
        &(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    mapu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
        (sort_kernel)[6], &(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    mapu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
        (sort_kernel)[6], &(mapu_alloc_prefix_cu_cache_length));
    mapu_sort_one_grid_x_8_exec((sort_kernel)[6],
        mapu_sort_one_grid_x_8_get_xlen(), numvec);

    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    long XYZLEN = XLEN;
    int the_dir_num = 0;
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
            cu_swap_l_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_l_8_scmc_set_parameter_the_dir_num(
            cu_swap_l_8_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_8_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_l_8_exec(cu_swap_l_8_kernel, mapu_cu_swap_l_8_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    (XYZLEN = -(XYZLEN));
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
            cu_swap_r_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_r_8_scmc_set_parameter_the_dir_num(
            cu_swap_r_8_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_8_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_r_8_exec(cu_swap_r_8_kernel, mapu_cu_swap_r_8_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    return 0;
}
int mapu_call_particle_sort_single_y_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void** sort_kernel = (pthis)->sort_kernel;
    void* cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;
    void* cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;
    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;
    int ovlp = (pfield)->ovlp;

    //====================Field3D_Seq
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    mapu_sort_one_grid_y_8_scmc_set_parameter_inoutput((sort_kernel)[7],
        inoutput);
    mapu_sort_one_grid_y_8_scmc_set_parameter_xyzw((sort_kernel)[7], xyzw);
    mapu_sort_one_grid_y_8_scmc_set_parameter_cu_cache((sort_kernel)[7],
        cu_cache);
    mapu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw((sort_kernel)[7], cu_xyzw);
    mapu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[7],
        adjoint_vec_pids);
    mapu_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
    mapu_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
    mapu_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
    mapu_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
    mapu_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel,
        adjoint_vec_pids);
    mapu_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel,
        adjoint_vec_pids);
    mapu_pscmc_mem mapu_alloc_prefix_XLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
    mapu_sort_one_grid_y_8_scmc_set_parameter_XLEN((sort_kernel)[7],
        &(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem mapu_alloc_prefix_YLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
    mapu_sort_one_grid_y_8_scmc_set_parameter_YLEN((sort_kernel)[7],
        &(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    mapu_sort_one_grid_y_8_scmc_set_parameter_ZLEN((sort_kernel)[7],
        &(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ovlp;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
    mapu_sort_one_grid_y_8_scmc_set_parameter_ovlp((sort_kernel)[7],
        &(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem mapu_alloc_prefix_numvec;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
    mapu_sort_one_grid_y_8_scmc_set_parameter_numvec((sort_kernel)[7],
        &(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    mapu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
        (sort_kernel)[7], &(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    mapu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
        (sort_kernel)[7], &(mapu_alloc_prefix_cu_cache_length));
    mapu_sort_one_grid_y_8_exec((sort_kernel)[7],
        mapu_sort_one_grid_y_8_get_xlen(), numvec);

    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    long XYZLEN = YLEN;
    int the_dir_num = 1;
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
            cu_swap_l_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_l_8_scmc_set_parameter_the_dir_num(
            cu_swap_l_8_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_8_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_l_8_exec(cu_swap_l_8_kernel, mapu_cu_swap_l_8_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    (XYZLEN = -(XYZLEN));
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
            cu_swap_r_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_r_8_scmc_set_parameter_the_dir_num(
            cu_swap_r_8_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_8_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_r_8_exec(cu_swap_r_8_kernel, mapu_cu_swap_r_8_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    return 0;
}
int mapu_call_particle_sort_single_z_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void** sort_kernel = (pthis)->sort_kernel;
    void* cu_swap_l_8_kernel = (pthis)->cu_swap_l_8_kernel;
    void* cu_swap_r_8_kernel = (pthis)->cu_swap_r_8_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;
    void* adjoint_vec_pids = (pthis)->adjoint_vec_pids;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;
    int ovlp = (pfield)->ovlp;

    //====================Field3D_Seq
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    mapu_sort_one_grid_z_8_scmc_set_parameter_inoutput((sort_kernel)[8],
        inoutput);
    mapu_sort_one_grid_z_8_scmc_set_parameter_xyzw((sort_kernel)[8], xyzw);
    mapu_sort_one_grid_z_8_scmc_set_parameter_cu_cache((sort_kernel)[8],
        cu_cache);
    mapu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw((sort_kernel)[8], cu_xyzw);
    mapu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids((sort_kernel)[8],
        adjoint_vec_pids);
    mapu_cu_swap_l_8_scmc_set_parameter_cu_cache(cu_swap_l_8_kernel, cu_cache);
    mapu_cu_swap_r_8_scmc_set_parameter_cu_cache(cu_swap_r_8_kernel, cu_cache);
    mapu_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cu_swap_l_8_kernel, cu_xyzw);
    mapu_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cu_swap_r_8_kernel, cu_xyzw);
    mapu_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_l_8_kernel,
        adjoint_vec_pids);
    mapu_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(cu_swap_r_8_kernel,
        adjoint_vec_pids);
    mapu_pscmc_mem mapu_alloc_prefix_XLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
    mapu_sort_one_grid_z_8_scmc_set_parameter_XLEN((sort_kernel)[8],
        &(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem mapu_alloc_prefix_YLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
    mapu_sort_one_grid_z_8_scmc_set_parameter_YLEN((sort_kernel)[8],
        &(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
    mapu_sort_one_grid_z_8_scmc_set_parameter_ZLEN((sort_kernel)[8],
        &(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem mapu_alloc_prefix_ovlp;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
    ((((int*)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
    mapu_sort_one_grid_z_8_scmc_set_parameter_ovlp((sort_kernel)[8],
        &(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem mapu_alloc_prefix_numvec;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
    mapu_sort_one_grid_z_8_scmc_set_parameter_numvec((sort_kernel)[8],
        &(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
    mapu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
        (sort_kernel)[8], &(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
    mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM, 0);
    ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] = cu_cache_length);
    mapu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
        (sort_kernel)[8], &(mapu_alloc_prefix_cu_cache_length));
    mapu_sort_one_grid_z_8_exec((sort_kernel)[8],
        mapu_sort_one_grid_z_8_get_xlen(), numvec);

    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
    mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    long XYZLEN = ZLEN;
    int the_dir_num = 2;
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
            cu_swap_l_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_l_8_scmc_set_parameter_the_dir_num(
            cu_swap_l_8_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_l_8_scmc_set_parameter_XYZLEN(cu_swap_l_8_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_l_8_exec(cu_swap_l_8_kernel, mapu_cu_swap_l_8_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    (XYZLEN = -(XYZLEN));
    {
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
            cu_swap_r_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem mapu_alloc_prefix_the_dir_num;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_the_dir_num), PS_INT_NUM, 0);
        ((((int*)(mapu_alloc_prefix_the_dir_num).h_data))[0] = the_dir_num);
        mapu_cu_swap_r_8_scmc_set_parameter_the_dir_num(
            cu_swap_r_8_kernel, &(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem mapu_alloc_prefix_XYZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XYZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XYZLEN).h_data))[0] = XYZLEN);
        mapu_cu_swap_r_8_scmc_set_parameter_XYZLEN(cu_swap_r_8_kernel,
            &(mapu_alloc_prefix_XYZLEN));
        mapu_cu_swap_r_8_exec(cu_swap_r_8_kernel, mapu_cu_swap_r_8_get_xlen(),
            numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_the_dir_num));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XYZLEN));
    }
    return 0;
}
int mapu_call_move_back_kernel_single_6(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void* move_back_kernel_6_kernel = (pthis)->move_back_kernel_6_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;

    //====================Field3D_Seq
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    {
        mapu_move_back_kernel_6_scmc_set_parameter_inoutput(
            move_back_kernel_6_kernel, inoutput);
        mapu_move_back_kernel_6_scmc_set_parameter_xyzw(move_back_kernel_6_kernel,
            xyzw);
        mapu_move_back_kernel_6_scmc_set_parameter_cu_cache(
            move_back_kernel_6_kernel, cu_cache);
        mapu_move_back_kernel_6_scmc_set_parameter_cu_xyzw(
            move_back_kernel_6_kernel, cu_xyzw);
        mapu_pscmc_mem mapu_alloc_prefix_XLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
        mapu_move_back_kernel_6_scmc_set_parameter_XLEN(move_back_kernel_6_kernel,
            &(mapu_alloc_prefix_XLEN));
        mapu_pscmc_mem mapu_alloc_prefix_YLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
        mapu_move_back_kernel_6_scmc_set_parameter_YLEN(move_back_kernel_6_kernel,
            &(mapu_alloc_prefix_YLEN));
        mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
        mapu_move_back_kernel_6_scmc_set_parameter_ZLEN(move_back_kernel_6_kernel,
            &(mapu_alloc_prefix_ZLEN));
        mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
        mapu_move_back_kernel_6_scmc_set_parameter_grid_cache_len(
            move_back_kernel_6_kernel, &(mapu_alloc_prefix_grid_cache_len));
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_move_back_kernel_6_scmc_set_parameter_cu_cache_length(
            move_back_kernel_6_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_move_back_kernel_6_exec(move_back_kernel_6_kernel,
            mapu_move_back_kernel_6_get_xlen(), numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    }
    return 0;
}
int mapu_call_move_back_kernel_single_8(One_Particle_Collection* pthis) {

    // defined from class One_Particle_Collection
    Field3D_Seq* pfield = (pthis)->pfield;
    void* move_back_kernel_8_kernel = (pthis)->move_back_kernel_8_kernel;
    long grid_cache_len = (pthis)->grid_cache_len;
    long cu_cache_length = (pthis)->cu_cache_length;
    void* inoutput = (pthis)->inoutput;
    void* xyzw = (pthis)->xyzw;
    void* cu_cache = (pthis)->cu_cache;
    void* cu_xyzw = (pthis)->cu_xyzw;

    //====================One_Particle_Collection

    // defined from class Field3D_Seq
    void* pe = (pfield)->pe;
    long xlen = (pfield)->xlen;
    long ylen = (pfield)->ylen;
    long zlen = (pfield)->zlen;
    long numvec = (pfield)->numvec;

    //====================Field3D_Seq
    long XLEN = xlen;
    long YLEN = ylen;
    long ZLEN = zlen;
    {
        mapu_move_back_kernel_8_scmc_set_parameter_inoutput(
            move_back_kernel_8_kernel, inoutput);
        mapu_move_back_kernel_8_scmc_set_parameter_xyzw(move_back_kernel_8_kernel,
            xyzw);
        mapu_move_back_kernel_8_scmc_set_parameter_cu_cache(
            move_back_kernel_8_kernel, cu_cache);
        mapu_move_back_kernel_8_scmc_set_parameter_cu_xyzw(
            move_back_kernel_8_kernel, cu_xyzw);
        mapu_pscmc_mem mapu_alloc_prefix_XLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
        mapu_move_back_kernel_8_scmc_set_parameter_XLEN(move_back_kernel_8_kernel,
            &(mapu_alloc_prefix_XLEN));
        mapu_pscmc_mem mapu_alloc_prefix_YLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
        mapu_move_back_kernel_8_scmc_set_parameter_YLEN(move_back_kernel_8_kernel,
            &(mapu_alloc_prefix_YLEN));
        mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
        ((((long*)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
        mapu_move_back_kernel_8_scmc_set_parameter_ZLEN(move_back_kernel_8_kernel,
            &(mapu_alloc_prefix_ZLEN));
        mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_grid_cache_len), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_grid_cache_len).h_data))[0] = grid_cache_len);
        mapu_move_back_kernel_8_scmc_set_parameter_grid_cache_len(
            move_back_kernel_8_kernel, &(mapu_alloc_prefix_grid_cache_len));
        mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
        mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_cu_cache_length), PS_LONG_NUM,
            0);
        ((((long*)(mapu_alloc_prefix_cu_cache_length).h_data))[0] =
            cu_cache_length);
        mapu_move_back_kernel_8_scmc_set_parameter_cu_cache_length(
            move_back_kernel_8_kernel, &(mapu_alloc_prefix_cu_cache_length));
        mapu_move_back_kernel_8_exec(move_back_kernel_8_kernel,
            mapu_move_back_kernel_8_get_xlen(), numvec);

        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_grid_cache_len));
        mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_cu_cache_length));
    }
    return 0;
}
#endif

int call_particle_sort_single(One_Particle_Collection* pthis, int dir, int use_vlo, int ptlen) {

    if (((dir == 0) && ((use_vlo == 0) && (ptlen == 6)))) {
#ifdef SYMPIC_CUDA
        cuda_call_particle_sort_single_x_6(pthis);
#endif
#ifdef SYMPIC_MAPU
        mapu_call_particle_sort_single_x_6(pthis);
#endif
    }

    if (((dir == 0) && ((use_vlo == 0) && (ptlen == 8)))) {
#ifdef SYMPIC_CUDA
        cuda_call_particle_sort_single_x_8(pthis);
#endif
#ifdef SYMPIC_MAPU
        mapu_call_particle_sort_single_x_8(pthis);
#endif
    }

    if (((dir == 1) && ((use_vlo == 0) && (ptlen == 6)))) {
#ifdef SYMPIC_CUDA
        cuda_call_particle_sort_single_y_6(pthis);
#endif
#ifdef SYMPIC_MAPU
        mapu_call_particle_sort_single_y_6(pthis);
#endif
    }

    if (((dir == 1) && ((use_vlo == 0) && (ptlen == 8)))) {
#ifdef SYMPIC_CUDA
        cuda_call_particle_sort_single_y_8(pthis);
#endif
#ifdef SYMPIC_MAPU
        mapu_call_particle_sort_single_y_8(pthis);
#endif
    }

    if (((dir == 2) && ((use_vlo == 0) && (ptlen == 6)))) {
#ifdef SYMPIC_CUDA
        cuda_call_particle_sort_single_z_6(pthis);
#endif
#ifdef SYMPIC_MAPU
        mapu_call_particle_sort_single_z_6(pthis);
#endif
    }

    if (((dir == 2) && ((use_vlo == 0) && (ptlen == 8)))) {
#ifdef SYMPIC_CUDA
        cuda_call_particle_sort_single_z_8(pthis);
#endif
#ifdef SYMPIC_MAPU
        mapu_call_particle_sort_single_z_8(pthis);
#endif
    }

    return 0;
}

/* Static (peer, key) ordering for the sort exchange.  adj_processes/adj_ids
   never change after init, so the per-step O(n^2) selection sorts are replaced
   by a one-time qsort plus per-step linear scans.  The posted comm op sequence
   is identical to the old code. */
typedef struct {
  long j;
  long peer;
  long key;
} SortOrdEntry;

static int cmp_sort_ord_entry(const void *a, const void *b) {
  const SortOrdEntry *ea = (const SortOrdEntry *)a;
  const SortOrdEntry *eb = (const SortOrdEntry *)b;
  if (ea->peer < eb->peer) return -1;
  if (ea->peer > eb->peer) return 1;
  if (ea->key < eb->key) return -1;
  if (ea->key > eb->key) return 1;
  if (ea->j < eb->j) return -1;
  if (ea->j > eb->j) return 1;
  return 0;
}

static void build_sort_exchange_plan(One_Particle_Collection *pc,
                                     long cur_rank, long num_runtime) {
  Field3D_Seq *pfield = pc->pfield;
  long numvec = pfield->numvec;
  long *adjp = pfield->adj_processes;
  long *adji = pfield->adj_ids;

  for (int dir = 0; dir < 3; dir++) {
    long xyzarr0[3] = {1, 1, 1};
    xyzarr0[dir] = 0;
    int xyz0 = (int)(xyzarr0[0] + 3 * (xyzarr0[1] + 3 * xyzarr0[2]));
    long xyzarr2[3] = {1, 1, 1};
    xyzarr2[dir] = 2;
    int xyz2 = (int)(xyzarr2[0] + 3 * (xyzarr2[1] + 3 * xyzarr2[2]));

    for (int side = 0; side < 2; side++) {
      /* sends: L side posts to the -dir neighbor (xyz0), R side to +dir (xyz2);
         sort key = the receiving subdomain's global id */
      int sxyz = (side == 0) ? xyz0 : xyz2;
      SortOrdEntry *se =
          (SortOrdEntry *)malloc((size_t)numvec * sizeof(SortOrdEntry));
      assert(se);
      long ns = 0;
      for (long j = 0; j < numvec; j++) {
        long peer = adjp[j * NUM_SYNC_LAYER + sxyz];
        if (peer == adjp[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)]) continue;
        if (peer / num_runtime == cur_rank) continue;
        se[ns].j = j;
        se[ns].peer = peer;
        se[ns].key = adji[j * NUM_SYNC_LAYER + sxyz];
        ns++;
      }
      qsort(se, (size_t)ns, sizeof(SortOrdEntry), cmp_sort_ord_entry);
      pc->sort_send_ord[dir][side] =
          (long *)malloc((size_t)(ns > 0 ? ns : 1) * sizeof(long));
      pc->sort_send_peer[dir][side] =
          (long *)malloc((size_t)(ns > 0 ? ns : 1) * sizeof(long));
      assert(pc->sort_send_ord[dir][side] && pc->sort_send_peer[dir][side]);
      for (long k = 0; k < ns; k++) {
        pc->sort_send_ord[dir][side][k] = se[k].j;
        pc->sort_send_peer[dir][side][k] = se[k].peer;
      }
      pc->sort_send_n[dir][side] = ns;

      /* recvs: L side receives from the +dir neighbor (xyz2), R side from -dir
         (xyz0); sort key = own subdomain global id */
      int rxyz = (side == 0) ? xyz2 : xyz0;
      SortOrdEntry *re =
          (SortOrdEntry *)malloc((size_t)numvec * sizeof(SortOrdEntry));
      assert(re);
      long nr = 0;
      for (long j = 0; j < numvec; j++) {
        long peer = adjp[j * NUM_SYNC_LAYER + rxyz];
        if (peer == adjp[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)]) continue;
        if (peer / num_runtime == cur_rank) continue;
        re[nr].j = j;
        re[nr].peer = peer;
        re[nr].key = adji[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
        nr++;
      }
      qsort(re, (size_t)nr, sizeof(SortOrdEntry), cmp_sort_ord_entry);
      pc->sort_recv_ord[dir][side] =
          (long *)malloc((size_t)(nr > 0 ? nr : 1) * sizeof(long));
      pc->sort_recv_peer[dir][side] =
          (long *)malloc((size_t)(nr > 0 ? nr : 1) * sizeof(long));
      assert(pc->sort_recv_ord[dir][side] && pc->sort_recv_peer[dir][side]);
      for (long k = 0; k < nr; k++) {
        pc->sort_recv_ord[dir][side][k] = re[k].j;
        pc->sort_recv_peer[dir][side][k] = re[k].peer;
      }
      pc->sort_recv_n[dir][side] = nr;

      free(se);
      free(re);
    }
  }
  pc->sort_order_valid = 1;
}

/* Per-step segment plan for the packed sort exchange.  Entries are pushed in
   precomputed (peer, key) order and grouped per peer on finalize.
   Single-threaded per rank (OMP_NUM_THREADS=1), so file-static scratch is
   safe. */
typedef struct {
  long nseg;
  long total;
  int npeer;
} SortSegPlan;

static long *g_plan_off, *g_plan_src, *g_plan_dst, *g_plan_len, *g_plan_peer;
static long *g_plan_peer_off, *g_plan_peer_count;
static long g_plan_cap, g_plan_peer_cap;

static void sort_plan_ensure(long nseg, int npeer) {
  if (nseg > g_plan_cap) {
    g_plan_off = (long *)realloc(g_plan_off, (size_t)nseg * sizeof(long));
    g_plan_src = (long *)realloc(g_plan_src, (size_t)nseg * sizeof(long));
    g_plan_dst = (long *)realloc(g_plan_dst, (size_t)nseg * sizeof(long));
    g_plan_len = (long *)realloc(g_plan_len, (size_t)nseg * sizeof(long));
    g_plan_peer = (long *)realloc(g_plan_peer, (size_t)nseg * sizeof(long));
    assert(g_plan_off && g_plan_src && g_plan_dst && g_plan_len && g_plan_peer);
    g_plan_cap = nseg;
  }
  if (npeer > g_plan_peer_cap) {
    g_plan_peer_off =
        (long *)realloc(g_plan_peer_off, (size_t)npeer * sizeof(long));
    g_plan_peer_count =
        (long *)realloc(g_plan_peer_count, (size_t)npeer * sizeof(long));
    assert(g_plan_peer_off && g_plan_peer_count);
    g_plan_peer_cap = npeer;
  }
}

static void sort_plan_push(SortSegPlan *p, long elem_off, long len, long peer) {
  sort_plan_ensure(p->nseg + 1, p->nseg + 1);
  g_plan_off[p->nseg] = elem_off;
  g_plan_len[p->nseg] = len;
  g_plan_peer[p->nseg] = peer;
  p->nseg++;
}

/* entries are already in (peer, key) order; group per peer and compute the
   packed offsets.  send: packed dst = running offset; recv: packed src =
   running offset. */
static void sort_plan_finalize(SortSegPlan *p, int is_send) {
  p->npeer = 0;
  long running = 0;
  for (long k = 0; k < p->nseg; k++) {
    if (k == 0 || g_plan_peer[k] != g_plan_peer[k - 1]) {
      sort_plan_ensure(g_plan_cap, p->npeer + 1);
      g_plan_peer_off[p->npeer] = running;
      g_plan_peer_count[p->npeer] = 0;
      p->npeer++;
    }
    if (is_send) {
      g_plan_src[k] = g_plan_off[k];
      g_plan_dst[k] = running;
    } else {
      g_plan_src[k] = running;
      g_plan_dst[k] = g_plan_off[k];
    }
    g_plan_peer_count[p->npeer - 1] += g_plan_len[k];
    running += g_plan_len[k];
  }
  p->total = running;
}

static void sort_buf_ensure_int(int **buf, long *cap, long need, int dev) {
  if (need <= *cap) return;
  sympic_set_device(dev);
  if (*buf) sympic_device_free(*buf);
  int err = sympic_device_malloc((void **)buf, (size_t)need * sizeof(int));
  if (err != 0) {
    fprintf(stderr, "device malloc sort int buf failed: err=%s dev=%d need=%ld\n",
            sympic_device_error_string(err), dev, need);
    assert(0);
  }
  *cap = need;
}

static void sort_buf_ensure_double(double **buf, long *cap, long need, int dev) {
  if (need <= *cap) return;
  sympic_set_device(dev);
  if (*buf) sympic_device_free(*buf);
  int err = sympic_device_malloc((void **)buf, (size_t)need * sizeof(double));
  if (err != 0) {
    fprintf(stderr, "device malloc sort double buf failed: err=%s dev=%d need=%ld\n",
            sympic_device_error_string(err), dev, need);
    assert(0);
  }
  *cap = need;
}

static void sort_plan_upload(One_Particle_Collection *pc, SortSegPlan *p,
                             int dev) {
  if (p->nseg == 0) return;
  if (p->nseg > pc->sort_plan_cap) {
    sympic_set_device(dev);
    if (pc->sort_plan_src_d) sympic_device_free(pc->sort_plan_src_d);
    if (pc->sort_plan_dst_d) sympic_device_free(pc->sort_plan_dst_d);
    if (pc->sort_plan_len_d) sympic_device_free(pc->sort_plan_len_d);
    int err = sympic_device_malloc((void **)&pc->sort_plan_src_d,
                                   (size_t)p->nseg * sizeof(long));
    if (err == 0)
      err = sympic_device_malloc((void **)&pc->sort_plan_dst_d,
                                 (size_t)p->nseg * sizeof(long));
    if (err == 0)
      err = sympic_device_malloc((void **)&pc->sort_plan_len_d,
                                 (size_t)p->nseg * sizeof(long));
    if (err != 0) {
      fprintf(stderr, "device malloc sort plan failed: err=%s dev=%d n=%ld\n",
              sympic_device_error_string(err), dev, p->nseg);
      assert(0);
    }
    pc->sort_plan_cap = p->nseg;
  }
  sympic_copy_h2d(pc->sort_plan_src_d, g_plan_src,
                  (size_t)p->nseg * sizeof(long));
  sympic_copy_h2d(pc->sort_plan_dst_d, g_plan_dst,
                  (size_t)p->nseg * sizeof(long));
  sympic_copy_h2d(pc->sort_plan_len_d, g_plan_len,
                  (size_t)p->nseg * sizeof(long));
}

int swap_particle_sort_host_l(Field3D_MPI *pthis, int dir, int mask) {

  long num_runtime = pthis->num_runtime;
  One_Particle_Collection *particles = pthis->particles;
  int num_spec = pthis->num_spec;

  {
    for (long xyzx = 0; xyzx < num_spec; xyzx++) {
      One_Particle_Collection *particle_spec_1 = &particles[xyzx * num_runtime];
      int ptype = (((Particle_in_Cell_MPI *)pthis)->o_particle_type)[xyzx];
      int ptlen = ((ptype & 2) ? 8 : 6);
      long i, j;

      if (!(mask == 0 || ptype & mask)) continue;

      /* Phase 0: D2H cu_xyzw for host-side metadata reads */
      for (i = 0; i < num_runtime; i++) {
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        sympic_mem_sync_d2h(particle_spec_1[i].cu_xyzw);
      }

      /* ---- Phase 1: exchange cu_xyzw rows via NCCL ---- */
      /* Step 1a: packed meta sends — one comm send per peer */
      sympic_comm_group_start();
      for (i = 0; i < num_runtime; i++)
      {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        int *xyzw_d = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->d_data;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *s_ord = particle_spec_1[i].sort_send_ord[dir][0];
        long *s_peer = particle_spec_1[i].sort_send_peer[dir][0];
        long s_n = particle_spec_1[i].sort_send_n[dir][0];
        for (long k = 0; k < s_n; k++) {
          long jj = s_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir] != -1) continue;
          sort_plan_push(&sp, 4 * jj, 4, s_peer[k]);
        }
        sort_plan_finalize(&sp, 1);
        sort_buf_ensure_int(&particle_spec_1[i].sort_meta_send_buf,
                            &particle_spec_1[i].sort_meta_send_cap, sp.total,
                            dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        sympic_launch_sort_copy_int(particle_spec_1[i].sort_meta_send_buf,
                                    xyzw_d, particle_spec_1[i].sort_plan_src_d,
                                    particle_spec_1[i].sort_plan_dst_d,
                                    particle_spec_1[i].sort_plan_len_d, sp.nseg,
                                    dev);
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_send_int(particle_spec_1[i].sort_meta_send_buf + g_plan_peer_off[p],
                               g_plan_peer_count[p], g_plan_peer[p],
                               pthis->device_comm[i]);
      }

      /* Step 1b: packed meta recvs — one comm recv per peer */
      long l_meta_recv_nseg[8]; /* num_runtime <= 8 GPUs */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *r_ord = particle_spec_1[i].sort_recv_ord[dir][0];
        long *r_peer = particle_spec_1[i].sort_recv_peer[dir][0];
        long r_n = particle_spec_1[i].sort_recv_n[dir][0];
        for (long k = 0; k < r_n; k++) {
          long jj = r_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir + 1] != -1) continue;
          sort_plan_push(&sp, 4 * jj, 4, r_peer[k]);
        }
        sort_plan_finalize(&sp, 0);
        sort_buf_ensure_int(&particle_spec_1[i].sort_meta_recv_buf,
                            &particle_spec_1[i].sort_meta_recv_cap, sp.total,
                            dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        l_meta_recv_nseg[i] = sp.nseg;
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_recv_int(particle_spec_1[i].sort_meta_recv_buf + g_plan_peer_off[p],
                               g_plan_peer_count[p], g_plan_peer[p],
                               pthis->device_comm[i]);
      }
      sympic_comm_group_end();
      /* scatter received meta rows into swap_len_buf */
      for (i = 0; i < num_runtime; i++) {
        if (l_meta_recv_nseg[i] <= 0) continue;
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        int *len_d = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].swap_len_buf)->d_data;
        sympic_launch_sort_copy_int(len_d, particle_spec_1[i].sort_meta_recv_buf,
                                    particle_spec_1[i].sort_plan_src_d,
                                    particle_spec_1[i].sort_plan_dst_d,
                                    particle_spec_1[i].sort_plan_len_d,
                                    l_meta_recv_nseg[i],
                                    particle_spec_1[i].pfield->cuda_device);
      }
      for (i = 0; i < num_runtime; i++) {
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        sympic_device_synchronize();
      }

      /* ---- Compute frl (from_right_len) from received/swapped rows ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long numvec = pfield->numvec;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        int *xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->h_data;
        int *len_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].swap_len_buf)->h_data;
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;

        sympic_set_device(pfield->cuda_device);
        sympic_mem_sync_d2h(particle_spec_1[i].swap_len_buf);

        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
          if (recv_gate != -1) { len_h[4 * numvec + j] = 0; continue; }

          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 2;
          int xyz_idx = xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]);
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          long REMOTE_RANK = neighbor_pid / num_runtime;
          long left_local_tid = adj_local_tid[j * NUM_SYNC_LAYER + xyz_idx];

          if (neighbor_pid == self_pid) {
            len_h[4 * numvec + j] = 0;
          } else if (REMOTE_RANK == pthis->cur_rank) {
            long src_runtime = neighbor_pid % num_runtime;
            int *src_xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[src_runtime].cu_xyzw)->h_data;
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
        sympic_mem_sync_h2d(particle_spec_1[i].swap_len_buf);
      }

      /* ---- Phase 2: exchange particle data via NCCL ---- */
      long l_data_recv_nseg[8]; /* num_runtime <= 8 GPUs */
      sympic_comm_group_start();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        double *cache_d = (double *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_cache)->d_data;
        int *xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->h_data;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        /* packed data sends — one comm send per peer */
        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *s_ord = particle_spec_1[i].sort_send_ord[dir][0];
        long *s_peer = particle_spec_1[i].sort_send_peer[dir][0];
        long s_n = particle_spec_1[i].sort_send_n[dir][0];
        for (long k = 0; k < s_n; k++) {
          long jj = s_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir] != -1) continue;
          int beg = xyzw_h[4 * jj + 1];
          int end = xyzw_h[4 * jj + 2];
          if (end <= beg) continue;
          long base = jj * cu_cache_length * 6;
          sort_plan_push(&sp, base + (long)beg * ptlen,
                         (long)(end - beg) * ptlen, s_peer[k]);
        }
        sort_plan_finalize(&sp, 1);
        sort_buf_ensure_double(&particle_spec_1[i].sort_data_send_buf,
                               &particle_spec_1[i].sort_data_send_cap, sp.total,
                               dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        sympic_launch_sort_copy_double(particle_spec_1[i].sort_data_send_buf,
                                       cache_d, particle_spec_1[i].sort_plan_src_d,
                                       particle_spec_1[i].sort_plan_dst_d,
                                       particle_spec_1[i].sort_plan_len_d,
                                       sp.nseg, dev);
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_send_double(particle_spec_1[i].sort_data_send_buf + g_plan_peer_off[p],
                                  g_plan_peer_count[p], g_plan_peer[p],
                                  pthis->device_comm[i]);
      }

      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long numvec = pfield->numvec;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        double *cache_d = (double *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_cache)->d_data;
        int *xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->h_data;
        int *len_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].swap_len_buf)->h_data;
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        /* packed data recvs — one comm recv per peer */
        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *r_ord = particle_spec_1[i].sort_recv_ord[dir][0];
        long *r_peer = particle_spec_1[i].sort_recv_peer[dir][0];
        long r_n = particle_spec_1[i].sort_recv_n[dir][0];
        for (long k = 0; k < r_n; k++) {
          long jj = r_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir + 1] != -1) continue;
          int n = len_h[4 * numvec + jj];
          if (n <= 0) continue;
          int cur_len = xyzw_h[4 * jj];
          long base = jj * cu_cache_length * 6;
          sort_plan_push(&sp, base + (long)cur_len * ptlen, (long)n * ptlen,
                         r_peer[k]);
        }
        sort_plan_finalize(&sp, 0);
        sort_buf_ensure_double(&particle_spec_1[i].sort_data_recv_buf,
                               &particle_spec_1[i].sort_data_recv_cap, sp.total,
                               dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        l_data_recv_nseg[i] = sp.nseg;
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_recv_double(particle_spec_1[i].sort_data_recv_buf + g_plan_peer_off[p],
                                  g_plan_peer_count[p], g_plan_peer[p],
                                  pthis->device_comm[i]);

        /* same-rank-different-runtime recvs (rt2 only): per-segment peer copy */
        {
          long xyzarr2[3] = {1, 1, 1};
          xyzarr2[dir] = 2;
          int xyz_idx2 = xyzarr2[0] + 3 * (xyzarr2[1] + 3 * xyzarr2[2]);
          for (j = 0; j < numvec; j++) {
            long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir + 1];
            if (recv_gate != -1) continue;
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx2];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime != pthis->cur_rank) continue;
            int n = len_h[4 * numvec + j];
            if (n <= 0) continue;
            int cur_len = xyzw_h[4 * j];
            long base = j * cu_cache_length * 6;
            long src_runtime = neighbor_pid % num_runtime;
            long left_local_tid = adj_local_tid[j * NUM_SYNC_LAYER + xyz_idx2];
            int *src_xyzw_h2 = (int *)((SymPIC_Device_Mem *)particle_spec_1[src_runtime].cu_xyzw)->h_data;
            double *src_cache_d2 = (double *)((SymPIC_Device_Mem *)particle_spec_1[src_runtime].cu_cache)->d_data;
            int src_dev2 = particle_spec_1[src_runtime].pfield->cuda_device;
            int src_end2 = src_xyzw_h2[4 * left_local_tid + 2];
            long src_base2 = left_local_tid * cu_cache_length * 6;
            sympic_copy_peer(cache_d + base + (long)cur_len * ptlen, dev,
                             src_cache_d2 + src_base2 + (long)src_end2 * ptlen, src_dev2,
                             sizeof(double) * n * ptlen);
          }
        }
      }
      sympic_comm_group_end();
      /* scatter received particle data into cu_cache */
      for (i = 0; i < num_runtime; i++) {
        if (l_data_recv_nseg[i] <= 0) continue;
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        double *cache_d2 = (double *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_cache)->d_data;
        sympic_launch_sort_copy_double(cache_d2, particle_spec_1[i].sort_data_recv_buf,
                                       particle_spec_1[i].sort_plan_src_d,
                                       particle_spec_1[i].sort_plan_dst_d,
                                       particle_spec_1[i].sort_plan_len_d,
                                       l_data_recv_nseg[i],
                                       particle_spec_1[i].pfield->cuda_device);
      }

      /* ---- Phase 3: coordinate shift via GPU kernel ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        int dev = pfield->cuda_device;
        long numvec = pfield->numvec;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        long xyzlenarr[3] = {pfield->xlen, pfield->ylen, pfield->zlen};
        long XYZLEN = (1 - 0) * xyzlenarr[dir];

        sympic_set_device(dev);
        sympic_device_synchronize();

        sympic_particle_shift(&particle_spec_1[i], numvec, dir, XYZLEN,
                              ptlen, dev);
        sympic_device_synchronize();
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
      int ptype = (((Particle_in_Cell_MPI *)pthis)->o_particle_type)[xyzx];
      int ptlen = ((ptype & 2) ? 8 : 6);
      long i, j;

      if (!(mask == 0 || ptype & mask)) continue;

      /* Phase 0: D2H cu_xyzw */
      for (i = 0; i < num_runtime; i++) {
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        sympic_mem_sync_d2h(particle_spec_1[i].cu_xyzw);
      }

      /* ---- Phase 1: exchange cu_xyzw rows ---- */
      sympic_comm_group_start();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        int *xyzw_d = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->d_data;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        /* packed meta sends — one comm send per peer */
        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *s_ord = particle_spec_1[i].sort_send_ord[dir][1];
        long *s_peer = particle_spec_1[i].sort_send_peer[dir][1];
        long s_n = particle_spec_1[i].sort_send_n[dir][1];
        for (long k = 0; k < s_n; k++) {
          long jj = s_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir + 1] != -1) continue;
          sort_plan_push(&sp, 4 * jj, 4, s_peer[k]);
        }
        sort_plan_finalize(&sp, 1);
        sort_buf_ensure_int(&particle_spec_1[i].sort_meta_send_buf,
                            &particle_spec_1[i].sort_meta_send_cap, sp.total,
                            dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        sympic_launch_sort_copy_int(particle_spec_1[i].sort_meta_send_buf,
                                    xyzw_d, particle_spec_1[i].sort_plan_src_d,
                                    particle_spec_1[i].sort_plan_dst_d,
                                    particle_spec_1[i].sort_plan_len_d, sp.nseg,
                                    dev);
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_send_int(particle_spec_1[i].sort_meta_send_buf + g_plan_peer_off[p],
                               g_plan_peer_count[p], g_plan_peer[p],
                               pthis->device_comm[i]);
      }

      long r_meta_recv_nseg[8]; /* num_runtime <= 8 GPUs */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        /* packed meta recvs — one comm recv per peer */
        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *r_ord = particle_spec_1[i].sort_recv_ord[dir][1];
        long *r_peer = particle_spec_1[i].sort_recv_peer[dir][1];
        long r_n = particle_spec_1[i].sort_recv_n[dir][1];
        for (long k = 0; k < r_n; k++) {
          long jj = r_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir] != -1) continue;
          sort_plan_push(&sp, 4 * jj, 4, r_peer[k]);
        }
        sort_plan_finalize(&sp, 0);
        sort_buf_ensure_int(&particle_spec_1[i].sort_meta_recv_buf,
                            &particle_spec_1[i].sort_meta_recv_cap, sp.total,
                            dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        r_meta_recv_nseg[i] = sp.nseg;
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_recv_int(particle_spec_1[i].sort_meta_recv_buf + g_plan_peer_off[p],
                               g_plan_peer_count[p], g_plan_peer[p],
                               pthis->device_comm[i]);
      }
      sympic_comm_group_end();
      /* scatter received meta rows into swap_len_buf */
      for (i = 0; i < num_runtime; i++) {
        if (r_meta_recv_nseg[i] <= 0) continue;
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        int *len_d = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].swap_len_buf)->d_data;
        sympic_launch_sort_copy_int(len_d, particle_spec_1[i].sort_meta_recv_buf,
                                    particle_spec_1[i].sort_plan_src_d,
                                    particle_spec_1[i].sort_plan_dst_d,
                                    particle_spec_1[i].sort_plan_len_d,
                                    r_meta_recv_nseg[i],
                                    particle_spec_1[i].pfield->cuda_device);
      }
      for (i = 0; i < num_runtime; i++) {
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        sympic_device_synchronize();
      }

      /* ---- Compute frl ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long numvec = pfield->numvec;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        int *xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->h_data;
        int *len_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].swap_len_buf)->h_data;
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;

        sympic_set_device(pfield->cuda_device);
        sympic_mem_sync_d2h(particle_spec_1[i].swap_len_buf);

        for (j = 0; j < numvec; j++) {
          long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
          if (recv_gate != -1) { len_h[4 * numvec + j] = 0; continue; }

          long xyzarr[3] = {1, 1, 1};
          xyzarr[dir] = 0;
          int xyz_idx = xyzarr[0] + 3 * (xyzarr[1] + 3 * xyzarr[2]);
          long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx];
          long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
          long REMOTE_RANK = neighbor_pid / num_runtime;
          long left_local_tid = adj_local_tid[j * NUM_SYNC_LAYER + xyz_idx];

          if (neighbor_pid == self_pid) {
            len_h[4 * numvec + j] = 0;
          } else if (REMOTE_RANK == pthis->cur_rank) {
            long src_runtime = neighbor_pid % num_runtime;
            int *src_xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[src_runtime].cu_xyzw)->h_data;
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
        sympic_mem_sync_h2d(particle_spec_1[i].swap_len_buf);
      }

      /* ---- Phase 2: exchange particle data ---- */
      long r_data_recv_nseg[8]; /* num_runtime <= 8 GPUs */
      sympic_comm_group_start();
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        double *cache_d = (double *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_cache)->d_data;
        int *xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->h_data;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        /* packed data sends — one comm send per peer */
        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *s_ord = particle_spec_1[i].sort_send_ord[dir][1];
        long *s_peer = particle_spec_1[i].sort_send_peer[dir][1];
        long s_n = particle_spec_1[i].sort_send_n[dir][1];
        for (long k = 0; k < s_n; k++) {
          long jj = s_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir + 1] != -1) continue;
          int beg = xyzw_h[4 * jj + 3];
          int count = cu_cache_length - beg;
          if (count <= 0) continue;
          long base = jj * cu_cache_length * 6;
          sort_plan_push(&sp, base + (long)beg * ptlen, (long)count * ptlen,
                         s_peer[k]);
        }
        sort_plan_finalize(&sp, 1);
        sort_buf_ensure_double(&particle_spec_1[i].sort_data_send_buf,
                               &particle_spec_1[i].sort_data_send_cap, sp.total,
                               dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        sympic_launch_sort_copy_double(particle_spec_1[i].sort_data_send_buf,
                                       cache_d, particle_spec_1[i].sort_plan_src_d,
                                       particle_spec_1[i].sort_plan_dst_d,
                                       particle_spec_1[i].sort_plan_len_d,
                                       sp.nseg, dev);
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_send_double(particle_spec_1[i].sort_data_send_buf + g_plan_peer_off[p],
                                  g_plan_peer_count[p], g_plan_peer[p],
                                  pthis->device_comm[i]);
      }

      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        long numvec = pfield->numvec;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        double *cache_d = (double *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_cache)->d_data;
        int *xyzw_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_xyzw)->h_data;
        int *len_h = (int *)((SymPIC_Device_Mem *)particle_spec_1[i].swap_len_buf)->h_data;
        long *adj_processes = pfield->adj_processes;
        long *adj_local_tid = pfield->adj_local_tid;
        long *adjoint_vec_pids_h = (long *)((SymPIC_Device_Mem *)particle_spec_1[i].adjoint_vec_pids)->h_data;
        int dev = pfield->cuda_device;

        sympic_set_device(dev);

        /* packed data recvs — one comm recv per peer */
        if (!particle_spec_1[i].sort_order_valid)
          build_sort_exchange_plan(&particle_spec_1[i], pthis->cur_rank,
                                   num_runtime);
        SortSegPlan sp;
        sp.nseg = 0;
        sp.total = 0;
        sp.npeer = 0;
        long *r_ord = particle_spec_1[i].sort_recv_ord[dir][1];
        long *r_peer = particle_spec_1[i].sort_recv_peer[dir][1];
        long r_n = particle_spec_1[i].sort_recv_n[dir][1];
        for (long k = 0; k < r_n; k++) {
          long jj = r_ord[k];
          if (adjoint_vec_pids_h[jj * 6 + 2 * dir] != -1) continue;
          int n = len_h[4 * numvec + jj];
          if (n <= 0) continue;
          int cur_len = xyzw_h[4 * jj];
          long base = jj * cu_cache_length * 6;
          sort_plan_push(&sp, base + (long)cur_len * ptlen, (long)n * ptlen,
                         r_peer[k]);
        }
        sort_plan_finalize(&sp, 0);
        sort_buf_ensure_double(&particle_spec_1[i].sort_data_recv_buf,
                               &particle_spec_1[i].sort_data_recv_cap, sp.total,
                               dev);
        sort_plan_upload(&particle_spec_1[i], &sp, dev);
        r_data_recv_nseg[i] = sp.nseg;
        for (int p = 0; p < sp.npeer; p++)
          sympic_comm_recv_double(particle_spec_1[i].sort_data_recv_buf + g_plan_peer_off[p],
                                  g_plan_peer_count[p], g_plan_peer[p],
                                  pthis->device_comm[i]);

        /* same-rank-different-runtime recvs (rt2 only): per-segment peer copy */
        {
          long xyzarr2[3] = {1, 1, 1};
          xyzarr2[dir] = 0;
          int xyz_idx2 = xyzarr2[0] + 3 * (xyzarr2[1] + 3 * xyzarr2[2]);
          for (j = 0; j < numvec; j++) {
            long recv_gate = adjoint_vec_pids_h[j * 6 + 2 * dir];
            if (recv_gate != -1) continue;
            long neighbor_pid = adj_processes[j * NUM_SYNC_LAYER + xyz_idx2];
            long self_pid = adj_processes[j * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
            if (neighbor_pid == self_pid) continue;
            if (neighbor_pid / num_runtime != pthis->cur_rank) continue;
            int n = len_h[4 * numvec + j];
            if (n <= 0) continue;
            int cur_len = xyzw_h[4 * j];
            long base = j * cu_cache_length * 6;
            long src_runtime = neighbor_pid % num_runtime;
            long left_local_tid = adj_local_tid[j * NUM_SYNC_LAYER + xyz_idx2];
            int *src_xyzw_h2 = (int *)((SymPIC_Device_Mem *)particle_spec_1[src_runtime].cu_xyzw)->h_data;
            double *src_cache_d2 = (double *)((SymPIC_Device_Mem *)particle_spec_1[src_runtime].cu_cache)->d_data;
            int src_dev2 = particle_spec_1[src_runtime].pfield->cuda_device;
            int src_beg2 = src_xyzw_h2[4 * left_local_tid + 3];
            long src_base2 = left_local_tid * cu_cache_length * 6;
            sympic_copy_peer(cache_d + base + (long)cur_len * ptlen, dev,
                             src_cache_d2 + src_base2 + (long)src_beg2 * ptlen, src_dev2,
                             sizeof(double) * n * ptlen);
          }
        }
      }
      sympic_comm_group_end();
      /* scatter received particle data into cu_cache */
      for (i = 0; i < num_runtime; i++) {
        if (r_data_recv_nseg[i] <= 0) continue;
        sympic_set_device(particle_spec_1[i].pfield->cuda_device);
        double *cache_d2 = (double *)((SymPIC_Device_Mem *)particle_spec_1[i].cu_cache)->d_data;
        sympic_launch_sort_copy_double(cache_d2, particle_spec_1[i].sort_data_recv_buf,
                                       particle_spec_1[i].sort_plan_src_d,
                                       particle_spec_1[i].sort_plan_dst_d,
                                       particle_spec_1[i].sort_plan_len_d,
                                       r_data_recv_nseg[i],
                                       particle_spec_1[i].pfield->cuda_device);
      }

      /* ---- Phase 3: coordinate shift ---- */
      for (i = 0; i < num_runtime; i++) {
        Field3D_Seq *pfield = particle_spec_1[i].pfield;
        int dev = pfield->cuda_device;
        long numvec = pfield->numvec;
        long cu_cache_length = particle_spec_1[i].cu_cache_length;
        long xyzlenarr[3] = {pfield->xlen, pfield->ylen, pfield->zlen};
        long XYZLEN = (1 - 2) * xyzlenarr[dir];

        sympic_set_device(dev);
        sympic_device_synchronize();

        sympic_particle_shift(&particle_spec_1[i], numvec, dir, XYZLEN,
                              ptlen, dev);
        sympic_device_synchronize();
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
#ifdef SYMPIC_CUDA
        cuda_call_move_back_kernel_single_6((particles + i));
#elif defined(SYMPIC_MAPU)
        mapu_call_move_back_kernel_single_6((particles + i));
#endif

      } else {
#ifdef SYMPIC_CUDA
        cuda_call_move_back_kernel_single_8((particles + i));
#elif defined(SYMPIC_MAPU)
        mapu_call_move_back_kernel_single_8((particles + i));
#endif
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

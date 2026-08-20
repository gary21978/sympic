#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "pubdefs.h"
#include "kernel_includes.h"
#include "space_filling_curve.h"
#include "mpifields.h"
#include "init_field3d_mpi.h"

#ifdef SYMPIC_CUDA
int cuda_blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

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


  void *blas_yisax_enlarge_kernel = (pthis)->blas_yisax_enlarge_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_blas_yisax_enlarge_scmc_set_parameter_x(blas_yisax_enlarge_kernel, (x)->main_data);
  cuda_blas_yisax_enlarge_scmc_set_parameter_y(blas_yisax_enlarge_kernel, (y)->main_data);
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_blas_yisax_enlarge_scmc_set_parameter_num_ele(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_blas_yisax_enlarge_scmc_set_parameter_zblock(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_blas_yisax_enlarge_scmc_set_parameter_yblock(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_blas_yisax_enlarge_scmc_set_parameter_xblock(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_blas_yisax_enlarge_scmc_set_parameter_ovlp(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_blas_yisax_enlarge_scmc_set_parameter_ZLEN(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_blas_yisax_enlarge_scmc_set_parameter_YLEN(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_blas_yisax_enlarge_scmc_set_parameter_XLEN(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_blas_yisax_enlarge_scmc_set_parameter_numvec(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem cuda_alloc_prefix_a;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_a), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_a).h_data))[0] = a);
  cuda_blas_yisax_enlarge_scmc_set_parameter_a(blas_yisax_enlarge_kernel, &(cuda_alloc_prefix_a));
  cuda_blas_yisax_enlarge_exec(blas_yisax_enlarge_kernel, 1, numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_a));
  return 0;
}
#elif defined SYMPIC_MAPU
int mapu_blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

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


  void *blas_yisax_enlarge_kernel = (pthis)->blas_yisax_enlarge_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  mapu_blas_yisax_enlarge_scmc_set_parameter_x(blas_yisax_enlarge_kernel, (x)->main_data);
  mapu_blas_yisax_enlarge_scmc_set_parameter_y(blas_yisax_enlarge_kernel, (y)->main_data);
  mapu_pscmc_mem mapu_alloc_prefix_num_ele;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_num_ele).h_data))[0] = num_ele);
  mapu_blas_yisax_enlarge_scmc_set_parameter_num_ele(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem mapu_alloc_prefix_zblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_zblock).h_data))[0] = zblock);
  mapu_blas_yisax_enlarge_scmc_set_parameter_zblock(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem mapu_alloc_prefix_yblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_yblock).h_data))[0] = yblock);
  mapu_blas_yisax_enlarge_scmc_set_parameter_yblock(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem mapu_alloc_prefix_xblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_xblock).h_data))[0] = xblock);
  mapu_blas_yisax_enlarge_scmc_set_parameter_xblock(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem mapu_alloc_prefix_ovlp;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
  mapu_blas_yisax_enlarge_scmc_set_parameter_ovlp(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem mapu_alloc_prefix_ZLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  mapu_blas_yisax_enlarge_scmc_set_parameter_ZLEN(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem mapu_alloc_prefix_YLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
  mapu_blas_yisax_enlarge_scmc_set_parameter_YLEN(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem mapu_alloc_prefix_XLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
  mapu_blas_yisax_enlarge_scmc_set_parameter_XLEN(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem mapu_alloc_prefix_numvec;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
  mapu_blas_yisax_enlarge_scmc_set_parameter_numvec(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem mapu_alloc_prefix_y_cpu_core;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  mapu_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_y_cpu_core));
  mapu_pscmc_mem mapu_alloc_prefix_a;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_a), PS_DOUBLE_NUM, 0);
  ((((double *)(mapu_alloc_prefix_a).h_data))[0] = a);
  mapu_blas_yisax_enlarge_scmc_set_parameter_a(blas_yisax_enlarge_kernel, &(mapu_alloc_prefix_a));
  mapu_blas_yisax_enlarge_exec(blas_yisax_enlarge_kernel, 1, numvec);
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_y_cpu_core));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_a));
  return 0;
}
#endif
int blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {
#ifdef SYMPIC_CUDA
  return cuda_blas_yisax_enlarge_Field3D_Seq(pthis, y, a, x);
#elif defined SYMPIC_MAPU
  return mapu_blas_yisax_enlarge_Field3D_Seq(pthis, y, a, x);
#endif
}
int blas_yisax_enlarge_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int i;

  for (i = 0; (i < num_runtime); i++) {
    blas_yisax_enlarge_Field3D_Seq((data + i), ((y)->data + i), a, ((x)->data + i));
  }
  return 0;
}

#ifdef SYMPIC_CUDA
int cuda_blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

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


  void *blas_axpy_kernel = (pthis)->blas_axpy_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_blas_axpy_scmc_set_parameter_x(blas_axpy_kernel, (x)->main_data);
  cuda_blas_axpy_scmc_set_parameter_y(blas_axpy_kernel, (y)->main_data);
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_blas_axpy_scmc_set_parameter_num_ele(blas_axpy_kernel, &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_blas_axpy_scmc_set_parameter_zblock(blas_axpy_kernel, &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_blas_axpy_scmc_set_parameter_yblock(blas_axpy_kernel, &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_blas_axpy_scmc_set_parameter_xblock(blas_axpy_kernel, &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_blas_axpy_scmc_set_parameter_ovlp(blas_axpy_kernel, &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_blas_axpy_scmc_set_parameter_ZLEN(blas_axpy_kernel, &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_blas_axpy_scmc_set_parameter_YLEN(blas_axpy_kernel, &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_blas_axpy_scmc_set_parameter_XLEN(blas_axpy_kernel, &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_blas_axpy_scmc_set_parameter_numvec(blas_axpy_kernel, &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_blas_axpy_scmc_set_parameter_y_cpu_core(blas_axpy_kernel, &(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem cuda_alloc_prefix_a;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_a), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_a).h_data))[0] = a);
  cuda_blas_axpy_scmc_set_parameter_a(blas_axpy_kernel, &(cuda_alloc_prefix_a));
  cuda_blas_axpy_exec(blas_axpy_kernel, 1, numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_a));
  return 0;
}
#elif defined SYMPIC_MAPU
int mapu_blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

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


  void *blas_axpy_kernel = (pthis)->blas_axpy_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  mapu_blas_axpy_scmc_set_parameter_x(blas_axpy_kernel, (x)->main_data);
  mapu_blas_axpy_scmc_set_parameter_y(blas_axpy_kernel, (y)->main_data);
  mapu_pscmc_mem mapu_alloc_prefix_num_ele;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_num_ele).h_data))[0] = num_ele);
  mapu_blas_axpy_scmc_set_parameter_num_ele(blas_axpy_kernel, &(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem mapu_alloc_prefix_zblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_zblock).h_data))[0] = zblock);
  mapu_blas_axpy_scmc_set_parameter_zblock(blas_axpy_kernel, &(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem mapu_alloc_prefix_yblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_yblock).h_data))[0] = yblock);
  mapu_blas_axpy_scmc_set_parameter_yblock(blas_axpy_kernel, &(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem mapu_alloc_prefix_xblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_xblock).h_data))[0] = xblock);
  mapu_blas_axpy_scmc_set_parameter_xblock(blas_axpy_kernel, &(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem mapu_alloc_prefix_ovlp;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
  mapu_blas_axpy_scmc_set_parameter_ovlp(blas_axpy_kernel, &(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem mapu_alloc_prefix_ZLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  mapu_blas_axpy_scmc_set_parameter_ZLEN(blas_axpy_kernel, &(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem mapu_alloc_prefix_YLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
  mapu_blas_axpy_scmc_set_parameter_YLEN(blas_axpy_kernel, &(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem mapu_alloc_prefix_XLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
  mapu_blas_axpy_scmc_set_parameter_XLEN(blas_axpy_kernel, &(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem mapu_alloc_prefix_numvec;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
  mapu_blas_axpy_scmc_set_parameter_numvec(blas_axpy_kernel, &(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem mapu_alloc_prefix_y_cpu_core;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  mapu_blas_axpy_scmc_set_parameter_y_cpu_core(blas_axpy_kernel, &(mapu_alloc_prefix_y_cpu_core));
  mapu_pscmc_mem mapu_alloc_prefix_a;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_a), PS_DOUBLE_NUM, 0);
  ((((double *)(mapu_alloc_prefix_a).h_data))[0] = a);
  mapu_blas_axpy_scmc_set_parameter_a(blas_axpy_kernel, &(mapu_alloc_prefix_a));
  mapu_blas_axpy_exec(blas_axpy_kernel, 1, numvec);
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_y_cpu_core));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_a));
  return 0;
}
#endif
int blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {
#ifdef SYMPIC_CUDA  
  return cuda_blas_axpy_Field3D_Seq(pthis, y, a, x);
#elif defined SYMPIC_MAPU
  return mapu_blas_axpy_Field3D_Seq(pthis, y, a, x);
#endif
}
int blas_axpy_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int i;

  for (i = 0; (i < num_runtime); i++) {
    blas_axpy_Field3D_Seq((data + i), ((y)->data + i), a, ((x)->data + i));
  }
  return 0;
}

#ifdef SYMPIC_CUDA 
int cuda_blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

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


  void *blas_yisax_kernel = (pthis)->blas_yisax_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_blas_yisax_scmc_set_parameter_x(blas_yisax_kernel, (x)->main_data);
  cuda_blas_yisax_scmc_set_parameter_y(blas_yisax_kernel, (y)->main_data);
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_blas_yisax_scmc_set_parameter_num_ele(blas_yisax_kernel, &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_blas_yisax_scmc_set_parameter_zblock(blas_yisax_kernel, &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_blas_yisax_scmc_set_parameter_yblock(blas_yisax_kernel, &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_blas_yisax_scmc_set_parameter_xblock(blas_yisax_kernel, &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_blas_yisax_scmc_set_parameter_ovlp(blas_yisax_kernel, &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_blas_yisax_scmc_set_parameter_ZLEN(blas_yisax_kernel, &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_blas_yisax_scmc_set_parameter_YLEN(blas_yisax_kernel, &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_blas_yisax_scmc_set_parameter_XLEN(blas_yisax_kernel, &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_blas_yisax_scmc_set_parameter_numvec(blas_yisax_kernel, &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_blas_yisax_scmc_set_parameter_y_cpu_core(blas_yisax_kernel, &(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem cuda_alloc_prefix_a;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_a), PS_DOUBLE_NUM, 0);
  ((((double *)(cuda_alloc_prefix_a).h_data))[0] = a);
  cuda_blas_yisax_scmc_set_parameter_a(blas_yisax_kernel, &(cuda_alloc_prefix_a));
  cuda_blas_yisax_exec(blas_yisax_kernel, 1, numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_a));
  return 0;
}
#elif defined SYMPIC_MAPU
int mapu_blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

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


  void *blas_yisax_kernel = (pthis)->blas_yisax_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  mapu_blas_yisax_scmc_set_parameter_x(blas_yisax_kernel, (x)->main_data);
  mapu_blas_yisax_scmc_set_parameter_y(blas_yisax_kernel, (y)->main_data);
  mapu_pscmc_mem mapu_alloc_prefix_num_ele;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_num_ele).h_data))[0] = num_ele);
  mapu_blas_yisax_scmc_set_parameter_num_ele(blas_yisax_kernel, &(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem mapu_alloc_prefix_zblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_zblock).h_data))[0] = zblock);
  mapu_blas_yisax_scmc_set_parameter_zblock(blas_yisax_kernel, &(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem mapu_alloc_prefix_yblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_yblock).h_data))[0] = yblock);
  mapu_blas_yisax_scmc_set_parameter_yblock(blas_yisax_kernel, &(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem mapu_alloc_prefix_xblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_xblock).h_data))[0] = xblock);
  mapu_blas_yisax_scmc_set_parameter_xblock(blas_yisax_kernel, &(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem mapu_alloc_prefix_ovlp;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
  mapu_blas_yisax_scmc_set_parameter_ovlp(blas_yisax_kernel, &(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem mapu_alloc_prefix_ZLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  mapu_blas_yisax_scmc_set_parameter_ZLEN(blas_yisax_kernel, &(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem mapu_alloc_prefix_YLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
  mapu_blas_yisax_scmc_set_parameter_YLEN(blas_yisax_kernel, &(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem mapu_alloc_prefix_XLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
  mapu_blas_yisax_scmc_set_parameter_XLEN(blas_yisax_kernel, &(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem mapu_alloc_prefix_numvec;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
  mapu_blas_yisax_scmc_set_parameter_numvec(blas_yisax_kernel, &(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem mapu_alloc_prefix_y_cpu_core;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  mapu_blas_yisax_scmc_set_parameter_y_cpu_core(blas_yisax_kernel, &(mapu_alloc_prefix_y_cpu_core));
  mapu_pscmc_mem mapu_alloc_prefix_a;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_a), PS_DOUBLE_NUM, 0);
  ((((double *)(mapu_alloc_prefix_a).h_data))[0] = a);
  mapu_blas_yisax_scmc_set_parameter_a(blas_yisax_kernel, &(mapu_alloc_prefix_a));
  mapu_blas_yisax_exec(blas_yisax_kernel, 1, numvec);
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_y_cpu_core));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_a));
  return 0;
}
#endif
int blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {
#ifdef SYMPIC_CUDA   
  return cuda_blas_yisax_Field3D_Seq(pthis, y, a, x);
#elif defined SYMPIC_MAPU
  return mapu_blas_yisax_Field3D_Seq(pthis, y, a, x);
#endif
}
int blas_yisax_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int i;

  for (i = 0; (i < num_runtime); i++) {
    blas_yisax_Field3D_Seq((data + i), ((y)->data + i), a, ((x)->data + i));
  }
  return 0;
}

#ifdef SYMPIC_CUDA 
int cuda_blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {

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


  void *blas_yiszero_kernel = (pthis)->blas_yiszero_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_blas_yiszero_scmc_set_parameter_y(blas_yiszero_kernel, (y)->main_data);
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_blas_yiszero_scmc_set_parameter_num_ele(blas_yiszero_kernel, &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_blas_yiszero_scmc_set_parameter_zblock(blas_yiszero_kernel, &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_blas_yiszero_scmc_set_parameter_yblock(blas_yiszero_kernel, &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_blas_yiszero_scmc_set_parameter_xblock(blas_yiszero_kernel, &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_blas_yiszero_scmc_set_parameter_ovlp(blas_yiszero_kernel, &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_blas_yiszero_scmc_set_parameter_ZLEN(blas_yiszero_kernel, &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_blas_yiszero_scmc_set_parameter_YLEN(blas_yiszero_kernel, &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_blas_yiszero_scmc_set_parameter_XLEN(blas_yiszero_kernel, &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_blas_yiszero_scmc_set_parameter_numvec(blas_yiszero_kernel, &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_blas_yiszero_scmc_set_parameter_y_cpu_core(blas_yiszero_kernel, &(cuda_alloc_prefix_y_cpu_core));
  cuda_blas_yiszero_exec(blas_yiszero_kernel, 1, numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  return 0;
}
#elif defined SYMPIC_MAPU
int mapu_blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {

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


  void *blas_yiszero_kernel = (pthis)->blas_yiszero_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  mapu_blas_yiszero_scmc_set_parameter_y(blas_yiszero_kernel, (y)->main_data);
  mapu_pscmc_mem mapu_alloc_prefix_num_ele;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_num_ele).h_data))[0] = num_ele);
  mapu_blas_yiszero_scmc_set_parameter_num_ele(blas_yiszero_kernel, &(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem mapu_alloc_prefix_zblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_zblock).h_data))[0] = zblock);
  mapu_blas_yiszero_scmc_set_parameter_zblock(blas_yiszero_kernel, &(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem mapu_alloc_prefix_yblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_yblock).h_data))[0] = yblock);
  mapu_blas_yiszero_scmc_set_parameter_yblock(blas_yiszero_kernel, &(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem mapu_alloc_prefix_xblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_xblock).h_data))[0] = xblock);
  mapu_blas_yiszero_scmc_set_parameter_xblock(blas_yiszero_kernel, &(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem mapu_alloc_prefix_ovlp;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
  mapu_blas_yiszero_scmc_set_parameter_ovlp(blas_yiszero_kernel, &(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem mapu_alloc_prefix_ZLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  mapu_blas_yiszero_scmc_set_parameter_ZLEN(blas_yiszero_kernel, &(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem mapu_alloc_prefix_YLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
  mapu_blas_yiszero_scmc_set_parameter_YLEN(blas_yiszero_kernel, &(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem mapu_alloc_prefix_XLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
  mapu_blas_yiszero_scmc_set_parameter_XLEN(blas_yiszero_kernel, &(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem mapu_alloc_prefix_numvec;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
  mapu_blas_yiszero_scmc_set_parameter_numvec(blas_yiszero_kernel, &(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem mapu_alloc_prefix_y_cpu_core;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  mapu_blas_yiszero_scmc_set_parameter_y_cpu_core(blas_yiszero_kernel, &(mapu_alloc_prefix_y_cpu_core));
  mapu_blas_yiszero_exec(blas_yiszero_kernel, 1, numvec);
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_y_cpu_core));
  return 0;
}
#endif
int blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {
#ifdef SYMPIC_CUDA
  return cuda_blas_yiszero_Field3D_Seq(pthis, y);
#elif defined SYMPIC_MAPU
  return mapu_blas_yiszero_Field3D_Seq(pthis, y);
#endif
}
int blas_yiszero_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int i;

  for (i = 0; (i < num_runtime); i++) {
    blas_yiszero_Field3D_Seq((data + i), ((y)->data + i));
  }
  return 0;
}

#ifdef SYMPIC_CUDA
int cuda_blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {

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


  void *blas_yiszero_synced_kernel = (pthis)->blas_yiszero_synced_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  cuda_blas_yiszero_synced_scmc_set_parameter_y(blas_yiszero_synced_kernel, (y)->main_data);
  cuda_pscmc_mem cuda_alloc_prefix_num_ele;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_num_ele).h_data))[0] = num_ele);
  cuda_blas_yiszero_synced_scmc_set_parameter_num_ele(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem cuda_alloc_prefix_zblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_zblock).h_data))[0] = zblock);
  cuda_blas_yiszero_synced_scmc_set_parameter_zblock(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem cuda_alloc_prefix_yblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_yblock).h_data))[0] = yblock);
  cuda_blas_yiszero_synced_scmc_set_parameter_yblock(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem cuda_alloc_prefix_xblock;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_xblock).h_data))[0] = xblock);
  cuda_blas_yiszero_synced_scmc_set_parameter_xblock(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem cuda_alloc_prefix_ovlp;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(cuda_alloc_prefix_ovlp).h_data))[0] = ovlp);
  cuda_blas_yiszero_synced_scmc_set_parameter_ovlp(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  cuda_blas_yiszero_synced_scmc_set_parameter_ZLEN(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem cuda_alloc_prefix_YLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_YLEN).h_data))[0] = YLEN);
  cuda_blas_yiszero_synced_scmc_set_parameter_YLEN(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem cuda_alloc_prefix_XLEN;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_XLEN).h_data))[0] = XLEN);
  cuda_blas_yiszero_synced_scmc_set_parameter_XLEN(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem cuda_alloc_prefix_numvec;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_numvec).h_data))[0] = numvec);
  cuda_blas_yiszero_synced_scmc_set_parameter_numvec(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem cuda_alloc_prefix_y_cpu_core;

  cuda_pscmc_mem_init(pe, &(cuda_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(cuda_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  cuda_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(blas_yiszero_synced_kernel, &(cuda_alloc_prefix_y_cpu_core));
  cuda_blas_yiszero_synced_exec(blas_yiszero_synced_kernel, 1, numvec);
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_num_ele));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_zblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_yblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_xblock));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ovlp));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_ZLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_YLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_XLEN));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_numvec));
  cuda_pscmc_mem_destroy(&(cuda_alloc_prefix_y_cpu_core));
  return 0;
}
#elif defined SYMPIC_MAPU
int mapu_blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {

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


  void *blas_yiszero_synced_kernel = (pthis)->blas_yiszero_synced_kernel;


  //====================Field3D_Seq
  long XLEN = xlen;

  long YLEN = ylen;

  long ZLEN = zlen;

  long y_cpu_core = numvec;

  mapu_blas_yiszero_synced_scmc_set_parameter_y(blas_yiszero_synced_kernel, (y)->main_data);
  mapu_pscmc_mem mapu_alloc_prefix_num_ele;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_num_ele), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_num_ele).h_data))[0] = num_ele);
  mapu_blas_yiszero_synced_scmc_set_parameter_num_ele(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem mapu_alloc_prefix_zblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_zblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_zblock).h_data))[0] = zblock);
  mapu_blas_yiszero_synced_scmc_set_parameter_zblock(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem mapu_alloc_prefix_yblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_yblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_yblock).h_data))[0] = yblock);
  mapu_blas_yiszero_synced_scmc_set_parameter_yblock(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem mapu_alloc_prefix_xblock;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_xblock), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_xblock).h_data))[0] = xblock);
  mapu_blas_yiszero_synced_scmc_set_parameter_xblock(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem mapu_alloc_prefix_ovlp;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ovlp), PS_INT_NUM, 0);
  ((((int *)(mapu_alloc_prefix_ovlp).h_data))[0] = ovlp);
  mapu_blas_yiszero_synced_scmc_set_parameter_ovlp(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem mapu_alloc_prefix_ZLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_ZLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_ZLEN).h_data))[0] = ZLEN);
  mapu_blas_yiszero_synced_scmc_set_parameter_ZLEN(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem mapu_alloc_prefix_YLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_YLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_YLEN).h_data))[0] = YLEN);
  mapu_blas_yiszero_synced_scmc_set_parameter_YLEN(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem mapu_alloc_prefix_XLEN;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_XLEN), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_XLEN).h_data))[0] = XLEN);
  mapu_blas_yiszero_synced_scmc_set_parameter_XLEN(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem mapu_alloc_prefix_numvec;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_numvec), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_numvec).h_data))[0] = numvec);
  mapu_blas_yiszero_synced_scmc_set_parameter_numvec(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem mapu_alloc_prefix_y_cpu_core;

  mapu_pscmc_mem_init(pe, &(mapu_alloc_prefix_y_cpu_core), PS_LONG_NUM, 0);
  ((((long *)(mapu_alloc_prefix_y_cpu_core).h_data))[0] = y_cpu_core);
  mapu_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(blas_yiszero_synced_kernel, &(mapu_alloc_prefix_y_cpu_core));
  mapu_blas_yiszero_synced_exec(blas_yiszero_synced_kernel, 1, numvec);
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_num_ele));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_zblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_yblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_xblock));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ovlp));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_ZLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_YLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_XLEN));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_numvec));
  mapu_pscmc_mem_destroy(&(mapu_alloc_prefix_y_cpu_core));
  return 0;
}
#endif
int blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {
#ifdef SYMPIC_CUDA
  return cuda_blas_yiszero_synced_Field3D_Seq(pthis, y);
#elif defined SYMPIC_MAPU
  return mapu_blas_yiszero_synced_Field3D_Seq(pthis, y);
#endif
}
int blas_yiszero_synced_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int i;

  for (i = 0; (i < num_runtime); i++) {
    blas_yiszero_synced_Field3D_Seq((data + i), ((y)->data + i));
  }
  return 0;
}

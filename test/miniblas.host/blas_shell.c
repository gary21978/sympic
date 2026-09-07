#include "blas_shell.h"
#include "miniblas.kernel_runtime.h"

int mapu_blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {

  // defined from class Field3D_Seq
  void *pe = pthis->pe;
  long xlen = pthis->xlen;
  long ylen = pthis->ylen;
  long zlen = pthis->zlen;
  long xblock = pthis->xblock;
  long yblock = pthis->yblock;
  long zblock = pthis->zblock;
  long numvec = pthis->numvec;

  int ovlp = pthis->ovlp;
  int num_ele = pthis->num_ele;

  void *blas_axpy_kernel = pthis->blas_axpy_kernel;
    printf("blas_shell.sc--pthis->pe: %p\n", pthis->pe);
    printf("blas_shell.sc--pthis->xlen: %d\n", pthis->xlen);
    printf("blas_shell.sc--pthis->ylen: %d\n", pthis->ylen);
    printf("blas_shell.sc--pthis->zlen: %d\n", pthis->zlen);
    printf("blas_shell.sc--pthis->xblock: %d\n", pthis->xblock);
    printf("blas_shell.sc--pthis->yblock: %d\n", pthis->yblock);
    printf("blas_shell.sc--pthis->zblock: %d\n", pthis->zblock);
    printf("blas_shell.sc--pthis->numvec: %d\n", pthis->numvec);
    printf("blas_shell.sc--pthis->blas_axpy_kernel: %p\n", pthis->blas_axpy_kernel);
    printf("blas_shell.sc--blas_axpy_kernel: %p\n", blas_axpy_kernel);

  //====================Field3D_Seq
  long XLEN = xlen;
  long YLEN = ylen;
  long ZLEN = zlen;
  long y_cpu_core = numvec;

  mapu_blas_axpy_scmc_set_parameter_x(blas_axpy_kernel, (x)->main_data);
  mapu_blas_axpy_scmc_set_parameter_y(blas_axpy_kernel, (y)->main_data);

    printf("blas_shell.sc--blas_axpy_kernel->x: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->x);
    printf("blas_shell.sc--blas_axpy_kernel->y: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->y);
    printf("blas_shell.sc--x->main_data: %p\n", x->main_data);
    printf("blas_shell.sc--y->main_data: %p\n", y->main_data);
    printf("blas_shell.sc--x->main_data->d_data: %p\n", ((mapu_pscmc_mem *)(x->main_data))->d_data);
    printf("blas_shell.sc--y->main_data->d_data: %p\n", ((mapu_pscmc_mem *)(y->main_data))->d_data);

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
  printf("~~~~~~~~~~~~~~~mapu_blas_axpy_exec~~~~~~~~~~~~~~~\n");
  printf("&mapu_alloc_prefix_num_ele: %p\n", &mapu_alloc_prefix_num_ele);
  printf("blas_axpy_kernel->num_ele: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->num_ele);
  printf("&mapu_alloc_prefix_zblock: %p\n", &mapu_alloc_prefix_zblock);
  printf("blas_axpy_kernel->zblock: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->zblock);
  printf("&mapu_alloc_prefix_yblock: %p\n", &mapu_alloc_prefix_yblock);
  printf("blas_axpy_kernel->yblock: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->yblock);
  printf("&mapu_alloc_prefix_xblock: %p\n", &mapu_alloc_prefix_xblock);
  printf("blas_axpy_kernel->xblock: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->xblock);
  printf("&mapu_alloc_prefix_ovlp: %p\n", &mapu_alloc_prefix_ovlp);
  printf("blas_axpy_kernel->ovlp: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->ovlp);
  printf("&mapu_alloc_prefix_ZLEN: %p\n", &mapu_alloc_prefix_ZLEN);
  printf("blas_axpy_kernel->ZLEN: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->ZLEN);
  printf("&mapu_alloc_prefix_YLEN: %p\n", &mapu_alloc_prefix_YLEN);
  printf("blas_axpy_kernel->YLEN: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->YLEN);
  printf("&mapu_alloc_prefix_XLEN: %p\n", &mapu_alloc_prefix_XLEN);
  printf("blas_axpy_kernel->XLEN: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->XLEN);
  printf("&mapu_alloc_prefix_numvec: %p\n", &mapu_alloc_prefix_numvec);
  printf("blas_axpy_kernel->numvec: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->numvec);
  printf("&mapu_alloc_prefix_y_cpu_core: %p\n", &mapu_alloc_prefix_y_cpu_core);
  printf("blas_axpy_kernel->y_cpu_core: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->y_cpu_core);
  printf("&mapu_alloc_prefix_a: %p\n", &mapu_alloc_prefix_a);
  printf("blas_axpy_kernel->a: %p\n", ((mapu_blas_axpy_struct *)blas_axpy_kernel)->a);
//return 0;
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

int blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) 
{
    return mapu_blas_axpy_Field3D_Seq(pthis, y, a, x);
}

int blas_axpy_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x)
{
    Field3D_Seq *data = pthis->data;
    long num_runtime = pthis->num_runtime;

    for (int i = 0; i < num_runtime; i++)
    {
        blas_axpy_Field3D_Seq(data + i, y->data + i, a, x->data + i);
    }
    return 0;
}

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

int blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {
    return mapu_blas_yisax_Field3D_Seq(pthis, y, a, x);
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

int blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x) {
    return mapu_blas_yisax_enlarge_Field3D_Seq(pthis, y, a, x);
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

int blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {
    return mapu_blas_yiszero_Field3D_Seq(pthis, y);
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

int blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y) {
    return mapu_blas_yiszero_synced_Field3D_Seq(pthis, y);
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
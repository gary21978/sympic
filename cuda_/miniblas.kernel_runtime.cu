#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "miniblas.kernel_inc.h"

#include "miniblas.kernel.cu"

extern "C" {
int cuda_blas_axpby_enlarge_init(cuda_pscmc_env *pe,
                                 cuda_blas_axpby_enlarge_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpby_enlarge_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpby_enlarge_struct));
}
int cuda_blas_axpby_enlarge_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpby_enlarge_get_num_compute_units(
    cuda_blas_axpby_enlarge_struct *kerstr) {
  return 64;
}
int cuda_blas_axpby_enlarge_exec(cuda_blas_axpby_enlarge_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpby_enlarge<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpby_enlarge<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpby_enlarge");
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_y(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_x(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_a(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_b(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_numvec(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_XLEN(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_YLEN(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_ZLEN(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_ovlp(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_xblock(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_yblock(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_zblock(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpby_enlarge_scmc_set_parameter_num_ele(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpby_shrink_init(cuda_pscmc_env *pe,
                                cuda_blas_axpby_shrink_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpby_shrink_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpby_shrink_struct));
}
int cuda_blas_axpby_shrink_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpby_shrink_get_num_compute_units(
    cuda_blas_axpby_shrink_struct *kerstr) {
  return 64;
}
int cuda_blas_axpby_shrink_exec(cuda_blas_axpby_shrink_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpby_shrink<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpby_shrink<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpby_shrink");
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_y(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_x(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_a(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_b(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_numvec(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_XLEN(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_YLEN(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_ZLEN(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_ovlp(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_xblock(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_yblock(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_zblock(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpby_shrink_scmc_set_parameter_num_ele(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_init(cuda_pscmc_env *pe,
                                cuda_blas_axpy_enlarge_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpy_enlarge_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpy_enlarge_struct));
}
int cuda_blas_axpy_enlarge_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpy_enlarge_get_num_compute_units(
    cuda_blas_axpy_enlarge_struct *kerstr) {
  return 64;
}
int cuda_blas_axpy_enlarge_exec(cuda_blas_axpy_enlarge_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpy_enlarge<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpy_enlarge<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpy_enlarge");
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_y(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_x(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_a(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_numvec(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_XLEN(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_YLEN(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_ZLEN(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_ovlp(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_xblock(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_yblock(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_zblock(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpy_enlarge_scmc_set_parameter_num_ele(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpy_shrink_init(cuda_pscmc_env *pe,
                               cuda_blas_axpy_shrink_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpy_shrink_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpy_shrink_struct));
}
int cuda_blas_axpy_shrink_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpy_shrink_get_num_compute_units(
    cuda_blas_axpy_shrink_struct *kerstr) {
  return 64;
}
int cuda_blas_axpy_shrink_exec(cuda_blas_axpy_shrink_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpy_shrink<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpy_shrink<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpy_shrink");
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_y(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_x(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_a(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_numvec(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_XLEN(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_YLEN(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_ZLEN(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_ovlp(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_xblock(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_yblock(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_zblock(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpy_shrink_scmc_set_parameter_num_ele(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_init(cuda_pscmc_env *pe,
                                 cuda_blas_yisax_enlarge_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yisax_enlarge_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yisax_enlarge_struct));
}
int cuda_blas_yisax_enlarge_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yisax_enlarge_get_num_compute_units(
    cuda_blas_yisax_enlarge_struct *kerstr) {
  return 64;
}
int cuda_blas_yisax_enlarge_exec(cuda_blas_yisax_enlarge_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yisax_enlarge<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yisax_enlarge<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yisax_enlarge");
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_y(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_x(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_a(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_numvec(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_XLEN(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_YLEN(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_ZLEN(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_ovlp(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_xblock(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_yblock(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_zblock(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yisax_enlarge_scmc_set_parameter_num_ele(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yisax_shrink_init(cuda_pscmc_env *pe,
                                cuda_blas_yisax_shrink_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yisax_shrink_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yisax_shrink_struct));
}
int cuda_blas_yisax_shrink_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yisax_shrink_get_num_compute_units(
    cuda_blas_yisax_shrink_struct *kerstr) {
  return 64;
}
int cuda_blas_yisax_shrink_exec(cuda_blas_yisax_shrink_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yisax_shrink<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yisax_shrink<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yisax_shrink");
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_y(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_x(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_a(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_numvec(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_XLEN(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_YLEN(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_ZLEN(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_ovlp(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_xblock(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_yblock(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_zblock(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yisax_shrink_scmc_set_parameter_num_ele(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_sum_full_block_init(cuda_pscmc_env *pe,
                                  cuda_blas_sum_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_sum_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_sum_full_block_struct));
}
int cuda_blas_sum_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_sum_full_block_get_num_compute_units(
    cuda_blas_sum_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_sum_full_block_exec(cuda_blas_sum_full_block_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_sum_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_sum_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_sum_full_block");
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_y(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_rdcd_sum(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->rdcd_sum = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_numvec(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_XLEN(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_YLEN(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_ovlp(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_xblock(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_yblock(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_zblock(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_sum_full_block_scmc_set_parameter_num_ele(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_sum_init(cuda_pscmc_env *pe, cuda_blas_sum_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_sum_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_sum_struct));
}
int cuda_blas_sum_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_sum_get_num_compute_units(cuda_blas_sum_struct *kerstr) {
  return 64;
}
int cuda_blas_sum_exec(cuda_blas_sum_struct *kerstr, long scmc_internal_g_xlen,
                       long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_sum<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_sum<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_sum");
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_y(cuda_blas_sum_struct *kerstr,
                                       cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_rdcd_sum(cuda_blas_sum_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->rdcd_sum = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_y_cpu_core(cuda_blas_sum_struct *kerstr,
                                                cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_numvec(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_XLEN(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_YLEN(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_ZLEN(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_ovlp(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_xblock(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_yblock(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_zblock(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_sum_scmc_set_parameter_num_ele(cuda_blas_sum_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_dot_full_block_init(cuda_pscmc_env *pe,
                                  cuda_blas_dot_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_dot_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_dot_full_block_struct));
}
int cuda_blas_dot_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_dot_full_block_get_num_compute_units(
    cuda_blas_dot_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_dot_full_block_exec(cuda_blas_dot_full_block_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_dot_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_dot_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_dot_full_block");
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_y(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_x(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_rdcd_sum(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->rdcd_sum = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_numvec(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_XLEN(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_YLEN(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_ovlp(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_xblock(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_yblock(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_zblock(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_dot_full_block_scmc_set_parameter_num_ele(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_dot_init(cuda_pscmc_env *pe, cuda_blas_dot_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_dot_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_dot_struct));
}
int cuda_blas_dot_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_dot_get_num_compute_units(cuda_blas_dot_struct *kerstr) {
  return 64;
}
int cuda_blas_dot_exec(cuda_blas_dot_struct *kerstr, long scmc_internal_g_xlen,
                       long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_dot<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_dot<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->rdcd_sum->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_dot");
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_y(cuda_blas_dot_struct *kerstr,
                                       cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_x(cuda_blas_dot_struct *kerstr,
                                       cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_rdcd_sum(cuda_blas_dot_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->rdcd_sum = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_y_cpu_core(cuda_blas_dot_struct *kerstr,
                                                cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_numvec(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_XLEN(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_YLEN(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_ZLEN(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_ovlp(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_xblock(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_yblock(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_zblock(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_dot_scmc_set_parameter_num_ele(cuda_blas_dot_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_findmax_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_findmax_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_findmax_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_findmax_full_block_struct));
}
int cuda_blas_findmax_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_findmax_full_block_get_num_compute_units(
    cuda_blas_findmax_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_findmax_full_block_exec(
    cuda_blas_findmax_full_block_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_findmax_full_block<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_max->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_findmax_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_max->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_findmax_full_block");
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_y(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_rdcd_max(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->rdcd_max = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_numvec(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_XLEN(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_YLEN(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_ovlp(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_xblock(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_yblock(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_zblock(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_findmax_full_block_scmc_set_parameter_num_ele(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_findmax_init(cuda_pscmc_env *pe,
                           cuda_blas_findmax_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_findmax_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_findmax_struct));
}
int cuda_blas_findmax_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_findmax_get_num_compute_units(cuda_blas_findmax_struct *kerstr) {
  return 64;
}
int cuda_blas_findmax_exec(cuda_blas_findmax_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_findmax<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_max->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_findmax<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->rdcd_max->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_findmax");
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_y(cuda_blas_findmax_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_rdcd_max(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->rdcd_max = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_y_cpu_core(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_numvec(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_XLEN(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_YLEN(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_ZLEN(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_ovlp(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_xblock(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_yblock(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_zblock(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_findmax_scmc_set_parameter_num_ele(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_init(cuda_pscmc_env *pe,
                                    cuda_blas_mulxy_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_mulxy_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_mulxy_full_block_struct));
}
int cuda_blas_mulxy_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_mulxy_full_block_get_num_compute_units(
    cuda_blas_mulxy_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_mulxy_full_block_exec(cuda_blas_mulxy_full_block_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_mulxy_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_mulxy_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_mulxy_full_block");
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_y(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_x(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_numvec(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_XLEN(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_YLEN(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_ovlp(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_xblock(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_yblock(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_zblock(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_mulxy_full_block_scmc_set_parameter_num_ele(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_mulxy_init(cuda_pscmc_env *pe, cuda_blas_mulxy_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_mulxy_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_mulxy_struct));
}
int cuda_blas_mulxy_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_mulxy_get_num_compute_units(cuda_blas_mulxy_struct *kerstr) {
  return 64;
}
int cuda_blas_mulxy_exec(cuda_blas_mulxy_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_mulxy<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_mulxy<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_mulxy");
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_y(cuda_blas_mulxy_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_x(cuda_blas_mulxy_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_y_cpu_core(
    cuda_blas_mulxy_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_numvec(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_XLEN(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_YLEN(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_ZLEN(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_ovlp(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_xblock(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_yblock(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_zblock(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_mulxy_scmc_set_parameter_num_ele(cuda_blas_mulxy_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpby_full_block_init(cuda_pscmc_env *pe,
                                    cuda_blas_axpby_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpby_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpby_full_block_struct));
}
int cuda_blas_axpby_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpby_full_block_get_num_compute_units(
    cuda_blas_axpby_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_axpby_full_block_exec(cuda_blas_axpby_full_block_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpby_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpby_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpby_full_block");
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_y(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_x(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_a(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_b(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_numvec(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_XLEN(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_YLEN(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_ovlp(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_xblock(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_yblock(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_zblock(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpby_full_block_scmc_set_parameter_num_ele(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpby_init(cuda_pscmc_env *pe, cuda_blas_axpby_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpby_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpby_struct));
}
int cuda_blas_axpby_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpby_get_num_compute_units(cuda_blas_axpby_struct *kerstr) {
  return 64;
}
int cuda_blas_axpby_exec(cuda_blas_axpby_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpby<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpby<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0], (((double *)kerstr->b->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpby");
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_y(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_x(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_a(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_b(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->b = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_numvec(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_XLEN(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_YLEN(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_ZLEN(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_ovlp(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_xblock(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_yblock(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_zblock(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpby_scmc_set_parameter_num_ele(cuda_blas_axpby_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpy_full_block_init(cuda_pscmc_env *pe,
                                   cuda_blas_axpy_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpy_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpy_full_block_struct));
}
int cuda_blas_axpy_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpy_full_block_get_num_compute_units(
    cuda_blas_axpy_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_axpy_full_block_exec(cuda_blas_axpy_full_block_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpy_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpy_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpy_full_block");
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_y(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_x(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_a(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_numvec(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_XLEN(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_YLEN(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_ovlp(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_xblock(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_yblock(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_zblock(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpy_full_block_scmc_set_parameter_num_ele(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_axpy_init(cuda_pscmc_env *pe, cuda_blas_axpy_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_axpy_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_axpy_struct));
}
int cuda_blas_axpy_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_axpy_get_num_compute_units(cuda_blas_axpy_struct *kerstr) {
  return 64;
}
int cuda_blas_axpy_exec(cuda_blas_axpy_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_axpy<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_axpy<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_axpy");
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_y(cuda_blas_axpy_struct *kerstr,
                                        cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_x(cuda_blas_axpy_struct *kerstr,
                                        cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_a(cuda_blas_axpy_struct *kerstr,
                                        cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_y_cpu_core(cuda_blas_axpy_struct *kerstr,
                                                 cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_numvec(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_XLEN(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_YLEN(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_ZLEN(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_ovlp(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_xblock(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_yblock(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_zblock(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_axpy_scmc_set_parameter_num_ele(cuda_blas_axpy_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yisax_full_block_init(cuda_pscmc_env *pe,
                                    cuda_blas_yisax_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yisax_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yisax_full_block_struct));
}
int cuda_blas_yisax_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yisax_full_block_get_num_compute_units(
    cuda_blas_yisax_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_yisax_full_block_exec(cuda_blas_yisax_full_block_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yisax_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yisax_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yisax_full_block");
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_y(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_x(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_a(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_numvec(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_XLEN(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_YLEN(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_ovlp(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_xblock(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_yblock(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_zblock(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yisax_full_block_scmc_set_parameter_num_ele(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yisax_init(cuda_pscmc_env *pe, cuda_blas_yisax_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yisax_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yisax_struct));
}
int cuda_blas_yisax_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yisax_get_num_compute_units(cuda_blas_yisax_struct *kerstr) {
  return 64;
}
int cuda_blas_yisax_exec(cuda_blas_yisax_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yisax<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yisax<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yisax");
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_y(cuda_blas_yisax_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_x(cuda_blas_yisax_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_a(cuda_blas_yisax_struct *kerstr,
                                         cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_numvec(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_XLEN(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_YLEN(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_ZLEN(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_ovlp(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_xblock(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_yblock(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_zblock(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yisax_scmc_set_parameter_num_ele(cuda_blas_yisax_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_invy_full_block_init(cuda_pscmc_env *pe,
                                   cuda_blas_invy_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_invy_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_invy_full_block_struct));
}
int cuda_blas_invy_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_invy_full_block_get_num_compute_units(
    cuda_blas_invy_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_invy_full_block_exec(cuda_blas_invy_full_block_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_invy_full_block<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_invy_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_invy_full_block");
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_y(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_numvec(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_XLEN(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_YLEN(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_ovlp(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_xblock(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_yblock(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_zblock(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_invy_full_block_scmc_set_parameter_num_ele(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_invy_init(cuda_pscmc_env *pe, cuda_blas_invy_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_invy_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_invy_struct));
}
int cuda_blas_invy_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_invy_get_num_compute_units(cuda_blas_invy_struct *kerstr) {
  return 64;
}
int cuda_blas_invy_exec(cuda_blas_invy_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_invy<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_invy<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_invy");
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_y(cuda_blas_invy_struct *kerstr,
                                        cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_y_cpu_core(cuda_blas_invy_struct *kerstr,
                                                 cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_numvec(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_XLEN(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_YLEN(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_ZLEN(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_ovlp(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_xblock(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_yblock(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_zblock(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_invy_scmc_set_parameter_num_ele(cuda_blas_invy_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_get_ITG_Potential_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_get_ITG_Potential_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_get_ITG_Potential_full_block_struct));
}
int cuda_blas_get_ITG_Potential_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_get_ITG_Potential_full_block_get_num_compute_units(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_get_ITG_Potential_full_block_exec(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_get_ITG_Potential_full_block<<<scmc_internal_g_ylen,
                                             scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->u->d_data),
        (((double *)kerstr->minus_over_q_e->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_get_ITG_Potential_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->u->d_data),
        (((double *)kerstr->minus_over_q_e->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_get_ITG_Potential_full_block");
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_y(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_x(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_u(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->u = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_minus_over_q_e(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->minus_over_q_e = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_numvec(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_XLEN(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_YLEN(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_ovlp(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_xblock(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_yblock(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_zblock(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_num_ele(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_init(
    cuda_pscmc_env *pe, cuda_blas_get_ITG_Potential_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_get_ITG_Potential_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_get_ITG_Potential_struct));
}
int cuda_blas_get_ITG_Potential_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_get_ITG_Potential_get_num_compute_units(
    cuda_blas_get_ITG_Potential_struct *kerstr) {
  return 64;
}
int cuda_blas_get_ITG_Potential_exec(cuda_blas_get_ITG_Potential_struct *kerstr,
                                     long scmc_internal_g_xlen,
                                     long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_get_ITG_Potential<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->u->d_data),
        (((double *)kerstr->minus_over_q_e->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_get_ITG_Potential<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        ((double *)kerstr->u->d_data),
        (((double *)kerstr->minus_over_q_e->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_get_ITG_Potential");
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_y(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_x(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_u(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->u = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_minus_over_q_e(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->minus_over_q_e = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_y_cpu_core(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_numvec(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_XLEN(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_YLEN(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_ZLEN(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_ovlp(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_xblock(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_yblock(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_zblock(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_get_ITG_Potential_scmc_set_parameter_num_ele(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_yisconst_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yisconst_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yisconst_full_block_struct));
}
int cuda_blas_yisconst_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yisconst_full_block_get_num_compute_units(
    cuda_blas_yisconst_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_yisconst_full_block_exec(
    cuda_blas_yisconst_full_block_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yisconst_full_block<<<scmc_internal_g_ylen,
                                    scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yisconst_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yisconst_full_block");
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_y(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_a(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_numvec(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_XLEN(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_YLEN(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_ovlp(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_xblock(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_yblock(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_zblock(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yisconst_full_block_scmc_set_parameter_num_ele(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yisconst_init(cuda_pscmc_env *pe,
                            cuda_blas_yisconst_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yisconst_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yisconst_struct));
}
int cuda_blas_yisconst_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yisconst_get_num_compute_units(
    cuda_blas_yisconst_struct *kerstr) {
  return 64;
}
int cuda_blas_yisconst_exec(cuda_blas_yisconst_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yisconst<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yisconst<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), (((double *)kerstr->a->h_data))[0],
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yisconst");
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_y(cuda_blas_yisconst_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_a(cuda_blas_yisconst_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->a = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_numvec(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_XLEN(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_YLEN(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_ZLEN(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_ovlp(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_xblock(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_yblock(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_zblock(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yisconst_scmc_set_parameter_num_ele(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_yiszero_full_block_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yiszero_full_block_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yiszero_full_block_struct));
}
int cuda_blas_yiszero_full_block_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yiszero_full_block_get_num_compute_units(
    cuda_blas_yiszero_full_block_struct *kerstr) {
  return 64;
}
int cuda_blas_yiszero_full_block_exec(
    cuda_blas_yiszero_full_block_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yiszero_full_block<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yiszero_full_block<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yiszero_full_block");
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_y(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_numvec(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_XLEN(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_YLEN(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_ovlp(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_xblock(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_yblock(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_zblock(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yiszero_full_block_scmc_set_parameter_num_ele(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yiszero_init(cuda_pscmc_env *pe,
                           cuda_blas_yiszero_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yiszero_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yiszero_struct));
}
int cuda_blas_yiszero_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yiszero_get_num_compute_units(cuda_blas_yiszero_struct *kerstr) {
  return 64;
}
int cuda_blas_yiszero_exec(cuda_blas_yiszero_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yiszero<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yiszero<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yiszero");
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_y(cuda_blas_yiszero_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_y_cpu_core(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_numvec(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_XLEN(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_YLEN(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_ZLEN(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_ovlp(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_xblock(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_yblock(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_zblock(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yiszero_scmc_set_parameter_num_ele(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_init(cuda_pscmc_env *pe,
                                 cuda_blas_mulxy_numele3_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_mulxy_numele3_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_mulxy_numele3_struct));
}
int cuda_blas_mulxy_numele3_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_mulxy_numele3_get_num_compute_units(
    cuda_blas_mulxy_numele3_struct *kerstr) {
  return 64;
}
int cuda_blas_mulxy_numele3_exec(cuda_blas_mulxy_numele3_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_mulxy_numele3<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_mulxy_numele3<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data), ((double *)kerstr->x->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_mulxy_numele3");
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_y(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_x(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_y_cpu_core(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_numvec(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_XLEN(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_YLEN(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_ZLEN(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_ovlp(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_xblock(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_yblock(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_zblock(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_mulxy_numele3_scmc_set_parameter_num_ele(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_blas_yiszero_synced_init(cuda_pscmc_env *pe,
                                  cuda_blas_yiszero_synced_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_blas_yiszero_synced_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_blas_yiszero_synced_struct));
}
int cuda_blas_yiszero_synced_get_xlen() { return IDX_OPT_MAX; }
int cuda_blas_yiszero_synced_get_num_compute_units(
    cuda_blas_yiszero_synced_struct *kerstr) {
  return 64;
}
int cuda_blas_yiszero_synced_exec(cuda_blas_yiszero_synced_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_blas_yiszero_synced<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_blas_yiszero_synced<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->y->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_blas_yiszero_synced");
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_y(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_numvec(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_XLEN(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_YLEN(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_ZLEN(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_ovlp(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_xblock(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_yblock(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_zblock(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_blas_yiszero_synced_scmc_set_parameter_num_ele(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
}
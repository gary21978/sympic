#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "stencil.kernel_inc.h"

#include "stencil.kernel.cu"

extern "C" {
int cuda_Yee_FDTD_W04_2_init(cuda_pscmc_env *pe,
                             cuda_Yee_FDTD_W04_2_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_W04_2_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_W04_2_struct));
}
int cuda_Yee_FDTD_W04_2_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_W04_2_get_num_compute_units(
    cuda_Yee_FDTD_W04_2_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_W04_2_exec(cuda_Yee_FDTD_W04_2_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_W04_2<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0]);

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

    cuda_Yee_FDTD_W04_2<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_Yee_FDTD_W04_2");
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_DT(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_init(cuda_pscmc_env *pe,
                             cuda_Yee_FDTD_W04_1_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_W04_1_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_W04_1_struct));
}
int cuda_Yee_FDTD_W04_1_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_W04_1_get_num_compute_units(
    cuda_Yee_FDTD_W04_1_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_W04_1_exec(cuda_Yee_FDTD_W04_1_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_W04_1<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0]);

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

    cuda_Yee_FDTD_W04_1<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_Yee_FDTD_W04_1");
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_DT(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_init(cuda_pscmc_env *pe,
                             cuda_Yee_FDTD_W04_0_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_W04_0_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_W04_0_struct));
}
int cuda_Yee_FDTD_W04_0_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_W04_0_get_num_compute_units(
    cuda_Yee_FDTD_W04_0_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_W04_0_exec(cuda_Yee_FDTD_W04_0_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_W04_0<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0]);

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

    cuda_Yee_FDTD_W04_0<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_Yee_FDTD_W04_0");
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_DT(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
}
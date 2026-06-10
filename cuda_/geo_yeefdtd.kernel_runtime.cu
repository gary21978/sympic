#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "geo_yeefdtd.kernel_inc.h"

#include "geo_yeefdtd.kernel.cu"

extern "C" {
int cuda_YEE_CURL_R_init(cuda_pscmc_env *pe, cuda_YEE_CURL_R_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_YEE_CURL_R_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_YEE_CURL_R_struct));
}
int cuda_YEE_CURL_R_get_xlen() { return IDX_OPT_MAX; }
int cuda_YEE_CURL_R_get_num_compute_units(cuda_YEE_CURL_R_struct *kerstr) {
  return 64;
}
int cuda_YEE_CURL_R_exec(cuda_YEE_CURL_R_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_YEE_CURL_R<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutE1->d_data), ((double *)kerstr->inB0->d_data),
        ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),
        ((int *)kerstr->zoffset->d_data),
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

    cuda_YEE_CURL_R<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutE1->d_data), ((double *)kerstr->inB0->d_data),
        ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),
        ((int *)kerstr->zoffset->d_data),
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

  ERROPT(err, "Error in execcuda_YEE_CURL_R");
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_inoutE1(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->inoutE1 = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_inB0(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->inB0 = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_xoffset(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_yoffset(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_zoffset(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_y_cpu_core(
    cuda_YEE_CURL_R_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_numvec(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_XLEN(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_YLEN(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_ZLEN(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_ovlp(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_xblock(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_yblock(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_zblock(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_num_ele(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_YEE_CURL_R_scmc_set_parameter_DT(cuda_YEE_CURL_R_struct *kerstr,
                                          cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_init(cuda_pscmc_env *pe,
                             cuda_GEO_YEE_CURL_L_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_GEO_YEE_CURL_L_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_GEO_YEE_CURL_L_struct));
}
int cuda_GEO_YEE_CURL_L_get_xlen() { return IDX_OPT_MAX; }
int cuda_GEO_YEE_CURL_L_get_num_compute_units(
    cuda_GEO_YEE_CURL_L_struct *kerstr) {
  return 64;
}
int cuda_GEO_YEE_CURL_L_exec(cuda_GEO_YEE_CURL_L_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_GEO_YEE_CURL_L<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutE1->d_data), ((double *)kerstr->inB0->d_data),
        ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),
        ((int *)kerstr->zoffset->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->x0->h_data))[0]);

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

    cuda_GEO_YEE_CURL_L<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutE1->d_data), ((double *)kerstr->inB0->d_data),
        ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),
        ((int *)kerstr->zoffset->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->x0->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_GEO_YEE_CURL_L");
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutE1 = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_inB0(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inB0 = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_xoffset(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_yoffset(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_zoffset(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_numvec(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_XLEN(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_YLEN(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_ovlp(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_xblock(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_yblock(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_zblock(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_num_ele(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DT(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_x0(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->x0 = pm);
  return 0;
}
}
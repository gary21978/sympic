#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "yeefdtd.kernel_inc.h"

#include "yeefdtd.kernel.cu"

extern "C" {
int cuda_kgm_eqn_core_init(cuda_pscmc_env *pe,
                           cuda_kgm_eqn_core_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_kgm_eqn_core_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_kgm_eqn_core_struct));
}
int cuda_kgm_eqn_core_get_xlen() { return IDX_OPT_MAX; }
int cuda_kgm_eqn_core_get_num_compute_units(cuda_kgm_eqn_core_struct *kerstr) {
  return 64;
}
int cuda_kgm_eqn_core_exec(cuda_kgm_eqn_core_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_kgm_eqn_core<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        ((double *)kerstr->extA0->d_data), ((double *)kerstr->extA1->d_data),
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
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->GEXT->h_data))[0],
        (((double *)kerstr->rfz0->h_data))[0],
        (((double *)kerstr->g_beg->h_data))[0],
        (((int *)kerstr->swap_input->h_data))[0]);

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

    cuda_kgm_eqn_core<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        ((double *)kerstr->extA0->d_data), ((double *)kerstr->extA1->d_data),
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
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->GEXT->h_data))[0],
        (((double *)kerstr->rfz0->h_data))[0],
        (((double *)kerstr->g_beg->h_data))[0],
        (((int *)kerstr->swap_input->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_kgm_eqn_core");
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_outEB(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_inEB(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_extA0(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->extA0 = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_extA1(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->extA1 = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_xoffset(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_yoffset(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_zoffset(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_y_cpu_core(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_numvec(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_XLEN(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_YLEN(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_ZLEN(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_ovlp(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_xblock(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_yblock(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_zblock(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_num_ele(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_DT(cuda_kgm_eqn_core_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_M(cuda_kgm_eqn_core_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->M = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_Q(cuda_kgm_eqn_core_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->Q = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_DX(cuda_kgm_eqn_core_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->DX = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_GEXT(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->GEXT = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_rfz0(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->rfz0 = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_g_beg(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->g_beg = pm);
  return 0;
}
int cuda_kgm_eqn_core_scmc_set_parameter_swap_input(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->swap_input = pm);
  return 0;
}
int cuda_kgm_calc_rho_init(cuda_pscmc_env *pe,
                           cuda_kgm_calc_rho_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_kgm_calc_rho_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_kgm_calc_rho_struct));
}
int cuda_kgm_calc_rho_get_xlen() { return IDX_OPT_MAX; }
int cuda_kgm_calc_rho_get_num_compute_units(cuda_kgm_calc_rho_struct *kerstr) {
  return 64;
}
int cuda_kgm_calc_rho_exec(cuda_kgm_calc_rho_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_kgm_calc_rho<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
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
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->refz0->h_data))[0],
        (((double *)kerstr->q->h_data))[0],
        (((double *)kerstr->dtodx->h_data))[0],
        (((int *)kerstr->mode->h_data))[0],
        (((int *)kerstr->swap_input->h_data))[0]);

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

    cuda_kgm_calc_rho<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
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
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->refz0->h_data))[0],
        (((double *)kerstr->q->h_data))[0],
        (((double *)kerstr->dtodx->h_data))[0],
        (((int *)kerstr->mode->h_data))[0],
        (((int *)kerstr->swap_input->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_kgm_calc_rho");
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_outEB(cuda_kgm_calc_rho_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_inEB(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_xoffset(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_yoffset(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_zoffset(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_y_cpu_core(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_numvec(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_XLEN(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_YLEN(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_ZLEN(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_ovlp(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_xblock(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_yblock(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_zblock(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_num_ele(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_DT(cuda_kgm_calc_rho_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_M(cuda_kgm_calc_rho_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->M = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_Q(cuda_kgm_calc_rho_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->Q = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_DX(cuda_kgm_calc_rho_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->DX = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_refz0(cuda_kgm_calc_rho_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->refz0 = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_q(cuda_kgm_calc_rho_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->q = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_dtodx(cuda_kgm_calc_rho_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->dtodx = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_mode(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->mode = pm);
  return 0;
}
int cuda_kgm_calc_rho_scmc_set_parameter_swap_input(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->swap_input = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_init(cuda_pscmc_env *pe,
                                cuda_PML_FDTD_CURL_BWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_PML_FDTD_CURL_BWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_PML_FDTD_CURL_BWD_struct));
}
int cuda_PML_FDTD_CURL_BWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_PML_FDTD_CURL_BWD_get_num_compute_units(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr) {
  return 64;
}
int cuda_PML_FDTD_CURL_BWD_exec(cuda_PML_FDTD_CURL_BWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_PML_FDTD_CURL_BWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        ((double *)kerstr->outPMLEB->d_data),
        ((double *)kerstr->inPMLEB->d_data), ((int *)kerstr->xoffset->d_data),
        ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->DY->h_data))[0],
        (((double *)kerstr->DZ->h_data))[0],
        (((int *)kerstr->abc_dir->h_data))[0],
        (((int *)kerstr->level->h_data))[0],
        (((int *)kerstr->pml_m->h_data))[0],
        (((double *)kerstr->max_sigma->h_data))[0],
        (((long *)kerstr->allxmax->h_data))[0],
        (((long *)kerstr->allymax->h_data))[0],
        (((long *)kerstr->allzmax->h_data))[0]);

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

    cuda_PML_FDTD_CURL_BWD<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        ((double *)kerstr->outPMLEB->d_data),
        ((double *)kerstr->inPMLEB->d_data), ((int *)kerstr->xoffset->d_data),
        ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->DY->h_data))[0],
        (((double *)kerstr->DZ->h_data))[0],
        (((int *)kerstr->abc_dir->h_data))[0],
        (((int *)kerstr->level->h_data))[0],
        (((int *)kerstr->pml_m->h_data))[0],
        (((double *)kerstr->max_sigma->h_data))[0],
        (((long *)kerstr->allxmax->h_data))[0],
        (((long *)kerstr->allymax->h_data))[0],
        (((long *)kerstr->allzmax->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_PML_FDTD_CURL_BWD");
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_outEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_inEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_outPMLEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outPMLEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_inPMLEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inPMLEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_xoffset(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_yoffset(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_zoffset(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_y_cpu_core(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_numvec(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_XLEN(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_YLEN(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_ZLEN(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_ovlp(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_xblock(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_yblock(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_zblock(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_num_ele(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DT(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_M(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->M = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_Q(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DX(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DX = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DY(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DY = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DZ(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DZ = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_abc_dir(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->abc_dir = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_level(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->level = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_pml_m(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->pml_m = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_max_sigma(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->max_sigma = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_allxmax(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->allxmax = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_allymax(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->allymax = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_allzmax(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->allzmax = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_init(cuda_pscmc_env *pe,
                                cuda_PML_FDTD_CURL_FWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_PML_FDTD_CURL_FWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_PML_FDTD_CURL_FWD_struct));
}
int cuda_PML_FDTD_CURL_FWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_PML_FDTD_CURL_FWD_get_num_compute_units(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr) {
  return 64;
}
int cuda_PML_FDTD_CURL_FWD_exec(cuda_PML_FDTD_CURL_FWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_PML_FDTD_CURL_FWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        ((double *)kerstr->outPMLEB->d_data),
        ((double *)kerstr->inPMLEB->d_data), ((int *)kerstr->xoffset->d_data),
        ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->DY->h_data))[0],
        (((double *)kerstr->DZ->h_data))[0],
        (((int *)kerstr->abc_dir->h_data))[0],
        (((int *)kerstr->level->h_data))[0],
        (((int *)kerstr->pml_m->h_data))[0],
        (((double *)kerstr->max_sigma->h_data))[0],
        (((long *)kerstr->allxmax->h_data))[0],
        (((long *)kerstr->allymax->h_data))[0],
        (((long *)kerstr->allzmax->h_data))[0]);

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

    cuda_PML_FDTD_CURL_FWD<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
        ((double *)kerstr->outPMLEB->d_data),
        ((double *)kerstr->inPMLEB->d_data), ((int *)kerstr->xoffset->d_data),
        ((int *)kerstr->yoffset->d_data), ((int *)kerstr->zoffset->d_data),
        (((long *)kerstr->y_cpu_core->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->M->h_data))[0],
        (((double *)kerstr->Q->h_data))[0], (((double *)kerstr->DX->h_data))[0],
        (((double *)kerstr->DY->h_data))[0],
        (((double *)kerstr->DZ->h_data))[0],
        (((int *)kerstr->abc_dir->h_data))[0],
        (((int *)kerstr->level->h_data))[0],
        (((int *)kerstr->pml_m->h_data))[0],
        (((double *)kerstr->max_sigma->h_data))[0],
        (((long *)kerstr->allxmax->h_data))[0],
        (((long *)kerstr->allymax->h_data))[0],
        (((long *)kerstr->allzmax->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_PML_FDTD_CURL_FWD");
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_outEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_inEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_outPMLEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outPMLEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_inPMLEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inPMLEB = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_xoffset(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_yoffset(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_zoffset(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_y_cpu_core(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_numvec(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_XLEN(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_YLEN(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_ZLEN(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_ovlp(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_xblock(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_yblock(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_zblock(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_num_ele(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DT(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_M(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->M = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_Q(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DX(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DX = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DY(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DY = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DZ(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DZ = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_abc_dir(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->abc_dir = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_level(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->level = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_pml_m(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->pml_m = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_max_sigma(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->max_sigma = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_allxmax(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->allxmax = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_allymax(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->allymax = pm);
  return 0;
}
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_allzmax(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->allzmax = pm);
  return 0;
}
int cuda_merge_current_init(cuda_pscmc_env *pe,
                            cuda_merge_current_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_current_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_current_struct));
}
int cuda_merge_current_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_current_get_num_compute_units(
    cuda_merge_current_struct *kerstr) {
  return 64;
}
int cuda_merge_current_exec(cuda_merge_current_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_current<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
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

    cuda_merge_current<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
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

  ERROPT(err, "Error in execcuda_merge_current");
  return 0;
}
int cuda_merge_current_scmc_set_parameter_outEB(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_inEB(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_y_cpu_core(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_numvec(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_XLEN(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_YLEN(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_ZLEN(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_ovlp(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_xblock(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_yblock(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_zblock(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_current_scmc_set_parameter_num_ele(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_current_2_init(cuda_pscmc_env *pe,
                              cuda_merge_current_2_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_current_2_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_current_2_struct));
}
int cuda_merge_current_2_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_current_2_get_num_compute_units(
    cuda_merge_current_2_struct *kerstr) {
  return 64;
}
int cuda_merge_current_2_exec(cuda_merge_current_2_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_current_2<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
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

    cuda_merge_current_2<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->outEB->d_data), ((double *)kerstr->inEB->d_data),
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

  ERROPT(err, "Error in execcuda_merge_current_2");
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_outEB(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_inEB(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_y_cpu_core(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_numvec(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_XLEN(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_YLEN(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_ZLEN(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_ovlp(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_xblock(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_yblock(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_zblock(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_current_2_scmc_set_parameter_num_ele(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_init(cuda_pscmc_env *pe,
                                   cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Div_FWD_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Div_FWD_4th_struct));
}
int cuda_Yee_FDTD_Div_FWD_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Div_FWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Div_FWD_4th_exec(cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Div_FWD_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Div_FWD_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Div_FWD_4th");
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_init(cuda_pscmc_env *pe,
                               cuda_Yee_FDTD_Div_FWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Div_FWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Div_FWD_struct));
}
int cuda_Yee_FDTD_Div_FWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Div_FWD_get_num_compute_units(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Div_FWD_exec(cuda_Yee_FDTD_Div_FWD_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Div_FWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Div_FWD<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Div_FWD");
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_init(cuda_pscmc_env *pe,
                                   cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Div_BWD_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Div_BWD_4th_struct));
}
int cuda_Yee_FDTD_Div_BWD_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Div_BWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Div_BWD_4th_exec(cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Div_BWD_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Div_BWD_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Div_BWD_4th");
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_init(cuda_pscmc_env *pe,
                               cuda_Yee_FDTD_Div_BWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Div_BWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Div_BWD_struct));
}
int cuda_Yee_FDTD_Div_BWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Div_BWD_get_num_compute_units(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Div_BWD_exec(cuda_Yee_FDTD_Div_BWD_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Div_BWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Div_BWD<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Div_BWD");
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_FWD_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_FWD_4th_struct));
}
int cuda_Yee_FDTD_Curl_FWD_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_FWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_FWD_4th_exec(cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_FWD_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_FWD_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_FWD_4th");
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Curl_FWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_FWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_FWD_struct));
}
int cuda_Yee_FDTD_Curl_FWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_FWD_get_num_compute_units(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_FWD_exec(cuda_Yee_FDTD_Curl_FWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_FWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_FWD<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_FWD");
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_BWD_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_BWD_4th_struct));
}
int cuda_Yee_FDTD_Curl_BWD_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_BWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_BWD_4th_exec(cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_BWD_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_BWD_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_BWD_4th");
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Curl_BWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_BWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_BWD_struct));
}
int cuda_Yee_FDTD_Curl_BWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_BWD_get_num_compute_units(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_BWD_exec(cuda_Yee_FDTD_Curl_BWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_BWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_BWD<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_BWD");
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Grad_FWD_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Grad_FWD_4th_struct));
}
int cuda_Yee_FDTD_Grad_FWD_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Grad_FWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Grad_FWD_4th_exec(cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Grad_FWD_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Grad_FWD_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Grad_FWD_4th");
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Grad_FWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Grad_FWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Grad_FWD_struct));
}
int cuda_Yee_FDTD_Grad_FWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Grad_FWD_get_num_compute_units(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Grad_FWD_exec(cuda_Yee_FDTD_Grad_FWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Grad_FWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Grad_FWD<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Grad_FWD");
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Grad_BWD_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Grad_BWD_4th_struct));
}
int cuda_Yee_FDTD_Grad_BWD_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Grad_BWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Grad_BWD_4th_exec(cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Grad_BWD_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Grad_BWD_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Grad_BWD_4th");
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Grad_BWD_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Grad_BWD_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Grad_BWD_struct));
}
int cuda_Yee_FDTD_Grad_BWD_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Grad_BWD_get_num_compute_units(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Grad_BWD_exec(cuda_Yee_FDTD_Grad_BWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Grad_BWD<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Grad_BWD<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Grad_BWD");
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_init(cuda_pscmc_env *pe,
                                  cuda_Yee_FDTD_Curl_B_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_B_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_B_4th_struct));
}
int cuda_Yee_FDTD_Curl_B_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_B_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_B_4th_exec(cuda_Yee_FDTD_Curl_B_4th_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_B_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_B_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_B_4th");
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_init(cuda_pscmc_env *pe,
                              cuda_Yee_FDTD_Curl_B_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_B_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_B_struct));
}
int cuda_Yee_FDTD_Curl_B_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_B_get_num_compute_units(
    cuda_Yee_FDTD_Curl_B_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_B_exec(cuda_Yee_FDTD_Curl_B_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_B<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_B<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_B");
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_init(cuda_pscmc_env *pe,
                                  cuda_Yee_FDTD_Curl_E_4th_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_E_4th_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_E_4th_struct));
}
int cuda_Yee_FDTD_Curl_E_4th_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_E_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_E_4th_exec(cuda_Yee_FDTD_Curl_E_4th_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_E_4th<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_E_4th<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_E_4th");
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_init(cuda_pscmc_env *pe,
                              cuda_Yee_FDTD_Curl_E_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_Yee_FDTD_Curl_E_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_Yee_FDTD_Curl_E_struct));
}
int cuda_Yee_FDTD_Curl_E_get_xlen() { return IDX_OPT_MAX; }
int cuda_Yee_FDTD_Curl_E_get_num_compute_units(
    cuda_Yee_FDTD_Curl_E_struct *kerstr) {
  return 64;
}
int cuda_Yee_FDTD_Curl_E_exec(cuda_Yee_FDTD_Curl_E_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_Yee_FDTD_Curl_E<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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

    cuda_Yee_FDTD_Curl_E<<<multiylen, scmc_internal_g_xlen>>>(
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

  ERROPT(err, "Error in execcuda_Yee_FDTD_Curl_E");
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->outEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inEB = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->y_cpu_core = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DT = pm);
  return 0;
}
}
#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "inner_split_pass.kernel_inc.h"

#include "inner_split_pass.kernel.cu"

extern "C" {


int cuda_geo_nr_Bfield_pushJ_vlo_init(
    cuda_pscmc_env *pe, cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_geo_nr_Bfield_pushJ_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_geo_nr_Bfield_pushJ_vlo_struct));
}
int cuda_geo_nr_Bfield_pushJ_vlo_get_xlen() { return 32; }
int cuda_geo_nr_Bfield_pushJ_vlo_get_num_compute_units(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr) {
  return 64;
}
int cuda_geo_nr_Bfield_pushJ_vlo_exec(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_geo_nr_Bfield_pushJ_vlo<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),
        ((int *)kerstr->zoffset->d_data), ((double *)kerstr->fieldE->d_data),
        ((double *)kerstr->fieldB->d_data), ((double *)kerstr->fieldB1->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0],
        (((double *)kerstr->Tori_X0->h_data))[0],
        (((double *)kerstr->r0->h_data))[0],
        (((double *)kerstr->MIN_R0->h_data))[0],
        (((double *)kerstr->Q0->h_data))[0],
        (((double *)kerstr->b0->h_data))[0],
        (((double *)kerstr->zmid->h_data))[0]);

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

    cuda_geo_nr_Bfield_pushJ_vlo<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((int *)kerstr->xoffset->d_data), ((int *)kerstr->yoffset->d_data),
        ((int *)kerstr->zoffset->d_data), ((double *)kerstr->fieldE->d_data),
        ((double *)kerstr->fieldB->d_data), ((double *)kerstr->fieldB1->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0],
        (((double *)kerstr->Tori_X0->h_data))[0],
        (((double *)kerstr->r0->h_data))[0],
        (((double *)kerstr->MIN_R0->h_data))[0],
        (((double *)kerstr->Q0->h_data))[0],
        (((double *)kerstr->b0->h_data))[0],
        (((double *)kerstr->zmid->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_geo_nr_Bfield_pushJ_vlo");
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}

// --- Stubs for variants not used by standard CUDA regression ---
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_init( cuda_pscmc_env *pe, cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct));
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_get_xlen() {
  return 32;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_get_num_compute_units( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr) {
  return 64;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_exec( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  fprintf(stderr, "FATAL: cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_exec() was called. Exiting now.\n");
  exit(1);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_inoutput( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_xyzw( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_cu_cache( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_cu_xyzw( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_xoffset( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_yoffset( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_zoffset( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_fieldE( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_fieldB( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_fieldB1( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_FoutJ( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_XLEN( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_YLEN( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_ZLEN( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_ovlp( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_numvec( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_num_ele( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_grid_cache_len( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_cu_cache_length( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_DELTA_X( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_DELTA_Y( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_DELTA_Z( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Mass0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Charge0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Deltat( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Tori_X0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_r0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_MIN_R0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Q0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_b0( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_zmid( cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_init( cuda_pscmc_env *pe, cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_geo_nr_Bfield_pushJ_nopush_par_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_geo_nr_Bfield_pushJ_nopush_par_struct));
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_get_xlen() {
  return 32;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_get_num_compute_units( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr) {
  return 64;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_exec( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  fprintf(stderr, "FATAL: cuda_geo_nr_Bfield_pushJ_nopush_par_exec() was called. Exiting now.\n");
  exit(1);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_inoutput( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_xyzw( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_cu_cache( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_cu_xyzw( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_xoffset( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_yoffset( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_zoffset( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_fieldE( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_fieldB( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_fieldB1( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_FoutJ( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_XLEN( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_YLEN( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_ZLEN( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_ovlp( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_numvec( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_num_ele( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_grid_cache_len( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_cu_cache_length( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_DELTA_X( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_DELTA_Y( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_DELTA_Z( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Mass0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Charge0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Deltat( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Tori_X0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_r0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_MIN_R0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Q0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_b0( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_zmid( cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}
int cuda_geo_nr_Bfield_init(cuda_pscmc_env *pe, cuda_geo_nr_Bfield_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_geo_nr_Bfield_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_geo_nr_Bfield_struct));
}
int cuda_geo_nr_Bfield_get_xlen() {
  return 32;
}
int cuda_geo_nr_Bfield_get_num_compute_units(cuda_geo_nr_Bfield_struct *kerstr) {
  return 64;
}
int cuda_geo_nr_Bfield_exec(cuda_geo_nr_Bfield_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  fprintf(stderr, "FATAL: cuda_geo_nr_Bfield_exec() was called. Exiting now.\n");
  exit(1);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_inoutput( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_xyzw( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_cu_cache( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_cu_xyzw( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_xoffset( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_yoffset( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_zoffset( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_fieldE( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_fieldB( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_fieldB1( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_FoutJ( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_XLEN( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_YLEN( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_ZLEN( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_ovlp( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_numvec( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_num_ele( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_grid_cache_len( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_cu_cache_length( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_DELTA_X( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_DELTA_Y( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_DELTA_Z( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_Mass0( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_Charge0( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_Deltat( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_Tori_X0( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_r0(cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_MIN_R0( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_Q0(cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_b0(cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_geo_nr_Bfield_scmc_set_parameter_zmid( cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}
int cuda_geo_nr_vlo_init(cuda_pscmc_env *pe, cuda_geo_nr_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_geo_nr_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_geo_nr_vlo_struct));
}
int cuda_geo_nr_vlo_get_xlen() {
  return 32;
}
int cuda_geo_nr_vlo_get_num_compute_units(cuda_geo_nr_vlo_struct *kerstr) {
  return 64;
}
int cuda_geo_nr_vlo_exec(cuda_geo_nr_vlo_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  fprintf(stderr, "FATAL: cuda_geo_nr_vlo_exec() was called. Exiting now.\n");
  exit(1);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_inoutput(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_xyzw(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_cu_cache(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_cu_xyzw(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_xoffset(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_yoffset(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_zoffset(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_fieldE(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_fieldB(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_fieldB1(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_FoutJ(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_XLEN(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_YLEN(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_ZLEN(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_ovlp(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_numvec(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_num_ele(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_grid_cache_len( cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_cu_cache_length( cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_DELTA_X(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_DELTA_Y(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_DELTA_Z(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_Mass0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_Charge0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_Deltat(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_Tori_X0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_r0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_MIN_R0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_Q0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_b0(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_geo_nr_vlo_scmc_set_parameter_zmid(cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}
int cuda_geo_nr_init(cuda_pscmc_env *pe, cuda_geo_nr_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_geo_nr_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_geo_nr_struct));
}
int cuda_geo_nr_get_xlen() {
  return 32;
}
int cuda_geo_nr_get_num_compute_units(cuda_geo_nr_struct *kerstr) {
  return 64;
}
int cuda_geo_nr_exec(cuda_geo_nr_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  fprintf(stderr, "FATAL: cuda_geo_nr_exec() was called. Exiting now.\n");
  exit(1);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_inoutput(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_xyzw(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_cu_cache(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_cu_xyzw(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_xoffset(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_yoffset(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_zoffset(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_fieldE(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_fieldB(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_fieldB1(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_FoutJ(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_XLEN(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_YLEN(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_ZLEN(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_ovlp(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_numvec(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_num_ele(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_grid_cache_len(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_cu_cache_length(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_DELTA_X(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_DELTA_Y(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_DELTA_Z(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_Mass0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_Charge0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_Deltat(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_Tori_X0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_r0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_MIN_R0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_Q0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_b0(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_geo_nr_scmc_set_parameter_zmid(cuda_geo_nr_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}
int cuda_ngeo_gc_init(cuda_pscmc_env *pe, cuda_ngeo_gc_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_ngeo_gc_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_ngeo_gc_struct));
}
int cuda_ngeo_gc_get_xlen() {
  return 32;
}
int cuda_ngeo_gc_get_num_compute_units(cuda_ngeo_gc_struct *kerstr) {
  return 64;
}
int cuda_ngeo_gc_exec(cuda_ngeo_gc_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  fprintf(stderr, "FATAL: cuda_ngeo_gc_exec() was called. Exiting now.\n");
  exit(1);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_inoutput(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_xyzw(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_cu_cache(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_cu_xyzw(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_xoffset(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xoffset = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_yoffset(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yoffset = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_zoffset(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zoffset = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_fieldE(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_fieldB(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_fieldB1(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB1 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_FoutJ(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_XLEN(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_YLEN(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_ZLEN(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_ovlp(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_numvec(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_num_ele(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_grid_cache_len(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_cu_cache_length(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_DELTA_X(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_DELTA_Y(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_DELTA_Z(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_Mass0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_Charge0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_Deltat(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_Tori_X0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Tori_X0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_r0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->r0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_MIN_R0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->MIN_R0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_Q0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Q0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_b0(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->b0 = pm);
  return 0;
}
int cuda_ngeo_gc_scmc_set_parameter_zmid(cuda_ngeo_gc_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zmid = pm);
  return 0;
}
}

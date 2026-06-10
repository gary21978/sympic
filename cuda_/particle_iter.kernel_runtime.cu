#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "particle_iter.kernel_inc.h"

#include "particle_iter.kernel.cu"

extern "C" {
int cuda_dump_ene_num_init(cuda_pscmc_env *pe,
                           cuda_dump_ene_num_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_dump_ene_num_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_dump_ene_num_struct));
}
int cuda_dump_ene_num_get_xlen() { return IDX_OPT_MAX; }
int cuda_dump_ene_num_get_num_compute_units(cuda_dump_ene_num_struct *kerstr) {
  return 64;
}
int cuda_dump_ene_num_exec(cuda_dump_ene_num_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_dump_ene_num<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_dump_ene_num<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_dump_ene_num");
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_inoutput(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_xyzw(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_cu_cache(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_cu_xyzw(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_fieldE(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_fieldB(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_FoutJ(cuda_dump_ene_num_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_FoutEN(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_XLEN(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_YLEN(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_ZLEN(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_ovlp(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_numvec(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_num_ele(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_grid_cache_len(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_cu_cache_length(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_Mass(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_Charge(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_SPEC(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_NUM_SPEC(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_DELTA_X(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_DELTA_Y(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_DELTA_Z(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_dump_ene_num_scmc_set_parameter_Deltat(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_calculate_rho_init(cuda_pscmc_env *pe,
                            cuda_calculate_rho_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_calculate_rho_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_calculate_rho_struct));
}
int cuda_calculate_rho_get_xlen() { return IDX_OPT_MAX; }
int cuda_calculate_rho_get_num_compute_units(
    cuda_calculate_rho_struct *kerstr) {
  return 64;
}
int cuda_calculate_rho_exec(cuda_calculate_rho_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_calculate_rho<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_calculate_rho<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_calculate_rho");
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_inoutput(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_xyzw(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_cu_cache(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_cu_xyzw(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_fieldE(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_fieldB(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_FoutJ(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_FoutEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_XLEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_YLEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_ZLEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_ovlp(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_numvec(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_num_ele(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_grid_cache_len(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_cu_cache_length(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_Mass(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_Charge(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_SPEC(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_NUM_SPEC(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_DELTA_X(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_DELTA_Y(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_DELTA_Z(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_calculate_rho_scmc_set_parameter_Deltat(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_krook_collision_test_init(cuda_pscmc_env *pe,
                                   cuda_krook_collision_test_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_krook_collision_test_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_krook_collision_test_struct));
}
int cuda_krook_collision_test_get_xlen() { return IDX_OPT_MAX; }
int cuda_krook_collision_test_get_num_compute_units(
    cuda_krook_collision_test_struct *kerstr) {
  return 64;
}
int cuda_krook_collision_test_exec(cuda_krook_collision_test_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_krook_collision_test<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0],
        (((double *)kerstr->mu_freq->h_data))[0]);

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

    cuda_krook_collision_test<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0],
        (((double *)kerstr->mu_freq->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_krook_collision_test");
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_inoutput(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_xyzw(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_cu_cache(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_cu_xyzw(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_fieldE(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_fieldB(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_FoutJ(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_XLEN(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_YLEN(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_ZLEN(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_ovlp(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_numvec(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_num_ele(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_grid_cache_len(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_cu_cache_length(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_Mass0(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_Charge0(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_Deltat(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_krook_collision_test_scmc_set_parameter_mu_freq(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->mu_freq = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_init(
    cuda_pscmc_env *pe,
    cuda_krook_collision_remove_small_speed_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_krook_collision_remove_small_speed_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_krook_collision_remove_small_speed_struct));
}
int cuda_krook_collision_remove_small_speed_get_xlen() { return IDX_OPT_MAX; }
int cuda_krook_collision_remove_small_speed_get_num_compute_units(
    cuda_krook_collision_remove_small_speed_struct *kerstr) {
  return 64;
}
int cuda_krook_collision_remove_small_speed_exec(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_krook_collision_remove_small_speed<<<scmc_internal_g_ylen,
                                              scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0],
        (((double *)kerstr->mu_freq->h_data))[0]);

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

    cuda_krook_collision_remove_small_speed<<<multiylen,
                                              scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0],
        (((double *)kerstr->mu_freq->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_krook_collision_remove_small_speed");
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_inoutput(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_xyzw(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_cu_xyzw(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_fieldE(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_fieldB(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_FoutJ(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_XLEN(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_YLEN(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_ZLEN(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_ovlp(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_numvec(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_num_ele(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_grid_cache_len(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache_length(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_Mass0(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_Charge0(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_Deltat(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_mu_freq(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->mu_freq = pm);
  return 0;
}
int cuda_boris_yee_init(cuda_pscmc_env *pe, cuda_boris_yee_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_boris_yee_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_boris_yee_struct));
}
int cuda_boris_yee_get_xlen() { return IDX_OPT_MAX; }
int cuda_boris_yee_get_num_compute_units(cuda_boris_yee_struct *kerstr) {
  return 64;
}
int cuda_boris_yee_exec(cuda_boris_yee_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_boris_yee<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_boris_yee<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass0->h_data))[0],
        (((double *)kerstr->Charge0->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_boris_yee");
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_inoutput(cuda_boris_yee_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_xyzw(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_cu_cache(cuda_boris_yee_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_cu_xyzw(cuda_boris_yee_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_fieldE(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_fieldB(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_FoutJ(cuda_boris_yee_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_XLEN(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_YLEN(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_ZLEN(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_ovlp(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_numvec(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_num_ele(cuda_boris_yee_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_grid_cache_len(
    cuda_boris_yee_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_cu_cache_length(
    cuda_boris_yee_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_Mass0(cuda_boris_yee_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->Mass0 = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_Charge0(cuda_boris_yee_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->Charge0 = pm);
  return 0;
}
int cuda_boris_yee_scmc_set_parameter_Deltat(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_init(
    cuda_pscmc_env *pe, cuda_split_pass_E_particle_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_E_particle_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_E_particle_vlo_struct));
}
int cuda_split_pass_E_particle_vlo_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_E_particle_vlo_get_num_compute_units(
    cuda_split_pass_E_particle_vlo_struct *kerstr) {
  return 64;
}
int cuda_split_pass_E_particle_vlo_exec(
    cuda_split_pass_E_particle_vlo_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_E_particle_vlo<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_E_particle_vlo<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_E_particle_vlo");
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_E_particle_init(cuda_pscmc_env *pe,
                                    cuda_split_pass_E_particle_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_E_particle_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_E_particle_struct));
}
int cuda_split_pass_E_particle_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_E_particle_get_num_compute_units(
    cuda_split_pass_E_particle_struct *kerstr) {
  return 64;
}
int cuda_split_pass_E_particle_exec(cuda_split_pass_E_particle_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_E_particle<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_E_particle<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_E_particle");
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_inoutput(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_xyzw(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_cu_cache(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_fieldE(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_fieldB(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_FoutJ(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_FoutEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_XLEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_YLEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_ZLEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_ovlp(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_numvec(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_num_ele(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_Mass(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_Charge(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_SPEC(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_DELTA_X(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_E_particle_scmc_set_parameter_Deltat(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_init(
    cuda_pscmc_env *pe,
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_vlo_sg2_nopush_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct));
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_get_xlen() { return 4; }
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_get_num_compute_units(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_exec(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_vlo_sg2_nopush_small_grids<<<scmc_internal_g_ylen,
                                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_vlo_sg2_nopush_small_grids<<<multiylen,
                                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_vlo_sg2_nopush_small_grids");
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_vlo_sg2_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_vlo_sg2_small_grids_struct));
}
int cuda_split_pass_z_vlo_sg2_small_grids_get_xlen() { return 4; }
int cuda_split_pass_z_vlo_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_vlo_sg2_small_grids_exec(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_vlo_sg2_small_grids<<<scmc_internal_g_ylen,
                                            scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_vlo_sg2_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_vlo_sg2_small_grids");
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_vlo_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_vlo_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_vlo_small_grids_struct));
}
int cuda_split_pass_z_vlo_small_grids_get_xlen() { return 4; }
int cuda_split_pass_z_vlo_small_grids_get_num_compute_units(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_vlo_small_grids_exec(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_vlo_small_grids<<<scmc_internal_g_ylen,
                                        scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_vlo_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_vlo_small_grids");
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_sg2_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_sg2_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_sg2_small_grids_struct));
}
int cuda_split_pass_z_sg2_small_grids_get_xlen() { return 4; }
int cuda_split_pass_z_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_sg2_small_grids_exec(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_sg2_small_grids<<<scmc_internal_g_ylen,
                                        scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_sg2_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_sg2_small_grids");
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_small_grids_struct));
}
int cuda_split_pass_z_small_grids_get_xlen() { return 4; }
int cuda_split_pass_z_small_grids_get_num_compute_units(
    cuda_split_pass_z_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_small_grids_exec(
    cuda_split_pass_z_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_small_grids<<<scmc_internal_g_ylen,
                                    scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_small_grids");
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_vlo_nopush_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_vlo_nopush_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_vlo_nopush_struct));
}
int cuda_split_pass_z_vlo_nopush_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_z_vlo_nopush_get_num_compute_units(
    cuda_split_pass_z_vlo_nopush_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_vlo_nopush_exec(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_vlo_nopush<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_vlo_nopush<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_vlo_nopush");
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_vlo_init(cuda_pscmc_env *pe,
                               cuda_split_pass_z_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_vlo_struct));
}
int cuda_split_pass_z_vlo_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_z_vlo_get_num_compute_units(
    cuda_split_pass_z_vlo_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_vlo_exec(cuda_split_pass_z_vlo_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_vlo<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_vlo<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_vlo");
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_nopush_init(cuda_pscmc_env *pe,
                                  cuda_split_pass_z_nopush_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_nopush_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_nopush_struct));
}
int cuda_split_pass_z_nopush_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_z_nopush_get_num_compute_units(
    cuda_split_pass_z_nopush_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_nopush_exec(cuda_split_pass_z_nopush_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z_nopush<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z_nopush<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z_nopush");
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_z_init(cuda_pscmc_env *pe,
                           cuda_split_pass_z_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_z_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_z_struct));
}
int cuda_split_pass_z_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_z_get_num_compute_units(cuda_split_pass_z_struct *kerstr) {
  return 64;
}
int cuda_split_pass_z_exec(cuda_split_pass_z_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_z<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_z<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_z");
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_inoutput(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_xyzw(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_fieldE(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_fieldB(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_FoutJ(cuda_split_pass_z_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_XLEN(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_YLEN(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_ZLEN(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_ovlp(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_numvec(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_num_ele(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_Mass(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_Charge(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_SPEC(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_z_scmc_set_parameter_Deltat(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_init(
    cuda_pscmc_env *pe,
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_vlo_sg2_nopush_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct));
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_get_xlen() { return 4; }
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_get_num_compute_units(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_exec(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_vlo_sg2_nopush_small_grids<<<scmc_internal_g_ylen,
                                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_vlo_sg2_nopush_small_grids<<<multiylen,
                                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_vlo_sg2_nopush_small_grids");
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_vlo_sg2_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_vlo_sg2_small_grids_struct));
}
int cuda_split_pass_y_vlo_sg2_small_grids_get_xlen() { return 4; }
int cuda_split_pass_y_vlo_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_vlo_sg2_small_grids_exec(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_vlo_sg2_small_grids<<<scmc_internal_g_ylen,
                                            scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_vlo_sg2_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_vlo_sg2_small_grids");
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_vlo_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_vlo_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_vlo_small_grids_struct));
}
int cuda_split_pass_y_vlo_small_grids_get_xlen() { return 4; }
int cuda_split_pass_y_vlo_small_grids_get_num_compute_units(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_vlo_small_grids_exec(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_vlo_small_grids<<<scmc_internal_g_ylen,
                                        scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_vlo_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_vlo_small_grids");
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_sg2_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_sg2_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_sg2_small_grids_struct));
}
int cuda_split_pass_y_sg2_small_grids_get_xlen() { return 4; }
int cuda_split_pass_y_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_sg2_small_grids_exec(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_sg2_small_grids<<<scmc_internal_g_ylen,
                                        scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_sg2_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_sg2_small_grids");
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_small_grids_struct));
}
int cuda_split_pass_y_small_grids_get_xlen() { return 4; }
int cuda_split_pass_y_small_grids_get_num_compute_units(
    cuda_split_pass_y_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_small_grids_exec(
    cuda_split_pass_y_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_small_grids<<<scmc_internal_g_ylen,
                                    scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_small_grids");
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_vlo_nopush_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_vlo_nopush_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_vlo_nopush_struct));
}
int cuda_split_pass_y_vlo_nopush_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_y_vlo_nopush_get_num_compute_units(
    cuda_split_pass_y_vlo_nopush_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_vlo_nopush_exec(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_vlo_nopush<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_vlo_nopush<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_vlo_nopush");
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_vlo_init(cuda_pscmc_env *pe,
                               cuda_split_pass_y_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_vlo_struct));
}
int cuda_split_pass_y_vlo_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_y_vlo_get_num_compute_units(
    cuda_split_pass_y_vlo_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_vlo_exec(cuda_split_pass_y_vlo_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_vlo<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_vlo<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_vlo");
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_nopush_init(cuda_pscmc_env *pe,
                                  cuda_split_pass_y_nopush_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_nopush_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_nopush_struct));
}
int cuda_split_pass_y_nopush_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_y_nopush_get_num_compute_units(
    cuda_split_pass_y_nopush_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_nopush_exec(cuda_split_pass_y_nopush_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y_nopush<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y_nopush<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y_nopush");
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_y_init(cuda_pscmc_env *pe,
                           cuda_split_pass_y_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_y_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_y_struct));
}
int cuda_split_pass_y_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_y_get_num_compute_units(cuda_split_pass_y_struct *kerstr) {
  return 64;
}
int cuda_split_pass_y_exec(cuda_split_pass_y_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_y<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_y<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_y");
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_inoutput(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_xyzw(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_fieldE(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_fieldB(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_FoutJ(cuda_split_pass_y_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_XLEN(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_YLEN(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_ZLEN(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_ovlp(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_numvec(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_num_ele(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_Mass(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_Charge(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_SPEC(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_y_scmc_set_parameter_Deltat(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_init(
    cuda_pscmc_env *pe,
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_vlo_sg2_nopush_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct));
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_get_xlen() { return 4; }
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_get_num_compute_units(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_exec(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_vlo_sg2_nopush_small_grids<<<scmc_internal_g_ylen,
                                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_vlo_sg2_nopush_small_grids<<<multiylen,
                                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_vlo_sg2_nopush_small_grids");
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_vlo_sg2_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_vlo_sg2_small_grids_struct));
}
int cuda_split_pass_x_vlo_sg2_small_grids_get_xlen() { return 4; }
int cuda_split_pass_x_vlo_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_vlo_sg2_small_grids_exec(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_vlo_sg2_small_grids<<<scmc_internal_g_ylen,
                                            scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_vlo_sg2_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_vlo_sg2_small_grids");
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_vlo_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_vlo_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_vlo_small_grids_struct));
}
int cuda_split_pass_x_vlo_small_grids_get_xlen() { return 4; }
int cuda_split_pass_x_vlo_small_grids_get_num_compute_units(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_vlo_small_grids_exec(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_vlo_small_grids<<<scmc_internal_g_ylen,
                                        scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_vlo_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_vlo_small_grids");
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_sg2_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_sg2_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_sg2_small_grids_struct));
}
int cuda_split_pass_x_sg2_small_grids_get_xlen() { return 4; }
int cuda_split_pass_x_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_sg2_small_grids_exec(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_sg2_small_grids<<<scmc_internal_g_ylen,
                                        scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_sg2_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_sg2_small_grids");
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_small_grids_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_small_grids_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_small_grids_struct));
}
int cuda_split_pass_x_small_grids_get_xlen() { return 4; }
int cuda_split_pass_x_small_grids_get_num_compute_units(
    cuda_split_pass_x_small_grids_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_small_grids_exec(
    cuda_split_pass_x_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_small_grids<<<scmc_internal_g_ylen,
                                    scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_small_grids<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->LFoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_small_grids");
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->LFoutJ = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_vlo_nopush_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_vlo_nopush_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_vlo_nopush_struct));
}
int cuda_split_pass_x_vlo_nopush_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_x_vlo_nopush_get_num_compute_units(
    cuda_split_pass_x_vlo_nopush_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_vlo_nopush_exec(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_vlo_nopush<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_vlo_nopush<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_vlo_nopush");
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_vlo_init(cuda_pscmc_env *pe,
                               cuda_split_pass_x_vlo_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_vlo_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_vlo_struct));
}
int cuda_split_pass_x_vlo_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_x_vlo_get_num_compute_units(
    cuda_split_pass_x_vlo_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_vlo_exec(cuda_split_pass_x_vlo_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_vlo<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_vlo<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_vlo");
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_nopush_init(cuda_pscmc_env *pe,
                                  cuda_split_pass_x_nopush_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_nopush_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_nopush_struct));
}
int cuda_split_pass_x_nopush_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_x_nopush_get_num_compute_units(
    cuda_split_pass_x_nopush_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_nopush_exec(cuda_split_pass_x_nopush_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x_nopush<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x_nopush<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x_nopush");
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
int cuda_split_pass_x_init(cuda_pscmc_env *pe,
                           cuda_split_pass_x_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_split_pass_x_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_split_pass_x_struct));
}
int cuda_split_pass_x_get_xlen() { return IDX_OPT_MAX; }
int cuda_split_pass_x_get_num_compute_units(cuda_split_pass_x_struct *kerstr) {
  return 64;
}
int cuda_split_pass_x_exec(cuda_split_pass_x_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_split_pass_x<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);

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

    cuda_split_pass_x<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((double *)kerstr->fieldE->d_data), ((double *)kerstr->fieldB->d_data),
        ((double *)kerstr->FoutJ->d_data), ((double *)kerstr->FoutEN->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((double *)kerstr->Mass->h_data))[0],
        (((double *)kerstr->Charge->h_data))[0],
        (((int *)kerstr->SPEC->h_data))[0],
        (((int *)kerstr->NUM_SPEC->h_data))[0],
        (((double *)kerstr->DELTA_X->h_data))[0],
        (((double *)kerstr->DELTA_Y->h_data))[0],
        (((double *)kerstr->DELTA_Z->h_data))[0],
        (((double *)kerstr->Deltat->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_split_pass_x");
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_inoutput(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_xyzw(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_fieldE(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldE = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_fieldB(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->fieldB = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_FoutJ(cuda_split_pass_x_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->FoutJ = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->FoutEN = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_XLEN(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_YLEN(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_ZLEN(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_ovlp(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_numvec(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_num_ele(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_Mass(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->Mass = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_Charge(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Charge = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_SPEC(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->SPEC = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_X = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Y = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->DELTA_Z = pm);
  return 0;
}
int cuda_split_pass_x_scmc_set_parameter_Deltat(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->Deltat = pm);
  return 0;
}
}
#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "move_back.kernel_inc.h"

#include "move_back.kernel.cu"

extern "C" {
int cuda_move_back_kernel_8_init(cuda_pscmc_env *pe,
                                 cuda_move_back_kernel_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_move_back_kernel_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_move_back_kernel_8_struct));
}
int cuda_move_back_kernel_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_move_back_kernel_8_get_num_compute_units(
    cuda_move_back_kernel_8_struct *kerstr) {
  return 64;
}
int cuda_move_back_kernel_8_exec(cuda_move_back_kernel_8_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_move_back_kernel_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);

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

    cuda_move_back_kernel_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_move_back_kernel_8");
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_inoutput(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_xyzw(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_cu_cache(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_cu_xyzw(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_XLEN(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_YLEN(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_ZLEN(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_grid_cache_len(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_move_back_kernel_8_scmc_set_parameter_cu_cache_length(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_move_back_kernel_6_init(cuda_pscmc_env *pe,
                                 cuda_move_back_kernel_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_move_back_kernel_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_move_back_kernel_6_struct));
}
int cuda_move_back_kernel_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_move_back_kernel_6_get_num_compute_units(
    cuda_move_back_kernel_6_struct *kerstr) {
  return 64;
}
int cuda_move_back_kernel_6_exec(cuda_move_back_kernel_6_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_move_back_kernel_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);

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

    cuda_move_back_kernel_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_move_back_kernel_6");
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_inoutput(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_xyzw(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_cu_cache(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_cu_xyzw(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_XLEN(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_YLEN(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_ZLEN(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_grid_cache_len(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_move_back_kernel_6_scmc_set_parameter_cu_cache_length(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
}
#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "general_partial_sort.kernel_inc.h"

#include "general_partial_sort.kernel.cu"

extern "C" {
int cuda_cu_swap_r_8_init(cuda_pscmc_env *pe, cuda_cu_swap_r_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_cu_swap_r_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_cu_swap_r_8_struct));
}
int cuda_cu_swap_r_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_cu_swap_r_8_get_num_compute_units(cuda_cu_swap_r_8_struct *kerstr) {
  return 64;
}
int cuda_cu_swap_r_8_exec(cuda_cu_swap_r_8_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_cu_swap_r_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);

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

    cuda_cu_swap_r_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_cu_swap_r_8");
  return 0;
}
int cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cuda_cu_swap_r_8_struct *kerstr,
                                                cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->the_dir_num = pm);
  return 0;
}
int cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cuda_cu_swap_r_8_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->XYZLEN = pm);
  return 0;
}
int cuda_cu_swap_l_8_init(cuda_pscmc_env *pe, cuda_cu_swap_l_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_cu_swap_l_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_cu_swap_l_8_struct));
}
int cuda_cu_swap_l_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_cu_swap_l_8_get_num_compute_units(cuda_cu_swap_l_8_struct *kerstr) {
  return 64;
}
int cuda_cu_swap_l_8_exec(cuda_cu_swap_l_8_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_cu_swap_l_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);

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

    cuda_cu_swap_l_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_cu_swap_l_8");
  return 0;
}
int cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cuda_cu_swap_l_8_struct *kerstr,
                                                cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->the_dir_num = pm);
  return 0;
}
int cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cuda_cu_swap_l_8_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->XYZLEN = pm);
  return 0;
}
int cuda_cu_swap_r_6_init(cuda_pscmc_env *pe, cuda_cu_swap_r_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_cu_swap_r_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_cu_swap_r_6_struct));
}
int cuda_cu_swap_r_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_cu_swap_r_6_get_num_compute_units(cuda_cu_swap_r_6_struct *kerstr) {
  return 64;
}
int cuda_cu_swap_r_6_exec(cuda_cu_swap_r_6_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_cu_swap_r_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);

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

    cuda_cu_swap_r_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_cu_swap_r_6");
  return 0;
}
int cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cuda_cu_swap_r_6_struct *kerstr,
                                                cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->the_dir_num = pm);
  return 0;
}
int cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cuda_cu_swap_r_6_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->XYZLEN = pm);
  return 0;
}
int cuda_cu_swap_l_6_init(cuda_pscmc_env *pe, cuda_cu_swap_l_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_cu_swap_l_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_cu_swap_l_6_struct));
}
int cuda_cu_swap_l_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_cu_swap_l_6_get_num_compute_units(cuda_cu_swap_l_6_struct *kerstr) {
  return 64;
}
int cuda_cu_swap_l_6_exec(cuda_cu_swap_l_6_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_cu_swap_l_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);

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

    cuda_cu_swap_l_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((long *)kerstr->XYZLEN->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_cu_swap_l_6");
  return 0;
}
int cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cuda_cu_swap_l_6_struct *kerstr,
                                                cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->the_dir_num = pm);
  return 0;
}
int cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cuda_cu_swap_l_6_struct *kerstr,
                                               cuda_pscmc_mem *pm) {
  (kerstr->XYZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_z_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_z_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_z_vlo_8_struct));
}
int cuda_sort_one_grid_z_vlo_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_z_vlo_8_get_num_compute_units(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_z_vlo_8_exec(cuda_sort_one_grid_z_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_z_vlo_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_z_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_z_vlo_8");
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_z_vlo_8_struct));
}
int cuda_gpu_sort_one_grid_z_vlo_8_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_z_vlo_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_z_vlo_8_exec(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_z_vlo_8<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_z_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_z_vlo_8");
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_y_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_y_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_y_vlo_8_struct));
}
int cuda_sort_one_grid_y_vlo_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_y_vlo_8_get_num_compute_units(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_y_vlo_8_exec(cuda_sort_one_grid_y_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_y_vlo_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_y_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_y_vlo_8");
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_y_vlo_8_struct));
}
int cuda_gpu_sort_one_grid_y_vlo_8_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_y_vlo_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_y_vlo_8_exec(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_y_vlo_8<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_y_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_y_vlo_8");
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_x_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_x_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_x_vlo_8_struct));
}
int cuda_sort_one_grid_x_vlo_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_x_vlo_8_get_num_compute_units(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_x_vlo_8_exec(cuda_sort_one_grid_x_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_x_vlo_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_x_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_x_vlo_8");
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_x_vlo_8_struct));
}
int cuda_gpu_sort_one_grid_x_vlo_8_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_x_vlo_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_x_vlo_8_exec(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_x_vlo_8<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_x_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_x_vlo_8");
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_z_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_z_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_z_8_struct));
}
int cuda_sort_one_grid_z_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_z_8_get_num_compute_units(
    cuda_sort_one_grid_z_8_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_z_8_exec(cuda_sort_one_grid_z_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_z_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_z_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_z_8");
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_z_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_z_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_z_8_struct));
}
int cuda_gpu_sort_one_grid_z_8_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_z_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_z_8_exec(cuda_gpu_sort_one_grid_z_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_z_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_z_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_z_8");
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_y_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_y_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_y_8_struct));
}
int cuda_sort_one_grid_y_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_y_8_get_num_compute_units(
    cuda_sort_one_grid_y_8_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_y_8_exec(cuda_sort_one_grid_y_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_y_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_y_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_y_8");
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_y_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_y_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_y_8_struct));
}
int cuda_gpu_sort_one_grid_y_8_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_y_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_y_8_exec(cuda_gpu_sort_one_grid_y_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_y_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_y_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_y_8");
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_x_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_x_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_x_8_struct));
}
int cuda_sort_one_grid_x_8_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_x_8_get_num_compute_units(
    cuda_sort_one_grid_x_8_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_x_8_exec(cuda_sort_one_grid_x_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_x_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_x_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_x_8");
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_x_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_x_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_x_8_struct));
}
int cuda_gpu_sort_one_grid_x_8_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_x_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_x_8_exec(cuda_gpu_sort_one_grid_x_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_x_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_x_8<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_x_8");
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_z_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_z_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_z_vlo_6_struct));
}
int cuda_sort_one_grid_z_vlo_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_z_vlo_6_get_num_compute_units(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_z_vlo_6_exec(cuda_sort_one_grid_z_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_z_vlo_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_z_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_z_vlo_6");
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_z_vlo_6_struct));
}
int cuda_gpu_sort_one_grid_z_vlo_6_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_z_vlo_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_z_vlo_6_exec(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_z_vlo_6<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_z_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_z_vlo_6");
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_y_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_y_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_y_vlo_6_struct));
}
int cuda_sort_one_grid_y_vlo_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_y_vlo_6_get_num_compute_units(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_y_vlo_6_exec(cuda_sort_one_grid_y_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_y_vlo_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_y_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_y_vlo_6");
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_y_vlo_6_struct));
}
int cuda_gpu_sort_one_grid_y_vlo_6_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_y_vlo_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_y_vlo_6_exec(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_y_vlo_6<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_y_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_y_vlo_6");
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_x_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_x_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_x_vlo_6_struct));
}
int cuda_sort_one_grid_x_vlo_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_x_vlo_6_get_num_compute_units(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_x_vlo_6_exec(cuda_sort_one_grid_x_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_x_vlo_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_x_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_x_vlo_6");
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_x_vlo_6_struct));
}
int cuda_gpu_sort_one_grid_x_vlo_6_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_x_vlo_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_x_vlo_6_exec(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_x_vlo_6<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_x_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_x_vlo_6");
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_z_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_z_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_z_6_struct));
}
int cuda_sort_one_grid_z_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_z_6_get_num_compute_units(
    cuda_sort_one_grid_z_6_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_z_6_exec(cuda_sort_one_grid_z_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_z_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_z_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_z_6");
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_z_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_z_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_z_6_struct));
}
int cuda_gpu_sort_one_grid_z_6_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_z_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_z_6_exec(cuda_gpu_sort_one_grid_z_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_z_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_z_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_z_6");
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_y_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_y_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_y_6_struct));
}
int cuda_sort_one_grid_y_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_y_6_get_num_compute_units(
    cuda_sort_one_grid_y_6_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_y_6_exec(cuda_sort_one_grid_y_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_y_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_y_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_y_6");
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_y_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_y_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_y_6_struct));
}
int cuda_gpu_sort_one_grid_y_6_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_y_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_y_6_exec(cuda_gpu_sort_one_grid_y_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_y_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_y_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_y_6");
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_x_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sort_one_grid_x_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sort_one_grid_x_6_struct));
}
int cuda_sort_one_grid_x_6_get_xlen() { return IDX_OPT_MAX; }
int cuda_sort_one_grid_x_6_get_num_compute_units(
    cuda_sort_one_grid_x_6_struct *kerstr) {
  return 64;
}
int cuda_sort_one_grid_x_6_exec(cuda_sort_one_grid_x_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sort_one_grid_x_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_sort_one_grid_x_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sort_one_grid_x_6");
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_x_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_gpu_sort_one_grid_x_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_gpu_sort_one_grid_x_6_struct));
}
int cuda_gpu_sort_one_grid_x_6_get_xlen() { return 32; }
int cuda_gpu_sort_one_grid_x_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr) {
  return 64;
}
int cuda_gpu_sort_one_grid_x_6_exec(cuda_gpu_sort_one_grid_x_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_gpu_sort_one_grid_x_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
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

    cuda_gpu_sort_one_grid_x_6<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inoutput->d_data), ((int *)kerstr->xyzw->d_data),
        ((double *)kerstr->cu_cache->d_data), ((int *)kerstr->cu_xyzw->d_data),
        ((long *)kerstr->adjoint_vec_pids->d_data),
        (((long *)kerstr->XLEN->h_data))[0],
        (((long *)kerstr->YLEN->h_data))[0],
        (((long *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((long *)kerstr->grid_cache_len->h_data))[0],
        (((long *)kerstr->cu_cache_length->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_gpu_sort_one_grid_x_6");
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->inoutput = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_xyzw = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->XLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->YLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ZLEN = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->grid_cache_len = pm);
  return 0;
}
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->cu_cache_length = pm);
  return 0;
}
}
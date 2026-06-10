#include "pubdefs.h"

int cuda_cu_swap_r_8_init(cuda_pscmc_env *pe, cuda_cu_swap_r_8_struct *kerstr);
void cuda_cu_swap_r_8_get_struct_len(size_t *len);
int cuda_cu_swap_r_8_get_xlen();
int cuda_cu_swap_r_8_get_num_compute_units(cuda_cu_swap_r_8_struct *kerstr);
int cuda_cu_swap_r_8_exec(cuda_cu_swap_r_8_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_cu_swap_r_8_scmc_set_parameter_cu_cache(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_8_scmc_set_parameter_cu_xyzw(cuda_cu_swap_r_8_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_8_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_r_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_8_scmc_set_parameter_XYZLEN(cuda_cu_swap_r_8_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_cu_swap_l_8_init(cuda_pscmc_env *pe, cuda_cu_swap_l_8_struct *kerstr);
void cuda_cu_swap_l_8_get_struct_len(size_t *len);
int cuda_cu_swap_l_8_get_xlen();
int cuda_cu_swap_l_8_get_num_compute_units(cuda_cu_swap_l_8_struct *kerstr);
int cuda_cu_swap_l_8_exec(cuda_cu_swap_l_8_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_cu_swap_l_8_scmc_set_parameter_cu_cache(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_8_scmc_set_parameter_cu_xyzw(cuda_cu_swap_l_8_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_8_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_l_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_8_scmc_set_parameter_XYZLEN(cuda_cu_swap_l_8_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_cu_swap_r_6_init(cuda_pscmc_env *pe, cuda_cu_swap_r_6_struct *kerstr);
void cuda_cu_swap_r_6_get_struct_len(size_t *len);
int cuda_cu_swap_r_6_get_xlen();
int cuda_cu_swap_r_6_get_num_compute_units(cuda_cu_swap_r_6_struct *kerstr);
int cuda_cu_swap_r_6_exec(cuda_cu_swap_r_6_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_cu_swap_r_6_scmc_set_parameter_cu_cache(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_6_scmc_set_parameter_cu_xyzw(cuda_cu_swap_r_6_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_6_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_r_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_r_6_scmc_set_parameter_XYZLEN(cuda_cu_swap_r_6_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_cu_swap_l_6_init(cuda_pscmc_env *pe, cuda_cu_swap_l_6_struct *kerstr);
void cuda_cu_swap_l_6_get_struct_len(size_t *len);
int cuda_cu_swap_l_6_get_xlen();
int cuda_cu_swap_l_6_get_num_compute_units(cuda_cu_swap_l_6_struct *kerstr);
int cuda_cu_swap_l_6_exec(cuda_cu_swap_l_6_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_cu_swap_l_6_scmc_set_parameter_cu_cache(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_6_scmc_set_parameter_cu_xyzw(cuda_cu_swap_l_6_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_6_scmc_set_parameter_the_dir_num(
    cuda_cu_swap_l_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_cu_swap_l_6_scmc_set_parameter_XYZLEN(cuda_cu_swap_l_6_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_z_vlo_8_struct *kerstr);
void cuda_sort_one_grid_z_vlo_8_get_struct_len(size_t *len);
int cuda_sort_one_grid_z_vlo_8_get_xlen();
int cuda_sort_one_grid_z_vlo_8_get_num_compute_units(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr);
int cuda_sort_one_grid_z_vlo_8_exec(cuda_sort_one_grid_z_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr);
void cuda_gpu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_z_vlo_8_get_xlen();
int cuda_gpu_sort_one_grid_z_vlo_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr);
int cuda_gpu_sort_one_grid_z_vlo_8_exec(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_y_vlo_8_struct *kerstr);
void cuda_sort_one_grid_y_vlo_8_get_struct_len(size_t *len);
int cuda_sort_one_grid_y_vlo_8_get_xlen();
int cuda_sort_one_grid_y_vlo_8_get_num_compute_units(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr);
int cuda_sort_one_grid_y_vlo_8_exec(cuda_sort_one_grid_y_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr);
void cuda_gpu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_y_vlo_8_get_xlen();
int cuda_gpu_sort_one_grid_y_vlo_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr);
int cuda_gpu_sort_one_grid_y_vlo_8_exec(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_x_vlo_8_struct *kerstr);
void cuda_sort_one_grid_x_vlo_8_get_struct_len(size_t *len);
int cuda_sort_one_grid_x_vlo_8_get_xlen();
int cuda_sort_one_grid_x_vlo_8_get_num_compute_units(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr);
int cuda_sort_one_grid_x_vlo_8_exec(cuda_sort_one_grid_x_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr);
void cuda_gpu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_x_vlo_8_get_xlen();
int cuda_gpu_sort_one_grid_x_vlo_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr);
int cuda_gpu_sort_one_grid_x_vlo_8_exec(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_vlo_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_z_8_struct *kerstr);
void cuda_sort_one_grid_z_8_get_struct_len(size_t *len);
int cuda_sort_one_grid_z_8_get_xlen();
int cuda_sort_one_grid_z_8_get_num_compute_units(
    cuda_sort_one_grid_z_8_struct *kerstr);
int cuda_sort_one_grid_z_8_exec(cuda_sort_one_grid_z_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_z_8_struct *kerstr);
void cuda_gpu_sort_one_grid_z_8_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_z_8_get_xlen();
int cuda_gpu_sort_one_grid_z_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr);
int cuda_gpu_sort_one_grid_z_8_exec(cuda_gpu_sort_one_grid_z_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_y_8_struct *kerstr);
void cuda_sort_one_grid_y_8_get_struct_len(size_t *len);
int cuda_sort_one_grid_y_8_get_xlen();
int cuda_sort_one_grid_y_8_get_num_compute_units(
    cuda_sort_one_grid_y_8_struct *kerstr);
int cuda_sort_one_grid_y_8_exec(cuda_sort_one_grid_y_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_y_8_struct *kerstr);
void cuda_gpu_sort_one_grid_y_8_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_y_8_get_xlen();
int cuda_gpu_sort_one_grid_y_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr);
int cuda_gpu_sort_one_grid_y_8_exec(cuda_gpu_sort_one_grid_y_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_x_8_struct *kerstr);
void cuda_sort_one_grid_x_8_get_struct_len(size_t *len);
int cuda_sort_one_grid_x_8_get_xlen();
int cuda_sort_one_grid_x_8_get_num_compute_units(
    cuda_sort_one_grid_x_8_struct *kerstr);
int cuda_sort_one_grid_x_8_exec(cuda_sort_one_grid_x_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_x_8_struct *kerstr);
void cuda_gpu_sort_one_grid_x_8_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_x_8_get_xlen();
int cuda_gpu_sort_one_grid_x_8_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr);
int cuda_gpu_sort_one_grid_x_8_exec(cuda_gpu_sort_one_grid_x_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_z_vlo_6_struct *kerstr);
void cuda_sort_one_grid_z_vlo_6_get_struct_len(size_t *len);
int cuda_sort_one_grid_z_vlo_6_get_xlen();
int cuda_sort_one_grid_z_vlo_6_get_num_compute_units(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr);
int cuda_sort_one_grid_z_vlo_6_exec(cuda_sort_one_grid_z_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr);
void cuda_gpu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_z_vlo_6_get_xlen();
int cuda_gpu_sort_one_grid_z_vlo_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr);
int cuda_gpu_sort_one_grid_z_vlo_6_exec(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_y_vlo_6_struct *kerstr);
void cuda_sort_one_grid_y_vlo_6_get_struct_len(size_t *len);
int cuda_sort_one_grid_y_vlo_6_get_xlen();
int cuda_sort_one_grid_y_vlo_6_get_num_compute_units(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr);
int cuda_sort_one_grid_y_vlo_6_exec(cuda_sort_one_grid_y_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr);
void cuda_gpu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_y_vlo_6_get_xlen();
int cuda_gpu_sort_one_grid_y_vlo_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr);
int cuda_gpu_sort_one_grid_y_vlo_6_exec(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_init(cuda_pscmc_env *pe,
                                    cuda_sort_one_grid_x_vlo_6_struct *kerstr);
void cuda_sort_one_grid_x_vlo_6_get_struct_len(size_t *len);
int cuda_sort_one_grid_x_vlo_6_get_xlen();
int cuda_sort_one_grid_x_vlo_6_get_num_compute_units(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr);
int cuda_sort_one_grid_x_vlo_6_exec(cuda_sort_one_grid_x_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_init(
    cuda_pscmc_env *pe, cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr);
void cuda_gpu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_x_vlo_6_get_xlen();
int cuda_gpu_sort_one_grid_x_vlo_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr);
int cuda_gpu_sort_one_grid_x_vlo_6_exec(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_vlo_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_z_6_struct *kerstr);
void cuda_sort_one_grid_z_6_get_struct_len(size_t *len);
int cuda_sort_one_grid_z_6_get_xlen();
int cuda_sort_one_grid_z_6_get_num_compute_units(
    cuda_sort_one_grid_z_6_struct *kerstr);
int cuda_sort_one_grid_z_6_exec(cuda_sort_one_grid_z_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_z_6_struct *kerstr);
void cuda_gpu_sort_one_grid_z_6_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_z_6_get_xlen();
int cuda_gpu_sort_one_grid_z_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr);
int cuda_gpu_sort_one_grid_z_6_exec(cuda_gpu_sort_one_grid_z_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_z_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_y_6_struct *kerstr);
void cuda_sort_one_grid_y_6_get_struct_len(size_t *len);
int cuda_sort_one_grid_y_6_get_xlen();
int cuda_sort_one_grid_y_6_get_num_compute_units(
    cuda_sort_one_grid_y_6_struct *kerstr);
int cuda_sort_one_grid_y_6_exec(cuda_sort_one_grid_y_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_y_6_struct *kerstr);
void cuda_gpu_sort_one_grid_y_6_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_y_6_get_xlen();
int cuda_gpu_sort_one_grid_y_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr);
int cuda_gpu_sort_one_grid_y_6_exec(cuda_gpu_sort_one_grid_y_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_y_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_init(cuda_pscmc_env *pe,
                                cuda_sort_one_grid_x_6_struct *kerstr);
void cuda_sort_one_grid_x_6_get_struct_len(size_t *len);
int cuda_sort_one_grid_x_6_get_xlen();
int cuda_sort_one_grid_x_6_get_num_compute_units(
    cuda_sort_one_grid_x_6_struct *kerstr);
int cuda_sort_one_grid_x_6_exec(cuda_sort_one_grid_x_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_numvec(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    cuda_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_init(cuda_pscmc_env *pe,
                                    cuda_gpu_sort_one_grid_x_6_struct *kerstr);
void cuda_gpu_sort_one_grid_x_6_get_struct_len(size_t *len);
int cuda_gpu_sort_one_grid_x_6_get_xlen();
int cuda_gpu_sort_one_grid_x_6_get_num_compute_units(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr);
int cuda_gpu_sort_one_grid_x_6_exec(cuda_gpu_sort_one_grid_x_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    cuda_gpu_sort_one_grid_x_6_struct *kerstr, cuda_pscmc_mem *pm);

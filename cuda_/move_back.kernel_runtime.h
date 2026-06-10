#include "pubdefs.h"

int cuda_move_back_kernel_8_init(cuda_pscmc_env *pe,
                                 cuda_move_back_kernel_8_struct *kerstr);
void cuda_move_back_kernel_8_get_struct_len(size_t *len);
int cuda_move_back_kernel_8_get_xlen();
int cuda_move_back_kernel_8_get_num_compute_units(
    cuda_move_back_kernel_8_struct *kerstr);
int cuda_move_back_kernel_8_exec(cuda_move_back_kernel_8_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_move_back_kernel_8_scmc_set_parameter_inoutput(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_xyzw(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_cu_cache(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_cu_xyzw(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_XLEN(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_YLEN(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_ZLEN(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_grid_cache_len(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_8_scmc_set_parameter_cu_cache_length(
    cuda_move_back_kernel_8_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_init(cuda_pscmc_env *pe,
                                 cuda_move_back_kernel_6_struct *kerstr);
void cuda_move_back_kernel_6_get_struct_len(size_t *len);
int cuda_move_back_kernel_6_get_xlen();
int cuda_move_back_kernel_6_get_num_compute_units(
    cuda_move_back_kernel_6_struct *kerstr);
int cuda_move_back_kernel_6_exec(cuda_move_back_kernel_6_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_move_back_kernel_6_scmc_set_parameter_inoutput(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_xyzw(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_cu_cache(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_cu_xyzw(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_XLEN(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_YLEN(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_ZLEN(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_grid_cache_len(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_move_back_kernel_6_scmc_set_parameter_cu_cache_length(
    cuda_move_back_kernel_6_struct *kerstr, cuda_pscmc_mem *pm);

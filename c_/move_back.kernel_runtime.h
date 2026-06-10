#include "pubdefs.h"

int c_move_back_kernel_8_init(c_pscmc_env *pe,
                              c_move_back_kernel_8_struct *kerstr);
void c_move_back_kernel_8_get_struct_len(size_t *len);
int c_move_back_kernel_8_get_xlen();
int c_move_back_kernel_8_get_num_compute_units(
    c_move_back_kernel_8_struct *kerstr);
int c_move_back_kernel_8_exec(c_move_back_kernel_8_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen);
int c_move_back_kernel_8_scmc_set_parameter_inoutput(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_xyzw(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_cu_cache(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_cu_xyzw(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_XLEN(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_YLEN(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_ZLEN(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_grid_cache_len(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_8_scmc_set_parameter_cu_cache_length(
    c_move_back_kernel_8_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_init(c_pscmc_env *pe,
                              c_move_back_kernel_6_struct *kerstr);
void c_move_back_kernel_6_get_struct_len(size_t *len);
int c_move_back_kernel_6_get_xlen();
int c_move_back_kernel_6_get_num_compute_units(
    c_move_back_kernel_6_struct *kerstr);
int c_move_back_kernel_6_exec(c_move_back_kernel_6_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen);
int c_move_back_kernel_6_scmc_set_parameter_inoutput(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_xyzw(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_cu_cache(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_cu_xyzw(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_XLEN(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_YLEN(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_ZLEN(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_grid_cache_len(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);
int c_move_back_kernel_6_scmc_set_parameter_cu_cache_length(
    c_move_back_kernel_6_struct *kerstr, c_pscmc_mem *pm);

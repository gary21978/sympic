#pragma once
#include "mapu_pscmc.h"


typedef struct {
	mapu_pscmc_env* pe;
	mapu_pscmc_mem* inoutput;
	mapu_pscmc_mem* xyzw;
	mapu_pscmc_mem* cu_cache;
	mapu_pscmc_mem* cu_xyzw;
	mapu_pscmc_mem* XLEN;
	mapu_pscmc_mem* YLEN;
	mapu_pscmc_mem* ZLEN;
	mapu_pscmc_mem* grid_cache_len;
	mapu_pscmc_mem* cu_cache_length;
} mapu_move_back_kernel_8_struct; typedef struct {
	mapu_pscmc_env* pe;
	mapu_pscmc_mem* inoutput;
	mapu_pscmc_mem* xyzw;
	mapu_pscmc_mem* cu_cache;
	mapu_pscmc_mem* cu_xyzw;
	mapu_pscmc_mem* XLEN;
	mapu_pscmc_mem* YLEN;
	mapu_pscmc_mem* ZLEN;
	mapu_pscmc_mem* grid_cache_len;
	mapu_pscmc_mem* cu_cache_length;
} mapu_move_back_kernel_6_struct;


#ifdef __cplusplus
    extern "C" {
#endif

int mapu_move_back_kernel_8_init(mapu_pscmc_env *pe,
                                 mapu_move_back_kernel_8_struct *kerstr);
void mapu_move_back_kernel_8_get_struct_len(size_t *len);
int mapu_move_back_kernel_8_get_xlen();
int mapu_move_back_kernel_8_get_num_compute_units(
    mapu_move_back_kernel_8_struct *kerstr);
int mapu_move_back_kernel_8_exec(mapu_move_back_kernel_8_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int mapu_move_back_kernel_8_scmc_set_parameter_inoutput(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_xyzw(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_cu_cache(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_cu_xyzw(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_XLEN(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_YLEN(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_ZLEN(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_grid_cache_len(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_8_scmc_set_parameter_cu_cache_length(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_init(mapu_pscmc_env *pe,
                                 mapu_move_back_kernel_6_struct *kerstr);
void mapu_move_back_kernel_6_get_struct_len(size_t *len);
int mapu_move_back_kernel_6_get_xlen();
int mapu_move_back_kernel_6_get_num_compute_units(
    mapu_move_back_kernel_6_struct *kerstr);
int mapu_move_back_kernel_6_exec(mapu_move_back_kernel_6_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int mapu_move_back_kernel_6_scmc_set_parameter_inoutput(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_xyzw(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_cu_cache(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_cu_xyzw(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_XLEN(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_YLEN(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_ZLEN(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_grid_cache_len(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_move_back_kernel_6_scmc_set_parameter_cu_cache_length(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm);

#ifdef __cplusplus    
    }
#endif
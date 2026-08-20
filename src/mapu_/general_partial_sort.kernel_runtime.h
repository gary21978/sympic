#pragma once

#include "mapu_pscmc.h"

typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *cu_cache_length;
  mapu_pscmc_mem *the_dir_num;
  mapu_pscmc_mem *XYZLEN;
} mapu_cu_swap_r_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *cu_cache_length;
  mapu_pscmc_mem *the_dir_num;
  mapu_pscmc_mem *XYZLEN;
} mapu_cu_swap_l_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *cu_cache_length;
  mapu_pscmc_mem *the_dir_num;
  mapu_pscmc_mem *XYZLEN;
} mapu_cu_swap_r_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *cu_cache_length;
  mapu_pscmc_mem *the_dir_num;
  mapu_pscmc_mem *XYZLEN;
} mapu_cu_swap_l_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_z_vlo_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_z_vlo_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_y_vlo_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_y_vlo_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_x_vlo_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_x_vlo_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_z_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_z_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_y_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_y_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_x_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_x_8_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_z_vlo_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_z_vlo_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_y_vlo_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_y_vlo_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_x_vlo_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_x_vlo_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_z_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_z_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_y_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_y_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_sort_one_grid_x_6_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *adjoint_vec_pids;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
} mapu_gpu_sort_one_grid_x_6_struct;

#ifdef __cplusplus
extern "C"{
#endif

int mapu_cu_swap_r_8_init(mapu_pscmc_env *pe, mapu_cu_swap_r_8_struct *kerstr);

int mapu_cu_swap_r_8_get_xlen();

int mapu_cu_swap_r_8_exec(mapu_cu_swap_r_8_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);

int mapu_cu_swap_r_8_scmc_set_parameter_cu_cache(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_8_scmc_set_parameter_cu_xyzw(mapu_cu_swap_r_8_struct *kerstr,
                                                mapu_pscmc_mem *pm);

int mapu_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_8_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_8_scmc_set_parameter_XYZLEN(mapu_cu_swap_r_8_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_cu_swap_l_8_init(mapu_pscmc_env *pe, mapu_cu_swap_l_8_struct *kerstr);

int mapu_cu_swap_l_8_get_xlen();

int mapu_cu_swap_l_8_exec(mapu_cu_swap_l_8_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);

int mapu_cu_swap_l_8_scmc_set_parameter_cu_cache(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_8_scmc_set_parameter_cu_xyzw(mapu_cu_swap_l_8_struct *kerstr,
                                                mapu_pscmc_mem *pm);

int mapu_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_8_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_8_scmc_set_parameter_XYZLEN(mapu_cu_swap_l_8_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_cu_swap_r_6_init(mapu_pscmc_env *pe, mapu_cu_swap_r_6_struct *kerstr);

void mapu_cu_swap_r_6_get_struct_len(size_t *len);

int mapu_cu_swap_r_6_get_xlen();

int mapu_cu_swap_r_6_exec(mapu_cu_swap_r_6_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);

int mapu_cu_swap_r_6_scmc_set_parameter_cu_cache(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_6_scmc_set_parameter_cu_xyzw(mapu_cu_swap_r_6_struct *kerstr,
                                                mapu_pscmc_mem *pm);

int mapu_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_6_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_r_6_scmc_set_parameter_XYZLEN(mapu_cu_swap_r_6_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_cu_swap_l_6_init(mapu_pscmc_env *pe, mapu_cu_swap_l_6_struct *kerstr);

void mapu_cu_swap_l_6_get_struct_len(size_t *len);

int mapu_cu_swap_l_6_get_xlen();

int mapu_cu_swap_l_6_exec(mapu_cu_swap_l_6_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);

int mapu_cu_swap_l_6_scmc_set_parameter_cu_cache(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_6_scmc_set_parameter_cu_xyzw(mapu_cu_swap_l_6_struct *kerstr,
                                                mapu_pscmc_mem *pm);

int mapu_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_6_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_cu_swap_l_6_scmc_set_parameter_XYZLEN(mapu_cu_swap_l_6_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_z_vlo_8_struct *kerstr);

void mapu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len);

int mapu_sort_one_grid_z_vlo_8_get_xlen();

int mapu_sort_one_grid_z_vlo_8_exec(mapu_sort_one_grid_z_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr);

void mapu_gpu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len);

int mapu_gpu_sort_one_grid_z_vlo_8_get_xlen();

int mapu_gpu_sort_one_grid_z_vlo_8_exec(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_y_vlo_8_struct *kerstr);

void mapu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len);

int mapu_sort_one_grid_y_vlo_8_get_xlen();

int mapu_sort_one_grid_y_vlo_8_exec(mapu_sort_one_grid_y_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr);

void mapu_gpu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len);

int mapu_gpu_sort_one_grid_y_vlo_8_get_xlen();

int mapu_gpu_sort_one_grid_y_vlo_8_exec(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_x_vlo_8_struct *kerstr);

void mapu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len);

int mapu_sort_one_grid_x_vlo_8_get_xlen();

int mapu_sort_one_grid_x_vlo_8_exec(mapu_sort_one_grid_x_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr);

void mapu_gpu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len);

int mapu_gpu_sort_one_grid_x_vlo_8_get_xlen();

int mapu_gpu_sort_one_grid_x_vlo_8_exec(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_z_8_struct *kerstr);

void mapu_sort_one_grid_z_8_get_struct_len(size_t *len);
int mapu_sort_one_grid_z_8_get_xlen();

int mapu_sort_one_grid_z_8_exec(mapu_sort_one_grid_z_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);

int mapu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_z_8_struct *kerstr);

void mapu_gpu_sort_one_grid_z_8_get_struct_len(size_t *len);

int mapu_gpu_sort_one_grid_z_8_get_xlen();

int mapu_gpu_sort_one_grid_z_8_exec(mapu_gpu_sort_one_grid_z_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_8_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_y_8_struct *kerstr);

void mapu_sort_one_grid_y_8_get_struct_len(size_t *len);

int mapu_sort_one_grid_y_8_get_xlen();

int mapu_sort_one_grid_y_8_exec(mapu_sort_one_grid_y_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);

int mapu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_y_8_struct *kerstr);
void mapu_gpu_sort_one_grid_y_8_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_y_8_get_xlen();

int mapu_gpu_sort_one_grid_y_8_exec(mapu_gpu_sort_one_grid_y_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_x_8_struct *kerstr);
void mapu_sort_one_grid_x_8_get_struct_len(size_t *len);
int mapu_sort_one_grid_x_8_get_xlen();

int mapu_sort_one_grid_x_8_exec(mapu_sort_one_grid_x_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int mapu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_x_8_struct *kerstr);
void mapu_gpu_sort_one_grid_x_8_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_x_8_get_xlen();

int mapu_gpu_sort_one_grid_x_8_exec(mapu_gpu_sort_one_grid_x_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_z_vlo_6_struct *kerstr);
void mapu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len);
int mapu_sort_one_grid_z_vlo_6_get_xlen();

int mapu_sort_one_grid_z_vlo_6_exec(mapu_sort_one_grid_z_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr);
void mapu_gpu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_z_vlo_6_get_xlen();

int mapu_gpu_sort_one_grid_z_vlo_6_exec(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_y_vlo_6_struct *kerstr);
void mapu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len);
int mapu_sort_one_grid_y_vlo_6_get_xlen();

int mapu_sort_one_grid_y_vlo_6_exec(mapu_sort_one_grid_y_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr);
void mapu_gpu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_y_vlo_6_get_xlen();

int mapu_gpu_sort_one_grid_y_vlo_6_exec(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_x_vlo_6_struct *kerstr);
void mapu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len);
int mapu_sort_one_grid_x_vlo_6_get_xlen();

int mapu_sort_one_grid_x_vlo_6_exec(mapu_sort_one_grid_x_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr);
void mapu_gpu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_x_vlo_6_get_xlen();

int mapu_gpu_sort_one_grid_x_vlo_6_exec(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_z_6_struct *kerstr);
void mapu_sort_one_grid_z_6_get_struct_len(size_t *len);
int mapu_sort_one_grid_z_6_get_xlen();

int mapu_sort_one_grid_z_6_exec(mapu_sort_one_grid_z_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int mapu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_z_6_struct *kerstr);
void mapu_gpu_sort_one_grid_z_6_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_z_6_get_xlen();

int mapu_gpu_sort_one_grid_z_6_exec(mapu_gpu_sort_one_grid_z_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_y_6_struct *kerstr);
void mapu_sort_one_grid_y_6_get_struct_len(size_t *len);
int mapu_sort_one_grid_y_6_get_xlen();

int mapu_sort_one_grid_y_6_exec(mapu_sort_one_grid_y_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int mapu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_y_6_struct *kerstr);
void mapu_gpu_sort_one_grid_y_6_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_y_6_get_xlen();

int mapu_gpu_sort_one_grid_y_6_exec(mapu_gpu_sort_one_grid_y_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_x_6_struct *kerstr);
void mapu_sort_one_grid_x_6_get_struct_len(size_t *len);
int mapu_sort_one_grid_x_6_get_xlen();

int mapu_sort_one_grid_x_6_exec(mapu_sort_one_grid_x_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int mapu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_6_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_x_6_struct *kerstr);
void mapu_gpu_sort_one_grid_x_6_get_struct_len(size_t *len);
int mapu_gpu_sort_one_grid_x_6_get_xlen();

int mapu_gpu_sort_one_grid_x_6_exec(mapu_gpu_sort_one_grid_x_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm);

#ifdef __cplusplus
}
#endif
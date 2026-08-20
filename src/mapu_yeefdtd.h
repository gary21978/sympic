
#pragma once

/*
 * MAPU/SCALE runtime wrapper for inner_split_pass.kernel.sc.
 *
 * This file intentionally keeps the same PSCMC-style strong typing as the
 * CUDA backend runtime: setters take
 *
 *     mapu_geo_nr_Bfield_pushJ_vlo_struct *
 *     mapu_pscmc_mem *
 *
 * The upper run_particle_call layer is responsible for casting its generic
 * void* members to backend-specific types.
 */

// #include "../pubdefs.h"
#include "mapu_pscmc.h"
#include "inner_split_pass.kernel_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

int  mapu_geo_nr_Bfield_pushJ_vlo_init(
    mapu_pscmc_env *pe,
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr);

long mapu_geo_nr_Bfield_pushJ_vlo_get_struct_len(void);
long mapu_geo_nr_Bfield_pushJ_vlo_get_xlen(void);
long mapu_geo_nr_Bfield_pushJ_vlo_get_num_compute_units(void);

int mapu_geo_nr_Bfield_pushJ_vlo_exec(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr,
    long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);

/* pointer parameters */
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE_ext(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB(
mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);

/* scalar parameters, passed through one-element pscmc_mem objects */
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_use_g_e(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, mapu_pscmc_mem *pm);

#ifdef __cplusplus
} /* extern \"C\" */
#endif




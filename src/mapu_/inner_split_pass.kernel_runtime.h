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


typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *xoffset;
  mapu_pscmc_mem *yoffset;
  mapu_pscmc_mem *zoffset;
  mapu_pscmc_mem *fieldE;
  mapu_pscmc_mem *fieldE_ext;
  mapu_pscmc_mem *fieldB;
  mapu_pscmc_mem *fieldB1;
  mapu_pscmc_mem *FoutJ;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *num_ele;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
  mapu_pscmc_mem *use_g_e;
  mapu_pscmc_mem *DELTA_X;
  mapu_pscmc_mem *DELTA_Y;
  mapu_pscmc_mem *DELTA_Z;
  mapu_pscmc_mem *Mass0;
  mapu_pscmc_mem *Charge0;
  mapu_pscmc_mem *Deltat;
  mapu_pscmc_mem *Tori_X0;
  mapu_pscmc_mem *r0;
  mapu_pscmc_mem *MIN_R0;
  mapu_pscmc_mem *Q0;
  mapu_pscmc_mem *b0;
  mapu_pscmc_mem *zmid;
} mapu_geo_nr_Bfield_pushJ_vlo_struct;


#ifdef __cplusplus
extern "C" {
#endif

int mapu_geo_nr_Bfield_pushJ_vlo_init(
    mapu_pscmc_env *pe, mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr);

long mapu_geo_nr_Bfield_pushJ_vlo_get_struct_len(void);
long mapu_geo_nr_Bfield_pushJ_vlo_get_xlen(void);
long mapu_geo_nr_Bfield_pushJ_vlo_get_num_compute_units(void);

int mapu_geo_nr_Bfield_pushJ_vlo_exec(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr, long scmc_internal_g_xlen,
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


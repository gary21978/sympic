
#pragma once

#include "mapu_pscmc.h"

typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutput;
  mapu_pscmc_mem *xyzw;
  mapu_pscmc_mem *cu_cache;
  mapu_pscmc_mem *cu_xyzw;
  mapu_pscmc_mem *fieldE;
  mapu_pscmc_mem *fieldB;
  mapu_pscmc_mem *FoutJ;
  mapu_pscmc_mem *FoutEN;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *num_ele;
  mapu_pscmc_mem *grid_cache_len;
  mapu_pscmc_mem *cu_cache_length;
  mapu_pscmc_mem *Mass;
  mapu_pscmc_mem *Charge;
  mapu_pscmc_mem *SPEC;
  mapu_pscmc_mem *NUM_SPEC;
  mapu_pscmc_mem *DELTA_X;
  mapu_pscmc_mem *DELTA_Y;
  mapu_pscmc_mem *DELTA_Z;
  mapu_pscmc_mem *Deltat;
} mapu_dump_ene_num_struct;

#ifdef __cplusplus
    extern "C" {
#endif

int mapu_dump_ene_num_init(mapu_pscmc_env *pe,
                           mapu_dump_ene_num_struct *kerstr);
void mapu_dump_ene_num_get_struct_len(size_t *len);
int mapu_dump_ene_num_get_xlen();
int mapu_dump_ene_num_get_num_compute_units(mapu_dump_ene_num_struct *kerstr);
int mapu_dump_ene_num_exec(mapu_dump_ene_num_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int mapu_dump_ene_num_scmc_set_parameter_inoutput(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_xyzw(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_cu_cache(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_cu_xyzw(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_fieldE(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_fieldB(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_FoutJ(mapu_dump_ene_num_struct *kerstr,
                                               mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_FoutEN(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_XLEN(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_YLEN(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_ZLEN(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_ovlp(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_numvec(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_num_ele(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_grid_cache_len(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_cu_cache_length(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_Mass(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_Charge(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_SPEC(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_NUM_SPEC(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_DELTA_X(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_DELTA_Y(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_DELTA_Z(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_dump_ene_num_scmc_set_parameter_Deltat(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm);

#ifdef __cplusplus
    }
#endif
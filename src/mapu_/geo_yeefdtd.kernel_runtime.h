
#pragma once

#include "mapu_pscmc.h"

typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutE1;
  mapu_pscmc_mem *inB0;
  mapu_pscmc_mem *xoffset;
  mapu_pscmc_mem *yoffset;
  mapu_pscmc_mem *zoffset;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
  mapu_pscmc_mem *DT;
} mapu_YEE_CURL_R_struct;
typedef struct {
  mapu_pscmc_env *pe;
  mapu_pscmc_mem *inoutE1;
  mapu_pscmc_mem *inB0;
  mapu_pscmc_mem *xoffset;
  mapu_pscmc_mem *yoffset;
  mapu_pscmc_mem *zoffset;
  mapu_pscmc_mem *y_cpu_core;
  mapu_pscmc_mem *numvec;
  mapu_pscmc_mem *XLEN;
  mapu_pscmc_mem *YLEN;
  mapu_pscmc_mem *ZLEN;
  mapu_pscmc_mem *ovlp;
  mapu_pscmc_mem *xblock;
  mapu_pscmc_mem *yblock;
  mapu_pscmc_mem *zblock;
  mapu_pscmc_mem *num_ele;
  mapu_pscmc_mem *DT;
  mapu_pscmc_mem *DELTA_Z;
  mapu_pscmc_mem *DELTA_Y;
  mapu_pscmc_mem *DELTA_X;
  mapu_pscmc_mem *x0;
  mapu_pscmc_mem *r0;
} mapu_GEO_YEE_CURL_L_struct;

#ifdef __cplusplus
extern "C" {
#endif

int mapu_YEE_CURL_R_init(mapu_pscmc_env *pe, mapu_YEE_CURL_R_struct *kerstr);
void mapu_YEE_CURL_R_get_struct_len(size_t *len);
int mapu_YEE_CURL_R_get_xlen();
int mapu_YEE_CURL_R_exec(mapu_YEE_CURL_R_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_YEE_CURL_R_scmc_set_parameter_inoutE1(mapu_YEE_CURL_R_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_inB0(mapu_YEE_CURL_R_struct *kerstr,
                                            mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_xoffset(mapu_YEE_CURL_R_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_yoffset(mapu_YEE_CURL_R_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_zoffset(mapu_YEE_CURL_R_struct *kerstr,
                                               mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_y_cpu_core(
    mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_numvec(mapu_YEE_CURL_R_struct *kerstr,
                                              mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_XLEN(mapu_YEE_CURL_R_struct *kerstr,
                                            mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_YLEN(mapu_YEE_CURL_R_struct *kerstr,
                                            mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_ZLEN(mapu_YEE_CURL_R_struct *kerstr,
                                            mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_ovlp(mapu_YEE_CURL_R_struct *kerstr,
                                            mapu_pscmc_mem *pm);
int mapu_YEE_CURL_R_scmc_set_parameter_xblock(mapu_YEE_CURL_R_struct *kerstr,
                                              mapu_pscmc_mem *pm);

int mapu_YEE_CURL_R_scmc_set_parameter_yblock(mapu_YEE_CURL_R_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_YEE_CURL_R_scmc_set_parameter_zblock(mapu_YEE_CURL_R_struct *kerstr,
                                              mapu_pscmc_mem *pm);
int mapu_YEE_CURL_R_scmc_set_parameter_num_ele(mapu_YEE_CURL_R_struct *kerstr,
                                               mapu_pscmc_mem *pm);
int mapu_YEE_CURL_R_scmc_set_parameter_DT(mapu_YEE_CURL_R_struct *kerstr,
                                          mapu_pscmc_mem *pm);

int mapu_GEO_YEE_CURL_L_init(mapu_pscmc_env *pe,
                             mapu_GEO_YEE_CURL_L_struct *kerstr);
void mapu_GEO_YEE_CURL_L_get_struct_len(size_t *len);
int mapu_GEO_YEE_CURL_L_get_xlen();

int mapu_GEO_YEE_CURL_L_exec(mapu_GEO_YEE_CURL_L_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_inB0(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_xoffset(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_yoffset(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_zoffset(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_numvec(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_XLEN(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_YLEN(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_ovlp(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_xblock(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_yblock(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_zblock(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_num_ele(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DT(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_x0(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_GEO_YEE_CURL_L_scmc_set_parameter_r0(
    mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm);
    
#ifdef __cplusplus
    }
#endif
#include "pubdefs.h"

int cuda_YEE_CURL_R_init(cuda_pscmc_env *pe, cuda_YEE_CURL_R_struct *kerstr);
void cuda_YEE_CURL_R_get_struct_len(size_t *len);
int cuda_YEE_CURL_R_get_xlen();
int cuda_YEE_CURL_R_get_num_compute_units(cuda_YEE_CURL_R_struct *kerstr);
int cuda_YEE_CURL_R_exec(cuda_YEE_CURL_R_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_YEE_CURL_R_scmc_set_parameter_inoutE1(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_inB0(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_xoffset(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_yoffset(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_zoffset(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_y_cpu_core(
    cuda_YEE_CURL_R_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_numvec(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_XLEN(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_YLEN(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_ZLEN(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_ovlp(cuda_YEE_CURL_R_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_xblock(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_yblock(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_zblock(cuda_YEE_CURL_R_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_num_ele(cuda_YEE_CURL_R_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_YEE_CURL_R_scmc_set_parameter_DT(cuda_YEE_CURL_R_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_init(cuda_pscmc_env *pe,
                             cuda_GEO_YEE_CURL_L_struct *kerstr);
void cuda_GEO_YEE_CURL_L_get_struct_len(size_t *len);
int cuda_GEO_YEE_CURL_L_get_xlen();
int cuda_GEO_YEE_CURL_L_get_num_compute_units(
    cuda_GEO_YEE_CURL_L_struct *kerstr);
int cuda_GEO_YEE_CURL_L_exec(cuda_GEO_YEE_CURL_L_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_inB0(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_xoffset(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_yoffset(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_zoffset(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_numvec(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_XLEN(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_YLEN(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_ovlp(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_xblock(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_yblock(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_zblock(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_num_ele(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DT(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_GEO_YEE_CURL_L_scmc_set_parameter_x0(
    cuda_GEO_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);

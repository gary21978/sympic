#include "pubdefs.h"

int cuda_RECT_YEE_CURL_L_init(cuda_pscmc_env *pe,
                              cuda_RECT_YEE_CURL_L_struct *kerstr);
void cuda_RECT_YEE_CURL_L_get_struct_len(size_t *len);
int cuda_RECT_YEE_CURL_L_get_xlen();
int cuda_RECT_YEE_CURL_L_get_num_compute_units(
    cuda_RECT_YEE_CURL_L_struct *kerstr);
int cuda_RECT_YEE_CURL_L_exec(cuda_RECT_YEE_CURL_L_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_inoutE1(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_inB0(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_xoffset(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_yoffset(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_zoffset(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_y_cpu_core(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_numvec(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_XLEN(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_YLEN(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_ZLEN(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_ovlp(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_xblock(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_yblock(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_zblock(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_num_ele(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_DT(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_X(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Y(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_RECT_YEE_CURL_L_scmc_set_parameter_DELTA_Z(
    cuda_RECT_YEE_CURL_L_struct *kerstr, cuda_pscmc_mem *pm);

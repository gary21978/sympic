#include "pubdefs.h"

int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_init(
    cuda_pscmc_env *pe, cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr);
void cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_get_struct_len(size_t *len);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_get_xlen();
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_get_num_compute_units(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_exec(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_inoutput(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_xyzw(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_cu_cache(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_cu_xyzw(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_xoffset(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_yoffset(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_zoffset(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_fieldE(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_fieldB(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_fieldB1(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_FoutJ(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_XLEN(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_YLEN(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_ZLEN(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_ovlp(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_numvec(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_num_ele(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_grid_cache_len(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_cu_cache_length(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_DELTA_X(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_DELTA_Y(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_DELTA_Z(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Mass0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Charge0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Deltat(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Tori_X0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_r0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_MIN_R0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_Q0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_b0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_set_parameter_zmid(
    cuda_geo_nr_Bfield_pushJ_nopush_par_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_init(
    cuda_pscmc_env *pe, cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr);
void cuda_geo_nr_Bfield_pushJ_vlo_get_struct_len(size_t *len);
int cuda_geo_nr_Bfield_pushJ_vlo_get_xlen();
int cuda_geo_nr_Bfield_pushJ_vlo_get_num_compute_units(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr);
int cuda_geo_nr_Bfield_pushJ_vlo_exec(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid(
    cuda_geo_nr_Bfield_pushJ_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_init(
    cuda_pscmc_env *pe, cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr);
void cuda_geo_nr_Bfield_pushJ_nopush_par_get_struct_len(size_t *len);
int cuda_geo_nr_Bfield_pushJ_nopush_par_get_xlen();
int cuda_geo_nr_Bfield_pushJ_nopush_par_get_num_compute_units(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr);
int cuda_geo_nr_Bfield_pushJ_nopush_par_exec(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_inoutput(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_xyzw(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_cu_cache(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_cu_xyzw(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_xoffset(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_yoffset(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_zoffset(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_fieldE(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_fieldB(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_fieldB1(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_FoutJ(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_XLEN(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_YLEN(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_ZLEN(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_ovlp(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_numvec(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_num_ele(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_grid_cache_len(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_cu_cache_length(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_DELTA_X(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_DELTA_Y(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_DELTA_Z(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Mass0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Charge0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Deltat(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Tori_X0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_r0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_MIN_R0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_Q0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_b0(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_pushJ_nopush_par_scmc_set_parameter_zmid(
    cuda_geo_nr_Bfield_pushJ_nopush_par_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_init(cuda_pscmc_env *pe,
                            cuda_geo_nr_Bfield_struct *kerstr);
void cuda_geo_nr_Bfield_get_struct_len(size_t *len);
int cuda_geo_nr_Bfield_get_xlen();
int cuda_geo_nr_Bfield_get_num_compute_units(cuda_geo_nr_Bfield_struct *kerstr);
int cuda_geo_nr_Bfield_exec(cuda_geo_nr_Bfield_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen);
int cuda_geo_nr_Bfield_scmc_set_parameter_inoutput(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_xyzw(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_cu_cache(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_cu_xyzw(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_xoffset(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_yoffset(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_zoffset(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_fieldE(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_fieldB(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_fieldB1(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_FoutJ(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_XLEN(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_YLEN(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_ZLEN(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_ovlp(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_numvec(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_num_ele(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_grid_cache_len(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_cu_cache_length(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_DELTA_X(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_DELTA_Y(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_DELTA_Z(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_Mass0(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_Charge0(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_Deltat(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_Tori_X0(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_r0(cuda_geo_nr_Bfield_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_MIN_R0(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_Q0(cuda_geo_nr_Bfield_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_b0(cuda_geo_nr_Bfield_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_geo_nr_Bfield_scmc_set_parameter_zmid(
    cuda_geo_nr_Bfield_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_init(cuda_pscmc_env *pe, cuda_geo_nr_vlo_struct *kerstr);
void cuda_geo_nr_vlo_get_struct_len(size_t *len);
int cuda_geo_nr_vlo_get_xlen();
int cuda_geo_nr_vlo_get_num_compute_units(cuda_geo_nr_vlo_struct *kerstr);
int cuda_geo_nr_vlo_exec(cuda_geo_nr_vlo_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_geo_nr_vlo_scmc_set_parameter_inoutput(cuda_geo_nr_vlo_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_xyzw(cuda_geo_nr_vlo_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_cu_cache(cuda_geo_nr_vlo_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_cu_xyzw(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_xoffset(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_yoffset(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_zoffset(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_fieldE(cuda_geo_nr_vlo_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_fieldB(cuda_geo_nr_vlo_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_fieldB1(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_FoutJ(cuda_geo_nr_vlo_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_XLEN(cuda_geo_nr_vlo_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_YLEN(cuda_geo_nr_vlo_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_ZLEN(cuda_geo_nr_vlo_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_ovlp(cuda_geo_nr_vlo_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_numvec(cuda_geo_nr_vlo_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_num_ele(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_grid_cache_len(
    cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_cu_cache_length(
    cuda_geo_nr_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_DELTA_X(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_DELTA_Y(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_DELTA_Z(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_Mass0(cuda_geo_nr_vlo_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_Charge0(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_Deltat(cuda_geo_nr_vlo_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_Tori_X0(cuda_geo_nr_vlo_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_r0(cuda_geo_nr_vlo_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_MIN_R0(cuda_geo_nr_vlo_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_Q0(cuda_geo_nr_vlo_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_b0(cuda_geo_nr_vlo_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_vlo_scmc_set_parameter_zmid(cuda_geo_nr_vlo_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_init(cuda_pscmc_env *pe, cuda_geo_nr_struct *kerstr);
void cuda_geo_nr_get_struct_len(size_t *len);
int cuda_geo_nr_get_xlen();
int cuda_geo_nr_get_num_compute_units(cuda_geo_nr_struct *kerstr);
int cuda_geo_nr_exec(cuda_geo_nr_struct *kerstr, long scmc_internal_g_xlen,
                     long scmc_internal_g_ylen);
int cuda_geo_nr_scmc_set_parameter_inoutput(cuda_geo_nr_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_xyzw(cuda_geo_nr_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_cu_cache(cuda_geo_nr_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_cu_xyzw(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_xoffset(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_yoffset(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_zoffset(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_fieldE(cuda_geo_nr_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_fieldB(cuda_geo_nr_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_fieldB1(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_FoutJ(cuda_geo_nr_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_XLEN(cuda_geo_nr_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_YLEN(cuda_geo_nr_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_ZLEN(cuda_geo_nr_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_ovlp(cuda_geo_nr_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_numvec(cuda_geo_nr_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_num_ele(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_grid_cache_len(cuda_geo_nr_struct *kerstr,
                                                  cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_cu_cache_length(cuda_geo_nr_struct *kerstr,
                                                   cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_DELTA_X(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_DELTA_Y(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_DELTA_Z(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_Mass0(cuda_geo_nr_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_Charge0(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_Deltat(cuda_geo_nr_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_Tori_X0(cuda_geo_nr_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_r0(cuda_geo_nr_struct *kerstr,
                                      cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_MIN_R0(cuda_geo_nr_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_Q0(cuda_geo_nr_struct *kerstr,
                                      cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_b0(cuda_geo_nr_struct *kerstr,
                                      cuda_pscmc_mem *pm);
int cuda_geo_nr_scmc_set_parameter_zmid(cuda_geo_nr_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_ngeo_gc_init(cuda_pscmc_env *pe, cuda_ngeo_gc_struct *kerstr);
void cuda_ngeo_gc_get_struct_len(size_t *len);
int cuda_ngeo_gc_get_xlen();
int cuda_ngeo_gc_get_num_compute_units(cuda_ngeo_gc_struct *kerstr);
int cuda_ngeo_gc_exec(cuda_ngeo_gc_struct *kerstr, long scmc_internal_g_xlen,
                      long scmc_internal_g_ylen);
int cuda_ngeo_gc_scmc_set_parameter_inoutput(cuda_ngeo_gc_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_xyzw(cuda_ngeo_gc_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_cu_cache(cuda_ngeo_gc_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_cu_xyzw(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_xoffset(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_yoffset(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_zoffset(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_fieldE(cuda_ngeo_gc_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_fieldB(cuda_ngeo_gc_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_fieldB1(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_FoutJ(cuda_ngeo_gc_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_XLEN(cuda_ngeo_gc_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_YLEN(cuda_ngeo_gc_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_ZLEN(cuda_ngeo_gc_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_ovlp(cuda_ngeo_gc_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_numvec(cuda_ngeo_gc_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_num_ele(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_grid_cache_len(cuda_ngeo_gc_struct *kerstr,
                                                   cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_cu_cache_length(cuda_ngeo_gc_struct *kerstr,
                                                    cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_DELTA_X(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_DELTA_Y(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_DELTA_Z(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_Mass0(cuda_ngeo_gc_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_Charge0(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_Deltat(cuda_ngeo_gc_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_Tori_X0(cuda_ngeo_gc_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_r0(cuda_ngeo_gc_struct *kerstr,
                                       cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_MIN_R0(cuda_ngeo_gc_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_Q0(cuda_ngeo_gc_struct *kerstr,
                                       cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_b0(cuda_ngeo_gc_struct *kerstr,
                                       cuda_pscmc_mem *pm);
int cuda_ngeo_gc_scmc_set_parameter_zmid(cuda_ngeo_gc_struct *kerstr,
                                         cuda_pscmc_mem *pm);

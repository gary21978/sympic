#include "pubdefs.h"

int cuda_kgm_eqn_core_init(cuda_pscmc_env *pe,
                           cuda_kgm_eqn_core_struct *kerstr);
void cuda_kgm_eqn_core_get_struct_len(size_t *len);
int cuda_kgm_eqn_core_get_xlen();
int cuda_kgm_eqn_core_get_num_compute_units(cuda_kgm_eqn_core_struct *kerstr);
int cuda_kgm_eqn_core_exec(cuda_kgm_eqn_core_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_kgm_eqn_core_scmc_set_parameter_outEB(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_inEB(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_extA0(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_extA1(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_xoffset(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_yoffset(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_zoffset(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_y_cpu_core(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_numvec(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_XLEN(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_YLEN(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_ZLEN(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_ovlp(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_xblock(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_yblock(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_zblock(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_num_ele(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_DT(cuda_kgm_eqn_core_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_M(cuda_kgm_eqn_core_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_Q(cuda_kgm_eqn_core_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_DX(cuda_kgm_eqn_core_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_GEXT(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_rfz0(cuda_kgm_eqn_core_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_g_beg(cuda_kgm_eqn_core_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_eqn_core_scmc_set_parameter_swap_input(
    cuda_kgm_eqn_core_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_init(cuda_pscmc_env *pe,
                           cuda_kgm_calc_rho_struct *kerstr);
void cuda_kgm_calc_rho_get_struct_len(size_t *len);
int cuda_kgm_calc_rho_get_xlen();
int cuda_kgm_calc_rho_get_num_compute_units(cuda_kgm_calc_rho_struct *kerstr);
int cuda_kgm_calc_rho_exec(cuda_kgm_calc_rho_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_kgm_calc_rho_scmc_set_parameter_outEB(cuda_kgm_calc_rho_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_inEB(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_xoffset(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_yoffset(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_zoffset(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_y_cpu_core(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_numvec(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_XLEN(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_YLEN(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_ZLEN(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_ovlp(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_xblock(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_yblock(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_zblock(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_num_ele(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_DT(cuda_kgm_calc_rho_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_M(cuda_kgm_calc_rho_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_Q(cuda_kgm_calc_rho_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_DX(cuda_kgm_calc_rho_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_refz0(cuda_kgm_calc_rho_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_q(cuda_kgm_calc_rho_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_dtodx(cuda_kgm_calc_rho_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_mode(cuda_kgm_calc_rho_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_kgm_calc_rho_scmc_set_parameter_swap_input(
    cuda_kgm_calc_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_init(cuda_pscmc_env *pe,
                                cuda_PML_FDTD_CURL_BWD_struct *kerstr);
void cuda_PML_FDTD_CURL_BWD_get_struct_len(size_t *len);
int cuda_PML_FDTD_CURL_BWD_get_xlen();
int cuda_PML_FDTD_CURL_BWD_get_num_compute_units(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr);
int cuda_PML_FDTD_CURL_BWD_exec(cuda_PML_FDTD_CURL_BWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_outEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_inEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_outPMLEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_inPMLEB(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_xoffset(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_yoffset(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_zoffset(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_y_cpu_core(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_numvec(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_XLEN(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_YLEN(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_ZLEN(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_ovlp(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_xblock(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_yblock(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_zblock(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_num_ele(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DT(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_M(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_Q(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DX(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DY(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_DZ(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_abc_dir(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_level(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_pml_m(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_max_sigma(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_allxmax(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_allymax(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_BWD_scmc_set_parameter_allzmax(
    cuda_PML_FDTD_CURL_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_init(cuda_pscmc_env *pe,
                                cuda_PML_FDTD_CURL_FWD_struct *kerstr);
void cuda_PML_FDTD_CURL_FWD_get_struct_len(size_t *len);
int cuda_PML_FDTD_CURL_FWD_get_xlen();
int cuda_PML_FDTD_CURL_FWD_get_num_compute_units(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr);
int cuda_PML_FDTD_CURL_FWD_exec(cuda_PML_FDTD_CURL_FWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_outEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_inEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_outPMLEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_inPMLEB(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_xoffset(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_yoffset(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_zoffset(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_y_cpu_core(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_numvec(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_XLEN(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_YLEN(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_ZLEN(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_ovlp(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_xblock(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_yblock(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_zblock(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_num_ele(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DT(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_M(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_Q(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DX(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DY(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_DZ(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_abc_dir(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_level(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_pml_m(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_max_sigma(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_allxmax(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_allymax(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_PML_FDTD_CURL_FWD_scmc_set_parameter_allzmax(
    cuda_PML_FDTD_CURL_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_init(cuda_pscmc_env *pe,
                            cuda_merge_current_struct *kerstr);
void cuda_merge_current_get_struct_len(size_t *len);
int cuda_merge_current_get_xlen();
int cuda_merge_current_get_num_compute_units(cuda_merge_current_struct *kerstr);
int cuda_merge_current_exec(cuda_merge_current_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen);
int cuda_merge_current_scmc_set_parameter_outEB(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_inEB(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_y_cpu_core(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_numvec(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_XLEN(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_YLEN(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_ZLEN(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_ovlp(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_xblock(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_yblock(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_zblock(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_scmc_set_parameter_num_ele(
    cuda_merge_current_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_init(cuda_pscmc_env *pe,
                              cuda_merge_current_2_struct *kerstr);
void cuda_merge_current_2_get_struct_len(size_t *len);
int cuda_merge_current_2_get_xlen();
int cuda_merge_current_2_get_num_compute_units(
    cuda_merge_current_2_struct *kerstr);
int cuda_merge_current_2_exec(cuda_merge_current_2_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen);
int cuda_merge_current_2_scmc_set_parameter_outEB(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_inEB(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_y_cpu_core(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_numvec(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_XLEN(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_YLEN(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_ZLEN(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_ovlp(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_xblock(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_yblock(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_zblock(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_current_2_scmc_set_parameter_num_ele(
    cuda_merge_current_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_init(cuda_pscmc_env *pe,
                                   cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr);
void cuda_Yee_FDTD_Div_FWD_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Div_FWD_4th_get_xlen();
int cuda_Yee_FDTD_Div_FWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr);
int cuda_Yee_FDTD_Div_FWD_4th_exec(cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_init(cuda_pscmc_env *pe,
                               cuda_Yee_FDTD_Div_FWD_struct *kerstr);
void cuda_Yee_FDTD_Div_FWD_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Div_FWD_get_xlen();
int cuda_Yee_FDTD_Div_FWD_get_num_compute_units(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr);
int cuda_Yee_FDTD_Div_FWD_exec(cuda_Yee_FDTD_Div_FWD_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_FWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_init(cuda_pscmc_env *pe,
                                   cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr);
void cuda_Yee_FDTD_Div_BWD_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Div_BWD_4th_get_xlen();
int cuda_Yee_FDTD_Div_BWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr);
int cuda_Yee_FDTD_Div_BWD_4th_exec(cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_init(cuda_pscmc_env *pe,
                               cuda_Yee_FDTD_Div_BWD_struct *kerstr);
void cuda_Yee_FDTD_Div_BWD_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Div_BWD_get_xlen();
int cuda_Yee_FDTD_Div_BWD_get_num_compute_units(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr);
int cuda_Yee_FDTD_Div_BWD_exec(cuda_Yee_FDTD_Div_BWD_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Div_BWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Div_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr);
void cuda_Yee_FDTD_Curl_FWD_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_FWD_4th_get_xlen();
int cuda_Yee_FDTD_Curl_FWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr);
int cuda_Yee_FDTD_Curl_FWD_4th_exec(cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Curl_FWD_struct *kerstr);
void cuda_Yee_FDTD_Curl_FWD_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_FWD_get_xlen();
int cuda_Yee_FDTD_Curl_FWD_get_num_compute_units(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr);
int cuda_Yee_FDTD_Curl_FWD_exec(cuda_Yee_FDTD_Curl_FWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_FWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr);
void cuda_Yee_FDTD_Curl_BWD_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_BWD_4th_get_xlen();
int cuda_Yee_FDTD_Curl_BWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr);
int cuda_Yee_FDTD_Curl_BWD_4th_exec(cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Curl_BWD_struct *kerstr);
void cuda_Yee_FDTD_Curl_BWD_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_BWD_get_xlen();
int cuda_Yee_FDTD_Curl_BWD_get_num_compute_units(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr);
int cuda_Yee_FDTD_Curl_BWD_exec(cuda_Yee_FDTD_Curl_BWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_BWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr);
void cuda_Yee_FDTD_Grad_FWD_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Grad_FWD_4th_get_xlen();
int cuda_Yee_FDTD_Grad_FWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr);
int cuda_Yee_FDTD_Grad_FWD_4th_exec(cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_FWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Grad_FWD_struct *kerstr);
void cuda_Yee_FDTD_Grad_FWD_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Grad_FWD_get_xlen();
int cuda_Yee_FDTD_Grad_FWD_get_num_compute_units(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr);
int cuda_Yee_FDTD_Grad_FWD_exec(cuda_Yee_FDTD_Grad_FWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_FWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_FWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_init(cuda_pscmc_env *pe,
                                    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr);
void cuda_Yee_FDTD_Grad_BWD_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Grad_BWD_4th_get_xlen();
int cuda_Yee_FDTD_Grad_BWD_4th_get_num_compute_units(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr);
int cuda_Yee_FDTD_Grad_BWD_4th_exec(cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_BWD_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_init(cuda_pscmc_env *pe,
                                cuda_Yee_FDTD_Grad_BWD_struct *kerstr);
void cuda_Yee_FDTD_Grad_BWD_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Grad_BWD_get_xlen();
int cuda_Yee_FDTD_Grad_BWD_get_num_compute_units(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr);
int cuda_Yee_FDTD_Grad_BWD_exec(cuda_Yee_FDTD_Grad_BWD_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Grad_BWD_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Grad_BWD_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_init(cuda_pscmc_env *pe,
                                  cuda_Yee_FDTD_Curl_B_4th_struct *kerstr);
void cuda_Yee_FDTD_Curl_B_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_B_4th_get_xlen();
int cuda_Yee_FDTD_Curl_B_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr);
int cuda_Yee_FDTD_Curl_B_4th_exec(cuda_Yee_FDTD_Curl_B_4th_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_B_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_init(cuda_pscmc_env *pe,
                              cuda_Yee_FDTD_Curl_B_struct *kerstr);
void cuda_Yee_FDTD_Curl_B_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_B_get_xlen();
int cuda_Yee_FDTD_Curl_B_get_num_compute_units(
    cuda_Yee_FDTD_Curl_B_struct *kerstr);
int cuda_Yee_FDTD_Curl_B_exec(cuda_Yee_FDTD_Curl_B_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_B_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_B_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_init(cuda_pscmc_env *pe,
                                  cuda_Yee_FDTD_Curl_E_4th_struct *kerstr);
void cuda_Yee_FDTD_Curl_E_4th_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_E_4th_get_xlen();
int cuda_Yee_FDTD_Curl_E_4th_get_num_compute_units(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr);
int cuda_Yee_FDTD_Curl_E_4th_exec(cuda_Yee_FDTD_Curl_E_4th_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_4th_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_E_4th_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_init(cuda_pscmc_env *pe,
                              cuda_Yee_FDTD_Curl_E_struct *kerstr);
void cuda_Yee_FDTD_Curl_E_get_struct_len(size_t *len);
int cuda_Yee_FDTD_Curl_E_get_xlen();
int cuda_Yee_FDTD_Curl_E_get_num_compute_units(
    cuda_Yee_FDTD_Curl_E_struct *kerstr);
int cuda_Yee_FDTD_Curl_E_exec(cuda_Yee_FDTD_Curl_E_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_Curl_E_scmc_set_parameter_DT(
    cuda_Yee_FDTD_Curl_E_struct *kerstr, cuda_pscmc_mem *pm);

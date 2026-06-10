#include "pubdefs.h"

int c_Yee_FDTD_W04_2_init(c_pscmc_env *pe, c_Yee_FDTD_W04_2_struct *kerstr);
void c_Yee_FDTD_W04_2_get_struct_len(size_t *len);
int c_Yee_FDTD_W04_2_get_xlen();
int c_Yee_FDTD_W04_2_get_num_compute_units(c_Yee_FDTD_W04_2_struct *kerstr);
int c_Yee_FDTD_W04_2_exec(c_Yee_FDTD_W04_2_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int c_Yee_FDTD_W04_2_scmc_set_parameter_outEB(c_Yee_FDTD_W04_2_struct *kerstr,
                                              c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_inEB(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_y_cpu_core(
    c_Yee_FDTD_W04_2_struct *kerstr, c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_numvec(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_XLEN(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_YLEN(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_ZLEN(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_ovlp(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_xblock(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_yblock(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_zblock(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_num_ele(c_Yee_FDTD_W04_2_struct *kerstr,
                                                c_pscmc_mem *pm);
int c_Yee_FDTD_W04_2_scmc_set_parameter_DT(c_Yee_FDTD_W04_2_struct *kerstr,
                                           c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_init(c_pscmc_env *pe, c_Yee_FDTD_W04_1_struct *kerstr);
void c_Yee_FDTD_W04_1_get_struct_len(size_t *len);
int c_Yee_FDTD_W04_1_get_xlen();
int c_Yee_FDTD_W04_1_get_num_compute_units(c_Yee_FDTD_W04_1_struct *kerstr);
int c_Yee_FDTD_W04_1_exec(c_Yee_FDTD_W04_1_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int c_Yee_FDTD_W04_1_scmc_set_parameter_outEB(c_Yee_FDTD_W04_1_struct *kerstr,
                                              c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_inEB(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_y_cpu_core(
    c_Yee_FDTD_W04_1_struct *kerstr, c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_numvec(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_XLEN(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_YLEN(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_ZLEN(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_ovlp(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_xblock(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_yblock(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_zblock(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_num_ele(c_Yee_FDTD_W04_1_struct *kerstr,
                                                c_pscmc_mem *pm);
int c_Yee_FDTD_W04_1_scmc_set_parameter_DT(c_Yee_FDTD_W04_1_struct *kerstr,
                                           c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_init(c_pscmc_env *pe, c_Yee_FDTD_W04_0_struct *kerstr);
void c_Yee_FDTD_W04_0_get_struct_len(size_t *len);
int c_Yee_FDTD_W04_0_get_xlen();
int c_Yee_FDTD_W04_0_get_num_compute_units(c_Yee_FDTD_W04_0_struct *kerstr);
int c_Yee_FDTD_W04_0_exec(c_Yee_FDTD_W04_0_struct *kerstr,
                          long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int c_Yee_FDTD_W04_0_scmc_set_parameter_outEB(c_Yee_FDTD_W04_0_struct *kerstr,
                                              c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_inEB(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_y_cpu_core(
    c_Yee_FDTD_W04_0_struct *kerstr, c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_numvec(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_XLEN(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_YLEN(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_ZLEN(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_ovlp(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_xblock(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_yblock(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_zblock(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_num_ele(c_Yee_FDTD_W04_0_struct *kerstr,
                                                c_pscmc_mem *pm);
int c_Yee_FDTD_W04_0_scmc_set_parameter_DT(c_Yee_FDTD_W04_0_struct *kerstr,
                                           c_pscmc_mem *pm);

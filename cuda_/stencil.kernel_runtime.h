#include "pubdefs.h"

int cuda_Yee_FDTD_W04_2_init(cuda_pscmc_env *pe,
                             cuda_Yee_FDTD_W04_2_struct *kerstr);
void cuda_Yee_FDTD_W04_2_get_struct_len(size_t *len);
int cuda_Yee_FDTD_W04_2_get_xlen();
int cuda_Yee_FDTD_W04_2_get_num_compute_units(
    cuda_Yee_FDTD_W04_2_struct *kerstr);
int cuda_Yee_FDTD_W04_2_exec(cuda_Yee_FDTD_W04_2_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_2_scmc_set_parameter_DT(
    cuda_Yee_FDTD_W04_2_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_init(cuda_pscmc_env *pe,
                             cuda_Yee_FDTD_W04_1_struct *kerstr);
void cuda_Yee_FDTD_W04_1_get_struct_len(size_t *len);
int cuda_Yee_FDTD_W04_1_get_xlen();
int cuda_Yee_FDTD_W04_1_get_num_compute_units(
    cuda_Yee_FDTD_W04_1_struct *kerstr);
int cuda_Yee_FDTD_W04_1_exec(cuda_Yee_FDTD_W04_1_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_1_scmc_set_parameter_DT(
    cuda_Yee_FDTD_W04_1_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_init(cuda_pscmc_env *pe,
                             cuda_Yee_FDTD_W04_0_struct *kerstr);
void cuda_Yee_FDTD_W04_0_get_struct_len(size_t *len);
int cuda_Yee_FDTD_W04_0_get_xlen();
int cuda_Yee_FDTD_W04_0_get_num_compute_units(
    cuda_Yee_FDTD_W04_0_struct *kerstr);
int cuda_Yee_FDTD_W04_0_exec(cuda_Yee_FDTD_W04_0_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_outEB(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_inEB(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_y_cpu_core(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_numvec(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_XLEN(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_YLEN(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_ZLEN(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_ovlp(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_xblock(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_yblock(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_zblock(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_num_ele(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_Yee_FDTD_W04_0_scmc_set_parameter_DT(
    cuda_Yee_FDTD_W04_0_struct *kerstr, cuda_pscmc_mem *pm);

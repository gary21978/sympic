#include "basic.h"
#ifdef __cplusplus
extern "C" {
#endif
int mapu_blas_axpy_scmc_set_parameter_x(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_y(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_blas_axpy_scmc_set_parameter_xblock(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_yblock(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_zblock(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_num_ele(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_XLEN(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_YLEN(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_ZLEN(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_ovlp(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_a(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_y_cpu_core(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_scmc_set_parameter_numvec(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_axpy_exec(mapu_blas_axpy_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen);

int mapu_blas_yisax_exec(mapu_blas_yisax_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_blas_yisax_scmc_set_parameter_y(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_x(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_a(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_y_cpu_core(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_numvec(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_XLEN(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_YLEN(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_ZLEN(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_ovlp(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_xblock(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_yblock(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_zblock(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_scmc_set_parameter_num_ele(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_blas_yisax_enlarge_exec(mapu_blas_yisax_enlarge_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_blas_yisax_enlarge_scmc_set_parameter_y(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_x(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_a(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_numvec(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_XLEN(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_YLEN(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_ZLEN(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_ovlp(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_xblock(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_yblock(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_zblock(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yisax_enlarge_scmc_set_parameter_num_ele(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_blas_yiszero_synced_exec(mapu_blas_yiszero_synced_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_blas_yiszero_synced_scmc_set_parameter_y(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_numvec(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_XLEN(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_YLEN(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_ZLEN(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_ovlp(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_xblock(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_yblock(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_zblock(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_synced_scmc_set_parameter_num_ele(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_blas_yiszero_exec(mapu_blas_yiszero_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int mapu_blas_yiszero_scmc_set_parameter_y(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_y_cpu_core(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_numvec(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_XLEN(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_YLEN(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_ZLEN(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_ovlp(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_xblock(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_yblock(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_zblock(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_blas_yiszero_scmc_set_parameter_num_ele(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm);
#ifdef __cplusplus
} /* extern "C" */
#endif
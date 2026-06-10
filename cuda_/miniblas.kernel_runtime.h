#include "pubdefs.h"

int cuda_blas_axpby_enlarge_init(cuda_pscmc_env *pe,
                                 cuda_blas_axpby_enlarge_struct *kerstr);
void cuda_blas_axpby_enlarge_get_struct_len(size_t *len);
int cuda_blas_axpby_enlarge_get_xlen();
int cuda_blas_axpby_enlarge_get_num_compute_units(
    cuda_blas_axpby_enlarge_struct *kerstr);
int cuda_blas_axpby_enlarge_exec(cuda_blas_axpby_enlarge_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_blas_axpby_enlarge_scmc_set_parameter_y(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_x(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_a(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_b(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_numvec(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_XLEN(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_YLEN(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_ZLEN(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_ovlp(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_xblock(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_yblock(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_zblock(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_enlarge_scmc_set_parameter_num_ele(
    cuda_blas_axpby_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_init(cuda_pscmc_env *pe,
                                cuda_blas_axpby_shrink_struct *kerstr);
void cuda_blas_axpby_shrink_get_struct_len(size_t *len);
int cuda_blas_axpby_shrink_get_xlen();
int cuda_blas_axpby_shrink_get_num_compute_units(
    cuda_blas_axpby_shrink_struct *kerstr);
int cuda_blas_axpby_shrink_exec(cuda_blas_axpby_shrink_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_blas_axpby_shrink_scmc_set_parameter_y(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_x(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_a(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_b(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_numvec(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_XLEN(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_YLEN(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_ZLEN(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_ovlp(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_xblock(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_yblock(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_zblock(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_shrink_scmc_set_parameter_num_ele(
    cuda_blas_axpby_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_init(cuda_pscmc_env *pe,
                                cuda_blas_axpy_enlarge_struct *kerstr);
void cuda_blas_axpy_enlarge_get_struct_len(size_t *len);
int cuda_blas_axpy_enlarge_get_xlen();
int cuda_blas_axpy_enlarge_get_num_compute_units(
    cuda_blas_axpy_enlarge_struct *kerstr);
int cuda_blas_axpy_enlarge_exec(cuda_blas_axpy_enlarge_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_blas_axpy_enlarge_scmc_set_parameter_y(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_x(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_a(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_numvec(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_XLEN(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_YLEN(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_ZLEN(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_ovlp(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_xblock(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_yblock(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_zblock(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_enlarge_scmc_set_parameter_num_ele(
    cuda_blas_axpy_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_init(cuda_pscmc_env *pe,
                               cuda_blas_axpy_shrink_struct *kerstr);
void cuda_blas_axpy_shrink_get_struct_len(size_t *len);
int cuda_blas_axpy_shrink_get_xlen();
int cuda_blas_axpy_shrink_get_num_compute_units(
    cuda_blas_axpy_shrink_struct *kerstr);
int cuda_blas_axpy_shrink_exec(cuda_blas_axpy_shrink_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen);
int cuda_blas_axpy_shrink_scmc_set_parameter_y(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_x(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_a(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_numvec(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_XLEN(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_YLEN(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_ZLEN(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_ovlp(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_xblock(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_yblock(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_zblock(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_shrink_scmc_set_parameter_num_ele(
    cuda_blas_axpy_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_init(cuda_pscmc_env *pe,
                                 cuda_blas_yisax_enlarge_struct *kerstr);
void cuda_blas_yisax_enlarge_get_struct_len(size_t *len);
int cuda_blas_yisax_enlarge_get_xlen();
int cuda_blas_yisax_enlarge_get_num_compute_units(
    cuda_blas_yisax_enlarge_struct *kerstr);
int cuda_blas_yisax_enlarge_exec(cuda_blas_yisax_enlarge_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_blas_yisax_enlarge_scmc_set_parameter_y(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_x(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_a(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_numvec(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_XLEN(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_YLEN(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_ZLEN(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_ovlp(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_xblock(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_yblock(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_zblock(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_enlarge_scmc_set_parameter_num_ele(
    cuda_blas_yisax_enlarge_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_init(cuda_pscmc_env *pe,
                                cuda_blas_yisax_shrink_struct *kerstr);
void cuda_blas_yisax_shrink_get_struct_len(size_t *len);
int cuda_blas_yisax_shrink_get_xlen();
int cuda_blas_yisax_shrink_get_num_compute_units(
    cuda_blas_yisax_shrink_struct *kerstr);
int cuda_blas_yisax_shrink_exec(cuda_blas_yisax_shrink_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen);
int cuda_blas_yisax_shrink_scmc_set_parameter_y(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_x(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_a(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_numvec(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_XLEN(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_YLEN(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_ZLEN(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_ovlp(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_xblock(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_yblock(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_zblock(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_shrink_scmc_set_parameter_num_ele(
    cuda_blas_yisax_shrink_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_init(cuda_pscmc_env *pe,
                                  cuda_blas_sum_full_block_struct *kerstr);
void cuda_blas_sum_full_block_get_struct_len(size_t *len);
int cuda_blas_sum_full_block_get_xlen();
int cuda_blas_sum_full_block_get_num_compute_units(
    cuda_blas_sum_full_block_struct *kerstr);
int cuda_blas_sum_full_block_exec(cuda_blas_sum_full_block_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_blas_sum_full_block_scmc_set_parameter_y(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_rdcd_sum(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_numvec(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_XLEN(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_YLEN(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_ovlp(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_xblock(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_yblock(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_zblock(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_full_block_scmc_set_parameter_num_ele(
    cuda_blas_sum_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_sum_init(cuda_pscmc_env *pe, cuda_blas_sum_struct *kerstr);
void cuda_blas_sum_get_struct_len(size_t *len);
int cuda_blas_sum_get_xlen();
int cuda_blas_sum_get_num_compute_units(cuda_blas_sum_struct *kerstr);
int cuda_blas_sum_exec(cuda_blas_sum_struct *kerstr, long scmc_internal_g_xlen,
                       long scmc_internal_g_ylen);
int cuda_blas_sum_scmc_set_parameter_y(cuda_blas_sum_struct *kerstr,
                                       cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_rdcd_sum(cuda_blas_sum_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_y_cpu_core(cuda_blas_sum_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_numvec(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_XLEN(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_YLEN(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_ZLEN(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_ovlp(cuda_blas_sum_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_xblock(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_yblock(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_zblock(cuda_blas_sum_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_sum_scmc_set_parameter_num_ele(cuda_blas_sum_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_init(cuda_pscmc_env *pe,
                                  cuda_blas_dot_full_block_struct *kerstr);
void cuda_blas_dot_full_block_get_struct_len(size_t *len);
int cuda_blas_dot_full_block_get_xlen();
int cuda_blas_dot_full_block_get_num_compute_units(
    cuda_blas_dot_full_block_struct *kerstr);
int cuda_blas_dot_full_block_exec(cuda_blas_dot_full_block_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_blas_dot_full_block_scmc_set_parameter_y(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_x(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_rdcd_sum(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_numvec(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_XLEN(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_YLEN(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_ovlp(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_xblock(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_yblock(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_zblock(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_full_block_scmc_set_parameter_num_ele(
    cuda_blas_dot_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_dot_init(cuda_pscmc_env *pe, cuda_blas_dot_struct *kerstr);
void cuda_blas_dot_get_struct_len(size_t *len);
int cuda_blas_dot_get_xlen();
int cuda_blas_dot_get_num_compute_units(cuda_blas_dot_struct *kerstr);
int cuda_blas_dot_exec(cuda_blas_dot_struct *kerstr, long scmc_internal_g_xlen,
                       long scmc_internal_g_ylen);
int cuda_blas_dot_scmc_set_parameter_y(cuda_blas_dot_struct *kerstr,
                                       cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_x(cuda_blas_dot_struct *kerstr,
                                       cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_rdcd_sum(cuda_blas_dot_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_y_cpu_core(cuda_blas_dot_struct *kerstr,
                                                cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_numvec(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_XLEN(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_YLEN(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_ZLEN(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_ovlp(cuda_blas_dot_struct *kerstr,
                                          cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_xblock(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_yblock(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_zblock(cuda_blas_dot_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_dot_scmc_set_parameter_num_ele(cuda_blas_dot_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_findmax_full_block_struct *kerstr);
void cuda_blas_findmax_full_block_get_struct_len(size_t *len);
int cuda_blas_findmax_full_block_get_xlen();
int cuda_blas_findmax_full_block_get_num_compute_units(
    cuda_blas_findmax_full_block_struct *kerstr);
int cuda_blas_findmax_full_block_exec(
    cuda_blas_findmax_full_block_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_blas_findmax_full_block_scmc_set_parameter_y(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_rdcd_max(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_numvec(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_XLEN(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_YLEN(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_ovlp(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_xblock(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_yblock(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_zblock(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_full_block_scmc_set_parameter_num_ele(
    cuda_blas_findmax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_init(cuda_pscmc_env *pe,
                           cuda_blas_findmax_struct *kerstr);
void cuda_blas_findmax_get_struct_len(size_t *len);
int cuda_blas_findmax_get_xlen();
int cuda_blas_findmax_get_num_compute_units(cuda_blas_findmax_struct *kerstr);
int cuda_blas_findmax_exec(cuda_blas_findmax_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_blas_findmax_scmc_set_parameter_y(cuda_blas_findmax_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_rdcd_max(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_y_cpu_core(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_numvec(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_XLEN(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_YLEN(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_ZLEN(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_ovlp(cuda_blas_findmax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_xblock(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_yblock(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_zblock(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_findmax_scmc_set_parameter_num_ele(
    cuda_blas_findmax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_init(cuda_pscmc_env *pe,
                                    cuda_blas_mulxy_full_block_struct *kerstr);
void cuda_blas_mulxy_full_block_get_struct_len(size_t *len);
int cuda_blas_mulxy_full_block_get_xlen();
int cuda_blas_mulxy_full_block_get_num_compute_units(
    cuda_blas_mulxy_full_block_struct *kerstr);
int cuda_blas_mulxy_full_block_exec(cuda_blas_mulxy_full_block_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_blas_mulxy_full_block_scmc_set_parameter_y(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_x(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_numvec(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_XLEN(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_YLEN(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_ovlp(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_xblock(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_yblock(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_zblock(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_full_block_scmc_set_parameter_num_ele(
    cuda_blas_mulxy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_init(cuda_pscmc_env *pe, cuda_blas_mulxy_struct *kerstr);
void cuda_blas_mulxy_get_struct_len(size_t *len);
int cuda_blas_mulxy_get_xlen();
int cuda_blas_mulxy_get_num_compute_units(cuda_blas_mulxy_struct *kerstr);
int cuda_blas_mulxy_exec(cuda_blas_mulxy_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_blas_mulxy_scmc_set_parameter_y(cuda_blas_mulxy_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_x(cuda_blas_mulxy_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_y_cpu_core(
    cuda_blas_mulxy_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_numvec(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_XLEN(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_YLEN(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_ZLEN(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_ovlp(cuda_blas_mulxy_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_xblock(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_yblock(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_zblock(cuda_blas_mulxy_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_mulxy_scmc_set_parameter_num_ele(cuda_blas_mulxy_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_init(cuda_pscmc_env *pe,
                                    cuda_blas_axpby_full_block_struct *kerstr);
void cuda_blas_axpby_full_block_get_struct_len(size_t *len);
int cuda_blas_axpby_full_block_get_xlen();
int cuda_blas_axpby_full_block_get_num_compute_units(
    cuda_blas_axpby_full_block_struct *kerstr);
int cuda_blas_axpby_full_block_exec(cuda_blas_axpby_full_block_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_blas_axpby_full_block_scmc_set_parameter_y(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_x(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_a(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_b(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_numvec(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_XLEN(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_YLEN(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_ovlp(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_xblock(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_yblock(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_zblock(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_full_block_scmc_set_parameter_num_ele(
    cuda_blas_axpby_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_init(cuda_pscmc_env *pe, cuda_blas_axpby_struct *kerstr);
void cuda_blas_axpby_get_struct_len(size_t *len);
int cuda_blas_axpby_get_xlen();
int cuda_blas_axpby_get_num_compute_units(cuda_blas_axpby_struct *kerstr);
int cuda_blas_axpby_exec(cuda_blas_axpby_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_blas_axpby_scmc_set_parameter_y(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_x(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_a(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_b(cuda_blas_axpby_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpby_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_numvec(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_XLEN(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_YLEN(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_ZLEN(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_ovlp(cuda_blas_axpby_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_xblock(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_yblock(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_zblock(cuda_blas_axpby_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_axpby_scmc_set_parameter_num_ele(cuda_blas_axpby_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_init(cuda_pscmc_env *pe,
                                   cuda_blas_axpy_full_block_struct *kerstr);
void cuda_blas_axpy_full_block_get_struct_len(size_t *len);
int cuda_blas_axpy_full_block_get_xlen();
int cuda_blas_axpy_full_block_get_num_compute_units(
    cuda_blas_axpy_full_block_struct *kerstr);
int cuda_blas_axpy_full_block_exec(cuda_blas_axpy_full_block_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen);
int cuda_blas_axpy_full_block_scmc_set_parameter_y(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_x(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_a(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_numvec(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_XLEN(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_YLEN(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_ovlp(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_xblock(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_yblock(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_zblock(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_full_block_scmc_set_parameter_num_ele(
    cuda_blas_axpy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_axpy_init(cuda_pscmc_env *pe, cuda_blas_axpy_struct *kerstr);
void cuda_blas_axpy_get_struct_len(size_t *len);
int cuda_blas_axpy_get_xlen();
int cuda_blas_axpy_get_num_compute_units(cuda_blas_axpy_struct *kerstr);
int cuda_blas_axpy_exec(cuda_blas_axpy_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_blas_axpy_scmc_set_parameter_y(cuda_blas_axpy_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_x(cuda_blas_axpy_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_a(cuda_blas_axpy_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_y_cpu_core(cuda_blas_axpy_struct *kerstr,
                                                 cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_numvec(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_XLEN(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_YLEN(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_ZLEN(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_ovlp(cuda_blas_axpy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_xblock(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_yblock(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_zblock(cuda_blas_axpy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_axpy_scmc_set_parameter_num_ele(cuda_blas_axpy_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_init(cuda_pscmc_env *pe,
                                    cuda_blas_yisax_full_block_struct *kerstr);
void cuda_blas_yisax_full_block_get_struct_len(size_t *len);
int cuda_blas_yisax_full_block_get_xlen();
int cuda_blas_yisax_full_block_get_num_compute_units(
    cuda_blas_yisax_full_block_struct *kerstr);
int cuda_blas_yisax_full_block_exec(cuda_blas_yisax_full_block_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_blas_yisax_full_block_scmc_set_parameter_y(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_x(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_a(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_numvec(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_XLEN(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_YLEN(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_ovlp(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_xblock(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_yblock(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_zblock(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_full_block_scmc_set_parameter_num_ele(
    cuda_blas_yisax_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_init(cuda_pscmc_env *pe, cuda_blas_yisax_struct *kerstr);
void cuda_blas_yisax_get_struct_len(size_t *len);
int cuda_blas_yisax_get_xlen();
int cuda_blas_yisax_get_num_compute_units(cuda_blas_yisax_struct *kerstr);
int cuda_blas_yisax_exec(cuda_blas_yisax_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_blas_yisax_scmc_set_parameter_y(cuda_blas_yisax_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_x(cuda_blas_yisax_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_a(cuda_blas_yisax_struct *kerstr,
                                         cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisax_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_numvec(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_XLEN(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_YLEN(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_ZLEN(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_ovlp(cuda_blas_yisax_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_xblock(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_yblock(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_zblock(cuda_blas_yisax_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yisax_scmc_set_parameter_num_ele(cuda_blas_yisax_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_init(cuda_pscmc_env *pe,
                                   cuda_blas_invy_full_block_struct *kerstr);
void cuda_blas_invy_full_block_get_struct_len(size_t *len);
int cuda_blas_invy_full_block_get_xlen();
int cuda_blas_invy_full_block_get_num_compute_units(
    cuda_blas_invy_full_block_struct *kerstr);
int cuda_blas_invy_full_block_exec(cuda_blas_invy_full_block_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen);
int cuda_blas_invy_full_block_scmc_set_parameter_y(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_numvec(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_XLEN(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_YLEN(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_ovlp(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_xblock(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_yblock(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_zblock(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_full_block_scmc_set_parameter_num_ele(
    cuda_blas_invy_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_invy_init(cuda_pscmc_env *pe, cuda_blas_invy_struct *kerstr);
void cuda_blas_invy_get_struct_len(size_t *len);
int cuda_blas_invy_get_xlen();
int cuda_blas_invy_get_num_compute_units(cuda_blas_invy_struct *kerstr);
int cuda_blas_invy_exec(cuda_blas_invy_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_blas_invy_scmc_set_parameter_y(cuda_blas_invy_struct *kerstr,
                                        cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_y_cpu_core(cuda_blas_invy_struct *kerstr,
                                                 cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_numvec(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_XLEN(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_YLEN(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_ZLEN(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_ovlp(cuda_blas_invy_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_xblock(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_yblock(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_zblock(cuda_blas_invy_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_blas_invy_scmc_set_parameter_num_ele(cuda_blas_invy_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_get_ITG_Potential_full_block_struct *kerstr);
void cuda_blas_get_ITG_Potential_full_block_get_struct_len(size_t *len);
int cuda_blas_get_ITG_Potential_full_block_get_xlen();
int cuda_blas_get_ITG_Potential_full_block_get_num_compute_units(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr);
int cuda_blas_get_ITG_Potential_full_block_exec(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_y(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_x(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_u(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_minus_over_q_e(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_numvec(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_XLEN(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_YLEN(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_ovlp(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_xblock(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_yblock(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_zblock(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_full_block_scmc_set_parameter_num_ele(
    cuda_blas_get_ITG_Potential_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_init(
    cuda_pscmc_env *pe, cuda_blas_get_ITG_Potential_struct *kerstr);
void cuda_blas_get_ITG_Potential_get_struct_len(size_t *len);
int cuda_blas_get_ITG_Potential_get_xlen();
int cuda_blas_get_ITG_Potential_get_num_compute_units(
    cuda_blas_get_ITG_Potential_struct *kerstr);
int cuda_blas_get_ITG_Potential_exec(cuda_blas_get_ITG_Potential_struct *kerstr,
                                     long scmc_internal_g_xlen,
                                     long scmc_internal_g_ylen);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_y(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_x(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_u(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_minus_over_q_e(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_y_cpu_core(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_numvec(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_XLEN(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_YLEN(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_ZLEN(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_ovlp(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_xblock(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_yblock(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_zblock(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_get_ITG_Potential_scmc_set_parameter_num_ele(
    cuda_blas_get_ITG_Potential_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_yisconst_full_block_struct *kerstr);
void cuda_blas_yisconst_full_block_get_struct_len(size_t *len);
int cuda_blas_yisconst_full_block_get_xlen();
int cuda_blas_yisconst_full_block_get_num_compute_units(
    cuda_blas_yisconst_full_block_struct *kerstr);
int cuda_blas_yisconst_full_block_exec(
    cuda_blas_yisconst_full_block_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_blas_yisconst_full_block_scmc_set_parameter_y(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_a(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_numvec(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_XLEN(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_YLEN(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_ovlp(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_xblock(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_yblock(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_zblock(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_full_block_scmc_set_parameter_num_ele(
    cuda_blas_yisconst_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_init(cuda_pscmc_env *pe,
                            cuda_blas_yisconst_struct *kerstr);
void cuda_blas_yisconst_get_struct_len(size_t *len);
int cuda_blas_yisconst_get_xlen();
int cuda_blas_yisconst_get_num_compute_units(cuda_blas_yisconst_struct *kerstr);
int cuda_blas_yisconst_exec(cuda_blas_yisconst_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen);
int cuda_blas_yisconst_scmc_set_parameter_y(cuda_blas_yisconst_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_a(cuda_blas_yisconst_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_y_cpu_core(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_numvec(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_XLEN(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_YLEN(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_ZLEN(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_ovlp(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_xblock(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_yblock(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_zblock(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yisconst_scmc_set_parameter_num_ele(
    cuda_blas_yisconst_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_init(
    cuda_pscmc_env *pe, cuda_blas_yiszero_full_block_struct *kerstr);
void cuda_blas_yiszero_full_block_get_struct_len(size_t *len);
int cuda_blas_yiszero_full_block_get_xlen();
int cuda_blas_yiszero_full_block_get_num_compute_units(
    cuda_blas_yiszero_full_block_struct *kerstr);
int cuda_blas_yiszero_full_block_exec(
    cuda_blas_yiszero_full_block_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_blas_yiszero_full_block_scmc_set_parameter_y(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_y_cpu_core(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_numvec(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_XLEN(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_YLEN(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_ZLEN(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_ovlp(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_xblock(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_yblock(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_zblock(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_full_block_scmc_set_parameter_num_ele(
    cuda_blas_yiszero_full_block_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_init(cuda_pscmc_env *pe,
                           cuda_blas_yiszero_struct *kerstr);
void cuda_blas_yiszero_get_struct_len(size_t *len);
int cuda_blas_yiszero_get_xlen();
int cuda_blas_yiszero_get_num_compute_units(cuda_blas_yiszero_struct *kerstr);
int cuda_blas_yiszero_exec(cuda_blas_yiszero_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_blas_yiszero_scmc_set_parameter_y(cuda_blas_yiszero_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_y_cpu_core(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_numvec(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_XLEN(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_YLEN(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_ZLEN(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_ovlp(cuda_blas_yiszero_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_xblock(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_yblock(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_zblock(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_scmc_set_parameter_num_ele(
    cuda_blas_yiszero_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_init(cuda_pscmc_env *pe,
                                 cuda_blas_mulxy_numele3_struct *kerstr);
void cuda_blas_mulxy_numele3_get_struct_len(size_t *len);
int cuda_blas_mulxy_numele3_get_xlen();
int cuda_blas_mulxy_numele3_get_num_compute_units(
    cuda_blas_mulxy_numele3_struct *kerstr);
int cuda_blas_mulxy_numele3_exec(cuda_blas_mulxy_numele3_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_blas_mulxy_numele3_scmc_set_parameter_y(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_x(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_y_cpu_core(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_numvec(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_XLEN(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_YLEN(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_ZLEN(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_ovlp(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_xblock(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_yblock(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_zblock(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_mulxy_numele3_scmc_set_parameter_num_ele(
    cuda_blas_mulxy_numele3_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_init(cuda_pscmc_env *pe,
                                  cuda_blas_yiszero_synced_struct *kerstr);
void cuda_blas_yiszero_synced_get_struct_len(size_t *len);
int cuda_blas_yiszero_synced_get_xlen();
int cuda_blas_yiszero_synced_get_num_compute_units(
    cuda_blas_yiszero_synced_struct *kerstr);
int cuda_blas_yiszero_synced_exec(cuda_blas_yiszero_synced_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_blas_yiszero_synced_scmc_set_parameter_y(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_numvec(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_XLEN(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_YLEN(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_ZLEN(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_ovlp(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_xblock(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_yblock(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_zblock(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_blas_yiszero_synced_scmc_set_parameter_num_ele(
    cuda_blas_yiszero_synced_struct *kerstr, cuda_pscmc_mem *pm);

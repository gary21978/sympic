#include "pubdefs.h"

int cuda_dump_ene_num_init(cuda_pscmc_env *pe,
                           cuda_dump_ene_num_struct *kerstr);
void cuda_dump_ene_num_get_struct_len(size_t *len);
int cuda_dump_ene_num_get_xlen();
int cuda_dump_ene_num_get_num_compute_units(cuda_dump_ene_num_struct *kerstr);
int cuda_dump_ene_num_exec(cuda_dump_ene_num_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_dump_ene_num_scmc_set_parameter_inoutput(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_xyzw(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_cu_cache(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_cu_xyzw(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_fieldE(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_fieldB(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_FoutJ(cuda_dump_ene_num_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_FoutEN(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_XLEN(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_YLEN(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_ZLEN(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_ovlp(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_numvec(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_num_ele(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_grid_cache_len(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_cu_cache_length(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_Mass(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_Charge(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_SPEC(cuda_dump_ene_num_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_NUM_SPEC(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_DELTA_X(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_DELTA_Y(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_DELTA_Z(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_dump_ene_num_scmc_set_parameter_Deltat(
    cuda_dump_ene_num_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_init(cuda_pscmc_env *pe,
                            cuda_calculate_rho_struct *kerstr);
void cuda_calculate_rho_get_struct_len(size_t *len);
int cuda_calculate_rho_get_xlen();
int cuda_calculate_rho_get_num_compute_units(cuda_calculate_rho_struct *kerstr);
int cuda_calculate_rho_exec(cuda_calculate_rho_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen);
int cuda_calculate_rho_scmc_set_parameter_inoutput(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_xyzw(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_cu_cache(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_cu_xyzw(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_fieldE(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_fieldB(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_FoutJ(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_FoutEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_XLEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_YLEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_ZLEN(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_ovlp(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_numvec(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_num_ele(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_grid_cache_len(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_cu_cache_length(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_Mass(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_Charge(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_SPEC(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_NUM_SPEC(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_DELTA_X(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_DELTA_Y(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_DELTA_Z(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_calculate_rho_scmc_set_parameter_Deltat(
    cuda_calculate_rho_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_init(cuda_pscmc_env *pe,
                                   cuda_krook_collision_test_struct *kerstr);
void cuda_krook_collision_test_get_struct_len(size_t *len);
int cuda_krook_collision_test_get_xlen();
int cuda_krook_collision_test_get_num_compute_units(
    cuda_krook_collision_test_struct *kerstr);
int cuda_krook_collision_test_exec(cuda_krook_collision_test_struct *kerstr,
                                   long scmc_internal_g_xlen,
                                   long scmc_internal_g_ylen);
int cuda_krook_collision_test_scmc_set_parameter_inoutput(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_xyzw(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_cu_cache(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_cu_xyzw(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_fieldE(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_fieldB(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_FoutJ(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_XLEN(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_YLEN(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_ZLEN(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_ovlp(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_numvec(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_num_ele(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_grid_cache_len(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_cu_cache_length(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_Mass0(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_Charge0(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_Deltat(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_test_scmc_set_parameter_mu_freq(
    cuda_krook_collision_test_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_init(
    cuda_pscmc_env *pe, cuda_krook_collision_remove_small_speed_struct *kerstr);
void cuda_krook_collision_remove_small_speed_get_struct_len(size_t *len);
int cuda_krook_collision_remove_small_speed_get_xlen();
int cuda_krook_collision_remove_small_speed_get_num_compute_units(
    cuda_krook_collision_remove_small_speed_struct *kerstr);
int cuda_krook_collision_remove_small_speed_exec(
    cuda_krook_collision_remove_small_speed_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_inoutput(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_xyzw(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_cu_xyzw(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_fieldE(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_fieldB(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_FoutJ(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_XLEN(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_YLEN(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_ZLEN(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_ovlp(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_numvec(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_num_ele(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_grid_cache_len(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_cu_cache_length(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_Mass0(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_Charge0(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_Deltat(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_krook_collision_remove_small_speed_scmc_set_parameter_mu_freq(
    cuda_krook_collision_remove_small_speed_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_boris_yee_init(cuda_pscmc_env *pe, cuda_boris_yee_struct *kerstr);
void cuda_boris_yee_get_struct_len(size_t *len);
int cuda_boris_yee_get_xlen();
int cuda_boris_yee_get_num_compute_units(cuda_boris_yee_struct *kerstr);
int cuda_boris_yee_exec(cuda_boris_yee_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_boris_yee_scmc_set_parameter_inoutput(cuda_boris_yee_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_xyzw(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_cu_cache(cuda_boris_yee_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_cu_xyzw(cuda_boris_yee_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_fieldE(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_fieldB(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_FoutJ(cuda_boris_yee_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_XLEN(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_YLEN(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_ZLEN(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_ovlp(cuda_boris_yee_struct *kerstr,
                                           cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_numvec(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_num_ele(cuda_boris_yee_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_grid_cache_len(
    cuda_boris_yee_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_cu_cache_length(
    cuda_boris_yee_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_Mass0(cuda_boris_yee_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_Charge0(cuda_boris_yee_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_boris_yee_scmc_set_parameter_Deltat(cuda_boris_yee_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_init(
    cuda_pscmc_env *pe, cuda_split_pass_E_particle_vlo_struct *kerstr);
void cuda_split_pass_E_particle_vlo_get_struct_len(size_t *len);
int cuda_split_pass_E_particle_vlo_get_xlen();
int cuda_split_pass_E_particle_vlo_get_num_compute_units(
    cuda_split_pass_E_particle_vlo_struct *kerstr);
int cuda_split_pass_E_particle_vlo_exec(
    cuda_split_pass_E_particle_vlo_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_E_particle_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_init(cuda_pscmc_env *pe,
                                    cuda_split_pass_E_particle_struct *kerstr);
void cuda_split_pass_E_particle_get_struct_len(size_t *len);
int cuda_split_pass_E_particle_get_xlen();
int cuda_split_pass_E_particle_get_num_compute_units(
    cuda_split_pass_E_particle_struct *kerstr);
int cuda_split_pass_E_particle_exec(cuda_split_pass_E_particle_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen);
int cuda_split_pass_E_particle_scmc_set_parameter_inoutput(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_xyzw(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_cu_cache(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_fieldE(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_fieldB(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_FoutJ(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_FoutEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_XLEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_YLEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_ZLEN(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_ovlp(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_numvec(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_num_ele(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_Mass(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_Charge(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_SPEC(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_DELTA_X(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_E_particle_scmc_set_parameter_Deltat(
    cuda_split_pass_E_particle_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_init(
    cuda_pscmc_env *pe,
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr);
void cuda_split_pass_z_vlo_sg2_nopush_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_get_xlen();
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_get_num_compute_units(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_exec(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr);
void cuda_split_pass_z_vlo_sg2_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_z_vlo_sg2_small_grids_get_xlen();
int cuda_split_pass_z_vlo_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr);
int cuda_split_pass_z_vlo_sg2_small_grids_exec(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_vlo_small_grids_struct *kerstr);
void cuda_split_pass_z_vlo_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_z_vlo_small_grids_get_xlen();
int cuda_split_pass_z_vlo_small_grids_get_num_compute_units(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr);
int cuda_split_pass_z_vlo_small_grids_exec(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_sg2_small_grids_struct *kerstr);
void cuda_split_pass_z_sg2_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_z_sg2_small_grids_get_xlen();
int cuda_split_pass_z_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr);
int cuda_split_pass_z_sg2_small_grids_exec(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_small_grids_struct *kerstr);
void cuda_split_pass_z_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_z_small_grids_get_xlen();
int cuda_split_pass_z_small_grids_get_num_compute_units(
    cuda_split_pass_z_small_grids_struct *kerstr);
int cuda_split_pass_z_small_grids_exec(
    cuda_split_pass_z_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_z_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_z_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_init(
    cuda_pscmc_env *pe, cuda_split_pass_z_vlo_nopush_struct *kerstr);
void cuda_split_pass_z_vlo_nopush_get_struct_len(size_t *len);
int cuda_split_pass_z_vlo_nopush_get_xlen();
int cuda_split_pass_z_vlo_nopush_get_num_compute_units(
    cuda_split_pass_z_vlo_nopush_struct *kerstr);
int cuda_split_pass_z_vlo_nopush_exec(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_init(cuda_pscmc_env *pe,
                               cuda_split_pass_z_vlo_struct *kerstr);
void cuda_split_pass_z_vlo_get_struct_len(size_t *len);
int cuda_split_pass_z_vlo_get_xlen();
int cuda_split_pass_z_vlo_get_num_compute_units(
    cuda_split_pass_z_vlo_struct *kerstr);
int cuda_split_pass_z_vlo_exec(cuda_split_pass_z_vlo_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen);
int cuda_split_pass_z_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_z_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_init(cuda_pscmc_env *pe,
                                  cuda_split_pass_z_nopush_struct *kerstr);
void cuda_split_pass_z_nopush_get_struct_len(size_t *len);
int cuda_split_pass_z_nopush_get_xlen();
int cuda_split_pass_z_nopush_get_num_compute_units(
    cuda_split_pass_z_nopush_struct *kerstr);
int cuda_split_pass_z_nopush_exec(cuda_split_pass_z_nopush_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_split_pass_z_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_z_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_init(cuda_pscmc_env *pe,
                           cuda_split_pass_z_struct *kerstr);
void cuda_split_pass_z_get_struct_len(size_t *len);
int cuda_split_pass_z_get_xlen();
int cuda_split_pass_z_get_num_compute_units(cuda_split_pass_z_struct *kerstr);
int cuda_split_pass_z_exec(cuda_split_pass_z_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_split_pass_z_scmc_set_parameter_inoutput(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_xyzw(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_cu_cache(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_fieldE(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_fieldB(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_FoutJ(cuda_split_pass_z_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_FoutEN(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_XLEN(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_YLEN(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_ZLEN(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_ovlp(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_numvec(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_num_ele(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_Mass(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_Charge(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_SPEC(cuda_split_pass_z_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_DELTA_X(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_z_scmc_set_parameter_Deltat(
    cuda_split_pass_z_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_init(
    cuda_pscmc_env *pe,
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr);
void cuda_split_pass_y_vlo_sg2_nopush_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_get_xlen();
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_get_num_compute_units(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_exec(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr);
void cuda_split_pass_y_vlo_sg2_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_y_vlo_sg2_small_grids_get_xlen();
int cuda_split_pass_y_vlo_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr);
int cuda_split_pass_y_vlo_sg2_small_grids_exec(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_vlo_small_grids_struct *kerstr);
void cuda_split_pass_y_vlo_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_y_vlo_small_grids_get_xlen();
int cuda_split_pass_y_vlo_small_grids_get_num_compute_units(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr);
int cuda_split_pass_y_vlo_small_grids_exec(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_sg2_small_grids_struct *kerstr);
void cuda_split_pass_y_sg2_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_y_sg2_small_grids_get_xlen();
int cuda_split_pass_y_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr);
int cuda_split_pass_y_sg2_small_grids_exec(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_small_grids_struct *kerstr);
void cuda_split_pass_y_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_y_small_grids_get_xlen();
int cuda_split_pass_y_small_grids_get_num_compute_units(
    cuda_split_pass_y_small_grids_struct *kerstr);
int cuda_split_pass_y_small_grids_exec(
    cuda_split_pass_y_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_y_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_y_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_init(
    cuda_pscmc_env *pe, cuda_split_pass_y_vlo_nopush_struct *kerstr);
void cuda_split_pass_y_vlo_nopush_get_struct_len(size_t *len);
int cuda_split_pass_y_vlo_nopush_get_xlen();
int cuda_split_pass_y_vlo_nopush_get_num_compute_units(
    cuda_split_pass_y_vlo_nopush_struct *kerstr);
int cuda_split_pass_y_vlo_nopush_exec(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_init(cuda_pscmc_env *pe,
                               cuda_split_pass_y_vlo_struct *kerstr);
void cuda_split_pass_y_vlo_get_struct_len(size_t *len);
int cuda_split_pass_y_vlo_get_xlen();
int cuda_split_pass_y_vlo_get_num_compute_units(
    cuda_split_pass_y_vlo_struct *kerstr);
int cuda_split_pass_y_vlo_exec(cuda_split_pass_y_vlo_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen);
int cuda_split_pass_y_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_y_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_init(cuda_pscmc_env *pe,
                                  cuda_split_pass_y_nopush_struct *kerstr);
void cuda_split_pass_y_nopush_get_struct_len(size_t *len);
int cuda_split_pass_y_nopush_get_xlen();
int cuda_split_pass_y_nopush_get_num_compute_units(
    cuda_split_pass_y_nopush_struct *kerstr);
int cuda_split_pass_y_nopush_exec(cuda_split_pass_y_nopush_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_split_pass_y_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_y_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_init(cuda_pscmc_env *pe,
                           cuda_split_pass_y_struct *kerstr);
void cuda_split_pass_y_get_struct_len(size_t *len);
int cuda_split_pass_y_get_xlen();
int cuda_split_pass_y_get_num_compute_units(cuda_split_pass_y_struct *kerstr);
int cuda_split_pass_y_exec(cuda_split_pass_y_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_split_pass_y_scmc_set_parameter_inoutput(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_xyzw(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_cu_cache(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_fieldE(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_fieldB(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_FoutJ(cuda_split_pass_y_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_FoutEN(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_XLEN(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_YLEN(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_ZLEN(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_ovlp(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_numvec(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_num_ele(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_Mass(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_Charge(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_SPEC(cuda_split_pass_y_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_DELTA_X(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_y_scmc_set_parameter_Deltat(
    cuda_split_pass_y_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_init(
    cuda_pscmc_env *pe,
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr);
void cuda_split_pass_x_vlo_sg2_nopush_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_get_xlen();
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_get_num_compute_units(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_exec(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct *kerstr,
    cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr);
void cuda_split_pass_x_vlo_sg2_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_x_vlo_sg2_small_grids_get_xlen();
int cuda_split_pass_x_vlo_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr);
int cuda_split_pass_x_vlo_sg2_small_grids_exec(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr,
    long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_vlo_small_grids_struct *kerstr);
void cuda_split_pass_x_vlo_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_x_vlo_small_grids_get_xlen();
int cuda_split_pass_x_vlo_small_grids_get_num_compute_units(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr);
int cuda_split_pass_x_vlo_small_grids_exec(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_sg2_small_grids_struct *kerstr);
void cuda_split_pass_x_sg2_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_x_sg2_small_grids_get_xlen();
int cuda_split_pass_x_sg2_small_grids_get_num_compute_units(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr);
int cuda_split_pass_x_sg2_small_grids_exec(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_sg2_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_sg2_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_small_grids_struct *kerstr);
void cuda_split_pass_x_small_grids_get_struct_len(size_t *len);
int cuda_split_pass_x_small_grids_get_xlen();
int cuda_split_pass_x_small_grids_get_num_compute_units(
    cuda_split_pass_x_small_grids_struct *kerstr);
int cuda_split_pass_x_small_grids_exec(
    cuda_split_pass_x_small_grids_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_x_small_grids_scmc_set_parameter_inoutput(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_xyzw(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_fieldE(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_fieldB(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_LFoutJ(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_XLEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_YLEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_ovlp(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_numvec(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_num_ele(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_Mass(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_Charge(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_SPEC(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_small_grids_scmc_set_parameter_Deltat(
    cuda_split_pass_x_small_grids_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_init(
    cuda_pscmc_env *pe, cuda_split_pass_x_vlo_nopush_struct *kerstr);
void cuda_split_pass_x_vlo_nopush_get_struct_len(size_t *len);
int cuda_split_pass_x_vlo_nopush_get_xlen();
int cuda_split_pass_x_vlo_nopush_get_num_compute_units(
    cuda_split_pass_x_vlo_nopush_struct *kerstr);
int cuda_split_pass_x_vlo_nopush_exec(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_init(cuda_pscmc_env *pe,
                               cuda_split_pass_x_vlo_struct *kerstr);
void cuda_split_pass_x_vlo_get_struct_len(size_t *len);
int cuda_split_pass_x_vlo_get_xlen();
int cuda_split_pass_x_vlo_get_num_compute_units(
    cuda_split_pass_x_vlo_struct *kerstr);
int cuda_split_pass_x_vlo_exec(cuda_split_pass_x_vlo_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen);
int cuda_split_pass_x_vlo_scmc_set_parameter_inoutput(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_xyzw(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_fieldE(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_fieldB(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_FoutJ(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_XLEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_YLEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_ovlp(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_numvec(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_num_ele(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_Mass(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_Charge(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_SPEC(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_vlo_scmc_set_parameter_Deltat(
    cuda_split_pass_x_vlo_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_init(cuda_pscmc_env *pe,
                                  cuda_split_pass_x_nopush_struct *kerstr);
void cuda_split_pass_x_nopush_get_struct_len(size_t *len);
int cuda_split_pass_x_nopush_get_xlen();
int cuda_split_pass_x_nopush_get_num_compute_units(
    cuda_split_pass_x_nopush_struct *kerstr);
int cuda_split_pass_x_nopush_exec(cuda_split_pass_x_nopush_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_split_pass_x_nopush_scmc_set_parameter_inoutput(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_xyzw(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_fieldE(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_fieldB(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_FoutJ(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_XLEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_YLEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_ZLEN(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_ovlp(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_numvec(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_num_ele(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_Mass(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_Charge(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_SPEC(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_nopush_scmc_set_parameter_Deltat(
    cuda_split_pass_x_nopush_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_init(cuda_pscmc_env *pe,
                           cuda_split_pass_x_struct *kerstr);
void cuda_split_pass_x_get_struct_len(size_t *len);
int cuda_split_pass_x_get_xlen();
int cuda_split_pass_x_get_num_compute_units(cuda_split_pass_x_struct *kerstr);
int cuda_split_pass_x_exec(cuda_split_pass_x_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen);
int cuda_split_pass_x_scmc_set_parameter_inoutput(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_xyzw(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_cu_cache(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_cu_xyzw(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_fieldE(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_fieldB(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_FoutJ(cuda_split_pass_x_struct *kerstr,
                                               cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_FoutEN(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_XLEN(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_YLEN(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_ZLEN(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_ovlp(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_numvec(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_num_ele(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_grid_cache_len(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_cu_cache_length(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_Mass(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_Charge(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_SPEC(cuda_split_pass_x_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_NUM_SPEC(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_DELTA_X(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_DELTA_Y(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_DELTA_Z(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_split_pass_x_scmc_set_parameter_Deltat(
    cuda_split_pass_x_struct *kerstr, cuda_pscmc_mem *pm);

#include "pubdefs.h"

int cuda_merge_ovlp_m2o_once_init(cuda_pscmc_env *pe,
                                  cuda_merge_ovlp_m2o_once_struct *kerstr);
void cuda_merge_ovlp_m2o_once_get_struct_len(size_t *len);
int cuda_merge_ovlp_m2o_once_get_xlen();
int cuda_merge_ovlp_m2o_once_get_num_compute_units(
    cuda_merge_ovlp_m2o_once_struct *kerstr);
int cuda_merge_ovlp_m2o_once_exec(cuda_merge_ovlp_m2o_once_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp0(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp1(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp2(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp3(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp4(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp5(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp6(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp7(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp8(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp9(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp10(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp11(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp12(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp14(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp15(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp16(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp17(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp18(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp19(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp20(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp21(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp22(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp23(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp24(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp25(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp26(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_numvec(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_xblock(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_yblock(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_zblock(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_init(
    cuda_pscmc_env *pe, cuda_merge_ovlp_m2o_all_in_one_struct *kerstr);
void cuda_merge_ovlp_m2o_all_in_one_get_struct_len(size_t *len);
int cuda_merge_ovlp_m2o_all_in_one_get_xlen();
int cuda_merge_ovlp_m2o_all_in_one_get_num_compute_units(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr);
int cuda_merge_ovlp_m2o_all_in_one_exec(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_init(cuda_pscmc_env *pe,
                             cuda_merge_ovlp_m2o_struct *kerstr);
void cuda_merge_ovlp_m2o_get_struct_len(size_t *len);
int cuda_merge_ovlp_m2o_get_xlen();
int cuda_merge_ovlp_m2o_get_num_compute_units(
    cuda_merge_ovlp_m2o_struct *kerstr);
int cuda_merge_ovlp_m2o_exec(cuda_merge_ovlp_m2o_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int cuda_merge_ovlp_m2o_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_vecovlp(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_ovlpindex(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_numvec(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_xblock(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_yblock(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_zblock(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_m2o_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_init(cuda_pscmc_env *pe,
                                  cuda_merge_ovlp_o2m_once_struct *kerstr);
void cuda_merge_ovlp_o2m_once_get_struct_len(size_t *len);
int cuda_merge_ovlp_o2m_once_get_xlen();
int cuda_merge_ovlp_o2m_once_get_num_compute_units(
    cuda_merge_ovlp_o2m_once_struct *kerstr);
int cuda_merge_ovlp_o2m_once_exec(cuda_merge_ovlp_o2m_once_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp0(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp1(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp2(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp3(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp4(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp5(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp6(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp7(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp8(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp9(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp10(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp11(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp12(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp14(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp15(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp16(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp17(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp18(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp19(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp20(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp21(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp22(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp23(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp24(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp25(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp26(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_numvec(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_xblock(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_yblock(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_zblock(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_init(
    cuda_pscmc_env *pe, cuda_merge_ovlp_o2m_all_in_one_struct *kerstr);
void cuda_merge_ovlp_o2m_all_in_one_get_struct_len(size_t *len);
int cuda_merge_ovlp_o2m_all_in_one_get_xlen();
int cuda_merge_ovlp_o2m_all_in_one_get_num_compute_units(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr);
int cuda_merge_ovlp_o2m_all_in_one_exec(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_init(cuda_pscmc_env *pe,
                             cuda_merge_ovlp_o2m_struct *kerstr);
void cuda_merge_ovlp_o2m_get_struct_len(size_t *len);
int cuda_merge_ovlp_o2m_get_xlen();
int cuda_merge_ovlp_o2m_get_num_compute_units(
    cuda_merge_ovlp_o2m_struct *kerstr);
int cuda_merge_ovlp_o2m_exec(cuda_merge_ovlp_o2m_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen);
int cuda_merge_ovlp_o2m_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_vecovlp(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_ovlpindex(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_numvec(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_xblock(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_yblock(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_zblock(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_merge_ovlp_o2m_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_init(cuda_pscmc_env *pe,
                                 cuda_sync_ovlp_m2o_once_struct *kerstr);
void cuda_sync_ovlp_m2o_once_get_struct_len(size_t *len);
int cuda_sync_ovlp_m2o_once_get_xlen();
int cuda_sync_ovlp_m2o_once_get_num_compute_units(
    cuda_sync_ovlp_m2o_once_struct *kerstr);
int cuda_sync_ovlp_m2o_once_exec(cuda_sync_ovlp_m2o_once_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp0(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp1(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp2(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp3(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp4(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp5(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp6(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp7(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp8(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp9(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp10(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp11(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp12(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp14(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp15(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp16(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp17(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp18(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp19(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp20(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp21(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp22(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp23(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp24(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp25(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp26(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_numvec(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_xblock(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_yblock(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_zblock(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_init(
    cuda_pscmc_env *pe, cuda_sync_ovlp_m2o_all_in_one_struct *kerstr);
void cuda_sync_ovlp_m2o_all_in_one_get_struct_len(size_t *len);
int cuda_sync_ovlp_m2o_all_in_one_get_xlen();
int cuda_sync_ovlp_m2o_all_in_one_get_num_compute_units(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr);
int cuda_sync_ovlp_m2o_all_in_one_exec(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_init(cuda_pscmc_env *pe,
                            cuda_sync_ovlp_m2o_struct *kerstr);
void cuda_sync_ovlp_m2o_get_struct_len(size_t *len);
int cuda_sync_ovlp_m2o_get_xlen();
int cuda_sync_ovlp_m2o_get_num_compute_units(cuda_sync_ovlp_m2o_struct *kerstr);
int cuda_sync_ovlp_m2o_exec(cuda_sync_ovlp_m2o_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen);
int cuda_sync_ovlp_m2o_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_vecovlp(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_ovlpindex(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_numvec(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_xblock(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_yblock(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_zblock(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_m2o_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_init(cuda_pscmc_env *pe,
                                 cuda_sync_ovlp_o2m_once_struct *kerstr);
void cuda_sync_ovlp_o2m_once_get_struct_len(size_t *len);
int cuda_sync_ovlp_o2m_once_get_xlen();
int cuda_sync_ovlp_o2m_once_get_num_compute_units(
    cuda_sync_ovlp_o2m_once_struct *kerstr);
int cuda_sync_ovlp_o2m_once_exec(cuda_sync_ovlp_o2m_once_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp0(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp1(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp2(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp3(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp4(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp5(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp6(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp7(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp8(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp9(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp10(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp11(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp12(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp14(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp15(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp16(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp17(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp18(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp19(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp20(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp21(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp22(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp23(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp24(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp25(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp26(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_numvec(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_xblock(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_yblock(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_zblock(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_init(
    cuda_pscmc_env *pe, cuda_sync_ovlp_o2m_all_in_one_struct *kerstr);
void cuda_sync_ovlp_o2m_all_in_one_get_struct_len(size_t *len);
int cuda_sync_ovlp_o2m_all_in_one_get_xlen();
int cuda_sync_ovlp_o2m_all_in_one_get_num_compute_units(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr);
int cuda_sync_ovlp_o2m_all_in_one_exec(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_init(cuda_pscmc_env *pe,
                            cuda_sync_ovlp_o2m_struct *kerstr);
void cuda_sync_ovlp_o2m_get_struct_len(size_t *len);
int cuda_sync_ovlp_o2m_get_xlen();
int cuda_sync_ovlp_o2m_get_num_compute_units(cuda_sync_ovlp_o2m_struct *kerstr);
int cuda_sync_ovlp_o2m_exec(cuda_sync_ovlp_o2m_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen);
int cuda_sync_ovlp_o2m_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_vecovlp(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_ovlpindex(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_numvec(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_xblock(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_yblock(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_zblock(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_sync_ovlp_o2m_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm);
int cuda_yee_local_init(cuda_pscmc_env *pe, cuda_yee_local_struct *kerstr);
void cuda_yee_local_get_struct_len(size_t *len);
int cuda_yee_local_get_xlen();
int cuda_yee_local_get_num_compute_units(cuda_yee_local_struct *kerstr);
int cuda_yee_local_exec(cuda_yee_local_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen);
int cuda_yee_local_scmc_set_parameter_inout(cuda_yee_local_struct *kerstr,
                                            cuda_pscmc_mem *pm);
int cuda_yee_local_scmc_set_parameter_numvec(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_yee_local_scmc_set_parameter_num_ele(cuda_yee_local_struct *kerstr,
                                              cuda_pscmc_mem *pm);
int cuda_yee_local_scmc_set_parameter_xblock(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_yee_local_scmc_set_parameter_yblock(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_yee_local_scmc_set_parameter_zblock(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm);
int cuda_yee_local_scmc_set_parameter_ovlp(cuda_yee_local_struct *kerstr,
                                           cuda_pscmc_mem *pm);

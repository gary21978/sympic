#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "c_pscmc_inc.h"

#include "mergefields.kernel_inc.h"

int c_merge_ovlp_m2o_once_init(c_pscmc_env *pe,
                               c_merge_ovlp_m2o_once_struct *kerstr) {
  return 0;
}
void c_merge_ovlp_m2o_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_merge_ovlp_m2o_once_struct));
}
int c_merge_ovlp_m2o_once_get_xlen() { return IDX_OPT_MAX; }
int c_merge_ovlp_m2o_once_get_num_compute_units(
    c_merge_ovlp_m2o_once_struct *kerstr) {
  return 1;
}
int c_merge_ovlp_m2o_once_exec(c_merge_ovlp_m2o_once_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_merge_ovlp_m2o_once_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1,
          (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4,
          (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7,
          (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10,
          (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14,
          (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17,
          (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20,
          (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23,
          (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26,
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecmain(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp0(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp0 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp1(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp1 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp2(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp2 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp3(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp3 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp4(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp4 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp5(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp5 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp6(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp6 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp7(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp7 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp8(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp8 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp9(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp9 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp10(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp10 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp11(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp11 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp12(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp12 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp14(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp14 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp15(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp15 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp16(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp16 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp17(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp17 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp18(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp18 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp19(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp19 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp20(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp20 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp21(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp21 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp22(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp22 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp23(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp23 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp24(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp24 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp25(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp25 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp26(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp26 = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_numvec(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_num_ele(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_xblock(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_yblock(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_zblock(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_ovlp(
    c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_init(
    c_pscmc_env *pe, c_merge_ovlp_m2o_all_in_one_struct *kerstr) {
  return 0;
}
void c_merge_ovlp_m2o_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_merge_ovlp_m2o_all_in_one_struct));
}
int c_merge_ovlp_m2o_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int c_merge_ovlp_m2o_all_in_one_get_num_compute_units(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr) {
  return 1;
}
int c_merge_ovlp_m2o_all_in_one_exec(c_merge_ovlp_m2o_all_in_one_struct *kerstr,
                                     long scmc_internal_g_xlen,
                                     long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_merge_ovlp_m2o_all_in_one_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0],
          ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0],
          ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid,
          scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlps = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_merge_ovlp_m2o_init(c_pscmc_env *pe, c_merge_ovlp_m2o_struct *kerstr) {
  return 0;
}
void c_merge_ovlp_m2o_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_merge_ovlp_m2o_struct));
}
int c_merge_ovlp_m2o_get_xlen() { return IDX_OPT_MAX; }
int c_merge_ovlp_m2o_get_num_compute_units(c_merge_ovlp_m2o_struct *kerstr) {
  return 1;
}
int c_merge_ovlp_m2o_exec(c_merge_ovlp_m2o_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_merge_ovlp_m2o_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0],
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_merge_ovlp_m2o_scmc_set_parameter_vecmain(c_merge_ovlp_m2o_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_vecovlp(c_merge_ovlp_m2o_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->vecovlp = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_ovlpindex(
    c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlpindex = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_numvec(c_merge_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_num_ele(c_merge_ovlp_m2o_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_xblock(c_merge_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_yblock(c_merge_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_zblock(c_merge_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_merge_ovlp_m2o_scmc_set_parameter_ovlp(c_merge_ovlp_m2o_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_merge_ovlp_o2m_once_init(c_pscmc_env *pe,
                               c_merge_ovlp_o2m_once_struct *kerstr) {
  return 0;
}
void c_merge_ovlp_o2m_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_merge_ovlp_o2m_once_struct));
}
int c_merge_ovlp_o2m_once_get_xlen() { return IDX_OPT_MAX; }
int c_merge_ovlp_o2m_once_get_num_compute_units(
    c_merge_ovlp_o2m_once_struct *kerstr) {
  return 1;
}
int c_merge_ovlp_o2m_once_exec(c_merge_ovlp_o2m_once_struct *kerstr,
                               long scmc_internal_g_xlen,
                               long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_merge_ovlp_o2m_once_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1,
          (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4,
          (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7,
          (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10,
          (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14,
          (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17,
          (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20,
          (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23,
          (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26,
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecmain(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp0(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp0 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp1(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp1 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp2(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp2 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp3(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp3 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp4(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp4 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp5(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp5 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp6(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp6 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp7(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp7 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp8(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp8 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp9(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp9 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp10(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp10 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp11(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp11 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp12(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp12 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp14(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp14 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp15(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp15 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp16(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp16 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp17(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp17 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp18(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp18 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp19(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp19 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp20(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp20 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp21(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp21 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp22(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp22 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp23(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp23 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp24(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp24 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp25(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp25 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp26(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp26 = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_numvec(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_num_ele(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_xblock(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_yblock(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_zblock(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_ovlp(
    c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_init(
    c_pscmc_env *pe, c_merge_ovlp_o2m_all_in_one_struct *kerstr) {
  return 0;
}
void c_merge_ovlp_o2m_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_merge_ovlp_o2m_all_in_one_struct));
}
int c_merge_ovlp_o2m_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int c_merge_ovlp_o2m_all_in_one_get_num_compute_units(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr) {
  return 1;
}
int c_merge_ovlp_o2m_all_in_one_exec(c_merge_ovlp_o2m_all_in_one_struct *kerstr,
                                     long scmc_internal_g_xlen,
                                     long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_merge_ovlp_o2m_all_in_one_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0],
          ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0],
          ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid,
          scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlps = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_merge_ovlp_o2m_init(c_pscmc_env *pe, c_merge_ovlp_o2m_struct *kerstr) {
  return 0;
}
void c_merge_ovlp_o2m_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_merge_ovlp_o2m_struct));
}
int c_merge_ovlp_o2m_get_xlen() { return IDX_OPT_MAX; }
int c_merge_ovlp_o2m_get_num_compute_units(c_merge_ovlp_o2m_struct *kerstr) {
  return 1;
}
int c_merge_ovlp_o2m_exec(c_merge_ovlp_o2m_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_merge_ovlp_o2m_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0],
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_merge_ovlp_o2m_scmc_set_parameter_vecmain(c_merge_ovlp_o2m_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_vecovlp(c_merge_ovlp_o2m_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->vecovlp = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_ovlpindex(
    c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlpindex = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_numvec(c_merge_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_num_ele(c_merge_ovlp_o2m_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_xblock(c_merge_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_yblock(c_merge_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_zblock(c_merge_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_merge_ovlp_o2m_scmc_set_parameter_ovlp(c_merge_ovlp_o2m_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sync_ovlp_m2o_once_init(c_pscmc_env *pe,
                              c_sync_ovlp_m2o_once_struct *kerstr) {
  return 0;
}
void c_sync_ovlp_m2o_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sync_ovlp_m2o_once_struct));
}
int c_sync_ovlp_m2o_once_get_xlen() { return IDX_OPT_MAX; }
int c_sync_ovlp_m2o_once_get_num_compute_units(
    c_sync_ovlp_m2o_once_struct *kerstr) {
  return 1;
}
int c_sync_ovlp_m2o_once_exec(c_sync_ovlp_m2o_once_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_sync_ovlp_m2o_once_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1,
          (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4,
          (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7,
          (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10,
          (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14,
          (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17,
          (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20,
          (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23,
          (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26,
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecmain(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp0(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp0 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp1(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp1 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp2(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp2 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp3(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp3 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp4(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp4 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp5(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp5 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp6(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp6 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp7(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp7 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp8(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp8 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp9(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp9 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp10(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp10 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp11(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp11 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp12(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp12 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp14(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp14 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp15(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp15 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp16(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp16 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp17(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp17 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp18(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp18 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp19(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp19 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp20(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp20 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp21(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp21 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp22(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp22 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp23(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp23 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp24(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp24 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp25(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp25 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp26(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp26 = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_numvec(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_num_ele(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_xblock(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_yblock(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_zblock(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_ovlp(
    c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_init(c_pscmc_env *pe,
                                    c_sync_ovlp_m2o_all_in_one_struct *kerstr) {
  return 0;
}
void c_sync_ovlp_m2o_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sync_ovlp_m2o_all_in_one_struct));
}
int c_sync_ovlp_m2o_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int c_sync_ovlp_m2o_all_in_one_get_num_compute_units(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr) {
  return 1;
}
int c_sync_ovlp_m2o_all_in_one_exec(c_sync_ovlp_m2o_all_in_one_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_sync_ovlp_m2o_all_in_one_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0],
          ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0],
          ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid,
          scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlps = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sync_ovlp_m2o_init(c_pscmc_env *pe, c_sync_ovlp_m2o_struct *kerstr) {
  return 0;
}
void c_sync_ovlp_m2o_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sync_ovlp_m2o_struct));
}
int c_sync_ovlp_m2o_get_xlen() { return IDX_OPT_MAX; }
int c_sync_ovlp_m2o_get_num_compute_units(c_sync_ovlp_m2o_struct *kerstr) {
  return 1;
}
int c_sync_ovlp_m2o_exec(c_sync_ovlp_m2o_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_sync_ovlp_m2o_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0],
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sync_ovlp_m2o_scmc_set_parameter_vecmain(c_sync_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_vecovlp(c_sync_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->vecovlp = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_ovlpindex(c_sync_ovlp_m2o_struct *kerstr,
                                                 c_pscmc_mem *pm) {
  ((kerstr)->ovlpindex = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_numvec(c_sync_ovlp_m2o_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_num_ele(c_sync_ovlp_m2o_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_xblock(c_sync_ovlp_m2o_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_yblock(c_sync_ovlp_m2o_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_zblock(c_sync_ovlp_m2o_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_sync_ovlp_m2o_scmc_set_parameter_ovlp(c_sync_ovlp_m2o_struct *kerstr,
                                            c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sync_ovlp_o2m_once_init(c_pscmc_env *pe,
                              c_sync_ovlp_o2m_once_struct *kerstr) {
  return 0;
}
void c_sync_ovlp_o2m_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sync_ovlp_o2m_once_struct));
}
int c_sync_ovlp_o2m_once_get_xlen() { return IDX_OPT_MAX; }
int c_sync_ovlp_o2m_once_get_num_compute_units(
    c_sync_ovlp_o2m_once_struct *kerstr) {
  return 1;
}
int c_sync_ovlp_o2m_once_exec(c_sync_ovlp_o2m_once_struct *kerstr,
                              long scmc_internal_g_xlen,
                              long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_sync_ovlp_o2m_once_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1,
          (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4,
          (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7,
          (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10,
          (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14,
          (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17,
          (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20,
          (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23,
          (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26,
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecmain(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp0(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp0 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp1(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp1 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp2(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp2 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp3(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp3 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp4(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp4 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp5(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp5 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp6(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp6 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp7(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp7 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp8(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp8 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp9(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp9 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp10(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp10 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp11(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp11 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp12(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp12 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp14(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp14 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp15(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp15 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp16(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp16 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp17(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp17 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp18(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp18 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp19(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp19 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp20(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp20 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp21(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp21 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp22(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp22 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp23(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp23 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp24(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp24 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp25(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp25 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp26(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlp26 = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_numvec(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_num_ele(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_xblock(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_yblock(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_zblock(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_ovlp(
    c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_init(c_pscmc_env *pe,
                                    c_sync_ovlp_o2m_all_in_one_struct *kerstr) {
  return 0;
}
void c_sync_ovlp_o2m_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sync_ovlp_o2m_all_in_one_struct));
}
int c_sync_ovlp_o2m_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int c_sync_ovlp_o2m_all_in_one_get_num_compute_units(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr) {
  return 1;
}
int c_sync_ovlp_o2m_all_in_one_exec(c_sync_ovlp_o2m_all_in_one_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_sync_ovlp_o2m_all_in_one_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0],
          ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0],
          ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid,
          scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->vecovlps = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sync_ovlp_o2m_init(c_pscmc_env *pe, c_sync_ovlp_o2m_struct *kerstr) {
  return 0;
}
void c_sync_ovlp_o2m_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sync_ovlp_o2m_struct));
}
int c_sync_ovlp_o2m_get_xlen() { return IDX_OPT_MAX; }
int c_sync_ovlp_o2m_get_num_compute_units(c_sync_ovlp_o2m_struct *kerstr) {
  return 1;
}
int c_sync_ovlp_o2m_exec(c_sync_ovlp_o2m_struct *kerstr,
                         long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_sync_ovlp_o2m_scmc_kernel(
          (kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0],
          ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0],
          yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sync_ovlp_o2m_scmc_set_parameter_vecmain(c_sync_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->vecmain = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_vecovlp(c_sync_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->vecovlp = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_ovlpindex(c_sync_ovlp_o2m_struct *kerstr,
                                                 c_pscmc_mem *pm) {
  ((kerstr)->ovlpindex = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_numvec(c_sync_ovlp_o2m_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_num_ele(c_sync_ovlp_o2m_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_xblock(c_sync_ovlp_o2m_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_yblock(c_sync_ovlp_o2m_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_zblock(c_sync_ovlp_o2m_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_sync_ovlp_o2m_scmc_set_parameter_ovlp(c_sync_ovlp_o2m_struct *kerstr,
                                            c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_yee_local_init(c_pscmc_env *pe, c_yee_local_struct *kerstr) { return 0; }
void c_yee_local_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_yee_local_struct));
}
int c_yee_local_get_xlen() { return IDX_OPT_MAX; }
int c_yee_local_get_num_compute_units(c_yee_local_struct *kerstr) { return 1; }
int c_yee_local_exec(c_yee_local_struct *kerstr, long scmc_internal_g_xlen,
                     long scmc_internal_g_ylen) {
  {
    int yid;

    int numt = 1;

    int tid = 0;

    int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);

    int ymin = (tid * ysingle);

    int ymax = ((1 + tid) * ysingle);

    for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen));
         (yid = (yid + 1))) {
      c_yee_local_scmc_kernel((kerstr)->inout, ((kerstr)->numvec)[0],
                              ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0],
                              ((kerstr)->yblock)[0], ((kerstr)->zblock)[0],
                              ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_yee_local_scmc_set_parameter_inout(c_yee_local_struct *kerstr,
                                         c_pscmc_mem *pm) {
  ((kerstr)->inout = pm->d_data);
}
int c_yee_local_scmc_set_parameter_numvec(c_yee_local_struct *kerstr,
                                          c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_yee_local_scmc_set_parameter_num_ele(c_yee_local_struct *kerstr,
                                           c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_yee_local_scmc_set_parameter_xblock(c_yee_local_struct *kerstr,
                                          c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_yee_local_scmc_set_parameter_yblock(c_yee_local_struct *kerstr,
                                          c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_yee_local_scmc_set_parameter_zblock(c_yee_local_struct *kerstr,
                                          c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_yee_local_scmc_set_parameter_ovlp(c_yee_local_struct *kerstr,
                                        c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}

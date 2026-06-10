#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "c_pscmc_inc.h"

#include "stencil.kernel_inc.h"

int c_Yee_FDTD_W04_2_init(c_pscmc_env *pe, c_Yee_FDTD_W04_2_struct *kerstr) {
  return 0;
}
void c_Yee_FDTD_W04_2_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_Yee_FDTD_W04_2_struct));
}
int c_Yee_FDTD_W04_2_get_xlen() { return IDX_OPT_MAX; }
int c_Yee_FDTD_W04_2_get_num_compute_units(c_Yee_FDTD_W04_2_struct *kerstr) {
  return 1;
}
int c_Yee_FDTD_W04_2_exec(c_Yee_FDTD_W04_2_struct *kerstr,
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
      c_Yee_FDTD_W04_2_scmc_kernel(
          (kerstr)->outEB, (kerstr)->inEB, ((kerstr)->y_cpu_core)[0],
          ((kerstr)->numvec)[0], ((kerstr)->XLEN)[0], ((kerstr)->YLEN)[0],
          ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->num_ele)[0],
          ((kerstr)->DT)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_outEB(c_Yee_FDTD_W04_2_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->outEB = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_inEB(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->inEB = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_y_cpu_core(
    c_Yee_FDTD_W04_2_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->y_cpu_core = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_numvec(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_XLEN(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_YLEN(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_ZLEN(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_ovlp(c_Yee_FDTD_W04_2_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_xblock(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_yblock(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_zblock(c_Yee_FDTD_W04_2_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_num_ele(c_Yee_FDTD_W04_2_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_Yee_FDTD_W04_2_scmc_set_parameter_DT(c_Yee_FDTD_W04_2_struct *kerstr,
                                           c_pscmc_mem *pm) {
  ((kerstr)->DT = pm->d_data);
}
int c_Yee_FDTD_W04_1_init(c_pscmc_env *pe, c_Yee_FDTD_W04_1_struct *kerstr) {
  return 0;
}
void c_Yee_FDTD_W04_1_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_Yee_FDTD_W04_1_struct));
}
int c_Yee_FDTD_W04_1_get_xlen() { return IDX_OPT_MAX; }
int c_Yee_FDTD_W04_1_get_num_compute_units(c_Yee_FDTD_W04_1_struct *kerstr) {
  return 1;
}
int c_Yee_FDTD_W04_1_exec(c_Yee_FDTD_W04_1_struct *kerstr,
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
      c_Yee_FDTD_W04_1_scmc_kernel(
          (kerstr)->outEB, (kerstr)->inEB, ((kerstr)->y_cpu_core)[0],
          ((kerstr)->numvec)[0], ((kerstr)->XLEN)[0], ((kerstr)->YLEN)[0],
          ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->num_ele)[0],
          ((kerstr)->DT)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_outEB(c_Yee_FDTD_W04_1_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->outEB = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_inEB(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->inEB = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_y_cpu_core(
    c_Yee_FDTD_W04_1_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->y_cpu_core = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_numvec(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_XLEN(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_YLEN(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_ZLEN(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_ovlp(c_Yee_FDTD_W04_1_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_xblock(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_yblock(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_zblock(c_Yee_FDTD_W04_1_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_num_ele(c_Yee_FDTD_W04_1_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_Yee_FDTD_W04_1_scmc_set_parameter_DT(c_Yee_FDTD_W04_1_struct *kerstr,
                                           c_pscmc_mem *pm) {
  ((kerstr)->DT = pm->d_data);
}
int c_Yee_FDTD_W04_0_init(c_pscmc_env *pe, c_Yee_FDTD_W04_0_struct *kerstr) {
  return 0;
}
void c_Yee_FDTD_W04_0_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_Yee_FDTD_W04_0_struct));
}
int c_Yee_FDTD_W04_0_get_xlen() { return IDX_OPT_MAX; }
int c_Yee_FDTD_W04_0_get_num_compute_units(c_Yee_FDTD_W04_0_struct *kerstr) {
  return 1;
}
int c_Yee_FDTD_W04_0_exec(c_Yee_FDTD_W04_0_struct *kerstr,
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
      c_Yee_FDTD_W04_0_scmc_kernel(
          (kerstr)->outEB, (kerstr)->inEB, ((kerstr)->y_cpu_core)[0],
          ((kerstr)->numvec)[0], ((kerstr)->XLEN)[0], ((kerstr)->YLEN)[0],
          ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0], ((kerstr)->xblock)[0],
          ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->num_ele)[0],
          ((kerstr)->DT)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_outEB(c_Yee_FDTD_W04_0_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->outEB = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_inEB(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->inEB = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_y_cpu_core(
    c_Yee_FDTD_W04_0_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->y_cpu_core = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_numvec(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_XLEN(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_YLEN(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_ZLEN(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_ovlp(c_Yee_FDTD_W04_0_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_xblock(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->xblock = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_yblock(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->yblock = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_zblock(c_Yee_FDTD_W04_0_struct *kerstr,
                                               c_pscmc_mem *pm) {
  ((kerstr)->zblock = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_num_ele(c_Yee_FDTD_W04_0_struct *kerstr,
                                                c_pscmc_mem *pm) {
  ((kerstr)->num_ele = pm->d_data);
}
int c_Yee_FDTD_W04_0_scmc_set_parameter_DT(c_Yee_FDTD_W04_0_struct *kerstr,
                                           c_pscmc_mem *pm) {
  ((kerstr)->DT = pm->d_data);
}

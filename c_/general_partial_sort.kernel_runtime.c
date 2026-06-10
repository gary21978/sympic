#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "c_pscmc_inc.h"

#include "general_partial_sort.kernel_inc.h"

int c_cu_swap_r_8_init(c_pscmc_env *pe, c_cu_swap_r_8_struct *kerstr) {
  return 0;
}
void c_cu_swap_r_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_cu_swap_r_8_struct));
}
int c_cu_swap_r_8_get_xlen() { return IDX_OPT_MAX; }
int c_cu_swap_r_8_get_num_compute_units(c_cu_swap_r_8_struct *kerstr) {
  return 1;
}
int c_cu_swap_r_8_exec(c_cu_swap_r_8_struct *kerstr, long scmc_internal_g_xlen,
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
      c_cu_swap_r_8_scmc_kernel(
          (kerstr)->cu_cache, (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids,
          ((kerstr)->cu_cache_length)[0], ((kerstr)->the_dir_num)[0],
          ((kerstr)->XYZLEN)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_cu_swap_r_8_scmc_set_parameter_cu_cache(c_cu_swap_r_8_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_cu_swap_r_8_scmc_set_parameter_cu_xyzw(c_cu_swap_r_8_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(
    c_cu_swap_r_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
    c_cu_swap_r_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_cu_swap_r_8_scmc_set_parameter_the_dir_num(c_cu_swap_r_8_struct *kerstr,
                                                 c_pscmc_mem *pm) {
  ((kerstr)->the_dir_num = pm->d_data);
}
int c_cu_swap_r_8_scmc_set_parameter_XYZLEN(c_cu_swap_r_8_struct *kerstr,
                                            c_pscmc_mem *pm) {
  ((kerstr)->XYZLEN = pm->d_data);
}
int c_cu_swap_l_8_init(c_pscmc_env *pe, c_cu_swap_l_8_struct *kerstr) {
  return 0;
}
void c_cu_swap_l_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_cu_swap_l_8_struct));
}
int c_cu_swap_l_8_get_xlen() { return IDX_OPT_MAX; }
int c_cu_swap_l_8_get_num_compute_units(c_cu_swap_l_8_struct *kerstr) {
  return 1;
}
int c_cu_swap_l_8_exec(c_cu_swap_l_8_struct *kerstr, long scmc_internal_g_xlen,
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
      c_cu_swap_l_8_scmc_kernel(
          (kerstr)->cu_cache, (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids,
          ((kerstr)->cu_cache_length)[0], ((kerstr)->the_dir_num)[0],
          ((kerstr)->XYZLEN)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_cu_swap_l_8_scmc_set_parameter_cu_cache(c_cu_swap_l_8_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_cu_swap_l_8_scmc_set_parameter_cu_xyzw(c_cu_swap_l_8_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(
    c_cu_swap_l_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
    c_cu_swap_l_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_cu_swap_l_8_scmc_set_parameter_the_dir_num(c_cu_swap_l_8_struct *kerstr,
                                                 c_pscmc_mem *pm) {
  ((kerstr)->the_dir_num = pm->d_data);
}
int c_cu_swap_l_8_scmc_set_parameter_XYZLEN(c_cu_swap_l_8_struct *kerstr,
                                            c_pscmc_mem *pm) {
  ((kerstr)->XYZLEN = pm->d_data);
}
int c_cu_swap_r_6_init(c_pscmc_env *pe, c_cu_swap_r_6_struct *kerstr) {
  return 0;
}
void c_cu_swap_r_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_cu_swap_r_6_struct));
}
int c_cu_swap_r_6_get_xlen() { return IDX_OPT_MAX; }
int c_cu_swap_r_6_get_num_compute_units(c_cu_swap_r_6_struct *kerstr) {
  return 1;
}
int c_cu_swap_r_6_exec(c_cu_swap_r_6_struct *kerstr, long scmc_internal_g_xlen,
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
      c_cu_swap_r_6_scmc_kernel(
          (kerstr)->cu_cache, (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids,
          ((kerstr)->cu_cache_length)[0], ((kerstr)->the_dir_num)[0],
          ((kerstr)->XYZLEN)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_cu_swap_r_6_scmc_set_parameter_cu_cache(c_cu_swap_r_6_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_cu_swap_r_6_scmc_set_parameter_cu_xyzw(c_cu_swap_r_6_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(
    c_cu_swap_r_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
    c_cu_swap_r_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_cu_swap_r_6_scmc_set_parameter_the_dir_num(c_cu_swap_r_6_struct *kerstr,
                                                 c_pscmc_mem *pm) {
  ((kerstr)->the_dir_num = pm->d_data);
}
int c_cu_swap_r_6_scmc_set_parameter_XYZLEN(c_cu_swap_r_6_struct *kerstr,
                                            c_pscmc_mem *pm) {
  ((kerstr)->XYZLEN = pm->d_data);
}
int c_cu_swap_l_6_init(c_pscmc_env *pe, c_cu_swap_l_6_struct *kerstr) {
  return 0;
}
void c_cu_swap_l_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_cu_swap_l_6_struct));
}
int c_cu_swap_l_6_get_xlen() { return IDX_OPT_MAX; }
int c_cu_swap_l_6_get_num_compute_units(c_cu_swap_l_6_struct *kerstr) {
  return 1;
}
int c_cu_swap_l_6_exec(c_cu_swap_l_6_struct *kerstr, long scmc_internal_g_xlen,
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
      c_cu_swap_l_6_scmc_kernel(
          (kerstr)->cu_cache, (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids,
          ((kerstr)->cu_cache_length)[0], ((kerstr)->the_dir_num)[0],
          ((kerstr)->XYZLEN)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_cu_swap_l_6_scmc_set_parameter_cu_cache(c_cu_swap_l_6_struct *kerstr,
                                              c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_cu_swap_l_6_scmc_set_parameter_cu_xyzw(c_cu_swap_l_6_struct *kerstr,
                                             c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(
    c_cu_swap_l_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
    c_cu_swap_l_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_cu_swap_l_6_scmc_set_parameter_the_dir_num(c_cu_swap_l_6_struct *kerstr,
                                                 c_pscmc_mem *pm) {
  ((kerstr)->the_dir_num = pm->d_data);
}
int c_cu_swap_l_6_scmc_set_parameter_XYZLEN(c_cu_swap_l_6_struct *kerstr,
                                            c_pscmc_mem *pm) {
  ((kerstr)->XYZLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_init(c_pscmc_env *pe,
                                 c_sort_one_grid_z_vlo_8_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_z_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_z_vlo_8_struct));
}
int c_sort_one_grid_z_vlo_8_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_z_vlo_8_get_num_compute_units(
    c_sort_one_grid_z_vlo_8_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_z_vlo_8_exec(c_sort_one_grid_z_vlo_8_struct *kerstr,
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
      c_sort_one_grid_z_vlo_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_init(
    c_pscmc_env *pe, c_gpu_sort_one_grid_z_vlo_8_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_z_vlo_8_struct));
}
int c_gpu_sort_one_grid_z_vlo_8_get_xlen() { return 32; }
int c_gpu_sort_one_grid_z_vlo_8_get_num_compute_units(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_z_vlo_8_exec(c_gpu_sort_one_grid_z_vlo_8_struct *kerstr,
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
      c_gpu_sort_one_grid_z_vlo_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_z_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_init(c_pscmc_env *pe,
                                 c_sort_one_grid_y_vlo_8_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_y_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_y_vlo_8_struct));
}
int c_sort_one_grid_y_vlo_8_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_y_vlo_8_get_num_compute_units(
    c_sort_one_grid_y_vlo_8_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_y_vlo_8_exec(c_sort_one_grid_y_vlo_8_struct *kerstr,
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
      c_sort_one_grid_y_vlo_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_init(
    c_pscmc_env *pe, c_gpu_sort_one_grid_y_vlo_8_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_y_vlo_8_struct));
}
int c_gpu_sort_one_grid_y_vlo_8_get_xlen() { return 32; }
int c_gpu_sort_one_grid_y_vlo_8_get_num_compute_units(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_y_vlo_8_exec(c_gpu_sort_one_grid_y_vlo_8_struct *kerstr,
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
      c_gpu_sort_one_grid_y_vlo_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_y_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_init(c_pscmc_env *pe,
                                 c_sort_one_grid_x_vlo_8_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_x_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_x_vlo_8_struct));
}
int c_sort_one_grid_x_vlo_8_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_x_vlo_8_get_num_compute_units(
    c_sort_one_grid_x_vlo_8_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_x_vlo_8_exec(c_sort_one_grid_x_vlo_8_struct *kerstr,
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
      c_sort_one_grid_x_vlo_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_init(
    c_pscmc_env *pe, c_gpu_sort_one_grid_x_vlo_8_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_x_vlo_8_struct));
}
int c_gpu_sort_one_grid_x_vlo_8_get_xlen() { return 32; }
int c_gpu_sort_one_grid_x_vlo_8_get_num_compute_units(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_x_vlo_8_exec(c_gpu_sort_one_grid_x_vlo_8_struct *kerstr,
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
      c_gpu_sort_one_grid_x_vlo_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_x_vlo_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_z_8_init(c_pscmc_env *pe,
                             c_sort_one_grid_z_8_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_z_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_z_8_struct));
}
int c_sort_one_grid_z_8_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_z_8_get_num_compute_units(
    c_sort_one_grid_z_8_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_z_8_exec(c_sort_one_grid_z_8_struct *kerstr,
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
      c_sort_one_grid_z_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_numvec(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_init(c_pscmc_env *pe,
                                 c_gpu_sort_one_grid_z_8_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_z_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_z_8_struct));
}
int c_gpu_sort_one_grid_z_8_get_xlen() { return 32; }
int c_gpu_sort_one_grid_z_8_get_num_compute_units(
    c_gpu_sort_one_grid_z_8_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_z_8_exec(c_gpu_sort_one_grid_z_8_struct *kerstr,
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
      c_gpu_sort_one_grid_z_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_z_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_y_8_init(c_pscmc_env *pe,
                             c_sort_one_grid_y_8_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_y_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_y_8_struct));
}
int c_sort_one_grid_y_8_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_y_8_get_num_compute_units(
    c_sort_one_grid_y_8_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_y_8_exec(c_sort_one_grid_y_8_struct *kerstr,
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
      c_sort_one_grid_y_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_numvec(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_init(c_pscmc_env *pe,
                                 c_gpu_sort_one_grid_y_8_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_y_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_y_8_struct));
}
int c_gpu_sort_one_grid_y_8_get_xlen() { return 32; }
int c_gpu_sort_one_grid_y_8_get_num_compute_units(
    c_gpu_sort_one_grid_y_8_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_y_8_exec(c_gpu_sort_one_grid_y_8_struct *kerstr,
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
      c_gpu_sort_one_grid_y_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_y_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_x_8_init(c_pscmc_env *pe,
                             c_sort_one_grid_x_8_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_x_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_x_8_struct));
}
int c_sort_one_grid_x_8_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_x_8_get_num_compute_units(
    c_sort_one_grid_x_8_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_x_8_exec(c_sort_one_grid_x_8_struct *kerstr,
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
      c_sort_one_grid_x_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_numvec(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_init(c_pscmc_env *pe,
                                 c_gpu_sort_one_grid_x_8_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_x_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_x_8_struct));
}
int c_gpu_sort_one_grid_x_8_get_xlen() { return 32; }
int c_gpu_sort_one_grid_x_8_get_num_compute_units(
    c_gpu_sort_one_grid_x_8_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_x_8_exec(c_gpu_sort_one_grid_x_8_struct *kerstr,
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
      c_gpu_sort_one_grid_x_8_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_x_8_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_init(c_pscmc_env *pe,
                                 c_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_z_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_z_vlo_6_struct));
}
int c_sort_one_grid_z_vlo_6_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_z_vlo_6_get_num_compute_units(
    c_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_z_vlo_6_exec(c_sort_one_grid_z_vlo_6_struct *kerstr,
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
      c_sort_one_grid_z_vlo_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_init(
    c_pscmc_env *pe, c_gpu_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_z_vlo_6_struct));
}
int c_gpu_sort_one_grid_z_vlo_6_get_xlen() { return 32; }
int c_gpu_sort_one_grid_z_vlo_6_get_num_compute_units(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_z_vlo_6_exec(c_gpu_sort_one_grid_z_vlo_6_struct *kerstr,
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
      c_gpu_sort_one_grid_z_vlo_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_z_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_init(c_pscmc_env *pe,
                                 c_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_y_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_y_vlo_6_struct));
}
int c_sort_one_grid_y_vlo_6_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_y_vlo_6_get_num_compute_units(
    c_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_y_vlo_6_exec(c_sort_one_grid_y_vlo_6_struct *kerstr,
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
      c_sort_one_grid_y_vlo_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_init(
    c_pscmc_env *pe, c_gpu_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_y_vlo_6_struct));
}
int c_gpu_sort_one_grid_y_vlo_6_get_xlen() { return 32; }
int c_gpu_sort_one_grid_y_vlo_6_get_num_compute_units(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_y_vlo_6_exec(c_gpu_sort_one_grid_y_vlo_6_struct *kerstr,
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
      c_gpu_sort_one_grid_y_vlo_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_y_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_init(c_pscmc_env *pe,
                                 c_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_x_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_x_vlo_6_struct));
}
int c_sort_one_grid_x_vlo_6_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_x_vlo_6_get_num_compute_units(
    c_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_x_vlo_6_exec(c_sort_one_grid_x_vlo_6_struct *kerstr,
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
      c_sort_one_grid_x_vlo_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_init(
    c_pscmc_env *pe, c_gpu_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_x_vlo_6_struct));
}
int c_gpu_sort_one_grid_x_vlo_6_get_xlen() { return 32; }
int c_gpu_sort_one_grid_x_vlo_6_get_num_compute_units(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_x_vlo_6_exec(c_gpu_sort_one_grid_x_vlo_6_struct *kerstr,
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
      c_gpu_sort_one_grid_x_vlo_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_x_vlo_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_z_6_init(c_pscmc_env *pe,
                             c_sort_one_grid_z_6_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_z_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_z_6_struct));
}
int c_sort_one_grid_z_6_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_z_6_get_num_compute_units(
    c_sort_one_grid_z_6_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_z_6_exec(c_sort_one_grid_z_6_struct *kerstr,
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
      c_sort_one_grid_z_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_numvec(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_init(c_pscmc_env *pe,
                                 c_gpu_sort_one_grid_z_6_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_z_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_z_6_struct));
}
int c_gpu_sort_one_grid_z_6_get_xlen() { return 32; }
int c_gpu_sort_one_grid_z_6_get_num_compute_units(
    c_gpu_sort_one_grid_z_6_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_z_6_exec(c_gpu_sort_one_grid_z_6_struct *kerstr,
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
      c_gpu_sort_one_grid_z_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_z_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_y_6_init(c_pscmc_env *pe,
                             c_sort_one_grid_y_6_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_y_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_y_6_struct));
}
int c_sort_one_grid_y_6_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_y_6_get_num_compute_units(
    c_sort_one_grid_y_6_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_y_6_exec(c_sort_one_grid_y_6_struct *kerstr,
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
      c_sort_one_grid_y_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_numvec(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_init(c_pscmc_env *pe,
                                 c_gpu_sort_one_grid_y_6_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_y_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_y_6_struct));
}
int c_gpu_sort_one_grid_y_6_get_xlen() { return 32; }
int c_gpu_sort_one_grid_y_6_get_num_compute_units(
    c_gpu_sort_one_grid_y_6_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_y_6_exec(c_gpu_sort_one_grid_y_6_struct *kerstr,
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
      c_gpu_sort_one_grid_y_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_y_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_sort_one_grid_x_6_init(c_pscmc_env *pe,
                             c_sort_one_grid_x_6_struct *kerstr) {
  return 0;
}
void c_sort_one_grid_x_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_sort_one_grid_x_6_struct));
}
int c_sort_one_grid_x_6_get_xlen() { return IDX_OPT_MAX; }
int c_sort_one_grid_x_6_get_num_compute_units(
    c_sort_one_grid_x_6_struct *kerstr) {
  return 1;
}
int c_sort_one_grid_x_6_exec(c_sort_one_grid_x_6_struct *kerstr,
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
      c_sort_one_grid_x_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_numvec(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    c_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_init(c_pscmc_env *pe,
                                 c_gpu_sort_one_grid_x_6_struct *kerstr) {
  return 0;
}
void c_gpu_sort_one_grid_x_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(c_gpu_sort_one_grid_x_6_struct));
}
int c_gpu_sort_one_grid_x_6_get_xlen() { return 32; }
int c_gpu_sort_one_grid_x_6_get_num_compute_units(
    c_gpu_sort_one_grid_x_6_struct *kerstr) {
  return 1;
}
int c_gpu_sort_one_grid_x_6_exec(c_gpu_sort_one_grid_x_6_struct *kerstr,
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
      c_gpu_sort_one_grid_x_6_scmc_kernel(
          (kerstr)->inoutput, (kerstr)->xyzw, (kerstr)->cu_cache,
          (kerstr)->cu_xyzw, (kerstr)->adjoint_vec_pids, ((kerstr)->XLEN)[0],
          ((kerstr)->YLEN)[0], ((kerstr)->ZLEN)[0], ((kerstr)->ovlp)[0],
          ((kerstr)->numvec)[0], ((kerstr)->grid_cache_len)[0],
          ((kerstr)->cu_cache_length)[0], yid, scmc_internal_g_ylen);
    }
  }
  return 0;
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->inoutput = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_xyzw = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->adjoint_vec_pids = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->XLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->YLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ZLEN = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->ovlp = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->numvec = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->grid_cache_len = pm->d_data);
}
int c_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    c_gpu_sort_one_grid_x_6_struct *kerstr, c_pscmc_mem *pm) {
  ((kerstr)->cu_cache_length = pm->d_data);
}

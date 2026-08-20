#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "run_particle_call_fun.h"

#if defined(SYMPIC_CUDA) && defined(SYMPIC_MAPU)
#error "Only one backend can be enabled: SYMPIC_CUDA or SYMPIC_MAPU"
#endif

#if !defined(SYMPIC_CUDA) && !defined(SYMPIC_MAPU)
#error "Please define SYMPIC_CUDA or SYMPIC_MAPU"
#endif

#if defined(SYMPIC_CUDA)
#include "cuda_/cuda_pscmc_inc.h"
#include "cuda_/inner_split_pass.kernel_inc.h"
/*
 * The generated CUDA runtime definitions are usually emitted with extern "C".
 * Wrap the generated runtime header here so C++ compilation of this file uses
 * the same linkage.
 */
#ifdef __cplusplus
extern "C" {
#endif
#if defined(__has_include)
#if __has_include("cuda_/inner_split_pass.kernel_runtime.h")
#include "cuda_/inner_split_pass.kernel_runtime.h"
#else
#include "cuda_/inner_split_pass_runtime.h"
#endif
#else
#include "cuda_/inner_split_pass.kernel_runtime.h"
#endif
#ifdef __cplusplus
}
#endif
#endif

#if defined(SYMPIC_MAPU)

#ifdef __cplusplus
extern "C" {
#endif
#include "mapu_/mapu_pscmc.h"
#ifdef __cplusplus
}
#endif

#include "mapu_/inner_split_pass.kernel_runtime.h"
#endif

/* ========================================================================== */
/* CUDA backend                                                               */
/* ========================================================================== */
#if defined(SYMPIC_CUDA)

int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC) {

  Field3D_Seq *pfield = pthis->pfield;
  void **nonrel_test_kernel = pthis->nonrel_test_kernel;

  long grid_cache_len = pthis->grid_cache_len;
  long cu_cache_length = pthis->cu_cache_length;

  void *inoutput = pthis->inoutput;
  void *xyzw = pthis->xyzw;
  void *cu_cache = pthis->cu_cache;
  void *cu_xyzw = pthis->cu_xyzw;

  cuda_pscmc_env *pe = (cuda_pscmc_env *)pfield->pe;
  cuda_geo_nr_Bfield_pushJ_vlo_struct *ker =
      (cuda_geo_nr_Bfield_pushJ_vlo_struct *)nonrel_test_kernel[0];

  long XLEN = pfield->xlen;
  long YLEN = pfield->ylen;
  long ZLEN = pfield->zlen;
  long numvec = pfield->numvec;

  int ovlp = pfield->ovlp;
  int num_ele = pfield->num_ele;

  void *xoffset = pfield->xoffset;
  void *yoffset = pfield->yoffset;
  void *zoffset = pfield->zoffset;

  double DELTA_X = pfield->delta_x;
  double DELTA_Y = pfield->delta_y;
  double DELTA_Z = pfield->delta_z;

  double Mass0 = Mass0_lst_fix;
  double Charge0 = Charge0_lst_fix;

  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput(
      ker, (cuda_pscmc_mem *)inoutput);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE(
      ker, (cuda_pscmc_mem *)fieldE->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB(
      ker, (cuda_pscmc_mem *)fieldB->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1(
      ker, (cuda_pscmc_mem *)fieldB1->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ(
      ker, (cuda_pscmc_mem *)FoutJ->main_data);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw(ker,
                                                       (cuda_pscmc_mem *)xyzw);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache(
      ker, (cuda_pscmc_mem *)cu_cache);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw(
      ker, (cuda_pscmc_mem *)cu_xyzw);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset(
      ker, (cuda_pscmc_mem *)xoffset);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset(
      ker, (cuda_pscmc_mem *)yoffset);
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset(
      ker, (cuda_pscmc_mem *)zoffset);

  cuda_pscmc_mem cuda_alloc_prefix_XLEN;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_XLEN, PS_LONG_NUM, 0);
  ((long *)cuda_alloc_prefix_XLEN.h_data)[0] = XLEN;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN(ker,
                                                       &cuda_alloc_prefix_XLEN);

  cuda_pscmc_mem cuda_alloc_prefix_YLEN;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_YLEN, PS_LONG_NUM, 0);
  ((long *)cuda_alloc_prefix_YLEN.h_data)[0] = YLEN;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN(ker,
                                                       &cuda_alloc_prefix_YLEN);

  cuda_pscmc_mem cuda_alloc_prefix_ZLEN;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_ZLEN, PS_LONG_NUM, 0);
  ((long *)cuda_alloc_prefix_ZLEN.h_data)[0] = ZLEN;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN(ker,
                                                       &cuda_alloc_prefix_ZLEN);

  cuda_pscmc_mem cuda_alloc_prefix_ovlp;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_ovlp, PS_INT_NUM, 0);
  ((int *)cuda_alloc_prefix_ovlp.h_data)[0] = ovlp;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp(ker,
                                                       &cuda_alloc_prefix_ovlp);

  cuda_pscmc_mem cuda_alloc_prefix_numvec;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_numvec, PS_LONG_NUM, 0);
  ((long *)cuda_alloc_prefix_numvec.h_data)[0] = numvec;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec(
      ker, &cuda_alloc_prefix_numvec);

  cuda_pscmc_mem cuda_alloc_prefix_num_ele;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_num_ele, PS_INT_NUM, 0);
  ((int *)cuda_alloc_prefix_num_ele.h_data)[0] = num_ele;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele(
      ker, &cuda_alloc_prefix_num_ele);

  cuda_pscmc_mem cuda_alloc_prefix_grid_cache_len;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_grid_cache_len, PS_LONG_NUM, 0);
  ((long *)cuda_alloc_prefix_grid_cache_len.h_data)[0] = grid_cache_len;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len(
      ker, &cuda_alloc_prefix_grid_cache_len);

  cuda_pscmc_mem cuda_alloc_prefix_cu_cache_length;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_cu_cache_length, PS_LONG_NUM, 0);
  ((long *)cuda_alloc_prefix_cu_cache_length.h_data)[0] = cu_cache_length;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length(
      ker, &cuda_alloc_prefix_cu_cache_length);

  cuda_pscmc_mem cuda_alloc_prefix_DELTA_X;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_DELTA_X, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_DELTA_X.h_data)[0] = DELTA_X;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X(
      ker, &cuda_alloc_prefix_DELTA_X);

  cuda_pscmc_mem cuda_alloc_prefix_DELTA_Y;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_DELTA_Y, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_DELTA_Y.h_data)[0] = DELTA_Y;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y(
      ker, &cuda_alloc_prefix_DELTA_Y);

  cuda_pscmc_mem cuda_alloc_prefix_DELTA_Z;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_DELTA_Z, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_DELTA_Z.h_data)[0] = DELTA_Z;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z(
      ker, &cuda_alloc_prefix_DELTA_Z);

  cuda_pscmc_mem cuda_alloc_prefix_Mass0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_Mass0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_Mass0.h_data)[0] = Mass0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0(
      ker, &cuda_alloc_prefix_Mass0);

  cuda_pscmc_mem cuda_alloc_prefix_Charge0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_Charge0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_Charge0.h_data)[0] = Charge0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0(
      ker, &cuda_alloc_prefix_Charge0);

  cuda_pscmc_mem cuda_alloc_prefix_Deltat;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_Deltat, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_Deltat.h_data)[0] = Deltat;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat(
      ker, &cuda_alloc_prefix_Deltat);

  cuda_pscmc_mem cuda_alloc_prefix_Tori_X0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_Tori_X0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_Tori_X0.h_data)[0] = Tori_X0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0(
      ker, &cuda_alloc_prefix_Tori_X0);

  cuda_pscmc_mem cuda_alloc_prefix_r0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_r0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_r0.h_data)[0] = r0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0(ker,
                                                     &cuda_alloc_prefix_r0);

  cuda_pscmc_mem cuda_alloc_prefix_MIN_R0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_MIN_R0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_MIN_R0.h_data)[0] = MIN_R0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0(
      ker, &cuda_alloc_prefix_MIN_R0);

  cuda_pscmc_mem cuda_alloc_prefix_Q0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_Q0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_Q0.h_data)[0] = Q0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0(ker,
                                                     &cuda_alloc_prefix_Q0);

  cuda_pscmc_mem cuda_alloc_prefix_b0;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_b0, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_b0.h_data)[0] = b0;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0(ker,
                                                     &cuda_alloc_prefix_b0);

  cuda_pscmc_mem cuda_alloc_prefix_zmid;
  cuda_pscmc_mem_init(pe, &cuda_alloc_prefix_zmid, PS_DOUBLE_NUM, 0);
  ((double *)cuda_alloc_prefix_zmid.h_data)[0] = zmid;
  cuda_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid(ker,
                                                       &cuda_alloc_prefix_zmid);

  cuda_geo_nr_Bfield_pushJ_vlo_exec(
      ker, cuda_geo_nr_Bfield_pushJ_vlo_get_xlen(), numvec);

  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_XLEN);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_YLEN);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_ZLEN);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_ovlp);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_numvec);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_num_ele);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_grid_cache_len);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_cu_cache_length);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_DELTA_X);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_DELTA_Y);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_DELTA_Z);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_Mass0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_Charge0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_Deltat);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_Tori_X0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_r0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_MIN_R0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_Q0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_b0);
  cuda_pscmc_mem_destroy(&cuda_alloc_prefix_zmid);

  return 0;
}

#endif /* SYMPIC_CUDA */

/* ========================================================================== */
/* MAPU backend                                                               */
/* ========================================================================== */
#if defined(SYMPIC_MAPU)

int mapu_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC) {

  Field3D_Seq *pfield = pthis->pfield;
  void **nonrel_test_kernel = pthis->nonrel_test_kernel;

  long grid_cache_len = pthis->grid_cache_len;
  long cu_cache_length = pthis->cu_cache_length;

  void *inoutput = pthis->inoutput;
  void *xyzw = pthis->xyzw;
  void *cu_cache = pthis->cu_cache;
  void *cu_xyzw = pthis->cu_xyzw;

  mapu_pscmc_env *pe = (mapu_pscmc_env *)pfield->pe;
  mapu_geo_nr_Bfield_pushJ_vlo_struct *ker =
      (mapu_geo_nr_Bfield_pushJ_vlo_struct *)nonrel_test_kernel[0];

  long XLEN = pfield->xlen;
  long YLEN = pfield->ylen;
  long ZLEN = pfield->zlen;
  long numvec = pfield->numvec;

  int ovlp = pfield->ovlp;
  int num_ele = pfield->num_ele;

  void *xoffset = pfield->xoffset;
  void *yoffset = pfield->yoffset;
  void *zoffset = pfield->zoffset;

  double DELTA_X = pfield->delta_x;
  double DELTA_Y = pfield->delta_y;
  double DELTA_Z = pfield->delta_z;

  double Mass0 = Mass0_lst_fix;
  double Charge0 = Charge0_lst_fix;
  int use_g_e = 0;

  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_inoutput(
      ker, (mapu_pscmc_mem *)inoutput);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xyzw(ker,
                                                       (mapu_pscmc_mem *)xyzw);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache(
      ker, (mapu_pscmc_mem *)cu_cache);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_xyzw(
      ker, (mapu_pscmc_mem *)cu_xyzw);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_xoffset(
      ker, (mapu_pscmc_mem *)xoffset);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_yoffset(
      ker, (mapu_pscmc_mem *)yoffset);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zoffset(
      ker, (mapu_pscmc_mem *)zoffset);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE(
      ker, (mapu_pscmc_mem *)fieldE->main_data);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldE_ext(
      ker, (mapu_pscmc_mem *)fieldE->main_data);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB(
      ker, (mapu_pscmc_mem *)fieldB->main_data);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_fieldB1(
      ker, (mapu_pscmc_mem *)fieldB1->main_data);
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_FoutJ(
      ker, (mapu_pscmc_mem *)FoutJ->main_data);

  mapu_pscmc_mem mapu_alloc_prefix_XLEN;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_XLEN, PS_LONG_NUM, 0);
  ((long *)mapu_alloc_prefix_XLEN.h_data)[0] = XLEN;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_XLEN(ker,
                                                       &mapu_alloc_prefix_XLEN);

  mapu_pscmc_mem mapu_alloc_prefix_YLEN;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_YLEN, PS_LONG_NUM, 0);
  ((long *)mapu_alloc_prefix_YLEN.h_data)[0] = YLEN;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_YLEN(ker,
                                                       &mapu_alloc_prefix_YLEN);

  mapu_pscmc_mem mapu_alloc_prefix_ZLEN;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_ZLEN, PS_LONG_NUM, 0);
  ((long *)mapu_alloc_prefix_ZLEN.h_data)[0] = ZLEN;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ZLEN(ker,
                                                       &mapu_alloc_prefix_ZLEN);

  mapu_pscmc_mem mapu_alloc_prefix_ovlp;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_ovlp, PS_INT_NUM, 0);
  ((int *)mapu_alloc_prefix_ovlp.h_data)[0] = ovlp;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_ovlp(ker,
                                                       &mapu_alloc_prefix_ovlp);

  mapu_pscmc_mem mapu_alloc_prefix_numvec;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_numvec, PS_LONG_NUM, 0);
  ((long *)mapu_alloc_prefix_numvec.h_data)[0] = numvec;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_numvec(
      ker, &mapu_alloc_prefix_numvec);

  mapu_pscmc_mem mapu_alloc_prefix_num_ele;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_num_ele, PS_INT_NUM, 0);
  ((int *)mapu_alloc_prefix_num_ele.h_data)[0] = num_ele;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_num_ele(
      ker, &mapu_alloc_prefix_num_ele);

  mapu_pscmc_mem mapu_alloc_prefix_grid_cache_len;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_grid_cache_len, PS_LONG_NUM, 0);
  ((long *)mapu_alloc_prefix_grid_cache_len.h_data)[0] = grid_cache_len;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_grid_cache_len(
      ker, &mapu_alloc_prefix_grid_cache_len);

  mapu_pscmc_mem mapu_alloc_prefix_cu_cache_length;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_cu_cache_length, PS_LONG_NUM, 0);
  ((long *)mapu_alloc_prefix_cu_cache_length.h_data)[0] = cu_cache_length;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_cu_cache_length(
      ker, &mapu_alloc_prefix_cu_cache_length);

  mapu_pscmc_mem mapu_alloc_prefix_use_g_e;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_use_g_e, PS_INT_NUM, 0);
  ((int *)mapu_alloc_prefix_use_g_e.h_data)[0] = use_g_e;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_use_g_e(
      ker, &mapu_alloc_prefix_use_g_e);

  mapu_pscmc_mem mapu_alloc_prefix_DELTA_X;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_DELTA_X, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_DELTA_X.h_data)[0] = DELTA_X;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_X(
      ker, &mapu_alloc_prefix_DELTA_X);

  mapu_pscmc_mem mapu_alloc_prefix_DELTA_Y;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_DELTA_Y, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_DELTA_Y.h_data)[0] = DELTA_Y;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Y(
      ker, &mapu_alloc_prefix_DELTA_Y);

  mapu_pscmc_mem mapu_alloc_prefix_DELTA_Z;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_DELTA_Z, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_DELTA_Z.h_data)[0] = DELTA_Z;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_DELTA_Z(
      ker, &mapu_alloc_prefix_DELTA_Z);

  mapu_pscmc_mem mapu_alloc_prefix_Mass0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_Mass0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_Mass0.h_data)[0] = Mass0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Mass0(
      ker, &mapu_alloc_prefix_Mass0);

  mapu_pscmc_mem mapu_alloc_prefix_Charge0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_Charge0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_Charge0.h_data)[0] = Charge0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Charge0(
      ker, &mapu_alloc_prefix_Charge0);

  mapu_pscmc_mem mapu_alloc_prefix_Deltat;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_Deltat, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_Deltat.h_data)[0] = Deltat;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Deltat(
      ker, &mapu_alloc_prefix_Deltat);

  mapu_pscmc_mem mapu_alloc_prefix_Tori_X0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_Tori_X0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_Tori_X0.h_data)[0] = Tori_X0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Tori_X0(
      ker, &mapu_alloc_prefix_Tori_X0);

  mapu_pscmc_mem mapu_alloc_prefix_r0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_r0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_r0.h_data)[0] = r0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_r0(ker,
                                                     &mapu_alloc_prefix_r0);

  mapu_pscmc_mem mapu_alloc_prefix_MIN_R0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_MIN_R0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_MIN_R0.h_data)[0] = MIN_R0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_MIN_R0(
      ker, &mapu_alloc_prefix_MIN_R0);

  mapu_pscmc_mem mapu_alloc_prefix_Q0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_Q0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_Q0.h_data)[0] = Q0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_Q0(ker,
                                                     &mapu_alloc_prefix_Q0);

  mapu_pscmc_mem mapu_alloc_prefix_b0;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_b0, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_b0.h_data)[0] = b0;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_b0(ker,
                                                     &mapu_alloc_prefix_b0);

  mapu_pscmc_mem mapu_alloc_prefix_zmid;
  mapu_pscmc_mem_init(pe, &mapu_alloc_prefix_zmid, PS_DOUBLE_NUM, 0);
  ((double *)mapu_alloc_prefix_zmid.h_data)[0] = zmid;
  mapu_geo_nr_Bfield_pushJ_vlo_scmc_set_parameter_zmid(ker,
                                                       &mapu_alloc_prefix_zmid);

  mapu_geo_nr_Bfield_pushJ_vlo_exec(
      ker, mapu_geo_nr_Bfield_pushJ_vlo_get_xlen(), numvec);

  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_XLEN);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_YLEN);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_ZLEN);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_ovlp);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_numvec);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_num_ele);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_grid_cache_len);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_cu_cache_length);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_use_g_e);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_DELTA_X);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_DELTA_Y);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_DELTA_Z);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_Mass0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_Charge0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_Deltat);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_Tori_X0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_r0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_MIN_R0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_Q0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_b0);
  mapu_pscmc_mem_destroy(&mapu_alloc_prefix_zmid);

  return 0;
}

#endif /* SYMPIC_MAPU */

/* ========================================================================== */
/* Unified upper-level wrapper                                                */
/* ========================================================================== */

int One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec) {
#if defined(SYMPIC_CUDA)
  return cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
      pthis, fieldE, fieldB, fieldB1, FoutJ, Mass0_lst_fix, Charge0_lst_fix,
      Deltat, Tori_X0, r0, MIN_R0, Q0, b0, zmid, spec, num_spec);
#elif defined(SYMPIC_MAPU)
  return mapu_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
      pthis, fieldE, fieldB, fieldB1, FoutJ, Mass0_lst_fix, Charge0_lst_fix,
      Deltat, Tori_X0, r0, MIN_R0, Q0, b0, zmid, spec, num_spec);
#else
#error "Please define SYMPIC_CUDA or SYMPIC_MAPU"
#endif
}

/* ========================================================================== */
/* MPI-level wrapper: keeps the original upper call path unchanged */
/* ========================================================================== */

int MPI_geo_nr_Bfield_pushJ_vlo(Particle_in_Cell_MPI *pthis,
                                Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
                                double *Mass0, double *Charge0, double Deltat,
                                double Tori_X0, double r0, double MIN_R0,
                                double Q0, double b0, double zmid) {

  Field3D_MPI MPI_fieldE = pthis->MPI_fieldE;
  int *o_particle_type = pthis->o_particle_type;

  int num_spec = MPI_fieldE.num_spec;
  int num_runtime = MPI_fieldE.num_runtime;

  for (long i = 0; i < (num_runtime * num_spec); i++) {
    int cur_spec = (int)(i / num_runtime);

    if (o_particle_type[cur_spec] == 0) {
      One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
          MPI_fieldE.particles + i, fieldE->data + (i % num_runtime),
          fieldB->data + (i % num_runtime), fieldB1->data + (i % num_runtime),
          FoutJ->data + (i % num_runtime), Mass0[i / num_runtime],
          Charge0[i / num_runtime], Deltat, Tori_X0, r0, MIN_R0, Q0, b0, zmid,
          cur_spec, num_spec);
    }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local_header.h"
#include "inner_split_pass.kernel_runtime.h"

#include "inner_split_pass.kernel.inc"


  
int mapu_geo_nr_Bfield_pushJ_vlo_init(
    mapu_pscmc_env *pe,
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr) {
  memset(kerstr, 0, sizeof(*kerstr));
  kerstr->pe = pe;
  mapu_geo_nr_Bfield_pushJ_vlo_set_device(kerstr);
  return 0;
}

long mapu_geo_nr_Bfield_pushJ_vlo_get_struct_len(void) {
  return (long)sizeof(mapu_geo_nr_Bfield_pushJ_vlo_struct);
}

long mapu_geo_nr_Bfield_pushJ_vlo_get_xlen(void) {
  return 1;
}

long mapu_geo_nr_Bfield_pushJ_vlo_get_num_compute_units(void) {
  return 64;
}

MAPU_DEFINE_SET_PARAM(inoutput)
MAPU_DEFINE_SET_PARAM(xyzw)
MAPU_DEFINE_SET_PARAM(cu_cache)
MAPU_DEFINE_SET_PARAM(cu_xyzw)
MAPU_DEFINE_SET_PARAM(xoffset)
MAPU_DEFINE_SET_PARAM(yoffset)
MAPU_DEFINE_SET_PARAM(zoffset)
MAPU_DEFINE_SET_PARAM(fieldE)
MAPU_DEFINE_SET_PARAM(fieldE_ext)
MAPU_DEFINE_SET_PARAM(fieldB)
MAPU_DEFINE_SET_PARAM(fieldB1)
MAPU_DEFINE_SET_PARAM(FoutJ)
MAPU_DEFINE_SET_PARAM(XLEN)
MAPU_DEFINE_SET_PARAM(YLEN)
MAPU_DEFINE_SET_PARAM(ZLEN)
MAPU_DEFINE_SET_PARAM(ovlp)
MAPU_DEFINE_SET_PARAM(numvec)
MAPU_DEFINE_SET_PARAM(num_ele)
MAPU_DEFINE_SET_PARAM(grid_cache_len)
MAPU_DEFINE_SET_PARAM(cu_cache_length)
MAPU_DEFINE_SET_PARAM(use_g_e)
MAPU_DEFINE_SET_PARAM(DELTA_X)
MAPU_DEFINE_SET_PARAM(DELTA_Y)
MAPU_DEFINE_SET_PARAM(DELTA_Z)
MAPU_DEFINE_SET_PARAM(Mass0)
MAPU_DEFINE_SET_PARAM(Charge0)
MAPU_DEFINE_SET_PARAM(Deltat)
MAPU_DEFINE_SET_PARAM(Tori_X0)
MAPU_DEFINE_SET_PARAM(r0)
MAPU_DEFINE_SET_PARAM(MIN_R0)
MAPU_DEFINE_SET_PARAM(Q0)
MAPU_DEFINE_SET_PARAM(b0)
MAPU_DEFINE_SET_PARAM(zmid)
  
int mapu_geo_nr_Bfield_pushJ_vlo_exec(
    mapu_geo_nr_Bfield_pushJ_vlo_struct *kerstr,
    long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {

  mapu_geo_nr_Bfield_pushJ_vlo_set_device(kerstr);

  mapu_pscmc_mem *fieldE_ext_pm = kerstr->fieldE_ext ? kerstr->fieldE_ext : kerstr->fieldE;

  MAPU_LONG XLEN_v            = (MAPU_LONG)MAPU_HVAL(long, kerstr->XLEN);
  MAPU_LONG YLEN_v            = (MAPU_LONG)MAPU_HVAL(long, kerstr->YLEN);
  MAPU_LONG ZLEN_v            = (MAPU_LONG)MAPU_HVAL(long, kerstr->ZLEN);
  int       ovlp_v            = MAPU_HVAL(int, kerstr->ovlp);
  MAPU_LONG numvec_v          = (MAPU_LONG)MAPU_HVAL(long, kerstr->numvec);
  int       num_ele_v         = MAPU_HVAL(int, kerstr->num_ele);
  MAPU_LONG grid_cache_len_v  = (MAPU_LONG)MAPU_HVAL(long, kerstr->grid_cache_len);
  MAPU_LONG cu_cache_length_v = (MAPU_LONG)MAPU_HVAL(long, kerstr->cu_cache_length);
  int       use_g_e_v         = MAPU_HVAL_OR(int, kerstr->use_g_e, 0);
  double    DELTA_X_v         = MAPU_HVAL(double, kerstr->DELTA_X);
  double    DELTA_Y_v         = MAPU_HVAL(double, kerstr->DELTA_Y);
  double    DELTA_Z_v         = MAPU_HVAL(double, kerstr->DELTA_Z);
  double    Mass0_v           = MAPU_HVAL(double, kerstr->Mass0);
  double    Charge0_v         = MAPU_HVAL(double, kerstr->Charge0);
  double    Deltat_v          = MAPU_HVAL(double, kerstr->Deltat);
  double    Tori_X0_v         = MAPU_HVAL(double, kerstr->Tori_X0);
  double    r0_v              = MAPU_HVAL(double, kerstr->r0);
  double    MIN_R0_v          = MAPU_HVAL(double, kerstr->MIN_R0);
  double    Q0_v              = MAPU_HVAL(double, kerstr->Q0);
  double    b0_v              = MAPU_HVAL(double, kerstr->b0);
  double    zmid_v            = MAPU_HVAL(double, kerstr->zmid);

#define MAPU_GEO_NR_BFIELD_PUSHJ_VLO_ARGS                                             \
      MAPU_DDR_PTR(double, kerstr->inoutput),                                         \
      MAPU_DDR_PTR(int,    kerstr->xyzw),                                             \
      MAPU_DDR_PTR(double, kerstr->cu_cache),                                         \
      MAPU_DDR_PTR(int,    kerstr->cu_xyzw),                                          \
      MAPU_DDR_PTR(int,    kerstr->xoffset),                                          \
      MAPU_DDR_PTR(int,    kerstr->yoffset),                                          \
      MAPU_DDR_PTR(int,    kerstr->zoffset),                                          \
      MAPU_DDR_PTR(double, kerstr->fieldE),                                           \
      MAPU_DDR_PTR(double, fieldE_ext_pm),                                            \
      MAPU_DDR_PTR(double, kerstr->fieldB),                                           \
      MAPU_DDR_PTR(double, kerstr->fieldB1),                                          \
      MAPU_DDR_PTR(double, kerstr->FoutJ),                                            \
      XLEN_v, YLEN_v, ZLEN_v, ovlp_v, numvec_v, num_ele_v,                            \
      grid_cache_len_v, cu_cache_length_v, use_g_e_v,                                 \
      DELTA_X_v, DELTA_Y_v, DELTA_Z_v, Mass0_v, Charge0_v, Deltat_v,                  \
      Tori_X0_v, r0_v, MIN_R0_v, Q0_v, b0_v, zmid_v

    if (scmc_internal_g_ylen < 65536) {
    mapu_geo_nr_Bfield_pushJ_vlo<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        MAPU_GEO_NR_BFIELD_PUSHJ_VLO_ARGS);
  } else {
    dim3 gridDim(65535, (unsigned int)((scmc_internal_g_ylen + 65534) / 65535), 1);
    dim3 blockDim((unsigned int)scmc_internal_g_xlen, 1, 1);
    mapu_geo_nr_Bfield_pushJ_vlo<<<gridDim, blockDim>>>(
        MAPU_GEO_NR_BFIELD_PUSHJ_VLO_ARGS);
  }

#undef MAPU_GEO_NR_BFIELD_PUSHJ_VLO_ARGS

  return 0;
}


#undef MAPU_DEFINE_SET_PARAM
#undef MAPU_HVAL_OR
#undef MAPU_HVAL
#undef MAPU_DDR_PTR

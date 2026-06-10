#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "cuda_pscmc_inc.h"

#include "mergefields.kernel_inc.h"

#include "mergefields.kernel.cu"

extern "C" {
int cuda_merge_ovlp_m2o_once_init(cuda_pscmc_env *pe,
                                  cuda_merge_ovlp_m2o_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_ovlp_m2o_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_ovlp_m2o_once_struct));
}
int cuda_merge_ovlp_m2o_once_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_ovlp_m2o_once_get_num_compute_units(
    cuda_merge_ovlp_m2o_once_struct *kerstr) {
  return 64;
}
int cuda_merge_ovlp_m2o_once_exec(cuda_merge_ovlp_m2o_once_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_ovlp_m2o_once<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_merge_ovlp_m2o_once<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_merge_ovlp_m2o_once");
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp0(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp0 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp1(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp1 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp2(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp2 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp3(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp3 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp4(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp4 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp5(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp5 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp6(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp6 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp7(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp7 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp8(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp8 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp9(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp9 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp10(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp10 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp11(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp11 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp12(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp12 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp14(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp14 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp15(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp15 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp16(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp16 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp17(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp17 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp18(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp18 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp19(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp19 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp20(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp20 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp21(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp21 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp22(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp22 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp23(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp23 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp24(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp24 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp25(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp25 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp26(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp26 = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_numvec(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_xblock(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_yblock(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_zblock(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_once_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_init(
    cuda_pscmc_env *pe, cuda_merge_ovlp_m2o_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_ovlp_m2o_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_ovlp_m2o_all_in_one_struct));
}
int cuda_merge_ovlp_m2o_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_ovlp_m2o_all_in_one_get_num_compute_units(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr) {
  return 64;
}
int cuda_merge_ovlp_m2o_all_in_one_exec(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_ovlp_m2o_all_in_one<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_merge_ovlp_m2o_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_merge_ovlp_m2o_all_in_one");
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlps = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_init(cuda_pscmc_env *pe,
                             cuda_merge_ovlp_m2o_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_ovlp_m2o_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_ovlp_m2o_struct));
}
int cuda_merge_ovlp_m2o_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_ovlp_m2o_get_num_compute_units(
    cuda_merge_ovlp_m2o_struct *kerstr) {
  return 64;
}
int cuda_merge_ovlp_m2o_exec(cuda_merge_ovlp_m2o_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_ovlp_m2o<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_merge_ovlp_m2o<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_merge_ovlp_m2o");
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_vecovlp(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_ovlpindex(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlpindex = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_numvec(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_xblock(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_yblock(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_zblock(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_ovlp_m2o_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_init(cuda_pscmc_env *pe,
                                  cuda_merge_ovlp_o2m_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_ovlp_o2m_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_ovlp_o2m_once_struct));
}
int cuda_merge_ovlp_o2m_once_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_ovlp_o2m_once_get_num_compute_units(
    cuda_merge_ovlp_o2m_once_struct *kerstr) {
  return 64;
}
int cuda_merge_ovlp_o2m_once_exec(cuda_merge_ovlp_o2m_once_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_ovlp_o2m_once<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_merge_ovlp_o2m_once<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_merge_ovlp_o2m_once");
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp0(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp0 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp1(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp1 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp2(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp2 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp3(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp3 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp4(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp4 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp5(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp5 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp6(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp6 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp7(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp7 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp8(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp8 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp9(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp9 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp10(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp10 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp11(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp11 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp12(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp12 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp14(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp14 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp15(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp15 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp16(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp16 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp17(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp17 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp18(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp18 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp19(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp19 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp20(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp20 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp21(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp21 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp22(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp22 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp23(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp23 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp24(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp24 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp25(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp25 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp26(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp26 = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_numvec(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_xblock(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_yblock(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_zblock(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_once_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_init(
    cuda_pscmc_env *pe, cuda_merge_ovlp_o2m_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_ovlp_o2m_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_ovlp_o2m_all_in_one_struct));
}
int cuda_merge_ovlp_o2m_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_ovlp_o2m_all_in_one_get_num_compute_units(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr) {
  return 64;
}
int cuda_merge_ovlp_o2m_all_in_one_exec(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_ovlp_o2m_all_in_one<<<scmc_internal_g_ylen,
                                     scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_merge_ovlp_o2m_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_merge_ovlp_o2m_all_in_one");
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlps = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_init(cuda_pscmc_env *pe,
                             cuda_merge_ovlp_o2m_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_merge_ovlp_o2m_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_merge_ovlp_o2m_struct));
}
int cuda_merge_ovlp_o2m_get_xlen() { return IDX_OPT_MAX; }
int cuda_merge_ovlp_o2m_get_num_compute_units(
    cuda_merge_ovlp_o2m_struct *kerstr) {
  return 64;
}
int cuda_merge_ovlp_o2m_exec(cuda_merge_ovlp_o2m_struct *kerstr,
                             long scmc_internal_g_xlen,
                             long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_merge_ovlp_o2m<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_merge_ovlp_o2m<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_merge_ovlp_o2m");
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_vecmain(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_vecovlp(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_ovlpindex(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlpindex = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_numvec(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_num_ele(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_xblock(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_yblock(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_zblock(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_merge_ovlp_o2m_scmc_set_parameter_ovlp(
    cuda_merge_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_init(cuda_pscmc_env *pe,
                                 cuda_sync_ovlp_m2o_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sync_ovlp_m2o_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sync_ovlp_m2o_once_struct));
}
int cuda_sync_ovlp_m2o_once_get_xlen() { return IDX_OPT_MAX; }
int cuda_sync_ovlp_m2o_once_get_num_compute_units(
    cuda_sync_ovlp_m2o_once_struct *kerstr) {
  return 64;
}
int cuda_sync_ovlp_m2o_once_exec(cuda_sync_ovlp_m2o_once_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sync_ovlp_m2o_once<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_sync_ovlp_m2o_once<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sync_ovlp_m2o_once");
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp0(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp0 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp1(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp1 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp2(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp2 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp3(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp3 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp4(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp4 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp5(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp5 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp6(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp6 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp7(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp7 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp8(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp8 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp9(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp9 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp10(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp10 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp11(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp11 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp12(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp12 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp14(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp14 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp15(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp15 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp16(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp16 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp17(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp17 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp18(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp18 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp19(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp19 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp20(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp20 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp21(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp21 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp22(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp22 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp23(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp23 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp24(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp24 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp25(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp25 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp26(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp26 = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_numvec(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_xblock(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_yblock(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_zblock(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_once_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_m2o_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_init(
    cuda_pscmc_env *pe, cuda_sync_ovlp_m2o_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sync_ovlp_m2o_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sync_ovlp_m2o_all_in_one_struct));
}
int cuda_sync_ovlp_m2o_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int cuda_sync_ovlp_m2o_all_in_one_get_num_compute_units(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr) {
  return 64;
}
int cuda_sync_ovlp_m2o_all_in_one_exec(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sync_ovlp_m2o_all_in_one<<<scmc_internal_g_ylen,
                                    scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_sync_ovlp_m2o_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sync_ovlp_m2o_all_in_one");
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlps = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_m2o_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_init(cuda_pscmc_env *pe,
                            cuda_sync_ovlp_m2o_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sync_ovlp_m2o_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sync_ovlp_m2o_struct));
}
int cuda_sync_ovlp_m2o_get_xlen() { return IDX_OPT_MAX; }
int cuda_sync_ovlp_m2o_get_num_compute_units(
    cuda_sync_ovlp_m2o_struct *kerstr) {
  return 64;
}
int cuda_sync_ovlp_m2o_exec(cuda_sync_ovlp_m2o_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sync_ovlp_m2o<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_sync_ovlp_m2o<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sync_ovlp_m2o");
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_vecovlp(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_ovlpindex(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlpindex = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_numvec(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_xblock(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_yblock(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_zblock(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_sync_ovlp_m2o_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_m2o_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_init(cuda_pscmc_env *pe,
                                 cuda_sync_ovlp_o2m_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sync_ovlp_o2m_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sync_ovlp_o2m_once_struct));
}
int cuda_sync_ovlp_o2m_once_get_xlen() { return IDX_OPT_MAX; }
int cuda_sync_ovlp_o2m_once_get_num_compute_units(
    cuda_sync_ovlp_o2m_once_struct *kerstr) {
  return 64;
}
int cuda_sync_ovlp_o2m_once_exec(cuda_sync_ovlp_o2m_once_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sync_ovlp_o2m_once<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_sync_ovlp_o2m_once<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp0->d_data),
        ((double *)kerstr->vecovlp1->d_data),
        ((double *)kerstr->vecovlp2->d_data),
        ((double *)kerstr->vecovlp3->d_data),
        ((double *)kerstr->vecovlp4->d_data),
        ((double *)kerstr->vecovlp5->d_data),
        ((double *)kerstr->vecovlp6->d_data),
        ((double *)kerstr->vecovlp7->d_data),
        ((double *)kerstr->vecovlp8->d_data),
        ((double *)kerstr->vecovlp9->d_data),
        ((double *)kerstr->vecovlp10->d_data),
        ((double *)kerstr->vecovlp11->d_data),
        ((double *)kerstr->vecovlp12->d_data),
        ((double *)kerstr->vecovlp14->d_data),
        ((double *)kerstr->vecovlp15->d_data),
        ((double *)kerstr->vecovlp16->d_data),
        ((double *)kerstr->vecovlp17->d_data),
        ((double *)kerstr->vecovlp18->d_data),
        ((double *)kerstr->vecovlp19->d_data),
        ((double *)kerstr->vecovlp20->d_data),
        ((double *)kerstr->vecovlp21->d_data),
        ((double *)kerstr->vecovlp22->d_data),
        ((double *)kerstr->vecovlp23->d_data),
        ((double *)kerstr->vecovlp24->d_data),
        ((double *)kerstr->vecovlp25->d_data),
        ((double *)kerstr->vecovlp26->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sync_ovlp_o2m_once");
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp0(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp0 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp1(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp1 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp2(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp2 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp3(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp3 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp4(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp4 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp5(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp5 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp6(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp6 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp7(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp7 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp8(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp8 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp9(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp9 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp10(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp10 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp11(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp11 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp12(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp12 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp14(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp14 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp15(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp15 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp16(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp16 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp17(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp17 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp18(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp18 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp19(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp19 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp20(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp20 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp21(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp21 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp22(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp22 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp23(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp23 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp24(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp24 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp25(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp25 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp26(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp26 = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_numvec(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_xblock(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_yblock(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_zblock(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_once_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_o2m_once_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_init(
    cuda_pscmc_env *pe, cuda_sync_ovlp_o2m_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sync_ovlp_o2m_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sync_ovlp_o2m_all_in_one_struct));
}
int cuda_sync_ovlp_o2m_all_in_one_get_xlen() { return IDX_OPT_MAX; }
int cuda_sync_ovlp_o2m_all_in_one_get_num_compute_units(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr) {
  return 64;
}
int cuda_sync_ovlp_o2m_all_in_one_exec(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sync_ovlp_o2m_all_in_one<<<scmc_internal_g_ylen,
                                    scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_sync_ovlp_o2m_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlps->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sync_ovlp_o2m_all_in_one");
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlps = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_o2m_all_in_one_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_init(cuda_pscmc_env *pe,
                            cuda_sync_ovlp_o2m_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_sync_ovlp_o2m_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_sync_ovlp_o2m_struct));
}
int cuda_sync_ovlp_o2m_get_xlen() { return IDX_OPT_MAX; }
int cuda_sync_ovlp_o2m_get_num_compute_units(
    cuda_sync_ovlp_o2m_struct *kerstr) {
  return 64;
}
int cuda_sync_ovlp_o2m_exec(cuda_sync_ovlp_o2m_struct *kerstr,
                            long scmc_internal_g_xlen,
                            long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_sync_ovlp_o2m<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_sync_ovlp_o2m<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->vecmain->d_data),
        ((double *)kerstr->vecovlp->d_data),
        (((int *)kerstr->ovlpindex->h_data))[0],
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_sync_ovlp_o2m");
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_vecmain(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecmain = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_vecovlp(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->vecovlp = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_ovlpindex(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlpindex = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_numvec(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_num_ele(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_xblock(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_yblock(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_zblock(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_sync_ovlp_o2m_scmc_set_parameter_ovlp(
    cuda_sync_ovlp_o2m_struct *kerstr, cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
int cuda_yee_local_init(cuda_pscmc_env *pe, cuda_yee_local_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void cuda_yee_local_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(cuda_yee_local_struct));
}
int cuda_yee_local_get_xlen() { return IDX_OPT_MAX; }
int cuda_yee_local_get_num_compute_units(cuda_yee_local_struct *kerstr) {
  return 64;
}
int cuda_yee_local_exec(cuda_yee_local_struct *kerstr,
                        long scmc_internal_g_xlen, long scmc_internal_g_ylen) {
  cudaSetDevice((kerstr->pe)->device_id);
  if (scmc_internal_g_ylen < 65536) {
    cuda_yee_local<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inout->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);

  } else {
    dim3 multiylen = 1;

    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if (rest != 0) {
      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by 64, "
              "__ylen=%ld\n",
              scmc_internal_g_ylen);

    }

    cuda_yee_local<<<multiylen, scmc_internal_g_xlen>>>(
        ((double *)kerstr->inout->d_data),
        (((long *)kerstr->numvec->h_data))[0],
        (((int *)kerstr->num_ele->h_data))[0],
        (((long *)kerstr->xblock->h_data))[0],
        (((long *)kerstr->yblock->h_data))[0],
        (((long *)kerstr->zblock->h_data))[0],
        (((int *)kerstr->ovlp->h_data))[0]);
  }

  cudaError_t err = cudaGetLastError();

  ERROPT(err, "Error in execcuda_yee_local");
  return 0;
}
int cuda_yee_local_scmc_set_parameter_inout(cuda_yee_local_struct *kerstr,
                                            cuda_pscmc_mem *pm) {
  (kerstr->inout = pm);
  return 0;
}
int cuda_yee_local_scmc_set_parameter_numvec(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->numvec = pm);
  return 0;
}
int cuda_yee_local_scmc_set_parameter_num_ele(cuda_yee_local_struct *kerstr,
                                              cuda_pscmc_mem *pm) {
  (kerstr->num_ele = pm);
  return 0;
}
int cuda_yee_local_scmc_set_parameter_xblock(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->xblock = pm);
  return 0;
}
int cuda_yee_local_scmc_set_parameter_yblock(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->yblock = pm);
  return 0;
}
int cuda_yee_local_scmc_set_parameter_zblock(cuda_yee_local_struct *kerstr,
                                             cuda_pscmc_mem *pm) {
  (kerstr->zblock = pm);
  return 0;
}
int cuda_yee_local_scmc_set_parameter_ovlp(cuda_yee_local_struct *kerstr,
                                           cuda_pscmc_mem *pm) {
  (kerstr->ovlp = pm);
  return 0;
}
}
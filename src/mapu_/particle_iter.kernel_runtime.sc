#include "local_header.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "particle_iter.kernel_runtime.h"


#include "particle_iter.kernel.inc"

static int dump_kernel_variables = 0;

extern long _pscmc_mapu_global_dump_kernel_variables,
    _pscmc_mapu_global_dump_times;

int mapu_dump_ene_num_init(mapu_pscmc_env *pe,
                           mapu_dump_ene_num_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_dump_ene_num_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_dump_ene_num_struct));
}
int mapu_dump_ene_num_get_xlen() { return 1; }
int mapu_dump_ene_num_get_num_compute_units(mapu_dump_ene_num_struct *kerstr) {
  return 4;
}
int mapu_dump_ene_num_exec(mapu_dump_ene_num_struct *kerstr,
                           long scmc_internal_g_xlen,
                           long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->inoutput)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->inoutput);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_inoutput_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->inoutput)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->inoutput, NULL), write_len,
               (kerstr->inoutput)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xyzw)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xyzw);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_xyzw_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xyzw)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->xyzw, NULL), write_len,
               (kerstr->xyzw)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->cu_cache)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->cu_cache);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_cu_cache_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->cu_cache)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->cu_cache, NULL), write_len,
               (kerstr->cu_cache)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->cu_xyzw)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->cu_xyzw);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_cu_xyzw_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->cu_xyzw)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->cu_xyzw, NULL), write_len,
               (kerstr->cu_xyzw)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->fieldE)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->fieldE);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_fieldE_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->fieldE)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->fieldE, NULL), write_len,
               (kerstr->fieldE)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->fieldB)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->fieldB);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_fieldB_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->fieldB)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->fieldB, NULL), write_len,
               (kerstr->fieldB)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->FoutJ)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->FoutJ);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_FoutJ_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->FoutJ)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->FoutJ, NULL), write_len,
               (kerstr->FoutJ)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->FoutEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->FoutEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_FoutEN_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->FoutEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->FoutEN, NULL), write_len,
               (kerstr->FoutEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->XLEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_XLEN_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->XLEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len,
               (kerstr->XLEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->YLEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_YLEN_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->YLEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len,
               (kerstr->YLEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ZLEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_ZLEN_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ZLEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len,
               (kerstr->ZLEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_ovlp_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_numvec_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_num_ele_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->grid_cache_len)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->grid_cache_len);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_dump_ene_num_grid_cache_len_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->grid_cache_len)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->grid_cache_len, NULL), write_len,
               (kerstr->grid_cache_len)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->cu_cache_length)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->cu_cache_length);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_dump_ene_num_cu_cache_length_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->cu_cache_length)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->cu_cache_length, NULL), write_len,
               (kerstr->cu_cache_length)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->Mass)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->Mass);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_Mass_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->Mass)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->Mass, NULL), write_len,
               (kerstr->Mass)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->Charge)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->Charge);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_Charge_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->Charge)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->Charge, NULL), write_len,
               (kerstr->Charge)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->SPEC)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->SPEC);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_SPEC_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->SPEC)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->SPEC, NULL), write_len,
               (kerstr->SPEC)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->NUM_SPEC)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->NUM_SPEC);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_NUM_SPEC_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->NUM_SPEC)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->NUM_SPEC, NULL), write_len,
               (kerstr->NUM_SPEC)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->DELTA_X)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->DELTA_X);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_DELTA_X_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->DELTA_X)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->DELTA_X, NULL), write_len,
               (kerstr->DELTA_X)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->DELTA_Y)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->DELTA_Y);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_DELTA_Y_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->DELTA_Y)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->DELTA_Y, NULL), write_len,
               (kerstr->DELTA_Y)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->DELTA_Z)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->DELTA_Z);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_DELTA_Z_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->DELTA_Z)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->DELTA_Z, NULL), write_len,
               (kerstr->DELTA_Z)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->Deltat)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->Deltat);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_Deltat_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->Deltat)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->Deltat, NULL), write_len,
               (kerstr->Deltat)->type_len, fp);
        fclose(fp);
      }
    }
  } else {
    {
      0;
    }
  }

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_dump_ene_num<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->inoutput->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR int *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->xyzw->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->cu_cache->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR int *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->cu_xyzw->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->fieldE->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->fieldB->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->FoutJ->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->FoutEN->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((double *)kerstr->Mass->h_data))[0],
          (((double *)kerstr->Charge->h_data))[0],
          (((int *)kerstr->SPEC->h_data))[0],
          (((int *)kerstr->NUM_SPEC->h_data))[0],
          (((double *)kerstr->DELTA_X->h_data))[0],
          (((double *)kerstr->DELTA_Y->h_data))[0],
          (((double *)kerstr->DELTA_Z->h_data))[0],
          (((double *)kerstr->Deltat->h_data))[0]);
    }
  } else {
    {
      dim3 multiylen = 1;
      (multiylen.x = 64);
      (multiylen.y = (scmc_internal_g_ylen / 64));
      int rest = (scmc_internal_g_ylen % 64);

      if ((rest != 0)) {
        {
          fprintf(stderr,
                  "Warning: if __ylen>=65536 then __ylen must be divisible by "
                  "64, __ylen=%d\n",
                  scmc_internal_g_ylen);
        }
      } else {
        {
          0;
        }
      }
      mapu_dump_ene_num<<<multiylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->inoutput->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR int *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->xyzw->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->cu_cache->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR int *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->cu_xyzw->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->fieldE->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->fieldB->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->FoutJ->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->FoutEN->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((double *)kerstr->Mass->h_data))[0],
          (((double *)kerstr->Charge->h_data))[0],
          (((int *)kerstr->SPEC->h_data))[0],
          (((int *)kerstr->NUM_SPEC->h_data))[0],
          (((double *)kerstr->DELTA_X->h_data))[0],
          (((double *)kerstr->DELTA_Y->h_data))[0],
          (((double *)kerstr->DELTA_Z->h_data))[0],
          (((double *)kerstr->Deltat->h_data))[0]);
    }
  }

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->inoutput)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->inoutput);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_inoutput_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->inoutput)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->inoutput, NULL), write_len,
               (kerstr->inoutput)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xyzw)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xyzw);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_xyzw_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xyzw)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->xyzw, NULL), write_len,
               (kerstr->xyzw)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->cu_cache)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->cu_cache);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_cu_cache_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->cu_cache)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->cu_cache, NULL), write_len,
               (kerstr->cu_cache)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->cu_xyzw)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->cu_xyzw);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_cu_xyzw_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->cu_xyzw)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->cu_xyzw, NULL), write_len,
               (kerstr->cu_xyzw)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->fieldE)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->fieldE);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_fieldE_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->fieldE)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->fieldE, NULL), write_len,
               (kerstr->fieldE)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->fieldB)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->fieldB);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_fieldB_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->fieldB)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->fieldB, NULL), write_len,
               (kerstr->fieldB)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->FoutJ)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->FoutJ);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_FoutJ_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->FoutJ)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->FoutJ, NULL), write_len,
               (kerstr->FoutJ)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->FoutEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->FoutEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_FoutEN_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->FoutEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->FoutEN, NULL), write_len,
               (kerstr->FoutEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->XLEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_XLEN_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->XLEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len,
               (kerstr->XLEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->YLEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_YLEN_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->YLEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len,
               (kerstr->YLEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ZLEN)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_ZLEN_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ZLEN)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len,
               (kerstr->ZLEN)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_ovlp_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_numvec_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_num_ele_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->grid_cache_len)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->grid_cache_len);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_dump_ene_num_grid_cache_len_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->grid_cache_len)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->grid_cache_len, NULL), write_len,
               (kerstr->grid_cache_len)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->cu_cache_length)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->cu_cache_length);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_dump_ene_num_cu_cache_length_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->cu_cache_length)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->cu_cache_length, NULL), write_len,
               (kerstr->cu_cache_length)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->Mass)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->Mass);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_Mass_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->Mass)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->Mass, NULL), write_len,
               (kerstr->Mass)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->Charge)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->Charge);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_Charge_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->Charge)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->Charge, NULL), write_len,
               (kerstr->Charge)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->SPEC)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->SPEC);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_SPEC_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->SPEC)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->SPEC, NULL), write_len,
               (kerstr->SPEC)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->NUM_SPEC)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->NUM_SPEC);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_NUM_SPEC_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->NUM_SPEC)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->NUM_SPEC, NULL), write_len,
               (kerstr->NUM_SPEC)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->DELTA_X)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->DELTA_X);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_DELTA_X_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->DELTA_X)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->DELTA_X, NULL), write_len,
               (kerstr->DELTA_X)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->DELTA_Y)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->DELTA_Y);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_DELTA_Y_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->DELTA_Y)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->DELTA_Y, NULL), write_len,
               (kerstr->DELTA_Y)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->DELTA_Z)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->DELTA_Z);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_DELTA_Z_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->DELTA_Z)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->DELTA_Z, NULL), write_len,
               (kerstr->DELTA_Z)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->Deltat)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->Deltat);
          }
        } else {
          {
            0;
          }
        }
        char fname[256];
        snprintf(fname, 256, "Debug_%d_mapu_dump_ene_num_Deltat_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->Deltat)->len;

        if ((write_len <= 0)) {
          {
            (write_len = 1);
          }
        } else {
          {
            0;
          }
        }
        fwrite(mapu_pscmc_get_h_data(kerstr->Deltat, NULL), write_len,
               (kerstr->Deltat)->type_len, fp);
        fclose(fp);
      }
    }
  } else {
    {
      0;
    }
  }
  (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_inoutput(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_xyzw(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_cu_cache(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_cu_xyzw(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_fieldE(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->fieldE = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_fieldB(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->fieldB = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_FoutJ(mapu_dump_ene_num_struct *kerstr,
                                               mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->FoutJ = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_FoutEN(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->FoutEN = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_XLEN(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_YLEN(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_ZLEN(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_ovlp(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_numvec(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_num_ele(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->num_ele = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_grid_cache_len(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_cu_cache_length(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_Mass(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->Mass = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_Charge(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->Charge = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_SPEC(mapu_dump_ene_num_struct *kerstr,
                                              mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->SPEC = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_NUM_SPEC(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->NUM_SPEC = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_DELTA_X(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->DELTA_X = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_DELTA_Y(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->DELTA_Y = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_DELTA_Z(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->DELTA_Z = pm);
  return 0;
}
int mapu_dump_ene_num_scmc_set_parameter_Deltat(
    mapu_dump_ene_num_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->Deltat = pm);
  return 0;
}
#ifdef __CUDACC__
/* Device-side coordinate fixup after particle payload exchange. */
__global__ static void sympic_particle_shift_kernel(
    double *cu_cache, int *cu_xyzw, const int *frl,
    long cu_cache_length, int dir, long xyz_len, int ptlen) {
  long j = blockIdx.x;
  int cur_len = cu_xyzw[4 * j];
  int n = frl[j];
  if (n <= 0) return;
  long base = j * cu_cache_length * 6;
  for (int i = threadIdx.x; i < n; i += blockDim.x)
    cu_cache[base + (cur_len + i) * ptlen + dir] += xyz_len;
  if (threadIdx.x == 0) cu_xyzw[4 * j] = cur_len + n;
}

extern "C" int cuda_particle_shift_launch(
    double *cu_cache, int *cu_xyzw, const int *frl,
    long cu_cache_length, long numvec, int dir, long xyz_len,
    int ptlen, int device_id) {
  cudaError_t err = cudaSetDevice(device_id);
  if (err != cudaSuccess) return 1;

  sympic_particle_shift_kernel<<<numvec, 4>>>(
      cu_cache, cu_xyzw, frl, cu_cache_length, dir, xyz_len, ptlen);
  return cudaGetLastError() == cudaSuccess ? 0 : 2;
}

#endif

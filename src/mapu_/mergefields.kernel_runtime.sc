#include "local_header.h"
#include "mergefields.kernel_runtime.h"

#include "mergefields.kernel.inc"


// 启动函数
static int dump_kernel_variables = 0;

extern long _pscmc_mapu_global_dump_kernel_variables,
    _pscmc_mapu_global_dump_times;
int mapu_merge_ovlp_m2o_once_init(mapu_pscmc_env *pe,
                                  mapu_merge_ovlp_m2o_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_merge_ovlp_m2o_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_merge_ovlp_m2o_once_struct));
}
int mapu_merge_ovlp_m2o_once_get_xlen() { return 1; }
int mapu_merge_ovlp_m2o_once_get_num_compute_units(
    mapu_merge_ovlp_m2o_once_struct *kerstr) {
  return 4;
}
int mapu_merge_ovlp_m2o_once_exec(mapu_merge_ovlp_m2o_once_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecmain_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp0)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp0);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp0_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp0)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp0, NULL), write_len,
               (kerstr->vecovlp0)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp1)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp1);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp1_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp1)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp1, NULL), write_len,
               (kerstr->vecovlp1)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp2)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp2);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp2_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp2)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp2, NULL), write_len,
               (kerstr->vecovlp2)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp3)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp3);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp3_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp3)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp3, NULL), write_len,
               (kerstr->vecovlp3)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp4)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp4);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp4_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp4)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp4, NULL), write_len,
               (kerstr->vecovlp4)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp5)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp5);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp5_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp5)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp5, NULL), write_len,
               (kerstr->vecovlp5)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp6)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp6);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp6_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp6)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp6, NULL), write_len,
               (kerstr->vecovlp6)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp7)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp7);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp7_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp7)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp7, NULL), write_len,
               (kerstr->vecovlp7)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp8)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp8);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp8_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp8)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp8, NULL), write_len,
               (kerstr->vecovlp8)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp9)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp9);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp9_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp9)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp9, NULL), write_len,
               (kerstr->vecovlp9)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp10)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp10);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp10_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp10)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp10, NULL), write_len,
               (kerstr->vecovlp10)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp11)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp11);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp11_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp11)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp11, NULL), write_len,
               (kerstr->vecovlp11)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp12)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp12);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp12_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp12)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp12, NULL), write_len,
               (kerstr->vecovlp12)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp14)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp14);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp14_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp14)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp14, NULL), write_len,
               (kerstr->vecovlp14)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp15)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp15);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp15_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp15)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp15, NULL), write_len,
               (kerstr->vecovlp15)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp16)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp16);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp16_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp16)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp16, NULL), write_len,
               (kerstr->vecovlp16)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp17)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp17);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp17_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp17)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp17, NULL), write_len,
               (kerstr->vecovlp17)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp18)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp18);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp18_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp18)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp18, NULL), write_len,
               (kerstr->vecovlp18)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp19)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp19);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp19_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp19)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp19, NULL), write_len,
               (kerstr->vecovlp19)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp20)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp20);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp20_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp20)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp20, NULL), write_len,
               (kerstr->vecovlp20)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp21)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp21);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp21_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp21)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp21, NULL), write_len,
               (kerstr->vecovlp21)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp22)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp22);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp22_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp22)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp22, NULL), write_len,
               (kerstr->vecovlp22)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp23)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp23);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp23_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp23)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp23, NULL), write_len,
               (kerstr->vecovlp23)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp24)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp24);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp24_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp24)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp24, NULL), write_len,
               (kerstr->vecovlp24)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp25)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp25);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp25_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp25)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp25, NULL), write_len,
               (kerstr->vecovlp25)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp26)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp26);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp26_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp26)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp26, NULL), write_len,
               (kerstr->vecovlp26)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_numvec_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_num_ele_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_xblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_yblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_zblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_ovlp_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_merge_ovlp_m2o_once<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp0->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp1->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp2->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp3->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp4->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp5->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp6->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp7->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp8->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp9->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp10->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp11->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp12->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp14->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp15->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp16->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp17->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp18->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp19->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp20->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp21->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp22->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp23->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp24->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp25->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp26->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
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
      mapu_merge_ovlp_m2o_once<<<multiylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp0->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp1->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp2->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp3->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp4->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp5->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp6->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp7->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp8->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp9->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp10->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp11->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp12->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp14->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp15->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp16->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp17->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp18->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp19->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp20->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp21->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp22->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp23->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp24->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp25->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlp26->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
    }
  }

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecmain_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp0)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp0);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp0_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp0)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp0, NULL), write_len,
               (kerstr->vecovlp0)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp1)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp1);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp1_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp1)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp1, NULL), write_len,
               (kerstr->vecovlp1)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp2)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp2);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp2_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp2)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp2, NULL), write_len,
               (kerstr->vecovlp2)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp3)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp3);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp3_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp3)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp3, NULL), write_len,
               (kerstr->vecovlp3)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp4)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp4);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp4_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp4)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp4, NULL), write_len,
               (kerstr->vecovlp4)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp5)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp5);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp5_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp5)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp5, NULL), write_len,
               (kerstr->vecovlp5)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp6)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp6);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp6_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp6)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp6, NULL), write_len,
               (kerstr->vecovlp6)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp7)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp7);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp7_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp7)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp7, NULL), write_len,
               (kerstr->vecovlp7)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp8)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp8);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp8_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp8)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp8, NULL), write_len,
               (kerstr->vecovlp8)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp9)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp9);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp9_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp9)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp9, NULL), write_len,
               (kerstr->vecovlp9)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp10)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp10);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp10_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp10)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp10, NULL), write_len,
               (kerstr->vecovlp10)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp11)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp11);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp11_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp11)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp11, NULL), write_len,
               (kerstr->vecovlp11)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp12)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp12);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp12_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp12)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp12, NULL), write_len,
               (kerstr->vecovlp12)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp14)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp14);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp14_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp14)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp14, NULL), write_len,
               (kerstr->vecovlp14)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp15)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp15);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp15_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp15)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp15, NULL), write_len,
               (kerstr->vecovlp15)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp16)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp16);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp16_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp16)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp16, NULL), write_len,
               (kerstr->vecovlp16)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp17)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp17);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp17_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp17)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp17, NULL), write_len,
               (kerstr->vecovlp17)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp18)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp18);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp18_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp18)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp18, NULL), write_len,
               (kerstr->vecovlp18)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp19)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp19);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp19_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp19)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp19, NULL), write_len,
               (kerstr->vecovlp19)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp20)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp20);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp20_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp20)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp20, NULL), write_len,
               (kerstr->vecovlp20)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp21)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp21);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp21_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp21)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp21, NULL), write_len,
               (kerstr->vecovlp21)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp22)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp22);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp22_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp22)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp22, NULL), write_len,
               (kerstr->vecovlp22)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp23)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp23);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp23_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp23)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp23, NULL), write_len,
               (kerstr->vecovlp23)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp24)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp24);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp24_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp24)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp24, NULL), write_len,
               (kerstr->vecovlp24)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp25)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp25);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp25_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp25)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp25, NULL), write_len,
               (kerstr->vecovlp25)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlp26)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlp26);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_vecovlp26_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlp26)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlp26, NULL), write_len,
               (kerstr->vecovlp26)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_numvec_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_num_ele_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_xblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_yblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_zblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_once_ovlp_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
  return 0;
}

int mapu_merge_ovlp_m2o_all_in_one_init(
    mapu_pscmc_env *pe, mapu_merge_ovlp_m2o_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_merge_ovlp_m2o_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_merge_ovlp_m2o_all_in_one_struct));
}
int mapu_merge_ovlp_m2o_all_in_one_get_xlen() { return 1; }

int mapu_merge_ovlp_m2o_all_in_one_exec(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice(kerstr->pe->device_id);

  if (dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables) {

    {
      if (kerstr->vecmain->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_vecmain_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->vecmain)->len;

      if (write_len <= 0) {
        write_len = 1;
      }

      fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
             (kerstr->vecmain)->type_len, fp);
      fclose(fp);
    }

    {
      if (kerstr->vecovlps->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_vecovlps_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->vecovlps)->len;

      if ((write_len <= 0)) {
        write_len = 1;
      }

      fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
             (kerstr->vecovlps)->type_len, fp);
      fclose(fp);
    }

    {

      if (kerstr->numvec->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_numvec_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->numvec)->len;

      if (write_len <= 0) {
        write_len = 1;
      }

      fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
             (kerstr->numvec)->type_len, fp);
      fclose(fp);
    }
    {
      if (kerstr->num_ele->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_num_ele_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->num_ele)->len;

      if (write_len <= 0) {
        write_len = 1;
      }

      fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
             (kerstr->num_ele)->type_len, fp);
      fclose(fp);
    }
    {

      if (kerstr->xblock->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_xblock_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->xblock)->len;

      write_len = write_len <= 0 ? 1 : write_len;

      fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
             (kerstr->xblock)->type_len, fp);
      fclose(fp);
    }
    {

      if (kerstr->yblock->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_yblock_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->yblock)->len;

      write_len = write_len <= 0 ? 1 : write_len;

      fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
             (kerstr->yblock)->type_len, fp);
      fclose(fp);
    }
    {

      if (kerstr->zblock->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_zblock_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->zblock)->len;

      write_len = write_len <= 0 ? 1 : write_len;

      fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
             (kerstr->zblock)->type_len, fp);
      fclose(fp);
    }
    {

      if (kerstr->ovlp->len > 0) {
        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
      }

      char fname[256];
      snprintf(fname, 256,
               "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_ovlp_before_exec",
               _pscmc_mapu_global_dump_times);
      FILE *fp = fopen(fname, "wb");
      size_t write_len = (kerstr->ovlp)->len;

      write_len = write_len <= 0 ? 1 : write_len;

      fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
             (kerstr->ovlp)->type_len, fp);
      fclose(fp);
    }
  }

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_merge_ovlp_m2o_all_in_one<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
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
      }
      mapu_merge_ovlp_m2o_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
    }
  }

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_vecmain_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_vecovlps_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_numvec_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_num_ele_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_xblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_yblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_zblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_m2o_all_in_one_ovlp_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
  return 0;
}

int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecmain = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecovlps = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->num_ele = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xblock = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->yblock = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->zblock = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_merge_ovlp_m2o_init(mapu_pscmc_env *pe,
                             mapu_merge_ovlp_m2o_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_merge_ovlp_m2o_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_merge_ovlp_m2o_struct));
}

int mapu_merge_ovlp_o2m_once_init(mapu_pscmc_env *pe,
                                  mapu_merge_ovlp_o2m_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_merge_ovlp_o2m_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_merge_ovlp_o2m_once_struct));
}

int mapu_merge_ovlp_o2m_once_scmc_set_parameter_yblock(
    mapu_merge_ovlp_o2m_once_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->yblock = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_once_scmc_set_parameter_zblock(
    mapu_merge_ovlp_o2m_once_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->zblock = pm);
  return 0;
}

int mapu_merge_ovlp_o2m_all_in_one_init(
    mapu_pscmc_env *pe, mapu_merge_ovlp_o2m_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_merge_ovlp_o2m_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_merge_ovlp_o2m_all_in_one_struct));
}
int mapu_merge_ovlp_o2m_all_in_one_get_xlen() { return 1; }

int mapu_merge_ovlp_o2m_all_in_one_exec(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_vecmain_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_vecovlps_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_numvec_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_num_ele_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_xblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_yblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_zblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_ovlp_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_merge_ovlp_o2m_all_in_one<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
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
      mapu_merge_ovlp_o2m_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
    }
  }

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_vecmain_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_vecovlps_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_numvec_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_num_ele_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_xblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_yblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_zblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_merge_ovlp_o2m_all_in_one_ovlp_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecmain = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecovlps = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->num_ele = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xblock = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->yblock = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->zblock = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_merge_ovlp_o2m_init(mapu_pscmc_env *pe,
                             mapu_merge_ovlp_o2m_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_merge_ovlp_o2m_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_merge_ovlp_o2m_struct));
}

int mapu_sync_ovlp_m2o_once_init(mapu_pscmc_env *pe,
                                 mapu_sync_ovlp_m2o_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sync_ovlp_m2o_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sync_ovlp_m2o_once_struct));
}

int mapu_sync_ovlp_m2o_all_in_one_init(
    mapu_pscmc_env *pe, mapu_sync_ovlp_m2o_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sync_ovlp_m2o_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sync_ovlp_m2o_all_in_one_struct));
}
int mapu_sync_ovlp_m2o_all_in_one_get_xlen() { return 1; }

int mapu_sync_ovlp_m2o_all_in_one_exec(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_vecmain_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_vecovlps_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_numvec_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_num_ele_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_xblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_yblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_zblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_ovlp_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sync_ovlp_m2o_all_in_one<<<scmc_internal_g_ylen,
                                      scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
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
      mapu_sync_ovlp_m2o_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
    }
  }

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_vecmain_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_vecovlps_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_numvec_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_num_ele_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_xblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_yblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_zblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_m2o_all_in_one_ovlp_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecmain = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecovlps = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->num_ele = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xblock = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->yblock = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->zblock = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sync_ovlp_m2o_init(mapu_pscmc_env *pe,
                            mapu_sync_ovlp_m2o_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sync_ovlp_m2o_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sync_ovlp_m2o_struct));
}

int mapu_sync_ovlp_o2m_once_init(mapu_pscmc_env *pe,
                                 mapu_sync_ovlp_o2m_once_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sync_ovlp_o2m_once_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sync_ovlp_o2m_once_struct));
}

int mapu_sync_ovlp_o2m_all_in_one_init(
    mapu_pscmc_env *pe, mapu_sync_ovlp_o2m_all_in_one_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sync_ovlp_o2m_all_in_one_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sync_ovlp_o2m_all_in_one_struct));
}
int mapu_sync_ovlp_o2m_all_in_one_get_xlen() { return 1; }

int mapu_sync_ovlp_o2m_all_in_one_exec(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_vecmain_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_vecovlps_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_numvec_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_num_ele_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_xblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_yblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_zblock_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_ovlp_before_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sync_ovlp_o2m_all_in_one<<<scmc_internal_g_ylen,
                                      scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
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
      mapu_sync_ovlp_o2m_all_in_one<<<multiylen, scmc_internal_g_xlen>>>(
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecmain->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          ((__DDR double *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->vecovlps->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((int *)kerstr->num_ele->h_data))[0],
          (((MAPU_LONG *)kerstr->xblock->h_data))[0],
          (((MAPU_LONG *)kerstr->yblock->h_data))[0],
          (((MAPU_LONG *)kerstr->zblock->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0]);
    }
  }

  if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables)) {
    {
      {

        if (((kerstr->vecmain)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecmain);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_vecmain_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecmain)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecmain, NULL), write_len,
               (kerstr->vecmain)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->vecovlps)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->vecovlps);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_vecovlps_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->vecovlps)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->vecovlps, NULL), write_len,
               (kerstr->vecovlps)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->numvec)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->numvec);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_numvec_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->numvec)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len,
               (kerstr->numvec)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->num_ele)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_num_ele_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->num_ele)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len,
               (kerstr->num_ele)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->xblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->xblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_xblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->xblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len,
               (kerstr->xblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->yblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->yblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_yblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->yblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len,
               (kerstr->yblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->zblock)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->zblock);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_zblock_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->zblock)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len,
               (kerstr->zblock)->type_len, fp);
        fclose(fp);
      }
      {

        if (((kerstr->ovlp)->len > 0)) {
          {
            mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
          }
        }

        char fname[256];
        snprintf(fname, 256,
                 "Debug_%d_mapu_sync_ovlp_o2m_all_in_one_ovlp_after_exec",
                 _pscmc_mapu_global_dump_times);
        FILE *fp = fopen(fname, "wb");
        size_t write_len = (kerstr->ovlp)->len;

        write_len = write_len <= 0 ? 1 : write_len;

        fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len,
               (kerstr->ovlp)->type_len, fp);
        fclose(fp);
      }
    }
  }

  (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecmain = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->vecovlps = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->num_ele = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xblock = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->yblock = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->zblock = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sync_ovlp_o2m_init(mapu_pscmc_env *pe,
                            mapu_sync_ovlp_o2m_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sync_ovlp_o2m_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sync_ovlp_o2m_struct));
}

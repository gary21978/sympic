#include "local_header.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "move_back.kernel_runtime.h"

#include "move_back.kernel.inc"

int mapu_move_back_kernel_8_init(mapu_pscmc_env *pe,
                                 mapu_move_back_kernel_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_move_back_kernel_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_move_back_kernel_8_struct));
}
int mapu_move_back_kernel_8_get_xlen() { return 1; }
int mapu_move_back_kernel_8_get_num_compute_units(
    mapu_move_back_kernel_8_struct *kerstr) {
  return 4;
}
int mapu_move_back_kernel_8_exec(mapu_move_back_kernel_8_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_move_back_kernel_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
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
      mapu_move_back_kernel_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_inoutput(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_xyzw(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_cu_cache(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_cu_xyzw(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_XLEN(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_YLEN(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_ZLEN(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_grid_cache_len(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_move_back_kernel_8_scmc_set_parameter_cu_cache_length(
    mapu_move_back_kernel_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_move_back_kernel_6_init(mapu_pscmc_env *pe,
                                 mapu_move_back_kernel_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_move_back_kernel_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_move_back_kernel_6_struct));
}
int mapu_move_back_kernel_6_get_xlen() { return 1; }
int mapu_move_back_kernel_6_get_num_compute_units(
    mapu_move_back_kernel_6_struct *kerstr) {
  return 4;
}
int mapu_move_back_kernel_6_exec(mapu_move_back_kernel_6_struct *kerstr,
                                 long scmc_internal_g_xlen,
                                 long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_move_back_kernel_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
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
      mapu_move_back_kernel_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_inoutput(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_xyzw(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_cu_cache(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_cu_xyzw(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_XLEN(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_YLEN(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_ZLEN(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_grid_cache_len(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_move_back_kernel_6_scmc_set_parameter_cu_cache_length(
    mapu_move_back_kernel_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
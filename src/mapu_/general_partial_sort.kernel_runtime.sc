#include "local_header.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "general_partial_sort.kernel_runtime.h"

#include "general_partial_sort.kernel.inc"

int mapu_cu_swap_r_8_init(mapu_pscmc_env *pe, mapu_cu_swap_r_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
// void mapu_cu_swap_r_8_get_struct_len(size_t *len) {
//   ((len)[0] = sizeof(mapu_cu_swap_r_8_struct));
// }
int mapu_cu_swap_r_8_get_xlen() { return 1; }
// int mapu_cu_swap_r_8_get_num_compute_units(mapu_cu_swap_r_8_struct *kerstr) {
//   return 4;
// }
int mapu_cu_swap_r_8_exec(mapu_cu_swap_r_8_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_cu_swap_r_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
    }
  } else {
    dim3 multiylen = 1;
    (multiylen.x = 64);
    (multiylen.y = (scmc_internal_g_ylen / 64));
    int rest = (scmc_internal_g_ylen % 64);

    if ((rest != 0)) {

      fprintf(stderr,
              "Warning: if __ylen>=65536 then __ylen must be divisible by "
              "64, __ylen=%d\n",
              scmc_internal_g_ylen);
    }
    mapu_cu_swap_r_8<<<multiylen, scmc_internal_g_xlen>>>(
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
        ((__DDR MAPU_LONG *)({
          uint64_t __d_data_address_tmp2;
          mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                       &(__d_data_address_tmp2));
          __d_data_address_tmp2;
        })),
        (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
        (((int *)kerstr->the_dir_num->h_data))[0],
        (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
  }

  return 0;
}
int mapu_cu_swap_r_8_scmc_set_parameter_cu_cache(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_cu_swap_r_8_scmc_set_parameter_cu_xyzw(mapu_cu_swap_r_8_struct *kerstr,
                                                mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_cu_swap_r_8_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_cu_swap_r_8_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_r_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->the_dir_num = pm);
  return 0;
}
int mapu_cu_swap_r_8_scmc_set_parameter_XYZLEN(mapu_cu_swap_r_8_struct *kerstr,
                                               mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XYZLEN = pm);
  return 0;
}
int mapu_cu_swap_l_8_init(mapu_pscmc_env *pe, mapu_cu_swap_l_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
// void mapu_cu_swap_l_8_get_struct_len(size_t *len) {
//   ((len)[0] = sizeof(mapu_cu_swap_l_8_struct));
// }
int mapu_cu_swap_l_8_get_xlen() { return 1; }
// int mapu_cu_swap_l_8_get_num_compute_units(mapu_cu_swap_l_8_struct *kerstr) {
//   return 4;
// }
int mapu_cu_swap_l_8_exec(mapu_cu_swap_l_8_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_cu_swap_l_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
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
      mapu_cu_swap_l_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
    }
  }

  return 0;
}
int mapu_cu_swap_l_8_scmc_set_parameter_cu_cache(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_cu_swap_l_8_scmc_set_parameter_cu_xyzw(mapu_cu_swap_l_8_struct *kerstr,
                                                mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_cu_swap_l_8_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_cu_swap_l_8_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_l_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->the_dir_num = pm);
  return 0;
}
int mapu_cu_swap_l_8_scmc_set_parameter_XYZLEN(mapu_cu_swap_l_8_struct *kerstr,
                                               mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XYZLEN = pm);
  return 0;
}
int mapu_cu_swap_r_6_init(mapu_pscmc_env *pe, mapu_cu_swap_r_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_cu_swap_r_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_cu_swap_r_6_struct));
}
int mapu_cu_swap_r_6_get_xlen() { return 1; }
// int mapu_cu_swap_r_6_get_num_compute_units(mapu_cu_swap_r_6_struct *kerstr) {
//   return 4;
// }
int mapu_cu_swap_r_6_exec(mapu_cu_swap_r_6_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_cu_swap_r_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
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
      mapu_cu_swap_r_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
    }
  }

  return 0;
}
int mapu_cu_swap_r_6_scmc_set_parameter_cu_cache(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_cu_swap_r_6_scmc_set_parameter_cu_xyzw(mapu_cu_swap_r_6_struct *kerstr,
                                                mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_cu_swap_r_6_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_cu_swap_r_6_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_r_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->the_dir_num = pm);
  return 0;
}
int mapu_cu_swap_r_6_scmc_set_parameter_XYZLEN(mapu_cu_swap_r_6_struct *kerstr,
                                               mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XYZLEN = pm);
  return 0;
}
int mapu_cu_swap_l_6_init(mapu_pscmc_env *pe, mapu_cu_swap_l_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_cu_swap_l_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_cu_swap_l_6_struct));
}
int mapu_cu_swap_l_6_get_xlen() { return 1; }
// int mapu_cu_swap_l_6_get_num_compute_units(mapu_cu_swap_l_6_struct *kerstr) {
//   return 4;
// }
int mapu_cu_swap_l_6_exec(mapu_cu_swap_l_6_struct *kerstr,
                          long scmc_internal_g_xlen,
                          long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_cu_swap_l_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
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
      mapu_cu_swap_l_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0],
          (((int *)kerstr->the_dir_num->h_data))[0],
          (((MAPU_LONG *)kerstr->XYZLEN->h_data))[0]);
    }
  }

  return 0;
}
int mapu_cu_swap_l_6_scmc_set_parameter_cu_cache(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_cu_swap_l_6_scmc_set_parameter_cu_xyzw(mapu_cu_swap_l_6_struct *kerstr,
                                                mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_cu_swap_l_6_scmc_set_parameter_cu_cache_length(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_cu_swap_l_6_scmc_set_parameter_the_dir_num(
    mapu_cu_swap_l_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->the_dir_num = pm);
  return 0;
}
int mapu_cu_swap_l_6_scmc_set_parameter_XYZLEN(mapu_cu_swap_l_6_struct *kerstr,
                                               mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XYZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_z_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_z_vlo_8_struct));
}
int mapu_sort_one_grid_z_vlo_8_get_xlen() { return 1; }
// int mapu_sort_one_grid_z_vlo_8_get_num_compute_units(
//     mapu_sort_one_grid_z_vlo_8_struct *kerstr) {
//   return 4;
// }
int mapu_sort_one_grid_z_vlo_8_exec(mapu_sort_one_grid_z_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_z_vlo_8<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_z_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_z_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_z_vlo_8_struct));
}
int mapu_gpu_sort_one_grid_z_vlo_8_get_xlen() { return 32; }
// int mapu_gpu_sort_one_grid_z_vlo_8_get_num_compute_units(
//     mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr) {
//   return 4;
// }
int mapu_gpu_sort_one_grid_z_vlo_8_exec(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_z_vlo_8<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_z_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_y_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_y_vlo_8_struct));
}
int mapu_sort_one_grid_y_vlo_8_get_xlen() { return 1; }
// int mapu_sort_one_grid_y_vlo_8_get_num_compute_units(
//     mapu_sort_one_grid_y_vlo_8_struct *kerstr) {
//   return 4;
// }
int mapu_sort_one_grid_y_vlo_8_exec(mapu_sort_one_grid_y_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_y_vlo_8<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_y_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_y_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_y_vlo_8_struct));
}
int mapu_gpu_sort_one_grid_y_vlo_8_get_xlen() { return 32; }
// int mapu_gpu_sort_one_grid_y_vlo_8_get_num_compute_units(
//     mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr) {
//   return 4;
// }
int mapu_gpu_sort_one_grid_y_vlo_8_exec(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_y_vlo_8<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_y_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_x_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_x_vlo_8_struct));
}
int mapu_sort_one_grid_x_vlo_8_get_xlen() { return 1; }
// int mapu_sort_one_grid_x_vlo_8_get_num_compute_units(
//     mapu_sort_one_grid_x_vlo_8_struct *kerstr) {
//   return 4;
// }
int mapu_sort_one_grid_x_vlo_8_exec(mapu_sort_one_grid_x_vlo_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_x_vlo_8<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_x_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_x_vlo_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_x_vlo_8_struct));
}
int mapu_gpu_sort_one_grid_x_vlo_8_get_xlen() { return 32; }
// int mapu_gpu_sort_one_grid_x_vlo_8_get_num_compute_units(
//     mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr) {
//   return 4;
// }
int mapu_gpu_sort_one_grid_x_vlo_8_exec(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_x_vlo_8<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_x_vlo_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_vlo_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_z_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_z_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_z_8_struct));
}
int mapu_sort_one_grid_z_8_get_xlen() { return 1; }
int mapu_sort_one_grid_z_8_get_num_compute_units(
    mapu_sort_one_grid_z_8_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_z_8_exec(mapu_sort_one_grid_z_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_z_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_z_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_z_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_z_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_z_8_struct));
}
int mapu_gpu_sort_one_grid_z_8_get_xlen() { return 32; }
// int mapu_gpu_sort_one_grid_z_8_get_num_compute_units(
//     mapu_gpu_sort_one_grid_z_8_struct *kerstr) {
//   return 4;
// }
int mapu_gpu_sort_one_grid_z_8_exec(mapu_gpu_sort_one_grid_z_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_z_8<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_z_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_y_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_y_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_y_8_struct));
}
int mapu_sort_one_grid_y_8_get_xlen() { return 1; }
// int mapu_sort_one_grid_y_8_get_num_compute_units(
//     mapu_sort_one_grid_y_8_struct *kerstr) {
//   return 4;
// }
int mapu_sort_one_grid_y_8_exec(mapu_sort_one_grid_y_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_y_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_y_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_y_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_y_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_y_8_struct));
}
int mapu_gpu_sort_one_grid_y_8_get_xlen() { return 32; }
int mapu_gpu_sort_one_grid_y_8_get_num_compute_units(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_y_8_exec(mapu_gpu_sort_one_grid_y_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_y_8<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_y_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_x_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_x_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_x_8_struct));
}
int mapu_sort_one_grid_x_8_get_xlen() { return 1; }
int mapu_sort_one_grid_x_8_get_num_compute_units(
    mapu_sort_one_grid_x_8_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_x_8_exec(mapu_sort_one_grid_x_8_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_x_8<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_x_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_x_8_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_x_8_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_x_8_struct));
}
int mapu_gpu_sort_one_grid_x_8_get_xlen() { return 32; }
int mapu_gpu_sort_one_grid_x_8_get_num_compute_units(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_x_8_exec(mapu_gpu_sort_one_grid_x_8_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_x_8<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_x_8<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_8_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_z_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_z_vlo_6_struct));
}
int mapu_sort_one_grid_z_vlo_6_get_xlen() { return 1; }
int mapu_sort_one_grid_z_vlo_6_get_num_compute_units(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_z_vlo_6_exec(mapu_sort_one_grid_z_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_z_vlo_6<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_z_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_z_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_z_vlo_6_struct));
}
int mapu_gpu_sort_one_grid_z_vlo_6_get_xlen() { return 32; }
int mapu_gpu_sort_one_grid_z_vlo_6_get_num_compute_units(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_z_vlo_6_exec(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_z_vlo_6<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_z_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_y_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_y_vlo_6_struct));
}
int mapu_sort_one_grid_y_vlo_6_get_xlen() { return 1; }
int mapu_sort_one_grid_y_vlo_6_get_num_compute_units(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_y_vlo_6_exec(mapu_sort_one_grid_y_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_y_vlo_6<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_y_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_y_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_y_vlo_6_struct));
}
int mapu_gpu_sort_one_grid_y_vlo_6_get_xlen() { return 32; }
int mapu_gpu_sort_one_grid_y_vlo_6_get_num_compute_units(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_y_vlo_6_exec(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_y_vlo_6<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_y_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_init(mapu_pscmc_env *pe,
                                    mapu_sort_one_grid_x_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_x_vlo_6_struct));
}
int mapu_sort_one_grid_x_vlo_6_get_xlen() { return 1; }
int mapu_sort_one_grid_x_vlo_6_get_num_compute_units(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_x_vlo_6_exec(mapu_sort_one_grid_x_vlo_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_x_vlo_6<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_x_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_init(
    mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_x_vlo_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_x_vlo_6_struct));
}
int mapu_gpu_sort_one_grid_x_vlo_6_get_xlen() { return 32; }
int mapu_gpu_sort_one_grid_x_vlo_6_get_num_compute_units(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_x_vlo_6_exec(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_x_vlo_6<<<scmc_internal_g_ylen,
                                       scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_x_vlo_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_vlo_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_z_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_z_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_z_6_struct));
}
int mapu_sort_one_grid_z_6_get_xlen() { return 1; }
int mapu_sort_one_grid_z_6_get_num_compute_units(
    mapu_sort_one_grid_z_6_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_z_6_exec(mapu_sort_one_grid_z_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_z_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_z_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_z_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_z_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_z_6_struct));
}

#ifndef MAPU_GPU_SORT_ONE_GRID_6_XLEN
#define MAPU_GPU_SORT_ONE_GRID_6_XLEN
#endif
/* number of thread within a block: 1~32 */
#define MAPU_GPU_SORT_ONE_GRID_6_XLEN 1
#if (MAPU_GPU_SORT_ONE_GRID_6_XLEN < 1) || \
    (MAPU_GPU_SORT_ONE_GRID_6_XLEN > 32)
#error "MAPU_GPU_SORT_ONE_GRID_6_XLEN must be in [1, 32]"
#endif

static int mapu_gpu_sort_one_grid_6_runtime_xlen() {
    return MAPU_GPU_SORT_ONE_GRID_6_XLEN;
}

int mapu_gpu_sort_one_grid_z_6_get_xlen() {
    return mapu_gpu_sort_one_grid_6_runtime_xlen();
}
int mapu_gpu_sort_one_grid_z_6_get_num_compute_units(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_z_6_exec(mapu_gpu_sort_one_grid_z_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_z_6<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_z_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_z_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_y_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_y_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_y_6_struct));
}
int mapu_sort_one_grid_y_6_get_xlen() { return 1; }
int mapu_sort_one_grid_y_6_get_num_compute_units(
    mapu_sort_one_grid_y_6_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_y_6_exec(mapu_sort_one_grid_y_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_y_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_y_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_y_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_y_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_y_6_struct));
}
int mapu_gpu_sort_one_grid_y_6_get_xlen() {
    return mapu_gpu_sort_one_grid_6_runtime_xlen();
}
int mapu_gpu_sort_one_grid_y_6_get_num_compute_units(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_y_6_exec(mapu_gpu_sort_one_grid_y_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_y_6<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_y_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_y_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_init(mapu_pscmc_env *pe,
                                mapu_sort_one_grid_x_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_sort_one_grid_x_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_sort_one_grid_x_6_struct));
}
int mapu_sort_one_grid_x_6_get_xlen() { return 1; }
int mapu_sort_one_grid_x_6_get_num_compute_units(
    mapu_sort_one_grid_x_6_struct *kerstr) {
  return 4;
}
int mapu_sort_one_grid_x_6_exec(mapu_sort_one_grid_x_6_struct *kerstr,
                                long scmc_internal_g_xlen,
                                long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_sort_one_grid_x_6<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_sort_one_grid_x_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    mapu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_init(mapu_pscmc_env *pe,
                                    mapu_gpu_sort_one_grid_x_6_struct *kerstr) {
  ((kerstr)->pe = pe);
  return 0;
}
void mapu_gpu_sort_one_grid_x_6_get_struct_len(size_t *len) {
  ((len)[0] = sizeof(mapu_gpu_sort_one_grid_x_6_struct));
}
int mapu_gpu_sort_one_grid_x_6_get_xlen() {
    return mapu_gpu_sort_one_grid_6_runtime_xlen();
}
int mapu_gpu_sort_one_grid_x_6_get_num_compute_units(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr) {
  return 4;
}
int mapu_gpu_sort_one_grid_x_6_exec(mapu_gpu_sort_one_grid_x_6_struct *kerstr,
                                    long scmc_internal_g_xlen,
                                    long scmc_internal_g_ylen) {
  mapsSetDevice((kerstr->pe)->device_id);

  if ((scmc_internal_g_ylen < 65536)) {
    {
      mapu_gpu_sort_one_grid_x_6<<<scmc_internal_g_ylen,
                                   scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
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
      mapu_gpu_sort_one_grid_x_6<<<multiylen, scmc_internal_g_xlen>>>(
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
          ((__DDR MAPU_LONG *)({
            uint64_t __d_data_address_tmp2;
            mapsMemobjGetPhysicalAddress(kerstr->adjoint_vec_pids->d_data,
                                         &(__d_data_address_tmp2));
            __d_data_address_tmp2;
          })),
          (((MAPU_LONG *)kerstr->XLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->YLEN->h_data))[0],
          (((MAPU_LONG *)kerstr->ZLEN->h_data))[0],
          (((int *)kerstr->ovlp->h_data))[0],
          (((MAPU_LONG *)kerstr->numvec->h_data))[0],
          (((MAPU_LONG *)kerstr->grid_cache_len->h_data))[0],
          (((MAPU_LONG *)kerstr->cu_cache_length->h_data))[0]);
    }
  }

  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->inoutput = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_xyzw = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->adjoint_vec_pids = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->XLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->YLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ZLEN = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->ovlp = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->numvec = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->grid_cache_len = pm);
  return 0;
}
int mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length(
    mapu_gpu_sort_one_grid_x_6_struct *kerstr, mapu_pscmc_mem *pm) {
  mapsSetDevice((kerstr->pe)->device_id);
  (kerstr->cu_cache_length = pm);
  return 0;
}

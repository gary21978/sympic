#ifndef MAPU_SORT_ONE_GRID_6_DISPATCH_H
#define MAPU_SORT_ONE_GRID_6_DISPATCH_H

#ifndef MAPU_SORT_ONE_GRID_6_USE_GPU
#define MAPU_SORT_ONE_GRID_6_USE_GPU
#endif

/* 1£ºmulti-thread mapu_gpu_sort_one_grid
 * 0: serial mapu_sort_one_grid
 */
#define MAPU_SORT_ONE_GRID_6_USE_GPU 1

#if MAPU_SORT_ONE_GRID_6_USE_GPU
#define MAPU_SORT_ONE_GRID_6_BRANCH_NAME "gpu_v2"

#define MAPU_GPU_SORT_ONE_GRID_6_DECLARE(axis)                                \
  int mapu_gpu_sort_one_grid_##axis##_6_init(                                 \
      mapu_pscmc_env *pe, mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr);  \
  void mapu_gpu_sort_one_grid_##axis##_6_get_struct_len(size_t *len);         \
  int mapu_gpu_sort_one_grid_##axis##_6_get_xlen(void);                       \
  int mapu_gpu_sort_one_grid_##axis##_6_exec(                                 \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr,                       \
      long scmc_internal_g_xlen, long scmc_internal_g_ylen);                  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_inoutput(          \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_xyzw(              \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_cu_cache(          \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_cu_xyzw(           \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_adjoint_vec_pids(  \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_XLEN(              \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_YLEN(              \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_ZLEN(              \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_ovlp(              \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_numvec(            \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_grid_cache_len(    \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm);  \
  int mapu_gpu_sort_one_grid_##axis##_6_scmc_set_parameter_cu_cache_length(   \
      mapu_gpu_sort_one_grid_##axis##_6_struct *kerstr, mapu_pscmc_mem *pm)

MAPU_GPU_SORT_ONE_GRID_6_DECLARE(x);
MAPU_GPU_SORT_ONE_GRID_6_DECLARE(y);
MAPU_GPU_SORT_ONE_GRID_6_DECLARE(z);

#undef MAPU_GPU_SORT_ONE_GRID_6_DECLARE

#define MAPU_SORT_ONE_GRID_X6_GET_STRUCT_LEN mapu_gpu_sort_one_grid_x_6_get_struct_len
#define MAPU_SORT_ONE_GRID_X6_INIT mapu_gpu_sort_one_grid_x_6_init
#define MAPU_SORT_ONE_GRID_X6_GET_XLEN mapu_gpu_sort_one_grid_x_6_get_xlen
#define MAPU_SORT_ONE_GRID_X6_EXEC mapu_gpu_sort_one_grid_x_6_exec
#define MAPU_SORT_ONE_GRID_X6_SET_INOUTPUT mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput
#define MAPU_SORT_ONE_GRID_X6_SET_XYZW mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw
#define MAPU_SORT_ONE_GRID_X6_SET_CU_CACHE mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache
#define MAPU_SORT_ONE_GRID_X6_SET_CU_XYZW mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw
#define MAPU_SORT_ONE_GRID_X6_SET_ADJOINT mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids
#define MAPU_SORT_ONE_GRID_X6_SET_XLEN mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN
#define MAPU_SORT_ONE_GRID_X6_SET_YLEN mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN
#define MAPU_SORT_ONE_GRID_X6_SET_ZLEN mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN
#define MAPU_SORT_ONE_GRID_X6_SET_OVLP mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp
#define MAPU_SORT_ONE_GRID_X6_SET_NUMVEC mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec
#define MAPU_SORT_ONE_GRID_X6_SET_GRID_CACHE_LEN mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len
#define MAPU_SORT_ONE_GRID_X6_SET_CU_CACHE_LENGTH mapu_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length

#define MAPU_SORT_ONE_GRID_Y6_GET_STRUCT_LEN mapu_gpu_sort_one_grid_y_6_get_struct_len
#define MAPU_SORT_ONE_GRID_Y6_INIT mapu_gpu_sort_one_grid_y_6_init
#define MAPU_SORT_ONE_GRID_Y6_GET_XLEN mapu_gpu_sort_one_grid_y_6_get_xlen
#define MAPU_SORT_ONE_GRID_Y6_EXEC mapu_gpu_sort_one_grid_y_6_exec
#define MAPU_SORT_ONE_GRID_Y6_SET_INOUTPUT mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput
#define MAPU_SORT_ONE_GRID_Y6_SET_XYZW mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw
#define MAPU_SORT_ONE_GRID_Y6_SET_CU_CACHE mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache
#define MAPU_SORT_ONE_GRID_Y6_SET_CU_XYZW mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw
#define MAPU_SORT_ONE_GRID_Y6_SET_ADJOINT mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids
#define MAPU_SORT_ONE_GRID_Y6_SET_XLEN mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN
#define MAPU_SORT_ONE_GRID_Y6_SET_YLEN mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN
#define MAPU_SORT_ONE_GRID_Y6_SET_ZLEN mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN
#define MAPU_SORT_ONE_GRID_Y6_SET_OVLP mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp
#define MAPU_SORT_ONE_GRID_Y6_SET_NUMVEC mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec
#define MAPU_SORT_ONE_GRID_Y6_SET_GRID_CACHE_LEN mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len
#define MAPU_SORT_ONE_GRID_Y6_SET_CU_CACHE_LENGTH mapu_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length

#define MAPU_SORT_ONE_GRID_Z6_GET_STRUCT_LEN mapu_gpu_sort_one_grid_z_6_get_struct_len
#define MAPU_SORT_ONE_GRID_Z6_INIT mapu_gpu_sort_one_grid_z_6_init
#define MAPU_SORT_ONE_GRID_Z6_GET_XLEN mapu_gpu_sort_one_grid_z_6_get_xlen
#define MAPU_SORT_ONE_GRID_Z6_EXEC mapu_gpu_sort_one_grid_z_6_exec
#define MAPU_SORT_ONE_GRID_Z6_SET_INOUTPUT mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput
#define MAPU_SORT_ONE_GRID_Z6_SET_XYZW mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw
#define MAPU_SORT_ONE_GRID_Z6_SET_CU_CACHE mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache
#define MAPU_SORT_ONE_GRID_Z6_SET_CU_XYZW mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw
#define MAPU_SORT_ONE_GRID_Z6_SET_ADJOINT mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids
#define MAPU_SORT_ONE_GRID_Z6_SET_XLEN mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN
#define MAPU_SORT_ONE_GRID_Z6_SET_YLEN mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN
#define MAPU_SORT_ONE_GRID_Z6_SET_ZLEN mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN
#define MAPU_SORT_ONE_GRID_Z6_SET_OVLP mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp
#define MAPU_SORT_ONE_GRID_Z6_SET_NUMVEC mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec
#define MAPU_SORT_ONE_GRID_Z6_SET_GRID_CACHE_LEN mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len
#define MAPU_SORT_ONE_GRID_Z6_SET_CU_CACHE_LENGTH mapu_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length

#else
#define MAPU_SORT_ONE_GRID_6_BRANCH_NAME "serial"

#define MAPU_SORT_ONE_GRID_X6_GET_STRUCT_LEN mapu_sort_one_grid_x_6_get_struct_len
#define MAPU_SORT_ONE_GRID_X6_INIT mapu_sort_one_grid_x_6_init
#define MAPU_SORT_ONE_GRID_X6_GET_XLEN mapu_sort_one_grid_x_6_get_xlen
#define MAPU_SORT_ONE_GRID_X6_EXEC mapu_sort_one_grid_x_6_exec
#define MAPU_SORT_ONE_GRID_X6_SET_INOUTPUT mapu_sort_one_grid_x_6_scmc_set_parameter_inoutput
#define MAPU_SORT_ONE_GRID_X6_SET_XYZW mapu_sort_one_grid_x_6_scmc_set_parameter_xyzw
#define MAPU_SORT_ONE_GRID_X6_SET_CU_CACHE mapu_sort_one_grid_x_6_scmc_set_parameter_cu_cache
#define MAPU_SORT_ONE_GRID_X6_SET_CU_XYZW mapu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw
#define MAPU_SORT_ONE_GRID_X6_SET_ADJOINT mapu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids
#define MAPU_SORT_ONE_GRID_X6_SET_XLEN mapu_sort_one_grid_x_6_scmc_set_parameter_XLEN
#define MAPU_SORT_ONE_GRID_X6_SET_YLEN mapu_sort_one_grid_x_6_scmc_set_parameter_YLEN
#define MAPU_SORT_ONE_GRID_X6_SET_ZLEN mapu_sort_one_grid_x_6_scmc_set_parameter_ZLEN
#define MAPU_SORT_ONE_GRID_X6_SET_OVLP mapu_sort_one_grid_x_6_scmc_set_parameter_ovlp
#define MAPU_SORT_ONE_GRID_X6_SET_NUMVEC mapu_sort_one_grid_x_6_scmc_set_parameter_numvec
#define MAPU_SORT_ONE_GRID_X6_SET_GRID_CACHE_LEN mapu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len
#define MAPU_SORT_ONE_GRID_X6_SET_CU_CACHE_LENGTH mapu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length

#define MAPU_SORT_ONE_GRID_Y6_GET_STRUCT_LEN mapu_sort_one_grid_y_6_get_struct_len
#define MAPU_SORT_ONE_GRID_Y6_INIT mapu_sort_one_grid_y_6_init
#define MAPU_SORT_ONE_GRID_Y6_GET_XLEN mapu_sort_one_grid_y_6_get_xlen
#define MAPU_SORT_ONE_GRID_Y6_EXEC mapu_sort_one_grid_y_6_exec
#define MAPU_SORT_ONE_GRID_Y6_SET_INOUTPUT mapu_sort_one_grid_y_6_scmc_set_parameter_inoutput
#define MAPU_SORT_ONE_GRID_Y6_SET_XYZW mapu_sort_one_grid_y_6_scmc_set_parameter_xyzw
#define MAPU_SORT_ONE_GRID_Y6_SET_CU_CACHE mapu_sort_one_grid_y_6_scmc_set_parameter_cu_cache
#define MAPU_SORT_ONE_GRID_Y6_SET_CU_XYZW mapu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw
#define MAPU_SORT_ONE_GRID_Y6_SET_ADJOINT mapu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids
#define MAPU_SORT_ONE_GRID_Y6_SET_XLEN mapu_sort_one_grid_y_6_scmc_set_parameter_XLEN
#define MAPU_SORT_ONE_GRID_Y6_SET_YLEN mapu_sort_one_grid_y_6_scmc_set_parameter_YLEN
#define MAPU_SORT_ONE_GRID_Y6_SET_ZLEN mapu_sort_one_grid_y_6_scmc_set_parameter_ZLEN
#define MAPU_SORT_ONE_GRID_Y6_SET_OVLP mapu_sort_one_grid_y_6_scmc_set_parameter_ovlp
#define MAPU_SORT_ONE_GRID_Y6_SET_NUMVEC mapu_sort_one_grid_y_6_scmc_set_parameter_numvec
#define MAPU_SORT_ONE_GRID_Y6_SET_GRID_CACHE_LEN mapu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len
#define MAPU_SORT_ONE_GRID_Y6_SET_CU_CACHE_LENGTH mapu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length

#define MAPU_SORT_ONE_GRID_Z6_GET_STRUCT_LEN mapu_sort_one_grid_z_6_get_struct_len
#define MAPU_SORT_ONE_GRID_Z6_INIT mapu_sort_one_grid_z_6_init
#define MAPU_SORT_ONE_GRID_Z6_GET_XLEN mapu_sort_one_grid_z_6_get_xlen
#define MAPU_SORT_ONE_GRID_Z6_EXEC mapu_sort_one_grid_z_6_exec
#define MAPU_SORT_ONE_GRID_Z6_SET_INOUTPUT mapu_sort_one_grid_z_6_scmc_set_parameter_inoutput
#define MAPU_SORT_ONE_GRID_Z6_SET_XYZW mapu_sort_one_grid_z_6_scmc_set_parameter_xyzw
#define MAPU_SORT_ONE_GRID_Z6_SET_CU_CACHE mapu_sort_one_grid_z_6_scmc_set_parameter_cu_cache
#define MAPU_SORT_ONE_GRID_Z6_SET_CU_XYZW mapu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw
#define MAPU_SORT_ONE_GRID_Z6_SET_ADJOINT mapu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids
#define MAPU_SORT_ONE_GRID_Z6_SET_XLEN mapu_sort_one_grid_z_6_scmc_set_parameter_XLEN
#define MAPU_SORT_ONE_GRID_Z6_SET_YLEN mapu_sort_one_grid_z_6_scmc_set_parameter_YLEN
#define MAPU_SORT_ONE_GRID_Z6_SET_ZLEN mapu_sort_one_grid_z_6_scmc_set_parameter_ZLEN
#define MAPU_SORT_ONE_GRID_Z6_SET_OVLP mapu_sort_one_grid_z_6_scmc_set_parameter_ovlp
#define MAPU_SORT_ONE_GRID_Z6_SET_NUMVEC mapu_sort_one_grid_z_6_scmc_set_parameter_numvec
#define MAPU_SORT_ONE_GRID_Z6_SET_GRID_CACHE_LEN mapu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len
#define MAPU_SORT_ONE_GRID_Z6_SET_CU_CACHE_LENGTH mapu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length

#endif

#endif

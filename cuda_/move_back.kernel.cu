
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32
__device__ int cuda_is_in(long x, long xl, long xr) {
  return ((x < xr) && (x >= xl));
}
__global__ void cuda_move_back_kernel_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, long XLEN,
                                        long YLEN, long ZLEN, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  long j = 0;

  __shared__ double local_temp_particle_cache[(64 * 6)];
  int cu_load = (cu_xyzw)[(4 * __idy)];

  int cur_cu_load = 0;

  for (i = 0; (i < cu_load); (i = (i + 64))) {
    long numcp = ((((i + 64) > cu_load)) ? ((cu_load - i)) : (64));

    {
      long MYGEN5 = 0;

      for (; (MYGEN5 < (numcp * 6)); (MYGEN5 = (MYGEN5 + __xlen))) {
        int ridx = (MYGEN5 + __idx);

        if (ridx < (numcp * 6)) {
          (((local_temp_particle_cache + (0 * 6)))[ridx] = ((cu_cache + (((cu_cache_length * __idy) + i) * 6)))[ridx]);
        }
      }
    }
    __syncthreads();
    if (__idx == 0) {
      for (j = 0; (j < numcp); j++) {

        long xyzx = floor(((local_temp_particle_cache + (j * 6)))[0]);

        long xyzy = floor(((local_temp_particle_cache + (j * 6)))[1]);

        long xyzz = floor(((local_temp_particle_cache + (j * 6)))[2]);


        int wrted_grid = 0;

        if ((cuda_is_in(xyzx, 0, XLEN) && (cuda_is_in(xyzy, 0, YLEN) && cuda_is_in(xyzz, 0, ZLEN)))) {
          long allid_grid = ((0 + (1 * (xyzx + (XLEN * (xyzy + (YLEN * xyzz)))))) + cu_offset);

          int gridload = (xyzw)[(4 * allid_grid)];

          if (gridload < grid_cache_len) {
            long grid_load_end = (gridload + 1);

            ((xyzw)[(4 * allid_grid)] = grid_load_end);
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((inoutput + (6 * ((allid_grid * grid_cache_len) + gridload))))[((inner_step * 1) + inner_g)] =
                         ((local_temp_particle_cache + (j * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (wrted_grid = 1);
          }
        }

        if (!wrted_grid) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache + (6 * ((__idy * cu_cache_length) + cur_cu_load))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache + (j * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
          (cur_cu_load = (cur_cu_load + 1));
        }
      }
    }
  }
  if (__idx == 0) {
    ((cu_xyzw)[(__idy * 4)] = cur_cu_load);
  }
}
__global__ void cuda_move_back_kernel_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, long XLEN,
                                        long YLEN, long ZLEN, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  long j = 0;

  __shared__ double local_temp_particle_cache[(64 * 8)];
  int cu_load = (cu_xyzw)[(4 * __idy)];

  int cur_cu_load = 0;

  for (i = 0; (i < cu_load); (i = (i + 64))) {
    long numcp = ((((i + 64) > cu_load)) ? ((cu_load - i)) : (64));

    {
      long MYGEN6 = 0;

      for (; (MYGEN6 < (numcp * 8)); (MYGEN6 = (MYGEN6 + __xlen))) {
        int ridx = (MYGEN6 + __idx);

        if (ridx < (numcp * 8)) {
          (((local_temp_particle_cache + (0 * 8)))[ridx] = ((cu_cache + (((cu_cache_length * __idy) + i) * 8)))[ridx]);
        }
      }
    }
    __syncthreads();
    if (__idx == 0) {
      for (j = 0; (j < numcp); j++) {

        long xyzx = floor(((local_temp_particle_cache + (j * 8)))[0]);

        long xyzy = floor(((local_temp_particle_cache + (j * 8)))[1]);

        long xyzz = floor(((local_temp_particle_cache + (j * 8)))[2]);


        int wrted_grid = 0;

        if ((cuda_is_in(xyzx, 0, XLEN) && (cuda_is_in(xyzy, 0, YLEN) && cuda_is_in(xyzz, 0, ZLEN)))) {
          long allid_grid = ((0 + (1 * (xyzx + (XLEN * (xyzy + (YLEN * xyzz)))))) + cu_offset);

          int gridload = (xyzw)[(4 * allid_grid)];

          if (gridload < grid_cache_len) {
            long grid_load_end = (gridload + 1);

            ((xyzw)[(4 * allid_grid)] = grid_load_end);
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((inoutput + (8 * ((allid_grid * grid_cache_len) + gridload))))[((inner_step * 1) + inner_g)] =
                         ((local_temp_particle_cache + (j * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (wrted_grid = 1);
          }
        }

        if (!wrted_grid) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache + (8 * ((__idy * cu_cache_length) + cur_cu_load))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache + (j * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
          (cur_cu_load = (cur_cu_load + 1));
        }
      }
    }
  }
  if (__idx == 0) {
    ((cu_xyzw)[(__idy * 4)] = cur_cu_load);
  }
}

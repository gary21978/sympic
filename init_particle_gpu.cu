#include "init_particle_gpu.h"

#include <assert.h>
#include <cuda_runtime.h>
#include <math.h>
#include <stdio.h>

#define INIT_PARTICLE_GPU_CHECK(err, msg)                                                                              \
  do {                                                                                                                 \
    cudaError_t _err = (err);                                                                                          \
    if (_err != cudaSuccess) {                                                                                         \
      fprintf(stderr, "Error:%s\n%s\n", cudaGetErrorString(_err), (msg));                                             \
      assert(0);                                                                                                       \
    }                                                                                                                  \
  } while (0)

__device__ static unsigned long long init_particle_splitmix64(unsigned long long *state) {
  unsigned long long z = (*state += 0x9e3779b97f4a7c15ULL);
  z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
  z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
  return z ^ (z >> 31);
}

__device__ static double init_particle_uniform01(unsigned long long *state) {
  unsigned long long x = init_particle_splitmix64(state);
  return ((x >> 11) + 1.0) * (1.0 / 9007199254740993.0);
}

__device__ static double init_particle_normal(unsigned long long *state, double mean, double sigma) {
  double u1 = init_particle_uniform01(state);
  double u2 = init_particle_uniform01(state);
  return sigma * sqrt(-2.0 * log(u1)) * cos(6.28318530717958647692 * u2) + mean;
}

__global__ static void init_non_uni_particle_gpu_kernel(double *inoutput,
                                                        int *xyzw,
                                                        long xlen,
                                                        long ylen,
                                                        long zlen,
                                                        long numvec,
                                                        long grid_cache_len,
                                                        int grid_load,
                                                        int ptlen,
                                                        double vt,
                                                        double vmax,
                                                        double vx0,
                                                        double vy0,
                                                        double vz0,
                                                        double tempx,
                                                        double tempy,
                                                        double tempz,
                                                        unsigned long long seed) {
  size_t idx = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;
  size_t cells = (size_t)xlen * (size_t)ylen * (size_t)zlen * (size_t)numvec;
  size_t total = cells * (size_t)grid_load;
  if (idx >= total) return;

  long l = (long)(idx % (size_t)grid_load);
  size_t cell_id = idx / (size_t)grid_load;
  long local = (long)(cell_id % ((size_t)xlen * (size_t)ylen * (size_t)zlen));
  long cur_pcid = (long)(cell_id / ((size_t)xlen * (size_t)ylen * (size_t)zlen));
  long xyzx = local % xlen;
  long xyzy = (local / xlen) % ylen;
  long xyzz = local / (xlen * ylen);

  size_t cell_offset = (size_t)cur_pcid * (size_t)xlen * (size_t)ylen * (size_t)zlen;
  cell_offset += (size_t)(xyzx + xlen * (xyzy + ylen * xyzz));
  xyzw[4 * cell_offset] = grid_load;

  double *xyzvs = inoutput + (size_t)cur_pcid * ((size_t)xlen * (size_t)ylen * (size_t)zlen) *
                                 (size_t)(6 * grid_cache_len);
  xyzvs += (size_t)(6 * grid_cache_len) * (size_t)(xyzx + xlen * (xyzy + ylen * xyzz));
  xyzvs += (size_t)l * (size_t)ptlen;

  unsigned long long state = seed ^ ((unsigned long long)idx + 1ULL) * 0xd1b54a32d192ed03ULL;
  xyzvs[0] = (double)xyzx + init_particle_uniform01(&state);
  xyzvs[1] = (double)xyzy + init_particle_uniform01(&state);
  xyzvs[2] = (double)xyzz + init_particle_uniform01(&state);

  double vx, vy, vz;
  do {
    vx = init_particle_normal(&state, vx0, tempx * vt);
    vy = init_particle_normal(&state, vy0, tempy * vt);
    vz = init_particle_normal(&state, vz0, tempz * vt);
  } while ((vx * vx + vy * vy + vz * vz) >= vmax);

  xyzvs[3] = vx;
  xyzvs[4] = vy;
  xyzvs[5] = vz;
}

extern "C" int launch_init_non_uni_particle_gpu(double *inoutput,
                                                 int *xyzw,
                                                 int *cu_xyzw,
                                                 long xlen,
                                                 long ylen,
                                                 long zlen,
                                                 long numvec,
                                                 long grid_cache_len,
                                                 int grid_load,
                                                 int ptlen,
                                                 double vt,
                                                 double vmax,
                                                 double vx0,
                                                 double vy0,
                                                 double vz0,
                                                 double tempx,
                                                 double tempy,
                                                 double tempz,
                                                 unsigned long long seed,
                                                 int device_id) {
  cudaSetDevice(device_id);
  size_t cells = (size_t)xlen * (size_t)ylen * (size_t)zlen * (size_t)numvec;
  size_t total = cells * (size_t)grid_load;
  if (cells == 0 || grid_load <= 0) return 0;

  INIT_PARTICLE_GPU_CHECK(cudaMemset(inoutput, 0, cells * (size_t)(6 * grid_cache_len) * sizeof(double)),
                          "Failed to clear particle inoutput");
  INIT_PARTICLE_GPU_CHECK(cudaMemset(xyzw, 0, cells * 4 * sizeof(int)), "Failed to clear particle xyzw");
  INIT_PARTICLE_GPU_CHECK(cudaMemset(cu_xyzw, 0, (size_t)numvec * 4 * sizeof(int)), "Failed to clear particle cu_xyzw");

  int block = 256;
  int grid = (int)((total + (size_t)block - 1) / (size_t)block);
  init_non_uni_particle_gpu_kernel<<<grid, block>>>(inoutput, xyzw, xlen, ylen, zlen, numvec, grid_cache_len, grid_load,
                                                    ptlen, vt, vmax, vx0, vy0, vz0, tempx, tempy, tempz, seed);
  INIT_PARTICLE_GPU_CHECK(cudaGetLastError(), "Failed to launch particle init kernel");
  INIT_PARTICLE_GPU_CHECK(cudaDeviceSynchronize(), "Failed to finish particle init kernel");
  return 0;
}

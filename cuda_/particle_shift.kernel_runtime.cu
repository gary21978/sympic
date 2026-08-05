#include <stdio.h>
#include <cuda_runtime.h>

__global__ void cuda_particle_shift_kernel(
    double *cu_cache, int *cu_xyzw, const int *frl,
    long cu_cache_length, int dir, long XYZLEN, int ptlen)
{
  long j = blockIdx.x;
  int cur_len = cu_xyzw[4 * j];
  int n = frl[j];
  if (n <= 0) return;
  long base = j * cu_cache_length * 6;
  for (int i = threadIdx.x; i < n; i += blockDim.x)
    cu_cache[base + (cur_len + i) * ptlen + dir] += XYZLEN;
  if (threadIdx.x == 0)
    cu_xyzw[4 * j] = cur_len + n;
}

extern "C" int cuda_particle_shift_launch(
    double *cu_cache, int *cu_xyzw, const int *frl,
    long cu_cache_length, long numvec, int dir, long XYZLEN,
    int ptlen, int device_id)
{
  cudaError_t err = cudaSetDevice(device_id);
  if (err != cudaSuccess) {
    fprintf(stderr, "particle_shift: cudaSetDevice(%d) failed: %s\n",
            device_id, cudaGetErrorString(err));
    return 1;
  }
  cuda_particle_shift_kernel<<<numvec, 256>>>(cu_cache, cu_xyzw, frl,
      cu_cache_length, dir, XYZLEN, ptlen);
  err = cudaGetLastError();
  if (err != cudaSuccess) {
    fprintf(stderr, "particle_shift: launch failed: %s\n",
            cudaGetErrorString(err));
    return 2;
  }
  return 0;
}

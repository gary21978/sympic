#include "local_halo_copy.kernel_runtime.h"

#include <assert.h>
#include <cuda_runtime.h>
#include <stdio.h>

__global__ static void cuda_local_halo_copy_kernel(double *dst_base,
                                                   const double *src_base,
                                                   const long *dst_tid,
                                                   const long *src_tid,
                                                   long ncopy, long sllen,
                                                   long numvec,
                                                   size_t recv_offset) {
  size_t idx = blockIdx.x * blockDim.x + threadIdx.x;
  size_t total = (size_t)ncopy * (size_t)sllen;
  if (idx >= total) return;

  long copy_id = (long)(idx / (size_t)sllen);
  long elem = (long)(idx - (size_t)copy_id * (size_t)sllen);
  long dst = dst_tid[copy_id] * sllen + elem;
  long src = src_tid[copy_id] * sllen + elem;
  dst_base[-((long)recv_offset + sllen * numvec) + dst] =
      src_base[(long)recv_offset + src];
}

int cuda_local_halo_copy_launch(double *dst_base, const double *src_base,
                                const long *dst_tid_d, const long *src_tid_d,
                                long ncopy, long sllen, long numvec,
                                size_t recv_offset, int device_id) {
  (void)device_id;
  size_t total = (size_t)ncopy * (size_t)sllen;
  if (total == 0) return 0;

  int block = 256;
  int grid = (int)((total + (size_t)block - 1) / (size_t)block);
  cuda_local_halo_copy_kernel<<<grid, block>>>(dst_base, src_base, dst_tid_d,
                                               src_tid_d, ncopy, sllen,
                                               numvec, recv_offset);
  cudaError_t err = cudaGetLastError();
  if (err != cudaSuccess) {
    fprintf(stderr, "local halo copy kernel launch failed: %s\n",
            cudaGetErrorString(err));
    assert(0);
  }
  return 0;
}

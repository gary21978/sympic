#include "local_halo_copy.h"

__global__ static void local_halo_copy_kernel(double *dst_base,
                                              const double *src_base,
                                              const long *dst_tid,
                                              const long *src_tid,
                                              long ncopy,
                                              long sllen,
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

extern "C" void launch_local_halo_copy(double *dst_base, const double *src_base,
                                        const long *dst_tid, const long *src_tid,
                                        long ncopy, long sllen, long numvec,
                                        size_t recv_offset) {
  size_t total = (size_t)ncopy * (size_t)sllen;
  if (total == 0) return;
  int block = 256;
  int grid = (int)((total + block - 1) / block);
  local_halo_copy_kernel<<<grid, block>>>(dst_base, src_base, dst_tid, src_tid,
                                          ncopy, sllen, numvec, recv_offset);
}

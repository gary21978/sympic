#include "local_halo_copy.h"

#include <assert.h>
#include <cuda_runtime.h>
#include <stdio.h>

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

__global__ static void field_halo_copy_segments_kernel(double *dst_base,
                                                       const double *src_base,
                                                       const long *src_off,
                                                       const long *dst_off,
                                                       const long *len,
                                                       long nseg) {
  long seg = (long)blockIdx.x;
  if (seg >= nseg) return;

  long src0 = src_off[seg];
  long dst0 = dst_off[seg];
  long n = len[seg];
  for (long elem = (long)threadIdx.x; elem < n; elem += (long)blockDim.x) {
    dst_base[dst0 + elem] = src_base[src0 + elem];
  }
}

static void launch_field_halo_copy_segments(double *dst_base,
                                            const double *src_base,
                                            const long *src_off_d,
                                            const long *dst_off_d,
                                            const long *len_d, long nseg,
                                            const char *op_name) {
  if (nseg == 0) return;

  int block = 256;
  field_halo_copy_segments_kernel<<<(unsigned int)nseg, block>>>(
      dst_base, src_base, src_off_d, dst_off_d, len_d, nseg);
  cudaError_t err = cudaGetLastError();
  if (err != cudaSuccess) {
    fprintf(stderr, "%s field halo kernel launch failed: %s\n", op_name,
            cudaGetErrorString(err));
    assert(0);
  }
}

extern "C" void launch_field_halo_pack(double *dst_base, const double *src_base,
                                       const long *src_off_d,
                                       const long *dst_off_d,
                                       const long *len_d, long nseg) {
  launch_field_halo_copy_segments(dst_base, src_base, src_off_d, dst_off_d,
                                  len_d, nseg, "pack");
}

extern "C" void launch_field_halo_unpack(double *dst_base,
                                         const double *src_base,
                                         const long *src_off_d,
                                         const long *dst_off_d,
                                         const long *len_d, long nseg) {
  launch_field_halo_copy_segments(dst_base, src_base, src_off_d, dst_off_d,
                                  len_d, nseg, "unpack");
}

/* Packed particle-sort exchange: segment gather/scatter for the meta rows
   (int) and particle data (double). */
__global__ static void sort_copy_segments_int_kernel(int *dst_base,
                                                     const int *src_base,
                                                     const long *src_off,
                                                     const long *dst_off,
                                                     const long *len,
                                                     long nseg) {
  long seg = (long)blockIdx.x;
  if (seg >= nseg) return;
  long src0 = src_off[seg];
  long dst0 = dst_off[seg];
  long n = len[seg];
  for (long elem = (long)threadIdx.x; elem < n; elem += (long)blockDim.x) {
    dst_base[dst0 + elem] = src_base[src0 + elem];
  }
}

__global__ static void sort_copy_segments_double_kernel(double *dst_base,
                                                        const double *src_base,
                                                        const long *src_off,
                                                        const long *dst_off,
                                                        const long *len,
                                                        long nseg) {
  long seg = (long)blockIdx.x;
  if (seg >= nseg) return;
  long src0 = src_off[seg];
  long dst0 = dst_off[seg];
  long n = len[seg];
  for (long elem = (long)threadIdx.x; elem < n; elem += (long)blockDim.x) {
    dst_base[dst0 + elem] = src_base[src0 + elem];
  }
}

static void sort_copy_segments_launch(void *dst_base, const void *src_base,
                                      const long *src_off_d,
                                      const long *dst_off_d,
                                      const long *len_d, long nseg, int is_int,
                                      const char *op_name) {
  if (nseg == 0) return;
  int block = 256;
  if (is_int)
    sort_copy_segments_int_kernel<<<(unsigned int)nseg, block>>>(
        (int *)dst_base, (const int *)src_base, src_off_d, dst_off_d, len_d,
        nseg);
  else
    sort_copy_segments_double_kernel<<<(unsigned int)nseg, block>>>(
        (double *)dst_base, (const double *)src_base, src_off_d, dst_off_d,
        len_d, nseg);
  cudaError_t err = cudaGetLastError();
  if (err != cudaSuccess) {
    fprintf(stderr, "%s sort segment kernel launch failed: %s\n", op_name,
            cudaGetErrorString(err));
    assert(0);
  }
}

extern "C" void launch_sort_copy_int(int *dst_base, const int *src_base,
                                     const long *src_off_d,
                                     const long *dst_off_d,
                                     const long *len_d, long nseg) {
  sort_copy_segments_launch(dst_base, src_base, src_off_d, dst_off_d, len_d,
                            nseg, 1, "int");
}

extern "C" void launch_sort_copy_double(double *dst_base, const double *src_base,
                                        const long *src_off_d,
                                        const long *dst_off_d,
                                        const long *len_d, long nseg) {
  sort_copy_segments_launch(dst_base, src_base, src_off_d, dst_off_d, len_d,
                            nseg, 0, "double");
}

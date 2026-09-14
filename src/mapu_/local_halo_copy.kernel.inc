__global__ void mapu_local_halo_copy(__DDR double *dst_base,
                                     __DDR const double *src_base,
                                     __DDR const long *dst_tid,
                                     __DDR const long *src_tid,
                                     long ncopy,
                                     long sllen,
                                     long numvec,
                                     size_t recv_offset) {
  size_t idx = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;
  size_t total = (size_t)ncopy * (size_t)sllen;
  if (idx >= total) return;

  long copy_id = (long)(idx / (size_t)sllen);
  long elem = (long)(idx - (size_t)copy_id * (size_t)sllen);
  long dst = dst_tid[copy_id] * sllen + elem;
  long src = src_tid[copy_id] * sllen + elem;
  dst_base[-((long)recv_offset + sllen * numvec) + dst] =
      src_base[(long)recv_offset + src];
}

__global__ void mapu_field_halo_copy_segments(__DDR double *dst_base,
                                              __DDR const double *src_base,
                                              __DDR const long *src_off,
                                              __DDR const long *dst_off,
                                              __DDR const long *len,
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

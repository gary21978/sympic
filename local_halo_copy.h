#ifndef LOCAL_HALO_COPY_H
#define LOCAL_HALO_COPY_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void launch_local_halo_copy(double *dst_base, const double *src_base,
                            const long *dst_tid, const long *src_tid,
                            long ncopy, long sllen, long numvec,
                            size_t recv_offset);

/* Packed field-halo P2P: gather/scatter segment copies for the packed
   ncclSend/ncclRecv buffers. */
void launch_field_halo_pack(double *dst_base, const double *src_base,
                            const long *src_off_d, const long *dst_off_d,
                            const long *len_d, long nseg);

void launch_field_halo_unpack(double *dst_base, const double *src_base,
                              const long *src_off_d, const long *dst_off_d,
                              const long *len_d, long nseg);

#ifdef __cplusplus
}
#endif

#endif

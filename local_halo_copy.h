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

#ifdef __cplusplus
}
#endif

#endif

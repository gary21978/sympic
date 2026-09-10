#ifndef LOCAL_HALO_COPY_KERNEL_RUNTIME_H
#define LOCAL_HALO_COPY_KERNEL_RUNTIME_H

#ifdef __cplusplus
extern "C" {
#endif

int cuda_local_halo_copy_launch(double *dst_base, const double *src_base,
                                const long *dst_tid_d, const long *src_tid_d,
                                long ncopy, long sllen, long numvec,
                                size_t recv_offset, int device_id);

#ifdef __cplusplus
}
#endif

#endif

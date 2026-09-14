#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "local_header.h"
#include "mapu_pscmc.h"
#include "local_halo_copy.kernel_runtime.h"
#include "local_halo_copy.kernel.inc"

int mapu_local_halo_copy_launch(double *dst_base, const double *src_base,
                                const long *dst_tid_d, const long *src_tid_d,
                                long ncopy, long sllen, long numvec,
                                size_t recv_offset, int device_id)
{
    mapsSetDevice(device_id);
    size_t total = (size_t)ncopy * (size_t)sllen;
    if (total == 0)
    {
        return 0;
    }

    int block = 4;
    int grid = (int)((total + (size_t)block - 1) / (size_t)block);
    mapu_local_halo_copy<<<grid, block>>>(
        (__DDR double *)dst_base, (__DDR const double *)src_base,
        (__DDR const long *)dst_tid_d, (__DDR const long *)src_tid_d,
        ncopy, sllen, numvec, recv_offset);
    return 0;
}

static int mapu_field_halo_copy_segments_launch(
    double *dst_base, const double *src_base, const long *src_off_d,
    const long *dst_off_d, const long *len_d, long nseg, int device_id) {
    mapsSetDevice(device_id);
    if (nseg == 0) {
        return 0;
    }

    int block = 4;
    mapu_field_halo_copy_segments<<<(int)nseg, block>>>(
        (__DDR double *)dst_base, (__DDR const double *)src_base,
        (__DDR const long *)src_off_d, (__DDR const long *)dst_off_d,
        (__DDR const long *)len_d, nseg);
    return 0;
}

int mapu_field_halo_pack_launch(double *dst_base, const double *src_base,
                                const long *src_off_d, const long *dst_off_d,
                                const long *len_d, long nseg,
                                int device_id) {
    return mapu_field_halo_copy_segments_launch(dst_base, src_base, src_off_d,
                                                dst_off_d, len_d, nseg,
                                                device_id);
}

int mapu_field_halo_unpack_launch(double *dst_base, const double *src_base,
                                  const long *src_off_d, const long *dst_off_d,
                                  const long *len_d, long nseg,
                                  int device_id) {
    return mapu_field_halo_copy_segments_launch(dst_base, src_base, src_off_d,
                                                dst_off_d, len_d, nseg,
                                                device_id);
}

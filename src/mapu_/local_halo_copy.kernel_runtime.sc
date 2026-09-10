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

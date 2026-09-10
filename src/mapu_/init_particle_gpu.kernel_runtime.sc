#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "local_header.h"
#include "mapu_pscmc.h"
#include "init_particle_gpu.kernel_runtime.h"
#include "init_particle_gpu.kernel.inc"

int mapu_init_non_uni_particle_gpu_launch(mapu_pscmc_mem *inoutput,
                                          mapu_pscmc_mem *xyzw,
                                          mapu_pscmc_mem *cu_xyzw,
                                          long xlen,
                                          long ylen,
                                          long zlen,
                                          long numvec,
                                          long grid_cache_len,
                                          int grid_load,
                                          int ptlen,
                                          double vt,
                                          double vmax,
                                          double vx0,
                                          double vy0,
                                          double vz0,
                                          double tempx,
                                          double tempy,
                                          double tempz,
                                          unsigned long long seed,
                                          int device_id)
{
    mapsSetDevice(device_id);
    size_t cells = (size_t)xlen * (size_t)ylen * (size_t)zlen * (size_t)numvec;
    size_t total = cells * (size_t)grid_load;
    if (cells == 0 || grid_load <= 0)
    {
        return 0;
    }

    mapsMemset(inoutput->d_data, 0, cells * (size_t)(6 * grid_cache_len) * sizeof(double));
    mapsMemset(xyzw->d_data, 0, cells * 4 * sizeof(int));
    mapsMemset(cu_xyzw->d_data, 0, (size_t)numvec * 4 * sizeof(int));

    int block = 4;
    int grid = (int)((total + (size_t)block - 1) / (size_t)block);
    mapu_init_non_uni_particle_gpu<<<grid, block>>>(
        (__DDR double *)inoutput->d_data,
        (__DDR int *)xyzw->d_data,
        (__DDR int *)cu_xyzw->d_data,
        xlen, ylen, zlen, numvec, grid_cache_len, grid_load, ptlen,
        vt, vmax, vx0, vy0, vz0, tempx, tempy, tempz, seed);

    mapsError_t err = mapsDeviceSynchronize();
    if (err != mapsSuccess)
    {
        fprintf(stderr, "mapu_init_non_uni_particle_gpu failed: %d\n", (int)err);
        assert(0);
        return -1;
    }
    return 0;
}

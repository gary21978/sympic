#pragma once

#ifdef __cplusplus
extern "C" {
#endif

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
                                          int device_id);

#ifdef __cplusplus
}
#endif

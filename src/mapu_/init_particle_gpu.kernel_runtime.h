#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* 粒子初始化 GPU 快路径（SYMPIC_INIT_PARTICLE_GPU_FAST）。
 * 返回 0 表示成功；非 0 表示不可用，调用方应回退 host 初始化。 */
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

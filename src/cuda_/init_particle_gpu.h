#ifndef INIT_PARTICLE_GPU_H
#define INIT_PARTICLE_GPU_H

#ifdef __cplusplus
extern "C" {
#endif

int launch_init_non_uni_particle_gpu(double *inoutput,
                                     int *xyzw,
                                     int *cu_xyzw,
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

#endif

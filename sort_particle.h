#include "pubdefs.h"

int cuda_call_particle_sort_single_x_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_y_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_z_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_x_vlo_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_y_vlo_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_z_vlo_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_x_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_y_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_z_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_x_vlo_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_y_vlo_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_z_vlo_8(One_Particle_Collection *pthis);

int cuda_call_move_back_kernel_single_6(One_Particle_Collection *pthis);

int cuda_call_move_back_kernel_single_8(One_Particle_Collection *pthis);
int call_particle_sort_single(One_Particle_Collection *pthis, int dir, int use_vlo, int ptlen);
int swap_particle_sort_host_l(Field3D_MPI *pthis, int dir, int mask);
int swap_particle_sort_host_r(Field3D_MPI *pthis, int dir, int mask);
int call_particle_sort_mpi_mask(Field3D_MPI *pthis, int dir, int use_vlo, int mask);
int call_particle_sort_mpi(Field3D_MPI *pthis, int dir, int use_vlo);

int cuda_particle_shift_launch(double *cu_cache, int *cu_xyzw, const int *frl,
    long cu_cache_length, long numvec, int dir, long XYZLEN,
    int ptlen, int device_id); /* USENCCL */
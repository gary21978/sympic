#include "pubdefs.h"
#ifdef SYMPIC_CUDA
int cuda_call_particle_sort_single_x_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_y_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_z_6(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_x_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_y_8(One_Particle_Collection *pthis);
int cuda_call_particle_sort_single_z_8(One_Particle_Collection *pthis);
#endif

#ifdef SYMPIC_MAPU
int mapu_call_particle_sort_single_x_6(One_Particle_Collection* pthis);
int mapu_call_particle_sort_single_y_6(One_Particle_Collection* pthis);
int mapu_call_particle_sort_single_z_6(One_Particle_Collection* pthis);
int mapu_call_particle_sort_single_x_8(One_Particle_Collection* pthis);
int mapu_call_particle_sort_single_y_8(One_Particle_Collection* pthis);
int mapu_call_particle_sort_single_z_8(One_Particle_Collection* pthis);
#endif

#ifdef SYMPIC_CUDA
int cuda_call_move_back_kernel_single_6(One_Particle_Collection *pthis);
int cuda_call_move_back_kernel_single_8(One_Particle_Collection *pthis);
#endif

#ifdef SYMPIC_MAPU
int mapu_call_move_back_kernel_single_6(One_Particle_Collection* pthis);
int mapu_call_move_back_kernel_single_8(One_Particle_Collection* pthis);
#endif

int call_particle_sort_single(One_Particle_Collection *pthis, int dir, int use_vlo, int ptlen);
int swap_particle_sort_host_l(Field3D_MPI *pthis, int dir, int mask);
int swap_particle_sort_host_r(Field3D_MPI *pthis, int dir, int mask);
int call_particle_sort_mpi_mask(Field3D_MPI *pthis, int dir, int use_vlo, int mask);
int call_particle_sort_mpi(Field3D_MPI *pthis, int dir, int use_vlo);

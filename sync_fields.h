#include "pubdefs.h"

int merge_ovlp_mpi_field(Field3D_MPI *pthis);
int sync_ovlp_mpi_field(Field3D_MPI *pthis);
int sync_main_data_d2h(Field3D_MPI *pthis);
int sync_main_data_h2d(Field3D_MPI *pthis);
void copy_between_devices(double *dst, int dst_dev, const double *src, int src_dev, size_t bytes); /* USENCCL */

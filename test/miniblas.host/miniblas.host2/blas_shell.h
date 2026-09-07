#include "basic.h"
#include "mpi_rel.h"

int blas_yisax_enlarge_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x);
int blas_axpy_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x);
int blas_yisax_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x);
int blas_yiszero_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y);
int blas_yiszero_synced_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y);
#include "pubdefs.h"

int cuda_blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int blas_yisax_enlarge_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x);

int cuda_blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int blas_axpy_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x);

int cuda_blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int blas_yisax_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x);

int cuda_blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y);
int blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y);
int blas_yiszero_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y);

int cuda_blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y);
int blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y);
int blas_yiszero_synced_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y);

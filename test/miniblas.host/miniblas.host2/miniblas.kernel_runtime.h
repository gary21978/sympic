#include "basic.h"
#ifdef __cplusplus
extern "C" {
#endif

int mapu_blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int mapu_blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int mapu_blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x);
int mapu_blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y);
int mapu_blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y);

#ifdef __cplusplus
} /* extern "C" */
#endif
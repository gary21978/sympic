#include "blas_shell.h"
#include "miniblas.kernel_runtime.h"

int blas_axpy_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x)
{
    for (long i = 0; i < pthis->num_runtime; i++)
    {
        mapu_blas_axpy_Field3D_Seq(pthis->data + i, y->data + i, a, x->data + i);
    }
    return 0;
}

int blas_yisax_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x)
{
    for (long i = 0; i < pthis->num_runtime; i++)
    {
        mapu_blas_yisax_Field3D_Seq(pthis->data + i, y->data + i, a, x->data + i);
    }
    return 0;
}

int blas_yisax_enlarge_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y, double a, Field3D_MPI *x)
{
    for (long i = 0; i < pthis->num_runtime; i++)
    {
        mapu_blas_yisax_enlarge_Field3D_Seq(pthis->data + i, y->data + i, a, x->data + i);
    }
    return 0;
}

int blas_yiszero_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y)
{
    for (long i = 0; i < pthis->num_runtime; i++)
    {
        mapu_blas_yiszero_Field3D_Seq(pthis->data + i, y->data + i);
    }
    return 0;
}

int blas_yiszero_synced_Field3D_MPI(Field3D_MPI *pthis, Field3D_MPI *y)
{
    for (long i = 0; i < pthis->num_runtime; i++)
    {
        mapu_blas_yiszero_synced_Field3D_Seq(pthis->data + i, y->data + i);
    }
    return 0;
}
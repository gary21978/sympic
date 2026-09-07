#include "blas_shell.h"
#include "init.h"
#include <stdio.h>

void init(Field3D_MPI* x_ptr, Field3D_MPI* y_ptr, int runtime, long long* len, int ovlp, int elenum, int vecnum)
{
    // init_Field3D_MPI_ALL    init_field3d_mpi.c
    x_ptr->num_runtime = runtime;
    y_ptr->num_runtime = runtime;
    size_t size = sizeof(Field3D_Seq) * runtime;
    x_ptr->data = malloc(size);
    y_ptr->data = malloc(size);

    for (int i = 0; i < runtime; i++)  //mpi TODO
    {
        init_seq(&(x_ptr->data[i]), &(y_ptr->data[i]), runtime, len, ovlp, elenum, vecnum);
    }
}
void reinit(Field3D_MPI* x_ptr, Field3D_MPI* y_ptr)
{
    for (int i = 0; i < x_ptr->num_runtime; i++)  //mpi TODO
    {
        reinit_seq(&(x_ptr->data[i]), &(y_ptr->data[i]));
    }    
}

void reinity(Field3D_MPI* y_ptr)
{
    for (int i = 0; i < y_ptr->num_runtime; i++)  //mpi TODO
    {
        reinity_seq(&(y_ptr->data[i]));
    }    
}

void reinit_enlargey(Field3D_MPI* x_ptr, Field3D_MPI* y_ptr)
{
    for (int i = 0; i < x_ptr->num_runtime; i++)  //mpi TODO
    {
        reinit_enlargey_seq(&(x_ptr->data[i]), &(y_ptr->data[i]));
    }    
}

int main()
{
    Field3D_MPI x;
    Field3D_MPI* x_ptr = &x;
    Field3D_MPI y;
    Field3D_MPI* y_ptr = &y;

    int runtime = 1;
    // long long len[3] = {4, 3, 2};
    long long len[3] = {20, 15, 2};
    int ovlp = 1;
    int elenum = 3;
    int vecnum = 2;

    init(x_ptr, y_ptr, runtime, len, ovlp, elenum, vecnum);
    blas_axpy_Field3D_MPI(y_ptr, y_ptr, 1, x_ptr);
    // mapsDeviceSynchronize();
    reinit(x_ptr, y_ptr);
    // mapsDeviceSynchronize();
    blas_yisax_Field3D_MPI(y_ptr, y_ptr, 1, x_ptr);
    // mapsDeviceSynchronize();
    reinity(y_ptr);
    // mapsDeviceSynchronize();
    long xb = len[0] + 2 * ovlp;
    long yb = len[1] + 2 * ovlp;
    long zb = len[2] + 2 * ovlp;
    for (int i = 0; i < runtime; i++)
    {
        void* dy = (void*)(((mapu_pscmc_mem*)(y.data[i].main_data))->d_data);
        mapsMemset(dy, 0, xb * yb * zb * elenum * vecnum * sizeof(double));
    }
    
    blas_yiszero_synced_Field3D_MPI(y_ptr, y_ptr);
    // mapsDeviceSynchronize();
    reinity(y_ptr);
    // mapsDeviceSynchronize();
    blas_yiszero_Field3D_MPI(y_ptr, y_ptr);
    // mapsDeviceSynchronize();
    reinit_enlargey(x_ptr, y_ptr);
    // mapsDeviceSynchronize();
    blas_yisax_enlarge_Field3D_MPI(y_ptr, y_ptr, 8, x_ptr);
    // mapsDeviceSynchronize();
    return 0;
}

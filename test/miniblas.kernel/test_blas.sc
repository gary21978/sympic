#include <scale.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <maps_runtime.h>
#include "../../src/c_/miniblas.kernel.sc"
#include "../../src/mapu_/miniblas.kernel.sc"


int main()
{
    const int num_ele = 3;
    const long long scmc_internal_g_idy = 0;
    const long long scmc_internal_g_ylen = 1;

    const long long XLEN = 64, YLEN = 3, ZLEN = 3;
    const int ovlp = 1;
    const long long xblock = XLEN + 2 * ovlp;
    const long long yblock = YLEN + 2 * ovlp;
    const long long zblock = ZLEN + 2 * ovlp;

    const long long y_cpu_core = 1;
    const long long numvec = 3;

    const double a = 1.23;
    
    const size_t total_size = num_ele * xblock * yblock * zblock * numvec;
    double *h_Fy = (double*)malloc(total_size * sizeof(double));
    double *h_Fx = (double*)malloc(total_size * sizeof(double));
    double *h_Fd = (double*)malloc(total_size * sizeof(double));
    for (int i = 0; i < total_size; i++)
    {
        h_Fy[i] = i + 0.1;
        h_Fx[i] = i + 0.2;
    }

    double *d_Fx, *d_Fy;
    mapsMalloc((void**)&d_Fx, total_size * sizeof(double));
    mapsMalloc((void**)&d_Fy, total_size * sizeof(double));
    mapsMemcpy(d_Fx, h_Fx, total_size * sizeof(double), mapsMemcpyHostToDevice);
    mapsMemcpy(d_Fy, h_Fy, total_size * sizeof(double), mapsMemcpyHostToDevice);

    c_blas_axpy_scmc_kernel(h_Fy, h_Fx, a, y_cpu_core, numvec, 
                            XLEN, YLEN, ZLEN, ovlp, xblock, yblock, 
                            zblock, num_ele, scmc_internal_g_idy, scmc_internal_g_ylen);

    // int grid_size = 1;
    // int block_size = 1;
    // int grid_size = ZLEN;
    // int block_size = YLEN;
    // int grid_size = 1;
    // int block_size = YLEN * ZLEN;
    int grid_size = YLEN * ZLEN;
    int block_size = 1;
    mapu_blas_axpy<<<grid_size, block_size>>>((__DDR double*)d_Fy, (__DDR double*)d_Fx, a, y_cpu_core, numvec, 
                            XLEN, YLEN, ZLEN, ovlp, xblock, yblock, 
                            zblock, num_ele);    
    
    mapsMemcpy(h_Fd, d_Fy, total_size * sizeof(double), mapsMemcpyDeviceToHost);
    
    bool pass = true;
    for (int i = 0; i < total_size; i++)
    {
        if (fabs(h_Fy[i] - h_Fd[i]) > 1.e-14)
        {
            printf("h_Fy[%d]: %.14f \nh_Fd[%d]: %.14f\n\n", i, h_Fy[i], i, h_Fd[i]); 
            pass = false;
        }       
    }
    printf("total_size: %zu\n", total_size);
    if (pass)
    {
        printf("==============axpy PASS!==============\n");
    }
    
    c_blas_yiszero_synced_scmc_kernel(h_Fy, y_cpu_core, numvec, 
                            XLEN, YLEN, ZLEN, ovlp, xblock, yblock, 
                            zblock, num_ele, scmc_internal_g_idy, scmc_internal_g_ylen);
    //mapu_blas_yiszero_synced<<<grid_size, block_size>>>((__DDR double*)d_Fy, y_cpu_core, numvec, 
    //                        XLEN, YLEN, ZLEN, ovlp, xblock, yblock, 
    //                        zblock, num_ele); 
    mapsMemset((void *)d_Fy, 0, total_size * sizeof(double));   
    mapsMemcpy(h_Fd, d_Fy, total_size * sizeof(double), mapsMemcpyDeviceToHost);

    pass = true;
    for (int i = 0; i < total_size; i++)
    {
        if (h_Fy[i] != 0 || h_Fd[i] != 0)
        {
            printf("h_Fy[%d]: %.16f \nh_Fd[%d]: %.16f\n\n", i, h_Fy[i], i, h_Fd[i]);
            pass = false;
        }        
    }
    if (pass)
    {
        printf("==============zero PASS!==============\n");
    }

    mapsFree(d_Fx);
    mapsFree(d_Fy);
    free(h_Fd);
    free(h_Fx);
    free(h_Fy);
    return 0;
}
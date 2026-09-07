#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "local_header.h"
#include "mapu_pscmc.h"
#include "miniblas.kernel_runtime.h"
#include "miniblas.kernel.inc"

void printy(mapu_pscmc_mem* y, char* funcName)
{
    return;
    mapsMemcpy(y->h_data, y->d_data, y->len * y->type_len, mapsMemcpyDeviceToHost);
    double *hy = (double*)(y->h_data);
    for (MAPU_LONG j = 0; j < y->len; j++)
    {
        printf("%s y[%lld]: %.16f\n", funcName, j, hy[j]);
    }

    static int times = 0;
    ++times;
    char fname[64];
    snprintf(fname, 64, "%s_%d", funcName, times);
    FILE *fp = fopen(fname, "wb");
    fwrite(y->h_data, y->type_len, y->len, fp);
    fclose(fp);
}

void mapu_blas_axpy_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x)
{
    char* dx = ((mapu_pscmc_mem*)(x->main_data))->d_data;
    char* dy = ((mapu_pscmc_mem*)(y->main_data))->d_data;
    mapu_blas_axpy<<<y->numvec, 1>>>((__DDR double *)dy, (__DDR double *)dx, a, y->numvec, y->numvec, y->xlen, y->ylen, y->zlen, y->ovlp, y->xblock, y->yblock, y->zblock, y->num_ele);
    printy((mapu_pscmc_mem*)(y->main_data), "axpy");
}

void mapu_blas_yisax_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x)
{
    char* dx = ((mapu_pscmc_mem*)(x->main_data))->d_data;
    char* dy = ((mapu_pscmc_mem*)(y->main_data))->d_data;
    mapu_blas_yisax<<<y->numvec, 1>>>((__DDR double *)dy, (__DDR double *)dx, a, y->numvec, y->numvec, y->xlen, y->ylen, y->zlen, y->ovlp, y->xblock, y->yblock, y->zblock, y->num_ele);
    printy((mapu_pscmc_mem*)(y->main_data), "yisax");
}

void mapu_blas_yisax_enlarge_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y, double a, Field3D_Seq *x)
{
    char* dx = ((mapu_pscmc_mem*)(x->main_data))->d_data;
    char* dy = ((mapu_pscmc_mem*)(y->main_data))->d_data;
    mapu_blas_yisax_enlarge<<<y->numvec, 1>>>((__DDR double *)dy, (__DDR double *)dx, a, y->numvec, y->numvec, y->xlen, y->ylen, y->zlen, y->ovlp, y->xblock, y->yblock, y->zblock, y->num_ele);
    printy((mapu_pscmc_mem*)(y->main_data), "yisax_enlarge");
}

void mapu_blas_yiszero_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y)
{
    char* dy = ((mapu_pscmc_mem*)(y->main_data))->d_data;
    mapu_blas_yiszero<<<y->numvec, 1>>>((__DDR double *)dy, y->numvec, y->numvec, y->xlen, y->ylen, y->zlen, y->ovlp, y->xblock, y->yblock, y->zblock, y->num_ele);
    printy((mapu_pscmc_mem*)(y->main_data), "yiszero");
}

void mapu_blas_yiszero_synced_Field3D_Seq(Field3D_Seq *pthis, Field3D_Seq *y)
{
    void* dy = (void*)(((mapu_pscmc_mem*)(y->main_data))->d_data);
    mapsMemset(dy, 0, y->xblock * y->yblock * y->zblock * y->num_ele * y->numvec * sizeof(double));
    printy((mapu_pscmc_mem*)(y->main_data), "yiszero_synced");
}
#include "init.h"
#include "basic.h"
#include <scale.h>
#include <maps_runtime.h>

#ifdef __cplusplus
extern "C"{
#endif

#include "init.h"
void init_seq(Field3D_Seq* x_ptr, Field3D_Seq* y_ptr, int rank, long long* len, int ovlp, int elenum, int vecnum)
{
    const size_t size = sizeof(mapu_pscmc_env);
    x_ptr->pe = malloc(size);
    y_ptr->pe = malloc(size);
    mapsSetDevice(rank);
    ((mapu_pscmc_env* )(x_ptr->pe))->device_id = rank;
    ((mapu_pscmc_env* )(y_ptr->pe))->device_id = rank;

    x_ptr->xlen = len[0];
    y_ptr->xlen = len[0];
    x_ptr->ylen = len[1];
    y_ptr->ylen = len[1];
    x_ptr->zlen = len[2];
    y_ptr->zlen = len[2];  

    x_ptr->ovlp = ovlp;
    y_ptr->ovlp = ovlp;

    long xblock = len[0] + 2 * ovlp;
    long yblock = len[1] + 2 * ovlp;
    long zblock = len[2] + 2 * ovlp;

    x_ptr->xblock = xblock;
    y_ptr->xblock = xblock;
    x_ptr->yblock = yblock;
    y_ptr->yblock = yblock;
    x_ptr->zblock = zblock;
    y_ptr->zblock = zblock;

    x_ptr->num_ele = elenum;
    y_ptr->num_ele = elenum;

    x_ptr->numvec = vecnum;
    y_ptr->numvec = vecnum;      

    const size_t size_mpm = sizeof(mapu_pscmc_mem);
    x_ptr->main_data = (void*)malloc(size_mpm);
    y_ptr->main_data = (void*)malloc(size_mpm);

    mapu_pscmc_mem* xmdata = (mapu_pscmc_mem*)(x_ptr->main_data);
    mapu_pscmc_mem* ymdata = (mapu_pscmc_mem*)(y_ptr->main_data);
    const size_t total_size = elenum * xblock * yblock * zblock * vecnum;
    const size_t total_size_byte = total_size * sizeof(double);
    xmdata->len = total_size;
    ymdata->len = total_size;
    xmdata->type_len = sizeof(double);
    ymdata->type_len = sizeof(double);
    xmdata->pe = (mapu_pscmc_env* )(x_ptr->pe);
    ymdata->pe = (mapu_pscmc_env* )(y_ptr->pe);

    xmdata->h_data = (char*)malloc(total_size_byte);
    ymdata->h_data = (char*)malloc(total_size_byte);
    double *h_Fy = (double*)(ymdata->h_data);
    double *h_Fx = (double*)(xmdata->h_data);

    for (int j = 0; j < total_size; j++)
    {
        h_Fx[j] =  1.1 * j;
        h_Fy[j] = -0.1 * j;
    }
    void** d_Fx = (void**)&(xmdata->d_data); 
    void** d_Fy = (void**)&(ymdata->d_data);

    mapsMalloc(d_Fx, total_size_byte);
    mapsMalloc(d_Fy, total_size_byte);

    mapsMemcpy(*d_Fx, h_Fx, total_size_byte, mapsMemcpyHostToDevice);
    mapsMemcpy(*d_Fy, h_Fy, total_size_byte, mapsMemcpyHostToDevice);
}

void reinit_seq(Field3D_Seq* x_ptr, Field3D_Seq* y_ptr)
{
    mapu_pscmc_mem* xmdata = (mapu_pscmc_mem*)(x_ptr->main_data);
    mapu_pscmc_mem* ymdata = (mapu_pscmc_mem*)(y_ptr->main_data);
    double *h_Fx = (double*)(xmdata->h_data);
    double *h_Fy = (double*)(ymdata->h_data);
    for (int j = 0; j < xmdata->len; j++)
    {
        h_Fx[j] = j * 1.0;
        h_Fy[j] = 0.0;
    }
    void* d_Fx = (void*)(xmdata->d_data);
    void* d_Fy = (void*)(ymdata->d_data);
    mapsMemcpy(d_Fx, h_Fx, xmdata->len * xmdata->type_len, mapsMemcpyHostToDevice);
    mapsMemcpy(d_Fy, h_Fy, ymdata->len * ymdata->type_len, mapsMemcpyHostToDevice);
}

void reinity_seq(Field3D_Seq* y_ptr)
{
    mapu_pscmc_mem* ymdata = (mapu_pscmc_mem*)(y_ptr->main_data);
    double *h_Fy = (double*)(ymdata->h_data);
    for (int j = 0; j < ymdata->len; j++)
    {
        h_Fy[j] = 1.0 * j;
    }
    void* d_Fy = (void*)(ymdata->d_data);
    mapsMemcpy(d_Fy, h_Fy, ymdata->len * ymdata->type_len, mapsMemcpyHostToDevice);
}

void reinit_enlargey_seq(Field3D_Seq* x_ptr, Field3D_Seq* y_ptr)
{
    mapu_pscmc_mem* xmdata = (mapu_pscmc_mem*)(x_ptr->main_data);
    double *h_Fx = (double*)(xmdata->h_data);
    for (int j = 0; j < xmdata->len; j++)
    {
        h_Fx[j] = j * 1.0;
    }
    void* d_Fx = (void*)(xmdata->d_data);
    mapsMemcpy(d_Fx, h_Fx, xmdata->len * xmdata->type_len, mapsMemcpyHostToDevice);
    
    mapu_pscmc_mem* ymdata = (mapu_pscmc_mem*)(y_ptr->main_data);
    mapsFree(ymdata->d_data);
    mapsFreeHost(ymdata->h_data);
    long x = y_ptr->xlen == 1 ? 1 : 2 * y_ptr->xlen;
    long y = y_ptr->ylen == 1 ? 1 : 2 * y_ptr->ylen;
    long z = y_ptr->zlen == 1 ? 1 : 2 * y_ptr->zlen;
    ymdata->len = (x + 2 * y_ptr->ovlp) * (y + 2 * y_ptr->ovlp) * (z + 2 * y_ptr->ovlp) * y_ptr->num_ele * y_ptr->numvec;
    long total_size_byte = ymdata->len * ymdata->type_len;
    
    void** d_Fy = (void**)&(ymdata->d_data);    
    mapsMalloc(d_Fy, total_size_byte);
    ymdata->h_data = (char*)malloc(total_size_byte);
    double* h_Fy = (double*)(ymdata->h_data);
    for (int j = 0; j < ymdata->len; j++)
    {
        h_Fy[j] = 0.0;
    }
    mapsMemcpy(*d_Fy, h_Fy, total_size_byte, mapsMemcpyHostToDevice);
}
#ifdef __cplusplus
}
#endif
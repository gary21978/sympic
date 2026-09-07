#include "miniblas.kernel_runtime.h"
#include "miniblas.kernel.h"

int dump_kernel_variables = 0;
long _pscmc_mapu_global_dump_kernel_variables = 1;
long _pscmc_mapu_global_dump_times = 0;
#ifdef __cplusplus
extern "C" {
#endif
int mapu_blas_axpy_scmc_set_parameter_y(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_x(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->x = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_xblock(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->xblock = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_yblock(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->yblock = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_zblock(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->zblock = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_num_ele(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->num_ele = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_XLEN(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->XLEN = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_YLEN(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->YLEN = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_ZLEN(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ZLEN = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_ovlp(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ovlp = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_a(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->a = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_y_cpu_core(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y_cpu_core = pm);
    return 0;
}
int mapu_blas_axpy_scmc_set_parameter_numvec(mapu_blas_axpy_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->numvec = pm);
    return 0;
}
int mapu_blas_axpy_exec(mapu_blas_axpy_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
    //return 0;
    mapsSetDevice((kerstr->pe)->device_id);
    printf("dump_kernel_variables: %d\n", dump_kernel_variables);
    printf("_pscmc_mapu_global_dump_kernel_variables: %d\n", _pscmc_mapu_global_dump_kernel_variables);
    //return 0;
    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                //return 0;
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_y_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->x)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->x);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_x_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->x)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->x, NULL), write_len, (kerstr->x)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->a)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->a);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_a_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->a)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->a, NULL), write_len, (kerstr->a)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_y_cpu_core_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_numvec_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_XLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_YLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_ZLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_ovlp_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_xblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_yblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_zblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_num_ele_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }

    if ((scmc_internal_g_ylen < 65536))
    {
        {
            printf("~~~~~~~~~~~~~~~mapu_blas_axpy~~~~~~~~~~~~~~~\n");
            //return 0;
            printf("kerstr: %p\n", kerstr);
            printf("kerstr->y: %p\n", kerstr->y);
            printf("kerstr->x: %p\n", kerstr->x);
            printf("kerstr->y->d_data: %p\n", kerstr->y->d_data);
            printf("kerstr->x->d_data: %p\n", kerstr->x->d_data);
            printf("(((double *)kerstr->a->h_data))[0]: %f\n", (((double *)kerstr->a->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->numvec->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->numvec->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->XLEN->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->XLEN->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->YLEN->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->YLEN->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->ZLEN->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->ZLEN->h_data))[0]);
            printf("(((int *)kerstr->ovlp->h_data))[0]: %d\n", (((int *)kerstr->ovlp->h_data))[0]);
            printf("(((int *)kerstr->num_ele->h_data))[0]: %d\n", (((int *)kerstr->num_ele->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->xblock->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->xblock->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->yblock->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->yblock->h_data))[0]);
            printf("(((MAPU_LONG *)kerstr->zblock->h_data))[0]: %d\n", (((MAPU_LONG *)kerstr->zblock->h_data))[0]);

            //return 0;
            mapu_blas_axpy<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(
                ((__DDR double *)({
                uint64_t  __d_data_address_tmp2 ;
                mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
                __d_data_address_tmp2; })), 
                ((__DDR double *)({
                uint64_t  __d_data_address_tmp2 ;
                mapsMemobjGetPhysicalAddress ( kerstr->x->d_data , & (__d_data_address_tmp2) );
                __d_data_address_tmp2; })), 
                (((double *)kerstr->a->h_data))[0], 
                (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], 
                (((MAPU_LONG *)kerstr->numvec->h_data))[0], 
                (((MAPU_LONG *)kerstr->XLEN->h_data))[0], 
                (((MAPU_LONG *)kerstr->YLEN->h_data))[0], 
                (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], 
                (((int *)kerstr->ovlp->h_data))[0], 
                (((MAPU_LONG *)kerstr->xblock->h_data))[0], 
                (((MAPU_LONG *)kerstr->yblock->h_data))[0], 
                (((MAPU_LONG *)kerstr->zblock->h_data))[0], 
                (((int *)kerstr->num_ele->h_data))[0]);
        }
    }
    else
    {
        {
            dim3 multiylen = 1;
            (multiylen.x = 64);
            (multiylen.y = (scmc_internal_g_ylen / 64));
            int rest = (scmc_internal_g_ylen % 64);

            if ((rest != 0))
            {
                {
                    fprintf(stderr, "Warning: if __ylen>=65536 then __ylen must be divisible by 64, __ylen=%d\n", scmc_internal_g_ylen);
                }
            }
            else
            {
                {
                    0;
                }
            }
            mapu_blas_axpy<<<multiylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->x->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((double *)kerstr->a->h_data))[0], (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_y_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
                double *yy = (double*)kerstr->y->h_data;
                for (MAPU_LONG j = 0; j < write_len; j++)
                {
                    printf("axpy y[%lld]: %.16f\n", j, yy[j]);
                }
            }
            {

                if (((kerstr->x)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->x);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_x_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->x)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->x, NULL), write_len, (kerstr->x)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->a)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->a);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_a_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->a)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->a, NULL), write_len, (kerstr->a)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_y_cpu_core_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_numvec_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_XLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_YLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_ZLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_ovlp_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_xblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_yblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_zblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_axpy_num_ele_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }
    (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
    return 0;
}

int mapu_blas_yisax_exec(mapu_blas_yisax_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
    mapsSetDevice((kerstr->pe)->device_id);

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_y_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->x)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->x);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_x_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->x)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->x, NULL), write_len, (kerstr->x)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->a)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->a);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_a_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->a)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->a, NULL), write_len, (kerstr->a)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_y_cpu_core_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_numvec_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_XLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_YLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_ZLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_ovlp_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_xblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_yblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_zblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_num_ele_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }

    if ((scmc_internal_g_ylen < 65536))
    {
        {
            mapu_blas_yisax<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->x->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((double *)kerstr->a->h_data))[0], (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }
    else
    {
        {
            dim3 multiylen = 1;
            (multiylen.x = 64);
            (multiylen.y = (scmc_internal_g_ylen / 64));
            int rest = (scmc_internal_g_ylen % 64);

            if ((rest != 0))
            {
                {
                    fprintf(stderr, "Warning: if __ylen>=65536 then __ylen must be divisible by 64, __ylen=%d\n", scmc_internal_g_ylen);
                }
            }
            else
            {
                {
                    0;
                }
            }
            mapu_blas_yisax<<<multiylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->x->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((double *)kerstr->a->h_data))[0], (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_y_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
                double *yy = (double*)kerstr->y->h_data;
                for (MAPU_LONG j = 0; j < write_len; j++)
                {
                    printf("yisax y[%lld]: %.16f\n", j, yy[j]);
                }
            }
            {

                if (((kerstr->x)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->x);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_x_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->x)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->x, NULL), write_len, (kerstr->x)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->a)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->a);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_a_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->a)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->a, NULL), write_len, (kerstr->a)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_y_cpu_core_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_numvec_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_XLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_YLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_ZLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_ovlp_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_xblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_yblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_zblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_num_ele_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }
    (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_y(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_x(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->x = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_a(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->a = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_y_cpu_core(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y_cpu_core = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_numvec(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->numvec = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_XLEN(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->XLEN = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_YLEN(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->YLEN = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_ZLEN(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ZLEN = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_ovlp(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ovlp = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_xblock(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->xblock = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_yblock(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->yblock = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_zblock(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->zblock = pm);
    return 0;
}
int mapu_blas_yisax_scmc_set_parameter_num_ele(mapu_blas_yisax_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->num_ele = pm);
    return 0;
}

int mapu_blas_yisax_enlarge_exec(mapu_blas_yisax_enlarge_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
    mapsSetDevice((kerstr->pe)->device_id);

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_y_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->x)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->x);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_x_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->x)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->x, NULL), write_len, (kerstr->x)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->a)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->a);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_a_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->a)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->a, NULL), write_len, (kerstr->a)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_y_cpu_core_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_numvec_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_XLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_YLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_ZLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_ovlp_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_xblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_yblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_zblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_num_ele_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }

    if ((scmc_internal_g_ylen < 65536))
    {
        {
            mapu_blas_yisax_enlarge<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->x->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((double *)kerstr->a->h_data))[0], (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }
    else
    {
        {
            dim3 multiylen = 1;
            (multiylen.x = 64);
            (multiylen.y = (scmc_internal_g_ylen / 64));
            int rest = (scmc_internal_g_ylen % 64);

            if ((rest != 0))
            {
                {
                    fprintf(stderr, "Warning: if __ylen>=65536 then __ylen must be divisible by 64, __ylen=%d\n", scmc_internal_g_ylen);
                }
            }
            else
            {
                {
                    0;
                }
            }
            mapu_blas_yisax_enlarge<<<multiylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->x->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((double *)kerstr->a->h_data))[0], (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_y_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
                double *yy = (double*)kerstr->y->h_data;
                for (MAPU_LONG j = 0; j < write_len; j++)
                {
                    printf("yisax_enlarge y[%lld]: %.16f\n", j, yy[j]);
                }
            }
            {

                if (((kerstr->x)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->x);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_x_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->x)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->x, NULL), write_len, (kerstr->x)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->a)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->a);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_a_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->a)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->a, NULL), write_len, (kerstr->a)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_y_cpu_core_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_numvec_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_XLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_YLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_ZLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_ovlp_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_xblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_yblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_zblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yisax_enlarge_num_ele_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }
    (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_y(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_x(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->x = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_a(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->a = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_y_cpu_core(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y_cpu_core = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_numvec(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->numvec = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_XLEN(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->XLEN = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_YLEN(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->YLEN = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_ZLEN(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ZLEN = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_ovlp(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ovlp = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_xblock(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->xblock = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_yblock(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->yblock = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_zblock(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->zblock = pm);
    return 0;
}
int mapu_blas_yisax_enlarge_scmc_set_parameter_num_ele(mapu_blas_yisax_enlarge_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->num_ele = pm);
    return 0;
}

int mapu_blas_yiszero_synced_exec(mapu_blas_yiszero_synced_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
    mapsSetDevice((kerstr->pe)->device_id);

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_y_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_y_cpu_core_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_numvec_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_XLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_YLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_ZLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_ovlp_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_xblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_yblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_zblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_num_ele_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }

    if ((scmc_internal_g_ylen < 65536))
    {
        {
            mapu_blas_yiszero_synced<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }
    else
    {
        {
            dim3 multiylen = 1;
            (multiylen.x = 64);
            (multiylen.y = (scmc_internal_g_ylen / 64));
            int rest = (scmc_internal_g_ylen % 64);

            if ((rest != 0))
            {
                {
                    fprintf(stderr, "Warning: if __ylen>=65536 then __ylen must be divisible by 64, __ylen=%d\n", scmc_internal_g_ylen);
                }
            }
            else
            {
                {
                    0;
                }
            }
            mapu_blas_yiszero_synced<<<multiylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_y_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
                double *yy = (double*)kerstr->y->h_data;
                for (MAPU_LONG j = 0; j < write_len; j++)
                {
                    printf("yiszero_synced y[%lld]: %.16f\n", j, yy[j]);
                }
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_y_cpu_core_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_numvec_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_XLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_YLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_ZLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_ovlp_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_xblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_yblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_zblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_synced_num_ele_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }
    (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_y(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_y_cpu_core(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y_cpu_core = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_numvec(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->numvec = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_XLEN(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->XLEN = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_YLEN(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->YLEN = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_ZLEN(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ZLEN = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_ovlp(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ovlp = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_xblock(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->xblock = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_yblock(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->yblock = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_zblock(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->zblock = pm);
    return 0;
}
int mapu_blas_yiszero_synced_scmc_set_parameter_num_ele(mapu_blas_yiszero_synced_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->num_ele = pm);
    return 0;
}

int mapu_blas_yiszero_exec(mapu_blas_yiszero_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
    mapsSetDevice((kerstr->pe)->device_id);

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_y_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_y_cpu_core_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_numvec_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_XLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_YLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_ZLEN_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_ovlp_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_xblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_yblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_zblock_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_num_ele_before_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }

    if ((scmc_internal_g_ylen < 65536))
    {
        {
            mapu_blas_yiszero<<<scmc_internal_g_ylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }
    else
    {
        {
            dim3 multiylen = 1;
            (multiylen.x = 64);
            (multiylen.y = (scmc_internal_g_ylen / 64));
            int rest = (scmc_internal_g_ylen % 64);

            if ((rest != 0))
            {
                {
                    fprintf(stderr, "Warning: if __ylen>=65536 then __ylen must be divisible by 64, __ylen=%d\n", scmc_internal_g_ylen);
                }
            }
            else
            {
                {
                    0;
                }
            }
            mapu_blas_yiszero<<<multiylen, scmc_internal_g_xlen>>>(((__DDR double *)({
    uint64_t  __d_data_address_tmp2 ;
mapsMemobjGetPhysicalAddress ( kerstr->y->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0]);
        }
    }

    if ((dump_kernel_variables || _pscmc_mapu_global_dump_kernel_variables))
    {
        {
            {

                if (((kerstr->y)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_y_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y, NULL), write_len, (kerstr->y)->type_len, fp);
                fclose(fp);
                double *yy = (double*)kerstr->y->h_data;
                for (MAPU_LONG j = 0; j < write_len; j++)
                {
                    printf("yiszero y[%lld]: %.16f\n", j, yy[j]);
                }
            }
            {

                if (((kerstr->y_cpu_core)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->y_cpu_core);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_y_cpu_core_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->y_cpu_core)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->y_cpu_core, NULL), write_len, (kerstr->y_cpu_core)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->numvec)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->numvec);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_numvec_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->numvec)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->numvec, NULL), write_len, (kerstr->numvec)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->XLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->XLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_XLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->XLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->XLEN, NULL), write_len, (kerstr->XLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->YLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->YLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_YLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->YLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->YLEN, NULL), write_len, (kerstr->YLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ZLEN)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ZLEN);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_ZLEN_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ZLEN)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ZLEN, NULL), write_len, (kerstr->ZLEN)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->ovlp)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->ovlp);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_ovlp_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->ovlp)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->ovlp, NULL), write_len, (kerstr->ovlp)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->xblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->xblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_xblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->xblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->xblock, NULL), write_len, (kerstr->xblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->yblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->yblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_yblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->yblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->yblock, NULL), write_len, (kerstr->yblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->zblock)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->zblock);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_zblock_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->zblock)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->zblock, NULL), write_len, (kerstr->zblock)->type_len, fp);
                fclose(fp);
            }
            {

                if (((kerstr->num_ele)->len > 0))
                {
                    {
                        mapu_pscmc_mem_sync_d2h(kerstr->num_ele);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                char fname[256];
                snprintf(fname, 256, "Debug_%d_mapu_blas_yiszero_num_ele_after_exec", _pscmc_mapu_global_dump_times);
                FILE *fp = fopen(fname, "wb");
                size_t write_len = (kerstr->num_ele)->len;

                if ((write_len <= 0))
                {
                    {
                        (write_len = 1);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
                fwrite(mapu_pscmc_get_h_data(kerstr->num_ele, NULL), write_len, (kerstr->num_ele)->type_len, fp);
                fclose(fp);
            }
        }
    }
    else
    {
        {
            0;
        }
    }
    (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_y(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_y_cpu_core(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->y_cpu_core = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_numvec(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->numvec = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_XLEN(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->XLEN = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_YLEN(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->YLEN = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_ZLEN(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ZLEN = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_ovlp(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->ovlp = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_xblock(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->xblock = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_yblock(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->yblock = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_zblock(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->zblock = pm);
    return 0;
}
int mapu_blas_yiszero_scmc_set_parameter_num_ele(mapu_blas_yiszero_struct *kerstr, mapu_pscmc_mem *pm)
{
    mapsSetDevice((kerstr->pe)->device_id);
    (kerstr->num_ele = pm);
    return 0;
}

#ifdef __cplusplus
} /* extern "C" */
#endif

#include <scale.h>
#include <maps_runtime.h>
#include <scale/barrier>
#include "cooperative_groups.h" 
#include "miniblas.kernel.h"

__global__ void mapu_blas_axpy(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&__pscmc_mapu_internal_barrier__, 1);
    MAPU_LONG blk_all_len = xb * yb * zb * num_ele;
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    const size_t data_size = sizeof(double) * blk_all_len;
    y = y + tid * blk_all_len;
    x = x + tid * blk_all_len;
    if (blk_all_len <= 3072)
    {        
        __mem0__ double fast_y[3072];
        __mem0__ double fast_x[3072];
        memcpy_async(__pscmc_mapu_internal_block__, (unsigned *)fast_y, (__DDR unsigned *)y, data_size, __pscmc_mapu_internal_barrier__);
        memcpy_async(__pscmc_mapu_internal_block__, (unsigned *)fast_x, (__DDR unsigned *)x, data_size, __pscmc_mapu_internal_barrier__);
        __pscmc_mapu_internal_barrier__.arrive_and_wait();

        for (MAPU_LONG k = 0; k < ZLEN; k++)
        {
            for (MAPU_LONG j = 0; j < YLEN; j++)
            {   
                MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (MAPU_LONG i = offset; i < offset + num_ele * XLEN; i++)
                {
                    fast_y[i] = fast_y[i] + a * fast_x[i];
                }   
            }
        }

        memcpy_async(__pscmc_mapu_internal_block__, (__DDR unsigned *)y, (unsigned *)fast_y, data_size, __pscmc_mapu_internal_barrier__);
        __pscmc_mapu_internal_barrier__.arrive_and_wait();
    }
    else
    {
        for (MAPU_LONG k = 0; k < ZLEN; k++)
        {
            for (MAPU_LONG j = 0; j < YLEN; j++)
            {
                MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (MAPU_LONG i = offset; i < offset + num_ele * XLEN; i++)
                {
                    y[i] = y[i] + a * x[i];
                } 
            }
        }
    }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****AXPY**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yisax(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&__pscmc_mapu_internal_barrier__, 1);
    MAPU_LONG blk_all_len = xb * yb * zb * num_ele;
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    const size_t data_size = sizeof(double) * blk_all_len;
    y = y + tid * blk_all_len;
    x = x + tid * blk_all_len;
    if (blk_all_len <= 3072)
    {        
        __mem0__ double fast_y[3072];
        __mem0__ double fast_x[3072];
        memcpy_async(__pscmc_mapu_internal_block__, (unsigned *)fast_y, (__DDR unsigned *)y, data_size, __pscmc_mapu_internal_barrier__);
        memcpy_async(__pscmc_mapu_internal_block__, (unsigned *)fast_x, (__DDR unsigned *)x, data_size, __pscmc_mapu_internal_barrier__);
        __pscmc_mapu_internal_barrier__.arrive_and_wait();

        for (MAPU_LONG k = 0; k < ZLEN; k++)
        {
            for (MAPU_LONG j = 0; j < YLEN; j++)
            {   
                MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (MAPU_LONG i = offset; i < offset + num_ele * XLEN; i++)
                {
                    fast_y[i] = a * fast_x[i];
                }   
            }
        }

        memcpy_async(__pscmc_mapu_internal_block__, (__DDR unsigned *)y, (unsigned *)fast_y, data_size, __pscmc_mapu_internal_barrier__);
        __pscmc_mapu_internal_barrier__.arrive_and_wait();
    }
    else
    {
        for (MAPU_LONG k = 0; k < ZLEN; k++)
        {
            for (MAPU_LONG j = 0; j < YLEN; j++)
            {
                MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (MAPU_LONG i = offset; i < offset + num_ele * XLEN; i++)
                {
                    y[i] = a * x[i];
                } 
            }
        }
    }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISAX**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yisax_enlarge(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    MAPU_LONG xb_2x = 2 * ovlp + (XLEN == 1 ? 1 : XLEN * 2);
    MAPU_LONG yb_2x = 2 * ovlp + (YLEN == 1 ? 1 : YLEN * 2);
    MAPU_LONG zb_2x = 2 * ovlp + (ZLEN == 1 ? 1 : ZLEN * 2);
    int x2 = XLEN == 1 ? 1 : 2;
    int y2 = YLEN == 1 ? 1 : 2;
    int z2 = ZLEN == 1 ? 1 : 2;

    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    y = y + tid * xb_2x * yb_2x * zb_2x * num_ele;
    x = x + tid * xb * yb * zb * num_ele;

    for (MAPU_LONG k = 0; k < ZLEN; k++)
    {
        for (MAPU_LONG j = 0; j < YLEN; j++)
        {
            for (MAPU_LONG i = 0; i < XLEN; i++)
            {    
                MAPU_LONG x_index = num_ele * (i + ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (int e = 0; e < num_ele; e++)
                {
                    double xe = a * 0.125 * x[e + x_index];
                    for (int gz = 0; gz < z2; gz++)
                    {
                        for (int gy = 0; gy < y2; gy++)
                        {
                            for (int gx = 0; gx < x2; gx++)
                            {
                                y[e + num_ele * (ovlp + 2 * i + gx + xb_2x * (ovlp + 2 * j + gy + yb_2x * (ovlp + 2 * k + gz)))] = xe;
                            }
                        }
                    }
                }            
            }
        }
    }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISAX_ENLARGE**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yiszero_synced(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&__pscmc_mapu_internal_barrier__, 1);
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    MAPU_LONG blk_all_len = xb * yb * zb * num_ele;
    y = y + tid * blk_all_len;

    const int LOCAL_CACHE_LEN = 128;
    const size_t data_size = sizeof(double);

    __mem0__ double zeros[128];
    for ( int lg = 0; lg < LOCAL_CACHE_LEN; lg++)
    {
        zeros[lg] = 0;
    }
    __shared__ barrier_t put_sync_id;

    if (threadIdx.x == 0)
    {
        init(&put_sync_id, blockDim.x * blockDim.y * blockDim.z);
    }

    for (MAPU_LONG j = 0; j < blk_all_len; j = j + LOCAL_CACHE_LEN)
    {
        MAPU_LONG numcp = (j + LOCAL_CACHE_LEN) < blk_all_len ? LOCAL_CACHE_LEN : (blk_all_len - j);
        if (numcp)
        {
            memcpy_async(__pscmc_mapu_internal_block__, (__DDR unsigned *)(y + j), (unsigned *)zeros, (uint64_t)(numcp * data_size), put_sync_id);
        }
    }
    put_sync_id.arrive_and_wait();
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISZERO_SYNCED**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yiszero(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&__pscmc_mapu_internal_barrier__, 1);
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    MAPU_LONG blk_all_len = xb * yb * zb * num_ele;
    const size_t data_size = sizeof(double) * blk_all_len;
    y = y + tid * blk_all_len;

    if (blk_all_len <= 3072)
    {
        __mem0__ double fast_y[3072];
        memcpy_async(__pscmc_mapu_internal_block__, (unsigned *)fast_y, (__DDR unsigned *)y, data_size, __pscmc_mapu_internal_barrier__);
        __pscmc_mapu_internal_barrier__.arrive_and_wait();

        for (MAPU_LONG k = 0; k < ZLEN; k++)
        {
            for (MAPU_LONG j = 0; j < YLEN; j++)
            {
                MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (MAPU_LONG i = offset; i < offset + num_ele * XLEN; i++)
                {
                    fast_y[i] = 0;
                }   
            }
        }
    
        memcpy_async(__pscmc_mapu_internal_block__, (__DDR unsigned *)y, (unsigned *)fast_y, data_size, __pscmc_mapu_internal_barrier__);
        __pscmc_mapu_internal_barrier__.arrive_and_wait();
    }
    else
    {
        for (MAPU_LONG k = 0; k < ZLEN; k++)
        {
            for (MAPU_LONG j = 0; j < YLEN; j++)
            {
                MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
                for (MAPU_LONG i = offset; i < offset + num_ele * XLEN; i++)
                {
                    y[i] = 0;
                } 
            }
        }
    }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISZERO**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

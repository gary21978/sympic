
#include <scale.h>
#include <maps_runtime.h>
#include <scale/barrier>
#include "cooperative_groups.h" 
#include "miniblas.kernel.h"

__global__ void mapu_blas_axpy(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele)
{
#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    // __mem1__ int __mapu_dma_index;
    // __mapu_dma_index = 0;
    // const MAPU_LONG pscmc_compute_unit_id = 0;
    // const MAPU_LONG pscmc_num_compute_units = 1;
    const MAPU_LONG __idx = 0;
    // const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    const MAPU_LONG __xlen = 1;
    // const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
    // const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
    // __mem1__ MAPU_LONG local_ynum;
    // local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    // __mem1__ MAPU_LONG local_ymin;
    // local_ymin = (__idy * local_ynum);
    // __mem1__ MAPU_LONG local_ymax;
    // local_ymax = ((1 + __idy) * local_ynum);
    __mem1__ MAPU_LONG xb;
    xb = xblock;
    __mem1__ MAPU_LONG yb;
    yb = yblock;
    __mem1__ MAPU_LONG zb;
    zb = zblock;
    __mem1__ MAPU_LONG blk_all_len;
    blk_all_len = (xb * (yb * (zb * num_ele)));
// printf("i        x        y\n");
// for (int i = 0; i < blk_all_len; i++)
// {
//     printf("%-9d%-9.4f%-9.4f\n" ,i ,x[i], y[i]);
// }
// return;
    // if ((local_ymax >= numvec))
    // {
    //     {
    //         (local_ymax = numvec);
    //     }
    // }
    // else
    // {
    //     {
    //         0;
    //     }
    // }
    // __mem0__ double reduce_tmp_arr[IDX_OPT_MAX];
    // __mem1__ double reduce_tmp;
    // reduce_tmp = 0.00000000000000000e+00;
    // {
        __mem1__ MAPU_LONG i;
        i = blockIdx.x * blockDim.x + threadIdx.x;
        // for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        // {

            if ((blk_all_len <= 3072))
            {
                {
                    __mem0__ double fast_y[3072];
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof(((y + (i * blk_all_len)))[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)fast_y), ((__DDR unsigned *)(y + (i * blk_all_len))), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                    __mem0__ double fast_x[3072];
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof(((x + (i * blk_all_len)))[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)fast_x), ((__DDR unsigned *)(x + (i * blk_all_len))), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                    {
                        __mem1__ MAPU_LONG xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            {
                                                __mem1__ MAPU_LONG realidx;
                                                for ((realidx = 0); (realidx < (num_ele * XLEN)); (realidx = (realidx + 1)))
                                                {
                                                    ((fast_y)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)] = ((fast_y)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)] + (a * (fast_x)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)])));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof((fast_y)[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((__DDR unsigned *)(y + (i * blk_all_len))), ((unsigned *)fast_y), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                }
            }
            else
            {
                {
                    {
                        __mem1__ MAPU_LONG xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            __mem1__ MAPU_LONG blk_offset_t1;
                                            blk_offset_t1 = (blk_all_len * i);
                                            __mem1__ MAPU_LONG blk_offset;
                                            blk_offset = ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));
                                            {
                                                __mem1__ MAPU_LONG g;
                                                g = 0;
                                                for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele)); g++)
                                                {
                                                    __mem1__ MAPU_LONG realidx;
                                                    realidx = (__idx + (g * __xlen));
                                                    ((y)[(blk_offset + realidx)] = ((y)[(blk_offset + realidx)] + (a * (x)[(blk_offset + realidx)])));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        // }
    // }

    // for (MAPU_LONG j = i * blk_all_len; j < (i+1) * blk_all_len; j++)
    // {
    //     printf("y[%lld]: %.16f\n", j, y[j]);
    // }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****AXPY**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yisax(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele)
{

#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    // __mem1__ int __mapu_dma_index;
    // __mapu_dma_index = 0;
    // const MAPU_LONG pscmc_compute_unit_id = 0;
    // const MAPU_LONG pscmc_num_compute_units = 1;
    const MAPU_LONG __idx = 0;
    // const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    const MAPU_LONG __xlen = 1;
    // const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
    // const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
    // __mem1__ MAPU_LONG local_ynum;
    // local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    // __mem1__ MAPU_LONG local_ymin;
    // local_ymin = (__idy * local_ynum);
    // __mem1__ MAPU_LONG local_ymax;
    // local_ymax = ((1 + __idy) * local_ynum);
    __mem1__ MAPU_LONG xb;
    xb = xblock;
    __mem1__ MAPU_LONG yb;
    yb = yblock;
    __mem1__ MAPU_LONG zb;
    zb = zblock;
    __mem1__ MAPU_LONG blk_all_len;
    blk_all_len = (xb * (yb * (zb * num_ele)));

    // if ((local_ymax >= numvec))
    // {
    //     {
    //         (local_ymax = numvec);
    //     }
    // }
    // else
    // {
    //     {
    //         0;
    //     }
    // }
    // __mem0__ double reduce_tmp_arr[IDX_OPT_MAX];
    // __mem1__ double reduce_tmp;
    // reduce_tmp = 0.00000000000000000e+00;
    // {
        __mem1__ MAPU_LONG i;
        i = blockIdx.x * blockDim.x + threadIdx.x;
        // for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        // {

            if ((blk_all_len <= 3072))
            {
                {
                    __mem0__ double fast_y[3072];
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof(((y + (i * blk_all_len)))[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)fast_y), ((__DDR unsigned *)(y + (i * blk_all_len))), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                    __mem0__ double fast_x[3072];
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof(((x + (i * blk_all_len)))[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)fast_x), ((__DDR unsigned *)(x + (i * blk_all_len))), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                    {
                        __mem1__ MAPU_LONG xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            {
                                                __mem1__ MAPU_LONG realidx;
                                                for ((realidx = 0); (realidx < (num_ele * XLEN)); (realidx = (realidx + 1)))
                                                {
                                                    ((fast_y)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)] = (a * (fast_x)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)]));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof((fast_y)[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((__DDR unsigned *)(y + (i * blk_all_len))), ((unsigned *)fast_y), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                }
            }
            else
            {
                {
                    {
                        __mem1__ MAPU_LONG xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            __mem1__ MAPU_LONG blk_offset_t1;
                                            blk_offset_t1 = (blk_all_len * i);
                                            __mem1__ MAPU_LONG blk_offset;
                                            blk_offset = ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));
                                            {
                                                __mem1__ MAPU_LONG g;
                                                g = 0;
                                                for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele)); g++)
                                                {
                                                    __mem1__ MAPU_LONG realidx;
                                                    realidx = (__idx + (g * __xlen));
                                                    ((y)[(blk_offset + realidx)] = (a * (x)[(blk_offset + realidx)]));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        // }
    // }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISAX**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yisax_enlarge(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele)
{

#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    // __mem1__ int __mapu_dma_index;
    // __mapu_dma_index = 0;
    // const MAPU_LONG pscmc_compute_unit_id = 0;
    // const MAPU_LONG pscmc_num_compute_units = 1;
    const MAPU_LONG __idx = 0;
    // const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    const MAPU_LONG __xlen = 1;
    // const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
    // const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
    // __mem1__ MAPU_LONG local_ynum;
    // local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    // __mem1__ MAPU_LONG local_ymin;
    // local_ymin = (__idy * local_ynum);
    // __mem1__ MAPU_LONG local_ymax;
    // local_ymax = ((1 + __idy) * local_ynum);
    __mem1__ MAPU_LONG xb;
    xb = xblock;
    __mem1__ MAPU_LONG yb;
    yb = yblock;
    __mem1__ MAPU_LONG zb;
    zb = zblock;
    __mem1__ MAPU_LONG blk_all_len;
    blk_all_len = (xb * (yb * (zb * num_ele)));
    __mem1__ MAPU_LONG xb_2x;
    xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (({ XLEN; })) : (({ (XLEN * 2); }))));
    __mem1__ MAPU_LONG yb_2x;
    yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (({ YLEN; })) : (({ (YLEN * 2); }))));
    __mem1__ MAPU_LONG zb_2x;
    zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (({ ZLEN; })) : (({ (ZLEN * 2); }))));
    __mem1__ MAPU_LONG blk_all_len_2x;
    blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));
    {
        __mem1__ MAPU_LONG i;
        i = blockIdx.x * blockDim.x + threadIdx.x;
        // for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        {
            {
                __mem1__ MAPU_LONG xyzz;
                for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                {
                    {
                        __mem1__ MAPU_LONG xyzy;
                        for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzx;
                                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG realidx;
                                        for ((realidx = 0); (realidx < num_ele); (realidx = (realidx + 1)))
                                        {
                                            {
                                                __mem1__ MAPU_LONG gz;
                                                for ((gz = 0); (gz < 2); (gz = (gz + 1)))
                                                {
                                                    {
                                                        __mem1__ MAPU_LONG gy;
                                                        for ((gy = 0); (gy < 2); (gy = (gy + 1)))
                                                        {
                                                            {
                                                                __mem1__ MAPU_LONG gx;
                                                                for ((gx = 0); (gx < 2); (gx = (gx + 1)))
                                                                {
                                                                    ((y)[((blk_all_len_2x * i) + (realidx + (num_ele * ((ovlp + ((2 * xyzx) + (((XLEN == 1)) ? (({ 0; })) : (({ gx; }))))) + (xb_2x * (((2 * xyzy) + (ovlp + (((YLEN == 1)) ? (({ 0; })) : (({ gy; }))))) + (yb_2x * ((2 * xyzz) + ((((ZLEN == 1)) ? (({ 0; })) : (({ gz; }))) + ovlp)))))))))] = (a * (1.25000000000000000e-01 * (x)[((blk_all_len * i) + (realidx + (num_ele * ((xyzx + ovlp) + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))))])));
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
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

__global__ void mapu_blas_yiszero_synced(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele)
{

#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    // __mem1__ int __mapu_dma_index;
    // __mapu_dma_index = 0;
    // const MAPU_LONG pscmc_compute_unit_id = 0;
    // const MAPU_LONG pscmc_num_compute_units = 1;
    const MAPU_LONG __idx = 0;
    // const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    const MAPU_LONG __xlen = 1;
    // const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
    // const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
    // __mem1__ MAPU_LONG local_ynum;
    // local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    const MAPU_LONG LOCAL_CACHE_LEN = 128;
    // __mem1__ MAPU_LONG local_ymin;
    // local_ymin = (__idy * local_ynum);
    // __mem1__ MAPU_LONG local_ymax;
    // local_ymax = ((1 + __idy) * local_ynum);
    __mem1__ MAPU_LONG xb;
    xb = xblock;
    __mem1__ MAPU_LONG yb;
    yb = yblock;
    __mem1__ MAPU_LONG zb;
    zb = zblock;
    __mem1__ MAPU_LONG blk_all_len;
    blk_all_len = (xb * (yb * (zb * num_ele)));

    // if ((local_ymax >= numvec))
    // {
    //     {
    //         (local_ymax = numvec);
    //     }
    // }
    // else
    // {
    //     {
    //         0;
    //     }
    // }
    __mem0__ double zeros[128];
    __mem1__ MAPU_LONG lg;
    lg = 0;
    for ((lg = 0); ((lg + __idx) < LOCAL_CACHE_LEN); (lg = (lg + __xlen)))
    {
        ((zeros)[(lg + __idx)] = 0);
    }
    __shared__ barrier_t put_sync_id;

    if ((threadIdx.x == 0))
    {
        {
            init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
    }
    else
    {
        {
            0;
        }
    }
    {
        __mem1__ MAPU_LONG i;
        i = blockIdx.x * blockDim.x + threadIdx.x;
        // for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        {
            __mem1__ MAPU_LONG blk_offset_t1;
            blk_offset_t1 = (blk_all_len * i);
            __mem1__ MAPU_LONG j;
            j = 0;
            for ((j = 0); (j < blk_all_len); (j = (j + LOCAL_CACHE_LEN)))
            {
                __mem1__ int numcp;
                numcp = ((((j + LOCAL_CACHE_LEN) < blk_all_len)) ? (({ LOCAL_CACHE_LEN; })) : (({ (blk_all_len - j); })));

                if ((numcp * 1))
                {
                    {
                        const size_t data_size = sizeof((zeros)[0]);
                        memcpy_async(__pscmc_mapu_internal_block__, ((__DDR unsigned *)(y + (blk_offset_t1 + j))), ((unsigned *)zeros), ((uint64_t)(1 * (numcp * data_size))), put_sync_id);
                    }
                }
                else
                {
                    {
                        0;
                    }
                }
            }
        }
    }
    (put_sync_id).arrive_and_wait();

    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISZERO_SYNCED**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

__global__ void mapu_blas_yiszero(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele)
{

#ifdef __SCALE_ARCH__
    __aurora_s_startCounter(f_Clear);
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    // __mem1__ int __mapu_dma_index;
    // __mapu_dma_index = 0;
    // const MAPU_LONG pscmc_compute_unit_id = 0;
    // const MAPU_LONG pscmc_num_compute_units = 1;
    const MAPU_LONG __idx = 0;
    // const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    const MAPU_LONG __xlen = 1;
    // const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
    // const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
    // __mem1__ MAPU_LONG local_ynum;
    // local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    // __mem1__ MAPU_LONG local_ymin;
    // local_ymin = (__idy * local_ynum);
    // __mem1__ MAPU_LONG local_ymax;
    // local_ymax = ((1 + __idy) * local_ynum);
    __mem1__ MAPU_LONG xb;
    xb = xblock;
    __mem1__ MAPU_LONG yb;
    yb = yblock;
    __mem1__ MAPU_LONG zb;
    zb = zblock;
    __mem1__ MAPU_LONG blk_all_len;
    blk_all_len = (xb * (yb * (zb * num_ele)));

    // if ((local_ymax >= numvec))
    // {
    //     {
    //         (local_ymax = numvec);
    //     }
    // }
    // else
    // {
    //     {
    //         0;
    //     }
    // }
    // __mem0__ double reduce_tmp_arr[IDX_OPT_MAX];
    // __mem1__ double reduce_tmp;
    // reduce_tmp = 0.00000000000000000e+00;
    {
        __mem1__ MAPU_LONG i;
        i = blockIdx.x * blockDim.x + threadIdx.x;
        // for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        {

            if ((blk_all_len <= 3072))
            {
                {
                    __mem0__ double fast_y[3072];
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof(((y + (i * blk_all_len)))[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)fast_y), ((__DDR unsigned *)(y + (i * blk_all_len))), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                    {
                        __mem1__ MAPU_LONG xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            {
                                                __mem1__ MAPU_LONG realidx;
                                                for ((realidx = 0); (realidx < (num_ele * XLEN)); (realidx = (realidx + 1)))
                                                {
                                                    ((fast_y)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)] = 0);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if ((blk_all_len * 1))
                    {
                        {
                            const size_t data_size = sizeof((fast_y)[0]);
                            memcpy_async(__pscmc_mapu_internal_block__, ((__DDR unsigned *)(y + (i * blk_all_len))), ((unsigned *)fast_y), ((uint64_t)(1 * (blk_all_len * data_size))), __pscmc_mapu_internal_barrier__);
                            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                    }
                    else
                    {
                        {
                            0;
                        }
                    }
                }
            }
            else
            {
                {
                    {
                        __mem1__ MAPU_LONG xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                __mem1__ MAPU_LONG xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        __mem1__ MAPU_LONG xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            __mem1__ MAPU_LONG blk_offset_t1;
                                            blk_offset_t1 = (blk_all_len * i);
                                            __mem1__ MAPU_LONG blk_offset;
                                            blk_offset = ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));
                                            {
                                                __mem1__ MAPU_LONG g;
                                                g = 0;
                                                for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele)); g++)
                                                {
                                                    __mem1__ MAPU_LONG realidx;
                                                    realidx = (__idx + (g * __xlen));
                                                    ((y)[(blk_offset + realidx)] = 0);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    __aurora_s_stopCounter();
    int spuCounter0 = __aurora_s_readCounter(f_NoFlag);
    printf("****YISZERO**** blockID = &=%lld; threadID = %lld; spu counter = %lld \n", (long long)blockIdx.x, (long long)threadIdx.x, (long long)spuCounter0);
#endif
}

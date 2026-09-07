static int mapu_counter_for_debug = 0;
#define IDX_OPT_MAX 1
#ifndef _MAPU_SIMD_BASE_FUN
#define _MAPU_SIMD_BASE_FUN
#endif

#define MAX_SIZE 3072
#define DOUBLE_VEC_SIZE 8
__device__ KERNEL_M void vaxpy_v8fp64_mpu(v8fp64 *y, v8fp64 *x, v8fp64 *a, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        y[i] = y[i] + a[0] * x[i];
    }
}

__device__ KERNEL_M void vyisax_v8fp64_mpu(v8fp64 *x, v8fp64 *a, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        x[i] = a[0] * x[i];
    }
}

__global__ void mapu_blas_axpy(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    auto block = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t bar;
    init(&bar, 1);

    MAPU_LONG blk_all_len = xb * yb * zb * num_ele;
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    int vnum = (XLEN * num_ele + DOUBLE_VEC_SIZE - 1) / DOUBLE_VEC_SIZE;
    const size_t data_size = sizeof(double) * XLEN * num_ele;
    y = y + tid * blk_all_len;
    x = x + tid * blk_all_len;

    __mem0__ __fix2__ double dm_x[MAX_SIZE];
    __mem1__ __fix3__ double dm_y[MAX_SIZE];
    __mem2__ __fix4__ double dm_a[DOUBLE_VEC_SIZE];
    for(int i = 0; i < DOUBLE_VEC_SIZE; i++)
    {
        dm_a[i] = a;
    }

    for (MAPU_LONG k = 0; k < ZLEN; k++)
    {
        for (MAPU_LONG j = 0; j < YLEN; j++)
        {   
            MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
            memcpy_async(block, (unsigned *)dm_y, (__DDR unsigned *)(y + offset), data_size, bar);
            memcpy_async(block, (unsigned *)dm_x, (__DDR unsigned *)(x + offset), data_size, bar);
            bar.arrive_and_wait();
            sync_call vaxpy_v8fp64_mpu((v8fp64*)dm_y, (v8fp64*)dm_x, (v8fp64*)dm_a, vnum);
            memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_y, data_size, bar);
            bar.arrive_and_wait();
        }
    }
#endif
}

__global__ void mapu_blas_yisax(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
#ifdef USE_LLCD
    __aurora_s_startCounter(f_Clear);
#endif
    auto block = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t bar;
    init(&bar, 1);

    MAPU_LONG blk_all_len = xb * yb * zb * num_ele;
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    int vnum = (XLEN * num_ele + DOUBLE_VEC_SIZE - 1) / DOUBLE_VEC_SIZE;
    const size_t data_size = sizeof(double) * XLEN * num_ele;
    y = y + tid * blk_all_len;
    x = x + tid * blk_all_len;

    __mem0__ __fix2__ double dm_x[MAX_SIZE];
    __mem1__ __fix3__ double dm_a[DOUBLE_VEC_SIZE];
    for(int i = 0; i < DOUBLE_VEC_SIZE; i++)
    {
        dm_a[i] = a;
    }

    for (MAPU_LONG k = 0; k < ZLEN; k++)
    {
        for (MAPU_LONG j = 0; j < YLEN; j++)
        {   
            MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
            memcpy_async(block, (unsigned *)dm_x, (__DDR unsigned *)(x + offset), data_size, bar);
            bar.arrive_and_wait();
            sync_call vyisax_v8fp64_mpu((v8fp64*)dm_x, (v8fp64*)dm_a, vnum);
            memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size, bar);
            bar.arrive_and_wait();
        }
    }  
#endif
}

__global__ void mapu_blas_yisax_enlarge(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    auto block = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t bar;
    init(&(bar), 1);

    MAPU_LONG xb_2x = 2 * ovlp + (XLEN == 1 ? 1 : XLEN * 2);
    MAPU_LONG yb_2x = 2 * ovlp + (YLEN == 1 ? 1 : YLEN * 2);
    MAPU_LONG zb_2x = 2 * ovlp + (ZLEN == 1 ? 1 : ZLEN * 2);
    int x2 = XLEN == 1 ? 1 : 2;
    int y2 = YLEN == 1 ? 1 : 2;
    int z2 = ZLEN == 1 ? 1 : 2;

    const size_t x_size = XLEN * num_ele;
    const size_t data_size = sizeof(double) * x_size;
    int vnum = (XLEN * num_ele + DOUBLE_VEC_SIZE - 1) / DOUBLE_VEC_SIZE;
    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    y = y + tid * xb_2x * yb_2x * zb_2x * num_ele;
    x = x + tid * xb * yb * zb * num_ele;

    __mem0__ __fix2__ double dm_x[MAX_SIZE];
    __mem1__ __fix3__ double dm_a[DOUBLE_VEC_SIZE];
    for(int i = 0; i < DOUBLE_VEC_SIZE; i++)
    {
        dm_a[i] = a * 0.125;
    }

    for (MAPU_LONG k = 0; k < ZLEN; k++)
    {
        for (MAPU_LONG j = 0; j < YLEN; j++)
        {
            MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
            memcpy_async(block, (unsigned *)dm_x, (__DDR unsigned *)(x + offset), data_size, bar);
            bar.arrive_and_wait();
            sync_call vyisax_v8fp64_mpu((v8fp64*)dm_x, (v8fp64*)dm_a, vnum);
            if (x2 == 2)
            {
                for (MAPU_LONG i = x_size - num_ele; i > -1; i-=num_ele)
                {
                    for (int e = 0; e < num_ele; e++)
                    {
                        dm_x[2 * i + e] = dm_x[i + e];
                        dm_x[2 * i + e + num_ele] = dm_x[i + e];
                    }
                }          
            }
            if (y2 == 2 && z2 == 2)
            {
                offset = num_ele * (ovlp + xb_2x * (2 * j + ovlp + yb_2x * (2 * k + ovlp)));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
                offset = num_ele * (ovlp + xb_2x * (2 * j + ovlp + yb_2x * (2 * k + 1 + ovlp)));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
                offset = num_ele * (ovlp + xb_2x * (2 * j + 1 + ovlp + yb_2x * (2 * k + ovlp)));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
                offset = num_ele * (ovlp + xb_2x * (2 * j + 1 + ovlp + yb_2x * (2 * k + 1 + ovlp)));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
            }
            else if(y2 == 2)
            {
                offset = num_ele * (ovlp + xb_2x * (2 * j + ovlp + yb_2x * ovlp));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
                offset = num_ele * (ovlp + xb_2x * (2 * j + 1 + ovlp + yb_2x * ovlp));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
            }
            else if(z2 == 2)
            {
                offset = num_ele * (ovlp + xb_2x * (ovlp + yb_2x * (2 * k + ovlp)));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
                offset = num_ele * (ovlp + xb_2x * (ovlp + yb_2x * (2 * k + 1 + ovlp)));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
            }
            else
            {
                offset = num_ele * (ovlp + xb_2x * (ovlp + yb_2x * ovlp));
                memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_x, data_size * x2, bar);
            }
            bar.arrive_and_wait();
        }
    }
#endif
}

__global__ void mapu_blas_yiszero(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xb, MAPU_LONG yb, MAPU_LONG zb, int num_ele)
{
#ifdef __SCALE_ARCH__
    auto block = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t bar;
    init(&bar, 1);

    MAPU_LONG tid = blockIdx.x * blockDim.x + threadIdx.x;
    y = y + tid * xb * yb * zb * num_ele;
    const size_t data_size = sizeof(double) * XLEN * num_ele;
    __mem0__ __fix2__ double dm_y[MAX_SIZE];
    for (MAPU_LONG i = 0; i < XLEN * num_ele; i++)
    {
        dm_y[i] = 0;
    }

    for (MAPU_LONG k = 0; k < ZLEN; k++)
    {
        for (MAPU_LONG j = 0; j < YLEN; j++)
        {
            MAPU_LONG offset = num_ele * (ovlp + xb * (j + ovlp + yb * (k + ovlp)));
            memcpy_async(block, (__DDR unsigned *)(y + offset), (unsigned *)dm_y, data_size, bar);
        }
    }
    bar.arrive_and_wait();
#endif
}

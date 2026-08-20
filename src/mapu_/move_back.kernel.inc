

#define IDX_OPT_MAX 1
#ifndef _MAPU_SIMD_BASE_FUN
#define _MAPU_SIMD_BASE_FUN
static __device__ KERNEL_M KERNEL_S double mapu_log_df(double p) {
    long long s = p;
    if (s < p) {
        return s;
    }
    else {
        return s + 1;
    }
}
static __device__ KERNEL_M KERNEL_S double mapu_floor_df(double p) {
    long long s = (long long)p;
    return (s > p) ? (double)(s - 1) : (double)s;
}
__device__ static KERNEL_M v8fp64 v8fp64_setr(double a0, double a1, double a2,
    double a3, double a4, double a5,
    double a6, double a7) {

    v8fp64 ret = { a0, a1, a2, a3, a4, a5, a6, a7 };
    return ret;
}
#define floor mapu_floor_df
#define log mapu_log_df
__device__ static KERNEL_M v8fp64 geo_floor_simd(v8fp64 input) {
    v8fp64 ret;
    double* pret = (double*)&(ret);
    double* pinput = (double*)&(input);
    int g;
    for ((g = 0); (g < 8); (g = (g + 1))) {
        ((pret)[g] = floor((pinput)[g]));
    }
    return ret;
}
#endif

#define IDX_OPT_MAX 1
__device__ int mapu_is_in(MAPU_LONG x, MAPU_LONG xl, MAPU_LONG xr) {
    return ((x < xr) && (x >= xl));
}
__global__ void mapu_move_back_kernel_6(__DDR double* inoutput, __DDR int* xyzw,
    __DDR double* cu_cache,
    __DDR int* cu_xyzw, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN,
    MAPU_LONG grid_cache_len,
    MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    __mem1__ int __mapu_dma_index;
    __mapu_dma_index = 0;
    const MAPU_LONG __idx = 0;
    const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    __mem1__ MAPU_LONG cu_offset;
    cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
    __mem1__ MAPU_LONG xyzalllen;
    xyzalllen = (XLEN * (YLEN * ZLEN));
    __shared__ barrier_t get_sync_id;

    if ((threadIdx.x == 0)) {
        {
            init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
    }
    else {
        {
            0;
        }
    }
    __shared__ barrier_t put_sync_id;

    if ((threadIdx.x == 0)) {
        {
            init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
    }
    else {
        {
            0;
        }
    }
    __mem1__ MAPU_LONG i;
    i = 0;
    __mem1__ MAPU_LONG j;
    j = 0;
    __mem0__ double local_temp_particle_cache[(64 * 6)];
    __mem1__ int cu_load;
    cu_load = (cu_xyzw)[(4 * __idy)];
    __mem1__ int cur_cu_load;
    cur_cu_load = 0;
    for (i = 0; (i < cu_load); (i = (i + 64))) {
        __mem1__ MAPU_LONG numcp;
        numcp = ((((i + 64) > cu_load)) ? (({ (cu_load - i); })) : (({ 64; })));

        if (((numcp * 6) * 1)) {
            {
                const size_t data_size =
                    sizeof(((cu_cache + (((cu_cache_length * __idy) + i) * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned*)(local_temp_particle_cache + (0 * 6))),
                    ((__DDR unsigned*)(cu_cache +
                        (((cu_cache_length * __idy) + i) * 6))),
                    ((uint64_t)(1 * ((numcp * 6) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
        }
        else {
            {
                0;
            }
        }

        if ((__idx == 0)) {
            {
                for (j = 0; (j < numcp); j++) {
                    __mem1__ MAPU_LONG allid;
                    allid = (i + j);
                    __mem1__ MAPU_LONG xyzx;
                    xyzx = floor(((local_temp_particle_cache + (j * 6)))[0]);
                    __mem1__ MAPU_LONG xyzy;
                    xyzy = floor(((local_temp_particle_cache + (j * 6)))[1]);
                    __mem1__ MAPU_LONG xyzz;
                    xyzz = floor(((local_temp_particle_cache + (j * 6)))[2]);
                    __mem1__ double dxyzx;
                    dxyzx = ((local_temp_particle_cache + (j * 6)))[0];
                    __mem1__ double dxyzy;
                    dxyzy = ((local_temp_particle_cache + (j * 6)))[1];
                    __mem1__ double dxyzz;
                    dxyzz = ((local_temp_particle_cache + (j * 6)))[2];
                    __mem1__ int wrted_grid;
                    wrted_grid = 0;

                    if ((mapu_is_in(xyzx, 0, XLEN) &&
                        (mapu_is_in(xyzy, 0, YLEN) && mapu_is_in(xyzz, 0, ZLEN)))) {
                            {
                                __mem1__ MAPU_LONG allid_grid;
                                allid_grid =
                                    ((0 + (1 * (xyzx + (XLEN * (xyzy + (YLEN * xyzz)))))) +
                                        cu_offset);
                                __mem1__ int gridload;
                                gridload = (xyzw)[(4 * allid_grid)];

                                if ((gridload < grid_cache_len)) {
                                    {
                                        __mem1__ MAPU_LONG grid_load_end;
                                        grid_load_end = (gridload + 1);
                                        ((xyzw)[(4 * allid_grid)] = grid_load_end);

                                        if ((6 * 1)) {
                                            {
                                                const size_t data_size =
                                                    sizeof(((local_temp_particle_cache + (j * 6)))[0]);
                                                memcpy_async(
                                                    __pscmc_mapu_internal_block__,
                                                    ((__DDR unsigned*)(inoutput +
                                                        (6 *
                                                            ((allid_grid * grid_cache_len) +
                                                                gridload)))),
                                                    ((unsigned*)(local_temp_particle_cache + (j * 6))),
                                                    ((uint64_t)(1 * (6 * data_size))), put_sync_id);
                                            }
                                        }
                                        else {
                                            {
                                                0;
                                            }
                                        }
                                        (wrted_grid = 1);
                                    }
                                }
                                else {
                                    {
                                        0;
                                    }
                                }
                            }
                    }
                    else {
                        {
                            0;
                        }
                    }

                    if ((!wrted_grid)) {
                        {

                            if ((6 * 1)) {
                                {
                                    const size_t data_size =
                                        sizeof(((local_temp_particle_cache + (j * 6)))[0]);
                                    memcpy_async(
                                        __pscmc_mapu_internal_block__,
                                        ((__DDR unsigned*)(cu_cache +
                                            (6 * ((__idy * cu_cache_length) +
                                                cur_cu_load)))),
                                        ((unsigned*)(local_temp_particle_cache + (j * 6))),
                                        ((uint64_t)(1 * (6 * data_size))), put_sync_id);
                                }
                            }
                            else {
                                {
                                    0;
                                }
                            }
                            (cur_cu_load = (cur_cu_load + 1));
                        }
                    }
                    else {
                        {
                            0;
                        }
                    }
                }
            }
        }
        else {
            {
                0;
            }
        }
        (put_sync_id).arrive_and_wait();
    }
    if ((__idx == 0)) {
        {
            ((cu_xyzw)[(__idy * 4)] = cur_cu_load);
        }
    }
    else {
        {
            0;
        }
    }

#endif
}
__global__ void mapu_move_back_kernel_8(__DDR double* inoutput, __DDR int* xyzw,
    __DDR double* cu_cache,
    __DDR int* cu_xyzw, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN,
    MAPU_LONG grid_cache_len,
    MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
    auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t __pscmc_mapu_internal_barrier__;

    static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
    init(&(__pscmc_mapu_internal_barrier__), 1);
    __mem1__ int __mapu_dma_index;
    __mapu_dma_index = 0;
    const MAPU_LONG __idx = 0;
    const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
    __mem1__ MAPU_LONG cu_offset;
    cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
    __mem1__ MAPU_LONG xyzalllen;
    xyzalllen = (XLEN * (YLEN * ZLEN));
    __shared__ barrier_t get_sync_id;

    if ((threadIdx.x == 0)) {
        {
            init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
    }
    else {
        {
            0;
        }
    }
    __shared__ barrier_t put_sync_id;

    if ((threadIdx.x == 0)) {
        {
            init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
    }
    else {
        {
            0;
        }
    }
    __mem1__ MAPU_LONG i;
    i = 0;
    __mem1__ MAPU_LONG j;
    j = 0;
    __mem0__ double local_temp_particle_cache[(64 * 8)];
    __mem1__ int cu_load;
    cu_load = (cu_xyzw)[(4 * __idy)];
    __mem1__ int cur_cu_load;
    cur_cu_load = 0;
    for (i = 0; (i < cu_load); (i = (i + 64))) {
        __mem1__ MAPU_LONG numcp;
        numcp = ((((i + 64) > cu_load)) ? (({ (cu_load - i); })) : (({ 64; })));

        if (((numcp * 8) * 1)) {
            {
                const size_t data_size =
                    sizeof(((cu_cache + (((cu_cache_length * __idy) + i) * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned*)(local_temp_particle_cache + (0 * 8))),
                    ((__DDR unsigned*)(cu_cache +
                        (((cu_cache_length * __idy) + i) * 8))),
                    ((uint64_t)(1 * ((numcp * 8) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
        }
        else {
            {
                0;
            }
        }

        if ((__idx == 0)) {
            {
                for (j = 0; (j < numcp); j++) {
                    __mem1__ MAPU_LONG allid;
                    allid = (i + j);
                    __mem1__ MAPU_LONG xyzx;
                    xyzx = floor(((local_temp_particle_cache + (j * 8)))[0]);
                    __mem1__ MAPU_LONG xyzy;
                    xyzy = floor(((local_temp_particle_cache + (j * 8)))[1]);
                    __mem1__ MAPU_LONG xyzz;
                    xyzz = floor(((local_temp_particle_cache + (j * 8)))[2]);
                    __mem1__ double dxyzx;
                    dxyzx = ((local_temp_particle_cache + (j * 8)))[0];
                    __mem1__ double dxyzy;
                    dxyzy = ((local_temp_particle_cache + (j * 8)))[1];
                    __mem1__ double dxyzz;
                    dxyzz = ((local_temp_particle_cache + (j * 8)))[2];
                    __mem1__ int wrted_grid;
                    wrted_grid = 0;

                    if ((mapu_is_in(xyzx, 0, XLEN) &&
                        (mapu_is_in(xyzy, 0, YLEN) && mapu_is_in(xyzz, 0, ZLEN)))) {
                            {
                                __mem1__ MAPU_LONG allid_grid;
                                allid_grid =
                                    ((0 + (1 * (xyzx + (XLEN * (xyzy + (YLEN * xyzz)))))) +
                                        cu_offset);
                                __mem1__ int gridload;
                                gridload = (xyzw)[(4 * allid_grid)];

                                if ((gridload < grid_cache_len)) {
                                    {
                                        __mem1__ MAPU_LONG grid_load_end;
                                        grid_load_end = (gridload + 1);
                                        ((xyzw)[(4 * allid_grid)] = grid_load_end);

                                        if ((8 * 1)) {
                                            {
                                                const size_t data_size =
                                                    sizeof(((local_temp_particle_cache + (j * 8)))[0]);
                                                memcpy_async(
                                                    __pscmc_mapu_internal_block__,
                                                    ((__DDR unsigned*)(inoutput +
                                                        (8 *
                                                            ((allid_grid * grid_cache_len) +
                                                                gridload)))),
                                                    ((unsigned*)(local_temp_particle_cache + (j * 8))),
                                                    ((uint64_t)(1 * (8 * data_size))), put_sync_id);
                                            }
                                        }
                                        else {
                                            {
                                                0;
                                            }
                                        }
                                        (wrted_grid = 1);
                                    }
                                }
                                else {
                                    {
                                        0;
                                    }
                                }
                            }
                    }
                    else {
                        {
                            0;
                        }
                    }

                    if ((!wrted_grid)) {
                        {

                            if ((8 * 1)) {
                                {
                                    const size_t data_size =
                                        sizeof(((local_temp_particle_cache + (j * 8)))[0]);
                                    memcpy_async(
                                        __pscmc_mapu_internal_block__,
                                        ((__DDR unsigned*)(cu_cache +
                                            (8 * ((__idy * cu_cache_length) +
                                                cur_cu_load)))),
                                        ((unsigned*)(local_temp_particle_cache + (j * 8))),
                                        ((uint64_t)(1 * (8 * data_size))), put_sync_id);
                                }
                            }
                            else {
                                {
                                    0;
                                }
                            }
                            (cur_cu_load = (cur_cu_load + 1));
                        }
                    }
                    else {
                        {
                            0;
                        }
                    }
                }
            }
        }
        else {
            {
                0;
            }
        }
        (put_sync_id).arrive_and_wait();
    }
    if ((__idx == 0)) {
        {
            ((cu_xyzw)[(__idy * 4)] = cur_cu_load);
        }
    }
    else {
        {
            0;
        }
    }

#endif
}

#define VEC_W           8
#define TILE_X          64              
#define TILE_X_PAD      (TILE_X + VEC_W) 
#define ROUND_UP(n, a)  (((n) + (a) - 1) / (a) * (a))
#define INV(x)          (1.0 / (x))


__device__ static inline __DDR double* ptr_field(
    __DDR double* base,
    long long blk_offset,
    int comp,
    long long x,
    long long y,
    long long z,
    long long xblock,
    long long yblock,
    long long num_ele)
{
    return base + blk_offset + comp + num_ele * ((x) + xblock * (y + yblock * z));
}

template <typename SrcType, typename DstType, typename BT2, typename C>
__device__ void dma_get_stride_async(
    C& block,
    DstType* dst,
    const __DDR SrcType* src,
    int batch_size,
    int stride,
    BT2& bar)
{
    for (int i = 0; i < batch_size; ++i) {
        memcpy_async(block, dst + i, src + i * stride, sizeof(SrcType), bar);
    }
}


template <typename SrcType, typename DstType, typename BT2, typename C>
__device__ void dma_put_stride_async(
    C& block,
    __DDR DstType* dst,
    const SrcType* src,
    int batch_size,
    int stride,
    BT2& bar)
{
    for (int i = 0; i < batch_size; ++i) {
        memcpy_async(block, dst + i * stride, src + i,  sizeof(SrcType), bar);
    }
}

typedef struct {
    double* __restrict__ b0_cur;   // B0(x-1..)
    double* __restrict__ b1_cur;   // B1(x-1..)
    double* __restrict__ b2_cur;   // B2(x-1..)
    double* __restrict__ b0_ym;    // B0(x, y-1, z)
    double* __restrict__ b2_ym;    // B2(x, y-1, z)
    double* __restrict__ b0_zm;    // B0(x, y, z-1)
    double* __restrict__ b1_zm;    // B1(x, y, z-1)
    double* __restrict__ e0;       // old E0 (SoA)
    double* __restrict__ e1;
    double* __restrict__ e2;
    double* __restrict__ o0;       // output E0 (SoA)
    double* __restrict__ o1;
    double* __restrict__ o2;
    double DT;
    double idx2;
    double idy2;
    double idz2;
    double x0;
    double gxoffset;
    long xbeg;
} GeoYeeCurlLParam;

__device__ KERNEL_M void geo_yee_curl_l_mpu(
    long end,
    const GeoYeeCurlLParam* __restrict__ p)
{
    v8fp64 DT_vec, x0_vec, idx2_vec, idy2_vec, idz2_vec;
    for (int i = 0; i < VEC_W; ++i) {
        ((double*)&DT_vec)[i]   = p->DT;
        ((double*)&x0_vec)[i]   = p->x0;
        ((double*)&idx2_vec)[i] = p->idx2;
        ((double*)&idy2_vec)[i] = p->idy2;
        ((double*)&idz2_vec)[i] = p->idz2;
    }

   
    #pragma clang loop waitgen_loop(enable)
    #pragma clang loop parallel(4)
    for (long off = 0; off < end; off += VEC_W) {

        v8fp64 t_vec;
        for (int i = 0; i < VEC_W; ++i)
            ((double*)&t_vec)[i] = (double)(off + i);

        v8fp64 A_vec = x0_vec + (double)p->gxoffset + (double)p->xbeg + t_vec;

        v8fp64 r_vec = x0_vec / A_vec;
        v8fp64 r2_vec = r_vec * r_vec;

        v8fp64 Ap1 = A_vec - 1.0;
        v8fp64 ap_vec = A_vec / Ap1;

        v8fp64 am_vec = Ap1 / A_vec;

        v8fp64 B0_c  = *(v8fp64*)(p->b0_cur + off + 1);
        v8fp64 B0_ym = *(v8fp64*)(p->b0_ym  + off);
        v8fp64 B0_zm = *(v8fp64*)(p->b0_zm  + off);

        v8fp64 B1_c  = *(v8fp64*)(p->b1_cur + off + 1);
        v8fp64 B1_xm = *(v8fp64*)(p->b1_cur + off);      // x-1
        v8fp64 B1_zm = *(v8fp64*)(p->b1_zm  + off);

        v8fp64 B2_c  = *(v8fp64*)(p->b2_cur + off + 1);
        v8fp64 B2_xm = *(v8fp64*)(p->b2_cur + off);
        v8fp64 B2_ym = *(v8fp64*)(p->b2_ym  + off);

        v8fp64 E0 = *(v8fp64*)(p->e0 + off);
        v8fp64 E1 = *(v8fp64*)(p->e1 + off);
        v8fp64 E2 = *(v8fp64*)(p->e2 + off);

        v8fp64 O0 = E0 + DT_vec * ((B1_zm - B1_c) * idz2_vec
                                 + r2_vec * (B2_c - B2_ym) * idy2_vec);
        v8fp64 O1 = E1 + DT_vec * ((B0_c - B0_zm) * idz2_vec
                                 + (ap_vec * B2_xm - B2_c) * idx2_vec);
        v8fp64 O2 = E2 + DT_vec * (r2_vec * (B0_ym - B0_c) * idy2_vec
                                 + (B1_c - am_vec * B1_xm) * idx2_vec);

        *(v8fp64*)(p->o0 + off) = O0;
        *(v8fp64*)(p->o1 + off) = O1;
        *(v8fp64*)(p->o2 + off) = O2;
    }
}


__global__ void mapu_GEO_YEE_CURL_L(
    __DDR double *inoutE1, __DDR double *inB0,
    __DDR int *xoffset, __DDR int *yoffset, __DDR int *zoffset,
    long long y_cpu_core, long long numvec,
    long long XLEN, long long YLEN, long long ZLEN,
    int ovlp, long long xblock, long long yblock, long long zblock,
    int num_ele, double DT,
    double DELTA_Z, double DELTA_Y, double DELTA_X,
    double x0)
{
#ifdef __SCALE_ARCH__

    double inv_DELTA_X = INV(DELTA_X);
    double inv_DELTA_Y = INV(DELTA_Y);
    double inv_DELTA_Z = INV(DELTA_Z);
    double idx2 = inv_DELTA_X * inv_DELTA_X;
    double idy2 = inv_DELTA_Y * inv_DELTA_Y;
    double idz2 = inv_DELTA_Z * inv_DELTA_Z;

    long long ntile_x = (XLEN + TILE_X - 1) / TILE_X;
    long long total_tasks = numvec * YLEN * ZLEN * ntile_x;

    int tid = threadIdx.x;
    int block_size = blockDim.x;

    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t get_bar, put_bar;
    if (tid == 0) {
        init(&get_bar, block_size);
        init(&put_bar, block_size);
    }
    __syncthreads();

    auto block = cooperative_groups::this_thread_block();

    long long base = (long long)blockIdx.x * block_size;
    long long stride = (long long)gridDim.x * block_size;

    for (long long task_base = base; task_base < total_tasks; task_base += stride) {
        long long task = task_base + tid;
        bool active = (task < total_tasks);

        __mem0__ __fix0__ double b0_cur[TILE_X_PAD] __attribute__((aligned(64)));
        __mem1__ __fix1__ double b1_cur[TILE_X_PAD] __attribute__((aligned(64)));
        __mem2__ __fix2__ double b2_cur[TILE_X_PAD] __attribute__((aligned(64)));

        __mem3__ __fix3__ double b0_ym[TILE_X_PAD] __attribute__((aligned(64)));
        __mem4__ __fix4__ double b2_ym[TILE_X_PAD] __attribute__((aligned(64)));

        __mem0__ __fix0__ double b0_zm[TILE_X_PAD] __attribute__((aligned(64)));
        __mem1__ __fix1__ double b1_zm[TILE_X_PAD] __attribute__((aligned(64)));

        __mem2__ __fix2__ double e0[TILE_X_PAD] __attribute__((aligned(64)));
        __mem3__ __fix3__ double e1[TILE_X_PAD] __attribute__((aligned(64)));
        __mem4__ __fix4__ double e2[TILE_X_PAD] __attribute__((aligned(64)));

        __mem0__ __fix0__ double o0[TILE_X_PAD] __attribute__((aligned(64)));
        __mem1__ __fix1__ double o1[TILE_X_PAD] __attribute__((aligned(64)));
        __mem2__ __fix2__ double o2[TILE_X_PAD] __attribute__((aligned(64)));

        long long tx, y, z, i;
        long long n, xbeg, end;
        double gxoffset;
        long long blk_offset;

        if (active) {
            tx = task % ntile_x;
            long long tmp = task / ntile_x;
            y = tmp % YLEN;
            long long tmp2 = tmp / YLEN;
            z = tmp2 % ZLEN;
            i = tmp2 / ZLEN;

            xbeg = tx * TILE_X;
            n = fmin(TILE_X, XLEN - xbeg);
            end = ROUND_UP(n, VEC_W);

            gxoffset = (double)(xoffset[i]);

            blk_offset = (xblock * yblock * zblock) * (i * num_ele);

            dma_get_stride_async(block, b0_cur,
                ptr_field(inB0, blk_offset, 0, xbeg - 1 + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n + 1, num_ele, get_bar);
            dma_get_stride_async(block, b1_cur,
                ptr_field(inB0, blk_offset, 1, xbeg - 1 + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n + 1, num_ele, get_bar);
            dma_get_stride_async(block, b2_cur,
                ptr_field(inB0, blk_offset, 2, xbeg - 1 + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n + 1, num_ele, get_bar);

            dma_get_stride_async(block, b0_ym,
                ptr_field(inB0, blk_offset, 0, xbeg + ovlp, y - 1 + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, b2_ym,
                ptr_field(inB0, blk_offset, 2, xbeg + ovlp, y - 1 + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);

            dma_get_stride_async(block, b0_zm,
                ptr_field(inB0, blk_offset, 0, xbeg + ovlp, y + ovlp, z - 1 + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, b1_zm,
                ptr_field(inB0, blk_offset, 1, xbeg + ovlp, y + ovlp, z - 1 + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);

            dma_get_stride_async(block, e0,
                ptr_field(inoutE1, blk_offset, 0, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, e1,
                ptr_field(inoutE1, blk_offset, 1, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, e2,
                ptr_field(inoutE1, blk_offset, 2, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
        }

        get_bar.arrive_and_wait();

        if (active) {
            if (n < end) {
                for (int lane = n; lane < end; ++lane) {
                    o0[lane] = 0.0;
                    o1[lane] = 0.0;
                    o2[lane] = 0.0;
                }
            }

            GeoYeeCurlLParam param;
            param.b0_cur  = b0_cur;
            param.b1_cur  = b1_cur;
            param.b2_cur  = b2_cur;
            param.b0_ym   = b0_ym;
            param.b2_ym   = b2_ym;
            param.b0_zm   = b0_zm;
            param.b1_zm   = b1_zm;
            param.e0      = e0;
            param.e1      = e1;
            param.e2      = e2;
            param.o0      = o0;
            param.o1      = o1;
            param.o2      = o2;
            param.DT      = DT;
            param.idx2    = idx2;
            param.idy2    = idy2;
            param.idz2    = idz2;
            param.x0      = x0;
            param.gxoffset = gxoffset;
            param.xbeg    = xbeg;

            MPU_SYNC();
            geo_yee_curl_l_mpu(end, &param);
            MPU_SYNC();

            dma_put_stride_async(block,
                ptr_field(inoutE1, blk_offset, 0, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                o0, n, num_ele, put_bar);
            dma_put_stride_async(block,
                ptr_field(inoutE1, blk_offset, 1, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                o1, n, num_ele, put_bar);
            dma_put_stride_async(block,
                ptr_field(inoutE1, blk_offset, 2, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                o2, n, num_ele, put_bar);
        }

        put_bar.arrive_and_wait();
    }

#endif
}

typedef struct {
    double* __restrict__ b0_cur;   // B0(x..x+n)
    double* __restrict__ b1_cur;   // B1(x..x+n)
    double* __restrict__ b2_cur;   // B2(x..x+n)
    double* __restrict__ b0_ym;    // B0(x, y+1, z)
    double* __restrict__ b2_ym;    // B2(x, y+1, z)
    double* __restrict__ b0_zm;    // B0(x, y, z+1)
    double* __restrict__ b1_zm;    // B1(x, y, z+1)
    double* __restrict__ e0;       // old E0
    double* __restrict__ e1;
    double* __restrict__ e2;
    double* __restrict__ o0;
    double* __restrict__ o1;
    double* __restrict__ o2;
    double DT;
} GeoYeeCurlRParam;

__device__ KERNEL_M void geo_yee_curl_r_mpu(
    long end,
    const GeoYeeCurlRParam* __restrict__ p)
{
    v8fp64 DT_vec;
    for (int i = 0; i < VEC_W; ++i)
        ((double*)&DT_vec)[i] = p->DT;

    #pragma clang loop waitgen_loop(enable)
    #pragma clang loop parallel(4)
    for (long off = 0; off < end; off += VEC_W) {
        v8fp64 B0_c  = *(v8fp64*)(p->b0_cur + off);      // B0(x)
        v8fp64 B0_ym = *(v8fp64*)(p->b0_ym  + off);      // B0(x, y+1, z)
        v8fp64 B0_zm = *(v8fp64*)(p->b0_zm  + off);      // B0(x, y, z+1)

        v8fp64 B1_c  = *(v8fp64*)(p->b1_cur + off);      // B1(x)
        v8fp64 B1_xp = *(v8fp64*)(p->b1_cur + off + 1);  // B1(x+1)
        v8fp64 B1_zm = *(v8fp64*)(p->b1_zm  + off);      // B1(x, y, z+1)

        v8fp64 B2_c  = *(v8fp64*)(p->b2_cur + off);      // B2(x)
        v8fp64 B2_xp = *(v8fp64*)(p->b2_cur + off + 1);  // B2(x+1)
        v8fp64 B2_ym = *(v8fp64*)(p->b2_ym  + off);      // B2(x, y+1, z)

        v8fp64 E0 = *(v8fp64*)(p->e0 + off);
        v8fp64 E1 = *(v8fp64*)(p->e1 + off);
        v8fp64 E2 = *(v8fp64*)(p->e2 + off);

        v8fp64 O0 = E0 + DT_vec * (-B1_c + B1_zm + B2_c - B2_ym);
        v8fp64 O1 = E1 + DT_vec * ( B0_c - B0_zm - B2_c + B2_xp);
        v8fp64 O2 = E2 + DT_vec * (-B0_c + B0_ym + B1_c - B1_xp);

        *(v8fp64*)(p->o0 + off) = O0;
        *(v8fp64*)(p->o1 + off) = O1;
        *(v8fp64*)(p->o2 + off) = O2;
    }
}

__global__ void mapu_YEE_CURL_R(
    __DDR double *inoutE1, __DDR double *inB0,
    __DDR int *xoffset, __DDR int *yoffset, __DDR int *zoffset,
    long long y_cpu_core, long long numvec,
    long long XLEN, long long YLEN, long long ZLEN,
    int ovlp, long long xblock, long long yblock, long long zblock,
    int num_ele, double DT)
{
#ifdef __SCALE_ARCH__

    long long ntile_x = (XLEN + TILE_X - 1) / TILE_X;
    long long total_tasks = numvec * YLEN * ZLEN * ntile_x;

    int tid = threadIdx.x;
    int block_size = blockDim.x;

    using barrier_t = scale::barrier<scale::thread_scope_block>;
    __shared__ barrier_t get_bar, put_bar;
    if (tid == 0) {
        init(&get_bar, block_size);
        init(&put_bar, block_size);
    }
    __syncthreads();

    auto block = cooperative_groups::this_thread_block();

    long long base = (long long)blockIdx.x * block_size;
    long long stride = (long long)gridDim.x * block_size;

    for (long long task_base = base; task_base < total_tasks; task_base += stride) {
        long long task = task_base + tid;
        bool active = (task < total_tasks);

        __mem0__ __fix0__ double b0_cur[TILE_X_PAD] __attribute__((aligned(64)));
        __mem1__ __fix1__ double b1_cur[TILE_X_PAD] __attribute__((aligned(64)));
        __mem2__ __fix2__ double b2_cur[TILE_X_PAD] __attribute__((aligned(64)));

        __mem3__ __fix3__ double b0_ym[TILE_X_PAD] __attribute__((aligned(64)));
        __mem4__ __fix4__ double b2_ym[TILE_X_PAD] __attribute__((aligned(64)));

        __mem0__ __fix0__ double b0_zm[TILE_X_PAD] __attribute__((aligned(64)));
        __mem1__ __fix1__ double b1_zm[TILE_X_PAD] __attribute__((aligned(64)));

        __mem2__ __fix2__ double e0[TILE_X_PAD] __attribute__((aligned(64)));
        __mem3__ __fix3__ double e1[TILE_X_PAD] __attribute__((aligned(64)));
        __mem4__ __fix4__ double e2[TILE_X_PAD] __attribute__((aligned(64)));

        __mem0__ __fix0__ double o0[TILE_X_PAD] __attribute__((aligned(64)));
        __mem1__ __fix1__ double o1[TILE_X_PAD] __attribute__((aligned(64)));
        __mem2__ __fix2__ double o2[TILE_X_PAD] __attribute__((aligned(64)));

        long long tx, y, z, i;
        long long n, xbeg, end;
        double gxoffset;
        long long blk_offset;

        if (active) {
            tx = task % ntile_x;
            long long tmp = task / ntile_x;
            y = tmp % YLEN;
            long long tmp2 = tmp / YLEN;
            z = tmp2 % ZLEN;
            i = tmp2 / ZLEN;

            xbeg = tx * TILE_X;
            n = fmin(TILE_X, XLEN - xbeg);
            end = ROUND_UP(n, VEC_W);

            gxoffset = (double)(xoffset[i]);

            blk_offset = (xblock * yblock * zblock) * (i * num_ele);

            dma_get_stride_async(block, b0_cur,
                ptr_field(inB0, blk_offset, 0, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n + 1, num_ele, get_bar);
            dma_get_stride_async(block, b1_cur,
                ptr_field(inB0, blk_offset, 1, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n + 1, num_ele, get_bar);
            dma_get_stride_async(block, b2_cur,
                ptr_field(inB0, blk_offset, 2, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n + 1, num_ele, get_bar);

            dma_get_stride_async(block, b0_ym,
                ptr_field(inB0, blk_offset, 0, xbeg + ovlp, y + 1 + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, b2_ym,
                ptr_field(inB0, blk_offset, 2, xbeg + ovlp, y + 1 + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);

            dma_get_stride_async(block, b0_zm,
                ptr_field(inB0, blk_offset, 0, xbeg + ovlp, y + ovlp, z + 1 + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, b1_zm,
                ptr_field(inB0, blk_offset, 1, xbeg + ovlp, y + ovlp, z + 1 + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);

            dma_get_stride_async(block, e0,
                ptr_field(inoutE1, blk_offset, 0, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, e1,
                ptr_field(inoutE1, blk_offset, 1, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
            dma_get_stride_async(block, e2,
                ptr_field(inoutE1, blk_offset, 2, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                n, num_ele, get_bar);
        }

        get_bar.arrive_and_wait();

        if (active) {
            if (n < end) {
                for (int lane = n; lane < end; ++lane) {
                    o0[lane] = 0.0;
                    o1[lane] = 0.0;
                    o2[lane] = 0.0;
                }
            }

            GeoYeeCurlRParam param;
            param.b0_cur = b0_cur;
            param.b1_cur = b1_cur;
            param.b2_cur = b2_cur;
            param.b0_ym  = b0_ym;
            param.b2_ym  = b2_ym;
            param.b0_zm  = b0_zm;
            param.b1_zm  = b1_zm;
            param.e0     = e0;
            param.e1     = e1;
            param.e2     = e2;
            param.o0     = o0;
            param.o1     = o1;
            param.o2     = o2;
            param.DT     = DT;

            MPU_SYNC();
            geo_yee_curl_r_mpu(end, &param);
            MPU_SYNC();

            dma_put_stride_async(block,
                ptr_field(inoutE1, blk_offset, 0, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                o0, n, num_ele, put_bar);
            dma_put_stride_async(block,
                ptr_field(inoutE1, blk_offset, 1, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                o1, n, num_ele, put_bar);
            dma_put_stride_async(block,
                ptr_field(inoutE1, blk_offset, 2, xbeg + ovlp, y + ovlp, z + ovlp, xblock, yblock, num_ele),
                o2, n, num_ele, put_bar);
        }

        put_bar.arrive_and_wait();
    }
#endif
}
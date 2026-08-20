#define INV(x) (1.0 / (x))
#define VEC_WIDTH 8

struct GeoCoeffs{
    double inv_DELTA_X, inv_DELTA_Y, inv_DELTA_Z;
    double DELTA_X, DELTA_Y, DELTA_Z;
    double x0;
};

__device__ KERNEL_M void mpu_GEO_update_Ex(
    v8fp64* Ex_out,
    v8fp64 vB10111, v8fp64 vB11111, v8fp64 vB21011, v8fp64 vB21111,
    v8fp64 xo0, v8fp64 DT
    ,const GeoCoeffs* coeffs)
{
    double x0 = coeffs->x0;
    double inv_DELTA_X = coeffs->inv_DELTA_X;
    double inv_DELTA_Y = coeffs->inv_DELTA_Y;
    double inv_DELTA_Z = coeffs->inv_DELTA_Z;
    double DELTA_X     = coeffs->DELTA_X;
    double DELTA_Y     = coeffs->DELTA_Y;
    double DELTA_Z     = coeffs->DELTA_Z;
    
    v8fp64 x0_vec;
    for(int i=0; i<VEC_WIDTH;i++) ((double*)&x0_vec)[i] = x0;

    v8fp64 inv_one_plus = 1.0 / (1.0 + x0_vec + xo0);
    v8fp64 inv_x0 = 1.0 / x0_vec;


    v8fp64 coeff1 = inv_x0 * (1.0 + x0_vec + xo0) * inv_DELTA_X * DELTA_Y * inv_DELTA_Z;
    v8fp64 coeff2 = x0_vec * inv_one_plus * inv_DELTA_X * inv_DELTA_Y * DELTA_Z;

    v8fp64 term1 = coeff1 * vB10111;
    v8fp64 term2 = -coeff1 * vB11111;
    v8fp64 term3 = -coeff2 * vB21011;
    v8fp64 term4 =  coeff2 * vB21111;

    v8fp64 sum = term1 + term2 + term3 + term4;

    v8fp64 factor = DT * x0_vec * inv_one_plus * (DELTA_X * inv_DELTA_Y * inv_DELTA_Z);
    *Ex_out = factor * sum;
}

__device__ KERNEL_M void mpu_GEO_update_Ey(
    v8fp64* Ey_out,
    v8fp64 vB00111, v8fp64 vB01111, v8fp64 vB21101, v8fp64 vB21111,
    v8fp64 xo0, v8fp64 DT
    ,const GeoCoeffs* coeffs)
{
    double x0 = coeffs->x0;
    double inv_DELTA_X = coeffs->inv_DELTA_X;
    double inv_DELTA_Y = coeffs->inv_DELTA_Y;
    double inv_DELTA_Z = coeffs->inv_DELTA_Z;
    double DELTA_X     = coeffs->DELTA_X;
    double DELTA_Y     = coeffs->DELTA_Y;
    double DELTA_Z     = coeffs->DELTA_Z;
    
    v8fp64 x0_vec;
    for(int i=0; i<VEC_WIDTH;i++) ((double*)&x0_vec)[i] = x0;

    v8fp64 inv_one_plus = 1.0 / (1.0 + x0_vec + xo0);
    v8fp64 inv_x0 = 1.0 / x0_vec;

    v8fp64 coeff1 = x0_vec * inv_one_plus * DELTA_X * inv_DELTA_Y * inv_DELTA_Z;
    v8fp64 coeff2 = x0_vec * (1.0 / (x0_vec + xo0)) * inv_DELTA_X * inv_DELTA_Y * DELTA_Z;
    v8fp64 coeff3 = x0_vec * inv_one_plus * inv_DELTA_X * inv_DELTA_Y * DELTA_Z;


    v8fp64 term1 = -coeff1 * vB00111;
    v8fp64 term2 =  coeff1 * vB01111;
    v8fp64 term3 =  coeff2 * vB21101;
    v8fp64 term4 = -coeff3 * vB21111;

    v8fp64 sum = term1 + term2 + term3 + term4;

    v8fp64 factor = DT * inv_x0 * (1.0 + x0_vec + xo0) * inv_DELTA_X * DELTA_Y * inv_DELTA_Z;
    *Ey_out = factor * sum;
}

__device__ KERNEL_M void mpu_GEO_update_Ez(
    v8fp64* Ez_out,
    v8fp64 vB01011, v8fp64 vB01111, v8fp64 vB11101, v8fp64 vB11111,
    v8fp64 xo0, v8fp64 DT
    ,const GeoCoeffs* coeffs)
{
    double x0 = coeffs->x0;
    double inv_DELTA_X = coeffs->inv_DELTA_X;
    double inv_DELTA_Y = coeffs->inv_DELTA_Y;
    double inv_DELTA_Z = coeffs->inv_DELTA_Z;
    double DELTA_X     = coeffs->DELTA_X;
    double DELTA_Y     = coeffs->DELTA_Y;
    double DELTA_Z     = coeffs->DELTA_Z;
    
    v8fp64 x0_vec;
    for(int i=0; i<VEC_WIDTH;i++) ((double*)&x0_vec)[i] = x0;

    v8fp64 inv_one_plus = 1.0 / (1.0 + x0_vec + xo0);
    v8fp64 inv_x0 = 1.0 / x0_vec;

    v8fp64 coeff1 = x0_vec * inv_one_plus * DELTA_X * inv_DELTA_Y * inv_DELTA_Z;
    v8fp64 coeff2 = inv_x0 * (x0_vec + xo0) * inv_DELTA_X * DELTA_Y * inv_DELTA_Z;
    v8fp64 coeff3 = inv_x0 * (1.0 + x0_vec + xo0) * inv_DELTA_X * DELTA_Y * inv_DELTA_Z;

    v8fp64 term1 =  coeff1 * vB01011;
    v8fp64 term2 = -coeff1 * vB01111;
    v8fp64 term3 = -coeff2 * vB11101;
    v8fp64 term4 =  coeff3 * vB11111;

    v8fp64 sum = term1 + term2 + term3 + term4;

    v8fp64 factor = DT * x0_vec * inv_one_plus * inv_DELTA_X * inv_DELTA_Y * DELTA_Z;
    *Ez_out = factor * sum;
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

   
    int tid = (blockIdx.x + blockIdx.y * gridDim.x) * blockDim.x + threadIdx.x;
    long long X_segments = (XLEN + VEC_WIDTH - 1) / VEC_WIDTH;
    long long total_per_xy = YLEN * ZLEN;
    long long total_per_i = total_per_xy * X_segments;

    long long idx = tid;
    long long x_seg = idx % X_segments;
    long long tmp = idx / X_segments;
    long long i = tmp / total_per_xy;
    long long rem = tmp % total_per_xy;
    long long xyzy = rem / ZLEN;
    long long xyzz = rem % ZLEN;

    if (i >= numvec || xyzy >= YLEN || xyzz >= ZLEN) return;

    
    double gxoffset = (double)(xoffset[i]);

    long long blk_all_len_nonele = xblock * yblock * zblock;
    long long blk_offset = blk_all_len_nonele * (i * num_ele);

    long long x_start = x_seg * VEC_WIDTH;
   
    if (x_start >= XLEN) return;

    
    long long actual_width = (x_start + VEC_WIDTH <= XLEN) ? VEC_WIDTH : (XLEN - x_start);

    __mem0__ v8fp64 vB10111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB11111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB21011 __attribute__((aligned(64)));

    __mem0__ v8fp64 vB21111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB00111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB01111 __attribute__((aligned(64)));

    __mem0__ v8fp64 vB21101 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB01011 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB11101 __attribute__((aligned(64)));

    auto get_B_offset_abs = [&](long long x_abs, int dx, int dy, int dz, int comp) -> size_t {
        long long x_idx = x_abs + dx + ovlp;
        long long y_idx = xyzy + dy + ovlp;
        long long z_idx = xyzz + dz + ovlp;
        return blk_offset + comp + num_ele * (x_idx + xblock * (y_idx + yblock * z_idx));
    };

    double* pB10111 = (double*)&vB10111;
    double* pB11111 = (double*)&vB11111;
    double* pB21011 = (double*)&vB21011;

    double* pB21111 = (double*)&vB21111;
    double* pB00111 = (double*)&vB00111;
    double* pB01111 = (double*)&vB01111;

    double* pB21101 = (double*)&vB21101;
    double* pB01011 = (double*)&vB01011;
    double* pB11101 = (double*)&vB11101;

    for (int lane = 0; lane < actual_width; ++lane) {
        long long x_abs = x_start + lane;
        pB10111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, -1, 1)];
        pB11111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 0, 1)];
        pB21011[lane] = inB0[get_B_offset_abs(x_abs, 0, -1, 0, 2)];

        pB21111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 0, 2)];
        pB00111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, -1, 0)];
        pB01111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 0, 0)];
        
        pB21101[lane] = inB0[get_B_offset_abs(x_abs, -1, 0, 0, 2)];
        pB01011[lane] = inB0[get_B_offset_abs(x_abs, 0, -1, 0, 0)];
        pB11101[lane] = inB0[get_B_offset_abs(x_abs, -1, 0, 0, 1)];
    }

    __mem0__ v8fp64 xo0_vec __attribute__((aligned(64)));
    for (int lane = 0; lane < VEC_WIDTH; ++lane) {
        long long x_abs = x_start + lane;
        double xo0 = gxoffset + (x_abs - 1);
        ((double*)&xo0_vec)[lane] = xo0;
    }

    v8fp64 x0_vec, DT_vec;
    for (int lane = 0; lane < VEC_WIDTH; ++lane) {
        ((double*)&x0_vec)[lane] = x0;
        ((double*)&DT_vec)[lane] = DT;
    }

    __mem0__ GeoCoeffs coeffs;
    coeffs.inv_DELTA_X = inv_DELTA_X;
    coeffs.inv_DELTA_Y = inv_DELTA_Y;
    coeffs.inv_DELTA_Z = inv_DELTA_Z;
    coeffs.DELTA_X = DELTA_X;
    coeffs.DELTA_Y = DELTA_Y;
    coeffs.DELTA_Z = DELTA_Z;
    coeffs.x0 = x0;
    
    v8fp64 Ex_vec, Ey_vec, Ez_vec;

    MPU_SYNC();
    mpu_GEO_update_Ex(&Ex_vec, vB10111, vB11111, vB21011, vB21111,
                  xo0_vec, DT_vec, &coeffs);
    mpu_GEO_update_Ey(&Ey_vec, vB00111, vB01111, vB21101, vB21111,
                  xo0_vec, DT_vec, &coeffs);
    mpu_GEO_update_Ez(&Ez_vec, vB01011, vB01111, vB11101, vB11111,
                  xo0_vec, DT_vec, &coeffs);
    MPU_SYNC();

	auto get_E_offset = [&](int comp) -> size_t {
		long long x_idx = x_start + ovlp;
		long long y_idx = xyzy + ovlp;
		long long z_idx = xyzz + ovlp;
		return blk_offset + comp + num_ele * (x_idx + xblock * (y_idx + yblock * z_idx));
	};
	
	long long e0_base = get_E_offset(0);
	long long e1_base = get_E_offset(1);
	long long e2_base = get_E_offset(2);

	for (int lane = 0; lane < actual_width; ++lane) 
    {
		long long offset = lane * num_ele; 
		inoutE1[e0_base + offset] += ((double*)&Ex_vec)[lane];
		inoutE1[e1_base + offset] += ((double*)&Ey_vec)[lane];
		inoutE1[e2_base + offset] += ((double*)&Ez_vec)[lane];
	}

#endif
}


__device__ KERNEL_M void mpu_R_update_Ex(
    v8fp64* Ex_out,
    v8fp64 vB11111, v8fp64 vB12111, v8fp64 vB21111, v8fp64 vB21211,
    v8fp64 DT_vec)
{
    *Ex_out = DT_vec * (-vB11111 + vB12111 + vB21111 - vB21211);
}

__device__ KERNEL_M void mpu_R_update_Ey(
    v8fp64* Ey_out, 
    v8fp64 vB21111, v8fp64 vB01111, v8fp64 vB02111, v8fp64 vB21121,
    v8fp64 DT_vec)
{
    *Ey_out = DT_vec * ( vB01111 - vB02111 - vB21111 + vB21121);
}

__device__ KERNEL_M void mpu_R_update_Ez(
    v8fp64* Ez_out,
    v8fp64 vB11111, v8fp64 vB01111, v8fp64 vB01211, v8fp64 vB11121,
    v8fp64 DT_vec)
{
    *Ez_out = DT_vec * (-vB01111 + vB01211 + vB11111 - vB11121);
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

    int tid = (blockIdx.x + blockIdx.y * gridDim.x) * blockDim.x + threadIdx.x;
    long long X_segments = (XLEN + VEC_WIDTH - 1) / VEC_WIDTH;
    long long total_per_xy = YLEN * ZLEN;
    long long total_per_i = total_per_xy * X_segments;

    long long idx = tid;
    long long x_seg = idx % X_segments;
    long long tmp = idx / X_segments;
    long long i = tmp / total_per_xy;
    long long rem = tmp % total_per_xy;
    long long xyzy = rem / ZLEN;
    long long xyzz = rem % ZLEN;

    if (i >= numvec || xyzy >= YLEN || xyzz >= ZLEN) return;

    double gxoffset = (double)(xoffset[i]);

    long long blk_all_len_nonele = xblock * yblock * zblock;
    long long blk_offset = blk_all_len_nonele * (i * num_ele);

    long long x_start = x_seg * VEC_WIDTH;
    if (x_start >= XLEN) return;
    long long actual_width = (x_start + VEC_WIDTH <= XLEN) ? VEC_WIDTH : (XLEN - x_start);

    __mem0__ v8fp64 vB11111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB12111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB21111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB21211 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB01111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB02111 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB21121 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB01211 __attribute__((aligned(64)));
    __mem0__ v8fp64 vB11121 __attribute__((aligned(64)));
	
    auto get_B_offset_abs = [&](long long x_abs, int dx, int dy, int dz, int comp) -> size_t {
        long long x_idx = x_abs + dx + ovlp;
        long long y_idx = xyzy + dy + ovlp;
        long long z_idx = xyzz + dz + ovlp;
        return blk_offset + comp + num_ele * (x_idx + xblock * (y_idx + yblock * z_idx));
    };

    double* pB11111 = (double*)&vB11111;
    double* pB12111 = (double*)&vB12111;
    double* pB21111 = (double*)&vB21111;
    double* pB21211 = (double*)&vB21211;
    double* pB01111 = (double*)&vB01111;
    double* pB02111 = (double*)&vB02111;
    double* pB21121 = (double*)&vB21121;
    double* pB01211 = (double*)&vB01211;
    double* pB11121 = (double*)&vB11121;

    for (int lane = 0; lane < actual_width; ++lane) {
        long long x_abs = x_start + lane;
        pB11111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 0, 1)];
        pB12111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 1, 1)];
        pB21111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 0, 2)];
        pB21211[lane] = inB0[get_B_offset_abs(x_abs, 0, 1, 0, 2)];
        pB01111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 0, 0)];
        pB02111[lane] = inB0[get_B_offset_abs(x_abs, 0, 0, 1, 0)];
        pB21121[lane] = inB0[get_B_offset_abs(x_abs, 1, 0, 0, 2)];
        pB01211[lane] = inB0[get_B_offset_abs(x_abs, 0, 1, 0, 0)];
        pB11121[lane] = inB0[get_B_offset_abs(x_abs, 1, 0, 0, 1)];
    }

    v8fp64 DT_vec;
    for (int lane = 0; lane < VEC_WIDTH; ++lane) ((double*)&DT_vec)[lane] = DT;

    v8fp64 Ex_vec, Ey_vec, Ez_vec;

    MPU_SYNC();
    mpu_R_update_Ex(&Ex_vec, vB11111, vB12111, vB21111, vB21211, DT_vec);
    mpu_R_update_Ey(&Ey_vec, vB21111, vB01111, vB02111, vB21121, DT_vec);
    mpu_R_update_Ez(&Ez_vec, vB11111, vB01111, vB01211, vB11121, DT_vec);
    MPU_SYNC();

	auto get_E_offset = [&](int comp) -> size_t {
		long long x_idx = x_start + ovlp;
		long long y_idx = xyzy + ovlp;
		long long z_idx = xyzz + ovlp;
		return blk_offset + comp + num_ele * (x_idx + xblock * (y_idx + yblock * z_idx));
	};
	
	long long e0_base = get_E_offset(0);
	long long e1_base = get_E_offset(1);
	long long e2_base = get_E_offset(2);

	for (int lane = 0; lane < actual_width; ++lane) {
		long long offset = lane * num_ele; 
		inoutE1[e0_base + offset] += ((double*)&Ex_vec)[lane];
		inoutE1[e1_base + offset] += ((double*)&Ey_vec)[lane];
		inoutE1[e2_base + offset] += ((double*)&Ez_vec)[lane];
	}

#endif
}
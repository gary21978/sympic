#include <math.h>
#include <scale.h>
#include <maps_runtime.h>
#define MAPU_LONG long long
#ifdef __SCALE_ARCH__
#include <scale/barrier>
#include <cooperative_groups.h>
#ifdef USE_LLCD
//typedef long long MAPU_LONG;
#include <aurora.h>
#include <aurora_s-intrin.h>
#include <llcdsc/inc/dma.h>
#endif
#else
#include <aurora.h>
#include <stdlib.h>
//#define MAPU_LONG long long
#endif

//using namespace std;

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

__device__ static KERNEL_M v8fp64 v8fp64_setr(double  a0, double  a1, double  a2, double  a3, double  a4, double  a5, double  a6, double  a7) {

	v8fp64 ret = { a0,a1,a2,a3,a4,a5,a6,a7 };
	return  ret;
}
#define floor mapu_floor_df
#define log mapu_log_df
__device__ static KERNEL_M v8fp64 geo_floor_simd(v8fp64  input) {
	v8fp64  ret;
	double* pret = (double*)&(ret);
	double* pinput = (double*)&(input);
	int  g;
	for ((g = 0); (g < 8); (g = (g + 1)))
	{
		((pret)[g] = floor((pinput)[g]));
	}	return  ret;
}
#endif

#define IDX_OPT_MAX 1

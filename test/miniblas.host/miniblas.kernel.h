#include "basic.h"
#include <scale.h>
#include <maps_runtime.h>

#define MAPU_LONG long long
#define IDX_OPT_MAX 1 

__global__ void mapu_blas_axpy(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele);
__global__ void mapu_blas_yisax(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele);
__global__ void mapu_blas_yisax_enlarge(__DDR double *y, __DDR double *x, double a, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele);
__global__ void mapu_blas_yiszero_synced(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele);
__global__ void mapu_blas_yiszero(__DDR double *y, MAPU_LONG y_cpu_core, MAPU_LONG numvec, MAPU_LONG XLEN, MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG xblock, MAPU_LONG yblock, MAPU_LONG zblock, int num_ele);
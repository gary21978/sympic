#include <scale.h>  

extern __global__ void mapu_YEE_CURL_R(__DDR double *inoutE1, __DDR double *inB0,
                                       __DDR int *xoffset, __DDR int *yoffset, __DDR int *zoffset,
                                       long long y_cpu_core, long long numvec,
                                       long long XLEN, long long YLEN, long long ZLEN,
                                       int ovlp, long long xblock, long long yblock, long long zblock,
                                       int num_ele, double DT);

extern __global__ void mapu_GEO_YEE_CURL_L(__DDR double *inoutE1, __DDR double *inB0,
                                           __DDR int *xoffset, __DDR int *yoffset, __DDR int *zoffset,
                                           long long y_cpu_core, long long numvec,
                                           long long XLEN, long long YLEN, long long ZLEN,
                                           int ovlp, long long xblock, long long yblock, long long zblock,
                                           int num_ele, double DT, double DELTA_Z, double DELTA_Y,
                                           double DELTA_X, double x0, double r0);


#ifndef __SCALE_ARCH__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <maps_runtime.h>

int main() {
   
    const long long XLEN = 2, YLEN = 2, ZLEN = 2;
    const int ovlp = 1;
    const long long xblock = XLEN + 2 * ovlp;  // 4
    const long long yblock = YLEN + 2 * ovlp;  // 4
    const long long zblock = ZLEN + 2 * ovlp;  // 4
    const int num_ele = 3;
    const double DT = 0.1;
    const double DELTA_X = 1.0, DELTA_Y = 1.0, DELTA_Z = 1.0;
    const double x0 = 2.0, r0 = 1.0;

    const long long numvec = 1;
    const long long y_cpu_core = 1;
    int h_xoffset[1] = {0};
    int h_yoffset[1] = {0};
    int h_zoffset[1] = {0};

    const size_t total_size = num_ele * xblock * yblock * zblock;
    double *h_B0 = (double*)calloc(total_size, sizeof(double));
    double *h_E1 = (double*)calloc(total_size, sizeof(double));
    if (!h_B0 || !h_E1) {
        fprintf(stderr, "Host memory allocation failed\n");
        return 1;
    }

 
    for (int iz = 0; iz < ZLEN; ++iz) {
        for (int iy = 0; iy < YLEN; ++iy) {
            for (int ix = 0; ix < XLEN; ++ix) {
                int base = (iz * YLEN + iy) * XLEN + ix;
                int gx = ix + ovlp;
                int gy = iy + ovlp;
                int gz = iz + ovlp;
                h_B0[0 + num_ele * (gx + xblock * (gy + yblock * gz))] = (double)(base * 3 + 1);
                h_B0[1 + num_ele * (gx + xblock * (gy + yblock * gz))] = (double)(base * 3 + 2);
                h_B0[2 + num_ele * (gx + xblock * (gy + yblock * gz))] = (double)(base * 3 + 3);
            }
        }
    }

   
    double *d_B0, *d_E1;
    int *d_xoffset, *d_yoffset, *d_zoffset;
    mapsMalloc((void**)&d_B0, total_size * sizeof(double));
    mapsMalloc((void**)&d_E1, total_size * sizeof(double));
    mapsMalloc((void**)&d_xoffset, numvec * sizeof(int));
    mapsMalloc((void**)&d_yoffset, numvec * sizeof(int));
    mapsMalloc((void**)&d_zoffset, numvec * sizeof(int));

    
    mapsMemcpy(d_B0, h_B0, total_size * sizeof(double), mapsMemcpyHostToDevice);
    mapsMemcpy(d_xoffset, h_xoffset, numvec * sizeof(int), mapsMemcpyHostToDevice);
    mapsMemcpy(d_yoffset, h_yoffset, numvec * sizeof(int), mapsMemcpyHostToDevice);
    mapsMemcpy(d_zoffset, h_zoffset, numvec * sizeof(int), mapsMemcpyHostToDevice);

   
    double *h_zero = (double*)calloc(total_size, sizeof(double));
    mapsMemcpy(d_E1, h_zero, total_size*sizeof(double), mapsMemcpyHostToDevice);
    free(h_zero);

  
    int grid_size = 1;
    int block_size = 1;

    printf("=== Testing mapu_YEE_CURL_R ===\n");
    double *h_zero2 = (double*)calloc(total_size, sizeof(double));
    mapsMemcpy(d_E1, h_zero2, total_size*sizeof(double), mapsMemcpyHostToDevice);
    free(h_zero2);
    mapu_YEE_CURL_R<<<grid_size, block_size>>>((__DDR double*)d_E1, (__DDR double*)d_B0,
                                                (__DDR int*)d_xoffset, (__DDR int*)d_yoffset, (__DDR int*)d_zoffset,
                                                y_cpu_core, numvec, XLEN, YLEN, ZLEN,
                                                ovlp, xblock, yblock, zblock, num_ele, DT);
    mapsDeviceSynchronize();

    mapsMemcpy(h_E1, d_E1, total_size * sizeof(double), mapsMemcpyDeviceToHost);

 
    const double expected_R[8][3] = {
        { 0.6, -0.9,  0.3},
        { 0.6, -1.8,  1.1},
        { 2.1, -0.9, -1.0},
        { 2.4, -2.4,  0.1},
        {-2.0,  1.6,  0.3},
        {-2.3, -0.2,  2.3},
        { 0.1,  2.2, -2.2},
        { 0.1, -0.2,  0.1}
    };
    bool ok_R = true;
    for (int iz = 0; iz < ZLEN; ++iz) {
        for (int iy = 0; iy < YLEN; ++iy) {
            for (int ix = 0; ix < XLEN; ++ix) {
                int gx = ix + ovlp;
                int gy = iy + ovlp;
                int gz = iz + ovlp;
                int idx = iz * YLEN * XLEN + iy * XLEN + ix;
                double ex = h_E1[0 + num_ele * (gx + xblock * (gy + yblock * gz))];
                double ey = h_E1[1 + num_ele * (gx + xblock * (gy + yblock * gz))];
                double ez = h_E1[2 + num_ele * (gx + xblock * (gy + yblock * gz))];
                if (fabs(ex - expected_R[idx][0]) > 1e-10 ||
                    fabs(ey - expected_R[idx][1]) > 1e-10 ||
                    fabs(ez - expected_R[idx][2]) > 1e-10) {
                    printf("R kernel mismatch at (%d,%d,%d): got (%f,%f,%f) expected (%f,%f,%f)\n",
                           ix, iy, iz, ex, ey, ez,
                           expected_R[idx][0], expected_R[idx][1], expected_R[idx][2]);
                    ok_R = false;
                }
            }
        }
    }
    printf("R kernel test %s\n\n", ok_R ? "PASS" : "FAIL");

    printf("=== Testing mapu_GEO_YEE_CURL_L ===\n");
    double *h_zero3 = (double*)calloc(total_size, sizeof(double));
    mapsMemcpy(d_E1, h_zero3, total_size*sizeof(double), mapsMemcpyHostToDevice);
    free(h_zero3);
    mapu_GEO_YEE_CURL_L<<<grid_size, block_size>>>((__DDR double*)d_E1, (__DDR double*)d_B0,
                                                    (__DDR int*)d_xoffset, (__DDR int*)d_yoffset, (__DDR int*)d_zoffset,
                                                    y_cpu_core, numvec, XLEN, YLEN, ZLEN,
                                                    ovlp, xblock, yblock, zblock, num_ele, DT,
                                                    DELTA_Z, DELTA_Y, DELTA_X, x0, r0);
    mapsDeviceSynchronize();
    mapsMemcpy(h_E1, d_E1, total_size * sizeof(double), mapsMemcpyDeviceToHost);

    const double expected_L[8][3] = {
        { 0.1, -0.2,  0.1},
        {-0.2333333333,  0.25, 0.1888888889},
        {-0.2, -0.2,  0.2},
        {-0.8333333333,  1.15, 0.3},
        { 0.3, -0.3,  0.1},
        {-0.4,  1.65, 0.0555555556},
        {-0.6, -0.9,  1.4},
        {-0.9333333333,  1.95, 0.7}
    };
    bool ok_L = true;
    for (int iz = 0; iz < ZLEN; ++iz) {
        for (int iy = 0; iy < YLEN; ++iy) {
            for (int ix = 0; ix < XLEN; ++ix) {
                int gx = ix + ovlp;
                int gy = iy + ovlp;
                int gz = iz + ovlp;
                int idx = iz * YLEN * XLEN + iy * XLEN + ix;
                double ex = h_E1[0 + num_ele * (gx + xblock * (gy + yblock * gz))];
                double ey = h_E1[1 + num_ele * (gx + xblock * (gy + yblock * gz))];
                double ez = h_E1[2 + num_ele * (gx + xblock * (gy + yblock * gz))];
                if (fabs(ex - expected_L[idx][0]) > 1e-10 ||
                    fabs(ey - expected_L[idx][1]) > 1e-10 ||
                    fabs(ez - expected_L[idx][2]) > 1e-10) {
                    printf("L kernel mismatch at (%d,%d,%d): got (%f,%f,%f) expected (%f,%f,%f)\n",
                           ix, iy, iz, ex, ey, ez,
                           expected_L[idx][0], expected_L[idx][1], expected_L[idx][2]);
                    ok_L = false;
                }
            }
        }
    }
    printf("GEO L kernel test %s\n", ok_L ? "PASS" : "FAIL");

    // 清理资源
    mapsFree(d_B0);
    mapsFree(d_E1);
    mapsFree(d_xoffset);
    mapsFree(d_yoffset);
    mapsFree(d_zoffset);
    free(h_B0);
    free(h_E1);

    return (ok_R && ok_L) ? 0 : 1;
}
#endif

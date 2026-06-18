
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32
__global__ void cuda_Yee_FDTD_Curl_E(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                     long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                     double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] -=
                       (DT * ((((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] -=
                         (DT * ((((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] -=
                           (DT *
                            ((((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                             (((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));
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
__global__ void cuda_Yee_FDTD_Curl_E_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                         long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                         int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] -=
                       (DT * ((1.12500000000000000e+00 *
                               ((((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                              (((((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (2 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))])) /
                               24))));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] -=
                         (DT *
                          ((1.12500000000000000e+00 *
                            ((((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                           (((((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (2 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))]) -
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 2) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + -1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                            24))));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] -=
                           (DT *
                            ((1.12500000000000000e+00 *
                              ((((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + 1) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                             (((((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + 2) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + -1) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                              24))));
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
__global__ void cuda_Yee_FDTD_Curl_B(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                     long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                     double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] -=
                       (DT * ((((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] -=
                         (DT * ((((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + -1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] -=
                           (DT *
                            ((((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + -1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                             (((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));
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
__global__ void cuda_Yee_FDTD_Curl_B_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                         long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                         int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] -=
                       (DT * ((1.12500000000000000e+00 *
                               ((((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                              (((((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((-2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-2 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))])) /
                               24))));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] -=
                         (DT *
                          ((1.12500000000000000e+00 *
                            ((((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + -1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                           (((((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (-2 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))]) -
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + -2) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                            24))));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] -=
                           (DT *
                            ((1.12500000000000000e+00 *
                              ((((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + -1) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                             (((((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + -2) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    1 + (num_ele * (((xidx + ovlp) + 1) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((-2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                              24))));
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
__global__ void cuda_Yee_FDTD_Grad_BWD(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                       long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                       double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           (((inEB + blk_offset_t1))[(
                                0 + (num_ele * (((xidx + ovlp) + -1) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                            ((inEB + blk_offset_t1))[(
                                0 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             (((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]));
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
__global__ void cuda_Yee_FDTD_Grad_BWD_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                           long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                           int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           ((1.12500000000000000e+00 *
                             (((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + -1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) -
                            ((((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + -2) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) /
                             24)));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             ((1.12500000000000000e+00 *
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) -
                              ((((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((-2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) /
                               24)));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               ((1.12500000000000000e+00 *
                                 (((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                                  ((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) -
                                ((((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (-2 + (xyzz + ovlp))))))))] -
                                  ((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))]) /
                                 24)));
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
__global__ void cuda_Yee_FDTD_Grad_FWD(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                       long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                       double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           (((inEB + blk_offset_t1))[(
                                0 + (num_ele * (((xidx + ovlp) + 1) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                            ((inEB + blk_offset_t1))[(
                                0 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             (((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]));
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
__global__ void cuda_Yee_FDTD_Grad_FWD_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                           long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                           int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           ((1.12500000000000000e+00 *
                             (((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) -
                            ((((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + 2) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  0 + (num_ele * (((xidx + ovlp) + -1) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) /
                             24)));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             ((1.12500000000000000e+00 *
                               (((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) -
                              ((((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                ((inEB + blk_offset_t1))[(
                                    0 + (num_ele * (((xidx + ovlp) + 0) +
                                                    (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) /
                               24)));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               ((1.12500000000000000e+00 *
                                 (((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                                  ((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) -
                                ((((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (2 + (xyzz + ovlp))))))))] -
                                  ((inEB + blk_offset_t1))[(
                                      0 + (num_ele * (((xidx + ovlp) + 0) +
                                                      (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))]) /
                                 24)));
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
__global__ void cuda_Yee_FDTD_Curl_BWD(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                       long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                       double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           ((((inEB + blk_offset_t1))[(
                                 2 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 2 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                            (((inEB + blk_offset_t1))[(
                                 1 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 1 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             ((((inEB + blk_offset_t1))[(
                                   0 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   0 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + -1) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               ((((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + -1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])));
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
__global__ void cuda_Yee_FDTD_Curl_BWD_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                           long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                           int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           ((1.12500000000000000e+00 *
                             ((((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                            (((((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((-2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (-2 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))])) /
                             24)));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             ((1.12500000000000000e+00 *
                               ((((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + -1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                              (((((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-2 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + -2) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                               24)));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               ((1.12500000000000000e+00 *
                                 ((((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + -1) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                  (((inEB + blk_offset_t1))[(
                                       0 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB +
                                     blk_offset_t1))[(0 + (num_ele * (((xidx + ovlp) + 0) +
                                                                      (xb * ((0 + (xyzy + ovlp)) +
                                                                             (yb * (0 + (xyzz + ovlp))))))))]))) -
                                (((((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + -2) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + 1) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                  (((inEB + blk_offset_t1))[(
                                       0 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((-2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB + blk_offset_t1))[(
                                       0 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                                 24)));
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
__global__ void cuda_Yee_FDTD_Curl_FWD(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                       long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                       double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           ((((inEB + blk_offset_t1))[(
                                 2 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 2 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                            (((inEB + blk_offset_t1))[(
                                 1 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 1 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             ((((inEB + blk_offset_t1))[(
                                   0 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   0 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 1) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               ((((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     1 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])));
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
__global__ void cuda_Yee_FDTD_Curl_FWD_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                           long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                           int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    if (l == 0) {
                      ((outEB)[(blk_offset + realidx)] =
                           ((1.12500000000000000e+00 *
                             ((((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                            (((((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   2 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                              (((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (2 + (xyzz + ovlp))))))))] -
                               ((inEB + blk_offset_t1))[(
                                   1 + (num_ele * (((xidx + ovlp) + 0) +
                                                   (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))])) /
                             24)));

                    } else {
                      if (l == 1) {
                        ((outEB)[(blk_offset + realidx)] =
                             ((1.12500000000000000e+00 *
                               ((((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))) -
                              (((((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (2 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     0 + (num_ele * (((xidx + ovlp) + 0) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))]) -
                                (((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + 2) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                 ((inEB + blk_offset_t1))[(
                                     2 + (num_ele * (((xidx + ovlp) + -1) +
                                                     (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) /
                               24)));

                      } else {
                        if (l == 2) {
                          ((outEB)[(blk_offset + realidx)] =
                               ((1.12500000000000000e+00 *
                                 ((((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + 1) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                  (((inEB + blk_offset_t1))[(
                                       0 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB +
                                     blk_offset_t1))[(0 + (num_ele * (((xidx + ovlp) + 0) +
                                                                      (xb * ((0 + (xyzy + ovlp)) +
                                                                             (yb * (0 + (xyzz + ovlp))))))))]))) -
                                (((((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + 2) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB + blk_offset_t1))[(
                                       1 + (num_ele * (((xidx + ovlp) + -1) +
                                                       (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                                  (((inEB + blk_offset_t1))[(
                                       0 + (num_ele * (((xidx + ovlp) + 0) +
                                                       (xb * ((2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                                   ((inEB + blk_offset_t1))[(
                                       0 + (num_ele * (((xidx + ovlp) + 0) + (xb * ((-1 + (xyzy + ovlp)) +
                                                                                    (yb * (0 + (xyzz + ovlp))))))))])) /
                                 24)));
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
__global__ void cuda_Yee_FDTD_Div_BWD(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                      long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                      double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < XLEN); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long xidx = realidx;

                    (realidx = (realidx * num_ele));
                    ((outEB)[(blk_offset + realidx)] =
                         ((((inEB + blk_offset_t1))[(
                               0 + (num_ele * (((xidx + ovlp) + -1) +
                                               (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                           ((inEB + blk_offset_t1))[(
                               0 + (num_ele * (((xidx + ovlp) + 0) +
                                               (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                          ((((inEB + blk_offset_t1))[(
                                1 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                            ((inEB + blk_offset_t1))[(
                                1 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                           (((inEB + blk_offset_t1))[(
                                2 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                            ((inEB + blk_offset_t1))[(
                                2 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));
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
__global__ void cuda_Yee_FDTD_Div_BWD_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                          long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                          int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < XLEN); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long xidx = realidx;

                    (realidx = (realidx * num_ele));
                    ((outEB)[(blk_offset + realidx)] =
                         ((1.12500000000000000e+00 *
                           ((((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + -1) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                            ((((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))) -
                          (((((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + -2) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + 1) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                            ((((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((-2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (-2 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))]))) /
                           24)));
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
__global__ void cuda_Yee_FDTD_Div_FWD(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                      long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                      double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < XLEN); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long xidx = realidx;

                    (realidx = (realidx * num_ele));
                    ((outEB)[(blk_offset + realidx)] =
                         ((((inEB + blk_offset_t1))[(
                               0 + (num_ele * (((xidx + ovlp) + 1) +
                                               (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                           ((inEB + blk_offset_t1))[(
                               0 + (num_ele * (((xidx + ovlp) + 0) +
                                               (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                          ((((inEB + blk_offset_t1))[(
                                1 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                            ((inEB + blk_offset_t1))[(
                                1 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                           (((inEB + blk_offset_t1))[(
                                2 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                            ((inEB + blk_offset_t1))[(
                                2 + (num_ele * (((xidx + ovlp) + 0) +
                                                (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]))));
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
__global__ void cuda_Yee_FDTD_Div_FWD_4th(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN,
                                          long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
                                          int num_ele, double DT) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  for ((i = local_ymin); (i < local_ymax); i++) {

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < XLEN); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long xidx = realidx;

                    (realidx = (realidx * num_ele));
                    ((outEB)[(blk_offset + realidx)] =
                         ((1.12500000000000000e+00 *
                           ((((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + 1) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + 0) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                            ((((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))) -
                          (((((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + 2) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                             ((inEB + blk_offset_t1))[(
                                 0 + (num_ele * (((xidx + ovlp) + -1) +
                                                 (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                            ((((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((2 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  1 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) +
                             (((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (2 + (xyzz + ovlp))))))))] -
                              ((inEB + blk_offset_t1))[(
                                  2 + (num_ele * (((xidx + ovlp) + 0) +
                                                  (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))]))) /
                           24)));
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
__global__ void cuda_merge_current_2(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                     long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele) {

  const long pscmc_num_compute_units = (gridDim.x * gridDim.y);

  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long ori_num_ele = (num_ele * pscmc_num_compute_units);

  long blk_all_len = (xblock * (yblock * (zblock * ori_num_ele)));

  long blk_len = (xblock * (yblock * zblock));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {

      if (__idx == 0) {
        {
          long lg;

          for ((lg = 0); (lg < blk_len); (lg = (lg + 1))) {
            long g = lg;

            long xx = (g % xblock);

            long xy = ((g / xblock) % yblock);

            long xz = (g / (xblock * yblock));

            long blk_offset = (blk_all_len * i);

            {
              long ig;

              for ((ig = 0); (ig < num_ele); (ig = (ig + 1))) {
                double lst_n0 = 0;

                long new_allid = (ig + (num_ele * (xx + (xblock * (xy + (yblock * xz))))));

                {
                  long il;

                  for ((il = 0); (il < pscmc_num_compute_units); (il = (il + 1))) {
                    long ori_allid = (new_allid + (il * (blk_len * num_ele)));

                    (lst_n0 = (lst_n0 + (inEB)[(ori_allid + blk_offset)]));
                  }
                }
                ((outEB)[(new_allid + (blk_len * (i * num_ele)))] = lst_n0);
              }
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_merge_current(double *outEB, double *inEB, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                   long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long blk_all_len = (xblock * (yblock * (zblock * 375)));

  long blk_len = (xblock * (yblock * zblock));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long lg = 0;

      if (__idx == 0) {
        for ((lg = 0); (lg < blk_len); (lg = (lg + 1))) {
          long g = lg;

          long xx = (g % xblock);

          long xy = ((g / xblock) % yblock);

          long xz = (g / (xblock * yblock));

          long blk_offset = (blk_all_len * i);

          double jx = 0;

          double jy = 0;

          double jz = 0;

          {
            long xyzz;

            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                      long local_all_id = (xyzx + (5 * (xyzy + (5 * xyzz))));

                      long curx = ((2 - xyzx) + xx);

                      long cury = ((2 - xyzy) + xy);

                      long curz = ((2 - xyzz) + xz);

                      long final_all_id = (local_all_id + (375 * (curx + (xblock * (cury + (yblock * curz))))));

                      if (((curx >= ovlp) && ((curx < (xblock - ovlp)) &&
                                              ((cury >= ovlp) && ((cury < (yblock - ovlp)) &&
                                                                  ((curz >= ovlp) && (curz < (zblock - ovlp)))))))) {
                        (jx = (jx + ((inEB + blk_offset))[(final_all_id + 0)]));
                        (jy = (jy + ((inEB + blk_offset))[(final_all_id + 125)]));
                        (jz = (jz + ((inEB + blk_offset))[(final_all_id + 250)]));
                      }
                    }
                  }
                }
              }
            }
          }
          long offset_idx = (xblock * (yblock * (zblock * (3 * i))));

          ((outEB)[(offset_idx + ((3 * g) + 0))] = jx);
          ((outEB)[(offset_idx + ((3 * g) + 1))] = jy);
          ((outEB)[(offset_idx + ((3 * g) + 2))] = jz);
        }
      }
    }
  }
}
__global__ void cuda_PML_FDTD_CURL_FWD(double *outEB, double *inEB, double *outPMLEB, double *inPMLEB, int *xoffset,
                                       int *yoffset, int *zoffset, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                       long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                       double DT, double M, double Q, double DX, double DY, double DZ, int abc_dir,
                                       int level, int pml_m, double max_sigma, long allxmax, long allymax,
                                       long allzmax) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long blk_all_len = (xblock * (yblock * (zblock * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long allmax = (XLEN * (YLEN * ZLEN));

      long g = 0;

      int xoffi = (xoffset)[i];

      int yoffi = (yoffset)[i];

      int zoffi = (zoffset)[i];

      int x_use_abc = (abc_dir % 2);

      int y_use_abc = ((abc_dir / 2) % 2);

      int z_use_abc = ((abc_dir / 4) % 2);

      for ((g = 0); (g < allmax); (g = (g + 1))) {
        long xyzx = (g % XLEN);

        long xyzy = ((g / XLEN) % YLEN);

        long xyzz = (g / (XLEN * YLEN));


        if (__idx == 0) {
          long use_pml_calc = 0;

          long inner_pec = 0;

          double sigma_Ex = 0.00000000000000000e+00;

          double sigma_Ey = 0.00000000000000000e+00;

          double sigma_Ez = 0.00000000000000000e+00;

          long cur_x = (xoffi + xyzx);

          long cur_y = (yoffi + xyzy);

          long cur_z = (zoffi + xyzz);

          long xb = xblock;

          long yb = yblock;


          if (x_use_abc && ((cur_x < level) || (cur_x >= (allxmax - level)))) {
            double ocs = ((1.00000000000000000e+00 *
                           (((cur_x < level)) ? (((level - 1) - cur_x)) : ((cur_x - (allxmax - level))))) /
                          level);

            (sigma_Ex = (max_sigma * pow(ocs, (1.00000000000000000e+00 * pml_m))));
            (use_pml_calc = 1);
            if (cur_x == 0) {
              (inner_pec = 1);
            }
          }

          if (y_use_abc && ((cur_y < level) || (cur_y >= (allymax - level)))) {
            double ocs = ((1.00000000000000000e+00 *
                           (((cur_y < level)) ? (((level - 1) - cur_y)) : ((cur_y - (allymax - level))))) /
                          level);

            (sigma_Ey = (max_sigma * pow(ocs, (1.00000000000000000e+00 * pml_m))));
            (use_pml_calc = 1);
            if (cur_y == 0) {
              (inner_pec = 1);
            }
          }

          if (z_use_abc && ((cur_z < level) || (cur_z >= (allzmax - level)))) {
            double ocs = ((1.00000000000000000e+00 *
                           (((cur_z < level)) ? (((level - 1) - cur_z)) : ((cur_z - (allzmax - level))))) /
                          level);

            (sigma_Ez = (max_sigma * pow(ocs, (1.00000000000000000e+00 * pml_m))));
            (use_pml_calc = 1);
            if (cur_z == 0) {
              (inner_pec = 1);
            }
          }

          if (use_pml_calc) {
            if (inner_pec) {
              (((outEB + (blk_all_len * i)))[(
                   0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ey;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DY)) : (((1 - expsgmBt) / (sgmB * DY))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(2 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + 1) + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(2 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 1) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))]);

                (((outEB + (blk_all_len * i)))[(
                     0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outEB + (blk_all_len *
                                   i)))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                    (yblock * (xyzz + ovlp)))))))]) +
                       (1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outPMLEB + (blk_all_len * i)))[(
                   0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ez;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DZ)) : (((1 - expsgmBt) / (sgmB * DZ))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(1 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 1) + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(1 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len *
                        i)))[(1 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 1) + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len *
                        i)))[(1 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                (((outPMLEB + (blk_all_len * i)))[(
                     0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outPMLEB + (blk_all_len * i)))[(
                            0 + (num_ele *
                                 ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]) +
                       (-1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outEB + (blk_all_len * i)))[(
                   1 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ez;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DZ)) : (((1 - expsgmBt) / (sgmB * DZ))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 1) + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len *
                        i)))[(0 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 1) + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len *
                        i)))[(0 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                (((outEB + (blk_all_len * i)))[(
                     1 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outEB + (blk_all_len * i)))[(
                            1 + (num_ele *
                                 ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]) +
                       (1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outPMLEB + (blk_all_len * i)))[(
                   1 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ex;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DX)) : (((1 - expsgmBt) / (sgmB * DX))));

                double dceb_A =
                    (((inEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + 1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + 1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                (((outPMLEB + (blk_all_len * i)))[(
                     1 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outPMLEB + (blk_all_len *
                                      i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]) +
                       (-1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outEB + (blk_all_len * i)))[(
                   2 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ex;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DX)) : (((1 - expsgmBt) / (sgmB * DX))));

                double dceb_A =
                    (((inEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + 1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + 1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                (((outEB + (blk_all_len * i)))[(
                     2 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outEB + (blk_all_len *
                                   i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) +
                                                         (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]) +
                       (1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outPMLEB + (blk_all_len * i)))[(
                   2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ey;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DY)) : (((1 - expsgmBt) / (sgmB * DY))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + 1) + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 1) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))]);

                (((outPMLEB + (blk_all_len * i)))[(
                     2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outPMLEB + (blk_all_len *
                                      i)))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))]) +
                       (-1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

          } else {
            (((outEB +
               (blk_all_len *
                i)))[(0 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -=
             (DT *
              (((((inEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                 ((inEB + (i * blk_all_len)))[(
                     1 +
                     (num_ele * (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) +
               ((((inPMLEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inPMLEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                 ((inPMLEB + (i * blk_all_len)))[(
                     1 + (num_ele *
                          (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))));
            (((outEB +
               (blk_all_len *
                i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -=
             (DT *
              (((((inEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                 ((inEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB + (i * blk_all_len)))[(
                     2 +
                     (num_ele * (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) +
               ((((inPMLEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (1 + (xyzz + ovlp))))))))] -
                 ((inPMLEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inPMLEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB + (i * blk_all_len)))[(
                     2 + (num_ele *
                          (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))));
            (((outEB +
               (blk_all_len *
                i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -=
             (DT *
              (((((inEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB + (i * blk_all_len)))[(
                     0 +
                     (num_ele * (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) +
               ((((inPMLEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inPMLEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB + (i * blk_all_len)))[(
                     0 + (num_ele *
                          (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))));
          }
        }
      }
    }
  }
}
__global__ void cuda_PML_FDTD_CURL_BWD(double *outEB, double *inEB, double *outPMLEB, double *inPMLEB, int *xoffset,
                                       int *yoffset, int *zoffset, long y_cpu_core, long numvec, long XLEN, long YLEN,
                                       long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
                                       double DT, double M, double Q, double DX, double DY, double DZ, int abc_dir,
                                       int level, int pml_m, double max_sigma, long allxmax, long allymax,
                                       long allzmax) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long blk_all_len = (xblock * (yblock * (zblock * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long allmax = (XLEN * (YLEN * ZLEN));

      long g = 0;

      int xoffi = (xoffset)[i];

      int yoffi = (yoffset)[i];

      int zoffi = (zoffset)[i];

      int x_use_abc = (abc_dir % 2);

      int y_use_abc = ((abc_dir / 2) % 2);

      int z_use_abc = ((abc_dir / 4) % 2);

      for ((g = 0); (g < allmax); (g = (g + 1))) {
        long xyzx = (g % XLEN);

        long xyzy = ((g / XLEN) % YLEN);

        long xyzz = (g / (XLEN * YLEN));


        if (__idx == 0) {
          long use_pml_calc = 0;

          long inner_pec = 0;

          double sigma_Ex = 0.00000000000000000e+00;

          double sigma_Ey = 0.00000000000000000e+00;

          double sigma_Ez = 0.00000000000000000e+00;

          long cur_x = (xoffi + xyzx);

          long cur_y = (yoffi + xyzy);

          long cur_z = (zoffi + xyzz);

          long xb = xblock;

          long yb = yblock;


          if (x_use_abc && ((cur_x < level) || (cur_x >= (allxmax - level)))) {
            double ocs = ((1.00000000000000000e+00 *
                           (((cur_x < level)) ? (((level - 1) - cur_x)) : ((cur_x - (allxmax - level))))) /
                          level);

            (sigma_Ex = (max_sigma * pow(ocs, (1.00000000000000000e+00 * pml_m))));
            (use_pml_calc = 1);
            if (cur_x == 0) {
              (inner_pec = 1);
            }
          }

          if (y_use_abc && ((cur_y < level) || (cur_y >= (allymax - level)))) {
            double ocs = ((1.00000000000000000e+00 *
                           (((cur_y < level)) ? (((level - 1) - cur_y)) : ((cur_y - (allymax - level))))) /
                          level);

            (sigma_Ey = (max_sigma * pow(ocs, (1.00000000000000000e+00 * pml_m))));
            (use_pml_calc = 1);
            if (cur_y == 0) {
              (inner_pec = 1);
            }
          }

          if (z_use_abc && ((cur_z < level) || (cur_z >= (allzmax - level)))) {
            double ocs = ((1.00000000000000000e+00 *
                           (((cur_z < level)) ? (((level - 1) - cur_z)) : ((cur_z - (allzmax - level))))) /
                          level);

            (sigma_Ez = (max_sigma * pow(ocs, (1.00000000000000000e+00 * pml_m))));
            (use_pml_calc = 1);
            if (cur_z == 0) {
              (inner_pec = 1);
            }
          }

          if (use_pml_calc) {
            if (inner_pec) {
              (((outEB + (blk_all_len * i)))[(
                   0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ey;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DY)) : (((1 - expsgmBt) / (sgmB * DY))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(2 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + -1) + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(2 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + -1) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))]);

                (((outEB + (blk_all_len * i)))[(
                     0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outEB + (blk_all_len *
                                   i)))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                    (yblock * (xyzz + ovlp)))))))]) +
                       (1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outPMLEB + (blk_all_len * i)))[(
                   0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ez;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DZ)) : (((1 - expsgmBt) / (sgmB * DZ))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(1 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + -1) + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(1 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len *
                        i)))[(1 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + -1) + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len *
                        i)))[(1 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                (((outPMLEB + (blk_all_len * i)))[(
                     0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outPMLEB + (blk_all_len * i)))[(
                            0 + (num_ele *
                                 ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]) +
                       (-1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outEB + (blk_all_len * i)))[(
                   1 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ez;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DZ)) : (((1 - expsgmBt) / (sgmB * DZ))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + -1) + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len *
                        i)))[(0 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + -1) + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len *
                        i)))[(0 + (num_ele *
                                   ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]);

                (((outEB + (blk_all_len * i)))[(
                     1 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outEB + (blk_all_len * i)))[(
                            1 + (num_ele *
                                 ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * ((xyzz + 0) + ovlp)))))))]) +
                       (1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outPMLEB + (blk_all_len * i)))[(
                   1 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ex;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DX)) : (((1 - expsgmBt) / (sgmB * DX))));

                double dceb_A =
                    (((inEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + -1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + -1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                (((outPMLEB + (blk_all_len * i)))[(
                     1 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outPMLEB + (blk_all_len *
                                      i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]) +
                       (-1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outEB + (blk_all_len * i)))[(
                   2 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ex;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DX)) : (((1 - expsgmBt) / (sgmB * DX))));

                double dceb_A =
                    (((inEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + -1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + -1) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) +
                                                            (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                (((outEB + (blk_all_len * i)))[(
                     2 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outEB + (blk_all_len *
                                   i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) +
                                                         (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))]) +
                       (1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

            if (inner_pec) {
              (((outPMLEB + (blk_all_len * i)))[(
                   2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] = 0);

            } else {
              {
                double sgmB = sigma_Ey;

                double expsgmBt = exp(-((DT * sgmB)));

                double mesgbosgbdb = (((sgmB == 0)) ? ((DT / DY)) : (((1 - expsgmBt) / (sgmB * DY))));

                double dceb_A =
                    (((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + -1) + ovlp) + (yblock * (xyzz + ovlp)))))))] -
                     ((inEB + (blk_all_len *
                               i)))[(0 + (num_ele * ((xyzx + ovlp) +
                                                     (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))]);

                double dceb_B =
                    (((inPMLEB +
                       (blk_all_len * i)))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + -1) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))] -
                     ((inPMLEB +
                       (blk_all_len * i)))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))]);

                (((outPMLEB + (blk_all_len * i)))[(
                     2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                     (1.00000000000000000e+00 *
                      ((expsgmBt *
                        ((outPMLEB + (blk_all_len *
                                      i)))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * (((xyzy + 0) + ovlp) +
                                                                                       (yblock * (xyzz + ovlp)))))))]) +
                       (-1 * (-1 * (mesgbosgbdb * (dceb_A + dceb_B)))))));
              }
            }

          } else {
            (((outEB +
               (blk_all_len *
                i)))[(0 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -=
             (DT *
              (((((inEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                 ((inEB + (i * blk_all_len)))[(
                     1 +
                     (num_ele * (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) +
               ((((inPMLEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inPMLEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                 ((inPMLEB + (i * blk_all_len)))[(
                     1 + (num_ele *
                          (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))));
            (((outEB +
               (blk_all_len *
                i)))[(1 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -=
             (DT *
              (((((inEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                 ((inEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + -1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB + (i * blk_all_len)))[(
                     2 +
                     (num_ele * (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) +
               ((((inPMLEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (-1 + (xyzz + ovlp))))))))] -
                 ((inPMLEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inPMLEB +
                   (i * blk_all_len)))[(2 + (num_ele * (((xyzx + ovlp) + -1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB + (i * blk_all_len)))[(
                     2 + (num_ele *
                          (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))));
            (((outEB +
               (blk_all_len *
                i)))[(2 + (num_ele * (((xyzx + 0) + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] -=
             (DT *
              (((((inEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + -1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inEB + (i * blk_all_len)))[(
                     0 +
                     (num_ele * (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])) +
               ((((inPMLEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + -1) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB +
                   (i * blk_all_len)))[(1 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))]) -
                (((inPMLEB +
                   (i * blk_all_len)))[(0 + (num_ele * (((xyzx + ovlp) + 0) +
                                                        (xb * ((-1 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))] -
                 ((inPMLEB + (i * blk_all_len)))[(
                     0 + (num_ele *
                          (((xyzx + ovlp) + 0) + (xb * ((0 + (xyzy + ovlp)) + (yb * (0 + (xyzz + ovlp))))))))])))));
          }
        }
      }
    }
  }
}
__global__ void cuda_kgm_calc_rho(double *outEB, double *inEB, int *xoffset, int *yoffset, int *zoffset,
                                  long y_cpu_core, long numvec, long XLEN, long YLEN, long ZLEN, int ovlp, long xblock,
                                  long yblock, long zblock, int num_ele, double DT, double M, double Q, double DX,
                                  double refz0, double q, double dtodx, int mode, int swap_input) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long blk_all_len = (xblock * (yblock * (zblock * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long allmax = (XLEN * (YLEN * ZLEN));

      long g = 0;

      for ((g = 0); (g < allmax); (g = (g + 1))) {
        long xyzx = (g % XLEN);

        long xyzy = ((g / XLEN) % YLEN);

        long xyzz = (g / (XLEN * YLEN));

        long blk_offset = (blk_all_len * i);

        if (__idx == 0) {
          double rho = 0;

          {
            long num_ele = 10;

            double p0r = ((inEB + (10 * blk_offset)))[(
                8 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))];

            double p0i = ((inEB + (10 * blk_offset)))[(
                9 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))];

            double p1r = ((inEB + (10 * blk_offset)))[(
                3 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))];

            double p1i = ((inEB + (10 * blk_offset)))[(
                4 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))];

            double cjp1i = p0i * p1r - p0r * p1i;

            (rho = ((2 * (cjp1i * q)) / dtodx));
            double curr[3];
            ((curr)[0] = (xyzx + (xoffset)[i]));
            ((curr)[1] = (xyzy + (yoffset)[i]));
            ((curr)[2] = (xyzz + (zoffset)[i]));
            if ((mode > 0) && (mode < 4)) {
              (rho = (rho * (curr)[(mode - 1)]));

            } else {
              if ((mode > 3) && (mode < 6)) {
                (rho = (rho * ({
                          double tmppowvar = (curr)[(mode - 4)];

                          (tmppowvar * tmppowvar);
                        })));
              }
            }
          }
          (((outEB +
             blk_offset))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               rho);
        }
      }
    }
  }
}
__global__ void cuda_kgm_eqn_core(double *outEB, double *inEB, double *extA0, double *extA1, int *xoffset, int *yoffset,
                                  int *zoffset, long y_cpu_core, long numvec, long XLEN, long YLEN, long ZLEN, int ovlp,
                                  long xblock, long yblock, long zblock, int num_ele, double DT, double M, double Q,
                                  double DX, double GEXT, double rfz0, double g_beg, int swap_input) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long blk_all_len = (xblock * (yblock * (zblock * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long allmax = (XLEN * (YLEN * ZLEN));

      long g = 0;

      for ((g = 0); (g < allmax); (g = (g + 1))) {
        long xyzx = (g % XLEN);

        long xyzy = ((g / XLEN) % YLEN);

        long xyzz = (g / (XLEN * YLEN));

        long blk_offset = (blk_all_len * i);

        if (__idx == 0) {


          double vA1110_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1110_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1110_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double PHI1_R1110 = ((inEB + blk_offset))[(
              3 + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1110 = ((inEB + blk_offset))[(
              4 + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1210_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((2 + (xyzz + -1)) + ovlp)))))))];


          double vA1120_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((2 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1101_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1101_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1101_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double PHI1_R1101 = ((inEB + blk_offset))[(
              3 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((0 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1101 = ((inEB + blk_offset))[(
              4 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((0 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1201_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((2 + (xyzz + -1)) + ovlp)))))))];


          double vA1011_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


          double vA1011_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


          double vA1011_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


          double PHI1_R1011 = ((inEB + blk_offset))[(
              3 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1011 = ((inEB + blk_offset))[(
              4 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];

          double veA0111_1 =
              ((extA0 + ((blk_offset * 3) /
                         num_ele)))[((1 + (-1 + 0)) + (3 * (((1 + (xyzx + -1)) + ovlp) +
                                                            (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                       (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA0111_1 = ((
              inEB + blk_offset))[((1 + (-1 + 5)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double vA1111_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA0111_2 = ((
              inEB + blk_offset))[((2 + (-1 + 5)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double vA1111_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA0111_3 = ((
              inEB + blk_offset))[((3 + (-1 + 5)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double vA1111_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_R0111 = ((inEB + blk_offset))[(
              8 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I0111 = ((inEB + blk_offset))[(
              9 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_R1111 = ((inEB + blk_offset))[(
              3 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1111 = ((inEB + blk_offset))[(
              4 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1211_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((2 + (xyzz + -1)) + ovlp)))))))];


          double vA1211_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((2 + (xyzz + -1)) + ovlp)))))))];


          double PHI1_R1211 = ((inEB + blk_offset))[(
              3 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((2 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1211 = ((inEB + blk_offset))[(
              4 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((2 + (xyzz + -1)) + ovlp)))))))];


          double vA1021_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((2 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


          double vA1121_1 = ((
              inEB + blk_offset))[((1 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((2 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1121_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((2 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double PHI1_R1121 = ((inEB + blk_offset))[(
              3 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((2 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1121 = ((inEB + blk_offset))[(
              4 + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                              (xblock * (((2 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1102_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((2 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1012_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((2 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


          double vA1112_2 = ((
              inEB + blk_offset))[((2 + (-1 + 0)) + (num_ele * (((2 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vA1112_3 = ((
              inEB + blk_offset))[((3 + (-1 + 0)) + (num_ele * (((2 + (xyzx + -1)) + ovlp) +
                                                                (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                           (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double PHI1_R1112 = ((inEB + blk_offset))[(
              3 + (num_ele * (((2 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double PHI1_I1112 = ((inEB + blk_offset))[(
              4 + (num_ele * (((2 + (xyzx + -1)) + ovlp) +
                              (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          (((outEB + blk_offset))[(
               (0 + 5) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               vA1111_1);
          (((outEB + blk_offset))[(
               (0 + 0) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               ((1.00000000000000000e+00 / ({
                   double tmppowvar = DX;

                   (tmppowvar * tmppowvar);
                 })) *
                ((-1.00000000000000000e+00 * (({
                                                double tmppowvar = DX;

                                                (tmppowvar * tmppowvar);
                                              }) *
                                              vA0111_1)) +
                 ((({
                     double tmppowvar = DT;

                     (tmppowvar * tmppowvar);
                   }) *
                   vA1011_1) +
                  ((-1.00000000000000000e+00 * (({
                                                  double tmppowvar = DT;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                vA1011_3)) +
                   ((({
                       double tmppowvar = DT;

                       (tmppowvar * tmppowvar);
                     }) *
                     vA1012_3) +
                    ((({
                        double tmppowvar = DT;

                        (tmppowvar * tmppowvar);
                      }) *
                      vA1101_1) +
                     ((-1.00000000000000000e+00 * (({
                                                     double tmppowvar = DT;

                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   vA1101_2)) +
                      ((({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        }) *
                        vA1102_2) +
                       ((((-4.00000000000000000e+00 * ({
                            double tmppowvar = DT;

                            (tmppowvar * tmppowvar);
                          })) +
                          (2.00000000000000000e+00 * ({
                             double tmppowvar = DX;

                             (tmppowvar * tmppowvar);
                           }))) *
                         vA1111_1) +
                        ((((-2.00000000000000000e+00 * (({
                                                          double tmppowvar = DT;

                                                          (tmppowvar * tmppowvar);
                                                        }) *
                                                        (DX * (PHI1_I1112 * PHI1_R1111)))) +
                           (2.00000000000000000e+00 * (({
                                                         double tmppowvar = DT;

                                                         (tmppowvar * tmppowvar);
                                                       }) *
                                                       (DX * (PHI1_I1111 * PHI1_R1112))))) *
                          (Q * cos((DX * (Q * vA1111_1))))) +
                         ((((-2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_I1111 * PHI1_I1112)))) +
                            (-2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_R1111 * PHI1_R1112))))) *
                           (Q * sin((DX * (Q * vA1111_1))))) +
                          ((({
                              double tmppowvar = DT;

                              (tmppowvar * tmppowvar);
                            }) *
                            vA1111_2) +
                           ((({
                               double tmppowvar = DT;

                               (tmppowvar * tmppowvar);
                             }) *
                             vA1111_3) +
                            ((-1.00000000000000000e+00 * (({
                                                            double tmppowvar = DT;

                                                            (tmppowvar * tmppowvar);
                                                          }) *
                                                          vA1112_2)) +
                             ((-1.00000000000000000e+00 * (({
                                                             double tmppowvar = DT;

                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           vA1112_3)) +
                              ((({
                                  double tmppowvar = DT;

                                  (tmppowvar * tmppowvar);
                                }) *
                                vA1121_1) +
                               (({
                                  double tmppowvar = DT;

                                  (tmppowvar * tmppowvar);
                                }) *
                                vA1211_1))))))))))))))))));
          (((outEB + blk_offset))[(
               (1 + 5) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               vA1111_2);
          (((outEB + blk_offset))[(
               (1 + 0) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               ((1.00000000000000000e+00 / ({
                   double tmppowvar = DX;

                   (tmppowvar * tmppowvar);
                 })) *
                ((-1.00000000000000000e+00 * (({
                                                double tmppowvar = DX;

                                                (tmppowvar * tmppowvar);
                                              }) *
                                              vA0111_2)) +
                 ((({
                     double tmppowvar = DT;

                     (tmppowvar * tmppowvar);
                   }) *
                   vA1011_2) +
                  ((-1.00000000000000000e+00 * (({
                                                  double tmppowvar = DT;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                vA1011_3)) +
                   ((({
                       double tmppowvar = DT;

                       (tmppowvar * tmppowvar);
                     }) *
                     vA1021_3) +
                    ((-1.00000000000000000e+00 * (({
                                                    double tmppowvar = DT;

                                                    (tmppowvar * tmppowvar);
                                                  }) *
                                                  vA1110_1)) +
                     ((({
                         double tmppowvar = DT;

                         (tmppowvar * tmppowvar);
                       }) *
                       vA1110_2) +
                      ((({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        }) *
                        vA1111_1) +
                       ((((-4.00000000000000000e+00 * ({
                            double tmppowvar = DT;

                            (tmppowvar * tmppowvar);
                          })) +
                          (2.00000000000000000e+00 * ({
                             double tmppowvar = DX;

                             (tmppowvar * tmppowvar);
                           }))) *
                         vA1111_2) +
                        ((((-2.00000000000000000e+00 * (({
                                                          double tmppowvar = DT;

                                                          (tmppowvar * tmppowvar);
                                                        }) *
                                                        (DX * (PHI1_I1121 * PHI1_R1111)))) +
                           (2.00000000000000000e+00 * (({
                                                         double tmppowvar = DT;

                                                         (tmppowvar * tmppowvar);
                                                       }) *
                                                       (DX * (PHI1_I1111 * PHI1_R1121))))) *
                          (Q * cos((DX * (Q * vA1111_2))))) +
                         ((((-2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_I1111 * PHI1_I1121)))) +
                            (-2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_R1111 * PHI1_R1121))))) *
                           (Q * sin((DX * (Q * vA1111_2))))) +
                          ((({
                              double tmppowvar = DT;

                              (tmppowvar * tmppowvar);
                            }) *
                            vA1111_3) +
                           ((({
                               double tmppowvar = DT;

                               (tmppowvar * tmppowvar);
                             }) *
                             vA1112_2) +
                            ((({
                                double tmppowvar = DT;

                                (tmppowvar * tmppowvar);
                              }) *
                              vA1120_1) +
                             ((-1.00000000000000000e+00 * (({
                                                             double tmppowvar = DT;

                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           vA1121_1)) +
                              ((-1.00000000000000000e+00 * (({
                                                              double tmppowvar = DT;

                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            vA1121_3)) +
                               (({
                                  double tmppowvar = DT;

                                  (tmppowvar * tmppowvar);
                                }) *
                                vA1211_2))))))))))))))))));
          (((outEB + blk_offset))[(
               (2 + 5) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               vA1111_3);
          (((outEB + blk_offset))[(
               (2 + 0) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               (-1.00000000000000000e+00 *
                ((1.00000000000000000e+00 / ({
                    double tmppowvar = DX;

                    (tmppowvar * tmppowvar);
                  })) *
                 ((({
                     double tmppowvar = DX;

                     (tmppowvar * tmppowvar);
                   }) *
                   vA0111_3) +
                  ((({
                      double tmppowvar = DT;

                      (tmppowvar * tmppowvar);
                    }) *
                    vA1101_2) +
                   ((-1.00000000000000000e+00 * (({
                                                   double tmppowvar = DT;

                                                   (tmppowvar * tmppowvar);
                                                 }) *
                                                 vA1101_3)) +
                    ((({
                        double tmppowvar = DT;

                        (tmppowvar * tmppowvar);
                      }) *
                      vA1110_1) +
                     ((-1.00000000000000000e+00 * (({
                                                     double tmppowvar = DT;

                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   vA1110_3)) +
                      ((-1.00000000000000000e+00 * (({
                                                      double tmppowvar = DT;

                                                      (tmppowvar * tmppowvar);
                                                    }) *
                                                    vA1111_1)) +
                       ((-1.00000000000000000e+00 * (({
                                                       double tmppowvar = DT;

                                                       (tmppowvar * tmppowvar);
                                                     }) *
                                                     vA1111_2)) +
                        ((((4.00000000000000000e+00 * ({
                              double tmppowvar = DT;

                              (tmppowvar * tmppowvar);
                            })) +
                           (-2.00000000000000000e+00 * ({
                             double tmppowvar = DX;

                             (tmppowvar * tmppowvar);
                           }))) *
                          vA1111_3) +
                         ((((2.00000000000000000e+00 * (({
                                                          double tmppowvar = DT;

                                                          (tmppowvar * tmppowvar);
                                                        }) *
                                                        (DX * (PHI1_I1211 * PHI1_R1111)))) +
                            (-2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_I1111 * PHI1_R1211))))) *
                           (Q * cos((DX * (Q * vA1111_3))))) +
                          ((((2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_I1111 * PHI1_I1211)))) +
                             (2.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (DX * (PHI1_R1111 * PHI1_R1211))))) *
                            (Q * sin((DX * (Q * vA1111_3))))) +
                           ((-1.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         vA1112_3)) +
                            ((-1.00000000000000000e+00 * (({
                                                            double tmppowvar = DT;

                                                            (tmppowvar * tmppowvar);
                                                          }) *
                                                          vA1121_3)) +
                             ((-1.00000000000000000e+00 * (({
                                                             double tmppowvar = DT;

                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           vA1201_2)) +
                              ((-1.00000000000000000e+00 * (({
                                                              double tmppowvar = DT;

                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            vA1210_1)) +
                               ((({
                                   double tmppowvar = DT;

                                   (tmppowvar * tmppowvar);
                                 }) *
                                 vA1211_1) +
                                (({
                                   double tmppowvar = DT;

                                   (tmppowvar * tmppowvar);
                                 }) *
                                 vA1211_2)))))))))))))))))));
          (((outEB + blk_offset))[(
               (3 + 5) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               PHI1_R1111);
          (((outEB + blk_offset))[(
               (3 + 0) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               ((1.00000000000000000e+00 / ({
                   double tmppowvar = DX;

                   (tmppowvar * tmppowvar);
                 })) *
                ((({
                    double tmppowvar = DX;

                    (tmppowvar * tmppowvar);
                  }) *
                  PHI1_R0111) +
                 ((((((-6.00000000000000000e+00 * ({
                        double tmppowvar = DT;

                        (tmppowvar * tmppowvar);
                      })) +
                      ((2.00000000000000000e+00 * ({
                          double tmppowvar = DX;

                          (tmppowvar * tmppowvar);
                        })) +
                       (-1.00000000000000000e+00 * (({
                                                      double tmppowvar = DT;

                                                      (tmppowvar * tmppowvar);
                                                    }) *
                                                    (({
                                                       double tmppowvar = DX;

                                                       (tmppowvar * tmppowvar);
                                                     }) *
                                                     ({
                                                       double tmppowvar = M;

                                                       (tmppowvar * tmppowvar);
                                                     })))))) *
                     PHI1_R1111) +
                    ((({
                        double tmppowvar = DT;

                        (tmppowvar * tmppowvar);
                      }) *
                      (PHI1_R1011 * cos((DX * (Q * vA1011_3))))) +
                     ((({
                         double tmppowvar = DT;

                         (tmppowvar * tmppowvar);
                       }) *
                       (PHI1_I1011 * sin((DX * (Q * vA1011_3))))) +
                      ((({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        }) *
                        (PHI1_R1101 * cos((DX * (Q * vA1101_2))))) +
                       ((({
                           double tmppowvar = DT;

                           (tmppowvar * tmppowvar);
                         }) *
                         (PHI1_I1101 * sin((DX * (Q * vA1101_2))))) +
                        ((({
                            double tmppowvar = DT;

                            (tmppowvar * tmppowvar);
                          }) *
                          (PHI1_R1110 * cos((DX * (Q * vA1110_1))))) +
                         ((({
                             double tmppowvar = DT;

                             (tmppowvar * tmppowvar);
                           }) *
                           (PHI1_I1110 * sin((DX * (Q * vA1110_1))))) +
                          ((({
                              double tmppowvar = DT;

                              (tmppowvar * tmppowvar);
                            }) *
                            (PHI1_R1112 * cos((DX * (Q * vA1111_1))))) +
                           ((-1.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (PHI1_I1112 * sin((DX * (Q * vA1111_1)))))) +
                            ((({
                                double tmppowvar = DT;

                                (tmppowvar * tmppowvar);
                              }) *
                              (PHI1_R1121 * cos((DX * (Q * vA1111_2))))) +
                             ((-1.00000000000000000e+00 * (({
                                                             double tmppowvar = DT;

                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           (PHI1_I1121 * sin((DX * (Q * vA1111_2)))))) +
                              ((({
                                  double tmppowvar = DT;

                                  (tmppowvar * tmppowvar);
                                }) *
                                (PHI1_R1211 * cos((DX * (Q * vA1111_3))))) +
                               (-1.00000000000000000e+00 * (({
                                                              double tmppowvar = DT;

                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            (PHI1_I1211 * sin((DX * (Q * vA1111_3)))))))))))))))))) *
                   cos((DT * (Q * veA0111_1)))) +
                  ((-2.00000000000000000e+00 * (({
                                                  double tmppowvar = DX;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                (PHI1_R0111 * ({
                                                   double tmppowvar = cos((DT * (Q * veA0111_1)));

                                                   (tmppowvar * tmppowvar);
                                                 })))) +
                   (((((6.00000000000000000e+00 * ({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        })) +
                       ((-2.00000000000000000e+00 * ({
                          double tmppowvar = DX;

                          (tmppowvar * tmppowvar);
                        })) +
                        (({
                           double tmppowvar = DT;

                           (tmppowvar * tmppowvar);
                         }) *
                         (({
                            double tmppowvar = DX;

                            (tmppowvar * tmppowvar);
                          }) *
                          ({
                            double tmppowvar = M;

                            (tmppowvar * tmppowvar);
                          }))))) *
                      PHI1_I1111) +
                     ((-1.00000000000000000e+00 * (({
                                                     double tmppowvar = DT;

                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   (PHI1_I1011 * cos((DX * (Q * vA1011_3)))))) +
                      ((({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        }) *
                        (PHI1_R1011 * sin((DX * (Q * vA1011_3))))) +
                       ((-1.00000000000000000e+00 * (({
                                                       double tmppowvar = DT;

                                                       (tmppowvar * tmppowvar);
                                                     }) *
                                                     (PHI1_I1101 * cos((DX * (Q * vA1101_2)))))) +
                        ((({
                            double tmppowvar = DT;

                            (tmppowvar * tmppowvar);
                          }) *
                          (PHI1_R1101 * sin((DX * (Q * vA1101_2))))) +
                         ((-1.00000000000000000e+00 * (({
                                                         double tmppowvar = DT;

                                                         (tmppowvar * tmppowvar);
                                                       }) *
                                                       (PHI1_I1110 * cos((DX * (Q * vA1110_1)))))) +
                          ((({
                              double tmppowvar = DT;

                              (tmppowvar * tmppowvar);
                            }) *
                            (PHI1_R1110 * sin((DX * (Q * vA1110_1))))) +
                           ((-1.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (PHI1_I1112 * cos((DX * (Q * vA1111_1)))))) +
                            ((-1.00000000000000000e+00 * (({
                                                            double tmppowvar = DT;

                                                            (tmppowvar * tmppowvar);
                                                          }) *
                                                          (PHI1_R1112 * sin((DX * (Q * vA1111_1)))))) +
                             ((-1.00000000000000000e+00 * (({
                                                             double tmppowvar = DT;

                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           (PHI1_I1121 * cos((DX * (Q * vA1111_2)))))) +
                              ((-1.00000000000000000e+00 * (({
                                                              double tmppowvar = DT;

                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            (PHI1_R1121 * sin((DX * (Q * vA1111_2)))))) +
                               ((-1.00000000000000000e+00 * (({
                                                               double tmppowvar = DT;

                                                               (tmppowvar * tmppowvar);
                                                             }) *
                                                             (PHI1_I1211 * cos((DX * (Q * vA1111_3)))))) +
                                ((-1.00000000000000000e+00 * (({
                                                                double tmppowvar = DT;

                                                                (tmppowvar * tmppowvar);
                                                              }) *
                                                              (PHI1_R1211 * sin((DX * (Q * vA1111_3)))))) +
                                 (2.00000000000000000e+00 * (({
                                                               double tmppowvar = DX;

                                                               (tmppowvar * tmppowvar);
                                                             }) *
                                                             (PHI1_I0111 * cos((DT * (Q * veA0111_1))))))))))))))))))) *
                    sin((DT * (Q * veA0111_1)))))))));
          (((outEB + blk_offset))[(
               (4 + 5) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               PHI1_I1111);
          (((outEB + blk_offset))[(
               (4 + 0) + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               (-1.00000000000000000e+00 *
                ((1.00000000000000000e+00 / ({
                    double tmppowvar = DX;

                    (tmppowvar * tmppowvar);
                  })) *
                 ((-1.00000000000000000e+00 * (({
                                                 double tmppowvar = DX;

                                                 (tmppowvar * tmppowvar);
                                               }) *
                                               PHI1_I0111)) +
                  ((((((6.00000000000000000e+00 * ({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        })) +
                       ((-2.00000000000000000e+00 * ({
                          double tmppowvar = DX;

                          (tmppowvar * tmppowvar);
                        })) +
                        (({
                           double tmppowvar = DT;

                           (tmppowvar * tmppowvar);
                         }) *
                         (({
                            double tmppowvar = DX;

                            (tmppowvar * tmppowvar);
                          }) *
                          ({
                            double tmppowvar = M;

                            (tmppowvar * tmppowvar);
                          }))))) *
                      PHI1_I1111) +
                     ((-1.00000000000000000e+00 * (({
                                                     double tmppowvar = DT;

                                                     (tmppowvar * tmppowvar);
                                                   }) *
                                                   (PHI1_I1011 * cos((DX * (Q * vA1011_3)))))) +
                      ((({
                          double tmppowvar = DT;

                          (tmppowvar * tmppowvar);
                        }) *
                        (PHI1_R1011 * sin((DX * (Q * vA1011_3))))) +
                       ((-1.00000000000000000e+00 * (({
                                                       double tmppowvar = DT;

                                                       (tmppowvar * tmppowvar);
                                                     }) *
                                                     (PHI1_I1101 * cos((DX * (Q * vA1101_2)))))) +
                        ((({
                            double tmppowvar = DT;

                            (tmppowvar * tmppowvar);
                          }) *
                          (PHI1_R1101 * sin((DX * (Q * vA1101_2))))) +
                         ((-1.00000000000000000e+00 * (({
                                                         double tmppowvar = DT;

                                                         (tmppowvar * tmppowvar);
                                                       }) *
                                                       (PHI1_I1110 * cos((DX * (Q * vA1110_1)))))) +
                          ((({
                              double tmppowvar = DT;

                              (tmppowvar * tmppowvar);
                            }) *
                            (PHI1_R1110 * sin((DX * (Q * vA1110_1))))) +
                           ((-1.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (PHI1_I1112 * cos((DX * (Q * vA1111_1)))))) +
                            ((-1.00000000000000000e+00 * (({
                                                            double tmppowvar = DT;

                                                            (tmppowvar * tmppowvar);
                                                          }) *
                                                          (PHI1_R1112 * sin((DX * (Q * vA1111_1)))))) +
                             ((-1.00000000000000000e+00 * (({
                                                             double tmppowvar = DT;

                                                             (tmppowvar * tmppowvar);
                                                           }) *
                                                           (PHI1_I1121 * cos((DX * (Q * vA1111_2)))))) +
                              ((-1.00000000000000000e+00 * (({
                                                              double tmppowvar = DT;

                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            (PHI1_R1121 * sin((DX * (Q * vA1111_2)))))) +
                               ((-1.00000000000000000e+00 * (({
                                                               double tmppowvar = DT;

                                                               (tmppowvar * tmppowvar);
                                                             }) *
                                                             (PHI1_I1211 * cos((DX * (Q * vA1111_3)))))) +
                                (-1.00000000000000000e+00 * (({
                                                               double tmppowvar = DT;

                                                               (tmppowvar * tmppowvar);
                                                             }) *
                                                             (PHI1_R1211 * sin((DX * (Q * vA1111_3)))))))))))))))))) *
                    cos((DT * (Q * veA0111_1)))) +
                   ((2.00000000000000000e+00 * (({
                                                  double tmppowvar = DX;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                (PHI1_I0111 * ({
                                                   double tmppowvar = cos((DT * (Q * veA0111_1)));

                                                   (tmppowvar * tmppowvar);
                                                 })))) +
                    (((((6.00000000000000000e+00 * ({
                           double tmppowvar = DT;

                           (tmppowvar * tmppowvar);
                         })) +
                        ((-2.00000000000000000e+00 * ({
                           double tmppowvar = DX;

                           (tmppowvar * tmppowvar);
                         })) +
                         (({
                            double tmppowvar = DT;

                            (tmppowvar * tmppowvar);
                          }) *
                          (({
                             double tmppowvar = DX;

                             (tmppowvar * tmppowvar);
                           }) *
                           ({
                             double tmppowvar = M;

                             (tmppowvar * tmppowvar);
                           }))))) *
                       PHI1_R1111) +
                      ((-1.00000000000000000e+00 * (({
                                                      double tmppowvar = DT;

                                                      (tmppowvar * tmppowvar);
                                                    }) *
                                                    (PHI1_R1011 * cos((DX * (Q * vA1011_3)))))) +
                       ((-1.00000000000000000e+00 * (({
                                                       double tmppowvar = DT;

                                                       (tmppowvar * tmppowvar);
                                                     }) *
                                                     (PHI1_I1011 * sin((DX * (Q * vA1011_3)))))) +
                        ((-1.00000000000000000e+00 * (({
                                                        double tmppowvar = DT;

                                                        (tmppowvar * tmppowvar);
                                                      }) *
                                                      (PHI1_R1101 * cos((DX * (Q * vA1101_2)))))) +
                         ((-1.00000000000000000e+00 * (({
                                                         double tmppowvar = DT;

                                                         (tmppowvar * tmppowvar);
                                                       }) *
                                                       (PHI1_I1101 * sin((DX * (Q * vA1101_2)))))) +
                          ((-1.00000000000000000e+00 * (({
                                                          double tmppowvar = DT;

                                                          (tmppowvar * tmppowvar);
                                                        }) *
                                                        (PHI1_R1110 * cos((DX * (Q * vA1110_1)))))) +
                           ((-1.00000000000000000e+00 * (({
                                                           double tmppowvar = DT;

                                                           (tmppowvar * tmppowvar);
                                                         }) *
                                                         (PHI1_I1110 * sin((DX * (Q * vA1110_1)))))) +
                            ((-1.00000000000000000e+00 * (({
                                                            double tmppowvar = DT;

                                                            (tmppowvar * tmppowvar);
                                                          }) *
                                                          (PHI1_R1112 * cos((DX * (Q * vA1111_1)))))) +
                             ((({
                                 double tmppowvar = DT;

                                 (tmppowvar * tmppowvar);
                               }) *
                               (PHI1_I1112 * sin((DX * (Q * vA1111_1))))) +
                              ((-1.00000000000000000e+00 * (({
                                                              double tmppowvar = DT;

                                                              (tmppowvar * tmppowvar);
                                                            }) *
                                                            (PHI1_R1121 * cos((DX * (Q * vA1111_2)))))) +
                               ((({
                                   double tmppowvar = DT;

                                   (tmppowvar * tmppowvar);
                                 }) *
                                 (PHI1_I1121 * sin((DX * (Q * vA1111_2))))) +
                                ((-1.00000000000000000e+00 * (({
                                                                double tmppowvar = DT;

                                                                (tmppowvar * tmppowvar);
                                                              }) *
                                                              (PHI1_R1211 * cos((DX * (Q * vA1111_3)))))) +
                                 ((({
                                     double tmppowvar = DT;

                                     (tmppowvar * tmppowvar);
                                   }) *
                                   (PHI1_I1211 * sin((DX * (Q * vA1111_3))))) +
                                  (2.00000000000000000e+00 *
                                   (({
                                      double tmppowvar = DX;

                                      (tmppowvar * tmppowvar);
                                    }) *
                                    (PHI1_R0111 * cos((DT * (Q * veA0111_1))))))))))))))))))) *
                     sin((DT * (Q * veA0111_1))))))))));
        }
      }
    }
  }
}

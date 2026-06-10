
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32
__global__ void cuda_yee_local(double *inout, long numvec, int num_ele,
                               long xblock, long yblock, long zblock,
                               int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);



  long xb = xblock;

  long yb = yblock;




}
__global__ void cuda_sync_ovlp_o2m(double *vecmain, double *vecovlp,
                                   int ovlpindex, long numvec, int num_ele,
                                   long xblock, long yblock, long zblock,
                                   int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / __ylen) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);

  }

  int xlo = (ovlpindex % 3);

  int ylo = ((ovlpindex / 3) % 3);

  int zlo = ((ovlpindex / 3) / 3);

  int field_xmi = ovlp;

  int field_ymi = ovlp;

  int field_zmi = ovlp;

  long field_xma = (xb - ovlp);

  long field_yma = (yb - ovlp);

  long field_zma = (zb - ovlp);

  if (xlo == 0) {
    (field_xmi = 0);
    (field_xma = (ovlp + 0));

  } else {
    if (xlo == 2) {
      (field_xmi = (xb - (ovlp + 0)));
      (field_xma = (xb - 0));

    }
  }

  if (ylo == 0) {
    (field_ymi = 0);
    (field_yma = (ovlp + 0));

  } else {
    if (ylo == 2) {
      (field_ymi = (yb - (ovlp + 0)));
      (field_yma = (yb - 0));

    }
  }

  if (zlo == 0) {
    (field_zmi = 0);
    (field_zma = (ovlp + 0));

  } else {
    if (zlo == 2) {
      (field_zmi = (zb - (ovlp + 0)));
      (field_zma = (zb - 0));

    }
  }

  long ovlpxma = (field_xma - field_xmi);

  long ovlpyma = (field_yma - field_ymi);

  long ovlpzma = (field_zma - field_zmi);

  long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

  for ((i = local_ymin); (i < local_ymax); i++) {
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                long lxyzx = (xyzx + field_xmi);

                long lxyzy = (xyzy + field_ymi);

                long lxyzz = (xyzz + field_zmi);

                if (0) {
                  if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                    (lxyzx = ovlp);

                  }

                  if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                    (lxyzy = ovlp);

                  }

                  if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                    (lxyzz = ovlp);

                  }

                }

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                    long realidx = (__idx + (g * __xlen));

                    ((vecmain)[((i * blk_all_len) +
                                (realidx +
                                 (num_ele *
                                  (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                         (vecovlp)[((i * ovlpalllen) +
                                    (realidx +
                                     (num_ele *
                                      (xyzx + (ovlpxma *
                                               (xyzy + (ovlpyma * xyzz)))))))]);
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
__global__ void cuda_sync_ovlp_o2m_all_in_one(double *vecmain, double *vecovlps,
                                              long numvec, int num_ele,
                                              long xblock, long yblock,
                                              long zblock, int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  size_t v_offset = 0;

  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps + v_offset);

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = 0);
          (field_xma = (ovlp + 0));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + 0)));
            (field_xma = (xb - 0));

          }
        }

        if (ylo == 0) {
          (field_ymi = 0);
          (field_yma = (ovlp + 0));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + 0)));
            (field_yma = (yb - 0));

          }
        }

        if (zlo == 0) {
          (field_zmi = 0);
          (field_zma = (ovlp + 0));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + 0)));
            (field_zma = (zb - 0));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (0) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecmain)[(
                               (i * blk_all_len) +
                               (realidx +
                                (num_ele *
                                 (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                               (vecovlp)[(
                                   (i * ovlpalllen) +
                                   (realidx +
                                    (num_ele *
                                     (xyzx + (ovlpxma *
                                              (xyzy + (ovlpyma * xyzz)))))))]);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        (v_offset = (v_offset + (ovlpalllen * numvec)));
      }
    }
  }
}
__global__ void cuda_sync_ovlp_o2m_once(
    double *vecmain, double *vecovlp0, double *vecovlp1, double *vecovlp2,
    double *vecovlp3, double *vecovlp4, double *vecovlp5, double *vecovlp6,
    double *vecovlp7, double *vecovlp8, double *vecovlp9, double *vecovlp10,
    double *vecovlp11, double *vecovlp12, double *vecovlp14, double *vecovlp15,
    double *vecovlp16, double *vecovlp17, double *vecovlp18, double *vecovlp19,
    double *vecovlp20, double *vecovlp21, double *vecovlp22, double *vecovlp23,
    double *vecovlp24, double *vecovlp25, double *vecovlp26, long numvec,
    int num_ele, long xblock, long yblock, long zblock, int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);
  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps)[ovlpindex];

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = 0);
          (field_xma = (ovlp + 0));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + 0)));
            (field_xma = (xb - 0));

          }
        }

        if (ylo == 0) {
          (field_ymi = 0);
          (field_yma = (ovlp + 0));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + 0)));
            (field_yma = (yb - 0));

          }
        }

        if (zlo == 0) {
          (field_zmi = 0);
          (field_zma = (ovlp + 0));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + 0)));
            (field_zma = (zb - 0));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (0) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecmain)[(
                               (i * blk_all_len) +
                               (realidx +
                                (num_ele *
                                 (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                               (vecovlp)[(
                                   (i * ovlpalllen) +
                                   (realidx +
                                    (num_ele *
                                     (xyzx + (ovlpxma *
                                              (xyzy + (ovlpyma * xyzz)))))))]);
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
__global__ void cuda_sync_ovlp_m2o(double *vecmain, double *vecovlp,
                                   int ovlpindex, long numvec, int num_ele,
                                   long xblock, long yblock, long zblock,
                                   int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / __ylen) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);

  }

  int xlo = (ovlpindex % 3);

  int ylo = ((ovlpindex / 3) % 3);

  int zlo = ((ovlpindex / 3) / 3);

  int field_xmi = ovlp;

  int field_ymi = ovlp;

  int field_zmi = ovlp;

  long field_xma = (xb - ovlp);

  long field_yma = (yb - ovlp);

  long field_zma = (zb - ovlp);

  if (xlo == 0) {
    (field_xmi = ovlp);
    (field_xma = (ovlp + ovlp));

  } else {
    if (xlo == 2) {
      (field_xmi = (xb - (ovlp + ovlp)));
      (field_xma = (xb - ovlp));

    }
  }

  if (ylo == 0) {
    (field_ymi = ovlp);
    (field_yma = (ovlp + ovlp));

  } else {
    if (ylo == 2) {
      (field_ymi = (yb - (ovlp + ovlp)));
      (field_yma = (yb - ovlp));

    }
  }

  if (zlo == 0) {
    (field_zmi = ovlp);
    (field_zma = (ovlp + ovlp));

  } else {
    if (zlo == 2) {
      (field_zmi = (zb - (ovlp + ovlp)));
      (field_zma = (zb - ovlp));

    }
  }

  long ovlpxma = (field_xma - field_xmi);

  long ovlpyma = (field_yma - field_ymi);

  long ovlpzma = (field_zma - field_zmi);

  long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

  for ((i = local_ymin); (i < local_ymax); i++) {
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                long lxyzx = (xyzx + field_xmi);

                long lxyzy = (xyzy + field_ymi);

                long lxyzz = (xyzz + field_zmi);

                if (1) {
                  if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                    (lxyzx = ovlp);

                  }

                  if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                    (lxyzy = ovlp);

                  }

                  if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                    (lxyzz = ovlp);

                  }

                }

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                    long realidx = (__idx + (g * __xlen));

                    ((vecovlp)[(
                         (i * ovlpalllen) +
                         (realidx +
                          (num_ele *
                           (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                         (vecmain)[(
                             (i * blk_all_len) +
                             (realidx +
                              (num_ele *
                               (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
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
__global__ void cuda_sync_ovlp_m2o_all_in_one(double *vecmain, double *vecovlps,
                                              long numvec, int num_ele,
                                              long xblock, long yblock,
                                              long zblock, int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  size_t v_offset = 0;

  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps + v_offset);

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = ovlp);
          (field_xma = (ovlp + ovlp));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + ovlp)));
            (field_xma = (xb - ovlp));

          }
        }

        if (ylo == 0) {
          (field_ymi = ovlp);
          (field_yma = (ovlp + ovlp));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + ovlp)));
            (field_yma = (yb - ovlp));

          }
        }

        if (zlo == 0) {
          (field_zmi = ovlp);
          (field_zma = (ovlp + ovlp));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + ovlp)));
            (field_zma = (zb - ovlp));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (1) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecovlp)[(
                               (i * ovlpalllen) +
                               (realidx +
                                (num_ele *
                                 (xyzx +
                                  (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                               (vecmain)[(
                                   (i * blk_all_len) +
                                   (realidx +
                                    (num_ele *
                                     (lxyzx +
                                      (xb * (lxyzy + (yb * lxyzz)))))))]);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        (v_offset = (v_offset + (ovlpalllen * numvec)));
      }
    }
  }
}
__global__ void cuda_sync_ovlp_m2o_once(
    double *vecmain, double *vecovlp0, double *vecovlp1, double *vecovlp2,
    double *vecovlp3, double *vecovlp4, double *vecovlp5, double *vecovlp6,
    double *vecovlp7, double *vecovlp8, double *vecovlp9, double *vecovlp10,
    double *vecovlp11, double *vecovlp12, double *vecovlp14, double *vecovlp15,
    double *vecovlp16, double *vecovlp17, double *vecovlp18, double *vecovlp19,
    double *vecovlp20, double *vecovlp21, double *vecovlp22, double *vecovlp23,
    double *vecovlp24, double *vecovlp25, double *vecovlp26, long numvec,
    int num_ele, long xblock, long yblock, long zblock, int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);
  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps)[ovlpindex];

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = ovlp);
          (field_xma = (ovlp + ovlp));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + ovlp)));
            (field_xma = (xb - ovlp));

          }
        }

        if (ylo == 0) {
          (field_ymi = ovlp);
          (field_yma = (ovlp + ovlp));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + ovlp)));
            (field_yma = (yb - ovlp));

          }
        }

        if (zlo == 0) {
          (field_zmi = ovlp);
          (field_zma = (ovlp + ovlp));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + ovlp)));
            (field_zma = (zb - ovlp));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (1) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecovlp)[(
                               (i * ovlpalllen) +
                               (realidx +
                                (num_ele *
                                 (xyzx +
                                  (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                               (vecmain)[(
                                   (i * blk_all_len) +
                                   (realidx +
                                    (num_ele *
                                     (lxyzx +
                                      (xb * (lxyzy + (yb * lxyzz)))))))]);
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
__global__ void cuda_merge_ovlp_o2m(double *vecmain, double *vecovlp,
                                    int ovlpindex, long numvec, int num_ele,
                                    long xblock, long yblock, long zblock,
                                    int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / __ylen) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);

  }

  int xlo = (ovlpindex % 3);

  int ylo = ((ovlpindex / 3) % 3);

  int zlo = ((ovlpindex / 3) / 3);

  int field_xmi = ovlp;

  int field_ymi = ovlp;

  int field_zmi = ovlp;

  long field_xma = (xb - ovlp);

  long field_yma = (yb - ovlp);

  long field_zma = (zb - ovlp);

  if (xlo == 0) {
    (field_xmi = ovlp);
    (field_xma = (ovlp + ovlp));

  } else {
    if (xlo == 2) {
      (field_xmi = (xb - (ovlp + ovlp)));
      (field_xma = (xb - ovlp));

    }
  }

  if (ylo == 0) {
    (field_ymi = ovlp);
    (field_yma = (ovlp + ovlp));

  } else {
    if (ylo == 2) {
      (field_ymi = (yb - (ovlp + ovlp)));
      (field_yma = (yb - ovlp));

    }
  }

  if (zlo == 0) {
    (field_zmi = ovlp);
    (field_zma = (ovlp + ovlp));

  } else {
    if (zlo == 2) {
      (field_zmi = (zb - (ovlp + ovlp)));
      (field_zma = (zb - ovlp));

    }
  }

  long ovlpxma = (field_xma - field_xmi);

  long ovlpyma = (field_yma - field_ymi);

  long ovlpzma = (field_zma - field_zmi);

  long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

  for ((i = local_ymin); (i < local_ymax); i++) {
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                long lxyzx = (xyzx + field_xmi);

                long lxyzy = (xyzy + field_ymi);

                long lxyzz = (xyzz + field_zmi);

                if (1) {
                  if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                    (lxyzx = ovlp);

                  }

                  if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                    (lxyzy = ovlp);

                  }

                  if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                    (lxyzz = ovlp);

                  }

                }

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                    long realidx = (__idx + (g * __xlen));

                    ((vecmain)[((i * blk_all_len) +
                                (realidx +
                                 (num_ele *
                                  (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                         ((vecmain)[(
                              (i * blk_all_len) +
                              (realidx +
                               (num_ele *
                                (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] +
                          (vecovlp)[(
                              (i * ovlpalllen) +
                              (realidx +
                               (num_ele *
                                (xyzx +
                                 (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))]));
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
__global__ void cuda_merge_ovlp_o2m_all_in_one(double *vecmain,
                                               double *vecovlps, long numvec,
                                               int num_ele, long xblock,
                                               long yblock, long zblock,
                                               int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  size_t v_offset = 0;

  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps + v_offset);

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = ovlp);
          (field_xma = (ovlp + ovlp));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + ovlp)));
            (field_xma = (xb - ovlp));

          }
        }

        if (ylo == 0) {
          (field_ymi = ovlp);
          (field_yma = (ovlp + ovlp));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + ovlp)));
            (field_yma = (yb - ovlp));

          }
        }

        if (zlo == 0) {
          (field_zmi = ovlp);
          (field_zma = (ovlp + ovlp));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + ovlp)));
            (field_zma = (zb - ovlp));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (1) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecmain)[(
                               (i * blk_all_len) +
                               (realidx +
                                (num_ele *
                                 (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                               ((vecmain)[(
                                    (i * blk_all_len) +
                                    (realidx +
                                     (num_ele *
                                      (lxyzx +
                                       (xb * (lxyzy + (yb * lxyzz)))))))] +
                                (vecovlp)[((i * ovlpalllen) +
                                           (realidx +
                                            (num_ele *
                                             (xyzx + (ovlpxma *
                                                      (xyzy + (ovlpyma *
                                                               xyzz)))))))]));
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        (v_offset = (v_offset + (ovlpalllen * numvec)));
      }
    }
  }
}
__global__ void cuda_merge_ovlp_o2m_once(
    double *vecmain, double *vecovlp0, double *vecovlp1, double *vecovlp2,
    double *vecovlp3, double *vecovlp4, double *vecovlp5, double *vecovlp6,
    double *vecovlp7, double *vecovlp8, double *vecovlp9, double *vecovlp10,
    double *vecovlp11, double *vecovlp12, double *vecovlp14, double *vecovlp15,
    double *vecovlp16, double *vecovlp17, double *vecovlp18, double *vecovlp19,
    double *vecovlp20, double *vecovlp21, double *vecovlp22, double *vecovlp23,
    double *vecovlp24, double *vecovlp25, double *vecovlp26, long numvec,
    int num_ele, long xblock, long yblock, long zblock, int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);
  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps)[ovlpindex];

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = ovlp);
          (field_xma = (ovlp + ovlp));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + ovlp)));
            (field_xma = (xb - ovlp));

          }
        }

        if (ylo == 0) {
          (field_ymi = ovlp);
          (field_yma = (ovlp + ovlp));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + ovlp)));
            (field_yma = (yb - ovlp));

          }
        }

        if (zlo == 0) {
          (field_zmi = ovlp);
          (field_zma = (ovlp + ovlp));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + ovlp)));
            (field_zma = (zb - ovlp));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (1) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecmain)[(
                               (i * blk_all_len) +
                               (realidx +
                                (num_ele *
                                 (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                               ((vecmain)[(
                                    (i * blk_all_len) +
                                    (realidx +
                                     (num_ele *
                                      (lxyzx +
                                       (xb * (lxyzy + (yb * lxyzz)))))))] +
                                (vecovlp)[((i * ovlpalllen) +
                                           (realidx +
                                            (num_ele *
                                             (xyzx + (ovlpxma *
                                                      (xyzy + (ovlpyma *
                                                               xyzz)))))))]));
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
__global__ void cuda_merge_ovlp_m2o(double *vecmain, double *vecovlp,
                                    int ovlpindex, long numvec, int num_ele,
                                    long xblock, long yblock, long zblock,
                                    int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  long i = 0;

  long local_ynum = (((numvec - 1) / __ylen) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if (local_ymax >= numvec) {
    (local_ymax = numvec);

  }

  int xlo = (ovlpindex % 3);

  int ylo = ((ovlpindex / 3) % 3);

  int zlo = ((ovlpindex / 3) / 3);

  int field_xmi = ovlp;

  int field_ymi = ovlp;

  int field_zmi = ovlp;

  long field_xma = (xb - ovlp);

  long field_yma = (yb - ovlp);

  long field_zma = (zb - ovlp);

  if (xlo == 0) {
    (field_xmi = 0);
    (field_xma = (ovlp + 0));

  } else {
    if (xlo == 2) {
      (field_xmi = (xb - (ovlp + 0)));
      (field_xma = (xb - 0));

    }
  }

  if (ylo == 0) {
    (field_ymi = 0);
    (field_yma = (ovlp + 0));

  } else {
    if (ylo == 2) {
      (field_ymi = (yb - (ovlp + 0)));
      (field_yma = (yb - 0));

    }
  }

  if (zlo == 0) {
    (field_zmi = 0);
    (field_zma = (ovlp + 0));

  } else {
    if (zlo == 2) {
      (field_zmi = (zb - (ovlp + 0)));
      (field_zma = (zb - 0));

    }
  }

  long ovlpxma = (field_xma - field_xmi);

  long ovlpyma = (field_yma - field_ymi);

  long ovlpzma = (field_zma - field_zmi);

  long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

  for ((i = local_ymin); (i < local_ymax); i++) {
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                long lxyzx = (xyzx + field_xmi);

                long lxyzy = (xyzy + field_ymi);

                long lxyzz = (xyzz + field_zmi);

                if (0) {
                  if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                    (lxyzx = ovlp);

                  }

                  if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                    (lxyzy = ovlp);

                  }

                  if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                    (lxyzz = ovlp);

                  }

                }

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                    long realidx = (__idx + (g * __xlen));

                    ((vecovlp)[(
                         (i * ovlpalllen) +
                         (realidx +
                          (num_ele *
                           (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                         (vecmain)[(
                             (i * blk_all_len) +
                             (realidx +
                              (num_ele *
                               (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
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
__global__ void cuda_merge_ovlp_m2o_all_in_one(double *vecmain,
                                               double *vecovlps, long numvec,
                                               int num_ele, long xblock,
                                               long yblock, long zblock,
                                               int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  size_t v_offset = 0;

  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps + v_offset);

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = 0);
          (field_xma = (ovlp + 0));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + 0)));
            (field_xma = (xb - 0));

          }
        }

        if (ylo == 0) {
          (field_ymi = 0);
          (field_yma = (ovlp + 0));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + 0)));
            (field_yma = (yb - 0));

          }
        }

        if (zlo == 0) {
          (field_zmi = 0);
          (field_zma = (ovlp + 0));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + 0)));
            (field_zma = (zb - 0));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (0) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecovlp)[(
                               (i * ovlpalllen) +
                               (realidx +
                                (num_ele *
                                 (xyzx +
                                  (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                               (vecmain)[(
                                   (i * blk_all_len) +
                                   (realidx +
                                    (num_ele *
                                     (lxyzx +
                                      (xb * (lxyzy + (yb * lxyzz)))))))]);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        (v_offset = (v_offset + (ovlpalllen * numvec)));
      }
    }
  }
}
__global__ void cuda_merge_ovlp_m2o_once(
    double *vecmain, double *vecovlp0, double *vecovlp1, double *vecovlp2,
    double *vecovlp3, double *vecovlp4, double *vecovlp5, double *vecovlp6,
    double *vecovlp7, double *vecovlp8, double *vecovlp9, double *vecovlp10,
    double *vecovlp11, double *vecovlp12, double *vecovlp14, double *vecovlp15,
    double *vecovlp16, double *vecovlp17, double *vecovlp18, double *vecovlp19,
    double *vecovlp20, double *vecovlp21, double *vecovlp22, double *vecovlp23,
    double *vecovlp24, double *vecovlp25, double *vecovlp26, long numvec,
    int num_ele, long xblock, long yblock, long zblock, int ovlp) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);

  const long __ylen = (gridDim.x * gridDim.y);


  double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);
  {
    long ovlpindex;

    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if (ovlpindex == 13) {
        continue;

      } else {
        double *vecovlp = (vecovlps)[ovlpindex];

        long i = 0;

        long local_ynum = (((numvec - 1) / __ylen) + 1);

        long local_ymin = (__idy * local_ynum);

        long local_ymax = ((1 + __idy) * local_ynum);

        long xb = xblock;

        long yb = yblock;

        long zb = zblock;

        long blk_all_len = (xb * (yb * (zb * num_ele)));

        if (local_ymax >= numvec) {
          (local_ymax = numvec);

        }

        int xlo = (ovlpindex % 3);

        int ylo = ((ovlpindex / 3) % 3);

        int zlo = ((ovlpindex / 3) / 3);

        int field_xmi = ovlp;

        int field_ymi = ovlp;

        int field_zmi = ovlp;

        long field_xma = (xb - ovlp);

        long field_yma = (yb - ovlp);

        long field_zma = (zb - ovlp);

        if (xlo == 0) {
          (field_xmi = 0);
          (field_xma = (ovlp + 0));

        } else {
          if (xlo == 2) {
            (field_xmi = (xb - (ovlp + 0)));
            (field_xma = (xb - 0));

          }
        }

        if (ylo == 0) {
          (field_ymi = 0);
          (field_yma = (ovlp + 0));

        } else {
          if (ylo == 2) {
            (field_ymi = (yb - (ovlp + 0)));
            (field_yma = (yb - 0));

          }
        }

        if (zlo == 0) {
          (field_zmi = 0);
          (field_zma = (ovlp + 0));

        } else {
          if (zlo == 2) {
            (field_zmi = (zb - (ovlp + 0)));
            (field_zma = (zb - 0));

          }
        }

        long ovlpxma = (field_xma - field_xmi);

        long ovlpyma = (field_yma - field_ymi);

        long ovlpzma = (field_zma - field_zmi);

        long ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));

        for ((i = local_ymin); (i < local_ymax); i++) {
          {
            long xyzz;

            for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
              {
                long xyzy;

                for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
                  {
                    long xyzx;

                    for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                      long lxyzx = (xyzx + field_xmi);

                      long lxyzy = (xyzy + field_ymi);

                      long lxyzz = (xyzz + field_zmi);

                      if (0) {
                        if ((lxyzx < ovlp) || (lxyzx >= (xb - ovlp))) {
                          (lxyzx = ovlp);

                        }

                        if ((lxyzy < ovlp) || (lxyzy >= (yb - ovlp))) {
                          (lxyzy = ovlp);

                        }

                        if ((lxyzz < ovlp) || (lxyzz >= (zb - ovlp))) {
                          (lxyzz = ovlp);

                        }

                      }

                      {
                        long g = 0;

                        for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                          long realidx = (__idx + (g * __xlen));

                          ((vecovlp)[(
                               (i * ovlpalllen) +
                               (realidx +
                                (num_ele *
                                 (xyzx +
                                  (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                               (vecmain)[(
                                   (i * blk_all_len) +
                                   (realidx +
                                    (num_ele *
                                     (lxyzx +
                                      (xb * (lxyzy + (yb * lxyzz)))))))]);
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

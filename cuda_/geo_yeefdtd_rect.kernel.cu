
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32
__global__ void cuda_RECT_YEE_CURL_L(double *inoutE1, double *inB0, int *xoffset, int *yoffset, int *zoffset,
                                     long y_cpu_core, long numvec, long XLEN, long YLEN, long ZLEN, int ovlp,
                                     long xblock, long yblock, long zblock, int num_ele, double DT, double DELTA_X,
                                     double DELTA_Y, double DELTA_Z) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  if (local_ymax >= numvec) {
    (local_ymax = numvec);
  }

  long blk_all_len_nonele = (xblock * (yblock * zblock));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {


      long allmax = (XLEN * (YLEN * ZLEN));

      long blk_offset = (blk_all_len_nonele * (i * num_ele));

      if (0 && ((blk_all_len_nonele * num_ele) < 2048)) {
        double vread_tmp[2048];
        double vwrt_tmp[2048];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (blk_all_len_nonele * num_ele)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((vread_tmp)[((inner_step * 1) + inner_g)] = ((inB0 + blk_offset))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (blk_all_len_nonele * num_ele)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((vwrt_tmp)[((inner_step * 1) + inner_g)] = ((inoutE1 + blk_offset))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long xyzz;

          for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
            {
              long xyzy;

              for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
                {
                  long xyzx;

                  for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {


                    double vB11101 =
                        (vread_tmp)[((1 + 0) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

                    double vB21101 =
                        (vread_tmp)[((2 + 0) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


                    double vB01011 =
                        (vread_tmp)[((0 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


                    double vB21011 =
                        (vread_tmp)[((2 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((0 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


                    double vB00111 =
                        (vread_tmp)[((0 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];

                    double vB10111 =
                        (vread_tmp)[((1 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


                    double vB01111 =
                        (vread_tmp)[((0 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

                    double vB11111 =
                        (vread_tmp)[((1 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

                    double vB21111 =
                        (vread_tmp)[((2 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                                           (xblock * (((1 + (xyzy + -1)) + ovlp) +
                                                                      (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


                    ((vwrt_tmp)[(0 +
                                 (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                         ((vwrt_tmp)[(0 + (num_ele *
                                           ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] +
                          (DT * (DELTA_X * ((1.00000000000000000e+00 / ({
                                               double tmppowvar = DELTA_Y;

                                               tmppowvar;
                                             })) *
                                            ((1.00000000000000000e+00 / ({
                                                double tmppowvar = DELTA_Z;

                                                tmppowvar;
                                              })) *
                                             (((1.00000000000000000e+00 / ({
                                                  double tmppowvar = DELTA_X;

                                                  tmppowvar;
                                                })) *
                                               (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                              double tmppowvar = DELTA_Z;

                                                              tmppowvar;
                                                            })) *
                                                           vB10111))) +
                                              ((-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                               double tmppowvar = DELTA_X;

                                                                               tmppowvar;
                                                                             })) *
                                                                            (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                                                           double tmppowvar = DELTA_Z;

                                                                                           tmppowvar;
                                                                                         })) *
                                                                                        vB11111)))) +
                                               ((-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                                double tmppowvar = DELTA_X;

                                                                                tmppowvar;
                                                                              })) *
                                                                             ((1.00000000000000000e+00 / ({
                                                                                 double tmppowvar = DELTA_Y;

                                                                                 tmppowvar;
                                                                               })) *
                                                                              (DELTA_Z * vB21011)))) +
                                                ((1.00000000000000000e+00 / ({
                                                    double tmppowvar = DELTA_X;

                                                    tmppowvar;
                                                  })) *
                                                 ((1.00000000000000000e+00 / ({
                                                     double tmppowvar = DELTA_Y;

                                                     tmppowvar;
                                                   })) *
                                                  (DELTA_Z * vB21111))))))))))));
                    ((vwrt_tmp)[(1 +
                                 (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                         ((vwrt_tmp)[(1 + (num_ele *
                                           ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] +
                          (DT * ((1.00000000000000000e+00 / ({
                                    double tmppowvar = DELTA_X;

                                    tmppowvar;
                                  })) *
                                 (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                double tmppowvar = DELTA_Z;

                                                tmppowvar;
                                              })) *
                                             ((-1.00000000000000000e+00 * (DELTA_X * ((1.00000000000000000e+00 / ({
                                                                                         double tmppowvar = DELTA_Y;

                                                                                         tmppowvar;
                                                                                       })) *
                                                                                      ((1.00000000000000000e+00 / ({
                                                                                          double tmppowvar = DELTA_Z;

                                                                                          tmppowvar;
                                                                                        })) *
                                                                                       vB00111)))) +
                                              ((DELTA_X * ((1.00000000000000000e+00 / ({
                                                              double tmppowvar = DELTA_Y;

                                                              tmppowvar;
                                                            })) *
                                                           ((1.00000000000000000e+00 / ({
                                                               double tmppowvar = DELTA_Z;

                                                               tmppowvar;
                                                             })) *
                                                            vB01111))) +
                                               (((1.00000000000000000e+00 / ({
                                                    double tmppowvar = DELTA_X;

                                                    tmppowvar;
                                                  })) *
                                                 ((1.00000000000000000e+00 / ({
                                                     double tmppowvar = DELTA_Y;

                                                     tmppowvar;
                                                   })) *
                                                  (DELTA_Z * vB21101))) +
                                                (-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                                double tmppowvar = DELTA_X;

                                                                                tmppowvar;
                                                                              })) *
                                                                             ((1.00000000000000000e+00 / ({
                                                                                 double tmppowvar = DELTA_Y;

                                                                                 tmppowvar;
                                                                               })) *
                                                                              (DELTA_Z * vB21111)))))))))))));
                    ((vwrt_tmp)[(2 +
                                 (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
                         ((vwrt_tmp)[(2 + (num_ele *
                                           ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] +
                          (DT * ((1.00000000000000000e+00 / ({
                                    double tmppowvar = DELTA_X;

                                    tmppowvar;
                                  })) *
                                 ((1.00000000000000000e+00 / ({
                                     double tmppowvar = DELTA_Y;

                                     tmppowvar;
                                   })) *
                                  (DELTA_Z * ((DELTA_X * ((1.00000000000000000e+00 / ({
                                                             double tmppowvar = DELTA_Y;

                                                             tmppowvar;
                                                           })) *
                                                          ((1.00000000000000000e+00 / ({
                                                              double tmppowvar = DELTA_Z;

                                                              tmppowvar;
                                                            })) *
                                                           vB01011))) +
                                              ((-1.00000000000000000e+00 * (DELTA_X * ((1.00000000000000000e+00 / ({
                                                                                          double tmppowvar = DELTA_Y;

                                                                                          tmppowvar;
                                                                                        })) *
                                                                                       ((1.00000000000000000e+00 / ({
                                                                                           double tmppowvar = DELTA_Z;

                                                                                           tmppowvar;
                                                                                         })) *
                                                                                        vB01111)))) +
                                               ((-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                                double tmppowvar = DELTA_X;

                                                                                tmppowvar;
                                                                              })) *
                                                                             (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                                                            double tmppowvar = DELTA_Z;

                                                                                            tmppowvar;
                                                                                          })) *
                                                                                         vB11101)))) +
                                                ((1.00000000000000000e+00 / ({
                                                    double tmppowvar = DELTA_X;

                                                    tmppowvar;
                                                  })) *
                                                 (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                                double tmppowvar = DELTA_Z;

                                                                tmppowvar;
                                                              })) *
                                                             vB11111))))))))))));
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (blk_all_len_nonele * num_ele)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((inoutE1 + blk_offset))[((inner_step * 1) + inner_g)] = (vwrt_tmp)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
        long lg = 0;

        for ((lg = 0); ((lg + __idx) < allmax); (lg = (lg + __xlen))) {
          long g = (lg + __idx);

          long xyzx = (g % XLEN);

          long xyzy = ((g / XLEN) % YLEN);

          long xyzz = (g / (XLEN * YLEN));


          double vB11101 = ((inB0 + blk_offset))[(
              (1 + 0) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double vB21101 = ((inB0 + blk_offset))[(
              (2 + 0) + (num_ele * (((0 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vB01011 = ((inB0 + blk_offset))[(
              (0 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((0 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vB21011 = ((inB0 + blk_offset))[(
              (2 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((0 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          double vB00111 = ((inB0 + blk_offset))[(
              (0 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];

          double vB10111 = ((inB0 + blk_offset))[(
              (1 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((0 + (xyzz + -1)) + ovlp)))))))];


          double vB01111 = ((inB0 + blk_offset))[(
              (0 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double vB11111 = ((inB0 + blk_offset))[(
              (1 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];

          double vB21111 = ((inB0 + blk_offset))[(
              (2 + 0) + (num_ele * (((1 + (xyzx + -1)) + ovlp) +
                                    (xblock * (((1 + (xyzy + -1)) + ovlp) + (yblock * ((1 + (xyzz + -1)) + ovlp)))))))];


          (((inoutE1 +
             blk_offset))[(0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               (((inoutE1 + blk_offset))[(
                    0 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] +
                (DT * (DELTA_X * ((1.00000000000000000e+00 / ({
                                     double tmppowvar = DELTA_Y;

                                     tmppowvar;
                                   })) *
                                  ((1.00000000000000000e+00 / ({
                                      double tmppowvar = DELTA_Z;

                                      tmppowvar;
                                    })) *
                                   (((1.00000000000000000e+00 / ({
                                        double tmppowvar = DELTA_X;

                                        tmppowvar;
                                      })) *
                                     (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                    double tmppowvar = DELTA_Z;

                                                    tmppowvar;
                                                  })) *
                                                 vB10111))) +
                                    ((-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                     double tmppowvar = DELTA_X;

                                                                     tmppowvar;
                                                                   })) *
                                                                  (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                                                 double tmppowvar = DELTA_Z;

                                                                                 tmppowvar;
                                                                               })) *
                                                                              vB11111)))) +
                                     ((-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                      double tmppowvar = DELTA_X;

                                                                      tmppowvar;
                                                                    })) *
                                                                   ((1.00000000000000000e+00 / ({
                                                                       double tmppowvar = DELTA_Y;

                                                                       tmppowvar;
                                                                     })) *
                                                                    (DELTA_Z * vB21011)))) +
                                      ((1.00000000000000000e+00 / ({
                                          double tmppowvar = DELTA_X;

                                          tmppowvar;
                                        })) *
                                       ((1.00000000000000000e+00 / ({
                                           double tmppowvar = DELTA_Y;

                                           tmppowvar;
                                         })) *
                                        (DELTA_Z * vB21111))))))))))));
          (((inoutE1 +
             blk_offset))[(1 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               (((inoutE1 + blk_offset))[(
                    1 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] +
                (DT * ((1.00000000000000000e+00 / ({
                          double tmppowvar = DELTA_X;

                          tmppowvar;
                        })) *
                       (DELTA_Y * ((1.00000000000000000e+00 / ({
                                      double tmppowvar = DELTA_Z;

                                      tmppowvar;
                                    })) *
                                   ((-1.00000000000000000e+00 * (DELTA_X * ((1.00000000000000000e+00 / ({
                                                                               double tmppowvar = DELTA_Y;

                                                                               tmppowvar;
                                                                             })) *
                                                                            ((1.00000000000000000e+00 / ({
                                                                                double tmppowvar = DELTA_Z;

                                                                                tmppowvar;
                                                                              })) *
                                                                             vB00111)))) +
                                    ((DELTA_X * ((1.00000000000000000e+00 / ({
                                                    double tmppowvar = DELTA_Y;

                                                    tmppowvar;
                                                  })) *
                                                 ((1.00000000000000000e+00 / ({
                                                     double tmppowvar = DELTA_Z;

                                                     tmppowvar;
                                                   })) *
                                                  vB01111))) +
                                     (((1.00000000000000000e+00 / ({
                                          double tmppowvar = DELTA_X;

                                          tmppowvar;
                                        })) *
                                       ((1.00000000000000000e+00 / ({
                                           double tmppowvar = DELTA_Y;

                                           tmppowvar;
                                         })) *
                                        (DELTA_Z * vB21101))) +
                                      (-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                      double tmppowvar = DELTA_X;

                                                                      tmppowvar;
                                                                    })) *
                                                                   ((1.00000000000000000e+00 / ({
                                                                       double tmppowvar = DELTA_Y;

                                                                       tmppowvar;
                                                                     })) *
                                                                    (DELTA_Z * vB21111)))))))))))));
          (((inoutE1 +
             blk_offset))[(2 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] =
               (((inoutE1 + blk_offset))[(
                    2 + (num_ele * ((xyzx + ovlp) + (xblock * ((xyzy + ovlp) + (yblock * (xyzz + ovlp)))))))] +
                (DT * ((1.00000000000000000e+00 / ({
                          double tmppowvar = DELTA_X;

                          tmppowvar;
                        })) *
                       ((1.00000000000000000e+00 / ({
                           double tmppowvar = DELTA_Y;

                           tmppowvar;
                         })) *
                        (DELTA_Z * ((DELTA_X * ((1.00000000000000000e+00 / ({
                                                   double tmppowvar = DELTA_Y;

                                                   tmppowvar;
                                                 })) *
                                                ((1.00000000000000000e+00 / ({
                                                    double tmppowvar = DELTA_Z;

                                                    tmppowvar;
                                                  })) *
                                                 vB01011))) +
                                    ((-1.00000000000000000e+00 * (DELTA_X * ((1.00000000000000000e+00 / ({
                                                                                double tmppowvar = DELTA_Y;

                                                                                tmppowvar;
                                                                              })) *
                                                                             ((1.00000000000000000e+00 / ({
                                                                                 double tmppowvar = DELTA_Z;

                                                                                 tmppowvar;
                                                                               })) *
                                                                              vB01111)))) +
                                     ((-1.00000000000000000e+00 * ((1.00000000000000000e+00 / ({
                                                                      double tmppowvar = DELTA_X;

                                                                      tmppowvar;
                                                                    })) *
                                                                   (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                                                  double tmppowvar = DELTA_Z;

                                                                                  tmppowvar;
                                                                                })) *
                                                                               vB11101)))) +
                                      ((1.00000000000000000e+00 / ({
                                          double tmppowvar = DELTA_X;

                                          tmppowvar;
                                        })) *
                                       (DELTA_Y * ((1.00000000000000000e+00 / ({
                                                      double tmppowvar = DELTA_Z;

                                                      tmppowvar;
                                                    })) *
                                                   vB11111))))))))))));
        }
      }
    }
  }
}


#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void c_blas_yiszero_synced_scmc_kernel(double *y, long y_cpu_core, long numvec,
                                       long XLEN, long YLEN, long ZLEN,
                                       int ovlp, long xblock, long yblock,
                                       long zblock, int num_ele,
                                       long scmc_internal_g_idy,
                                       long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  const long LOCAL_CACHE_LEN = 128;

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double zeros[128];
  long lg = 0;

  for ((lg = 0); ((lg + __idx) < LOCAL_CACHE_LEN); (lg = (lg + __xlen))) {
    ((zeros)[(lg + __idx)] = 0);
  }
  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long blk_offset_t1 = (blk_all_len * i);

      long j = 0;

      for ((j = 0); (j < blk_all_len); (j = (j + LOCAL_CACHE_LEN))) {
        int numcp =
            ((((j + LOCAL_CACHE_LEN) < blk_all_len)) ? (LOCAL_CACHE_LEN)
                                                     : ((blk_all_len - j)));

        {
          long Gll_P9918;

          for ((Gll_P9918 = 0); (Gll_P9918 < numcp);
               (Gll_P9918 = (Gll_P9918 + 1))) {
            (((y + (blk_offset_t1 + j)))[Gll_P9918] = (zeros)[Gll_P9918]);
          }
        }
      }
    }
  }
}
void c_blas_mulxy_numele3_scmc_kernel(double *y, double *x, long y_cpu_core,
                                      long numvec, long XLEN, long YLEN,
                                      long ZLEN, int ovlp, long xblock,
                                      long yblock, long zblock, int num_ele,
                                      long scmc_internal_g_idy,
                                      long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len_0 = (xb * (yb * (zb * num_ele)));

  long blk_all_len_1 = (xb * (yb * (zb * 3)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      long j = 0;

      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                  long blk_offset_0 =
                      ((blk_all_len_0 * i) +
                       (0 + (num_ele *
                             (ovlp +
                              (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));

                  long blk_offset_1 =
                      ((blk_all_len_1 * i) +
                       (0 + (3 * (ovlp + (xb * ((xyzy + ovlp) +
                                                (yb * (xyzz + ovlp))))))));

                  {
                    long g = 0;

                    for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                         g++) {
                      long realidx = (__idx + (g * __xlen));

                      int cur_id = (realidx % num_ele);

                      int realidx_1 = (cur_id + (3 * (realidx / num_ele)));

                      if ((cur_id < 3)) {
                        ((y)[(blk_offset_0 + realidx)] =
                             ((y)[(blk_offset_0 + realidx)] *
                              (x)[(blk_offset_1 + realidx_1)]));

                      } else {
                        0;
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
void c_blas_yiszero_scmc_kernel(double *y, long y_cpu_core, long numvec,
                                long XLEN, long YLEN, long ZLEN, int ovlp,
                                long xblock, long yblock, long zblock,
                                int num_ele, long scmc_internal_g_idy,
                                long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        ((fast_y)[(
                             (0 + (num_ele *
                                   (ovlp + (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                             realidx)] = 0);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        ((y)[(blk_offset + realidx)] = 0);
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
void c_blas_yiszero_full_block_scmc_kernel(
    double *y, long y_cpu_core, long numvec, long XLEN, long YLEN, long ZLEN,
    int ovlp, long xblock, long yblock, long zblock, int num_ele,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (((fast_y)[(g + inner_var_G0)])[0] = 0);
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (((fast_y)[g])[0] = 0);
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_yisconst_scmc_kernel(double *y, double a, long y_cpu_core,
                                 long numvec, long XLEN, long YLEN, long ZLEN,
                                 int ovlp, long xblock, long yblock,
                                 long zblock, int num_ele,
                                 long scmc_internal_g_idy,
                                 long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        ((fast_y)[(
                             (0 + (num_ele *
                                   (ovlp + (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                             realidx)] = a);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        ((y)[(blk_offset + realidx)] = a);
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
void c_blas_yisconst_full_block_scmc_kernel(
    double *y, double a, long y_cpu_core, long numvec, long XLEN, long YLEN,
    long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (((fast_y)[(g + inner_var_G0)])[0] = a);
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (((fast_y)[g])[0] = a);
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_get_ITG_Potential_scmc_kernel(
    double *y, double *x, double *u, double minus_over_q_e, long y_cpu_core,
    long numvec, long XLEN, long YLEN, long ZLEN, int ovlp, long xblock,
    long yblock, long zblock, int num_ele, long scmc_internal_g_idy,
    long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_x[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_x)[((inner_step * 1) + inner_g)] =
                       ((x + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_u[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_u)[((inner_step * 1) + inner_g)] =
                       ((u + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        if ((((fast_y)[(
                                  (0 +
                                   (num_ele *
                                    (ovlp + (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                  realidx)] > 0) &&
                             ((fast_u)[(
                                  (0 +
                                   (num_ele *
                                    (ovlp + (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                  realidx)] > 0))) {
                          ((fast_y)[(
                               (0 + (num_ele *
                                     (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                               realidx)] =
                               (minus_over_q_e *
                                ((fast_x)[(
                                     (0 + (num_ele *
                                           (ovlp +
                                            (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                     realidx)] *
                                 log(((fast_y)[(
                                          (0 +
                                           (num_ele *
                                            (ovlp +
                                             (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                                          realidx)] /
                                      (fast_u)[(
                                          (0 +
                                           (num_ele *
                                            (ovlp +
                                             (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                                          realidx)])))));

                        } else {
                          ((fast_y)[(
                               (0 + (num_ele *
                                     (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                               realidx)] = 0);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        if ((((y)[(blk_offset + realidx)] > 0) &&
                             ((u)[(blk_offset + realidx)] > 0))) {
                          ((y)[(blk_offset + realidx)] =
                               (minus_over_q_e *
                                ((x)[(blk_offset + realidx)] *
                                 log(((y)[(blk_offset + realidx)] /
                                      (u)[(blk_offset + realidx)])))));

                        } else {
                          ((y)[(blk_offset + realidx)] = 0);
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
void c_blas_get_ITG_Potential_full_block_scmc_kernel(
    double *y, double *x, double *u, double minus_over_q_e, long y_cpu_core,
    long numvec, long XLEN, long YLEN, long ZLEN, int ovlp, long xblock,
    long yblock, long zblock, int num_ele, long scmc_internal_g_idy,
    long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));

        double(*fast_x)[1];
        (fast_x = (x + (i * blk_all_len)));

        double(*fast_u)[1];
        (fast_u = (u + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    if (((((fast_y)[(g + inner_var_G0)])[0] > 0) &&
                         (((fast_u)[(g + inner_var_G0)])[0] > 0))) {
                      (((fast_y)[(g + inner_var_G0)])[0] =
                           (minus_over_q_e *
                            (((fast_x)[(g + inner_var_G0)])[0] *
                             log((((fast_y)[(g + inner_var_G0)])[0] /
                                  ((fast_u)[(g + inner_var_G0)])[0])))));

                    } else {
                      (((fast_y)[(g + inner_var_G0)])[0] = 0);
                    }
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                if (((((fast_y)[g])[0] > 0) && (((fast_u)[g])[0] > 0))) {
                  (((fast_y)[g])[0] =
                       (minus_over_q_e *
                        (((fast_x)[g])[0] *
                         log((((fast_y)[g])[0] / ((fast_u)[g])[0])))));

                } else {
                  (((fast_y)[g])[0] = 0);
                }
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_invy_scmc_kernel(double *y, long y_cpu_core, long numvec, long XLEN,
                             long YLEN, long ZLEN, int ovlp, long xblock,
                             long yblock, long zblock, int num_ele,
                             long scmc_internal_g_idy,
                             long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        if (((fast_y)[((0 + (num_ele *
                                             (ovlp +
                                              (xb * ((xyzy + ovlp) +
                                                     (yb * (xyzz + ovlp))))))) +
                                       realidx)] != 0)) {
                          ((fast_y)[(
                               (0 + (num_ele *
                                     (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                               realidx)] =
                               (1.00000000000000000e+00 /
                                (fast_y)[(
                                    (0 +
                                     (num_ele *
                                      (ovlp + (xb * ((xyzy + ovlp) +
                                                     (yb * (xyzz + ovlp))))))) +
                                    realidx)]));

                        } else {
                          0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        if (((y)[(blk_offset + realidx)] != 0)) {
                          ((y)[(blk_offset + realidx)] =
                               (1.00000000000000000e+00 /
                                (y)[(blk_offset + realidx)]));

                        } else {
                          0;
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
void c_blas_invy_full_block_scmc_kernel(double *y, long y_cpu_core, long numvec,
                                        long XLEN, long YLEN, long ZLEN,
                                        int ovlp, long xblock, long yblock,
                                        long zblock, int num_ele,
                                        long scmc_internal_g_idy,
                                        long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    if ((((fast_y)[(g + inner_var_G0)])[0] != 0)) {
                      (((fast_y)[(g + inner_var_G0)])[0] =
                           (1.00000000000000000e+00 /
                            ((fast_y)[(g + inner_var_G0)])[0]));

                    } else {
                      0;
                    }
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                if ((((fast_y)[g])[0] != 0)) {
                  (((fast_y)[g])[0] =
                       (1.00000000000000000e+00 / ((fast_y)[g])[0]));

                } else {
                  0;
                }
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_yisax_scmc_kernel(double *y, double *x, double a, long y_cpu_core,
                              long numvec, long XLEN, long YLEN, long ZLEN,
                              int ovlp, long xblock, long yblock, long zblock,
                              int num_ele, long scmc_internal_g_idy,
                              long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_x[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_x)[((inner_step * 1) + inner_g)] =
                       ((x + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        ((fast_y)[(
                             (0 + (num_ele *
                                   (ovlp + (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                             realidx)] =
                             (a * (fast_x)[(
                                      (0 + (num_ele *
                                            (ovlp +
                                             (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                                      realidx)]));
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        ((y)[(blk_offset + realidx)] =
                             (a * (x)[(blk_offset + realidx)]));
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
void c_blas_yisax_full_block_scmc_kernel(
    double *y, double *x, double a, long y_cpu_core, long numvec, long XLEN,
    long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
    int num_ele, long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));

        double(*fast_x)[1];
        (fast_x = (x + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (((fast_y)[(g + inner_var_G0)])[0] =
                         (a * ((fast_x)[(g + inner_var_G0)])[0]));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (((fast_y)[g])[0] = (a * ((fast_x)[g])[0]));
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_axpy_scmc_kernel(double *y, double *x, double a, long y_cpu_core,
                             long numvec, long XLEN, long YLEN, long ZLEN,
                             int ovlp, long xblock, long yblock, long zblock,
                             int num_ele, long scmc_internal_g_idy,
                             long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_x[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_x)[((inner_step * 1) + inner_g)] =
                       ((x + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        ((fast_y)[(
                             (0 + (num_ele *
                                   (ovlp + (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                             realidx)] =
                             ((fast_y)[(
                                  (0 +
                                   (num_ele *
                                    (ovlp + (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                  realidx)] +
                              (a * (fast_x)[(
                                       (0 + (num_ele *
                                             (ovlp +
                                              (xb * ((xyzy + ovlp) +
                                                     (yb * (xyzz + ovlp))))))) +
                                       realidx)])));
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        ((y)[(blk_offset + realidx)] =
                             ((y)[(blk_offset + realidx)] +
                              (a * (x)[(blk_offset + realidx)])));
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
void c_blas_axpy_full_block_scmc_kernel(double *y, double *x, double a,
                                        long y_cpu_core, long numvec, long XLEN,
                                        long YLEN, long ZLEN, int ovlp,
                                        long xblock, long yblock, long zblock,
                                        int num_ele, long scmc_internal_g_idy,
                                        long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));

        double(*fast_x)[1];
        (fast_x = (x + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (((fast_y)[(g + inner_var_G0)])[0] =
                         (((fast_y)[(g + inner_var_G0)])[0] +
                          (a * ((fast_x)[(g + inner_var_G0)])[0])));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (((fast_y)[g])[0] =
                     (((fast_y)[g])[0] + (a * ((fast_x)[g])[0])));
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_axpby_scmc_kernel(double *y, double *x, double a, double b,
                              long y_cpu_core, long numvec, long XLEN,
                              long YLEN, long ZLEN, int ovlp, long xblock,
                              long yblock, long zblock, int num_ele,
                              long scmc_internal_g_idy,
                              long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_x[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_x)[((inner_step * 1) + inner_g)] =
                       ((x + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        ((fast_y)[(
                             (0 + (num_ele *
                                   (ovlp + (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                             realidx)] =
                             ((a * (fast_x)[(
                                       (0 + (num_ele *
                                             (ovlp +
                                              (xb * ((xyzy + ovlp) +
                                                     (yb * (xyzz + ovlp))))))) +
                                       realidx)]) +
                              (b * (fast_y)[(
                                       (0 + (num_ele *
                                             (ovlp +
                                              (xb * ((xyzy + ovlp) +
                                                     (yb * (xyzz + ovlp))))))) +
                                       realidx)])));
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        ((y)[(blk_offset + realidx)] =
                             ((a * (x)[(blk_offset + realidx)]) +
                              (b * (y)[(blk_offset + realidx)])));
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
void c_blas_axpby_full_block_scmc_kernel(double *y, double *x, double a,
                                         double b, long y_cpu_core, long numvec,
                                         long XLEN, long YLEN, long ZLEN,
                                         int ovlp, long xblock, long yblock,
                                         long zblock, int num_ele,
                                         long scmc_internal_g_idy,
                                         long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));

        double(*fast_x)[1];
        (fast_x = (x + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (((fast_y)[(g + inner_var_G0)])[0] =
                         ((a * ((fast_x)[(g + inner_var_G0)])[0]) +
                          (b * ((fast_y)[(g + inner_var_G0)])[0])));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (((fast_y)[g])[0] =
                     ((a * ((fast_x)[g])[0]) + (b * ((fast_y)[g])[0])));
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_mulxy_scmc_kernel(double *y, double *x, long y_cpu_core,
                              long numvec, long XLEN, long YLEN, long ZLEN,
                              int ovlp, long xblock, long yblock, long zblock,
                              int num_ele, long scmc_internal_g_idy,
                              long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_x[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_x)[((inner_step * 1) + inner_g)] =
                       ((x + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        ((fast_y)[(
                             (0 + (num_ele *
                                   (ovlp + (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                             realidx)] =
                             ((fast_x)[(
                                  (0 +
                                   (num_ele *
                                    (ovlp + (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                  realidx)] *
                              (fast_y)[(
                                  (0 +
                                   (num_ele *
                                    (ovlp + (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                  realidx)]));
                      }
                    }
                  }
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < blk_all_len);
               (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)] =
                     (fast_y)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        ((y)[(blk_offset + realidx)] =
                             ((x)[(blk_offset + realidx)] *
                              (y)[(blk_offset + realidx)]));
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
void c_blas_mulxy_full_block_scmc_kernel(double *y, double *x, long y_cpu_core,
                                         long numvec, long XLEN, long YLEN,
                                         long ZLEN, int ovlp, long xblock,
                                         long yblock, long zblock, int num_ele,
                                         long scmc_internal_g_idy,
                                         long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));

        double(*fast_x)[1];
        (fast_x = (x + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (((fast_y)[(g + inner_var_G0)])[0] =
                         (((fast_x)[(g + inner_var_G0)])[0] *
                          ((fast_y)[(g + inner_var_G0)])[0]));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (((fast_y)[g])[0] = (((fast_x)[g])[0] * ((fast_y)[g])[0]));
              }
              {}
            }
          }
        }
      }
    }
  }
}
void c_blas_findmax_scmc_kernel(double *y, double *rdcd_max, long y_cpu_core,
                                long numvec, long XLEN, long YLEN, long ZLEN,
                                int ovlp, long xblock, long yblock, long zblock,
                                int num_ele, long scmc_internal_g_idy,
                                long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        (reduce_tmp =
                             (((fabs((fast_y)[(
                                    (0 +
                                     (num_ele *
                                      (ovlp + (xb * ((xyzy + ovlp) +
                                                     (yb * (xyzz + ovlp))))))) +
                                    realidx)]) > reduce_tmp))
                                  ? (fabs((fast_y)[(
                                        (0 +
                                         (num_ele *
                                          (ovlp +
                                           (xb * ((xyzy + ovlp) +
                                                  (yb * (xyzz + ovlp))))))) +
                                        realidx)]))
                                  : (reduce_tmp)));
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        (reduce_tmp =
                             (((fabs((y)[(blk_offset + realidx)]) > reduce_tmp))
                                  ? (fabs((y)[(blk_offset + realidx)]))
                                  : (reduce_tmp)));
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
  ((reduce_tmp_arr)[__idx] = reduce_tmp);
  if ((__idx == 0)) {
    {
      long i1;

      for ((i1 = 1); (i1 < IDX_OPT_MAX); (i1 = (i1 + 1))) {
        (reduce_tmp = (((fabs((reduce_tmp_arr)[i1]) > reduce_tmp))
                           ? (fabs((reduce_tmp_arr)[i1]))
                           : (reduce_tmp)));
      }
    }
    ((rdcd_max)[__idy] = reduce_tmp);

  } else {
    0;
  }
}
void c_blas_findmax_full_block_scmc_kernel(
    double *y, double *rdcd_max, long y_cpu_core, long numvec, long XLEN,
    long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock,
    int num_ele, long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (reduce_tmp =
                         (((fabs(((fast_y)[(g + inner_var_G0)])[0]) >
                            reduce_tmp))
                              ? (fabs(((fast_y)[(g + inner_var_G0)])[0]))
                              : (reduce_tmp)));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (reduce_tmp = (((fabs(((fast_y)[g])[0]) > reduce_tmp))
                                   ? (fabs(((fast_y)[g])[0]))
                                   : (reduce_tmp)));
              }
              {}
            }
          }
        }
      }
    }
  }
  ((reduce_tmp_arr)[__idx] = reduce_tmp);
  if ((__idx == 0)) {
    {
      long i1;

      for ((i1 = 1); (i1 < IDX_OPT_MAX); (i1 = (i1 + 1))) {
        (reduce_tmp = (((fabs((reduce_tmp_arr)[i1]) > reduce_tmp))
                           ? (fabs((reduce_tmp_arr)[i1]))
                           : (reduce_tmp)));
      }
    }
    ((rdcd_max)[__idy] = reduce_tmp);

  } else {
    0;
  }
}
void c_blas_dot_scmc_kernel(double *y, double *x, double *rdcd_sum,
                            long y_cpu_core, long numvec, long XLEN, long YLEN,
                            long ZLEN, int ovlp, long xblock, long yblock,
                            long zblock, int num_ele, long scmc_internal_g_idy,
                            long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        double fast_x[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_x)[((inner_step * 1) + inner_g)] =
                       ((x + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        (reduce_tmp =
                             (reduce_tmp +
                              ((fast_x)[(
                                   (0 +
                                    (num_ele *
                                     (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                                   realidx)] *
                               (fast_y)[(
                                   (0 +
                                    (num_ele *
                                     (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))) +
                                   realidx)])));
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        (reduce_tmp =
                             (reduce_tmp + ((x)[(blk_offset + realidx)] *
                                            (y)[(blk_offset + realidx)])));
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
  ((reduce_tmp_arr)[__idx] = reduce_tmp);
  if ((__idx == 0)) {
    {
      long i1;

      for ((i1 = 1); (i1 < IDX_OPT_MAX); (i1 = (i1 + 1))) {
        (reduce_tmp = (reduce_tmp + (1 * (reduce_tmp_arr)[i1])));
      }
    }
    ((rdcd_sum)[__idy] = reduce_tmp);

  } else {
    0;
  }
}
void c_blas_dot_full_block_scmc_kernel(double *y, double *x, double *rdcd_sum,
                                       long y_cpu_core, long numvec, long XLEN,
                                       long YLEN, long ZLEN, int ovlp,
                                       long xblock, long yblock, long zblock,
                                       int num_ele, long scmc_internal_g_idy,
                                       long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));

        double(*fast_x)[1];
        (fast_x = (x + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (reduce_tmp =
                         (reduce_tmp + (((fast_x)[(g + inner_var_G0)])[0] *
                                        ((fast_y)[(g + inner_var_G0)])[0])));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (reduce_tmp =
                     (reduce_tmp + (((fast_x)[g])[0] * ((fast_y)[g])[0])));
              }
              {}
            }
          }
        }
      }
    }
  }
  ((reduce_tmp_arr)[__idx] = reduce_tmp);
  if ((__idx == 0)) {
    {
      long i1;

      for ((i1 = 1); (i1 < IDX_OPT_MAX); (i1 = (i1 + 1))) {
        (reduce_tmp = (reduce_tmp + (1 * (reduce_tmp_arr)[i1])));
      }
    }
    ((rdcd_sum)[__idy] = reduce_tmp);

  } else {
    0;
  }
}
void c_blas_sum_scmc_kernel(double *y, double *rdcd_sum, long y_cpu_core,
                            long numvec, long XLEN, long YLEN, long ZLEN,
                            int ovlp, long xblock, long yblock, long zblock,
                            int num_ele, long scmc_internal_g_idy,
                            long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      if ((blk_all_len <= 1)) {
        double fast_y[1];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < blk_all_len);
                 (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((fast_y)[((inner_step * 1) + inner_g)] =
                       ((y + (i * blk_all_len)))[((inner_step * 1) + inner_g)]);
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

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    {
                      long realidx;

                      for ((realidx = 0); (realidx < (num_ele * XLEN));
                           (realidx = (realidx + 1))) {
                        (reduce_tmp =
                             (reduce_tmp +
                              (fast_y)[(
                                  (0 +
                                   (num_ele *
                                    (ovlp + (xb * ((xyzy + ovlp) +
                                                   (yb * (xyzz + ovlp))))))) +
                                  realidx)]));
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {
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
                        ((blk_all_len * i) +
                         (0 +
                          (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                    {
                      long g = 0;

                      for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele));
                           g++) {
                        long realidx = (__idx + (g * __xlen));

                        (reduce_tmp =
                             (reduce_tmp + (y)[(blk_offset + realidx)]));
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
  ((reduce_tmp_arr)[__idx] = reduce_tmp);
  if ((__idx == 0)) {
    {
      long i1;

      for ((i1 = 1); (i1 < IDX_OPT_MAX); (i1 = (i1 + 1))) {
        (reduce_tmp = (reduce_tmp + (reduce_tmp_arr)[i1]));
      }
    }
    ((rdcd_sum)[__idy] = reduce_tmp);

  } else {
    0;
  }
}
void c_blas_sum_full_block_scmc_kernel(double *y, double *rdcd_sum,
                                       long y_cpu_core, long numvec, long XLEN,
                                       long YLEN, long ZLEN, int ovlp,
                                       long xblock, long yblock, long zblock,
                                       int num_ele, long scmc_internal_g_idy,
                                       long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  if ((local_ymax >= numvec)) {
    (local_ymax = numvec);

  } else {
    0;
  }

  double reduce_tmp_arr[IDX_OPT_MAX];
  double reduce_tmp = 0.00000000000000000e+00;

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {

        double(*fast_y)[1];
        (fast_y = (y + (i * blk_all_len)));
        {
          {
            long g;

            for ((g = 0); (g < (blk_all_len - (4 - 1))); (g = (g + 4))) {
              {
                {
                  int inner_var_G0;

                  for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                       (inner_var_G0 = (inner_var_G0 + 1))) {
                    (reduce_tmp =
                         (reduce_tmp + ((fast_y)[(g + inner_var_G0)])[0]));
                  }
                }
              }
              {}
            }
            for (0; (g < blk_all_len); (g = (g + 1))) {
              {
                (reduce_tmp = (reduce_tmp + ((fast_y)[g])[0]));
              }
              {}
            }
          }
        }
      }
    }
  }
  ((reduce_tmp_arr)[__idx] = reduce_tmp);
  if ((__idx == 0)) {
    {
      long i1;

      for ((i1 = 1); (i1 < IDX_OPT_MAX); (i1 = (i1 + 1))) {
        (reduce_tmp = (reduce_tmp + (reduce_tmp_arr)[i1]));
      }
    }
    ((rdcd_sum)[__idy] = reduce_tmp);

  } else {
    0;
  }
}
void c_blas_yisax_shrink_scmc_kernel(double *y, double *x, double a,
                                     long y_cpu_core, long numvec, long XLEN,
                                     long YLEN, long ZLEN, int ovlp,
                                     long xblock, long yblock, long zblock,
                                     int num_ele, long scmc_internal_g_idy,
                                     long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  long xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (XLEN) : ((XLEN * 2))));

  long yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (YLEN) : ((YLEN * 2))));

  long zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (ZLEN) : ((ZLEN * 2))));

  long blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {
                  {
                    long realidx;

                    for ((realidx = 0); (realidx < num_ele);
                         (realidx = (realidx + 1))) {
                      ((y)[((blk_all_len * i) +
                            (realidx +
                             (num_ele * ((xyzx + ovlp) +
                                         (xb * ((xyzy + ovlp) +
                                                (yb * (xyzz + ovlp))))))))] =
                           (a * ({
                              double ret = 0;

                              {
                                long gz;

                                for ((gz = 0); (gz < 2); (gz = (gz + 1))) {
                                  {
                                    long gy;

                                    for ((gy = 0); (gy < 2); (gy = (gy + 1))) {
                                      {
                                        long gx;

                                        for ((gx = 0); (gx < 2);
                                             (gx = (gx + 1))) {
                                          (ret =
                                               (ret +
                                                (1.25000000000000000e-01 *
                                                 (x)[((blk_all_len_2x * i) +
                                                      (realidx +
                                                       (num_ele *
                                                        ((ovlp +
                                                          ((2 * xyzx) +
                                                           (((XLEN == 1))
                                                                ? (0)
                                                                : (gx)))) +
                                                         (xb_2x *
                                                          (((2 * xyzy) +
                                                            (ovlp +
                                                             (((YLEN == 1))
                                                                  ? (0)
                                                                  : (gy)))) +
                                                           (yb_2x *
                                                            ((2 * xyzz) +
                                                             ((((ZLEN == 1))
                                                                   ? (0)
                                                                   : (gz)) +
                                                              ovlp)))))))))])));
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              ret;
                            })));
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
void c_blas_yisax_enlarge_scmc_kernel(double *y, double *x, double a,
                                      long y_cpu_core, long numvec, long XLEN,
                                      long YLEN, long ZLEN, int ovlp,
                                      long xblock, long yblock, long zblock,
                                      int num_ele, long scmc_internal_g_idy,
                                      long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  long xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (XLEN) : ((XLEN * 2))));

  long yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (YLEN) : ((YLEN * 2))));

  long zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (ZLEN) : ((ZLEN * 2))));

  long blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {
                  {
                    long realidx;

                    for ((realidx = 0); (realidx < num_ele);
                         (realidx = (realidx + 1))) {
                      {
                        long gz;

                        for ((gz = 0); (gz < 2); (gz = (gz + 1))) {
                          {
                            long gy;

                            for ((gy = 0); (gy < 2); (gy = (gy + 1))) {
                              {
                                long gx;

                                for ((gx = 0); (gx < 2); (gx = (gx + 1))) {
                                  ((y)[((blk_all_len_2x * i) +
                                        (realidx +
                                         (num_ele *
                                          ((ovlp +
                                            ((2 * xyzx) +
                                             (((XLEN == 1)) ? (0) : (gx)))) +
                                           (xb_2x *
                                            (((2 * xyzy) +
                                              (ovlp +
                                               (((YLEN == 1)) ? (0) : (gy)))) +
                                             (yb_2x *
                                              ((2 * xyzz) +
                                               ((((ZLEN == 1)) ? (0) : (gz)) +
                                                ovlp)))))))))] =
                                       (a *
                                        (1.25000000000000000e-01 *
                                         (x)[((blk_all_len * i) +
                                              (realidx +
                                               (num_ele *
                                                ((xyzx + ovlp) +
                                                 (xb * ((xyzy + ovlp) +
                                                        (yb * (xyzz +
                                                               ovlp))))))))])));
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
      }
    }
  }
}
void c_blas_axpy_shrink_scmc_kernel(double *y, double *x, double a,
                                    long y_cpu_core, long numvec, long XLEN,
                                    long YLEN, long ZLEN, int ovlp, long xblock,
                                    long yblock, long zblock, int num_ele,
                                    long scmc_internal_g_idy,
                                    long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  long xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (XLEN) : ((XLEN * 2))));

  long yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (YLEN) : ((YLEN * 2))));

  long zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (ZLEN) : ((ZLEN * 2))));

  long blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {
                  {
                    long realidx;

                    for ((realidx = 0); (realidx < num_ele);
                         (realidx = (realidx + 1))) {
                      ((y)[((blk_all_len * i) +
                            (realidx +
                             (num_ele * ((xyzx + ovlp) +
                                         (xb * ((xyzy + ovlp) +
                                                (yb * (xyzz + ovlp))))))))] =
                           ((y)[((blk_all_len * i) +
                                 (realidx +
                                  (num_ele *
                                   ((xyzx + ovlp) +
                                    (xb * ((xyzy + ovlp) +
                                           (yb * (xyzz + ovlp))))))))] +
                            (a * ({
                               double ret = 0;

                               {
                                 long gz;

                                 for ((gz = 0); (gz < 2); (gz = (gz + 1))) {
                                   {
                                     long gy;

                                     for ((gy = 0); (gy < 2); (gy = (gy + 1))) {
                                       {
                                         long gx;

                                         for ((gx = 0); (gx < 2);
                                              (gx = (gx + 1))) {
                                           (ret =
                                                (ret +
                                                 (1.25000000000000000e-01 *
                                                  (x)[(
                                                      (blk_all_len_2x * i) +
                                                      (realidx +
                                                       (num_ele *
                                                        ((ovlp +
                                                          ((2 * xyzx) +
                                                           (((XLEN == 1))
                                                                ? (0)
                                                                : (gx)))) +
                                                         (xb_2x *
                                                          (((2 * xyzy) +
                                                            (ovlp +
                                                             (((YLEN == 1))
                                                                  ? (0)
                                                                  : (gy)))) +
                                                           (yb_2x *
                                                            ((2 * xyzz) +
                                                             ((((ZLEN == 1))
                                                                   ? (0)
                                                                   : (gz)) +
                                                              ovlp)))))))))])));
                                         }
                                       }
                                     }
                                   }
                                 }
                               }
                               ret;
                             }))));
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
void c_blas_axpy_enlarge_scmc_kernel(double *y, double *x, double a,
                                     long y_cpu_core, long numvec, long XLEN,
                                     long YLEN, long ZLEN, int ovlp,
                                     long xblock, long yblock, long zblock,
                                     int num_ele, long scmc_internal_g_idy,
                                     long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  long xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (XLEN) : ((XLEN * 2))));

  long yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (YLEN) : ((YLEN * 2))));

  long zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (ZLEN) : ((ZLEN * 2))));

  long blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {
                  {
                    long realidx;

                    for ((realidx = 0); (realidx < num_ele);
                         (realidx = (realidx + 1))) {
                      {
                        long gz;

                        for ((gz = 0); (gz < 2); (gz = (gz + 1))) {
                          {
                            long gy;

                            for ((gy = 0); (gy < 2); (gy = (gy + 1))) {
                              {
                                long gx;

                                for ((gx = 0); (gx < 2); (gx = (gx + 1))) {
                                  ((y)[((blk_all_len_2x * i) +
                                        (realidx +
                                         (num_ele *
                                          ((ovlp +
                                            ((2 * xyzx) +
                                             (((XLEN == 1)) ? (0) : (gx)))) +
                                           (xb_2x *
                                            (((2 * xyzy) +
                                              (ovlp +
                                               (((YLEN == 1)) ? (0) : (gy)))) +
                                             (yb_2x *
                                              ((2 * xyzz) +
                                               ((((ZLEN == 1)) ? (0) : (gz)) +
                                                ovlp)))))))))] =
                                       ((y)[((blk_all_len_2x * i) +
                                             (realidx +
                                              (num_ele *
                                               ((ovlp +
                                                 ((2 * xyzx) + (((XLEN == 1))
                                                                    ? (0)
                                                                    : (gx)))) +
                                                (xb_2x *
                                                 (((2 * xyzy) +
                                                   (ovlp + (((YLEN == 1))
                                                                ? (0)
                                                                : (gy)))) +
                                                  (yb_2x *
                                                   ((2 * xyzz) +
                                                    ((((ZLEN == 1)) ? (0)
                                                                    : (gz)) +
                                                     ovlp)))))))))] +
                                        (a *
                                         (1.25000000000000000e-01 *
                                          (x)[((blk_all_len * i) +
                                               (realidx +
                                                (num_ele *
                                                 ((xyzx + ovlp) +
                                                  (xb *
                                                   ((xyzy + ovlp) +
                                                    (yb *
                                                     (xyzz + ovlp))))))))]))));
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
      }
    }
  }
}
void c_blas_axpby_shrink_scmc_kernel(double *y, double *x, double a, double b,
                                     long y_cpu_core, long numvec, long XLEN,
                                     long YLEN, long ZLEN, int ovlp,
                                     long xblock, long yblock, long zblock,
                                     int num_ele, long scmc_internal_g_idy,
                                     long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  long xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (XLEN) : ((XLEN * 2))));

  long yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (YLEN) : ((YLEN * 2))));

  long zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (ZLEN) : ((ZLEN * 2))));

  long blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {
                  {
                    long realidx;

                    for ((realidx = 0); (realidx < num_ele);
                         (realidx = (realidx + 1))) {
                      ((y)[((blk_all_len * i) +
                            (realidx +
                             (num_ele * ((xyzx + ovlp) +
                                         (xb * ((xyzy + ovlp) +
                                                (yb * (xyzz + ovlp))))))))] =
                           ((a * ({
                               double ret = 0;

                               {
                                 long gz;

                                 for ((gz = 0); (gz < 2); (gz = (gz + 1))) {
                                   {
                                     long gy;

                                     for ((gy = 0); (gy < 2); (gy = (gy + 1))) {
                                       {
                                         long gx;

                                         for ((gx = 0); (gx < 2);
                                              (gx = (gx + 1))) {
                                           (ret =
                                                (ret +
                                                 (1.25000000000000000e-01 *
                                                  (x)[(
                                                      (blk_all_len_2x * i) +
                                                      (realidx +
                                                       (num_ele *
                                                        ((ovlp +
                                                          ((2 * xyzx) +
                                                           (((XLEN == 1))
                                                                ? (0)
                                                                : (gx)))) +
                                                         (xb_2x *
                                                          (((2 * xyzy) +
                                                            (ovlp +
                                                             (((YLEN == 1))
                                                                  ? (0)
                                                                  : (gy)))) +
                                                           (yb_2x *
                                                            ((2 * xyzz) +
                                                             ((((ZLEN == 1))
                                                                   ? (0)
                                                                   : (gz)) +
                                                              ovlp)))))))))])));
                                         }
                                       }
                                     }
                                   }
                                 }
                               }
                               ret;
                             })) +
                            (b * (y)[((blk_all_len * i) +
                                      (realidx +
                                       (num_ele *
                                        ((xyzx + ovlp) +
                                         (xb * ((xyzy + ovlp) +
                                                (yb * (xyzz + ovlp))))))))])));
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
void c_blas_axpby_enlarge_scmc_kernel(double *y, double *x, double a, double b,
                                      long y_cpu_core, long numvec, long XLEN,
                                      long YLEN, long ZLEN, int ovlp,
                                      long xblock, long yblock, long zblock,
                                      int num_ele, long scmc_internal_g_idy,
                                      long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long local_ynum = (((numvec - 1) / y_cpu_core) + 1);

  long local_ymin = (__idy * local_ynum);

  long local_ymax = ((1 + __idy) * local_ynum);

  long xb = xblock;

  long yb = yblock;

  long zb = zblock;

  long blk_all_len = (xb * (yb * (zb * num_ele)));

  long xb_2x = ((2 * ovlp) + (((XLEN == 1)) ? (XLEN) : ((XLEN * 2))));

  long yb_2x = ((2 * ovlp) + (((YLEN == 1)) ? (YLEN) : ((YLEN * 2))));

  long zb_2x = ((2 * ovlp) + (((ZLEN == 1)) ? (ZLEN) : ((ZLEN * 2))));

  long blk_all_len_2x = (xb_2x * (yb_2x * (zb_2x * num_ele)));

  {
    long i;

    for ((i = local_ymin); (i < local_ymax); (i = (i + 1))) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < XLEN); (xyzx = (xyzx + 1))) {
                  {
                    long realidx;

                    for ((realidx = 0); (realidx < num_ele);
                         (realidx = (realidx + 1))) {
                      {
                        long gz;

                        for ((gz = 0); (gz < 2); (gz = (gz + 1))) {
                          {
                            long gy;

                            for ((gy = 0); (gy < 2); (gy = (gy + 1))) {
                              {
                                long gx;

                                for ((gx = 0); (gx < 2); (gx = (gx + 1))) {
                                  ((y)[((blk_all_len_2x * i) +
                                        (realidx +
                                         (num_ele *
                                          ((ovlp +
                                            ((2 * xyzx) +
                                             (((XLEN == 1)) ? (0) : (gx)))) +
                                           (xb_2x *
                                            (((2 * xyzy) +
                                              (ovlp +
                                               (((YLEN == 1)) ? (0) : (gy)))) +
                                             (yb_2x *
                                              ((2 * xyzz) +
                                               ((((ZLEN == 1)) ? (0) : (gz)) +
                                                ovlp)))))))))] =
                                       ((a * (1.25000000000000000e-01 *
                                              (x)[((blk_all_len * i) +
                                                   (realidx +
                                                    (num_ele *
                                                     ((xyzx + ovlp) +
                                                      (xb *
                                                       ((xyzy + ovlp) +
                                                        (yb * (xyzz +
                                                               ovlp))))))))])) +
                                        (b *
                                         (y)[((blk_all_len_2x * i) +
                                              (realidx +
                                               (num_ele *
                                                ((ovlp +
                                                  ((2 * xyzx) + (((XLEN == 1))
                                                                     ? (0)
                                                                     : (gx)))) +
                                                 (xb_2x *
                                                  (((2 * xyzy) +
                                                    (ovlp + (((YLEN == 1))
                                                                 ? (0)
                                                                 : (gy)))) +
                                                   (yb_2x *
                                                    ((2 * xyzz) +
                                                     ((((ZLEN == 1)) ? (0)
                                                                     : (gz)) +
                                                      ovlp)))))))))])));
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
      }
    }
  }
}

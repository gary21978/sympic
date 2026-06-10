
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 1

#define FULL_MASK 0xffffffff
#include <immintrin.h>

__m256d c_geo_log_simd(__m256d inp) {
  __m256d ret;

  double *pret = &(ret);

  double *pinp = &(inp);

  ((pret)[0] = log((pinp)[0]));
  ((pret)[1] = log((pinp)[1]));
  ((pret)[2] = log((pinp)[2]));
  ((pret)[3] = log((pinp)[3]));
  return ret;
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_ngeo_gc_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[375];
  double shB0[375];
  double shB1[375];
  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long MYGEN572 = 0;

                  for (0; (MYGEN572 < (3 * 5));
                       (MYGEN572 = (MYGEN572 + __xlen))) {
                    int ridx = (MYGEN572 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN574 = 0;

                  for (0; (MYGEN574 < (3 * 5));
                       (MYGEN574 = (MYGEN574 + __xlen))) {
                    int ridx = (MYGEN574 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB0 + total_idx))[ridx] =
                           ((fieldB +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN576 = 0;

                  for (0; (MYGEN576 < (3 * 5));
                       (MYGEN576 = (MYGEN576 + __xlen))) {
                    int ridx = (MYGEN576 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB1 + total_idx))[ridx] =
                           ((fieldB1 +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

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
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 1))) {
          double local_particle_head[6];
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              ((local_particle_head)[stmpg1] = (particle_head_general)[(
                   stmpg1 +
                   ((((g_inner < load0)) ? (g_inner) : ((load0 - 1))) * 6))]);
            }
          }
          double xx1 = (local_particle_head)[0];

          double xy1 = (local_particle_head)[1];

          double xz1 = (local_particle_head)[2];

          double vx0 = (local_particle_head)[3];

          double vy0 = (local_particle_head)[4];

          double vz0 = (local_particle_head)[5];

          (xx1 = (xx1 + -5.00000000000000000e-01));
          (xy1 = (xy1 + -5.00000000000000000e-01));
          (xz1 = (xz1 + -5.00000000000000000e-01));
          double rx = (xx1 - Midx);

          double ry = (xy1 - Midy);

          double rz = (xz1 - Midz);

          double xx0 = (xx1 - (Deltat * vx0));

          double xy0 = (xy1 - (Deltat * vy0));

          double xz0 = (xz1 - (Deltat * vz0));

          double Midx0 = floor(xx0);

          double Midx1 = floor(xx1);

          double Midy0 = floor(xy0);

          double Midy1 = floor(xy1);

          double Midz0 = floor(xz0);

          double Midz1 = floor(xz1);

          double rx0 = (xx0 - Midx0);

          double rx1 = (xx1 - Midx1);

          double ry0 = (xy0 - Midy0);

          double ry1 = (xy1 - Midy1);

          double rz0 = (xz0 - Midz0);

          double rz1 = (xz1 - Midz1);

          double dixx0 = (Midx0 - Midx);

          double dixx1 = (Midx1 - Midx);

          double dixy0 = (Midy0 - Midy);

          double dixy1 = (Midy1 - Midy);

          double dixz0 = (Midz0 - Midz);

          double dixz1 = (Midz1 - Midz);

          double f0_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x0)[i] = 0);
            }
          }
          ((f0_x0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx0)),
                             2)));
          ((f0_x0)[0] = (((f0_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[1] * -(dixx0))));
          ((f0_x0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0)))))));
          ((f0_x0)[1] = (((f0_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[2] * -(dixx0))));
          ((f0_x0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2)))));
          ((f0_x0)[2] = (((f0_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[3] * -(dixx0))));
          ((f0_x0)[4] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((f0_x0)[3] = (((f0_x0)[3] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[4] * -(dixx0))));
          ((f0_x0)[4] = ((f0_x0)[4] * (dixx0 + 1.00000000000000000e+00)));
          double f1_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x0)[i] = 0);
            }
          }
          ((f1_x0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx0))));
          ((f1_x0)[0] = (((f1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[1] * -(dixx0))));
          ((f1_x0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx0)))));
          ((f1_x0)[1] = (((f1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[2] * -(dixx0))));
          ((f1_x0)[3] = (5.00000000000000000e-01 * rx0));
          ((f1_x0)[2] = (((f1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[3] * -(dixx0))));
          ((f1_x0)[3] = ((f1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double if1_x0[5];
          ((if1_x0)[0] = 1);
          ((if1_x0)[1] = 1);
          ((if1_x0)[3] = 0);
          ((if1_x0)[4] = 0);
          ((if1_x0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2))));
          ((if1_x0)[0] = (((if1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[1] * -(dixx0))));
          ((if1_x0)[2] =
               ((2.50000000000000000e-01 * pow(rx0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2))))));
          ((if1_x0)[1] = (((if1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[2] * -(dixx0))));
          ((if1_x0)[3] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((if1_x0)[2] = (((if1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[3] * -(dixx0))));
          ((if1_x0)[3] = ((if1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double f0_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y0)[i] = 0);
            }
          }
          ((f0_y0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry0)),
                             2)));
          ((f0_y0)[0] = (((f0_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[1] * -(dixy0))));
          ((f0_y0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0)))))));
          ((f0_y0)[1] = (((f0_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[2] * -(dixy0))));
          ((f0_y0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2)))));
          ((f0_y0)[2] = (((f0_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[3] * -(dixy0))));
          ((f0_y0)[4] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((f0_y0)[3] = (((f0_y0)[3] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[4] * -(dixy0))));
          ((f0_y0)[4] = ((f0_y0)[4] * (dixy0 + 1.00000000000000000e+00)));
          double f1_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y0)[i] = 0);
            }
          }
          ((f1_y0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry0))));
          ((f1_y0)[0] = (((f1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[1] * -(dixy0))));
          ((f1_y0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry0)))));
          ((f1_y0)[1] = (((f1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[2] * -(dixy0))));
          ((f1_y0)[3] = (5.00000000000000000e-01 * ry0));
          ((f1_y0)[2] = (((f1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[3] * -(dixy0))));
          ((f1_y0)[3] = ((f1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double if1_y0[5];
          ((if1_y0)[0] = 1);
          ((if1_y0)[1] = 1);
          ((if1_y0)[3] = 0);
          ((if1_y0)[4] = 0);
          ((if1_y0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2))));
          ((if1_y0)[0] = (((if1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[1] * -(dixy0))));
          ((if1_y0)[2] =
               ((2.50000000000000000e-01 * pow(ry0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2))))));
          ((if1_y0)[1] = (((if1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[2] * -(dixy0))));
          ((if1_y0)[3] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((if1_y0)[2] = (((if1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[3] * -(dixy0))));
          ((if1_y0)[3] = ((if1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double f0_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z0)[i] = 0);
            }
          }
          ((f0_z0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz0)),
                             2)));
          ((f0_z0)[0] = (((f0_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[1] * -(dixz0))));
          ((f0_z0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0)))))));
          ((f0_z0)[1] = (((f0_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[2] * -(dixz0))));
          ((f0_z0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2)))));
          ((f0_z0)[2] = (((f0_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[3] * -(dixz0))));
          ((f0_z0)[4] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((f0_z0)[3] = (((f0_z0)[3] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[4] * -(dixz0))));
          ((f0_z0)[4] = ((f0_z0)[4] * (dixz0 + 1.00000000000000000e+00)));
          double f1_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z0)[i] = 0);
            }
          }
          ((f1_z0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz0))));
          ((f1_z0)[0] = (((f1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[1] * -(dixz0))));
          ((f1_z0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz0)))));
          ((f1_z0)[1] = (((f1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[2] * -(dixz0))));
          ((f1_z0)[3] = (5.00000000000000000e-01 * rz0));
          ((f1_z0)[2] = (((f1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[3] * -(dixz0))));
          ((f1_z0)[3] = ((f1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double if1_z0[5];
          ((if1_z0)[0] = 1);
          ((if1_z0)[1] = 1);
          ((if1_z0)[3] = 0);
          ((if1_z0)[4] = 0);
          ((if1_z0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2))));
          ((if1_z0)[0] = (((if1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[1] * -(dixz0))));
          ((if1_z0)[2] =
               ((2.50000000000000000e-01 * pow(rz0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2))))));
          ((if1_z0)[1] = (((if1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[2] * -(dixz0))));
          ((if1_z0)[3] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((if1_z0)[2] = (((if1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[3] * -(dixz0))));
          ((if1_z0)[3] = ((if1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double f0_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x1)[i] = 0);
            }
          }
          ((f0_x1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx1)),
                             2)));
          ((f0_x1)[0] = (((f0_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[1] * -(dixx1))));
          ((f0_x1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1)))))));
          ((f0_x1)[1] = (((f0_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[2] * -(dixx1))));
          ((f0_x1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2)))));
          ((f0_x1)[2] = (((f0_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[3] * -(dixx1))));
          ((f0_x1)[4] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((f0_x1)[3] = (((f0_x1)[3] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[4] * -(dixx1))));
          ((f0_x1)[4] = ((f0_x1)[4] * (dixx1 + 1.00000000000000000e+00)));
          double f1_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x1)[i] = 0);
            }
          }
          ((f1_x1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx1))));
          ((f1_x1)[0] = (((f1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[1] * -(dixx1))));
          ((f1_x1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx1)))));
          ((f1_x1)[1] = (((f1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[2] * -(dixx1))));
          ((f1_x1)[3] = (5.00000000000000000e-01 * rx1));
          ((f1_x1)[2] = (((f1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[3] * -(dixx1))));
          ((f1_x1)[3] = ((f1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double if1_x1[5];
          ((if1_x1)[0] = 1);
          ((if1_x1)[1] = 1);
          ((if1_x1)[3] = 0);
          ((if1_x1)[4] = 0);
          ((if1_x1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2))));
          ((if1_x1)[0] = (((if1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[1] * -(dixx1))));
          ((if1_x1)[2] =
               ((2.50000000000000000e-01 * pow(rx1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2))))));
          ((if1_x1)[1] = (((if1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[2] * -(dixx1))));
          ((if1_x1)[3] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((if1_x1)[2] = (((if1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[3] * -(dixx1))));
          ((if1_x1)[3] = ((if1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double f0_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y1)[i] = 0);
            }
          }
          ((f0_y1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry1)),
                             2)));
          ((f0_y1)[0] = (((f0_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[1] * -(dixy1))));
          ((f0_y1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1)))))));
          ((f0_y1)[1] = (((f0_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[2] * -(dixy1))));
          ((f0_y1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2)))));
          ((f0_y1)[2] = (((f0_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[3] * -(dixy1))));
          ((f0_y1)[4] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((f0_y1)[3] = (((f0_y1)[3] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[4] * -(dixy1))));
          ((f0_y1)[4] = ((f0_y1)[4] * (dixy1 + 1.00000000000000000e+00)));
          double f1_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y1)[i] = 0);
            }
          }
          ((f1_y1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry1))));
          ((f1_y1)[0] = (((f1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[1] * -(dixy1))));
          ((f1_y1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry1)))));
          ((f1_y1)[1] = (((f1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[2] * -(dixy1))));
          ((f1_y1)[3] = (5.00000000000000000e-01 * ry1));
          ((f1_y1)[2] = (((f1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[3] * -(dixy1))));
          ((f1_y1)[3] = ((f1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double if1_y1[5];
          ((if1_y1)[0] = 1);
          ((if1_y1)[1] = 1);
          ((if1_y1)[3] = 0);
          ((if1_y1)[4] = 0);
          ((if1_y1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2))));
          ((if1_y1)[0] = (((if1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[1] * -(dixy1))));
          ((if1_y1)[2] =
               ((2.50000000000000000e-01 * pow(ry1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2))))));
          ((if1_y1)[1] = (((if1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[2] * -(dixy1))));
          ((if1_y1)[3] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((if1_y1)[2] = (((if1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[3] * -(dixy1))));
          ((if1_y1)[3] = ((if1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double f0_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z1)[i] = 0);
            }
          }
          ((f0_z1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz1)),
                             2)));
          ((f0_z1)[0] = (((f0_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[1] * -(dixz1))));
          ((f0_z1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1)))))));
          ((f0_z1)[1] = (((f0_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[2] * -(dixz1))));
          ((f0_z1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2)))));
          ((f0_z1)[2] = (((f0_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[3] * -(dixz1))));
          ((f0_z1)[4] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((f0_z1)[3] = (((f0_z1)[3] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[4] * -(dixz1))));
          ((f0_z1)[4] = ((f0_z1)[4] * (dixz1 + 1.00000000000000000e+00)));
          double f1_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z1)[i] = 0);
            }
          }
          ((f1_z1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz1))));
          ((f1_z1)[0] = (((f1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[1] * -(dixz1))));
          ((f1_z1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz1)))));
          ((f1_z1)[1] = (((f1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[2] * -(dixz1))));
          ((f1_z1)[3] = (5.00000000000000000e-01 * rz1));
          ((f1_z1)[2] = (((f1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[3] * -(dixz1))));
          ((f1_z1)[3] = ((f1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double if1_z1[5];
          ((if1_z1)[0] = 1);
          ((if1_z1)[1] = 1);
          ((if1_z1)[3] = 0);
          ((if1_z1)[4] = 0);
          ((if1_z1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2))));
          ((if1_z1)[0] = (((if1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[1] * -(dixz1))));
          ((if1_z1)[2] =
               ((2.50000000000000000e-01 * pow(rz1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2))))));
          ((if1_z1)[1] = (((if1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[2] * -(dixz1))));
          ((if1_z1)[3] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((if1_z1)[2] = (((if1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[3] * -(dixz1))));
          ((if1_z1)[3] = ((if1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double AllEx = 0;

          double AllEy = 0;

          double AllEz = 0;

          {
            long idz;

            for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
              {
                long idy;

                for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
                  {
                    long idx;

                    for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
                      (AllEx =
                           (AllEx +
                            (((shE0)[(0 +
                                      (3 * (idx + (5 * (idy + (idz * 5))))))] +
                              0) *
                             ((f1_x1)[idx] * ((f0_y1)[idy] * (f0_z1)[idz])))));
                      (AllEy =
                           (AllEy +
                            (((shE0)[(1 +
                                      (3 * (idz + (5 * (idx + (idy * 5))))))] +
                              0) *
                             ((f1_y1)[idx] * ((f0_z1)[idy] * (f0_x1)[idz])))));
                      (AllEz =
                           (AllEz +
                            (((shE0)[(2 +
                                      (3 * (idy + (5 * (idz + (idx * 5))))))] +
                              0) *
                             ((f1_z1)[idx] * ((f0_x1)[idy] * (f0_y1)[idz])))));
                    }
                  }
                }
              }
            }
          }
          double allincfvx;

          double allincfvy;

          double allincfvz;

          (allincfvx = (2.00000000000000000e+00 * (Deltat * AllEx)));
          (allincfvy = (2.00000000000000000e+00 * (Deltat * AllEy)));
          (allincfvz = (2.00000000000000000e+00 * (Deltat * AllEz)));
          double DT = Deltat;

          {
            double newvx = vx0;

            double newvy = vy0;

            double newvz = vz0;

            double curB0 = (shB0)[2];

            double dxdt = (allincfvy / curB0);

            double dydt = ((-1 * allincfvx) / curB0);

            double newxx = (dxdt + xx1);

            double newxy = (dydt + xy1);

            double newxz = xz1;

            (newxx = (newxx + 5.00000000000000000e-01));
            (newxy = (newxy + 5.00000000000000000e-01));
            (newxz = (newxz + 5.00000000000000000e-01));
            ((local_particle_head)[0] = newxx);
            ((local_particle_head)[1] = newxy);
            ((local_particle_head)[2] = newxz);
            ((local_particle_head)[3] = newvx);
            ((local_particle_head)[4] = newvy);
            ((local_particle_head)[5] = newvz);
          }
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              if ((g_inner < load0)) {
                ((particle_head_general)[(stmpg1 + (g_inner * 6))] =
                     (local_particle_head)[stmpg1]);

              } else {
                0;
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP1;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP1:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP2;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP2:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[192];
  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 4); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 4); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (4 * (xyzy + (4 * xyzz))));

                {
                  long MYGEN578 = 0;

                  for (0; (MYGEN578 < (3 * 4));
                       (MYGEN578 = (MYGEN578 + __xlen))) {
                    int ridx = (MYGEN578 + __idx);

                    if ((ridx < (3 * 4))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((Bidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + Bidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + Bidz) + ovlp))))))))))[ridx]);

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
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));
              }
            }
          }
        }
      }
    }
    {
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 1))) {
          double local_particle_head[6];
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              ((local_particle_head)[stmpg1] = (particle_head_general)[(
                   stmpg1 +
                   ((((g_inner < load0)) ? (g_inner) : ((load0 - 1))) * 6))]);
            }
          }
          double xx1 = (local_particle_head)[0];

          double xy1 = (local_particle_head)[1];

          double xz1 = (local_particle_head)[2];

          double vx0 = (local_particle_head)[3];

          double vy0 = (local_particle_head)[4];

          double vz0 = (local_particle_head)[5];

          double rx = (xx1 - Midx);

          double ry = (xy1 - Midy);

          double rz = (xz1 - Midz);

          double xx0 = (xx1 - (Deltat * vx0));

          double xy0 = (xy1 - (Deltat * vy0));

          double xz0 = (xz1 - (Deltat * vz0));

          double fEx[4];
          double fEy[4];
          double fEz[4];
          double fdEx[3];
          double fdEy[3];
          double fdEz[3];
          double AllEx = 0;

          double AllEy = 0;

          double AllEz = 0;

          ((fEx)[0] =
               (2.50000000000000000e-01 *
                pow((1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx)),
                    2)));
          ((fEy)[0] =
               (2.50000000000000000e-01 *
                pow((1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry)),
                    2)));
          ((fEz)[0] =
               (2.50000000000000000e-01 *
                pow((1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz)),
                    2)));
          ((fEx)[1] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx)),
                             2) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx)))))));
          ((fEy)[1] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry)),
                             2) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry)))))));
          ((fEz)[1] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz)),
                             2) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz)))))));
          ((fEx)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        ((-2.00000000000000000e+00 * rx) + pow(rx, 2)))));
          ((fEy)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        ((-2.00000000000000000e+00 * ry) + pow(ry, 2)))));
          ((fEz)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        ((-2.00000000000000000e+00 * rz) + pow(rz, 2)))));
          ((fEx)[3] = (2.50000000000000000e-01 * pow(rx, 2)));
          ((fEy)[3] = (2.50000000000000000e-01 * pow(ry, 2)));
          ((fEz)[3] = (2.50000000000000000e-01 * pow(rz, 2)));
          ((fdEx)[0] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx))));
          ((fdEy)[0] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry))));
          ((fdEz)[0] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz))));
          ((fdEx)[1] =
               ((2.50000000000000000e-01 *
                 (2.00000000000000000e+00 +
                  (-2.00000000000000000e+00 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * rx))))) +
                (5.00000000000000000e-01 *
                 (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx)))));
          ((fdEy)[1] =
               ((2.50000000000000000e-01 *
                 (2.00000000000000000e+00 +
                  (-2.00000000000000000e+00 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * ry))))) +
                (5.00000000000000000e-01 *
                 (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry)))));
          ((fdEz)[1] =
               ((2.50000000000000000e-01 *
                 (2.00000000000000000e+00 +
                  (-2.00000000000000000e+00 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * rz))))) +
                (5.00000000000000000e-01 *
                 (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz)))));
          ((fdEx)[2] = (5.00000000000000000e-01 * rx));
          ((fdEy)[2] = (5.00000000000000000e-01 * ry));
          ((fdEz)[2] = (5.00000000000000000e-01 * rz));
          {
            long idz;

            for ((idz = 0); (idz < 4); (idz = (idz + 1))) {
              {
                long idy;

                for ((idy = 0); (idy < 4); (idy = (idy + 1))) {
                  {
                    long idx;

                    for ((idx = 0); (idx < 3); (idx = (idx + 1))) {
                      (AllEx = (AllEx +
                                ((shE0)[(0 + (3 * (idx +
                                                   (4 * (idy + (idz * 4))))))] *
                                 ((fdEx)[idx] * ((fEy)[idy] * (fEz)[idz])))));
                      (AllEy = (AllEy +
                                ((shE0)[(1 + (3 * (idz +
                                                   (4 * (idx + (idy * 4))))))] *
                                 ((fdEy)[idx] * ((fEz)[idy] * (fEx)[idz])))));
                      (AllEz = (AllEz +
                                ((shE0)[(2 + (3 * (idy +
                                                   (4 * (idz + (idx * 4))))))] *
                                 ((fdEz)[idx] * ((fEx)[idy] * (fEy)[idz])))));
                    }
                  }
                }
              }
            }
          }
          (AllEx = 0);
          (AllEy = 0);
          (AllEz = 0);
          double allincfvx;

          double allincfvy;

          double allincfvz;

          (allincfvx = (2.00000000000000000e+00 * (Deltat * AllEx)));
          (allincfvy = (2.00000000000000000e+00 * (Deltat * AllEy)));
          (allincfvz = (2.00000000000000000e+00 * (Deltat * AllEz)));
          double DT = Deltat;

          {
            double x0;

            (x0 = (xx0 + XO));
            double y0 = (xy0 + YO);

            double z0 = ((xz0 + ZO) - zmid);

            double x1 = (xx1 + XO);

            double y1 = (xy1 + YO);

            double z1 = ((xz1 + ZO) - zmid);

            double mzero = 0.00000000000000000e+00;

            double iBx =
                ((-1.00000000000000000e+00 *
                  (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                    0.00000000000000000e+00) *
                   pow(DT, -1.00000000000000000e+00))) +
                 mzero);

            double x2 =
                (((-1.00000000000000000e+00 * x0) +
                  (2.00000000000000000e+00 * x1)) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvx + (-1.00000000000000000e+00 * iBx))))));

            double iBy =
                (pow(DT, -1.00000000000000000e+00) *
                 (0.00000000000000000e+00 +
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (((((((b0 * (pow(r0, 2) * pow(MIN_R0, 2))) +
                         ((-2.00000000000000000e+00 *
                           (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                          ((b0 * (pow(MIN_R0, 2) * pow(TX0, 2))) +
                           ((((-2.00000000000000000e+00 *
                               (b0 * (r0 * pow(MIN_R0, 2)))) +
                              (2.00000000000000000e+00 *
                               (b0 * (pow(MIN_R0, 2) * TX0)))) *
                             x1) +
                            ((b0 * (pow(MIN_R0, 2) * pow(x1, 2))) +
                             (b0 * (pow(MIN_R0, 2) * pow(z1, 2)))))))) *
                        pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                               (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * pow(TX0, 2)))) +
                              ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x1, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x1, 3))) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * (TX0 * pow(z1, 2)))) +
                                  (x1 *
                                   ((((2.00000000000000000e+00 * pow(r0, 2)) +
                                      (2.00000000000000000e+00 *
                                       pow(MIN_R0, 2))) *
                                     Q0) +
                                    ((-8.00000000000000000e+00 *
                                      (r0 * (Q0 * TX0))) +
                                     ((6.00000000000000000e+00 *
                                       (Q0 * pow(TX0, 2))) +
                                      (2.00000000000000000e+00 *
                                       (Q0 * pow(z1, 2))))))))))))),
                            -1)) -
                       (((b0 * (pow(r0, 2) * pow(MIN_R0, 2))) +
                         ((-2.00000000000000000e+00 *
                           (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                          ((b0 * (pow(MIN_R0, 2) * pow(TX0, 2))) +
                           ((((-2.00000000000000000e+00 *
                               (b0 * (r0 * pow(MIN_R0, 2)))) +
                              (2.00000000000000000e+00 *
                               (b0 * (pow(MIN_R0, 2) * TX0)))) *
                             x0) +
                            ((b0 * (pow(MIN_R0, 2) * pow(x0, 2))) +
                             (b0 * (pow(MIN_R0, 2) * pow(z1, 2)))))))) *
                        pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                               (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * pow(TX0, 2)))) +
                              ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x0, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x0, 3))) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * (TX0 * pow(z1, 2)))) +
                                  (x0 *
                                   ((((2.00000000000000000e+00 * pow(r0, 2)) +
                                      (2.00000000000000000e+00 *
                                       pow(MIN_R0, 2))) *
                                     Q0) +
                                    ((-8.00000000000000000e+00 *
                                      (r0 * (Q0 * TX0))) +
                                     ((6.00000000000000000e+00 *
                                       (Q0 * pow(TX0, 2))) +
                                      (2.00000000000000000e+00 *
                                       (Q0 * pow(z1, 2))))))))))))),
                            -1))) +
                      0.00000000000000000e+00) +
                     (((((b0 * (pow(r0, 2) * pow(MIN_R0, 2))) +
                         ((-2.00000000000000000e+00 *
                           (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                          ((b0 * (pow(MIN_R0, 2) * pow(TX0, 2))) +
                           ((((-2.00000000000000000e+00 *
                               (b0 * (r0 * pow(MIN_R0, 2)))) +
                              (2.00000000000000000e+00 *
                               (b0 * (pow(MIN_R0, 2) * TX0)))) *
                             x2) +
                            ((b0 * (pow(MIN_R0, 2) * pow(x2, 2))) +
                             (b0 * (pow(MIN_R0, 2) * pow(z1, 2)))))))) *
                        pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                               (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * pow(TX0, 2)))) +
                              ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x2, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x2, 3))) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * (TX0 * pow(z1, 2)))) +
                                  (x2 *
                                   ((((2.00000000000000000e+00 * pow(r0, 2)) +
                                      (2.00000000000000000e+00 *
                                       pow(MIN_R0, 2))) *
                                     Q0) +
                                    ((-8.00000000000000000e+00 *
                                      (r0 * (Q0 * TX0))) +
                                     ((6.00000000000000000e+00 *
                                       (Q0 * pow(TX0, 2))) +
                                      (2.00000000000000000e+00 *
                                       (Q0 * pow(z1, 2))))))))))))),
                            -1)) -
                       (((b0 * (pow(r0, 2) * pow(MIN_R0, 2))) +
                         ((-2.00000000000000000e+00 *
                           (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                          ((b0 * (pow(MIN_R0, 2) * pow(TX0, 2))) +
                           ((((-2.00000000000000000e+00 *
                               (b0 * (r0 * pow(MIN_R0, 2)))) +
                              (2.00000000000000000e+00 *
                               (b0 * (pow(MIN_R0, 2) * TX0)))) *
                             x1) +
                            ((b0 * (pow(MIN_R0, 2) * pow(x1, 2))) +
                             (b0 * (pow(MIN_R0, 2) * pow(z1, 2)))))))) *
                        pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                               (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * pow(TX0, 2)))) +
                              ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x1, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x1, 3))) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * (TX0 * pow(z1, 2)))) +
                                  (x1 *
                                   ((((2.00000000000000000e+00 * pow(r0, 2)) +
                                      (2.00000000000000000e+00 *
                                       pow(MIN_R0, 2))) *
                                     Q0) +
                                    ((-8.00000000000000000e+00 *
                                      (r0 * (Q0 * TX0))) +
                                     ((6.00000000000000000e+00 *
                                       (Q0 * pow(TX0, 2))) +
                                      (2.00000000000000000e+00 *
                                       (Q0 * pow(z1, 2))))))))))))),
                            -1))) +
                      0.00000000000000000e+00)) *
                    DT))));

            double y2 =
                ((pow((pow(TX0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))),
                      -1.00000000000000000e+00) *
                  ((((-1.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((-2.00000000000000000e+00 * (TX0 * x0)) +
                      (-1.00000000000000000e+00 *
                       pow(x0, 2.00000000000000000e+00)))) *
                    y0) +
                   (((2.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((2.00000000000000000e+00 * (TX0 * x0)) +
                      (pow(x0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))))) *
                    y1))) +
                 (pow(TX0, 2.00000000000000000e+00) *
                  ((QE_MASS *
                    (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
                   pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                         pow(TX0, 2.00000000000000000e+00)) +
                        ((2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) *
                           (TX0 * x2))) +
                         (pow(DELTA_Y, 2.00000000000000000e+00) *
                          pow(x2, 2.00000000000000000e+00)))),
                       -1.00000000000000000e+00))));

            double iBz =
                (-1.00000000000000000e+00 *
                 (pow(DT, -1.00000000000000000e+00) *
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (0.00000000000000000e+00 +
                    (((-1.00000000000000000e+00 *
                       (((-1.00000000000000000e+00 *
                          (b0 *
                           (pow(MIN_R0, 4) *
                            (y1 *
                             (z1 *
                              pow((((pow(r0, 4) +
                                     ((2.00000000000000000e+00 *
                                       (pow(r0, 2) * pow(MIN_R0, 2))) +
                                      pow(MIN_R0, 4))) *
                                    (Q0 * TX0)) +
                                   ((((-4.00000000000000000e+00 * pow(r0, 3)) +
                                      (-4.00000000000000000e+00 *
                                       (r0 * pow(MIN_R0, 2)))) *
                                     (Q0 * pow(TX0, 2))) +
                                    ((((6.00000000000000000e+00 * pow(r0, 2)) +
                                       (2.00000000000000000e+00 *
                                        pow(MIN_R0, 2))) *
                                      (Q0 * pow(TX0, 3))) +
                                     ((-4.00000000000000000e+00 *
                                       (r0 * (Q0 * pow(TX0, 4)))) +
                                      ((Q0 * pow(TX0, 5)) +
                                       (((((pow(r0, 4) +
                                            ((2.00000000000000000e+00 *
                                              (pow(r0, 2) * pow(MIN_R0, 2))) +
                                             pow(MIN_R0, 4))) *
                                           Q0) +
                                          ((((-8.00000000000000000e+00 *
                                              pow(r0, 3)) +
                                             (-8.00000000000000000e+00 *
                                              (r0 * pow(MIN_R0, 2)))) *
                                            (Q0 * TX0)) +
                                           ((((1.80000000000000000e+01 *
                                               pow(r0, 2)) +
                                              (6.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * pow(TX0, 2))) +
                                            ((-1.60000000000000000e+01 *
                                              (r0 * (Q0 * pow(TX0, 3)))) +
                                             (5.00000000000000000e+00 *
                                              (Q0 * pow(TX0, 4))))))) *
                                         x0) +
                                        ((((((-4.00000000000000000e+00 *
                                              pow(r0, 3)) +
                                             (-4.00000000000000000e+00 *
                                              (r0 * pow(MIN_R0, 2)))) *
                                            Q0) +
                                           ((((1.80000000000000000e+01 *
                                               pow(r0, 2)) +
                                              (6.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * TX0)) +
                                            ((-2.40000000000000000e+01 *
                                              (r0 * (Q0 * pow(TX0, 2)))) +
                                             (1.00000000000000000e+01 *
                                              (Q0 * pow(TX0, 3)))))) *
                                          pow(x0, 2)) +
                                         ((((((6.00000000000000000e+00 *
                                               pow(r0, 2)) +
                                              (2.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             Q0) +
                                            ((-1.60000000000000000e+01 *
                                              (r0 * (Q0 * TX0))) +
                                             (1.00000000000000000e+01 *
                                              (Q0 * pow(TX0, 2))))) *
                                           pow(x0, 3)) +
                                          ((((-4.00000000000000000e+00 *
                                              (r0 * Q0)) +
                                             (5.00000000000000000e+00 *
                                              (Q0 * TX0))) *
                                            pow(x0, 4)) +
                                           ((Q0 * pow(x0, 5)) +
                                            ((((((2.00000000000000000e+00 *
                                                  pow(r0, 2)) +
                                                 (2.00000000000000000e+00 *
                                                  pow(MIN_R0, 2))) *
                                                (Q0 * TX0)) +
                                               ((-4.00000000000000000e+00 *
                                                 (r0 * (Q0 * pow(TX0, 2)))) +
                                                ((2.00000000000000000e+00 *
                                                  (Q0 * pow(TX0, 3))) +
                                                 ((((((2.00000000000000000e+00 *
                                                       pow(r0, 2)) +
                                                      (2.00000000000000000e+00 *
                                                       pow(MIN_R0, 2))) *
                                                     Q0) +
                                                    ((-8.00000000000000000e+00 *
                                                      (r0 * (Q0 * TX0))) +
                                                     (6.00000000000000000e+00 *
                                                      (Q0 * pow(TX0, 2))))) *
                                                   x0) +
                                                  ((((-4.00000000000000000e+00 *
                                                      (r0 * Q0)) +
                                                     (6.00000000000000000e+00 *
                                                      (Q0 * TX0))) *
                                                    pow(x0, 2)) +
                                                   (2.00000000000000000e+00 *
                                                    (Q0 * pow(x0, 3)))))))) *
                                              pow(z1, 2)) +
                                             (((Q0 * TX0) + (Q0 * x0)) *
                                              pow(z1, 4))))))))))))),
                                  -1)))))) -
                         (-1.00000000000000000e+00 *
                          (b0 *
                           (pow(MIN_R0, 4) *
                            (y0 *
                             (z1 *
                              pow((((pow(r0, 4) +
                                     ((2.00000000000000000e+00 *
                                       (pow(r0, 2) * pow(MIN_R0, 2))) +
                                      pow(MIN_R0, 4))) *
                                    (Q0 * TX0)) +
                                   ((((-4.00000000000000000e+00 * pow(r0, 3)) +
                                      (-4.00000000000000000e+00 *
                                       (r0 * pow(MIN_R0, 2)))) *
                                     (Q0 * pow(TX0, 2))) +
                                    ((((6.00000000000000000e+00 * pow(r0, 2)) +
                                       (2.00000000000000000e+00 *
                                        pow(MIN_R0, 2))) *
                                      (Q0 * pow(TX0, 3))) +
                                     ((-4.00000000000000000e+00 *
                                       (r0 * (Q0 * pow(TX0, 4)))) +
                                      ((Q0 * pow(TX0, 5)) +
                                       (((((pow(r0, 4) +
                                            ((2.00000000000000000e+00 *
                                              (pow(r0, 2) * pow(MIN_R0, 2))) +
                                             pow(MIN_R0, 4))) *
                                           Q0) +
                                          ((((-8.00000000000000000e+00 *
                                              pow(r0, 3)) +
                                             (-8.00000000000000000e+00 *
                                              (r0 * pow(MIN_R0, 2)))) *
                                            (Q0 * TX0)) +
                                           ((((1.80000000000000000e+01 *
                                               pow(r0, 2)) +
                                              (6.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * pow(TX0, 2))) +
                                            ((-1.60000000000000000e+01 *
                                              (r0 * (Q0 * pow(TX0, 3)))) +
                                             (5.00000000000000000e+00 *
                                              (Q0 * pow(TX0, 4))))))) *
                                         x0) +
                                        ((((((-4.00000000000000000e+00 *
                                              pow(r0, 3)) +
                                             (-4.00000000000000000e+00 *
                                              (r0 * pow(MIN_R0, 2)))) *
                                            Q0) +
                                           ((((1.80000000000000000e+01 *
                                               pow(r0, 2)) +
                                              (6.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * TX0)) +
                                            ((-2.40000000000000000e+01 *
                                              (r0 * (Q0 * pow(TX0, 2)))) +
                                             (1.00000000000000000e+01 *
                                              (Q0 * pow(TX0, 3)))))) *
                                          pow(x0, 2)) +
                                         ((((((6.00000000000000000e+00 *
                                               pow(r0, 2)) +
                                              (2.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             Q0) +
                                            ((-1.60000000000000000e+01 *
                                              (r0 * (Q0 * TX0))) +
                                             (1.00000000000000000e+01 *
                                              (Q0 * pow(TX0, 2))))) *
                                           pow(x0, 3)) +
                                          ((((-4.00000000000000000e+00 *
                                              (r0 * Q0)) +
                                             (5.00000000000000000e+00 *
                                              (Q0 * TX0))) *
                                            pow(x0, 4)) +
                                           ((Q0 * pow(x0, 5)) +
                                            ((((((2.00000000000000000e+00 *
                                                  pow(r0, 2)) +
                                                 (2.00000000000000000e+00 *
                                                  pow(MIN_R0, 2))) *
                                                (Q0 * TX0)) +
                                               ((-4.00000000000000000e+00 *
                                                 (r0 * (Q0 * pow(TX0, 2)))) +
                                                ((2.00000000000000000e+00 *
                                                  (Q0 * pow(TX0, 3))) +
                                                 ((((((2.00000000000000000e+00 *
                                                       pow(r0, 2)) +
                                                      (2.00000000000000000e+00 *
                                                       pow(MIN_R0, 2))) *
                                                     Q0) +
                                                    ((-8.00000000000000000e+00 *
                                                      (r0 * (Q0 * TX0))) +
                                                     (6.00000000000000000e+00 *
                                                      (Q0 * pow(TX0, 2))))) *
                                                   x0) +
                                                  ((((-4.00000000000000000e+00 *
                                                      (r0 * Q0)) +
                                                     (6.00000000000000000e+00 *
                                                      (Q0 * TX0))) *
                                                    pow(x0, 2)) +
                                                   (2.00000000000000000e+00 *
                                                    (Q0 * pow(x0, 3)))))))) *
                                              pow(z1, 2)) +
                                             (((Q0 * TX0) + (Q0 * x0)) *
                                              pow(z1, 4))))))))))))),
                                  -1))))))) +
                        0.00000000000000000e+00)) +
                      ((((b0 * (r0 * log((TX0 + x1)))) -
                         (b0 * (r0 * log((TX0 + x0))))) +
                        0.00000000000000000e+00) +
                       ((-1.00000000000000000e+00 *
                         (((-1.00000000000000000e+00 *
                            (b0 *
                             (pow(MIN_R0, 4) *
                              (y2 *
                               (z1 *
                                pow((((pow(r0, 4) +
                                       ((2.00000000000000000e+00 *
                                         (pow(r0, 2) * pow(MIN_R0, 2))) +
                                        pow(MIN_R0, 4))) *
                                      (Q0 * TX0)) +
                                     ((((-4.00000000000000000e+00 *
                                         pow(r0, 3)) +
                                        (-4.00000000000000000e+00 *
                                         (r0 * pow(MIN_R0, 2)))) *
                                       (Q0 * pow(TX0, 2))) +
                                      ((((6.00000000000000000e+00 *
                                          pow(r0, 2)) +
                                         (2.00000000000000000e+00 *
                                          pow(MIN_R0, 2))) *
                                        (Q0 * pow(TX0, 3))) +
                                       ((-4.00000000000000000e+00 *
                                         (r0 * (Q0 * pow(TX0, 4)))) +
                                        ((Q0 * pow(TX0, 5)) +
                                         (((((pow(r0, 4) +
                                              ((2.00000000000000000e+00 *
                                                (pow(r0, 2) * pow(MIN_R0, 2))) +
                                               pow(MIN_R0, 4))) *
                                             Q0) +
                                            ((((-8.00000000000000000e+00 *
                                                pow(r0, 3)) +
                                               (-8.00000000000000000e+00 *
                                                (r0 * pow(MIN_R0, 2)))) *
                                              (Q0 * TX0)) +
                                             ((((1.80000000000000000e+01 *
                                                 pow(r0, 2)) +
                                                (6.00000000000000000e+00 *
                                                 pow(MIN_R0, 2))) *
                                               (Q0 * pow(TX0, 2))) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 * (Q0 * pow(TX0, 3)))) +
                                               (5.00000000000000000e+00 *
                                                (Q0 * pow(TX0, 4))))))) *
                                           x2) +
                                          ((((((-4.00000000000000000e+00 *
                                                pow(r0, 3)) +
                                               (-4.00000000000000000e+00 *
                                                (r0 * pow(MIN_R0, 2)))) *
                                              Q0) +
                                             ((((1.80000000000000000e+01 *
                                                 pow(r0, 2)) +
                                                (6.00000000000000000e+00 *
                                                 pow(MIN_R0, 2))) *
                                               (Q0 * TX0)) +
                                              ((-2.40000000000000000e+01 *
                                                (r0 * (Q0 * pow(TX0, 2)))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * pow(TX0, 3)))))) *
                                            pow(x2, 2)) +
                                           ((((((6.00000000000000000e+00 *
                                                 pow(r0, 2)) +
                                                (2.00000000000000000e+00 *
                                                 pow(MIN_R0, 2))) *
                                               Q0) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 * (Q0 * TX0))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * pow(TX0, 2))))) *
                                             pow(x2, 3)) +
                                            ((((-4.00000000000000000e+00 *
                                                (r0 * Q0)) +
                                               (5.00000000000000000e+00 *
                                                (Q0 * TX0))) *
                                              pow(x2, 4)) +
                                             ((Q0 * pow(x2, 5)) +
                                              ((((((2.00000000000000000e+00 *
                                                    pow(r0, 2)) +
                                                   (2.00000000000000000e+00 *
                                                    pow(MIN_R0, 2))) *
                                                  (Q0 * TX0)) +
                                                 ((-4.00000000000000000e+00 *
                                                   (r0 * (Q0 * pow(TX0, 2)))) +
                                                  ((2.00000000000000000e+00 *
                                                    (Q0 * pow(TX0, 3))) +
                                                   ((((((2.00000000000000000e+00 *
                                                         pow(r0, 2)) +
                                                        (2.00000000000000000e+00 *
                                                         pow(MIN_R0, 2))) *
                                                       Q0) +
                                                      ((-8.00000000000000000e+00 *
                                                        (r0 * (Q0 * TX0))) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * pow(TX0, 2))))) *
                                                     x2) +
                                                    ((((-4.00000000000000000e+00 *
                                                        (r0 * Q0)) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * TX0))) *
                                                      pow(x2, 2)) +
                                                     (2.00000000000000000e+00 *
                                                      (Q0 * pow(x2, 3)))))))) *
                                                pow(z1, 2)) +
                                               (((Q0 * TX0) + (Q0 * x2)) *
                                                pow(z1, 4))))))))))))),
                                    -1)))))) -
                           (-1.00000000000000000e+00 *
                            (b0 *
                             (pow(MIN_R0, 4) *
                              (y1 *
                               (z1 *
                                pow((((pow(r0, 4) +
                                       ((2.00000000000000000e+00 *
                                         (pow(r0, 2) * pow(MIN_R0, 2))) +
                                        pow(MIN_R0, 4))) *
                                      (Q0 * TX0)) +
                                     ((((-4.00000000000000000e+00 *
                                         pow(r0, 3)) +
                                        (-4.00000000000000000e+00 *
                                         (r0 * pow(MIN_R0, 2)))) *
                                       (Q0 * pow(TX0, 2))) +
                                      ((((6.00000000000000000e+00 *
                                          pow(r0, 2)) +
                                         (2.00000000000000000e+00 *
                                          pow(MIN_R0, 2))) *
                                        (Q0 * pow(TX0, 3))) +
                                       ((-4.00000000000000000e+00 *
                                         (r0 * (Q0 * pow(TX0, 4)))) +
                                        ((Q0 * pow(TX0, 5)) +
                                         (((((pow(r0, 4) +
                                              ((2.00000000000000000e+00 *
                                                (pow(r0, 2) * pow(MIN_R0, 2))) +
                                               pow(MIN_R0, 4))) *
                                             Q0) +
                                            ((((-8.00000000000000000e+00 *
                                                pow(r0, 3)) +
                                               (-8.00000000000000000e+00 *
                                                (r0 * pow(MIN_R0, 2)))) *
                                              (Q0 * TX0)) +
                                             ((((1.80000000000000000e+01 *
                                                 pow(r0, 2)) +
                                                (6.00000000000000000e+00 *
                                                 pow(MIN_R0, 2))) *
                                               (Q0 * pow(TX0, 2))) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 * (Q0 * pow(TX0, 3)))) +
                                               (5.00000000000000000e+00 *
                                                (Q0 * pow(TX0, 4))))))) *
                                           x2) +
                                          ((((((-4.00000000000000000e+00 *
                                                pow(r0, 3)) +
                                               (-4.00000000000000000e+00 *
                                                (r0 * pow(MIN_R0, 2)))) *
                                              Q0) +
                                             ((((1.80000000000000000e+01 *
                                                 pow(r0, 2)) +
                                                (6.00000000000000000e+00 *
                                                 pow(MIN_R0, 2))) *
                                               (Q0 * TX0)) +
                                              ((-2.40000000000000000e+01 *
                                                (r0 * (Q0 * pow(TX0, 2)))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * pow(TX0, 3)))))) *
                                            pow(x2, 2)) +
                                           ((((((6.00000000000000000e+00 *
                                                 pow(r0, 2)) +
                                                (2.00000000000000000e+00 *
                                                 pow(MIN_R0, 2))) *
                                               Q0) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 * (Q0 * TX0))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * pow(TX0, 2))))) *
                                             pow(x2, 3)) +
                                            ((((-4.00000000000000000e+00 *
                                                (r0 * Q0)) +
                                               (5.00000000000000000e+00 *
                                                (Q0 * TX0))) *
                                              pow(x2, 4)) +
                                             ((Q0 * pow(x2, 5)) +
                                              ((((((2.00000000000000000e+00 *
                                                    pow(r0, 2)) +
                                                   (2.00000000000000000e+00 *
                                                    pow(MIN_R0, 2))) *
                                                  (Q0 * TX0)) +
                                                 ((-4.00000000000000000e+00 *
                                                   (r0 * (Q0 * pow(TX0, 2)))) +
                                                  ((2.00000000000000000e+00 *
                                                    (Q0 * pow(TX0, 3))) +
                                                   ((((((2.00000000000000000e+00 *
                                                         pow(r0, 2)) +
                                                        (2.00000000000000000e+00 *
                                                         pow(MIN_R0, 2))) *
                                                       Q0) +
                                                      ((-8.00000000000000000e+00 *
                                                        (r0 * (Q0 * TX0))) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * pow(TX0, 2))))) *
                                                     x2) +
                                                    ((((-4.00000000000000000e+00 *
                                                        (r0 * Q0)) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * TX0))) *
                                                      pow(x2, 2)) +
                                                     (2.00000000000000000e+00 *
                                                      (Q0 * pow(x2, 3)))))))) *
                                                pow(z1, 2)) +
                                               (((Q0 * TX0) + (Q0 * x2)) *
                                                pow(z1, 4))))))))))))),
                                    -1))))))) +
                          0.00000000000000000e+00)) +
                        (((b0 * (r0 * log((TX0 + x2)))) -
                          (b0 * (r0 * log((TX0 + x1))))) +
                         0.00000000000000000e+00)))) *
                     DT)))));

            double z2 =
                (((-1.00000000000000000e+00 * z0) +
                  (2.00000000000000000e+00 * z1)) +
                 (pow(DELTA_Z, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

            (iBz = 0.00000000000000000e+00);
            double z3 = (((-1.00000000000000000e+00 * z1) +
                          (2.00000000000000000e+00 * z2)) +
                         (pow(DELTA_Z, -2.00000000000000000e+00) *
                          (-1 * (Deltat * (QE_MASS * iBz)))));

            (iBy =
                 ((-1.00000000000000000e+00 *
                   (((b0 *
                      (pow(MIN_R0, 4) *
                       pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                              (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                             (Q0 * TX0)) +
                            ((-4.00000000000000000e+00 *
                              (r0 * (Q0 * pow(TX0, 2)))) +
                             ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                              ((((((2.00000000000000000e+00 * pow(r0, 2)) +
                                   (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  Q0) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * TX0))) +
                                  (6.00000000000000000e+00 *
                                   (Q0 * pow(TX0, 2))))) *
                                x2) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x2, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x2, 3))) +
                                 (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                   (2.00000000000000000e+00 * (Q0 * x2))) *
                                  pow(z2, 2)))))))),
                           -1))) -
                     (b0 *
                      (pow(MIN_R0, 4) *
                       pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                              (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                             (Q0 * TX0)) +
                            ((-4.00000000000000000e+00 *
                              (r0 * (Q0 * pow(TX0, 2)))) +
                             ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                              ((((((2.00000000000000000e+00 * pow(r0, 2)) +
                                   (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  Q0) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * TX0))) +
                                  (6.00000000000000000e+00 *
                                   (Q0 * pow(TX0, 2))))) *
                                x2) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x2, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x2, 3))) +
                                 (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                   (2.00000000000000000e+00 * (Q0 * x2))) *
                                  pow(z1, 2)))))))),
                           -1)))) +
                    0.00000000000000000e+00)) +
                  (-1.00000000000000000e+00 *
                   (((b0 *
                      (pow(MIN_R0, 4) *
                       pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                              (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                             (Q0 * TX0)) +
                            ((-4.00000000000000000e+00 *
                              (r0 * (Q0 * pow(TX0, 2)))) +
                             ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                              ((((((2.00000000000000000e+00 * pow(r0, 2)) +
                                   (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  Q0) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * TX0))) +
                                  (6.00000000000000000e+00 *
                                   (Q0 * pow(TX0, 2))))) *
                                x2) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x2, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x2, 3))) +
                                 (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                   (2.00000000000000000e+00 * (Q0 * x2))) *
                                  pow(z3, 2)))))))),
                           -1))) -
                     (b0 *
                      (pow(MIN_R0, 4) *
                       pow(((((2.00000000000000000e+00 * pow(r0, 2)) +
                              (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                             (Q0 * TX0)) +
                            ((-4.00000000000000000e+00 *
                              (r0 * (Q0 * pow(TX0, 2)))) +
                             ((2.00000000000000000e+00 * (Q0 * pow(TX0, 3))) +
                              ((((((2.00000000000000000e+00 * pow(r0, 2)) +
                                   (2.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  Q0) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * TX0))) +
                                  (6.00000000000000000e+00 *
                                   (Q0 * pow(TX0, 2))))) *
                                x2) +
                               ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                  (6.00000000000000000e+00 * (Q0 * TX0))) *
                                 pow(x2, 2)) +
                                ((2.00000000000000000e+00 * (Q0 * pow(x2, 3))) +
                                 (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                   (2.00000000000000000e+00 * (Q0 * x2))) *
                                  pow(z2, 2)))))))),
                           -1)))) +
                    0.00000000000000000e+00))));
            double y3 = (((-1.00000000000000000e+00 * y1) +
                          (2.00000000000000000e+00 * y2)) +
                         (pow(TX0, 2.00000000000000000e+00) *
                          ((-1 * (Deltat * (QE_MASS * iBy))) *
                           pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                                 pow(TX0, 2.00000000000000000e+00)) +
                                ((2.00000000000000000e+00 *
                                  (pow(DELTA_Y, 2.00000000000000000e+00) *
                                   (TX0 * x2))) +
                                 (pow(DELTA_Y, 2.00000000000000000e+00) *
                                  pow(x2, 2.00000000000000000e+00)))),
                               -1.00000000000000000e+00))));

            (iBx =
                 ((((b0 * (r0 * (pow((TX0 + x2), -1) * z2))) -
                    (b0 * (r0 * (pow((TX0 + x2), -1) * z1)))) +
                   0.00000000000000000e+00) +
                  ((((b0 * (r0 * (pow((TX0 + x2), -1) * z3))) -
                     (b0 * (r0 * (pow((TX0 + x2), -1) * z2)))) +
                    0.00000000000000000e+00) +
                   ((-1.00000000000000000e+00 *
                     (((-1.00000000000000000e+00 *
                        (y2 *
                         (((b0 * (pow(r0, 4) * pow(MIN_R0, 2))) +
                           ((b0 * (pow(r0, 2) * pow(MIN_R0, 4))) +
                            ((-4.00000000000000000e+00 *
                              (b0 * (pow(r0, 3) * (pow(MIN_R0, 2) * TX0)))) +
                             ((((6.00000000000000000e+00 *
                                 (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                (-1.00000000000000000e+00 *
                                 (b0 * pow(MIN_R0, 4)))) *
                               pow(TX0, 2)) +
                              ((-4.00000000000000000e+00 *
                                (b0 * (r0 * (pow(MIN_R0, 2) * pow(TX0, 3))))) +
                               ((b0 * (pow(MIN_R0, 2) * pow(TX0, 4))) +
                                ((((-4.00000000000000000e+00 *
                                    (b0 * (pow(r0, 3) * pow(MIN_R0, 2)))) +
                                   ((((1.20000000000000000e+01 *
                                       (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                      (-2.00000000000000000e+00 *
                                       (b0 * pow(MIN_R0, 4)))) *
                                     TX0) +
                                    ((-1.20000000000000000e+01 *
                                      (b0 *
                                       (r0 * (pow(MIN_R0, 2) * pow(TX0, 2))))) +
                                     (4.00000000000000000e+00 *
                                      (b0 *
                                       (pow(MIN_R0, 2) * pow(TX0, 3))))))) *
                                  x2) +
                                 ((((6.00000000000000000e+00 *
                                     (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                    ((-1.00000000000000000e+00 *
                                      (b0 * pow(MIN_R0, 4))) +
                                     ((-1.20000000000000000e+01 *
                                       (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                      (6.00000000000000000e+00 *
                                       (b0 *
                                        (pow(MIN_R0, 2) * pow(TX0, 2))))))) *
                                   pow(x2, 2)) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * (r0 * pow(MIN_R0, 2)))) +
                                     (4.00000000000000000e+00 *
                                      (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                    pow(x2, 3)) +
                                   ((b0 * (pow(MIN_R0, 2) * pow(x2, 4))) +
                                    ((((2.00000000000000000e+00 *
                                        (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                       ((b0 * pow(MIN_R0, 4)) +
                                        ((-4.00000000000000000e+00 *
                                          (b0 *
                                           (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                         ((2.00000000000000000e+00 *
                                           (b0 *
                                            (pow(MIN_R0, 2) * pow(TX0, 2)))) +
                                          ((((-4.00000000000000000e+00 *
                                              (b0 * (r0 * pow(MIN_R0, 2)))) +
                                             (4.00000000000000000e+00 *
                                              (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                            x2) +
                                           (2.00000000000000000e+00 *
                                            (b0 * (pow(MIN_R0, 2) *
                                                   pow(x2, 2))))))))) *
                                      pow(z1, 2)) +
                                     (b0 * (pow(MIN_R0, 2) *
                                            pow(z1, 4)))))))))))))) *
                          pow(((((2.00000000000000000e+00 * pow(r0, 4)) +
                                 ((4.00000000000000000e+00 *
                                   (pow(r0, 2) * pow(MIN_R0, 2))) +
                                  (2.00000000000000000e+00 * pow(MIN_R0, 4)))) *
                                (Q0 * pow(TX0, 2))) +
                               ((((-8.00000000000000000e+00 * pow(r0, 3)) +
                                  (-8.00000000000000000e+00 *
                                   (r0 * pow(MIN_R0, 2)))) *
                                 (Q0 * pow(TX0, 3))) +
                                ((((1.20000000000000000e+01 * pow(r0, 2)) +
                                   (4.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  (Q0 * pow(TX0, 4))) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * pow(TX0, 5)))) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * pow(TX0, 6))) +
                                   ((((((4.00000000000000000e+00 * pow(r0, 4)) +
                                        ((8.00000000000000000e+00 *
                                          (pow(r0, 2) * pow(MIN_R0, 2))) +
                                         (4.00000000000000000e+00 *
                                          pow(MIN_R0, 4)))) *
                                       (Q0 * TX0)) +
                                      ((((-2.40000000000000000e+01 *
                                          pow(r0, 3)) +
                                         (-2.40000000000000000e+01 *
                                          (r0 * pow(MIN_R0, 2)))) *
                                        (Q0 * pow(TX0, 2))) +
                                       ((((4.80000000000000000e+01 *
                                           pow(r0, 2)) +
                                          (1.60000000000000000e+01 *
                                           pow(MIN_R0, 2))) *
                                         (Q0 * pow(TX0, 3))) +
                                        ((-4.00000000000000000e+01 *
                                          (r0 * (Q0 * pow(TX0, 4)))) +
                                         (1.20000000000000000e+01 *
                                          (Q0 * pow(TX0, 5))))))) *
                                     x2) +
                                    ((((((2.00000000000000000e+00 *
                                          pow(r0, 4)) +
                                         ((4.00000000000000000e+00 *
                                           (pow(r0, 2) * pow(MIN_R0, 2))) +
                                          (2.00000000000000000e+00 *
                                           pow(MIN_R0, 4)))) *
                                        Q0) +
                                       ((((-2.40000000000000000e+01 *
                                           pow(r0, 3)) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         (Q0 * TX0)) +
                                        ((((7.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (2.40000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * pow(TX0, 2))) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 3)))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 4))))))) *
                                      pow(x2, 2)) +
                                     ((((((-8.00000000000000000e+00 *
                                           pow(r0, 3)) +
                                          (-8.00000000000000000e+00 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         Q0) +
                                        ((((4.80000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (1.60000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * TX0)) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 2)))) +
                                          (4.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 3)))))) *
                                       pow(x2, 3)) +
                                      ((((((1.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (4.00000000000000000e+00 *
                                            pow(MIN_R0, 2))) *
                                          Q0) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 * (Q0 * TX0))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 2))))) *
                                        pow(x2, 4)) +
                                       ((((-8.00000000000000000e+00 *
                                           (r0 * Q0)) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * TX0))) *
                                         pow(x2, 5)) +
                                        ((2.00000000000000000e+00 *
                                          (Q0 * pow(x2, 6))) +
                                         ((((((4.00000000000000000e+00 *
                                               pow(r0, 2)) +
                                              (4.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * pow(TX0, 2))) +
                                            ((-8.00000000000000000e+00 *
                                              (r0 * (Q0 * pow(TX0, 3)))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * pow(TX0, 4))) +
                                              ((((((8.00000000000000000e+00 *
                                                    pow(r0, 2)) +
                                                   (8.00000000000000000e+00 *
                                                    pow(MIN_R0, 2))) *
                                                  (Q0 * TX0)) +
                                                 ((-2.40000000000000000e+01 *
                                                   (r0 * (Q0 * pow(TX0, 2)))) +
                                                  (1.60000000000000000e+01 *
                                                   (Q0 * pow(TX0, 3))))) *
                                                x2) +
                                               ((((((4.00000000000000000e+00 *
                                                     pow(r0, 2)) +
                                                    (4.00000000000000000e+00 *
                                                     pow(MIN_R0, 2))) *
                                                   Q0) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * TX0))) +
                                                   (2.40000000000000000e+01 *
                                                    (Q0 * pow(TX0, 2))))) *
                                                 pow(x2, 2)) +
                                                ((((-8.00000000000000000e+00 *
                                                    (r0 * Q0)) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 * TX0))) *
                                                  pow(x2, 3)) +
                                                 (4.00000000000000000e+00 *
                                                  (Q0 * pow(x2, 4))))))))) *
                                           pow(z1, 2)) +
                                          (((2.00000000000000000e+00 *
                                             (Q0 * pow(TX0, 2))) +
                                            ((4.00000000000000000e+00 *
                                              (Q0 * (TX0 * x2))) +
                                             (2.00000000000000000e+00 *
                                              (Q0 * pow(x2, 2))))) *
                                           pow(z1, 4)))))))))))))),
                              -1)))) -
                       (-1.00000000000000000e+00 *
                        (y1 *
                         (((b0 * (pow(r0, 4) * pow(MIN_R0, 2))) +
                           ((b0 * (pow(r0, 2) * pow(MIN_R0, 4))) +
                            ((-4.00000000000000000e+00 *
                              (b0 * (pow(r0, 3) * (pow(MIN_R0, 2) * TX0)))) +
                             ((((6.00000000000000000e+00 *
                                 (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                (-1.00000000000000000e+00 *
                                 (b0 * pow(MIN_R0, 4)))) *
                               pow(TX0, 2)) +
                              ((-4.00000000000000000e+00 *
                                (b0 * (r0 * (pow(MIN_R0, 2) * pow(TX0, 3))))) +
                               ((b0 * (pow(MIN_R0, 2) * pow(TX0, 4))) +
                                ((((-4.00000000000000000e+00 *
                                    (b0 * (pow(r0, 3) * pow(MIN_R0, 2)))) +
                                   ((((1.20000000000000000e+01 *
                                       (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                      (-2.00000000000000000e+00 *
                                       (b0 * pow(MIN_R0, 4)))) *
                                     TX0) +
                                    ((-1.20000000000000000e+01 *
                                      (b0 *
                                       (r0 * (pow(MIN_R0, 2) * pow(TX0, 2))))) +
                                     (4.00000000000000000e+00 *
                                      (b0 *
                                       (pow(MIN_R0, 2) * pow(TX0, 3))))))) *
                                  x2) +
                                 ((((6.00000000000000000e+00 *
                                     (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                    ((-1.00000000000000000e+00 *
                                      (b0 * pow(MIN_R0, 4))) +
                                     ((-1.20000000000000000e+01 *
                                       (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                      (6.00000000000000000e+00 *
                                       (b0 *
                                        (pow(MIN_R0, 2) * pow(TX0, 2))))))) *
                                   pow(x2, 2)) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * (r0 * pow(MIN_R0, 2)))) +
                                     (4.00000000000000000e+00 *
                                      (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                    pow(x2, 3)) +
                                   ((b0 * (pow(MIN_R0, 2) * pow(x2, 4))) +
                                    ((((2.00000000000000000e+00 *
                                        (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                       ((b0 * pow(MIN_R0, 4)) +
                                        ((-4.00000000000000000e+00 *
                                          (b0 *
                                           (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                         ((2.00000000000000000e+00 *
                                           (b0 *
                                            (pow(MIN_R0, 2) * pow(TX0, 2)))) +
                                          ((((-4.00000000000000000e+00 *
                                              (b0 * (r0 * pow(MIN_R0, 2)))) +
                                             (4.00000000000000000e+00 *
                                              (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                            x2) +
                                           (2.00000000000000000e+00 *
                                            (b0 * (pow(MIN_R0, 2) *
                                                   pow(x2, 2))))))))) *
                                      pow(z1, 2)) +
                                     (b0 * (pow(MIN_R0, 2) *
                                            pow(z1, 4)))))))))))))) *
                          pow(((((2.00000000000000000e+00 * pow(r0, 4)) +
                                 ((4.00000000000000000e+00 *
                                   (pow(r0, 2) * pow(MIN_R0, 2))) +
                                  (2.00000000000000000e+00 * pow(MIN_R0, 4)))) *
                                (Q0 * pow(TX0, 2))) +
                               ((((-8.00000000000000000e+00 * pow(r0, 3)) +
                                  (-8.00000000000000000e+00 *
                                   (r0 * pow(MIN_R0, 2)))) *
                                 (Q0 * pow(TX0, 3))) +
                                ((((1.20000000000000000e+01 * pow(r0, 2)) +
                                   (4.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  (Q0 * pow(TX0, 4))) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * pow(TX0, 5)))) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * pow(TX0, 6))) +
                                   ((((((4.00000000000000000e+00 * pow(r0, 4)) +
                                        ((8.00000000000000000e+00 *
                                          (pow(r0, 2) * pow(MIN_R0, 2))) +
                                         (4.00000000000000000e+00 *
                                          pow(MIN_R0, 4)))) *
                                       (Q0 * TX0)) +
                                      ((((-2.40000000000000000e+01 *
                                          pow(r0, 3)) +
                                         (-2.40000000000000000e+01 *
                                          (r0 * pow(MIN_R0, 2)))) *
                                        (Q0 * pow(TX0, 2))) +
                                       ((((4.80000000000000000e+01 *
                                           pow(r0, 2)) +
                                          (1.60000000000000000e+01 *
                                           pow(MIN_R0, 2))) *
                                         (Q0 * pow(TX0, 3))) +
                                        ((-4.00000000000000000e+01 *
                                          (r0 * (Q0 * pow(TX0, 4)))) +
                                         (1.20000000000000000e+01 *
                                          (Q0 * pow(TX0, 5))))))) *
                                     x2) +
                                    ((((((2.00000000000000000e+00 *
                                          pow(r0, 4)) +
                                         ((4.00000000000000000e+00 *
                                           (pow(r0, 2) * pow(MIN_R0, 2))) +
                                          (2.00000000000000000e+00 *
                                           pow(MIN_R0, 4)))) *
                                        Q0) +
                                       ((((-2.40000000000000000e+01 *
                                           pow(r0, 3)) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         (Q0 * TX0)) +
                                        ((((7.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (2.40000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * pow(TX0, 2))) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 3)))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 4))))))) *
                                      pow(x2, 2)) +
                                     ((((((-8.00000000000000000e+00 *
                                           pow(r0, 3)) +
                                          (-8.00000000000000000e+00 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         Q0) +
                                        ((((4.80000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (1.60000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * TX0)) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 2)))) +
                                          (4.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 3)))))) *
                                       pow(x2, 3)) +
                                      ((((((1.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (4.00000000000000000e+00 *
                                            pow(MIN_R0, 2))) *
                                          Q0) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 * (Q0 * TX0))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 2))))) *
                                        pow(x2, 4)) +
                                       ((((-8.00000000000000000e+00 *
                                           (r0 * Q0)) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * TX0))) *
                                         pow(x2, 5)) +
                                        ((2.00000000000000000e+00 *
                                          (Q0 * pow(x2, 6))) +
                                         ((((((4.00000000000000000e+00 *
                                               pow(r0, 2)) +
                                              (4.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * pow(TX0, 2))) +
                                            ((-8.00000000000000000e+00 *
                                              (r0 * (Q0 * pow(TX0, 3)))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * pow(TX0, 4))) +
                                              ((((((8.00000000000000000e+00 *
                                                    pow(r0, 2)) +
                                                   (8.00000000000000000e+00 *
                                                    pow(MIN_R0, 2))) *
                                                  (Q0 * TX0)) +
                                                 ((-2.40000000000000000e+01 *
                                                   (r0 * (Q0 * pow(TX0, 2)))) +
                                                  (1.60000000000000000e+01 *
                                                   (Q0 * pow(TX0, 3))))) *
                                                x2) +
                                               ((((((4.00000000000000000e+00 *
                                                     pow(r0, 2)) +
                                                    (4.00000000000000000e+00 *
                                                     pow(MIN_R0, 2))) *
                                                   Q0) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * TX0))) +
                                                   (2.40000000000000000e+01 *
                                                    (Q0 * pow(TX0, 2))))) *
                                                 pow(x2, 2)) +
                                                ((((-8.00000000000000000e+00 *
                                                    (r0 * Q0)) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 * TX0))) *
                                                  pow(x2, 3)) +
                                                 (4.00000000000000000e+00 *
                                                  (Q0 * pow(x2, 4))))))))) *
                                           pow(z1, 2)) +
                                          (((2.00000000000000000e+00 *
                                             (Q0 * pow(TX0, 2))) +
                                            ((4.00000000000000000e+00 *
                                              (Q0 * (TX0 * x2))) +
                                             (2.00000000000000000e+00 *
                                              (Q0 * pow(x2, 2))))) *
                                           pow(z1, 4)))))))))))))),
                              -1))))) +
                      0.00000000000000000e+00)) +
                    (-1.00000000000000000e+00 *
                     (((-1.00000000000000000e+00 *
                        (y3 *
                         (((b0 * (pow(r0, 4) * pow(MIN_R0, 2))) +
                           ((b0 * (pow(r0, 2) * pow(MIN_R0, 4))) +
                            ((-4.00000000000000000e+00 *
                              (b0 * (pow(r0, 3) * (pow(MIN_R0, 2) * TX0)))) +
                             ((((6.00000000000000000e+00 *
                                 (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                (-1.00000000000000000e+00 *
                                 (b0 * pow(MIN_R0, 4)))) *
                               pow(TX0, 2)) +
                              ((-4.00000000000000000e+00 *
                                (b0 * (r0 * (pow(MIN_R0, 2) * pow(TX0, 3))))) +
                               ((b0 * (pow(MIN_R0, 2) * pow(TX0, 4))) +
                                ((((-4.00000000000000000e+00 *
                                    (b0 * (pow(r0, 3) * pow(MIN_R0, 2)))) +
                                   ((((1.20000000000000000e+01 *
                                       (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                      (-2.00000000000000000e+00 *
                                       (b0 * pow(MIN_R0, 4)))) *
                                     TX0) +
                                    ((-1.20000000000000000e+01 *
                                      (b0 *
                                       (r0 * (pow(MIN_R0, 2) * pow(TX0, 2))))) +
                                     (4.00000000000000000e+00 *
                                      (b0 *
                                       (pow(MIN_R0, 2) * pow(TX0, 3))))))) *
                                  x2) +
                                 ((((6.00000000000000000e+00 *
                                     (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                    ((-1.00000000000000000e+00 *
                                      (b0 * pow(MIN_R0, 4))) +
                                     ((-1.20000000000000000e+01 *
                                       (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                      (6.00000000000000000e+00 *
                                       (b0 *
                                        (pow(MIN_R0, 2) * pow(TX0, 2))))))) *
                                   pow(x2, 2)) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * (r0 * pow(MIN_R0, 2)))) +
                                     (4.00000000000000000e+00 *
                                      (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                    pow(x2, 3)) +
                                   ((b0 * (pow(MIN_R0, 2) * pow(x2, 4))) +
                                    ((((2.00000000000000000e+00 *
                                        (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                       ((b0 * pow(MIN_R0, 4)) +
                                        ((-4.00000000000000000e+00 *
                                          (b0 *
                                           (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                         ((2.00000000000000000e+00 *
                                           (b0 *
                                            (pow(MIN_R0, 2) * pow(TX0, 2)))) +
                                          ((((-4.00000000000000000e+00 *
                                              (b0 * (r0 * pow(MIN_R0, 2)))) +
                                             (4.00000000000000000e+00 *
                                              (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                            x2) +
                                           (2.00000000000000000e+00 *
                                            (b0 * (pow(MIN_R0, 2) *
                                                   pow(x2, 2))))))))) *
                                      pow(z3, 2)) +
                                     (b0 * (pow(MIN_R0, 2) *
                                            pow(z3, 4)))))))))))))) *
                          pow(((((2.00000000000000000e+00 * pow(r0, 4)) +
                                 ((4.00000000000000000e+00 *
                                   (pow(r0, 2) * pow(MIN_R0, 2))) +
                                  (2.00000000000000000e+00 * pow(MIN_R0, 4)))) *
                                (Q0 * pow(TX0, 2))) +
                               ((((-8.00000000000000000e+00 * pow(r0, 3)) +
                                  (-8.00000000000000000e+00 *
                                   (r0 * pow(MIN_R0, 2)))) *
                                 (Q0 * pow(TX0, 3))) +
                                ((((1.20000000000000000e+01 * pow(r0, 2)) +
                                   (4.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  (Q0 * pow(TX0, 4))) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * pow(TX0, 5)))) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * pow(TX0, 6))) +
                                   ((((((4.00000000000000000e+00 * pow(r0, 4)) +
                                        ((8.00000000000000000e+00 *
                                          (pow(r0, 2) * pow(MIN_R0, 2))) +
                                         (4.00000000000000000e+00 *
                                          pow(MIN_R0, 4)))) *
                                       (Q0 * TX0)) +
                                      ((((-2.40000000000000000e+01 *
                                          pow(r0, 3)) +
                                         (-2.40000000000000000e+01 *
                                          (r0 * pow(MIN_R0, 2)))) *
                                        (Q0 * pow(TX0, 2))) +
                                       ((((4.80000000000000000e+01 *
                                           pow(r0, 2)) +
                                          (1.60000000000000000e+01 *
                                           pow(MIN_R0, 2))) *
                                         (Q0 * pow(TX0, 3))) +
                                        ((-4.00000000000000000e+01 *
                                          (r0 * (Q0 * pow(TX0, 4)))) +
                                         (1.20000000000000000e+01 *
                                          (Q0 * pow(TX0, 5))))))) *
                                     x2) +
                                    ((((((2.00000000000000000e+00 *
                                          pow(r0, 4)) +
                                         ((4.00000000000000000e+00 *
                                           (pow(r0, 2) * pow(MIN_R0, 2))) +
                                          (2.00000000000000000e+00 *
                                           pow(MIN_R0, 4)))) *
                                        Q0) +
                                       ((((-2.40000000000000000e+01 *
                                           pow(r0, 3)) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         (Q0 * TX0)) +
                                        ((((7.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (2.40000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * pow(TX0, 2))) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 3)))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 4))))))) *
                                      pow(x2, 2)) +
                                     ((((((-8.00000000000000000e+00 *
                                           pow(r0, 3)) +
                                          (-8.00000000000000000e+00 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         Q0) +
                                        ((((4.80000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (1.60000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * TX0)) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 2)))) +
                                          (4.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 3)))))) *
                                       pow(x2, 3)) +
                                      ((((((1.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (4.00000000000000000e+00 *
                                            pow(MIN_R0, 2))) *
                                          Q0) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 * (Q0 * TX0))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 2))))) *
                                        pow(x2, 4)) +
                                       ((((-8.00000000000000000e+00 *
                                           (r0 * Q0)) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * TX0))) *
                                         pow(x2, 5)) +
                                        ((2.00000000000000000e+00 *
                                          (Q0 * pow(x2, 6))) +
                                         ((((((4.00000000000000000e+00 *
                                               pow(r0, 2)) +
                                              (4.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * pow(TX0, 2))) +
                                            ((-8.00000000000000000e+00 *
                                              (r0 * (Q0 * pow(TX0, 3)))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * pow(TX0, 4))) +
                                              ((((((8.00000000000000000e+00 *
                                                    pow(r0, 2)) +
                                                   (8.00000000000000000e+00 *
                                                    pow(MIN_R0, 2))) *
                                                  (Q0 * TX0)) +
                                                 ((-2.40000000000000000e+01 *
                                                   (r0 * (Q0 * pow(TX0, 2)))) +
                                                  (1.60000000000000000e+01 *
                                                   (Q0 * pow(TX0, 3))))) *
                                                x2) +
                                               ((((((4.00000000000000000e+00 *
                                                     pow(r0, 2)) +
                                                    (4.00000000000000000e+00 *
                                                     pow(MIN_R0, 2))) *
                                                   Q0) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * TX0))) +
                                                   (2.40000000000000000e+01 *
                                                    (Q0 * pow(TX0, 2))))) *
                                                 pow(x2, 2)) +
                                                ((((-8.00000000000000000e+00 *
                                                    (r0 * Q0)) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 * TX0))) *
                                                  pow(x2, 3)) +
                                                 (4.00000000000000000e+00 *
                                                  (Q0 * pow(x2, 4))))))))) *
                                           pow(z3, 2)) +
                                          (((2.00000000000000000e+00 *
                                             (Q0 * pow(TX0, 2))) +
                                            ((4.00000000000000000e+00 *
                                              (Q0 * (TX0 * x2))) +
                                             (2.00000000000000000e+00 *
                                              (Q0 * pow(x2, 2))))) *
                                           pow(z3, 4)))))))))))))),
                              -1)))) -
                       (-1.00000000000000000e+00 *
                        (y2 *
                         (((b0 * (pow(r0, 4) * pow(MIN_R0, 2))) +
                           ((b0 * (pow(r0, 2) * pow(MIN_R0, 4))) +
                            ((-4.00000000000000000e+00 *
                              (b0 * (pow(r0, 3) * (pow(MIN_R0, 2) * TX0)))) +
                             ((((6.00000000000000000e+00 *
                                 (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                (-1.00000000000000000e+00 *
                                 (b0 * pow(MIN_R0, 4)))) *
                               pow(TX0, 2)) +
                              ((-4.00000000000000000e+00 *
                                (b0 * (r0 * (pow(MIN_R0, 2) * pow(TX0, 3))))) +
                               ((b0 * (pow(MIN_R0, 2) * pow(TX0, 4))) +
                                ((((-4.00000000000000000e+00 *
                                    (b0 * (pow(r0, 3) * pow(MIN_R0, 2)))) +
                                   ((((1.20000000000000000e+01 *
                                       (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                      (-2.00000000000000000e+00 *
                                       (b0 * pow(MIN_R0, 4)))) *
                                     TX0) +
                                    ((-1.20000000000000000e+01 *
                                      (b0 *
                                       (r0 * (pow(MIN_R0, 2) * pow(TX0, 2))))) +
                                     (4.00000000000000000e+00 *
                                      (b0 *
                                       (pow(MIN_R0, 2) * pow(TX0, 3))))))) *
                                  x2) +
                                 ((((6.00000000000000000e+00 *
                                     (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                    ((-1.00000000000000000e+00 *
                                      (b0 * pow(MIN_R0, 4))) +
                                     ((-1.20000000000000000e+01 *
                                       (b0 * (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                      (6.00000000000000000e+00 *
                                       (b0 *
                                        (pow(MIN_R0, 2) * pow(TX0, 2))))))) *
                                   pow(x2, 2)) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * (r0 * pow(MIN_R0, 2)))) +
                                     (4.00000000000000000e+00 *
                                      (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                    pow(x2, 3)) +
                                   ((b0 * (pow(MIN_R0, 2) * pow(x2, 4))) +
                                    ((((2.00000000000000000e+00 *
                                        (b0 * (pow(r0, 2) * pow(MIN_R0, 2)))) +
                                       ((b0 * pow(MIN_R0, 4)) +
                                        ((-4.00000000000000000e+00 *
                                          (b0 *
                                           (r0 * (pow(MIN_R0, 2) * TX0)))) +
                                         ((2.00000000000000000e+00 *
                                           (b0 *
                                            (pow(MIN_R0, 2) * pow(TX0, 2)))) +
                                          ((((-4.00000000000000000e+00 *
                                              (b0 * (r0 * pow(MIN_R0, 2)))) +
                                             (4.00000000000000000e+00 *
                                              (b0 * (pow(MIN_R0, 2) * TX0)))) *
                                            x2) +
                                           (2.00000000000000000e+00 *
                                            (b0 * (pow(MIN_R0, 2) *
                                                   pow(x2, 2))))))))) *
                                      pow(z3, 2)) +
                                     (b0 * (pow(MIN_R0, 2) *
                                            pow(z3, 4)))))))))))))) *
                          pow(((((2.00000000000000000e+00 * pow(r0, 4)) +
                                 ((4.00000000000000000e+00 *
                                   (pow(r0, 2) * pow(MIN_R0, 2))) +
                                  (2.00000000000000000e+00 * pow(MIN_R0, 4)))) *
                                (Q0 * pow(TX0, 2))) +
                               ((((-8.00000000000000000e+00 * pow(r0, 3)) +
                                  (-8.00000000000000000e+00 *
                                   (r0 * pow(MIN_R0, 2)))) *
                                 (Q0 * pow(TX0, 3))) +
                                ((((1.20000000000000000e+01 * pow(r0, 2)) +
                                   (4.00000000000000000e+00 * pow(MIN_R0, 2))) *
                                  (Q0 * pow(TX0, 4))) +
                                 ((-8.00000000000000000e+00 *
                                   (r0 * (Q0 * pow(TX0, 5)))) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * pow(TX0, 6))) +
                                   ((((((4.00000000000000000e+00 * pow(r0, 4)) +
                                        ((8.00000000000000000e+00 *
                                          (pow(r0, 2) * pow(MIN_R0, 2))) +
                                         (4.00000000000000000e+00 *
                                          pow(MIN_R0, 4)))) *
                                       (Q0 * TX0)) +
                                      ((((-2.40000000000000000e+01 *
                                          pow(r0, 3)) +
                                         (-2.40000000000000000e+01 *
                                          (r0 * pow(MIN_R0, 2)))) *
                                        (Q0 * pow(TX0, 2))) +
                                       ((((4.80000000000000000e+01 *
                                           pow(r0, 2)) +
                                          (1.60000000000000000e+01 *
                                           pow(MIN_R0, 2))) *
                                         (Q0 * pow(TX0, 3))) +
                                        ((-4.00000000000000000e+01 *
                                          (r0 * (Q0 * pow(TX0, 4)))) +
                                         (1.20000000000000000e+01 *
                                          (Q0 * pow(TX0, 5))))))) *
                                     x2) +
                                    ((((((2.00000000000000000e+00 *
                                          pow(r0, 4)) +
                                         ((4.00000000000000000e+00 *
                                           (pow(r0, 2) * pow(MIN_R0, 2))) +
                                          (2.00000000000000000e+00 *
                                           pow(MIN_R0, 4)))) *
                                        Q0) +
                                       ((((-2.40000000000000000e+01 *
                                           pow(r0, 3)) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         (Q0 * TX0)) +
                                        ((((7.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (2.40000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * pow(TX0, 2))) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 3)))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 4))))))) *
                                      pow(x2, 2)) +
                                     ((((((-8.00000000000000000e+00 *
                                           pow(r0, 3)) +
                                          (-8.00000000000000000e+00 *
                                           (r0 * pow(MIN_R0, 2)))) *
                                         Q0) +
                                        ((((4.80000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (1.60000000000000000e+01 *
                                            pow(MIN_R0, 2))) *
                                          (Q0 * TX0)) +
                                         ((-8.00000000000000000e+01 *
                                           (r0 * (Q0 * pow(TX0, 2)))) +
                                          (4.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 3)))))) *
                                       pow(x2, 3)) +
                                      ((((((1.20000000000000000e+01 *
                                            pow(r0, 2)) +
                                           (4.00000000000000000e+00 *
                                            pow(MIN_R0, 2))) *
                                          Q0) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 * (Q0 * TX0))) +
                                          (3.00000000000000000e+01 *
                                           (Q0 * pow(TX0, 2))))) *
                                        pow(x2, 4)) +
                                       ((((-8.00000000000000000e+00 *
                                           (r0 * Q0)) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * TX0))) *
                                         pow(x2, 5)) +
                                        ((2.00000000000000000e+00 *
                                          (Q0 * pow(x2, 6))) +
                                         ((((((4.00000000000000000e+00 *
                                               pow(r0, 2)) +
                                              (4.00000000000000000e+00 *
                                               pow(MIN_R0, 2))) *
                                             (Q0 * pow(TX0, 2))) +
                                            ((-8.00000000000000000e+00 *
                                              (r0 * (Q0 * pow(TX0, 3)))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * pow(TX0, 4))) +
                                              ((((((8.00000000000000000e+00 *
                                                    pow(r0, 2)) +
                                                   (8.00000000000000000e+00 *
                                                    pow(MIN_R0, 2))) *
                                                  (Q0 * TX0)) +
                                                 ((-2.40000000000000000e+01 *
                                                   (r0 * (Q0 * pow(TX0, 2)))) +
                                                  (1.60000000000000000e+01 *
                                                   (Q0 * pow(TX0, 3))))) *
                                                x2) +
                                               ((((((4.00000000000000000e+00 *
                                                     pow(r0, 2)) +
                                                    (4.00000000000000000e+00 *
                                                     pow(MIN_R0, 2))) *
                                                   Q0) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * TX0))) +
                                                   (2.40000000000000000e+01 *
                                                    (Q0 * pow(TX0, 2))))) *
                                                 pow(x2, 2)) +
                                                ((((-8.00000000000000000e+00 *
                                                    (r0 * Q0)) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 * TX0))) *
                                                  pow(x2, 3)) +
                                                 (4.00000000000000000e+00 *
                                                  (Q0 * pow(x2, 4))))))))) *
                                           pow(z3, 2)) +
                                          (((2.00000000000000000e+00 *
                                             (Q0 * pow(TX0, 2))) +
                                            ((4.00000000000000000e+00 *
                                              (Q0 * (TX0 * x2))) +
                                             (2.00000000000000000e+00 *
                                              (Q0 * pow(x2, 2))))) *
                                           pow(z3, 4)))))))))))))),
                              -1))))) +
                      0.00000000000000000e+00))))));
            double x3 =
                ((pow(DELTA_X, -2.00000000000000000e+00) *
                  (pow(TX0, -2.00000000000000000e+00) *
                   ((-1.00000000000000000e+00 *
                     (pow(DELTA_X, 2.00000000000000000e+00) *
                      (pow(TX0, 2.00000000000000000e+00) * x1))) +
                    ((2.00000000000000000e+00 *
                      (pow(DELTA_X, 2.00000000000000000e+00) *
                       (pow(TX0, 2.00000000000000000e+00) * x2))) +
                     ((((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                        (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                       pow(y1, 2.00000000000000000e+00)) +
                      ((((-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                         (-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                        (y1 * y2)) +
                       ((((2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                          (2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                         pow(y2, 2.00000000000000000e+00)) +
                        ((((-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                           (-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                          (y2 * y3)) +
                         (((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                          pow(y3, 2.00000000000000000e+00)))))))))) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (-1 * (Deltat * (QE_MASS * iBx)))));

            double newvx = ((x3 - x2) / DT);

            double newvy = ((y3 - y2) / DT);

            double newvz = ((z3 - z2) / DT);

            double newxx = (x3 - XO);

            double newxy = (y3 - YO);

            double newxz = ((z3 + zmid) - ZO);

            ((local_particle_head)[0] = newxx);
            ((local_particle_head)[1] = newxy);
            ((local_particle_head)[2] = newxz);
            ((local_particle_head)[3] = newvx);
            ((local_particle_head)[4] = newvy);
            ((local_particle_head)[5] = newvz);
          }
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              if ((g_inner < load0)) {
                ((particle_head_general)[(stmpg1 + (g_inner * 6))] =
                     (local_particle_head)[stmpg1]);

              } else {
                0;
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP3;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP3:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP4;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP4:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_vlo_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[192];
  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 4); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 4); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (4 * (xyzy + (4 * xyzz))));

                {
                  long MYGEN606 = 0;

                  for (0; (MYGEN606 < (3 * 4));
                       (MYGEN606 = (MYGEN606 + __xlen))) {
                    int ridx = (MYGEN606 + __idx);

                    if ((ridx < (3 * 4))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((Bidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + Bidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + Bidz) + ovlp))))))))))[ridx]);

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
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));
              }
            }
          }
        }
      }
    }
    {
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 4))) {
          __m256d VPFX_simd_mask[1];
          double *simd_mask = VPFX_simd_mask;

          {
            int inner_var_G0;

            for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                 (inner_var_G0 = (inner_var_G0 + 1))) {
              ((simd_mask)[inner_var_G0] = ((g_inner + inner_var_G0) < load0));
            }
          }
          {
            __m256d VPFX_local_particle_head[6];
            double(*local_particle_head)[4];
            (local_particle_head = VPFX_local_particle_head);
            {
              int stmpg1;

#pragma clang loop vectorize(disable)
              for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
                {
                  {
                    int inner_var_G0;

                    for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                         (inner_var_G0 = (inner_var_G0 + 1))) {
                      (((local_particle_head)[stmpg1])[inner_var_G0] =
                           (particle_head_general)[(
                               stmpg1 + (((((g_inner + inner_var_G0) < load0))
                                              ? ((g_inner + inner_var_G0))
                                              : ((load0 - 1))) *
                                         6))]);
                    }
                  }
                }
              }
            }
            __m256d VPFX_xx1[1];
            double *xx1 = VPFX_xx1;

            ((VPFX_xx1)[0] = (VPFX_local_particle_head)[((0 * 1) + 0)]);
            __m256d VPFX_xy1[1];
            double *xy1 = VPFX_xy1;

            ((VPFX_xy1)[0] = (VPFX_local_particle_head)[((1 * 1) + 0)]);
            __m256d VPFX_xz1[1];
            double *xz1 = VPFX_xz1;

            ((VPFX_xz1)[0] = (VPFX_local_particle_head)[((2 * 1) + 0)]);
            __m256d VPFX_vx0[1];
            double *vx0 = VPFX_vx0;

            ((VPFX_vx0)[0] = (VPFX_local_particle_head)[((3 * 1) + 0)]);
            __m256d VPFX_vy0[1];
            double *vy0 = VPFX_vy0;

            ((VPFX_vy0)[0] = (VPFX_local_particle_head)[((4 * 1) + 0)]);
            __m256d VPFX_vz0[1];
            double *vz0 = VPFX_vz0;

            ((VPFX_vz0)[0] = (VPFX_local_particle_head)[((5 * 1) + 0)]);
            __m256d VPFX_rx[1];
            double *rx = VPFX_rx;

            ((VPFX_rx)[0] = ((VPFX_xx1)[0] - Midx));
            __m256d VPFX_ry[1];
            double *ry = VPFX_ry;

            ((VPFX_ry)[0] = ((VPFX_xy1)[0] - Midy));
            __m256d VPFX_rz[1];
            double *rz = VPFX_rz;

            ((VPFX_rz)[0] = ((VPFX_xz1)[0] - Midz));
            __m256d VPFX_xx0[1];
            double *xx0 = VPFX_xx0;

            ((VPFX_xx0)[0] = ((VPFX_xx1)[0] - (Deltat * (VPFX_vx0)[0])));
            __m256d VPFX_xy0[1];
            double *xy0 = VPFX_xy0;

            ((VPFX_xy0)[0] = ((VPFX_xy1)[0] - (Deltat * (VPFX_vy0)[0])));
            __m256d VPFX_xz0[1];
            double *xz0 = VPFX_xz0;

            ((VPFX_xz0)[0] = ((VPFX_xz1)[0] - (Deltat * (VPFX_vz0)[0])));
            __m256d VPFX_fEx[4];
            double(*fEx)[4];
            (fEx = VPFX_fEx);
            __m256d VPFX_fEy[4];
            double(*fEy)[4];
            (fEy = VPFX_fEy);
            __m256d VPFX_fEz[4];
            double(*fEz)[4];
            (fEz = VPFX_fEz);
            __m256d VPFX_fdEx[3];
            double(*fdEx)[4];
            (fdEx = VPFX_fdEx);
            __m256d VPFX_fdEy[3];
            double(*fdEy)[4];
            (fdEy = VPFX_fdEy);
            __m256d VPFX_fdEz[3];
            double(*fdEz)[4];
            (fdEz = VPFX_fdEz);
            __m256d VPFX_AllEx[1];
            double *AllEx = VPFX_AllEx;

            ((VPFX_AllEx)[0] = (0 - ((__m256d){})));
            __m256d VPFX_AllEy[1];
            double *AllEy = VPFX_AllEy;

            ((VPFX_AllEy)[0] = (0 - ((__m256d){})));
            __m256d VPFX_AllEz[1];
            double *AllEz = VPFX_AllEz;

            ((VPFX_AllEz)[0] = (0 - ((__m256d){})));
            ((VPFX_fEx)[((0 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx)[0])))));
            ((VPFX_fEy)[((0 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry)[0])))));
            ((VPFX_fEz)[((0 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz)[0])))));
            ((VPFX_fEx)[((1 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx)[0])))))));
            ((VPFX_fEy)[((1 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry)[0])))))));
            ((VPFX_fEz)[((1 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz)[0])))))));
            ((VPFX_fEx)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rx)[0]) +
                    ((VPFX_rx)[0] * (VPFX_rx)[0])))));
            ((VPFX_fEy)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_ry)[0]) +
                    ((VPFX_ry)[0] * (VPFX_ry)[0])))));
            ((VPFX_fEz)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rz)[0]) +
                    ((VPFX_rz)[0] * (VPFX_rz)[0])))));
            ((VPFX_fEx)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx)[0] * (VPFX_rx)[0])));
            ((VPFX_fEy)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry)[0] * (VPFX_ry)[0])));
            ((VPFX_fEz)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz)[0] * (VPFX_rz)[0])));
            ((VPFX_fdEx)[((0 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rx)[0]))));
            ((VPFX_fdEy)[((0 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_ry)[0]))));
            ((VPFX_fdEz)[((0 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rz)[0]))));
            ((VPFX_fdEx)[((1 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx)[0])))));
            ((VPFX_fdEy)[((1 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry)[0])))));
            ((VPFX_fdEz)[((1 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz)[0])))));
            ((VPFX_fdEx)[((2 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rx)[0]));
            ((VPFX_fdEy)[((2 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_ry)[0]));
            ((VPFX_fdEz)[((2 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rz)[0]));
            {
              long idz;

              for ((idz = 0); (idz < 4); (idz = (idz + 1))) {
                {
                  long idy;

                  for ((idy = 0); (idy < 4); (idy = (idy + 1))) {
                    {
                      long idx;

                      for ((idx = 0); (idx < 3); (idx = (idx + 1))) {
                        ((VPFX_AllEx)[0] =
                             ((VPFX_AllEx)[0] +
                              ((shE0)[(0 +
                                       (3 * (idx + (4 * (idy + (idz * 4))))))] *
                               ((VPFX_fdEx)[((idx * 1) + 0)] *
                                ((VPFX_fEy)[((idy * 1) + 0)] *
                                 (VPFX_fEz)[((idz * 1) + 0)])))));
                        ((VPFX_AllEy)[0] =
                             ((VPFX_AllEy)[0] +
                              ((shE0)[(1 +
                                       (3 * (idz + (4 * (idx + (idy * 4))))))] *
                               ((VPFX_fdEy)[((idx * 1) + 0)] *
                                ((VPFX_fEz)[((idy * 1) + 0)] *
                                 (VPFX_fEx)[((idz * 1) + 0)])))));
                        ((VPFX_AllEz)[0] =
                             ((VPFX_AllEz)[0] +
                              ((shE0)[(2 +
                                       (3 * (idy + (4 * (idz + (idx * 4))))))] *
                               ((VPFX_fdEz)[((idx * 1) + 0)] *
                                ((VPFX_fEx)[((idy * 1) + 0)] *
                                 (VPFX_fEy)[((idz * 1) + 0)])))));
                      }
                    }
                  }
                }
              }
            }
            ((VPFX_AllEx)[0] = (0 - ((__m256d){})));
            ((VPFX_AllEy)[0] = (0 - ((__m256d){})));
            ((VPFX_AllEz)[0] = (0 - ((__m256d){})));
            __m256d VPFX_allincfvx[1];
            double *allincfvx = VPFX_allincfvx;

            __m256d VPFX_allincfvy[1];
            double *allincfvy = VPFX_allincfvy;

            __m256d VPFX_allincfvz[1];
            double *allincfvz = VPFX_allincfvz;

            ((VPFX_allincfvx)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEx)[0])));
            ((VPFX_allincfvy)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEy)[0])));
            ((VPFX_allincfvz)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEz)[0])));
            double DT;

            (DT = Deltat);
            {
              __m256d VPFX_x0[1];
              double *x0 = VPFX_x0;

              ((VPFX_x0)[0] = ((VPFX_xx0)[0] + XO));
              __m256d VPFX_y0[1];
              double *y0 = VPFX_y0;

              ((VPFX_y0)[0] = ((VPFX_xy0)[0] + YO));
              __m256d VPFX_z0[1];
              double *z0 = VPFX_z0;

              ((VPFX_z0)[0] = (((VPFX_xz0)[0] + ZO) - zmid));
              __m256d VPFX_x1[1];
              double *x1 = VPFX_x1;

              ((VPFX_x1)[0] = ((VPFX_xx1)[0] + XO));
              __m256d VPFX_y1[1];
              double *y1 = VPFX_y1;

              ((VPFX_y1)[0] = ((VPFX_xy1)[0] + YO));
              __m256d VPFX_z1[1];
              double *z1 = VPFX_z1;

              ((VPFX_z1)[0] = (((VPFX_xz1)[0] + ZO) - zmid));
              __m256d VPFX_mzero[1];
              double *mzero = VPFX_mzero;

              ((VPFX_mzero)[0] = (0.00000000000000000e+00 - ((__m256d){})));
              __m256d VPFX_iBx[1];
              double *iBx = VPFX_iBx;

              ((VPFX_iBx)[0] =
                   ((-1.00000000000000000e+00 *
                     (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                       0.00000000000000000e+00) *
                      ({ (1.00000000000000000e+00 / DT); }))) +
                    (VPFX_mzero)[0]));
              __m256d VPFX_x2[1];
              double *x2 = VPFX_x2;

              ((VPFX_x2)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_x0)[0]) +
                     (2.00000000000000000e+00 * (VPFX_x1)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (QE_MASS * (Deltat * ((VPFX_allincfvx)[0] +
                                           (-1.00000000000000000e+00 *
                                            (VPFX_iBx)[0])))))));
              __m256d VPFX_iBy[1];
              double *iBy = VPFX_iBy;

              ((VPFX_iBy)[0] =
                   (({ (1.00000000000000000e+00 / DT); }) *
                    (0.00000000000000000e+00 +
                     ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                      (((((((b0 * ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                            ((-2.00000000000000000e+00 *
                              (b0 * (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                             ((b0 * ((MIN_R0 * MIN_R0) * (TX0 * TX0))) +
                              ((((-2.00000000000000000e+00 *
                                  (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                 (2.00000000000000000e+00 *
                                  (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                (VPFX_x1)[0]) +
                               ((b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_x1)[0] * (VPFX_x1)[0]))) +
                                (b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_z1)[0] * (VPFX_z1)[0])))))))) *
                           ({
                             (1.00000000000000000e+00 /
                              ((((2.00000000000000000e+00 * (r0 * r0)) +
                                 (2.00000000000000000e+00 *
                                  (MIN_R0 * MIN_R0))) *
                                (Q0 * TX0)) +
                               ((-4.00000000000000000e+00 *
                                 (r0 * (Q0 * (TX0 * TX0)))) +
                                ((2.00000000000000000e+00 *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                    (6.00000000000000000e+00 * (Q0 * TX0))) *
                                   ((VPFX_x1)[0] * (VPFX_x1)[0])) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * ((VPFX_x1)[0] *
                                           ((VPFX_x1)[0] * (VPFX_x1)[0])))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 * ((VPFX_z1)[0] * (VPFX_z1)[0])))) +
                                    ((VPFX_x1)[0] *
                                     ((((2.00000000000000000e+00 * (r0 * r0)) +
                                        (2.00000000000000000e+00 *
                                         (MIN_R0 * MIN_R0))) *
                                       Q0) +
                                      ((-8.00000000000000000e+00 *
                                        (r0 * (Q0 * TX0))) +
                                       ((6.00000000000000000e+00 *
                                         (Q0 * (TX0 * TX0))) +
                                        (2.00000000000000000e+00 *
                                         (Q0 * ((VPFX_z1)[0] *
                                                (VPFX_z1)[0]))))))))))))));
                           })) -
                          (((b0 * ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                            ((-2.00000000000000000e+00 *
                              (b0 * (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                             ((b0 * ((MIN_R0 * MIN_R0) * (TX0 * TX0))) +
                              ((((-2.00000000000000000e+00 *
                                  (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                 (2.00000000000000000e+00 *
                                  (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                (VPFX_x0)[0]) +
                               ((b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_x0)[0] * (VPFX_x0)[0]))) +
                                (b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_z1)[0] * (VPFX_z1)[0])))))))) *
                           ({
                             (1.00000000000000000e+00 /
                              ((((2.00000000000000000e+00 * (r0 * r0)) +
                                 (2.00000000000000000e+00 *
                                  (MIN_R0 * MIN_R0))) *
                                (Q0 * TX0)) +
                               ((-4.00000000000000000e+00 *
                                 (r0 * (Q0 * (TX0 * TX0)))) +
                                ((2.00000000000000000e+00 *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                    (6.00000000000000000e+00 * (Q0 * TX0))) *
                                   ((VPFX_x0)[0] * (VPFX_x0)[0])) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * ((VPFX_x0)[0] *
                                           ((VPFX_x0)[0] * (VPFX_x0)[0])))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 * ((VPFX_z1)[0] * (VPFX_z1)[0])))) +
                                    ((VPFX_x0)[0] *
                                     ((((2.00000000000000000e+00 * (r0 * r0)) +
                                        (2.00000000000000000e+00 *
                                         (MIN_R0 * MIN_R0))) *
                                       Q0) +
                                      ((-8.00000000000000000e+00 *
                                        (r0 * (Q0 * TX0))) +
                                       ((6.00000000000000000e+00 *
                                         (Q0 * (TX0 * TX0))) +
                                        (2.00000000000000000e+00 *
                                         (Q0 * ((VPFX_z1)[0] *
                                                (VPFX_z1)[0]))))))))))))));
                           }))) +
                         0.00000000000000000e+00) +
                        (((((b0 * ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                            ((-2.00000000000000000e+00 *
                              (b0 * (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                             ((b0 * ((MIN_R0 * MIN_R0) * (TX0 * TX0))) +
                              ((((-2.00000000000000000e+00 *
                                  (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                 (2.00000000000000000e+00 *
                                  (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                (VPFX_x2)[0]) +
                               ((b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                (b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_z1)[0] * (VPFX_z1)[0])))))))) *
                           ({
                             (1.00000000000000000e+00 /
                              ((((2.00000000000000000e+00 * (r0 * r0)) +
                                 (2.00000000000000000e+00 *
                                  (MIN_R0 * MIN_R0))) *
                                (Q0 * TX0)) +
                               ((-4.00000000000000000e+00 *
                                 (r0 * (Q0 * (TX0 * TX0)))) +
                                ((2.00000000000000000e+00 *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                    (6.00000000000000000e+00 * (Q0 * TX0))) *
                                   ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 * ((VPFX_z1)[0] * (VPFX_z1)[0])))) +
                                    ((VPFX_x2)[0] *
                                     ((((2.00000000000000000e+00 * (r0 * r0)) +
                                        (2.00000000000000000e+00 *
                                         (MIN_R0 * MIN_R0))) *
                                       Q0) +
                                      ((-8.00000000000000000e+00 *
                                        (r0 * (Q0 * TX0))) +
                                       ((6.00000000000000000e+00 *
                                         (Q0 * (TX0 * TX0))) +
                                        (2.00000000000000000e+00 *
                                         (Q0 * ((VPFX_z1)[0] *
                                                (VPFX_z1)[0]))))))))))))));
                           })) -
                          (((b0 * ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                            ((-2.00000000000000000e+00 *
                              (b0 * (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                             ((b0 * ((MIN_R0 * MIN_R0) * (TX0 * TX0))) +
                              ((((-2.00000000000000000e+00 *
                                  (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                 (2.00000000000000000e+00 *
                                  (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                (VPFX_x1)[0]) +
                               ((b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_x1)[0] * (VPFX_x1)[0]))) +
                                (b0 * ((MIN_R0 * MIN_R0) *
                                       ((VPFX_z1)[0] * (VPFX_z1)[0])))))))) *
                           ({
                             (1.00000000000000000e+00 /
                              ((((2.00000000000000000e+00 * (r0 * r0)) +
                                 (2.00000000000000000e+00 *
                                  (MIN_R0 * MIN_R0))) *
                                (Q0 * TX0)) +
                               ((-4.00000000000000000e+00 *
                                 (r0 * (Q0 * (TX0 * TX0)))) +
                                ((2.00000000000000000e+00 *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                    (6.00000000000000000e+00 * (Q0 * TX0))) *
                                   ((VPFX_x1)[0] * (VPFX_x1)[0])) +
                                  ((2.00000000000000000e+00 *
                                    (Q0 * ((VPFX_x1)[0] *
                                           ((VPFX_x1)[0] * (VPFX_x1)[0])))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 * ((VPFX_z1)[0] * (VPFX_z1)[0])))) +
                                    ((VPFX_x1)[0] *
                                     ((((2.00000000000000000e+00 * (r0 * r0)) +
                                        (2.00000000000000000e+00 *
                                         (MIN_R0 * MIN_R0))) *
                                       Q0) +
                                      ((-8.00000000000000000e+00 *
                                        (r0 * (Q0 * TX0))) +
                                       ((6.00000000000000000e+00 *
                                         (Q0 * (TX0 * TX0))) +
                                        (2.00000000000000000e+00 *
                                         (Q0 * ((VPFX_z1)[0] *
                                                (VPFX_z1)[0]))))))))))))));
                           }))) +
                         0.00000000000000000e+00)) *
                       DT)))));
              __m256d VPFX_y2[1];
              double *y2 = VPFX_y2;

              ((VPFX_y2)[0] =
                   ((({
                       (1.00000000000000000e+00 /
                        ((TX0 * TX0) +
                         ((2.00000000000000000e+00 * (TX0 * (VPFX_x2)[0])) +
                          ((VPFX_x2)[0] * (VPFX_x2)[0]))));
                     }) *
                     ((((-1.00000000000000000e+00 * (TX0 * TX0)) +
                        ((-2.00000000000000000e+00 * (TX0 * (VPFX_x0)[0])) +
                         (-1.00000000000000000e+00 *
                          ((VPFX_x0)[0] * (VPFX_x0)[0])))) *
                       (VPFX_y0)[0]) +
                      (((2.00000000000000000e+00 * (TX0 * TX0)) +
                        ((2.00000000000000000e+00 * (TX0 * (VPFX_x0)[0])) +
                         (((VPFX_x0)[0] * (VPFX_x0)[0]) +
                          ((2.00000000000000000e+00 * (TX0 * (VPFX_x2)[0])) +
                           ((VPFX_x2)[0] * (VPFX_x2)[0]))))) *
                       (VPFX_y1)[0]))) +
                    ((TX0 * TX0) *
                     ((QE_MASS * (Deltat * ((VPFX_allincfvy)[0] +
                                            (-1.00000000000000000e+00 *
                                             (VPFX_iBy)[0])))) *
                      ({
                        (1.00000000000000000e+00 /
                         (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
                          ((2.00000000000000000e+00 *
                            ((DELTA_Y * DELTA_Y) * (TX0 * (VPFX_x2)[0]))) +
                           ((DELTA_Y * DELTA_Y) *
                            ((VPFX_x2)[0] * (VPFX_x2)[0])))));
                      })))));
              __m256d VPFX_iBz[1];
              double *iBz = VPFX_iBz;

              ((VPFX_iBz)[0] =
                   (-1.00000000000000000e+00 *
                    (({ (1.00000000000000000e+00 / DT); }) *
                     ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                      (0.00000000000000000e+00 +
                       (((-1.00000000000000000e+00 *
                          (((-1.00000000000000000e+00 *
                             (b0 *
                              ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) *
                               ((VPFX_y1)[0] *
                                ((VPFX_z1)[0] * ({
                                   (1.00000000000000000e+00 /
                                    ((((r0 * (r0 * (r0 * r0))) +
                                       ((2.00000000000000000e+00 *
                                         ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                        (MIN_R0 *
                                         (MIN_R0 * (MIN_R0 * MIN_R0))))) *
                                      (Q0 * TX0)) +
                                     ((((-4.00000000000000000e+00 *
                                         (r0 * (r0 * r0))) +
                                        (-4.00000000000000000e+00 *
                                         (r0 * (MIN_R0 * MIN_R0)))) *
                                       (Q0 * (TX0 * TX0))) +
                                      ((((6.00000000000000000e+00 * (r0 * r0)) +
                                         (2.00000000000000000e+00 *
                                          (MIN_R0 * MIN_R0))) *
                                        (Q0 * (TX0 * (TX0 * TX0)))) +
                                       ((-4.00000000000000000e+00 *
                                         (r0 *
                                          (Q0 * (TX0 * (TX0 * (TX0 * TX0)))))) +
                                        ((Q0 *
                                          (TX0 * (TX0 * (TX0 * (TX0 * TX0))))) +
                                         ((((((r0 * (r0 * (r0 * r0))) +
                                              ((2.00000000000000000e+00 *
                                                ((r0 * r0) *
                                                 (MIN_R0 * MIN_R0))) +
                                               (MIN_R0 *
                                                (MIN_R0 *
                                                 (MIN_R0 * MIN_R0))))) *
                                             Q0) +
                                            ((((-8.00000000000000000e+00 *
                                                (r0 * (r0 * r0))) +
                                               (-8.00000000000000000e+00 *
                                                (r0 * (MIN_R0 * MIN_R0)))) *
                                              (Q0 * TX0)) +
                                             ((((1.80000000000000000e+01 *
                                                 (r0 * r0)) +
                                                (6.00000000000000000e+00 *
                                                 (MIN_R0 * MIN_R0))) *
                                               (Q0 * (TX0 * TX0))) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 *
                                                 (Q0 * (TX0 * (TX0 * TX0))))) +
                                               (5.00000000000000000e+00 *
                                                (Q0 *
                                                 (TX0 *
                                                  (TX0 * (TX0 * TX0))))))))) *
                                           (VPFX_x0)[0]) +
                                          ((((((-4.00000000000000000e+00 *
                                                (r0 * (r0 * r0))) +
                                               (-4.00000000000000000e+00 *
                                                (r0 * (MIN_R0 * MIN_R0)))) *
                                              Q0) +
                                             ((((1.80000000000000000e+01 *
                                                 (r0 * r0)) +
                                                (6.00000000000000000e+00 *
                                                 (MIN_R0 * MIN_R0))) *
                                               (Q0 * TX0)) +
                                              ((-2.40000000000000000e+01 *
                                                (r0 * (Q0 * (TX0 * TX0)))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * (TX0 * (TX0 * TX0))))))) *
                                            ((VPFX_x0)[0] * (VPFX_x0)[0])) +
                                           ((((((6.00000000000000000e+00 *
                                                 (r0 * r0)) +
                                                (2.00000000000000000e+00 *
                                                 (MIN_R0 * MIN_R0))) *
                                               Q0) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 * (Q0 * TX0))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * (TX0 * TX0))))) *
                                             ((VPFX_x0)[0] *
                                              ((VPFX_x0)[0] * (VPFX_x0)[0]))) +
                                            ((((-4.00000000000000000e+00 *
                                                (r0 * Q0)) +
                                               (5.00000000000000000e+00 *
                                                (Q0 * TX0))) *
                                              ((VPFX_x0)[0] *
                                               ((VPFX_x0)[0] *
                                                ((VPFX_x0)[0] *
                                                 (VPFX_x0)[0])))) +
                                             ((Q0 * ((VPFX_x0)[0] *
                                                     ((VPFX_x0)[0] *
                                                      ((VPFX_x0)[0] *
                                                       ((VPFX_x0)[0] *
                                                        (VPFX_x0)[0]))))) +
                                              ((((((2.00000000000000000e+00 *
                                                    (r0 * r0)) +
                                                   (2.00000000000000000e+00 *
                                                    (MIN_R0 * MIN_R0))) *
                                                  (Q0 * TX0)) +
                                                 ((-4.00000000000000000e+00 *
                                                   (r0 * (Q0 * (TX0 * TX0)))) +
                                                  ((2.00000000000000000e+00 *
                                                    (Q0 *
                                                     (TX0 * (TX0 * TX0)))) +
                                                   ((((((2.00000000000000000e+00 *
                                                         (r0 * r0)) +
                                                        (2.00000000000000000e+00 *
                                                         (MIN_R0 * MIN_R0))) *
                                                       Q0) +
                                                      ((-8.00000000000000000e+00 *
                                                        (r0 * (Q0 * TX0))) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * (TX0 * TX0))))) *
                                                     (VPFX_x0)[0]) +
                                                    ((((-4.00000000000000000e+00 *
                                                        (r0 * Q0)) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * TX0))) *
                                                      ((VPFX_x0)[0] *
                                                       (VPFX_x0)[0])) +
                                                     (2.00000000000000000e+00 *
                                                      (Q0 *
                                                       ((VPFX_x0)[0] *
                                                        ((VPFX_x0)[0] *
                                                         (VPFX_x0)[0]))))))))) *
                                                ((VPFX_z1)[0] * (VPFX_z1)[0])) +
                                               (((Q0 * TX0) +
                                                 (Q0 * (VPFX_x0)[0])) *
                                                ((VPFX_z1)[0] *
                                                 ((VPFX_z1)[0] *
                                                  ((VPFX_z1)[0] *
                                                   (VPFX_z1)[0]))))))))))))))));
                                 })))))) -
                            (-1.00000000000000000e+00 *
                             (b0 *
                              ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) *
                               ((VPFX_y0)[0] *
                                ((VPFX_z1)[0] * ({
                                   (1.00000000000000000e+00 /
                                    ((((r0 * (r0 * (r0 * r0))) +
                                       ((2.00000000000000000e+00 *
                                         ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                        (MIN_R0 *
                                         (MIN_R0 * (MIN_R0 * MIN_R0))))) *
                                      (Q0 * TX0)) +
                                     ((((-4.00000000000000000e+00 *
                                         (r0 * (r0 * r0))) +
                                        (-4.00000000000000000e+00 *
                                         (r0 * (MIN_R0 * MIN_R0)))) *
                                       (Q0 * (TX0 * TX0))) +
                                      ((((6.00000000000000000e+00 * (r0 * r0)) +
                                         (2.00000000000000000e+00 *
                                          (MIN_R0 * MIN_R0))) *
                                        (Q0 * (TX0 * (TX0 * TX0)))) +
                                       ((-4.00000000000000000e+00 *
                                         (r0 *
                                          (Q0 * (TX0 * (TX0 * (TX0 * TX0)))))) +
                                        ((Q0 *
                                          (TX0 * (TX0 * (TX0 * (TX0 * TX0))))) +
                                         ((((((r0 * (r0 * (r0 * r0))) +
                                              ((2.00000000000000000e+00 *
                                                ((r0 * r0) *
                                                 (MIN_R0 * MIN_R0))) +
                                               (MIN_R0 *
                                                (MIN_R0 *
                                                 (MIN_R0 * MIN_R0))))) *
                                             Q0) +
                                            ((((-8.00000000000000000e+00 *
                                                (r0 * (r0 * r0))) +
                                               (-8.00000000000000000e+00 *
                                                (r0 * (MIN_R0 * MIN_R0)))) *
                                              (Q0 * TX0)) +
                                             ((((1.80000000000000000e+01 *
                                                 (r0 * r0)) +
                                                (6.00000000000000000e+00 *
                                                 (MIN_R0 * MIN_R0))) *
                                               (Q0 * (TX0 * TX0))) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 *
                                                 (Q0 * (TX0 * (TX0 * TX0))))) +
                                               (5.00000000000000000e+00 *
                                                (Q0 *
                                                 (TX0 *
                                                  (TX0 * (TX0 * TX0))))))))) *
                                           (VPFX_x0)[0]) +
                                          ((((((-4.00000000000000000e+00 *
                                                (r0 * (r0 * r0))) +
                                               (-4.00000000000000000e+00 *
                                                (r0 * (MIN_R0 * MIN_R0)))) *
                                              Q0) +
                                             ((((1.80000000000000000e+01 *
                                                 (r0 * r0)) +
                                                (6.00000000000000000e+00 *
                                                 (MIN_R0 * MIN_R0))) *
                                               (Q0 * TX0)) +
                                              ((-2.40000000000000000e+01 *
                                                (r0 * (Q0 * (TX0 * TX0)))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * (TX0 * (TX0 * TX0))))))) *
                                            ((VPFX_x0)[0] * (VPFX_x0)[0])) +
                                           ((((((6.00000000000000000e+00 *
                                                 (r0 * r0)) +
                                                (2.00000000000000000e+00 *
                                                 (MIN_R0 * MIN_R0))) *
                                               Q0) +
                                              ((-1.60000000000000000e+01 *
                                                (r0 * (Q0 * TX0))) +
                                               (1.00000000000000000e+01 *
                                                (Q0 * (TX0 * TX0))))) *
                                             ((VPFX_x0)[0] *
                                              ((VPFX_x0)[0] * (VPFX_x0)[0]))) +
                                            ((((-4.00000000000000000e+00 *
                                                (r0 * Q0)) +
                                               (5.00000000000000000e+00 *
                                                (Q0 * TX0))) *
                                              ((VPFX_x0)[0] *
                                               ((VPFX_x0)[0] *
                                                ((VPFX_x0)[0] *
                                                 (VPFX_x0)[0])))) +
                                             ((Q0 * ((VPFX_x0)[0] *
                                                     ((VPFX_x0)[0] *
                                                      ((VPFX_x0)[0] *
                                                       ((VPFX_x0)[0] *
                                                        (VPFX_x0)[0]))))) +
                                              ((((((2.00000000000000000e+00 *
                                                    (r0 * r0)) +
                                                   (2.00000000000000000e+00 *
                                                    (MIN_R0 * MIN_R0))) *
                                                  (Q0 * TX0)) +
                                                 ((-4.00000000000000000e+00 *
                                                   (r0 * (Q0 * (TX0 * TX0)))) +
                                                  ((2.00000000000000000e+00 *
                                                    (Q0 *
                                                     (TX0 * (TX0 * TX0)))) +
                                                   ((((((2.00000000000000000e+00 *
                                                         (r0 * r0)) +
                                                        (2.00000000000000000e+00 *
                                                         (MIN_R0 * MIN_R0))) *
                                                       Q0) +
                                                      ((-8.00000000000000000e+00 *
                                                        (r0 * (Q0 * TX0))) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * (TX0 * TX0))))) *
                                                     (VPFX_x0)[0]) +
                                                    ((((-4.00000000000000000e+00 *
                                                        (r0 * Q0)) +
                                                       (6.00000000000000000e+00 *
                                                        (Q0 * TX0))) *
                                                      ((VPFX_x0)[0] *
                                                       (VPFX_x0)[0])) +
                                                     (2.00000000000000000e+00 *
                                                      (Q0 *
                                                       ((VPFX_x0)[0] *
                                                        ((VPFX_x0)[0] *
                                                         (VPFX_x0)[0]))))))))) *
                                                ((VPFX_z1)[0] * (VPFX_z1)[0])) +
                                               (((Q0 * TX0) +
                                                 (Q0 * (VPFX_x0)[0])) *
                                                ((VPFX_z1)[0] *
                                                 ((VPFX_z1)[0] *
                                                  ((VPFX_z1)[0] *
                                                   (VPFX_z1)[0]))))))))))))))));
                                 }))))))) +
                           0.00000000000000000e+00)) +
                         ((((b0 * (r0 * c_geo_log_simd((TX0 + (VPFX_x1)[0])))) -
                            (b0 *
                             (r0 * c_geo_log_simd((TX0 + (VPFX_x0)[0]))))) +
                           0.00000000000000000e+00) +
                          ((-1.00000000000000000e+00 *
                            (((-1.00000000000000000e+00 *
                               (b0 *
                                ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) *
                                 ((VPFX_y2)[0] *
                                  ((VPFX_z1)[0] * ({
                                     (1.00000000000000000e+00 /
                                      ((((r0 * (r0 * (r0 * r0))) +
                                         ((2.00000000000000000e+00 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                          (MIN_R0 *
                                           (MIN_R0 * (MIN_R0 * MIN_R0))))) *
                                        (Q0 * TX0)) +
                                       ((((-4.00000000000000000e+00 *
                                           (r0 * (r0 * r0))) +
                                          (-4.00000000000000000e+00 *
                                           (r0 * (MIN_R0 * MIN_R0)))) *
                                         (Q0 * (TX0 * TX0))) +
                                        ((((6.00000000000000000e+00 *
                                            (r0 * r0)) +
                                           (2.00000000000000000e+00 *
                                            (MIN_R0 * MIN_R0))) *
                                          (Q0 * (TX0 * (TX0 * TX0)))) +
                                         ((-4.00000000000000000e+00 *
                                           (r0 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0)))))) +
                                          ((Q0 *
                                            (TX0 *
                                             (TX0 * (TX0 * (TX0 * TX0))))) +
                                           ((((((r0 * (r0 * (r0 * r0))) +
                                                ((2.00000000000000000e+00 *
                                                  ((r0 * r0) *
                                                   (MIN_R0 * MIN_R0))) +
                                                 (MIN_R0 *
                                                  (MIN_R0 *
                                                   (MIN_R0 * MIN_R0))))) *
                                               Q0) +
                                              ((((-8.00000000000000000e+00 *
                                                  (r0 * (r0 * r0))) +
                                                 (-8.00000000000000000e+00 *
                                                  (r0 * (MIN_R0 * MIN_R0)))) *
                                                (Q0 * TX0)) +
                                               ((((1.80000000000000000e+01 *
                                                   (r0 * r0)) +
                                                  (6.00000000000000000e+00 *
                                                   (MIN_R0 * MIN_R0))) *
                                                 (Q0 * (TX0 * TX0))) +
                                                ((-1.60000000000000000e+01 *
                                                  (r0 * (Q0 * (TX0 *
                                                               (TX0 * TX0))))) +
                                                 (5.00000000000000000e+00 *
                                                  (Q0 *
                                                   (TX0 *
                                                    (TX0 * (TX0 * TX0))))))))) *
                                             (VPFX_x2)[0]) +
                                            ((((((-4.00000000000000000e+00 *
                                                  (r0 * (r0 * r0))) +
                                                 (-4.00000000000000000e+00 *
                                                  (r0 * (MIN_R0 * MIN_R0)))) *
                                                Q0) +
                                               ((((1.80000000000000000e+01 *
                                                   (r0 * r0)) +
                                                  (6.00000000000000000e+00 *
                                                   (MIN_R0 * MIN_R0))) *
                                                 (Q0 * TX0)) +
                                                ((-2.40000000000000000e+01 *
                                                  (r0 * (Q0 * (TX0 * TX0)))) +
                                                 (1.00000000000000000e+01 *
                                                  (Q0 *
                                                   (TX0 * (TX0 * TX0))))))) *
                                              ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                             ((((((6.00000000000000000e+00 *
                                                   (r0 * r0)) +
                                                  (2.00000000000000000e+00 *
                                                   (MIN_R0 * MIN_R0))) *
                                                 Q0) +
                                                ((-1.60000000000000000e+01 *
                                                  (r0 * (Q0 * TX0))) +
                                                 (1.00000000000000000e+01 *
                                                  (Q0 * (TX0 * TX0))))) *
                                               ((VPFX_x2)[0] *
                                                ((VPFX_x2)[0] *
                                                 (VPFX_x2)[0]))) +
                                              ((((-4.00000000000000000e+00 *
                                                  (r0 * Q0)) +
                                                 (5.00000000000000000e+00 *
                                                  (Q0 * TX0))) *
                                                ((VPFX_x2)[0] *
                                                 ((VPFX_x2)[0] *
                                                  ((VPFX_x2)[0] *
                                                   (VPFX_x2)[0])))) +
                                               ((Q0 * ((VPFX_x2)[0] *
                                                       ((VPFX_x2)[0] *
                                                        ((VPFX_x2)[0] *
                                                         ((VPFX_x2)[0] *
                                                          (VPFX_x2)[0]))))) +
                                                ((((((2.00000000000000000e+00 *
                                                      (r0 * r0)) +
                                                     (2.00000000000000000e+00 *
                                                      (MIN_R0 * MIN_R0))) *
                                                    (Q0 * TX0)) +
                                                   ((-4.00000000000000000e+00 *
                                                     (r0 *
                                                      (Q0 * (TX0 * TX0)))) +
                                                    ((2.00000000000000000e+00 *
                                                      (Q0 *
                                                       (TX0 * (TX0 * TX0)))) +
                                                     ((((((2.00000000000000000e+00 *
                                                           (r0 * r0)) +
                                                          (2.00000000000000000e+00 *
                                                           (MIN_R0 * MIN_R0))) *
                                                         Q0) +
                                                        ((-8.00000000000000000e+00 *
                                                          (r0 * (Q0 * TX0))) +
                                                         (6.00000000000000000e+00 *
                                                          (Q0 *
                                                           (TX0 * TX0))))) *
                                                       (VPFX_x2)[0]) +
                                                      ((((-4.00000000000000000e+00 *
                                                          (r0 * Q0)) +
                                                         (6.00000000000000000e+00 *
                                                          (Q0 * TX0))) *
                                                        ((VPFX_x2)[0] *
                                                         (VPFX_x2)[0])) +
                                                       (2.00000000000000000e+00 *
                                                        (Q0 *
                                                         ((VPFX_x2)[0] *
                                                          ((VPFX_x2)[0] *
                                                           (VPFX_x2)
                                                               [0]))))))))) *
                                                  ((VPFX_z1)[0] *
                                                   (VPFX_z1)[0])) +
                                                 (((Q0 * TX0) +
                                                   (Q0 * (VPFX_x2)[0])) *
                                                  ((VPFX_z1)[0] *
                                                   ((VPFX_z1)[0] *
                                                    ((VPFX_z1)[0] *
                                                     (VPFX_z1)
                                                         [0]))))))))))))))));
                                   })))))) -
                              (-1.00000000000000000e+00 *
                               (b0 *
                                ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) *
                                 ((VPFX_y1)[0] *
                                  ((VPFX_z1)[0] * ({
                                     (1.00000000000000000e+00 /
                                      ((((r0 * (r0 * (r0 * r0))) +
                                         ((2.00000000000000000e+00 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                          (MIN_R0 *
                                           (MIN_R0 * (MIN_R0 * MIN_R0))))) *
                                        (Q0 * TX0)) +
                                       ((((-4.00000000000000000e+00 *
                                           (r0 * (r0 * r0))) +
                                          (-4.00000000000000000e+00 *
                                           (r0 * (MIN_R0 * MIN_R0)))) *
                                         (Q0 * (TX0 * TX0))) +
                                        ((((6.00000000000000000e+00 *
                                            (r0 * r0)) +
                                           (2.00000000000000000e+00 *
                                            (MIN_R0 * MIN_R0))) *
                                          (Q0 * (TX0 * (TX0 * TX0)))) +
                                         ((-4.00000000000000000e+00 *
                                           (r0 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0)))))) +
                                          ((Q0 *
                                            (TX0 *
                                             (TX0 * (TX0 * (TX0 * TX0))))) +
                                           ((((((r0 * (r0 * (r0 * r0))) +
                                                ((2.00000000000000000e+00 *
                                                  ((r0 * r0) *
                                                   (MIN_R0 * MIN_R0))) +
                                                 (MIN_R0 *
                                                  (MIN_R0 *
                                                   (MIN_R0 * MIN_R0))))) *
                                               Q0) +
                                              ((((-8.00000000000000000e+00 *
                                                  (r0 * (r0 * r0))) +
                                                 (-8.00000000000000000e+00 *
                                                  (r0 * (MIN_R0 * MIN_R0)))) *
                                                (Q0 * TX0)) +
                                               ((((1.80000000000000000e+01 *
                                                   (r0 * r0)) +
                                                  (6.00000000000000000e+00 *
                                                   (MIN_R0 * MIN_R0))) *
                                                 (Q0 * (TX0 * TX0))) +
                                                ((-1.60000000000000000e+01 *
                                                  (r0 * (Q0 * (TX0 *
                                                               (TX0 * TX0))))) +
                                                 (5.00000000000000000e+00 *
                                                  (Q0 *
                                                   (TX0 *
                                                    (TX0 * (TX0 * TX0))))))))) *
                                             (VPFX_x2)[0]) +
                                            ((((((-4.00000000000000000e+00 *
                                                  (r0 * (r0 * r0))) +
                                                 (-4.00000000000000000e+00 *
                                                  (r0 * (MIN_R0 * MIN_R0)))) *
                                                Q0) +
                                               ((((1.80000000000000000e+01 *
                                                   (r0 * r0)) +
                                                  (6.00000000000000000e+00 *
                                                   (MIN_R0 * MIN_R0))) *
                                                 (Q0 * TX0)) +
                                                ((-2.40000000000000000e+01 *
                                                  (r0 * (Q0 * (TX0 * TX0)))) +
                                                 (1.00000000000000000e+01 *
                                                  (Q0 *
                                                   (TX0 * (TX0 * TX0))))))) *
                                              ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                             ((((((6.00000000000000000e+00 *
                                                   (r0 * r0)) +
                                                  (2.00000000000000000e+00 *
                                                   (MIN_R0 * MIN_R0))) *
                                                 Q0) +
                                                ((-1.60000000000000000e+01 *
                                                  (r0 * (Q0 * TX0))) +
                                                 (1.00000000000000000e+01 *
                                                  (Q0 * (TX0 * TX0))))) *
                                               ((VPFX_x2)[0] *
                                                ((VPFX_x2)[0] *
                                                 (VPFX_x2)[0]))) +
                                              ((((-4.00000000000000000e+00 *
                                                  (r0 * Q0)) +
                                                 (5.00000000000000000e+00 *
                                                  (Q0 * TX0))) *
                                                ((VPFX_x2)[0] *
                                                 ((VPFX_x2)[0] *
                                                  ((VPFX_x2)[0] *
                                                   (VPFX_x2)[0])))) +
                                               ((Q0 * ((VPFX_x2)[0] *
                                                       ((VPFX_x2)[0] *
                                                        ((VPFX_x2)[0] *
                                                         ((VPFX_x2)[0] *
                                                          (VPFX_x2)[0]))))) +
                                                ((((((2.00000000000000000e+00 *
                                                      (r0 * r0)) +
                                                     (2.00000000000000000e+00 *
                                                      (MIN_R0 * MIN_R0))) *
                                                    (Q0 * TX0)) +
                                                   ((-4.00000000000000000e+00 *
                                                     (r0 *
                                                      (Q0 * (TX0 * TX0)))) +
                                                    ((2.00000000000000000e+00 *
                                                      (Q0 *
                                                       (TX0 * (TX0 * TX0)))) +
                                                     ((((((2.00000000000000000e+00 *
                                                           (r0 * r0)) +
                                                          (2.00000000000000000e+00 *
                                                           (MIN_R0 * MIN_R0))) *
                                                         Q0) +
                                                        ((-8.00000000000000000e+00 *
                                                          (r0 * (Q0 * TX0))) +
                                                         (6.00000000000000000e+00 *
                                                          (Q0 *
                                                           (TX0 * TX0))))) *
                                                       (VPFX_x2)[0]) +
                                                      ((((-4.00000000000000000e+00 *
                                                          (r0 * Q0)) +
                                                         (6.00000000000000000e+00 *
                                                          (Q0 * TX0))) *
                                                        ((VPFX_x2)[0] *
                                                         (VPFX_x2)[0])) +
                                                       (2.00000000000000000e+00 *
                                                        (Q0 *
                                                         ((VPFX_x2)[0] *
                                                          ((VPFX_x2)[0] *
                                                           (VPFX_x2)
                                                               [0]))))))))) *
                                                  ((VPFX_z1)[0] *
                                                   (VPFX_z1)[0])) +
                                                 (((Q0 * TX0) +
                                                   (Q0 * (VPFX_x2)[0])) *
                                                  ((VPFX_z1)[0] *
                                                   ((VPFX_z1)[0] *
                                                    ((VPFX_z1)[0] *
                                                     (VPFX_z1)
                                                         [0]))))))))))))))));
                                   }))))))) +
                             0.00000000000000000e+00)) +
                           (((b0 *
                              (r0 * c_geo_log_simd((TX0 + (VPFX_x2)[0])))) -
                             (b0 *
                              (r0 * c_geo_log_simd((TX0 + (VPFX_x1)[0]))))) +
                            0.00000000000000000e+00)))) *
                        DT))))));
              __m256d VPFX_z2[1];
              double *z2 = VPFX_z2;

              ((VPFX_z2)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_z0)[0]) +
                     (2.00000000000000000e+00 * (VPFX_z1)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_Z * DELTA_Z)); }) *
                     (QE_MASS * (Deltat * ((VPFX_allincfvz)[0] +
                                           (-1.00000000000000000e+00 *
                                            (VPFX_iBz)[0])))))));
              ((VPFX_iBz)[0] = (0.00000000000000000e+00 - ((__m256d){})));
              __m256d VPFX_z3[1];
              double *z3 = VPFX_z3;

              ((VPFX_z3)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_z1)[0]) +
                     (2.00000000000000000e+00 * (VPFX_z2)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_Z * DELTA_Z)); }) *
                     (-1 * (Deltat * (QE_MASS * (VPFX_iBz)[0]))))));
              ((VPFX_iBy)[0] =
                   ((-1.00000000000000000e+00 *
                     (((b0 *
                        ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) * ({
                           (1.00000000000000000e+00 /
                            ((((2.00000000000000000e+00 * (r0 * r0)) +
                               (2.00000000000000000e+00 * (MIN_R0 * MIN_R0))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * (TX0 * TX0)))) +
                              ((2.00000000000000000e+00 *
                                (Q0 * (TX0 * (TX0 * TX0)))) +
                               ((((((2.00000000000000000e+00 * (r0 * r0)) +
                                    (2.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   Q0) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 * (Q0 * TX0))) +
                                   (6.00000000000000000e+00 *
                                    (Q0 * (TX0 * TX0))))) *
                                 (VPFX_x2)[0]) +
                                ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                   (6.00000000000000000e+00 * (Q0 * TX0))) *
                                  ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                  (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                    (2.00000000000000000e+00 *
                                     (Q0 * (VPFX_x2)[0]))) *
                                   ((VPFX_z2)[0] * (VPFX_z2)[0])))))))));
                         }))) -
                       (b0 *
                        ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) * ({
                           (1.00000000000000000e+00 /
                            ((((2.00000000000000000e+00 * (r0 * r0)) +
                               (2.00000000000000000e+00 * (MIN_R0 * MIN_R0))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * (TX0 * TX0)))) +
                              ((2.00000000000000000e+00 *
                                (Q0 * (TX0 * (TX0 * TX0)))) +
                               ((((((2.00000000000000000e+00 * (r0 * r0)) +
                                    (2.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   Q0) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 * (Q0 * TX0))) +
                                   (6.00000000000000000e+00 *
                                    (Q0 * (TX0 * TX0))))) *
                                 (VPFX_x2)[0]) +
                                ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                   (6.00000000000000000e+00 * (Q0 * TX0))) *
                                  ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                  (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                    (2.00000000000000000e+00 *
                                     (Q0 * (VPFX_x2)[0]))) *
                                   ((VPFX_z1)[0] * (VPFX_z1)[0])))))))));
                         })))) +
                      0.00000000000000000e+00)) +
                    (-1.00000000000000000e+00 *
                     (((b0 *
                        ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) * ({
                           (1.00000000000000000e+00 /
                            ((((2.00000000000000000e+00 * (r0 * r0)) +
                               (2.00000000000000000e+00 * (MIN_R0 * MIN_R0))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * (TX0 * TX0)))) +
                              ((2.00000000000000000e+00 *
                                (Q0 * (TX0 * (TX0 * TX0)))) +
                               ((((((2.00000000000000000e+00 * (r0 * r0)) +
                                    (2.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   Q0) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 * (Q0 * TX0))) +
                                   (6.00000000000000000e+00 *
                                    (Q0 * (TX0 * TX0))))) *
                                 (VPFX_x2)[0]) +
                                ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                   (6.00000000000000000e+00 * (Q0 * TX0))) *
                                  ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                  (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                    (2.00000000000000000e+00 *
                                     (Q0 * (VPFX_x2)[0]))) *
                                   ((VPFX_z3)[0] * (VPFX_z3)[0])))))))));
                         }))) -
                       (b0 *
                        ((MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))) * ({
                           (1.00000000000000000e+00 /
                            ((((2.00000000000000000e+00 * (r0 * r0)) +
                               (2.00000000000000000e+00 * (MIN_R0 * MIN_R0))) *
                              (Q0 * TX0)) +
                             ((-4.00000000000000000e+00 *
                               (r0 * (Q0 * (TX0 * TX0)))) +
                              ((2.00000000000000000e+00 *
                                (Q0 * (TX0 * (TX0 * TX0)))) +
                               ((((((2.00000000000000000e+00 * (r0 * r0)) +
                                    (2.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   Q0) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 * (Q0 * TX0))) +
                                   (6.00000000000000000e+00 *
                                    (Q0 * (TX0 * TX0))))) *
                                 (VPFX_x2)[0]) +
                                ((((-4.00000000000000000e+00 * (r0 * Q0)) +
                                   (6.00000000000000000e+00 * (Q0 * TX0))) *
                                  ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                 ((2.00000000000000000e+00 *
                                   (Q0 * ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                  (((2.00000000000000000e+00 * (Q0 * TX0)) +
                                    (2.00000000000000000e+00 *
                                     (Q0 * (VPFX_x2)[0]))) *
                                   ((VPFX_z2)[0] * (VPFX_z2)[0])))))))));
                         })))) +
                      0.00000000000000000e+00))));
              __m256d VPFX_y3[1];
              double *y3 = VPFX_y3;

              ((VPFX_y3)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_y1)[0]) +
                     (2.00000000000000000e+00 * (VPFX_y2)[0])) +
                    ((TX0 * TX0) *
                     ((-1 * (Deltat * (QE_MASS * (VPFX_iBy)[0]))) * ({
                        (1.00000000000000000e+00 /
                         (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
                          ((2.00000000000000000e+00 *
                            ((DELTA_Y * DELTA_Y) * (TX0 * (VPFX_x2)[0]))) +
                           ((DELTA_Y * DELTA_Y) *
                            ((VPFX_x2)[0] * (VPFX_x2)[0])))));
                      })))));
              ((VPFX_iBx)[0] =
                   ((((b0 * (r0 * (({
                                     (1.00000000000000000e+00 /
                                      (TX0 + (VPFX_x2)[0]));
                                   }) *
                                   (VPFX_z2)[0]))) -
                      (b0 * (r0 * (({
                                     (1.00000000000000000e+00 /
                                      (TX0 + (VPFX_x2)[0]));
                                   }) *
                                   (VPFX_z1)[0])))) +
                     0.00000000000000000e+00) +
                    ((((b0 * (r0 * (({
                                      (1.00000000000000000e+00 /
                                       (TX0 + (VPFX_x2)[0]));
                                    }) *
                                    (VPFX_z3)[0]))) -
                       (b0 * (r0 * (({
                                      (1.00000000000000000e+00 /
                                       (TX0 + (VPFX_x2)[0]));
                                    }) *
                                    (VPFX_z2)[0])))) +
                      0.00000000000000000e+00) +
                     ((-1.00000000000000000e+00 *
                       (((-1.00000000000000000e+00 *
                          ((VPFX_y2)[0] *
                           (((b0 *
                              ((r0 * (r0 * (r0 * r0))) * (MIN_R0 * MIN_R0))) +
                             ((b0 * ((r0 * r0) *
                                     (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                              ((-4.00000000000000000e+00 *
                                (b0 * ((r0 * (r0 * r0)) *
                                       ((MIN_R0 * MIN_R0) * TX0)))) +
                               ((((6.00000000000000000e+00 *
                                   (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                  (-1.00000000000000000e+00 *
                                   (b0 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (TX0 * TX0)) +
                                ((-4.00000000000000000e+00 *
                                  (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))) +
                                 ((b0 * ((MIN_R0 * MIN_R0) *
                                         (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * ((r0 * (r0 * r0)) *
                                             (MIN_R0 * MIN_R0)))) +
                                     ((((1.20000000000000000e+01 *
                                         (b0 *
                                          ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                        (-2.00000000000000000e+00 *
                                         (b0 *
                                          (MIN_R0 *
                                           (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                       TX0) +
                                      ((-1.20000000000000000e+01 *
                                        (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                     (TX0 * TX0))))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))))) *
                                    (VPFX_x2)[0]) +
                                   ((((6.00000000000000000e+00 *
                                       (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                      ((-1.00000000000000000e+00 *
                                        (b0 * (MIN_R0 *
                                               (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                                       ((-1.20000000000000000e+01 *
                                         (b0 *
                                          (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                                        (6.00000000000000000e+00 *
                                         (b0 * ((MIN_R0 * MIN_R0) *
                                                (TX0 * TX0))))))) *
                                     ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                    ((((-4.00000000000000000e+00 *
                                        (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                      ((VPFX_x2)[0] *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                     ((b0 *
                                       ((MIN_R0 * MIN_R0) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                      ((((2.00000000000000000e+00 *
                                          (b0 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                         ((b0 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))) +
                                          ((-4.00000000000000000e+00 *
                                            (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                         TX0)))) +
                                           ((2.00000000000000000e+00 *
                                             (b0 * ((MIN_R0 * MIN_R0) *
                                                    (TX0 * TX0)))) +
                                            ((((-4.00000000000000000e+00 *
                                                (b0 *
                                                 (r0 * (MIN_R0 * MIN_R0)))) +
                                               (4.00000000000000000e+00 *
                                                (b0 *
                                                 ((MIN_R0 * MIN_R0) * TX0)))) *
                                              (VPFX_x2)[0]) +
                                             (2.00000000000000000e+00 *
                                              (b0 * ((MIN_R0 * MIN_R0) *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))))) *
                                        ((VPFX_z1)[0] * (VPFX_z1)[0])) +
                                       (b0 * ((MIN_R0 * MIN_R0) *
                                              ((VPFX_z1)[0] *
                                               ((VPFX_z1)[0] *
                                                ((VPFX_z1)[0] *
                                                 (VPFX_z1)[0])))))))))))))))) *
                            ({
                              (1.00000000000000000e+00 /
                               ((((2.00000000000000000e+00 *
                                   (r0 * (r0 * (r0 * r0)))) +
                                  ((4.00000000000000000e+00 *
                                    ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                   (2.00000000000000000e+00 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (Q0 * (TX0 * TX0))) +
                                ((((-8.00000000000000000e+00 *
                                    (r0 * (r0 * r0))) +
                                   (-8.00000000000000000e+00 *
                                    (r0 * (MIN_R0 * MIN_R0)))) *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((1.20000000000000000e+01 * (r0 * r0)) +
                                    (4.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   (Q0 * (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 *
                                     (Q0 *
                                      (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 *
                                       (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                    ((((((4.00000000000000000e+00 *
                                          (r0 * (r0 * (r0 * r0)))) +
                                         ((8.00000000000000000e+00 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                          (4.00000000000000000e+00 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                        (Q0 * TX0)) +
                                       ((((-2.40000000000000000e+01 *
                                           (r0 * (r0 * r0))) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * (MIN_R0 * MIN_R0)))) *
                                         (Q0 * (TX0 * TX0))) +
                                        ((((4.80000000000000000e+01 *
                                            (r0 * r0)) +
                                           (1.60000000000000000e+01 *
                                            (MIN_R0 * MIN_R0))) *
                                          (Q0 * (TX0 * (TX0 * TX0)))) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0)))))) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * (TX0 *
                                                  (TX0 *
                                                   (TX0 * (TX0 * TX0)))))))))) *
                                      (VPFX_x2)[0]) +
                                     ((((((2.00000000000000000e+00 *
                                           (r0 * (r0 * (r0 * r0)))) +
                                          ((4.00000000000000000e+00 *
                                            ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                           (2.00000000000000000e+00 *
                                            (MIN_R0 *
                                             (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                         Q0) +
                                        ((((-2.40000000000000000e+01 *
                                            (r0 * (r0 * r0))) +
                                           (-2.40000000000000000e+01 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          (Q0 * TX0)) +
                                         ((((7.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (2.40000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * (TX0 * TX0))) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * (TX0 * TX0))))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0))))))))) *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                      ((((((-8.00000000000000000e+00 *
                                            (r0 * (r0 * r0))) +
                                           (-8.00000000000000000e+00 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          Q0) +
                                         ((((4.80000000000000000e+01 *
                                             (r0 * r0)) +
                                            (1.60000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * TX0)) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * TX0)))) +
                                           (4.00000000000000000e+01 *
                                            (Q0 * (TX0 * (TX0 * TX0))))))) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                       ((((((1.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (4.00000000000000000e+00 *
                                             (MIN_R0 * MIN_R0))) *
                                           Q0) +
                                          ((-4.00000000000000000e+01 *
                                            (r0 * (Q0 * TX0))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 * (TX0 * TX0))))) *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                        ((((-8.00000000000000000e+00 *
                                            (r0 * Q0)) +
                                           (1.20000000000000000e+01 *
                                            (Q0 * TX0))) *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] *
                                            ((VPFX_x2)[0] *
                                             ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                         ((2.00000000000000000e+00 *
                                           (Q0 * ((VPFX_x2)[0] *
                                                  ((VPFX_x2)[0] *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))) +
                                          ((((((4.00000000000000000e+00 *
                                                (r0 * r0)) +
                                               (4.00000000000000000e+00 *
                                                (MIN_R0 * MIN_R0))) *
                                              (Q0 * (TX0 * TX0))) +
                                             ((-8.00000000000000000e+00 *
                                               (r0 *
                                                (Q0 * (TX0 * (TX0 * TX0))))) +
                                              ((4.00000000000000000e+00 *
                                                (Q0 *
                                                 (TX0 * (TX0 * (TX0 * TX0))))) +
                                               ((((((8.00000000000000000e+00 *
                                                     (r0 * r0)) +
                                                    (8.00000000000000000e+00 *
                                                     (MIN_R0 * MIN_R0))) *
                                                   (Q0 * TX0)) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * (TX0 * TX0)))) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 *
                                                     (TX0 * (TX0 * TX0)))))) *
                                                 (VPFX_x2)[0]) +
                                                ((((((4.00000000000000000e+00 *
                                                      (r0 * r0)) +
                                                     (4.00000000000000000e+00 *
                                                      (MIN_R0 * MIN_R0))) *
                                                    Q0) +
                                                   ((-2.40000000000000000e+01 *
                                                     (r0 * (Q0 * TX0))) +
                                                    (2.40000000000000000e+01 *
                                                     (Q0 * (TX0 * TX0))))) *
                                                  ((VPFX_x2)[0] *
                                                   (VPFX_x2)[0])) +
                                                 ((((-8.00000000000000000e+00 *
                                                     (r0 * Q0)) +
                                                    (1.60000000000000000e+01 *
                                                     (Q0 * TX0))) *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     (VPFX_x2)[0]))) +
                                                  (4.00000000000000000e+00 *
                                                   (Q0 *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      ((VPFX_x2)[0] *
                                                       (VPFX_x2)[0]))))))))))) *
                                            ((VPFX_z1)[0] * (VPFX_z1)[0])) +
                                           (((2.00000000000000000e+00 *
                                              (Q0 * (TX0 * TX0))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * (TX0 * (VPFX_x2)[0]))) +
                                              (2.00000000000000000e+00 *
                                               (Q0 * ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))) *
                                            ((VPFX_z1)[0] *
                                             ((VPFX_z1)[0] *
                                              ((VPFX_z1)[0] *
                                               (VPFX_z1)[0])))))))))))))))));
                            })))) -
                         (-1.00000000000000000e+00 *
                          ((VPFX_y1)[0] *
                           (((b0 *
                              ((r0 * (r0 * (r0 * r0))) * (MIN_R0 * MIN_R0))) +
                             ((b0 * ((r0 * r0) *
                                     (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                              ((-4.00000000000000000e+00 *
                                (b0 * ((r0 * (r0 * r0)) *
                                       ((MIN_R0 * MIN_R0) * TX0)))) +
                               ((((6.00000000000000000e+00 *
                                   (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                  (-1.00000000000000000e+00 *
                                   (b0 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (TX0 * TX0)) +
                                ((-4.00000000000000000e+00 *
                                  (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))) +
                                 ((b0 * ((MIN_R0 * MIN_R0) *
                                         (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * ((r0 * (r0 * r0)) *
                                             (MIN_R0 * MIN_R0)))) +
                                     ((((1.20000000000000000e+01 *
                                         (b0 *
                                          ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                        (-2.00000000000000000e+00 *
                                         (b0 *
                                          (MIN_R0 *
                                           (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                       TX0) +
                                      ((-1.20000000000000000e+01 *
                                        (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                     (TX0 * TX0))))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))))) *
                                    (VPFX_x2)[0]) +
                                   ((((6.00000000000000000e+00 *
                                       (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                      ((-1.00000000000000000e+00 *
                                        (b0 * (MIN_R0 *
                                               (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                                       ((-1.20000000000000000e+01 *
                                         (b0 *
                                          (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                                        (6.00000000000000000e+00 *
                                         (b0 * ((MIN_R0 * MIN_R0) *
                                                (TX0 * TX0))))))) *
                                     ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                    ((((-4.00000000000000000e+00 *
                                        (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                      ((VPFX_x2)[0] *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                     ((b0 *
                                       ((MIN_R0 * MIN_R0) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                      ((((2.00000000000000000e+00 *
                                          (b0 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                         ((b0 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))) +
                                          ((-4.00000000000000000e+00 *
                                            (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                         TX0)))) +
                                           ((2.00000000000000000e+00 *
                                             (b0 * ((MIN_R0 * MIN_R0) *
                                                    (TX0 * TX0)))) +
                                            ((((-4.00000000000000000e+00 *
                                                (b0 *
                                                 (r0 * (MIN_R0 * MIN_R0)))) +
                                               (4.00000000000000000e+00 *
                                                (b0 *
                                                 ((MIN_R0 * MIN_R0) * TX0)))) *
                                              (VPFX_x2)[0]) +
                                             (2.00000000000000000e+00 *
                                              (b0 * ((MIN_R0 * MIN_R0) *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))))) *
                                        ((VPFX_z1)[0] * (VPFX_z1)[0])) +
                                       (b0 * ((MIN_R0 * MIN_R0) *
                                              ((VPFX_z1)[0] *
                                               ((VPFX_z1)[0] *
                                                ((VPFX_z1)[0] *
                                                 (VPFX_z1)[0])))))))))))))))) *
                            ({
                              (1.00000000000000000e+00 /
                               ((((2.00000000000000000e+00 *
                                   (r0 * (r0 * (r0 * r0)))) +
                                  ((4.00000000000000000e+00 *
                                    ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                   (2.00000000000000000e+00 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (Q0 * (TX0 * TX0))) +
                                ((((-8.00000000000000000e+00 *
                                    (r0 * (r0 * r0))) +
                                   (-8.00000000000000000e+00 *
                                    (r0 * (MIN_R0 * MIN_R0)))) *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((1.20000000000000000e+01 * (r0 * r0)) +
                                    (4.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   (Q0 * (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 *
                                     (Q0 *
                                      (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 *
                                       (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                    ((((((4.00000000000000000e+00 *
                                          (r0 * (r0 * (r0 * r0)))) +
                                         ((8.00000000000000000e+00 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                          (4.00000000000000000e+00 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                        (Q0 * TX0)) +
                                       ((((-2.40000000000000000e+01 *
                                           (r0 * (r0 * r0))) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * (MIN_R0 * MIN_R0)))) *
                                         (Q0 * (TX0 * TX0))) +
                                        ((((4.80000000000000000e+01 *
                                            (r0 * r0)) +
                                           (1.60000000000000000e+01 *
                                            (MIN_R0 * MIN_R0))) *
                                          (Q0 * (TX0 * (TX0 * TX0)))) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0)))))) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * (TX0 *
                                                  (TX0 *
                                                   (TX0 * (TX0 * TX0)))))))))) *
                                      (VPFX_x2)[0]) +
                                     ((((((2.00000000000000000e+00 *
                                           (r0 * (r0 * (r0 * r0)))) +
                                          ((4.00000000000000000e+00 *
                                            ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                           (2.00000000000000000e+00 *
                                            (MIN_R0 *
                                             (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                         Q0) +
                                        ((((-2.40000000000000000e+01 *
                                            (r0 * (r0 * r0))) +
                                           (-2.40000000000000000e+01 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          (Q0 * TX0)) +
                                         ((((7.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (2.40000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * (TX0 * TX0))) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * (TX0 * TX0))))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0))))))))) *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                      ((((((-8.00000000000000000e+00 *
                                            (r0 * (r0 * r0))) +
                                           (-8.00000000000000000e+00 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          Q0) +
                                         ((((4.80000000000000000e+01 *
                                             (r0 * r0)) +
                                            (1.60000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * TX0)) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * TX0)))) +
                                           (4.00000000000000000e+01 *
                                            (Q0 * (TX0 * (TX0 * TX0))))))) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                       ((((((1.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (4.00000000000000000e+00 *
                                             (MIN_R0 * MIN_R0))) *
                                           Q0) +
                                          ((-4.00000000000000000e+01 *
                                            (r0 * (Q0 * TX0))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 * (TX0 * TX0))))) *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                        ((((-8.00000000000000000e+00 *
                                            (r0 * Q0)) +
                                           (1.20000000000000000e+01 *
                                            (Q0 * TX0))) *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] *
                                            ((VPFX_x2)[0] *
                                             ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                         ((2.00000000000000000e+00 *
                                           (Q0 * ((VPFX_x2)[0] *
                                                  ((VPFX_x2)[0] *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))) +
                                          ((((((4.00000000000000000e+00 *
                                                (r0 * r0)) +
                                               (4.00000000000000000e+00 *
                                                (MIN_R0 * MIN_R0))) *
                                              (Q0 * (TX0 * TX0))) +
                                             ((-8.00000000000000000e+00 *
                                               (r0 *
                                                (Q0 * (TX0 * (TX0 * TX0))))) +
                                              ((4.00000000000000000e+00 *
                                                (Q0 *
                                                 (TX0 * (TX0 * (TX0 * TX0))))) +
                                               ((((((8.00000000000000000e+00 *
                                                     (r0 * r0)) +
                                                    (8.00000000000000000e+00 *
                                                     (MIN_R0 * MIN_R0))) *
                                                   (Q0 * TX0)) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * (TX0 * TX0)))) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 *
                                                     (TX0 * (TX0 * TX0)))))) *
                                                 (VPFX_x2)[0]) +
                                                ((((((4.00000000000000000e+00 *
                                                      (r0 * r0)) +
                                                     (4.00000000000000000e+00 *
                                                      (MIN_R0 * MIN_R0))) *
                                                    Q0) +
                                                   ((-2.40000000000000000e+01 *
                                                     (r0 * (Q0 * TX0))) +
                                                    (2.40000000000000000e+01 *
                                                     (Q0 * (TX0 * TX0))))) *
                                                  ((VPFX_x2)[0] *
                                                   (VPFX_x2)[0])) +
                                                 ((((-8.00000000000000000e+00 *
                                                     (r0 * Q0)) +
                                                    (1.60000000000000000e+01 *
                                                     (Q0 * TX0))) *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     (VPFX_x2)[0]))) +
                                                  (4.00000000000000000e+00 *
                                                   (Q0 *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      ((VPFX_x2)[0] *
                                                       (VPFX_x2)[0]))))))))))) *
                                            ((VPFX_z1)[0] * (VPFX_z1)[0])) +
                                           (((2.00000000000000000e+00 *
                                              (Q0 * (TX0 * TX0))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * (TX0 * (VPFX_x2)[0]))) +
                                              (2.00000000000000000e+00 *
                                               (Q0 * ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))) *
                                            ((VPFX_z1)[0] *
                                             ((VPFX_z1)[0] *
                                              ((VPFX_z1)[0] *
                                               (VPFX_z1)[0])))))))))))))))));
                            }))))) +
                        0.00000000000000000e+00)) +
                      (-1.00000000000000000e+00 *
                       (((-1.00000000000000000e+00 *
                          ((VPFX_y3)[0] *
                           (((b0 *
                              ((r0 * (r0 * (r0 * r0))) * (MIN_R0 * MIN_R0))) +
                             ((b0 * ((r0 * r0) *
                                     (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                              ((-4.00000000000000000e+00 *
                                (b0 * ((r0 * (r0 * r0)) *
                                       ((MIN_R0 * MIN_R0) * TX0)))) +
                               ((((6.00000000000000000e+00 *
                                   (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                  (-1.00000000000000000e+00 *
                                   (b0 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (TX0 * TX0)) +
                                ((-4.00000000000000000e+00 *
                                  (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))) +
                                 ((b0 * ((MIN_R0 * MIN_R0) *
                                         (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * ((r0 * (r0 * r0)) *
                                             (MIN_R0 * MIN_R0)))) +
                                     ((((1.20000000000000000e+01 *
                                         (b0 *
                                          ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                        (-2.00000000000000000e+00 *
                                         (b0 *
                                          (MIN_R0 *
                                           (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                       TX0) +
                                      ((-1.20000000000000000e+01 *
                                        (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                     (TX0 * TX0))))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))))) *
                                    (VPFX_x2)[0]) +
                                   ((((6.00000000000000000e+00 *
                                       (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                      ((-1.00000000000000000e+00 *
                                        (b0 * (MIN_R0 *
                                               (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                                       ((-1.20000000000000000e+01 *
                                         (b0 *
                                          (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                                        (6.00000000000000000e+00 *
                                         (b0 * ((MIN_R0 * MIN_R0) *
                                                (TX0 * TX0))))))) *
                                     ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                    ((((-4.00000000000000000e+00 *
                                        (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                      ((VPFX_x2)[0] *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                     ((b0 *
                                       ((MIN_R0 * MIN_R0) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                      ((((2.00000000000000000e+00 *
                                          (b0 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                         ((b0 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))) +
                                          ((-4.00000000000000000e+00 *
                                            (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                         TX0)))) +
                                           ((2.00000000000000000e+00 *
                                             (b0 * ((MIN_R0 * MIN_R0) *
                                                    (TX0 * TX0)))) +
                                            ((((-4.00000000000000000e+00 *
                                                (b0 *
                                                 (r0 * (MIN_R0 * MIN_R0)))) +
                                               (4.00000000000000000e+00 *
                                                (b0 *
                                                 ((MIN_R0 * MIN_R0) * TX0)))) *
                                              (VPFX_x2)[0]) +
                                             (2.00000000000000000e+00 *
                                              (b0 * ((MIN_R0 * MIN_R0) *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))))) *
                                        ((VPFX_z3)[0] * (VPFX_z3)[0])) +
                                       (b0 * ((MIN_R0 * MIN_R0) *
                                              ((VPFX_z3)[0] *
                                               ((VPFX_z3)[0] *
                                                ((VPFX_z3)[0] *
                                                 (VPFX_z3)[0])))))))))))))))) *
                            ({
                              (1.00000000000000000e+00 /
                               ((((2.00000000000000000e+00 *
                                   (r0 * (r0 * (r0 * r0)))) +
                                  ((4.00000000000000000e+00 *
                                    ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                   (2.00000000000000000e+00 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (Q0 * (TX0 * TX0))) +
                                ((((-8.00000000000000000e+00 *
                                    (r0 * (r0 * r0))) +
                                   (-8.00000000000000000e+00 *
                                    (r0 * (MIN_R0 * MIN_R0)))) *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((1.20000000000000000e+01 * (r0 * r0)) +
                                    (4.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   (Q0 * (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 *
                                     (Q0 *
                                      (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 *
                                       (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                    ((((((4.00000000000000000e+00 *
                                          (r0 * (r0 * (r0 * r0)))) +
                                         ((8.00000000000000000e+00 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                          (4.00000000000000000e+00 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                        (Q0 * TX0)) +
                                       ((((-2.40000000000000000e+01 *
                                           (r0 * (r0 * r0))) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * (MIN_R0 * MIN_R0)))) *
                                         (Q0 * (TX0 * TX0))) +
                                        ((((4.80000000000000000e+01 *
                                            (r0 * r0)) +
                                           (1.60000000000000000e+01 *
                                            (MIN_R0 * MIN_R0))) *
                                          (Q0 * (TX0 * (TX0 * TX0)))) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0)))))) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * (TX0 *
                                                  (TX0 *
                                                   (TX0 * (TX0 * TX0)))))))))) *
                                      (VPFX_x2)[0]) +
                                     ((((((2.00000000000000000e+00 *
                                           (r0 * (r0 * (r0 * r0)))) +
                                          ((4.00000000000000000e+00 *
                                            ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                           (2.00000000000000000e+00 *
                                            (MIN_R0 *
                                             (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                         Q0) +
                                        ((((-2.40000000000000000e+01 *
                                            (r0 * (r0 * r0))) +
                                           (-2.40000000000000000e+01 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          (Q0 * TX0)) +
                                         ((((7.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (2.40000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * (TX0 * TX0))) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * (TX0 * TX0))))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0))))))))) *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                      ((((((-8.00000000000000000e+00 *
                                            (r0 * (r0 * r0))) +
                                           (-8.00000000000000000e+00 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          Q0) +
                                         ((((4.80000000000000000e+01 *
                                             (r0 * r0)) +
                                            (1.60000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * TX0)) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * TX0)))) +
                                           (4.00000000000000000e+01 *
                                            (Q0 * (TX0 * (TX0 * TX0))))))) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                       ((((((1.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (4.00000000000000000e+00 *
                                             (MIN_R0 * MIN_R0))) *
                                           Q0) +
                                          ((-4.00000000000000000e+01 *
                                            (r0 * (Q0 * TX0))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 * (TX0 * TX0))))) *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                        ((((-8.00000000000000000e+00 *
                                            (r0 * Q0)) +
                                           (1.20000000000000000e+01 *
                                            (Q0 * TX0))) *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] *
                                            ((VPFX_x2)[0] *
                                             ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                         ((2.00000000000000000e+00 *
                                           (Q0 * ((VPFX_x2)[0] *
                                                  ((VPFX_x2)[0] *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))) +
                                          ((((((4.00000000000000000e+00 *
                                                (r0 * r0)) +
                                               (4.00000000000000000e+00 *
                                                (MIN_R0 * MIN_R0))) *
                                              (Q0 * (TX0 * TX0))) +
                                             ((-8.00000000000000000e+00 *
                                               (r0 *
                                                (Q0 * (TX0 * (TX0 * TX0))))) +
                                              ((4.00000000000000000e+00 *
                                                (Q0 *
                                                 (TX0 * (TX0 * (TX0 * TX0))))) +
                                               ((((((8.00000000000000000e+00 *
                                                     (r0 * r0)) +
                                                    (8.00000000000000000e+00 *
                                                     (MIN_R0 * MIN_R0))) *
                                                   (Q0 * TX0)) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * (TX0 * TX0)))) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 *
                                                     (TX0 * (TX0 * TX0)))))) *
                                                 (VPFX_x2)[0]) +
                                                ((((((4.00000000000000000e+00 *
                                                      (r0 * r0)) +
                                                     (4.00000000000000000e+00 *
                                                      (MIN_R0 * MIN_R0))) *
                                                    Q0) +
                                                   ((-2.40000000000000000e+01 *
                                                     (r0 * (Q0 * TX0))) +
                                                    (2.40000000000000000e+01 *
                                                     (Q0 * (TX0 * TX0))))) *
                                                  ((VPFX_x2)[0] *
                                                   (VPFX_x2)[0])) +
                                                 ((((-8.00000000000000000e+00 *
                                                     (r0 * Q0)) +
                                                    (1.60000000000000000e+01 *
                                                     (Q0 * TX0))) *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     (VPFX_x2)[0]))) +
                                                  (4.00000000000000000e+00 *
                                                   (Q0 *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      ((VPFX_x2)[0] *
                                                       (VPFX_x2)[0]))))))))))) *
                                            ((VPFX_z3)[0] * (VPFX_z3)[0])) +
                                           (((2.00000000000000000e+00 *
                                              (Q0 * (TX0 * TX0))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * (TX0 * (VPFX_x2)[0]))) +
                                              (2.00000000000000000e+00 *
                                               (Q0 * ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))) *
                                            ((VPFX_z3)[0] *
                                             ((VPFX_z3)[0] *
                                              ((VPFX_z3)[0] *
                                               (VPFX_z3)[0])))))))))))))))));
                            })))) -
                         (-1.00000000000000000e+00 *
                          ((VPFX_y2)[0] *
                           (((b0 *
                              ((r0 * (r0 * (r0 * r0))) * (MIN_R0 * MIN_R0))) +
                             ((b0 * ((r0 * r0) *
                                     (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                              ((-4.00000000000000000e+00 *
                                (b0 * ((r0 * (r0 * r0)) *
                                       ((MIN_R0 * MIN_R0) * TX0)))) +
                               ((((6.00000000000000000e+00 *
                                   (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                  (-1.00000000000000000e+00 *
                                   (b0 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (TX0 * TX0)) +
                                ((-4.00000000000000000e+00 *
                                  (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))) +
                                 ((b0 * ((MIN_R0 * MIN_R0) *
                                         (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((((-4.00000000000000000e+00 *
                                      (b0 * ((r0 * (r0 * r0)) *
                                             (MIN_R0 * MIN_R0)))) +
                                     ((((1.20000000000000000e+01 *
                                         (b0 *
                                          ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                        (-2.00000000000000000e+00 *
                                         (b0 *
                                          (MIN_R0 *
                                           (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                       TX0) +
                                      ((-1.20000000000000000e+01 *
                                        (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                     (TX0 * TX0))))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) *
                                               (TX0 * (TX0 * TX0)))))))) *
                                    (VPFX_x2)[0]) +
                                   ((((6.00000000000000000e+00 *
                                       (b0 * ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                      ((-1.00000000000000000e+00 *
                                        (b0 * (MIN_R0 *
                                               (MIN_R0 * (MIN_R0 * MIN_R0))))) +
                                       ((-1.20000000000000000e+01 *
                                         (b0 *
                                          (r0 * ((MIN_R0 * MIN_R0) * TX0)))) +
                                        (6.00000000000000000e+00 *
                                         (b0 * ((MIN_R0 * MIN_R0) *
                                                (TX0 * TX0))))))) *
                                     ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                    ((((-4.00000000000000000e+00 *
                                        (b0 * (r0 * (MIN_R0 * MIN_R0)))) +
                                       (4.00000000000000000e+00 *
                                        (b0 * ((MIN_R0 * MIN_R0) * TX0)))) *
                                      ((VPFX_x2)[0] *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                     ((b0 *
                                       ((MIN_R0 * MIN_R0) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                      ((((2.00000000000000000e+00 *
                                          (b0 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0)))) +
                                         ((b0 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))) +
                                          ((-4.00000000000000000e+00 *
                                            (b0 * (r0 * ((MIN_R0 * MIN_R0) *
                                                         TX0)))) +
                                           ((2.00000000000000000e+00 *
                                             (b0 * ((MIN_R0 * MIN_R0) *
                                                    (TX0 * TX0)))) +
                                            ((((-4.00000000000000000e+00 *
                                                (b0 *
                                                 (r0 * (MIN_R0 * MIN_R0)))) +
                                               (4.00000000000000000e+00 *
                                                (b0 *
                                                 ((MIN_R0 * MIN_R0) * TX0)))) *
                                              (VPFX_x2)[0]) +
                                             (2.00000000000000000e+00 *
                                              (b0 * ((MIN_R0 * MIN_R0) *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))))) *
                                        ((VPFX_z3)[0] * (VPFX_z3)[0])) +
                                       (b0 * ((MIN_R0 * MIN_R0) *
                                              ((VPFX_z3)[0] *
                                               ((VPFX_z3)[0] *
                                                ((VPFX_z3)[0] *
                                                 (VPFX_z3)[0])))))))))))))))) *
                            ({
                              (1.00000000000000000e+00 /
                               ((((2.00000000000000000e+00 *
                                   (r0 * (r0 * (r0 * r0)))) +
                                  ((4.00000000000000000e+00 *
                                    ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                   (2.00000000000000000e+00 *
                                    (MIN_R0 * (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                 (Q0 * (TX0 * TX0))) +
                                ((((-8.00000000000000000e+00 *
                                    (r0 * (r0 * r0))) +
                                   (-8.00000000000000000e+00 *
                                    (r0 * (MIN_R0 * MIN_R0)))) *
                                  (Q0 * (TX0 * (TX0 * TX0)))) +
                                 ((((1.20000000000000000e+01 * (r0 * r0)) +
                                    (4.00000000000000000e+00 *
                                     (MIN_R0 * MIN_R0))) *
                                   (Q0 * (TX0 * (TX0 * (TX0 * TX0))))) +
                                  ((-8.00000000000000000e+00 *
                                    (r0 *
                                     (Q0 *
                                      (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                   ((2.00000000000000000e+00 *
                                     (Q0 *
                                      (TX0 *
                                       (TX0 * (TX0 * (TX0 * (TX0 * TX0))))))) +
                                    ((((((4.00000000000000000e+00 *
                                          (r0 * (r0 * (r0 * r0)))) +
                                         ((8.00000000000000000e+00 *
                                           ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                          (4.00000000000000000e+00 *
                                           (MIN_R0 *
                                            (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                        (Q0 * TX0)) +
                                       ((((-2.40000000000000000e+01 *
                                           (r0 * (r0 * r0))) +
                                          (-2.40000000000000000e+01 *
                                           (r0 * (MIN_R0 * MIN_R0)))) *
                                         (Q0 * (TX0 * TX0))) +
                                        ((((4.80000000000000000e+01 *
                                            (r0 * r0)) +
                                           (1.60000000000000000e+01 *
                                            (MIN_R0 * MIN_R0))) *
                                          (Q0 * (TX0 * (TX0 * TX0)))) +
                                         ((-4.00000000000000000e+01 *
                                           (r0 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0)))))) +
                                          (1.20000000000000000e+01 *
                                           (Q0 * (TX0 *
                                                  (TX0 *
                                                   (TX0 * (TX0 * TX0)))))))))) *
                                      (VPFX_x2)[0]) +
                                     ((((((2.00000000000000000e+00 *
                                           (r0 * (r0 * (r0 * r0)))) +
                                          ((4.00000000000000000e+00 *
                                            ((r0 * r0) * (MIN_R0 * MIN_R0))) +
                                           (2.00000000000000000e+00 *
                                            (MIN_R0 *
                                             (MIN_R0 * (MIN_R0 * MIN_R0)))))) *
                                         Q0) +
                                        ((((-2.40000000000000000e+01 *
                                            (r0 * (r0 * r0))) +
                                           (-2.40000000000000000e+01 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          (Q0 * TX0)) +
                                         ((((7.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (2.40000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * (TX0 * TX0))) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * (TX0 * TX0))))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 *
                                             (TX0 * (TX0 * (TX0 * TX0))))))))) *
                                       ((VPFX_x2)[0] * (VPFX_x2)[0])) +
                                      ((((((-8.00000000000000000e+00 *
                                            (r0 * (r0 * r0))) +
                                           (-8.00000000000000000e+00 *
                                            (r0 * (MIN_R0 * MIN_R0)))) *
                                          Q0) +
                                         ((((4.80000000000000000e+01 *
                                             (r0 * r0)) +
                                            (1.60000000000000000e+01 *
                                             (MIN_R0 * MIN_R0))) *
                                           (Q0 * TX0)) +
                                          ((-8.00000000000000000e+01 *
                                            (r0 * (Q0 * (TX0 * TX0)))) +
                                           (4.00000000000000000e+01 *
                                            (Q0 * (TX0 * (TX0 * TX0))))))) *
                                        ((VPFX_x2)[0] *
                                         ((VPFX_x2)[0] * (VPFX_x2)[0]))) +
                                       ((((((1.20000000000000000e+01 *
                                             (r0 * r0)) +
                                            (4.00000000000000000e+00 *
                                             (MIN_R0 * MIN_R0))) *
                                           Q0) +
                                          ((-4.00000000000000000e+01 *
                                            (r0 * (Q0 * TX0))) +
                                           (3.00000000000000000e+01 *
                                            (Q0 * (TX0 * TX0))))) *
                                         ((VPFX_x2)[0] *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] * (VPFX_x2)[0])))) +
                                        ((((-8.00000000000000000e+00 *
                                            (r0 * Q0)) +
                                           (1.20000000000000000e+01 *
                                            (Q0 * TX0))) *
                                          ((VPFX_x2)[0] *
                                           ((VPFX_x2)[0] *
                                            ((VPFX_x2)[0] *
                                             ((VPFX_x2)[0] * (VPFX_x2)[0]))))) +
                                         ((2.00000000000000000e+00 *
                                           (Q0 * ((VPFX_x2)[0] *
                                                  ((VPFX_x2)[0] *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))))) +
                                          ((((((4.00000000000000000e+00 *
                                                (r0 * r0)) +
                                               (4.00000000000000000e+00 *
                                                (MIN_R0 * MIN_R0))) *
                                              (Q0 * (TX0 * TX0))) +
                                             ((-8.00000000000000000e+00 *
                                               (r0 *
                                                (Q0 * (TX0 * (TX0 * TX0))))) +
                                              ((4.00000000000000000e+00 *
                                                (Q0 *
                                                 (TX0 * (TX0 * (TX0 * TX0))))) +
                                               ((((((8.00000000000000000e+00 *
                                                     (r0 * r0)) +
                                                    (8.00000000000000000e+00 *
                                                     (MIN_R0 * MIN_R0))) *
                                                   (Q0 * TX0)) +
                                                  ((-2.40000000000000000e+01 *
                                                    (r0 * (Q0 * (TX0 * TX0)))) +
                                                   (1.60000000000000000e+01 *
                                                    (Q0 *
                                                     (TX0 * (TX0 * TX0)))))) *
                                                 (VPFX_x2)[0]) +
                                                ((((((4.00000000000000000e+00 *
                                                      (r0 * r0)) +
                                                     (4.00000000000000000e+00 *
                                                      (MIN_R0 * MIN_R0))) *
                                                    Q0) +
                                                   ((-2.40000000000000000e+01 *
                                                     (r0 * (Q0 * TX0))) +
                                                    (2.40000000000000000e+01 *
                                                     (Q0 * (TX0 * TX0))))) *
                                                  ((VPFX_x2)[0] *
                                                   (VPFX_x2)[0])) +
                                                 ((((-8.00000000000000000e+00 *
                                                     (r0 * Q0)) +
                                                    (1.60000000000000000e+01 *
                                                     (Q0 * TX0))) *
                                                   ((VPFX_x2)[0] *
                                                    ((VPFX_x2)[0] *
                                                     (VPFX_x2)[0]))) +
                                                  (4.00000000000000000e+00 *
                                                   (Q0 *
                                                    ((VPFX_x2)[0] *
                                                     ((VPFX_x2)[0] *
                                                      ((VPFX_x2)[0] *
                                                       (VPFX_x2)[0]))))))))))) *
                                            ((VPFX_z3)[0] * (VPFX_z3)[0])) +
                                           (((2.00000000000000000e+00 *
                                              (Q0 * (TX0 * TX0))) +
                                             ((4.00000000000000000e+00 *
                                               (Q0 * (TX0 * (VPFX_x2)[0]))) +
                                              (2.00000000000000000e+00 *
                                               (Q0 * ((VPFX_x2)[0] *
                                                      (VPFX_x2)[0]))))) *
                                            ((VPFX_z3)[0] *
                                             ((VPFX_z3)[0] *
                                              ((VPFX_z3)[0] *
                                               (VPFX_z3)[0])))))))))))))))));
                            }))))) +
                        0.00000000000000000e+00))))));
              __m256d VPFX_x3[1];
              double *x3 = VPFX_x3;

              ((VPFX_x3)[0] =
                   ((({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (({ (1.00000000000000000e+00 / (TX0 * TX0)); }) *
                      ((-1.00000000000000000e+00 *
                        ((DELTA_X * DELTA_X) * ((TX0 * TX0) * (VPFX_x1)[0]))) +
                       ((2.00000000000000000e+00 *
                         ((DELTA_X * DELTA_X) * ((TX0 * TX0) * (VPFX_x2)[0]))) +
                        (((((DELTA_Y * DELTA_Y) * TX0) +
                           ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0])) *
                          ((VPFX_y1)[0] * (VPFX_y1)[0])) +
                         ((((-2.00000000000000000e+00 *
                             ((DELTA_Y * DELTA_Y) * TX0)) +
                            (-2.00000000000000000e+00 *
                             ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                           ((VPFX_y1)[0] * (VPFX_y2)[0])) +
                          ((((2.00000000000000000e+00 *
                              ((DELTA_Y * DELTA_Y) * TX0)) +
                             (2.00000000000000000e+00 *
                              ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                            ((VPFX_y2)[0] * (VPFX_y2)[0])) +
                           ((((-2.00000000000000000e+00 *
                               ((DELTA_Y * DELTA_Y) * TX0)) +
                              (-2.00000000000000000e+00 *
                               ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                             ((VPFX_y2)[0] * (VPFX_y3)[0])) +
                            ((((DELTA_Y * DELTA_Y) * TX0) +
                              ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0])) *
                             ((VPFX_y3)[0] * (VPFX_y3)[0])))))))))) +
                    (({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (-1 * (Deltat * (QE_MASS * (VPFX_iBx)[0]))))));
              __m256d VPFX_newvx[1];
              double *newvx = VPFX_newvx;

              ((VPFX_newvx)[0] = (((VPFX_x3)[0] - (VPFX_x2)[0]) / DT));
              __m256d VPFX_newvy[1];
              double *newvy = VPFX_newvy;

              ((VPFX_newvy)[0] = (((VPFX_y3)[0] - (VPFX_y2)[0]) / DT));
              __m256d VPFX_newvz[1];
              double *newvz = VPFX_newvz;

              ((VPFX_newvz)[0] = (((VPFX_z3)[0] - (VPFX_z2)[0]) / DT));
              __m256d VPFX_newxx[1];
              double *newxx = VPFX_newxx;

              ((VPFX_newxx)[0] = ((VPFX_x3)[0] - XO));
              __m256d VPFX_newxy[1];
              double *newxy = VPFX_newxy;

              ((VPFX_newxy)[0] = ((VPFX_y3)[0] - YO));
              __m256d VPFX_newxz[1];
              double *newxz = VPFX_newxz;

              ((VPFX_newxz)[0] = (((VPFX_z3)[0] + zmid) - ZO));
              ((VPFX_local_particle_head)[((0 * 1) + 0)] = (VPFX_newxx)[0]);
              ((VPFX_local_particle_head)[((1 * 1) + 0)] = (VPFX_newxy)[0]);
              ((VPFX_local_particle_head)[((2 * 1) + 0)] = (VPFX_newxz)[0]);
              ((VPFX_local_particle_head)[((3 * 1) + 0)] = (VPFX_newvx)[0]);
              ((VPFX_local_particle_head)[((4 * 1) + 0)] = (VPFX_newvy)[0]);
              ((VPFX_local_particle_head)[((5 * 1) + 0)] = (VPFX_newvz)[0]);
            }
            {
              int stmpg1;

#pragma clang loop vectorize(disable)
              for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
                {
                  {
                    int inner_var_G0;

                    for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                         (inner_var_G0 = (inner_var_G0 + 1))) {
                      if (((g_inner + inner_var_G0) < load0)) {
                        ((particle_head_general)[(
                             stmpg1 + ((g_inner + inner_var_G0) * 6))] =
                             ((local_particle_head)[stmpg1])[inner_var_G0]);

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
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP5;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP5:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP6;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP6:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_Bfield_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[375];
  double shB0[375];
  double shB1[375];
  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long MYGEN634 = 0;

                  for (0; (MYGEN634 < (3 * 5));
                       (MYGEN634 = (MYGEN634 + __xlen))) {
                    int ridx = (MYGEN634 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN636 = 0;

                  for (0; (MYGEN636 < (3 * 5));
                       (MYGEN636 = (MYGEN636 + __xlen))) {
                    int ridx = (MYGEN636 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB0 + total_idx))[ridx] =
                           ((fieldB +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN638 = 0;

                  for (0; (MYGEN638 < (3 * 5));
                       (MYGEN638 = (MYGEN638 + __xlen))) {
                    int ridx = (MYGEN638 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB1 + total_idx))[ridx] =
                           ((fieldB1 +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

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
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 1))) {
          double local_particle_head[6];
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              ((local_particle_head)[stmpg1] = (particle_head_general)[(
                   stmpg1 +
                   ((((g_inner < load0)) ? (g_inner) : ((load0 - 1))) * 6))]);
            }
          }
          double xx1 = (local_particle_head)[0];

          double xy1 = (local_particle_head)[1];

          double xz1 = (local_particle_head)[2];

          double vx0 = (local_particle_head)[3];

          double vy0 = (local_particle_head)[4];

          double vz0 = (local_particle_head)[5];

          (xx1 = (xx1 + -5.00000000000000000e-01));
          (xy1 = (xy1 + -5.00000000000000000e-01));
          (xz1 = (xz1 + -5.00000000000000000e-01));
          double rx = (xx1 - Midx);

          double ry = (xy1 - Midy);

          double rz = (xz1 - Midz);

          double xx0 = (xx1 - (Deltat * vx0));

          double xy0 = (xy1 - (Deltat * vy0));

          double xz0 = (xz1 - (Deltat * vz0));

          double Midx0 = floor(xx0);

          double Midx1 = floor(xx1);

          double Midy0 = floor(xy0);

          double Midy1 = floor(xy1);

          double Midz0 = floor(xz0);

          double Midz1 = floor(xz1);

          double rx0 = (xx0 - Midx0);

          double rx1 = (xx1 - Midx1);

          double ry0 = (xy0 - Midy0);

          double ry1 = (xy1 - Midy1);

          double rz0 = (xz0 - Midz0);

          double rz1 = (xz1 - Midz1);

          double dixx0 = (Midx0 - Midx);

          double dixx1 = (Midx1 - Midx);

          double dixy0 = (Midy0 - Midy);

          double dixy1 = (Midy1 - Midy);

          double dixz0 = (Midz0 - Midz);

          double dixz1 = (Midz1 - Midz);

          double f0_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x0)[i] = 0);
            }
          }
          ((f0_x0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx0)),
                             2)));
          ((f0_x0)[0] = (((f0_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[1] * -(dixx0))));
          ((f0_x0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0)))))));
          ((f0_x0)[1] = (((f0_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[2] * -(dixx0))));
          ((f0_x0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2)))));
          ((f0_x0)[2] = (((f0_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[3] * -(dixx0))));
          ((f0_x0)[4] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((f0_x0)[3] = (((f0_x0)[3] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[4] * -(dixx0))));
          ((f0_x0)[4] = ((f0_x0)[4] * (dixx0 + 1.00000000000000000e+00)));
          double f1_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x0)[i] = 0);
            }
          }
          ((f1_x0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx0))));
          ((f1_x0)[0] = (((f1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[1] * -(dixx0))));
          ((f1_x0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx0)))));
          ((f1_x0)[1] = (((f1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[2] * -(dixx0))));
          ((f1_x0)[3] = (5.00000000000000000e-01 * rx0));
          ((f1_x0)[2] = (((f1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[3] * -(dixx0))));
          ((f1_x0)[3] = ((f1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double if1_x0[5];
          ((if1_x0)[0] = 1);
          ((if1_x0)[1] = 1);
          ((if1_x0)[3] = 0);
          ((if1_x0)[4] = 0);
          ((if1_x0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2))));
          ((if1_x0)[0] = (((if1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[1] * -(dixx0))));
          ((if1_x0)[2] =
               ((2.50000000000000000e-01 * pow(rx0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2))))));
          ((if1_x0)[1] = (((if1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[2] * -(dixx0))));
          ((if1_x0)[3] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((if1_x0)[2] = (((if1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[3] * -(dixx0))));
          ((if1_x0)[3] = ((if1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double f0_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y0)[i] = 0);
            }
          }
          ((f0_y0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry0)),
                             2)));
          ((f0_y0)[0] = (((f0_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[1] * -(dixy0))));
          ((f0_y0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0)))))));
          ((f0_y0)[1] = (((f0_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[2] * -(dixy0))));
          ((f0_y0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2)))));
          ((f0_y0)[2] = (((f0_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[3] * -(dixy0))));
          ((f0_y0)[4] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((f0_y0)[3] = (((f0_y0)[3] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[4] * -(dixy0))));
          ((f0_y0)[4] = ((f0_y0)[4] * (dixy0 + 1.00000000000000000e+00)));
          double f1_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y0)[i] = 0);
            }
          }
          ((f1_y0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry0))));
          ((f1_y0)[0] = (((f1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[1] * -(dixy0))));
          ((f1_y0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry0)))));
          ((f1_y0)[1] = (((f1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[2] * -(dixy0))));
          ((f1_y0)[3] = (5.00000000000000000e-01 * ry0));
          ((f1_y0)[2] = (((f1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[3] * -(dixy0))));
          ((f1_y0)[3] = ((f1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double if1_y0[5];
          ((if1_y0)[0] = 1);
          ((if1_y0)[1] = 1);
          ((if1_y0)[3] = 0);
          ((if1_y0)[4] = 0);
          ((if1_y0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2))));
          ((if1_y0)[0] = (((if1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[1] * -(dixy0))));
          ((if1_y0)[2] =
               ((2.50000000000000000e-01 * pow(ry0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2))))));
          ((if1_y0)[1] = (((if1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[2] * -(dixy0))));
          ((if1_y0)[3] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((if1_y0)[2] = (((if1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[3] * -(dixy0))));
          ((if1_y0)[3] = ((if1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double f0_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z0)[i] = 0);
            }
          }
          ((f0_z0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz0)),
                             2)));
          ((f0_z0)[0] = (((f0_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[1] * -(dixz0))));
          ((f0_z0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0)))))));
          ((f0_z0)[1] = (((f0_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[2] * -(dixz0))));
          ((f0_z0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2)))));
          ((f0_z0)[2] = (((f0_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[3] * -(dixz0))));
          ((f0_z0)[4] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((f0_z0)[3] = (((f0_z0)[3] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[4] * -(dixz0))));
          ((f0_z0)[4] = ((f0_z0)[4] * (dixz0 + 1.00000000000000000e+00)));
          double f1_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z0)[i] = 0);
            }
          }
          ((f1_z0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz0))));
          ((f1_z0)[0] = (((f1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[1] * -(dixz0))));
          ((f1_z0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz0)))));
          ((f1_z0)[1] = (((f1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[2] * -(dixz0))));
          ((f1_z0)[3] = (5.00000000000000000e-01 * rz0));
          ((f1_z0)[2] = (((f1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[3] * -(dixz0))));
          ((f1_z0)[3] = ((f1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double if1_z0[5];
          ((if1_z0)[0] = 1);
          ((if1_z0)[1] = 1);
          ((if1_z0)[3] = 0);
          ((if1_z0)[4] = 0);
          ((if1_z0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2))));
          ((if1_z0)[0] = (((if1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[1] * -(dixz0))));
          ((if1_z0)[2] =
               ((2.50000000000000000e-01 * pow(rz0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2))))));
          ((if1_z0)[1] = (((if1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[2] * -(dixz0))));
          ((if1_z0)[3] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((if1_z0)[2] = (((if1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[3] * -(dixz0))));
          ((if1_z0)[3] = ((if1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double f0_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x1)[i] = 0);
            }
          }
          ((f0_x1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx1)),
                             2)));
          ((f0_x1)[0] = (((f0_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[1] * -(dixx1))));
          ((f0_x1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1)))))));
          ((f0_x1)[1] = (((f0_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[2] * -(dixx1))));
          ((f0_x1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2)))));
          ((f0_x1)[2] = (((f0_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[3] * -(dixx1))));
          ((f0_x1)[4] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((f0_x1)[3] = (((f0_x1)[3] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[4] * -(dixx1))));
          ((f0_x1)[4] = ((f0_x1)[4] * (dixx1 + 1.00000000000000000e+00)));
          double f1_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x1)[i] = 0);
            }
          }
          ((f1_x1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx1))));
          ((f1_x1)[0] = (((f1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[1] * -(dixx1))));
          ((f1_x1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx1)))));
          ((f1_x1)[1] = (((f1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[2] * -(dixx1))));
          ((f1_x1)[3] = (5.00000000000000000e-01 * rx1));
          ((f1_x1)[2] = (((f1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[3] * -(dixx1))));
          ((f1_x1)[3] = ((f1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double if1_x1[5];
          ((if1_x1)[0] = 1);
          ((if1_x1)[1] = 1);
          ((if1_x1)[3] = 0);
          ((if1_x1)[4] = 0);
          ((if1_x1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2))));
          ((if1_x1)[0] = (((if1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[1] * -(dixx1))));
          ((if1_x1)[2] =
               ((2.50000000000000000e-01 * pow(rx1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2))))));
          ((if1_x1)[1] = (((if1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[2] * -(dixx1))));
          ((if1_x1)[3] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((if1_x1)[2] = (((if1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[3] * -(dixx1))));
          ((if1_x1)[3] = ((if1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double f0_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y1)[i] = 0);
            }
          }
          ((f0_y1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry1)),
                             2)));
          ((f0_y1)[0] = (((f0_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[1] * -(dixy1))));
          ((f0_y1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1)))))));
          ((f0_y1)[1] = (((f0_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[2] * -(dixy1))));
          ((f0_y1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2)))));
          ((f0_y1)[2] = (((f0_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[3] * -(dixy1))));
          ((f0_y1)[4] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((f0_y1)[3] = (((f0_y1)[3] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[4] * -(dixy1))));
          ((f0_y1)[4] = ((f0_y1)[4] * (dixy1 + 1.00000000000000000e+00)));
          double f1_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y1)[i] = 0);
            }
          }
          ((f1_y1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry1))));
          ((f1_y1)[0] = (((f1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[1] * -(dixy1))));
          ((f1_y1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry1)))));
          ((f1_y1)[1] = (((f1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[2] * -(dixy1))));
          ((f1_y1)[3] = (5.00000000000000000e-01 * ry1));
          ((f1_y1)[2] = (((f1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[3] * -(dixy1))));
          ((f1_y1)[3] = ((f1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double if1_y1[5];
          ((if1_y1)[0] = 1);
          ((if1_y1)[1] = 1);
          ((if1_y1)[3] = 0);
          ((if1_y1)[4] = 0);
          ((if1_y1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2))));
          ((if1_y1)[0] = (((if1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[1] * -(dixy1))));
          ((if1_y1)[2] =
               ((2.50000000000000000e-01 * pow(ry1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2))))));
          ((if1_y1)[1] = (((if1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[2] * -(dixy1))));
          ((if1_y1)[3] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((if1_y1)[2] = (((if1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[3] * -(dixy1))));
          ((if1_y1)[3] = ((if1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double f0_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z1)[i] = 0);
            }
          }
          ((f0_z1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz1)),
                             2)));
          ((f0_z1)[0] = (((f0_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[1] * -(dixz1))));
          ((f0_z1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1)))))));
          ((f0_z1)[1] = (((f0_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[2] * -(dixz1))));
          ((f0_z1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2)))));
          ((f0_z1)[2] = (((f0_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[3] * -(dixz1))));
          ((f0_z1)[4] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((f0_z1)[3] = (((f0_z1)[3] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[4] * -(dixz1))));
          ((f0_z1)[4] = ((f0_z1)[4] * (dixz1 + 1.00000000000000000e+00)));
          double f1_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z1)[i] = 0);
            }
          }
          ((f1_z1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz1))));
          ((f1_z1)[0] = (((f1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[1] * -(dixz1))));
          ((f1_z1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz1)))));
          ((f1_z1)[1] = (((f1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[2] * -(dixz1))));
          ((f1_z1)[3] = (5.00000000000000000e-01 * rz1));
          ((f1_z1)[2] = (((f1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[3] * -(dixz1))));
          ((f1_z1)[3] = ((f1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double if1_z1[5];
          ((if1_z1)[0] = 1);
          ((if1_z1)[1] = 1);
          ((if1_z1)[3] = 0);
          ((if1_z1)[4] = 0);
          ((if1_z1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2))));
          ((if1_z1)[0] = (((if1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[1] * -(dixz1))));
          ((if1_z1)[2] =
               ((2.50000000000000000e-01 * pow(rz1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2))))));
          ((if1_z1)[1] = (((if1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[2] * -(dixz1))));
          ((if1_z1)[3] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((if1_z1)[2] = (((if1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[3] * -(dixz1))));
          ((if1_z1)[3] = ((if1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double AllEx = 0;

          double AllEy = 0;

          double AllEz = 0;

          {
            long idz;

            for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
              {
                long idy;

                for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
                  {
                    long idx;

                    for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
                      (AllEx =
                           (AllEx +
                            (((shE0)[(0 +
                                      (3 * (idx + (5 * (idy + (idz * 5))))))] +
                              0) *
                             ((f1_x1)[idx] * ((f0_y1)[idy] * (f0_z1)[idz])))));
                      (AllEy =
                           (AllEy +
                            (((shE0)[(1 +
                                      (3 * (idz + (5 * (idx + (idy * 5))))))] +
                              0) *
                             ((f1_y1)[idx] * ((f0_z1)[idy] * (f0_x1)[idz])))));
                      (AllEz =
                           (AllEz +
                            (((shE0)[(2 +
                                      (3 * (idy + (5 * (idz + (idx * 5))))))] +
                              0) *
                             ((f1_z1)[idx] * ((f0_x1)[idy] * (f0_y1)[idz])))));
                    }
                  }
                }
              }
            }
          }
          double allincfvx;

          double allincfvy;

          double allincfvz;

          (allincfvx = (2.00000000000000000e+00 * (Deltat * AllEx)));
          (allincfvy = (2.00000000000000000e+00 * (Deltat * AllEy)));
          (allincfvz = (2.00000000000000000e+00 * (Deltat * AllEz)));
          double DT = Deltat;

          {
            double x0;

            (x0 = (xx0 + XO));
            double y0 = (xy0 + YO);

            double z0 = ((xz0 + ZO) - zmid);

            double x1 = (xx1 + XO);

            double y1 = (xy1 + YO);

            double z1 = ((xz1 + ZO) - zmid);

            double mzero = 0.00000000000000000e+00;

            double iBx =
                ((-1.00000000000000000e+00 *
                  (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                    0.00000000000000000e+00) *
                   pow(DT, -1.00000000000000000e+00))) +
                 mzero);

            double x2 =
                (((-1.00000000000000000e+00 * x0) +
                  (2.00000000000000000e+00 * x1)) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvx + (-1.00000000000000000e+00 * iBx))))));

            double rx2 = ((x2 - XO) - floor((x2 - XO)));

            double dixx2 = (floor((x2 - XO)) - Midx);

            double f0_x2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_x2)[i] = 0);
              }
            }
            ((f0_x2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx2)),
                               2)));
            ((f0_x2)[0] = (((f0_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[1] * -(dixx2))));
            ((f0_x2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx2)))))));
            ((f0_x2)[1] = (((f0_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[2] * -(dixx2))));
            ((f0_x2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rx2) + pow(rx2, 2)))));
            ((f0_x2)[2] = (((f0_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[3] * -(dixx2))));
            ((f0_x2)[4] = (2.50000000000000000e-01 * pow(rx2, 2)));
            ((f0_x2)[3] = (((f0_x2)[3] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[4] * -(dixx2))));
            ((f0_x2)[4] = ((f0_x2)[4] * (dixx2 + 1.00000000000000000e+00)));
            double f1_x2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_x2)[i] = 0);
              }
            }
            ((f1_x2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rx2))));
            ((f1_x2)[0] = (((f1_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[1] * -(dixx2))));
            ((f1_x2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx2)))));
            ((f1_x2)[1] = (((f1_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[2] * -(dixx2))));
            ((f1_x2)[3] = (5.00000000000000000e-01 * rx2));
            ((f1_x2)[2] = (((f1_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[3] * -(dixx2))));
            ((f1_x2)[3] = ((f1_x2)[3] * (dixx2 + 1.00000000000000000e+00)));
            double if1_x2[5];
            ((if1_x2)[0] = 1);
            ((if1_x2)[1] = 1);
            ((if1_x2)[3] = 0);
            ((if1_x2)[4] = 0);
            ((if1_x2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx2)),
                                 2))));
            ((if1_x2)[0] = (((if1_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[1] * -(dixx2))));
            ((if1_x2)[2] =
                 ((2.50000000000000000e-01 * pow(rx2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rx2) + pow(rx2, 2))))));
            ((if1_x2)[1] = (((if1_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[2] * -(dixx2))));
            ((if1_x2)[3] = (2.50000000000000000e-01 * pow(rx2, 2)));
            ((if1_x2)[2] = (((if1_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[3] * -(dixx2))));
            ((if1_x2)[3] = ((if1_x2)[3] * (dixx2 + 1.00000000000000000e+00)));
            double iBy =
                (pow(DT, -1.00000000000000000e+00) *
                 (0.00000000000000000e+00 +
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (((0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB0)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_x1)[xyzx] - (if1_x0)[xyzx]) *
                                             (f1_y1)[xyzy])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      })) +
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                             (f1_y1)[xyzy])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      }))) *
                    DT))));

            double y2 =
                ((pow((pow(TX0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))),
                      -1.00000000000000000e+00) *
                  ((((-1.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((-2.00000000000000000e+00 * (TX0 * x0)) +
                      (-1.00000000000000000e+00 *
                       pow(x0, 2.00000000000000000e+00)))) *
                    y0) +
                   (((2.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((2.00000000000000000e+00 * (TX0 * x0)) +
                      (pow(x0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))))) *
                    y1))) +
                 (pow(TX0, 2.00000000000000000e+00) *
                  ((QE_MASS *
                    (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
                   pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                         pow(TX0, 2.00000000000000000e+00)) +
                        ((2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) *
                           (TX0 * x2))) +
                         (pow(DELTA_Y, 2.00000000000000000e+00) *
                          pow(x2, 2.00000000000000000e+00)))),
                       -1.00000000000000000e+00))));

            double ry2 = ((y2 - YO) - floor((y2 - YO)));

            double dixy2 = (floor((y2 - YO)) - Midy);

            double f0_y2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_y2)[i] = 0);
              }
            }
            ((f0_y2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry2)),
                               2)));
            ((f0_y2)[0] = (((f0_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[1] * -(dixy2))));
            ((f0_y2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry2)))))));
            ((f0_y2)[1] = (((f0_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[2] * -(dixy2))));
            ((f0_y2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * ry2) + pow(ry2, 2)))));
            ((f0_y2)[2] = (((f0_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[3] * -(dixy2))));
            ((f0_y2)[4] = (2.50000000000000000e-01 * pow(ry2, 2)));
            ((f0_y2)[3] = (((f0_y2)[3] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[4] * -(dixy2))));
            ((f0_y2)[4] = ((f0_y2)[4] * (dixy2 + 1.00000000000000000e+00)));
            double f1_y2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_y2)[i] = 0);
              }
            }
            ((f1_y2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * ry2))));
            ((f1_y2)[0] = (((f1_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[1] * -(dixy2))));
            ((f1_y2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry2)))));
            ((f1_y2)[1] = (((f1_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[2] * -(dixy2))));
            ((f1_y2)[3] = (5.00000000000000000e-01 * ry2));
            ((f1_y2)[2] = (((f1_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[3] * -(dixy2))));
            ((f1_y2)[3] = ((f1_y2)[3] * (dixy2 + 1.00000000000000000e+00)));
            double if1_y2[5];
            ((if1_y2)[0] = 1);
            ((if1_y2)[1] = 1);
            ((if1_y2)[3] = 0);
            ((if1_y2)[4] = 0);
            ((if1_y2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry2)),
                                 2))));
            ((if1_y2)[0] = (((if1_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[1] * -(dixy2))));
            ((if1_y2)[2] =
                 ((2.50000000000000000e-01 * pow(ry2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * ry2) + pow(ry2, 2))))));
            ((if1_y2)[1] = (((if1_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[2] * -(dixy2))));
            ((if1_y2)[3] = (2.50000000000000000e-01 * pow(ry2, 2)));
            ((if1_y2)[2] = (((if1_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[3] * -(dixy2))));
            ((if1_y2)[3] = ((if1_y2)[3] * (dixy2 + 1.00000000000000000e+00)));
            double iBz =
                (-1.00000000000000000e+00 *
                 (pow(DT, -1.00000000000000000e+00) *
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (0.00000000000000000e+00 +
                    (((-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          double tmpBfd = 0.00000000000000000e+00;

                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx =
                                          (xyzx + (5 * (xyzy + (5 * xyzz))));

                                      (tmpBfd = (tmpBfd +
                                                 ((shB0)[((allidx * 3) + 0)] *
                                                  ((f0_x0)[xyzx] *
                                                   (((if1_y1)[xyzy] -
                                                     (if1_y0)[xyzy]) *
                                                    (f1_z1)[xyzz])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          tmpBfd;
                        }))) +
                      ((0.00000000000000000e+00 + ({
                          double tmpBfd = 0.00000000000000000e+00;

                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx =
                                          (xyzx + (5 * (xyzy + (5 * xyzz))));

                                      (tmpBfd = (tmpBfd +
                                                 ((shB0)[((allidx * 3) + 1)] *
                                                  ((f0_y1)[xyzy] *
                                                   (((if1_x1)[xyzx] -
                                                     (if1_x0)[xyzx]) *
                                                    (f1_z1)[xyzz])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          tmpBfd;
                        })) +
                       ((-1.00000000000000000e+00 *
                         (0.00000000000000000e+00 + ({
                            double tmpBfd = 0.00000000000000000e+00;

                            {
                              long xyzz;

                              for ((xyzz = 0); (xyzz < 5);
                                   (xyzz = (xyzz + 1))) {
                                {
                                  long xyzy;

                                  for ((xyzy = 0); (xyzy < 5);
                                       (xyzy = (xyzy + 1))) {
                                    {
                                      long xyzx;

                                      for ((xyzx = 0); (xyzx < 5);
                                           (xyzx = (xyzx + 1))) {
                                        int allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz))));

                                        (tmpBfd = (tmpBfd +
                                                   ((shB1)[((allidx * 3) + 0)] *
                                                    ((f0_x2)[xyzx] *
                                                     (((if1_y2)[xyzy] -
                                                       (if1_y1)[xyzy]) *
                                                      (f1_z1)[xyzz])))));
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            tmpBfd;
                          }))) +
                        (0.00000000000000000e+00 + ({
                           double tmpBfd = 0.00000000000000000e+00;

                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz))));

                                       (tmpBfd = (tmpBfd +
                                                  ((shB1)[((allidx * 3) + 1)] *
                                                   ((f0_y1)[xyzy] *
                                                    (((if1_x2)[xyzx] -
                                                      (if1_x1)[xyzx]) *
                                                     (f1_z1)[xyzz])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           tmpBfd;
                         }))))) *
                     DT)))));

            double z2 =
                (((-1.00000000000000000e+00 * z0) +
                  (2.00000000000000000e+00 * z1)) +
                 (pow(DELTA_Z, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

            double rz2 = ((z2 - (ZO - zmid)) - floor((z2 - (ZO - zmid))));

            double dixz2 = (floor((z2 - (ZO - zmid))) - Midz);

            double f0_z2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_z2)[i] = 0);
              }
            }
            ((f0_z2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz2)),
                               2)));
            ((f0_z2)[0] = (((f0_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[1] * -(dixz2))));
            ((f0_z2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz2)))))));
            ((f0_z2)[1] = (((f0_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[2] * -(dixz2))));
            ((f0_z2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rz2) + pow(rz2, 2)))));
            ((f0_z2)[2] = (((f0_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[3] * -(dixz2))));
            ((f0_z2)[4] = (2.50000000000000000e-01 * pow(rz2, 2)));
            ((f0_z2)[3] = (((f0_z2)[3] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[4] * -(dixz2))));
            ((f0_z2)[4] = ((f0_z2)[4] * (dixz2 + 1.00000000000000000e+00)));
            double f1_z2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_z2)[i] = 0);
              }
            }
            ((f1_z2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rz2))));
            ((f1_z2)[0] = (((f1_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[1] * -(dixz2))));
            ((f1_z2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz2)))));
            ((f1_z2)[1] = (((f1_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[2] * -(dixz2))));
            ((f1_z2)[3] = (5.00000000000000000e-01 * rz2));
            ((f1_z2)[2] = (((f1_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[3] * -(dixz2))));
            ((f1_z2)[3] = ((f1_z2)[3] * (dixz2 + 1.00000000000000000e+00)));
            double if1_z2[5];
            ((if1_z2)[0] = 1);
            ((if1_z2)[1] = 1);
            ((if1_z2)[3] = 0);
            ((if1_z2)[4] = 0);
            ((if1_z2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz2)),
                                 2))));
            ((if1_z2)[0] = (((if1_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[1] * -(dixz2))));
            ((if1_z2)[2] =
                 ((2.50000000000000000e-01 * pow(rz2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rz2) + pow(rz2, 2))))));
            ((if1_z2)[1] = (((if1_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[2] * -(dixz2))));
            ((if1_z2)[3] = (2.50000000000000000e-01 * pow(rz2, 2)));
            ((if1_z2)[2] = (((if1_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[3] * -(dixz2))));
            ((if1_z2)[3] = ((if1_z2)[3] * (dixz2 + 1.00000000000000000e+00)));
            (iBz = 0.00000000000000000e+00);
            double z3 = (((-1.00000000000000000e+00 * z1) +
                          (2.00000000000000000e+00 * z2)) +
                         (pow(DELTA_Z, -2.00000000000000000e+00) *
                          (-1 * (Deltat * (QE_MASS * iBz)))));

            double rz3 = ((z3 - (ZO - zmid)) - floor((z3 - (ZO - zmid))));

            double dixz3 = (floor((z3 - (ZO - zmid))) - Midz);

            double f0_z3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_z3)[i] = 0);
              }
            }
            ((f0_z3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz3)),
                               2)));
            ((f0_z3)[0] = (((f0_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[1] * -(dixz3))));
            ((f0_z3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz3)))))));
            ((f0_z3)[1] = (((f0_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[2] * -(dixz3))));
            ((f0_z3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rz3) + pow(rz3, 2)))));
            ((f0_z3)[2] = (((f0_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[3] * -(dixz3))));
            ((f0_z3)[4] = (2.50000000000000000e-01 * pow(rz3, 2)));
            ((f0_z3)[3] = (((f0_z3)[3] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[4] * -(dixz3))));
            ((f0_z3)[4] = ((f0_z3)[4] * (dixz3 + 1.00000000000000000e+00)));
            double f1_z3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_z3)[i] = 0);
              }
            }
            ((f1_z3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rz3))));
            ((f1_z3)[0] = (((f1_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[1] * -(dixz3))));
            ((f1_z3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz3)))));
            ((f1_z3)[1] = (((f1_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[2] * -(dixz3))));
            ((f1_z3)[3] = (5.00000000000000000e-01 * rz3));
            ((f1_z3)[2] = (((f1_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[3] * -(dixz3))));
            ((f1_z3)[3] = ((f1_z3)[3] * (dixz3 + 1.00000000000000000e+00)));
            double if1_z3[5];
            ((if1_z3)[0] = 1);
            ((if1_z3)[1] = 1);
            ((if1_z3)[3] = 0);
            ((if1_z3)[4] = 0);
            ((if1_z3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz3)),
                                 2))));
            ((if1_z3)[0] = (((if1_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[1] * -(dixz3))));
            ((if1_z3)[2] =
                 ((2.50000000000000000e-01 * pow(rz3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rz3) + pow(rz3, 2))))));
            ((if1_z3)[1] = (((if1_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[2] * -(dixz3))));
            ((if1_z3)[3] = (2.50000000000000000e-01 * pow(rz3, 2)));
            ((if1_z3)[2] = (((if1_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[3] * -(dixz3))));
            ((if1_z3)[3] = ((if1_z3)[3] * (dixz3 + 1.00000000000000000e+00)));
            (iBy =
                 ((-1.00000000000000000e+00 *
                   (0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 0)] *
                                         ((f0_x2)[xyzx] *
                                          (((if1_z2)[xyzz] - (if1_z1)[xyzz]) *
                                           (f1_y2)[xyzy])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    }))) +
                  (-1.00000000000000000e+00 *
                   (0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 0)] *
                                         ((f0_x2)[xyzx] *
                                          (((if1_z3)[xyzz] - (if1_z2)[xyzz]) *
                                           (f1_y2)[xyzy])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    })))));
            double y3 = (((-1.00000000000000000e+00 * y1) +
                          (2.00000000000000000e+00 * y2)) +
                         (pow(TX0, 2.00000000000000000e+00) *
                          ((-1 * (Deltat * (QE_MASS * iBy))) *
                           pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                                 pow(TX0, 2.00000000000000000e+00)) +
                                ((2.00000000000000000e+00 *
                                  (pow(DELTA_Y, 2.00000000000000000e+00) *
                                   (TX0 * x2))) +
                                 (pow(DELTA_Y, 2.00000000000000000e+00) *
                                  pow(x2, 2.00000000000000000e+00)))),
                               -1.00000000000000000e+00))));

            double ry3 = ((y3 - YO) - floor((y3 - YO)));

            double dixy3 = (floor((y3 - YO)) - Midy);

            double f0_y3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_y3)[i] = 0);
              }
            }
            ((f0_y3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry3)),
                               2)));
            ((f0_y3)[0] = (((f0_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[1] * -(dixy3))));
            ((f0_y3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry3)))))));
            ((f0_y3)[1] = (((f0_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[2] * -(dixy3))));
            ((f0_y3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * ry3) + pow(ry3, 2)))));
            ((f0_y3)[2] = (((f0_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[3] * -(dixy3))));
            ((f0_y3)[4] = (2.50000000000000000e-01 * pow(ry3, 2)));
            ((f0_y3)[3] = (((f0_y3)[3] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[4] * -(dixy3))));
            ((f0_y3)[4] = ((f0_y3)[4] * (dixy3 + 1.00000000000000000e+00)));
            double f1_y3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_y3)[i] = 0);
              }
            }
            ((f1_y3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * ry3))));
            ((f1_y3)[0] = (((f1_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[1] * -(dixy3))));
            ((f1_y3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry3)))));
            ((f1_y3)[1] = (((f1_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[2] * -(dixy3))));
            ((f1_y3)[3] = (5.00000000000000000e-01 * ry3));
            ((f1_y3)[2] = (((f1_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[3] * -(dixy3))));
            ((f1_y3)[3] = ((f1_y3)[3] * (dixy3 + 1.00000000000000000e+00)));
            double if1_y3[5];
            ((if1_y3)[0] = 1);
            ((if1_y3)[1] = 1);
            ((if1_y3)[3] = 0);
            ((if1_y3)[4] = 0);
            ((if1_y3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry3)),
                                 2))));
            ((if1_y3)[0] = (((if1_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[1] * -(dixy3))));
            ((if1_y3)[2] =
                 ((2.50000000000000000e-01 * pow(ry3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * ry3) + pow(ry3, 2))))));
            ((if1_y3)[1] = (((if1_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[2] * -(dixy3))));
            ((if1_y3)[3] = (2.50000000000000000e-01 * pow(ry3, 2)));
            ((if1_y3)[2] = (((if1_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[3] * -(dixy3))));
            ((if1_y3)[3] = ((if1_y3)[3] * (dixy3 + 1.00000000000000000e+00)));
            (iBx =
                 ((0.00000000000000000e+00 + ({
                     double tmpBfd = 0.00000000000000000e+00;

                     {
                       long xyzz;

                       for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                         {
                           long xyzy;

                           for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                             {
                               long xyzx;

                               for ((xyzx = 0); (xyzx < 5);
                                    (xyzx = (xyzx + 1))) {
                                 int allidx =
                                     (xyzx + (5 * (xyzy + (5 * xyzz))));

                                 (tmpBfd =
                                      (tmpBfd +
                                       ((shB1)[((allidx * 3) + 1)] *
                                        ((f0_y2)[xyzy] *
                                         (((if1_z2)[xyzz] - (if1_z1)[xyzz]) *
                                          (f1_x2)[xyzx])))));
                               }
                             }
                           }
                         }
                       }
                     }
                     tmpBfd;
                   })) +
                  ((0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 1)] *
                                         ((f0_y2)[xyzy] *
                                          (((if1_z3)[xyzz] - (if1_z2)[xyzz]) *
                                           (f1_x2)[xyzx])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    })) +
                   ((-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                             (f1_x2)[xyzx])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      }))) +
                    (-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z3)[xyzz] *
                                            (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                             (f1_x2)[xyzx])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      })))))));
            double x3 =
                ((pow(DELTA_X, -2.00000000000000000e+00) *
                  (pow(TX0, -2.00000000000000000e+00) *
                   ((-1.00000000000000000e+00 *
                     (pow(DELTA_X, 2.00000000000000000e+00) *
                      (pow(TX0, 2.00000000000000000e+00) * x1))) +
                    ((2.00000000000000000e+00 *
                      (pow(DELTA_X, 2.00000000000000000e+00) *
                       (pow(TX0, 2.00000000000000000e+00) * x2))) +
                     ((((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                        (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                       pow(y1, 2.00000000000000000e+00)) +
                      ((((-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                         (-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                        (y1 * y2)) +
                       ((((2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                          (2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                         pow(y2, 2.00000000000000000e+00)) +
                        ((((-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                           (-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                          (y2 * y3)) +
                         (((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                          pow(y3, 2.00000000000000000e+00)))))))))) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (-1 * (Deltat * (QE_MASS * iBx)))));

            double rx3 = ((x3 - XO) - floor((x3 - XO)));

            double dixx3 = (floor((x3 - XO)) - Midx);

            double f0_x3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_x3)[i] = 0);
              }
            }
            ((f0_x3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx3)),
                               2)));
            ((f0_x3)[0] = (((f0_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[1] * -(dixx3))));
            ((f0_x3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx3)))))));
            ((f0_x3)[1] = (((f0_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[2] * -(dixx3))));
            ((f0_x3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rx3) + pow(rx3, 2)))));
            ((f0_x3)[2] = (((f0_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[3] * -(dixx3))));
            ((f0_x3)[4] = (2.50000000000000000e-01 * pow(rx3, 2)));
            ((f0_x3)[3] = (((f0_x3)[3] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[4] * -(dixx3))));
            ((f0_x3)[4] = ((f0_x3)[4] * (dixx3 + 1.00000000000000000e+00)));
            double f1_x3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_x3)[i] = 0);
              }
            }
            ((f1_x3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rx3))));
            ((f1_x3)[0] = (((f1_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[1] * -(dixx3))));
            ((f1_x3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx3)))));
            ((f1_x3)[1] = (((f1_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[2] * -(dixx3))));
            ((f1_x3)[3] = (5.00000000000000000e-01 * rx3));
            ((f1_x3)[2] = (((f1_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[3] * -(dixx3))));
            ((f1_x3)[3] = ((f1_x3)[3] * (dixx3 + 1.00000000000000000e+00)));
            double if1_x3[5];
            ((if1_x3)[0] = 1);
            ((if1_x3)[1] = 1);
            ((if1_x3)[3] = 0);
            ((if1_x3)[4] = 0);
            ((if1_x3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx3)),
                                 2))));
            ((if1_x3)[0] = (((if1_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[1] * -(dixx3))));
            ((if1_x3)[2] =
                 ((2.50000000000000000e-01 * pow(rx3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rx3) + pow(rx3, 2))))));
            ((if1_x3)[1] = (((if1_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[2] * -(dixx3))));
            ((if1_x3)[3] = (2.50000000000000000e-01 * pow(rx3, 2)));
            ((if1_x3)[2] = (((if1_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[3] * -(dixx3))));
            ((if1_x3)[3] = ((if1_x3)[3] * (dixx3 + 1.00000000000000000e+00)));
            double newvx = ((x3 - x2) / DT);

            double newvy = ((y3 - y2) / DT);

            double newvz = ((z3 - z2) / DT);

            double newxx = (x3 - XO);

            double newxy = (y3 - YO);

            double newxz = ((z3 + zmid) - ZO);

            (newxx = (newxx + 5.00000000000000000e-01));
            (newxy = (newxy + 5.00000000000000000e-01));
            (newxz = (newxz + 5.00000000000000000e-01));
            ((local_particle_head)[0] = newxx);
            ((local_particle_head)[1] = newxy);
            ((local_particle_head)[2] = newxz);
            ((local_particle_head)[3] = newvx);
            ((local_particle_head)[4] = newvy);
            ((local_particle_head)[5] = newvz);
          }
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              if ((g_inner < load0)) {
                ((particle_head_general)[(stmpg1 + (g_inner * 6))] =
                     (local_particle_head)[stmpg1]);

              } else {
                0;
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP7;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP7:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP8;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP8:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_Bfield_pushJ_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[375];
  double shB0[375];
  double shB1[375];
  double shJ0[375];
  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long MYGEN640 = 0;

                  for (0; (MYGEN640 < (3 * 5));
                       (MYGEN640 = (MYGEN640 + __xlen))) {
                    int ridx = (MYGEN640 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN642 = 0;

                  for (0; (MYGEN642 < (3 * 5));
                       (MYGEN642 = (MYGEN642 + __xlen))) {
                    int ridx = (MYGEN642 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB0 + total_idx))[ridx] =
                           ((fieldB +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN644 = 0;

                  for (0; (MYGEN644 < (3 * 5));
                       (MYGEN644 = (MYGEN644 + __xlen))) {
                    int ridx = (MYGEN644 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB1 + total_idx))[ridx] =
                           ((fieldB1 +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN646 = 0;

                  for (0; (MYGEN646 < (3 * 5));
                       (MYGEN646 = (MYGEN646 + __xlen))) {
                    int ridx = (MYGEN646 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shJ0 + total_idx))[ridx] =
                           ((FoutJ +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

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
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 1))) {
          double local_particle_head[6];
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              ((local_particle_head)[stmpg1] = (particle_head_general)[(
                   stmpg1 +
                   ((((g_inner < load0)) ? (g_inner) : ((load0 - 1))) * 6))]);
            }
          }
          double xx1 = (local_particle_head)[0];

          double xy1 = (local_particle_head)[1];

          double xz1 = (local_particle_head)[2];

          double vx0 = (local_particle_head)[3];

          double vy0 = (local_particle_head)[4];

          double vz0 = (local_particle_head)[5];

          (xx1 = (xx1 + -5.00000000000000000e-01));
          (xy1 = (xy1 + -5.00000000000000000e-01));
          (xz1 = (xz1 + -5.00000000000000000e-01));
          double rx = (xx1 - Midx);

          double ry = (xy1 - Midy);

          double rz = (xz1 - Midz);

          double xx0 = (xx1 - (Deltat * vx0));

          double xy0 = (xy1 - (Deltat * vy0));

          double xz0 = (xz1 - (Deltat * vz0));

          double Midx0 = floor(xx0);

          double Midx1 = floor(xx1);

          double Midy0 = floor(xy0);

          double Midy1 = floor(xy1);

          double Midz0 = floor(xz0);

          double Midz1 = floor(xz1);

          double rx0 = (xx0 - Midx0);

          double rx1 = (xx1 - Midx1);

          double ry0 = (xy0 - Midy0);

          double ry1 = (xy1 - Midy1);

          double rz0 = (xz0 - Midz0);

          double rz1 = (xz1 - Midz1);

          double dixx0 = (Midx0 - Midx);

          double dixx1 = (Midx1 - Midx);

          double dixy0 = (Midy0 - Midy);

          double dixy1 = (Midy1 - Midy);

          double dixz0 = (Midz0 - Midz);

          double dixz1 = (Midz1 - Midz);

          double f0_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x0)[i] = 0);
            }
          }
          ((f0_x0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx0)),
                             2)));
          ((f0_x0)[0] = (((f0_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[1] * -(dixx0))));
          ((f0_x0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0)))))));
          ((f0_x0)[1] = (((f0_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[2] * -(dixx0))));
          ((f0_x0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2)))));
          ((f0_x0)[2] = (((f0_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[3] * -(dixx0))));
          ((f0_x0)[4] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((f0_x0)[3] = (((f0_x0)[3] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[4] * -(dixx0))));
          ((f0_x0)[4] = ((f0_x0)[4] * (dixx0 + 1.00000000000000000e+00)));
          double f1_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x0)[i] = 0);
            }
          }
          ((f1_x0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx0))));
          ((f1_x0)[0] = (((f1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[1] * -(dixx0))));
          ((f1_x0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx0)))));
          ((f1_x0)[1] = (((f1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[2] * -(dixx0))));
          ((f1_x0)[3] = (5.00000000000000000e-01 * rx0));
          ((f1_x0)[2] = (((f1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[3] * -(dixx0))));
          ((f1_x0)[3] = ((f1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double if1_x0[5];
          ((if1_x0)[0] = 1);
          ((if1_x0)[1] = 1);
          ((if1_x0)[3] = 0);
          ((if1_x0)[4] = 0);
          ((if1_x0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2))));
          ((if1_x0)[0] = (((if1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[1] * -(dixx0))));
          ((if1_x0)[2] =
               ((2.50000000000000000e-01 * pow(rx0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2))))));
          ((if1_x0)[1] = (((if1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[2] * -(dixx0))));
          ((if1_x0)[3] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((if1_x0)[2] = (((if1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[3] * -(dixx0))));
          ((if1_x0)[3] = ((if1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double f0_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y0)[i] = 0);
            }
          }
          ((f0_y0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry0)),
                             2)));
          ((f0_y0)[0] = (((f0_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[1] * -(dixy0))));
          ((f0_y0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0)))))));
          ((f0_y0)[1] = (((f0_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[2] * -(dixy0))));
          ((f0_y0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2)))));
          ((f0_y0)[2] = (((f0_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[3] * -(dixy0))));
          ((f0_y0)[4] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((f0_y0)[3] = (((f0_y0)[3] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[4] * -(dixy0))));
          ((f0_y0)[4] = ((f0_y0)[4] * (dixy0 + 1.00000000000000000e+00)));
          double f1_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y0)[i] = 0);
            }
          }
          ((f1_y0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry0))));
          ((f1_y0)[0] = (((f1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[1] * -(dixy0))));
          ((f1_y0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry0)))));
          ((f1_y0)[1] = (((f1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[2] * -(dixy0))));
          ((f1_y0)[3] = (5.00000000000000000e-01 * ry0));
          ((f1_y0)[2] = (((f1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[3] * -(dixy0))));
          ((f1_y0)[3] = ((f1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double if1_y0[5];
          ((if1_y0)[0] = 1);
          ((if1_y0)[1] = 1);
          ((if1_y0)[3] = 0);
          ((if1_y0)[4] = 0);
          ((if1_y0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2))));
          ((if1_y0)[0] = (((if1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[1] * -(dixy0))));
          ((if1_y0)[2] =
               ((2.50000000000000000e-01 * pow(ry0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2))))));
          ((if1_y0)[1] = (((if1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[2] * -(dixy0))));
          ((if1_y0)[3] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((if1_y0)[2] = (((if1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[3] * -(dixy0))));
          ((if1_y0)[3] = ((if1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double f0_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z0)[i] = 0);
            }
          }
          ((f0_z0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz0)),
                             2)));
          ((f0_z0)[0] = (((f0_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[1] * -(dixz0))));
          ((f0_z0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0)))))));
          ((f0_z0)[1] = (((f0_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[2] * -(dixz0))));
          ((f0_z0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2)))));
          ((f0_z0)[2] = (((f0_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[3] * -(dixz0))));
          ((f0_z0)[4] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((f0_z0)[3] = (((f0_z0)[3] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[4] * -(dixz0))));
          ((f0_z0)[4] = ((f0_z0)[4] * (dixz0 + 1.00000000000000000e+00)));
          double f1_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z0)[i] = 0);
            }
          }
          ((f1_z0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz0))));
          ((f1_z0)[0] = (((f1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[1] * -(dixz0))));
          ((f1_z0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz0)))));
          ((f1_z0)[1] = (((f1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[2] * -(dixz0))));
          ((f1_z0)[3] = (5.00000000000000000e-01 * rz0));
          ((f1_z0)[2] = (((f1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[3] * -(dixz0))));
          ((f1_z0)[3] = ((f1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double if1_z0[5];
          ((if1_z0)[0] = 1);
          ((if1_z0)[1] = 1);
          ((if1_z0)[3] = 0);
          ((if1_z0)[4] = 0);
          ((if1_z0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2))));
          ((if1_z0)[0] = (((if1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[1] * -(dixz0))));
          ((if1_z0)[2] =
               ((2.50000000000000000e-01 * pow(rz0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2))))));
          ((if1_z0)[1] = (((if1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[2] * -(dixz0))));
          ((if1_z0)[3] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((if1_z0)[2] = (((if1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[3] * -(dixz0))));
          ((if1_z0)[3] = ((if1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double f0_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x1)[i] = 0);
            }
          }
          ((f0_x1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx1)),
                             2)));
          ((f0_x1)[0] = (((f0_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[1] * -(dixx1))));
          ((f0_x1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1)))))));
          ((f0_x1)[1] = (((f0_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[2] * -(dixx1))));
          ((f0_x1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2)))));
          ((f0_x1)[2] = (((f0_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[3] * -(dixx1))));
          ((f0_x1)[4] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((f0_x1)[3] = (((f0_x1)[3] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[4] * -(dixx1))));
          ((f0_x1)[4] = ((f0_x1)[4] * (dixx1 + 1.00000000000000000e+00)));
          double f1_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x1)[i] = 0);
            }
          }
          ((f1_x1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx1))));
          ((f1_x1)[0] = (((f1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[1] * -(dixx1))));
          ((f1_x1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx1)))));
          ((f1_x1)[1] = (((f1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[2] * -(dixx1))));
          ((f1_x1)[3] = (5.00000000000000000e-01 * rx1));
          ((f1_x1)[2] = (((f1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[3] * -(dixx1))));
          ((f1_x1)[3] = ((f1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double if1_x1[5];
          ((if1_x1)[0] = 1);
          ((if1_x1)[1] = 1);
          ((if1_x1)[3] = 0);
          ((if1_x1)[4] = 0);
          ((if1_x1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2))));
          ((if1_x1)[0] = (((if1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[1] * -(dixx1))));
          ((if1_x1)[2] =
               ((2.50000000000000000e-01 * pow(rx1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2))))));
          ((if1_x1)[1] = (((if1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[2] * -(dixx1))));
          ((if1_x1)[3] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((if1_x1)[2] = (((if1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[3] * -(dixx1))));
          ((if1_x1)[3] = ((if1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double f0_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y1)[i] = 0);
            }
          }
          ((f0_y1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry1)),
                             2)));
          ((f0_y1)[0] = (((f0_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[1] * -(dixy1))));
          ((f0_y1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1)))))));
          ((f0_y1)[1] = (((f0_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[2] * -(dixy1))));
          ((f0_y1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2)))));
          ((f0_y1)[2] = (((f0_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[3] * -(dixy1))));
          ((f0_y1)[4] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((f0_y1)[3] = (((f0_y1)[3] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[4] * -(dixy1))));
          ((f0_y1)[4] = ((f0_y1)[4] * (dixy1 + 1.00000000000000000e+00)));
          double f1_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y1)[i] = 0);
            }
          }
          ((f1_y1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry1))));
          ((f1_y1)[0] = (((f1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[1] * -(dixy1))));
          ((f1_y1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry1)))));
          ((f1_y1)[1] = (((f1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[2] * -(dixy1))));
          ((f1_y1)[3] = (5.00000000000000000e-01 * ry1));
          ((f1_y1)[2] = (((f1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[3] * -(dixy1))));
          ((f1_y1)[3] = ((f1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double if1_y1[5];
          ((if1_y1)[0] = 1);
          ((if1_y1)[1] = 1);
          ((if1_y1)[3] = 0);
          ((if1_y1)[4] = 0);
          ((if1_y1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2))));
          ((if1_y1)[0] = (((if1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[1] * -(dixy1))));
          ((if1_y1)[2] =
               ((2.50000000000000000e-01 * pow(ry1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2))))));
          ((if1_y1)[1] = (((if1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[2] * -(dixy1))));
          ((if1_y1)[3] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((if1_y1)[2] = (((if1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[3] * -(dixy1))));
          ((if1_y1)[3] = ((if1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double f0_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z1)[i] = 0);
            }
          }
          ((f0_z1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz1)),
                             2)));
          ((f0_z1)[0] = (((f0_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[1] * -(dixz1))));
          ((f0_z1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1)))))));
          ((f0_z1)[1] = (((f0_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[2] * -(dixz1))));
          ((f0_z1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2)))));
          ((f0_z1)[2] = (((f0_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[3] * -(dixz1))));
          ((f0_z1)[4] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((f0_z1)[3] = (((f0_z1)[3] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[4] * -(dixz1))));
          ((f0_z1)[4] = ((f0_z1)[4] * (dixz1 + 1.00000000000000000e+00)));
          double f1_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z1)[i] = 0);
            }
          }
          ((f1_z1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz1))));
          ((f1_z1)[0] = (((f1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[1] * -(dixz1))));
          ((f1_z1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz1)))));
          ((f1_z1)[1] = (((f1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[2] * -(dixz1))));
          ((f1_z1)[3] = (5.00000000000000000e-01 * rz1));
          ((f1_z1)[2] = (((f1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[3] * -(dixz1))));
          ((f1_z1)[3] = ((f1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double if1_z1[5];
          ((if1_z1)[0] = 1);
          ((if1_z1)[1] = 1);
          ((if1_z1)[3] = 0);
          ((if1_z1)[4] = 0);
          ((if1_z1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2))));
          ((if1_z1)[0] = (((if1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[1] * -(dixz1))));
          ((if1_z1)[2] =
               ((2.50000000000000000e-01 * pow(rz1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2))))));
          ((if1_z1)[1] = (((if1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[2] * -(dixz1))));
          ((if1_z1)[3] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((if1_z1)[2] = (((if1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[3] * -(dixz1))));
          ((if1_z1)[3] = ((if1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double AllEx = 0;

          double AllEy = 0;

          double AllEz = 0;

          {
            long idz;

            for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
              {
                long idy;

                for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
                  {
                    long idx;

                    for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
                      (AllEx =
                           (AllEx +
                            (((shE0)[(0 +
                                      (3 * (idx + (5 * (idy + (idz * 5))))))] +
                              0) *
                             ((f1_x1)[idx] * ((f0_y1)[idy] * (f0_z1)[idz])))));
                      (AllEy =
                           (AllEy +
                            (((shE0)[(1 +
                                      (3 * (idz + (5 * (idx + (idy * 5))))))] +
                              0) *
                             ((f1_y1)[idx] * ((f0_z1)[idy] * (f0_x1)[idz])))));
                      (AllEz =
                           (AllEz +
                            (((shE0)[(2 +
                                      (3 * (idy + (5 * (idz + (idx * 5))))))] +
                              0) *
                             ((f1_z1)[idx] * ((f0_x1)[idy] * (f0_y1)[idz])))));
                    }
                  }
                }
              }
            }
          }
          double allincfvx;

          double allincfvy;

          double allincfvz;

          (allincfvx = (2.00000000000000000e+00 * (Deltat * AllEx)));
          (allincfvy = (2.00000000000000000e+00 * (Deltat * AllEy)));
          (allincfvz = (2.00000000000000000e+00 * (Deltat * AllEz)));
          double DT = Deltat;

          {
            double x0;

            (x0 = (xx0 + XO));
            double y0 = (xy0 + YO);

            double z0 = ((xz0 + ZO) - zmid);

            double x1 = (xx1 + XO);

            double y1 = (xy1 + YO);

            double z1 = ((xz1 + ZO) - zmid);

            double mzero = 0.00000000000000000e+00;

            double iBx =
                ((-1.00000000000000000e+00 *
                  (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                    0.00000000000000000e+00) *
                   pow(DT, -1.00000000000000000e+00))) +
                 mzero);

            double x2 =
                (((-1.00000000000000000e+00 * x0) +
                  (2.00000000000000000e+00 * x1)) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvx + (-1.00000000000000000e+00 * iBx))))));

            double rx2 = ((x2 - XO) - floor((x2 - XO)));

            double dixx2 = (floor((x2 - XO)) - Midx);

            double f0_x2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_x2)[i] = 0);
              }
            }
            ((f0_x2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx2)),
                               2)));
            ((f0_x2)[0] = (((f0_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[1] * -(dixx2))));
            ((f0_x2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx2)))))));
            ((f0_x2)[1] = (((f0_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[2] * -(dixx2))));
            ((f0_x2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rx2) + pow(rx2, 2)))));
            ((f0_x2)[2] = (((f0_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[3] * -(dixx2))));
            ((f0_x2)[4] = (2.50000000000000000e-01 * pow(rx2, 2)));
            ((f0_x2)[3] = (((f0_x2)[3] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[4] * -(dixx2))));
            ((f0_x2)[4] = ((f0_x2)[4] * (dixx2 + 1.00000000000000000e+00)));
            double f1_x2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_x2)[i] = 0);
              }
            }
            ((f1_x2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rx2))));
            ((f1_x2)[0] = (((f1_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[1] * -(dixx2))));
            ((f1_x2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx2)))));
            ((f1_x2)[1] = (((f1_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[2] * -(dixx2))));
            ((f1_x2)[3] = (5.00000000000000000e-01 * rx2));
            ((f1_x2)[2] = (((f1_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[3] * -(dixx2))));
            ((f1_x2)[3] = ((f1_x2)[3] * (dixx2 + 1.00000000000000000e+00)));
            double if1_x2[5];
            ((if1_x2)[0] = 1);
            ((if1_x2)[1] = 1);
            ((if1_x2)[3] = 0);
            ((if1_x2)[4] = 0);
            ((if1_x2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx2)),
                                 2))));
            ((if1_x2)[0] = (((if1_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[1] * -(dixx2))));
            ((if1_x2)[2] =
                 ((2.50000000000000000e-01 * pow(rx2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rx2) + pow(rx2, 2))))));
            ((if1_x2)[1] = (((if1_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[2] * -(dixx2))));
            ((if1_x2)[3] = (2.50000000000000000e-01 * pow(rx2, 2)));
            ((if1_x2)[2] = (((if1_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[3] * -(dixx2))));
            ((if1_x2)[3] = ((if1_x2)[3] * (dixx2 + 1.00000000000000000e+00)));
            double iBy =
                (pow(DT, -1.00000000000000000e+00) *
                 (0.00000000000000000e+00 +
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (((0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB0)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_x1)[xyzx] - (if1_x0)[xyzx]) *
                                             (f1_y1)[xyzy])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      })) +
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                             (f1_y1)[xyzy])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      }))) *
                    DT))));

            double y2 =
                ((pow((pow(TX0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))),
                      -1.00000000000000000e+00) *
                  ((((-1.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((-2.00000000000000000e+00 * (TX0 * x0)) +
                      (-1.00000000000000000e+00 *
                       pow(x0, 2.00000000000000000e+00)))) *
                    y0) +
                   (((2.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((2.00000000000000000e+00 * (TX0 * x0)) +
                      (pow(x0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))))) *
                    y1))) +
                 (pow(TX0, 2.00000000000000000e+00) *
                  ((QE_MASS *
                    (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
                   pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                         pow(TX0, 2.00000000000000000e+00)) +
                        ((2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) *
                           (TX0 * x2))) +
                         (pow(DELTA_Y, 2.00000000000000000e+00) *
                          pow(x2, 2.00000000000000000e+00)))),
                       -1.00000000000000000e+00))));

            double ry2 = ((y2 - YO) - floor((y2 - YO)));

            double dixy2 = (floor((y2 - YO)) - Midy);

            double f0_y2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_y2)[i] = 0);
              }
            }
            ((f0_y2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry2)),
                               2)));
            ((f0_y2)[0] = (((f0_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[1] * -(dixy2))));
            ((f0_y2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry2)))))));
            ((f0_y2)[1] = (((f0_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[2] * -(dixy2))));
            ((f0_y2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * ry2) + pow(ry2, 2)))));
            ((f0_y2)[2] = (((f0_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[3] * -(dixy2))));
            ((f0_y2)[4] = (2.50000000000000000e-01 * pow(ry2, 2)));
            ((f0_y2)[3] = (((f0_y2)[3] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[4] * -(dixy2))));
            ((f0_y2)[4] = ((f0_y2)[4] * (dixy2 + 1.00000000000000000e+00)));
            double f1_y2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_y2)[i] = 0);
              }
            }
            ((f1_y2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * ry2))));
            ((f1_y2)[0] = (((f1_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[1] * -(dixy2))));
            ((f1_y2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry2)))));
            ((f1_y2)[1] = (((f1_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[2] * -(dixy2))));
            ((f1_y2)[3] = (5.00000000000000000e-01 * ry2));
            ((f1_y2)[2] = (((f1_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[3] * -(dixy2))));
            ((f1_y2)[3] = ((f1_y2)[3] * (dixy2 + 1.00000000000000000e+00)));
            double if1_y2[5];
            ((if1_y2)[0] = 1);
            ((if1_y2)[1] = 1);
            ((if1_y2)[3] = 0);
            ((if1_y2)[4] = 0);
            ((if1_y2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry2)),
                                 2))));
            ((if1_y2)[0] = (((if1_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[1] * -(dixy2))));
            ((if1_y2)[2] =
                 ((2.50000000000000000e-01 * pow(ry2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * ry2) + pow(ry2, 2))))));
            ((if1_y2)[1] = (((if1_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[2] * -(dixy2))));
            ((if1_y2)[3] = (2.50000000000000000e-01 * pow(ry2, 2)));
            ((if1_y2)[2] = (((if1_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[3] * -(dixy2))));
            ((if1_y2)[3] = ((if1_y2)[3] * (dixy2 + 1.00000000000000000e+00)));
            double iBz =
                (-1.00000000000000000e+00 *
                 (pow(DT, -1.00000000000000000e+00) *
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (0.00000000000000000e+00 +
                    (((-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          double tmpBfd = 0.00000000000000000e+00;

                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx =
                                          (xyzx + (5 * (xyzy + (5 * xyzz))));

                                      (tmpBfd = (tmpBfd +
                                                 ((shB0)[((allidx * 3) + 0)] *
                                                  ((f0_x0)[xyzx] *
                                                   (((if1_y1)[xyzy] -
                                                     (if1_y0)[xyzy]) *
                                                    (f1_z1)[xyzz])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          tmpBfd;
                        }))) +
                      ((0.00000000000000000e+00 + ({
                          double tmpBfd = 0.00000000000000000e+00;

                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx =
                                          (xyzx + (5 * (xyzy + (5 * xyzz))));

                                      (tmpBfd = (tmpBfd +
                                                 ((shB0)[((allidx * 3) + 1)] *
                                                  ((f0_y1)[xyzy] *
                                                   (((if1_x1)[xyzx] -
                                                     (if1_x0)[xyzx]) *
                                                    (f1_z1)[xyzz])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          tmpBfd;
                        })) +
                       ((-1.00000000000000000e+00 *
                         (0.00000000000000000e+00 + ({
                            double tmpBfd = 0.00000000000000000e+00;

                            {
                              long xyzz;

                              for ((xyzz = 0); (xyzz < 5);
                                   (xyzz = (xyzz + 1))) {
                                {
                                  long xyzy;

                                  for ((xyzy = 0); (xyzy < 5);
                                       (xyzy = (xyzy + 1))) {
                                    {
                                      long xyzx;

                                      for ((xyzx = 0); (xyzx < 5);
                                           (xyzx = (xyzx + 1))) {
                                        int allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz))));

                                        (tmpBfd = (tmpBfd +
                                                   ((shB1)[((allidx * 3) + 0)] *
                                                    ((f0_x2)[xyzx] *
                                                     (((if1_y2)[xyzy] -
                                                       (if1_y1)[xyzy]) *
                                                      (f1_z1)[xyzz])))));
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            tmpBfd;
                          }))) +
                        (0.00000000000000000e+00 + ({
                           double tmpBfd = 0.00000000000000000e+00;

                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz))));

                                       (tmpBfd = (tmpBfd +
                                                  ((shB1)[((allidx * 3) + 1)] *
                                                   ((f0_y1)[xyzy] *
                                                    (((if1_x2)[xyzx] -
                                                      (if1_x1)[xyzx]) *
                                                     (f1_z1)[xyzz])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           tmpBfd;
                         }))))) *
                     DT)))));

            double z2 =
                (((-1.00000000000000000e+00 * z0) +
                  (2.00000000000000000e+00 * z1)) +
                 (pow(DELTA_Z, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

            double rz2 = ((z2 - (ZO - zmid)) - floor((z2 - (ZO - zmid))));

            double dixz2 = (floor((z2 - (ZO - zmid))) - Midz);

            double f0_z2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_z2)[i] = 0);
              }
            }
            ((f0_z2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz2)),
                               2)));
            ((f0_z2)[0] = (((f0_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[1] * -(dixz2))));
            ((f0_z2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz2)))))));
            ((f0_z2)[1] = (((f0_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[2] * -(dixz2))));
            ((f0_z2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rz2) + pow(rz2, 2)))));
            ((f0_z2)[2] = (((f0_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[3] * -(dixz2))));
            ((f0_z2)[4] = (2.50000000000000000e-01 * pow(rz2, 2)));
            ((f0_z2)[3] = (((f0_z2)[3] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[4] * -(dixz2))));
            ((f0_z2)[4] = ((f0_z2)[4] * (dixz2 + 1.00000000000000000e+00)));
            double f1_z2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_z2)[i] = 0);
              }
            }
            ((f1_z2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rz2))));
            ((f1_z2)[0] = (((f1_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[1] * -(dixz2))));
            ((f1_z2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz2)))));
            ((f1_z2)[1] = (((f1_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[2] * -(dixz2))));
            ((f1_z2)[3] = (5.00000000000000000e-01 * rz2));
            ((f1_z2)[2] = (((f1_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[3] * -(dixz2))));
            ((f1_z2)[3] = ((f1_z2)[3] * (dixz2 + 1.00000000000000000e+00)));
            double if1_z2[5];
            ((if1_z2)[0] = 1);
            ((if1_z2)[1] = 1);
            ((if1_z2)[3] = 0);
            ((if1_z2)[4] = 0);
            ((if1_z2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz2)),
                                 2))));
            ((if1_z2)[0] = (((if1_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[1] * -(dixz2))));
            ((if1_z2)[2] =
                 ((2.50000000000000000e-01 * pow(rz2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rz2) + pow(rz2, 2))))));
            ((if1_z2)[1] = (((if1_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[2] * -(dixz2))));
            ((if1_z2)[3] = (2.50000000000000000e-01 * pow(rz2, 2)));
            ((if1_z2)[2] = (((if1_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[3] * -(dixz2))));
            ((if1_z2)[3] = ((if1_z2)[3] * (dixz2 + 1.00000000000000000e+00)));
            (iBz = 0.00000000000000000e+00);
            double z3 = (((-1.00000000000000000e+00 * z1) +
                          (2.00000000000000000e+00 * z2)) +
                         (pow(DELTA_Z, -2.00000000000000000e+00) *
                          (-1 * (Deltat * (QE_MASS * iBz)))));

            double rz3 = ((z3 - (ZO - zmid)) - floor((z3 - (ZO - zmid))));

            double dixz3 = (floor((z3 - (ZO - zmid))) - Midz);

            double f0_z3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_z3)[i] = 0);
              }
            }
            ((f0_z3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz3)),
                               2)));
            ((f0_z3)[0] = (((f0_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[1] * -(dixz3))));
            ((f0_z3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz3)))))));
            ((f0_z3)[1] = (((f0_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[2] * -(dixz3))));
            ((f0_z3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rz3) + pow(rz3, 2)))));
            ((f0_z3)[2] = (((f0_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[3] * -(dixz3))));
            ((f0_z3)[4] = (2.50000000000000000e-01 * pow(rz3, 2)));
            ((f0_z3)[3] = (((f0_z3)[3] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[4] * -(dixz3))));
            ((f0_z3)[4] = ((f0_z3)[4] * (dixz3 + 1.00000000000000000e+00)));
            double f1_z3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_z3)[i] = 0);
              }
            }
            ((f1_z3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rz3))));
            ((f1_z3)[0] = (((f1_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[1] * -(dixz3))));
            ((f1_z3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz3)))));
            ((f1_z3)[1] = (((f1_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[2] * -(dixz3))));
            ((f1_z3)[3] = (5.00000000000000000e-01 * rz3));
            ((f1_z3)[2] = (((f1_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[3] * -(dixz3))));
            ((f1_z3)[3] = ((f1_z3)[3] * (dixz3 + 1.00000000000000000e+00)));
            double if1_z3[5];
            ((if1_z3)[0] = 1);
            ((if1_z3)[1] = 1);
            ((if1_z3)[3] = 0);
            ((if1_z3)[4] = 0);
            ((if1_z3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz3)),
                                 2))));
            ((if1_z3)[0] = (((if1_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[1] * -(dixz3))));
            ((if1_z3)[2] =
                 ((2.50000000000000000e-01 * pow(rz3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rz3) + pow(rz3, 2))))));
            ((if1_z3)[1] = (((if1_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[2] * -(dixz3))));
            ((if1_z3)[3] = (2.50000000000000000e-01 * pow(rz3, 2)));
            ((if1_z3)[2] = (((if1_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[3] * -(dixz3))));
            ((if1_z3)[3] = ((if1_z3)[3] * (dixz3 + 1.00000000000000000e+00)));
            (iBy =
                 ((-1.00000000000000000e+00 *
                   (0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 0)] *
                                         ((f0_x2)[xyzx] *
                                          (((if1_z2)[xyzz] - (if1_z1)[xyzz]) *
                                           (f1_y2)[xyzy])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    }))) +
                  (-1.00000000000000000e+00 *
                   (0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 0)] *
                                         ((f0_x2)[xyzx] *
                                          (((if1_z3)[xyzz] - (if1_z2)[xyzz]) *
                                           (f1_y2)[xyzy])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    })))));
            double y3 = (((-1.00000000000000000e+00 * y1) +
                          (2.00000000000000000e+00 * y2)) +
                         (pow(TX0, 2.00000000000000000e+00) *
                          ((-1 * (Deltat * (QE_MASS * iBy))) *
                           pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                                 pow(TX0, 2.00000000000000000e+00)) +
                                ((2.00000000000000000e+00 *
                                  (pow(DELTA_Y, 2.00000000000000000e+00) *
                                   (TX0 * x2))) +
                                 (pow(DELTA_Y, 2.00000000000000000e+00) *
                                  pow(x2, 2.00000000000000000e+00)))),
                               -1.00000000000000000e+00))));

            double ry3 = ((y3 - YO) - floor((y3 - YO)));

            double dixy3 = (floor((y3 - YO)) - Midy);

            double f0_y3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_y3)[i] = 0);
              }
            }
            ((f0_y3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry3)),
                               2)));
            ((f0_y3)[0] = (((f0_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[1] * -(dixy3))));
            ((f0_y3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry3)))))));
            ((f0_y3)[1] = (((f0_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[2] * -(dixy3))));
            ((f0_y3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * ry3) + pow(ry3, 2)))));
            ((f0_y3)[2] = (((f0_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[3] * -(dixy3))));
            ((f0_y3)[4] = (2.50000000000000000e-01 * pow(ry3, 2)));
            ((f0_y3)[3] = (((f0_y3)[3] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[4] * -(dixy3))));
            ((f0_y3)[4] = ((f0_y3)[4] * (dixy3 + 1.00000000000000000e+00)));
            double f1_y3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_y3)[i] = 0);
              }
            }
            ((f1_y3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * ry3))));
            ((f1_y3)[0] = (((f1_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[1] * -(dixy3))));
            ((f1_y3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry3)))));
            ((f1_y3)[1] = (((f1_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[2] * -(dixy3))));
            ((f1_y3)[3] = (5.00000000000000000e-01 * ry3));
            ((f1_y3)[2] = (((f1_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[3] * -(dixy3))));
            ((f1_y3)[3] = ((f1_y3)[3] * (dixy3 + 1.00000000000000000e+00)));
            double if1_y3[5];
            ((if1_y3)[0] = 1);
            ((if1_y3)[1] = 1);
            ((if1_y3)[3] = 0);
            ((if1_y3)[4] = 0);
            ((if1_y3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry3)),
                                 2))));
            ((if1_y3)[0] = (((if1_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[1] * -(dixy3))));
            ((if1_y3)[2] =
                 ((2.50000000000000000e-01 * pow(ry3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * ry3) + pow(ry3, 2))))));
            ((if1_y3)[1] = (((if1_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[2] * -(dixy3))));
            ((if1_y3)[3] = (2.50000000000000000e-01 * pow(ry3, 2)));
            ((if1_y3)[2] = (((if1_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[3] * -(dixy3))));
            ((if1_y3)[3] = ((if1_y3)[3] * (dixy3 + 1.00000000000000000e+00)));
            (iBx =
                 ((0.00000000000000000e+00 + ({
                     double tmpBfd = 0.00000000000000000e+00;

                     {
                       long xyzz;

                       for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                         {
                           long xyzy;

                           for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                             {
                               long xyzx;

                               for ((xyzx = 0); (xyzx < 5);
                                    (xyzx = (xyzx + 1))) {
                                 int allidx =
                                     (xyzx + (5 * (xyzy + (5 * xyzz))));

                                 (tmpBfd =
                                      (tmpBfd +
                                       ((shB1)[((allidx * 3) + 1)] *
                                        ((f0_y2)[xyzy] *
                                         (((if1_z2)[xyzz] - (if1_z1)[xyzz]) *
                                          (f1_x2)[xyzx])))));
                               }
                             }
                           }
                         }
                       }
                     }
                     tmpBfd;
                   })) +
                  ((0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 1)] *
                                         ((f0_y2)[xyzy] *
                                          (((if1_z3)[xyzz] - (if1_z2)[xyzz]) *
                                           (f1_x2)[xyzx])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    })) +
                   ((-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                             (f1_x2)[xyzx])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      }))) +
                    (-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z3)[xyzz] *
                                            (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                             (f1_x2)[xyzx])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      })))))));
            double x3 =
                ((pow(DELTA_X, -2.00000000000000000e+00) *
                  (pow(TX0, -2.00000000000000000e+00) *
                   ((-1.00000000000000000e+00 *
                     (pow(DELTA_X, 2.00000000000000000e+00) *
                      (pow(TX0, 2.00000000000000000e+00) * x1))) +
                    ((2.00000000000000000e+00 *
                      (pow(DELTA_X, 2.00000000000000000e+00) *
                       (pow(TX0, 2.00000000000000000e+00) * x2))) +
                     ((((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                        (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                       pow(y1, 2.00000000000000000e+00)) +
                      ((((-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                         (-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                        (y1 * y2)) +
                       ((((2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                          (2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                         pow(y2, 2.00000000000000000e+00)) +
                        ((((-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                           (-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                          (y2 * y3)) +
                         (((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                          pow(y3, 2.00000000000000000e+00)))))))))) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (-1 * (Deltat * (QE_MASS * iBx)))));

            double rx3 = ((x3 - XO) - floor((x3 - XO)));

            double dixx3 = (floor((x3 - XO)) - Midx);

            double f0_x3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_x3)[i] = 0);
              }
            }
            ((f0_x3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx3)),
                               2)));
            ((f0_x3)[0] = (((f0_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[1] * -(dixx3))));
            ((f0_x3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx3)))))));
            ((f0_x3)[1] = (((f0_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[2] * -(dixx3))));
            ((f0_x3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rx3) + pow(rx3, 2)))));
            ((f0_x3)[2] = (((f0_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[3] * -(dixx3))));
            ((f0_x3)[4] = (2.50000000000000000e-01 * pow(rx3, 2)));
            ((f0_x3)[3] = (((f0_x3)[3] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[4] * -(dixx3))));
            ((f0_x3)[4] = ((f0_x3)[4] * (dixx3 + 1.00000000000000000e+00)));
            double f1_x3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_x3)[i] = 0);
              }
            }
            ((f1_x3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rx3))));
            ((f1_x3)[0] = (((f1_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[1] * -(dixx3))));
            ((f1_x3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx3)))));
            ((f1_x3)[1] = (((f1_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[2] * -(dixx3))));
            ((f1_x3)[3] = (5.00000000000000000e-01 * rx3));
            ((f1_x3)[2] = (((f1_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[3] * -(dixx3))));
            ((f1_x3)[3] = ((f1_x3)[3] * (dixx3 + 1.00000000000000000e+00)));
            double if1_x3[5];
            ((if1_x3)[0] = 1);
            ((if1_x3)[1] = 1);
            ((if1_x3)[3] = 0);
            ((if1_x3)[4] = 0);
            ((if1_x3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx3)),
                                 2))));
            ((if1_x3)[0] = (((if1_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[1] * -(dixx3))));
            ((if1_x3)[2] =
                 ((2.50000000000000000e-01 * pow(rx3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rx3) + pow(rx3, 2))))));
            ((if1_x3)[1] = (((if1_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[2] * -(dixx3))));
            ((if1_x3)[3] = (2.50000000000000000e-01 * pow(rx3, 2)));
            ((if1_x3)[2] = (((if1_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[3] * -(dixx3))));
            ((if1_x3)[3] = ((if1_x3)[3] * (dixx3 + 1.00000000000000000e+00)));
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                           ((f0_y1)[xyzy] * (f0_z1)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 0)] =
                             ((shJ0)[((allidx * 3) + 0)] +
                              ((grid_geo_x *
                                ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                           ((f0_x2)[xyzx] * (f0_z1)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 1)] =
                             ((shJ0)[((allidx * 3) + 1)] +
                              ((grid_geo_y *
                                (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_z3)[xyzz] - (if1_z1)[xyzz]) *
                                           ((f0_x2)[xyzx] * (f0_y2)[xyzy]))));
                        ((shJ0)[((allidx * 3) + 2)] =
                             ((shJ0)[((allidx * 3) + 2)] +
                              ((grid_geo_z *
                                ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                           ((f0_x2)[xyzx] * (f0_z3)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 1)] =
                             ((shJ0)[((allidx * 3) + 1)] +
                              ((grid_geo_y *
                                (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_x3)[xyzx] - (if1_x2)[xyzx]) *
                                           ((f0_y3)[xyzy] * (f0_z3)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 0)] =
                             ((shJ0)[((allidx * 3) + 0)] +
                              ((grid_geo_x *
                                ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            double newvx = ((x3 - x2) / DT);

            double newvy = ((y3 - y2) / DT);

            double newvz = ((z3 - z2) / DT);

            double newxx = (x3 - XO);

            double newxy = (y3 - YO);

            double newxz = ((z3 + zmid) - ZO);

            (newxx = (newxx + 5.00000000000000000e-01));
            (newxy = (newxy + 5.00000000000000000e-01));
            (newxz = (newxz + 5.00000000000000000e-01));
            ((local_particle_head)[0] = newxx);
            ((local_particle_head)[1] = newxy);
            ((local_particle_head)[2] = newxz);
            ((local_particle_head)[3] = newvx);
            ((local_particle_head)[4] = newvy);
            ((local_particle_head)[5] = newvz);
          }
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              if ((g_inner < load0)) {
                ((particle_head_general)[(stmpg1 + (g_inner * 6))] =
                     (local_particle_head)[stmpg1]);

              } else {
                0;
              }
            }
          }
        }
      }
    }
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long Gll_P9918;

                  for ((Gll_P9918 = 0); (Gll_P9918 < (3 * 5));
                       (Gll_P9918 = (Gll_P9918 + 1))) {
                    (((FoutJ + ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                     ((YLEN + (2 * ovlp)) *
                                                      (ZLEN + (2 * ovlp)))))) +
                                (0 + (num_ele * ((bBidx + ovlp) +
                                                 ((XLEN + (2 * ovlp)) *
                                                  (((xyzy + bBidy) + ovlp) +
                                                   ((YLEN + (2 * ovlp)) *
                                                    ((xyzz + bBidz) +
                                                     ovlp))))))))))[Gll_P9918] =
                         ((shJ0 + total_idx))[Gll_P9918]);
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP9;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP9:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP10;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP10:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_Bfield_pushJ_nopush_par_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[375];
  double shB0[375];
  double shB1[375];
  double shJ0[375];
  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long MYGEN649 = 0;

                  for (0; (MYGEN649 < (3 * 5));
                       (MYGEN649 = (MYGEN649 + __xlen))) {
                    int ridx = (MYGEN649 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN651 = 0;

                  for (0; (MYGEN651 < (3 * 5));
                       (MYGEN651 = (MYGEN651 + __xlen))) {
                    int ridx = (MYGEN651 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB0 + total_idx))[ridx] =
                           ((fieldB +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN653 = 0;

                  for (0; (MYGEN653 < (3 * 5));
                       (MYGEN653 = (MYGEN653 + __xlen))) {
                    int ridx = (MYGEN653 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB1 + total_idx))[ridx] =
                           ((fieldB1 +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN655 = 0;

                  for (0; (MYGEN655 < (3 * 5));
                       (MYGEN655 = (MYGEN655 + __xlen))) {
                    int ridx = (MYGEN655 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shJ0 + total_idx))[ridx] =
                           ((FoutJ +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

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
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 1))) {
          double local_particle_head[6];
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              ((local_particle_head)[stmpg1] = (particle_head_general)[(
                   stmpg1 +
                   ((((g_inner < load0)) ? (g_inner) : ((load0 - 1))) * 6))]);
            }
          }
          double xx1 = (local_particle_head)[0];

          double xy1 = (local_particle_head)[1];

          double xz1 = (local_particle_head)[2];

          double vx0 = (local_particle_head)[3];

          double vy0 = (local_particle_head)[4];

          double vz0 = (local_particle_head)[5];

          (xx1 = (xx1 + -5.00000000000000000e-01));
          (xy1 = (xy1 + -5.00000000000000000e-01));
          (xz1 = (xz1 + -5.00000000000000000e-01));
          double rx = (xx1 - Midx);

          double ry = (xy1 - Midy);

          double rz = (xz1 - Midz);

          double xx0 = (xx1 - (Deltat * vx0));

          double xy0 = (xy1 - (Deltat * vy0));

          double xz0 = (xz1 - (Deltat * vz0));

          double Midx0 = floor(xx0);

          double Midx1 = floor(xx1);

          double Midy0 = floor(xy0);

          double Midy1 = floor(xy1);

          double Midz0 = floor(xz0);

          double Midz1 = floor(xz1);

          double rx0 = (xx0 - Midx0);

          double rx1 = (xx1 - Midx1);

          double ry0 = (xy0 - Midy0);

          double ry1 = (xy1 - Midy1);

          double rz0 = (xz0 - Midz0);

          double rz1 = (xz1 - Midz1);

          double dixx0 = (Midx0 - Midx);

          double dixx1 = (Midx1 - Midx);

          double dixy0 = (Midy0 - Midy);

          double dixy1 = (Midy1 - Midy);

          double dixz0 = (Midz0 - Midz);

          double dixz1 = (Midz1 - Midz);

          double f0_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x0)[i] = 0);
            }
          }
          ((f0_x0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx0)),
                             2)));
          ((f0_x0)[0] = (((f0_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[1] * -(dixx0))));
          ((f0_x0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0)))))));
          ((f0_x0)[1] = (((f0_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[2] * -(dixx0))));
          ((f0_x0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2)))));
          ((f0_x0)[2] = (((f0_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[3] * -(dixx0))));
          ((f0_x0)[4] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((f0_x0)[3] = (((f0_x0)[3] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f0_x0)[4] * -(dixx0))));
          ((f0_x0)[4] = ((f0_x0)[4] * (dixx0 + 1.00000000000000000e+00)));
          double f1_x0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x0)[i] = 0);
            }
          }
          ((f1_x0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx0))));
          ((f1_x0)[0] = (((f1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[1] * -(dixx0))));
          ((f1_x0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx0)))));
          ((f1_x0)[1] = (((f1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[2] * -(dixx0))));
          ((f1_x0)[3] = (5.00000000000000000e-01 * rx0));
          ((f1_x0)[2] = (((f1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                         ((f1_x0)[3] * -(dixx0))));
          ((f1_x0)[3] = ((f1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double if1_x0[5];
          ((if1_x0)[0] = 1);
          ((if1_x0)[1] = 1);
          ((if1_x0)[3] = 0);
          ((if1_x0)[4] = 0);
          ((if1_x0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx0)),
                               2))));
          ((if1_x0)[0] = (((if1_x0)[0] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[1] * -(dixx0))));
          ((if1_x0)[2] =
               ((2.50000000000000000e-01 * pow(rx0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx0) + pow(rx0, 2))))));
          ((if1_x0)[1] = (((if1_x0)[1] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[2] * -(dixx0))));
          ((if1_x0)[3] = (2.50000000000000000e-01 * pow(rx0, 2)));
          ((if1_x0)[2] = (((if1_x0)[2] * (dixx0 + 1.00000000000000000e+00)) +
                          ((if1_x0)[3] * -(dixx0))));
          ((if1_x0)[3] = ((if1_x0)[3] * (dixx0 + 1.00000000000000000e+00)));
          double f0_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y0)[i] = 0);
            }
          }
          ((f0_y0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry0)),
                             2)));
          ((f0_y0)[0] = (((f0_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[1] * -(dixy0))));
          ((f0_y0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0)))))));
          ((f0_y0)[1] = (((f0_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[2] * -(dixy0))));
          ((f0_y0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2)))));
          ((f0_y0)[2] = (((f0_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[3] * -(dixy0))));
          ((f0_y0)[4] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((f0_y0)[3] = (((f0_y0)[3] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f0_y0)[4] * -(dixy0))));
          ((f0_y0)[4] = ((f0_y0)[4] * (dixy0 + 1.00000000000000000e+00)));
          double f1_y0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y0)[i] = 0);
            }
          }
          ((f1_y0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry0))));
          ((f1_y0)[0] = (((f1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[1] * -(dixy0))));
          ((f1_y0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry0)))));
          ((f1_y0)[1] = (((f1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[2] * -(dixy0))));
          ((f1_y0)[3] = (5.00000000000000000e-01 * ry0));
          ((f1_y0)[2] = (((f1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                         ((f1_y0)[3] * -(dixy0))));
          ((f1_y0)[3] = ((f1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double if1_y0[5];
          ((if1_y0)[0] = 1);
          ((if1_y0)[1] = 1);
          ((if1_y0)[3] = 0);
          ((if1_y0)[4] = 0);
          ((if1_y0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry0)),
                               2))));
          ((if1_y0)[0] = (((if1_y0)[0] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[1] * -(dixy0))));
          ((if1_y0)[2] =
               ((2.50000000000000000e-01 * pow(ry0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry0) + pow(ry0, 2))))));
          ((if1_y0)[1] = (((if1_y0)[1] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[2] * -(dixy0))));
          ((if1_y0)[3] = (2.50000000000000000e-01 * pow(ry0, 2)));
          ((if1_y0)[2] = (((if1_y0)[2] * (dixy0 + 1.00000000000000000e+00)) +
                          ((if1_y0)[3] * -(dixy0))));
          ((if1_y0)[3] = ((if1_y0)[3] * (dixy0 + 1.00000000000000000e+00)));
          double f0_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z0)[i] = 0);
            }
          }
          ((f0_z0)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz0)),
                             2)));
          ((f0_z0)[0] = (((f0_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[1] * -(dixz0))));
          ((f0_z0)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0)))))));
          ((f0_z0)[1] = (((f0_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[2] * -(dixz0))));
          ((f0_z0)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2)))));
          ((f0_z0)[2] = (((f0_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[3] * -(dixz0))));
          ((f0_z0)[4] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((f0_z0)[3] = (((f0_z0)[3] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f0_z0)[4] * -(dixz0))));
          ((f0_z0)[4] = ((f0_z0)[4] * (dixz0 + 1.00000000000000000e+00)));
          double f1_z0[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z0)[i] = 0);
            }
          }
          ((f1_z0)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz0))));
          ((f1_z0)[0] = (((f1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[1] * -(dixz0))));
          ((f1_z0)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz0))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz0)))));
          ((f1_z0)[1] = (((f1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[2] * -(dixz0))));
          ((f1_z0)[3] = (5.00000000000000000e-01 * rz0));
          ((f1_z0)[2] = (((f1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                         ((f1_z0)[3] * -(dixz0))));
          ((f1_z0)[3] = ((f1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double if1_z0[5];
          ((if1_z0)[0] = 1);
          ((if1_z0)[1] = 1);
          ((if1_z0)[3] = 0);
          ((if1_z0)[4] = 0);
          ((if1_z0)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz0)),
                               2))));
          ((if1_z0)[0] = (((if1_z0)[0] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[1] * -(dixz0))));
          ((if1_z0)[2] =
               ((2.50000000000000000e-01 * pow(rz0, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz0) + pow(rz0, 2))))));
          ((if1_z0)[1] = (((if1_z0)[1] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[2] * -(dixz0))));
          ((if1_z0)[3] = (2.50000000000000000e-01 * pow(rz0, 2)));
          ((if1_z0)[2] = (((if1_z0)[2] * (dixz0 + 1.00000000000000000e+00)) +
                          ((if1_z0)[3] * -(dixz0))));
          ((if1_z0)[3] = ((if1_z0)[3] * (dixz0 + 1.00000000000000000e+00)));
          double f0_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_x1)[i] = 0);
            }
          }
          ((f0_x1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rx1)),
                             2)));
          ((f0_x1)[0] = (((f0_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[1] * -(dixx1))));
          ((f0_x1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1)))))));
          ((f0_x1)[1] = (((f0_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[2] * -(dixx1))));
          ((f0_x1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2)))));
          ((f0_x1)[2] = (((f0_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[3] * -(dixx1))));
          ((f0_x1)[4] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((f0_x1)[3] = (((f0_x1)[3] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f0_x1)[4] * -(dixx1))));
          ((f0_x1)[4] = ((f0_x1)[4] * (dixx1 + 1.00000000000000000e+00)));
          double f1_x1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_x1)[i] = 0);
            }
          }
          ((f1_x1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rx1))));
          ((f1_x1)[0] = (((f1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[1] * -(dixx1))));
          ((f1_x1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rx1)))));
          ((f1_x1)[1] = (((f1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[2] * -(dixx1))));
          ((f1_x1)[3] = (5.00000000000000000e-01 * rx1));
          ((f1_x1)[2] = (((f1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                         ((f1_x1)[3] * -(dixx1))));
          ((f1_x1)[3] = ((f1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double if1_x1[5];
          ((if1_x1)[0] = 1);
          ((if1_x1)[1] = 1);
          ((if1_x1)[3] = 0);
          ((if1_x1)[4] = 0);
          ((if1_x1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx1)),
                               2))));
          ((if1_x1)[0] = (((if1_x1)[0] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[1] * -(dixx1))));
          ((if1_x1)[2] =
               ((2.50000000000000000e-01 * pow(rx1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rx1) + pow(rx1, 2))))));
          ((if1_x1)[1] = (((if1_x1)[1] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[2] * -(dixx1))));
          ((if1_x1)[3] = (2.50000000000000000e-01 * pow(rx1, 2)));
          ((if1_x1)[2] = (((if1_x1)[2] * (dixx1 + 1.00000000000000000e+00)) +
                          ((if1_x1)[3] * -(dixx1))));
          ((if1_x1)[3] = ((if1_x1)[3] * (dixx1 + 1.00000000000000000e+00)));
          double f0_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_y1)[i] = 0);
            }
          }
          ((f0_y1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * ry1)),
                             2)));
          ((f0_y1)[0] = (((f0_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[1] * -(dixy1))));
          ((f0_y1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1)))))));
          ((f0_y1)[1] = (((f0_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[2] * -(dixy1))));
          ((f0_y1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2)))));
          ((f0_y1)[2] = (((f0_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[3] * -(dixy1))));
          ((f0_y1)[4] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((f0_y1)[3] = (((f0_y1)[3] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f0_y1)[4] * -(dixy1))));
          ((f0_y1)[4] = ((f0_y1)[4] * (dixy1 + 1.00000000000000000e+00)));
          double f1_y1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_y1)[i] = 0);
            }
          }
          ((f1_y1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * ry1))));
          ((f1_y1)[0] = (((f1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[1] * -(dixy1))));
          ((f1_y1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * ry1)))));
          ((f1_y1)[1] = (((f1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[2] * -(dixy1))));
          ((f1_y1)[3] = (5.00000000000000000e-01 * ry1));
          ((f1_y1)[2] = (((f1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                         ((f1_y1)[3] * -(dixy1))));
          ((f1_y1)[3] = ((f1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double if1_y1[5];
          ((if1_y1)[0] = 1);
          ((if1_y1)[1] = 1);
          ((if1_y1)[3] = 0);
          ((if1_y1)[4] = 0);
          ((if1_y1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry1)),
                               2))));
          ((if1_y1)[0] = (((if1_y1)[0] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[1] * -(dixy1))));
          ((if1_y1)[2] =
               ((2.50000000000000000e-01 * pow(ry1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * ry1) + pow(ry1, 2))))));
          ((if1_y1)[1] = (((if1_y1)[1] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[2] * -(dixy1))));
          ((if1_y1)[3] = (2.50000000000000000e-01 * pow(ry1, 2)));
          ((if1_y1)[2] = (((if1_y1)[2] * (dixy1 + 1.00000000000000000e+00)) +
                          ((if1_y1)[3] * -(dixy1))));
          ((if1_y1)[3] = ((if1_y1)[3] * (dixy1 + 1.00000000000000000e+00)));
          double f0_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f0_z1)[i] = 0);
            }
          }
          ((f0_z1)[1] = (2.50000000000000000e-01 *
                         pow((1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * rz1)),
                             2)));
          ((f0_z1)[0] = (((f0_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[1] * -(dixz1))));
          ((f0_z1)[2] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          (pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2) +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1)))))));
          ((f0_z1)[1] = (((f0_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[2] * -(dixz1))));
          ((f0_z1)[3] = (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2)))));
          ((f0_z1)[2] = (((f0_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[3] * -(dixz1))));
          ((f0_z1)[4] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((f0_z1)[3] = (((f0_z1)[3] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f0_z1)[4] * -(dixz1))));
          ((f0_z1)[4] = ((f0_z1)[4] * (dixz1 + 1.00000000000000000e+00)));
          double f1_z1[5];
          {
            long i;

            for ((i = 0); (i < 5); (i = (i + 1))) {
              ((f1_z1)[i] = 0);
            }
          }
          ((f1_z1)[1] =
               (5.00000000000000000e-01 *
                (1.00000000000000000e+00 + (-1.00000000000000000e+00 * rz1))));
          ((f1_z1)[0] = (((f1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[1] * -(dixz1))));
          ((f1_z1)[2] = ((2.50000000000000000e-01 *
                          (2.00000000000000000e+00 +
                           (-2.00000000000000000e+00 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz1))))) +
                         (5.00000000000000000e-01 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * rz1)))));
          ((f1_z1)[1] = (((f1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[2] * -(dixz1))));
          ((f1_z1)[3] = (5.00000000000000000e-01 * rz1));
          ((f1_z1)[2] = (((f1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                         ((f1_z1)[3] * -(dixz1))));
          ((f1_z1)[3] = ((f1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double if1_z1[5];
          ((if1_z1)[0] = 1);
          ((if1_z1)[1] = 1);
          ((if1_z1)[3] = 0);
          ((if1_z1)[4] = 0);
          ((if1_z1)[1] = (1.00000000000000000e+00 +
                          (-2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz1)),
                               2))));
          ((if1_z1)[0] = (((if1_z1)[0] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[1] * -(dixz1))));
          ((if1_z1)[2] =
               ((2.50000000000000000e-01 * pow(rz1, 2)) +
                (-2.50000000000000000e-01 *
                 (-1.00000000000000000e+00 +
                  ((-2.00000000000000000e+00 * rz1) + pow(rz1, 2))))));
          ((if1_z1)[1] = (((if1_z1)[1] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[2] * -(dixz1))));
          ((if1_z1)[3] = (2.50000000000000000e-01 * pow(rz1, 2)));
          ((if1_z1)[2] = (((if1_z1)[2] * (dixz1 + 1.00000000000000000e+00)) +
                          ((if1_z1)[3] * -(dixz1))));
          ((if1_z1)[3] = ((if1_z1)[3] * (dixz1 + 1.00000000000000000e+00)));
          double AllEx = 0;

          double AllEy = 0;

          double AllEz = 0;

          {
            long idz;

            for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
              {
                long idy;

                for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
                  {
                    long idx;

                    for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
                      (AllEx =
                           (AllEx +
                            (((shE0)[(0 +
                                      (3 * (idx + (5 * (idy + (idz * 5))))))] +
                              0) *
                             ((f1_x1)[idx] * ((f0_y1)[idy] * (f0_z1)[idz])))));
                      (AllEy =
                           (AllEy +
                            (((shE0)[(1 +
                                      (3 * (idz + (5 * (idx + (idy * 5))))))] +
                              0) *
                             ((f1_y1)[idx] * ((f0_z1)[idy] * (f0_x1)[idz])))));
                      (AllEz =
                           (AllEz +
                            (((shE0)[(2 +
                                      (3 * (idy + (5 * (idz + (idx * 5))))))] +
                              0) *
                             ((f1_z1)[idx] * ((f0_x1)[idy] * (f0_y1)[idz])))));
                    }
                  }
                }
              }
            }
          }
          double allincfvx;

          double allincfvy;

          double allincfvz;

          (allincfvx = (2.00000000000000000e+00 * (Deltat * AllEx)));
          (allincfvy = (2.00000000000000000e+00 * (Deltat * AllEy)));
          (allincfvz = (2.00000000000000000e+00 * (Deltat * AllEz)));
          double DT = Deltat;

          {
            double x0;

            (x0 = (xx0 + XO));
            double y0 = (xy0 + YO);

            double z0 = ((xz0 + ZO) - zmid);

            double x1 = (xx1 + XO);

            double y1 = (xy1 + YO);

            double z1 = ((xz1 + ZO) - zmid);

            double mzero = 0.00000000000000000e+00;

            double iBx =
                ((-1.00000000000000000e+00 *
                  (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                    0.00000000000000000e+00) *
                   pow(DT, -1.00000000000000000e+00))) +
                 mzero);

            double x2 =
                (((-1.00000000000000000e+00 * x0) +
                  (2.00000000000000000e+00 * x1)) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvx + (-1.00000000000000000e+00 * iBx))))));

            double rx2 = ((x2 - XO) - floor((x2 - XO)));

            double dixx2 = (floor((x2 - XO)) - Midx);

            double f0_x2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_x2)[i] = 0);
              }
            }
            ((f0_x2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx2)),
                               2)));
            ((f0_x2)[0] = (((f0_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[1] * -(dixx2))));
            ((f0_x2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx2)))))));
            ((f0_x2)[1] = (((f0_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[2] * -(dixx2))));
            ((f0_x2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rx2) + pow(rx2, 2)))));
            ((f0_x2)[2] = (((f0_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[3] * -(dixx2))));
            ((f0_x2)[4] = (2.50000000000000000e-01 * pow(rx2, 2)));
            ((f0_x2)[3] = (((f0_x2)[3] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f0_x2)[4] * -(dixx2))));
            ((f0_x2)[4] = ((f0_x2)[4] * (dixx2 + 1.00000000000000000e+00)));
            double f1_x2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_x2)[i] = 0);
              }
            }
            ((f1_x2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rx2))));
            ((f1_x2)[0] = (((f1_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[1] * -(dixx2))));
            ((f1_x2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx2)))));
            ((f1_x2)[1] = (((f1_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[2] * -(dixx2))));
            ((f1_x2)[3] = (5.00000000000000000e-01 * rx2));
            ((f1_x2)[2] = (((f1_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                           ((f1_x2)[3] * -(dixx2))));
            ((f1_x2)[3] = ((f1_x2)[3] * (dixx2 + 1.00000000000000000e+00)));
            double if1_x2[5];
            ((if1_x2)[0] = 1);
            ((if1_x2)[1] = 1);
            ((if1_x2)[3] = 0);
            ((if1_x2)[4] = 0);
            ((if1_x2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx2)),
                                 2))));
            ((if1_x2)[0] = (((if1_x2)[0] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[1] * -(dixx2))));
            ((if1_x2)[2] =
                 ((2.50000000000000000e-01 * pow(rx2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rx2) + pow(rx2, 2))))));
            ((if1_x2)[1] = (((if1_x2)[1] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[2] * -(dixx2))));
            ((if1_x2)[3] = (2.50000000000000000e-01 * pow(rx2, 2)));
            ((if1_x2)[2] = (((if1_x2)[2] * (dixx2 + 1.00000000000000000e+00)) +
                            ((if1_x2)[3] * -(dixx2))));
            ((if1_x2)[3] = ((if1_x2)[3] * (dixx2 + 1.00000000000000000e+00)));
            double iBy =
                (pow(DT, -1.00000000000000000e+00) *
                 (0.00000000000000000e+00 +
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (((0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB0)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_x1)[xyzx] - (if1_x0)[xyzx]) *
                                             (f1_y1)[xyzy])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      })) +
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                             (f1_y1)[xyzy])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      }))) *
                    DT))));

            double y2 =
                ((pow((pow(TX0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))),
                      -1.00000000000000000e+00) *
                  ((((-1.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((-2.00000000000000000e+00 * (TX0 * x0)) +
                      (-1.00000000000000000e+00 *
                       pow(x0, 2.00000000000000000e+00)))) *
                    y0) +
                   (((2.00000000000000000e+00 *
                      pow(TX0, 2.00000000000000000e+00)) +
                     ((2.00000000000000000e+00 * (TX0 * x0)) +
                      (pow(x0, 2.00000000000000000e+00) +
                       ((2.00000000000000000e+00 * (TX0 * x2)) +
                        pow(x2, 2.00000000000000000e+00))))) *
                    y1))) +
                 (pow(TX0, 2.00000000000000000e+00) *
                  ((QE_MASS *
                    (Deltat * (allincfvy + (-1.00000000000000000e+00 * iBy)))) *
                   pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                         pow(TX0, 2.00000000000000000e+00)) +
                        ((2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) *
                           (TX0 * x2))) +
                         (pow(DELTA_Y, 2.00000000000000000e+00) *
                          pow(x2, 2.00000000000000000e+00)))),
                       -1.00000000000000000e+00))));

            double ry2 = ((y2 - YO) - floor((y2 - YO)));

            double dixy2 = (floor((y2 - YO)) - Midy);

            double f0_y2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_y2)[i] = 0);
              }
            }
            ((f0_y2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry2)),
                               2)));
            ((f0_y2)[0] = (((f0_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[1] * -(dixy2))));
            ((f0_y2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry2)))))));
            ((f0_y2)[1] = (((f0_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[2] * -(dixy2))));
            ((f0_y2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * ry2) + pow(ry2, 2)))));
            ((f0_y2)[2] = (((f0_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[3] * -(dixy2))));
            ((f0_y2)[4] = (2.50000000000000000e-01 * pow(ry2, 2)));
            ((f0_y2)[3] = (((f0_y2)[3] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f0_y2)[4] * -(dixy2))));
            ((f0_y2)[4] = ((f0_y2)[4] * (dixy2 + 1.00000000000000000e+00)));
            double f1_y2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_y2)[i] = 0);
              }
            }
            ((f1_y2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * ry2))));
            ((f1_y2)[0] = (((f1_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[1] * -(dixy2))));
            ((f1_y2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry2)))));
            ((f1_y2)[1] = (((f1_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[2] * -(dixy2))));
            ((f1_y2)[3] = (5.00000000000000000e-01 * ry2));
            ((f1_y2)[2] = (((f1_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                           ((f1_y2)[3] * -(dixy2))));
            ((f1_y2)[3] = ((f1_y2)[3] * (dixy2 + 1.00000000000000000e+00)));
            double if1_y2[5];
            ((if1_y2)[0] = 1);
            ((if1_y2)[1] = 1);
            ((if1_y2)[3] = 0);
            ((if1_y2)[4] = 0);
            ((if1_y2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry2)),
                                 2))));
            ((if1_y2)[0] = (((if1_y2)[0] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[1] * -(dixy2))));
            ((if1_y2)[2] =
                 ((2.50000000000000000e-01 * pow(ry2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * ry2) + pow(ry2, 2))))));
            ((if1_y2)[1] = (((if1_y2)[1] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[2] * -(dixy2))));
            ((if1_y2)[3] = (2.50000000000000000e-01 * pow(ry2, 2)));
            ((if1_y2)[2] = (((if1_y2)[2] * (dixy2 + 1.00000000000000000e+00)) +
                            ((if1_y2)[3] * -(dixy2))));
            ((if1_y2)[3] = ((if1_y2)[3] * (dixy2 + 1.00000000000000000e+00)));
            double iBz =
                (-1.00000000000000000e+00 *
                 (pow(DT, -1.00000000000000000e+00) *
                  ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                   (0.00000000000000000e+00 +
                    (((-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          double tmpBfd = 0.00000000000000000e+00;

                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx =
                                          (xyzx + (5 * (xyzy + (5 * xyzz))));

                                      (tmpBfd = (tmpBfd +
                                                 ((shB0)[((allidx * 3) + 0)] *
                                                  ((f0_x0)[xyzx] *
                                                   (((if1_y1)[xyzy] -
                                                     (if1_y0)[xyzy]) *
                                                    (f1_z1)[xyzz])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          tmpBfd;
                        }))) +
                      ((0.00000000000000000e+00 + ({
                          double tmpBfd = 0.00000000000000000e+00;

                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx =
                                          (xyzx + (5 * (xyzy + (5 * xyzz))));

                                      (tmpBfd = (tmpBfd +
                                                 ((shB0)[((allidx * 3) + 1)] *
                                                  ((f0_y1)[xyzy] *
                                                   (((if1_x1)[xyzx] -
                                                     (if1_x0)[xyzx]) *
                                                    (f1_z1)[xyzz])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          tmpBfd;
                        })) +
                       ((-1.00000000000000000e+00 *
                         (0.00000000000000000e+00 + ({
                            double tmpBfd = 0.00000000000000000e+00;

                            {
                              long xyzz;

                              for ((xyzz = 0); (xyzz < 5);
                                   (xyzz = (xyzz + 1))) {
                                {
                                  long xyzy;

                                  for ((xyzy = 0); (xyzy < 5);
                                       (xyzy = (xyzy + 1))) {
                                    {
                                      long xyzx;

                                      for ((xyzx = 0); (xyzx < 5);
                                           (xyzx = (xyzx + 1))) {
                                        int allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz))));

                                        (tmpBfd = (tmpBfd +
                                                   ((shB1)[((allidx * 3) + 0)] *
                                                    ((f0_x2)[xyzx] *
                                                     (((if1_y2)[xyzy] -
                                                       (if1_y1)[xyzy]) *
                                                      (f1_z1)[xyzz])))));
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            tmpBfd;
                          }))) +
                        (0.00000000000000000e+00 + ({
                           double tmpBfd = 0.00000000000000000e+00;

                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz))));

                                       (tmpBfd = (tmpBfd +
                                                  ((shB1)[((allidx * 3) + 1)] *
                                                   ((f0_y1)[xyzy] *
                                                    (((if1_x2)[xyzx] -
                                                      (if1_x1)[xyzx]) *
                                                     (f1_z1)[xyzz])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           tmpBfd;
                         }))))) *
                     DT)))));

            double z2 =
                (((-1.00000000000000000e+00 * z0) +
                  (2.00000000000000000e+00 * z1)) +
                 (pow(DELTA_Z, -2.00000000000000000e+00) *
                  (QE_MASS *
                   (Deltat * (allincfvz + (-1.00000000000000000e+00 * iBz))))));

            double rz2 = ((z2 - (ZO - zmid)) - floor((z2 - (ZO - zmid))));

            double dixz2 = (floor((z2 - (ZO - zmid))) - Midz);

            double f0_z2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_z2)[i] = 0);
              }
            }
            ((f0_z2)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz2)),
                               2)));
            ((f0_z2)[0] = (((f0_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[1] * -(dixz2))));
            ((f0_z2)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz2)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz2)))))));
            ((f0_z2)[1] = (((f0_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[2] * -(dixz2))));
            ((f0_z2)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rz2) + pow(rz2, 2)))));
            ((f0_z2)[2] = (((f0_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[3] * -(dixz2))));
            ((f0_z2)[4] = (2.50000000000000000e-01 * pow(rz2, 2)));
            ((f0_z2)[3] = (((f0_z2)[3] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f0_z2)[4] * -(dixz2))));
            ((f0_z2)[4] = ((f0_z2)[4] * (dixz2 + 1.00000000000000000e+00)));
            double f1_z2[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_z2)[i] = 0);
              }
            }
            ((f1_z2)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rz2))));
            ((f1_z2)[0] = (((f1_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[1] * -(dixz2))));
            ((f1_z2)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz2))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz2)))));
            ((f1_z2)[1] = (((f1_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[2] * -(dixz2))));
            ((f1_z2)[3] = (5.00000000000000000e-01 * rz2));
            ((f1_z2)[2] = (((f1_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                           ((f1_z2)[3] * -(dixz2))));
            ((f1_z2)[3] = ((f1_z2)[3] * (dixz2 + 1.00000000000000000e+00)));
            double if1_z2[5];
            ((if1_z2)[0] = 1);
            ((if1_z2)[1] = 1);
            ((if1_z2)[3] = 0);
            ((if1_z2)[4] = 0);
            ((if1_z2)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz2)),
                                 2))));
            ((if1_z2)[0] = (((if1_z2)[0] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[1] * -(dixz2))));
            ((if1_z2)[2] =
                 ((2.50000000000000000e-01 * pow(rz2, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rz2) + pow(rz2, 2))))));
            ((if1_z2)[1] = (((if1_z2)[1] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[2] * -(dixz2))));
            ((if1_z2)[3] = (2.50000000000000000e-01 * pow(rz2, 2)));
            ((if1_z2)[2] = (((if1_z2)[2] * (dixz2 + 1.00000000000000000e+00)) +
                            ((if1_z2)[3] * -(dixz2))));
            ((if1_z2)[3] = ((if1_z2)[3] * (dixz2 + 1.00000000000000000e+00)));
            (iBz = 0.00000000000000000e+00);
            double z3 = (((-1.00000000000000000e+00 * z1) +
                          (2.00000000000000000e+00 * z2)) +
                         (pow(DELTA_Z, -2.00000000000000000e+00) *
                          (-1 * (Deltat * (QE_MASS * iBz)))));

            double rz3 = ((z3 - (ZO - zmid)) - floor((z3 - (ZO - zmid))));

            double dixz3 = (floor((z3 - (ZO - zmid))) - Midz);

            double f0_z3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_z3)[i] = 0);
              }
            }
            ((f0_z3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rz3)),
                               2)));
            ((f0_z3)[0] = (((f0_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[1] * -(dixz3))));
            ((f0_z3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz3)))))));
            ((f0_z3)[1] = (((f0_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[2] * -(dixz3))));
            ((f0_z3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rz3) + pow(rz3, 2)))));
            ((f0_z3)[2] = (((f0_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[3] * -(dixz3))));
            ((f0_z3)[4] = (2.50000000000000000e-01 * pow(rz3, 2)));
            ((f0_z3)[3] = (((f0_z3)[3] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f0_z3)[4] * -(dixz3))));
            ((f0_z3)[4] = ((f0_z3)[4] * (dixz3 + 1.00000000000000000e+00)));
            double f1_z3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_z3)[i] = 0);
              }
            }
            ((f1_z3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rz3))));
            ((f1_z3)[0] = (((f1_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[1] * -(dixz3))));
            ((f1_z3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rz3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rz3)))));
            ((f1_z3)[1] = (((f1_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[2] * -(dixz3))));
            ((f1_z3)[3] = (5.00000000000000000e-01 * rz3));
            ((f1_z3)[2] = (((f1_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                           ((f1_z3)[3] * -(dixz3))));
            ((f1_z3)[3] = ((f1_z3)[3] * (dixz3 + 1.00000000000000000e+00)));
            double if1_z3[5];
            ((if1_z3)[0] = 1);
            ((if1_z3)[1] = 1);
            ((if1_z3)[3] = 0);
            ((if1_z3)[4] = 0);
            ((if1_z3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rz3)),
                                 2))));
            ((if1_z3)[0] = (((if1_z3)[0] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[1] * -(dixz3))));
            ((if1_z3)[2] =
                 ((2.50000000000000000e-01 * pow(rz3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rz3) + pow(rz3, 2))))));
            ((if1_z3)[1] = (((if1_z3)[1] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[2] * -(dixz3))));
            ((if1_z3)[3] = (2.50000000000000000e-01 * pow(rz3, 2)));
            ((if1_z3)[2] = (((if1_z3)[2] * (dixz3 + 1.00000000000000000e+00)) +
                            ((if1_z3)[3] * -(dixz3))));
            ((if1_z3)[3] = ((if1_z3)[3] * (dixz3 + 1.00000000000000000e+00)));
            (iBy =
                 ((-1.00000000000000000e+00 *
                   (0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 0)] *
                                         ((f0_x2)[xyzx] *
                                          (((if1_z2)[xyzz] - (if1_z1)[xyzz]) *
                                           (f1_y2)[xyzy])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    }))) +
                  (-1.00000000000000000e+00 *
                   (0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 0)] *
                                         ((f0_x2)[xyzx] *
                                          (((if1_z3)[xyzz] - (if1_z2)[xyzz]) *
                                           (f1_y2)[xyzy])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    })))));
            double y3 = (((-1.00000000000000000e+00 * y1) +
                          (2.00000000000000000e+00 * y2)) +
                         (pow(TX0, 2.00000000000000000e+00) *
                          ((-1 * (Deltat * (QE_MASS * iBy))) *
                           pow(((pow(DELTA_Y, 2.00000000000000000e+00) *
                                 pow(TX0, 2.00000000000000000e+00)) +
                                ((2.00000000000000000e+00 *
                                  (pow(DELTA_Y, 2.00000000000000000e+00) *
                                   (TX0 * x2))) +
                                 (pow(DELTA_Y, 2.00000000000000000e+00) *
                                  pow(x2, 2.00000000000000000e+00)))),
                               -1.00000000000000000e+00))));

            double ry3 = ((y3 - YO) - floor((y3 - YO)));

            double dixy3 = (floor((y3 - YO)) - Midy);

            double f0_y3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_y3)[i] = 0);
              }
            }
            ((f0_y3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * ry3)),
                               2)));
            ((f0_y3)[0] = (((f0_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[1] * -(dixy3))));
            ((f0_y3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry3)))))));
            ((f0_y3)[1] = (((f0_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[2] * -(dixy3))));
            ((f0_y3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * ry3) + pow(ry3, 2)))));
            ((f0_y3)[2] = (((f0_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[3] * -(dixy3))));
            ((f0_y3)[4] = (2.50000000000000000e-01 * pow(ry3, 2)));
            ((f0_y3)[3] = (((f0_y3)[3] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f0_y3)[4] * -(dixy3))));
            ((f0_y3)[4] = ((f0_y3)[4] * (dixy3 + 1.00000000000000000e+00)));
            double f1_y3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_y3)[i] = 0);
              }
            }
            ((f1_y3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * ry3))));
            ((f1_y3)[0] = (((f1_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[1] * -(dixy3))));
            ((f1_y3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * ry3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * ry3)))));
            ((f1_y3)[1] = (((f1_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[2] * -(dixy3))));
            ((f1_y3)[3] = (5.00000000000000000e-01 * ry3));
            ((f1_y3)[2] = (((f1_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                           ((f1_y3)[3] * -(dixy3))));
            ((f1_y3)[3] = ((f1_y3)[3] * (dixy3 + 1.00000000000000000e+00)));
            double if1_y3[5];
            ((if1_y3)[0] = 1);
            ((if1_y3)[1] = 1);
            ((if1_y3)[3] = 0);
            ((if1_y3)[4] = 0);
            ((if1_y3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * ry3)),
                                 2))));
            ((if1_y3)[0] = (((if1_y3)[0] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[1] * -(dixy3))));
            ((if1_y3)[2] =
                 ((2.50000000000000000e-01 * pow(ry3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * ry3) + pow(ry3, 2))))));
            ((if1_y3)[1] = (((if1_y3)[1] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[2] * -(dixy3))));
            ((if1_y3)[3] = (2.50000000000000000e-01 * pow(ry3, 2)));
            ((if1_y3)[2] = (((if1_y3)[2] * (dixy3 + 1.00000000000000000e+00)) +
                            ((if1_y3)[3] * -(dixy3))));
            ((if1_y3)[3] = ((if1_y3)[3] * (dixy3 + 1.00000000000000000e+00)));
            (iBx =
                 ((0.00000000000000000e+00 + ({
                     double tmpBfd = 0.00000000000000000e+00;

                     {
                       long xyzz;

                       for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                         {
                           long xyzy;

                           for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                             {
                               long xyzx;

                               for ((xyzx = 0); (xyzx < 5);
                                    (xyzx = (xyzx + 1))) {
                                 int allidx =
                                     (xyzx + (5 * (xyzy + (5 * xyzz))));

                                 (tmpBfd =
                                      (tmpBfd +
                                       ((shB1)[((allidx * 3) + 1)] *
                                        ((f0_y2)[xyzy] *
                                         (((if1_z2)[xyzz] - (if1_z1)[xyzz]) *
                                          (f1_x2)[xyzx])))));
                               }
                             }
                           }
                         }
                       }
                     }
                     tmpBfd;
                   })) +
                  ((0.00000000000000000e+00 + ({
                      double tmpBfd = 0.00000000000000000e+00;

                      {
                        long xyzz;

                        for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                          {
                            long xyzy;

                            for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                              {
                                long xyzx;

                                for ((xyzx = 0); (xyzx < 5);
                                     (xyzx = (xyzx + 1))) {
                                  int allidx =
                                      (xyzx + (5 * (xyzy + (5 * xyzz))));

                                  (tmpBfd =
                                       (tmpBfd +
                                        ((shB1)[((allidx * 3) + 1)] *
                                         ((f0_y2)[xyzy] *
                                          (((if1_z3)[xyzz] - (if1_z2)[xyzz]) *
                                           (f1_x2)[xyzx])))));
                                }
                              }
                            }
                          }
                        }
                      }
                      tmpBfd;
                    })) +
                   ((-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z1)[xyzz] *
                                            (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                             (f1_x2)[xyzx])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      }))) +
                    (-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        double tmpBfd = 0.00000000000000000e+00;

                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz))));

                                    (tmpBfd =
                                         (tmpBfd +
                                          ((shB1)[((allidx * 3) + 2)] *
                                           ((f0_z3)[xyzz] *
                                            (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                             (f1_x2)[xyzx])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        tmpBfd;
                      })))))));
            double x3 =
                ((pow(DELTA_X, -2.00000000000000000e+00) *
                  (pow(TX0, -2.00000000000000000e+00) *
                   ((-1.00000000000000000e+00 *
                     (pow(DELTA_X, 2.00000000000000000e+00) *
                      (pow(TX0, 2.00000000000000000e+00) * x1))) +
                    ((2.00000000000000000e+00 *
                      (pow(DELTA_X, 2.00000000000000000e+00) *
                       (pow(TX0, 2.00000000000000000e+00) * x2))) +
                     ((((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                        (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                       pow(y1, 2.00000000000000000e+00)) +
                      ((((-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                         (-2.00000000000000000e+00 *
                          (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                        (y1 * y2)) +
                       ((((2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                          (2.00000000000000000e+00 *
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                         pow(y2, 2.00000000000000000e+00)) +
                        ((((-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * TX0)) +
                           (-2.00000000000000000e+00 *
                            (pow(DELTA_Y, 2.00000000000000000e+00) * x2))) *
                          (y2 * y3)) +
                         (((pow(DELTA_Y, 2.00000000000000000e+00) * TX0) +
                           (pow(DELTA_Y, 2.00000000000000000e+00) * x2)) *
                          pow(y3, 2.00000000000000000e+00)))))))))) +
                 (pow(DELTA_X, -2.00000000000000000e+00) *
                  (-1 * (Deltat * (QE_MASS * iBx)))));

            double rx3 = ((x3 - XO) - floor((x3 - XO)));

            double dixx3 = (floor((x3 - XO)) - Midx);

            double f0_x3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f0_x3)[i] = 0);
              }
            }
            ((f0_x3)[1] = (2.50000000000000000e-01 *
                           pow((1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * rx3)),
                               2)));
            ((f0_x3)[0] = (((f0_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[1] * -(dixx3))));
            ((f0_x3)[2] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            (pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx3)),
                                 2) +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx3)))))));
            ((f0_x3)[1] = (((f0_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[2] * -(dixx3))));
            ((f0_x3)[3] = (-2.50000000000000000e-01 *
                           (-1.00000000000000000e+00 +
                            ((-2.00000000000000000e+00 * rx3) + pow(rx3, 2)))));
            ((f0_x3)[2] = (((f0_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[3] * -(dixx3))));
            ((f0_x3)[4] = (2.50000000000000000e-01 * pow(rx3, 2)));
            ((f0_x3)[3] = (((f0_x3)[3] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f0_x3)[4] * -(dixx3))));
            ((f0_x3)[4] = ((f0_x3)[4] * (dixx3 + 1.00000000000000000e+00)));
            double f1_x3[5];
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((f1_x3)[i] = 0);
              }
            }
            ((f1_x3)[1] = (5.00000000000000000e-01 *
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * rx3))));
            ((f1_x3)[0] = (((f1_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[1] * -(dixx3))));
            ((f1_x3)[2] = ((2.50000000000000000e-01 *
                            (2.00000000000000000e+00 +
                             (-2.00000000000000000e+00 *
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * rx3))))) +
                           (5.00000000000000000e-01 *
                            (1.00000000000000000e+00 +
                             (-1.00000000000000000e+00 * rx3)))));
            ((f1_x3)[1] = (((f1_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[2] * -(dixx3))));
            ((f1_x3)[3] = (5.00000000000000000e-01 * rx3));
            ((f1_x3)[2] = (((f1_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                           ((f1_x3)[3] * -(dixx3))));
            ((f1_x3)[3] = ((f1_x3)[3] * (dixx3 + 1.00000000000000000e+00)));
            double if1_x3[5];
            ((if1_x3)[0] = 1);
            ((if1_x3)[1] = 1);
            ((if1_x3)[3] = 0);
            ((if1_x3)[4] = 0);
            ((if1_x3)[1] = (1.00000000000000000e+00 +
                            (-2.50000000000000000e-01 *
                             pow((1.00000000000000000e+00 +
                                  (-1.00000000000000000e+00 * rx3)),
                                 2))));
            ((if1_x3)[0] = (((if1_x3)[0] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[1] * -(dixx3))));
            ((if1_x3)[2] =
                 ((2.50000000000000000e-01 * pow(rx3, 2)) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * rx3) + pow(rx3, 2))))));
            ((if1_x3)[1] = (((if1_x3)[1] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[2] * -(dixx3))));
            ((if1_x3)[3] = (2.50000000000000000e-01 * pow(rx3, 2)));
            ((if1_x3)[2] = (((if1_x3)[2] * (dixx3 + 1.00000000000000000e+00)) +
                            ((if1_x3)[3] * -(dixx3))));
            ((if1_x3)[3] = ((if1_x3)[3] * (dixx3 + 1.00000000000000000e+00)));
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_x2)[xyzx] - (if1_x1)[xyzx]) *
                                           ((f0_y1)[xyzy] * (f0_z1)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 0)] =
                             ((shJ0)[((allidx * 3) + 0)] +
                              ((grid_geo_x *
                                ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_y2)[xyzy] - (if1_y1)[xyzy]) *
                                           ((f0_x2)[xyzx] * (f0_z1)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 1)] =
                             ((shJ0)[((allidx * 3) + 1)] +
                              ((grid_geo_y *
                                (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_z3)[xyzz] - (if1_z1)[xyzz]) *
                                           ((f0_x2)[xyzx] * (f0_y2)[xyzy]))));
                        ((shJ0)[((allidx * 3) + 2)] =
                             ((shJ0)[((allidx * 3) + 2)] +
                              ((grid_geo_z *
                                ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_y3)[xyzy] - (if1_y2)[xyzy]) *
                                           ((f0_x2)[xyzx] * (f0_z3)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 1)] =
                             ((shJ0)[((allidx * 3) + 1)] +
                              ((grid_geo_y *
                                (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                        int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                        double Jtmp;

                        (Jtmp =
                             (simd_mask * (((if1_x3)[xyzx] - (if1_x2)[xyzx]) *
                                           ((f0_y3)[xyzy] * (f0_z3)[xyzz]))));
                        ((shJ0)[((allidx * 3) + 0)] =
                             ((shJ0)[((allidx * 3) + 0)] +
                              ((grid_geo_x *
                                ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                 Charge0)) *
                               Jtmp)));
                      }
                    }
                  }
                }
              }
            }
            double newvx = ((x3 - x2) / DT);

            double newvy = ((y3 - y2) / DT);

            double newvz = ((z3 - z2) / DT);

            double newxx = (x3 - XO);

            double newxy = (y3 - YO);

            double newxz = ((z3 + zmid) - ZO);

            (newxx = (newxx + 5.00000000000000000e-01));
            (newxy = (newxy + 5.00000000000000000e-01));
            (newxz = (newxz + 5.00000000000000000e-01));
          }
          {
            long stmpg1;

            for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
              if ((g_inner < load0)) {
                ((particle_head_general)[(stmpg1 + (g_inner * 6))] =
                     (local_particle_head)[stmpg1]);

              } else {
                0;
              }
            }
          }
        }
      }
    }
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long Gll_P9918;

                  for ((Gll_P9918 = 0); (Gll_P9918 < (3 * 5));
                       (Gll_P9918 = (Gll_P9918 + 1))) {
                    (((FoutJ + ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                     ((YLEN + (2 * ovlp)) *
                                                      (ZLEN + (2 * ovlp)))))) +
                                (0 + (num_ele * ((bBidx + ovlp) +
                                                 ((XLEN + (2 * ovlp)) *
                                                  (((xyzy + bBidy) + ovlp) +
                                                   ((YLEN + (2 * ovlp)) *
                                                    ((xyzz + bBidz) +
                                                     ovlp))))))))))[Gll_P9918] =
                         ((shJ0 + total_idx))[Gll_P9918]);
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP11;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP11:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP12;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP12:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_Bfield_pushJ_vlo_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[375];
  double shB0[375];
  double shB1[375];
  double shJ0[375];
  __m256d shJ_incf_simdp[375];
  double *shJ_incf = shJ_incf_simdp;

  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long MYGEN658 = 0;

                  for (0; (MYGEN658 < (3 * 5));
                       (MYGEN658 = (MYGEN658 + __xlen))) {
                    int ridx = (MYGEN658 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN660 = 0;

                  for (0; (MYGEN660 < (3 * 5));
                       (MYGEN660 = (MYGEN660 + __xlen))) {
                    int ridx = (MYGEN660 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB0 + total_idx))[ridx] =
                           ((fieldB +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN662 = 0;

                  for (0; (MYGEN662 < (3 * 5));
                       (MYGEN662 = (MYGEN662 + __xlen))) {
                    int ridx = (MYGEN662 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB1 + total_idx))[ridx] =
                           ((fieldB1 +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN664 = 0;

                  for (0; (MYGEN664 < (3 * 5));
                       (MYGEN664 = (MYGEN664 + __xlen))) {
                    int ridx = (MYGEN664 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shJ0 + total_idx))[ridx] =
                           ((FoutJ +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long xtmp;

                  for ((xtmp = 0); (xtmp < (15 * 4)); (xtmp = (xtmp + 1))) {
                    ((shJ_incf)[((total_idx * 4) + xtmp)] = 0);
                  }
                }
              }
            }
          }
        }
      }
    }
    {
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 4))) {
          __m256d VPFX_simd_mask[1];
          double *simd_mask = VPFX_simd_mask;

          {
            int inner_var_G0;

            for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                 (inner_var_G0 = (inner_var_G0 + 1))) {
              ((simd_mask)[inner_var_G0] = ((g_inner + inner_var_G0) < load0));
            }
          }
          {
            __m256d VPFX_local_particle_head[6];
            double(*local_particle_head)[4];
            (local_particle_head = VPFX_local_particle_head);
            {
              int stmpg1;

#pragma clang loop vectorize(disable)
              for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
                {
                  {
                    int inner_var_G0;

                    for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                         (inner_var_G0 = (inner_var_G0 + 1))) {
                      (((local_particle_head)[stmpg1])[inner_var_G0] =
                           (particle_head_general)[(
                               stmpg1 + (((((g_inner + inner_var_G0) < load0))
                                              ? ((g_inner + inner_var_G0))
                                              : ((load0 - 1))) *
                                         6))]);
                    }
                  }
                }
              }
            }
            __m256d VPFX_xx1[1];
            double *xx1 = VPFX_xx1;

            ((VPFX_xx1)[0] = (VPFX_local_particle_head)[((0 * 1) + 0)]);
            __m256d VPFX_xy1[1];
            double *xy1 = VPFX_xy1;

            ((VPFX_xy1)[0] = (VPFX_local_particle_head)[((1 * 1) + 0)]);
            __m256d VPFX_xz1[1];
            double *xz1 = VPFX_xz1;

            ((VPFX_xz1)[0] = (VPFX_local_particle_head)[((2 * 1) + 0)]);
            __m256d VPFX_vx0[1];
            double *vx0 = VPFX_vx0;

            ((VPFX_vx0)[0] = (VPFX_local_particle_head)[((3 * 1) + 0)]);
            __m256d VPFX_vy0[1];
            double *vy0 = VPFX_vy0;

            ((VPFX_vy0)[0] = (VPFX_local_particle_head)[((4 * 1) + 0)]);
            __m256d VPFX_vz0[1];
            double *vz0 = VPFX_vz0;

            ((VPFX_vz0)[0] = (VPFX_local_particle_head)[((5 * 1) + 0)]);
            ((VPFX_xx1)[0] = ((VPFX_xx1)[0] + -5.00000000000000000e-01));
            ((VPFX_xy1)[0] = ((VPFX_xy1)[0] + -5.00000000000000000e-01));
            ((VPFX_xz1)[0] = ((VPFX_xz1)[0] + -5.00000000000000000e-01));
            __m256d VPFX_rx[1];
            double *rx = VPFX_rx;

            ((VPFX_rx)[0] = ((VPFX_xx1)[0] - Midx));
            __m256d VPFX_ry[1];
            double *ry = VPFX_ry;

            ((VPFX_ry)[0] = ((VPFX_xy1)[0] - Midy));
            __m256d VPFX_rz[1];
            double *rz = VPFX_rz;

            ((VPFX_rz)[0] = ((VPFX_xz1)[0] - Midz));
            __m256d VPFX_xx0[1];
            double *xx0 = VPFX_xx0;

            ((VPFX_xx0)[0] = ((VPFX_xx1)[0] - (Deltat * (VPFX_vx0)[0])));
            __m256d VPFX_xy0[1];
            double *xy0 = VPFX_xy0;

            ((VPFX_xy0)[0] = ((VPFX_xy1)[0] - (Deltat * (VPFX_vy0)[0])));
            __m256d VPFX_xz0[1];
            double *xz0 = VPFX_xz0;

            ((VPFX_xz0)[0] = ((VPFX_xz1)[0] - (Deltat * (VPFX_vz0)[0])));
            __m256d VPFX_Midx0[1];
            double *Midx0 = VPFX_Midx0;

            ((VPFX_Midx0)[0] = _mm256_floor_pd((VPFX_xx0)[0]));
            __m256d VPFX_Midx1[1];
            double *Midx1 = VPFX_Midx1;

            ((VPFX_Midx1)[0] = _mm256_floor_pd((VPFX_xx1)[0]));
            __m256d VPFX_Midy0[1];
            double *Midy0 = VPFX_Midy0;

            ((VPFX_Midy0)[0] = _mm256_floor_pd((VPFX_xy0)[0]));
            __m256d VPFX_Midy1[1];
            double *Midy1 = VPFX_Midy1;

            ((VPFX_Midy1)[0] = _mm256_floor_pd((VPFX_xy1)[0]));
            __m256d VPFX_Midz0[1];
            double *Midz0 = VPFX_Midz0;

            ((VPFX_Midz0)[0] = _mm256_floor_pd((VPFX_xz0)[0]));
            __m256d VPFX_Midz1[1];
            double *Midz1 = VPFX_Midz1;

            ((VPFX_Midz1)[0] = _mm256_floor_pd((VPFX_xz1)[0]));
            __m256d VPFX_rx0[1];
            double *rx0 = VPFX_rx0;

            ((VPFX_rx0)[0] = ((VPFX_xx0)[0] - (VPFX_Midx0)[0]));
            __m256d VPFX_rx1[1];
            double *rx1 = VPFX_rx1;

            ((VPFX_rx1)[0] = ((VPFX_xx1)[0] - (VPFX_Midx1)[0]));
            __m256d VPFX_ry0[1];
            double *ry0 = VPFX_ry0;

            ((VPFX_ry0)[0] = ((VPFX_xy0)[0] - (VPFX_Midy0)[0]));
            __m256d VPFX_ry1[1];
            double *ry1 = VPFX_ry1;

            ((VPFX_ry1)[0] = ((VPFX_xy1)[0] - (VPFX_Midy1)[0]));
            __m256d VPFX_rz0[1];
            double *rz0 = VPFX_rz0;

            ((VPFX_rz0)[0] = ((VPFX_xz0)[0] - (VPFX_Midz0)[0]));
            __m256d VPFX_rz1[1];
            double *rz1 = VPFX_rz1;

            ((VPFX_rz1)[0] = ((VPFX_xz1)[0] - (VPFX_Midz1)[0]));
            __m256d VPFX_dixx0[1];
            double *dixx0 = VPFX_dixx0;

            ((VPFX_dixx0)[0] = ((VPFX_Midx0)[0] - Midx));
            __m256d VPFX_dixx1[1];
            double *dixx1 = VPFX_dixx1;

            ((VPFX_dixx1)[0] = ((VPFX_Midx1)[0] - Midx));
            __m256d VPFX_dixy0[1];
            double *dixy0 = VPFX_dixy0;

            ((VPFX_dixy0)[0] = ((VPFX_Midy0)[0] - Midy));
            __m256d VPFX_dixy1[1];
            double *dixy1 = VPFX_dixy1;

            ((VPFX_dixy1)[0] = ((VPFX_Midy1)[0] - Midy));
            __m256d VPFX_dixz0[1];
            double *dixz0 = VPFX_dixz0;

            ((VPFX_dixz0)[0] = ((VPFX_Midz0)[0] - Midz));
            __m256d VPFX_dixz1[1];
            double *dixz1 = VPFX_dixz1;

            ((VPFX_dixz1)[0] = ((VPFX_Midz1)[0] - Midz));
            __m256d VPFX_f0_x0[5];
            double(*f0_x0)[4];
            (f0_x0 = VPFX_f0_x0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_x0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_x0)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx0)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx0)[0])))));
            ((VPFX_f0_x0)[((0 * 1) + 0)] =
                 (((VPFX_f0_x0)[((0 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((1 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0])))))));
            ((VPFX_f0_x0)[((1 * 1) + 0)] =
                 (((VPFX_f0_x0)[((1 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((2 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rx0)[0]) +
                    ((VPFX_rx0)[0] * (VPFX_rx0)[0])))));
            ((VPFX_f0_x0)[((2 * 1) + 0)] =
                 (((VPFX_f0_x0)[((2 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((3 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx0)[0] * (VPFX_rx0)[0])));
            ((VPFX_f0_x0)[((3 * 1) + 0)] =
                 (((VPFX_f0_x0)[((3 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((4 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((4 * 1) + 0)] =
                 ((VPFX_f0_x0)[((4 * 1) + 0)] *
                  ((VPFX_dixx0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_x0[5];
            double(*f1_x0)[4];
            (f1_x0 = VPFX_f1_x0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_x0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_x0)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rx0)[0]))));
            ((VPFX_f1_x0)[((0 * 1) + 0)] =
                 (((VPFX_f1_x0)[((0 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x0)[((1 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f1_x0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx0)[0])))));
            ((VPFX_f1_x0)[((1 * 1) + 0)] =
                 (((VPFX_f1_x0)[((1 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x0)[((2 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f1_x0)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rx0)[0]));
            ((VPFX_f1_x0)[((2 * 1) + 0)] =
                 (((VPFX_f1_x0)[((2 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x0)[((3 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f1_x0)[((3 * 1) + 0)] =
                 ((VPFX_f1_x0)[((3 * 1) + 0)] *
                  ((VPFX_dixx0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_x0[5];
            double(*if1_x0)[4];
            (if1_x0 = VPFX_if1_x0);
            ((VPFX_if1_x0)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x0)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x0)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x0)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x0)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx0)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx0)[0]))))));
            ((VPFX_if1_x0)[((0 * 1) + 0)] =
                 (((VPFX_if1_x0)[((0 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x0)[((1 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_if1_x0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rx0)[0] * (VPFX_rx0)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rx0)[0]) +
                     ((VPFX_rx0)[0] * (VPFX_rx0)[0]))))));
            ((VPFX_if1_x0)[((1 * 1) + 0)] =
                 (((VPFX_if1_x0)[((1 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x0)[((2 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_if1_x0)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx0)[0] * (VPFX_rx0)[0])));
            ((VPFX_if1_x0)[((2 * 1) + 0)] =
                 (((VPFX_if1_x0)[((2 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x0)[((3 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_if1_x0)[((3 * 1) + 0)] =
                 ((VPFX_if1_x0)[((3 * 1) + 0)] *
                  ((VPFX_dixx0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_y0[5];
            double(*f0_y0)[4];
            (f0_y0 = VPFX_f0_y0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_y0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_y0)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry0)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry0)[0])))));
            ((VPFX_f0_y0)[((0 * 1) + 0)] =
                 (((VPFX_f0_y0)[((0 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((1 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0])))))));
            ((VPFX_f0_y0)[((1 * 1) + 0)] =
                 (((VPFX_f0_y0)[((1 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((2 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_ry0)[0]) +
                    ((VPFX_ry0)[0] * (VPFX_ry0)[0])))));
            ((VPFX_f0_y0)[((2 * 1) + 0)] =
                 (((VPFX_f0_y0)[((2 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((3 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry0)[0] * (VPFX_ry0)[0])));
            ((VPFX_f0_y0)[((3 * 1) + 0)] =
                 (((VPFX_f0_y0)[((3 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((4 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((4 * 1) + 0)] =
                 ((VPFX_f0_y0)[((4 * 1) + 0)] *
                  ((VPFX_dixy0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_y0[5];
            double(*f1_y0)[4];
            (f1_y0 = VPFX_f1_y0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_y0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_y0)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_ry0)[0]))));
            ((VPFX_f1_y0)[((0 * 1) + 0)] =
                 (((VPFX_f1_y0)[((0 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y0)[((1 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f1_y0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry0)[0])))));
            ((VPFX_f1_y0)[((1 * 1) + 0)] =
                 (((VPFX_f1_y0)[((1 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y0)[((2 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f1_y0)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_ry0)[0]));
            ((VPFX_f1_y0)[((2 * 1) + 0)] =
                 (((VPFX_f1_y0)[((2 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y0)[((3 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f1_y0)[((3 * 1) + 0)] =
                 ((VPFX_f1_y0)[((3 * 1) + 0)] *
                  ((VPFX_dixy0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_y0[5];
            double(*if1_y0)[4];
            (if1_y0 = VPFX_if1_y0);
            ((VPFX_if1_y0)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y0)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y0)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y0)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y0)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry0)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry0)[0]))))));
            ((VPFX_if1_y0)[((0 * 1) + 0)] =
                 (((VPFX_if1_y0)[((0 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y0)[((1 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_if1_y0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_ry0)[0] * (VPFX_ry0)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_ry0)[0]) +
                     ((VPFX_ry0)[0] * (VPFX_ry0)[0]))))));
            ((VPFX_if1_y0)[((1 * 1) + 0)] =
                 (((VPFX_if1_y0)[((1 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y0)[((2 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_if1_y0)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry0)[0] * (VPFX_ry0)[0])));
            ((VPFX_if1_y0)[((2 * 1) + 0)] =
                 (((VPFX_if1_y0)[((2 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y0)[((3 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_if1_y0)[((3 * 1) + 0)] =
                 ((VPFX_if1_y0)[((3 * 1) + 0)] *
                  ((VPFX_dixy0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_z0[5];
            double(*f0_z0)[4];
            (f0_z0 = VPFX_f0_z0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_z0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_z0)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz0)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz0)[0])))));
            ((VPFX_f0_z0)[((0 * 1) + 0)] =
                 (((VPFX_f0_z0)[((0 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((1 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0])))))));
            ((VPFX_f0_z0)[((1 * 1) + 0)] =
                 (((VPFX_f0_z0)[((1 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((2 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rz0)[0]) +
                    ((VPFX_rz0)[0] * (VPFX_rz0)[0])))));
            ((VPFX_f0_z0)[((2 * 1) + 0)] =
                 (((VPFX_f0_z0)[((2 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((3 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz0)[0] * (VPFX_rz0)[0])));
            ((VPFX_f0_z0)[((3 * 1) + 0)] =
                 (((VPFX_f0_z0)[((3 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((4 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((4 * 1) + 0)] =
                 ((VPFX_f0_z0)[((4 * 1) + 0)] *
                  ((VPFX_dixz0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_z0[5];
            double(*f1_z0)[4];
            (f1_z0 = VPFX_f1_z0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_z0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_z0)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rz0)[0]))));
            ((VPFX_f1_z0)[((0 * 1) + 0)] =
                 (((VPFX_f1_z0)[((0 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z0)[((1 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f1_z0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz0)[0])))));
            ((VPFX_f1_z0)[((1 * 1) + 0)] =
                 (((VPFX_f1_z0)[((1 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z0)[((2 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f1_z0)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rz0)[0]));
            ((VPFX_f1_z0)[((2 * 1) + 0)] =
                 (((VPFX_f1_z0)[((2 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z0)[((3 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f1_z0)[((3 * 1) + 0)] =
                 ((VPFX_f1_z0)[((3 * 1) + 0)] *
                  ((VPFX_dixz0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_z0[5];
            double(*if1_z0)[4];
            (if1_z0 = VPFX_if1_z0);
            ((VPFX_if1_z0)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z0)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z0)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z0)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z0)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz0)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz0)[0]))))));
            ((VPFX_if1_z0)[((0 * 1) + 0)] =
                 (((VPFX_if1_z0)[((0 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z0)[((1 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_if1_z0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rz0)[0] * (VPFX_rz0)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rz0)[0]) +
                     ((VPFX_rz0)[0] * (VPFX_rz0)[0]))))));
            ((VPFX_if1_z0)[((1 * 1) + 0)] =
                 (((VPFX_if1_z0)[((1 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z0)[((2 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_if1_z0)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz0)[0] * (VPFX_rz0)[0])));
            ((VPFX_if1_z0)[((2 * 1) + 0)] =
                 (((VPFX_if1_z0)[((2 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z0)[((3 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_if1_z0)[((3 * 1) + 0)] =
                 ((VPFX_if1_z0)[((3 * 1) + 0)] *
                  ((VPFX_dixz0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_x1[5];
            double(*f0_x1)[4];
            (f0_x1 = VPFX_f0_x1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_x1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_x1)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx1)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx1)[0])))));
            ((VPFX_f0_x1)[((0 * 1) + 0)] =
                 (((VPFX_f0_x1)[((0 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((1 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0])))))));
            ((VPFX_f0_x1)[((1 * 1) + 0)] =
                 (((VPFX_f0_x1)[((1 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((2 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rx1)[0]) +
                    ((VPFX_rx1)[0] * (VPFX_rx1)[0])))));
            ((VPFX_f0_x1)[((2 * 1) + 0)] =
                 (((VPFX_f0_x1)[((2 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((3 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx1)[0] * (VPFX_rx1)[0])));
            ((VPFX_f0_x1)[((3 * 1) + 0)] =
                 (((VPFX_f0_x1)[((3 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((4 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((4 * 1) + 0)] =
                 ((VPFX_f0_x1)[((4 * 1) + 0)] *
                  ((VPFX_dixx1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_x1[5];
            double(*f1_x1)[4];
            (f1_x1 = VPFX_f1_x1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_x1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_x1)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rx1)[0]))));
            ((VPFX_f1_x1)[((0 * 1) + 0)] =
                 (((VPFX_f1_x1)[((0 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x1)[((1 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f1_x1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx1)[0])))));
            ((VPFX_f1_x1)[((1 * 1) + 0)] =
                 (((VPFX_f1_x1)[((1 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x1)[((2 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f1_x1)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rx1)[0]));
            ((VPFX_f1_x1)[((2 * 1) + 0)] =
                 (((VPFX_f1_x1)[((2 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x1)[((3 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f1_x1)[((3 * 1) + 0)] =
                 ((VPFX_f1_x1)[((3 * 1) + 0)] *
                  ((VPFX_dixx1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_x1[5];
            double(*if1_x1)[4];
            (if1_x1 = VPFX_if1_x1);
            ((VPFX_if1_x1)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x1)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x1)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x1)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x1)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx1)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx1)[0]))))));
            ((VPFX_if1_x1)[((0 * 1) + 0)] =
                 (((VPFX_if1_x1)[((0 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x1)[((1 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_if1_x1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rx1)[0] * (VPFX_rx1)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rx1)[0]) +
                     ((VPFX_rx1)[0] * (VPFX_rx1)[0]))))));
            ((VPFX_if1_x1)[((1 * 1) + 0)] =
                 (((VPFX_if1_x1)[((1 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x1)[((2 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_if1_x1)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx1)[0] * (VPFX_rx1)[0])));
            ((VPFX_if1_x1)[((2 * 1) + 0)] =
                 (((VPFX_if1_x1)[((2 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x1)[((3 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_if1_x1)[((3 * 1) + 0)] =
                 ((VPFX_if1_x1)[((3 * 1) + 0)] *
                  ((VPFX_dixx1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_y1[5];
            double(*f0_y1)[4];
            (f0_y1 = VPFX_f0_y1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_y1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_y1)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry1)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry1)[0])))));
            ((VPFX_f0_y1)[((0 * 1) + 0)] =
                 (((VPFX_f0_y1)[((0 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((1 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0])))))));
            ((VPFX_f0_y1)[((1 * 1) + 0)] =
                 (((VPFX_f0_y1)[((1 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((2 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_ry1)[0]) +
                    ((VPFX_ry1)[0] * (VPFX_ry1)[0])))));
            ((VPFX_f0_y1)[((2 * 1) + 0)] =
                 (((VPFX_f0_y1)[((2 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((3 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry1)[0] * (VPFX_ry1)[0])));
            ((VPFX_f0_y1)[((3 * 1) + 0)] =
                 (((VPFX_f0_y1)[((3 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((4 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((4 * 1) + 0)] =
                 ((VPFX_f0_y1)[((4 * 1) + 0)] *
                  ((VPFX_dixy1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_y1[5];
            double(*f1_y1)[4];
            (f1_y1 = VPFX_f1_y1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_y1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_y1)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_ry1)[0]))));
            ((VPFX_f1_y1)[((0 * 1) + 0)] =
                 (((VPFX_f1_y1)[((0 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y1)[((1 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f1_y1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry1)[0])))));
            ((VPFX_f1_y1)[((1 * 1) + 0)] =
                 (((VPFX_f1_y1)[((1 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y1)[((2 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f1_y1)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_ry1)[0]));
            ((VPFX_f1_y1)[((2 * 1) + 0)] =
                 (((VPFX_f1_y1)[((2 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y1)[((3 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f1_y1)[((3 * 1) + 0)] =
                 ((VPFX_f1_y1)[((3 * 1) + 0)] *
                  ((VPFX_dixy1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_y1[5];
            double(*if1_y1)[4];
            (if1_y1 = VPFX_if1_y1);
            ((VPFX_if1_y1)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y1)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y1)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y1)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y1)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry1)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry1)[0]))))));
            ((VPFX_if1_y1)[((0 * 1) + 0)] =
                 (((VPFX_if1_y1)[((0 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y1)[((1 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_if1_y1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_ry1)[0] * (VPFX_ry1)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_ry1)[0]) +
                     ((VPFX_ry1)[0] * (VPFX_ry1)[0]))))));
            ((VPFX_if1_y1)[((1 * 1) + 0)] =
                 (((VPFX_if1_y1)[((1 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y1)[((2 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_if1_y1)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry1)[0] * (VPFX_ry1)[0])));
            ((VPFX_if1_y1)[((2 * 1) + 0)] =
                 (((VPFX_if1_y1)[((2 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y1)[((3 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_if1_y1)[((3 * 1) + 0)] =
                 ((VPFX_if1_y1)[((3 * 1) + 0)] *
                  ((VPFX_dixy1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_z1[5];
            double(*f0_z1)[4];
            (f0_z1 = VPFX_f0_z1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_z1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_z1)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz1)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz1)[0])))));
            ((VPFX_f0_z1)[((0 * 1) + 0)] =
                 (((VPFX_f0_z1)[((0 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((1 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0])))))));
            ((VPFX_f0_z1)[((1 * 1) + 0)] =
                 (((VPFX_f0_z1)[((1 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((2 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rz1)[0]) +
                    ((VPFX_rz1)[0] * (VPFX_rz1)[0])))));
            ((VPFX_f0_z1)[((2 * 1) + 0)] =
                 (((VPFX_f0_z1)[((2 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((3 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz1)[0] * (VPFX_rz1)[0])));
            ((VPFX_f0_z1)[((3 * 1) + 0)] =
                 (((VPFX_f0_z1)[((3 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((4 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((4 * 1) + 0)] =
                 ((VPFX_f0_z1)[((4 * 1) + 0)] *
                  ((VPFX_dixz1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_z1[5];
            double(*f1_z1)[4];
            (f1_z1 = VPFX_f1_z1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_z1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_z1)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rz1)[0]))));
            ((VPFX_f1_z1)[((0 * 1) + 0)] =
                 (((VPFX_f1_z1)[((0 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z1)[((1 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f1_z1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz1)[0])))));
            ((VPFX_f1_z1)[((1 * 1) + 0)] =
                 (((VPFX_f1_z1)[((1 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z1)[((2 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f1_z1)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rz1)[0]));
            ((VPFX_f1_z1)[((2 * 1) + 0)] =
                 (((VPFX_f1_z1)[((2 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z1)[((3 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f1_z1)[((3 * 1) + 0)] =
                 ((VPFX_f1_z1)[((3 * 1) + 0)] *
                  ((VPFX_dixz1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_z1[5];
            double(*if1_z1)[4];
            (if1_z1 = VPFX_if1_z1);
            ((VPFX_if1_z1)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z1)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z1)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z1)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z1)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz1)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz1)[0]))))));
            ((VPFX_if1_z1)[((0 * 1) + 0)] =
                 (((VPFX_if1_z1)[((0 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z1)[((1 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_if1_z1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rz1)[0] * (VPFX_rz1)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rz1)[0]) +
                     ((VPFX_rz1)[0] * (VPFX_rz1)[0]))))));
            ((VPFX_if1_z1)[((1 * 1) + 0)] =
                 (((VPFX_if1_z1)[((1 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z1)[((2 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_if1_z1)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz1)[0] * (VPFX_rz1)[0])));
            ((VPFX_if1_z1)[((2 * 1) + 0)] =
                 (((VPFX_if1_z1)[((2 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z1)[((3 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_if1_z1)[((3 * 1) + 0)] =
                 ((VPFX_if1_z1)[((3 * 1) + 0)] *
                  ((VPFX_dixz1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_AllEx[1];
            double *AllEx = VPFX_AllEx;

            ((VPFX_AllEx)[0] = (0 - ((__m256d){})));
            __m256d VPFX_AllEy[1];
            double *AllEy = VPFX_AllEy;

            ((VPFX_AllEy)[0] = (0 - ((__m256d){})));
            __m256d VPFX_AllEz[1];
            double *AllEz = VPFX_AllEz;

            ((VPFX_AllEz)[0] = (0 - ((__m256d){})));
            {
              long idz;

              for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
                {
                  long idy;

                  for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
                    {
                      long idx;

                      for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
                        ((VPFX_AllEx)[0] =
                             ((VPFX_AllEx)[0] +
                              (((shE0)[(0 + (3 * (idx +
                                                  (5 * (idy + (idz * 5))))))] +
                                0) *
                               ((VPFX_f1_x1)[((idx * 1) + 0)] *
                                ((VPFX_f0_y1)[((idy * 1) + 0)] *
                                 (VPFX_f0_z1)[((idz * 1) + 0)])))));
                        ((VPFX_AllEy)[0] =
                             ((VPFX_AllEy)[0] +
                              (((shE0)[(1 + (3 * (idz +
                                                  (5 * (idx + (idy * 5))))))] +
                                0) *
                               ((VPFX_f1_y1)[((idx * 1) + 0)] *
                                ((VPFX_f0_z1)[((idy * 1) + 0)] *
                                 (VPFX_f0_x1)[((idz * 1) + 0)])))));
                        ((VPFX_AllEz)[0] =
                             ((VPFX_AllEz)[0] +
                              (((shE0)[(2 + (3 * (idy +
                                                  (5 * (idz + (idx * 5))))))] +
                                0) *
                               ((VPFX_f1_z1)[((idx * 1) + 0)] *
                                ((VPFX_f0_x1)[((idy * 1) + 0)] *
                                 (VPFX_f0_y1)[((idz * 1) + 0)])))));
                      }
                    }
                  }
                }
              }
            }
            __m256d VPFX_allincfvx[1];
            double *allincfvx = VPFX_allincfvx;

            __m256d VPFX_allincfvy[1];
            double *allincfvy = VPFX_allincfvy;

            __m256d VPFX_allincfvz[1];
            double *allincfvz = VPFX_allincfvz;

            ((VPFX_allincfvx)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEx)[0])));
            ((VPFX_allincfvy)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEy)[0])));
            ((VPFX_allincfvz)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEz)[0])));
            double DT;

            (DT = Deltat);
            {
              __m256d VPFX_x0[1];
              double *x0 = VPFX_x0;

              ((VPFX_x0)[0] = ((VPFX_xx0)[0] + XO));
              __m256d VPFX_y0[1];
              double *y0 = VPFX_y0;

              ((VPFX_y0)[0] = ((VPFX_xy0)[0] + YO));
              __m256d VPFX_z0[1];
              double *z0 = VPFX_z0;

              ((VPFX_z0)[0] = (((VPFX_xz0)[0] + ZO) - zmid));
              __m256d VPFX_x1[1];
              double *x1 = VPFX_x1;

              ((VPFX_x1)[0] = ((VPFX_xx1)[0] + XO));
              __m256d VPFX_y1[1];
              double *y1 = VPFX_y1;

              ((VPFX_y1)[0] = ((VPFX_xy1)[0] + YO));
              __m256d VPFX_z1[1];
              double *z1 = VPFX_z1;

              ((VPFX_z1)[0] = (((VPFX_xz1)[0] + ZO) - zmid));
              __m256d VPFX_mzero[1];
              double *mzero = VPFX_mzero;

              ((VPFX_mzero)[0] = (0.00000000000000000e+00 - ((__m256d){})));
              __m256d VPFX_iBx[1];
              double *iBx = VPFX_iBx;

              ((VPFX_iBx)[0] =
                   ((-1.00000000000000000e+00 *
                     (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                       0.00000000000000000e+00) *
                      ({ (1.00000000000000000e+00 / DT); }))) +
                    (VPFX_mzero)[0]));
              __m256d VPFX_x2[1];
              double *x2 = VPFX_x2;

              ((VPFX_x2)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_x0)[0]) +
                     (2.00000000000000000e+00 * (VPFX_x1)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (QE_MASS * (Deltat * ((VPFX_allincfvx)[0] +
                                           (-1.00000000000000000e+00 *
                                            (VPFX_iBx)[0])))))));
              __m256d VPFX_rx2[1];
              double *rx2 = VPFX_rx2;

              ((VPFX_rx2)[0] = (((VPFX_x2)[0] - XO) -
                                _mm256_floor_pd(((VPFX_x2)[0] - XO))));
              __m256d VPFX_dixx2[1];
              double *dixx2 = VPFX_dixx2;

              ((VPFX_dixx2)[0] = (_mm256_floor_pd(((VPFX_x2)[0] - XO)) - Midx));
              __m256d VPFX_f0_x2[5];
              double(*f0_x2)[4];
              (f0_x2 = VPFX_f0_x2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_x2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_x2)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx2)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx2)[0])))));
              ((VPFX_f0_x2)[((0 * 1) + 0)] =
                   (((VPFX_f0_x2)[((0 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((1 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0])))))));
              ((VPFX_f0_x2)[((1 * 1) + 0)] =
                   (((VPFX_f0_x2)[((1 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((2 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rx2)[0]) +
                      ((VPFX_rx2)[0] * (VPFX_rx2)[0])))));
              ((VPFX_f0_x2)[((2 * 1) + 0)] =
                   (((VPFX_f0_x2)[((2 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((3 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx2)[0] * (VPFX_rx2)[0])));
              ((VPFX_f0_x2)[((3 * 1) + 0)] =
                   (((VPFX_f0_x2)[((3 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((4 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((4 * 1) + 0)] =
                   ((VPFX_f0_x2)[((4 * 1) + 0)] *
                    ((VPFX_dixx2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_x2[5];
              double(*f1_x2)[4];
              (f1_x2 = VPFX_f1_x2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_x2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_x2)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx2)[0]))));
              ((VPFX_f1_x2)[((0 * 1) + 0)] =
                   (((VPFX_f1_x2)[((0 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x2)[((1 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f1_x2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx2)[0])))));
              ((VPFX_f1_x2)[((1 * 1) + 0)] =
                   (((VPFX_f1_x2)[((1 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x2)[((2 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f1_x2)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rx2)[0]));
              ((VPFX_f1_x2)[((2 * 1) + 0)] =
                   (((VPFX_f1_x2)[((2 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x2)[((3 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f1_x2)[((3 * 1) + 0)] =
                   ((VPFX_f1_x2)[((3 * 1) + 0)] *
                    ((VPFX_dixx2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_x2[5];
              double(*if1_x2)[4];
              (if1_x2 = VPFX_if1_x2);
              ((VPFX_if1_x2)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x2)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x2)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x2)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x2)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx2)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx2)[0]))))));
              ((VPFX_if1_x2)[((0 * 1) + 0)] =
                   (((VPFX_if1_x2)[((0 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x2)[((1 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_if1_x2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rx2)[0] * (VPFX_rx2)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rx2)[0]) +
                       ((VPFX_rx2)[0] * (VPFX_rx2)[0]))))));
              ((VPFX_if1_x2)[((1 * 1) + 0)] =
                   (((VPFX_if1_x2)[((1 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x2)[((2 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_if1_x2)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx2)[0] * (VPFX_rx2)[0])));
              ((VPFX_if1_x2)[((2 * 1) + 0)] =
                   (((VPFX_if1_x2)[((2 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x2)[((3 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_if1_x2)[((3 * 1) + 0)] =
                   ((VPFX_if1_x2)[((3 * 1) + 0)] *
                    ((VPFX_dixx2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_iBy[1];
              double *iBy = VPFX_iBy;

              ((VPFX_iBy)[0] =
                   (({ (1.00000000000000000e+00 / DT); }) *
                    (0.00000000000000000e+00 +
                     ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                      (((0.00000000000000000e+00 + ({
                           __m256d VPFX_tmpBfd[1];
                           double *tmpBfd = VPFX_tmpBfd;

                           ((VPFX_tmpBfd)[0] =
                                (0.00000000000000000e+00 - ((__m256d){})));
                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx;

                                       (allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                       ((VPFX_tmpBfd)[0] =
                                            ((VPFX_tmpBfd)[0] +
                                             ((shB0)[((allidx * 3) + 2)] *
                                              ((VPFX_f0_z1)[((xyzz * 1) + 0)] *
                                               (((VPFX_if1_x1)[((xyzx * 1) +
                                                                0)] -
                                                 (VPFX_if1_x0)[((xyzx * 1) +
                                                                0)]) *
                                                (VPFX_f1_y1)[((xyzy * 1) +
                                                              0)])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           (VPFX_tmpBfd)[0];
                         })) +
                        (0.00000000000000000e+00 + ({
                           __m256d VPFX_tmpBfd[1];
                           double *tmpBfd = VPFX_tmpBfd;

                           ((VPFX_tmpBfd)[0] =
                                (0.00000000000000000e+00 - ((__m256d){})));
                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx;

                                       (allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                       ((VPFX_tmpBfd)[0] =
                                            ((VPFX_tmpBfd)[0] +
                                             ((shB1)[((allidx * 3) + 2)] *
                                              ((VPFX_f0_z1)[((xyzz * 1) + 0)] *
                                               (((VPFX_if1_x2)[((xyzx * 1) +
                                                                0)] -
                                                 (VPFX_if1_x1)[((xyzx * 1) +
                                                                0)]) *
                                                (VPFX_f1_y1)[((xyzy * 1) +
                                                              0)])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           (VPFX_tmpBfd)[0];
                         }))) *
                       DT)))));
              __m256d VPFX_y2[1];
              double *y2 = VPFX_y2;

              ((VPFX_y2)[0] =
                   ((({
                       (1.00000000000000000e+00 /
                        ((TX0 * TX0) +
                         ((2.00000000000000000e+00 * (TX0 * (VPFX_x2)[0])) +
                          ((VPFX_x2)[0] * (VPFX_x2)[0]))));
                     }) *
                     ((((-1.00000000000000000e+00 * (TX0 * TX0)) +
                        ((-2.00000000000000000e+00 * (TX0 * (VPFX_x0)[0])) +
                         (-1.00000000000000000e+00 *
                          ((VPFX_x0)[0] * (VPFX_x0)[0])))) *
                       (VPFX_y0)[0]) +
                      (((2.00000000000000000e+00 * (TX0 * TX0)) +
                        ((2.00000000000000000e+00 * (TX0 * (VPFX_x0)[0])) +
                         (((VPFX_x0)[0] * (VPFX_x0)[0]) +
                          ((2.00000000000000000e+00 * (TX0 * (VPFX_x2)[0])) +
                           ((VPFX_x2)[0] * (VPFX_x2)[0]))))) *
                       (VPFX_y1)[0]))) +
                    ((TX0 * TX0) *
                     ((QE_MASS * (Deltat * ((VPFX_allincfvy)[0] +
                                            (-1.00000000000000000e+00 *
                                             (VPFX_iBy)[0])))) *
                      ({
                        (1.00000000000000000e+00 /
                         (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
                          ((2.00000000000000000e+00 *
                            ((DELTA_Y * DELTA_Y) * (TX0 * (VPFX_x2)[0]))) +
                           ((DELTA_Y * DELTA_Y) *
                            ((VPFX_x2)[0] * (VPFX_x2)[0])))));
                      })))));
              __m256d VPFX_ry2[1];
              double *ry2 = VPFX_ry2;

              ((VPFX_ry2)[0] = (((VPFX_y2)[0] - YO) -
                                _mm256_floor_pd(((VPFX_y2)[0] - YO))));
              __m256d VPFX_dixy2[1];
              double *dixy2 = VPFX_dixy2;

              ((VPFX_dixy2)[0] = (_mm256_floor_pd(((VPFX_y2)[0] - YO)) - Midy));
              __m256d VPFX_f0_y2[5];
              double(*f0_y2)[4];
              (f0_y2 = VPFX_f0_y2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_y2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_y2)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry2)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry2)[0])))));
              ((VPFX_f0_y2)[((0 * 1) + 0)] =
                   (((VPFX_f0_y2)[((0 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((1 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0])))))));
              ((VPFX_f0_y2)[((1 * 1) + 0)] =
                   (((VPFX_f0_y2)[((1 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((2 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_ry2)[0]) +
                      ((VPFX_ry2)[0] * (VPFX_ry2)[0])))));
              ((VPFX_f0_y2)[((2 * 1) + 0)] =
                   (((VPFX_f0_y2)[((2 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((3 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry2)[0] * (VPFX_ry2)[0])));
              ((VPFX_f0_y2)[((3 * 1) + 0)] =
                   (((VPFX_f0_y2)[((3 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((4 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((4 * 1) + 0)] =
                   ((VPFX_f0_y2)[((4 * 1) + 0)] *
                    ((VPFX_dixy2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_y2[5];
              double(*f1_y2)[4];
              (f1_y2 = VPFX_f1_y2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_y2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_y2)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry2)[0]))));
              ((VPFX_f1_y2)[((0 * 1) + 0)] =
                   (((VPFX_f1_y2)[((0 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y2)[((1 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f1_y2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry2)[0])))));
              ((VPFX_f1_y2)[((1 * 1) + 0)] =
                   (((VPFX_f1_y2)[((1 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y2)[((2 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f1_y2)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_ry2)[0]));
              ((VPFX_f1_y2)[((2 * 1) + 0)] =
                   (((VPFX_f1_y2)[((2 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y2)[((3 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f1_y2)[((3 * 1) + 0)] =
                   ((VPFX_f1_y2)[((3 * 1) + 0)] *
                    ((VPFX_dixy2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_y2[5];
              double(*if1_y2)[4];
              (if1_y2 = VPFX_if1_y2);
              ((VPFX_if1_y2)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y2)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y2)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y2)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y2)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry2)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry2)[0]))))));
              ((VPFX_if1_y2)[((0 * 1) + 0)] =
                   (((VPFX_if1_y2)[((0 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y2)[((1 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_if1_y2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_ry2)[0] * (VPFX_ry2)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_ry2)[0]) +
                       ((VPFX_ry2)[0] * (VPFX_ry2)[0]))))));
              ((VPFX_if1_y2)[((1 * 1) + 0)] =
                   (((VPFX_if1_y2)[((1 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y2)[((2 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_if1_y2)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry2)[0] * (VPFX_ry2)[0])));
              ((VPFX_if1_y2)[((2 * 1) + 0)] =
                   (((VPFX_if1_y2)[((2 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y2)[((3 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_if1_y2)[((3 * 1) + 0)] =
                   ((VPFX_if1_y2)[((3 * 1) + 0)] *
                    ((VPFX_dixy2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_iBz[1];
              double *iBz = VPFX_iBz;

              ((VPFX_iBz)[0] =
                   (-1.00000000000000000e+00 *
                    (({ (1.00000000000000000e+00 / DT); }) *
                     ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                      (0.00000000000000000e+00 +
                       (((-1.00000000000000000e+00 *
                          (0.00000000000000000e+00 + ({
                             __m256d VPFX_tmpBfd[1];
                             double *tmpBfd = VPFX_tmpBfd;

                             ((VPFX_tmpBfd)[0] =
                                  (0.00000000000000000e+00 - ((__m256d){})));
                             {
                               long xyzz;

                               for ((xyzz = 0); (xyzz < 5);
                                    (xyzz = (xyzz + 1))) {
                                 {
                                   long xyzy;

                                   for ((xyzy = 0); (xyzy < 5);
                                        (xyzy = (xyzy + 1))) {
                                     {
                                       long xyzx;

                                       for ((xyzx = 0); (xyzx < 5);
                                            (xyzx = (xyzx + 1))) {
                                         int allidx;

                                         (allidx = (xyzx +
                                                    (5 * (xyzy + (5 * xyzz)))));
                                         ((VPFX_tmpBfd)[0] =
                                              ((VPFX_tmpBfd)[0] +
                                               ((shB0)[((allidx * 3) + 0)] *
                                                ((VPFX_f0_x0)[((xyzx * 1) +
                                                               0)] *
                                                 (((VPFX_if1_y1)[((xyzy * 1) +
                                                                  0)] -
                                                   (VPFX_if1_y0)[((xyzy * 1) +
                                                                  0)]) *
                                                  (VPFX_f1_z1)[((xyzz * 1) +
                                                                0)])))));
                                       }
                                     }
                                   }
                                 }
                               }
                             }
                             (VPFX_tmpBfd)[0];
                           }))) +
                         ((0.00000000000000000e+00 + ({
                             __m256d VPFX_tmpBfd[1];
                             double *tmpBfd = VPFX_tmpBfd;

                             ((VPFX_tmpBfd)[0] =
                                  (0.00000000000000000e+00 - ((__m256d){})));
                             {
                               long xyzz;

                               for ((xyzz = 0); (xyzz < 5);
                                    (xyzz = (xyzz + 1))) {
                                 {
                                   long xyzy;

                                   for ((xyzy = 0); (xyzy < 5);
                                        (xyzy = (xyzy + 1))) {
                                     {
                                       long xyzx;

                                       for ((xyzx = 0); (xyzx < 5);
                                            (xyzx = (xyzx + 1))) {
                                         int allidx;

                                         (allidx = (xyzx +
                                                    (5 * (xyzy + (5 * xyzz)))));
                                         ((VPFX_tmpBfd)[0] =
                                              ((VPFX_tmpBfd)[0] +
                                               ((shB0)[((allidx * 3) + 1)] *
                                                ((VPFX_f0_y1)[((xyzy * 1) +
                                                               0)] *
                                                 (((VPFX_if1_x1)[((xyzx * 1) +
                                                                  0)] -
                                                   (VPFX_if1_x0)[((xyzx * 1) +
                                                                  0)]) *
                                                  (VPFX_f1_z1)[((xyzz * 1) +
                                                                0)])))));
                                       }
                                     }
                                   }
                                 }
                               }
                             }
                             (VPFX_tmpBfd)[0];
                           })) +
                          ((-1.00000000000000000e+00 *
                            (0.00000000000000000e+00 + ({
                               __m256d VPFX_tmpBfd[1];
                               double *tmpBfd = VPFX_tmpBfd;

                               ((VPFX_tmpBfd)[0] =
                                    (0.00000000000000000e+00 - ((__m256d){})));
                               {
                                 long xyzz;

                                 for ((xyzz = 0); (xyzz < 5);
                                      (xyzz = (xyzz + 1))) {
                                   {
                                     long xyzy;

                                     for ((xyzy = 0); (xyzy < 5);
                                          (xyzy = (xyzy + 1))) {
                                       {
                                         long xyzx;

                                         for ((xyzx = 0); (xyzx < 5);
                                              (xyzx = (xyzx + 1))) {
                                           int allidx;

                                           (allidx =
                                                (xyzx +
                                                 (5 * (xyzy + (5 * xyzz)))));
                                           ((VPFX_tmpBfd)[0] =
                                                ((VPFX_tmpBfd)[0] +
                                                 ((shB1)[((allidx * 3) + 0)] *
                                                  ((VPFX_f0_x2)[((xyzx * 1) +
                                                                 0)] *
                                                   (((VPFX_if1_y2)[((xyzy * 1) +
                                                                    0)] -
                                                     (VPFX_if1_y1)[((xyzy * 1) +
                                                                    0)]) *
                                                    (VPFX_f1_z1)[((xyzz * 1) +
                                                                  0)])))));
                                         }
                                       }
                                     }
                                   }
                                 }
                               }
                               (VPFX_tmpBfd)[0];
                             }))) +
                           (0.00000000000000000e+00 + ({
                              __m256d VPFX_tmpBfd[1];
                              double *tmpBfd = VPFX_tmpBfd;

                              ((VPFX_tmpBfd)[0] =
                                   (0.00000000000000000e+00 - ((__m256d){})));
                              {
                                long xyzz;

                                for ((xyzz = 0); (xyzz < 5);
                                     (xyzz = (xyzz + 1))) {
                                  {
                                    long xyzy;

                                    for ((xyzy = 0); (xyzy < 5);
                                         (xyzy = (xyzy + 1))) {
                                      {
                                        long xyzx;

                                        for ((xyzx = 0); (xyzx < 5);
                                             (xyzx = (xyzx + 1))) {
                                          int allidx;

                                          (allidx =
                                               (xyzx +
                                                (5 * (xyzy + (5 * xyzz)))));
                                          ((VPFX_tmpBfd)[0] =
                                               ((VPFX_tmpBfd)[0] +
                                                ((shB1)[((allidx * 3) + 1)] *
                                                 ((VPFX_f0_y1)[((xyzy * 1) +
                                                                0)] *
                                                  (((VPFX_if1_x2)[((xyzx * 1) +
                                                                   0)] -
                                                    (VPFX_if1_x1)[((xyzx * 1) +
                                                                   0)]) *
                                                   (VPFX_f1_z1)[((xyzz * 1) +
                                                                 0)])))));
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              (VPFX_tmpBfd)[0];
                            }))))) *
                        DT))))));
              __m256d VPFX_z2[1];
              double *z2 = VPFX_z2;

              ((VPFX_z2)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_z0)[0]) +
                     (2.00000000000000000e+00 * (VPFX_z1)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_Z * DELTA_Z)); }) *
                     (QE_MASS * (Deltat * ((VPFX_allincfvz)[0] +
                                           (-1.00000000000000000e+00 *
                                            (VPFX_iBz)[0])))))));
              __m256d VPFX_rz2[1];
              double *rz2 = VPFX_rz2;

              ((VPFX_rz2)[0] = (((VPFX_z2)[0] - (ZO - zmid)) -
                                _mm256_floor_pd(((VPFX_z2)[0] - (ZO - zmid)))));
              __m256d VPFX_dixz2[1];
              double *dixz2 = VPFX_dixz2;

              ((VPFX_dixz2)[0] =
                   (_mm256_floor_pd(((VPFX_z2)[0] - (ZO - zmid))) - Midz));
              __m256d VPFX_f0_z2[5];
              double(*f0_z2)[4];
              (f0_z2 = VPFX_f0_z2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_z2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_z2)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz2)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz2)[0])))));
              ((VPFX_f0_z2)[((0 * 1) + 0)] =
                   (((VPFX_f0_z2)[((0 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((1 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0])))))));
              ((VPFX_f0_z2)[((1 * 1) + 0)] =
                   (((VPFX_f0_z2)[((1 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((2 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rz2)[0]) +
                      ((VPFX_rz2)[0] * (VPFX_rz2)[0])))));
              ((VPFX_f0_z2)[((2 * 1) + 0)] =
                   (((VPFX_f0_z2)[((2 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((3 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz2)[0] * (VPFX_rz2)[0])));
              ((VPFX_f0_z2)[((3 * 1) + 0)] =
                   (((VPFX_f0_z2)[((3 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((4 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((4 * 1) + 0)] =
                   ((VPFX_f0_z2)[((4 * 1) + 0)] *
                    ((VPFX_dixz2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_z2[5];
              double(*f1_z2)[4];
              (f1_z2 = VPFX_f1_z2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_z2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_z2)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz2)[0]))));
              ((VPFX_f1_z2)[((0 * 1) + 0)] =
                   (((VPFX_f1_z2)[((0 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z2)[((1 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f1_z2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz2)[0])))));
              ((VPFX_f1_z2)[((1 * 1) + 0)] =
                   (((VPFX_f1_z2)[((1 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z2)[((2 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f1_z2)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rz2)[0]));
              ((VPFX_f1_z2)[((2 * 1) + 0)] =
                   (((VPFX_f1_z2)[((2 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z2)[((3 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f1_z2)[((3 * 1) + 0)] =
                   ((VPFX_f1_z2)[((3 * 1) + 0)] *
                    ((VPFX_dixz2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_z2[5];
              double(*if1_z2)[4];
              (if1_z2 = VPFX_if1_z2);
              ((VPFX_if1_z2)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z2)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z2)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z2)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z2)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz2)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz2)[0]))))));
              ((VPFX_if1_z2)[((0 * 1) + 0)] =
                   (((VPFX_if1_z2)[((0 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z2)[((1 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_if1_z2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rz2)[0] * (VPFX_rz2)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rz2)[0]) +
                       ((VPFX_rz2)[0] * (VPFX_rz2)[0]))))));
              ((VPFX_if1_z2)[((1 * 1) + 0)] =
                   (((VPFX_if1_z2)[((1 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z2)[((2 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_if1_z2)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz2)[0] * (VPFX_rz2)[0])));
              ((VPFX_if1_z2)[((2 * 1) + 0)] =
                   (((VPFX_if1_z2)[((2 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z2)[((3 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_if1_z2)[((3 * 1) + 0)] =
                   ((VPFX_if1_z2)[((3 * 1) + 0)] *
                    ((VPFX_dixz2)[0] + 1.00000000000000000e+00)));
              ((VPFX_iBz)[0] = (0.00000000000000000e+00 - ((__m256d){})));
              __m256d VPFX_z3[1];
              double *z3 = VPFX_z3;

              ((VPFX_z3)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_z1)[0]) +
                     (2.00000000000000000e+00 * (VPFX_z2)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_Z * DELTA_Z)); }) *
                     (-1 * (Deltat * (QE_MASS * (VPFX_iBz)[0]))))));
              __m256d VPFX_rz3[1];
              double *rz3 = VPFX_rz3;

              ((VPFX_rz3)[0] = (((VPFX_z3)[0] - (ZO - zmid)) -
                                _mm256_floor_pd(((VPFX_z3)[0] - (ZO - zmid)))));
              __m256d VPFX_dixz3[1];
              double *dixz3 = VPFX_dixz3;

              ((VPFX_dixz3)[0] =
                   (_mm256_floor_pd(((VPFX_z3)[0] - (ZO - zmid))) - Midz));
              __m256d VPFX_f0_z3[5];
              double(*f0_z3)[4];
              (f0_z3 = VPFX_f0_z3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_z3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_z3)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz3)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz3)[0])))));
              ((VPFX_f0_z3)[((0 * 1) + 0)] =
                   (((VPFX_f0_z3)[((0 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((1 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0])))))));
              ((VPFX_f0_z3)[((1 * 1) + 0)] =
                   (((VPFX_f0_z3)[((1 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((2 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rz3)[0]) +
                      ((VPFX_rz3)[0] * (VPFX_rz3)[0])))));
              ((VPFX_f0_z3)[((2 * 1) + 0)] =
                   (((VPFX_f0_z3)[((2 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((3 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz3)[0] * (VPFX_rz3)[0])));
              ((VPFX_f0_z3)[((3 * 1) + 0)] =
                   (((VPFX_f0_z3)[((3 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((4 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((4 * 1) + 0)] =
                   ((VPFX_f0_z3)[((4 * 1) + 0)] *
                    ((VPFX_dixz3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_z3[5];
              double(*f1_z3)[4];
              (f1_z3 = VPFX_f1_z3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_z3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_z3)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz3)[0]))));
              ((VPFX_f1_z3)[((0 * 1) + 0)] =
                   (((VPFX_f1_z3)[((0 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z3)[((1 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f1_z3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz3)[0])))));
              ((VPFX_f1_z3)[((1 * 1) + 0)] =
                   (((VPFX_f1_z3)[((1 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z3)[((2 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f1_z3)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rz3)[0]));
              ((VPFX_f1_z3)[((2 * 1) + 0)] =
                   (((VPFX_f1_z3)[((2 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z3)[((3 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f1_z3)[((3 * 1) + 0)] =
                   ((VPFX_f1_z3)[((3 * 1) + 0)] *
                    ((VPFX_dixz3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_z3[5];
              double(*if1_z3)[4];
              (if1_z3 = VPFX_if1_z3);
              ((VPFX_if1_z3)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z3)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z3)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z3)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z3)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz3)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz3)[0]))))));
              ((VPFX_if1_z3)[((0 * 1) + 0)] =
                   (((VPFX_if1_z3)[((0 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z3)[((1 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_if1_z3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rz3)[0] * (VPFX_rz3)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rz3)[0]) +
                       ((VPFX_rz3)[0] * (VPFX_rz3)[0]))))));
              ((VPFX_if1_z3)[((1 * 1) + 0)] =
                   (((VPFX_if1_z3)[((1 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z3)[((2 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_if1_z3)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz3)[0] * (VPFX_rz3)[0])));
              ((VPFX_if1_z3)[((2 * 1) + 0)] =
                   (((VPFX_if1_z3)[((2 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z3)[((3 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_if1_z3)[((3 * 1) + 0)] =
                   ((VPFX_if1_z3)[((3 * 1) + 0)] *
                    ((VPFX_dixz3)[0] + 1.00000000000000000e+00)));
              ((VPFX_iBy)[0] =
                   ((-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        __m256d VPFX_tmpBfd[1];
                        double *tmpBfd = VPFX_tmpBfd;

                        ((VPFX_tmpBfd)[0] =
                             (0.00000000000000000e+00 - ((__m256d){})));
                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx;

                                    (allidx =
                                         (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                    ((VPFX_tmpBfd)[0] =
                                         ((VPFX_tmpBfd)[0] +
                                          ((shB1)[((allidx * 3) + 0)] *
                                           ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                            (((VPFX_if1_z2)[((xyzz * 1) + 0)] -
                                              (VPFX_if1_z1)[((xyzz * 1) + 0)]) *
                                             (VPFX_f1_y2)[((xyzy * 1) +
                                                           0)])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        (VPFX_tmpBfd)[0];
                      }))) +
                    (-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        __m256d VPFX_tmpBfd[1];
                        double *tmpBfd = VPFX_tmpBfd;

                        ((VPFX_tmpBfd)[0] =
                             (0.00000000000000000e+00 - ((__m256d){})));
                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx;

                                    (allidx =
                                         (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                    ((VPFX_tmpBfd)[0] =
                                         ((VPFX_tmpBfd)[0] +
                                          ((shB1)[((allidx * 3) + 0)] *
                                           ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                            (((VPFX_if1_z3)[((xyzz * 1) + 0)] -
                                              (VPFX_if1_z2)[((xyzz * 1) + 0)]) *
                                             (VPFX_f1_y2)[((xyzy * 1) +
                                                           0)])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        (VPFX_tmpBfd)[0];
                      })))));
              __m256d VPFX_y3[1];
              double *y3 = VPFX_y3;

              ((VPFX_y3)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_y1)[0]) +
                     (2.00000000000000000e+00 * (VPFX_y2)[0])) +
                    ((TX0 * TX0) *
                     ((-1 * (Deltat * (QE_MASS * (VPFX_iBy)[0]))) * ({
                        (1.00000000000000000e+00 /
                         (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
                          ((2.00000000000000000e+00 *
                            ((DELTA_Y * DELTA_Y) * (TX0 * (VPFX_x2)[0]))) +
                           ((DELTA_Y * DELTA_Y) *
                            ((VPFX_x2)[0] * (VPFX_x2)[0])))));
                      })))));
              __m256d VPFX_ry3[1];
              double *ry3 = VPFX_ry3;

              ((VPFX_ry3)[0] = (((VPFX_y3)[0] - YO) -
                                _mm256_floor_pd(((VPFX_y3)[0] - YO))));
              __m256d VPFX_dixy3[1];
              double *dixy3 = VPFX_dixy3;

              ((VPFX_dixy3)[0] = (_mm256_floor_pd(((VPFX_y3)[0] - YO)) - Midy));
              __m256d VPFX_f0_y3[5];
              double(*f0_y3)[4];
              (f0_y3 = VPFX_f0_y3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_y3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_y3)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry3)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry3)[0])))));
              ((VPFX_f0_y3)[((0 * 1) + 0)] =
                   (((VPFX_f0_y3)[((0 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((1 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0])))))));
              ((VPFX_f0_y3)[((1 * 1) + 0)] =
                   (((VPFX_f0_y3)[((1 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((2 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_ry3)[0]) +
                      ((VPFX_ry3)[0] * (VPFX_ry3)[0])))));
              ((VPFX_f0_y3)[((2 * 1) + 0)] =
                   (((VPFX_f0_y3)[((2 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((3 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry3)[0] * (VPFX_ry3)[0])));
              ((VPFX_f0_y3)[((3 * 1) + 0)] =
                   (((VPFX_f0_y3)[((3 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((4 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((4 * 1) + 0)] =
                   ((VPFX_f0_y3)[((4 * 1) + 0)] *
                    ((VPFX_dixy3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_y3[5];
              double(*f1_y3)[4];
              (f1_y3 = VPFX_f1_y3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_y3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_y3)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry3)[0]))));
              ((VPFX_f1_y3)[((0 * 1) + 0)] =
                   (((VPFX_f1_y3)[((0 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y3)[((1 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f1_y3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry3)[0])))));
              ((VPFX_f1_y3)[((1 * 1) + 0)] =
                   (((VPFX_f1_y3)[((1 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y3)[((2 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f1_y3)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_ry3)[0]));
              ((VPFX_f1_y3)[((2 * 1) + 0)] =
                   (((VPFX_f1_y3)[((2 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y3)[((3 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f1_y3)[((3 * 1) + 0)] =
                   ((VPFX_f1_y3)[((3 * 1) + 0)] *
                    ((VPFX_dixy3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_y3[5];
              double(*if1_y3)[4];
              (if1_y3 = VPFX_if1_y3);
              ((VPFX_if1_y3)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y3)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y3)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y3)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y3)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry3)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry3)[0]))))));
              ((VPFX_if1_y3)[((0 * 1) + 0)] =
                   (((VPFX_if1_y3)[((0 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y3)[((1 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_if1_y3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_ry3)[0] * (VPFX_ry3)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_ry3)[0]) +
                       ((VPFX_ry3)[0] * (VPFX_ry3)[0]))))));
              ((VPFX_if1_y3)[((1 * 1) + 0)] =
                   (((VPFX_if1_y3)[((1 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y3)[((2 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_if1_y3)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry3)[0] * (VPFX_ry3)[0])));
              ((VPFX_if1_y3)[((2 * 1) + 0)] =
                   (((VPFX_if1_y3)[((2 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y3)[((3 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_if1_y3)[((3 * 1) + 0)] =
                   ((VPFX_if1_y3)[((3 * 1) + 0)] *
                    ((VPFX_dixy3)[0] + 1.00000000000000000e+00)));
              ((VPFX_iBx)[0] =
                   ((0.00000000000000000e+00 + ({
                       __m256d VPFX_tmpBfd[1];
                       double *tmpBfd = VPFX_tmpBfd;

                       ((VPFX_tmpBfd)[0] =
                            (0.00000000000000000e+00 - ((__m256d){})));
                       {
                         long xyzz;

                         for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                           {
                             long xyzy;

                             for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                               {
                                 long xyzx;

                                 for ((xyzx = 0); (xyzx < 5);
                                      (xyzx = (xyzx + 1))) {
                                   int allidx;

                                   (allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                   ((VPFX_tmpBfd)[0] =
                                        ((VPFX_tmpBfd)[0] +
                                         ((shB1)[((allidx * 3) + 1)] *
                                          ((VPFX_f0_y2)[((xyzy * 1) + 0)] *
                                           (((VPFX_if1_z2)[((xyzz * 1) + 0)] -
                                             (VPFX_if1_z1)[((xyzz * 1) + 0)]) *
                                            (VPFX_f1_x2)[((xyzx * 1) + 0)])))));
                                 }
                               }
                             }
                           }
                         }
                       }
                       (VPFX_tmpBfd)[0];
                     })) +
                    ((0.00000000000000000e+00 + ({
                        __m256d VPFX_tmpBfd[1];
                        double *tmpBfd = VPFX_tmpBfd;

                        ((VPFX_tmpBfd)[0] =
                             (0.00000000000000000e+00 - ((__m256d){})));
                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx;

                                    (allidx =
                                         (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                    ((VPFX_tmpBfd)[0] =
                                         ((VPFX_tmpBfd)[0] +
                                          ((shB1)[((allidx * 3) + 1)] *
                                           ((VPFX_f0_y2)[((xyzy * 1) + 0)] *
                                            (((VPFX_if1_z3)[((xyzz * 1) + 0)] -
                                              (VPFX_if1_z2)[((xyzz * 1) + 0)]) *
                                             (VPFX_f1_x2)[((xyzx * 1) +
                                                           0)])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        (VPFX_tmpBfd)[0];
                      })) +
                     ((-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          __m256d VPFX_tmpBfd[1];
                          double *tmpBfd = VPFX_tmpBfd;

                          ((VPFX_tmpBfd)[0] =
                               (0.00000000000000000e+00 - ((__m256d){})));
                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx;

                                      (allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                      ((VPFX_tmpBfd)[0] =
                                           ((VPFX_tmpBfd)[0] +
                                            ((shB1)[((allidx * 3) + 2)] *
                                             ((VPFX_f0_z1)[((xyzz * 1) + 0)] *
                                              (((VPFX_if1_y2)[((xyzy * 1) +
                                                               0)] -
                                                (VPFX_if1_y1)[((xyzy * 1) +
                                                               0)]) *
                                               (VPFX_f1_x2)[((xyzx * 1) +
                                                             0)])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          (VPFX_tmpBfd)[0];
                        }))) +
                      (-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          __m256d VPFX_tmpBfd[1];
                          double *tmpBfd = VPFX_tmpBfd;

                          ((VPFX_tmpBfd)[0] =
                               (0.00000000000000000e+00 - ((__m256d){})));
                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx;

                                      (allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                      ((VPFX_tmpBfd)[0] =
                                           ((VPFX_tmpBfd)[0] +
                                            ((shB1)[((allidx * 3) + 2)] *
                                             ((VPFX_f0_z3)[((xyzz * 1) + 0)] *
                                              (((VPFX_if1_y3)[((xyzy * 1) +
                                                               0)] -
                                                (VPFX_if1_y2)[((xyzy * 1) +
                                                               0)]) *
                                               (VPFX_f1_x2)[((xyzx * 1) +
                                                             0)])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          (VPFX_tmpBfd)[0];
                        })))))));
              __m256d VPFX_x3[1];
              double *x3 = VPFX_x3;

              ((VPFX_x3)[0] =
                   ((({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (({ (1.00000000000000000e+00 / (TX0 * TX0)); }) *
                      ((-1.00000000000000000e+00 *
                        ((DELTA_X * DELTA_X) * ((TX0 * TX0) * (VPFX_x1)[0]))) +
                       ((2.00000000000000000e+00 *
                         ((DELTA_X * DELTA_X) * ((TX0 * TX0) * (VPFX_x2)[0]))) +
                        (((((DELTA_Y * DELTA_Y) * TX0) +
                           ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0])) *
                          ((VPFX_y1)[0] * (VPFX_y1)[0])) +
                         ((((-2.00000000000000000e+00 *
                             ((DELTA_Y * DELTA_Y) * TX0)) +
                            (-2.00000000000000000e+00 *
                             ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                           ((VPFX_y1)[0] * (VPFX_y2)[0])) +
                          ((((2.00000000000000000e+00 *
                              ((DELTA_Y * DELTA_Y) * TX0)) +
                             (2.00000000000000000e+00 *
                              ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                            ((VPFX_y2)[0] * (VPFX_y2)[0])) +
                           ((((-2.00000000000000000e+00 *
                               ((DELTA_Y * DELTA_Y) * TX0)) +
                              (-2.00000000000000000e+00 *
                               ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                             ((VPFX_y2)[0] * (VPFX_y3)[0])) +
                            ((((DELTA_Y * DELTA_Y) * TX0) +
                              ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0])) *
                             ((VPFX_y3)[0] * (VPFX_y3)[0])))))))))) +
                    (({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (-1 * (Deltat * (QE_MASS * (VPFX_iBx)[0]))))));
              __m256d VPFX_rx3[1];
              double *rx3 = VPFX_rx3;

              ((VPFX_rx3)[0] = (((VPFX_x3)[0] - XO) -
                                _mm256_floor_pd(((VPFX_x3)[0] - XO))));
              __m256d VPFX_dixx3[1];
              double *dixx3 = VPFX_dixx3;

              ((VPFX_dixx3)[0] = (_mm256_floor_pd(((VPFX_x3)[0] - XO)) - Midx));
              __m256d VPFX_f0_x3[5];
              double(*f0_x3)[4];
              (f0_x3 = VPFX_f0_x3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_x3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_x3)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx3)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx3)[0])))));
              ((VPFX_f0_x3)[((0 * 1) + 0)] =
                   (((VPFX_f0_x3)[((0 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((1 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0])))))));
              ((VPFX_f0_x3)[((1 * 1) + 0)] =
                   (((VPFX_f0_x3)[((1 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((2 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rx3)[0]) +
                      ((VPFX_rx3)[0] * (VPFX_rx3)[0])))));
              ((VPFX_f0_x3)[((2 * 1) + 0)] =
                   (((VPFX_f0_x3)[((2 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((3 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx3)[0] * (VPFX_rx3)[0])));
              ((VPFX_f0_x3)[((3 * 1) + 0)] =
                   (((VPFX_f0_x3)[((3 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((4 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((4 * 1) + 0)] =
                   ((VPFX_f0_x3)[((4 * 1) + 0)] *
                    ((VPFX_dixx3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_x3[5];
              double(*f1_x3)[4];
              (f1_x3 = VPFX_f1_x3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_x3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_x3)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx3)[0]))));
              ((VPFX_f1_x3)[((0 * 1) + 0)] =
                   (((VPFX_f1_x3)[((0 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x3)[((1 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f1_x3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx3)[0])))));
              ((VPFX_f1_x3)[((1 * 1) + 0)] =
                   (((VPFX_f1_x3)[((1 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x3)[((2 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f1_x3)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rx3)[0]));
              ((VPFX_f1_x3)[((2 * 1) + 0)] =
                   (((VPFX_f1_x3)[((2 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x3)[((3 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f1_x3)[((3 * 1) + 0)] =
                   ((VPFX_f1_x3)[((3 * 1) + 0)] *
                    ((VPFX_dixx3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_x3[5];
              double(*if1_x3)[4];
              (if1_x3 = VPFX_if1_x3);
              ((VPFX_if1_x3)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x3)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x3)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x3)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x3)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx3)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx3)[0]))))));
              ((VPFX_if1_x3)[((0 * 1) + 0)] =
                   (((VPFX_if1_x3)[((0 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x3)[((1 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_if1_x3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rx3)[0] * (VPFX_rx3)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rx3)[0]) +
                       ((VPFX_rx3)[0] * (VPFX_rx3)[0]))))));
              ((VPFX_if1_x3)[((1 * 1) + 0)] =
                   (((VPFX_if1_x3)[((1 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x3)[((2 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_if1_x3)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx3)[0] * (VPFX_rx3)[0])));
              ((VPFX_if1_x3)[((2 * 1) + 0)] =
                   (((VPFX_if1_x3)[((2 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x3)[((3 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_if1_x3)[((3 * 1) + 0)] =
                   ((VPFX_if1_x3)[((3 * 1) + 0)] *
                    ((VPFX_dixx3)[0] + 1.00000000000000000e+00)));
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_x2)[((xyzx * 1) + 0)] -
                                        (VPFX_if1_x1)[((xyzx * 1) + 0)]) *
                                       ((VPFX_f0_y1)[((xyzy * 1) + 0)] *
                                        (VPFX_f0_z1)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 0)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 0)] +
                                        (((grid_geo_x *
                                           ((Tori_X0 /
                                             (Tori_X0 +
                                              (XO + (bBidx + xyzx)))) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 0)] =
                                       ((shJ0)[((allidx * 3) + 0)] +
                                        ((grid_geo_x *
                                          ((Tori_X0 /
                                            (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_y2)[((xyzy * 1) + 0)] -
                                        (VPFX_if1_y1)[((xyzy * 1) + 0)]) *
                                       ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                        (VPFX_f0_z1)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 1)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 1)] +
                                        (((grid_geo_y *
                                           (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                             Tori_X0) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 1)] =
                                       ((shJ0)[((allidx * 3) + 1)] +
                                        ((grid_geo_y *
                                          (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                            Tori_X0) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_z3)[((xyzz * 1) + 0)] -
                                        (VPFX_if1_z1)[((xyzz * 1) + 0)]) *
                                       ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                        (VPFX_f0_y2)[((xyzy * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 2)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 2)] +
                                        (((grid_geo_z *
                                           ((Tori_X0 /
                                             (Tori_X0 +
                                              (XO + (bBidx + xyzx)))) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 2)] =
                                       ((shJ0)[((allidx * 3) + 2)] +
                                        ((grid_geo_z *
                                          ((Tori_X0 /
                                            (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_y3)[((xyzy * 1) + 0)] -
                                        (VPFX_if1_y2)[((xyzy * 1) + 0)]) *
                                       ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                        (VPFX_f0_z3)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 1)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 1)] +
                                        (((grid_geo_y *
                                           (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                             Tori_X0) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 1)] =
                                       ((shJ0)[((allidx * 3) + 1)] +
                                        ((grid_geo_y *
                                          (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                            Tori_X0) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_x3)[((xyzx * 1) + 0)] -
                                        (VPFX_if1_x2)[((xyzx * 1) + 0)]) *
                                       ((VPFX_f0_y3)[((xyzy * 1) + 0)] *
                                        (VPFX_f0_z3)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 0)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 0)] +
                                        (((grid_geo_x *
                                           ((Tori_X0 /
                                             (Tori_X0 +
                                              (XO + (bBidx + xyzx)))) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 0)] =
                                       ((shJ0)[((allidx * 3) + 0)] +
                                        ((grid_geo_x *
                                          ((Tori_X0 /
                                            (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              __m256d VPFX_newvx[1];
              double *newvx = VPFX_newvx;

              ((VPFX_newvx)[0] = (((VPFX_x3)[0] - (VPFX_x2)[0]) / DT));
              __m256d VPFX_newvy[1];
              double *newvy = VPFX_newvy;

              ((VPFX_newvy)[0] = (((VPFX_y3)[0] - (VPFX_y2)[0]) / DT));
              __m256d VPFX_newvz[1];
              double *newvz = VPFX_newvz;

              ((VPFX_newvz)[0] = (((VPFX_z3)[0] - (VPFX_z2)[0]) / DT));
              __m256d VPFX_newxx[1];
              double *newxx = VPFX_newxx;

              ((VPFX_newxx)[0] = ((VPFX_x3)[0] - XO));
              __m256d VPFX_newxy[1];
              double *newxy = VPFX_newxy;

              ((VPFX_newxy)[0] = ((VPFX_y3)[0] - YO));
              __m256d VPFX_newxz[1];
              double *newxz = VPFX_newxz;

              ((VPFX_newxz)[0] = (((VPFX_z3)[0] + zmid) - ZO));
              ((VPFX_newxx)[0] = ((VPFX_newxx)[0] + 5.00000000000000000e-01));
              ((VPFX_newxy)[0] = ((VPFX_newxy)[0] + 5.00000000000000000e-01));
              ((VPFX_newxz)[0] = ((VPFX_newxz)[0] + 5.00000000000000000e-01));
              ((VPFX_local_particle_head)[((0 * 1) + 0)] = (VPFX_newxx)[0]);
              ((VPFX_local_particle_head)[((1 * 1) + 0)] = (VPFX_newxy)[0]);
              ((VPFX_local_particle_head)[((2 * 1) + 0)] = (VPFX_newxz)[0]);
              ((VPFX_local_particle_head)[((3 * 1) + 0)] = (VPFX_newvx)[0]);
              ((VPFX_local_particle_head)[((4 * 1) + 0)] = (VPFX_newvy)[0]);
              ((VPFX_local_particle_head)[((5 * 1) + 0)] = (VPFX_newvz)[0]);
            }
            {
              int stmpg1;

#pragma clang loop vectorize(disable)
              for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
                {
                  {
                    int inner_var_G0;

                    for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                         (inner_var_G0 = (inner_var_G0 + 1))) {
                      if (((g_inner + inner_var_G0) < load0)) {
                        ((particle_head_general)[(
                             stmpg1 + ((g_inner + inner_var_G0) * 6))] =
                             ((local_particle_head)[stmpg1])[inner_var_G0]);

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
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long xii;

                  for ((xii = 0); (xii < 15); (xii = (xii + 1))) {
                    {
                      long i;

                      for ((i = 0); (i < 4); (i = (i + 1))) {
                        ((shJ0)[(total_idx + xii)] =
                             ((shJ0)[(total_idx + xii)] +
                              (shJ_incf)[(((total_idx + xii) * 4) + i)]));
                      }
                    }
                  }
                }
                {
                  long Gll_P9918;

                  for ((Gll_P9918 = 0); (Gll_P9918 < (3 * 5));
                       (Gll_P9918 = (Gll_P9918 + 1))) {
                    (((FoutJ + ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                     ((YLEN + (2 * ovlp)) *
                                                      (ZLEN + (2 * ovlp)))))) +
                                (0 + (num_ele * ((bBidx + ovlp) +
                                                 ((XLEN + (2 * ovlp)) *
                                                  (((xyzy + bBidy) + ovlp) +
                                                   ((YLEN + (2 * ovlp)) *
                                                    ((xyzz + bBidz) +
                                                     ovlp))))))))))[Gll_P9918] =
                         ((shJ0 + total_idx))[Gll_P9918]);
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP13;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP13:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP14;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP14:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 1
void c_geo_nr_Bfield_pushJ_nopush_par_vlo_scmc_kernel(
    double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, int *xoffset,
    int *yoffset, int *zoffset, double *fieldE, double *fieldB, double *fieldB1,
    double *FoutJ, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
    int num_ele, long grid_cache_len, long cu_cache_length, double DELTA_X,
    double DELTA_Y, double DELTA_Z, double Mass0, double Charge0, double Deltat,
    double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid,
    long scmc_internal_g_idy, long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  void *call_stack_pointer[4];
  int cur_frame_num = 0;

  long numgrid = (XLEN * (YLEN * ZLEN));

  long numallgrid = ((XLEN + (ovlp + ovlp)) *
                     ((YLEN + (ovlp + ovlp)) * (ZLEN + (ovlp + ovlp))));

  long blk_len = (numallgrid * num_ele);

  long blk_len_x = (XLEN + (ovlp + ovlp));

  long blk_len_y = (YLEN + (ovlp + ovlp));

  long blk_len_z = (ZLEN + (ovlp + ovlp));

  long numgrid_cu = (numgrid * numvec);

  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];

  int call_sort = 1;

  int cr_allgid = 0;

  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  double shE0[375];
  double shB0[375];
  double shB1[375];
  double shJ0[375];
  __m256d shJ_incf_simdp[375];
  double *shJ_incf = shJ_incf_simdp;

  double *particle_head_general;

  int load0;

  int new_load;

  int global_idy_tmp;

  goto beg_prog;
core_fun:

{
  int __idy = global_idy_tmp;

  if (load0) {
    double TX0 = Tori_X0;

    long i_idy = __idy;

    double XO = (xoffset)[i_idy];

    double YO = (yoffset)[i_idy];

    double ZO = (zoffset)[i_idy];

    double Midx =
        ((use_local_particle_position) ? (floor((particle_head_general)[0]))
                                       : (mdx));

    double Midy =
        ((use_local_particle_position) ? (floor((particle_head_general)[1]))
                                       : (mdy));

    double Midz =
        ((use_local_particle_position) ? (floor((particle_head_general)[2]))
                                       : (mdz));

    if ((Midx < 0)) {
      (Midx = 0);

    } else {
      0;
    }

    if ((Midy < 0)) {
      (Midy = 0);

    } else {
      0;
    }

    if ((Midz < 0)) {
      (Midz = 0);

    } else {
      0;
    }

    if ((Midx > (XLEN - 1))) {
      (Midx = (XLEN - 1));

    } else {
      0;
    }

    if ((Midy > (YLEN - 1))) {
      (Midy = (YLEN - 1));

    } else {
      0;
    }

    if ((Midz > (ZLEN - 1))) {
      (Midz = (ZLEN - 1));

    } else {
      0;
    }

    int iMidx = Midx;

    int iMidy = Midy;

    int iMidz = Midz;

    int Bidx = (Midx - 1);

    int Bidy = (Midy - 1);

    int Bidz = (Midz - 1);

    int bBidx = (Midx - 2);

    int bBidy = (Midy - 2);

    int bBidz = (Midz - 2);

    double QE_MASS = (Charge0 / Mass0);

    double grid_geo_x = (DELTA_X / (DELTA_Y * DELTA_Z));

    double grid_geo_y = (DELTA_Y / (DELTA_Z * DELTA_X));

    double grid_geo_z = (DELTA_Z / (DELTA_X * DELTA_Y));

    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long MYGEN667 = 0;

                  for (0; (MYGEN667 < (3 * 5));
                       (MYGEN667 = (MYGEN667 + __xlen))) {
                    int ridx = (MYGEN667 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shE0 + total_idx))[ridx] =
                           ((fieldE +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN669 = 0;

                  for (0; (MYGEN669 < (3 * 5));
                       (MYGEN669 = (MYGEN669 + __xlen))) {
                    int ridx = (MYGEN669 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB0 + total_idx))[ridx] =
                           ((fieldB +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN671 = 0;

                  for (0; (MYGEN671 < (3 * 5));
                       (MYGEN671 = (MYGEN671 + __xlen))) {
                    int ridx = (MYGEN671 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shB1 + total_idx))[ridx] =
                           ((fieldB1 +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long MYGEN673 = 0;

                  for (0; (MYGEN673 < (3 * 5));
                       (MYGEN673 = (MYGEN673 + __xlen))) {
                    int ridx = (MYGEN673 + __idx);

                    if ((ridx < (3 * 5))) {
                      (((shJ0 + total_idx))[ridx] =
                           ((FoutJ +
                             ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx]);

                    } else {
                      0;
                    }
                  }
                }
                {
                  long xtmp;

                  for ((xtmp = 0); (xtmp < (15 * 4)); (xtmp = (xtmp + 1))) {
                    ((shJ_incf)[((total_idx * 4) + xtmp)] = 0);
                  }
                }
              }
            }
          }
        }
      }
    }
    {
      double simd_mask = 1;

      {
        long g_inner;

        for ((g_inner = 0); (g_inner < load0); (g_inner = (g_inner + 4))) {
          __m256d VPFX_simd_mask[1];
          double *simd_mask = VPFX_simd_mask;

          {
            int inner_var_G0;

            for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                 (inner_var_G0 = (inner_var_G0 + 1))) {
              ((simd_mask)[inner_var_G0] = ((g_inner + inner_var_G0) < load0));
            }
          }
          {
            __m256d VPFX_local_particle_head[6];
            double(*local_particle_head)[4];
            (local_particle_head = VPFX_local_particle_head);
            {
              int stmpg1;

#pragma clang loop vectorize(disable)
              for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
                {
                  {
                    int inner_var_G0;

                    for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                         (inner_var_G0 = (inner_var_G0 + 1))) {
                      (((local_particle_head)[stmpg1])[inner_var_G0] =
                           (particle_head_general)[(
                               stmpg1 + (((((g_inner + inner_var_G0) < load0))
                                              ? ((g_inner + inner_var_G0))
                                              : ((load0 - 1))) *
                                         6))]);
                    }
                  }
                }
              }
            }
            __m256d VPFX_xx1[1];
            double *xx1 = VPFX_xx1;

            ((VPFX_xx1)[0] = (VPFX_local_particle_head)[((0 * 1) + 0)]);
            __m256d VPFX_xy1[1];
            double *xy1 = VPFX_xy1;

            ((VPFX_xy1)[0] = (VPFX_local_particle_head)[((1 * 1) + 0)]);
            __m256d VPFX_xz1[1];
            double *xz1 = VPFX_xz1;

            ((VPFX_xz1)[0] = (VPFX_local_particle_head)[((2 * 1) + 0)]);
            __m256d VPFX_vx0[1];
            double *vx0 = VPFX_vx0;

            ((VPFX_vx0)[0] = (VPFX_local_particle_head)[((3 * 1) + 0)]);
            __m256d VPFX_vy0[1];
            double *vy0 = VPFX_vy0;

            ((VPFX_vy0)[0] = (VPFX_local_particle_head)[((4 * 1) + 0)]);
            __m256d VPFX_vz0[1];
            double *vz0 = VPFX_vz0;

            ((VPFX_vz0)[0] = (VPFX_local_particle_head)[((5 * 1) + 0)]);
            ((VPFX_xx1)[0] = ((VPFX_xx1)[0] + -5.00000000000000000e-01));
            ((VPFX_xy1)[0] = ((VPFX_xy1)[0] + -5.00000000000000000e-01));
            ((VPFX_xz1)[0] = ((VPFX_xz1)[0] + -5.00000000000000000e-01));
            __m256d VPFX_rx[1];
            double *rx = VPFX_rx;

            ((VPFX_rx)[0] = ((VPFX_xx1)[0] - Midx));
            __m256d VPFX_ry[1];
            double *ry = VPFX_ry;

            ((VPFX_ry)[0] = ((VPFX_xy1)[0] - Midy));
            __m256d VPFX_rz[1];
            double *rz = VPFX_rz;

            ((VPFX_rz)[0] = ((VPFX_xz1)[0] - Midz));
            __m256d VPFX_xx0[1];
            double *xx0 = VPFX_xx0;

            ((VPFX_xx0)[0] = ((VPFX_xx1)[0] - (Deltat * (VPFX_vx0)[0])));
            __m256d VPFX_xy0[1];
            double *xy0 = VPFX_xy0;

            ((VPFX_xy0)[0] = ((VPFX_xy1)[0] - (Deltat * (VPFX_vy0)[0])));
            __m256d VPFX_xz0[1];
            double *xz0 = VPFX_xz0;

            ((VPFX_xz0)[0] = ((VPFX_xz1)[0] - (Deltat * (VPFX_vz0)[0])));
            __m256d VPFX_Midx0[1];
            double *Midx0 = VPFX_Midx0;

            ((VPFX_Midx0)[0] = _mm256_floor_pd((VPFX_xx0)[0]));
            __m256d VPFX_Midx1[1];
            double *Midx1 = VPFX_Midx1;

            ((VPFX_Midx1)[0] = _mm256_floor_pd((VPFX_xx1)[0]));
            __m256d VPFX_Midy0[1];
            double *Midy0 = VPFX_Midy0;

            ((VPFX_Midy0)[0] = _mm256_floor_pd((VPFX_xy0)[0]));
            __m256d VPFX_Midy1[1];
            double *Midy1 = VPFX_Midy1;

            ((VPFX_Midy1)[0] = _mm256_floor_pd((VPFX_xy1)[0]));
            __m256d VPFX_Midz0[1];
            double *Midz0 = VPFX_Midz0;

            ((VPFX_Midz0)[0] = _mm256_floor_pd((VPFX_xz0)[0]));
            __m256d VPFX_Midz1[1];
            double *Midz1 = VPFX_Midz1;

            ((VPFX_Midz1)[0] = _mm256_floor_pd((VPFX_xz1)[0]));
            __m256d VPFX_rx0[1];
            double *rx0 = VPFX_rx0;

            ((VPFX_rx0)[0] = ((VPFX_xx0)[0] - (VPFX_Midx0)[0]));
            __m256d VPFX_rx1[1];
            double *rx1 = VPFX_rx1;

            ((VPFX_rx1)[0] = ((VPFX_xx1)[0] - (VPFX_Midx1)[0]));
            __m256d VPFX_ry0[1];
            double *ry0 = VPFX_ry0;

            ((VPFX_ry0)[0] = ((VPFX_xy0)[0] - (VPFX_Midy0)[0]));
            __m256d VPFX_ry1[1];
            double *ry1 = VPFX_ry1;

            ((VPFX_ry1)[0] = ((VPFX_xy1)[0] - (VPFX_Midy1)[0]));
            __m256d VPFX_rz0[1];
            double *rz0 = VPFX_rz0;

            ((VPFX_rz0)[0] = ((VPFX_xz0)[0] - (VPFX_Midz0)[0]));
            __m256d VPFX_rz1[1];
            double *rz1 = VPFX_rz1;

            ((VPFX_rz1)[0] = ((VPFX_xz1)[0] - (VPFX_Midz1)[0]));
            __m256d VPFX_dixx0[1];
            double *dixx0 = VPFX_dixx0;

            ((VPFX_dixx0)[0] = ((VPFX_Midx0)[0] - Midx));
            __m256d VPFX_dixx1[1];
            double *dixx1 = VPFX_dixx1;

            ((VPFX_dixx1)[0] = ((VPFX_Midx1)[0] - Midx));
            __m256d VPFX_dixy0[1];
            double *dixy0 = VPFX_dixy0;

            ((VPFX_dixy0)[0] = ((VPFX_Midy0)[0] - Midy));
            __m256d VPFX_dixy1[1];
            double *dixy1 = VPFX_dixy1;

            ((VPFX_dixy1)[0] = ((VPFX_Midy1)[0] - Midy));
            __m256d VPFX_dixz0[1];
            double *dixz0 = VPFX_dixz0;

            ((VPFX_dixz0)[0] = ((VPFX_Midz0)[0] - Midz));
            __m256d VPFX_dixz1[1];
            double *dixz1 = VPFX_dixz1;

            ((VPFX_dixz1)[0] = ((VPFX_Midz1)[0] - Midz));
            __m256d VPFX_f0_x0[5];
            double(*f0_x0)[4];
            (f0_x0 = VPFX_f0_x0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_x0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_x0)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx0)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx0)[0])))));
            ((VPFX_f0_x0)[((0 * 1) + 0)] =
                 (((VPFX_f0_x0)[((0 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((1 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0])))))));
            ((VPFX_f0_x0)[((1 * 1) + 0)] =
                 (((VPFX_f0_x0)[((1 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((2 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rx0)[0]) +
                    ((VPFX_rx0)[0] * (VPFX_rx0)[0])))));
            ((VPFX_f0_x0)[((2 * 1) + 0)] =
                 (((VPFX_f0_x0)[((2 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((3 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx0)[0] * (VPFX_rx0)[0])));
            ((VPFX_f0_x0)[((3 * 1) + 0)] =
                 (((VPFX_f0_x0)[((3 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x0)[((4 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f0_x0)[((4 * 1) + 0)] =
                 ((VPFX_f0_x0)[((4 * 1) + 0)] *
                  ((VPFX_dixx0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_x0[5];
            double(*f1_x0)[4];
            (f1_x0 = VPFX_f1_x0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_x0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_x0)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rx0)[0]))));
            ((VPFX_f1_x0)[((0 * 1) + 0)] =
                 (((VPFX_f1_x0)[((0 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x0)[((1 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f1_x0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx0)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx0)[0])))));
            ((VPFX_f1_x0)[((1 * 1) + 0)] =
                 (((VPFX_f1_x0)[((1 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x0)[((2 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f1_x0)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rx0)[0]));
            ((VPFX_f1_x0)[((2 * 1) + 0)] =
                 (((VPFX_f1_x0)[((2 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x0)[((3 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_f1_x0)[((3 * 1) + 0)] =
                 ((VPFX_f1_x0)[((3 * 1) + 0)] *
                  ((VPFX_dixx0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_x0[5];
            double(*if1_x0)[4];
            (if1_x0 = VPFX_if1_x0);
            ((VPFX_if1_x0)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x0)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x0)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x0)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x0)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx0)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx0)[0]))))));
            ((VPFX_if1_x0)[((0 * 1) + 0)] =
                 (((VPFX_if1_x0)[((0 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x0)[((1 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_if1_x0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rx0)[0] * (VPFX_rx0)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rx0)[0]) +
                     ((VPFX_rx0)[0] * (VPFX_rx0)[0]))))));
            ((VPFX_if1_x0)[((1 * 1) + 0)] =
                 (((VPFX_if1_x0)[((1 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x0)[((2 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_if1_x0)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx0)[0] * (VPFX_rx0)[0])));
            ((VPFX_if1_x0)[((2 * 1) + 0)] =
                 (((VPFX_if1_x0)[((2 * 1) + 0)] *
                   ((VPFX_dixx0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x0)[((3 * 1) + 0)] * -((VPFX_dixx0)[0]))));
            ((VPFX_if1_x0)[((3 * 1) + 0)] =
                 ((VPFX_if1_x0)[((3 * 1) + 0)] *
                  ((VPFX_dixx0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_y0[5];
            double(*f0_y0)[4];
            (f0_y0 = VPFX_f0_y0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_y0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_y0)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry0)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry0)[0])))));
            ((VPFX_f0_y0)[((0 * 1) + 0)] =
                 (((VPFX_f0_y0)[((0 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((1 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0])))))));
            ((VPFX_f0_y0)[((1 * 1) + 0)] =
                 (((VPFX_f0_y0)[((1 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((2 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_ry0)[0]) +
                    ((VPFX_ry0)[0] * (VPFX_ry0)[0])))));
            ((VPFX_f0_y0)[((2 * 1) + 0)] =
                 (((VPFX_f0_y0)[((2 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((3 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry0)[0] * (VPFX_ry0)[0])));
            ((VPFX_f0_y0)[((3 * 1) + 0)] =
                 (((VPFX_f0_y0)[((3 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y0)[((4 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f0_y0)[((4 * 1) + 0)] =
                 ((VPFX_f0_y0)[((4 * 1) + 0)] *
                  ((VPFX_dixy0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_y0[5];
            double(*f1_y0)[4];
            (f1_y0 = VPFX_f1_y0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_y0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_y0)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_ry0)[0]))));
            ((VPFX_f1_y0)[((0 * 1) + 0)] =
                 (((VPFX_f1_y0)[((0 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y0)[((1 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f1_y0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry0)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry0)[0])))));
            ((VPFX_f1_y0)[((1 * 1) + 0)] =
                 (((VPFX_f1_y0)[((1 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y0)[((2 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f1_y0)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_ry0)[0]));
            ((VPFX_f1_y0)[((2 * 1) + 0)] =
                 (((VPFX_f1_y0)[((2 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y0)[((3 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_f1_y0)[((3 * 1) + 0)] =
                 ((VPFX_f1_y0)[((3 * 1) + 0)] *
                  ((VPFX_dixy0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_y0[5];
            double(*if1_y0)[4];
            (if1_y0 = VPFX_if1_y0);
            ((VPFX_if1_y0)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y0)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y0)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y0)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y0)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry0)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry0)[0]))))));
            ((VPFX_if1_y0)[((0 * 1) + 0)] =
                 (((VPFX_if1_y0)[((0 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y0)[((1 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_if1_y0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_ry0)[0] * (VPFX_ry0)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_ry0)[0]) +
                     ((VPFX_ry0)[0] * (VPFX_ry0)[0]))))));
            ((VPFX_if1_y0)[((1 * 1) + 0)] =
                 (((VPFX_if1_y0)[((1 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y0)[((2 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_if1_y0)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry0)[0] * (VPFX_ry0)[0])));
            ((VPFX_if1_y0)[((2 * 1) + 0)] =
                 (((VPFX_if1_y0)[((2 * 1) + 0)] *
                   ((VPFX_dixy0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y0)[((3 * 1) + 0)] * -((VPFX_dixy0)[0]))));
            ((VPFX_if1_y0)[((3 * 1) + 0)] =
                 ((VPFX_if1_y0)[((3 * 1) + 0)] *
                  ((VPFX_dixy0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_z0[5];
            double(*f0_z0)[4];
            (f0_z0 = VPFX_f0_z0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_z0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_z0)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz0)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz0)[0])))));
            ((VPFX_f0_z0)[((0 * 1) + 0)] =
                 (((VPFX_f0_z0)[((0 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((1 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0])))))));
            ((VPFX_f0_z0)[((1 * 1) + 0)] =
                 (((VPFX_f0_z0)[((1 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((2 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rz0)[0]) +
                    ((VPFX_rz0)[0] * (VPFX_rz0)[0])))));
            ((VPFX_f0_z0)[((2 * 1) + 0)] =
                 (((VPFX_f0_z0)[((2 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((3 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz0)[0] * (VPFX_rz0)[0])));
            ((VPFX_f0_z0)[((3 * 1) + 0)] =
                 (((VPFX_f0_z0)[((3 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z0)[((4 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f0_z0)[((4 * 1) + 0)] =
                 ((VPFX_f0_z0)[((4 * 1) + 0)] *
                  ((VPFX_dixz0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_z0[5];
            double(*f1_z0)[4];
            (f1_z0 = VPFX_f1_z0);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_z0)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_z0)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rz0)[0]))));
            ((VPFX_f1_z0)[((0 * 1) + 0)] =
                 (((VPFX_f1_z0)[((0 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z0)[((1 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f1_z0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz0)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz0)[0])))));
            ((VPFX_f1_z0)[((1 * 1) + 0)] =
                 (((VPFX_f1_z0)[((1 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z0)[((2 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f1_z0)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rz0)[0]));
            ((VPFX_f1_z0)[((2 * 1) + 0)] =
                 (((VPFX_f1_z0)[((2 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z0)[((3 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_f1_z0)[((3 * 1) + 0)] =
                 ((VPFX_f1_z0)[((3 * 1) + 0)] *
                  ((VPFX_dixz0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_z0[5];
            double(*if1_z0)[4];
            (if1_z0 = VPFX_if1_z0);
            ((VPFX_if1_z0)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z0)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z0)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z0)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z0)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz0)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz0)[0]))))));
            ((VPFX_if1_z0)[((0 * 1) + 0)] =
                 (((VPFX_if1_z0)[((0 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z0)[((1 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_if1_z0)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rz0)[0] * (VPFX_rz0)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rz0)[0]) +
                     ((VPFX_rz0)[0] * (VPFX_rz0)[0]))))));
            ((VPFX_if1_z0)[((1 * 1) + 0)] =
                 (((VPFX_if1_z0)[((1 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z0)[((2 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_if1_z0)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz0)[0] * (VPFX_rz0)[0])));
            ((VPFX_if1_z0)[((2 * 1) + 0)] =
                 (((VPFX_if1_z0)[((2 * 1) + 0)] *
                   ((VPFX_dixz0)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z0)[((3 * 1) + 0)] * -((VPFX_dixz0)[0]))));
            ((VPFX_if1_z0)[((3 * 1) + 0)] =
                 ((VPFX_if1_z0)[((3 * 1) + 0)] *
                  ((VPFX_dixz0)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_x1[5];
            double(*f0_x1)[4];
            (f0_x1 = VPFX_f0_x1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_x1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_x1)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx1)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx1)[0])))));
            ((VPFX_f0_x1)[((0 * 1) + 0)] =
                 (((VPFX_f0_x1)[((0 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((1 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0])))))));
            ((VPFX_f0_x1)[((1 * 1) + 0)] =
                 (((VPFX_f0_x1)[((1 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((2 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rx1)[0]) +
                    ((VPFX_rx1)[0] * (VPFX_rx1)[0])))));
            ((VPFX_f0_x1)[((2 * 1) + 0)] =
                 (((VPFX_f0_x1)[((2 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((3 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx1)[0] * (VPFX_rx1)[0])));
            ((VPFX_f0_x1)[((3 * 1) + 0)] =
                 (((VPFX_f0_x1)[((3 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_x1)[((4 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f0_x1)[((4 * 1) + 0)] =
                 ((VPFX_f0_x1)[((4 * 1) + 0)] *
                  ((VPFX_dixx1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_x1[5];
            double(*f1_x1)[4];
            (f1_x1 = VPFX_f1_x1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_x1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_x1)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rx1)[0]))));
            ((VPFX_f1_x1)[((0 * 1) + 0)] =
                 (((VPFX_f1_x1)[((0 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x1)[((1 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f1_x1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx1)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rx1)[0])))));
            ((VPFX_f1_x1)[((1 * 1) + 0)] =
                 (((VPFX_f1_x1)[((1 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x1)[((2 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f1_x1)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rx1)[0]));
            ((VPFX_f1_x1)[((2 * 1) + 0)] =
                 (((VPFX_f1_x1)[((2 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_x1)[((3 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_f1_x1)[((3 * 1) + 0)] =
                 ((VPFX_f1_x1)[((3 * 1) + 0)] *
                  ((VPFX_dixx1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_x1[5];
            double(*if1_x1)[4];
            (if1_x1 = VPFX_if1_x1);
            ((VPFX_if1_x1)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x1)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_x1)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x1)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_x1)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx1)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx1)[0]))))));
            ((VPFX_if1_x1)[((0 * 1) + 0)] =
                 (((VPFX_if1_x1)[((0 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x1)[((1 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_if1_x1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rx1)[0] * (VPFX_rx1)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rx1)[0]) +
                     ((VPFX_rx1)[0] * (VPFX_rx1)[0]))))));
            ((VPFX_if1_x1)[((1 * 1) + 0)] =
                 (((VPFX_if1_x1)[((1 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x1)[((2 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_if1_x1)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rx1)[0] * (VPFX_rx1)[0])));
            ((VPFX_if1_x1)[((2 * 1) + 0)] =
                 (((VPFX_if1_x1)[((2 * 1) + 0)] *
                   ((VPFX_dixx1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_x1)[((3 * 1) + 0)] * -((VPFX_dixx1)[0]))));
            ((VPFX_if1_x1)[((3 * 1) + 0)] =
                 ((VPFX_if1_x1)[((3 * 1) + 0)] *
                  ((VPFX_dixx1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_y1[5];
            double(*f0_y1)[4];
            (f0_y1 = VPFX_f0_y1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_y1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_y1)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry1)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry1)[0])))));
            ((VPFX_f0_y1)[((0 * 1) + 0)] =
                 (((VPFX_f0_y1)[((0 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((1 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0])))))));
            ((VPFX_f0_y1)[((1 * 1) + 0)] =
                 (((VPFX_f0_y1)[((1 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((2 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_ry1)[0]) +
                    ((VPFX_ry1)[0] * (VPFX_ry1)[0])))));
            ((VPFX_f0_y1)[((2 * 1) + 0)] =
                 (((VPFX_f0_y1)[((2 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((3 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry1)[0] * (VPFX_ry1)[0])));
            ((VPFX_f0_y1)[((3 * 1) + 0)] =
                 (((VPFX_f0_y1)[((3 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_y1)[((4 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f0_y1)[((4 * 1) + 0)] =
                 ((VPFX_f0_y1)[((4 * 1) + 0)] *
                  ((VPFX_dixy1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_y1[5];
            double(*f1_y1)[4];
            (f1_y1 = VPFX_f1_y1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_y1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_y1)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_ry1)[0]))));
            ((VPFX_f1_y1)[((0 * 1) + 0)] =
                 (((VPFX_f1_y1)[((0 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y1)[((1 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f1_y1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry1)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_ry1)[0])))));
            ((VPFX_f1_y1)[((1 * 1) + 0)] =
                 (((VPFX_f1_y1)[((1 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y1)[((2 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f1_y1)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_ry1)[0]));
            ((VPFX_f1_y1)[((2 * 1) + 0)] =
                 (((VPFX_f1_y1)[((2 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_y1)[((3 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_f1_y1)[((3 * 1) + 0)] =
                 ((VPFX_f1_y1)[((3 * 1) + 0)] *
                  ((VPFX_dixy1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_y1[5];
            double(*if1_y1)[4];
            (if1_y1 = VPFX_if1_y1);
            ((VPFX_if1_y1)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y1)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_y1)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y1)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_y1)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry1)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry1)[0]))))));
            ((VPFX_if1_y1)[((0 * 1) + 0)] =
                 (((VPFX_if1_y1)[((0 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y1)[((1 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_if1_y1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_ry1)[0] * (VPFX_ry1)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_ry1)[0]) +
                     ((VPFX_ry1)[0] * (VPFX_ry1)[0]))))));
            ((VPFX_if1_y1)[((1 * 1) + 0)] =
                 (((VPFX_if1_y1)[((1 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y1)[((2 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_if1_y1)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_ry1)[0] * (VPFX_ry1)[0])));
            ((VPFX_if1_y1)[((2 * 1) + 0)] =
                 (((VPFX_if1_y1)[((2 * 1) + 0)] *
                   ((VPFX_dixy1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_y1)[((3 * 1) + 0)] * -((VPFX_dixy1)[0]))));
            ((VPFX_if1_y1)[((3 * 1) + 0)] =
                 ((VPFX_if1_y1)[((3 * 1) + 0)] *
                  ((VPFX_dixy1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f0_z1[5];
            double(*f0_z1)[4];
            (f0_z1 = VPFX_f0_z1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f0_z1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f0_z1)[((1 * 1) + 0)] =
                 (2.50000000000000000e-01 *
                  ((1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz1)[0])) *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz1)[0])))));
            ((VPFX_f0_z1)[((0 * 1) + 0)] =
                 (((VPFX_f0_z1)[((0 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((1 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((2 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   (((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0]))) +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0])))))));
            ((VPFX_f0_z1)[((1 * 1) + 0)] =
                 (((VPFX_f0_z1)[((1 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((2 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((3 * 1) + 0)] =
                 (-2.50000000000000000e-01 *
                  (-1.00000000000000000e+00 +
                   ((-2.00000000000000000e+00 * (VPFX_rz1)[0]) +
                    ((VPFX_rz1)[0] * (VPFX_rz1)[0])))));
            ((VPFX_f0_z1)[((2 * 1) + 0)] =
                 (((VPFX_f0_z1)[((2 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((3 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((4 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz1)[0] * (VPFX_rz1)[0])));
            ((VPFX_f0_z1)[((3 * 1) + 0)] =
                 (((VPFX_f0_z1)[((3 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f0_z1)[((4 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f0_z1)[((4 * 1) + 0)] =
                 ((VPFX_f0_z1)[((4 * 1) + 0)] *
                  ((VPFX_dixz1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_f1_z1[5];
            double(*f1_z1)[4];
            (f1_z1 = VPFX_f1_z1);
            {
              long i;

              for ((i = 0); (i < 5); (i = (i + 1))) {
                ((VPFX_f1_z1)[((i * 1) + 0)] = (0 - ((__m256d){})));
              }
            }
            ((VPFX_f1_z1)[((1 * 1) + 0)] =
                 (5.00000000000000000e-01 *
                  (1.00000000000000000e+00 +
                   (-1.00000000000000000e+00 * (VPFX_rz1)[0]))));
            ((VPFX_f1_z1)[((0 * 1) + 0)] =
                 (((VPFX_f1_z1)[((0 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z1)[((1 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f1_z1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 *
                   (2.00000000000000000e+00 +
                    (-2.00000000000000000e+00 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz1)[0]))))) +
                  (5.00000000000000000e-01 *
                   (1.00000000000000000e+00 +
                    (-1.00000000000000000e+00 * (VPFX_rz1)[0])))));
            ((VPFX_f1_z1)[((1 * 1) + 0)] =
                 (((VPFX_f1_z1)[((1 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z1)[((2 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f1_z1)[((3 * 1) + 0)] =
                 (5.00000000000000000e-01 * (VPFX_rz1)[0]));
            ((VPFX_f1_z1)[((2 * 1) + 0)] =
                 (((VPFX_f1_z1)[((2 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_f1_z1)[((3 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_f1_z1)[((3 * 1) + 0)] =
                 ((VPFX_f1_z1)[((3 * 1) + 0)] *
                  ((VPFX_dixz1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_if1_z1[5];
            double(*if1_z1)[4];
            (if1_z1 = VPFX_if1_z1);
            ((VPFX_if1_z1)[((0 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z1)[((1 * 1) + 0)] = (1 - ((__m256d){})));
            ((VPFX_if1_z1)[((3 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z1)[((4 * 1) + 0)] = (0 - ((__m256d){})));
            ((VPFX_if1_z1)[((1 * 1) + 0)] =
                 (1.00000000000000000e+00 +
                  (-2.50000000000000000e-01 *
                   ((1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz1)[0])) *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz1)[0]))))));
            ((VPFX_if1_z1)[((0 * 1) + 0)] =
                 (((VPFX_if1_z1)[((0 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z1)[((1 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_if1_z1)[((2 * 1) + 0)] =
                 ((2.50000000000000000e-01 * ((VPFX_rz1)[0] * (VPFX_rz1)[0])) +
                  (-2.50000000000000000e-01 *
                   (-1.00000000000000000e+00 +
                    ((-2.00000000000000000e+00 * (VPFX_rz1)[0]) +
                     ((VPFX_rz1)[0] * (VPFX_rz1)[0]))))));
            ((VPFX_if1_z1)[((1 * 1) + 0)] =
                 (((VPFX_if1_z1)[((1 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z1)[((2 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_if1_z1)[((3 * 1) + 0)] =
                 (2.50000000000000000e-01 * ((VPFX_rz1)[0] * (VPFX_rz1)[0])));
            ((VPFX_if1_z1)[((2 * 1) + 0)] =
                 (((VPFX_if1_z1)[((2 * 1) + 0)] *
                   ((VPFX_dixz1)[0] + 1.00000000000000000e+00)) +
                  ((VPFX_if1_z1)[((3 * 1) + 0)] * -((VPFX_dixz1)[0]))));
            ((VPFX_if1_z1)[((3 * 1) + 0)] =
                 ((VPFX_if1_z1)[((3 * 1) + 0)] *
                  ((VPFX_dixz1)[0] + 1.00000000000000000e+00)));
            __m256d VPFX_AllEx[1];
            double *AllEx = VPFX_AllEx;

            ((VPFX_AllEx)[0] = (0 - ((__m256d){})));
            __m256d VPFX_AllEy[1];
            double *AllEy = VPFX_AllEy;

            ((VPFX_AllEy)[0] = (0 - ((__m256d){})));
            __m256d VPFX_AllEz[1];
            double *AllEz = VPFX_AllEz;

            ((VPFX_AllEz)[0] = (0 - ((__m256d){})));
            {
              long idz;

              for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
                {
                  long idy;

                  for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
                    {
                      long idx;

                      for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
                        ((VPFX_AllEx)[0] =
                             ((VPFX_AllEx)[0] +
                              (((shE0)[(0 + (3 * (idx +
                                                  (5 * (idy + (idz * 5))))))] +
                                0) *
                               ((VPFX_f1_x1)[((idx * 1) + 0)] *
                                ((VPFX_f0_y1)[((idy * 1) + 0)] *
                                 (VPFX_f0_z1)[((idz * 1) + 0)])))));
                        ((VPFX_AllEy)[0] =
                             ((VPFX_AllEy)[0] +
                              (((shE0)[(1 + (3 * (idz +
                                                  (5 * (idx + (idy * 5))))))] +
                                0) *
                               ((VPFX_f1_y1)[((idx * 1) + 0)] *
                                ((VPFX_f0_z1)[((idy * 1) + 0)] *
                                 (VPFX_f0_x1)[((idz * 1) + 0)])))));
                        ((VPFX_AllEz)[0] =
                             ((VPFX_AllEz)[0] +
                              (((shE0)[(2 + (3 * (idy +
                                                  (5 * (idz + (idx * 5))))))] +
                                0) *
                               ((VPFX_f1_z1)[((idx * 1) + 0)] *
                                ((VPFX_f0_x1)[((idy * 1) + 0)] *
                                 (VPFX_f0_y1)[((idz * 1) + 0)])))));
                      }
                    }
                  }
                }
              }
            }
            __m256d VPFX_allincfvx[1];
            double *allincfvx = VPFX_allincfvx;

            __m256d VPFX_allincfvy[1];
            double *allincfvy = VPFX_allincfvy;

            __m256d VPFX_allincfvz[1];
            double *allincfvz = VPFX_allincfvz;

            ((VPFX_allincfvx)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEx)[0])));
            ((VPFX_allincfvy)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEy)[0])));
            ((VPFX_allincfvz)[0] =
                 (2.00000000000000000e+00 * (Deltat * (VPFX_AllEz)[0])));
            double DT;

            (DT = Deltat);
            {
              __m256d VPFX_x0[1];
              double *x0 = VPFX_x0;

              ((VPFX_x0)[0] = ((VPFX_xx0)[0] + XO));
              __m256d VPFX_y0[1];
              double *y0 = VPFX_y0;

              ((VPFX_y0)[0] = ((VPFX_xy0)[0] + YO));
              __m256d VPFX_z0[1];
              double *z0 = VPFX_z0;

              ((VPFX_z0)[0] = (((VPFX_xz0)[0] + ZO) - zmid));
              __m256d VPFX_x1[1];
              double *x1 = VPFX_x1;

              ((VPFX_x1)[0] = ((VPFX_xx1)[0] + XO));
              __m256d VPFX_y1[1];
              double *y1 = VPFX_y1;

              ((VPFX_y1)[0] = ((VPFX_xy1)[0] + YO));
              __m256d VPFX_z1[1];
              double *z1 = VPFX_z1;

              ((VPFX_z1)[0] = (((VPFX_xz1)[0] + ZO) - zmid));
              __m256d VPFX_mzero[1];
              double *mzero = VPFX_mzero;

              ((VPFX_mzero)[0] = (0.00000000000000000e+00 - ((__m256d){})));
              __m256d VPFX_iBx[1];
              double *iBx = VPFX_iBx;

              ((VPFX_iBx)[0] =
                   ((-1.00000000000000000e+00 *
                     (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                       0.00000000000000000e+00) *
                      ({ (1.00000000000000000e+00 / DT); }))) +
                    (VPFX_mzero)[0]));
              __m256d VPFX_x2[1];
              double *x2 = VPFX_x2;

              ((VPFX_x2)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_x0)[0]) +
                     (2.00000000000000000e+00 * (VPFX_x1)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (QE_MASS * (Deltat * ((VPFX_allincfvx)[0] +
                                           (-1.00000000000000000e+00 *
                                            (VPFX_iBx)[0])))))));
              __m256d VPFX_rx2[1];
              double *rx2 = VPFX_rx2;

              ((VPFX_rx2)[0] = (((VPFX_x2)[0] - XO) -
                                _mm256_floor_pd(((VPFX_x2)[0] - XO))));
              __m256d VPFX_dixx2[1];
              double *dixx2 = VPFX_dixx2;

              ((VPFX_dixx2)[0] = (_mm256_floor_pd(((VPFX_x2)[0] - XO)) - Midx));
              __m256d VPFX_f0_x2[5];
              double(*f0_x2)[4];
              (f0_x2 = VPFX_f0_x2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_x2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_x2)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx2)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx2)[0])))));
              ((VPFX_f0_x2)[((0 * 1) + 0)] =
                   (((VPFX_f0_x2)[((0 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((1 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0])))))));
              ((VPFX_f0_x2)[((1 * 1) + 0)] =
                   (((VPFX_f0_x2)[((1 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((2 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rx2)[0]) +
                      ((VPFX_rx2)[0] * (VPFX_rx2)[0])))));
              ((VPFX_f0_x2)[((2 * 1) + 0)] =
                   (((VPFX_f0_x2)[((2 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((3 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx2)[0] * (VPFX_rx2)[0])));
              ((VPFX_f0_x2)[((3 * 1) + 0)] =
                   (((VPFX_f0_x2)[((3 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x2)[((4 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f0_x2)[((4 * 1) + 0)] =
                   ((VPFX_f0_x2)[((4 * 1) + 0)] *
                    ((VPFX_dixx2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_x2[5];
              double(*f1_x2)[4];
              (f1_x2 = VPFX_f1_x2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_x2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_x2)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx2)[0]))));
              ((VPFX_f1_x2)[((0 * 1) + 0)] =
                   (((VPFX_f1_x2)[((0 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x2)[((1 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f1_x2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx2)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx2)[0])))));
              ((VPFX_f1_x2)[((1 * 1) + 0)] =
                   (((VPFX_f1_x2)[((1 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x2)[((2 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f1_x2)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rx2)[0]));
              ((VPFX_f1_x2)[((2 * 1) + 0)] =
                   (((VPFX_f1_x2)[((2 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x2)[((3 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_f1_x2)[((3 * 1) + 0)] =
                   ((VPFX_f1_x2)[((3 * 1) + 0)] *
                    ((VPFX_dixx2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_x2[5];
              double(*if1_x2)[4];
              (if1_x2 = VPFX_if1_x2);
              ((VPFX_if1_x2)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x2)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x2)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x2)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x2)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx2)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx2)[0]))))));
              ((VPFX_if1_x2)[((0 * 1) + 0)] =
                   (((VPFX_if1_x2)[((0 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x2)[((1 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_if1_x2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rx2)[0] * (VPFX_rx2)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rx2)[0]) +
                       ((VPFX_rx2)[0] * (VPFX_rx2)[0]))))));
              ((VPFX_if1_x2)[((1 * 1) + 0)] =
                   (((VPFX_if1_x2)[((1 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x2)[((2 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_if1_x2)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx2)[0] * (VPFX_rx2)[0])));
              ((VPFX_if1_x2)[((2 * 1) + 0)] =
                   (((VPFX_if1_x2)[((2 * 1) + 0)] *
                     ((VPFX_dixx2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x2)[((3 * 1) + 0)] * -((VPFX_dixx2)[0]))));
              ((VPFX_if1_x2)[((3 * 1) + 0)] =
                   ((VPFX_if1_x2)[((3 * 1) + 0)] *
                    ((VPFX_dixx2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_iBy[1];
              double *iBy = VPFX_iBy;

              ((VPFX_iBy)[0] =
                   (({ (1.00000000000000000e+00 / DT); }) *
                    (0.00000000000000000e+00 +
                     ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                      (((0.00000000000000000e+00 + ({
                           __m256d VPFX_tmpBfd[1];
                           double *tmpBfd = VPFX_tmpBfd;

                           ((VPFX_tmpBfd)[0] =
                                (0.00000000000000000e+00 - ((__m256d){})));
                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx;

                                       (allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                       ((VPFX_tmpBfd)[0] =
                                            ((VPFX_tmpBfd)[0] +
                                             ((shB0)[((allidx * 3) + 2)] *
                                              ((VPFX_f0_z1)[((xyzz * 1) + 0)] *
                                               (((VPFX_if1_x1)[((xyzx * 1) +
                                                                0)] -
                                                 (VPFX_if1_x0)[((xyzx * 1) +
                                                                0)]) *
                                                (VPFX_f1_y1)[((xyzy * 1) +
                                                              0)])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           (VPFX_tmpBfd)[0];
                         })) +
                        (0.00000000000000000e+00 + ({
                           __m256d VPFX_tmpBfd[1];
                           double *tmpBfd = VPFX_tmpBfd;

                           ((VPFX_tmpBfd)[0] =
                                (0.00000000000000000e+00 - ((__m256d){})));
                           {
                             long xyzz;

                             for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                               {
                                 long xyzy;

                                 for ((xyzy = 0); (xyzy < 5);
                                      (xyzy = (xyzy + 1))) {
                                   {
                                     long xyzx;

                                     for ((xyzx = 0); (xyzx < 5);
                                          (xyzx = (xyzx + 1))) {
                                       int allidx;

                                       (allidx =
                                            (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                       ((VPFX_tmpBfd)[0] =
                                            ((VPFX_tmpBfd)[0] +
                                             ((shB1)[((allidx * 3) + 2)] *
                                              ((VPFX_f0_z1)[((xyzz * 1) + 0)] *
                                               (((VPFX_if1_x2)[((xyzx * 1) +
                                                                0)] -
                                                 (VPFX_if1_x1)[((xyzx * 1) +
                                                                0)]) *
                                                (VPFX_f1_y1)[((xyzy * 1) +
                                                              0)])))));
                                     }
                                   }
                                 }
                               }
                             }
                           }
                           (VPFX_tmpBfd)[0];
                         }))) *
                       DT)))));
              __m256d VPFX_y2[1];
              double *y2 = VPFX_y2;

              ((VPFX_y2)[0] =
                   ((({
                       (1.00000000000000000e+00 /
                        ((TX0 * TX0) +
                         ((2.00000000000000000e+00 * (TX0 * (VPFX_x2)[0])) +
                          ((VPFX_x2)[0] * (VPFX_x2)[0]))));
                     }) *
                     ((((-1.00000000000000000e+00 * (TX0 * TX0)) +
                        ((-2.00000000000000000e+00 * (TX0 * (VPFX_x0)[0])) +
                         (-1.00000000000000000e+00 *
                          ((VPFX_x0)[0] * (VPFX_x0)[0])))) *
                       (VPFX_y0)[0]) +
                      (((2.00000000000000000e+00 * (TX0 * TX0)) +
                        ((2.00000000000000000e+00 * (TX0 * (VPFX_x0)[0])) +
                         (((VPFX_x0)[0] * (VPFX_x0)[0]) +
                          ((2.00000000000000000e+00 * (TX0 * (VPFX_x2)[0])) +
                           ((VPFX_x2)[0] * (VPFX_x2)[0]))))) *
                       (VPFX_y1)[0]))) +
                    ((TX0 * TX0) *
                     ((QE_MASS * (Deltat * ((VPFX_allincfvy)[0] +
                                            (-1.00000000000000000e+00 *
                                             (VPFX_iBy)[0])))) *
                      ({
                        (1.00000000000000000e+00 /
                         (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
                          ((2.00000000000000000e+00 *
                            ((DELTA_Y * DELTA_Y) * (TX0 * (VPFX_x2)[0]))) +
                           ((DELTA_Y * DELTA_Y) *
                            ((VPFX_x2)[0] * (VPFX_x2)[0])))));
                      })))));
              __m256d VPFX_ry2[1];
              double *ry2 = VPFX_ry2;

              ((VPFX_ry2)[0] = (((VPFX_y2)[0] - YO) -
                                _mm256_floor_pd(((VPFX_y2)[0] - YO))));
              __m256d VPFX_dixy2[1];
              double *dixy2 = VPFX_dixy2;

              ((VPFX_dixy2)[0] = (_mm256_floor_pd(((VPFX_y2)[0] - YO)) - Midy));
              __m256d VPFX_f0_y2[5];
              double(*f0_y2)[4];
              (f0_y2 = VPFX_f0_y2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_y2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_y2)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry2)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry2)[0])))));
              ((VPFX_f0_y2)[((0 * 1) + 0)] =
                   (((VPFX_f0_y2)[((0 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((1 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0])))))));
              ((VPFX_f0_y2)[((1 * 1) + 0)] =
                   (((VPFX_f0_y2)[((1 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((2 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_ry2)[0]) +
                      ((VPFX_ry2)[0] * (VPFX_ry2)[0])))));
              ((VPFX_f0_y2)[((2 * 1) + 0)] =
                   (((VPFX_f0_y2)[((2 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((3 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry2)[0] * (VPFX_ry2)[0])));
              ((VPFX_f0_y2)[((3 * 1) + 0)] =
                   (((VPFX_f0_y2)[((3 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y2)[((4 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f0_y2)[((4 * 1) + 0)] =
                   ((VPFX_f0_y2)[((4 * 1) + 0)] *
                    ((VPFX_dixy2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_y2[5];
              double(*f1_y2)[4];
              (f1_y2 = VPFX_f1_y2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_y2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_y2)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry2)[0]))));
              ((VPFX_f1_y2)[((0 * 1) + 0)] =
                   (((VPFX_f1_y2)[((0 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y2)[((1 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f1_y2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry2)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry2)[0])))));
              ((VPFX_f1_y2)[((1 * 1) + 0)] =
                   (((VPFX_f1_y2)[((1 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y2)[((2 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f1_y2)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_ry2)[0]));
              ((VPFX_f1_y2)[((2 * 1) + 0)] =
                   (((VPFX_f1_y2)[((2 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y2)[((3 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_f1_y2)[((3 * 1) + 0)] =
                   ((VPFX_f1_y2)[((3 * 1) + 0)] *
                    ((VPFX_dixy2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_y2[5];
              double(*if1_y2)[4];
              (if1_y2 = VPFX_if1_y2);
              ((VPFX_if1_y2)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y2)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y2)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y2)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y2)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry2)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry2)[0]))))));
              ((VPFX_if1_y2)[((0 * 1) + 0)] =
                   (((VPFX_if1_y2)[((0 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y2)[((1 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_if1_y2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_ry2)[0] * (VPFX_ry2)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_ry2)[0]) +
                       ((VPFX_ry2)[0] * (VPFX_ry2)[0]))))));
              ((VPFX_if1_y2)[((1 * 1) + 0)] =
                   (((VPFX_if1_y2)[((1 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y2)[((2 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_if1_y2)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry2)[0] * (VPFX_ry2)[0])));
              ((VPFX_if1_y2)[((2 * 1) + 0)] =
                   (((VPFX_if1_y2)[((2 * 1) + 0)] *
                     ((VPFX_dixy2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y2)[((3 * 1) + 0)] * -((VPFX_dixy2)[0]))));
              ((VPFX_if1_y2)[((3 * 1) + 0)] =
                   ((VPFX_if1_y2)[((3 * 1) + 0)] *
                    ((VPFX_dixy2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_iBz[1];
              double *iBz = VPFX_iBz;

              ((VPFX_iBz)[0] =
                   (-1.00000000000000000e+00 *
                    (({ (1.00000000000000000e+00 / DT); }) *
                     ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                      (0.00000000000000000e+00 +
                       (((-1.00000000000000000e+00 *
                          (0.00000000000000000e+00 + ({
                             __m256d VPFX_tmpBfd[1];
                             double *tmpBfd = VPFX_tmpBfd;

                             ((VPFX_tmpBfd)[0] =
                                  (0.00000000000000000e+00 - ((__m256d){})));
                             {
                               long xyzz;

                               for ((xyzz = 0); (xyzz < 5);
                                    (xyzz = (xyzz + 1))) {
                                 {
                                   long xyzy;

                                   for ((xyzy = 0); (xyzy < 5);
                                        (xyzy = (xyzy + 1))) {
                                     {
                                       long xyzx;

                                       for ((xyzx = 0); (xyzx < 5);
                                            (xyzx = (xyzx + 1))) {
                                         int allidx;

                                         (allidx = (xyzx +
                                                    (5 * (xyzy + (5 * xyzz)))));
                                         ((VPFX_tmpBfd)[0] =
                                              ((VPFX_tmpBfd)[0] +
                                               ((shB0)[((allidx * 3) + 0)] *
                                                ((VPFX_f0_x0)[((xyzx * 1) +
                                                               0)] *
                                                 (((VPFX_if1_y1)[((xyzy * 1) +
                                                                  0)] -
                                                   (VPFX_if1_y0)[((xyzy * 1) +
                                                                  0)]) *
                                                  (VPFX_f1_z1)[((xyzz * 1) +
                                                                0)])))));
                                       }
                                     }
                                   }
                                 }
                               }
                             }
                             (VPFX_tmpBfd)[0];
                           }))) +
                         ((0.00000000000000000e+00 + ({
                             __m256d VPFX_tmpBfd[1];
                             double *tmpBfd = VPFX_tmpBfd;

                             ((VPFX_tmpBfd)[0] =
                                  (0.00000000000000000e+00 - ((__m256d){})));
                             {
                               long xyzz;

                               for ((xyzz = 0); (xyzz < 5);
                                    (xyzz = (xyzz + 1))) {
                                 {
                                   long xyzy;

                                   for ((xyzy = 0); (xyzy < 5);
                                        (xyzy = (xyzy + 1))) {
                                     {
                                       long xyzx;

                                       for ((xyzx = 0); (xyzx < 5);
                                            (xyzx = (xyzx + 1))) {
                                         int allidx;

                                         (allidx = (xyzx +
                                                    (5 * (xyzy + (5 * xyzz)))));
                                         ((VPFX_tmpBfd)[0] =
                                              ((VPFX_tmpBfd)[0] +
                                               ((shB0)[((allidx * 3) + 1)] *
                                                ((VPFX_f0_y1)[((xyzy * 1) +
                                                               0)] *
                                                 (((VPFX_if1_x1)[((xyzx * 1) +
                                                                  0)] -
                                                   (VPFX_if1_x0)[((xyzx * 1) +
                                                                  0)]) *
                                                  (VPFX_f1_z1)[((xyzz * 1) +
                                                                0)])))));
                                       }
                                     }
                                   }
                                 }
                               }
                             }
                             (VPFX_tmpBfd)[0];
                           })) +
                          ((-1.00000000000000000e+00 *
                            (0.00000000000000000e+00 + ({
                               __m256d VPFX_tmpBfd[1];
                               double *tmpBfd = VPFX_tmpBfd;

                               ((VPFX_tmpBfd)[0] =
                                    (0.00000000000000000e+00 - ((__m256d){})));
                               {
                                 long xyzz;

                                 for ((xyzz = 0); (xyzz < 5);
                                      (xyzz = (xyzz + 1))) {
                                   {
                                     long xyzy;

                                     for ((xyzy = 0); (xyzy < 5);
                                          (xyzy = (xyzy + 1))) {
                                       {
                                         long xyzx;

                                         for ((xyzx = 0); (xyzx < 5);
                                              (xyzx = (xyzx + 1))) {
                                           int allidx;

                                           (allidx =
                                                (xyzx +
                                                 (5 * (xyzy + (5 * xyzz)))));
                                           ((VPFX_tmpBfd)[0] =
                                                ((VPFX_tmpBfd)[0] +
                                                 ((shB1)[((allidx * 3) + 0)] *
                                                  ((VPFX_f0_x2)[((xyzx * 1) +
                                                                 0)] *
                                                   (((VPFX_if1_y2)[((xyzy * 1) +
                                                                    0)] -
                                                     (VPFX_if1_y1)[((xyzy * 1) +
                                                                    0)]) *
                                                    (VPFX_f1_z1)[((xyzz * 1) +
                                                                  0)])))));
                                         }
                                       }
                                     }
                                   }
                                 }
                               }
                               (VPFX_tmpBfd)[0];
                             }))) +
                           (0.00000000000000000e+00 + ({
                              __m256d VPFX_tmpBfd[1];
                              double *tmpBfd = VPFX_tmpBfd;

                              ((VPFX_tmpBfd)[0] =
                                   (0.00000000000000000e+00 - ((__m256d){})));
                              {
                                long xyzz;

                                for ((xyzz = 0); (xyzz < 5);
                                     (xyzz = (xyzz + 1))) {
                                  {
                                    long xyzy;

                                    for ((xyzy = 0); (xyzy < 5);
                                         (xyzy = (xyzy + 1))) {
                                      {
                                        long xyzx;

                                        for ((xyzx = 0); (xyzx < 5);
                                             (xyzx = (xyzx + 1))) {
                                          int allidx;

                                          (allidx =
                                               (xyzx +
                                                (5 * (xyzy + (5 * xyzz)))));
                                          ((VPFX_tmpBfd)[0] =
                                               ((VPFX_tmpBfd)[0] +
                                                ((shB1)[((allidx * 3) + 1)] *
                                                 ((VPFX_f0_y1)[((xyzy * 1) +
                                                                0)] *
                                                  (((VPFX_if1_x2)[((xyzx * 1) +
                                                                   0)] -
                                                    (VPFX_if1_x1)[((xyzx * 1) +
                                                                   0)]) *
                                                   (VPFX_f1_z1)[((xyzz * 1) +
                                                                 0)])))));
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              (VPFX_tmpBfd)[0];
                            }))))) *
                        DT))))));
              __m256d VPFX_z2[1];
              double *z2 = VPFX_z2;

              ((VPFX_z2)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_z0)[0]) +
                     (2.00000000000000000e+00 * (VPFX_z1)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_Z * DELTA_Z)); }) *
                     (QE_MASS * (Deltat * ((VPFX_allincfvz)[0] +
                                           (-1.00000000000000000e+00 *
                                            (VPFX_iBz)[0])))))));
              __m256d VPFX_rz2[1];
              double *rz2 = VPFX_rz2;

              ((VPFX_rz2)[0] = (((VPFX_z2)[0] - (ZO - zmid)) -
                                _mm256_floor_pd(((VPFX_z2)[0] - (ZO - zmid)))));
              __m256d VPFX_dixz2[1];
              double *dixz2 = VPFX_dixz2;

              ((VPFX_dixz2)[0] =
                   (_mm256_floor_pd(((VPFX_z2)[0] - (ZO - zmid))) - Midz));
              __m256d VPFX_f0_z2[5];
              double(*f0_z2)[4];
              (f0_z2 = VPFX_f0_z2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_z2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_z2)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz2)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz2)[0])))));
              ((VPFX_f0_z2)[((0 * 1) + 0)] =
                   (((VPFX_f0_z2)[((0 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((1 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0])))))));
              ((VPFX_f0_z2)[((1 * 1) + 0)] =
                   (((VPFX_f0_z2)[((1 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((2 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rz2)[0]) +
                      ((VPFX_rz2)[0] * (VPFX_rz2)[0])))));
              ((VPFX_f0_z2)[((2 * 1) + 0)] =
                   (((VPFX_f0_z2)[((2 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((3 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz2)[0] * (VPFX_rz2)[0])));
              ((VPFX_f0_z2)[((3 * 1) + 0)] =
                   (((VPFX_f0_z2)[((3 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z2)[((4 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f0_z2)[((4 * 1) + 0)] =
                   ((VPFX_f0_z2)[((4 * 1) + 0)] *
                    ((VPFX_dixz2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_z2[5];
              double(*f1_z2)[4];
              (f1_z2 = VPFX_f1_z2);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_z2)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_z2)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz2)[0]))));
              ((VPFX_f1_z2)[((0 * 1) + 0)] =
                   (((VPFX_f1_z2)[((0 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z2)[((1 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f1_z2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz2)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz2)[0])))));
              ((VPFX_f1_z2)[((1 * 1) + 0)] =
                   (((VPFX_f1_z2)[((1 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z2)[((2 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f1_z2)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rz2)[0]));
              ((VPFX_f1_z2)[((2 * 1) + 0)] =
                   (((VPFX_f1_z2)[((2 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z2)[((3 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_f1_z2)[((3 * 1) + 0)] =
                   ((VPFX_f1_z2)[((3 * 1) + 0)] *
                    ((VPFX_dixz2)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_z2[5];
              double(*if1_z2)[4];
              (if1_z2 = VPFX_if1_z2);
              ((VPFX_if1_z2)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z2)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z2)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z2)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z2)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz2)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz2)[0]))))));
              ((VPFX_if1_z2)[((0 * 1) + 0)] =
                   (((VPFX_if1_z2)[((0 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z2)[((1 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_if1_z2)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rz2)[0] * (VPFX_rz2)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rz2)[0]) +
                       ((VPFX_rz2)[0] * (VPFX_rz2)[0]))))));
              ((VPFX_if1_z2)[((1 * 1) + 0)] =
                   (((VPFX_if1_z2)[((1 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z2)[((2 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_if1_z2)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz2)[0] * (VPFX_rz2)[0])));
              ((VPFX_if1_z2)[((2 * 1) + 0)] =
                   (((VPFX_if1_z2)[((2 * 1) + 0)] *
                     ((VPFX_dixz2)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z2)[((3 * 1) + 0)] * -((VPFX_dixz2)[0]))));
              ((VPFX_if1_z2)[((3 * 1) + 0)] =
                   ((VPFX_if1_z2)[((3 * 1) + 0)] *
                    ((VPFX_dixz2)[0] + 1.00000000000000000e+00)));
              ((VPFX_iBz)[0] = (0.00000000000000000e+00 - ((__m256d){})));
              __m256d VPFX_z3[1];
              double *z3 = VPFX_z3;

              ((VPFX_z3)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_z1)[0]) +
                     (2.00000000000000000e+00 * (VPFX_z2)[0])) +
                    (({ (1.00000000000000000e+00 / (DELTA_Z * DELTA_Z)); }) *
                     (-1 * (Deltat * (QE_MASS * (VPFX_iBz)[0]))))));
              __m256d VPFX_rz3[1];
              double *rz3 = VPFX_rz3;

              ((VPFX_rz3)[0] = (((VPFX_z3)[0] - (ZO - zmid)) -
                                _mm256_floor_pd(((VPFX_z3)[0] - (ZO - zmid)))));
              __m256d VPFX_dixz3[1];
              double *dixz3 = VPFX_dixz3;

              ((VPFX_dixz3)[0] =
                   (_mm256_floor_pd(((VPFX_z3)[0] - (ZO - zmid))) - Midz));
              __m256d VPFX_f0_z3[5];
              double(*f0_z3)[4];
              (f0_z3 = VPFX_f0_z3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_z3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_z3)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz3)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz3)[0])))));
              ((VPFX_f0_z3)[((0 * 1) + 0)] =
                   (((VPFX_f0_z3)[((0 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((1 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0])))))));
              ((VPFX_f0_z3)[((1 * 1) + 0)] =
                   (((VPFX_f0_z3)[((1 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((2 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rz3)[0]) +
                      ((VPFX_rz3)[0] * (VPFX_rz3)[0])))));
              ((VPFX_f0_z3)[((2 * 1) + 0)] =
                   (((VPFX_f0_z3)[((2 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((3 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz3)[0] * (VPFX_rz3)[0])));
              ((VPFX_f0_z3)[((3 * 1) + 0)] =
                   (((VPFX_f0_z3)[((3 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_z3)[((4 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f0_z3)[((4 * 1) + 0)] =
                   ((VPFX_f0_z3)[((4 * 1) + 0)] *
                    ((VPFX_dixz3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_z3[5];
              double(*f1_z3)[4];
              (f1_z3 = VPFX_f1_z3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_z3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_z3)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rz3)[0]))));
              ((VPFX_f1_z3)[((0 * 1) + 0)] =
                   (((VPFX_f1_z3)[((0 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z3)[((1 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f1_z3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rz3)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rz3)[0])))));
              ((VPFX_f1_z3)[((1 * 1) + 0)] =
                   (((VPFX_f1_z3)[((1 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z3)[((2 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f1_z3)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rz3)[0]));
              ((VPFX_f1_z3)[((2 * 1) + 0)] =
                   (((VPFX_f1_z3)[((2 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_z3)[((3 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_f1_z3)[((3 * 1) + 0)] =
                   ((VPFX_f1_z3)[((3 * 1) + 0)] *
                    ((VPFX_dixz3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_z3[5];
              double(*if1_z3)[4];
              (if1_z3 = VPFX_if1_z3);
              ((VPFX_if1_z3)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z3)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_z3)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z3)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_z3)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz3)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rz3)[0]))))));
              ((VPFX_if1_z3)[((0 * 1) + 0)] =
                   (((VPFX_if1_z3)[((0 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z3)[((1 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_if1_z3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rz3)[0] * (VPFX_rz3)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rz3)[0]) +
                       ((VPFX_rz3)[0] * (VPFX_rz3)[0]))))));
              ((VPFX_if1_z3)[((1 * 1) + 0)] =
                   (((VPFX_if1_z3)[((1 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z3)[((2 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_if1_z3)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rz3)[0] * (VPFX_rz3)[0])));
              ((VPFX_if1_z3)[((2 * 1) + 0)] =
                   (((VPFX_if1_z3)[((2 * 1) + 0)] *
                     ((VPFX_dixz3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_z3)[((3 * 1) + 0)] * -((VPFX_dixz3)[0]))));
              ((VPFX_if1_z3)[((3 * 1) + 0)] =
                   ((VPFX_if1_z3)[((3 * 1) + 0)] *
                    ((VPFX_dixz3)[0] + 1.00000000000000000e+00)));
              ((VPFX_iBy)[0] =
                   ((-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        __m256d VPFX_tmpBfd[1];
                        double *tmpBfd = VPFX_tmpBfd;

                        ((VPFX_tmpBfd)[0] =
                             (0.00000000000000000e+00 - ((__m256d){})));
                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx;

                                    (allidx =
                                         (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                    ((VPFX_tmpBfd)[0] =
                                         ((VPFX_tmpBfd)[0] +
                                          ((shB1)[((allidx * 3) + 0)] *
                                           ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                            (((VPFX_if1_z2)[((xyzz * 1) + 0)] -
                                              (VPFX_if1_z1)[((xyzz * 1) + 0)]) *
                                             (VPFX_f1_y2)[((xyzy * 1) +
                                                           0)])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        (VPFX_tmpBfd)[0];
                      }))) +
                    (-1.00000000000000000e+00 *
                     (0.00000000000000000e+00 + ({
                        __m256d VPFX_tmpBfd[1];
                        double *tmpBfd = VPFX_tmpBfd;

                        ((VPFX_tmpBfd)[0] =
                             (0.00000000000000000e+00 - ((__m256d){})));
                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx;

                                    (allidx =
                                         (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                    ((VPFX_tmpBfd)[0] =
                                         ((VPFX_tmpBfd)[0] +
                                          ((shB1)[((allidx * 3) + 0)] *
                                           ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                            (((VPFX_if1_z3)[((xyzz * 1) + 0)] -
                                              (VPFX_if1_z2)[((xyzz * 1) + 0)]) *
                                             (VPFX_f1_y2)[((xyzy * 1) +
                                                           0)])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        (VPFX_tmpBfd)[0];
                      })))));
              __m256d VPFX_y3[1];
              double *y3 = VPFX_y3;

              ((VPFX_y3)[0] =
                   (((-1.00000000000000000e+00 * (VPFX_y1)[0]) +
                     (2.00000000000000000e+00 * (VPFX_y2)[0])) +
                    ((TX0 * TX0) *
                     ((-1 * (Deltat * (QE_MASS * (VPFX_iBy)[0]))) * ({
                        (1.00000000000000000e+00 /
                         (((DELTA_Y * DELTA_Y) * (TX0 * TX0)) +
                          ((2.00000000000000000e+00 *
                            ((DELTA_Y * DELTA_Y) * (TX0 * (VPFX_x2)[0]))) +
                           ((DELTA_Y * DELTA_Y) *
                            ((VPFX_x2)[0] * (VPFX_x2)[0])))));
                      })))));
              __m256d VPFX_ry3[1];
              double *ry3 = VPFX_ry3;

              ((VPFX_ry3)[0] = (((VPFX_y3)[0] - YO) -
                                _mm256_floor_pd(((VPFX_y3)[0] - YO))));
              __m256d VPFX_dixy3[1];
              double *dixy3 = VPFX_dixy3;

              ((VPFX_dixy3)[0] = (_mm256_floor_pd(((VPFX_y3)[0] - YO)) - Midy));
              __m256d VPFX_f0_y3[5];
              double(*f0_y3)[4];
              (f0_y3 = VPFX_f0_y3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_y3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_y3)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry3)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry3)[0])))));
              ((VPFX_f0_y3)[((0 * 1) + 0)] =
                   (((VPFX_f0_y3)[((0 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((1 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0])))))));
              ((VPFX_f0_y3)[((1 * 1) + 0)] =
                   (((VPFX_f0_y3)[((1 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((2 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_ry3)[0]) +
                      ((VPFX_ry3)[0] * (VPFX_ry3)[0])))));
              ((VPFX_f0_y3)[((2 * 1) + 0)] =
                   (((VPFX_f0_y3)[((2 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((3 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry3)[0] * (VPFX_ry3)[0])));
              ((VPFX_f0_y3)[((3 * 1) + 0)] =
                   (((VPFX_f0_y3)[((3 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_y3)[((4 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f0_y3)[((4 * 1) + 0)] =
                   ((VPFX_f0_y3)[((4 * 1) + 0)] *
                    ((VPFX_dixy3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_y3[5];
              double(*f1_y3)[4];
              (f1_y3 = VPFX_f1_y3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_y3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_y3)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_ry3)[0]))));
              ((VPFX_f1_y3)[((0 * 1) + 0)] =
                   (((VPFX_f1_y3)[((0 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y3)[((1 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f1_y3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_ry3)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_ry3)[0])))));
              ((VPFX_f1_y3)[((1 * 1) + 0)] =
                   (((VPFX_f1_y3)[((1 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y3)[((2 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f1_y3)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_ry3)[0]));
              ((VPFX_f1_y3)[((2 * 1) + 0)] =
                   (((VPFX_f1_y3)[((2 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_y3)[((3 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_f1_y3)[((3 * 1) + 0)] =
                   ((VPFX_f1_y3)[((3 * 1) + 0)] *
                    ((VPFX_dixy3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_y3[5];
              double(*if1_y3)[4];
              (if1_y3 = VPFX_if1_y3);
              ((VPFX_if1_y3)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y3)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_y3)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y3)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_y3)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry3)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_ry3)[0]))))));
              ((VPFX_if1_y3)[((0 * 1) + 0)] =
                   (((VPFX_if1_y3)[((0 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y3)[((1 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_if1_y3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_ry3)[0] * (VPFX_ry3)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_ry3)[0]) +
                       ((VPFX_ry3)[0] * (VPFX_ry3)[0]))))));
              ((VPFX_if1_y3)[((1 * 1) + 0)] =
                   (((VPFX_if1_y3)[((1 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y3)[((2 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_if1_y3)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_ry3)[0] * (VPFX_ry3)[0])));
              ((VPFX_if1_y3)[((2 * 1) + 0)] =
                   (((VPFX_if1_y3)[((2 * 1) + 0)] *
                     ((VPFX_dixy3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_y3)[((3 * 1) + 0)] * -((VPFX_dixy3)[0]))));
              ((VPFX_if1_y3)[((3 * 1) + 0)] =
                   ((VPFX_if1_y3)[((3 * 1) + 0)] *
                    ((VPFX_dixy3)[0] + 1.00000000000000000e+00)));
              ((VPFX_iBx)[0] =
                   ((0.00000000000000000e+00 + ({
                       __m256d VPFX_tmpBfd[1];
                       double *tmpBfd = VPFX_tmpBfd;

                       ((VPFX_tmpBfd)[0] =
                            (0.00000000000000000e+00 - ((__m256d){})));
                       {
                         long xyzz;

                         for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                           {
                             long xyzy;

                             for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                               {
                                 long xyzx;

                                 for ((xyzx = 0); (xyzx < 5);
                                      (xyzx = (xyzx + 1))) {
                                   int allidx;

                                   (allidx =
                                        (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                   ((VPFX_tmpBfd)[0] =
                                        ((VPFX_tmpBfd)[0] +
                                         ((shB1)[((allidx * 3) + 1)] *
                                          ((VPFX_f0_y2)[((xyzy * 1) + 0)] *
                                           (((VPFX_if1_z2)[((xyzz * 1) + 0)] -
                                             (VPFX_if1_z1)[((xyzz * 1) + 0)]) *
                                            (VPFX_f1_x2)[((xyzx * 1) + 0)])))));
                                 }
                               }
                             }
                           }
                         }
                       }
                       (VPFX_tmpBfd)[0];
                     })) +
                    ((0.00000000000000000e+00 + ({
                        __m256d VPFX_tmpBfd[1];
                        double *tmpBfd = VPFX_tmpBfd;

                        ((VPFX_tmpBfd)[0] =
                             (0.00000000000000000e+00 - ((__m256d){})));
                        {
                          long xyzz;

                          for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                            {
                              long xyzy;

                              for ((xyzy = 0); (xyzy < 5);
                                   (xyzy = (xyzy + 1))) {
                                {
                                  long xyzx;

                                  for ((xyzx = 0); (xyzx < 5);
                                       (xyzx = (xyzx + 1))) {
                                    int allidx;

                                    (allidx =
                                         (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                    ((VPFX_tmpBfd)[0] =
                                         ((VPFX_tmpBfd)[0] +
                                          ((shB1)[((allidx * 3) + 1)] *
                                           ((VPFX_f0_y2)[((xyzy * 1) + 0)] *
                                            (((VPFX_if1_z3)[((xyzz * 1) + 0)] -
                                              (VPFX_if1_z2)[((xyzz * 1) + 0)]) *
                                             (VPFX_f1_x2)[((xyzx * 1) +
                                                           0)])))));
                                  }
                                }
                              }
                            }
                          }
                        }
                        (VPFX_tmpBfd)[0];
                      })) +
                     ((-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          __m256d VPFX_tmpBfd[1];
                          double *tmpBfd = VPFX_tmpBfd;

                          ((VPFX_tmpBfd)[0] =
                               (0.00000000000000000e+00 - ((__m256d){})));
                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx;

                                      (allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                      ((VPFX_tmpBfd)[0] =
                                           ((VPFX_tmpBfd)[0] +
                                            ((shB1)[((allidx * 3) + 2)] *
                                             ((VPFX_f0_z1)[((xyzz * 1) + 0)] *
                                              (((VPFX_if1_y2)[((xyzy * 1) +
                                                               0)] -
                                                (VPFX_if1_y1)[((xyzy * 1) +
                                                               0)]) *
                                               (VPFX_f1_x2)[((xyzx * 1) +
                                                             0)])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          (VPFX_tmpBfd)[0];
                        }))) +
                      (-1.00000000000000000e+00 *
                       (0.00000000000000000e+00 + ({
                          __m256d VPFX_tmpBfd[1];
                          double *tmpBfd = VPFX_tmpBfd;

                          ((VPFX_tmpBfd)[0] =
                               (0.00000000000000000e+00 - ((__m256d){})));
                          {
                            long xyzz;

                            for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                              {
                                long xyzy;

                                for ((xyzy = 0); (xyzy < 5);
                                     (xyzy = (xyzy + 1))) {
                                  {
                                    long xyzx;

                                    for ((xyzx = 0); (xyzx < 5);
                                         (xyzx = (xyzx + 1))) {
                                      int allidx;

                                      (allidx =
                                           (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                      ((VPFX_tmpBfd)[0] =
                                           ((VPFX_tmpBfd)[0] +
                                            ((shB1)[((allidx * 3) + 2)] *
                                             ((VPFX_f0_z3)[((xyzz * 1) + 0)] *
                                              (((VPFX_if1_y3)[((xyzy * 1) +
                                                               0)] -
                                                (VPFX_if1_y2)[((xyzy * 1) +
                                                               0)]) *
                                               (VPFX_f1_x2)[((xyzx * 1) +
                                                             0)])))));
                                    }
                                  }
                                }
                              }
                            }
                          }
                          (VPFX_tmpBfd)[0];
                        })))))));
              __m256d VPFX_x3[1];
              double *x3 = VPFX_x3;

              ((VPFX_x3)[0] =
                   ((({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (({ (1.00000000000000000e+00 / (TX0 * TX0)); }) *
                      ((-1.00000000000000000e+00 *
                        ((DELTA_X * DELTA_X) * ((TX0 * TX0) * (VPFX_x1)[0]))) +
                       ((2.00000000000000000e+00 *
                         ((DELTA_X * DELTA_X) * ((TX0 * TX0) * (VPFX_x2)[0]))) +
                        (((((DELTA_Y * DELTA_Y) * TX0) +
                           ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0])) *
                          ((VPFX_y1)[0] * (VPFX_y1)[0])) +
                         ((((-2.00000000000000000e+00 *
                             ((DELTA_Y * DELTA_Y) * TX0)) +
                            (-2.00000000000000000e+00 *
                             ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                           ((VPFX_y1)[0] * (VPFX_y2)[0])) +
                          ((((2.00000000000000000e+00 *
                              ((DELTA_Y * DELTA_Y) * TX0)) +
                             (2.00000000000000000e+00 *
                              ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                            ((VPFX_y2)[0] * (VPFX_y2)[0])) +
                           ((((-2.00000000000000000e+00 *
                               ((DELTA_Y * DELTA_Y) * TX0)) +
                              (-2.00000000000000000e+00 *
                               ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0]))) *
                             ((VPFX_y2)[0] * (VPFX_y3)[0])) +
                            ((((DELTA_Y * DELTA_Y) * TX0) +
                              ((DELTA_Y * DELTA_Y) * (VPFX_x2)[0])) *
                             ((VPFX_y3)[0] * (VPFX_y3)[0])))))))))) +
                    (({ (1.00000000000000000e+00 / (DELTA_X * DELTA_X)); }) *
                     (-1 * (Deltat * (QE_MASS * (VPFX_iBx)[0]))))));
              __m256d VPFX_rx3[1];
              double *rx3 = VPFX_rx3;

              ((VPFX_rx3)[0] = (((VPFX_x3)[0] - XO) -
                                _mm256_floor_pd(((VPFX_x3)[0] - XO))));
              __m256d VPFX_dixx3[1];
              double *dixx3 = VPFX_dixx3;

              ((VPFX_dixx3)[0] = (_mm256_floor_pd(((VPFX_x3)[0] - XO)) - Midx));
              __m256d VPFX_f0_x3[5];
              double(*f0_x3)[4];
              (f0_x3 = VPFX_f0_x3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f0_x3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f0_x3)[((1 * 1) + 0)] =
                   (2.50000000000000000e-01 *
                    ((1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx3)[0])) *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx3)[0])))));
              ((VPFX_f0_x3)[((0 * 1) + 0)] =
                   (((VPFX_f0_x3)[((0 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((1 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((2 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     (((1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0])) *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0]))) +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0])))))));
              ((VPFX_f0_x3)[((1 * 1) + 0)] =
                   (((VPFX_f0_x3)[((1 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((2 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((3 * 1) + 0)] =
                   (-2.50000000000000000e-01 *
                    (-1.00000000000000000e+00 +
                     ((-2.00000000000000000e+00 * (VPFX_rx3)[0]) +
                      ((VPFX_rx3)[0] * (VPFX_rx3)[0])))));
              ((VPFX_f0_x3)[((2 * 1) + 0)] =
                   (((VPFX_f0_x3)[((2 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((3 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((4 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx3)[0] * (VPFX_rx3)[0])));
              ((VPFX_f0_x3)[((3 * 1) + 0)] =
                   (((VPFX_f0_x3)[((3 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f0_x3)[((4 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f0_x3)[((4 * 1) + 0)] =
                   ((VPFX_f0_x3)[((4 * 1) + 0)] *
                    ((VPFX_dixx3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_f1_x3[5];
              double(*f1_x3)[4];
              (f1_x3 = VPFX_f1_x3);
              {
                long i;

                for ((i = 0); (i < 5); (i = (i + 1))) {
                  ((VPFX_f1_x3)[((i * 1) + 0)] = (0 - ((__m256d){})));
                }
              }
              ((VPFX_f1_x3)[((1 * 1) + 0)] =
                   (5.00000000000000000e-01 *
                    (1.00000000000000000e+00 +
                     (-1.00000000000000000e+00 * (VPFX_rx3)[0]))));
              ((VPFX_f1_x3)[((0 * 1) + 0)] =
                   (((VPFX_f1_x3)[((0 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x3)[((1 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f1_x3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     (2.00000000000000000e+00 +
                      (-2.00000000000000000e+00 *
                       (1.00000000000000000e+00 +
                        (-1.00000000000000000e+00 * (VPFX_rx3)[0]))))) +
                    (5.00000000000000000e-01 *
                     (1.00000000000000000e+00 +
                      (-1.00000000000000000e+00 * (VPFX_rx3)[0])))));
              ((VPFX_f1_x3)[((1 * 1) + 0)] =
                   (((VPFX_f1_x3)[((1 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x3)[((2 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f1_x3)[((3 * 1) + 0)] =
                   (5.00000000000000000e-01 * (VPFX_rx3)[0]));
              ((VPFX_f1_x3)[((2 * 1) + 0)] =
                   (((VPFX_f1_x3)[((2 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_f1_x3)[((3 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_f1_x3)[((3 * 1) + 0)] =
                   ((VPFX_f1_x3)[((3 * 1) + 0)] *
                    ((VPFX_dixx3)[0] + 1.00000000000000000e+00)));
              __m256d VPFX_if1_x3[5];
              double(*if1_x3)[4];
              (if1_x3 = VPFX_if1_x3);
              ((VPFX_if1_x3)[((0 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x3)[((1 * 1) + 0)] = (1 - ((__m256d){})));
              ((VPFX_if1_x3)[((3 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x3)[((4 * 1) + 0)] = (0 - ((__m256d){})));
              ((VPFX_if1_x3)[((1 * 1) + 0)] =
                   (1.00000000000000000e+00 +
                    (-2.50000000000000000e-01 *
                     ((1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx3)[0])) *
                      (1.00000000000000000e+00 +
                       (-1.00000000000000000e+00 * (VPFX_rx3)[0]))))));
              ((VPFX_if1_x3)[((0 * 1) + 0)] =
                   (((VPFX_if1_x3)[((0 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x3)[((1 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_if1_x3)[((2 * 1) + 0)] =
                   ((2.50000000000000000e-01 *
                     ((VPFX_rx3)[0] * (VPFX_rx3)[0])) +
                    (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      ((-2.00000000000000000e+00 * (VPFX_rx3)[0]) +
                       ((VPFX_rx3)[0] * (VPFX_rx3)[0]))))));
              ((VPFX_if1_x3)[((1 * 1) + 0)] =
                   (((VPFX_if1_x3)[((1 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x3)[((2 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_if1_x3)[((3 * 1) + 0)] =
                   (2.50000000000000000e-01 * ((VPFX_rx3)[0] * (VPFX_rx3)[0])));
              ((VPFX_if1_x3)[((2 * 1) + 0)] =
                   (((VPFX_if1_x3)[((2 * 1) + 0)] *
                     ((VPFX_dixx3)[0] + 1.00000000000000000e+00)) +
                    ((VPFX_if1_x3)[((3 * 1) + 0)] * -((VPFX_dixx3)[0]))));
              ((VPFX_if1_x3)[((3 * 1) + 0)] =
                   ((VPFX_if1_x3)[((3 * 1) + 0)] *
                    ((VPFX_dixx3)[0] + 1.00000000000000000e+00)));
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_x2)[((xyzx * 1) + 0)] -
                                        (VPFX_if1_x1)[((xyzx * 1) + 0)]) *
                                       ((VPFX_f0_y1)[((xyzy * 1) + 0)] *
                                        (VPFX_f0_z1)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 0)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 0)] +
                                        (((grid_geo_x *
                                           ((Tori_X0 /
                                             (Tori_X0 +
                                              (XO + (bBidx + xyzx)))) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 0)] =
                                       ((shJ0)[((allidx * 3) + 0)] +
                                        ((grid_geo_x *
                                          ((Tori_X0 /
                                            (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_y2)[((xyzy * 1) + 0)] -
                                        (VPFX_if1_y1)[((xyzy * 1) + 0)]) *
                                       ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                        (VPFX_f0_z1)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 1)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 1)] +
                                        (((grid_geo_y *
                                           (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                             Tori_X0) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 1)] =
                                       ((shJ0)[((allidx * 3) + 1)] +
                                        ((grid_geo_y *
                                          (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                            Tori_X0) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_z3)[((xyzz * 1) + 0)] -
                                        (VPFX_if1_z1)[((xyzz * 1) + 0)]) *
                                       ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                        (VPFX_f0_y2)[((xyzy * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 2)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 2)] +
                                        (((grid_geo_z *
                                           ((Tori_X0 /
                                             (Tori_X0 +
                                              (XO + (bBidx + xyzx)))) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 2)] =
                                       ((shJ0)[((allidx * 3) + 2)] +
                                        ((grid_geo_z *
                                          ((Tori_X0 /
                                            (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_y3)[((xyzy * 1) + 0)] -
                                        (VPFX_if1_y2)[((xyzy * 1) + 0)]) *
                                       ((VPFX_f0_x2)[((xyzx * 1) + 0)] *
                                        (VPFX_f0_z3)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 1)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 1)] +
                                        (((grid_geo_y *
                                           (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                             Tori_X0) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 1)] =
                                       ((shJ0)[((allidx * 3) + 1)] +
                                        ((grid_geo_y *
                                          (((Tori_X0 + (XO + (bBidx + xyzx))) /
                                            Tori_X0) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              {
                int xyzz;

#pragma clang loop vectorize(disable)
                for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
                  {
                    {
                      int xyzy;

#pragma clang loop vectorize(disable)
                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          {
                            int xyzx;

#pragma clang loop vectorize(disable)
                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              {
                                int allidx;

                                (allidx = (xyzx + (5 * (xyzy + (5 * xyzz)))));
                                __m256d VPFX_Jtmp[1];
                                double *Jtmp = VPFX_Jtmp;

                                ((VPFX_Jtmp)[0] =
                                     ((VPFX_simd_mask)[0] *
                                      (((VPFX_if1_x3)[((xyzx * 1) + 0)] -
                                        (VPFX_if1_x2)[((xyzx * 1) + 0)]) *
                                       ((VPFX_f0_y3)[((xyzy * 1) + 0)] *
                                        (VPFX_f0_z3)[((xyzz * 1) + 0)]))));
                                {
                                  ((shJ_incf_simdp)[((allidx * 3) + 0)] =
                                       ((shJ_incf_simdp)[((allidx * 3) + 0)] +
                                        (((grid_geo_x *
                                           ((Tori_X0 /
                                             (Tori_X0 +
                                              (XO + (bBidx + xyzx)))) *
                                            Charge0)) *
                                          (VPFX_Jtmp)[0]) *
                                         1)));
                                  ((shJ0)[((allidx * 3) + 0)] =
                                       ((shJ0)[((allidx * 3) + 0)] +
                                        ((grid_geo_x *
                                          ((Tori_X0 /
                                            (Tori_X0 + (XO + (bBidx + xyzx)))) *
                                           Charge0)) *
                                         (((Jtmp)[0] +
                                           ((Jtmp)[1] +
                                            ((Jtmp)[2] + (Jtmp)[3]))) *
                                          (!1)))));
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
              __m256d VPFX_newvx[1];
              double *newvx = VPFX_newvx;

              ((VPFX_newvx)[0] = (((VPFX_x3)[0] - (VPFX_x2)[0]) / DT));
              __m256d VPFX_newvy[1];
              double *newvy = VPFX_newvy;

              ((VPFX_newvy)[0] = (((VPFX_y3)[0] - (VPFX_y2)[0]) / DT));
              __m256d VPFX_newvz[1];
              double *newvz = VPFX_newvz;

              ((VPFX_newvz)[0] = (((VPFX_z3)[0] - (VPFX_z2)[0]) / DT));
              __m256d VPFX_newxx[1];
              double *newxx = VPFX_newxx;

              ((VPFX_newxx)[0] = ((VPFX_x3)[0] - XO));
              __m256d VPFX_newxy[1];
              double *newxy = VPFX_newxy;

              ((VPFX_newxy)[0] = ((VPFX_y3)[0] - YO));
              __m256d VPFX_newxz[1];
              double *newxz = VPFX_newxz;

              ((VPFX_newxz)[0] = (((VPFX_z3)[0] + zmid) - ZO));
              ((VPFX_newxx)[0] = ((VPFX_newxx)[0] + 5.00000000000000000e-01));
              ((VPFX_newxy)[0] = ((VPFX_newxy)[0] + 5.00000000000000000e-01));
              ((VPFX_newxz)[0] = ((VPFX_newxz)[0] + 5.00000000000000000e-01));
            }
            {
              int stmpg1;

#pragma clang loop vectorize(disable)
              for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
                {
                  {
                    int inner_var_G0;

                    for ((inner_var_G0 = 0); (inner_var_G0 < 4);
                         (inner_var_G0 = (inner_var_G0 + 1))) {
                      if (((g_inner + inner_var_G0) < load0)) {
                        ((particle_head_general)[(
                             stmpg1 + ((g_inner + inner_var_G0) * 6))] =
                             ((local_particle_head)[stmpg1])[inner_var_G0]);

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
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 5); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                int total_idx = (3 * (5 * (xyzy + (5 * xyzz))));

                {
                  long xii;

                  for ((xii = 0); (xii < 15); (xii = (xii + 1))) {
                    {
                      long i;

                      for ((i = 0); (i < 4); (i = (i + 1))) {
                        ((shJ0)[(total_idx + xii)] =
                             ((shJ0)[(total_idx + xii)] +
                              (shJ_incf)[(((total_idx + xii) * 4) + i)]));
                      }
                    }
                  }
                }
                {
                  long Gll_P9918;

                  for ((Gll_P9918 = 0); (Gll_P9918 < (3 * 5));
                       (Gll_P9918 = (Gll_P9918 + 1))) {
                    (((FoutJ + ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                     ((YLEN + (2 * ovlp)) *
                                                      (ZLEN + (2 * ovlp)))))) +
                                (0 + (num_ele * ((bBidx + ovlp) +
                                                 ((XLEN + (2 * ovlp)) *
                                                  (((xyzy + bBidy) + ovlp) +
                                                   ((YLEN + (2 * ovlp)) *
                                                    ((xyzz + bBidz) +
                                                     ovlp))))))))))[Gll_P9918] =
                         ((shJ0 + total_idx))[Gll_P9918]);
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    0;
  }
}
  (cur_frame_num = (cur_frame_num + -1));
  goto *((call_stack_pointer)[cur_frame_num]);
beg_prog:

  0;
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      (load0 = 1);
      (use_local_particle_position = 1);
      (particle_head_general =
           (cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))));
      (new_load = load0);
      (call_sort = 0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP15;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP15:

      0;
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (cr_allgid = allgid);
      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      (load0 = new_load_tmp);
      (call_sort = 0);
      (particle_head_general =
           (inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))));
      (new_load = load0);
      (global_idy_tmp = __idy);

      call_stack_pointer[cur_frame_num] = &&LAB_TMP16;
      (cur_frame_num = (cur_frame_num + 1));
      goto core_fun;

    LAB_TMP16:

      0;
      if ((load0 != new_load)) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);

      } else {
        0;
      }
    }
  }
}

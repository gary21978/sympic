/* pushJ_vlo K1 split - extracted from cuda_geo_nr_Bfield_pushJ_vlo Pass A */
#ifndef PUSHJ_VLO_SPLIT_CUH
#define PUSHJ_VLO_SPLIT_CUH

#ifndef IDX_LOCAL_XLEN
#define IDX_LOCAL_XLEN 32
#endif
#ifndef FULL_MASK
#define FULL_MASK 0xffffffffu
#endif

typedef struct {
  double local_particle_head[6];
  double simd_mask;
  int g;
  int _gen_long_for_opt_loop_already_idx_0;
  double xx1, xy1, xz1, vx0, vy0, vz0;
  double rx, ry, rz;
  double xx0, xy0, xz0;
  double Midx0, Midx1, Midy0, Midy1, Midz0, Midz1;
  double rx0, rx1, ry0, ry1, rz0, rz1;
  double dixx0, dixx1, dixy0, dixy1, dixz0, dixz1;
  double f0_x1[5], f1_x1[5], if1_x1[5];
  double f0_y1[5], f1_y1[5], if1_y1[5];
  double f0_z1[5], f1_z1[5], if1_z1[5];

  /* K2 */
  double AllEx, AllEy, AllEz;
  double allincfvx, allincfvy, allincfvz;
  double DT;
  double x0, y0, z0, x1, y1, z1, mzero;
  double iBx, iBy, iBz;
  double x2, y2, z2, x3, y3, z3;
  double rx2, rx3, ry2, ry3, rz2, rz3;
  double dixx2, dixx3, dixy2, dixy3, dixz2, dixz3;
  double f0_x2[5], f1_x2[5], if1_x2[5];
  double f0_y2[5], f1_y2[5], if1_y2[5];
  double f0_z2[5], f1_z2[5], if1_z2[5];
  double f0_z3[5], f1_z3[5], if1_z3[5];
  double f0_y3[5], f1_y3[5], if1_y3[5];
  double f0_x3[5], f1_x3[5], if1_x3[5];
  /* K3 */
  double newvx, newvy, newvz, newxx, newxy, newxz;
} pushJ_vlo_state_t;

static __device__ __forceinline__ void pushJ_vlo_K1_load_shared_5x5x5(
    double *shE0, double *shB0, double *shB1, double *shJ0, double *fieldE,
    double *fieldB, double *fieldB1, double *FoutJ, long __idy, long __idx,
    long __xlen, int bBidx, int bBidy, int bBidz, long XLEN, long YLEN,
    long ZLEN, int ovlp, int num_ele) {
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
                long MYGEN1286 = 0;

                for (; (MYGEN1286 < (3 * 5));
                     (MYGEN1286 = (MYGEN1286 + __xlen))) {
                  int ridx = (MYGEN1286 + __idx);

                  if (ridx < (3 * 5)) {
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

                  }
                }
              }
              {
                long MYGEN1288 = 0;

                for (; (MYGEN1288 < (3 * 5));
                     (MYGEN1288 = (MYGEN1288 + __xlen))) {
                  int ridx = (MYGEN1288 + __idx);

                  if (ridx < (3 * 5)) {
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

                  }
                }
              }
              {
                long MYGEN1290 = 0;

                for (; (MYGEN1290 < (3 * 5));
                     (MYGEN1290 = (MYGEN1290 + __xlen))) {
                  int ridx = (MYGEN1290 + __idx);

                  if (ridx < (3 * 5)) {
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

                  }
                }
              }
              {
                long MYGEN1292 = 0;

                for (; (MYGEN1292 < (3 * 5));
                     (MYGEN1292 = (MYGEN1292 + __xlen))) {
                  int ridx = (MYGEN1292 + __idx);

                  if (ridx < (3 * 5)) {
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

static __device__ __forceinline__ void
pushJ_vlo_K1_setup_weights_x0x1(pushJ_vlo_state_t *st, double *particle_buf,
                                long __idx, long __xlen, int g_inner,
                                long load0, double Midx, double Midy,
                                double Midz, double Deltat) {
  st->simd_mask = 1;

  st->g = (g_inner + __idx);

  st->_gen_long_for_opt_loop_already_idx_0 = (st->g >= load0);

  {
    long stmpg1;

    for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
      int cid = (g_inner + __idx);

      ((st->local_particle_head)[stmpg1] =
           (((cid < load0)) ? ((particle_buf)[(stmpg1 + (cid * 6))])
                            : ((particle_buf)[(stmpg1 + (g_inner * 6))])));
    }
  }
  st->xx1 = (st->local_particle_head)[0];

  st->xy1 = (st->local_particle_head)[1];

  st->xz1 = (st->local_particle_head)[2];

  st->vx0 = (st->local_particle_head)[3];

  st->vy0 = (st->local_particle_head)[4];

  st->vz0 = (st->local_particle_head)[5];

  (st->xx1 = (st->xx1 + -5.00000000000000000e-01));
  (st->xy1 = (st->xy1 + -5.00000000000000000e-01));
  (st->xz1 = (st->xz1 + -5.00000000000000000e-01));
  st->rx = (st->xx1 - Midx);

  st->ry = (st->xy1 - Midy);

  st->rz = (st->xz1 - Midz);

  st->xx0 = (st->xx1 - (Deltat * st->vx0));

  st->xy0 = (st->xy1 - (Deltat * st->vy0));

  st->xz0 = (st->xz1 - (Deltat * st->vz0));

  st->Midx0 = floor(st->xx0);

  st->Midx1 = floor(st->xx1);

  st->Midy0 = floor(st->xy0);

  st->Midy1 = floor(st->xy1);

  st->Midz0 = floor(st->xz0);

  st->Midz1 = floor(st->xz1);

  st->rx0 = (st->xx0 - st->Midx0);

  st->rx1 = (st->xx1 - st->Midx1);

  st->ry0 = (st->xy0 - st->Midy0);

  st->ry1 = (st->xy1 - st->Midy1);

  st->rz0 = (st->xz0 - st->Midz0);

  st->rz1 = (st->xz1 - st->Midz1);

  st->dixx0 = (st->Midx0 - Midx);

  st->dixx1 = (st->Midx1 - Midx);

  st->dixy0 = (st->Midy0 - Midy);

  st->dixy1 = (st->Midy1 - Midy);

  st->dixz0 = (st->Midz0 - Midz);

  st->dixz1 = (st->Midz1 - Midz);

  {
    long i;

    for ((i = 0); (i < 5); (i = (i + 1))) {
      ((st->f0_x1)[i] = 0);
    }
  }
  ((st->f0_x1)[1] =
       (2.50000000000000000e-01 * ({
          double tmppowvar =
              (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx1));

          (tmppowvar * tmppowvar);
        })));
  ((st->f0_x1)[0] = (((st->f0_x1)[0] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f0_x1)[1] * -(st->dixx1))));
  ((st->f0_x1)[2] = (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      (({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rx1));

                         (tmppowvar * tmppowvar);
                       }) +
                       (-2.00000000000000000e+00 *
                        (1.00000000000000000e+00 +
                         (-1.00000000000000000e+00 * st->rx1)))))));
  ((st->f0_x1)[1] = (((st->f0_x1)[1] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f0_x1)[2] * -(st->dixx1))));
  ((st->f0_x1)[3] =
       (-2.50000000000000000e-01 *
        (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rx1) + ({
                                       double tmppowvar = st->rx1;

                                       (tmppowvar * tmppowvar);
                                     })))));
  ((st->f0_x1)[2] = (((st->f0_x1)[2] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f0_x1)[3] * -(st->dixx1))));
  ((st->f0_x1)[4] = (2.50000000000000000e-01 * ({
                       double tmppowvar = st->rx1;

                       (tmppowvar * tmppowvar);
                     })));
  ((st->f0_x1)[3] = (((st->f0_x1)[3] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f0_x1)[4] * -(st->dixx1))));
  ((st->f0_x1)[4] = ((st->f0_x1)[4] * (st->dixx1 + 1.00000000000000000e+00)));
  {
    long i;

    for ((i = 0); (i < 5); (i = (i + 1))) {
      ((st->f1_x1)[i] = 0);
    }
  }
  ((st->f1_x1)[1] =
       (5.00000000000000000e-01 *
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx1))));
  ((st->f1_x1)[0] = (((st->f1_x1)[0] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f1_x1)[1] * -(st->dixx1))));
  ((st->f1_x1)[2] =
       ((2.50000000000000000e-01 *
         (2.00000000000000000e+00 +
          (-2.00000000000000000e+00 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx1))))) +
        (5.00000000000000000e-01 *
         (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx1)))));
  ((st->f1_x1)[1] = (((st->f1_x1)[1] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f1_x1)[2] * -(st->dixx1))));
  ((st->f1_x1)[3] = (5.00000000000000000e-01 * st->rx1));
  ((st->f1_x1)[2] = (((st->f1_x1)[2] * (st->dixx1 + 1.00000000000000000e+00)) +
                     ((st->f1_x1)[3] * -(st->dixx1))));
  ((st->f1_x1)[3] = ((st->f1_x1)[3] * (st->dixx1 + 1.00000000000000000e+00)));
  ((st->if1_x1)[0] = 1);
  ((st->if1_x1)[1] = 1);
  ((st->if1_x1)[3] = 0);
  ((st->if1_x1)[4] = 0);
  ((st->if1_x1)[1] =
       (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
          double tmppowvar =
              (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx1));

          (tmppowvar * tmppowvar);
        }))));
  ((st->if1_x1)[0] =
       (((st->if1_x1)[0] * (st->dixx1 + 1.00000000000000000e+00)) +
        ((st->if1_x1)[1] * -(st->dixx1))));
  ((st->if1_x1)[2] =
       ((2.50000000000000000e-01 * ({
           double tmppowvar = st->rx1;

           (tmppowvar * tmppowvar);
         })) +
        (-2.50000000000000000e-01 *
         (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rx1) + ({
                                        double tmppowvar = st->rx1;

                                        (tmppowvar * tmppowvar);
                                      }))))));
  ((st->if1_x1)[1] =
       (((st->if1_x1)[1] * (st->dixx1 + 1.00000000000000000e+00)) +
        ((st->if1_x1)[2] * -(st->dixx1))));
  ((st->if1_x1)[3] = (2.50000000000000000e-01 * ({
                        double tmppowvar = st->rx1;

                        (tmppowvar * tmppowvar);
                      })));
  ((st->if1_x1)[2] =
       (((st->if1_x1)[2] * (st->dixx1 + 1.00000000000000000e+00)) +
        ((st->if1_x1)[3] * -(st->dixx1))));
  ((st->if1_x1)[3] = ((st->if1_x1)[3] * (st->dixx1 + 1.00000000000000000e+00)));
  {
    long i;

    for ((i = 0); (i < 5); (i = (i + 1))) {
      ((st->f0_y1)[i] = 0);
    }
  }
  ((st->f0_y1)[1] =
       (2.50000000000000000e-01 * ({
          double tmppowvar =
              (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry1));

          (tmppowvar * tmppowvar);
        })));
  ((st->f0_y1)[0] = (((st->f0_y1)[0] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f0_y1)[1] * -(st->dixy1))));
  ((st->f0_y1)[2] = (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      (({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->ry1));

                         (tmppowvar * tmppowvar);
                       }) +
                       (-2.00000000000000000e+00 *
                        (1.00000000000000000e+00 +
                         (-1.00000000000000000e+00 * st->ry1)))))));
  ((st->f0_y1)[1] = (((st->f0_y1)[1] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f0_y1)[2] * -(st->dixy1))));
  ((st->f0_y1)[3] =
       (-2.50000000000000000e-01 *
        (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->ry1) + ({
                                       double tmppowvar = st->ry1;

                                       (tmppowvar * tmppowvar);
                                     })))));
  ((st->f0_y1)[2] = (((st->f0_y1)[2] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f0_y1)[3] * -(st->dixy1))));
  ((st->f0_y1)[4] = (2.50000000000000000e-01 * ({
                       double tmppowvar = st->ry1;

                       (tmppowvar * tmppowvar);
                     })));
  ((st->f0_y1)[3] = (((st->f0_y1)[3] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f0_y1)[4] * -(st->dixy1))));
  ((st->f0_y1)[4] = ((st->f0_y1)[4] * (st->dixy1 + 1.00000000000000000e+00)));
  {
    long i;

    for ((i = 0); (i < 5); (i = (i + 1))) {
      ((st->f1_y1)[i] = 0);
    }
  }
  ((st->f1_y1)[1] =
       (5.00000000000000000e-01 *
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry1))));
  ((st->f1_y1)[0] = (((st->f1_y1)[0] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f1_y1)[1] * -(st->dixy1))));
  ((st->f1_y1)[2] =
       ((2.50000000000000000e-01 *
         (2.00000000000000000e+00 +
          (-2.00000000000000000e+00 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry1))))) +
        (5.00000000000000000e-01 *
         (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry1)))));
  ((st->f1_y1)[1] = (((st->f1_y1)[1] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f1_y1)[2] * -(st->dixy1))));
  ((st->f1_y1)[3] = (5.00000000000000000e-01 * st->ry1));
  ((st->f1_y1)[2] = (((st->f1_y1)[2] * (st->dixy1 + 1.00000000000000000e+00)) +
                     ((st->f1_y1)[3] * -(st->dixy1))));
  ((st->f1_y1)[3] = ((st->f1_y1)[3] * (st->dixy1 + 1.00000000000000000e+00)));
  ((st->if1_y1)[0] = 1);
  ((st->if1_y1)[1] = 1);
  ((st->if1_y1)[3] = 0);
  ((st->if1_y1)[4] = 0);
  ((st->if1_y1)[1] =
       (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
          double tmppowvar =
              (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry1));

          (tmppowvar * tmppowvar);
        }))));
  ((st->if1_y1)[0] =
       (((st->if1_y1)[0] * (st->dixy1 + 1.00000000000000000e+00)) +
        ((st->if1_y1)[1] * -(st->dixy1))));
  ((st->if1_y1)[2] =
       ((2.50000000000000000e-01 * ({
           double tmppowvar = st->ry1;

           (tmppowvar * tmppowvar);
         })) +
        (-2.50000000000000000e-01 *
         (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->ry1) + ({
                                        double tmppowvar = st->ry1;

                                        (tmppowvar * tmppowvar);
                                      }))))));
  ((st->if1_y1)[1] =
       (((st->if1_y1)[1] * (st->dixy1 + 1.00000000000000000e+00)) +
        ((st->if1_y1)[2] * -(st->dixy1))));
  ((st->if1_y1)[3] = (2.50000000000000000e-01 * ({
                        double tmppowvar = st->ry1;

                        (tmppowvar * tmppowvar);
                      })));
  ((st->if1_y1)[2] =
       (((st->if1_y1)[2] * (st->dixy1 + 1.00000000000000000e+00)) +
        ((st->if1_y1)[3] * -(st->dixy1))));
  ((st->if1_y1)[3] = ((st->if1_y1)[3] * (st->dixy1 + 1.00000000000000000e+00)));
  {
    long i;

    for ((i = 0); (i < 5); (i = (i + 1))) {
      ((st->f0_z1)[i] = 0);
    }
  }
  ((st->f0_z1)[1] =
       (2.50000000000000000e-01 * ({
          double tmppowvar =
              (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz1));

          (tmppowvar * tmppowvar);
        })));
  ((st->f0_z1)[0] = (((st->f0_z1)[0] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f0_z1)[1] * -(st->dixz1))));
  ((st->f0_z1)[2] = (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      (({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rz1));

                         (tmppowvar * tmppowvar);
                       }) +
                       (-2.00000000000000000e+00 *
                        (1.00000000000000000e+00 +
                         (-1.00000000000000000e+00 * st->rz1)))))));
  ((st->f0_z1)[1] = (((st->f0_z1)[1] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f0_z1)[2] * -(st->dixz1))));
  ((st->f0_z1)[3] =
       (-2.50000000000000000e-01 *
        (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rz1) + ({
                                       double tmppowvar = st->rz1;

                                       (tmppowvar * tmppowvar);
                                     })))));
  ((st->f0_z1)[2] = (((st->f0_z1)[2] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f0_z1)[3] * -(st->dixz1))));
  ((st->f0_z1)[4] = (2.50000000000000000e-01 * ({
                       double tmppowvar = st->rz1;

                       (tmppowvar * tmppowvar);
                     })));
  ((st->f0_z1)[3] = (((st->f0_z1)[3] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f0_z1)[4] * -(st->dixz1))));
  ((st->f0_z1)[4] = ((st->f0_z1)[4] * (st->dixz1 + 1.00000000000000000e+00)));
  {
    long i;

    for ((i = 0); (i < 5); (i = (i + 1))) {
      ((st->f1_z1)[i] = 0);
    }
  }
  ((st->f1_z1)[1] =
       (5.00000000000000000e-01 *
        (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz1))));
  ((st->f1_z1)[0] = (((st->f1_z1)[0] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f1_z1)[1] * -(st->dixz1))));
  ((st->f1_z1)[2] =
       ((2.50000000000000000e-01 *
         (2.00000000000000000e+00 +
          (-2.00000000000000000e+00 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz1))))) +
        (5.00000000000000000e-01 *
         (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz1)))));
  ((st->f1_z1)[1] = (((st->f1_z1)[1] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f1_z1)[2] * -(st->dixz1))));
  ((st->f1_z1)[3] = (5.00000000000000000e-01 * st->rz1));
  ((st->f1_z1)[2] = (((st->f1_z1)[2] * (st->dixz1 + 1.00000000000000000e+00)) +
                     ((st->f1_z1)[3] * -(st->dixz1))));
  ((st->f1_z1)[3] = ((st->f1_z1)[3] * (st->dixz1 + 1.00000000000000000e+00)));
  ((st->if1_z1)[0] = 1);
  ((st->if1_z1)[1] = 1);
  ((st->if1_z1)[3] = 0);
  ((st->if1_z1)[4] = 0);
  ((st->if1_z1)[1] =
       (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
          double tmppowvar =
              (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz1));

          (tmppowvar * tmppowvar);
        }))));
  ((st->if1_z1)[0] =
       (((st->if1_z1)[0] * (st->dixz1 + 1.00000000000000000e+00)) +
        ((st->if1_z1)[1] * -(st->dixz1))));
  ((st->if1_z1)[2] =
       ((2.50000000000000000e-01 * ({
           double tmppowvar = st->rz1;

           (tmppowvar * tmppowvar);
         })) +
        (-2.50000000000000000e-01 *
         (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rz1) + ({
                                        double tmppowvar = st->rz1;

                                        (tmppowvar * tmppowvar);
                                      }))))));
  ((st->if1_z1)[1] =
       (((st->if1_z1)[1] * (st->dixz1 + 1.00000000000000000e+00)) +
        ((st->if1_z1)[2] * -(st->dixz1))));
  ((st->if1_z1)[3] = (2.50000000000000000e-01 * ({
                        double tmppowvar = st->rz1;

                        (tmppowvar * tmppowvar);
                      })));
  ((st->if1_z1)[2] =
       (((st->if1_z1)[2] * (st->dixz1 + 1.00000000000000000e+00)) +
        ((st->if1_z1)[3] * -(st->dixz1))));
  ((st->if1_z1)[3] = ((st->if1_z1)[3] * (st->dixz1 + 1.00000000000000000e+00)));
}

static __device__ __forceinline__ void pushJ_vlo_K2_push_weights_x2x3(
    pushJ_vlo_state_t *st, const double *shE0, const double *shB0,
    const double *shB1, double DELTA_X, double DELTA_Y, double DELTA_Z,
    double Deltat, double Tori_X0, double QE_MASS, double XO, double YO,
    double ZO, double zmid, double Midx, double Midy, double Midz) {
  const double TX0 = Tori_X0;

  st->AllEx = 0;

  st->AllEy = 0;

  st->AllEz = 0;

  {
    long idz;

    for ((idz = 0); (idz < 5); (idz = (idz + 1))) {
      {
        long idy;

        for ((idy = 0); (idy < 5); (idy = (idy + 1))) {
          {
            long idx;

            for ((idx = 0); (idx < 4); (idx = (idx + 1))) {
              (st->AllEx =
                   (st->AllEx +
                    (((shE0)[(0 + (3 * (idx + (5 * (idy + (idz * 5))))))] + 0) *
                     ((st->f1_x1)[idx] *
                      ((st->f0_y1)[idy] * (st->f0_z1)[idz])))));
              (st->AllEy =
                   (st->AllEy +
                    (((shE0)[(1 + (3 * (idz + (5 * (idx + (idy * 5))))))] + 0) *
                     ((st->f1_y1)[idx] *
                      ((st->f0_z1)[idy] * (st->f0_x1)[idz])))));
              (st->AllEz =
                   (st->AllEz +
                    (((shE0)[(2 + (3 * (idy + (5 * (idz + (idx * 5))))))] + 0) *
                     ((st->f1_z1)[idx] *
                      ((st->f0_x1)[idy] * (st->f0_y1)[idz])))));
            }
          }
        }
      }
    }
  }

  (st->allincfvx = (2.00000000000000000e+00 * (Deltat * st->AllEx)));
  (st->allincfvy = (2.00000000000000000e+00 * (Deltat * st->AllEy)));
  (st->allincfvz = (2.00000000000000000e+00 * (Deltat * st->AllEz)));
  st->DT = Deltat;

  {

    (st->x0 = (st->xx0 + XO));
    st->y0 = (st->xy0 + YO);

    st->z0 = ((st->xz0 + ZO) - zmid);

    st->x1 = (st->xx1 + XO);

    st->y1 = (st->xy1 + YO);

    st->z1 = ((st->xz1 + ZO) - zmid);

    st->mzero = 0.00000000000000000e+00;

    st->iBx = ((-1.00000000000000000e+00 *
                (((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
                  0.00000000000000000e+00) *
                 (1.00000000000000000e+00 / ({
                    double tmppowvar = st->DT;

                    tmppowvar;
                  })))) +
               st->mzero);

    st->x2 =
        (((-1.00000000000000000e+00 * st->x0) +
          (2.00000000000000000e+00 * st->x1)) +
         ((1.00000000000000000e+00 / ({
             double tmppowvar = DELTA_X;

             (tmppowvar * tmppowvar);
           })) *
          (QE_MASS *
           (Deltat * (st->allincfvx + (-1.00000000000000000e+00 * st->iBx))))));

    st->rx2 = ((st->x2 - XO) - floor((st->x2 - XO)));

    st->dixx2 = (floor((st->x2 - XO)) - Midx);

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f0_x2)[i] = 0);
      }
    }
    ((st->f0_x2)[1] = (2.50000000000000000e-01 * ({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rx2));

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_x2)[0] =
         (((st->f0_x2)[0] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f0_x2)[1] * -(st->dixx2))));
    ((st->f0_x2)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (({
                           double tmppowvar =
                               (1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * st->rx2));

                           (tmppowvar * tmppowvar);
                         }) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * st->rx2)))))));
    ((st->f0_x2)[1] =
         (((st->f0_x2)[1] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f0_x2)[2] * -(st->dixx2))));
    ((st->f0_x2)[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rx2) + ({
                                         double tmppowvar = st->rx2;

                                         (tmppowvar * tmppowvar);
                                       })))));
    ((st->f0_x2)[2] =
         (((st->f0_x2)[2] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f0_x2)[3] * -(st->dixx2))));
    ((st->f0_x2)[4] = (2.50000000000000000e-01 * ({
                         double tmppowvar = st->rx2;

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_x2)[3] =
         (((st->f0_x2)[3] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f0_x2)[4] * -(st->dixx2))));
    ((st->f0_x2)[4] = ((st->f0_x2)[4] * (st->dixx2 + 1.00000000000000000e+00)));
    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f1_x2)[i] = 0);
      }
    }
    ((st->f1_x2)[1] =
         (5.00000000000000000e-01 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx2))));
    ((st->f1_x2)[0] =
         (((st->f1_x2)[0] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f1_x2)[1] * -(st->dixx2))));
    ((st->f1_x2)[2] =
         ((2.50000000000000000e-01 *
           (2.00000000000000000e+00 +
            (-2.00000000000000000e+00 *
             (1.00000000000000000e+00 +
              (-1.00000000000000000e+00 * st->rx2))))) +
          (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx2)))));
    ((st->f1_x2)[1] =
         (((st->f1_x2)[1] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f1_x2)[2] * -(st->dixx2))));
    ((st->f1_x2)[3] = (5.00000000000000000e-01 * st->rx2));
    ((st->f1_x2)[2] =
         (((st->f1_x2)[2] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->f1_x2)[3] * -(st->dixx2))));
    ((st->f1_x2)[3] = ((st->f1_x2)[3] * (st->dixx2 + 1.00000000000000000e+00)));
    ((st->if1_x2)[0] = 1);
    ((st->if1_x2)[1] = 1);
    ((st->if1_x2)[3] = 0);
    ((st->if1_x2)[4] = 0);
    ((st->if1_x2)[1] = (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
                          double tmppowvar =
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * st->rx2));

                          (tmppowvar * tmppowvar);
                        }))));
    ((st->if1_x2)[0] =
         (((st->if1_x2)[0] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->if1_x2)[1] * -(st->dixx2))));
    ((st->if1_x2)[2] = ((2.50000000000000000e-01 * ({
                           double tmppowvar = st->rx2;

                           (tmppowvar * tmppowvar);
                         })) +
                        (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * st->rx2) + ({
                             double tmppowvar = st->rx2;

                             (tmppowvar * tmppowvar);
                           }))))));
    ((st->if1_x2)[1] =
         (((st->if1_x2)[1] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->if1_x2)[2] * -(st->dixx2))));
    ((st->if1_x2)[3] = (2.50000000000000000e-01 * ({
                          double tmppowvar = st->rx2;

                          (tmppowvar * tmppowvar);
                        })));
    ((st->if1_x2)[2] =
         (((st->if1_x2)[2] * (st->dixx2 + 1.00000000000000000e+00)) +
          ((st->if1_x2)[3] * -(st->dixx2))));
    ((st->if1_x2)[3] =
         ((st->if1_x2)[3] * (st->dixx2 + 1.00000000000000000e+00)));

    double if1_x0_loc[5];
    double if1_y0_loc[5];
    double f0_x0_loc[5];

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        (f0_x0_loc[i] = 0);
      }
    }
    (f0_x0_loc[1] = (2.50000000000000000e-01 * ({
                       double tmppowvar =
                           (1.00000000000000000e+00 +
                            (-1.00000000000000000e+00 * st->rx0));

                       (tmppowvar * tmppowvar);
                     })));
    (f0_x0_loc[0] =
         (((f0_x0_loc[0] * (st->dixx0 + 1.00000000000000000e+00)) +
           (f0_x0_loc[1] * -(st->dixx0)))));
    (f0_x0_loc[2] = (-2.50000000000000000e-01 *
                     (-1.00000000000000000e+00 +
                      (({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rx0));

                         (tmppowvar * tmppowvar);
                       }) +
                       (-2.00000000000000000e+00 *
                        (1.00000000000000000e+00 +
                         (-1.00000000000000000e+00 * st->rx0)))))));
    (f0_x0_loc[1] =
         (((f0_x0_loc[1] * (st->dixx0 + 1.00000000000000000e+00)) +
           (f0_x0_loc[2] * -(st->dixx0)))));
    (f0_x0_loc[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rx0) + ({
                                         double tmppowvar = st->rx0;

                                         (tmppowvar * tmppowvar);
                                       })))));
    (f0_x0_loc[2] =
         (((f0_x0_loc[2] * (st->dixx0 + 1.00000000000000000e+00)) +
           (f0_x0_loc[3] * -(st->dixx0)))));
    (f0_x0_loc[4] = (2.50000000000000000e-01 * ({
                       double tmppowvar = st->rx0;

                       (tmppowvar * tmppowvar);
                     })));
    (f0_x0_loc[3] =
         (((f0_x0_loc[3] * (st->dixx0 + 1.00000000000000000e+00)) +
           (f0_x0_loc[4] * -(st->dixx0)))));
    (f0_x0_loc[4] =
         (f0_x0_loc[4] * (st->dixx0 + 1.00000000000000000e+00)));

    (if1_x0_loc[0] = 1);
    (if1_x0_loc[1] = 1);
    (if1_x0_loc[3] = 0);
    (if1_x0_loc[4] = 0);
    (if1_x0_loc[1] =
         (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
            double tmppowvar =
                (1.00000000000000000e+00 +
                 (-1.00000000000000000e+00 * st->rx0));

            (tmppowvar * tmppowvar);
          }))));
    (if1_x0_loc[0] =
         (((if1_x0_loc[0] * (st->dixx0 + 1.00000000000000000e+00)) +
           (if1_x0_loc[1] * -(st->dixx0)))));
    (if1_x0_loc[2] =
         ((2.50000000000000000e-01 * ({
             double tmppowvar = st->rx0;

             (tmppowvar * tmppowvar);
           })) +
          (-2.50000000000000000e-01 *
           (-1.00000000000000000e+00 +
            ((-2.00000000000000000e+00 * st->rx0) + ({
               double tmppowvar = st->rx0;

               (tmppowvar * tmppowvar);
             }))))));
    (if1_x0_loc[1] =
         (((if1_x0_loc[1] * (st->dixx0 + 1.00000000000000000e+00)) +
           (if1_x0_loc[2] * -(st->dixx0)))));
    (if1_x0_loc[3] = (2.50000000000000000e-01 * ({
                        double tmppowvar = st->rx0;

                        (tmppowvar * tmppowvar);
                      })));
    (if1_x0_loc[2] =
         (((if1_x0_loc[2] * (st->dixx0 + 1.00000000000000000e+00)) +
           (if1_x0_loc[3] * -(st->dixx0)))));
    (if1_x0_loc[3] =
         (if1_x0_loc[3] * (st->dixx0 + 1.00000000000000000e+00)));

    (if1_y0_loc[0] = 1);
    (if1_y0_loc[1] = 1);
    (if1_y0_loc[3] = 0);
    (if1_y0_loc[4] = 0);
    (if1_y0_loc[1] =
         (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
            double tmppowvar =
                (1.00000000000000000e+00 +
                 (-1.00000000000000000e+00 * st->ry0));

            (tmppowvar * tmppowvar);
          }))));
    (if1_y0_loc[0] =
         (((if1_y0_loc[0] * (st->dixy0 + 1.00000000000000000e+00)) +
           (if1_y0_loc[1] * -(st->dixy0)))));
    (if1_y0_loc[2] =
         ((2.50000000000000000e-01 * ({
             double tmppowvar = st->ry0;

             (tmppowvar * tmppowvar);
           })) +
          (-2.50000000000000000e-01 *
           (-1.00000000000000000e+00 +
            ((-2.00000000000000000e+00 * st->ry0) + ({
               double tmppowvar = st->ry0;

               (tmppowvar * tmppowvar);
             }))))));
    (if1_y0_loc[1] =
         (((if1_y0_loc[1] * (st->dixy0 + 1.00000000000000000e+00)) +
           (if1_y0_loc[2] * -(st->dixy0)))));
    (if1_y0_loc[3] = (2.50000000000000000e-01 * ({
                        double tmppowvar = st->ry0;

                        (tmppowvar * tmppowvar);
                      })));
    (if1_y0_loc[2] =
         (((if1_y0_loc[2] * (st->dixy0 + 1.00000000000000000e+00)) +
           (if1_y0_loc[3] * -(st->dixy0)))));
    (if1_y0_loc[3] =
         (if1_y0_loc[3] * (st->dixy0 + 1.00000000000000000e+00)));
    st->iBy =
        ((1.00000000000000000e+00 / ({
            double tmppowvar = st->DT;

            tmppowvar;
          })) *
         (0.00000000000000000e+00 +
          ((-1.00000000000000000e+00 * 0.00000000000000000e+00) +
           (((0.00000000000000000e+00 + ({
                double tmpBfd = 0.00000000000000000e+00;

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

                            (tmpBfd =
                                 (tmpBfd +
                                  ((shB0)[((allidx * 3) + 2)] *
                                   ((st->f0_z1)[xyzz] *
                                    (((st->if1_x1)[xyzx] - if1_x0_loc[xyzx]) *
                                     (st->f1_y1)[xyzy])))));
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

                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          long xyzx;

                          for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                            int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                            (tmpBfd =
                                 (tmpBfd +
                                  ((shB1)[((allidx * 3) + 2)] *
                                   ((st->f0_z1)[xyzz] *
                                    (((st->if1_x2)[xyzx] - (st->if1_x1)[xyzx]) *
                                     (st->f1_y1)[xyzy])))));
                          }
                        }
                      }
                    }
                  }
                }
                tmpBfd;
              }))) *
            st->DT))));

    st->y2 =
        (((1.00000000000000000e+00 / ({
             double tmppowvar =
                 (({
                    double tmppowvar = TX0;

                    (tmppowvar * tmppowvar);
                  }) +
                  ((2.00000000000000000e+00 * (TX0 * st->x2)) + ({
                     double tmppowvar = st->x2;

                     (tmppowvar * tmppowvar);
                   })));

             tmppowvar;
           })) *
          ((((-1.00000000000000000e+00 * ({
               double tmppowvar = TX0;

               (tmppowvar * tmppowvar);
             })) +
             ((-2.00000000000000000e+00 * (TX0 * st->x0)) +
              (-1.00000000000000000e+00 * ({
                double tmppowvar = st->x0;

                (tmppowvar * tmppowvar);
              })))) *
            st->y0) +
           (((2.00000000000000000e+00 * ({
                double tmppowvar = TX0;

                (tmppowvar * tmppowvar);
              })) +
             ((2.00000000000000000e+00 * (TX0 * st->x0)) +
              (({
                 double tmppowvar = st->x0;

                 (tmppowvar * tmppowvar);
               }) +
               ((2.00000000000000000e+00 * (TX0 * st->x2)) + ({
                  double tmppowvar = st->x2;

                  (tmppowvar * tmppowvar);
                }))))) *
            st->y1))) +
         (({
            double tmppowvar = TX0;

            (tmppowvar * tmppowvar);
          }) *
          ((QE_MASS *
            (Deltat * (st->allincfvy + (-1.00000000000000000e+00 * st->iBy)))) *
           (1.00000000000000000e+00 / ({
              double tmppowvar =
                  ((({
                      double tmppowvar = DELTA_Y;

                      (tmppowvar * tmppowvar);
                    }) *
                    ({
                      double tmppowvar = TX0;

                      (tmppowvar * tmppowvar);
                    })) +
                   ((2.00000000000000000e+00 * (({
                                                  double tmppowvar = DELTA_Y;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                (TX0 * st->x2))) +
                    (({
                       double tmppowvar = DELTA_Y;

                       (tmppowvar * tmppowvar);
                     }) *
                     ({
                       double tmppowvar = st->x2;

                       (tmppowvar * tmppowvar);
                     }))));

              tmppowvar;
            })))));

    st->ry2 = ((st->y2 - YO) - floor((st->y2 - YO)));

    st->dixy2 = (floor((st->y2 - YO)) - Midy);

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f0_y2)[i] = 0);
      }
    }
    ((st->f0_y2)[1] = (2.50000000000000000e-01 * ({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->ry2));

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_y2)[0] =
         (((st->f0_y2)[0] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f0_y2)[1] * -(st->dixy2))));
    ((st->f0_y2)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (({
                           double tmppowvar =
                               (1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * st->ry2));

                           (tmppowvar * tmppowvar);
                         }) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * st->ry2)))))));
    ((st->f0_y2)[1] =
         (((st->f0_y2)[1] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f0_y2)[2] * -(st->dixy2))));
    ((st->f0_y2)[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->ry2) + ({
                                         double tmppowvar = st->ry2;

                                         (tmppowvar * tmppowvar);
                                       })))));
    ((st->f0_y2)[2] =
         (((st->f0_y2)[2] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f0_y2)[3] * -(st->dixy2))));
    ((st->f0_y2)[4] = (2.50000000000000000e-01 * ({
                         double tmppowvar = st->ry2;

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_y2)[3] =
         (((st->f0_y2)[3] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f0_y2)[4] * -(st->dixy2))));
    ((st->f0_y2)[4] = ((st->f0_y2)[4] * (st->dixy2 + 1.00000000000000000e+00)));
    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f1_y2)[i] = 0);
      }
    }
    ((st->f1_y2)[1] =
         (5.00000000000000000e-01 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry2))));
    ((st->f1_y2)[0] =
         (((st->f1_y2)[0] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f1_y2)[1] * -(st->dixy2))));
    ((st->f1_y2)[2] =
         ((2.50000000000000000e-01 *
           (2.00000000000000000e+00 +
            (-2.00000000000000000e+00 *
             (1.00000000000000000e+00 +
              (-1.00000000000000000e+00 * st->ry2))))) +
          (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry2)))));
    ((st->f1_y2)[1] =
         (((st->f1_y2)[1] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f1_y2)[2] * -(st->dixy2))));
    ((st->f1_y2)[3] = (5.00000000000000000e-01 * st->ry2));
    ((st->f1_y2)[2] =
         (((st->f1_y2)[2] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->f1_y2)[3] * -(st->dixy2))));
    ((st->f1_y2)[3] = ((st->f1_y2)[3] * (st->dixy2 + 1.00000000000000000e+00)));
    ((st->if1_y2)[0] = 1);
    ((st->if1_y2)[1] = 1);
    ((st->if1_y2)[3] = 0);
    ((st->if1_y2)[4] = 0);
    ((st->if1_y2)[1] = (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
                          double tmppowvar =
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * st->ry2));

                          (tmppowvar * tmppowvar);
                        }))));
    ((st->if1_y2)[0] =
         (((st->if1_y2)[0] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->if1_y2)[1] * -(st->dixy2))));
    ((st->if1_y2)[2] = ((2.50000000000000000e-01 * ({
                           double tmppowvar = st->ry2;

                           (tmppowvar * tmppowvar);
                         })) +
                        (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * st->ry2) + ({
                             double tmppowvar = st->ry2;

                             (tmppowvar * tmppowvar);
                           }))))));
    ((st->if1_y2)[1] =
         (((st->if1_y2)[1] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->if1_y2)[2] * -(st->dixy2))));
    ((st->if1_y2)[3] = (2.50000000000000000e-01 * ({
                          double tmppowvar = st->ry2;

                          (tmppowvar * tmppowvar);
                        })));
    ((st->if1_y2)[2] =
         (((st->if1_y2)[2] * (st->dixy2 + 1.00000000000000000e+00)) +
          ((st->if1_y2)[3] * -(st->dixy2))));
    ((st->if1_y2)[3] =
         ((st->if1_y2)[3] * (st->dixy2 + 1.00000000000000000e+00)));
    st->iBz =
        (-1.00000000000000000e+00 *
         ((1.00000000000000000e+00 / ({
             double tmppowvar = st->DT;

             tmppowvar;
           })) *
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

                        for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                          {
                            long xyzx;

                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                              (tmpBfd = (tmpBfd + ((shB0)[((allidx * 3) + 0)] *
                                                   (f0_x0_loc[xyzx] *
                                                    (((st->if1_y1)[xyzy] -
                                                      if1_y0_loc[xyzy]) *
                                                     (st->f1_z1)[xyzz])))));
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

                        for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                          {
                            long xyzx;

                            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                              int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                              (tmpBfd = (tmpBfd + ((shB0)[((allidx * 3) + 1)] *
                                                   ((st->f0_y1)[xyzy] *
                                                    (((st->if1_x1)[xyzx] -
                                                      if1_x0_loc[xyzx]) *
                                                     (st->f1_z1)[xyzz])))));
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

                          for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                            {
                              long xyzx;

                              for ((xyzx = 0); (xyzx < 5);
                                   (xyzx = (xyzx + 1))) {
                                int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                                (tmpBfd =
                                     (tmpBfd + ((shB1)[((allidx * 3) + 0)] *
                                                ((st->f0_x2)[xyzx] *
                                                 (((st->if1_y2)[xyzy] -
                                                   (st->if1_y1)[xyzy]) *
                                                  (st->f1_z1)[xyzz])))));
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

                         for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                           {
                             long xyzx;

                             for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                               int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                               (tmpBfd = (tmpBfd + ((shB1)[((allidx * 3) + 1)] *
                                                    ((st->f0_y1)[xyzy] *
                                                     (((st->if1_x2)[xyzx] -
                                                       (st->if1_x1)[xyzx]) *
                                                      (st->f1_z1)[xyzz])))));
                             }
                           }
                         }
                       }
                     }
                   }
                   tmpBfd;
                 }))))) *
             st->DT)))));

    st->z2 =
        (((-1.00000000000000000e+00 * st->z0) +
          (2.00000000000000000e+00 * st->z1)) +
         ((1.00000000000000000e+00 / ({
             double tmppowvar = DELTA_Z;

             (tmppowvar * tmppowvar);
           })) *
          (QE_MASS *
           (Deltat * (st->allincfvz + (-1.00000000000000000e+00 * st->iBz))))));

    st->rz2 = ((st->z2 - (ZO - zmid)) - floor((st->z2 - (ZO - zmid))));

    st->dixz2 = (floor((st->z2 - (ZO - zmid))) - Midz);

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f0_z2)[i] = 0);
      }
    }
    ((st->f0_z2)[1] = (2.50000000000000000e-01 * ({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rz2));

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_z2)[0] =
         (((st->f0_z2)[0] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f0_z2)[1] * -(st->dixz2))));
    ((st->f0_z2)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (({
                           double tmppowvar =
                               (1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * st->rz2));

                           (tmppowvar * tmppowvar);
                         }) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * st->rz2)))))));
    ((st->f0_z2)[1] =
         (((st->f0_z2)[1] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f0_z2)[2] * -(st->dixz2))));
    ((st->f0_z2)[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rz2) + ({
                                         double tmppowvar = st->rz2;

                                         (tmppowvar * tmppowvar);
                                       })))));
    ((st->f0_z2)[2] =
         (((st->f0_z2)[2] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f0_z2)[3] * -(st->dixz2))));
    ((st->f0_z2)[4] = (2.50000000000000000e-01 * ({
                         double tmppowvar = st->rz2;

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_z2)[3] =
         (((st->f0_z2)[3] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f0_z2)[4] * -(st->dixz2))));
    ((st->f0_z2)[4] = ((st->f0_z2)[4] * (st->dixz2 + 1.00000000000000000e+00)));
    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f1_z2)[i] = 0);
      }
    }
    ((st->f1_z2)[1] =
         (5.00000000000000000e-01 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz2))));
    ((st->f1_z2)[0] =
         (((st->f1_z2)[0] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f1_z2)[1] * -(st->dixz2))));
    ((st->f1_z2)[2] =
         ((2.50000000000000000e-01 *
           (2.00000000000000000e+00 +
            (-2.00000000000000000e+00 *
             (1.00000000000000000e+00 +
              (-1.00000000000000000e+00 * st->rz2))))) +
          (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz2)))));
    ((st->f1_z2)[1] =
         (((st->f1_z2)[1] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f1_z2)[2] * -(st->dixz2))));
    ((st->f1_z2)[3] = (5.00000000000000000e-01 * st->rz2));
    ((st->f1_z2)[2] =
         (((st->f1_z2)[2] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->f1_z2)[3] * -(st->dixz2))));
    ((st->f1_z2)[3] = ((st->f1_z2)[3] * (st->dixz2 + 1.00000000000000000e+00)));
    ((st->if1_z2)[0] = 1);
    ((st->if1_z2)[1] = 1);
    ((st->if1_z2)[3] = 0);
    ((st->if1_z2)[4] = 0);
    ((st->if1_z2)[1] = (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
                          double tmppowvar =
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * st->rz2));

                          (tmppowvar * tmppowvar);
                        }))));
    ((st->if1_z2)[0] =
         (((st->if1_z2)[0] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->if1_z2)[1] * -(st->dixz2))));
    ((st->if1_z2)[2] = ((2.50000000000000000e-01 * ({
                           double tmppowvar = st->rz2;

                           (tmppowvar * tmppowvar);
                         })) +
                        (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * st->rz2) + ({
                             double tmppowvar = st->rz2;

                             (tmppowvar * tmppowvar);
                           }))))));
    ((st->if1_z2)[1] =
         (((st->if1_z2)[1] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->if1_z2)[2] * -(st->dixz2))));
    ((st->if1_z2)[3] = (2.50000000000000000e-01 * ({
                          double tmppowvar = st->rz2;

                          (tmppowvar * tmppowvar);
                        })));
    ((st->if1_z2)[2] =
         (((st->if1_z2)[2] * (st->dixz2 + 1.00000000000000000e+00)) +
          ((st->if1_z2)[3] * -(st->dixz2))));
    ((st->if1_z2)[3] =
         ((st->if1_z2)[3] * (st->dixz2 + 1.00000000000000000e+00)));
    (st->iBz = 0.00000000000000000e+00);
    st->z3 = (((-1.00000000000000000e+00 * st->z1) +
               (2.00000000000000000e+00 * st->z2)) +
              ((1.00000000000000000e+00 / ({
                  double tmppowvar = DELTA_Z;

                  (tmppowvar * tmppowvar);
                })) *
               (-1 * (Deltat * (QE_MASS * st->iBz)))));

    st->rz3 = ((st->z3 - (ZO - zmid)) - floor((st->z3 - (ZO - zmid))));

    st->dixz3 = (floor((st->z3 - (ZO - zmid))) - Midz);

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f0_z3)[i] = 0);
      }
    }
    ((st->f0_z3)[1] = (2.50000000000000000e-01 * ({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rz3));

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_z3)[0] =
         (((st->f0_z3)[0] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f0_z3)[1] * -(st->dixz3))));
    ((st->f0_z3)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (({
                           double tmppowvar =
                               (1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * st->rz3));

                           (tmppowvar * tmppowvar);
                         }) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * st->rz3)))))));
    ((st->f0_z3)[1] =
         (((st->f0_z3)[1] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f0_z3)[2] * -(st->dixz3))));
    ((st->f0_z3)[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rz3) + ({
                                         double tmppowvar = st->rz3;

                                         (tmppowvar * tmppowvar);
                                       })))));
    ((st->f0_z3)[2] =
         (((st->f0_z3)[2] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f0_z3)[3] * -(st->dixz3))));
    ((st->f0_z3)[4] = (2.50000000000000000e-01 * ({
                         double tmppowvar = st->rz3;

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_z3)[3] =
         (((st->f0_z3)[3] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f0_z3)[4] * -(st->dixz3))));
    ((st->f0_z3)[4] = ((st->f0_z3)[4] * (st->dixz3 + 1.00000000000000000e+00)));
    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f1_z3)[i] = 0);
      }
    }
    ((st->f1_z3)[1] =
         (5.00000000000000000e-01 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz3))));
    ((st->f1_z3)[0] =
         (((st->f1_z3)[0] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f1_z3)[1] * -(st->dixz3))));
    ((st->f1_z3)[2] =
         ((2.50000000000000000e-01 *
           (2.00000000000000000e+00 +
            (-2.00000000000000000e+00 *
             (1.00000000000000000e+00 +
              (-1.00000000000000000e+00 * st->rz3))))) +
          (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rz3)))));
    ((st->f1_z3)[1] =
         (((st->f1_z3)[1] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f1_z3)[2] * -(st->dixz3))));
    ((st->f1_z3)[3] = (5.00000000000000000e-01 * st->rz3));
    ((st->f1_z3)[2] =
         (((st->f1_z3)[2] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->f1_z3)[3] * -(st->dixz3))));
    ((st->f1_z3)[3] = ((st->f1_z3)[3] * (st->dixz3 + 1.00000000000000000e+00)));
    ((st->if1_z3)[0] = 1);
    ((st->if1_z3)[1] = 1);
    ((st->if1_z3)[3] = 0);
    ((st->if1_z3)[4] = 0);
    ((st->if1_z3)[1] = (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
                          double tmppowvar =
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * st->rz3));

                          (tmppowvar * tmppowvar);
                        }))));
    ((st->if1_z3)[0] =
         (((st->if1_z3)[0] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->if1_z3)[1] * -(st->dixz3))));
    ((st->if1_z3)[2] = ((2.50000000000000000e-01 * ({
                           double tmppowvar = st->rz3;

                           (tmppowvar * tmppowvar);
                         })) +
                        (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * st->rz3) + ({
                             double tmppowvar = st->rz3;

                             (tmppowvar * tmppowvar);
                           }))))));
    ((st->if1_z3)[1] =
         (((st->if1_z3)[1] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->if1_z3)[2] * -(st->dixz3))));
    ((st->if1_z3)[3] = (2.50000000000000000e-01 * ({
                          double tmppowvar = st->rz3;

                          (tmppowvar * tmppowvar);
                        })));
    ((st->if1_z3)[2] =
         (((st->if1_z3)[2] * (st->dixz3 + 1.00000000000000000e+00)) +
          ((st->if1_z3)[3] * -(st->dixz3))));
    ((st->if1_z3)[3] =
         ((st->if1_z3)[3] * (st->dixz3 + 1.00000000000000000e+00)));
    (st->iBy =
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

                        for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                          int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                          (tmpBfd =
                               (tmpBfd +
                                ((shB1)[((allidx * 3) + 0)] *
                                 ((st->f0_x2)[xyzx] *
                                  (((st->if1_z2)[xyzz] - (st->if1_z1)[xyzz]) *
                                   (st->f1_y2)[xyzy])))));
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

                        for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                          int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                          (tmpBfd =
                               (tmpBfd +
                                ((shB1)[((allidx * 3) + 0)] *
                                 ((st->f0_x2)[xyzx] *
                                  (((st->if1_z3)[xyzz] - (st->if1_z2)[xyzz]) *
                                   (st->f1_y2)[xyzy])))));
                        }
                      }
                    }
                  }
                }
              }
              tmpBfd;
            })))));
    st->y3 = (((-1.00000000000000000e+00 * st->y1) +
               (2.00000000000000000e+00 * st->y2)) +
              (({
                 double tmppowvar = TX0;

                 (tmppowvar * tmppowvar);
               }) *
               ((-1 * (Deltat * (QE_MASS * st->iBy))) *
                (1.00000000000000000e+00 / ({
                   double tmppowvar =
                       ((({
                           double tmppowvar = DELTA_Y;

                           (tmppowvar * tmppowvar);
                         }) *
                         ({
                           double tmppowvar = TX0;

                           (tmppowvar * tmppowvar);
                         })) +
                        ((2.00000000000000000e+00 * (({
                                                       double tmppowvar =
                                                           DELTA_Y;

                                                       (tmppowvar * tmppowvar);
                                                     }) *
                                                     (TX0 * st->x2))) +
                         (({
                            double tmppowvar = DELTA_Y;

                            (tmppowvar * tmppowvar);
                          }) *
                          ({
                            double tmppowvar = st->x2;

                            (tmppowvar * tmppowvar);
                          }))));

                   tmppowvar;
                 })))));

    st->ry3 = ((st->y3 - YO) - floor((st->y3 - YO)));

    st->dixy3 = (floor((st->y3 - YO)) - Midy);

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f0_y3)[i] = 0);
      }
    }
    ((st->f0_y3)[1] = (2.50000000000000000e-01 * ({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->ry3));

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_y3)[0] =
         (((st->f0_y3)[0] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f0_y3)[1] * -(st->dixy3))));
    ((st->f0_y3)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (({
                           double tmppowvar =
                               (1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * st->ry3));

                           (tmppowvar * tmppowvar);
                         }) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * st->ry3)))))));
    ((st->f0_y3)[1] =
         (((st->f0_y3)[1] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f0_y3)[2] * -(st->dixy3))));
    ((st->f0_y3)[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->ry3) + ({
                                         double tmppowvar = st->ry3;

                                         (tmppowvar * tmppowvar);
                                       })))));
    ((st->f0_y3)[2] =
         (((st->f0_y3)[2] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f0_y3)[3] * -(st->dixy3))));
    ((st->f0_y3)[4] = (2.50000000000000000e-01 * ({
                         double tmppowvar = st->ry3;

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_y3)[3] =
         (((st->f0_y3)[3] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f0_y3)[4] * -(st->dixy3))));
    ((st->f0_y3)[4] = ((st->f0_y3)[4] * (st->dixy3 + 1.00000000000000000e+00)));
    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f1_y3)[i] = 0);
      }
    }
    ((st->f1_y3)[1] =
         (5.00000000000000000e-01 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry3))));
    ((st->f1_y3)[0] =
         (((st->f1_y3)[0] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f1_y3)[1] * -(st->dixy3))));
    ((st->f1_y3)[2] =
         ((2.50000000000000000e-01 *
           (2.00000000000000000e+00 +
            (-2.00000000000000000e+00 *
             (1.00000000000000000e+00 +
              (-1.00000000000000000e+00 * st->ry3))))) +
          (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->ry3)))));
    ((st->f1_y3)[1] =
         (((st->f1_y3)[1] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f1_y3)[2] * -(st->dixy3))));
    ((st->f1_y3)[3] = (5.00000000000000000e-01 * st->ry3));
    ((st->f1_y3)[2] =
         (((st->f1_y3)[2] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->f1_y3)[3] * -(st->dixy3))));
    ((st->f1_y3)[3] = ((st->f1_y3)[3] * (st->dixy3 + 1.00000000000000000e+00)));
    ((st->if1_y3)[0] = 1);
    ((st->if1_y3)[1] = 1);
    ((st->if1_y3)[3] = 0);
    ((st->if1_y3)[4] = 0);
    ((st->if1_y3)[1] = (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
                          double tmppowvar =
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * st->ry3));

                          (tmppowvar * tmppowvar);
                        }))));
    ((st->if1_y3)[0] =
         (((st->if1_y3)[0] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->if1_y3)[1] * -(st->dixy3))));
    ((st->if1_y3)[2] = ((2.50000000000000000e-01 * ({
                           double tmppowvar = st->ry3;

                           (tmppowvar * tmppowvar);
                         })) +
                        (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * st->ry3) + ({
                             double tmppowvar = st->ry3;

                             (tmppowvar * tmppowvar);
                           }))))));
    ((st->if1_y3)[1] =
         (((st->if1_y3)[1] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->if1_y3)[2] * -(st->dixy3))));
    ((st->if1_y3)[3] = (2.50000000000000000e-01 * ({
                          double tmppowvar = st->ry3;

                          (tmppowvar * tmppowvar);
                        })));
    ((st->if1_y3)[2] =
         (((st->if1_y3)[2] * (st->dixy3 + 1.00000000000000000e+00)) +
          ((st->if1_y3)[3] * -(st->dixy3))));
    ((st->if1_y3)[3] =
         ((st->if1_y3)[3] * (st->dixy3 + 1.00000000000000000e+00)));
    (st->iBx =
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

                       for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                         int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                         (tmpBfd =
                              (tmpBfd +
                               ((shB1)[((allidx * 3) + 1)] *
                                ((st->f0_y2)[xyzy] *
                                 (((st->if1_z2)[xyzz] - (st->if1_z1)[xyzz]) *
                                  (st->f1_x2)[xyzx])))));
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

                        for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                          int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                          (tmpBfd =
                               (tmpBfd +
                                ((shB1)[((allidx * 3) + 1)] *
                                 ((st->f0_y2)[xyzy] *
                                  (((st->if1_z3)[xyzz] - (st->if1_z2)[xyzz]) *
                                   (st->f1_x2)[xyzx])))));
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

                      for ((xyzy = 0); (xyzy < 5); (xyzy = (xyzy + 1))) {
                        {
                          long xyzx;

                          for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                            int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                            (tmpBfd =
                                 (tmpBfd +
                                  ((shB1)[((allidx * 3) + 2)] *
                                   ((st->f0_z1)[xyzz] *
                                    (((st->if1_y2)[xyzy] - (st->if1_y1)[xyzy]) *
                                     (st->f1_x2)[xyzx])))));
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

                          for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
                            int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

                            (tmpBfd =
                                 (tmpBfd +
                                  ((shB1)[((allidx * 3) + 2)] *
                                   ((st->f0_z3)[xyzz] *
                                    (((st->if1_y3)[xyzy] - (st->if1_y2)[xyzy]) *
                                     (st->f1_x2)[xyzx])))));
                          }
                        }
                      }
                    }
                  }
                }
                tmpBfd;
              })))))));
    st->x3 =
        (((1.00000000000000000e+00 / ({
             double tmppowvar = DELTA_X;

             (tmppowvar * tmppowvar);
           })) *
          ((1.00000000000000000e+00 / ({
              double tmppowvar = TX0;

              (tmppowvar * tmppowvar);
            })) *
           ((-1.00000000000000000e+00 * (({
                                           double tmppowvar = DELTA_X;

                                           (tmppowvar * tmppowvar);
                                         }) *
                                         (({
                                            double tmppowvar = TX0;

                                            (tmppowvar * tmppowvar);
                                          }) *
                                          st->x1))) +
            ((2.00000000000000000e+00 * (({
                                           double tmppowvar = DELTA_X;

                                           (tmppowvar * tmppowvar);
                                         }) *
                                         (({
                                            double tmppowvar = TX0;

                                            (tmppowvar * tmppowvar);
                                          }) *
                                          st->x2))) +
             ((((({
                   double tmppowvar = DELTA_Y;

                   (tmppowvar * tmppowvar);
                 }) *
                 TX0) +
                (({
                   double tmppowvar = DELTA_Y;

                   (tmppowvar * tmppowvar);
                 }) *
                 st->x2)) *
               ({
                 double tmppowvar = st->y1;

                 (tmppowvar * tmppowvar);
               })) +
              ((((-2.00000000000000000e+00 * (({
                                                double tmppowvar = DELTA_Y;

                                                (tmppowvar * tmppowvar);
                                              }) *
                                              TX0)) +
                 (-2.00000000000000000e+00 * (({
                                                double tmppowvar = DELTA_Y;

                                                (tmppowvar * tmppowvar);
                                              }) *
                                              st->x2))) *
                (st->y1 * st->y2)) +
               ((((2.00000000000000000e+00 * (({
                                                double tmppowvar = DELTA_Y;

                                                (tmppowvar * tmppowvar);
                                              }) *
                                              TX0)) +
                  (2.00000000000000000e+00 * (({
                                                double tmppowvar = DELTA_Y;

                                                (tmppowvar * tmppowvar);
                                              }) *
                                              st->x2))) *
                 ({
                   double tmppowvar = st->y2;

                   (tmppowvar * tmppowvar);
                 })) +
                ((((-2.00000000000000000e+00 * (({
                                                  double tmppowvar = DELTA_Y;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                TX0)) +
                   (-2.00000000000000000e+00 * (({
                                                  double tmppowvar = DELTA_Y;

                                                  (tmppowvar * tmppowvar);
                                                }) *
                                                st->x2))) *
                  (st->y2 * st->y3)) +
                 (((({
                      double tmppowvar = DELTA_Y;

                      (tmppowvar * tmppowvar);
                    }) *
                    TX0) +
                   (({
                      double tmppowvar = DELTA_Y;

                      (tmppowvar * tmppowvar);
                    }) *
                    st->x2)) *
                  ({
                    double tmppowvar = st->y3;

                    (tmppowvar * tmppowvar);
                  })))))))))) +
         ((1.00000000000000000e+00 / ({
             double tmppowvar = DELTA_X;

             (tmppowvar * tmppowvar);
           })) *
          (-1 * (Deltat * (QE_MASS * st->iBx)))));

    st->rx3 = ((st->x3 - XO) - floor((st->x3 - XO)));

    st->dixx3 = (floor((st->x3 - XO)) - Midx);

    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f0_x3)[i] = 0);
      }
    }
    ((st->f0_x3)[1] = (2.50000000000000000e-01 * ({
                         double tmppowvar =
                             (1.00000000000000000e+00 +
                              (-1.00000000000000000e+00 * st->rx3));

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_x3)[0] =
         (((st->f0_x3)[0] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f0_x3)[1] * -(st->dixx3))));
    ((st->f0_x3)[2] = (-2.50000000000000000e-01 *
                       (-1.00000000000000000e+00 +
                        (({
                           double tmppowvar =
                               (1.00000000000000000e+00 +
                                (-1.00000000000000000e+00 * st->rx3));

                           (tmppowvar * tmppowvar);
                         }) +
                         (-2.00000000000000000e+00 *
                          (1.00000000000000000e+00 +
                           (-1.00000000000000000e+00 * st->rx3)))))));
    ((st->f0_x3)[1] =
         (((st->f0_x3)[1] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f0_x3)[2] * -(st->dixx3))));
    ((st->f0_x3)[3] =
         (-2.50000000000000000e-01 *
          (-1.00000000000000000e+00 + ((-2.00000000000000000e+00 * st->rx3) + ({
                                         double tmppowvar = st->rx3;

                                         (tmppowvar * tmppowvar);
                                       })))));
    ((st->f0_x3)[2] =
         (((st->f0_x3)[2] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f0_x3)[3] * -(st->dixx3))));
    ((st->f0_x3)[4] = (2.50000000000000000e-01 * ({
                         double tmppowvar = st->rx3;

                         (tmppowvar * tmppowvar);
                       })));
    ((st->f0_x3)[3] =
         (((st->f0_x3)[3] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f0_x3)[4] * -(st->dixx3))));
    ((st->f0_x3)[4] = ((st->f0_x3)[4] * (st->dixx3 + 1.00000000000000000e+00)));
    {
      long i;

      for ((i = 0); (i < 5); (i = (i + 1))) {
        ((st->f1_x3)[i] = 0);
      }
    }
    ((st->f1_x3)[1] =
         (5.00000000000000000e-01 *
          (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx3))));
    ((st->f1_x3)[0] =
         (((st->f1_x3)[0] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f1_x3)[1] * -(st->dixx3))));
    ((st->f1_x3)[2] =
         ((2.50000000000000000e-01 *
           (2.00000000000000000e+00 +
            (-2.00000000000000000e+00 *
             (1.00000000000000000e+00 +
              (-1.00000000000000000e+00 * st->rx3))))) +
          (5.00000000000000000e-01 *
           (1.00000000000000000e+00 + (-1.00000000000000000e+00 * st->rx3)))));
    ((st->f1_x3)[1] =
         (((st->f1_x3)[1] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f1_x3)[2] * -(st->dixx3))));
    ((st->f1_x3)[3] = (5.00000000000000000e-01 * st->rx3));
    ((st->f1_x3)[2] =
         (((st->f1_x3)[2] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->f1_x3)[3] * -(st->dixx3))));
    ((st->f1_x3)[3] = ((st->f1_x3)[3] * (st->dixx3 + 1.00000000000000000e+00)));
    ((st->if1_x3)[0] = 1);
    ((st->if1_x3)[1] = 1);
    ((st->if1_x3)[3] = 0);
    ((st->if1_x3)[4] = 0);
    ((st->if1_x3)[1] = (1.00000000000000000e+00 + (-2.50000000000000000e-01 * ({
                          double tmppowvar =
                              (1.00000000000000000e+00 +
                               (-1.00000000000000000e+00 * st->rx3));

                          (tmppowvar * tmppowvar);
                        }))));
    ((st->if1_x3)[0] =
         (((st->if1_x3)[0] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->if1_x3)[1] * -(st->dixx3))));
    ((st->if1_x3)[2] = ((2.50000000000000000e-01 * ({
                           double tmppowvar = st->rx3;

                           (tmppowvar * tmppowvar);
                         })) +
                        (-2.50000000000000000e-01 *
                         (-1.00000000000000000e+00 +
                          ((-2.00000000000000000e+00 * st->rx3) + ({
                             double tmppowvar = st->rx3;

                             (tmppowvar * tmppowvar);
                           }))))));
    ((st->if1_x3)[1] =
         (((st->if1_x3)[1] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->if1_x3)[2] * -(st->dixx3))));
    ((st->if1_x3)[3] = (2.50000000000000000e-01 * ({
                          double tmppowvar = st->rx3;

                          (tmppowvar * tmppowvar);
                        })));
    ((st->if1_x3)[2] =
         (((st->if1_x3)[2] * (st->dixx3 + 1.00000000000000000e+00)) +
          ((st->if1_x3)[3] * -(st->dixx3))));
    ((st->if1_x3)[3] =
         ((st->if1_x3)[3] * (st->dixx3 + 1.00000000000000000e+00)));
  }
}

static __device__ __forceinline__ void pushJ_vlo_K3_deposit_writeback_particle(
    pushJ_vlo_state_t *st, double *shJ0, double *Jtmp_shd, double *particle_buf,
    double Deltat, long __idx, long __xlen, int g_inner, long load0,
    double Charge0, double Tori_X0, double grid_geo_x, double grid_geo_y,
    double grid_geo_z, double XO, double YO, double ZO, double zmid, int bBidx,
    int bBidy, int bBidz) {
  st->DT = Deltat;

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
                   (st->simd_mask * (((st->if1_x2)[xyzx] - (st->if1_x1)[xyzx]) *
                                     ((st->f0_y1)[xyzy] * (st->f0_z1)[xyzz]))));
              if (st->_gen_long_for_opt_loop_already_idx_0) {
                (Jtmp = 0);

              }

              {
                if ((IDX_LOCAL_XLEN == 32) || (IDX_LOCAL_XLEN == 64)) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 16)));

                }

                if (IDX_LOCAL_XLEN >= 16) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 8)));

                }

                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 4)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 2)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 1)));
                if (IDX_LOCAL_XLEN <= 32) {
                  if (__idx == 0) {
                    ((shJ0)[((allidx * 3) + 0)] =
                         ((shJ0)[((allidx * 3) + 0)] +
                          ((grid_geo_x *
                            ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                             Charge0)) *
                           Jtmp)));

                  }

                } else {
                  __syncthreads();
                  if ((__idx % 32) == 0) {
                    ((Jtmp_shd)[(__idx >> 5)] = Jtmp);

                  }

                  __syncthreads();
                  if (__idx == 0) {
                    (Jtmp = (Jtmp + (Jtmp_shd)[1]));
                    ((shJ0)[((allidx * 3) + 0)] =
                         ((shJ0)[((allidx * 3) + 0)] +
                          ((grid_geo_x *
                            ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                             Charge0)) *
                           Jtmp)));

                  }

                  __syncthreads();
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

            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
              int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

              double Jtmp;

              (Jtmp =
                   (st->simd_mask * (((st->if1_y2)[xyzy] - (st->if1_y1)[xyzy]) *
                                     ((st->f0_x2)[xyzx] * (st->f0_z1)[xyzz]))));
              if (st->_gen_long_for_opt_loop_already_idx_0) {
                (Jtmp = 0);

              }

              {
                if ((IDX_LOCAL_XLEN == 32) || (IDX_LOCAL_XLEN == 64)) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 16)));

                }

                if (IDX_LOCAL_XLEN >= 16) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 8)));

                }

                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 4)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 2)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 1)));
                if (IDX_LOCAL_XLEN <= 32) {
                  if (__idx == 0) {
                    ((shJ0)[((allidx * 3) + 1)] =
                         ((shJ0)[((allidx * 3) + 1)] +
                          ((grid_geo_y *
                            (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                             Charge0)) *
                           Jtmp)));

                  }

                } else {
                  __syncthreads();
                  if ((__idx % 32) == 0) {
                    ((Jtmp_shd)[(__idx >> 5)] = Jtmp);

                  }

                  __syncthreads();
                  if (__idx == 0) {
                    (Jtmp = (Jtmp + (Jtmp_shd)[1]));
                    ((shJ0)[((allidx * 3) + 1)] =
                         ((shJ0)[((allidx * 3) + 1)] +
                          ((grid_geo_y *
                            (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                             Charge0)) *
                           Jtmp)));

                  }

                  __syncthreads();
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

            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
              int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

              double Jtmp;

              (Jtmp =
                   (st->simd_mask * (((st->if1_z3)[xyzz] - (st->if1_z1)[xyzz]) *
                                     ((st->f0_x2)[xyzx] * (st->f0_y2)[xyzy]))));
              if (st->_gen_long_for_opt_loop_already_idx_0) {
                (Jtmp = 0);

              }

              {
                if ((IDX_LOCAL_XLEN == 32) || (IDX_LOCAL_XLEN == 64)) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 16)));

                }

                if (IDX_LOCAL_XLEN >= 16) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 8)));

                }

                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 4)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 2)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 1)));
                if (IDX_LOCAL_XLEN <= 32) {
                  if (__idx == 0) {
                    ((shJ0)[((allidx * 3) + 2)] =
                         ((shJ0)[((allidx * 3) + 2)] +
                          ((grid_geo_z *
                            ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                             Charge0)) *
                           Jtmp)));

                  }

                } else {
                  __syncthreads();
                  if ((__idx % 32) == 0) {
                    ((Jtmp_shd)[(__idx >> 5)] = Jtmp);

                  }

                  __syncthreads();
                  if (__idx == 0) {
                    (Jtmp = (Jtmp + (Jtmp_shd)[1]));
                    ((shJ0)[((allidx * 3) + 2)] =
                         ((shJ0)[((allidx * 3) + 2)] +
                          ((grid_geo_z *
                            ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                             Charge0)) *
                           Jtmp)));

                  }

                  __syncthreads();
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

            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
              int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

              double Jtmp;

              (Jtmp =
                   (st->simd_mask * (((st->if1_y3)[xyzy] - (st->if1_y2)[xyzy]) *
                                     ((st->f0_x2)[xyzx] * (st->f0_z3)[xyzz]))));
              if (st->_gen_long_for_opt_loop_already_idx_0) {
                (Jtmp = 0);

              }

              {
                if ((IDX_LOCAL_XLEN == 32) || (IDX_LOCAL_XLEN == 64)) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 16)));

                }

                if (IDX_LOCAL_XLEN >= 16) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 8)));

                }

                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 4)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 2)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 1)));
                if (IDX_LOCAL_XLEN <= 32) {
                  if (__idx == 0) {
                    ((shJ0)[((allidx * 3) + 1)] =
                         ((shJ0)[((allidx * 3) + 1)] +
                          ((grid_geo_y *
                            (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                             Charge0)) *
                           Jtmp)));

                  }

                } else {
                  __syncthreads();
                  if ((__idx % 32) == 0) {
                    ((Jtmp_shd)[(__idx >> 5)] = Jtmp);

                  }

                  __syncthreads();
                  if (__idx == 0) {
                    (Jtmp = (Jtmp + (Jtmp_shd)[1]));
                    ((shJ0)[((allidx * 3) + 1)] =
                         ((shJ0)[((allidx * 3) + 1)] +
                          ((grid_geo_y *
                            (((Tori_X0 + (XO + (bBidx + xyzx))) / Tori_X0) *
                             Charge0)) *
                           Jtmp)));

                  }

                  __syncthreads();
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

            for ((xyzx = 0); (xyzx < 5); (xyzx = (xyzx + 1))) {
              int allidx = (xyzx + (5 * (xyzy + (5 * xyzz))));

              double Jtmp;

              (Jtmp =
                   (st->simd_mask * (((st->if1_x3)[xyzx] - (st->if1_x2)[xyzx]) *
                                     ((st->f0_y3)[xyzy] * (st->f0_z3)[xyzz]))));
              if (st->_gen_long_for_opt_loop_already_idx_0) {
                (Jtmp = 0);

              }

              {
                if ((IDX_LOCAL_XLEN == 32) || (IDX_LOCAL_XLEN == 64)) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 16)));

                }

                if (IDX_LOCAL_XLEN >= 16) {
                  (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 8)));

                }

                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 4)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 2)));
                (Jtmp = (Jtmp + __shfl_down_sync(FULL_MASK, Jtmp, 1)));
                if (IDX_LOCAL_XLEN <= 32) {
                  if (__idx == 0) {
                    ((shJ0)[((allidx * 3) + 0)] =
                         ((shJ0)[((allidx * 3) + 0)] +
                          ((grid_geo_x *
                            ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                             Charge0)) *
                           Jtmp)));

                  }

                } else {
                  __syncthreads();
                  if ((__idx % 32) == 0) {
                    ((Jtmp_shd)[(__idx >> 5)] = Jtmp);

                  }

                  __syncthreads();
                  if (__idx == 0) {
                    (Jtmp = (Jtmp + (Jtmp_shd)[1]));
                    ((shJ0)[((allidx * 3) + 0)] =
                         ((shJ0)[((allidx * 3) + 0)] +
                          ((grid_geo_x *
                            ((Tori_X0 / (Tori_X0 + (XO + (bBidx + xyzx)))) *
                             Charge0)) *
                           Jtmp)));

                  }

                  __syncthreads();
                }
              }
            }
          }
        }
      }
    }
  }

  (st->newvx = ((st->x3 - st->x2) / st->DT));
  (st->newvy = ((st->y3 - st->y2) / st->DT));
  (st->newvz = ((st->z3 - st->z2) / st->DT));
  (st->newxx = (st->x3 - XO));
  (st->newxy = (st->y3 - YO));
  (st->newxz = ((st->z3 + zmid) - ZO));
  (st->newxx = (st->newxx + 5.00000000000000000e-01));
  (st->newxy = (st->newxy + 5.00000000000000000e-01));
  (st->newxz = (st->newxz + 5.00000000000000000e-01));
  ((st->local_particle_head)[0] = st->newxx);
  ((st->local_particle_head)[1] = st->newxy);
  ((st->local_particle_head)[2] = st->newxz);
  ((st->local_particle_head)[3] = st->newvx);
  ((st->local_particle_head)[4] = st->newvy);
  ((st->local_particle_head)[5] = st->newvz);
  {
    long stmpg1;
    for ((stmpg1 = 0); (stmpg1 < 6); (stmpg1 = (stmpg1 + 1))) {
      int cid = (g_inner + __idx);
      if (cid < load0) {
        particle_buf[stmpg1 + cid * 6] = st->local_particle_head[stmpg1];
      }
    }
  }
}

static __device__ __forceinline__ void
pushJ_vlo_K3_write_FoutJ_from_shared(double *shJ0, double *FoutJ, long __idy,
                                     long __idx, long __xlen, int bBidx,
                                     int bBidy, int bBidz, long XLEN, long YLEN,
                                     long ZLEN, int ovlp, int num_ele) {
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
              long lgGG817621_1 = 0;

              for (; (lgGG817621_1 < (3 * 5));
                   (lgGG817621_1 = (lgGG817621_1 + __xlen))) {
                int ridx = (lgGG817621_1 + __idx);

                if (ridx < (3 * 5)) {
                  (((FoutJ + ((num_ele * (__idy * ((XLEN + (2 * ovlp)) *
                                                   ((YLEN + (2 * ovlp)) *
                                                    (ZLEN + (2 * ovlp)))))) +
                              (0 + (num_ele *
                                    ((bBidx + ovlp) +
                                     ((XLEN + (2 * ovlp)) *
                                      (((xyzy + bBidy) + ovlp) +
                                       ((YLEN + (2 * ovlp)) *
                                        ((xyzz + bBidz) + ovlp))))))))))[ridx] =
                       ((shJ0 + total_idx))[ridx]);

                }
              }
            }
          }
        }
      }
    }
  }
}

#endif

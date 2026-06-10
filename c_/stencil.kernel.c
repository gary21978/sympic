
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 1
void c_Yee_FDTD_W04_0_scmc_kernel(double *outEB, double *inEB, long y_cpu_core,
                                  long numvec, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long xblock, long yblock,
                                  long zblock, int num_ele, double DT,
                                  long scmc_internal_g_idy,
                                  long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long i = 0;

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

  for ((i = local_ymin); (i < local_ymax); i++) {
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
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) +
                     (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    ((outEB)[(blk_offset + realidx)] =
                         ((1.08333333333333326e+00 *
                           ((1.08333333333333326e+00 *
                             ((1.08333333333333326e+00 *
                               ((inEB + blk_offset_t1))[(
                                   l + (num_ele *
                                        (((0 + xidx) + ovlp) +
                                         (xblock * (((0 + xyzy) + ovlp) +
                                                    (yblock * ((0 + xyzz) +
                                                               ovlp)))))))]) +
                              ((-4.16666666666666644e-02 *
                                ((inEB + blk_offset_t1))[(
                                    l + (num_ele *
                                         (((0 + xidx) + ovlp) +
                                          (xblock * (((0 + xyzy) + ovlp) +
                                                     (yblock * ((1 + xyzz) +
                                                                ovlp)))))))]) +
                               (-4.16666666666666644e-02 *
                                ((inEB + blk_offset_t1))[(
                                    l +
                                    (num_ele *
                                     (((0 + xidx) + ovlp) +
                                      (xblock * (((0 + xyzy) + ovlp) +
                                                 (yblock * ((-1 + xyzz) +
                                                            ovlp)))))))])))) +
                            ((-4.16666666666666644e-02 *
                              ((1.08333333333333326e+00 *
                                ((inEB + blk_offset_t1))[(
                                    l + (num_ele *
                                         (((0 + xidx) + ovlp) +
                                          (xblock * (((1 + xyzy) + ovlp) +
                                                     (yblock * ((0 + xyzz) +
                                                                ovlp)))))))]) +
                               ((-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((0 + xidx) + ovlp) +
                                           (xblock * (((1 + xyzy) + ovlp) +
                                                      (yblock * ((1 + xyzz) +
                                                                 ovlp)))))))]) +
                                (-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l +
                                     (num_ele *
                                      (((0 + xidx) + ovlp) +
                                       (xblock * (((1 + xyzy) + ovlp) +
                                                  (yblock * ((-1 + xyzz) +
                                                             ovlp)))))))])))) +
                             (-4.16666666666666644e-02 *
                              ((1.08333333333333326e+00 *
                                ((inEB + blk_offset_t1))[(
                                    l + (num_ele *
                                         (((0 + xidx) + ovlp) +
                                          (xblock * (((-1 + xyzy) + ovlp) +
                                                     (yblock * ((0 + xyzz) +
                                                                ovlp)))))))]) +
                               ((-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((0 + xidx) + ovlp) +
                                           (xblock * (((-1 + xyzy) + ovlp) +
                                                      (yblock * ((1 + xyzz) +
                                                                 ovlp)))))))]) +
                                (-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((0 + xidx) + ovlp) +
                                           (xblock *
                                            (((-1 + xyzy) + ovlp) +
                                             (yblock * ((-1 + xyzz) +
                                                        ovlp)))))))]))))))) +
                          ((-4.16666666666666644e-02 *
                            ((1.08333333333333326e+00 *
                              ((1.08333333333333326e+00 *
                                ((inEB + blk_offset_t1))[(
                                    l + (num_ele *
                                         (((1 + xidx) + ovlp) +
                                          (xblock * (((0 + xyzy) + ovlp) +
                                                     (yblock * ((0 + xyzz) +
                                                                ovlp)))))))]) +
                               ((-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((1 + xidx) + ovlp) +
                                           (xblock * (((0 + xyzy) + ovlp) +
                                                      (yblock * ((1 + xyzz) +
                                                                 ovlp)))))))]) +
                                (-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l +
                                     (num_ele *
                                      (((1 + xidx) + ovlp) +
                                       (xblock * (((0 + xyzy) + ovlp) +
                                                  (yblock * ((-1 + xyzz) +
                                                             ovlp)))))))])))) +
                             ((-4.16666666666666644e-02 *
                               ((1.08333333333333326e+00 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((1 + xidx) + ovlp) +
                                           (xblock * (((1 + xyzy) + ovlp) +
                                                      (yblock * ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                ((-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l +
                                      (num_ele *
                                       (((1 + xidx) + ovlp) +
                                        (xblock * (((1 + xyzy) + ovlp) +
                                                   (yblock * ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                 (-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l +
                                      (num_ele *
                                       (((1 + xidx) + ovlp) +
                                        (xblock * (((1 + xyzy) + ovlp) +
                                                   (yblock * ((-1 + xyzz) +
                                                              ovlp)))))))])))) +
                              (-4.16666666666666644e-02 *
                               ((1.08333333333333326e+00 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((1 + xidx) + ovlp) +
                                           (xblock * (((-1 + xyzy) + ovlp) +
                                                      (yblock * ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                ((-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l +
                                      (num_ele *
                                       (((1 + xidx) + ovlp) +
                                        (xblock * (((-1 + xyzy) + ovlp) +
                                                   (yblock * ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                 (-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l + (num_ele *
                                           (((1 + xidx) + ovlp) +
                                            (xblock *
                                             (((-1 + xyzy) + ovlp) +
                                              (yblock * ((-1 + xyzz) +
                                                         ovlp)))))))]))))))) +
                           (-4.16666666666666644e-02 *
                            ((1.08333333333333326e+00 *
                              ((1.08333333333333326e+00 *
                                ((inEB + blk_offset_t1))[(
                                    l + (num_ele *
                                         (((-1 + xidx) + ovlp) +
                                          (xblock * (((0 + xyzy) + ovlp) +
                                                     (yblock * ((0 + xyzz) +
                                                                ovlp)))))))]) +
                               ((-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((-1 + xidx) + ovlp) +
                                           (xblock * (((0 + xyzy) + ovlp) +
                                                      (yblock * ((1 + xyzz) +
                                                                 ovlp)))))))]) +
                                (-4.16666666666666644e-02 *
                                 ((inEB + blk_offset_t1))[(
                                     l +
                                     (num_ele *
                                      (((-1 + xidx) + ovlp) +
                                       (xblock * (((0 + xyzy) + ovlp) +
                                                  (yblock * ((-1 + xyzz) +
                                                             ovlp)))))))])))) +
                             ((-4.16666666666666644e-02 *
                               ((1.08333333333333326e+00 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((-1 + xidx) + ovlp) +
                                           (xblock * (((1 + xyzy) + ovlp) +
                                                      (yblock * ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                ((-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l +
                                      (num_ele *
                                       (((-1 + xidx) + ovlp) +
                                        (xblock * (((1 + xyzy) + ovlp) +
                                                   (yblock * ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                 (-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l +
                                      (num_ele *
                                       (((-1 + xidx) + ovlp) +
                                        (xblock * (((1 + xyzy) + ovlp) +
                                                   (yblock * ((-1 + xyzz) +
                                                              ovlp)))))))])))) +
                              (-4.16666666666666644e-02 *
                               ((1.08333333333333326e+00 *
                                 ((inEB + blk_offset_t1))[(
                                     l + (num_ele *
                                          (((-1 + xidx) + ovlp) +
                                           (xblock * (((-1 + xyzy) + ovlp) +
                                                      (yblock * ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                ((-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l +
                                      (num_ele *
                                       (((-1 + xidx) + ovlp) +
                                        (xblock * (((-1 + xyzy) + ovlp) +
                                                   (yblock * ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                 (-4.16666666666666644e-02 *
                                  ((inEB + blk_offset_t1))[(
                                      l + (num_ele *
                                           (((-1 + xidx) + ovlp) +
                                            (xblock *
                                             (((-1 + xyzy) + ovlp) +
                                              (yblock * ((-1 + xyzz) +
                                                         ovlp)))))))]))))))))));
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
void c_Yee_FDTD_W04_1_scmc_kernel(double *outEB, double *inEB, long y_cpu_core,
                                  long numvec, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long xblock, long yblock,
                                  long zblock, int num_ele, double DT,
                                  long scmc_internal_g_idy,
                                  long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long i = 0;

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

  for ((i = local_ymin); (i < local_ymax); i++) {
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
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) +
                     (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    ((outEB)[(blk_offset + realidx)] =
                         (((l == 0))
                              ? (((1.08333333333333326e+00 *
                                   ((1.08333333333333326e+00 *
                                     ((inEB + blk_offset_t1))[(
                                         l +
                                         (num_ele *
                                          ((xidx + ovlp) +
                                           (xblock * (((0 + xyzy) + ovlp) +
                                                      (yblock * ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                    ((-4.16666666666666644e-02 *
                                      ((inEB + blk_offset_t1))[(
                                          l + (num_ele *
                                               ((xidx + ovlp) +
                                                (xblock *
                                                 (((0 + xyzy) + ovlp) +
                                                  (yblock *
                                                   ((1 + xyzz) + ovlp)))))))]) +
                                     (-4.16666666666666644e-02 *
                                      ((inEB + blk_offset_t1))[(
                                          l + (num_ele *
                                               ((xidx + ovlp) +
                                                (xblock *
                                                 (((0 + xyzy) + ovlp) +
                                                  (yblock * ((-1 + xyzz) +
                                                             ovlp)))))))])))) +
                                  ((-4.16666666666666644e-02 *
                                    ((1.08333333333333326e+00 *
                                      ((inEB + blk_offset_t1))[(
                                          l + (num_ele *
                                               ((xidx + ovlp) +
                                                (xblock *
                                                 (((1 + xyzy) + ovlp) +
                                                  (yblock *
                                                   ((0 + xyzz) + ovlp)))))))]) +
                                     ((-4.16666666666666644e-02 *
                                       ((inEB + blk_offset_t1))[(
                                           l + (num_ele *
                                                ((xidx + ovlp) +
                                                 (xblock *
                                                  (((1 + xyzy) + ovlp) +
                                                   (yblock * ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                      (-4.16666666666666644e-02 *
                                       ((inEB + blk_offset_t1))[(
                                           l + (num_ele *
                                                ((xidx + ovlp) +
                                                 (xblock *
                                                  (((1 + xyzy) + ovlp) +
                                                   (yblock * ((-1 + xyzz) +
                                                              ovlp)))))))])))) +
                                   (-4.16666666666666644e-02 *
                                    ((1.08333333333333326e+00 *
                                      ((inEB + blk_offset_t1))[(
                                          l + (num_ele *
                                               ((xidx + ovlp) +
                                                (xblock *
                                                 (((-1 + xyzy) + ovlp) +
                                                  (yblock *
                                                   ((0 + xyzz) + ovlp)))))))]) +
                                     ((-4.16666666666666644e-02 *
                                       ((inEB + blk_offset_t1))[(
                                           l + (num_ele *
                                                ((xidx + ovlp) +
                                                 (xblock *
                                                  (((-1 + xyzy) + ovlp) +
                                                   (yblock * ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                      (-4.16666666666666644e-02 *
                                       ((inEB + blk_offset_t1))[(
                                           l +
                                           (num_ele *
                                            ((xidx + ovlp) +
                                             (xblock *
                                              (((-1 + xyzy) + ovlp) +
                                               (yblock * ((-1 + xyzz) +
                                                          ovlp)))))))])))))))
                              : ((((l == 1))
                                      ? (((1.08333333333333326e+00 *
                                           ((1.08333333333333326e+00 *
                                             ((inEB + blk_offset_t1))[(
                                                 l +
                                                 (num_ele *
                                                  (((0 + xidx) + ovlp) +
                                                   (xblock *
                                                    ((xyzy + ovlp) +
                                                     (yblock * ((0 + xyzz) +
                                                                ovlp)))))))]) +
                                            ((-4.16666666666666644e-02 *
                                              ((inEB + blk_offset_t1))[(
                                                  l +
                                                  (num_ele *
                                                   (((1 + xidx) + ovlp) +
                                                    (xblock *
                                                     ((xyzy + ovlp) +
                                                      (yblock * ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                             (-4.16666666666666644e-02 *
                                              ((inEB + blk_offset_t1))[(
                                                  l + (num_ele *
                                                       (((-1 + xidx) + ovlp) +
                                                        (xblock *
                                                         ((xyzy + ovlp) +
                                                          (yblock *
                                                           ((0 + xyzz) +
                                                            ovlp)))))))])))) +
                                          ((-4.16666666666666644e-02 *
                                            ((1.08333333333333326e+00 *
                                              ((inEB + blk_offset_t1))[(
                                                  l +
                                                  (num_ele *
                                                   (((0 + xidx) + ovlp) +
                                                    (xblock *
                                                     ((xyzy + ovlp) +
                                                      (yblock * ((1 + xyzz) +
                                                                 ovlp)))))))]) +
                                             ((-4.16666666666666644e-02 *
                                               ((inEB + blk_offset_t1))[(
                                                   l + (num_ele *
                                                        (((1 + xidx) + ovlp) +
                                                         (xblock *
                                                          ((xyzy + ovlp) +
                                                           (yblock *
                                                            ((1 + xyzz) +
                                                             ovlp)))))))]) +
                                              (-4.16666666666666644e-02 *
                                               ((inEB + blk_offset_t1))[(
                                                   l + (num_ele *
                                                        (((-1 + xidx) + ovlp) +
                                                         (xblock *
                                                          ((xyzy + ovlp) +
                                                           (yblock *
                                                            ((1 + xyzz) +
                                                             ovlp)))))))])))) +
                                           (-4.16666666666666644e-02 *
                                            ((1.08333333333333326e+00 *
                                              ((inEB + blk_offset_t1))[(
                                                  l +
                                                  (num_ele *
                                                   (((0 + xidx) + ovlp) +
                                                    (xblock *
                                                     ((xyzy + ovlp) +
                                                      (yblock * ((-1 + xyzz) +
                                                                 ovlp)))))))]) +
                                             ((-4.16666666666666644e-02 *
                                               ((inEB + blk_offset_t1))[(
                                                   l + (num_ele *
                                                        (((1 + xidx) + ovlp) +
                                                         (xblock *
                                                          ((xyzy + ovlp) +
                                                           (yblock *
                                                            ((-1 + xyzz) +
                                                             ovlp)))))))]) +
                                              (-4.16666666666666644e-02 *
                                               ((inEB + blk_offset_t1))[(
                                                   l + (num_ele *
                                                        (((-1 + xidx) + ovlp) +
                                                         (xblock *
                                                          ((xyzy + ovlp) +
                                                           (yblock *
                                                            ((-1 + xyzz) +
                                                             ovlp)))))))])))))))
                                      : ((((l == 2))
                                              ? (((1.08333333333333326e+00 *
                                                   ((1.08333333333333326e+00 *
                                                     ((inEB + blk_offset_t1))[(
                                                         l +
                                                         (num_ele *
                                                          (((0 + xidx) + ovlp) +
                                                           (xblock *
                                                            (((0 + xyzy) +
                                                              ovlp) +
                                                             (yblock *
                                                              (xyzz +
                                                               ovlp)))))))]) +
                                                    ((-4.16666666666666644e-02 *
                                                      ((inEB + blk_offset_t1))[(
                                                          l +
                                                          (num_ele *
                                                           (((0 + xidx) +
                                                             ovlp) +
                                                            (xblock *
                                                             (((1 + xyzy) +
                                                               ovlp) +
                                                              (yblock *
                                                               (xyzz +
                                                                ovlp)))))))]) +
                                                     (-4.16666666666666644e-02 *
                                                      ((inEB + blk_offset_t1))[(
                                                          l +
                                                          (num_ele *
                                                           (((0 + xidx) +
                                                             ovlp) +
                                                            (xblock *
                                                             (((-1 + xyzy) +
                                                               ovlp) +
                                                              (yblock *
                                                               (xyzz +
                                                                ovlp)))))))])))) +
                                                  ((-4.16666666666666644e-02 *
                                                    ((1.08333333333333326e+00 *
                                                      ((inEB + blk_offset_t1))[(
                                                          l +
                                                          (num_ele *
                                                           (((1 + xidx) +
                                                             ovlp) +
                                                            (xblock *
                                                             (((0 + xyzy) +
                                                               ovlp) +
                                                              (yblock *
                                                               (xyzz +
                                                                ovlp)))))))]) +
                                                     ((-4.16666666666666644e-02 *
                                                       ((inEB +
                                                         blk_offset_t1))[(
                                                           l +
                                                           (num_ele *
                                                            (((1 + xidx) +
                                                              ovlp) +
                                                             (xblock *
                                                              (((1 + xyzy) +
                                                                ovlp) +
                                                               (yblock *
                                                                (xyzz +
                                                                 ovlp)))))))]) +
                                                      (-4.16666666666666644e-02 *
                                                       ((inEB +
                                                         blk_offset_t1))[(
                                                           l +
                                                           (num_ele *
                                                            (((1 + xidx) +
                                                              ovlp) +
                                                             (xblock *
                                                              (((-1 + xyzy) +
                                                                ovlp) +
                                                               (yblock *
                                                                (xyzz +
                                                                 ovlp)))))))])))) +
                                                   (-4.16666666666666644e-02 *
                                                    ((1.08333333333333326e+00 *
                                                      ((inEB + blk_offset_t1))[(
                                                          l +
                                                          (num_ele *
                                                           (((-1 + xidx) +
                                                             ovlp) +
                                                            (xblock *
                                                             (((0 + xyzy) +
                                                               ovlp) +
                                                              (yblock *
                                                               (xyzz +
                                                                ovlp)))))))]) +
                                                     ((-4.16666666666666644e-02 *
                                                       ((inEB +
                                                         blk_offset_t1))[(
                                                           l +
                                                           (num_ele *
                                                            (((-1 + xidx) +
                                                              ovlp) +
                                                             (xblock *
                                                              (((1 + xyzy) +
                                                                ovlp) +
                                                               (yblock *
                                                                (xyzz +
                                                                 ovlp)))))))]) +
                                                      (-4.16666666666666644e-02 *
                                                       ((inEB +
                                                         blk_offset_t1))[(
                                                           l +
                                                           (num_ele *
                                                            (((-1 + xidx) +
                                                              ovlp) +
                                                             (xblock *
                                                              (((-1 + xyzy) +
                                                                ovlp) +
                                                               (yblock *
                                                                (xyzz +
                                                                 ovlp)))))))])))))))
                                              : (0)))))));
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
void c_Yee_FDTD_W04_2_scmc_kernel(double *outEB, double *inEB, long y_cpu_core,
                                  long numvec, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long xblock, long yblock,
                                  long zblock, int num_ele, double DT,
                                  long scmc_internal_g_idy,
                                  long scmc_internal_g_ylen) {
  const long pscmc_compute_unit_id = 0;

  const long pscmc_num_compute_units = 1;

  const long __idx = 0;

  const long __idy = scmc_internal_g_idy;

  const long __xlen = 1;

  const long __ylen = scmc_internal_g_ylen;

  const long __global_idx = (__idx + (__idy * __xlen));

  long i = 0;

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

  for ((i = local_ymin); (i < local_ymax); i++) {
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
                long blk_offset_t1 = (blk_all_len * i);

                long blk_offset =
                    ((blk_all_len * i) +
                     (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) +
                                                    (yb * (xyzz + ovlp))))))));

                {
                  long g = 0;

                  for (g = 0; ((__idx + (g * __xlen)) < (XLEN * 3)); g++) {
                    long realidx = (__idx + (g * __xlen));

                    long l = (realidx % 3);

                    long xidx = (realidx / 3);

                    (realidx = (((realidx / 3) * num_ele) + l));
                    ((outEB)[(blk_offset + realidx)] =
                         (((l == 0))
                              ? (((1.08333333333333326e+00 *
                                   ((inEB + blk_offset_t1))[(
                                       l + (num_ele *
                                            (((0 + xidx) + ovlp) +
                                             (xblock *
                                              ((xyzy + ovlp) +
                                               (yblock * (xyzz + ovlp)))))))]) +
                                  ((-4.16666666666666644e-02 *
                                    ((inEB + blk_offset_t1))[(
                                        l +
                                        (num_ele *
                                         (((1 + xidx) + ovlp) +
                                          (xblock *
                                           ((xyzy + ovlp) +
                                            (yblock * (xyzz + ovlp)))))))]) +
                                   (-4.16666666666666644e-02 *
                                    ((inEB + blk_offset_t1))[(
                                        l +
                                        (num_ele *
                                         (((-1 + xidx) + ovlp) +
                                          (xblock *
                                           ((xyzy + ovlp) +
                                            (yblock * (xyzz + ovlp)))))))]))))
                              : ((((l == 1))
                                      ? (((1.08333333333333326e+00 *
                                           ((inEB + blk_offset_t1))[(
                                               l + (num_ele *
                                                    ((xidx + ovlp) +
                                                     (xblock *
                                                      (((0 + xyzy) + ovlp) +
                                                       (yblock *
                                                        (xyzz + ovlp)))))))]) +
                                          ((-4.16666666666666644e-02 *
                                            ((inEB + blk_offset_t1))[(
                                                l + (num_ele *
                                                     ((xidx + ovlp) +
                                                      (xblock *
                                                       (((1 + xyzy) + ovlp) +
                                                        (yblock *
                                                         (xyzz + ovlp)))))))]) +
                                           (-4.16666666666666644e-02 *
                                            ((inEB + blk_offset_t1))[(
                                                l +
                                                (num_ele *
                                                 ((xidx + ovlp) +
                                                  (xblock *
                                                   (((-1 + xyzy) + ovlp) +
                                                    (yblock *
                                                     (xyzz + ovlp)))))))]))))
                                      : ((((l == 2))
                                              ? (((1.08333333333333326e+00 *
                                                   ((inEB + blk_offset_t1))[(
                                                       l + (num_ele *
                                                            ((xidx + ovlp) +
                                                             (xblock *
                                                              ((xyzy + ovlp) +
                                                               (yblock *
                                                                ((0 + xyzz) +
                                                                 ovlp)))))))]) +
                                                  ((-4.16666666666666644e-02 *
                                                    ((inEB + blk_offset_t1))[(
                                                        l +
                                                        (num_ele *
                                                         ((xidx + ovlp) +
                                                          (xblock *
                                                           ((xyzy + ovlp) +
                                                            (yblock *
                                                             ((1 + xyzz) +
                                                              ovlp)))))))]) +
                                                   (-4.16666666666666644e-02 *
                                                    ((inEB + blk_offset_t1))[(
                                                        l +
                                                        (num_ele *
                                                         ((xidx + ovlp) +
                                                          (xblock *
                                                           ((xyzy + ovlp) +
                                                            (yblock *
                                                             ((-1 + xyzz) +
                                                              ovlp)))))))]))))
                                              : (0)))))));
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

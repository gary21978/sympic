
#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32
__global__ void cuda_dump_ene_num(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw, double *fieldE,
                                  double *fieldB, double *FoutJ, double *FoutEN, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long numvec, int num_ele, long grid_cache_len, long cu_cache_length,
                                  double Mass, double Charge, int SPEC, int NUM_SPEC, double DELTA_X, double DELTA_Y,
                                  double DELTA_Z, double Deltat) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long numgrid = (XLEN * (YLEN * ZLEN));


  long grid_base_offset = (__idy * (numgrid * (grid_cache_len * 6)));

  int cu_load = (cu_xyzw)[(4 * __idy)];


  int use_local_particle_position = 1;

  int mdx;

  int mdy;

  int mdz;

  __shared__ double enevec[IDX_OPT_MAX * 3];
  __shared__ double avvvec[IDX_OPT_MAX * 3];
  __shared__ int numcpvec[IDX_OPT_MAX];
  {
    long l1;

    for ((l1 = 0); (l1 < cu_load); (l1 = (l1 + 1))) {
      long load0 = 1;


      (use_local_particle_position = 1);
      if (load0) {
        int Midx =
            ((use_local_particle_position) ? (floor(((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[0]))
                                           : (mdx));

        int Midy =
            ((use_local_particle_position) ? (floor(((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[1]))
                                           : (mdy));

        int Midz =
            ((use_local_particle_position) ? (floor(((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))))[2]))
                                           : (mdz));

        long lg = 0;

        double allene0_x = 0.00000000000000000e+00;

        double allene0_y = 0.00000000000000000e+00;

        double allene0_z = 0.00000000000000000e+00;

        double allavv_x = 0.00000000000000000e+00;

        double allavv_y = 0.00000000000000000e+00;

        double allavv_z = 0.00000000000000000e+00;

        int allnumcp = 0;

        {
          long g;

          for ((g = 0); (g < 3); (g = (g + 1))) {
            ((enevec)[(g + (3 * __idx))] = 0);
            ((avvvec)[(g + (3 * __idx))] = 0);
          }
        }
        ((numcpvec)[(1 * __idx)] = 0);
        for (; (((__idx * 1) + lg) < load0); (lg = (lg + (__xlen * 1)))) {
          double a_rva[(1 * 6)];
          int __idx_all_base = ((__idx * 1) + lg);

          int numcp = 1;

          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < numcp); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 6); (inner_g = (inner_g + 1))) {
                    (((a_rva + (0 * 6)))[((inner_step * 6) + inner_g)] =
                         (((cu_cache + ((__idy * (6 * cu_cache_length)) + (l1 * 6))) +
                           (__idx_all_base * 6)))[((inner_step * 6) + inner_g)]);
                  }
                }
              }
            }
          }
          double ene0_x = 0.00000000000000000e+00;

          double ene0_y = 0.00000000000000000e+00;

          double ene0_z = 0.00000000000000000e+00;

          double aver_vx = 0.00000000000000000e+00;

          double aver_vy = 0.00000000000000000e+00;

          double aver_vz = 0.00000000000000000e+00;

          {
            long g;

            for ((g = 0); (g < numcp); (g = (g + 1))) {
              double vx = ((a_rva + (g * 6)))[3];

              double vy = ((a_rva + (g * 6)))[4];

              double vz = ((a_rva + (g * 6)))[5];

              double curene_x = (Mass * (5.00000000000000000e-01 * +((vx * vx))));

              double curene_y = (Mass * (5.00000000000000000e-01 * +((vy * vy))));

              double curene_z = (Mass * (5.00000000000000000e-01 * +((vz * vz))));

              (ene0_x = (ene0_x + curene_x));
              (ene0_y = (ene0_y + curene_y));
              (ene0_z = (ene0_z + curene_z));
              (aver_vx = (aver_vx + vx));
              (aver_vy = (aver_vy + vy));
              (aver_vz = (aver_vz + vz));
            }
          }
          ((enevec)[(3 * __idx)] = ((enevec)[(3 * __idx)] + ene0_x));
          ((enevec)[((3 * __idx) + 1)] = ((enevec)[((3 * __idx) + 1)] + ene0_y));
          ((enevec)[((3 * __idx) + 2)] = ((enevec)[((3 * __idx) + 2)] + ene0_z));
          ((avvvec)[(3 * __idx)] = ((avvvec)[(3 * __idx)] + aver_vx));
          ((avvvec)[((3 * __idx) + 1)] = ((avvvec)[((3 * __idx) + 1)] + aver_vy));
          ((avvvec)[((3 * __idx) + 2)] = ((avvvec)[((3 * __idx) + 2)] + aver_vz));
          ((numcpvec)[__idx] = ((numcpvec)[__idx] + numcp));
        }
        __syncthreads();
        if (__idx == 0) {
          {
            long g;

            for ((g = 0); (g < __xlen); (g = (g + 1))) {
              (allene0_x = (allene0_x + (enevec)[((3 * g) + 0)]));
              (allene0_y = (allene0_y + (enevec)[((3 * g) + 1)]));
              (allene0_z = (allene0_z + (enevec)[((3 * g) + 2)]));
              (allavv_x = (allavv_x + (avvvec)[((3 * g) + 0)]));
              (allavv_y = (allavv_y + (avvvec)[((3 * g) + 1)]));
              (allavv_z = (allavv_z + (avvvec)[((3 * g) + 2)]));
              (allnumcp = (allnumcp + (numcpvec)[g]));
            }
          }
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[0] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[0] +
                allene0_x));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[1] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[1] +
                allene0_y));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[2] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[2] +
                allene0_z));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[3] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[3] +
                allavv_x));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[4] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[4] +
                allavv_y));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[5] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[5] +
                allavv_z));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[6] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[6] +
                allnumcp));
        }
      }
    }
  }
  {
    long allgid;

    for ((allgid = 0); (allgid < numgrid); (allgid = (allgid + 1))) {
      int new_load_tmp = (xyzw)[(4 * ((__idy * numgrid) + allgid))];

      long c_gid = allgid;

      (use_local_particle_position = 0);
      (mdx = (c_gid % XLEN));
      (mdy = ((c_gid / XLEN) % YLEN));
      (mdz = (c_gid / (XLEN * YLEN)));
      int load0 = new_load_tmp;

      int new_load = new_load_tmp;


      if (load0) {
        int Midx = ((use_local_particle_position)
                        ? (floor(((inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))))[0]))
                        : (mdx));

        int Midy = ((use_local_particle_position)
                        ? (floor(((inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))))[1]))
                        : (mdy));

        int Midz = ((use_local_particle_position)
                        ? (floor(((inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))))[2]))
                        : (mdz));

        long lg = 0;

        double allene0_x = 0.00000000000000000e+00;

        double allene0_y = 0.00000000000000000e+00;

        double allene0_z = 0.00000000000000000e+00;

        double allavv_x = 0.00000000000000000e+00;

        double allavv_y = 0.00000000000000000e+00;

        double allavv_z = 0.00000000000000000e+00;

        int allnumcp = 0;

        {
          long g;

          for ((g = 0); (g < 3); (g = (g + 1))) {
            ((enevec)[(g + (3 * __idx))] = 0);
            ((avvvec)[(g + (3 * __idx))] = 0);
          }
        }
        ((numcpvec)[(1 * __idx)] = 0);
        for (; (((__idx * 1) + lg) < load0); (lg = (lg + (__xlen * 1)))) {
          double a_rva[(1 * 6)];
          int __idx_all_base = ((__idx * 1) + lg);

          int numcp = 1;

          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < numcp); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 6); (inner_g = (inner_g + 1))) {
                    (((a_rva + (0 * 6)))[((inner_step * 6) + inner_g)] =
                         (((inoutput + (grid_base_offset + (6 * (allgid * grid_cache_len)))) +
                           (__idx_all_base * 6)))[((inner_step * 6) + inner_g)]);
                  }
                }
              }
            }
          }
          double ene0_x = 0.00000000000000000e+00;

          double ene0_y = 0.00000000000000000e+00;

          double ene0_z = 0.00000000000000000e+00;

          double aver_vx = 0.00000000000000000e+00;

          double aver_vy = 0.00000000000000000e+00;

          double aver_vz = 0.00000000000000000e+00;

          {
            long g;

            for ((g = 0); (g < numcp); (g = (g + 1))) {
              double vx = ((a_rva + (g * 6)))[3];

              double vy = ((a_rva + (g * 6)))[4];

              double vz = ((a_rva + (g * 6)))[5];

              double curene_x = (Mass * (5.00000000000000000e-01 * +((vx * vx))));

              double curene_y = (Mass * (5.00000000000000000e-01 * +((vy * vy))));

              double curene_z = (Mass * (5.00000000000000000e-01 * +((vz * vz))));

              (ene0_x = (ene0_x + curene_x));
              (ene0_y = (ene0_y + curene_y));
              (ene0_z = (ene0_z + curene_z));
              (aver_vx = (aver_vx + vx));
              (aver_vy = (aver_vy + vy));
              (aver_vz = (aver_vz + vz));
            }
          }
          ((enevec)[(3 * __idx)] = ((enevec)[(3 * __idx)] + ene0_x));
          ((enevec)[((3 * __idx) + 1)] = ((enevec)[((3 * __idx) + 1)] + ene0_y));
          ((enevec)[((3 * __idx) + 2)] = ((enevec)[((3 * __idx) + 2)] + ene0_z));
          ((avvvec)[(3 * __idx)] = ((avvvec)[(3 * __idx)] + aver_vx));
          ((avvvec)[((3 * __idx) + 1)] = ((avvvec)[((3 * __idx) + 1)] + aver_vy));
          ((avvvec)[((3 * __idx) + 2)] = ((avvvec)[((3 * __idx) + 2)] + aver_vz));
          ((numcpvec)[__idx] = ((numcpvec)[__idx] + numcp));
        }
        __syncthreads();
        if (__idx == 0) {
          {
            long g;

            for ((g = 0); (g < __xlen); (g = (g + 1))) {
              (allene0_x = (allene0_x + (enevec)[((3 * g) + 0)]));
              (allene0_y = (allene0_y + (enevec)[((3 * g) + 1)]));
              (allene0_z = (allene0_z + (enevec)[((3 * g) + 2)]));
              (allavv_x = (allavv_x + (avvvec)[((3 * g) + 0)]));
              (allavv_y = (allavv_y + (avvvec)[((3 * g) + 1)]));
              (allavv_z = (allavv_z + (avvvec)[((3 * g) + 2)]));
              (allnumcp = (allnumcp + (numcpvec)[g]));
            }
          }
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[0] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[0] +
                allene0_x));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[1] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[1] +
                allene0_y));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[2] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[2] +
                allene0_z));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[3] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[3] +
                allavv_x));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[4] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[4] +
                allavv_y));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[5] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[5] +
                allavv_z));
          (((FoutEN +
             ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
               (0 + ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                        ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
              (SPEC * 7))))[6] =
               (((FoutEN +
                  ((((NUM_SPEC * 7) * (__idy * ((XLEN + (2 * ovlp)) * ((YLEN + (2 * ovlp)) * (ZLEN + (2 * ovlp)))))) +
                    (0 +
                     ((NUM_SPEC * 7) * ((Midx + ovlp) + ((XLEN + (2 * ovlp)) *
                                                         ((Midy + ovlp) + ((YLEN + (2 * ovlp)) * (Midz + ovlp)))))))) +
                   (SPEC * 7))))[6] +
                allnumcp));
        }
      }

      if (load0 != new_load) {
        ((xyzw)[(4 * ((__idy * numgrid) + allgid))] = new_load);
      }
    }
  }
}


#include <assert.h>
#include <math.h>
#include <stdio.h>
#define IDX_OPT_MAX 32

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_x_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));

  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    long grid_id = i;

    long bxyzx = (grid_id % XLEN);


    int cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];

    int cur_load = cur_load0;


    int lg = 0;


    long left_bound = bxyzx;

    long right_bound = (bxyzx + 1);


    long num_write_minus = 0;

    long num_write_plus = 0;

    long num_write_main = 0;


    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      int cur_grid_num = 0;

      int to_left_num = 0;

      int to_right_num = 0;

      __shared__ int cgn_shared[IDX_LOCAL_XLEN];
      __shared__ int tln_shared[IDX_LOCAL_XLEN];
      __shared__ int trn_shared[IDX_LOCAL_XLEN];
      {
        long p;

        for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          int real_p = p;

          int local_p_id = (p - (lg + (__idx * __xlen)));

          int if_exist_particle = (real_p < cur_load);

          double particle_sort_key_element =
              ((if_exist_particle) ? (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (real_p * 6))])
                                   : (-1));

          int is_to_left = (particle_sort_key_element < left_bound);

          int is_to_right = (particle_sort_key_element > right_bound);

          int is_cur = ((!is_to_right) && (!is_to_left));

          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            long i;

            for ((i = 0); (i < 6); (i = (i + 1))) {
              if (is_to_left) {
                ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_to_right) {
                ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_cur) {
                (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               6)))[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }
            }
          }
          if (is_cur) {
            (cur_grid_num = (cur_grid_num + 1));
          }

          if (is_to_left) {
            (to_left_num = (to_left_num + 1));
          }

          if (is_to_right) {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __syncthreads();
      long p = 0;

      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
        {
          long MYGEN6 = 0;

          for (; (MYGEN6 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN6 = (MYGEN6 + __xlen))) {
            int ridx = (MYGEN6 + __idx);

            if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
              ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                6)))[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                   (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                    6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
        {
          long MYGEN7 = 0;

          for (; (MYGEN7 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN7 = (MYGEN7 + __xlen))) {
            int ridx = (MYGEN7 + __idx);

            if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
              ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                   (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
        {
          long MYGEN8 = 0;

          for (; (MYGEN8 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN8 = (MYGEN8 + __xlen))) {
            int ridx = (MYGEN8 + __idx);

            if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
              ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                   (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
        __syncthreads();
      }
    }
    int is_most_left = (bxyzx == 0);

    int is_most_right = (bxyzx == (XLEN - 1));

    int beg_left_main = grid_cache_len;

    int beg_plus = 0;

    int end_plus = 0;

    if (!is_most_left) {
      (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - 1))]);
      (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 2)]);
      (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 3)]);
    }

    {
      int num_copy_real_11516lap = (end_plus - beg_plus);

      if (num_copy_real_11516lap > (grid_cache_len - num_write_main)) {
        (num_copy_real_11516lap = (grid_cache_len - num_write_main));
        {
          long MYGEN9 = 0;

          for (; (MYGEN9 < (6 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
               (MYGEN9 = (MYGEN9 + __xlen))) {
            int ridx = (MYGEN9 + __idx);

            if ((ridx < (6 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (beg_plus - (1 * grid_cache_len)))))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
      }

      {
        long MYGEN10 = 0;

        for (; (MYGEN10 < (num_copy_real_11516lap * 6)); (MYGEN10 = (MYGEN10 + __xlen))) {
          int ridx = (MYGEN10 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
               (num_write_main * 6)))[ridx] =
                 (&(((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (beg_plus - (1 * grid_cache_len)))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_minus;

      if (num_copy_real_11516lap > (grid_cache_len - beg_left_main)) {
        (num_copy_real_11516lap = (grid_cache_len - beg_left_main));
        {
          long MYGEN11 = 0;

          for (; (MYGEN11 < (6 * (num_write_minus - (grid_cache_len - beg_left_main))));
               (MYGEN11 = (MYGEN11 + __xlen))) {
            int ridx = (MYGEN11 + __idx);

            if ((ridx < (6 * (num_write_minus - (grid_cache_len - beg_left_main))))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_minus - (grid_cache_len - beg_left_main))));
      }

      {
        long MYGEN12 = 0;

        for (; (MYGEN12 < (num_copy_real_11516lap * 6)); (MYGEN12 = (MYGEN12 + __xlen))) {
          int ridx = (MYGEN12 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               6)))[(0 + (6 * ((__idx * (__xlen * 0)) + -((1 * grid_cache_len)))))]) +
               (beg_left_main * 6)))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if ((!is_most_left) && (__idx == 0)) {
      ((xyzw)[(4 * ((cu_offset + grid_id) - 1))] = beg_left_main);
    }

    int cap_tmp = ((is_most_right) ? (0) : ((grid_cache_len - num_write_main)));

    int total_cache_num = num_write_main;

    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_plus;

      if (num_copy_real_11516lap > cap_tmp) {
        (num_copy_real_11516lap = cap_tmp);
        {
          long MYGEN13 = 0;

          for (; (MYGEN13 < (6 * (num_write_plus - cap_tmp))); (MYGEN13 = (MYGEN13 + __xlen))) {
            int ridx = (MYGEN13 + __idx);

            if (ridx < (6 * (num_write_plus - cap_tmp))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_plus - cap_tmp)));
      }

      {
        long MYGEN14 = 0;

        for (; (MYGEN14 < (num_copy_real_11516lap * 6)); (MYGEN14 = (MYGEN14 + __xlen))) {
          int ridx = (MYGEN14 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
               (total_cache_num * 6)))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);
    if (__idx == 0) {
      {
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 4) + inner_g)] =
                     (xm4)[((inner_step * 4) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }
  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = XLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(0 + (real_p * 6))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 6); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN15 = 0;

        for (; (MYGEN15 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN15 = (MYGEN15 + __xlen))) {
          int ridx = (MYGEN15 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
            ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN16 = 0;

        for (; (MYGEN16 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN16 = (MYGEN16 + __xlen))) {
          int ridx = (MYGEN16 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN17 = 0;

        for (; (MYGEN17 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN17 = (MYGEN17 + __xlen))) {
          int ridx = (MYGEN17 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN18 = (num_write_plus * 6);

    for (; (MYGEN18 > 0); (MYGEN18 = (MYGEN18 + -__xlen))) {
      int ridx = (MYGEN18 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_x_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                       long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
                                       long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 6)];
  double local_temp_particle_cache_minus[(384 * 6)];
  double local_pos_cache[(64 * 6)];
  double local_vel_cache[192];
  __shared__ int cu_xyzw_shared[4];
  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  if (__idx == 0) {
    {

      int beg_to_left = ((2 * cu_cache_length) / 5);

      int cur_to_left = beg_to_left;

      int cur_to_right = cu_cache_length;

      int cur_this = 0;

      int lg;

      int g;

      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cu_cur_cache_load)) ? ((cu_cur_cache_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((cu_cache + (__idy * (6 * cu_cache_length))) + (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {

          if (((local_pos_cache + (g * 6)))[0] < 0) {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((cu_cache + (__idy * (6 * cu_cache_length))) +
                       (cur_to_left * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {
            if (((local_pos_cache + (g * 6)))[0] > XLEN) {
              cur_to_right--;
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (6 * cu_cache_length))) +
                         (cur_to_right * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
            } else {
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (6 * cu_cache_length))) + (cur_this * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (cur_this = (cur_this + 1));
            }
          }
        }
      }
      ((cu_xyzw_shared)[0] = cur_this);
      ((cu_xyzw_shared)[1] = beg_to_left);
      ((cu_xyzw_shared)[2] = cur_to_left);
      ((cu_xyzw_shared)[3] = cur_to_right);
    }
  }

  __syncthreads();
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    long grid_id = (__idx + (i * __xlen));

    if (grid_id < xyzalllen) {
      int cur_load = (xyzw)[(4 * (cu_offset + grid_id))];

      long bxyzx = (grid_id % XLEN);


      int g = 0;

      int lg = 0;


      long left_bound = bxyzx;

      long right_bound = (left_bound + 1);


      long num_write_minus = 0;

      long num_write_plus = 0;

      long num_write_main = 0;

      long num_write_tmp = 0;

      for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cur_load)) ? ((cur_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < num_read); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 3); (inner_g = (inner_g + 1))) {
                  ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (3 + (lg * 6))))[((inner_step * 6) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {
          if (((local_pos_cache + (g * 6)))[0] < left_bound) {
            assert((num_write_minus < 384));
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                       (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (num_write_main = (num_write_main + num_write_tmp));
            (num_write_tmp = 0);
            {
              long i;

              for ((i = 0); (i < 6); (i = (i + 1))) {
                (((local_temp_particle_cache_minus + (num_write_minus * 6)))[i] = ((local_pos_cache + (g * 6)))[i]);
              }
            }
            num_write_minus++;

          } else {
            if (((local_pos_cache + (g * 6)))[0] > right_bound) {
              assert((num_write_plus < 384));
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                long i;

                for ((i = 0); (i < 6); (i = (i + 1))) {
                  (((local_temp_particle_cache_plus + (num_write_plus * 6)))[i] = ((local_pos_cache + (g * 6)))[i]);
                }
              }
              num_write_plus++;

            } else {
              if (((((local_vel_cache)[((g * 3) + 0)] * (local_vel_cache)[((g * 3) + 0)]) +
                    (((local_vel_cache)[((g * 3) + 1)] * (local_vel_cache)[((g * 3) + 1)]) +
                     ((local_vel_cache)[((g * 3) + 2)] * (local_vel_cache)[((g * 3) + 2)]))) >
                   1.00000000000000000e+00)) {
                {
                  long inner_step;

                  for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                    {
                      long inner_g;

                      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                        ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                             ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                      }
                    }
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);

              } else {
                num_write_tmp++;
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        (num_write_main = (num_write_main + num_write_tmp));
        (num_write_tmp = 0);
      }
      int x_main = num_write_main;

      int x_beg_minus = x_main;

      int x_beg_plus = (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));

      int xm4[4];
      ((xm4)[0] = x_main);
      ((xm4)[1] = (num_write_minus + x_main));
      ((xm4)[2] = x_beg_plus);
      ((xm4)[3] = (num_write_plus + x_beg_plus));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 1) + inner_g)] =
                   (xm4)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (6 * num_write_minus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                 (x_beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      if ((xm4)[3] > grid_cache_len) {
        long i = 0;

        for (i = 0; (i < 4); i++) {
        }
        assert(0);
      }

      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (6 * num_write_plus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                 (x_beg_plus * 6)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }
  }
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        long bxyzx = (grid_id % XLEN);


        int is_most_left = (bxyzx == 0);

        int is_most_right = (bxyzx == (XLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_minus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (6 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           ((beg_plus - (1 * grid_cache_len)) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                     ((beg_plus * 6) - (1 * (grid_cache_len * 6)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - 1))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (6 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 6)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           6))))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (6 * cur_beg_plus)))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_plus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_y_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));

  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    long grid_id = i;


    long bxyzy = ((grid_id / XLEN) % YLEN);


    int cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];

    int cur_load = cur_load0;


    int lg = 0;


    long left_bound = bxyzy;

    long right_bound = (bxyzy + 1);


    long num_write_minus = 0;

    long num_write_plus = 0;

    long num_write_main = 0;


    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      int cur_grid_num = 0;

      int to_left_num = 0;

      int to_right_num = 0;

      __shared__ int cgn_shared[IDX_LOCAL_XLEN];
      __shared__ int tln_shared[IDX_LOCAL_XLEN];
      __shared__ int trn_shared[IDX_LOCAL_XLEN];
      {
        long p;

        for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          int real_p = p;

          int local_p_id = (p - (lg + (__idx * __xlen)));

          int if_exist_particle = (real_p < cur_load);

          double particle_sort_key_element =
              ((if_exist_particle) ? (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(1 + (real_p * 6))])
                                   : (-1));

          int is_to_left = (particle_sort_key_element < left_bound);

          int is_to_right = (particle_sort_key_element > right_bound);

          int is_cur = ((!is_to_right) && (!is_to_left));

          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            long i;

            for ((i = 0); (i < 6); (i = (i + 1))) {
              if (is_to_left) {
                ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_to_right) {
                ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_cur) {
                (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               6)))[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }
            }
          }
          if (is_cur) {
            (cur_grid_num = (cur_grid_num + 1));
          }

          if (is_to_left) {
            (to_left_num = (to_left_num + 1));
          }

          if (is_to_right) {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __syncthreads();
      long p = 0;

      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
        {
          long MYGEN19 = 0;

          for (; (MYGEN19 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN19 = (MYGEN19 + __xlen))) {
            int ridx = (MYGEN19 + __idx);

            if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
              ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                6)))[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                   (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                    6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
        {
          long MYGEN20 = 0;

          for (; (MYGEN20 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN20 = (MYGEN20 + __xlen))) {
            int ridx = (MYGEN20 + __idx);

            if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
              ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                   (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
        {
          long MYGEN21 = 0;

          for (; (MYGEN21 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN21 = (MYGEN21 + __xlen))) {
            int ridx = (MYGEN21 + __idx);

            if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
              ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                   (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
        __syncthreads();
      }
    }
    int is_most_left = (bxyzy == 0);

    int is_most_right = (bxyzy == (YLEN - 1));

    int beg_left_main = grid_cache_len;

    int beg_plus = 0;

    int end_plus = 0;

    if (!is_most_left) {
      (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - XLEN))]);
      (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 2)]);
      (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 3)]);
    }

    {
      int num_copy_real_11516lap = (end_plus - beg_plus);

      if (num_copy_real_11516lap > (grid_cache_len - num_write_main)) {
        (num_copy_real_11516lap = (grid_cache_len - num_write_main));
        {
          long MYGEN22 = 0;

          for (; (MYGEN22 < (6 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
               (MYGEN22 = (MYGEN22 + __xlen))) {
            int ridx = (MYGEN22 + __idx);

            if ((ridx < (6 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] = ((
                   &(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (beg_plus - (XLEN * grid_cache_len)))))]) +
                   (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
      }

      {
        long MYGEN23 = 0;

        for (; (MYGEN23 < (num_copy_real_11516lap * 6)); (MYGEN23 = (MYGEN23 + __xlen))) {
          int ridx = (MYGEN23 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
               (num_write_main * 6)))[ridx] =
                 (&(((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (beg_plus - (XLEN * grid_cache_len)))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_minus;

      if (num_copy_real_11516lap > (grid_cache_len - beg_left_main)) {
        (num_copy_real_11516lap = (grid_cache_len - beg_left_main));
        {
          long MYGEN24 = 0;

          for (; (MYGEN24 < (6 * (num_write_minus - (grid_cache_len - beg_left_main))));
               (MYGEN24 = (MYGEN24 + __xlen))) {
            int ridx = (MYGEN24 + __idx);

            if ((ridx < (6 * (num_write_minus - (grid_cache_len - beg_left_main))))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_minus - (grid_cache_len - beg_left_main))));
      }

      {
        long MYGEN25 = 0;

        for (; (MYGEN25 < (num_copy_real_11516lap * 6)); (MYGEN25 = (MYGEN25 + __xlen))) {
          int ridx = (MYGEN25 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               6)))[(0 + (6 * ((__idx * (__xlen * 0)) + -((XLEN * grid_cache_len)))))]) +
               (beg_left_main * 6)))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if ((!is_most_left) && (__idx == 0)) {
      ((xyzw)[(4 * ((cu_offset + grid_id) - XLEN))] = beg_left_main);
    }

    int cap_tmp = ((is_most_right) ? (0) : ((grid_cache_len - num_write_main)));

    int total_cache_num = num_write_main;

    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_plus;

      if (num_copy_real_11516lap > cap_tmp) {
        (num_copy_real_11516lap = cap_tmp);
        {
          long MYGEN26 = 0;

          for (; (MYGEN26 < (6 * (num_write_plus - cap_tmp))); (MYGEN26 = (MYGEN26 + __xlen))) {
            int ridx = (MYGEN26 + __idx);

            if (ridx < (6 * (num_write_plus - cap_tmp))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_plus - cap_tmp)));
      }

      {
        long MYGEN27 = 0;

        for (; (MYGEN27 < (num_copy_real_11516lap * 6)); (MYGEN27 = (MYGEN27 + __xlen))) {
          int ridx = (MYGEN27 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
               (total_cache_num * 6)))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);
    if (__idx == 0) {
      {
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 4) + inner_g)] =
                     (xm4)[((inner_step * 4) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }
  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = YLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(1 + (real_p * 6))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 6); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN28 = 0;

        for (; (MYGEN28 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN28 = (MYGEN28 + __xlen))) {
          int ridx = (MYGEN28 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
            ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN29 = 0;

        for (; (MYGEN29 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN29 = (MYGEN29 + __xlen))) {
          int ridx = (MYGEN29 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN30 = 0;

        for (; (MYGEN30 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN30 = (MYGEN30 + __xlen))) {
          int ridx = (MYGEN30 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN31 = (num_write_plus * 6);

    for (; (MYGEN31 > 0); (MYGEN31 = (MYGEN31 + -__xlen))) {
      int ridx = (MYGEN31 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_y_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                       long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
                                       long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 6)];
  double local_temp_particle_cache_minus[(384 * 6)];
  double local_pos_cache[(64 * 6)];
  double local_vel_cache[192];
  __shared__ int cu_xyzw_shared[4];
  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  if (__idx == 0) {
    {

      int beg_to_left = ((2 * cu_cache_length) / 5);

      int cur_to_left = beg_to_left;

      int cur_to_right = cu_cache_length;

      int cur_this = 0;

      int lg;

      int g;

      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cu_cur_cache_load)) ? ((cu_cur_cache_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((cu_cache + (__idy * (6 * cu_cache_length))) + (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {

          if (((local_pos_cache + (g * 6)))[1] < 0) {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((cu_cache + (__idy * (6 * cu_cache_length))) +
                       (cur_to_left * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {
            if (((local_pos_cache + (g * 6)))[1] > YLEN) {
              cur_to_right--;
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (6 * cu_cache_length))) +
                         (cur_to_right * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
            } else {
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (6 * cu_cache_length))) + (cur_this * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (cur_this = (cur_this + 1));
            }
          }
        }
      }
      ((cu_xyzw_shared)[0] = cur_this);
      ((cu_xyzw_shared)[1] = beg_to_left);
      ((cu_xyzw_shared)[2] = cur_to_left);
      ((cu_xyzw_shared)[3] = cur_to_right);
    }
  }

  __syncthreads();
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    long grid_id = (__idx + (i * __xlen));

    if (grid_id < xyzalllen) {
      int cur_load = (xyzw)[(4 * (cu_offset + grid_id))];


      long bxyzy = ((grid_id / XLEN) % YLEN);


      int g = 0;

      int lg = 0;


      long left_bound = bxyzy;

      long right_bound = (left_bound + 1);


      long num_write_minus = 0;

      long num_write_plus = 0;

      long num_write_main = 0;

      long num_write_tmp = 0;

      for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cur_load)) ? ((cur_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < num_read); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 3); (inner_g = (inner_g + 1))) {
                  ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (3 + (lg * 6))))[((inner_step * 6) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {
          if (((local_pos_cache + (g * 6)))[1] < left_bound) {
            assert((num_write_minus < 384));
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                       (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (num_write_main = (num_write_main + num_write_tmp));
            (num_write_tmp = 0);
            {
              long i;

              for ((i = 0); (i < 6); (i = (i + 1))) {
                (((local_temp_particle_cache_minus + (num_write_minus * 6)))[i] = ((local_pos_cache + (g * 6)))[i]);
              }
            }
            num_write_minus++;

          } else {
            if (((local_pos_cache + (g * 6)))[1] > right_bound) {
              assert((num_write_plus < 384));
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                long i;

                for ((i = 0); (i < 6); (i = (i + 1))) {
                  (((local_temp_particle_cache_plus + (num_write_plus * 6)))[i] = ((local_pos_cache + (g * 6)))[i]);
                }
              }
              num_write_plus++;

            } else {
              if (((((local_vel_cache)[((g * 3) + 0)] * (local_vel_cache)[((g * 3) + 0)]) +
                    (((local_vel_cache)[((g * 3) + 1)] * (local_vel_cache)[((g * 3) + 1)]) +
                     ((local_vel_cache)[((g * 3) + 2)] * (local_vel_cache)[((g * 3) + 2)]))) >
                   1.00000000000000000e+00)) {
                {
                  long inner_step;

                  for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                    {
                      long inner_g;

                      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                        ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                             ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                      }
                    }
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);

              } else {
                num_write_tmp++;
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        (num_write_main = (num_write_main + num_write_tmp));
        (num_write_tmp = 0);
      }
      int x_main = num_write_main;

      int x_beg_minus = x_main;

      int x_beg_plus = (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));

      int xm4[4];
      ((xm4)[0] = x_main);
      ((xm4)[1] = (num_write_minus + x_main));
      ((xm4)[2] = x_beg_plus);
      ((xm4)[3] = (num_write_plus + x_beg_plus));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 1) + inner_g)] =
                   (xm4)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (6 * num_write_minus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                 (x_beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      if ((xm4)[3] > grid_cache_len) {
        long i = 0;

        for (i = 0; (i < 4); i++) {
        }
        assert(0);
      }

      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (6 * num_write_plus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                 (x_beg_plus * 6)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }
  }
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }

        long bxyzy = ((grid_id / XLEN) % YLEN);


        int is_most_left = (bxyzy == 0);

        int is_most_right = (bxyzy == (YLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_minus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (6 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           ((beg_plus - (XLEN * grid_cache_len)) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                     ((beg_plus * 6) - (XLEN * (grid_cache_len * 6)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - XLEN))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (6 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 6)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           6))))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (6 * cur_beg_plus)))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_plus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_z_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));

  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    long grid_id = i;


    long bxyzz = (grid_id / (XLEN * YLEN));

    int cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];

    int cur_load = cur_load0;


    int lg = 0;


    long left_bound = bxyzz;

    long right_bound = (bxyzz + 1);


    long num_write_minus = 0;

    long num_write_plus = 0;

    long num_write_main = 0;


    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      int cur_grid_num = 0;

      int to_left_num = 0;

      int to_right_num = 0;

      __shared__ int cgn_shared[IDX_LOCAL_XLEN];
      __shared__ int tln_shared[IDX_LOCAL_XLEN];
      __shared__ int trn_shared[IDX_LOCAL_XLEN];
      {
        long p;

        for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          int real_p = p;

          int local_p_id = (p - (lg + (__idx * __xlen)));

          int if_exist_particle = (real_p < cur_load);

          double particle_sort_key_element =
              ((if_exist_particle) ? (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(2 + (real_p * 6))])
                                   : (-1));

          int is_to_left = (particle_sort_key_element < left_bound);

          int is_to_right = (particle_sort_key_element > right_bound);

          int is_cur = ((!is_to_right) && (!is_to_left));

          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            long i;

            for ((i = 0); (i < 6); (i = (i + 1))) {
              if (is_to_left) {
                ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_to_right) {
                ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_cur) {
                (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               6)))[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   6)))[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }
            }
          }
          if (is_cur) {
            (cur_grid_num = (cur_grid_num + 1));
          }

          if (is_to_left) {
            (to_left_num = (to_left_num + 1));
          }

          if (is_to_right) {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __syncthreads();
      long p = 0;

      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
        {
          long MYGEN32 = 0;

          for (; (MYGEN32 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN32 = (MYGEN32 + __xlen))) {
            int ridx = (MYGEN32 + __idx);

            if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
              ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                6)))[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                   (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                    6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
        {
          long MYGEN33 = 0;

          for (; (MYGEN33 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN33 = (MYGEN33 + __xlen))) {
            int ridx = (MYGEN33 + __idx);

            if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
              ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                   (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
        {
          long MYGEN34 = 0;

          for (; (MYGEN34 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN34 = (MYGEN34 + __xlen))) {
            int ridx = (MYGEN34 + __idx);

            if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
              ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                   (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
        __syncthreads();
      }
    }
    int is_most_left = (bxyzz == 0);

    int is_most_right = (bxyzz == (ZLEN - 1));

    int beg_left_main = grid_cache_len;

    int beg_plus = 0;

    int end_plus = 0;

    if (!is_most_left) {
      (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))]);
      (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)]);
      (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 3)]);
    }

    {
      int num_copy_real_11516lap = (end_plus - beg_plus);

      if (num_copy_real_11516lap > (grid_cache_len - num_write_main)) {
        (num_copy_real_11516lap = (grid_cache_len - num_write_main));
        {
          long MYGEN35 = 0;

          for (; (MYGEN35 < (6 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
               (MYGEN35 = (MYGEN35 + __xlen))) {
            int ridx = (MYGEN35 + __idx);

            if ((ridx < (6 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                         0 + (6 * ((__idx * (__xlen * 0)) + (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
      }

      {
        long MYGEN36 = 0;

        for (; (MYGEN36 < (num_copy_real_11516lap * 6)); (MYGEN36 = (MYGEN36 + __xlen))) {
          int ridx = (MYGEN36 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
               (num_write_main * 6)))[ridx] =
                 (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                     0 + (6 * ((__idx * (__xlen * 0)) + (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_minus;

      if (num_copy_real_11516lap > (grid_cache_len - beg_left_main)) {
        (num_copy_real_11516lap = (grid_cache_len - beg_left_main));
        {
          long MYGEN37 = 0;

          for (; (MYGEN37 < (6 * (num_write_minus - (grid_cache_len - beg_left_main))));
               (MYGEN37 = (MYGEN37 + __xlen))) {
            int ridx = (MYGEN37 + __idx);

            if ((ridx < (6 * (num_write_minus - (grid_cache_len - beg_left_main))))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_minus - (grid_cache_len - beg_left_main))));
      }

      {
        long MYGEN38 = 0;

        for (; (MYGEN38 < (num_copy_real_11516lap * 6)); (MYGEN38 = (MYGEN38 + __xlen))) {
          int ridx = (MYGEN38 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               6)))[(0 + (6 * ((__idx * (__xlen * 0)) + -(((XLEN * YLEN) * grid_cache_len)))))]) +
               (beg_left_main * 6)))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if ((!is_most_left) && (__idx == 0)) {
      ((xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))] = beg_left_main);
    }

    int cap_tmp = ((is_most_right) ? (0) : ((grid_cache_len - num_write_main)));

    int total_cache_num = num_write_main;

    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_plus;

      if (num_copy_real_11516lap > cap_tmp) {
        (num_copy_real_11516lap = cap_tmp);
        {
          long MYGEN39 = 0;

          for (; (MYGEN39 < (6 * (num_write_plus - cap_tmp))); (MYGEN39 = (MYGEN39 + __xlen))) {
            int ridx = (MYGEN39 + __idx);

            if (ridx < (6 * (num_write_plus - cap_tmp))) {
              (((cu_cache_head + (6 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 6)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_plus - cap_tmp)));
      }

      {
        long MYGEN40 = 0;

        for (; (MYGEN40 < (num_copy_real_11516lap * 6)); (MYGEN40 = (MYGEN40 + __xlen))) {
          int ridx = (MYGEN40 + __idx);

          if (ridx < (num_copy_real_11516lap * 6)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
               (total_cache_num * 6)))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);
    if (__idx == 0) {
      {
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 4) + inner_g)] =
                     (xm4)[((inner_step * 4) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }
  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = ZLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(2 + (real_p * 6))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 6); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN41 = 0;

        for (; (MYGEN41 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN41 = (MYGEN41 + __xlen))) {
          int ridx = (MYGEN41 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
            ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN42 = 0;

        for (; (MYGEN42 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN42 = (MYGEN42 + __xlen))) {
          int ridx = (MYGEN42 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN43 = 0;

        for (; (MYGEN43 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN43 = (MYGEN43 + __xlen))) {
          int ridx = (MYGEN43 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN44 = (num_write_plus * 6);

    for (; (MYGEN44 > 0); (MYGEN44 = (MYGEN44 + -__xlen))) {
      int ridx = (MYGEN44 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_z_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                       long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
                                       long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 6)];
  double local_temp_particle_cache_minus[(384 * 6)];
  double local_pos_cache[(64 * 6)];
  double local_vel_cache[192];
  __shared__ int cu_xyzw_shared[4];
  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  if (__idx == 0) {
    {

      int beg_to_left = ((2 * cu_cache_length) / 5);

      int cur_to_left = beg_to_left;

      int cur_to_right = cu_cache_length;

      int cur_this = 0;

      int lg;

      int g;

      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cu_cur_cache_load)) ? ((cu_cur_cache_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((cu_cache + (__idy * (6 * cu_cache_length))) + (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {

          if (((local_pos_cache + (g * 6)))[2] < 0) {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((cu_cache + (__idy * (6 * cu_cache_length))) +
                       (cur_to_left * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {
            if (((local_pos_cache + (g * 6)))[2] > ZLEN) {
              cur_to_right--;
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (6 * cu_cache_length))) +
                         (cur_to_right * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
            } else {
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (6 * cu_cache_length))) + (cur_this * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (cur_this = (cur_this + 1));
            }
          }
        }
      }
      ((cu_xyzw_shared)[0] = cur_this);
      ((cu_xyzw_shared)[1] = beg_to_left);
      ((cu_xyzw_shared)[2] = cur_to_left);
      ((cu_xyzw_shared)[3] = cur_to_right);
    }
  }

  __syncthreads();
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    long grid_id = (__idx + (i * __xlen));

    if (grid_id < xyzalllen) {
      int cur_load = (xyzw)[(4 * (cu_offset + grid_id))];


      long bxyzz = (grid_id / (XLEN * YLEN));

      int g = 0;

      int lg = 0;


      long left_bound = bxyzz;

      long right_bound = (left_bound + 1);


      long num_write_minus = 0;

      long num_write_plus = 0;

      long num_write_main = 0;

      long num_write_tmp = 0;

      for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cur_load)) ? ((cur_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < num_read); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 3); (inner_g = (inner_g + 1))) {
                  ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (3 + (lg * 6))))[((inner_step * 6) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {
          if (((local_pos_cache + (g * 6)))[2] < left_bound) {
            assert((num_write_minus < 384));
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                       (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (num_write_main = (num_write_main + num_write_tmp));
            (num_write_tmp = 0);
            {
              long i;

              for ((i = 0); (i < 6); (i = (i + 1))) {
                (((local_temp_particle_cache_minus + (num_write_minus * 6)))[i] = ((local_pos_cache + (g * 6)))[i]);
              }
            }
            num_write_minus++;

          } else {
            if (((local_pos_cache + (g * 6)))[2] > right_bound) {
              assert((num_write_plus < 384));
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                long i;

                for ((i = 0); (i < 6); (i = (i + 1))) {
                  (((local_temp_particle_cache_plus + (num_write_plus * 6)))[i] = ((local_pos_cache + (g * 6)))[i]);
                }
              }
              num_write_plus++;

            } else {
              if (((((local_vel_cache)[((g * 3) + 0)] * (local_vel_cache)[((g * 3) + 0)]) +
                    (((local_vel_cache)[((g * 3) + 1)] * (local_vel_cache)[((g * 3) + 1)]) +
                     ((local_vel_cache)[((g * 3) + 2)] * (local_vel_cache)[((g * 3) + 2)]))) >
                   1.00000000000000000e+00)) {
                {
                  long inner_step;

                  for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                    {
                      long inner_g;

                      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                        ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                             ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
                      }
                    }
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);

              } else {
                num_write_tmp++;
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_pos_cache + ((g - num_write_tmp) * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        (num_write_main = (num_write_main + num_write_tmp));
        (num_write_tmp = 0);
      }
      int x_main = num_write_main;

      int x_beg_minus = x_main;

      int x_beg_plus = (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));

      int xm4[4];
      ((xm4)[0] = x_main);
      ((xm4)[1] = (num_write_minus + x_main));
      ((xm4)[2] = x_beg_plus);
      ((xm4)[3] = (num_write_plus + x_beg_plus));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 1) + inner_g)] =
                   (xm4)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (6 * num_write_minus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                 (x_beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      if ((xm4)[3] > grid_cache_len) {
        long i = 0;

        for (i = 0; (i < 4); i++) {
        }
        assert(0);
      }

      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (6 * num_write_plus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                 (x_beg_plus * 6)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }
  }
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }


        long bxyzz = (grid_id / (XLEN * YLEN));

        int is_most_left = (bxyzz == 0);

        int is_most_right = (bxyzz == (ZLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_minus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (6 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                     ((beg_plus * 6) - ((XLEN * YLEN) * (grid_cache_len * 6)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - (XLEN * YLEN)))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (6 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 6)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           6))))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (6 * cur_beg_plus)))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_plus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_x_vlo_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                               long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                               long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));

  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = XLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(0 + (real_p * 6))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 6); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN45 = 0;

        for (; (MYGEN45 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN45 = (MYGEN45 + __xlen))) {
          int ridx = (MYGEN45 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
            ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN46 = 0;

        for (; (MYGEN46 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN46 = (MYGEN46 + __xlen))) {
          int ridx = (MYGEN46 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN47 = 0;

        for (; (MYGEN47 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN47 = (MYGEN47 + __xlen))) {
          int ridx = (MYGEN47 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN48 = (num_write_plus * 6);

    for (; (MYGEN48 > 0); (MYGEN48 = (MYGEN48 + -__xlen))) {
      int ridx = (MYGEN48 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_x_vlo_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 6)];
  double local_temp_particle_cache_minus[(384 * 6)];
  __shared__ int cu_xyzw_shared[4];
  {
    long MYGEN49 = 0;

    for (; (MYGEN49 < 4); (MYGEN49 = (MYGEN49 + __xlen))) {
      int ridx = (MYGEN49 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        long bxyzx = (grid_id % XLEN);


        int is_most_left = (bxyzx == 0);

        int is_most_right = (bxyzx == (XLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_minus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (6 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           ((beg_plus - (1 * grid_cache_len)) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                     ((beg_plus * 6) - (1 * (grid_cache_len * 6)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - 1))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (6 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 6)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           6))))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (6 * cur_beg_plus)))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_plus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_y_vlo_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                               long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                               long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));

  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = YLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(1 + (real_p * 6))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 6); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN50 = 0;

        for (; (MYGEN50 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN50 = (MYGEN50 + __xlen))) {
          int ridx = (MYGEN50 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
            ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN51 = 0;

        for (; (MYGEN51 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN51 = (MYGEN51 + __xlen))) {
          int ridx = (MYGEN51 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN52 = 0;

        for (; (MYGEN52 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN52 = (MYGEN52 + __xlen))) {
          int ridx = (MYGEN52 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN53 = (num_write_plus * 6);

    for (; (MYGEN53 > 0); (MYGEN53 = (MYGEN53 + -__xlen))) {
      int ridx = (MYGEN53 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_y_vlo_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 6)];
  double local_temp_particle_cache_minus[(384 * 6)];
  __shared__ int cu_xyzw_shared[4];
  {
    long MYGEN54 = 0;

    for (; (MYGEN54 < 4); (MYGEN54 = (MYGEN54 + __xlen))) {
      int ridx = (MYGEN54 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }

        long bxyzy = ((grid_id / XLEN) % YLEN);


        int is_most_left = (bxyzy == 0);

        int is_most_right = (bxyzy == (YLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_minus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (6 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           ((beg_plus - (XLEN * grid_cache_len)) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                     ((beg_plus * 6) - (XLEN * (grid_cache_len * 6)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - XLEN))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (6 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 6)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           6))))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (6 * cur_beg_plus)))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_plus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_z_vlo_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                               long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                               long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));

  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = ZLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(2 + (real_p * 6))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 6); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN55 = 0;

        for (; (MYGEN55 < ((cgn_shared)[(p / __xlen)] * 6)); (MYGEN55 = (MYGEN55 + __xlen))) {
          int ridx = (MYGEN55 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 6)) {
            ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN56 = 0;

        for (; (MYGEN56 < ((tln_shared)[(p / __xlen)] * 6)); (MYGEN56 = (MYGEN56 + __xlen))) {
          int ridx = (MYGEN56 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN57 = 0;

        for (; (MYGEN57 < ((trn_shared)[(p / __xlen)] * 6)); (MYGEN57 = (MYGEN57 + __xlen))) {
          int ridx = (MYGEN57 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 6)) {
            ((&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN58 = (num_write_plus * 6);

    for (; (MYGEN58 > 0); (MYGEN58 = (MYGEN58 + -__xlen))) {
      int ridx = (MYGEN58 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_z_vlo_6(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 6)];
  double local_temp_particle_cache_minus[(384 * 6)];
  __shared__ int cu_xyzw_shared[4];
  {
    long MYGEN59 = 0;

    for (; (MYGEN59 < 4); (MYGEN59 = (MYGEN59 + __xlen))) {
      int ridx = (MYGEN59 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }


        long bxyzz = (grid_id / (XLEN * YLEN));

        int is_most_left = (bxyzz == 0);

        int is_most_right = (bxyzz == (ZLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_minus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (6 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) * 6)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                     ((beg_plus * 6) - ((XLEN * YLEN) * (grid_cache_len * 6)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 6)) + (cur_cu_cache_load * 6))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - (XLEN * YLEN)))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (6 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 6)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           6))))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (6 * cur_beg_plus)))[((inner_step * (6 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                         (beg_plus * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (6 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (beg_minus * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 6)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_x_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));

  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    long grid_id = i;

    long bxyzx = (grid_id % XLEN);


    int cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];

    int cur_load = cur_load0;


    int lg = 0;


    long left_bound = bxyzx;

    long right_bound = (bxyzx + 1);


    long num_write_minus = 0;

    long num_write_plus = 0;

    long num_write_main = 0;


    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      int cur_grid_num = 0;

      int to_left_num = 0;

      int to_right_num = 0;

      __shared__ int cgn_shared[IDX_LOCAL_XLEN];
      __shared__ int tln_shared[IDX_LOCAL_XLEN];
      __shared__ int trn_shared[IDX_LOCAL_XLEN];
      {
        long p;

        for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          int real_p = p;

          int local_p_id = (p - (lg + (__idx * __xlen)));

          int if_exist_particle = (real_p < cur_load);

          double particle_sort_key_element =
              ((if_exist_particle) ? (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (real_p * 8))])
                                   : (-1));

          int is_to_left = (particle_sort_key_element < left_bound);

          int is_to_right = (particle_sort_key_element > right_bound);

          int is_cur = ((!is_to_right) && (!is_to_left));

          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            long i;

            for ((i = 0); (i < 8); (i = (i + 1))) {
              if (is_to_left) {
                ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_to_right) {
                ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_cur) {
                (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               8)))[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }
            }
          }
          if (is_cur) {
            (cur_grid_num = (cur_grid_num + 1));
          }

          if (is_to_left) {
            (to_left_num = (to_left_num + 1));
          }

          if (is_to_right) {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __syncthreads();
      long p = 0;

      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
        {
          long MYGEN60 = 0;

          for (; (MYGEN60 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN60 = (MYGEN60 + __xlen))) {
            int ridx = (MYGEN60 + __idx);

            if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
              ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                8)))[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                   (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                    8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
        {
          long MYGEN61 = 0;

          for (; (MYGEN61 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN61 = (MYGEN61 + __xlen))) {
            int ridx = (MYGEN61 + __idx);

            if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
              ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                   (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
        {
          long MYGEN62 = 0;

          for (; (MYGEN62 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN62 = (MYGEN62 + __xlen))) {
            int ridx = (MYGEN62 + __idx);

            if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
              ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                   (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
        __syncthreads();
      }
    }
    int is_most_left = (bxyzx == 0);

    int is_most_right = (bxyzx == (XLEN - 1));

    int beg_left_main = grid_cache_len;

    int beg_plus = 0;

    int end_plus = 0;

    if (!is_most_left) {
      (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - 1))]);
      (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 2)]);
      (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 3)]);
    }

    {
      int num_copy_real_11516lap = (end_plus - beg_plus);

      if (num_copy_real_11516lap > (grid_cache_len - num_write_main)) {
        (num_copy_real_11516lap = (grid_cache_len - num_write_main));
        {
          long MYGEN63 = 0;

          for (; (MYGEN63 < (8 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
               (MYGEN63 = (MYGEN63 + __xlen))) {
            int ridx = (MYGEN63 + __idx);

            if ((ridx < (8 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (beg_plus - (1 * grid_cache_len)))))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
      }

      {
        long MYGEN64 = 0;

        for (; (MYGEN64 < (num_copy_real_11516lap * 8)); (MYGEN64 = (MYGEN64 + __xlen))) {
          int ridx = (MYGEN64 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
               (num_write_main * 8)))[ridx] =
                 (&(((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (beg_plus - (1 * grid_cache_len)))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_minus;

      if (num_copy_real_11516lap > (grid_cache_len - beg_left_main)) {
        (num_copy_real_11516lap = (grid_cache_len - beg_left_main));
        {
          long MYGEN65 = 0;

          for (; (MYGEN65 < (8 * (num_write_minus - (grid_cache_len - beg_left_main))));
               (MYGEN65 = (MYGEN65 + __xlen))) {
            int ridx = (MYGEN65 + __idx);

            if ((ridx < (8 * (num_write_minus - (grid_cache_len - beg_left_main))))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_minus - (grid_cache_len - beg_left_main))));
      }

      {
        long MYGEN66 = 0;

        for (; (MYGEN66 < (num_copy_real_11516lap * 8)); (MYGEN66 = (MYGEN66 + __xlen))) {
          int ridx = (MYGEN66 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               8)))[(0 + (8 * ((__idx * (__xlen * 0)) + -((1 * grid_cache_len)))))]) +
               (beg_left_main * 8)))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if ((!is_most_left) && (__idx == 0)) {
      ((xyzw)[(4 * ((cu_offset + grid_id) - 1))] = beg_left_main);
    }

    int cap_tmp = ((is_most_right) ? (0) : ((grid_cache_len - num_write_main)));

    int total_cache_num = num_write_main;

    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_plus;

      if (num_copy_real_11516lap > cap_tmp) {
        (num_copy_real_11516lap = cap_tmp);
        {
          long MYGEN67 = 0;

          for (; (MYGEN67 < (8 * (num_write_plus - cap_tmp))); (MYGEN67 = (MYGEN67 + __xlen))) {
            int ridx = (MYGEN67 + __idx);

            if (ridx < (8 * (num_write_plus - cap_tmp))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_plus - cap_tmp)));
      }

      {
        long MYGEN68 = 0;

        for (; (MYGEN68 < (num_copy_real_11516lap * 8)); (MYGEN68 = (MYGEN68 + __xlen))) {
          int ridx = (MYGEN68 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
               (total_cache_num * 8)))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);
    if (__idx == 0) {
      {
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 4) + inner_g)] =
                     (xm4)[((inner_step * 4) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }
  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = XLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(0 + (real_p * 8))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 8); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN69 = 0;

        for (; (MYGEN69 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN69 = (MYGEN69 + __xlen))) {
          int ridx = (MYGEN69 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
            ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN70 = 0;

        for (; (MYGEN70 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN70 = (MYGEN70 + __xlen))) {
          int ridx = (MYGEN70 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN71 = 0;

        for (; (MYGEN71 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN71 = (MYGEN71 + __xlen))) {
          int ridx = (MYGEN71 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN72 = (num_write_plus * 8);

    for (; (MYGEN72 > 0); (MYGEN72 = (MYGEN72 + -__xlen))) {
      int ridx = (MYGEN72 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_x_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                       long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
                                       long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 8)];
  double local_temp_particle_cache_minus[(384 * 8)];
  double local_pos_cache[(64 * 8)];
  double local_vel_cache[192];
  __shared__ int cu_xyzw_shared[4];
  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  if (__idx == 0) {
    {

      int beg_to_left = ((2 * cu_cache_length) / 5);

      int cur_to_left = beg_to_left;

      int cur_to_right = cu_cache_length;

      int cur_this = 0;

      int lg;

      int g;

      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cu_cur_cache_load)) ? ((cu_cur_cache_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((cu_cache + (__idy * (8 * cu_cache_length))) + (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {

          if (((local_pos_cache + (g * 8)))[0] < 0) {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((cu_cache + (__idy * (8 * cu_cache_length))) +
                       (cur_to_left * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {
            if (((local_pos_cache + (g * 8)))[0] > XLEN) {
              cur_to_right--;
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (8 * cu_cache_length))) +
                         (cur_to_right * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
            } else {
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (8 * cu_cache_length))) + (cur_this * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (cur_this = (cur_this + 1));
            }
          }
        }
      }
      ((cu_xyzw_shared)[0] = cur_this);
      ((cu_xyzw_shared)[1] = beg_to_left);
      ((cu_xyzw_shared)[2] = cur_to_left);
      ((cu_xyzw_shared)[3] = cur_to_right);
    }
  }

  __syncthreads();
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    long grid_id = (__idx + (i * __xlen));

    if (grid_id < xyzalllen) {
      int cur_load = (xyzw)[(4 * (cu_offset + grid_id))];

      long bxyzx = (grid_id % XLEN);


      int g = 0;

      int lg = 0;


      long left_bound = bxyzx;

      long right_bound = (left_bound + 1);


      long num_write_minus = 0;

      long num_write_plus = 0;

      long num_write_main = 0;

      long num_write_tmp = 0;

      for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cur_load)) ? ((cur_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (lg * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < num_read); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 3); (inner_g = (inner_g + 1))) {
                  ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (3 + (lg * 8))))[((inner_step * 8) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {
          if (((local_pos_cache + (g * 8)))[0] < left_bound) {
            assert((num_write_minus < 384));
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                       (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (num_write_main = (num_write_main + num_write_tmp));
            (num_write_tmp = 0);
            {
              long i;

              for ((i = 0); (i < 8); (i = (i + 1))) {
                (((local_temp_particle_cache_minus + (num_write_minus * 8)))[i] = ((local_pos_cache + (g * 8)))[i]);
              }
            }
            num_write_minus++;

          } else {
            if (((local_pos_cache + (g * 8)))[0] > right_bound) {
              assert((num_write_plus < 384));
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                long i;

                for ((i = 0); (i < 8); (i = (i + 1))) {
                  (((local_temp_particle_cache_plus + (num_write_plus * 8)))[i] = ((local_pos_cache + (g * 8)))[i]);
                }
              }
              num_write_plus++;

            } else {
              if (((((local_vel_cache)[((g * 3) + 0)] * (local_vel_cache)[((g * 3) + 0)]) +
                    (((local_vel_cache)[((g * 3) + 1)] * (local_vel_cache)[((g * 3) + 1)]) +
                     ((local_vel_cache)[((g * 3) + 2)] * (local_vel_cache)[((g * 3) + 2)]))) >
                   1.00000000000000000e+00)) {
                {
                  long inner_step;

                  for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                    {
                      long inner_g;

                      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                        ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                             ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                      }
                    }
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);

              } else {
                num_write_tmp++;
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        (num_write_main = (num_write_main + num_write_tmp));
        (num_write_tmp = 0);
      }
      int x_main = num_write_main;

      int x_beg_minus = x_main;

      int x_beg_plus = (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));

      int xm4[4];
      ((xm4)[0] = x_main);
      ((xm4)[1] = (num_write_minus + x_main));
      ((xm4)[2] = x_beg_plus);
      ((xm4)[3] = (num_write_plus + x_beg_plus));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 1) + inner_g)] =
                   (xm4)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (8 * num_write_minus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                 (x_beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      if ((xm4)[3] > grid_cache_len) {
        long i = 0;

        for (i = 0; (i < 4); i++) {
        }
        assert(0);
      }

      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (8 * num_write_plus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                 (x_beg_plus * 8)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }
  }
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        long bxyzx = (grid_id % XLEN);


        int is_most_left = (bxyzx == 0);

        int is_most_right = (bxyzx == (XLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_minus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (8 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           ((beg_plus - (1 * grid_cache_len)) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 8)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                     ((beg_plus * 8) - (1 * (grid_cache_len * 8)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - 1))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (8 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 8)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           8))))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (8 * cur_beg_plus)))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_plus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_y_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));

  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    long grid_id = i;


    long bxyzy = ((grid_id / XLEN) % YLEN);


    int cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];

    int cur_load = cur_load0;


    int lg = 0;


    long left_bound = bxyzy;

    long right_bound = (bxyzy + 1);


    long num_write_minus = 0;

    long num_write_plus = 0;

    long num_write_main = 0;


    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      int cur_grid_num = 0;

      int to_left_num = 0;

      int to_right_num = 0;

      __shared__ int cgn_shared[IDX_LOCAL_XLEN];
      __shared__ int tln_shared[IDX_LOCAL_XLEN];
      __shared__ int trn_shared[IDX_LOCAL_XLEN];
      {
        long p;

        for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          int real_p = p;

          int local_p_id = (p - (lg + (__idx * __xlen)));

          int if_exist_particle = (real_p < cur_load);

          double particle_sort_key_element =
              ((if_exist_particle) ? (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(1 + (real_p * 8))])
                                   : (-1));

          int is_to_left = (particle_sort_key_element < left_bound);

          int is_to_right = (particle_sort_key_element > right_bound);

          int is_cur = ((!is_to_right) && (!is_to_left));

          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            long i;

            for ((i = 0); (i < 8); (i = (i + 1))) {
              if (is_to_left) {
                ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_to_right) {
                ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_cur) {
                (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               8)))[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }
            }
          }
          if (is_cur) {
            (cur_grid_num = (cur_grid_num + 1));
          }

          if (is_to_left) {
            (to_left_num = (to_left_num + 1));
          }

          if (is_to_right) {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __syncthreads();
      long p = 0;

      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
        {
          long MYGEN73 = 0;

          for (; (MYGEN73 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN73 = (MYGEN73 + __xlen))) {
            int ridx = (MYGEN73 + __idx);

            if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
              ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                8)))[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                   (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                    8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
        {
          long MYGEN74 = 0;

          for (; (MYGEN74 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN74 = (MYGEN74 + __xlen))) {
            int ridx = (MYGEN74 + __idx);

            if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
              ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                   (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
        {
          long MYGEN75 = 0;

          for (; (MYGEN75 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN75 = (MYGEN75 + __xlen))) {
            int ridx = (MYGEN75 + __idx);

            if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
              ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                   (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
        __syncthreads();
      }
    }
    int is_most_left = (bxyzy == 0);

    int is_most_right = (bxyzy == (YLEN - 1));

    int beg_left_main = grid_cache_len;

    int beg_plus = 0;

    int end_plus = 0;

    if (!is_most_left) {
      (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - XLEN))]);
      (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 2)]);
      (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 3)]);
    }

    {
      int num_copy_real_11516lap = (end_plus - beg_plus);

      if (num_copy_real_11516lap > (grid_cache_len - num_write_main)) {
        (num_copy_real_11516lap = (grid_cache_len - num_write_main));
        {
          long MYGEN76 = 0;

          for (; (MYGEN76 < (8 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
               (MYGEN76 = (MYGEN76 + __xlen))) {
            int ridx = (MYGEN76 + __idx);

            if ((ridx < (8 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] = ((
                   &(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (beg_plus - (XLEN * grid_cache_len)))))]) +
                   (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
      }

      {
        long MYGEN77 = 0;

        for (; (MYGEN77 < (num_copy_real_11516lap * 8)); (MYGEN77 = (MYGEN77 + __xlen))) {
          int ridx = (MYGEN77 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
               (num_write_main * 8)))[ridx] =
                 (&(((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (beg_plus - (XLEN * grid_cache_len)))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_minus;

      if (num_copy_real_11516lap > (grid_cache_len - beg_left_main)) {
        (num_copy_real_11516lap = (grid_cache_len - beg_left_main));
        {
          long MYGEN78 = 0;

          for (; (MYGEN78 < (8 * (num_write_minus - (grid_cache_len - beg_left_main))));
               (MYGEN78 = (MYGEN78 + __xlen))) {
            int ridx = (MYGEN78 + __idx);

            if ((ridx < (8 * (num_write_minus - (grid_cache_len - beg_left_main))))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_minus - (grid_cache_len - beg_left_main))));
      }

      {
        long MYGEN79 = 0;

        for (; (MYGEN79 < (num_copy_real_11516lap * 8)); (MYGEN79 = (MYGEN79 + __xlen))) {
          int ridx = (MYGEN79 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               8)))[(0 + (8 * ((__idx * (__xlen * 0)) + -((XLEN * grid_cache_len)))))]) +
               (beg_left_main * 8)))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if ((!is_most_left) && (__idx == 0)) {
      ((xyzw)[(4 * ((cu_offset + grid_id) - XLEN))] = beg_left_main);
    }

    int cap_tmp = ((is_most_right) ? (0) : ((grid_cache_len - num_write_main)));

    int total_cache_num = num_write_main;

    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_plus;

      if (num_copy_real_11516lap > cap_tmp) {
        (num_copy_real_11516lap = cap_tmp);
        {
          long MYGEN80 = 0;

          for (; (MYGEN80 < (8 * (num_write_plus - cap_tmp))); (MYGEN80 = (MYGEN80 + __xlen))) {
            int ridx = (MYGEN80 + __idx);

            if (ridx < (8 * (num_write_plus - cap_tmp))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_plus - cap_tmp)));
      }

      {
        long MYGEN81 = 0;

        for (; (MYGEN81 < (num_copy_real_11516lap * 8)); (MYGEN81 = (MYGEN81 + __xlen))) {
          int ridx = (MYGEN81 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
               (total_cache_num * 8)))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);
    if (__idx == 0) {
      {
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 4) + inner_g)] =
                     (xm4)[((inner_step * 4) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }
  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = YLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(1 + (real_p * 8))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 8); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN82 = 0;

        for (; (MYGEN82 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN82 = (MYGEN82 + __xlen))) {
          int ridx = (MYGEN82 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
            ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN83 = 0;

        for (; (MYGEN83 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN83 = (MYGEN83 + __xlen))) {
          int ridx = (MYGEN83 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN84 = 0;

        for (; (MYGEN84 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN84 = (MYGEN84 + __xlen))) {
          int ridx = (MYGEN84 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN85 = (num_write_plus * 8);

    for (; (MYGEN85 > 0); (MYGEN85 = (MYGEN85 + -__xlen))) {
      int ridx = (MYGEN85 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_y_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                       long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
                                       long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 8)];
  double local_temp_particle_cache_minus[(384 * 8)];
  double local_pos_cache[(64 * 8)];
  double local_vel_cache[192];
  __shared__ int cu_xyzw_shared[4];
  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  if (__idx == 0) {
    {

      int beg_to_left = ((2 * cu_cache_length) / 5);

      int cur_to_left = beg_to_left;

      int cur_to_right = cu_cache_length;

      int cur_this = 0;

      int lg;

      int g;

      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cu_cur_cache_load)) ? ((cu_cur_cache_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((cu_cache + (__idy * (8 * cu_cache_length))) + (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {

          if (((local_pos_cache + (g * 8)))[1] < 0) {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((cu_cache + (__idy * (8 * cu_cache_length))) +
                       (cur_to_left * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {
            if (((local_pos_cache + (g * 8)))[1] > YLEN) {
              cur_to_right--;
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (8 * cu_cache_length))) +
                         (cur_to_right * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
            } else {
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (8 * cu_cache_length))) + (cur_this * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (cur_this = (cur_this + 1));
            }
          }
        }
      }
      ((cu_xyzw_shared)[0] = cur_this);
      ((cu_xyzw_shared)[1] = beg_to_left);
      ((cu_xyzw_shared)[2] = cur_to_left);
      ((cu_xyzw_shared)[3] = cur_to_right);
    }
  }

  __syncthreads();
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    long grid_id = (__idx + (i * __xlen));

    if (grid_id < xyzalllen) {
      int cur_load = (xyzw)[(4 * (cu_offset + grid_id))];


      long bxyzy = ((grid_id / XLEN) % YLEN);


      int g = 0;

      int lg = 0;


      long left_bound = bxyzy;

      long right_bound = (left_bound + 1);


      long num_write_minus = 0;

      long num_write_plus = 0;

      long num_write_main = 0;

      long num_write_tmp = 0;

      for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cur_load)) ? ((cur_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (lg * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < num_read); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 3); (inner_g = (inner_g + 1))) {
                  ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (3 + (lg * 8))))[((inner_step * 8) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {
          if (((local_pos_cache + (g * 8)))[1] < left_bound) {
            assert((num_write_minus < 384));
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                       (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (num_write_main = (num_write_main + num_write_tmp));
            (num_write_tmp = 0);
            {
              long i;

              for ((i = 0); (i < 8); (i = (i + 1))) {
                (((local_temp_particle_cache_minus + (num_write_minus * 8)))[i] = ((local_pos_cache + (g * 8)))[i]);
              }
            }
            num_write_minus++;

          } else {
            if (((local_pos_cache + (g * 8)))[1] > right_bound) {
              assert((num_write_plus < 384));
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                long i;

                for ((i = 0); (i < 8); (i = (i + 1))) {
                  (((local_temp_particle_cache_plus + (num_write_plus * 8)))[i] = ((local_pos_cache + (g * 8)))[i]);
                }
              }
              num_write_plus++;

            } else {
              if (((((local_vel_cache)[((g * 3) + 0)] * (local_vel_cache)[((g * 3) + 0)]) +
                    (((local_vel_cache)[((g * 3) + 1)] * (local_vel_cache)[((g * 3) + 1)]) +
                     ((local_vel_cache)[((g * 3) + 2)] * (local_vel_cache)[((g * 3) + 2)]))) >
                   1.00000000000000000e+00)) {
                {
                  long inner_step;

                  for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                    {
                      long inner_g;

                      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                        ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                             ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                      }
                    }
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);

              } else {
                num_write_tmp++;
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        (num_write_main = (num_write_main + num_write_tmp));
        (num_write_tmp = 0);
      }
      int x_main = num_write_main;

      int x_beg_minus = x_main;

      int x_beg_plus = (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));

      int xm4[4];
      ((xm4)[0] = x_main);
      ((xm4)[1] = (num_write_minus + x_main));
      ((xm4)[2] = x_beg_plus);
      ((xm4)[3] = (num_write_plus + x_beg_plus));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 1) + inner_g)] =
                   (xm4)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (8 * num_write_minus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                 (x_beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      if ((xm4)[3] > grid_cache_len) {
        long i = 0;

        for (i = 0; (i < 4); i++) {
        }
        assert(0);
      }

      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (8 * num_write_plus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                 (x_beg_plus * 8)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }
  }
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }

        long bxyzy = ((grid_id / XLEN) % YLEN);


        int is_most_left = (bxyzy == 0);

        int is_most_right = (bxyzy == (YLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_minus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (8 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           ((beg_plus - (XLEN * grid_cache_len)) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 8)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                     ((beg_plus * 8) - (XLEN * (grid_cache_len * 8)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - XLEN))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (8 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 8)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           8))))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (8 * cur_beg_plus)))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_plus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_z_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));


  long i = 0;

  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));

  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    long grid_id = i;


    long bxyzz = (grid_id / (XLEN * YLEN));

    int cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];

    int cur_load = cur_load0;


    int lg = 0;


    long left_bound = bxyzz;

    long right_bound = (bxyzz + 1);


    long num_write_minus = 0;

    long num_write_plus = 0;

    long num_write_main = 0;


    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      int cur_grid_num = 0;

      int to_left_num = 0;

      int to_right_num = 0;

      __shared__ int cgn_shared[IDX_LOCAL_XLEN];
      __shared__ int tln_shared[IDX_LOCAL_XLEN];
      __shared__ int trn_shared[IDX_LOCAL_XLEN];
      {
        long p;

        for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          int real_p = p;

          int local_p_id = (p - (lg + (__idx * __xlen)));

          int if_exist_particle = (real_p < cur_load);

          double particle_sort_key_element =
              ((if_exist_particle) ? (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(2 + (real_p * 8))])
                                   : (-1));

          int is_to_left = (particle_sort_key_element < left_bound);

          int is_to_right = (particle_sort_key_element > right_bound);

          int is_cur = ((!is_to_right) && (!is_to_left));

          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            long i;

            for ((i = 0); (i < 8); (i = (i + 1))) {
              if (is_to_left) {
                ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_to_right) {
                ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }

              if (is_cur) {
                (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               8)))[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                     ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                   8)))[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
              }
            }
          }
          if (is_cur) {
            (cur_grid_num = (cur_grid_num + 1));
          }

          if (is_to_left) {
            (to_left_num = (to_left_num + 1));
          }

          if (is_to_right) {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __syncthreads();
      long p = 0;

      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
        {
          long MYGEN86 = 0;

          for (; (MYGEN86 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN86 = (MYGEN86 + __xlen))) {
            int ridx = (MYGEN86 + __idx);

            if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
              ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                8)))[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                   (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                    8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
        {
          long MYGEN87 = 0;

          for (; (MYGEN87 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN87 = (MYGEN87 + __xlen))) {
            int ridx = (MYGEN87 + __idx);

            if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
              ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                   (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
        {
          long MYGEN88 = 0;

          for (; (MYGEN88 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN88 = (MYGEN88 + __xlen))) {
            int ridx = (MYGEN88 + __idx);

            if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
              ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                   (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
            }
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
        __syncthreads();
      }
    }
    int is_most_left = (bxyzz == 0);

    int is_most_right = (bxyzz == (ZLEN - 1));

    int beg_left_main = grid_cache_len;

    int beg_plus = 0;

    int end_plus = 0;

    if (!is_most_left) {
      (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))]);
      (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)]);
      (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 3)]);
    }

    {
      int num_copy_real_11516lap = (end_plus - beg_plus);

      if (num_copy_real_11516lap > (grid_cache_len - num_write_main)) {
        (num_copy_real_11516lap = (grid_cache_len - num_write_main));
        {
          long MYGEN89 = 0;

          for (; (MYGEN89 < (8 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
               (MYGEN89 = (MYGEN89 + __xlen))) {
            int ridx = (MYGEN89 + __idx);

            if ((ridx < (8 * ((end_plus - beg_plus) - (grid_cache_len - num_write_main))))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                         0 + (8 * ((__idx * (__xlen * 0)) + (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
      }

      {
        long MYGEN90 = 0;

        for (; (MYGEN90 < (num_copy_real_11516lap * 8)); (MYGEN90 = (MYGEN90 + __xlen))) {
          int ridx = (MYGEN90 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
               (num_write_main * 8)))[ridx] =
                 (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                     0 + (8 * ((__idx * (__xlen * 0)) + (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_minus;

      if (num_copy_real_11516lap > (grid_cache_len - beg_left_main)) {
        (num_copy_real_11516lap = (grid_cache_len - beg_left_main));
        {
          long MYGEN91 = 0;

          for (; (MYGEN91 < (8 * (num_write_minus - (grid_cache_len - beg_left_main))));
               (MYGEN91 = (MYGEN91 + __xlen))) {
            int ridx = (MYGEN91 + __idx);

            if ((ridx < (8 * (num_write_minus - (grid_cache_len - beg_left_main))))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_minus - (grid_cache_len - beg_left_main))));
      }

      {
        long MYGEN92 = 0;

        for (; (MYGEN92 < (num_copy_real_11516lap * 8)); (MYGEN92 = (MYGEN92 + __xlen))) {
          int ridx = (MYGEN92 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                               8)))[(0 + (8 * ((__idx * (__xlen * 0)) + -(((XLEN * YLEN) * grid_cache_len)))))]) +
               (beg_left_main * 8)))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if ((!is_most_left) && (__idx == 0)) {
      ((xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))] = beg_left_main);
    }

    int cap_tmp = ((is_most_right) ? (0) : ((grid_cache_len - num_write_main)));

    int total_cache_num = num_write_main;

    __syncthreads();
    {
      int num_copy_real_11516lap = num_write_plus;

      if (num_copy_real_11516lap > cap_tmp) {
        (num_copy_real_11516lap = cap_tmp);
        {
          long MYGEN93 = 0;

          for (; (MYGEN93 < (8 * (num_write_plus - cap_tmp))); (MYGEN93 = (MYGEN93 + __xlen))) {
            int ridx = (MYGEN93 + __idx);

            if (ridx < (8 * (num_write_plus - cap_tmp))) {
              (((cu_cache_head + (8 * cu_cur_cache_load)))[ridx] =
                   ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                     (num_copy_real_11516lap * 8)))[ridx]);
            }
          }
        }
        (cu_cur_cache_load = (cu_cur_cache_load + (num_write_plus - cap_tmp)));
      }

      {
        long MYGEN94 = 0;

        for (; (MYGEN94 < (num_copy_real_11516lap * 8)); (MYGEN94 = (MYGEN94 + __xlen))) {
          int ridx = (MYGEN94 + __idx);

          if (ridx < (num_copy_real_11516lap * 8)) {
            (((&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) * 8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
               (total_cache_num * 8)))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
          }
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);
    if (__idx == 0) {
      {
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 4) + inner_g)] =
                     (xm4)[((inner_step * 4) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }
  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = ZLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(2 + (real_p * 8))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 8); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN95 = 0;

        for (; (MYGEN95 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN95 = (MYGEN95 + __xlen))) {
          int ridx = (MYGEN95 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
            ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN96 = 0;

        for (; (MYGEN96 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN96 = (MYGEN96 + __xlen))) {
          int ridx = (MYGEN96 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN97 = 0;

        for (; (MYGEN97 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN97 = (MYGEN97 + __xlen))) {
          int ridx = (MYGEN97 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN98 = (num_write_plus * 8);

    for (; (MYGEN98 > 0); (MYGEN98 = (MYGEN98 + -__xlen))) {
      int ridx = (MYGEN98 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_z_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                       long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp, long numvec,
                                       long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 8)];
  double local_temp_particle_cache_minus[(384 * 8)];
  double local_pos_cache[(64 * 8)];
  double local_vel_cache[192];
  __shared__ int cu_xyzw_shared[4];
  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  if (__idx == 0) {
    {

      int beg_to_left = ((2 * cu_cache_length) / 5);

      int cur_to_left = beg_to_left;

      int cur_to_right = cu_cache_length;

      int cur_this = 0;

      int lg;

      int g;

      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cu_cur_cache_load)) ? ((cu_cur_cache_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 6)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((cu_cache + (__idy * (8 * cu_cache_length))) + (lg * 6)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {

          if (((local_pos_cache + (g * 8)))[2] < 0) {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((cu_cache + (__idy * (8 * cu_cache_length))) +
                       (cur_to_left * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {
            if (((local_pos_cache + (g * 8)))[2] > ZLEN) {
              cur_to_right--;
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (8 * cu_cache_length))) +
                         (cur_to_right * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
            } else {
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((cu_cache + (__idy * (8 * cu_cache_length))) + (cur_this * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + (g * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (cur_this = (cur_this + 1));
            }
          }
        }
      }
      ((cu_xyzw_shared)[0] = cur_this);
      ((cu_xyzw_shared)[1] = beg_to_left);
      ((cu_xyzw_shared)[2] = cur_to_left);
      ((cu_xyzw_shared)[3] = cur_to_right);
    }
  }

  __syncthreads();
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    long grid_id = (__idx + (i * __xlen));

    if (grid_id < xyzalllen) {
      int cur_load = (xyzw)[(4 * (cu_offset + grid_id))];


      long bxyzz = (grid_id / (XLEN * YLEN));

      int g = 0;

      int lg = 0;


      long left_bound = bxyzz;

      long right_bound = (left_bound + 1);


      long num_write_minus = 0;

      long num_write_plus = 0;

      long num_write_main = 0;

      long num_write_tmp = 0;

      for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
        long num_read = ((((lg + 64) > cur_load)) ? ((cur_load - lg)) : (64));

        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_read * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_pos_cache + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (lg * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < num_read); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 3); (inner_g = (inner_g + 1))) {
                  ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (3 + (lg * 8))))[((inner_step * 8) + inner_g)]);
                }
              }
            }
          }
        }
        for (g = 0; (g < num_read); g++) {
          if (((local_pos_cache + (g * 8)))[2] < left_bound) {
            assert((num_write_minus < 384));
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                       (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                         ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
            (num_write_main = (num_write_main + num_write_tmp));
            (num_write_tmp = 0);
            {
              long i;

              for ((i = 0); (i < 8); (i = (i + 1))) {
                (((local_temp_particle_cache_minus + (num_write_minus * 8)))[i] = ((local_pos_cache + (g * 8)))[i]);
              }
            }
            num_write_minus++;

          } else {
            if (((local_pos_cache + (g * 8)))[2] > right_bound) {
              assert((num_write_plus < 384));
              {
                long inner_step;

                for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                  {
                    long inner_g;

                    for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                      ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                           ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                    }
                  }
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                long i;

                for ((i = 0); (i < 8); (i = (i + 1))) {
                  (((local_temp_particle_cache_plus + (num_write_plus * 8)))[i] = ((local_pos_cache + (g * 8)))[i]);
                }
              }
              num_write_plus++;

            } else {
              if (((((local_vel_cache)[((g * 3) + 0)] * (local_vel_cache)[((g * 3) + 0)]) +
                    (((local_vel_cache)[((g * 3) + 1)] * (local_vel_cache)[((g * 3) + 1)]) +
                     ((local_vel_cache)[((g * 3) + 2)] * (local_vel_cache)[((g * 3) + 2)]))) >
                   1.00000000000000000e+00)) {
                {
                  long inner_step;

                  for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
                    {
                      long inner_g;

                      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                        ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                             ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
                      }
                    }
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);

              } else {
                num_write_tmp++;
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_write_tmp * 6)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (num_write_main * 6)))[((inner_step * 1) + inner_g)] =
                     ((local_pos_cache + ((g - num_write_tmp) * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        (num_write_main = (num_write_main + num_write_tmp));
        (num_write_tmp = 0);
      }
      int x_main = num_write_main;

      int x_beg_minus = x_main;

      int x_beg_plus = (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));

      int xm4[4];
      ((xm4)[0] = x_main);
      ((xm4)[1] = (num_write_minus + x_main));
      ((xm4)[2] = x_beg_plus);
      ((xm4)[3] = (num_write_plus + x_beg_plus));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((xyzw + (4 * (cu_offset + grid_id))))[((inner_step * 1) + inner_g)] =
                   (xm4)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (8 * num_write_minus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                 (x_beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      if ((xm4)[3] > grid_cache_len) {
        long i = 0;

        for (i = 0; (i < 4); i++) {
        }
        assert(0);
      }

      {
        long inner_step;

        for ((inner_step = 0); (inner_step < (8 * num_write_plus)); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                 (x_beg_plus * 8)))[((inner_step * 1) + inner_g)] =
                   ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }
  }
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }


        long bxyzz = (grid_id / (XLEN * YLEN));

        int is_most_left = (bxyzz == 0);

        int is_most_right = (bxyzz == (ZLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_minus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (8 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 8)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                     ((beg_plus * 8) - ((XLEN * YLEN) * (grid_cache_len * 8)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - (XLEN * YLEN)))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (8 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 8)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           8))))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (8 * cur_beg_plus)))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_plus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_x_vlo_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                               long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                               long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));

  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = XLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(0 + (real_p * 8))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 8); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN99 = 0;

        for (; (MYGEN99 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN99 = (MYGEN99 + __xlen))) {
          int ridx = (MYGEN99 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
            ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN100 = 0;

        for (; (MYGEN100 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN100 = (MYGEN100 + __xlen))) {
          int ridx = (MYGEN100 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN101 = 0;

        for (; (MYGEN101 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN101 = (MYGEN101 + __xlen))) {
          int ridx = (MYGEN101 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN102 = (num_write_plus * 8);

    for (; (MYGEN102 > 0); (MYGEN102 = (MYGEN102 + -__xlen))) {
      int ridx = (MYGEN102 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_x_vlo_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 8)];
  double local_temp_particle_cache_minus[(384 * 8)];
  __shared__ int cu_xyzw_shared[4];
  {
    long MYGEN103 = 0;

    for (; (MYGEN103 < 4); (MYGEN103 = (MYGEN103 + __xlen))) {
      int ridx = (MYGEN103 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        long bxyzx = (grid_id % XLEN);


        int is_most_left = (bxyzx == 0);

        int is_most_right = (bxyzx == (XLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_minus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (8 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           ((beg_plus - (1 * grid_cache_len)) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 8)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                     ((beg_plus * 8) - (1 * (grid_cache_len * 8)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - 1))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (8 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 8)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           8))))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (8 * cur_beg_plus)))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_plus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_y_vlo_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                               long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                               long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));

  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = YLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(1 + (real_p * 8))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 8); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN104 = 0;

        for (; (MYGEN104 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN104 = (MYGEN104 + __xlen))) {
          int ridx = (MYGEN104 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
            ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN105 = 0;

        for (; (MYGEN105 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN105 = (MYGEN105 + __xlen))) {
          int ridx = (MYGEN105 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN106 = 0;

        for (; (MYGEN106 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN106 = (MYGEN106 + __xlen))) {
          int ridx = (MYGEN106 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN107 = (num_write_plus * 8);

    for (; (MYGEN107 > 0); (MYGEN107 = (MYGEN107 + -__xlen))) {
      int ridx = (MYGEN107 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_y_vlo_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 8)];
  double local_temp_particle_cache_minus[(384 * 8)];
  __shared__ int cu_xyzw_shared[4];
  {
    long MYGEN108 = 0;

    for (; (MYGEN108 < 4); (MYGEN108 = (MYGEN108 + __xlen))) {
      int ridx = (MYGEN108 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }

        long bxyzy = ((grid_id / XLEN) % YLEN);


        int is_most_left = (bxyzy == 0);

        int is_most_right = (bxyzy == (YLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_minus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (8 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           ((beg_plus - (XLEN * grid_cache_len)) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 8)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                     ((beg_plus * 8) - (XLEN * (grid_cache_len * 8)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - XLEN))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (8 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 8)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           8))))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (8 * cur_beg_plus)))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_plus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void cuda_gpu_sort_one_grid_z_vlo_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                               long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                               long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  int cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];

  double *for_sort_grid_memory_left = (cu_cache + (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));

  double *for_sort_grid_memory_right = (cu_cache + (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));

  double *cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));

  int cur_load = cu_cur_cache_load;


  int lg = 0;


  long left_bound = 0;

  long right_bound = ZLEN;


  long num_write_minus = 0;

  long num_write_plus = 0;

  long num_write_main = 0;


  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    int cur_grid_num = 0;

    int to_left_num = 0;

    int to_right_num = 0;

    __shared__ int cgn_shared[IDX_LOCAL_XLEN];
    __shared__ int tln_shared[IDX_LOCAL_XLEN];
    __shared__ int trn_shared[IDX_LOCAL_XLEN];
    {
      long p;

      for ((p = (lg + (__idx * __xlen))); (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        int real_p = p;

        int local_p_id = (p - (lg + (__idx * __xlen)));

        int if_exist_particle = (real_p < cur_load);

        double particle_sort_key_element = ((if_exist_particle) ? ((cu_cache_head)[(2 + (real_p * 8))]) : (-1));

        int is_to_left = (particle_sort_key_element < left_bound);

        int is_to_right = (particle_sort_key_element > right_bound);

        int is_cur = ((!is_to_right) && (!is_to_left));

        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          long i;

          for ((i = 0); (i < 8); (i = (i + 1))) {
            if (is_to_left) {
              ((for_sort_grid_memory_left)[(i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_to_right) {
              ((for_sort_grid_memory_right)[(i + (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }

            if (is_cur) {
              ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (cur_grid_num + lg))))] =
                   (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) + (local_p_id + lg))))]);
            }
          }
        }
        if (is_cur) {
          (cur_grid_num = (cur_grid_num + 1));
        }

        if (is_to_left) {
          (to_left_num = (to_left_num + 1));
        }

        if (is_to_right) {
          (to_right_num = (to_right_num + 1));
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __syncthreads();
    long p = 0;

    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {
      {
        long MYGEN109 = 0;

        for (; (MYGEN109 < ((cgn_shared)[(p / __xlen)] * 8)); (MYGEN109 = (MYGEN109 + __xlen))) {
          int ridx = (MYGEN109 + __idx);

          if (ridx < ((cgn_shared)[(p / __xlen)] * 8)) {
            ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))]))[ridx] =
                 (&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));
      {
        long MYGEN110 = 0;

        for (; (MYGEN110 < ((tln_shared)[(p / __xlen)] * 8)); (MYGEN110 = (MYGEN110 + __xlen))) {
          int ridx = (MYGEN110 + __idx);

          if (ridx < ((tln_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]))[ridx] =
                 (&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));
      {
        long MYGEN111 = 0;

        for (; (MYGEN111 < ((trn_shared)[(p / __xlen)] * 8)); (MYGEN111 = (MYGEN111 + __xlen))) {
          int ridx = (MYGEN111 + __idx);

          if (ridx < ((trn_shared)[(p / __xlen)] * 8)) {
            ((&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))]))[ridx] =
                 (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[ridx]);
          }
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      __syncthreads();
    }
  }
  {
    long MYGEN112 = (num_write_plus * 8);

    for (; (MYGEN112 > 0); (MYGEN112 = (MYGEN112 + -__xlen))) {
      int ridx = (MYGEN112 + (__idx + -__xlen));

      if (ridx >= 0) {
        ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]))[ridx] =
             (&((for_sort_grid_memory_right)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
      }
    }
  }
  int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] = ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + (cu_cache_length - num_write_plus))))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  if (__idx == 0) {
    {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * __idy)))[((inner_step * 4) + inner_g)] = (xm4)[((inner_step * 4) + inner_g)]);
            }
          }
        }
      }
    }
  }
}
__global__ void cuda_sort_one_grid_z_vlo_8(double *inoutput, int *xyzw, double *cu_cache, int *cu_xyzw,
                                           long *adjoint_vec_pids, long XLEN, long YLEN, long ZLEN, int ovlp,
                                           long numvec, long grid_cache_len, long cu_cache_length) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  long cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));

  long xyzalllen = (XLEN * (YLEN * ZLEN));

  long i = 0;

  double local_temp_particle_cache_plus[(384 * 8)];
  double local_temp_particle_cache_minus[(384 * 8)];
  __shared__ int cu_xyzw_shared[4];
  {
    long MYGEN113 = 0;

    for (; (MYGEN113 < 4); (MYGEN113 = (MYGEN113 + __xlen))) {
      int ridx = (MYGEN113 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  __syncthreads();
  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        int prev_zw[2];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }


        long bxyzz = (grid_id / (XLEN * YLEN));

        int is_most_left = (bxyzz == 0);

        int is_most_right = (bxyzz == (ZLEN - 1));

        if (is_most_left) {
          ((prev_zw)[0] = grid_cache_len);
          ((prev_zw)[1] = grid_cache_len);

        } else {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 2); (inner_g = (inner_g + 1))) {
                    ((prev_zw)[((inner_step * 2) + inner_g)] =
                         ((xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)))[((inner_step * 2) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int beg_minus = (cur_xyzw)[0];

        int end_minus = (cur_xyzw)[1];

        int minus_max = (cur_xyzw)[2];

        int beg_plus = (prev_zw)[0];

        int end_plus = (prev_zw)[1];

        int num_to_left = (end_minus - beg_minus);

        int num_from_left = (end_plus - beg_plus);

        int num_cur_remains = (minus_max - beg_minus);

        int num_left_remains = (grid_cache_len - beg_plus);


        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * num_to_left)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_minus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        if (num_from_left) {
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < (8 * num_from_left)); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                    (((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) * 8)))[((inner_step * 1) + inner_g)]);
                  }
                }
              }
            }
          }
        }

        int num_left_to_cu_cache = (((num_cur_remains < num_from_left)) ? ((num_from_left - num_cur_remains)) : (0));

        int num_cur_to_cu_cache = (((num_left_remains < num_to_left)) ? ((num_to_left - num_left_remains)) : (0));

        (num_from_left = (((num_cur_remains < num_from_left)) ? (num_cur_remains) : (num_from_left)));
        (num_to_left = (((num_left_remains < num_to_left)) ? (num_left_remains) : (num_to_left)));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (num_from_left * 8)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_plus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (num_to_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_to_left * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                     ((beg_plus * 8) - ((XLEN * YLEN) * (grid_cache_len * 8)))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_left_to_cu_cache) {
          int cur_cu_cache_load = atomicAdd(cu_xyzw_shared, num_left_to_cu_cache);

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_left_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_plus + (num_from_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (num_cur_to_cu_cache) {
          int cur_cu_cache_load = ((is_most_left) ? (atomicAdd((cu_xyzw_shared + 2), num_cur_to_cu_cache))
                                                  : (atomicAdd(cu_xyzw_shared, num_cur_to_cu_cache)));

          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (num_cur_to_cu_cache * 8)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_cache +
                     ((__idy * (cu_cache_length * 8)) + (cur_cu_cache_load * 8))))[((inner_step * 1) + inner_g)] =
                       ((local_temp_particle_cache_minus + (num_to_left * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        (beg_minus = (beg_minus + num_from_left));
        ((cur_xyzw)[0] = beg_minus);
        ((cur_xyzw)[1] = beg_minus);
        ((prev_zw)[1] = (beg_plus + num_to_left));
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                (((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 1) + inner_g)] =
                     (cur_xyzw)[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
        if (!is_most_left) {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + (grid_id - (XLEN * YLEN)))) + 2)))[((inner_step * 1) + inner_g)] =
                       (prev_zw)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }

        if (is_most_right) {
          int cur_beg_plus = (cur_xyzw)[2];

          int cur_end_plus = (cur_xyzw)[3];

          int cur_to_cu_cache = (cur_end_plus - cur_beg_plus);

          int cur_cu_cache_load = atomicAdd((cu_xyzw_shared + 3), -(cur_to_cu_cache));

          ((cur_xyzw)[2] = beg_minus);
          ((cur_xyzw)[3] = beg_minus);
          {
            {
              long inner_step;

              for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
                {
                  long inner_g;

                  for ((inner_g = 0); (inner_g < (8 * cur_to_cu_cache)); (inner_g = (inner_g + 1))) {
                    (((cu_cache +
                       ((__idy * (cu_cache_length * 8)) + ((cur_cu_cache_load - cur_to_cu_cache) *
                                                           8))))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)] =
                         (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (8 * cur_beg_plus)))[((inner_step * (8 * cur_to_cu_cache)) + inner_g)]);
                  }
                }
              }
            }
          }
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((xyzw + ((4 * (cu_offset + grid_id)) + 2)))[((inner_step * 1) + inner_g)] =
                       ((cur_xyzw + 2))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
  if (__idx == 0) {
    {
      long inner_step;

      for ((inner_step = 0); (inner_step < 4); (inner_step = (inner_step + 1))) {
        {
          long inner_g;

          for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
            (((cu_xyzw + (4 * __idy)))[((inner_step * 1) + inner_g)] = (cu_xyzw_shared)[((inner_step * 1) + inner_g)]);
          }
        }
      }
    }
  }

  if (1) {
    for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
      long grid_id = (__idx + (i * __xlen));

      if (grid_id < xyzalllen) {
        int cur_xyzw[4];
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 4); (inner_g = (inner_g + 1))) {
                  ((cur_xyzw)[((inner_step * 4) + inner_g)] =
                       ((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[((inner_step * 4) + inner_g)]);
                }
              }
            }
          }
        }
        int beg_minus = (cur_xyzw)[0];

        int beg_plus = (cur_xyzw)[2];

        int end_plus = (cur_xyzw)[3];

        int pluslen = (end_plus - beg_plus);

        int load0 = (beg_minus + pluslen);

        ((xyzw)[(4 * (cu_offset + grid_id))] = load0);
        {
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)] =
                       (((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                         (beg_plus * 8)))[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
        {
          long inner_step;

          for ((inner_step = 0); (inner_step < (8 * pluslen)); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (beg_minus * 8)))[((inner_step * 1) + inner_g)] =
                     ((local_temp_particle_cache_minus + (0 * 8)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
    }
  }

  __syncthreads();
}
__global__ void cuda_cu_swap_l_6(double *cu_cache, int *cu_xyzw, long *adjoint_vec_pids, long cu_cache_length,
                                 int the_dir_num, long XYZLEN) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  __shared__ int cu_xyzw_shared[4];
  __shared__ long adjoint_vec_pids_shared[2];
  {
    long MYGEN114 = 0;

    for (; (MYGEN114 < 2); (MYGEN114 = (MYGEN114 + __xlen))) {
      int ridx = (MYGEN114 + __idx);

      if (ridx < 2) {
        ((adjoint_vec_pids_shared)[ridx] = ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[ridx]);
      }
    }
  }
  {
    long MYGEN115 = 0;

    for (; (MYGEN115 < 4); (MYGEN115 = (MYGEN115 + __xlen))) {
      int ridx = (MYGEN115 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  long left_pid = (adjoint_vec_pids_shared)[0];

  int beg_left_par = (cu_xyzw_shared)[1];

  int end_left_par = (cu_xyzw_shared)[2];

  if (1 && ((left_pid != -1) && (beg_left_par != end_left_par))) {
    int end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];

    int new_left_par = (end_cu_par + (end_left_par - beg_left_par));

    if (__idx == 0) {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * left_pid)))[((inner_step * 1) + inner_g)] =
                   (&(new_left_par))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }

    if (1) {
      {
        __shared__ int al1[2];
        if (__idx == 0) {
          ((al1)[0] = (cu_xyzw_shared)[3]);
          ((al1)[1] = (cu_xyzw_shared)[3]);
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_xyzw + ((4 * __idy) + 1)))[((inner_step * 1) + inner_g)] = (al1)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }

    __syncthreads();
    int i;

    if (0) {
      {
        long i;

        for ((i = beg_left_par); (i < end_left_par); (i = (i + 1))) {
          int real_id = i;

          double par_cache[6];
          { { long inner_step;

          for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((par_cache)[((inner_step * 1) + inner_g)] =
                     (((cu_cache + (__idy * (6 * cu_cache_length))) + (6 * real_id)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
      ((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((cu_cache + (left_pid * (6 * cu_cache_length))) + (6 * end_cu_par)))[((inner_step * 1) + inner_g)] =
                   (par_cache)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      (end_cu_par = (end_cu_par + 1));
    }
  }
}

if (1) {
  for ((i = beg_left_par); ((i + __idx) < end_left_par); (i = (i + __xlen))) {
    int real_id = (i + __idx);

    double par_cache[6];
    { { long inner_step;

    for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
      {
        long inner_g;

        for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
          ((par_cache)[((inner_step * 1) + inner_g)] =
               (((cu_cache + (__idy * (6 * cu_cache_length))) + (6 * real_id)))[((inner_step * 1) + inner_g)]);
        }
      }
    }
  }
}
((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
{
  long inner_step;

  for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
    {
      long inner_g;

      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
        ((((cu_cache + (left_pid * (6 * cu_cache_length))) +
           (6 * (end_cu_par + __idx))))[((inner_step * 1) + inner_g)] = (par_cache)[((inner_step * 1) + inner_g)]);
      }
    }
  }
}
(end_cu_par = (end_cu_par + __xlen));
}
}

__syncthreads();
}
}
__global__ void cuda_cu_swap_r_6(double *cu_cache, int *cu_xyzw, long *adjoint_vec_pids, long cu_cache_length,
                                 int the_dir_num, long XYZLEN) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  __shared__ int cu_xyzw_shared[4];
  __shared__ long adjoint_vec_pids_shared[2];
  {
    long MYGEN116 = 0;

    for (; (MYGEN116 < 2); (MYGEN116 = (MYGEN116 + __xlen))) {
      int ridx = (MYGEN116 + __idx);

      if (ridx < 2) {
        ((adjoint_vec_pids_shared)[ridx] = ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[ridx]);
      }
    }
  }
  {
    long MYGEN117 = 0;

    for (; (MYGEN117 < 4); (MYGEN117 = (MYGEN117 + __xlen))) {
      int ridx = (MYGEN117 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  long left_pid = (adjoint_vec_pids_shared)[1];

  int beg_left_par = (cu_xyzw_shared)[3];

  int end_left_par = cu_cache_length;

  if (1 && ((left_pid != -1) && (beg_left_par != end_left_par))) {
    int end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];

    int new_left_par = (end_cu_par + (end_left_par - beg_left_par));

    if (__idx == 0) {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * left_pid)))[((inner_step * 1) + inner_g)] =
                   (&(new_left_par))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }

    if (1) {
      {
        __shared__ int al1[2];
        if (__idx == 0) {
          ((al1)[0] = cu_cache_length);
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_xyzw + ((4 * __idy) + 3)))[((inner_step * 1) + inner_g)] = (al1)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }

    __syncthreads();
    int i;

    if (0) {
      {
        long i;

        for ((i = beg_left_par); (i < end_left_par); (i = (i + 1))) {
          int real_id = i;

          double par_cache[6];
          { { long inner_step;

          for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((par_cache)[((inner_step * 1) + inner_g)] =
                     (((cu_cache + (__idy * (6 * cu_cache_length))) + (6 * real_id)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
      ((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((cu_cache + (left_pid * (6 * cu_cache_length))) + (6 * end_cu_par)))[((inner_step * 1) + inner_g)] =
                   (par_cache)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      (end_cu_par = (end_cu_par + 1));
    }
  }
}

if (1) {
  for ((i = beg_left_par); ((i + __idx) < end_left_par); (i = (i + __xlen))) {
    int real_id = (i + __idx);

    double par_cache[6];
    { { long inner_step;

    for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
      {
        long inner_g;

        for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
          ((par_cache)[((inner_step * 1) + inner_g)] =
               (((cu_cache + (__idy * (6 * cu_cache_length))) + (6 * real_id)))[((inner_step * 1) + inner_g)]);
        }
      }
    }
  }
}
((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
{
  long inner_step;

  for ((inner_step = 0); (inner_step < 6); (inner_step = (inner_step + 1))) {
    {
      long inner_g;

      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
        ((((cu_cache + (left_pid * (6 * cu_cache_length))) +
           (6 * (end_cu_par + __idx))))[((inner_step * 1) + inner_g)] = (par_cache)[((inner_step * 1) + inner_g)]);
      }
    }
  }
}
(end_cu_par = (end_cu_par + __xlen));
}
}

__syncthreads();
}
}
__global__ void cuda_cu_swap_l_8(double *cu_cache, int *cu_xyzw, long *adjoint_vec_pids, long cu_cache_length,
                                 int the_dir_num, long XYZLEN) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  __shared__ int cu_xyzw_shared[4];
  __shared__ long adjoint_vec_pids_shared[2];
  {
    long MYGEN118 = 0;

    for (; (MYGEN118 < 2); (MYGEN118 = (MYGEN118 + __xlen))) {
      int ridx = (MYGEN118 + __idx);

      if (ridx < 2) {
        ((adjoint_vec_pids_shared)[ridx] = ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[ridx]);
      }
    }
  }
  {
    long MYGEN119 = 0;

    for (; (MYGEN119 < 4); (MYGEN119 = (MYGEN119 + __xlen))) {
      int ridx = (MYGEN119 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  long left_pid = (adjoint_vec_pids_shared)[0];

  int beg_left_par = (cu_xyzw_shared)[1];

  int end_left_par = (cu_xyzw_shared)[2];

  if (1 && ((left_pid != -1) && (beg_left_par != end_left_par))) {
    int end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];

    int new_left_par = (end_cu_par + (end_left_par - beg_left_par));

    if (__idx == 0) {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * left_pid)))[((inner_step * 1) + inner_g)] =
                   (&(new_left_par))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }

    if (1) {
      {
        __shared__ int al1[2];
        if (__idx == 0) {
          ((al1)[0] = (cu_xyzw_shared)[3]);
          ((al1)[1] = (cu_xyzw_shared)[3]);
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 2); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_xyzw + ((4 * __idy) + 1)))[((inner_step * 1) + inner_g)] = (al1)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }

    __syncthreads();
    int i;

    if (0) {
      {
        long i;

        for ((i = beg_left_par); (i < end_left_par); (i = (i + 1))) {
          int real_id = i;

          double par_cache[8];
          { { long inner_step;

          for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((par_cache)[((inner_step * 1) + inner_g)] =
                     (((cu_cache + (__idy * (8 * cu_cache_length))) + (8 * real_id)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
      ((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((cu_cache + (left_pid * (8 * cu_cache_length))) + (8 * end_cu_par)))[((inner_step * 1) + inner_g)] =
                   (par_cache)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      (end_cu_par = (end_cu_par + 1));
    }
  }
}

if (1) {
  for ((i = beg_left_par); ((i + __idx) < end_left_par); (i = (i + __xlen))) {
    int real_id = (i + __idx);

    double par_cache[8];
    { { long inner_step;

    for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
      {
        long inner_g;

        for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
          ((par_cache)[((inner_step * 1) + inner_g)] =
               (((cu_cache + (__idy * (8 * cu_cache_length))) + (8 * real_id)))[((inner_step * 1) + inner_g)]);
        }
      }
    }
  }
}
((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
{
  long inner_step;

  for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
    {
      long inner_g;

      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
        ((((cu_cache + (left_pid * (8 * cu_cache_length))) +
           (8 * (end_cu_par + __idx))))[((inner_step * 1) + inner_g)] = (par_cache)[((inner_step * 1) + inner_g)]);
      }
    }
  }
}
(end_cu_par = (end_cu_par + __xlen));
}
}

__syncthreads();
}
}
__global__ void cuda_cu_swap_r_8(double *cu_cache, int *cu_xyzw, long *adjoint_vec_pids, long cu_cache_length,
                                 int the_dir_num, long XYZLEN) {


  const long __idx = (threadIdx.x + (threadIdx.y * blockDim.x));

  const long __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  const long __xlen = (blockDim.x * blockDim.y);


  __shared__ int cu_xyzw_shared[4];
  __shared__ long adjoint_vec_pids_shared[2];
  {
    long MYGEN120 = 0;

    for (; (MYGEN120 < 2); (MYGEN120 = (MYGEN120 + __xlen))) {
      int ridx = (MYGEN120 + __idx);

      if (ridx < 2) {
        ((adjoint_vec_pids_shared)[ridx] = ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[ridx]);
      }
    }
  }
  {
    long MYGEN121 = 0;

    for (; (MYGEN121 < 4); (MYGEN121 = (MYGEN121 + __xlen))) {
      int ridx = (MYGEN121 + __idx);

      if (ridx < 4) {
        ((cu_xyzw_shared)[ridx] = ((cu_xyzw + (4 * __idy)))[ridx]);
      }
    }
  }
  __syncthreads();
  long left_pid = (adjoint_vec_pids_shared)[1];

  int beg_left_par = (cu_xyzw_shared)[3];

  int end_left_par = cu_cache_length;

  if (1 && ((left_pid != -1) && (beg_left_par != end_left_par))) {
    int end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];

    int new_left_par = (end_cu_par + (end_left_par - beg_left_par));

    if (__idx == 0) {
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              (((cu_xyzw + (4 * left_pid)))[((inner_step * 1) + inner_g)] =
                   (&(new_left_par))[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
    }

    if (1) {
      {
        __shared__ int al1[2];
        if (__idx == 0) {
          ((al1)[0] = cu_cache_length);
          {
            long inner_step;

            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1))) {
              {
                long inner_g;

                for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                  (((cu_xyzw + ((4 * __idy) + 3)))[((inner_step * 1) + inner_g)] = (al1)[((inner_step * 1) + inner_g)]);
                }
              }
            }
          }
        }
      }
    }

    __syncthreads();
    int i;

    if (0) {
      {
        long i;

        for ((i = beg_left_par); (i < end_left_par); (i = (i + 1))) {
          int real_id = i;

          double par_cache[8];
          { { long inner_step;

          for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
            {
              long inner_g;

              for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
                ((par_cache)[((inner_step * 1) + inner_g)] =
                     (((cu_cache + (__idy * (8 * cu_cache_length))) + (8 * real_id)))[((inner_step * 1) + inner_g)]);
              }
            }
          }
        }
      }
      ((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
      {
        long inner_step;

        for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
          {
            long inner_g;

            for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
              ((((cu_cache + (left_pid * (8 * cu_cache_length))) + (8 * end_cu_par)))[((inner_step * 1) + inner_g)] =
                   (par_cache)[((inner_step * 1) + inner_g)]);
            }
          }
        }
      }
      (end_cu_par = (end_cu_par + 1));
    }
  }
}

if (1) {
  for ((i = beg_left_par); ((i + __idx) < end_left_par); (i = (i + __xlen))) {
    int real_id = (i + __idx);

    double par_cache[8];
    { { long inner_step;

    for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
      {
        long inner_g;

        for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
          ((par_cache)[((inner_step * 1) + inner_g)] =
               (((cu_cache + (__idy * (8 * cu_cache_length))) + (8 * real_id)))[((inner_step * 1) + inner_g)]);
        }
      }
    }
  }
}
((par_cache)[the_dir_num] = ((par_cache)[the_dir_num] + XYZLEN));
{
  long inner_step;

  for ((inner_step = 0); (inner_step < 8); (inner_step = (inner_step + 1))) {
    {
      long inner_g;

      for ((inner_g = 0); (inner_g < 1); (inner_g = (inner_g + 1))) {
        ((((cu_cache + (left_pid * (8 * cu_cache_length))) +
           (8 * (end_cu_par + __idx))))[((inner_step * 1) + inner_g)] = (par_cache)[((inner_step * 1) + inner_g)]);
      }
    }
  }
}
(end_cu_par = (end_cu_par + __xlen));
}
}

__syncthreads();
}
}

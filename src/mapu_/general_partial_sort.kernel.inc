#define IDX_OPT_MAX 1
#ifndef _MAPU_SIMD_BASE_FUN
#define _MAPU_SIMD_BASE_FUN
static __device__ KERNEL_M KERNEL_S double mapu_log_df(double p) {
  long long s = p;
  if (s < p) {
    return s;
  } else {
    return s + 1;
  }
}
static __device__ KERNEL_M KERNEL_S double mapu_floor_df(double p) {
  long long s = (long long)p;
  return (s > p) ? (double)(s - 1) : (double)s;
}
__device__ static KERNEL_M v8fp64 v8fp64_setr(double a0, double a1, double a2,
                                              double a3, double a4, double a5,
                                              double a6, double a7) {

  v8fp64 ret = {a0, a1, a2, a3, a4, a5, a6, a7};
  return ret;
}
#define floor mapu_floor_df
#define log mapu_log_df
__device__ static KERNEL_M v8fp64 geo_floor_simd(v8fp64 input) {
  v8fp64 ret;
  double *pret = (double *)&(ret);
  double *pinput = (double *)&(input);
  int g;
  for ((g = 0); (g < 8); (g = (g + 1))) {
    ((pret)[g] = floor((pinput)[g]));
  }
  return ret;
}
#endif
#define IDX_OPT_MAX 1

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_x_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));
  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = i;
    __mem1__ MAPU_LONG bxyzx;
    bxyzx = (grid_id % XLEN);
    __mem1__ MAPU_LONG bxyzy;
    bxyzy = ((grid_id / XLEN) % YLEN);
    __mem1__ MAPU_LONG bxyzz;
    bxyzz = (grid_id / (XLEN * YLEN));
    __mem1__ int cur_load0;
    cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];
    __mem1__ int cur_load;
    cur_load = cur_load0;
    __mem1__ int g;
    g = 0;
    __mem1__ int lg;
    lg = 0;
    __mem1__ MAPU_LONG plus_offset;
    plus_offset = 0;
    __mem1__ MAPU_LONG minus_offset;
    minus_offset = 0;
    __mem1__ MAPU_LONG left_bound;
    left_bound = bxyzx;
    __mem1__ MAPU_LONG right_bound;
    right_bound = (bxyzx + 1);
    __mem1__ int sizeof_double;
    sizeof_double = sizeof(double);
    __mem1__ MAPU_LONG num_write_minus;
    num_write_minus = 0;
    __mem1__ MAPU_LONG num_write_plus;
    num_write_plus = 0;
    __mem1__ MAPU_LONG num_write_main;
    num_write_main = 0;
    __mem1__ MAPU_LONG num_write_tmp;
    num_write_tmp = 0;
    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      __mem1__ int cur_grid_num;
      cur_grid_num = 0;
      __mem1__ int to_left_num;
      to_left_num = 0;
      __mem1__ int to_right_num;
      to_right_num = 0;
      __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
      __mem0__ int tln_shared[IDX_LOCAL_XLEN];
      __mem0__ int trn_shared[IDX_LOCAL_XLEN];
      {
        __mem1__ MAPU_LONG p;
        for ((p = (lg + (__idx * __xlen)));
             (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          __mem1__ int real_p;
          real_p = p;
          __mem1__ int local_p_id;
          local_p_id = (p - (lg + (__idx * __xlen)));
          __mem1__ int if_exist_particle;
          if_exist_particle = (real_p < cur_load);
          __mem1__ double particle_sort_key_element;
          particle_sort_key_element = ((if_exist_particle) ? (({
            ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                          6)))[(0 + (real_p * 6))];
          }))
                                                           : (({ -1; })));
          __mem1__ int is_to_left;
          is_to_left = (particle_sort_key_element < left_bound);
          __mem1__ int is_to_right;
          is_to_right = (particle_sort_key_element > right_bound);
          __mem1__ int is_cur;
          is_cur = ((!is_to_right) && (!is_to_left));
          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            __mem1__ MAPU_LONG i;
            for ((i = 0); (i < 6); (i = (i + 1))) {

              if (is_to_left) {
                {
                  ((for_sort_grid_memory_left)[(
                       i +
                       (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_to_right) {
                {
                  ((for_sort_grid_memory_right)[(
                       i +
                       (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_cur) {
                {
                  (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                 6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                 (cur_grid_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }
            }
          }
          if (is_cur) {
            {
              (cur_grid_num = (cur_grid_num + 1));
            }
          }

          if (is_to_left) {
            {
              (to_left_num = (to_left_num + 1));
            }
          }

          if (is_to_right) {
            {
              (to_right_num = (to_right_num + 1));
            }
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __mem1__ MAPU_LONG p;
      p = 0;
      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

        if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&(
                ((inoutput +
                  (((cu_offset + grid_id) * grid_cache_len) *
                   6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                        0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
                ((__DDR unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

        if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
                0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((tln_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

        if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
                0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((trn_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      }
    }
    __mem1__ int is_most_left;
    is_most_left = (bxyzx == 0);
    __mem1__ int is_most_right;
    is_most_right = (bxyzx == (XLEN - 1));
    __mem1__ int beg_left_main;
    beg_left_main = grid_cache_len;
    __mem1__ int beg_plus;
    beg_plus = 0;
    __mem1__ int end_plus;
    end_plus = 0;

    if ((!is_most_left)) {
      {
        (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - 1))]);
        (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 2)]);
        (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 3)]);
      }
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = (end_plus - beg_plus);

      if ((num_copy_real_11516lap > (grid_cache_len - num_write_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - num_write_main));

          if (((6 *
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))) *
               1)) {
            {
              const size_t data_size = sizeof((
                  (&(((inoutput +
                       (((cu_offset + grid_id) * grid_cache_len) *
                        6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                        (beg_plus - (1 * grid_cache_len)))))]) +
                   (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&(((inoutput +
                               (((cu_offset + grid_id) * grid_cache_len) *
                                6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                                (beg_plus -
                                                 (1 * grid_cache_len)))))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 * ((6 * ((end_plus - beg_plus) -
                                         (grid_cache_len - num_write_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof(
              (&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) *
                    6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                    (beg_plus - (1 * grid_cache_len)))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (num_write_main * 6))),
              ((__DDR unsigned *)&(
                  ((inoutput +
                    (((cu_offset + grid_id) * grid_cache_len) *
                     6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                     (beg_plus - (1 * grid_cache_len)))))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_minus;

      if ((num_copy_real_11516lap > (grid_cache_len - beg_left_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - beg_left_main));

          if (((6 * (num_write_minus - (grid_cache_len - beg_left_main))) *
               1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_left)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_left)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 * ((6 * (num_write_minus -
                                         (grid_cache_len - beg_left_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                (num_write_minus - (grid_cache_len - beg_left_main))));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)(&(((inoutput +
                                (((cu_offset + grid_id) * grid_cache_len) *
                                 6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                                 -((1 * grid_cache_len)))))]) +
                            (beg_left_main * 6))),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if (((!is_most_left) && (__idx == 0))) {
      {
        ((xyzw)[(4 * ((cu_offset + grid_id) - 1))] = beg_left_main);
      }
    }
    __mem1__ int cap_tmp;
    cap_tmp = ((is_most_right) ? (({ 0; }))
                               : (({ (grid_cache_len - num_write_main); })));
    __mem1__ int total_cache_num;
    total_cache_num = num_write_main;
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_plus;

      if ((num_copy_real_11516lap > cap_tmp)) {
        {
          (num_copy_real_11516lap = cap_tmp);

          if (((6 * (num_write_plus - cap_tmp)) * 1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_right)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_right)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 *
                              ((6 * (num_write_plus - cap_tmp)) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load + (num_write_plus - cap_tmp)));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (total_cache_num * 6))),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    __mem0__ int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);

    if ((__idx == 0)) {
      {

        if (((4 * 1) > 0)) {
          {
            __mem0__ double __tmp_array[4096];
            __mem1__ MAPU_LONG __pscmc_cpnum;
            __pscmc_cpnum = 0;
            __mem1__ MAPU_LONG __pscmc_one_copy;
            __pscmc_one_copy = (4096 / 4);
            for (0; (__pscmc_cpnum < 1);
                 (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
              __mem1__ MAPU_LONG cp_size;
              cp_size = __pscmc_one_copy;

              if (((cp_size + __pscmc_cpnum) > 1)) {
                {
                  (cp_size = (1 - __pscmc_cpnum));
                }
              }

              if ((cp_size * 4)) {
                {
                  const size_t data_size =
                      sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                  memcpy_async(__pscmc_mapu_internal_block__,
                               ((unsigned *)__tmp_array),
                               ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                               ((uint64_t)(4 * (cp_size * data_size))),
                               __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

              if ((cp_size * (4 * 1))) {
                {
                  const size_t data_size = sizeof((__tmp_array)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((xyzw + (4 * (cu_offset + grid_id))) +
                                          (__pscmc_cpnum * 4))),
                      ((unsigned *)__tmp_array),
                      ((uint64_t)((4 * 1) * (cp_size * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }
            }
          }
        }
      }
    }
  }
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = XLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(0 + (real_p * 6))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 6); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN18;
    MYGEN18 = (num_write_plus * 6);
    for (0; (MYGEN18 > 0); (MYGEN18 = (MYGEN18 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN18 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (6 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
        6));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_x_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 6)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 6)];
  __mem0__ double local_pos_cache[(64 * 6)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ double rat;
  rat = ((1.00000000000000000e+00 * cu_cur_cache_load) / cu_cache_length);

  if ((__idx == 0)) {
    {
      __mem1__ int num_cur_load;
      num_cur_load = 0;
      __mem1__ int beg_to_left;
      beg_to_left = ((2 * cu_cache_length) / 5);
      __mem1__ int cur_to_left;
      cur_to_left = beg_to_left;
      __mem1__ int cur_to_right;
      cur_to_right = cu_cache_length;
      __mem1__ int cur_this;
      cur_this = 0;
      __mem1__ int lg;
      __mem1__ int g;
      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        __mem1__ MAPU_LONG num_read;
        num_read = ((((lg + 64) > cu_cur_cache_load))
                        ? (({ (cu_cur_cache_load - lg); }))
                        : (({ 64; })));

        if (((num_read * 6) * 1)) {
          {
            const size_t data_size = sizeof(
                (((cu_cache + (__idy * (6 * cu_cache_length))) + (lg * 6)))[0]);
            memcpy_async(__pscmc_mapu_internal_block__,
                         ((unsigned *)(local_pos_cache + (0 * 6))),
                         ((__DDR unsigned *)((cu_cache +
                                              (__idy * (6 * cu_cache_length))) +
                                             (lg * 6))),
                         ((uint64_t)(1 * ((num_read * 6) * data_size))),
                         __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        for (g = 0; (g < num_read); g++) {
          __mem1__ int gall;
          gall = (g + lg);

          if ((((local_pos_cache + (g * 6)))[0] < 0)) {

            if ((6 * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_pos_cache + (g * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (6 * cu_cache_length))) +
                                        (cur_to_left * 6))),
                    ((unsigned *)(local_pos_cache + (g * 6))),
                    ((uint64_t)(1 * (6 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {

            if ((((local_pos_cache + (g * 6)))[0] > XLEN)) {
              cur_to_right--;

              if ((6 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (6 * cu_cache_length))) +
                                          (cur_to_right * 6))),
                      ((unsigned *)(local_pos_cache + (g * 6))),
                      ((uint64_t)(1 * (6 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

            } else {

              if ((6 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (6 * cu_cache_length))) +
                                          (cur_this * 6))),
                      ((unsigned *)(local_pos_cache + (g * 6))),
                      ((uint64_t)(1 * (6 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
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
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = (__idx + (i * __xlen));

    if ((grid_id < xyzalllen)) {
      {
        __mem1__ int cur_load;
        cur_load = (xyzw)[(4 * (cu_offset + grid_id))];
        __mem1__ double rat;
        rat = ((1.00000000000000000e+00 * cur_load) / grid_cache_len);
        __mem1__ MAPU_LONG bxyzx;
        bxyzx = (grid_id % XLEN);
        __mem1__ MAPU_LONG bxyzy;
        bxyzy = ((grid_id / XLEN) % YLEN);
        __mem1__ MAPU_LONG bxyzz;
        bxyzz = (grid_id / (XLEN * YLEN));
        __mem1__ int g;
        g = 0;
        __mem1__ int lg;
        lg = 0;
        __mem1__ MAPU_LONG plus_offset;
        plus_offset = 0;
        __mem1__ MAPU_LONG minus_offset;
        minus_offset = 0;
        __mem1__ MAPU_LONG left_bound;
        left_bound = bxyzx;
        __mem1__ MAPU_LONG right_bound;
        right_bound = (left_bound + 1);
        __mem1__ int sizeof_double;
        sizeof_double = sizeof(double);
        __mem1__ MAPU_LONG num_write_minus;
        num_write_minus = 0;
        __mem1__ MAPU_LONG num_write_plus;
        num_write_plus = 0;
        __mem1__ MAPU_LONG num_write_main;
        num_write_main = 0;
        __mem1__ MAPU_LONG num_write_tmp;
        num_write_tmp = 0;
        for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
          __mem1__ MAPU_LONG num_read;
          num_read = ((((lg + 64) > cur_load)) ? (({ (cur_load - lg); }))
                                               : (({ 64; })));

          if (((num_read * 6) * 1)) {
            {
              const size_t data_size = sizeof((
                  ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (lg * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(local_pos_cache + (0 * 6))),
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   6)) +
                                      (lg * 6))),
                  ((uint64_t)(1 * ((num_read * 6) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          {
            {
              __mem1__ MAPU_LONG inner_step;
              for ((inner_step = 0); (inner_step < num_read);
                   (inner_step = (inner_step + 1))) {
                {
                  __mem1__ MAPU_LONG inner_g;
                  for ((inner_g = 0); (inner_g < 3);
                       (inner_g = (inner_g + 1))) {
                    ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                         (((inoutput +
                            (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (3 + (lg * 6))))[((inner_step * 6) + inner_g)]);
                  }
                }
              }
            }
          }
          for (g = 0; (g < num_read); g++) {

            if ((((local_pos_cache + (g * 6)))[0] < left_bound)) {

              if (((num_write_tmp * 6) * 1)) {
                {
                  const size_t data_size = sizeof(
                      ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                        grid_cache_len) *
                                                       6)) +
                                          (num_write_main * 6))),
                      ((unsigned *)(local_pos_cache +
                                    ((g - num_write_tmp) * 6))),
                      ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                      put_sync_id);
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                __mem1__ MAPU_LONG i;
                for ((i = 0); (i < 6); (i = (i + 1))) {
                  (((local_temp_particle_cache_minus +
                     (num_write_minus * 6)))[i] =
                       ((local_pos_cache + (g * 6)))[i]);
                }
              }
              num_write_minus++;

            } else {

              if ((((local_pos_cache + (g * 6)))[0] > right_bound)) {

                if (((num_write_tmp * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            (num_write_main * 6))),
                        ((unsigned *)(local_pos_cache +
                                      ((g - num_write_tmp) * 6))),
                        ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                        put_sync_id);
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);
                {
                  __mem1__ MAPU_LONG i;
                  for ((i = 0); (i < 6); (i = (i + 1))) {
                    (((local_temp_particle_cache_plus +
                       (num_write_plus * 6)))[i] =
                         ((local_pos_cache + (g * 6)))[i]);
                  }
                }
                num_write_plus++;

              } else {

                if (((((local_vel_cache)[((g * 3) + 0)] *
                       (local_vel_cache)[((g * 3) + 0)]) +
                      (((local_vel_cache)[((g * 3) + 1)] *
                        (local_vel_cache)[((g * 3) + 1)]) +
                       ((local_vel_cache)[((g * 3) + 2)] *
                        (local_vel_cache)[((g * 3) + 2)]))) >
                     1.00000000000000000e+00)) {

                  if (((num_write_tmp * 6) * 1)) {
                    {
                      const size_t data_size = sizeof(
                          ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                      memcpy_async(
                          __pscmc_mapu_internal_block__,
                          ((__DDR unsigned *)((inoutput +
                                               (((cu_offset + grid_id) *
                                                 grid_cache_len) *
                                                6)) +
                                              (num_write_main * 6))),
                          ((unsigned *)(local_pos_cache +
                                        ((g - num_write_tmp) * 6))),
                          ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                          put_sync_id);
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
          if (((num_write_tmp * 6) * 1)) {
            {
              const size_t data_size =
                  sizeof(((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   6)) +
                                      (num_write_main * 6))),
                  ((unsigned *)(local_pos_cache + ((g - num_write_tmp) * 6))),
                  ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                  put_sync_id);
            }
          }
          (num_write_main = (num_write_main + num_write_tmp));
          (num_write_tmp = 0);
          (put_sync_id).arrive_and_wait();
          (get_sync_id).arrive_and_wait();
        }
        __mem1__ int x_main;
        x_main = num_write_main;
        __mem1__ int x_beg_minus;
        x_beg_minus = x_main;
        __mem1__ int x_beg_plus;
        x_beg_plus =
            (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));
        __mem0__ int xm4[4];
        ((xm4)[0] = x_main);
        ((xm4)[1] = (num_write_minus + x_main));
        ((xm4)[2] = x_beg_plus);
        ((xm4)[3] = (num_write_plus + x_beg_plus));

        if ((4 * 1)) {
          {
            const size_t data_size = sizeof((xm4)[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)(xyzw + (4 * (cu_offset + grid_id)))),
                ((unsigned *)xm4), ((uint64_t)(1 * (4 * data_size))),
                put_sync_id);
          }
        }

        if (((6 * num_write_minus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      6)) +
                                    (x_beg_minus * 6))),
                ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                ((uint64_t)(1 * ((6 * num_write_minus) * data_size))),
                put_sync_id);
          }
        }

        if (((xm4)[3] > grid_cache_len)) {
          {
            __mem1__ MAPU_LONG i;
            i = 0;
            for (i = 0; (i < 4); i++) {
            }
          }
        }

        if (((6 * num_write_plus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      6)) +
                                    (x_beg_plus * 6))),
                ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                ((uint64_t)(1 * ((6 * num_write_plus) * data_size))),
                put_sync_id);
          }
        }
        (put_sync_id).arrive_and_wait();
      }
    }
  }
  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzx == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzx == (XLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(
                        ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) - 1)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((6 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_minus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((uint64_t)(1 * ((6 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((6 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                          ((beg_plus - (1 * grid_cache_len)) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 6))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 ((beg_plus - (1 * grid_cache_len)) * 6))),
                        ((uint64_t)(1 * ((6 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 6) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                    ((uint64_t)(1 * ((num_from_left * 6) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            ((beg_plus * 6) -
                                             (1 * (grid_cache_len * 6))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 6))),
                        ((uint64_t)(1 * ((num_to_left * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + (grid_id - 1))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((6 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (6 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (6 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 (6 * cur_beg_plus)) +
                                (__pscmc_cpnum * (6 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                                   (6 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((uint64_t)((6 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((6 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 6)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     6))) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((6 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_plus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_plus * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_y_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));
  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = i;
    __mem1__ MAPU_LONG bxyzx;
    bxyzx = (grid_id % XLEN);
    __mem1__ MAPU_LONG bxyzy;
    bxyzy = ((grid_id / XLEN) % YLEN);
    __mem1__ MAPU_LONG bxyzz;
    bxyzz = (grid_id / (XLEN * YLEN));
    __mem1__ int cur_load0;
    cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];
    __mem1__ int cur_load;
    cur_load = cur_load0;
    __mem1__ int g;
    g = 0;
    __mem1__ int lg;
    lg = 0;
    __mem1__ MAPU_LONG plus_offset;
    plus_offset = 0;
    __mem1__ MAPU_LONG minus_offset;
    minus_offset = 0;
    __mem1__ MAPU_LONG left_bound;
    left_bound = bxyzy;
    __mem1__ MAPU_LONG right_bound;
    right_bound = (bxyzy + 1);
    __mem1__ int sizeof_double;
    sizeof_double = sizeof(double);
    __mem1__ MAPU_LONG num_write_minus;
    num_write_minus = 0;
    __mem1__ MAPU_LONG num_write_plus;
    num_write_plus = 0;
    __mem1__ MAPU_LONG num_write_main;
    num_write_main = 0;
    __mem1__ MAPU_LONG num_write_tmp;
    num_write_tmp = 0;
    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      __mem1__ int cur_grid_num;
      cur_grid_num = 0;
      __mem1__ int to_left_num;
      to_left_num = 0;
      __mem1__ int to_right_num;
      to_right_num = 0;
      __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
      __mem0__ int tln_shared[IDX_LOCAL_XLEN];
      __mem0__ int trn_shared[IDX_LOCAL_XLEN];
      {
        __mem1__ MAPU_LONG p;
        for ((p = (lg + (__idx * __xlen)));
             (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          __mem1__ int real_p;
          real_p = p;
          __mem1__ int local_p_id;
          local_p_id = (p - (lg + (__idx * __xlen)));
          __mem1__ int if_exist_particle;
          if_exist_particle = (real_p < cur_load);
          __mem1__ double particle_sort_key_element;
          particle_sort_key_element = ((if_exist_particle) ? (({
            ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                          6)))[(1 + (real_p * 6))];
          }))
                                                           : (({ -1; })));
          __mem1__ int is_to_left;
          is_to_left = (particle_sort_key_element < left_bound);
          __mem1__ int is_to_right;
          is_to_right = (particle_sort_key_element > right_bound);
          __mem1__ int is_cur;
          is_cur = ((!is_to_right) && (!is_to_left));
          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            __mem1__ MAPU_LONG i;
            for ((i = 0); (i < 6); (i = (i + 1))) {

              if (is_to_left) {
                {
                  ((for_sort_grid_memory_left)[(
                       i +
                       (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_to_right) {
                {
                  ((for_sort_grid_memory_right)[(
                       i +
                       (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_cur) {
                {
                  (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                 6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                 (cur_grid_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }
            }
          }
          if (is_cur) {
            {
              (cur_grid_num = (cur_grid_num + 1));
            }
          }

          if (is_to_left) {
            {
              (to_left_num = (to_left_num + 1));
            }
          }

          if (is_to_right) {
            {
              (to_right_num = (to_right_num + 1));
            }
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __mem1__ MAPU_LONG p;
      p = 0;
      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

        if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&(
                ((inoutput +
                  (((cu_offset + grid_id) * grid_cache_len) *
                   6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                        0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
                ((__DDR unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

        if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
                0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((tln_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

        if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
                0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((trn_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      }
    }
    __mem1__ int is_most_left;
    is_most_left = (bxyzy == 0);
    __mem1__ int is_most_right;
    is_most_right = (bxyzy == (YLEN - 1));
    __mem1__ int beg_left_main;
    beg_left_main = grid_cache_len;
    __mem1__ int beg_plus;
    beg_plus = 0;
    __mem1__ int end_plus;
    end_plus = 0;

    if ((!is_most_left)) {
      {
        (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - XLEN))]);
        (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 2)]);
        (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 3)]);
      }
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = (end_plus - beg_plus);

      if ((num_copy_real_11516lap > (grid_cache_len - num_write_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - num_write_main));

          if (((6 *
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))) *
               1)) {
            {
              const size_t data_size = sizeof(
                  ((&(((inoutput +
                        (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                        0 + (6 * ((__idx * (__xlen * 0)) +
                                  (beg_plus - (XLEN * grid_cache_len)))))]) +
                    (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&(((inoutput +
                               (((cu_offset + grid_id) * grid_cache_len) *
                                6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                                (beg_plus -
                                                 (XLEN * grid_cache_len)))))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 * ((6 * ((end_plus - beg_plus) -
                                         (grid_cache_len - num_write_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof(
              (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                  0 + (6 * ((__idx * (__xlen * 0)) +
                            (beg_plus - (XLEN * grid_cache_len)))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (num_write_main * 6))),
              ((__DDR unsigned *)&(
                  ((inoutput +
                    (((cu_offset + grid_id) * grid_cache_len) *
                     6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                     (beg_plus - (XLEN * grid_cache_len)))))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_minus;

      if ((num_copy_real_11516lap > (grid_cache_len - beg_left_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - beg_left_main));

          if (((6 * (num_write_minus - (grid_cache_len - beg_left_main))) *
               1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_left)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_left)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 * ((6 * (num_write_minus -
                                         (grid_cache_len - beg_left_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                (num_write_minus - (grid_cache_len - beg_left_main))));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                            -((XLEN * grid_cache_len)))))]) +
                       (beg_left_main * 6))),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if (((!is_most_left) && (__idx == 0))) {
      {
        ((xyzw)[(4 * ((cu_offset + grid_id) - XLEN))] = beg_left_main);
      }
    }
    __mem1__ int cap_tmp;
    cap_tmp = ((is_most_right) ? (({ 0; }))
                               : (({ (grid_cache_len - num_write_main); })));
    __mem1__ int total_cache_num;
    total_cache_num = num_write_main;
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_plus;

      if ((num_copy_real_11516lap > cap_tmp)) {
        {
          (num_copy_real_11516lap = cap_tmp);

          if (((6 * (num_write_plus - cap_tmp)) * 1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_right)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_right)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 *
                              ((6 * (num_write_plus - cap_tmp)) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load + (num_write_plus - cap_tmp)));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (total_cache_num * 6))),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    __mem0__ int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);

    if ((__idx == 0)) {
      {

        if (((4 * 1) > 0)) {
          {
            __mem0__ double __tmp_array[4096];
            __mem1__ MAPU_LONG __pscmc_cpnum;
            __pscmc_cpnum = 0;
            __mem1__ MAPU_LONG __pscmc_one_copy;
            __pscmc_one_copy = (4096 / 4);
            for (0; (__pscmc_cpnum < 1);
                 (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
              __mem1__ MAPU_LONG cp_size;
              cp_size = __pscmc_one_copy;

              if (((cp_size + __pscmc_cpnum) > 1)) {
                {
                  (cp_size = (1 - __pscmc_cpnum));
                }
              }

              if ((cp_size * 4)) {
                {
                  const size_t data_size =
                      sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                  memcpy_async(__pscmc_mapu_internal_block__,
                               ((unsigned *)__tmp_array),
                               ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                               ((uint64_t)(4 * (cp_size * data_size))),
                               __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

              if ((cp_size * (4 * 1))) {
                {
                  const size_t data_size = sizeof((__tmp_array)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((xyzw + (4 * (cu_offset + grid_id))) +
                                          (__pscmc_cpnum * 4))),
                      ((unsigned *)__tmp_array),
                      ((uint64_t)((4 * 1) * (cp_size * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }
            }
          }
        }
      }
    }
  }
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = YLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(1 + (real_p * 6))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 6); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN31;
    MYGEN31 = (num_write_plus * 6);
    for (0; (MYGEN31 > 0); (MYGEN31 = (MYGEN31 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN31 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (6 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
        6));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_y_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 6)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 6)];
  __mem0__ double local_pos_cache[(64 * 6)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ double rat;
  rat = ((1.00000000000000000e+00 * cu_cur_cache_load) / cu_cache_length);

  if ((__idx == 0)) {
    {
      __mem1__ int num_cur_load;
      num_cur_load = 0;
      __mem1__ int beg_to_left;
      beg_to_left = ((2 * cu_cache_length) / 5);
      __mem1__ int cur_to_left;
      cur_to_left = beg_to_left;
      __mem1__ int cur_to_right;
      cur_to_right = cu_cache_length;
      __mem1__ int cur_this;
      cur_this = 0;
      __mem1__ int lg;
      __mem1__ int g;
      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        __mem1__ MAPU_LONG num_read;
        num_read = ((((lg + 64) > cu_cur_cache_load))
                        ? (({ (cu_cur_cache_load - lg); }))
                        : (({ 64; })));

        if (((num_read * 6) * 1)) {
          {
            const size_t data_size = sizeof(
                (((cu_cache + (__idy * (6 * cu_cache_length))) + (lg * 6)))[0]);
            memcpy_async(__pscmc_mapu_internal_block__,
                         ((unsigned *)(local_pos_cache + (0 * 6))),
                         ((__DDR unsigned *)((cu_cache +
                                              (__idy * (6 * cu_cache_length))) +
                                             (lg * 6))),
                         ((uint64_t)(1 * ((num_read * 6) * data_size))),
                         __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        for (g = 0; (g < num_read); g++) {
          __mem1__ int gall;
          gall = (g + lg);

          if ((((local_pos_cache + (g * 6)))[1] < 0)) {

            if ((6 * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_pos_cache + (g * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (6 * cu_cache_length))) +
                                        (cur_to_left * 6))),
                    ((unsigned *)(local_pos_cache + (g * 6))),
                    ((uint64_t)(1 * (6 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {

            if ((((local_pos_cache + (g * 6)))[1] > YLEN)) {
              cur_to_right--;

              if ((6 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (6 * cu_cache_length))) +
                                          (cur_to_right * 6))),
                      ((unsigned *)(local_pos_cache + (g * 6))),
                      ((uint64_t)(1 * (6 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

            } else {

              if ((6 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (6 * cu_cache_length))) +
                                          (cur_this * 6))),
                      ((unsigned *)(local_pos_cache + (g * 6))),
                      ((uint64_t)(1 * (6 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
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
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = (__idx + (i * __xlen));

    if ((grid_id < xyzalllen)) {
      {
        __mem1__ int cur_load;
        cur_load = (xyzw)[(4 * (cu_offset + grid_id))];
        __mem1__ double rat;
        rat = ((1.00000000000000000e+00 * cur_load) / grid_cache_len);
        __mem1__ MAPU_LONG bxyzx;
        bxyzx = (grid_id % XLEN);
        __mem1__ MAPU_LONG bxyzy;
        bxyzy = ((grid_id / XLEN) % YLEN);
        __mem1__ MAPU_LONG bxyzz;
        bxyzz = (grid_id / (XLEN * YLEN));
        __mem1__ int g;
        g = 0;
        __mem1__ int lg;
        lg = 0;
        __mem1__ MAPU_LONG plus_offset;
        plus_offset = 0;
        __mem1__ MAPU_LONG minus_offset;
        minus_offset = 0;
        __mem1__ MAPU_LONG left_bound;
        left_bound = bxyzy;
        __mem1__ MAPU_LONG right_bound;
        right_bound = (left_bound + 1);
        __mem1__ int sizeof_double;
        sizeof_double = sizeof(double);
        __mem1__ MAPU_LONG num_write_minus;
        num_write_minus = 0;
        __mem1__ MAPU_LONG num_write_plus;
        num_write_plus = 0;
        __mem1__ MAPU_LONG num_write_main;
        num_write_main = 0;
        __mem1__ MAPU_LONG num_write_tmp;
        num_write_tmp = 0;
        for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
          __mem1__ MAPU_LONG num_read;
          num_read = ((((lg + 64) > cur_load)) ? (({ (cur_load - lg); }))
                                               : (({ 64; })));

          if (((num_read * 6) * 1)) {
            {
              const size_t data_size = sizeof((
                  ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (lg * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(local_pos_cache + (0 * 6))),
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   6)) +
                                      (lg * 6))),
                  ((uint64_t)(1 * ((num_read * 6) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          {
            {
              __mem1__ MAPU_LONG inner_step;
              for ((inner_step = 0); (inner_step < num_read);
                   (inner_step = (inner_step + 1))) {
                {
                  __mem1__ MAPU_LONG inner_g;
                  for ((inner_g = 0); (inner_g < 3);
                       (inner_g = (inner_g + 1))) {
                    ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                         (((inoutput +
                            (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (3 + (lg * 6))))[((inner_step * 6) + inner_g)]);
                  }
                }
              }
            }
          }
          for (g = 0; (g < num_read); g++) {

            if ((((local_pos_cache + (g * 6)))[1] < left_bound)) {

              if (((num_write_tmp * 6) * 1)) {
                {
                  const size_t data_size = sizeof(
                      ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                        grid_cache_len) *
                                                       6)) +
                                          (num_write_main * 6))),
                      ((unsigned *)(local_pos_cache +
                                    ((g - num_write_tmp) * 6))),
                      ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                      put_sync_id);
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                __mem1__ MAPU_LONG i;
                for ((i = 0); (i < 6); (i = (i + 1))) {
                  (((local_temp_particle_cache_minus +
                     (num_write_minus * 6)))[i] =
                       ((local_pos_cache + (g * 6)))[i]);
                }
              }
              num_write_minus++;

            } else {

              if ((((local_pos_cache + (g * 6)))[1] > right_bound)) {

                if (((num_write_tmp * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            (num_write_main * 6))),
                        ((unsigned *)(local_pos_cache +
                                      ((g - num_write_tmp) * 6))),
                        ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                        put_sync_id);
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);
                {
                  __mem1__ MAPU_LONG i;
                  for ((i = 0); (i < 6); (i = (i + 1))) {
                    (((local_temp_particle_cache_plus +
                       (num_write_plus * 6)))[i] =
                         ((local_pos_cache + (g * 6)))[i]);
                  }
                }
                num_write_plus++;

              } else {

                if (((((local_vel_cache)[((g * 3) + 0)] *
                       (local_vel_cache)[((g * 3) + 0)]) +
                      (((local_vel_cache)[((g * 3) + 1)] *
                        (local_vel_cache)[((g * 3) + 1)]) +
                       ((local_vel_cache)[((g * 3) + 2)] *
                        (local_vel_cache)[((g * 3) + 2)]))) >
                     1.00000000000000000e+00)) {

                  if (((num_write_tmp * 6) * 1)) {
                    {
                      const size_t data_size = sizeof(
                          ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                      memcpy_async(
                          __pscmc_mapu_internal_block__,
                          ((__DDR unsigned *)((inoutput +
                                               (((cu_offset + grid_id) *
                                                 grid_cache_len) *
                                                6)) +
                                              (num_write_main * 6))),
                          ((unsigned *)(local_pos_cache +
                                        ((g - num_write_tmp) * 6))),
                          ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                          put_sync_id);
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
          if (((num_write_tmp * 6) * 1)) {
            {
              const size_t data_size =
                  sizeof(((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   6)) +
                                      (num_write_main * 6))),
                  ((unsigned *)(local_pos_cache + ((g - num_write_tmp) * 6))),
                  ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                  put_sync_id);
            }
          }
          (num_write_main = (num_write_main + num_write_tmp));
          (num_write_tmp = 0);
          (put_sync_id).arrive_and_wait();
          (get_sync_id).arrive_and_wait();
        }
        __mem1__ int x_main;
        x_main = num_write_main;
        __mem1__ int x_beg_minus;
        x_beg_minus = x_main;
        __mem1__ int x_beg_plus;
        x_beg_plus =
            (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));
        __mem0__ int xm4[4];
        ((xm4)[0] = x_main);
        ((xm4)[1] = (num_write_minus + x_main));
        ((xm4)[2] = x_beg_plus);
        ((xm4)[3] = (num_write_plus + x_beg_plus));

        if ((4 * 1)) {
          {
            const size_t data_size = sizeof((xm4)[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)(xyzw + (4 * (cu_offset + grid_id)))),
                ((unsigned *)xm4), ((uint64_t)(1 * (4 * data_size))),
                put_sync_id);
          }
        }

        if (((6 * num_write_minus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      6)) +
                                    (x_beg_minus * 6))),
                ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                ((uint64_t)(1 * ((6 * num_write_minus) * data_size))),
                put_sync_id);
          }
        }

        if (((xm4)[3] > grid_cache_len)) {
          {
            __mem1__ MAPU_LONG i;
            i = 0;
            for (i = 0; (i < 4); i++) {
            }
          }
        }

        if (((6 * num_write_plus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      6)) +
                                    (x_beg_plus * 6))),
                ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                ((uint64_t)(1 * ((6 * num_write_plus) * data_size))),
                put_sync_id);
          }
        }
        (put_sync_id).arrive_and_wait();
      }
    }
  }
  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzy == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzy == (YLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(((
                        xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 *
                                              ((cu_offset + grid_id) - XLEN)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((6 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_minus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((uint64_t)(1 * ((6 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((6 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                          ((beg_plus - (XLEN * grid_cache_len)) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 6))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 ((beg_plus - (XLEN * grid_cache_len)) * 6))),
                        ((uint64_t)(1 * ((6 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 6) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                    ((uint64_t)(1 * ((num_from_left * 6) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            ((beg_plus * 6) -
                                             (XLEN * (grid_cache_len * 6))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 6))),
                        ((uint64_t)(1 * ((num_to_left * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw + ((4 * (cu_offset +
                                                          (grid_id - XLEN))) +
                                                    2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((6 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (6 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (6 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 (6 * cur_beg_plus)) +
                                (__pscmc_cpnum * (6 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                                   (6 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((uint64_t)((6 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((6 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 6)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     6))) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((6 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_plus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_plus * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_z_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));
  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = i;
    __mem1__ MAPU_LONG bxyzx;
    bxyzx = (grid_id % XLEN);
    __mem1__ MAPU_LONG bxyzy;
    bxyzy = ((grid_id / XLEN) % YLEN);
    __mem1__ MAPU_LONG bxyzz;
    bxyzz = (grid_id / (XLEN * YLEN));
    __mem1__ int cur_load0;
    cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];
    __mem1__ int cur_load;
    cur_load = cur_load0;
    __mem1__ int g;
    g = 0;
    __mem1__ int lg;
    lg = 0;
    __mem1__ MAPU_LONG plus_offset;
    plus_offset = 0;
    __mem1__ MAPU_LONG minus_offset;
    minus_offset = 0;
    __mem1__ MAPU_LONG left_bound;
    left_bound = bxyzz;
    __mem1__ MAPU_LONG right_bound;
    right_bound = (bxyzz + 1);
    __mem1__ int sizeof_double;
    sizeof_double = sizeof(double);
    __mem1__ MAPU_LONG num_write_minus;
    num_write_minus = 0;
    __mem1__ MAPU_LONG num_write_plus;
    num_write_plus = 0;
    __mem1__ MAPU_LONG num_write_main;
    num_write_main = 0;
    __mem1__ MAPU_LONG num_write_tmp;
    num_write_tmp = 0;
    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      __mem1__ int cur_grid_num;
      cur_grid_num = 0;
      __mem1__ int to_left_num;
      to_left_num = 0;
      __mem1__ int to_right_num;
      to_right_num = 0;
      __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
      __mem0__ int tln_shared[IDX_LOCAL_XLEN];
      __mem0__ int trn_shared[IDX_LOCAL_XLEN];
      {
        __mem1__ MAPU_LONG p;
        for ((p = (lg + (__idx * __xlen)));
             (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          __mem1__ int real_p;
          real_p = p;
          __mem1__ int local_p_id;
          local_p_id = (p - (lg + (__idx * __xlen)));
          __mem1__ int if_exist_particle;
          if_exist_particle = (real_p < cur_load);
          __mem1__ double particle_sort_key_element;
          particle_sort_key_element = ((if_exist_particle) ? (({
            ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                          6)))[(2 + (real_p * 6))];
          }))
                                                           : (({ -1; })));
          __mem1__ int is_to_left;
          is_to_left = (particle_sort_key_element < left_bound);
          __mem1__ int is_to_right;
          is_to_right = (particle_sort_key_element > right_bound);
          __mem1__ int is_cur;
          is_cur = ((!is_to_right) && (!is_to_left));
          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            __mem1__ MAPU_LONG i;
            for ((i = 0); (i < 6); (i = (i + 1))) {

              if (is_to_left) {
                {
                  ((for_sort_grid_memory_left)[(
                       i +
                       (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_to_right) {
                {
                  ((for_sort_grid_memory_right)[(
                       i +
                       (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_cur) {
                {
                  (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                 6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                 (cur_grid_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     6)))[(i + (6 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }
            }
          }
          if (is_cur) {
            {
              (cur_grid_num = (cur_grid_num + 1));
            }
          }

          if (is_to_left) {
            {
              (to_left_num = (to_left_num + 1));
            }
          }

          if (is_to_right) {
            {
              (to_right_num = (to_right_num + 1));
            }
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __mem1__ MAPU_LONG p;
      p = 0;
      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

        if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&(
                ((inoutput +
                  (((cu_offset + grid_id) * grid_cache_len) *
                   6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                        0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
                ((__DDR unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       6)))[(0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

        if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
                0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((tln_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

        if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
                0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((trn_shared)[(p / __xlen)] * 6) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      }
    }
    __mem1__ int is_most_left;
    is_most_left = (bxyzz == 0);
    __mem1__ int is_most_right;
    is_most_right = (bxyzz == (ZLEN - 1));
    __mem1__ int beg_left_main;
    beg_left_main = grid_cache_len;
    __mem1__ int beg_plus;
    beg_plus = 0;
    __mem1__ int end_plus;
    end_plus = 0;

    if ((!is_most_left)) {
      {
        (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))]);
        (beg_plus =
             (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)]);
        (end_plus =
             (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 3)]);
      }
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = (end_plus - beg_plus);

      if ((num_copy_real_11516lap > (grid_cache_len - num_write_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - num_write_main));

          if (((6 *
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))) *
               1)) {
            {
              const size_t data_size = sizeof(
                  ((&(((inoutput +
                        (((cu_offset + grid_id) * grid_cache_len) *
                         6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                         (beg_plus - ((XLEN * YLEN) *
                                                      grid_cache_len)))))]) +
                    (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&(((inoutput +
                               (((cu_offset + grid_id) * grid_cache_len) *
                                6)))[(0 +
                                      (6 * ((__idx * (__xlen * 0)) +
                                            (beg_plus - ((XLEN * YLEN) *
                                                         grid_cache_len)))))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 * ((6 * ((end_plus - beg_plus) -
                                         (grid_cache_len - num_write_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((
              (inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
              0 + (6 * ((__idx * (__xlen * 0)) +
                        (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (num_write_main * 6))),
              ((__DDR unsigned *)&((
                  (inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(
                  0 + (6 * ((__idx * (__xlen * 0)) +
                            (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_minus;

      if ((num_copy_real_11516lap > (grid_cache_len - beg_left_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - beg_left_main));

          if (((6 * (num_write_minus - (grid_cache_len - beg_left_main))) *
               1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_left)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_left)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 * ((6 * (num_write_minus -
                                         (grid_cache_len - beg_left_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                (num_write_minus - (grid_cache_len - beg_left_main))));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)(&(((inoutput +
                                (((cu_offset + grid_id) * grid_cache_len) *
                                 6)))[(0 + (6 * ((__idx * (__xlen * 0)) +
                                                 -(((XLEN * YLEN) *
                                                    grid_cache_len)))))]) +
                            (beg_left_main * 6))),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if (((!is_most_left) && (__idx == 0))) {
      {
        ((xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))] = beg_left_main);
      }
    }
    __mem1__ int cap_tmp;
    cap_tmp = ((is_most_right) ? (({ 0; }))
                               : (({ (grid_cache_len - num_write_main); })));
    __mem1__ int total_cache_num;
    total_cache_num = num_write_main;
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_plus;

      if ((num_copy_real_11516lap > cap_tmp)) {
        {
          (num_copy_real_11516lap = cap_tmp);

          if (((6 * (num_write_plus - cap_tmp)) * 1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_right)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (6 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_right)[(
                               0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 6))),
                  ((uint64_t)(1 *
                              ((6 * (num_write_plus - cap_tmp)) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load + (num_write_plus - cap_tmp)));
        }
      }

      if (((num_copy_real_11516lap * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            6)))[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (total_cache_num * 6))),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    __mem0__ int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);

    if ((__idx == 0)) {
      {

        if (((4 * 1) > 0)) {
          {
            __mem0__ double __tmp_array[4096];
            __mem1__ MAPU_LONG __pscmc_cpnum;
            __pscmc_cpnum = 0;
            __mem1__ MAPU_LONG __pscmc_one_copy;
            __pscmc_one_copy = (4096 / 4);
            for (0; (__pscmc_cpnum < 1);
                 (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
              __mem1__ MAPU_LONG cp_size;
              cp_size = __pscmc_one_copy;

              if (((cp_size + __pscmc_cpnum) > 1)) {
                {
                  (cp_size = (1 - __pscmc_cpnum));
                }
              }

              if ((cp_size * 4)) {
                {
                  const size_t data_size =
                      sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                  memcpy_async(__pscmc_mapu_internal_block__,
                               ((unsigned *)__tmp_array),
                               ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                               ((uint64_t)(4 * (cp_size * data_size))),
                               __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

              if ((cp_size * (4 * 1))) {
                {
                  const size_t data_size = sizeof((__tmp_array)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((xyzw + (4 * (cu_offset + grid_id))) +
                                          (__pscmc_cpnum * 4))),
                      ((unsigned *)__tmp_array),
                      ((uint64_t)((4 * 1) * (cp_size * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }
            }
          }
        }
      }
    }
  }
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = ZLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(2 + (real_p * 6))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 6); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN44;
    MYGEN44 = (num_write_plus * 6);
    for (0; (MYGEN44 > 0); (MYGEN44 = (MYGEN44 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN44 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (6 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
        6));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_z_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 6)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 6)];
  __mem0__ double local_pos_cache[(64 * 6)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ double rat;
  rat = ((1.00000000000000000e+00 * cu_cur_cache_load) / cu_cache_length);

  if ((__idx == 0)) {
    {
      __mem1__ int num_cur_load;
      num_cur_load = 0;
      __mem1__ int beg_to_left;
      beg_to_left = ((2 * cu_cache_length) / 5);
      __mem1__ int cur_to_left;
      cur_to_left = beg_to_left;
      __mem1__ int cur_to_right;
      cur_to_right = cu_cache_length;
      __mem1__ int cur_this;
      cur_this = 0;
      __mem1__ int lg;
      __mem1__ int g;
      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        __mem1__ MAPU_LONG num_read;
        num_read = ((((lg + 64) > cu_cur_cache_load))
                        ? (({ (cu_cur_cache_load - lg); }))
                        : (({ 64; })));

        if (((num_read * 6) * 1)) {
          {
            const size_t data_size = sizeof(
                (((cu_cache + (__idy * (6 * cu_cache_length))) + (lg * 6)))[0]);
            memcpy_async(__pscmc_mapu_internal_block__,
                         ((unsigned *)(local_pos_cache + (0 * 6))),
                         ((__DDR unsigned *)((cu_cache +
                                              (__idy * (6 * cu_cache_length))) +
                                             (lg * 6))),
                         ((uint64_t)(1 * ((num_read * 6) * data_size))),
                         __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        for (g = 0; (g < num_read); g++) {
          __mem1__ int gall;
          gall = (g + lg);

          if ((((local_pos_cache + (g * 6)))[2] < 0)) {

            if ((6 * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_pos_cache + (g * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (6 * cu_cache_length))) +
                                        (cur_to_left * 6))),
                    ((unsigned *)(local_pos_cache + (g * 6))),
                    ((uint64_t)(1 * (6 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {

            if ((((local_pos_cache + (g * 6)))[2] > ZLEN)) {
              cur_to_right--;

              if ((6 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (6 * cu_cache_length))) +
                                          (cur_to_right * 6))),
                      ((unsigned *)(local_pos_cache + (g * 6))),
                      ((uint64_t)(1 * (6 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

            } else {

              if ((6 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (6 * cu_cache_length))) +
                                          (cur_this * 6))),
                      ((unsigned *)(local_pos_cache + (g * 6))),
                      ((uint64_t)(1 * (6 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
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
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = (__idx + (i * __xlen));

    if ((grid_id < xyzalllen)) {
      {
        __mem1__ int cur_load;
        cur_load = (xyzw)[(4 * (cu_offset + grid_id))];
        __mem1__ double rat;
        rat = ((1.00000000000000000e+00 * cur_load) / grid_cache_len);
        __mem1__ MAPU_LONG bxyzx;
        bxyzx = (grid_id % XLEN);
        __mem1__ MAPU_LONG bxyzy;
        bxyzy = ((grid_id / XLEN) % YLEN);
        __mem1__ MAPU_LONG bxyzz;
        bxyzz = (grid_id / (XLEN * YLEN));
        __mem1__ int g;
        g = 0;
        __mem1__ int lg;
        lg = 0;
        __mem1__ MAPU_LONG plus_offset;
        plus_offset = 0;
        __mem1__ MAPU_LONG minus_offset;
        minus_offset = 0;
        __mem1__ MAPU_LONG left_bound;
        left_bound = bxyzz;
        __mem1__ MAPU_LONG right_bound;
        right_bound = (left_bound + 1);
        __mem1__ int sizeof_double;
        sizeof_double = sizeof(double);
        __mem1__ MAPU_LONG num_write_minus;
        num_write_minus = 0;
        __mem1__ MAPU_LONG num_write_plus;
        num_write_plus = 0;
        __mem1__ MAPU_LONG num_write_main;
        num_write_main = 0;
        __mem1__ MAPU_LONG num_write_tmp;
        num_write_tmp = 0;
        for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
          __mem1__ MAPU_LONG num_read;
          num_read = ((((lg + 64) > cur_load)) ? (({ (cur_load - lg); }))
                                               : (({ 64; })));

          if (((num_read * 6) * 1)) {
            {
              const size_t data_size = sizeof((
                  ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                   (lg * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(local_pos_cache + (0 * 6))),
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   6)) +
                                      (lg * 6))),
                  ((uint64_t)(1 * ((num_read * 6) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          {
            {
              __mem1__ MAPU_LONG inner_step;
              for ((inner_step = 0); (inner_step < num_read);
                   (inner_step = (inner_step + 1))) {
                {
                  __mem1__ MAPU_LONG inner_g;
                  for ((inner_g = 0); (inner_g < 3);
                       (inner_g = (inner_g + 1))) {
                    ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                         (((inoutput +
                            (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                           (3 + (lg * 6))))[((inner_step * 6) + inner_g)]);
                  }
                }
              }
            }
          }
          for (g = 0; (g < num_read); g++) {

            if ((((local_pos_cache + (g * 6)))[2] < left_bound)) {

              if (((num_write_tmp * 6) * 1)) {
                {
                  const size_t data_size = sizeof(
                      ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                        grid_cache_len) *
                                                       6)) +
                                          (num_write_main * 6))),
                      ((unsigned *)(local_pos_cache +
                                    ((g - num_write_tmp) * 6))),
                      ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                      put_sync_id);
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                __mem1__ MAPU_LONG i;
                for ((i = 0); (i < 6); (i = (i + 1))) {
                  (((local_temp_particle_cache_minus +
                     (num_write_minus * 6)))[i] =
                       ((local_pos_cache + (g * 6)))[i]);
                }
              }
              num_write_minus++;

            } else {

              if ((((local_pos_cache + (g * 6)))[2] > right_bound)) {

                if (((num_write_tmp * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            (num_write_main * 6))),
                        ((unsigned *)(local_pos_cache +
                                      ((g - num_write_tmp) * 6))),
                        ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                        put_sync_id);
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);
                {
                  __mem1__ MAPU_LONG i;
                  for ((i = 0); (i < 6); (i = (i + 1))) {
                    (((local_temp_particle_cache_plus +
                       (num_write_plus * 6)))[i] =
                         ((local_pos_cache + (g * 6)))[i]);
                  }
                }
                num_write_plus++;

              } else {

                if (((((local_vel_cache)[((g * 3) + 0)] *
                       (local_vel_cache)[((g * 3) + 0)]) +
                      (((local_vel_cache)[((g * 3) + 1)] *
                        (local_vel_cache)[((g * 3) + 1)]) +
                       ((local_vel_cache)[((g * 3) + 2)] *
                        (local_vel_cache)[((g * 3) + 2)]))) >
                     1.00000000000000000e+00)) {

                  if (((num_write_tmp * 6) * 1)) {
                    {
                      const size_t data_size = sizeof(
                          ((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
                      memcpy_async(
                          __pscmc_mapu_internal_block__,
                          ((__DDR unsigned *)((inoutput +
                                               (((cu_offset + grid_id) *
                                                 grid_cache_len) *
                                                6)) +
                                              (num_write_main * 6))),
                          ((unsigned *)(local_pos_cache +
                                        ((g - num_write_tmp) * 6))),
                          ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                          put_sync_id);
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
          if (((num_write_tmp * 6) * 1)) {
            {
              const size_t data_size =
                  sizeof(((local_pos_cache + ((g - num_write_tmp) * 6)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   6)) +
                                      (num_write_main * 6))),
                  ((unsigned *)(local_pos_cache + ((g - num_write_tmp) * 6))),
                  ((uint64_t)(1 * ((num_write_tmp * 6) * data_size))),
                  put_sync_id);
            }
          }
          (num_write_main = (num_write_main + num_write_tmp));
          (num_write_tmp = 0);
          (put_sync_id).arrive_and_wait();
          (get_sync_id).arrive_and_wait();
        }
        __mem1__ int x_main;
        x_main = num_write_main;
        __mem1__ int x_beg_minus;
        x_beg_minus = x_main;
        __mem1__ int x_beg_plus;
        x_beg_plus =
            (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));
        __mem0__ int xm4[4];
        ((xm4)[0] = x_main);
        ((xm4)[1] = (num_write_minus + x_main));
        ((xm4)[2] = x_beg_plus);
        ((xm4)[3] = (num_write_plus + x_beg_plus));

        if ((4 * 1)) {
          {
            const size_t data_size = sizeof((xm4)[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)(xyzw + (4 * (cu_offset + grid_id)))),
                ((unsigned *)xm4), ((uint64_t)(1 * (4 * data_size))),
                put_sync_id);
          }
        }

        if (((6 * num_write_minus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      6)) +
                                    (x_beg_minus * 6))),
                ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                ((uint64_t)(1 * ((6 * num_write_minus) * data_size))),
                put_sync_id);
          }
        }

        if (((xm4)[3] > grid_cache_len)) {
          {
            __mem1__ MAPU_LONG i;
            i = 0;
            for (i = 0; (i < 4); i++) {
            }
          }
        }

        if (((6 * num_write_plus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      6)) +
                                    (x_beg_plus * 6))),
                ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                ((uint64_t)(1 * ((6 * num_write_plus) * data_size))),
                put_sync_id);
          }
        }
        (put_sync_id).arrive_and_wait();
      }
    }
  }
  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzz == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzz == (ZLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof((
                        (xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) +
                                 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) -
                                                   (XLEN * YLEN))) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((6 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_minus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((uint64_t)(1 * ((6 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((6 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                          ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) *
                           6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 6))),
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            ((beg_plus - ((XLEN * YLEN) *
                                                          grid_cache_len)) *
                                             6))),
                        ((uint64_t)(1 * ((6 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 6) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                    ((uint64_t)(1 * ((num_from_left * 6) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 ((beg_plus * 6) -
                                  ((XLEN * YLEN) * (grid_cache_len * 6))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 6))),
                        ((uint64_t)(1 * ((num_to_left * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset +
                                                   (grid_id - (XLEN * YLEN)))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((6 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (6 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (6 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 (6 * cur_beg_plus)) +
                                (__pscmc_cpnum * (6 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                                   (6 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((uint64_t)((6 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((6 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 6)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     6))) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((6 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_plus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_plus * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_x_vlo_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = XLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(0 + (real_p * 6))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 6); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN48;
    MYGEN48 = (num_write_plus * 6);
    for (0; (MYGEN48 > 0); (MYGEN48 = (MYGEN48 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN48 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (6 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
        6));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_x_vlo_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 6)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 6)];
  __mem0__ double local_pos_cache[(64 * 6)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  if ((4 * 1)) {
    {
      const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
      memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)cu_xyzw_shared),
                   ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                   ((uint64_t)(1 * (4 * data_size))),
                   __pscmc_mapu_internal_barrier__);
      (__pscmc_mapu_internal_barrier__).arrive_and_wait();
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzx == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzx == (XLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(
                        ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) - 1)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((6 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_minus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((uint64_t)(1 * ((6 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((6 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                          ((beg_plus - (1 * grid_cache_len)) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 6))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 ((beg_plus - (1 * grid_cache_len)) * 6))),
                        ((uint64_t)(1 * ((6 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 6) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                    ((uint64_t)(1 * ((num_from_left * 6) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            ((beg_plus * 6) -
                                             (1 * (grid_cache_len * 6))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 6))),
                        ((uint64_t)(1 * ((num_to_left * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + (grid_id - 1))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((6 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (6 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (6 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 (6 * cur_beg_plus)) +
                                (__pscmc_cpnum * (6 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                                   (6 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((uint64_t)((6 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((6 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 6)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     6))) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((6 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_plus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_plus * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_y_vlo_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = YLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(1 + (real_p * 6))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 6); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN53;
    MYGEN53 = (num_write_plus * 6);
    for (0; (MYGEN53 > 0); (MYGEN53 = (MYGEN53 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN53 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (6 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
        6));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_y_vlo_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 6)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 6)];
  __mem0__ double local_pos_cache[(64 * 6)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  if ((4 * 1)) {
    {
      const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
      memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)cu_xyzw_shared),
                   ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                   ((uint64_t)(1 * (4 * data_size))),
                   __pscmc_mapu_internal_barrier__);
      (__pscmc_mapu_internal_barrier__).arrive_and_wait();
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzy == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzy == (YLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(((
                        xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 *
                                              ((cu_offset + grid_id) - XLEN)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((6 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_minus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((uint64_t)(1 * ((6 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((6 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                          ((beg_plus - (XLEN * grid_cache_len)) * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 6))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 ((beg_plus - (XLEN * grid_cache_len)) * 6))),
                        ((uint64_t)(1 * ((6 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 6) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                    ((uint64_t)(1 * ((num_from_left * 6) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            ((beg_plus * 6) -
                                             (XLEN * (grid_cache_len * 6))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 6))),
                        ((uint64_t)(1 * ((num_to_left * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw + ((4 * (cu_offset +
                                                          (grid_id - XLEN))) +
                                                    2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((6 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (6 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (6 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 (6 * cur_beg_plus)) +
                                (__pscmc_cpnum * (6 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                                   (6 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((uint64_t)((6 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((6 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 6)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     6))) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((6 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_plus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_plus * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_z_vlo_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (6 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (6 * (__idy * cu_cache_length)));
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = ZLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(2 + (real_p * 6))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 6); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (6 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (6 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (6 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 6) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (6 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 6) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN58;
    MYGEN58 = (num_write_plus * 6);
    for (0; (MYGEN58 > 0); (MYGEN58 = (MYGEN58 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN58 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (6 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (6 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (6 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
               6));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (6 * ((__idx * (__xlen * 0)) + 0)))])) /
        6));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_z_vlo_6(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 6)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 6)];
  __mem0__ double local_pos_cache[(64 * 6)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  if ((4 * 1)) {
    {
      const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
      memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)cu_xyzw_shared),
                   ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                   ((uint64_t)(1 * (4 * data_size))),
                   __pscmc_mapu_internal_barrier__);
      (__pscmc_mapu_internal_barrier__).arrive_and_wait();
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzz == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzz == (ZLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof((
                        (xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) +
                                 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) -
                                                   (XLEN * YLEN))) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 6)))[(j * 6)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((6 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_minus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((uint64_t)(1 * ((6 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((6 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                          ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) *
                           6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 6))),
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              6)) +
                                            ((beg_plus - ((XLEN * YLEN) *
                                                          grid_cache_len)) *
                                             6))),
                        ((uint64_t)(1 * ((6 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 6) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 6))),
                    ((uint64_t)(1 * ((num_from_left * 6) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 6) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 ((beg_plus * 6) -
                                  ((XLEN * YLEN) * (grid_cache_len * 6))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 6))),
                        ((uint64_t)(1 * ((num_to_left * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 6) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 6)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 6)) +
                                             (cur_cu_cache_load * 6)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 6))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 6) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset +
                                                   (grid_id - (XLEN * YLEN)))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((6 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (6 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (6 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   6)) +
                                 (6 * cur_beg_plus)) +
                                (__pscmc_cpnum * (6 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                                   (6 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((uint64_t)((6 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((6 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 6)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     6))) +
                                                  (__pscmc_cpnum *
                                                   (6 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((6 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 6)) +
                             (beg_plus * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_plus * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((6 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     6)) +
                                        (beg_minus * 6))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 6))),
                    ((uint64_t)(1 * ((6 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_x_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));
  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = i;
    __mem1__ MAPU_LONG bxyzx;
    bxyzx = (grid_id % XLEN);
    __mem1__ MAPU_LONG bxyzy;
    bxyzy = ((grid_id / XLEN) % YLEN);
    __mem1__ MAPU_LONG bxyzz;
    bxyzz = (grid_id / (XLEN * YLEN));
    __mem1__ int cur_load0;
    cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];
    __mem1__ int cur_load;
    cur_load = cur_load0;
    __mem1__ int g;
    g = 0;
    __mem1__ int lg;
    lg = 0;
    __mem1__ MAPU_LONG plus_offset;
    plus_offset = 0;
    __mem1__ MAPU_LONG minus_offset;
    minus_offset = 0;
    __mem1__ MAPU_LONG left_bound;
    left_bound = bxyzx;
    __mem1__ MAPU_LONG right_bound;
    right_bound = (bxyzx + 1);
    __mem1__ int sizeof_double;
    sizeof_double = sizeof(double);
    __mem1__ MAPU_LONG num_write_minus;
    num_write_minus = 0;
    __mem1__ MAPU_LONG num_write_plus;
    num_write_plus = 0;
    __mem1__ MAPU_LONG num_write_main;
    num_write_main = 0;
    __mem1__ MAPU_LONG num_write_tmp;
    num_write_tmp = 0;
    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      __mem1__ int cur_grid_num;
      cur_grid_num = 0;
      __mem1__ int to_left_num;
      to_left_num = 0;
      __mem1__ int to_right_num;
      to_right_num = 0;
      __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
      __mem0__ int tln_shared[IDX_LOCAL_XLEN];
      __mem0__ int trn_shared[IDX_LOCAL_XLEN];
      {
        __mem1__ MAPU_LONG p;
        for ((p = (lg + (__idx * __xlen)));
             (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          __mem1__ int real_p;
          real_p = p;
          __mem1__ int local_p_id;
          local_p_id = (p - (lg + (__idx * __xlen)));
          __mem1__ int if_exist_particle;
          if_exist_particle = (real_p < cur_load);
          __mem1__ double particle_sort_key_element;
          particle_sort_key_element = ((if_exist_particle) ? (({
            ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                          8)))[(0 + (real_p * 8))];
          }))
                                                           : (({ -1; })));
          __mem1__ int is_to_left;
          is_to_left = (particle_sort_key_element < left_bound);
          __mem1__ int is_to_right;
          is_to_right = (particle_sort_key_element > right_bound);
          __mem1__ int is_cur;
          is_cur = ((!is_to_right) && (!is_to_left));
          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            __mem1__ MAPU_LONG i;
            for ((i = 0); (i < 8); (i = (i + 1))) {

              if (is_to_left) {
                {
                  ((for_sort_grid_memory_left)[(
                       i +
                       (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_to_right) {
                {
                  ((for_sort_grid_memory_right)[(
                       i +
                       (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_cur) {
                {
                  (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                 8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                 (cur_grid_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }
            }
          }
          if (is_cur) {
            {
              (cur_grid_num = (cur_grid_num + 1));
            }
          }

          if (is_to_left) {
            {
              (to_left_num = (to_left_num + 1));
            }
          }

          if (is_to_right) {
            {
              (to_right_num = (to_right_num + 1));
            }
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __mem1__ MAPU_LONG p;
      p = 0;
      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

        if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&(
                ((inoutput +
                  (((cu_offset + grid_id) * grid_cache_len) *
                   8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                        0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
                ((__DDR unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

        if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
                0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((tln_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

        if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
                0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((trn_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      }
    }
    __mem1__ int is_most_left;
    is_most_left = (bxyzx == 0);
    __mem1__ int is_most_right;
    is_most_right = (bxyzx == (XLEN - 1));
    __mem1__ int beg_left_main;
    beg_left_main = grid_cache_len;
    __mem1__ int beg_plus;
    beg_plus = 0;
    __mem1__ int end_plus;
    end_plus = 0;

    if ((!is_most_left)) {
      {
        (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - 1))]);
        (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 2)]);
        (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - 1)) + 3)]);
      }
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = (end_plus - beg_plus);

      if ((num_copy_real_11516lap > (grid_cache_len - num_write_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - num_write_main));

          if (((8 *
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))) *
               1)) {
            {
              const size_t data_size = sizeof((
                  (&(((inoutput +
                       (((cu_offset + grid_id) * grid_cache_len) *
                        8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                        (beg_plus - (1 * grid_cache_len)))))]) +
                   (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&(((inoutput +
                               (((cu_offset + grid_id) * grid_cache_len) *
                                8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                                (beg_plus -
                                                 (1 * grid_cache_len)))))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 * ((8 * ((end_plus - beg_plus) -
                                         (grid_cache_len - num_write_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof(
              (&(((inoutput +
                   (((cu_offset + grid_id) * grid_cache_len) *
                    8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                    (beg_plus - (1 * grid_cache_len)))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (num_write_main * 8))),
              ((__DDR unsigned *)&(
                  ((inoutput +
                    (((cu_offset + grid_id) * grid_cache_len) *
                     8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                     (beg_plus - (1 * grid_cache_len)))))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_minus;

      if ((num_copy_real_11516lap > (grid_cache_len - beg_left_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - beg_left_main));

          if (((8 * (num_write_minus - (grid_cache_len - beg_left_main))) *
               1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_left)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_left)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 * ((8 * (num_write_minus -
                                         (grid_cache_len - beg_left_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                (num_write_minus - (grid_cache_len - beg_left_main))));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)(&(((inoutput +
                                (((cu_offset + grid_id) * grid_cache_len) *
                                 8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                                 -((1 * grid_cache_len)))))]) +
                            (beg_left_main * 8))),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if (((!is_most_left) && (__idx == 0))) {
      {
        ((xyzw)[(4 * ((cu_offset + grid_id) - 1))] = beg_left_main);
      }
    }
    __mem1__ int cap_tmp;
    cap_tmp = ((is_most_right) ? (({ 0; }))
                               : (({ (grid_cache_len - num_write_main); })));
    __mem1__ int total_cache_num;
    total_cache_num = num_write_main;
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_plus;

      if ((num_copy_real_11516lap > cap_tmp)) {
        {
          (num_copy_real_11516lap = cap_tmp);

          if (((8 * (num_write_plus - cap_tmp)) * 1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_right)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_right)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 *
                              ((8 * (num_write_plus - cap_tmp)) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load + (num_write_plus - cap_tmp)));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (total_cache_num * 8))),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    __mem0__ int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);

    if ((__idx == 0)) {
      {

        if (((4 * 1) > 0)) {
          {
            __mem0__ double __tmp_array[4096];
            __mem1__ MAPU_LONG __pscmc_cpnum;
            __pscmc_cpnum = 0;
            __mem1__ MAPU_LONG __pscmc_one_copy;
            __pscmc_one_copy = (4096 / 4);
            for (0; (__pscmc_cpnum < 1);
                 (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
              __mem1__ MAPU_LONG cp_size;
              cp_size = __pscmc_one_copy;

              if (((cp_size + __pscmc_cpnum) > 1)) {
                {
                  (cp_size = (1 - __pscmc_cpnum));
                }
              }

              if ((cp_size * 4)) {
                {
                  const size_t data_size =
                      sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                  memcpy_async(__pscmc_mapu_internal_block__,
                               ((unsigned *)__tmp_array),
                               ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                               ((uint64_t)(4 * (cp_size * data_size))),
                               __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

              if ((cp_size * (4 * 1))) {
                {
                  const size_t data_size = sizeof((__tmp_array)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((xyzw + (4 * (cu_offset + grid_id))) +
                                          (__pscmc_cpnum * 4))),
                      ((unsigned *)__tmp_array),
                      ((uint64_t)((4 * 1) * (cp_size * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }
            }
          }
        }
      }
    }
  }
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = XLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(0 + (real_p * 8))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 8); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN72;
    MYGEN72 = (num_write_plus * 8);
    for (0; (MYGEN72 > 0); (MYGEN72 = (MYGEN72 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN72 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (8 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
        8));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_x_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 8)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 8)];
  __mem0__ double local_pos_cache[(64 * 8)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ double rat;
  rat = ((1.00000000000000000e+00 * cu_cur_cache_load) / cu_cache_length);

  if ((__idx == 0)) {
    {
      __mem1__ int num_cur_load;
      num_cur_load = 0;
      __mem1__ int beg_to_left;
      beg_to_left = ((2 * cu_cache_length) / 5);
      __mem1__ int cur_to_left;
      cur_to_left = beg_to_left;
      __mem1__ int cur_to_right;
      cur_to_right = cu_cache_length;
      __mem1__ int cur_this;
      cur_this = 0;
      __mem1__ int lg;
      __mem1__ int g;
      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        __mem1__ MAPU_LONG num_read;
        num_read = ((((lg + 64) > cu_cur_cache_load))
                        ? (({ (cu_cur_cache_load - lg); }))
                        : (({ 64; })));

        if (((num_read * 8) * 1)) {
          {
            const size_t data_size = sizeof(
                (((cu_cache + (__idy * (8 * cu_cache_length))) + (lg * 8)))[0]);
            memcpy_async(__pscmc_mapu_internal_block__,
                         ((unsigned *)(local_pos_cache + (0 * 8))),
                         ((__DDR unsigned *)((cu_cache +
                                              (__idy * (8 * cu_cache_length))) +
                                             (lg * 8))),
                         ((uint64_t)(1 * ((num_read * 8) * data_size))),
                         __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        for (g = 0; (g < num_read); g++) {
          __mem1__ int gall;
          gall = (g + lg);

          if ((((local_pos_cache + (g * 8)))[0] < 0)) {

            if ((8 * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_pos_cache + (g * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (8 * cu_cache_length))) +
                                        (cur_to_left * 8))),
                    ((unsigned *)(local_pos_cache + (g * 8))),
                    ((uint64_t)(1 * (8 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {

            if ((((local_pos_cache + (g * 8)))[0] > XLEN)) {
              cur_to_right--;

              if ((8 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (8 * cu_cache_length))) +
                                          (cur_to_right * 8))),
                      ((unsigned *)(local_pos_cache + (g * 8))),
                      ((uint64_t)(1 * (8 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

            } else {

              if ((8 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (8 * cu_cache_length))) +
                                          (cur_this * 8))),
                      ((unsigned *)(local_pos_cache + (g * 8))),
                      ((uint64_t)(1 * (8 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
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
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = (__idx + (i * __xlen));

    if ((grid_id < xyzalllen)) {
      {
        __mem1__ int cur_load;
        cur_load = (xyzw)[(4 * (cu_offset + grid_id))];
        __mem1__ double rat;
        rat = ((1.00000000000000000e+00 * cur_load) / grid_cache_len);
        __mem1__ MAPU_LONG bxyzx;
        bxyzx = (grid_id % XLEN);
        __mem1__ MAPU_LONG bxyzy;
        bxyzy = ((grid_id / XLEN) % YLEN);
        __mem1__ MAPU_LONG bxyzz;
        bxyzz = (grid_id / (XLEN * YLEN));
        __mem1__ int g;
        g = 0;
        __mem1__ int lg;
        lg = 0;
        __mem1__ MAPU_LONG plus_offset;
        plus_offset = 0;
        __mem1__ MAPU_LONG minus_offset;
        minus_offset = 0;
        __mem1__ MAPU_LONG left_bound;
        left_bound = bxyzx;
        __mem1__ MAPU_LONG right_bound;
        right_bound = (left_bound + 1);
        __mem1__ int sizeof_double;
        sizeof_double = sizeof(double);
        __mem1__ MAPU_LONG num_write_minus;
        num_write_minus = 0;
        __mem1__ MAPU_LONG num_write_plus;
        num_write_plus = 0;
        __mem1__ MAPU_LONG num_write_main;
        num_write_main = 0;
        __mem1__ MAPU_LONG num_write_tmp;
        num_write_tmp = 0;
        for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
          __mem1__ MAPU_LONG num_read;
          num_read = ((((lg + 64) > cur_load)) ? (({ (cur_load - lg); }))
                                               : (({ 64; })));

          if (((num_read * 8) * 1)) {
            {
              const size_t data_size = sizeof((
                  ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (lg * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(local_pos_cache + (0 * 8))),
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   8)) +
                                      (lg * 8))),
                  ((uint64_t)(1 * ((num_read * 8) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          {
            {
              __mem1__ MAPU_LONG inner_step;
              for ((inner_step = 0); (inner_step < num_read);
                   (inner_step = (inner_step + 1))) {
                {
                  __mem1__ MAPU_LONG inner_g;
                  for ((inner_g = 0); (inner_g < 3);
                       (inner_g = (inner_g + 1))) {
                    ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                         (((inoutput +
                            (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (3 + (lg * 8))))[((inner_step * 8) + inner_g)]);
                  }
                }
              }
            }
          }
          for (g = 0; (g < num_read); g++) {

            if ((((local_pos_cache + (g * 8)))[0] < left_bound)) {

              if (((num_write_tmp * 8) * 1)) {
                {
                  const size_t data_size = sizeof(
                      ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                        grid_cache_len) *
                                                       8)) +
                                          (num_write_main * 8))),
                      ((unsigned *)(local_pos_cache +
                                    ((g - num_write_tmp) * 8))),
                      ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                      put_sync_id);
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                __mem1__ MAPU_LONG i;
                for ((i = 0); (i < 8); (i = (i + 1))) {
                  (((local_temp_particle_cache_minus +
                     (num_write_minus * 8)))[i] =
                       ((local_pos_cache + (g * 8)))[i]);
                }
              }
              num_write_minus++;

            } else {

              if ((((local_pos_cache + (g * 8)))[0] > right_bound)) {

                if (((num_write_tmp * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            (num_write_main * 8))),
                        ((unsigned *)(local_pos_cache +
                                      ((g - num_write_tmp) * 8))),
                        ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                        put_sync_id);
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);
                {
                  __mem1__ MAPU_LONG i;
                  for ((i = 0); (i < 8); (i = (i + 1))) {
                    (((local_temp_particle_cache_plus +
                       (num_write_plus * 8)))[i] =
                         ((local_pos_cache + (g * 8)))[i]);
                  }
                }
                num_write_plus++;

              } else {

                if (((((local_vel_cache)[((g * 3) + 0)] *
                       (local_vel_cache)[((g * 3) + 0)]) +
                      (((local_vel_cache)[((g * 3) + 1)] *
                        (local_vel_cache)[((g * 3) + 1)]) +
                       ((local_vel_cache)[((g * 3) + 2)] *
                        (local_vel_cache)[((g * 3) + 2)]))) >
                     1.00000000000000000e+00)) {

                  if (((num_write_tmp * 8) * 1)) {
                    {
                      const size_t data_size = sizeof(
                          ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                      memcpy_async(
                          __pscmc_mapu_internal_block__,
                          ((__DDR unsigned *)((inoutput +
                                               (((cu_offset + grid_id) *
                                                 grid_cache_len) *
                                                8)) +
                                              (num_write_main * 8))),
                          ((unsigned *)(local_pos_cache +
                                        ((g - num_write_tmp) * 8))),
                          ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                          put_sync_id);
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
          if (((num_write_tmp * 8) * 1)) {
            {
              const size_t data_size =
                  sizeof(((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   8)) +
                                      (num_write_main * 8))),
                  ((unsigned *)(local_pos_cache + ((g - num_write_tmp) * 8))),
                  ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                  put_sync_id);
            }
          }
          (num_write_main = (num_write_main + num_write_tmp));
          (num_write_tmp = 0);
          (put_sync_id).arrive_and_wait();
          (get_sync_id).arrive_and_wait();
        }
        __mem1__ int x_main;
        x_main = num_write_main;
        __mem1__ int x_beg_minus;
        x_beg_minus = x_main;
        __mem1__ int x_beg_plus;
        x_beg_plus =
            (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));
        __mem0__ int xm4[4];
        ((xm4)[0] = x_main);
        ((xm4)[1] = (num_write_minus + x_main));
        ((xm4)[2] = x_beg_plus);
        ((xm4)[3] = (num_write_plus + x_beg_plus));

        if ((4 * 1)) {
          {
            const size_t data_size = sizeof((xm4)[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)(xyzw + (4 * (cu_offset + grid_id)))),
                ((unsigned *)xm4), ((uint64_t)(1 * (4 * data_size))),
                put_sync_id);
          }
        }

        if (((8 * num_write_minus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      8)) +
                                    (x_beg_minus * 8))),
                ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                ((uint64_t)(1 * ((8 * num_write_minus) * data_size))),
                put_sync_id);
          }
        }

        if (((xm4)[3] > grid_cache_len)) {
          {
            __mem1__ MAPU_LONG i;
            i = 0;
            for (i = 0; (i < 4); i++) {
            }
          }
        }

        if (((8 * num_write_plus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      8)) +
                                    (x_beg_plus * 8))),
                ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                ((uint64_t)(1 * ((8 * num_write_plus) * data_size))),
                put_sync_id);
          }
        }
        (put_sync_id).arrive_and_wait();
      }
    }
  }
  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzx == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzx == (XLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(
                        ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) - 1)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((8 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_minus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((uint64_t)(1 * ((8 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((8 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                          ((beg_plus - (1 * grid_cache_len)) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 8))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 ((beg_plus - (1 * grid_cache_len)) * 8))),
                        ((uint64_t)(1 * ((8 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 8) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                    ((uint64_t)(1 * ((num_from_left * 8) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            ((beg_plus * 8) -
                                             (1 * (grid_cache_len * 8))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 8))),
                        ((uint64_t)(1 * ((num_to_left * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + (grid_id - 1))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((8 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (8 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (8 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 (8 * cur_beg_plus)) +
                                (__pscmc_cpnum * (8 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                                   (8 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((uint64_t)((8 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((8 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 8)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     8))) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((8 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_plus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_plus * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_y_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));
  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = i;
    __mem1__ MAPU_LONG bxyzx;
    bxyzx = (grid_id % XLEN);
    __mem1__ MAPU_LONG bxyzy;
    bxyzy = ((grid_id / XLEN) % YLEN);
    __mem1__ MAPU_LONG bxyzz;
    bxyzz = (grid_id / (XLEN * YLEN));
    __mem1__ int cur_load0;
    cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];
    __mem1__ int cur_load;
    cur_load = cur_load0;
    __mem1__ int g;
    g = 0;
    __mem1__ int lg;
    lg = 0;
    __mem1__ MAPU_LONG plus_offset;
    plus_offset = 0;
    __mem1__ MAPU_LONG minus_offset;
    minus_offset = 0;
    __mem1__ MAPU_LONG left_bound;
    left_bound = bxyzy;
    __mem1__ MAPU_LONG right_bound;
    right_bound = (bxyzy + 1);
    __mem1__ int sizeof_double;
    sizeof_double = sizeof(double);
    __mem1__ MAPU_LONG num_write_minus;
    num_write_minus = 0;
    __mem1__ MAPU_LONG num_write_plus;
    num_write_plus = 0;
    __mem1__ MAPU_LONG num_write_main;
    num_write_main = 0;
    __mem1__ MAPU_LONG num_write_tmp;
    num_write_tmp = 0;
    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      __mem1__ int cur_grid_num;
      cur_grid_num = 0;
      __mem1__ int to_left_num;
      to_left_num = 0;
      __mem1__ int to_right_num;
      to_right_num = 0;
      __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
      __mem0__ int tln_shared[IDX_LOCAL_XLEN];
      __mem0__ int trn_shared[IDX_LOCAL_XLEN];
      {
        __mem1__ MAPU_LONG p;
        for ((p = (lg + (__idx * __xlen)));
             (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          __mem1__ int real_p;
          real_p = p;
          __mem1__ int local_p_id;
          local_p_id = (p - (lg + (__idx * __xlen)));
          __mem1__ int if_exist_particle;
          if_exist_particle = (real_p < cur_load);
          __mem1__ double particle_sort_key_element;
          particle_sort_key_element = ((if_exist_particle) ? (({
            ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                          8)))[(1 + (real_p * 8))];
          }))
                                                           : (({ -1; })));
          __mem1__ int is_to_left;
          is_to_left = (particle_sort_key_element < left_bound);
          __mem1__ int is_to_right;
          is_to_right = (particle_sort_key_element > right_bound);
          __mem1__ int is_cur;
          is_cur = ((!is_to_right) && (!is_to_left));
          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            __mem1__ MAPU_LONG i;
            for ((i = 0); (i < 8); (i = (i + 1))) {

              if (is_to_left) {
                {
                  ((for_sort_grid_memory_left)[(
                       i +
                       (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_to_right) {
                {
                  ((for_sort_grid_memory_right)[(
                       i +
                       (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_cur) {
                {
                  (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                 8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                 (cur_grid_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }
            }
          }
          if (is_cur) {
            {
              (cur_grid_num = (cur_grid_num + 1));
            }
          }

          if (is_to_left) {
            {
              (to_left_num = (to_left_num + 1));
            }
          }

          if (is_to_right) {
            {
              (to_right_num = (to_right_num + 1));
            }
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __mem1__ MAPU_LONG p;
      p = 0;
      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

        if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&(
                ((inoutput +
                  (((cu_offset + grid_id) * grid_cache_len) *
                   8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                        0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
                ((__DDR unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

        if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
                0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((tln_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

        if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
                0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((trn_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      }
    }
    __mem1__ int is_most_left;
    is_most_left = (bxyzy == 0);
    __mem1__ int is_most_right;
    is_most_right = (bxyzy == (YLEN - 1));
    __mem1__ int beg_left_main;
    beg_left_main = grid_cache_len;
    __mem1__ int beg_plus;
    beg_plus = 0;
    __mem1__ int end_plus;
    end_plus = 0;

    if ((!is_most_left)) {
      {
        (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - XLEN))]);
        (beg_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 2)]);
        (end_plus = (xyzw)[((4 * ((cu_offset + grid_id) - XLEN)) + 3)]);
      }
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = (end_plus - beg_plus);

      if ((num_copy_real_11516lap > (grid_cache_len - num_write_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - num_write_main));

          if (((8 *
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))) *
               1)) {
            {
              const size_t data_size = sizeof(
                  ((&(((inoutput +
                        (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                        0 + (8 * ((__idx * (__xlen * 0)) +
                                  (beg_plus - (XLEN * grid_cache_len)))))]) +
                    (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&(((inoutput +
                               (((cu_offset + grid_id) * grid_cache_len) *
                                8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                                (beg_plus -
                                                 (XLEN * grid_cache_len)))))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 * ((8 * ((end_plus - beg_plus) -
                                         (grid_cache_len - num_write_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof(
              (&(((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                  0 + (8 * ((__idx * (__xlen * 0)) +
                            (beg_plus - (XLEN * grid_cache_len)))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (num_write_main * 8))),
              ((__DDR unsigned *)&(
                  ((inoutput +
                    (((cu_offset + grid_id) * grid_cache_len) *
                     8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                     (beg_plus - (XLEN * grid_cache_len)))))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_minus;

      if ((num_copy_real_11516lap > (grid_cache_len - beg_left_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - beg_left_main));

          if (((8 * (num_write_minus - (grid_cache_len - beg_left_main))) *
               1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_left)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_left)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 * ((8 * (num_write_minus -
                                         (grid_cache_len - beg_left_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                (num_write_minus - (grid_cache_len - beg_left_main))));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                            -((XLEN * grid_cache_len)))))]) +
                       (beg_left_main * 8))),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if (((!is_most_left) && (__idx == 0))) {
      {
        ((xyzw)[(4 * ((cu_offset + grid_id) - XLEN))] = beg_left_main);
      }
    }
    __mem1__ int cap_tmp;
    cap_tmp = ((is_most_right) ? (({ 0; }))
                               : (({ (grid_cache_len - num_write_main); })));
    __mem1__ int total_cache_num;
    total_cache_num = num_write_main;
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_plus;

      if ((num_copy_real_11516lap > cap_tmp)) {
        {
          (num_copy_real_11516lap = cap_tmp);

          if (((8 * (num_write_plus - cap_tmp)) * 1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_right)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_right)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 *
                              ((8 * (num_write_plus - cap_tmp)) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load + (num_write_plus - cap_tmp)));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (total_cache_num * 8))),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    __mem0__ int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);

    if ((__idx == 0)) {
      {

        if (((4 * 1) > 0)) {
          {
            __mem0__ double __tmp_array[4096];
            __mem1__ MAPU_LONG __pscmc_cpnum;
            __pscmc_cpnum = 0;
            __mem1__ MAPU_LONG __pscmc_one_copy;
            __pscmc_one_copy = (4096 / 4);
            for (0; (__pscmc_cpnum < 1);
                 (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
              __mem1__ MAPU_LONG cp_size;
              cp_size = __pscmc_one_copy;

              if (((cp_size + __pscmc_cpnum) > 1)) {
                {
                  (cp_size = (1 - __pscmc_cpnum));
                }
              }

              if ((cp_size * 4)) {
                {
                  const size_t data_size =
                      sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                  memcpy_async(__pscmc_mapu_internal_block__,
                               ((unsigned *)__tmp_array),
                               ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                               ((uint64_t)(4 * (cp_size * data_size))),
                               __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

              if ((cp_size * (4 * 1))) {
                {
                  const size_t data_size = sizeof((__tmp_array)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((xyzw + (4 * (cu_offset + grid_id))) +
                                          (__pscmc_cpnum * 4))),
                      ((unsigned *)__tmp_array),
                      ((uint64_t)((4 * 1) * (cp_size * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }
            }
          }
        }
      }
    }
  }
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = YLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(1 + (real_p * 8))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 8); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN85;
    MYGEN85 = (num_write_plus * 8);
    for (0; (MYGEN85 > 0); (MYGEN85 = (MYGEN85 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN85 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (8 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
        8));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_y_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 8)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 8)];
  __mem0__ double local_pos_cache[(64 * 8)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ double rat;
  rat = ((1.00000000000000000e+00 * cu_cur_cache_load) / cu_cache_length);

  if ((__idx == 0)) {
    {
      __mem1__ int num_cur_load;
      num_cur_load = 0;
      __mem1__ int beg_to_left;
      beg_to_left = ((2 * cu_cache_length) / 5);
      __mem1__ int cur_to_left;
      cur_to_left = beg_to_left;
      __mem1__ int cur_to_right;
      cur_to_right = cu_cache_length;
      __mem1__ int cur_this;
      cur_this = 0;
      __mem1__ int lg;
      __mem1__ int g;
      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        __mem1__ MAPU_LONG num_read;
        num_read = ((((lg + 64) > cu_cur_cache_load))
                        ? (({ (cu_cur_cache_load - lg); }))
                        : (({ 64; })));

        if (((num_read * 8) * 1)) {
          {
            const size_t data_size = sizeof(
                (((cu_cache + (__idy * (8 * cu_cache_length))) + (lg * 8)))[0]);
            memcpy_async(__pscmc_mapu_internal_block__,
                         ((unsigned *)(local_pos_cache + (0 * 8))),
                         ((__DDR unsigned *)((cu_cache +
                                              (__idy * (8 * cu_cache_length))) +
                                             (lg * 8))),
                         ((uint64_t)(1 * ((num_read * 8) * data_size))),
                         __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        for (g = 0; (g < num_read); g++) {
          __mem1__ int gall;
          gall = (g + lg);

          if ((((local_pos_cache + (g * 8)))[1] < 0)) {

            if ((8 * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_pos_cache + (g * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (8 * cu_cache_length))) +
                                        (cur_to_left * 8))),
                    ((unsigned *)(local_pos_cache + (g * 8))),
                    ((uint64_t)(1 * (8 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {

            if ((((local_pos_cache + (g * 8)))[1] > YLEN)) {
              cur_to_right--;

              if ((8 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (8 * cu_cache_length))) +
                                          (cur_to_right * 8))),
                      ((unsigned *)(local_pos_cache + (g * 8))),
                      ((uint64_t)(1 * (8 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

            } else {

              if ((8 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (8 * cu_cache_length))) +
                                          (cur_this * 8))),
                      ((unsigned *)(local_pos_cache + (g * 8))),
                      ((uint64_t)(1 * (8 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
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
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = (__idx + (i * __xlen));

    if ((grid_id < xyzalllen)) {
      {
        __mem1__ int cur_load;
        cur_load = (xyzw)[(4 * (cu_offset + grid_id))];
        __mem1__ double rat;
        rat = ((1.00000000000000000e+00 * cur_load) / grid_cache_len);
        __mem1__ MAPU_LONG bxyzx;
        bxyzx = (grid_id % XLEN);
        __mem1__ MAPU_LONG bxyzy;
        bxyzy = ((grid_id / XLEN) % YLEN);
        __mem1__ MAPU_LONG bxyzz;
        bxyzz = (grid_id / (XLEN * YLEN));
        __mem1__ int g;
        g = 0;
        __mem1__ int lg;
        lg = 0;
        __mem1__ MAPU_LONG plus_offset;
        plus_offset = 0;
        __mem1__ MAPU_LONG minus_offset;
        minus_offset = 0;
        __mem1__ MAPU_LONG left_bound;
        left_bound = bxyzy;
        __mem1__ MAPU_LONG right_bound;
        right_bound = (left_bound + 1);
        __mem1__ int sizeof_double;
        sizeof_double = sizeof(double);
        __mem1__ MAPU_LONG num_write_minus;
        num_write_minus = 0;
        __mem1__ MAPU_LONG num_write_plus;
        num_write_plus = 0;
        __mem1__ MAPU_LONG num_write_main;
        num_write_main = 0;
        __mem1__ MAPU_LONG num_write_tmp;
        num_write_tmp = 0;
        for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
          __mem1__ MAPU_LONG num_read;
          num_read = ((((lg + 64) > cur_load)) ? (({ (cur_load - lg); }))
                                               : (({ 64; })));

          if (((num_read * 8) * 1)) {
            {
              const size_t data_size = sizeof((
                  ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (lg * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(local_pos_cache + (0 * 8))),
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   8)) +
                                      (lg * 8))),
                  ((uint64_t)(1 * ((num_read * 8) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          {
            {
              __mem1__ MAPU_LONG inner_step;
              for ((inner_step = 0); (inner_step < num_read);
                   (inner_step = (inner_step + 1))) {
                {
                  __mem1__ MAPU_LONG inner_g;
                  for ((inner_g = 0); (inner_g < 3);
                       (inner_g = (inner_g + 1))) {
                    ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                         (((inoutput +
                            (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (3 + (lg * 8))))[((inner_step * 8) + inner_g)]);
                  }
                }
              }
            }
          }
          for (g = 0; (g < num_read); g++) {

            if ((((local_pos_cache + (g * 8)))[1] < left_bound)) {

              if (((num_write_tmp * 8) * 1)) {
                {
                  const size_t data_size = sizeof(
                      ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                        grid_cache_len) *
                                                       8)) +
                                          (num_write_main * 8))),
                      ((unsigned *)(local_pos_cache +
                                    ((g - num_write_tmp) * 8))),
                      ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                      put_sync_id);
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                __mem1__ MAPU_LONG i;
                for ((i = 0); (i < 8); (i = (i + 1))) {
                  (((local_temp_particle_cache_minus +
                     (num_write_minus * 8)))[i] =
                       ((local_pos_cache + (g * 8)))[i]);
                }
              }
              num_write_minus++;

            } else {

              if ((((local_pos_cache + (g * 8)))[1] > right_bound)) {

                if (((num_write_tmp * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            (num_write_main * 8))),
                        ((unsigned *)(local_pos_cache +
                                      ((g - num_write_tmp) * 8))),
                        ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                        put_sync_id);
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);
                {
                  __mem1__ MAPU_LONG i;
                  for ((i = 0); (i < 8); (i = (i + 1))) {
                    (((local_temp_particle_cache_plus +
                       (num_write_plus * 8)))[i] =
                         ((local_pos_cache + (g * 8)))[i]);
                  }
                }
                num_write_plus++;

              } else {

                if (((((local_vel_cache)[((g * 3) + 0)] *
                       (local_vel_cache)[((g * 3) + 0)]) +
                      (((local_vel_cache)[((g * 3) + 1)] *
                        (local_vel_cache)[((g * 3) + 1)]) +
                       ((local_vel_cache)[((g * 3) + 2)] *
                        (local_vel_cache)[((g * 3) + 2)]))) >
                     1.00000000000000000e+00)) {

                  if (((num_write_tmp * 8) * 1)) {
                    {
                      const size_t data_size = sizeof(
                          ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                      memcpy_async(
                          __pscmc_mapu_internal_block__,
                          ((__DDR unsigned *)((inoutput +
                                               (((cu_offset + grid_id) *
                                                 grid_cache_len) *
                                                8)) +
                                              (num_write_main * 8))),
                          ((unsigned *)(local_pos_cache +
                                        ((g - num_write_tmp) * 8))),
                          ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                          put_sync_id);
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
          if (((num_write_tmp * 8) * 1)) {
            {
              const size_t data_size =
                  sizeof(((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   8)) +
                                      (num_write_main * 8))),
                  ((unsigned *)(local_pos_cache + ((g - num_write_tmp) * 8))),
                  ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                  put_sync_id);
            }
          }
          (num_write_main = (num_write_main + num_write_tmp));
          (num_write_tmp = 0);
          (put_sync_id).arrive_and_wait();
          (get_sync_id).arrive_and_wait();
        }
        __mem1__ int x_main;
        x_main = num_write_main;
        __mem1__ int x_beg_minus;
        x_beg_minus = x_main;
        __mem1__ int x_beg_plus;
        x_beg_plus =
            (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));
        __mem0__ int xm4[4];
        ((xm4)[0] = x_main);
        ((xm4)[1] = (num_write_minus + x_main));
        ((xm4)[2] = x_beg_plus);
        ((xm4)[3] = (num_write_plus + x_beg_plus));

        if ((4 * 1)) {
          {
            const size_t data_size = sizeof((xm4)[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)(xyzw + (4 * (cu_offset + grid_id)))),
                ((unsigned *)xm4), ((uint64_t)(1 * (4 * data_size))),
                put_sync_id);
          }
        }

        if (((8 * num_write_minus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      8)) +
                                    (x_beg_minus * 8))),
                ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                ((uint64_t)(1 * ((8 * num_write_minus) * data_size))),
                put_sync_id);
          }
        }

        if (((xm4)[3] > grid_cache_len)) {
          {
            __mem1__ MAPU_LONG i;
            i = 0;
            for (i = 0; (i < 4); i++) {
            }
          }
        }

        if (((8 * num_write_plus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      8)) +
                                    (x_beg_plus * 8))),
                ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                ((uint64_t)(1 * ((8 * num_write_plus) * data_size))),
                put_sync_id);
          }
        }
        (put_sync_id).arrive_and_wait();
      }
    }
  }
  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzy == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzy == (YLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(((
                        xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 *
                                              ((cu_offset + grid_id) - XLEN)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((8 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_minus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((uint64_t)(1 * ((8 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((8 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                          ((beg_plus - (XLEN * grid_cache_len)) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 8))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 ((beg_plus - (XLEN * grid_cache_len)) * 8))),
                        ((uint64_t)(1 * ((8 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 8) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                    ((uint64_t)(1 * ((num_from_left * 8) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            ((beg_plus * 8) -
                                             (XLEN * (grid_cache_len * 8))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 8))),
                        ((uint64_t)(1 * ((num_to_left * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw + ((4 * (cu_offset +
                                                          (grid_id - XLEN))) +
                                                    2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((8 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (8 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (8 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 (8 * cur_beg_plus)) +
                                (__pscmc_cpnum * (8 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                                   (8 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((uint64_t)((8 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((8 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 8)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     8))) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((8 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_plus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_plus * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_z_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));
  for (i = 0; (i < (XLEN * (YLEN * ZLEN))); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = i;
    __mem1__ MAPU_LONG bxyzx;
    bxyzx = (grid_id % XLEN);
    __mem1__ MAPU_LONG bxyzy;
    bxyzy = ((grid_id / XLEN) % YLEN);
    __mem1__ MAPU_LONG bxyzz;
    bxyzz = (grid_id / (XLEN * YLEN));
    __mem1__ int cur_load0;
    cur_load0 = (xyzw)[(4 * (cu_offset + grid_id))];
    __mem1__ int cur_load;
    cur_load = cur_load0;
    __mem1__ int g;
    g = 0;
    __mem1__ int lg;
    lg = 0;
    __mem1__ MAPU_LONG plus_offset;
    plus_offset = 0;
    __mem1__ MAPU_LONG minus_offset;
    minus_offset = 0;
    __mem1__ MAPU_LONG left_bound;
    left_bound = bxyzz;
    __mem1__ MAPU_LONG right_bound;
    right_bound = (bxyzz + 1);
    __mem1__ int sizeof_double;
    sizeof_double = sizeof(double);
    __mem1__ MAPU_LONG num_write_minus;
    num_write_minus = 0;
    __mem1__ MAPU_LONG num_write_plus;
    num_write_plus = 0;
    __mem1__ MAPU_LONG num_write_main;
    num_write_main = 0;
    __mem1__ MAPU_LONG num_write_tmp;
    num_write_tmp = 0;
    for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
      __mem1__ int cur_grid_num;
      cur_grid_num = 0;
      __mem1__ int to_left_num;
      to_left_num = 0;
      __mem1__ int to_right_num;
      to_right_num = 0;
      __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
      __mem0__ int tln_shared[IDX_LOCAL_XLEN];
      __mem0__ int trn_shared[IDX_LOCAL_XLEN];
      {
        __mem1__ MAPU_LONG p;
        for ((p = (lg + (__idx * __xlen)));
             (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
          __mem1__ int real_p;
          real_p = p;
          __mem1__ int local_p_id;
          local_p_id = (p - (lg + (__idx * __xlen)));
          __mem1__ int if_exist_particle;
          if_exist_particle = (real_p < cur_load);
          __mem1__ double particle_sort_key_element;
          particle_sort_key_element = ((if_exist_particle) ? (({
            ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                          8)))[(2 + (real_p * 8))];
          }))
                                                           : (({ -1; })));
          __mem1__ int is_to_left;
          is_to_left = (particle_sort_key_element < left_bound);
          __mem1__ int is_to_right;
          is_to_right = (particle_sort_key_element > right_bound);
          __mem1__ int is_cur;
          is_cur = ((!is_to_right) && (!is_to_left));
          (is_to_left = (if_exist_particle && is_to_left));
          (is_to_right = (if_exist_particle && is_to_right));
          (is_cur = (if_exist_particle && is_cur));
          {
            __mem1__ MAPU_LONG i;
            for ((i = 0); (i < 8); (i = (i + 1))) {

              if (is_to_left) {
                {
                  ((for_sort_grid_memory_left)[(
                       i +
                       (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_to_right) {
                {
                  ((for_sort_grid_memory_right)[(
                       i +
                       (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }

              if (is_cur) {
                {
                  (((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                 8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                 (cur_grid_num + lg))))] =
                       ((inoutput + (((cu_offset + grid_id) * grid_cache_len) *
                                     8)))[(i + (8 * ((__idx * (__xlen * 1)) +
                                                     (local_p_id + lg))))]);
                }
              }
            }
          }
          if (is_cur) {
            {
              (cur_grid_num = (cur_grid_num + 1));
            }
          }

          if (is_to_left) {
            {
              (to_left_num = (to_left_num + 1));
            }
          }

          if (is_to_right) {
            {
              (to_right_num = (to_right_num + 1));
            }
          }
        }
      }
      ((cgn_shared)[__idx] = cur_grid_num);
      ((tln_shared)[__idx] = to_left_num);
      ((trn_shared)[__idx] = to_right_num);
      __mem1__ MAPU_LONG p;
      p = 0;
      for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

        if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&(
                ((inoutput +
                  (((cu_offset + grid_id) * grid_cache_len) *
                   8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                        0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
                ((__DDR unsigned *)&(
                    ((inoutput +
                      (((cu_offset + grid_id) * grid_cache_len) *
                       8)))[(0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

        if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
                0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((tln_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

        if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
          {
            const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
                0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
                ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
                ((uint64_t)(1 *
                            (((trn_shared)[(p / __xlen)] * 8) * data_size))),
                __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
      }
    }
    __mem1__ int is_most_left;
    is_most_left = (bxyzz == 0);
    __mem1__ int is_most_right;
    is_most_right = (bxyzz == (ZLEN - 1));
    __mem1__ int beg_left_main;
    beg_left_main = grid_cache_len;
    __mem1__ int beg_plus;
    beg_plus = 0;
    __mem1__ int end_plus;
    end_plus = 0;

    if ((!is_most_left)) {
      {
        (beg_left_main = (xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))]);
        (beg_plus =
             (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 2)]);
        (end_plus =
             (xyzw)[((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) + 3)]);
      }
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = (end_plus - beg_plus);

      if ((num_copy_real_11516lap > (grid_cache_len - num_write_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - num_write_main));

          if (((8 *
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))) *
               1)) {
            {
              const size_t data_size = sizeof(
                  ((&(((inoutput +
                        (((cu_offset + grid_id) * grid_cache_len) *
                         8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                         (beg_plus - ((XLEN * YLEN) *
                                                      grid_cache_len)))))]) +
                    (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&(((inoutput +
                               (((cu_offset + grid_id) * grid_cache_len) *
                                8)))[(0 +
                                      (8 * ((__idx * (__xlen * 0)) +
                                            (beg_plus - ((XLEN * YLEN) *
                                                         grid_cache_len)))))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 * ((8 * ((end_plus - beg_plus) -
                                         (grid_cache_len - num_write_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                ((end_plus - beg_plus) - (grid_cache_len - num_write_main))));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((
              (inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
              0 + (8 * ((__idx * (__xlen * 0)) +
                        (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (num_write_main * 8))),
              ((__DDR unsigned *)&((
                  (inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(
                  0 + (8 * ((__idx * (__xlen * 0)) +
                            (beg_plus - ((XLEN * YLEN) * grid_cache_len)))))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + num_copy_real_11516lap));
    }
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_minus;

      if ((num_copy_real_11516lap > (grid_cache_len - beg_left_main))) {
        {
          (num_copy_real_11516lap = (grid_cache_len - beg_left_main));

          if (((8 * (num_write_minus - (grid_cache_len - beg_left_main))) *
               1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_left)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_left)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 * ((8 * (num_write_minus -
                                         (grid_cache_len - beg_left_main))) *
                                   data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load +
                (num_write_minus - (grid_cache_len - beg_left_main))));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)(&(((inoutput +
                                (((cu_offset + grid_id) * grid_cache_len) *
                                 8)))[(0 + (8 * ((__idx * (__xlen * 0)) +
                                                 -(((XLEN * YLEN) *
                                                    grid_cache_len)))))]) +
                            (beg_left_main * 8))),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (beg_left_main = (beg_left_main + num_copy_real_11516lap));
    }
    if (((!is_most_left) && (__idx == 0))) {
      {
        ((xyzw)[(4 * ((cu_offset + grid_id) - (XLEN * YLEN)))] = beg_left_main);
      }
    }
    __mem1__ int cap_tmp;
    cap_tmp = ((is_most_right) ? (({ 0; }))
                               : (({ (grid_cache_len - num_write_main); })));
    __mem1__ int total_cache_num;
    total_cache_num = num_write_main;
    {
      __mem1__ int num_copy_real_11516lap;
      num_copy_real_11516lap = num_write_plus;

      if ((num_copy_real_11516lap > cap_tmp)) {
        {
          (num_copy_real_11516lap = cap_tmp);

          if (((8 * (num_write_plus - cap_tmp)) * 1)) {
            {
              const size_t data_size =
                  sizeof(((&((for_sort_grid_memory_right)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(cu_cache_head + (8 * cu_cur_cache_load))),
                  ((__DDR unsigned
                        *)(&((for_sort_grid_memory_right)[(
                               0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                           (num_copy_real_11516lap * 8))),
                  ((uint64_t)(1 *
                              ((8 * (num_write_plus - cap_tmp)) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          (cu_cur_cache_load =
               (cu_cur_cache_load + (num_write_plus - cap_tmp)));
        }
      }

      if (((num_copy_real_11516lap * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned
                    *)(&(((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) *
                            8)))[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) +
                       (total_cache_num * 8))),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + 0)))])),
              ((uint64_t)(1 * ((num_copy_real_11516lap * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (total_cache_num = (total_cache_num + num_copy_real_11516lap));
    }
    __mem0__ int xm4[4];
    ((xm4)[0] = num_write_main);
    ((xm4)[1] = num_write_main);
    ((xm4)[2] = num_write_main);
    ((xm4)[3] = total_cache_num);

    if ((__idx == 0)) {
      {

        if (((4 * 1) > 0)) {
          {
            __mem0__ double __tmp_array[4096];
            __mem1__ MAPU_LONG __pscmc_cpnum;
            __pscmc_cpnum = 0;
            __mem1__ MAPU_LONG __pscmc_one_copy;
            __pscmc_one_copy = (4096 / 4);
            for (0; (__pscmc_cpnum < 1);
                 (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
              __mem1__ MAPU_LONG cp_size;
              cp_size = __pscmc_one_copy;

              if (((cp_size + __pscmc_cpnum) > 1)) {
                {
                  (cp_size = (1 - __pscmc_cpnum));
                }
              }

              if ((cp_size * 4)) {
                {
                  const size_t data_size =
                      sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                  memcpy_async(__pscmc_mapu_internal_block__,
                               ((unsigned *)__tmp_array),
                               ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                               ((uint64_t)(4 * (cp_size * data_size))),
                               __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

              if ((cp_size * (4 * 1))) {
                {
                  const size_t data_size = sizeof((__tmp_array)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((xyzw + (4 * (cu_offset + grid_id))) +
                                          (__pscmc_cpnum * 4))),
                      ((unsigned *)__tmp_array),
                      ((uint64_t)((4 * 1) * (cp_size * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }
            }
          }
        }
      }
    }
  }
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = ZLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(2 + (real_p * 8))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 8); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN98;
    MYGEN98 = (num_write_plus * 8);
    for (0; (MYGEN98 > 0); (MYGEN98 = (MYGEN98 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN98 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (8 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
        8));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_z_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 8)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 8)];
  __mem0__ double local_pos_cache[(64 * 8)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ double rat;
  rat = ((1.00000000000000000e+00 * cu_cur_cache_load) / cu_cache_length);

  if ((__idx == 0)) {
    {
      __mem1__ int num_cur_load;
      num_cur_load = 0;
      __mem1__ int beg_to_left;
      beg_to_left = ((2 * cu_cache_length) / 5);
      __mem1__ int cur_to_left;
      cur_to_left = beg_to_left;
      __mem1__ int cur_to_right;
      cur_to_right = cu_cache_length;
      __mem1__ int cur_this;
      cur_this = 0;
      __mem1__ int lg;
      __mem1__ int g;
      for (lg = 0; (lg < cu_cur_cache_load); (lg = (lg + 64))) {
        __mem1__ MAPU_LONG num_read;
        num_read = ((((lg + 64) > cu_cur_cache_load))
                        ? (({ (cu_cur_cache_load - lg); }))
                        : (({ 64; })));

        if (((num_read * 8) * 1)) {
          {
            const size_t data_size = sizeof(
                (((cu_cache + (__idy * (8 * cu_cache_length))) + (lg * 8)))[0]);
            memcpy_async(__pscmc_mapu_internal_block__,
                         ((unsigned *)(local_pos_cache + (0 * 8))),
                         ((__DDR unsigned *)((cu_cache +
                                              (__idy * (8 * cu_cache_length))) +
                                             (lg * 8))),
                         ((uint64_t)(1 * ((num_read * 8) * data_size))),
                         __pscmc_mapu_internal_barrier__);
            (__pscmc_mapu_internal_barrier__).arrive_and_wait();
          }
        }
        for (g = 0; (g < num_read); g++) {
          __mem1__ int gall;
          gall = (g + lg);

          if ((((local_pos_cache + (g * 8)))[2] < 0)) {

            if ((8 * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_pos_cache + (g * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (8 * cu_cache_length))) +
                                        (cur_to_left * 8))),
                    ((unsigned *)(local_pos_cache + (g * 8))),
                    ((uint64_t)(1 * (8 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (cur_to_left = (cur_to_left + 1));

          } else {

            if ((((local_pos_cache + (g * 8)))[2] > ZLEN)) {
              cur_to_right--;

              if ((8 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (8 * cu_cache_length))) +
                                          (cur_to_right * 8))),
                      ((unsigned *)(local_pos_cache + (g * 8))),
                      ((uint64_t)(1 * (8 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                }
              }

            } else {

              if ((8 * 1)) {
                {
                  const size_t data_size =
                      sizeof(((local_pos_cache + (g * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((cu_cache +
                                           (__idy * (8 * cu_cache_length))) +
                                          (cur_this * 8))),
                      ((unsigned *)(local_pos_cache + (g * 8))),
                      ((uint64_t)(1 * (8 * data_size))),
                      __pscmc_mapu_internal_barrier__);
                  (__pscmc_mapu_internal_barrier__).arrive_and_wait();
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
  for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
    __mem1__ MAPU_LONG grid_id;
    grid_id = (__idx + (i * __xlen));

    if ((grid_id < xyzalllen)) {
      {
        __mem1__ int cur_load;
        cur_load = (xyzw)[(4 * (cu_offset + grid_id))];
        __mem1__ double rat;
        rat = ((1.00000000000000000e+00 * cur_load) / grid_cache_len);
        __mem1__ MAPU_LONG bxyzx;
        bxyzx = (grid_id % XLEN);
        __mem1__ MAPU_LONG bxyzy;
        bxyzy = ((grid_id / XLEN) % YLEN);
        __mem1__ MAPU_LONG bxyzz;
        bxyzz = (grid_id / (XLEN * YLEN));
        __mem1__ int g;
        g = 0;
        __mem1__ int lg;
        lg = 0;
        __mem1__ MAPU_LONG plus_offset;
        plus_offset = 0;
        __mem1__ MAPU_LONG minus_offset;
        minus_offset = 0;
        __mem1__ MAPU_LONG left_bound;
        left_bound = bxyzz;
        __mem1__ MAPU_LONG right_bound;
        right_bound = (left_bound + 1);
        __mem1__ int sizeof_double;
        sizeof_double = sizeof(double);
        __mem1__ MAPU_LONG num_write_minus;
        num_write_minus = 0;
        __mem1__ MAPU_LONG num_write_plus;
        num_write_plus = 0;
        __mem1__ MAPU_LONG num_write_main;
        num_write_main = 0;
        __mem1__ MAPU_LONG num_write_tmp;
        num_write_tmp = 0;
        for (lg = 0; (lg < cur_load); (lg = (lg + 64))) {
          __mem1__ MAPU_LONG num_read;
          num_read = ((((lg + 64) > cur_load)) ? (({ (cur_load - lg); }))
                                               : (({ 64; })));

          if (((num_read * 8) * 1)) {
            {
              const size_t data_size = sizeof((
                  ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                   (lg * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((unsigned *)(local_pos_cache + (0 * 8))),
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   8)) +
                                      (lg * 8))),
                  ((uint64_t)(1 * ((num_read * 8) * data_size))),
                  __pscmc_mapu_internal_barrier__);
              (__pscmc_mapu_internal_barrier__).arrive_and_wait();
            }
          }
          {
            {
              __mem1__ MAPU_LONG inner_step;
              for ((inner_step = 0); (inner_step < num_read);
                   (inner_step = (inner_step + 1))) {
                {
                  __mem1__ MAPU_LONG inner_g;
                  for ((inner_g = 0); (inner_g < 3);
                       (inner_g = (inner_g + 1))) {
                    ((local_vel_cache)[((inner_step * 3) + inner_g)] =
                         (((inoutput +
                            (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                           (3 + (lg * 8))))[((inner_step * 8) + inner_g)]);
                  }
                }
              }
            }
          }
          for (g = 0; (g < num_read); g++) {

            if ((((local_pos_cache + (g * 8)))[2] < left_bound)) {

              if (((num_write_tmp * 8) * 1)) {
                {
                  const size_t data_size = sizeof(
                      ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                        grid_cache_len) *
                                                       8)) +
                                          (num_write_main * 8))),
                      ((unsigned *)(local_pos_cache +
                                    ((g - num_write_tmp) * 8))),
                      ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                      put_sync_id);
                }
              }
              (num_write_main = (num_write_main + num_write_tmp));
              (num_write_tmp = 0);
              {
                __mem1__ MAPU_LONG i;
                for ((i = 0); (i < 8); (i = (i + 1))) {
                  (((local_temp_particle_cache_minus +
                     (num_write_minus * 8)))[i] =
                       ((local_pos_cache + (g * 8)))[i]);
                }
              }
              num_write_minus++;

            } else {

              if ((((local_pos_cache + (g * 8)))[2] > right_bound)) {

                if (((num_write_tmp * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            (num_write_main * 8))),
                        ((unsigned *)(local_pos_cache +
                                      ((g - num_write_tmp) * 8))),
                        ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                        put_sync_id);
                  }
                }
                (num_write_main = (num_write_main + num_write_tmp));
                (num_write_tmp = 0);
                {
                  __mem1__ MAPU_LONG i;
                  for ((i = 0); (i < 8); (i = (i + 1))) {
                    (((local_temp_particle_cache_plus +
                       (num_write_plus * 8)))[i] =
                         ((local_pos_cache + (g * 8)))[i]);
                  }
                }
                num_write_plus++;

              } else {

                if (((((local_vel_cache)[((g * 3) + 0)] *
                       (local_vel_cache)[((g * 3) + 0)]) +
                      (((local_vel_cache)[((g * 3) + 1)] *
                        (local_vel_cache)[((g * 3) + 1)]) +
                       ((local_vel_cache)[((g * 3) + 2)] *
                        (local_vel_cache)[((g * 3) + 2)]))) >
                     1.00000000000000000e+00)) {

                  if (((num_write_tmp * 8) * 1)) {
                    {
                      const size_t data_size = sizeof(
                          ((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
                      memcpy_async(
                          __pscmc_mapu_internal_block__,
                          ((__DDR unsigned *)((inoutput +
                                               (((cu_offset + grid_id) *
                                                 grid_cache_len) *
                                                8)) +
                                              (num_write_main * 8))),
                          ((unsigned *)(local_pos_cache +
                                        ((g - num_write_tmp) * 8))),
                          ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                          put_sync_id);
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
          if (((num_write_tmp * 8) * 1)) {
            {
              const size_t data_size =
                  sizeof(((local_pos_cache + ((g - num_write_tmp) * 8)))[0]);
              memcpy_async(
                  __pscmc_mapu_internal_block__,
                  ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                    grid_cache_len) *
                                                   8)) +
                                      (num_write_main * 8))),
                  ((unsigned *)(local_pos_cache + ((g - num_write_tmp) * 8))),
                  ((uint64_t)(1 * ((num_write_tmp * 8) * data_size))),
                  put_sync_id);
            }
          }
          (num_write_main = (num_write_main + num_write_tmp));
          (num_write_tmp = 0);
          (put_sync_id).arrive_and_wait();
          (get_sync_id).arrive_and_wait();
        }
        __mem1__ int x_main;
        x_main = num_write_main;
        __mem1__ int x_beg_minus;
        x_beg_minus = x_main;
        __mem1__ int x_beg_plus;
        x_beg_plus =
            (((grid_cache_len - cur_load) / 2) + (num_write_minus + x_main));
        __mem0__ int xm4[4];
        ((xm4)[0] = x_main);
        ((xm4)[1] = (num_write_minus + x_main));
        ((xm4)[2] = x_beg_plus);
        ((xm4)[3] = (num_write_plus + x_beg_plus));

        if ((4 * 1)) {
          {
            const size_t data_size = sizeof((xm4)[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)(xyzw + (4 * (cu_offset + grid_id)))),
                ((unsigned *)xm4), ((uint64_t)(1 * (4 * data_size))),
                put_sync_id);
          }
        }

        if (((8 * num_write_minus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      8)) +
                                    (x_beg_minus * 8))),
                ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                ((uint64_t)(1 * ((8 * num_write_minus) * data_size))),
                put_sync_id);
          }
        }

        if (((xm4)[3] > grid_cache_len)) {
          {
            __mem1__ MAPU_LONG i;
            i = 0;
            for (i = 0; (i < 4); i++) {
            }
          }
        }

        if (((8 * num_write_plus) * 1)) {
          {
            const size_t data_size =
                sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
            memcpy_async(
                __pscmc_mapu_internal_block__,
                ((__DDR unsigned *)((inoutput +
                                     (((cu_offset + grid_id) * grid_cache_len) *
                                      8)) +
                                    (x_beg_plus * 8))),
                ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                ((uint64_t)(1 * ((8 * num_write_plus) * data_size))),
                put_sync_id);
          }
        }
        (put_sync_id).arrive_and_wait();
      }
    }
  }
  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzz == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzz == (ZLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof((
                        (xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) +
                                 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) -
                                                   (XLEN * YLEN))) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((8 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_minus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((uint64_t)(1 * ((8 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((8 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                          ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) *
                           8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 8))),
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            ((beg_plus - ((XLEN * YLEN) *
                                                          grid_cache_len)) *
                                             8))),
                        ((uint64_t)(1 * ((8 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 8) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                    ((uint64_t)(1 * ((num_from_left * 8) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 ((beg_plus * 8) -
                                  ((XLEN * YLEN) * (grid_cache_len * 8))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 8))),
                        ((uint64_t)(1 * ((num_to_left * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset +
                                                   (grid_id - (XLEN * YLEN)))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((8 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (8 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (8 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 (8 * cur_beg_plus)) +
                                (__pscmc_cpnum * (8 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                                   (8 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((uint64_t)((8 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((8 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 8)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     8))) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((8 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_plus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_plus * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_x_vlo_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = XLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(0 + (real_p * 8))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 8); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN102;
    MYGEN102 = (num_write_plus * 8);
    for (0; (MYGEN102 > 0); (MYGEN102 = (MYGEN102 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN102 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (8 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
        8));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_x_vlo_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 8)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 8)];
  __mem0__ double local_pos_cache[(64 * 8)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  if ((4 * 1)) {
    {
      const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
      memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)cu_xyzw_shared),
                   ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                   ((uint64_t)(1 * (4 * data_size))),
                   __pscmc_mapu_internal_barrier__);
      (__pscmc_mapu_internal_barrier__).arrive_and_wait();
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzx == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzx == (XLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(
                        ((xyzw + ((4 * ((cu_offset + grid_id) - 1)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) - 1)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((8 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_minus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((uint64_t)(1 * ((8 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((8 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                          ((beg_plus - (1 * grid_cache_len)) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 8))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 ((beg_plus - (1 * grid_cache_len)) * 8))),
                        ((uint64_t)(1 * ((8 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 8) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                    ((uint64_t)(1 * ((num_from_left * 8) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            ((beg_plus * 8) -
                                             (1 * (grid_cache_len * 8))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 8))),
                        ((uint64_t)(1 * ((num_to_left * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + (grid_id - 1))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((8 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (8 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (8 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 (8 * cur_beg_plus)) +
                                (__pscmc_cpnum * (8 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                                   (8 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((uint64_t)((8 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((8 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 8)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     8))) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((8 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_plus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_plus * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_y_vlo_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = YLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(1 + (real_p * 8))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 8); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN107;
    MYGEN107 = (num_write_plus * 8);
    for (0; (MYGEN107 > 0); (MYGEN107 = (MYGEN107 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN107 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (8 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
        8));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_y_vlo_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 8)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 8)];
  __mem0__ double local_pos_cache[(64 * 8)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  if ((4 * 1)) {
    {
      const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
      memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)cu_xyzw_shared),
                   ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                   ((uint64_t)(1 * (4 * data_size))),
                   __pscmc_mapu_internal_barrier__);
      (__pscmc_mapu_internal_barrier__).arrive_and_wait();
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzy == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzy == (YLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof(((
                        xyzw + ((4 * ((cu_offset + grid_id) - XLEN)) + 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 *
                                              ((cu_offset + grid_id) - XLEN)) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((8 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_minus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((uint64_t)(1 * ((8 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((8 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                          ((beg_plus - (XLEN * grid_cache_len)) * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 8))),
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 ((beg_plus - (XLEN * grid_cache_len)) * 8))),
                        ((uint64_t)(1 * ((8 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 8) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                    ((uint64_t)(1 * ((num_from_left * 8) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            ((beg_plus * 8) -
                                             (XLEN * (grid_cache_len * 8))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 8))),
                        ((uint64_t)(1 * ((num_to_left * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw + ((4 * (cu_offset +
                                                          (grid_id - XLEN))) +
                                                    2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((8 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (8 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (8 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 (8 * cur_beg_plus)) +
                                (__pscmc_cpnum * (8 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                                   (8 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((uint64_t)((8 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((8 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 8)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     8))) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((8 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_plus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_plus * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}

#ifdef IDX_LOCAL_XLEN
#undef IDX_LOCAL_XLEN
#endif
#define IDX_LOCAL_XLEN 32
__global__ void mapu_gpu_sort_one_grid_z_vlo_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ int cu_cur_cache_load;
  cu_cur_cache_load = (cu_xyzw)[(4 * __idy)];
  __mem1__ __DDR double *for_sort_grid_memory_left;
  for_sort_grid_memory_left =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((2 * cu_cache_length) / 5))));
  __mem1__ __DDR double *for_sort_grid_memory_right;
  for_sort_grid_memory_right =
      (cu_cache +
       (8 * ((__idy * cu_cache_length) + ((7 * cu_cache_length) / 10))));
  __mem1__ __DDR double *cu_cache_head;
  cu_cache_head = (cu_cache + (8 * (__idy * cu_cache_length)));
  __mem1__ int cur_load;
  cur_load = cu_cur_cache_load;
  __mem1__ int g;
  g = 0;
  __mem1__ int lg;
  lg = 0;
  __mem1__ MAPU_LONG plus_offset;
  plus_offset = 0;
  __mem1__ MAPU_LONG minus_offset;
  minus_offset = 0;
  __mem1__ MAPU_LONG left_bound;
  left_bound = 0;
  __mem1__ MAPU_LONG right_bound;
  right_bound = ZLEN;
  __mem1__ int sizeof_double;
  sizeof_double = sizeof(double);
  __mem1__ MAPU_LONG num_write_minus;
  num_write_minus = 0;
  __mem1__ MAPU_LONG num_write_plus;
  num_write_plus = 0;
  __mem1__ MAPU_LONG num_write_main;
  num_write_main = 0;
  __mem1__ MAPU_LONG num_write_tmp;
  num_write_tmp = 0;
  for (lg = 0; (lg < cur_load); (lg = (lg + (__xlen * __xlen)))) {
    __mem1__ int cur_grid_num;
    cur_grid_num = 0;
    __mem1__ int to_left_num;
    to_left_num = 0;
    __mem1__ int to_right_num;
    to_right_num = 0;
    __mem0__ int cgn_shared[IDX_LOCAL_XLEN];
    __mem0__ int tln_shared[IDX_LOCAL_XLEN];
    __mem0__ int trn_shared[IDX_LOCAL_XLEN];
    {
      __mem1__ MAPU_LONG p;
      for ((p = (lg + (__idx * __xlen)));
           (p < (lg + ((__idx * __xlen) + __xlen))); (p = (p + 1))) {
        __mem1__ int real_p;
        real_p = p;
        __mem1__ int local_p_id;
        local_p_id = (p - (lg + (__idx * __xlen)));
        __mem1__ int if_exist_particle;
        if_exist_particle = (real_p < cur_load);
        __mem1__ double particle_sort_key_element;
        particle_sort_key_element =
            ((if_exist_particle) ? (({ (cu_cache_head)[(2 + (real_p * 8))]; }))
                                 : (({ -1; })));
        __mem1__ int is_to_left;
        is_to_left = (particle_sort_key_element < left_bound);
        __mem1__ int is_to_right;
        is_to_right = (particle_sort_key_element > right_bound);
        __mem1__ int is_cur;
        is_cur = ((!is_to_right) && (!is_to_left));
        (is_to_left = (if_exist_particle && is_to_left));
        (is_to_right = (if_exist_particle && is_to_right));
        (is_cur = (if_exist_particle && is_cur));
        {
          __mem1__ MAPU_LONG i;
          for ((i = 0); (i < 8); (i = (i + 1))) {

            if (is_to_left) {
              {
                ((for_sort_grid_memory_left)[(
                     i + (8 * ((__idx * (__xlen * 1)) + (to_left_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_to_right) {
              {
                ((for_sort_grid_memory_right)[(
                     i +
                     (8 * ((__idx * (__xlen * 1)) + (to_right_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }

            if (is_cur) {
              {
                ((cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                            (cur_grid_num + lg))))] =
                     (cu_cache_head)[(i + (8 * ((__idx * (__xlen * 1)) +
                                                (local_p_id + lg))))]);
              }
            }
          }
        }
        if (is_cur) {
          {
            (cur_grid_num = (cur_grid_num + 1));
          }
        }

        if (is_to_left) {
          {
            (to_left_num = (to_left_num + 1));
          }
        }

        if (is_to_right) {
          {
            (to_right_num = (to_right_num + 1));
          }
        }
      }
    }
    ((cgn_shared)[__idx] = cur_grid_num);
    ((tln_shared)[__idx] = to_left_num);
    ((trn_shared)[__idx] = to_right_num);
    __mem1__ MAPU_LONG p;
    p = 0;
    for (p = 0; (p < (__xlen * __xlen)); (p = (p + __xlen))) {

      if ((((cgn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((cu_cache_head)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_main)))])),
              ((__DDR unsigned *)&((cu_cache_head)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((cgn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_main = (num_write_main + (cgn_shared)[(p / __xlen)]));

      if ((((tln_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_left)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_left)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((tln_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_minus = (num_write_minus + (tln_shared)[(p / __xlen)]));

      if ((((trn_shared)[(p / __xlen)] * 8) * 1)) {
        {
          const size_t data_size = sizeof((&((for_sort_grid_memory_right)[(
              0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))]))[0]);
          memcpy_async(
              __pscmc_mapu_internal_block__,
              ((unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + num_write_plus)))])),
              ((__DDR unsigned *)&((for_sort_grid_memory_right)[(
                  0 + (8 * ((__idx * (__xlen * 0)) + (lg + p))))])),
              ((uint64_t)(1 * (((trn_shared)[(p / __xlen)] * 8) * data_size))),
              __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
      (num_write_plus = (num_write_plus + (trn_shared)[(p / __xlen)]));
    }
  }
  {
    __mem1__ MAPU_LONG MYGEN112;
    MYGEN112 = (num_write_plus * 8);
    for (0; (MYGEN112 > 0); (MYGEN112 = (MYGEN112 + -__xlen))) {
      __mem1__ int ridx;
      ridx = (MYGEN112 + (__idx + -__xlen));

      if ((ridx >= 0)) {
        {
          ((&((cu_cache_head)[(
               0 + (8 * ((__idx * (__xlen * 0)) +
                         (cu_cache_length - num_write_plus))))]))[ridx] =
               (&((for_sort_grid_memory_right)[(
                   0 + (8 * ((__idx * (__xlen * 0)) + 0)))]))[ridx]);
        }
      }
    }
  }
  __mem0__ int xm4[4];
  ((xm4)[0] = num_write_main);
  ((xm4)[1] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + 0)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[2] = ((&((for_sort_grid_memory_left)[(
                    0 + (8 * ((__idx * (__xlen * 0)) + num_write_minus)))]) -
                &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
               8));
  ((xm4)[3] =
       ((&((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) +
                                      (cu_cache_length - num_write_plus))))]) -
         &((cu_cache_head)[(0 + (8 * ((__idx * (__xlen * 0)) + 0)))])) /
        8));

  if ((__idx == 0)) {
    {

      if (((4 * 1) > 0)) {
        {
          __mem0__ double __tmp_array[4096];
          __mem1__ MAPU_LONG __pscmc_cpnum;
          __pscmc_cpnum = 0;
          __mem1__ MAPU_LONG __pscmc_one_copy;
          __pscmc_one_copy = (4096 / 4);
          for (0; (__pscmc_cpnum < 1);
               (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
            __mem1__ MAPU_LONG cp_size;
            cp_size = __pscmc_one_copy;

            if (((cp_size + __pscmc_cpnum) > 1)) {
              {
                (cp_size = (1 - __pscmc_cpnum));
              }
            }

            if ((cp_size * 4)) {
              {
                const size_t data_size =
                    sizeof(((xm4 + (__pscmc_cpnum * 4)))[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((unsigned *)__tmp_array),
                             ((__DDR unsigned *)(xm4 + (__pscmc_cpnum * 4))),
                             ((uint64_t)(4 * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if ((cp_size * (4 * 1))) {
              {
                const size_t data_size = sizeof((__tmp_array)[0]);
                memcpy_async(__pscmc_mapu_internal_block__,
                             ((__DDR unsigned *)((cu_xyzw + (4 * __idy)) +
                                                 (__pscmc_cpnum * 4))),
                             ((unsigned *)__tmp_array),
                             ((uint64_t)((4 * 1) * (cp_size * data_size))),
                             __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_sort_one_grid_z_vlo_8(
    __DDR double *inoutput, __DDR int *xyzw, __DDR double *cu_cache,
    __DDR int *cu_xyzw, __DDR MAPU_LONG *adjoint_vec_pids, MAPU_LONG XLEN,
    MAPU_LONG YLEN, MAPU_LONG ZLEN, int ovlp, MAPU_LONG numvec,
    MAPU_LONG grid_cache_len, MAPU_LONG cu_cache_length) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  __mem1__ MAPU_LONG cu_offset;
  cu_offset = (__idy * (XLEN * (YLEN * ZLEN)));
  __mem1__ MAPU_LONG xyzalllen;
  xyzalllen = (XLEN * (YLEN * ZLEN));
  __shared__ barrier_t get_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __shared__ barrier_t put_sync_id;

  if ((threadIdx.x == 0)) {
    {
      init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
    }
  }
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem0__ double local_temp_particle_cache_plus[(384 * 8)];
  __mem0__ double local_temp_particle_cache_minus[(384 * 8)];
  __mem0__ double local_pos_cache[(64 * 8)];
  __mem0__ double local_vel_cache[192];
  __mem0__ int cu_xyzw_shared[4];
  if ((4 * 1)) {
    {
      const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
      memcpy_async(__pscmc_mapu_internal_block__, ((unsigned *)cu_xyzw_shared),
                   ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                   ((uint64_t)(1 * (4 * data_size))),
                   __pscmc_mapu_internal_barrier__);
      (__pscmc_mapu_internal_barrier__).arrive_and_wait();
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            __mem0__ int cur_zw[2];
            __mem0__ int prev_zw[2];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))), get_sync_id);
              }
            }
            __mem1__ MAPU_LONG bxyzx;
            bxyzx = (grid_id % XLEN);
            __mem1__ MAPU_LONG bxyzy;
            bxyzy = ((grid_id / XLEN) % YLEN);
            __mem1__ MAPU_LONG bxyzz;
            bxyzz = (grid_id / (XLEN * YLEN));
            __mem1__ int is_most_left;
            is_most_left = (bxyzz == 0);
            __mem1__ int is_most_right;
            is_most_right = (bxyzz == (ZLEN - 1));

            if (is_most_left) {
              {
                ((prev_zw)[0] = grid_cache_len);
                ((prev_zw)[1] = grid_cache_len);
              }
            } else {
              {

                if ((1 * 2)) {
                  {
                    const size_t data_size = sizeof((
                        (xyzw + ((4 * ((cu_offset + grid_id) - (XLEN * YLEN))) +
                                 2)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__, ((unsigned *)prev_zw),
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * ((cu_offset + grid_id) -
                                                   (XLEN * YLEN))) +
                                             2))),
                        ((uint64_t)(2 * (1 * data_size))), get_sync_id);
                  }
                }
              }
            }
            (get_sync_id).arrive_and_wait();
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int end_minus;
            end_minus = (cur_xyzw)[1];
            __mem1__ int minus_max;
            minus_max = (cur_xyzw)[2];
            __mem1__ int beg_plus;
            beg_plus = (prev_zw)[0];
            __mem1__ int end_plus;
            end_plus = (prev_zw)[1];
            __mem1__ int num_to_left;
            num_to_left = (end_minus - beg_minus);
            __mem1__ int num_from_left;
            num_from_left = (end_plus - beg_plus);
            __mem1__ int num_cur_remains;
            num_cur_remains = (minus_max - beg_minus);
            __mem1__ int num_left_remains;
            num_left_remains = (grid_cache_len - beg_plus);

#if 0    
                        __mem1__ MAPU_LONG  j;
                        j = 0;

                        if (((bxyzx == 1) && (bxyzy == 1))) {
                            {
                                fprintf(stderr, "idy=%d x=[%d %d %d] main_load=%d cur_rem=%d ", __idy, bxyzx, bxyzy, bxyzz, beg_minus, num_cur_remains);
                                for (j; (j < beg_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d left_load=%d ", bxyzx, (end_minus - beg_minus));
                                for (j = beg_minus; (j < end_minus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                                fprintf(stderr, "x=%d right_load=%d ", bxyzx, (end_plus - beg_plus));
                                for (j = beg_plus; (j < end_plus); j++)
                                {
                                    fprintf(stderr, "%e ", ((inoutput + (((cu_offset + grid_id) * grid_cache_len) * 8)))[(j * 8)]);
                                }	fprintf(stderr, "\n");
                            }
                        }

#else

#endif

            if (((8 * num_to_left) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_minus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((uint64_t)(1 * ((8 * num_to_left) * data_size))),
                    get_sync_id);
              }
            }

            if (num_from_left) {
              {

                if (((8 * num_from_left) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        (((inoutput +
                           (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                          ((beg_plus - ((XLEN * YLEN) * grid_cache_len)) *
                           8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (0 * 8))),
                        ((__DDR unsigned *)((inoutput +
                                             (((cu_offset + grid_id) *
                                               grid_cache_len) *
                                              8)) +
                                            ((beg_plus - ((XLEN * YLEN) *
                                                          grid_cache_len)) *
                                             8))),
                        ((uint64_t)(1 * ((8 * num_from_left) * data_size))),
                        get_sync_id);
                  }
                }
              }
            }
            __mem1__ int num_left_to_cu_cache;
            num_left_to_cu_cache =
                (((num_cur_remains < num_from_left))
                     ? (({ (num_from_left - num_cur_remains); }))
                     : (({ 0; })));
            __mem1__ int num_cur_to_cu_cache;
            num_cur_to_cu_cache =
                (((num_left_remains < num_to_left))
                     ? (({ (num_to_left - num_left_remains); }))
                     : (({ 0; })));
            (num_from_left = (((num_cur_remains < num_from_left))
                                  ? (({ num_cur_remains; }))
                                  : (({ num_from_left; }))));
            (num_to_left =
                 (((num_left_remains < num_to_left)) ? (({ num_left_remains; }))
                                                     : (({ num_to_left; }))));
            (get_sync_id).arrive_and_wait();

            if (((num_from_left * 8) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_plus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_plus + (0 * 8))),
                    ((uint64_t)(1 * ((num_from_left * 8) * data_size))),
                    put_sync_id);
              }
            }

            if (num_to_left) {
              {

                if (((num_to_left * 8) * 1)) {
                  {
                    const size_t data_size = sizeof(
                        ((local_temp_particle_cache_minus + (0 * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned
                              *)((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 ((beg_plus * 8) -
                                  ((XLEN * YLEN) * (grid_cache_len * 8))))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (0 * 8))),
                        ((uint64_t)(1 * ((num_to_left * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_left_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = (cu_xyzw_shared)[0];
                  ((cu_xyzw_shared)[0] =
                       ((cu_xyzw_shared)[0] + num_left_to_cu_cache));
                  tmp0123212663;
                });

                if (((num_left_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_plus +
                                 (num_from_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_plus +
                                      (num_from_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_left_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }

            if (num_cur_to_cu_cache) {
              {
                __mem1__ int cur_cu_cache_load;

                if (is_most_left) {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = ((cu_xyzw_shared + 2))[0];
                       (((cu_xyzw_shared + 2))[0] =
                            (((cu_xyzw_shared + 2))[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                } else {
                  {
                    (cur_cu_cache_load = ({
                       __mem1__ int tmp0123212663;
                       tmp0123212663 = (cu_xyzw_shared)[0];
                       ((cu_xyzw_shared)[0] =
                            ((cu_xyzw_shared)[0] + num_cur_to_cu_cache));
                       tmp0123212663;
                     }));
                  }
                }

                if (((num_cur_to_cu_cache * 8) * 1)) {
                  {
                    const size_t data_size =
                        sizeof(((local_temp_particle_cache_minus +
                                 (num_to_left * 8)))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(cu_cache +
                                            ((__idy * (cu_cache_length * 8)) +
                                             (cur_cu_cache_load * 8)))),
                        ((unsigned *)(local_temp_particle_cache_minus +
                                      (num_to_left * 8))),
                        ((uint64_t)(1 *
                                    ((num_cur_to_cu_cache * 8) * data_size))),
                        put_sync_id);
                  }
                }
              }
            }
            (beg_minus = (beg_minus + num_from_left));
            ((cur_xyzw)[0] = beg_minus);
            ((cur_xyzw)[1] = beg_minus);
            ((prev_zw)[1] = (beg_plus + num_to_left));

            if ((2 * 1)) {
              {
                const size_t data_size = sizeof((cur_xyzw)[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((unsigned *)cur_xyzw), ((uint64_t)(1 * (2 * data_size))),
                    put_sync_id);
              }
            }

            if ((!is_most_left)) {
              {

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof((prev_zw)[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset +
                                                   (grid_id - (XLEN * YLEN)))) +
                                             2))),
                        ((unsigned *)prev_zw),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }

            if (is_most_right) {
              {
                __mem1__ int cur_beg_plus;
                cur_beg_plus = (cur_xyzw)[2];
                __mem1__ int cur_end_plus;
                cur_end_plus = (cur_xyzw)[3];
                __mem1__ int cur_to_cu_cache;
                cur_to_cu_cache = (cur_end_plus - cur_beg_plus);
                __mem1__ int cur_cu_cache_load;
                cur_cu_cache_load = ({
                  __mem1__ int tmp0123212663;
                  tmp0123212663 = ((cu_xyzw_shared + 3))[0];
                  (((cu_xyzw_shared + 3))[0] =
                       (((cu_xyzw_shared + 3))[0] + -(cur_to_cu_cache)));
                  tmp0123212663;
                });
                ((cur_xyzw)[2] = beg_minus);
                ((cur_xyzw)[3] = beg_minus);
                (put_sync_id).arrive_and_wait();

                if ((((8 * cur_to_cu_cache) * 1) > 0)) {
                  {
                    __mem0__ double __tmp_array[4096];
                    __mem1__ MAPU_LONG __pscmc_cpnum;
                    __pscmc_cpnum = 0;
                    __mem1__ MAPU_LONG __pscmc_one_copy;
                    __pscmc_one_copy = (4096 / (8 * cur_to_cu_cache));
                    for (0; (__pscmc_cpnum < 1);
                         (__pscmc_cpnum = (__pscmc_cpnum + __pscmc_one_copy))) {
                      __mem1__ MAPU_LONG cp_size;
                      cp_size = __pscmc_one_copy;

                      if (((cp_size + __pscmc_cpnum) > 1)) {
                        {
                          (cp_size = (1 - __pscmc_cpnum));
                        }
                      }

                      if ((cp_size * (8 * cur_to_cu_cache))) {
                        {
                          const size_t data_size = sizeof(
                              ((((inoutput +
                                  (((cu_offset + grid_id) * grid_cache_len) *
                                   8)) +
                                 (8 * cur_beg_plus)) +
                                (__pscmc_cpnum * (8 * cur_to_cu_cache))))[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((unsigned *)__tmp_array),
                              ((__DDR unsigned *)(((inoutput +
                                                    (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                                   (8 * cur_beg_plus)) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((uint64_t)((8 * cur_to_cu_cache) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }

                      if ((cp_size * ((8 * cur_to_cu_cache) * 1))) {
                        {
                          const size_t data_size = sizeof((__tmp_array)[0]);
                          memcpy_async(
                              __pscmc_mapu_internal_block__,
                              ((__DDR unsigned *)((cu_cache +
                                                   ((__idy *
                                                     (cu_cache_length * 8)) +
                                                    ((cur_cu_cache_load -
                                                      cur_to_cu_cache) *
                                                     8))) +
                                                  (__pscmc_cpnum *
                                                   (8 * cur_to_cu_cache)))),
                              ((unsigned *)__tmp_array),
                              ((uint64_t)(((8 * cur_to_cu_cache) * 1) *
                                          (cp_size * data_size))),
                              __pscmc_mapu_internal_barrier__);
                          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
                        }
                      }
                    }
                  }
                }

                if ((2 * 1)) {
                  {
                    const size_t data_size = sizeof(((cur_xyzw + 2))[0]);
                    memcpy_async(
                        __pscmc_mapu_internal_block__,
                        ((__DDR unsigned *)(xyzw +
                                            ((4 * (cu_offset + grid_id)) + 2))),
                        ((unsigned *)(cur_xyzw + 2)),
                        ((uint64_t)(1 * (2 * data_size))), put_sync_id);
                  }
                }
              }
            }
            (put_sync_id).arrive_and_wait();
          }
        }
      }
    }
  }

  if ((__idx == 0)) {
    {

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof((cu_xyzw_shared)[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((unsigned *)cu_xyzw_shared),
                       ((uint64_t)(1 * (4 * data_size))),
                       __pscmc_mapu_internal_barrier__);
          (__pscmc_mapu_internal_barrier__).arrive_and_wait();
        }
      }
    }
  }

  if (1) {
    {
      for (i = 0; ((__idx + (i * __xlen)) < xyzalllen); i++) {
        __mem1__ MAPU_LONG grid_id;
        grid_id = (__idx + (i * __xlen));

        if ((grid_id < xyzalllen)) {
          {
            __mem0__ int cur_xyzw[4];
            if ((1 * 4)) {
              {
                const size_t data_size =
                    sizeof(((xyzw + ((4 * (cu_offset + grid_id)) + 0)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__, ((unsigned *)cur_xyzw),
                    ((__DDR unsigned *)(xyzw +
                                        ((4 * (cu_offset + grid_id)) + 0))),
                    ((uint64_t)(4 * (1 * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int beg_minus;
            beg_minus = (cur_xyzw)[0];
            __mem1__ int beg_plus;
            beg_plus = (cur_xyzw)[2];
            __mem1__ int end_plus;
            end_plus = (cur_xyzw)[3];
            __mem1__ int pluslen;
            pluslen = (end_plus - beg_plus);
            __mem1__ int load0;
            load0 = (beg_minus + pluslen);
            ((xyzw)[(4 * (cu_offset + grid_id))] = load0);

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof((((inoutput +
                              (((cu_offset + grid_id) * grid_cache_len) * 8)) +
                             (beg_plus * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_plus * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }

            if (((8 * pluslen) * 1)) {
              {
                const size_t data_size =
                    sizeof(((local_temp_particle_cache_minus + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((inoutput + (((cu_offset + grid_id) *
                                                      grid_cache_len) *
                                                     8)) +
                                        (beg_minus * 8))),
                    ((unsigned *)(local_temp_particle_cache_minus + (0 * 8))),
                    ((uint64_t)(1 * ((8 * pluslen) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
          }
        }
      }
    }
  }

#endif
}
__global__ void mapu_cu_swap_l_6(__DDR double *cu_cache, __DDR int *cu_xyzw,
                                 __DDR MAPU_LONG *adjoint_vec_pids,
                                 MAPU_LONG cu_cache_length, int the_dir_num,
                                 MAPU_LONG XYZLEN) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  if ((__idx == 0)) {
    {
      __mem0__ int cu_xyzw_shared[4];
      __mem0__ MAPU_LONG adjoint_vec_pids_shared[2];
      __shared__ barrier_t get_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }
      __shared__ barrier_t put_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }

      if ((2 * 1)) {
        {
          const size_t data_size = sizeof(
              ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)adjoint_vec_pids_shared),
                       ((__DDR unsigned *)(adjoint_vec_pids +
                                           ((6 * __idy) + (2 * the_dir_num)))),
                       ((uint64_t)(1 * (2 * data_size))), get_sync_id);
        }
      }

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)cu_xyzw_shared),
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((uint64_t)(1 * (4 * data_size))), get_sync_id);
        }
      }
      (get_sync_id).arrive_and_wait();
      __mem1__ MAPU_LONG left_pid;
      left_pid = (adjoint_vec_pids_shared)[0];
      __mem1__ int beg_left_par;
      beg_left_par = (cu_xyzw_shared)[1];
      __mem1__ int end_left_par;
      end_left_par = (cu_xyzw_shared)[2];

#if 0    
            fprintf(stderr, "id=%d left_pid=%d lr=l\n", __idy, left_pid);
            fprintf(stderr, "lr=l, __idy=%d, lpid=%d sdl=%d\n", __idy, left_pid, (end_left_par - beg_left_par));

#else

#endif

      if ((1 && ((left_pid != -1) && (beg_left_par != end_left_par)))) {
        {
          __mem1__ int end_cu_par;
          end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];
          __mem1__ int new_left_par;
          new_left_par = (end_cu_par + (end_left_par - beg_left_par));

          if ((1 * 1)) {
            {
              const size_t data_size = sizeof((&(new_left_par))[0]);
              memcpy_async(__pscmc_mapu_internal_block__,
                           ((__DDR unsigned *)(cu_xyzw + (4 * left_pid))),
                           ((unsigned *)&(new_left_par)),
                           ((uint64_t)(1 * (1 * data_size))), put_sync_id);
            }
          }

          if (1) {
            {
              __mem0__ int al1[2];
              ((al1)[0] = (cu_xyzw_shared)[3]);
              ((al1)[1] = (cu_xyzw_shared)[3]);

              if ((2 * 1)) {
                {
                  const size_t data_size = sizeof((al1)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)(cu_xyzw + ((4 * __idy) + 1))),
                      ((unsigned *)al1), ((uint64_t)(1 * (2 * data_size))),
                      put_sync_id);
                }
              }
            }
          }
          __mem0__ double local_cache[(384 * 6)];
          __mem1__ int i;
          for ((i = beg_left_par); (i < end_left_par); (i = (i + 384))) {
            __mem1__ int num_cp;
            num_cp = ((((i + 384) > end_left_par)) ? (({ (end_left_par - i); }))
                                                   : (({ 384; })));

            if (((6 * num_cp) * 1)) {
              {
                const size_t data_size =
                    sizeof((((cu_cache + (__idy * (6 * cu_cache_length))) +
                             (6 * i)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_cache + (0 * 6))),
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (6 * cu_cache_length))) +
                                        (6 * i))),
                    ((uint64_t)(1 * ((6 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int ii;
            for ((ii = 0); (ii < num_cp); ii++) {
              (((local_cache + (ii * 6)))[the_dir_num] =
                   (((local_cache + (ii * 6)))[the_dir_num] + XYZLEN));
            }
            if (((6 * num_cp) * 1)) {
              {
                const size_t data_size = sizeof(((local_cache + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (left_pid * (6 * cu_cache_length))) +
                                        (6 * end_cu_par))),
                    ((unsigned *)(local_cache + (0 * 6))),
                    ((uint64_t)(1 * ((6 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (end_cu_par = (end_cu_par + num_cp));
          }
          (put_sync_id).arrive_and_wait();
        }
      }
    }
  }

#endif
}
__global__ void mapu_cu_swap_r_6(__DDR double *cu_cache, __DDR int *cu_xyzw,
                                 __DDR MAPU_LONG *adjoint_vec_pids,
                                 MAPU_LONG cu_cache_length, int the_dir_num,
                                 MAPU_LONG XYZLEN) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  if ((__idx == 0)) {
    {
      __mem0__ int cu_xyzw_shared[4];
      __mem0__ MAPU_LONG adjoint_vec_pids_shared[2];
      __shared__ barrier_t get_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }
      __shared__ barrier_t put_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }

      if ((2 * 1)) {
        {
          const size_t data_size = sizeof(
              ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)adjoint_vec_pids_shared),
                       ((__DDR unsigned *)(adjoint_vec_pids +
                                           ((6 * __idy) + (2 * the_dir_num)))),
                       ((uint64_t)(1 * (2 * data_size))), get_sync_id);
        }
      }

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)cu_xyzw_shared),
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((uint64_t)(1 * (4 * data_size))), get_sync_id);
        }
      }
      (get_sync_id).arrive_and_wait();
      __mem1__ MAPU_LONG left_pid;
      left_pid = (adjoint_vec_pids_shared)[1];
      __mem1__ int beg_left_par;
      beg_left_par = (cu_xyzw_shared)[3];
      __mem1__ MAPU_LONG end_left_par;
      end_left_par = cu_cache_length;

#if 0    
            fprintf(stderr, "id=%d left_pid=%d lr=r\n", __idy, left_pid);
            fprintf(stderr, "lr=r, __idy=%d, lpid=%d sdl=%d\n", __idy, left_pid, (end_left_par - beg_left_par));

#else

#endif

      if ((1 && ((left_pid != -1) && (beg_left_par != end_left_par)))) {
        {
          __mem1__ int end_cu_par;
          end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];
          __mem1__ int new_left_par;
          new_left_par = (end_cu_par + (end_left_par - beg_left_par));

          if ((1 * 1)) {
            {
              const size_t data_size = sizeof((&(new_left_par))[0]);
              memcpy_async(__pscmc_mapu_internal_block__,
                           ((__DDR unsigned *)(cu_xyzw + (4 * left_pid))),
                           ((unsigned *)&(new_left_par)),
                           ((uint64_t)(1 * (1 * data_size))), put_sync_id);
            }
          }

          if (1) {
            {
              __mem0__ int al1[2];
              ((al1)[0] = cu_cache_length);

              if ((1 * 1)) {
                {
                  const size_t data_size = sizeof((al1)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)(cu_xyzw + ((4 * __idy) + 3))),
                      ((unsigned *)al1), ((uint64_t)(1 * (1 * data_size))),
                      put_sync_id);
                }
              }
            }
          }
          __mem0__ double local_cache[(384 * 6)];
          __mem1__ int i;
          for ((i = beg_left_par); (i < end_left_par); (i = (i + 384))) {
            __mem1__ int num_cp;
            num_cp = ((((i + 384) > end_left_par)) ? (({ (end_left_par - i); }))
                                                   : (({ 384; })));

            if (((6 * num_cp) * 1)) {
              {
                const size_t data_size =
                    sizeof((((cu_cache + (__idy * (6 * cu_cache_length))) +
                             (6 * i)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_cache + (0 * 6))),
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (6 * cu_cache_length))) +
                                        (6 * i))),
                    ((uint64_t)(1 * ((6 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int ii;
            for ((ii = 0); (ii < num_cp); ii++) {
              (((local_cache + (ii * 6)))[the_dir_num] =
                   (((local_cache + (ii * 6)))[the_dir_num] + XYZLEN));
            }
            if (((6 * num_cp) * 1)) {
              {
                const size_t data_size = sizeof(((local_cache + (0 * 6)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (left_pid * (6 * cu_cache_length))) +
                                        (6 * end_cu_par))),
                    ((unsigned *)(local_cache + (0 * 6))),
                    ((uint64_t)(1 * ((6 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (end_cu_par = (end_cu_par + num_cp));
          }
          (put_sync_id).arrive_and_wait();
        }
      }
    }
  }

#endif
}
__global__ void mapu_cu_swap_l_8(__DDR double *cu_cache, __DDR int *cu_xyzw,
                                 __DDR MAPU_LONG *adjoint_vec_pids,
                                 MAPU_LONG cu_cache_length, int the_dir_num,
                                 MAPU_LONG XYZLEN) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  if ((__idx == 0)) {
    {
      __mem0__ int cu_xyzw_shared[4];
      __mem0__ MAPU_LONG adjoint_vec_pids_shared[2];
      __shared__ barrier_t get_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }
      __shared__ barrier_t put_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }

      if ((2 * 1)) {
        {
          const size_t data_size = sizeof(
              ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)adjoint_vec_pids_shared),
                       ((__DDR unsigned *)(adjoint_vec_pids +
                                           ((6 * __idy) + (2 * the_dir_num)))),
                       ((uint64_t)(1 * (2 * data_size))), get_sync_id);
        }
      }

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)cu_xyzw_shared),
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((uint64_t)(1 * (4 * data_size))), get_sync_id);
        }
      }
      (get_sync_id).arrive_and_wait();
      __mem1__ MAPU_LONG left_pid;
      left_pid = (adjoint_vec_pids_shared)[0];
      __mem1__ int beg_left_par;
      beg_left_par = (cu_xyzw_shared)[1];
      __mem1__ int end_left_par;
      end_left_par = (cu_xyzw_shared)[2];

#if 0    
            fprintf(stderr, "id=%d left_pid=%d lr=l\n", __idy, left_pid);
            fprintf(stderr, "lr=l, __idy=%d, lpid=%d sdl=%d\n", __idy, left_pid, (end_left_par - beg_left_par));

#else

#endif

      if ((1 && ((left_pid != -1) && (beg_left_par != end_left_par)))) {
        {
          __mem1__ int end_cu_par;
          end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];
          __mem1__ int new_left_par;
          new_left_par = (end_cu_par + (end_left_par - beg_left_par));

          if ((1 * 1)) {
            {
              const size_t data_size = sizeof((&(new_left_par))[0]);
              memcpy_async(__pscmc_mapu_internal_block__,
                           ((__DDR unsigned *)(cu_xyzw + (4 * left_pid))),
                           ((unsigned *)&(new_left_par)),
                           ((uint64_t)(1 * (1 * data_size))), put_sync_id);
            }
          }

          if (1) {
            {
              __mem0__ int al1[2];
              ((al1)[0] = (cu_xyzw_shared)[3]);
              ((al1)[1] = (cu_xyzw_shared)[3]);

              if ((2 * 1)) {
                {
                  const size_t data_size = sizeof((al1)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)(cu_xyzw + ((4 * __idy) + 1))),
                      ((unsigned *)al1), ((uint64_t)(1 * (2 * data_size))),
                      put_sync_id);
                }
              }
            }
          }
          __mem0__ double local_cache[(384 * 8)];
          __mem1__ int i;
          for ((i = beg_left_par); (i < end_left_par); (i = (i + 384))) {
            __mem1__ int num_cp;
            num_cp = ((((i + 384) > end_left_par)) ? (({ (end_left_par - i); }))
                                                   : (({ 384; })));

            if (((8 * num_cp) * 1)) {
              {
                const size_t data_size =
                    sizeof((((cu_cache + (__idy * (8 * cu_cache_length))) +
                             (8 * i)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_cache + (0 * 8))),
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (8 * cu_cache_length))) +
                                        (8 * i))),
                    ((uint64_t)(1 * ((8 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int ii;
            for ((ii = 0); (ii < num_cp); ii++) {
              (((local_cache + (ii * 8)))[the_dir_num] =
                   (((local_cache + (ii * 8)))[the_dir_num] + XYZLEN));
            }
            if (((8 * num_cp) * 1)) {
              {
                const size_t data_size = sizeof(((local_cache + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (left_pid * (8 * cu_cache_length))) +
                                        (8 * end_cu_par))),
                    ((unsigned *)(local_cache + (0 * 8))),
                    ((uint64_t)(1 * ((8 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (end_cu_par = (end_cu_par + num_cp));
          }
          (put_sync_id).arrive_and_wait();
        }
      }
    }
  }

#endif
}
__global__ void mapu_cu_swap_r_8(__DDR double *cu_cache, __DDR int *cu_xyzw,
                                 __DDR MAPU_LONG *adjoint_vec_pids,
                                 MAPU_LONG cu_cache_length, int the_dir_num,
                                 MAPU_LONG XYZLEN) {

#ifdef __SCALE_ARCH__
  auto __pscmc_mapu_internal_block__ = cooperative_groups::this_thread_block();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t __pscmc_mapu_internal_barrier__;

  static __mem0__ __attribute__((used)) int __pscmc_mapu_dummy_variable_v2;
  init(&(__pscmc_mapu_internal_barrier__), 1);
  __mem1__ int __mapu_dma_index;
  __mapu_dma_index = 0;
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  if ((__idx == 0)) {
    {
      __mem0__ int cu_xyzw_shared[4];
      __mem0__ MAPU_LONG adjoint_vec_pids_shared[2];
      __shared__ barrier_t get_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(get_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }
      __shared__ barrier_t put_sync_id;

      if ((threadIdx.x == 0)) {
        {
          init(&(put_sync_id), (blockDim.x * (blockDim.y * blockDim.z)));
        }
      }

      if ((2 * 1)) {
        {
          const size_t data_size = sizeof(
              ((adjoint_vec_pids + ((6 * __idy) + (2 * the_dir_num))))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)adjoint_vec_pids_shared),
                       ((__DDR unsigned *)(adjoint_vec_pids +
                                           ((6 * __idy) + (2 * the_dir_num)))),
                       ((uint64_t)(1 * (2 * data_size))), get_sync_id);
        }
      }

      if ((4 * 1)) {
        {
          const size_t data_size = sizeof(((cu_xyzw + (4 * __idy)))[0]);
          memcpy_async(__pscmc_mapu_internal_block__,
                       ((unsigned *)cu_xyzw_shared),
                       ((__DDR unsigned *)(cu_xyzw + (4 * __idy))),
                       ((uint64_t)(1 * (4 * data_size))), get_sync_id);
        }
      }
      (get_sync_id).arrive_and_wait();
      __mem1__ MAPU_LONG left_pid;
      left_pid = (adjoint_vec_pids_shared)[1];
      __mem1__ int beg_left_par;
      beg_left_par = (cu_xyzw_shared)[3];
      __mem1__ MAPU_LONG end_left_par;
      end_left_par = cu_cache_length;

#if 0    
            fprintf(stderr, "id=%d left_pid=%d lr=r\n", __idy, left_pid);
            fprintf(stderr, "lr=r, __idy=%d, lpid=%d sdl=%d\n", __idy, left_pid, (end_left_par - beg_left_par));

#else

#endif

      if ((1 && ((left_pid != -1) && (beg_left_par != end_left_par)))) {
        {
          __mem1__ int end_cu_par;
          end_cu_par = (cu_xyzw)[((left_pid * 4) + 0)];
          __mem1__ int new_left_par;
          new_left_par = (end_cu_par + (end_left_par - beg_left_par));

          if ((1 * 1)) {
            {
              const size_t data_size = sizeof((&(new_left_par))[0]);
              memcpy_async(__pscmc_mapu_internal_block__,
                           ((__DDR unsigned *)(cu_xyzw + (4 * left_pid))),
                           ((unsigned *)&(new_left_par)),
                           ((uint64_t)(1 * (1 * data_size))), put_sync_id);
            }
          }

          if (1) {
            {
              __mem0__ int al1[2];
              ((al1)[0] = cu_cache_length);

              if ((1 * 1)) {
                {
                  const size_t data_size = sizeof((al1)[0]);
                  memcpy_async(
                      __pscmc_mapu_internal_block__,
                      ((__DDR unsigned *)(cu_xyzw + ((4 * __idy) + 3))),
                      ((unsigned *)al1), ((uint64_t)(1 * (1 * data_size))),
                      put_sync_id);
                }
              }
            }
          }
          __mem0__ double local_cache[(384 * 8)];
          __mem1__ int i;
          for ((i = beg_left_par); (i < end_left_par); (i = (i + 384))) {
            __mem1__ int num_cp;
            num_cp = ((((i + 384) > end_left_par)) ? (({ (end_left_par - i); }))
                                                   : (({ 384; })));

            if (((8 * num_cp) * 1)) {
              {
                const size_t data_size =
                    sizeof((((cu_cache + (__idy * (8 * cu_cache_length))) +
                             (8 * i)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((unsigned *)(local_cache + (0 * 8))),
                    ((__DDR unsigned *)((cu_cache +
                                         (__idy * (8 * cu_cache_length))) +
                                        (8 * i))),
                    ((uint64_t)(1 * ((8 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            __mem1__ int ii;
            for ((ii = 0); (ii < num_cp); ii++) {
              (((local_cache + (ii * 8)))[the_dir_num] =
                   (((local_cache + (ii * 8)))[the_dir_num] + XYZLEN));
            }
            if (((8 * num_cp) * 1)) {
              {
                const size_t data_size = sizeof(((local_cache + (0 * 8)))[0]);
                memcpy_async(
                    __pscmc_mapu_internal_block__,
                    ((__DDR unsigned *)((cu_cache +
                                         (left_pid * (8 * cu_cache_length))) +
                                        (8 * end_cu_par))),
                    ((unsigned *)(local_cache + (0 * 8))),
                    ((uint64_t)(1 * ((8 * num_cp) * data_size))),
                    __pscmc_mapu_internal_barrier__);
                (__pscmc_mapu_internal_barrier__).arrive_and_wait();
              }
            }
            (end_cu_par = (end_cu_par + num_cp));
          }
          (put_sync_id).arrive_and_wait();
        }
      }
    }
  }

#endif
}
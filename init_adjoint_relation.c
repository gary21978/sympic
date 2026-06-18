#include <stdio.h>

#include <math.h>

#include <stdlib.h>

#include <stdint.h>

#include <string.h>

#include <assert.h>

#include "pubdefs.h"

#include "cfgcst.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"

#include "cuda_/yeefdtd.kernel_inc.h"

#include "cuda_/stencil.kernel_inc.h"

#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"

#include "cuda_/geo_yeefdtd_rect.kernel_inc.h"

#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

#include "space_filling_curve.h"

int init_complexity_tid(unsigned long num_proc, unsigned long num_thread, size_t *ori_vec, long *num_thread_array,
                        int64_t *local_tid_array, int *cd_performances, int num_cds_per_mpi_proc) {
  long *cplx_array = malloc((sizeof(long) * num_thread));

  long *cplx_ori_array = malloc((sizeof(long) * num_thread));

  double total_complexity = 0.00000000000000000e+00;

  char *cmplx_file_name = "COMPLEXITY_ARRAY";

  FILE *fp = fopen(cmplx_file_name, "r");

  long total_perf = 0;

  {
    long k;

    for ((k = 0); (k < num_cds_per_mpi_proc); (k = (k + 1))) {
      if ((!(cd_performances)[k])) {
        ((cd_performances)[k] = 1);
      }

      (total_perf = (total_perf + (cd_performances)[k]));
    }
  }
  if (fp) {
    fprintf(stderr, "found %s for input\n", cmplx_file_name);
    fread(cplx_ori_array, sizeof(int64_t), num_thread, fp);
    fclose(fp);
  }

  {
    long i;

    for ((i = 0); (i < num_thread); (i = (i + 1))) {
      ((cplx_array)[i] = ((fp) ? ((cplx_ori_array)[(ori_vec)[i]])
                               : (floor(call_CAL_FUN_ONE_PARA("get_thread_complexity", (ori_vec)[i])))));
      assert(((cplx_array)[i] >= 0));
      (total_complexity = (total_complexity + (cplx_array)[i]));
    }
  }
  assert(total_complexity);
  long global_cplx = 0;

  long current_pid = 0;

  long l_tid = 0;

  ((num_thread_array)[0] = 0);
  {
    long i;

    for ((i = 0); (i < num_thread); (i = (i + 1))) {
      long mpi_id = (current_pid / num_cds_per_mpi_proc);

      long dev_id = (current_pid % num_cds_per_mpi_proc);

      long current_perf_all = (mpi_id * total_perf);

      {
        long j;

        for ((j = 0); (j < dev_id); (j = (j + 1))) {
          (current_perf_all = (current_perf_all + (cd_performances)[j]));
        }
      }
      if (((global_cplx * ((num_proc / num_cds_per_mpi_proc) * total_perf)) >= (current_perf_all * total_complexity))) {
        if ((current_pid < num_proc)) {
          ((num_thread_array)[current_pid] = i);
        }

        if ((current_pid < num_proc)) {
          (current_pid = (current_pid + 1));
          (l_tid = -1);
        }
      }

      (global_cplx = (global_cplx + (cplx_array)[i]));
      (l_tid = (l_tid + 1));
      ((local_tid_array)[i] = l_tid);
    }
  }
  assert((current_pid == num_proc));
  free(cplx_array);
  free(cplx_ori_array);
  return 0;
}
int init_uniform_tid(unsigned long num_proc, unsigned long num_thread, long *num_thread_array, long *local_tid_array,
                     int *cd_performances, int num_cds_per_mpi_proc) {
  unsigned long num_mpi_proc = (num_proc / num_cds_per_mpi_proc);

  long i = 0;

  long global_tid = 0;

  long oneprocnum = (num_thread / num_mpi_proc);

  long plusone = (num_thread % num_mpi_proc);

  long total_perf = 0;

  {
    long k;

    for ((k = 0); (k < num_cds_per_mpi_proc); (k = (k + 1))) {
      (total_perf = (total_perf + (cd_performances)[k]));
    }
  }
  for (i = 0; (i < num_mpi_proc); i++) {
    long tid_min = global_tid;

    long tid_plus = (global_tid + oneprocnum);

    if ((i < plusone)) {
      (tid_plus = (tid_plus + 1));
    }

    long num_t_one_mpi_proc = (tid_plus - tid_min);

    {
      long k;

      for ((k = 0); (k < num_cds_per_mpi_proc); (k = (k + 1))) {
        ((num_thread_array)[(k + (i * num_cds_per_mpi_proc))] = global_tid);
        long old_pid = global_tid;

        double cur_proc_num_threads_f =
            ((1.00000000000000000e+00 * ((cd_performances)[k] * num_t_one_mpi_proc)) / total_perf);

        long cur_proc_num_threads =
            floor((cur_proc_num_threads_f +
                   ((1 - (1.00000000000000000e+00 / num_cds_per_mpi_proc)) + 1.00000000000000002e-02)));

        if ((k == (num_cds_per_mpi_proc - 1))) {
          (global_tid = (tid_min + num_t_one_mpi_proc));

        } else {
          (global_tid = (global_tid + cur_proc_num_threads));
        }

        if ((global_tid > num_thread)) {
          (global_tid = num_thread);
        }

        if ((global_tid > (num_t_one_mpi_proc + tid_min))) {
          (global_tid = (num_t_one_mpi_proc + tid_min));
        }

        {
          long j;

          for ((j = old_pid); (j < global_tid); (j = (j + 1))) {
            ((local_tid_array)[j] = (j - old_pid));
          }
        }
      }
    }
  }
  return 0;
}

long get_cur_num_tid(long pid, long num_thread, long num_proc, long *num_thread_array) {
  long ret = 0;

  assert((pid < num_proc));
  (ret = (((pid < (num_proc - 1))) ? (((num_thread_array)[(pid + 1)] - (num_thread_array)[pid]))
                                   : ((num_thread - (num_thread_array)[pid]))));
  return ret;
}
long find_the_proc_id(long tid, unsigned long num_proc, long *num_thread_array) {
  if ((num_proc <= 1)) {
    return 0;

  } else {
    if ((tid < (num_thread_array)[(num_proc / 2)])) {
      return find_the_proc_id(tid, (num_proc / 2), num_thread_array);

    } else {
      return ((num_proc / 2) + find_the_proc_id(tid, (num_proc - (num_proc / 2)), (num_thread_array + (num_proc / 2))));
    }
  }
}
int init_adjoint_relations(Field3D_Seq *pthis, long n, long ndim, long adj_type, long num_proc, long *ovvec,
                           long *ori_vec, long *num_thread_array, long *local_tid_array) {

  // defined from class Field3D_Seq

  long xlen = (pthis)->xlen;

  long ylen = (pthis)->ylen;

  long zlen = (pthis)->zlen;


  long numvec = (pthis)->numvec;

  long x_num_thread_block = (pthis)->x_num_thread_block;

  long y_num_thread_block = (pthis)->y_num_thread_block;

  long z_num_thread_block = (pthis)->z_num_thread_block;


  void *cur_rankx_pscmc = (pthis)->cur_rankx_pscmc;

  void *cur_ranky_pscmc = (pthis)->cur_ranky_pscmc;

  void *cur_rankz_pscmc = (pthis)->cur_rankz_pscmc;

  void *xoffset = (pthis)->xoffset;

  void *yoffset = (pthis)->yoffset;

  void *zoffset = (pthis)->zoffset;

  long *global_x_offset = (pthis)->global_x_offset;

  long *global_y_offset = (pthis)->global_y_offset;

  long *global_z_offset = (pthis)->global_z_offset;

  long *global_id = (pthis)->global_id;

  long global_pid = (pthis)->global_pid;

  long *adj_ids = (pthis)->adj_ids;

  long *adj_processes = (pthis)->adj_processes;

  long *adj_local_tid = (pthis)->adj_local_tid;


  //====================Field3D_Seq
  long onen = (1 << n);

  long alllen = 1;

  assert(ndim < 4);
  {
    long g;

    for ((g = 0); (g < ndim); (g = (g + 1))) {
      (alllen = (alllen * onen));
    }
  }
  long i = 0;

  for (i = 0; (i < numvec); (i = (i + 1))) {
    long cur_thread = (ori_vec)[((num_thread_array)[global_pid] + i)];

    long bxyzx = (cur_thread % x_num_thread_block);

    long bxyzy = ((cur_thread / x_num_thread_block) % y_num_thread_block);

    long bxyzz = (cur_thread / (x_num_thread_block * y_num_thread_block));

    ((global_x_offset)[i] = (xlen * bxyzx));
    ((global_y_offset)[i] = (ylen * bxyzy));
    ((global_z_offset)[i] = (zlen * bxyzz));
    {
      int *tmpv = (cuda_pscmc_get_h_data(cur_rankx_pscmc, NULL));

      ((tmpv)[i] = ((2 * (bxyzx == (x_num_thread_block - 1))) + (bxyzx == 0)));
      (tmpv = (cuda_pscmc_get_h_data(xoffset, NULL)));
      ((tmpv)[i] = (global_x_offset)[i]);
    }
    {
      int *tmpv = (cuda_pscmc_get_h_data(cur_ranky_pscmc, NULL));

      ((tmpv)[i] = ((2 * (bxyzy == (y_num_thread_block - 1))) + (bxyzy == 0)));
      (tmpv = (cuda_pscmc_get_h_data(yoffset, NULL)));
      ((tmpv)[i] = (global_y_offset)[i]);
    }
    {
      int *tmpv = (cuda_pscmc_get_h_data(cur_rankz_pscmc, NULL));

      ((tmpv)[i] = ((2 * (bxyzz == (z_num_thread_block - 1))) + (bxyzz == 0)));
      (tmpv = (cuda_pscmc_get_h_data(zoffset, NULL)));
      ((tmpv)[i] = (global_z_offset)[i]);
    }
    cuda_pscmc_mem_sync_h2d(cur_rankx_pscmc);

    cuda_pscmc_mem_sync_h2d(cur_ranky_pscmc);

    cuda_pscmc_mem_sync_h2d(cur_rankz_pscmc);

    cuda_pscmc_mem_sync_h2d(xoffset);

    cuda_pscmc_mem_sync_h2d(yoffset);

    cuda_pscmc_mem_sync_h2d(zoffset);

    ((global_id)[i] = cur_thread);
    {
      long xyzz;

      for ((xyzz = 0); (xyzz < 3); (xyzz = (xyzz + 1))) {
        {
          long xyzy;

          for ((xyzy = 0); (xyzy < 3); (xyzy = (xyzy + 1))) {
            {
              long xyzx;

              for ((xyzx = 0); (xyzx < 3); (xyzx = (xyzx + 1))) {
                int xyzlocalall = (0 + (1 * (xyzx + (3 * (xyzy + (3 * xyzz))))));

                long adj_id_pre =
                    (0 +
                     (1 * ((((bxyzx + (xyzx - 1)) + x_num_thread_block) % x_num_thread_block) +
                           (x_num_thread_block * ((((bxyzy + (xyzy - 1)) + y_num_thread_block) % y_num_thread_block) +
                                                  (y_num_thread_block * (((bxyzz + (xyzz - 1)) + z_num_thread_block) %
                                                                         z_num_thread_block)))))));

                long cur_adj_id = (ovvec)[adj_id_pre];

                ((adj_ids)[((i * NUM_SYNC_LAYER) + xyzlocalall)] = cur_adj_id);
                long cur_adj_pid = find_the_proc_id(cur_adj_id, num_proc, num_thread_array);

                ((adj_processes)[((i * NUM_SYNC_LAYER) + xyzlocalall)] = cur_adj_pid);
                ((adj_local_tid)[((i * NUM_SYNC_LAYER) + xyzlocalall)] = (local_tid_array)[cur_adj_id]);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

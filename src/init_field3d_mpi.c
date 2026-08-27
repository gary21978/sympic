#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <complex.h>
#include <assert.h>

#include "pubdefs.h"
#include "kernel_includes.h"
#include "space_filling_curve.h"
#include "init_adjoint_relation.h"
#include "init_field3d_mpi.h"
#include "mpifields.h"
#include "cfgcst.h"
#include "genrand.h"
#include <cgapsio.h>

void init_Field3D_MPI_from_new_num_ele(Field3D_MPI *pthis, Field3D_MPI *f, int new_num_ele) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  ((pthis)[0] = (f)[0]);
  reinit_Field3D_MPI(pthis, new_num_ele);
}
void init_Field3D_MPI_from(Field3D_MPI *pthis, Field3D_MPI *f) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  init_Field3D_MPI_from_new_num_ele(pthis, f, 0);
}
void reinit_Field3D_MPI(Field3D_MPI *pthis, int new_num_ele) {

  // defined from class Field3D_MPI

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  {
    Field3D_Seq *tmpdata = pthis->data;

    ((pthis)->data = malloc((sizeof(Field3D_Seq) * num_runtime)));
    ((pthis)->rqst = malloc((sizeof(PS_MPI_Request *) * num_runtime)));
    if (new_num_ele) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < 3); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < 3); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < 3); (xyzx = (xyzx + 1))) {

                  // defined from class Field3D_Seq

                  long xlen = (tmpdata)->xlen;

                  long ylen = (tmpdata)->ylen;

                  long zlen = (tmpdata)->zlen;


                  int ovlp = (tmpdata)->ovlp;


                  //====================Field3D_Seq
                  long rxlen = ovlp;

                  long rylen = ovlp;

                  long rzlen = ovlp;

                  if ((xyzx == 1)) {
                    (rxlen = xlen);
                  }

                  if ((xyzy == 1)) {
                    (rylen = ylen);
                  }

                  if ((xyzz == 1)) {
                    (rzlen = zlen);
                  }

                  ((pthis->sync_layer_len)[(0 + (1 * (xyzx + (3 * (xyzy + (3 * xyzz))))))] =
                       (rxlen * (rylen * (rzlen * new_num_ele))));
                }
              }
            }
          }
        }
      }
    }

    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {
        ((pthis->data)[i] = (tmpdata)[i]);
        if (new_num_ele) {
          (((pthis->data + i))->num_ele = new_num_ele);
        }

        {

          long numvec = ((pthis->data + i))->numvec;

          sympic_set_device(pthis->data[i].cuda_device);
          alloc_Field3D_Seq((pthis->data + i), 0);
          (((pthis->data + i))->cur_rankx_pscmc = ((tmpdata + i))->cur_rankx_pscmc);
          (((pthis->data + i))->cur_ranky_pscmc = ((tmpdata + i))->cur_ranky_pscmc);
          (((pthis->data + i))->cur_rankz_pscmc = ((tmpdata + i))->cur_rankz_pscmc);
          (((pthis->data + i))->xoffset = ((tmpdata + i))->xoffset);
          (((pthis->data + i))->yoffset = ((tmpdata + i))->yoffset);
          (((pthis->data + i))->zoffset = ((tmpdata + i))->zoffset);

          memcpy(((pthis->data + i))->global_id, ((tmpdata + i))->global_id, (sizeof(long) * (1 * numvec)));
          memcpy(((pthis->data + i))->global_x_offset, ((tmpdata + i))->global_x_offset, (sizeof(long) * (1 * numvec)));
          memcpy(((pthis->data + i))->global_y_offset, ((tmpdata + i))->global_y_offset, (sizeof(long) * (1 * numvec)));
          memcpy(((pthis->data + i))->global_z_offset, ((tmpdata + i))->global_z_offset, (sizeof(long) * (1 * numvec)));
          memcpy(((pthis->data + i))->adj_ids, ((tmpdata + i))->adj_ids, (sizeof(long) * (NUM_SYNC_LAYER * numvec)));
          memcpy(((pthis->data + i))->adj_processes, ((tmpdata + i))->adj_processes,
                 (sizeof(long) * (NUM_SYNC_LAYER * numvec)));
          memcpy(((pthis->data + i))->adj_local_tid, ((tmpdata + i))->adj_local_tid,
                 (sizeof(long) * (NUM_SYNC_LAYER * numvec)));
        }
        ((pthis->rqst)[i] = malloc((sizeof(PS_MPI_Request) * (NUM_SYNC_LAYER * ((pthis->data + i))->numvec))));
      }
    }
  }
}
int init_Field3D_MPI_ALL(Field3D_MPI *pthis, Field3D_Seq *sample_field, long n_hilbert, int ndim, int adjoint_type,
                         long *tids, int64_t *local_tid_array, int *cd_types, int *dev_nums, int *cd_performances,
                         long num_runtime, PS_MPI_Comm comm, long cur_rank, long num_mpi_process) {
  ((pthis)->num_runtime = num_runtime);
  ((pthis)->comm = comm);
  ((pthis)->cur_rank = cur_rank);
  ((pthis)->num_mpi_process = num_mpi_process);
  {
    double G_DAMP_RATIO = call_GET_VAR("DAMP_RATIO");

    ((pthis)->damp_vars = G_DAMP_RATIO);
  }
  ((pthis)->data = malloc((sizeof(Field3D_Seq) * num_runtime)));
  long i = 0;

  long onedim_len = (1 << n_hilbert);

  long numallthreads =
      (((ndim == 1))
           ? (onedim_len)
           : ((((ndim == 2)) ? ((onedim_len * onedim_len))
                             : ((((ndim == 3)) ? ((onedim_len * (onedim_len * onedim_len)))
                                               : (fprintf(stderr, "Warning: unknown dimension d=%d\n", ndim)))))));

  long onen = (1 << n_hilbert);

  long alllen = 1;

  assert(ndim < 4);
  {
    long g;

    for ((g = 0); (g < ndim); (g = (g + 1))) {
      (alllen = (alllen * onen));
    }
  }
  size_t *ovvec = malloc((sizeof(size_t) * alllen));

  size_t *ori_vec = malloc((sizeof(size_t) * alllen));

  if ((ndim == 1)) {
    sp_fill_curve_1d(ovvec, ori_vec, onen);

  } else {
    if ((ndim == 2)) {
      hilbert_curve_2d(ovvec, ori_vec, n_hilbert, onen);

    } else {
      if ((ndim == 3)) {
        hilbert_curve_3d(ovvec, ori_vec, n_hilbert, onen, onen);

      } else {
        fprintf(stderr, "Error: unknown ndim=%d\n", ndim);
        assert(0);
      }
    }
  }

  {
    double M_USE_CALC_WEIGHT = call_GET_VAR("USE_CALC_WEIGHT");

    long n = NUM_PROCESS;

    long num_runtime = NUM_RUNTIME;

    long numt = alllen;

    if (M_USE_CALC_WEIGHT) {
      init_complexity_tid((n * num_runtime), numt, ori_vec, tids, local_tid_array, cd_performances, num_runtime);

    } else {
      init_uniform_tid((n * num_runtime), numt, tids, local_tid_array, cd_performances, num_runtime);
    }
  }
  (pthis->rqst = malloc((sizeof(PS_MPI_Request *) * num_runtime)));
  for (i = 0; (i < num_runtime); i++) {
    ((pthis->data)[i] = (sample_field)[0]);
    (((pthis->data + i))->CD_type = (cd_types)[i]);
    (((pthis->data + i))->numvec =
         get_cur_num_tid(((num_runtime * cur_rank) + i), numallthreads, (num_runtime * num_mpi_process), tids));
    size_t pelen;

#ifdef SYMPIC_CUDA
    cuda_pscmc_get_env_len(&(pelen));
#endif
#ifdef SYMPIC_MAPU
    mapu_pscmc_get_env_len(&(pelen));
#endif

    (((pthis->data + i))->pe = malloc(pelen));
#ifdef SYMPIC_CUDA
    cuda_pscmc_env_init(((pthis->data + i))->pe, (dev_nums)[i], NULL);
#endif
#ifdef SYMPIC_MAPU
    mapu_pscmc_env_init(((pthis->data + i))->pe, (dev_nums)[i], NULL);
#endif
    pthis->data[i].cuda_device = dev_nums[i];
    (((pthis->data + i))->global_pid = ((cur_rank * num_runtime) + i));
    alloc_Field3D_Seq((pthis->data + i), 1);
    pthis->rqst[i] = malloc(sizeof(PS_MPI_Request) * NUM_SYNC_LAYER * pthis->data[i].numvec);
    init_adjoint_relations((pthis->data + i), n_hilbert, ndim, adjoint_type, (num_mpi_process * num_runtime), ovvec,
                           ori_vec, tids, local_tid_array);
  }
  {
    long xyzz;

    for ((xyzz = 0); (xyzz < 3); (xyzz = (xyzz + 1))) {
      {
        long xyzy;

        for ((xyzy = 0); (xyzy < 3); (xyzy = (xyzy + 1))) {
          {
            long xyzx;

            for ((xyzx = 0); (xyzx < 3); (xyzx = (xyzx + 1))) {

              // defined from class Field3D_Seq

              long xlen = (sample_field)->xlen;

              long ylen = (sample_field)->ylen;

              long zlen = (sample_field)->zlen;


              int ovlp = (sample_field)->ovlp;

              int num_ele = (sample_field)->num_ele;


              //====================Field3D_Seq
              long rxlen = ovlp;

              long rylen = ovlp;

              long rzlen = ovlp;

              if ((xyzx == 1)) {
                (rxlen = xlen);
              }

              if ((xyzy == 1)) {
                (rylen = ylen);
              }

              if ((xyzz == 1)) {
                (rzlen = zlen);
              }

              ((pthis->sync_layer_len)[(0 + (1 * (xyzx + (3 * (xyzy + (3 * xyzz))))))] =
                   (rxlen * (rylen * (rzlen * num_ele))));
            }
          }
        }
      }
    }
  }
  free(ovvec);
  free(ori_vec);
  return 0;
}

void init_external_field3d_E_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                            double r_z_rat, double random_rate) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int reduce_x = (reduce_dim == 1);

  int reduce_y = (reduce_dim == 2);

  int reduce_z = (reduce_dim == 3);

  double r_r_r[3];
  ((r_r_r)[0] = r_x_rat);
  ((r_r_r)[1] = r_y_rat);
  ((r_r_r)[2] = r_z_rat);
  char *nm = "E_file";

  FILE *fp = fopen(nm, "r");

  if (fp) {
    fclose(fp);
    fprintf(stderr, "found %s for input\n", nm);
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    GAPS_IO_InitIFile(pgid, nm);
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + 0);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        assert(((pgid)->dim == 4));
                        assert(((pgid)->version == 0));
                        assert(((pgid)->type == GAPS_IO_FLOAT64));
                        assert((((pgid)->pdimarray)[0] == num_ele));
                        long imax = ((pgid)->pdimarray)[1];

                        long jmax = ((pgid)->pdimarray)[2];


                        GAPS_IO_DataSeek(pgid, 0,
                                         (num_ele * (((reduce_x) ? (0) : (is)) +
                                                     (((reduce_x) ? (1) : (imax)) *
                                                      (((reduce_y) ? (0) : (js)) +
                                                       (((reduce_y) ? (1) : (jmax)) * ((reduce_z) ? (0) : (ks))))))));
                        GAPS_IO_FRead(
                            pgid,
                            &(((((double **)((data + i))->main_data))[0])[(
                                (j * (((data + i))->xblock *
                                      (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                (0 + (((data + i))->num_ele *
                                      ((0 + ((data + i))->ovlp) +
                                       (((data + i))->xblock *
                                        ((xyzy + ((data + i))->ovlp) +
                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]),
                            (num_ele * ((reduce_x) ? (1) : (xlen))));
                        if (reduce_dim) {
                          {
                            long g;

                            for ((g = 0); (g < ((reduce_x) ? (1) : (xlen))); (g = (g + 1))) {
                              {
                                long l;

                                for ((l = 0); (l < num_ele); (l = (l + 1))) {
                                  if ((l < 3)) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         ((r_r_r)[l] *
                                          ((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]));
                                  }

                                  if (random_rate) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         (((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] +
                                          (((((double **)((data + i))->main_data))[0])[(
                                               (j * (((data + i))->xblock *
                                                     (((data + i))->yblock *
                                                      (((data + i))->zblock * ((data + i))->num_ele)))) +
                                               (l + (((data + i))->num_ele *
                                                     ((g + ((data + i))->ovlp) +
                                                      (((data + i))->xblock *
                                                       ((xyzy + ((data + i))->ovlp) +
                                                        (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] *
                                           (random_rate * rand01(0, 1)))));
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
    GAPS_IO_DeleteDataInfo(pgid);

  } else {
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int ovlp = ((data + i))->ovlp;

        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = -(ovlp)); (xyzz < (zlen + ovlp)); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = -(ovlp)); (xyzy < (ylen + ovlp)); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = -(ovlp)); (xyzx < (xlen + ovlp)); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + xyzx);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        {
                          long l;

                          for ((l = 0); (l < num_ele); (l = (l + 1))) {
                            (((((double **)((data + i))->main_data))[0])[(
                                 (j * (((data + i))->xblock *
                                       (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                 (l + (((data + i))->num_ele *
                                       ((xyzx + ((data + i))->ovlp) +
                                        (((data + i))->xblock *
                                         ((xyzy + ((data + i))->ovlp) +
                                          (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                 call_GET_INIT_E(ks, js, is, l));
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
void init_external_field3d_E_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                       double r_z_rat) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  return init_external_field3d_E_2d_extend_rand(pthis, reduce_dim, r_x_rat, r_y_rat, r_z_rat, 0);
}

void init_external_field3d_B_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                            double r_z_rat, double random_rate) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int reduce_x = (reduce_dim == 1);

  int reduce_y = (reduce_dim == 2);

  int reduce_z = (reduce_dim == 3);

  double r_r_r[3];
  ((r_r_r)[0] = r_x_rat);
  ((r_r_r)[1] = r_y_rat);
  ((r_r_r)[2] = r_z_rat);
  char *nm = "B_file";

  FILE *fp = fopen(nm, "r");

  if (fp) {
    fclose(fp);
    fprintf(stderr, "found %s for input\n", nm);
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    GAPS_IO_InitIFile(pgid, nm);
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + 0);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        assert(((pgid)->dim == 4));
                        assert(((pgid)->version == 0));
                        assert(((pgid)->type == GAPS_IO_FLOAT64));
                        assert((((pgid)->pdimarray)[0] == num_ele));
                        long imax = ((pgid)->pdimarray)[1];

                        long jmax = ((pgid)->pdimarray)[2];


                        GAPS_IO_DataSeek(pgid, 0,
                                         (num_ele * (((reduce_x) ? (0) : (is)) +
                                                     (((reduce_x) ? (1) : (imax)) *
                                                      (((reduce_y) ? (0) : (js)) +
                                                       (((reduce_y) ? (1) : (jmax)) * ((reduce_z) ? (0) : (ks))))))));
                        GAPS_IO_FRead(
                            pgid,
                            &(((((double **)((data + i))->main_data))[0])[(
                                (j * (((data + i))->xblock *
                                      (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                (0 + (((data + i))->num_ele *
                                      ((0 + ((data + i))->ovlp) +
                                       (((data + i))->xblock *
                                        ((xyzy + ((data + i))->ovlp) +
                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]),
                            (num_ele * ((reduce_x) ? (1) : (xlen))));
                        if (reduce_dim) {
                          {
                            long g;

                            for ((g = 0); (g < ((reduce_x) ? (1) : (xlen))); (g = (g + 1))) {
                              {
                                long l;

                                for ((l = 0); (l < num_ele); (l = (l + 1))) {
                                  if ((l < 3)) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         ((r_r_r)[l] *
                                          ((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]));
                                  }

                                  if (random_rate) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         (((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] +
                                          (((((double **)((data + i))->main_data))[0])[(
                                               (j * (((data + i))->xblock *
                                                     (((data + i))->yblock *
                                                      (((data + i))->zblock * ((data + i))->num_ele)))) +
                                               (l + (((data + i))->num_ele *
                                                     ((g + ((data + i))->ovlp) +
                                                      (((data + i))->xblock *
                                                       ((xyzy + ((data + i))->ovlp) +
                                                        (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] *
                                           (random_rate * rand01(0, 1)))));
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
    GAPS_IO_DeleteDataInfo(pgid);

  } else {
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int ovlp = ((data + i))->ovlp;

        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = -(ovlp)); (xyzz < (zlen + ovlp)); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = -(ovlp)); (xyzy < (ylen + ovlp)); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = -(ovlp)); (xyzx < (xlen + ovlp)); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + xyzx);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        {
                          long l;

                          for ((l = 0); (l < num_ele); (l = (l + 1))) {
                            (((((double **)((data + i))->main_data))[0])[(
                                 (j * (((data + i))->xblock *
                                       (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                 (l + (((data + i))->num_ele *
                                       ((xyzx + ((data + i))->ovlp) +
                                        (((data + i))->xblock *
                                         ((xyzy + ((data + i))->ovlp) +
                                          (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                 call_GET_INIT_B(ks, js, is, l));
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
void init_external_field3d_B_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                       double r_z_rat) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  return init_external_field3d_B_2d_extend_rand(pthis, reduce_dim, r_x_rat, r_y_rat, r_z_rat, 0);
}

void init_external_field3d_E0_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                             double r_z_rat, double random_rate) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int reduce_x = (reduce_dim == 1);

  int reduce_y = (reduce_dim == 2);

  int reduce_z = (reduce_dim == 3);

  double r_r_r[3];
  ((r_r_r)[0] = r_x_rat);
  ((r_r_r)[1] = r_y_rat);
  ((r_r_r)[2] = r_z_rat);
  char *nm = "E0_file";

  FILE *fp = fopen(nm, "r");

  if (fp) {
    fclose(fp);
    fprintf(stderr, "found %s for input\n", nm);
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    GAPS_IO_InitIFile(pgid, nm);
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + 0);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        assert(((pgid)->dim == 4));
                        assert(((pgid)->version == 0));
                        assert(((pgid)->type == GAPS_IO_FLOAT64));
                        assert((((pgid)->pdimarray)[0] == num_ele));
                        long imax = ((pgid)->pdimarray)[1];

                        long jmax = ((pgid)->pdimarray)[2];


                        GAPS_IO_DataSeek(pgid, 0,
                                         (num_ele * (((reduce_x) ? (0) : (is)) +
                                                     (((reduce_x) ? (1) : (imax)) *
                                                      (((reduce_y) ? (0) : (js)) +
                                                       (((reduce_y) ? (1) : (jmax)) * ((reduce_z) ? (0) : (ks))))))));
                        GAPS_IO_FRead(
                            pgid,
                            &(((((double **)((data + i))->main_data))[0])[(
                                (j * (((data + i))->xblock *
                                      (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                (0 + (((data + i))->num_ele *
                                      ((0 + ((data + i))->ovlp) +
                                       (((data + i))->xblock *
                                        ((xyzy + ((data + i))->ovlp) +
                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]),
                            (num_ele * ((reduce_x) ? (1) : (xlen))));
                        if (reduce_dim) {
                          {
                            long g;

                            for ((g = 0); (g < ((reduce_x) ? (1) : (xlen))); (g = (g + 1))) {
                              {
                                long l;

                                for ((l = 0); (l < num_ele); (l = (l + 1))) {
                                  if ((l < 3)) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         ((r_r_r)[l] *
                                          ((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]));
                                  }

                                  if (random_rate) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         (((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] +
                                          (((((double **)((data + i))->main_data))[0])[(
                                               (j * (((data + i))->xblock *
                                                     (((data + i))->yblock *
                                                      (((data + i))->zblock * ((data + i))->num_ele)))) +
                                               (l + (((data + i))->num_ele *
                                                     ((g + ((data + i))->ovlp) +
                                                      (((data + i))->xblock *
                                                       ((xyzy + ((data + i))->ovlp) +
                                                        (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] *
                                           (random_rate * rand01(0, 1)))));
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
    GAPS_IO_DeleteDataInfo(pgid);

  } else {
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int ovlp = ((data + i))->ovlp;

        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = -(ovlp)); (xyzz < (zlen + ovlp)); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = -(ovlp)); (xyzy < (ylen + ovlp)); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = -(ovlp)); (xyzx < (xlen + ovlp)); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + xyzx);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        {
                          long l;

                          for ((l = 0); (l < num_ele); (l = (l + 1))) {
                            (((((double **)((data + i))->main_data))[0])[(
                                 (j * (((data + i))->xblock *
                                       (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                 (l + (((data + i))->num_ele *
                                       ((xyzx + ((data + i))->ovlp) +
                                        (((data + i))->xblock *
                                         ((xyzy + ((data + i))->ovlp) +
                                          (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                 call_GET_INIT_E0(ks, js, is, l));
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

void init_external_field3d_B0_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                             double r_z_rat, double random_rate) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int reduce_x = (reduce_dim == 1);

  int reduce_y = (reduce_dim == 2);

  int reduce_z = (reduce_dim == 3);

  double r_r_r[3];
  ((r_r_r)[0] = r_x_rat);
  ((r_r_r)[1] = r_y_rat);
  ((r_r_r)[2] = r_z_rat);
  char *nm = "B0_file";

  FILE *fp = fopen(nm, "r");

  if (fp) {
    fclose(fp);
    fprintf(stderr, "found %s for input\n", nm);
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    GAPS_IO_InitIFile(pgid, nm);
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + 0);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        assert(((pgid)->dim == 4));
                        assert(((pgid)->version == 0));
                        assert(((pgid)->type == GAPS_IO_FLOAT64));
                        assert((((pgid)->pdimarray)[0] == num_ele));
                        long imax = ((pgid)->pdimarray)[1];

                        long jmax = ((pgid)->pdimarray)[2];


                        GAPS_IO_DataSeek(pgid, 0,
                                         (num_ele * (((reduce_x) ? (0) : (is)) +
                                                     (((reduce_x) ? (1) : (imax)) *
                                                      (((reduce_y) ? (0) : (js)) +
                                                       (((reduce_y) ? (1) : (jmax)) * ((reduce_z) ? (0) : (ks))))))));
                        GAPS_IO_FRead(
                            pgid,
                            &(((((double **)((data + i))->main_data))[0])[(
                                (j * (((data + i))->xblock *
                                      (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                (0 + (((data + i))->num_ele *
                                      ((0 + ((data + i))->ovlp) +
                                       (((data + i))->xblock *
                                        ((xyzy + ((data + i))->ovlp) +
                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]),
                            (num_ele * ((reduce_x) ? (1) : (xlen))));
                        if (reduce_dim) {
                          {
                            long g;

                            for ((g = 0); (g < ((reduce_x) ? (1) : (xlen))); (g = (g + 1))) {
                              {
                                long l;

                                for ((l = 0); (l < num_ele); (l = (l + 1))) {
                                  if ((l < 3)) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         ((r_r_r)[l] *
                                          ((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]));
                                  }

                                  if (random_rate) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         (((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] +
                                          (((((double **)((data + i))->main_data))[0])[(
                                               (j * (((data + i))->xblock *
                                                     (((data + i))->yblock *
                                                      (((data + i))->zblock * ((data + i))->num_ele)))) +
                                               (l + (((data + i))->num_ele *
                                                     ((g + ((data + i))->ovlp) +
                                                      (((data + i))->xblock *
                                                       ((xyzy + ((data + i))->ovlp) +
                                                        (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] *
                                           (random_rate * rand01(0, 1)))));
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
    GAPS_IO_DeleteDataInfo(pgid);

  } else {
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int ovlp = ((data + i))->ovlp;

        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = -(ovlp)); (xyzz < (zlen + ovlp)); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = -(ovlp)); (xyzy < (ylen + ovlp)); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = -(ovlp)); (xyzx < (xlen + ovlp)); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + xyzx);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        {
                          long l;

                          for ((l = 0); (l < num_ele); (l = (l + 1))) {
                            (((((double **)((data + i))->main_data))[0])[(
                                 (j * (((data + i))->xblock *
                                       (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                 (l + (((data + i))->num_ele *
                                       ((xyzx + ((data + i))->ovlp) +
                                        (((data + i))->xblock *
                                         ((xyzy + ((data + i))->ovlp) +
                                          (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                 call_GET_INIT_B0(ks, js, is, l));
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

void init_external_field3d_FILTER_E_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                                   double r_z_rat, double random_rate) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int reduce_x = (reduce_dim == 1);

  int reduce_y = (reduce_dim == 2);

  int reduce_z = (reduce_dim == 3);

  double r_r_r[3];
  ((r_r_r)[0] = r_x_rat);
  ((r_r_r)[1] = r_y_rat);
  ((r_r_r)[2] = r_z_rat);
  char *nm = "FILTER_E_file";

  FILE *fp = fopen(nm, "r");

  if (fp) {
    fclose(fp);
    fprintf(stderr, "found %s for input\n", nm);
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    GAPS_IO_InitIFile(pgid, nm);
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + 0);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        assert(((pgid)->dim == 4));
                        assert(((pgid)->version == 0));
                        assert(((pgid)->type == GAPS_IO_FLOAT64));
                        assert((((pgid)->pdimarray)[0] == num_ele));
                        long imax = ((pgid)->pdimarray)[1];

                        long jmax = ((pgid)->pdimarray)[2];


                        GAPS_IO_DataSeek(pgid, 0,
                                         (num_ele * (((reduce_x) ? (0) : (is)) +
                                                     (((reduce_x) ? (1) : (imax)) *
                                                      (((reduce_y) ? (0) : (js)) +
                                                       (((reduce_y) ? (1) : (jmax)) * ((reduce_z) ? (0) : (ks))))))));
                        GAPS_IO_FRead(
                            pgid,
                            &(((((double **)((data + i))->main_data))[0])[(
                                (j * (((data + i))->xblock *
                                      (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                (0 + (((data + i))->num_ele *
                                      ((0 + ((data + i))->ovlp) +
                                       (((data + i))->xblock *
                                        ((xyzy + ((data + i))->ovlp) +
                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]),
                            (num_ele * ((reduce_x) ? (1) : (xlen))));
                        if (reduce_dim) {
                          {
                            long g;

                            for ((g = 0); (g < ((reduce_x) ? (1) : (xlen))); (g = (g + 1))) {
                              {
                                long l;

                                for ((l = 0); (l < num_ele); (l = (l + 1))) {
                                  if ((l < 3)) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         ((r_r_r)[l] *
                                          ((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]));
                                  }

                                  if (random_rate) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         (((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] +
                                          (((((double **)((data + i))->main_data))[0])[(
                                               (j * (((data + i))->xblock *
                                                     (((data + i))->yblock *
                                                      (((data + i))->zblock * ((data + i))->num_ele)))) +
                                               (l + (((data + i))->num_ele *
                                                     ((g + ((data + i))->ovlp) +
                                                      (((data + i))->xblock *
                                                       ((xyzy + ((data + i))->ovlp) +
                                                        (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] *
                                           (random_rate * rand01(0, 1)))));
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
    GAPS_IO_DeleteDataInfo(pgid);

  } else {
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int ovlp = ((data + i))->ovlp;

        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = -(ovlp)); (xyzz < (zlen + ovlp)); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = -(ovlp)); (xyzy < (ylen + ovlp)); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = -(ovlp)); (xyzx < (xlen + ovlp)); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + xyzx);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        {
                          long l;

                          for ((l = 0); (l < num_ele); (l = (l + 1))) {
                            (((((double **)((data + i))->main_data))[0])[(
                                 (j * (((data + i))->xblock *
                                       (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                 (l + (((data + i))->num_ele *
                                       ((xyzx + ((data + i))->ovlp) +
                                        (((data + i))->xblock *
                                         ((xyzy + ((data + i))->ovlp) +
                                          (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                 call_GET_INIT_FILTER_E(ks, js, is, l));
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
void init_external_field3d_FILTER_E_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                              double r_z_rat) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  return init_external_field3d_FILTER_E_2d_extend_rand(pthis, reduce_dim, r_x_rat, r_y_rat, r_z_rat, 0);
}
void init_external_field3d_FILTER_E(Field3D_MPI *pthis) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  return init_external_field3d_FILTER_E_2d_extend(pthis, 0, 1, 1, 1);
}
void init_external_field3d_FILTER_B_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                                   double r_z_rat, double random_rate) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  int reduce_x = (reduce_dim == 1);

  int reduce_y = (reduce_dim == 2);

  int reduce_z = (reduce_dim == 3);

  double r_r_r[3];
  ((r_r_r)[0] = r_x_rat);
  ((r_r_r)[1] = r_y_rat);
  ((r_r_r)[2] = r_z_rat);
  char *nm = "FILTER_B_file";

  FILE *fp = fopen(nm, "r");

  if (fp) {
    fclose(fp);
    fprintf(stderr, "found %s for input\n", nm);
    Gaps_IO_DataFile gid;

    Gaps_IO_DataFile *pgid = &(gid);

    GAPS_IO_InitIFile(pgid, nm);
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + 0);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        assert(((pgid)->dim == 4));
                        assert(((pgid)->version == 0));
                        assert(((pgid)->type == GAPS_IO_FLOAT64));
                        assert((((pgid)->pdimarray)[0] == num_ele));
                        long imax = ((pgid)->pdimarray)[1];

                        long jmax = ((pgid)->pdimarray)[2];


                        GAPS_IO_DataSeek(pgid, 0,
                                         (num_ele * (((reduce_x) ? (0) : (is)) +
                                                     (((reduce_x) ? (1) : (imax)) *
                                                      (((reduce_y) ? (0) : (js)) +
                                                       (((reduce_y) ? (1) : (jmax)) * ((reduce_z) ? (0) : (ks))))))));
                        GAPS_IO_FRead(
                            pgid,
                            &(((((double **)((data + i))->main_data))[0])[(
                                (j * (((data + i))->xblock *
                                      (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                (0 + (((data + i))->num_ele *
                                      ((0 + ((data + i))->ovlp) +
                                       (((data + i))->xblock *
                                        ((xyzy + ((data + i))->ovlp) +
                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]),
                            (num_ele * ((reduce_x) ? (1) : (xlen))));
                        if (reduce_dim) {
                          {
                            long g;

                            for ((g = 0); (g < ((reduce_x) ? (1) : (xlen))); (g = (g + 1))) {
                              {
                                long l;

                                for ((l = 0); (l < num_ele); (l = (l + 1))) {
                                  if ((l < 3)) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         ((r_r_r)[l] *
                                          ((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))]));
                                  }

                                  if (random_rate) {
                                    (((((double **)((data + i))->main_data))[0])[(
                                         (j *
                                          (((data + i))->xblock *
                                           (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                         (l + (((data + i))->num_ele *
                                               ((g + ((data + i))->ovlp) +
                                                (((data + i))->xblock *
                                                 ((xyzy + ((data + i))->ovlp) +
                                                  (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                         (((((double **)((data + i))->main_data))[0])[(
                                              (j * (((data + i))->xblock *
                                                    (((data + i))->yblock *
                                                     (((data + i))->zblock * ((data + i))->num_ele)))) +
                                              (l + (((data + i))->num_ele *
                                                    ((g + ((data + i))->ovlp) +
                                                     (((data + i))->xblock *
                                                      ((xyzy + ((data + i))->ovlp) +
                                                       (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] +
                                          (((((double **)((data + i))->main_data))[0])[(
                                               (j * (((data + i))->xblock *
                                                     (((data + i))->yblock *
                                                      (((data + i))->zblock * ((data + i))->num_ele)))) +
                                               (l + (((data + i))->num_ele *
                                                     ((g + ((data + i))->ovlp) +
                                                      (((data + i))->xblock *
                                                       ((xyzy + ((data + i))->ovlp) +
                                                        (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] *
                                           (random_rate * rand01(0, 1)))));
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
    GAPS_IO_DeleteDataInfo(pgid);

  } else {
    {
      long i;

      for ((i = 0); (i < num_runtime); (i = (i + 1))) {

        // defined from class Field3D_Seq

        long xlen = ((data + i))->xlen;

        long ylen = ((data + i))->ylen;

        long zlen = ((data + i))->zlen;


        long numvec = ((data + i))->numvec;


        int ovlp = ((data + i))->ovlp;

        int num_ele = ((data + i))->num_ele;


        long *global_x_offset = ((data + i))->global_x_offset;

        long *global_y_offset = ((data + i))->global_y_offset;

        long *global_z_offset = ((data + i))->global_z_offset;


        //====================Field3D_Seq
        {
          long j;

          for ((j = 0); (j < numvec); (j = (j + 1))) {
            {
              long xyzz;

              for ((xyzz = -(ovlp)); (xyzz < (zlen + ovlp)); (xyzz = (xyzz + 1))) {
                {
                  long xyzy;

                  for ((xyzy = -(ovlp)); (xyzy < (ylen + ovlp)); (xyzy = (xyzy + 1))) {
                    {
                      long xyzx;

                      for ((xyzx = -(ovlp)); (xyzx < (xlen + ovlp)); (xyzx = (xyzx + 1))) {
                        long is = ((global_x_offset)[j] + xyzx);

                        long js = ((global_y_offset)[j] + xyzy);

                        long ks = ((global_z_offset)[j] + xyzz);

                        {
                          long l;

                          for ((l = 0); (l < num_ele); (l = (l + 1))) {
                            (((((double **)((data + i))->main_data))[0])[(
                                 (j * (((data + i))->xblock *
                                       (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                                 (l + (((data + i))->num_ele *
                                       ((xyzx + ((data + i))->ovlp) +
                                        (((data + i))->xblock *
                                         ((xyzy + ((data + i))->ovlp) +
                                          (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                                 call_GET_INIT_FILTER_B(ks, js, is, l));
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
void init_external_field3d_FILTER_B_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                              double r_z_rat) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  return init_external_field3d_FILTER_B_2d_extend_rand(pthis, reduce_dim, r_x_rat, r_y_rat, r_z_rat, 0);
}
void init_external_field3d_FILTER_B(Field3D_MPI *pthis) {

  // defined from class Field3D_MPI


  //====================Field3D_MPI
  return init_external_field3d_FILTER_B_2d_extend(pthis, 0, 1, 1, 1);
}

int test_set_mainland(Field3D_MPI *pthis, double val) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  long i = 0;

  for (i = 0; i < num_runtime; i++) {

    // defined from class Field3D_Seq

    long xlen = ((data + i))->xlen;

    long ylen = ((data + i))->ylen;

    long zlen = ((data + i))->zlen;


    long numvec = ((data + i))->numvec;


    int num_ele = ((data + i))->num_ele;


    //====================Field3D_Seq
    long j = 0;

    for (j = 0; j < numvec; j++) {
      {
        long xyzz;

        for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
          {
            long xyzy;

            for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
              {
                long xyzx;

                for ((xyzx = 0); (xyzx < xlen); (xyzx = (xyzx + 1))) {
                  long l = 0;


                  for (l = 0; l < num_ele; l++) {
                    (((((double **)((data + i))->main_data))[0])[(
                         (j * (((data + i))->xblock *
                               (((data + i))->yblock * (((data + i))->zblock * ((data + i))->num_ele)))) +
                         (l + (((data + i))->num_ele *
                               ((xyzx + ((data + i))->ovlp) +
                                (((data + i))->xblock * ((xyzy + ((data + i))->ovlp) +
                                                         (((data + i))->yblock * (xyzz + ((data + i))->ovlp))))))))] =
                         (val * (1 * (0 == l))));
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

#include <stdio.h>

#include <stdint.h>

#include <stdlib.h>

#include <string.h>

#include <assert.h>

#include "pubdefs.h"

#include "cuda_/cuda_pscmc_inc.h"

#include "cuda_/inner_split_pass.kernel_inc.h"



#include "cuda_/mergefields.kernel_inc.h"

#include "cuda_/miniblas.kernel_inc.h"

#include "cuda_/general_partial_sort.kernel_inc.h"

#include "cuda_/move_back.kernel_inc.h"

#include "cuda_/particle_iter.kernel_inc.h"


#include "cuda_/geo_yeefdtd.kernel_inc.h"

#include "cuda_yeefdtd.h"

#include "space_filling_curve.h"

#include <cgapsio.h>

int init_parallel_file_for_mpi_fields(Field3D_MPI *pthis, Gaps_IO_DataFile *gid, char *pName, int64_t time_step,
                                      int version, int num_reduce_proc) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;


  //====================Field3D_MPI
  int64_t pdimarr[4];
  int64_t pblkarr[4];
  if ((version == 0)) {
    {

      // defined from class Field3D_Seq

      long xlen = (data)->xlen;

      long ylen = (data)->ylen;

      long zlen = (data)->zlen;


      long x_num_thread_block = (data)->x_num_thread_block;

      long y_num_thread_block = (data)->y_num_thread_block;

      long z_num_thread_block = (data)->z_num_thread_block;


      int num_ele = (data)->num_ele;


      //====================Field3D_Seq
      ((pdimarr)[0] = num_ele);
      ((pdimarr)[1] = (xlen * x_num_thread_block));
      ((pdimarr)[2] = (ylen * y_num_thread_block));
      ((pdimarr)[3] = (zlen * z_num_thread_block));
      GAPS_IO_InitDataInfo(gid, GAPS_IO_FLOAT64, 4, pdimarr);
    }
  } else {
    {

      // defined from class Field3D_Seq

      long xlen = (data)->xlen;

      long ylen = (data)->ylen;

      long zlen = (data)->zlen;


      long x_num_thread_block = (data)->x_num_thread_block;

      long y_num_thread_block = (data)->y_num_thread_block;

      long z_num_thread_block = (data)->z_num_thread_block;


      int num_ele = (data)->num_ele;


      //====================Field3D_Seq
      ((pdimarr)[0] = num_ele);
      ((pdimarr)[1] = xlen);
      ((pdimarr)[2] = ylen);
      ((pdimarr)[3] = zlen);
      ((pblkarr)[0] = 1);
      ((pblkarr)[1] = x_num_thread_block);
      ((pblkarr)[2] = y_num_thread_block);
      ((pblkarr)[3] = z_num_thread_block);
      if ((version == 1)) {
        GAPS_IO_InitDataInfoV1(gid, GAPS_IO_FLOAT64, 4, pdimarr, pblkarr);

      } else {
        if ((version == 2)) {
          long numvec_total = 0;

          {
            long i;

            for ((i = 0); (i < num_runtime); (i = (i + 1))) {

              // defined from class Field3D_Seq


              long numvec = ((data + i))->numvec;


              //====================Field3D_Seq
              (numvec_total = (numvec_total + numvec));
            }
          }
          int64_t *plocations = malloc((sizeof(int64_t) * numvec_total));

          long numvec_offset = 0;

          {
            long r;

            for ((r = 0); (r < num_runtime); (r = (r + 1))) {

              // defined from class Field3D_Seq

              long xlen = ((data + r))->xlen;

              long ylen = ((data + r))->ylen;

              long zlen = ((data + r))->zlen;


              long numvec = ((data + r))->numvec;

              long x_num_thread_block = ((data + r))->x_num_thread_block;

              long y_num_thread_block = ((data + r))->y_num_thread_block;


              long *global_x_offset = ((data + r))->global_x_offset;

              long *global_y_offset = ((data + r))->global_y_offset;

              long *global_z_offset = ((data + r))->global_z_offset;


              //====================Field3D_Seq
              {
                long i;

                for ((i = 0); (i < numvec); (i = (i + 1))) {
                  ((plocations)[(i + numvec_offset)] =
                       (((global_x_offset)[i] / xlen) +
                        (x_num_thread_block *
                         (((global_y_offset)[i] / ylen) + (y_num_thread_block * ((global_z_offset)[i] / zlen))))));
                }
              }
              (numvec_offset = (numvec_offset + numvec));
            }
          }
          GAPS_IO_InitDataInfoV2(gid, "", GAPS_IO_FLOAT64, 4, pdimarr, pblkarr, plocations, numvec_total, 0);
          if (num_reduce_proc) {
            GAPS_IO_SetNumReduceProc(gid, num_reduce_proc);
          }

          free(plocations);
        }
      }
    }
  }

  if ((version >= 2)) {
    GAPS_IO_InitOFile_with_TimeStepV2(gid, pName, (gid)->prefix, time_step);

  } else {
    GAPS_IO_InitOFile_with_TimeStep(gid, pName, time_step);
  }

  GAPS_IO_FileFlush(gid);
  PS_MPI_Barrier(comm);
  return 0;
}

int write_parallel_file_for_mpi_fields(Field3D_MPI *pthis, Gaps_IO_DataFile *gid, int64_t timestep) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  long cur_rank = (pthis)->cur_rank;


  //====================Field3D_MPI
  long i = 0;

  if (((gid)->version == 2)) {
    GAPS_IO_DataSeek(gid, timestep, 0);
  }

  double *write_buffer = NULL;

  for (i = 0; (i < num_runtime); i++) {

    // defined from class Field3D_Seq

    long xlen = ((data + i))->xlen;

    long ylen = ((data + i))->ylen;

    long zlen = ((data + i))->zlen;

    long xblock = ((data + i))->xblock;

    long yblock = ((data + i))->yblock;

    long zblock = ((data + i))->zblock;

    long numvec = ((data + i))->numvec;

    long x_num_thread_block = ((data + i))->x_num_thread_block;

    long y_num_thread_block = ((data + i))->y_num_thread_block;


    int ovlp = ((data + i))->ovlp;

    int num_ele = ((data + i))->num_ele;


    long *global_x_offset = ((data + i))->global_x_offset;

    long *global_y_offset = ((data + i))->global_y_offset;

    long *global_z_offset = ((data + i))->global_z_offset;


    void *main_data = ((data + i))->main_data;


    //====================Field3D_Seq
    double *odata = (((double **)main_data))[0];

    size_t oneblocklen = (xblock * (yblock * (zblock * num_ele)));

    size_t realoneblklen = (xlen * (ylen * (zlen * num_ele)));

    if ((!write_buffer)) {
      (write_buffer = malloc((sizeof(double) * realoneblklen)));
    }

    long vid = 0;

    if (((gid)->version == 2)) {
      if (((cur_rank != (gid)->send_to_proc) && (gid)->num_reduce_proc)) {
        MPI_Send(&(numvec), 1, PS_MPI_LONG, (gid)->send_to_proc, cur_rank, PS_MPI_COMM_WORLD);
      }
    }

    for (vid = 0; (vid < numvec); vid++) {
      if (((gid)->version == 0)) {
        {
          long xyzz;

          for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
            {
              long xyzy;

              for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                {
                  long xyzx;

                  for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1))) {
                    int64_t offsetlen =
                        (num_ele *
                         ((global_x_offset)[vid] +
                          (0 + (xlen * (x_num_thread_block *
                                        (xyzy + ((global_y_offset)[vid] +
                                                 (ylen * (y_num_thread_block * (xyzz + (global_z_offset)[vid]))))))))));

                    GAPS_IO_DataSeek(gid, timestep, offsetlen);
                    GAPS_IO_FWrite(
                        gid,
                        (odata + ((oneblocklen * vid) +
                                  (num_ele * (ovlp + (xblock * (xyzy + (ovlp + (yblock * (ovlp + xyzz))))))))),
                        (num_ele * xlen));
                  }
                }
              }
            }
          }
        }
      } else {
        int64_t offsetlen =
            ((((gid)->version == 1))
                 ? ((realoneblklen * (((global_x_offset)[vid] / xlen) +
                                      (x_num_thread_block * (((global_y_offset)[vid] / ylen) +
                                                             (y_num_thread_block * ((global_z_offset)[vid] / zlen)))))))
                 : ((realoneblklen * vid)));

        if (((gid)->version == 1)) {
          GAPS_IO_DataSeek(gid, timestep, offsetlen);
        }

        {
          long xyzz;

          for ((xyzz = 0); (xyzz < zlen); (xyzz = (xyzz + 1))) {
            {
              long xyzy;

              for ((xyzy = 0); (xyzy < ylen); (xyzy = (xyzy + 1))) {
                {
                  long xyzx;

                  for ((xyzx = 0); (xyzx < xlen); (xyzx = (xyzx + 1))) {
                    {
                      long l;

                      for ((l = 0); (l < num_ele); (l = (l + 1))) {
                        ((write_buffer)[(l + (num_ele * (xyzx + (xlen * (xyzy + (ylen * xyzz))))))] = (odata)[(
                             (oneblocklen * vid) +
                             (l +
                              (num_ele * (xyzx + (ovlp + (xblock * (xyzy + (ovlp + (yblock * (ovlp + xyzz))))))))))]);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        GAPS_IO_FWrite(gid, write_buffer, realoneblklen);
        if ((((gid)->version == 2) && (gid)->num_reduce_proc)) {
          int cur_rank;

          PS_MPI_Comm_rank(PS_MPI_COMM_WORLD, &(cur_rank));
          if (((gid)->cur_rank != (gid)->send_to_proc)) {
            PS_MPI_Send(write_buffer, realoneblklen, PS_MPI_DOUBLE, (gid)->send_to_proc, cur_rank, PS_MPI_COMM_WORLD);
          }
        }
      }
    }
  }
  for (i = 0; (i < num_runtime); i++) {

    // defined from class Field3D_Seq

    long xlen = ((data + i))->xlen;

    long ylen = ((data + i))->ylen;

    long zlen = ((data + i))->zlen;


    int num_ele = ((data + i))->num_ele;


    //====================Field3D_Seq


    size_t realoneblklen = (xlen * (ylen * (zlen * num_ele)));

    if ((((gid)->version == 2) && (gid)->num_reduce_proc)) {
      int cur_rank;

      PS_MPI_Comm_rank(PS_MPI_COMM_WORLD, &(cur_rank));
      if (((gid)->cur_rank != (gid)->send_to_proc)) {

      } else {
        {
          int cur_rank = (gid)->cur_rank;

          int num_reduce_proc = (gid)->num_reduce_proc;

          int real_rank = (gid)->real_rank;

          {
            long n;

            for ((n = (cur_rank + 1)); (n < (num_reduce_proc * (real_rank + 1))); (n = (n + 1))) {
              int num_proc;

              PS_MPI_Comm_size(PS_MPI_COMM_WORLD, &(num_proc));
              if ((n >= num_proc)) {
                break;
              }

              long remote_numvec;

              MPI_Status s1;

              PS_MPI_Recv(&(remote_numvec), 1, PS_MPI_LONG, n, n, PS_MPI_COMM_WORLD, &(s1));
              {
                long g;

                for ((g = 0); (g < remote_numvec); (g = (g + 1))) {
                  PS_MPI_Recv(write_buffer, realoneblklen, PS_MPI_DOUBLE, n, n, PS_MPI_COMM_WORLD, &(s1));
                  GAPS_IO_FWrite(gid, write_buffer, realoneblklen);
                }
              }
            }
          }
        }
      }
    }
  }
  free(write_buffer);
  return 0;
}

int mpi_field_write_to_file(Field3D_MPI *pthis, Gaps_IO_DataFile *pgid, long num_timestep) {

  // defined from class Field3D_MPI


  PS_MPI_Comm comm = (pthis)->comm;


  //====================Field3D_MPI

  PS_MPI_Barrier(comm);
  GAPS_IO_TruncateFile(pgid, (num_timestep + 1), -1);
  PS_MPI_Barrier(comm);
  GAPS_IO_DataSeek(pgid, num_timestep, 0);
  write_parallel_file_for_mpi_fields(pthis, pgid, num_timestep);
  return 0;
}

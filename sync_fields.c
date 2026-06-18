#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "pubdefs.h"

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

#include "mpifields.h"

int merge_ovlp_mpi_field(Field3D_MPI *pthis) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;


  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;


  //====================Field3D_MPI
  long i = 0;

  long num_data = num_runtime;

  size_t all_sync_len[num_data];
  size_t v_offset[num_data];
  for (i = 0; i < num_data; i++) {
    Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one((data + i), 1);

    // defined from class Field3D_Seq

    long xlen = ((data + i))->xlen;

    long ylen = ((data + i))->ylen;

    long zlen = ((data + i))->zlen;

    long xblock = ((data + i))->xblock;

    long yblock = ((data + i))->yblock;

    long zblock = ((data + i))->zblock;

    long numvec = ((data + i))->numvec;


    int num_ele = ((data + i))->num_ele;


    //====================Field3D_Seq
    ((v_offset)[i] = 0);
    ((all_sync_len)[i] = (numvec * (num_ele * ((xblock * (yblock * zblock)) - (xlen * (ylen * zlen))))));
  }
  int fieldid;

  for (fieldid = 0; (fieldid < NUM_SYNC_LAYER); fieldid++) {
    if ((fieldid == (NUM_SYNC_LAYER / 2))) {
      continue;
    }

    for (i = 0; i < num_data; i++) {

      // defined from class Field3D_Seq


      long numvec = ((data + i))->numvec;


      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;


      long *adj_ids = ((data + i))->adj_ids;

      long *adj_processes = ((data + i))->adj_processes;


      //====================Field3D_Seq
      double *sync_mem_host;

      cuda_pscmc_get_h_data((sync_layer_pscmc)[0], &(sync_mem_host));

      if ((fieldid == 0)) {
        cuda_pscmc_mem_sync_d2h((sync_layer_pscmc)[0]);
      }

      int tid;

      long sllen = (sync_layer_len)[fieldid];

      for (tid = 0; (tid < numvec); tid++) {
        double *t0;

        (t0 = (sync_mem_host + (v_offset)[i]));
        int REMOTE_PROC_ID = ((adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid)] / (pthis)->num_runtime);

        {
          if (((adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid)] ==
               (adj_processes)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))])) {
            continue;

          } else {
            PS_MPI_Isend((t0 + (tid * sllen)), sllen, PS_MPI_DOUBLE, REMOTE_PROC_ID,
                         ((NUM_SYNC_LAYER * (adj_ids)[((tid * NUM_SYNC_LAYER) + fieldid)]) + fieldid), comm,
                         ((rqst)[i] + ((tid * NUM_SYNC_LAYER) + fieldid)));
          }
        }
      }
    }
    for (i = 0; i < num_data; i++) {

      // defined from class Field3D_Seq


      long numvec = ((data + i))->numvec;


      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;

      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;


      long *adj_ids = ((data + i))->adj_ids;

      long *adj_processes = ((data + i))->adj_processes;

      long *adj_local_tid = ((data + i))->adj_local_tid;


      //====================Field3D_Seq
      double *sync_mem_host;

      double *swap_mem_host;

      cuda_pscmc_get_h_data((sync_layer_pscmc)[0], &(sync_mem_host));

      cuda_pscmc_get_h_data((swap_layer_pscmc)[0], &(swap_mem_host));

      (swap_mem_host = (swap_mem_host + (all_sync_len)[i]));
      int tid;

      int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);

      double *t1;

      double *t0;

      long sllen = (sync_layer_len)[fieldid1];

      for (tid = 0; (tid < numvec); tid++) {
        (t1 = (swap_mem_host - ((v_offset)[i] + (sllen * numvec))));
        (t0 = (sync_mem_host + (v_offset)[i]));
        {
          long adj_proc_id = (adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid1)];

          int REMOTE_PROC_ID = (adj_proc_id / (pthis)->num_runtime);

          if ((adj_proc_id == (adj_processes)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))])) {
            long t0id = (adj_local_tid)[((tid * NUM_SYNC_LAYER) + fieldid1)];

            memcpy((t1 + (tid * sllen)), (t0 + (t0id * sllen)), (sizeof(double) * sllen));

          } else {
            PS_MPI_Recv((t1 + (tid * sllen)), sllen, PS_MPI_DOUBLE, REMOTE_PROC_ID,
                        ((NUM_SYNC_LAYER * (adj_ids)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))]) +
                         ((NUM_SYNC_LAYER - 1) - fieldid1)),
                        comm, NULL);
          }
        }
      }
      ((v_offset)[i] = ((v_offset)[i] + (sllen * numvec)));
    }
    for (i = 0; i < num_data; i++) {

      // defined from class Field3D_Seq


      long numvec = ((data + i))->numvec;


      long *adj_processes = ((data + i))->adj_processes;


      //====================Field3D_Seq
      int tid;

      for (tid = 0; (tid < numvec); tid++) {
        long adj_proc_id = (adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid)];


        if ((adj_proc_id == (adj_processes)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))])) {
          continue;

        } else {
          PS_MPI_Wait(((rqst)[i] + ((tid * NUM_SYNC_LAYER) + fieldid)), NULL);
        }
      }
    }
  }
  for (i = 0; i < num_data; i++) {

    // defined from class Field3D_Seq


    void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;


    //====================Field3D_Seq
    cuda_pscmc_mem_sync_h2d((swap_layer_pscmc)[0]);

    Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one((data + i), 0);
  }
  return 0;
}

int sync_ovlp_mpi_field(Field3D_MPI *pthis) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  PS_MPI_Comm comm = (pthis)->comm;


  long *sync_layer_len = (pthis)->sync_layer_len;

  PS_MPI_Request **rqst = (pthis)->rqst;


  //====================Field3D_MPI
  long i = 0;

  long num_data = num_runtime;

  size_t all_sync_len[num_data];
  size_t v_offset[num_data];
  for (i = 0; i < num_data; i++) {
    Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one((data + i), 1);

    // defined from class Field3D_Seq

    long xlen = ((data + i))->xlen;

    long ylen = ((data + i))->ylen;

    long zlen = ((data + i))->zlen;

    long xblock = ((data + i))->xblock;

    long yblock = ((data + i))->yblock;

    long zblock = ((data + i))->zblock;

    long numvec = ((data + i))->numvec;


    int num_ele = ((data + i))->num_ele;


    //====================Field3D_Seq
    ((v_offset)[i] = 0);
    ((all_sync_len)[i] = (numvec * (num_ele * ((xblock * (yblock * zblock)) - (xlen * (ylen * zlen))))));
  }
  int fieldid;

  for (fieldid = 0; (fieldid < NUM_SYNC_LAYER); fieldid++) {
    if ((fieldid == (NUM_SYNC_LAYER / 2))) {
      continue;
    }

    for (i = 0; i < num_data; i++) {

      // defined from class Field3D_Seq


      long numvec = ((data + i))->numvec;


      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;


      long *adj_ids = ((data + i))->adj_ids;

      long *adj_processes = ((data + i))->adj_processes;


      //====================Field3D_Seq
      double *sync_mem_host;

      cuda_pscmc_get_h_data((sync_layer_pscmc)[0], &(sync_mem_host));

      if ((fieldid == 0)) {
        cuda_pscmc_mem_sync_d2h((sync_layer_pscmc)[0]);
      }

      int tid;

      long sllen = (sync_layer_len)[fieldid];

      for (tid = 0; (tid < numvec); tid++) {
        double *t0;

        (t0 = (sync_mem_host + (v_offset)[i]));
        int REMOTE_PROC_ID = ((adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid)] / (pthis)->num_runtime);

        {
          if (((adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid)] ==
               (adj_processes)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))])) {
            continue;

          } else {
            PS_MPI_Isend((t0 + (tid * sllen)), sllen, PS_MPI_DOUBLE, REMOTE_PROC_ID,
                         ((NUM_SYNC_LAYER * (adj_ids)[((tid * NUM_SYNC_LAYER) + fieldid)]) + fieldid), comm,
                         ((rqst)[i] + ((tid * NUM_SYNC_LAYER) + fieldid)));
          }
        }
      }
    }
    for (i = 0; i < num_data; i++) {

      // defined from class Field3D_Seq


      long numvec = ((data + i))->numvec;


      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;

      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;


      long *adj_ids = ((data + i))->adj_ids;

      long *adj_processes = ((data + i))->adj_processes;

      long *adj_local_tid = ((data + i))->adj_local_tid;


      //====================Field3D_Seq
      double *sync_mem_host;

      double *swap_mem_host;

      cuda_pscmc_get_h_data((sync_layer_pscmc)[0], &(sync_mem_host));

      cuda_pscmc_get_h_data((swap_layer_pscmc)[0], &(swap_mem_host));

      (swap_mem_host = (swap_mem_host + (all_sync_len)[i]));
      int tid;

      int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);

      double *t1;

      double *t0;

      long sllen = (sync_layer_len)[fieldid1];

      for (tid = 0; (tid < numvec); tid++) {
        (t1 = (swap_mem_host - ((v_offset)[i] + (sllen * numvec))));
        (t0 = (sync_mem_host + (v_offset)[i]));
        {
          long adj_proc_id = (adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid1)];

          int REMOTE_PROC_ID = (adj_proc_id / (pthis)->num_runtime);

          if ((adj_proc_id == (adj_processes)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))])) {
            long t0id = (adj_local_tid)[((tid * NUM_SYNC_LAYER) + fieldid1)];

            memcpy((t1 + (tid * sllen)), (t0 + (t0id * sllen)), (sizeof(double) * sllen));

          } else {
            PS_MPI_Recv((t1 + (tid * sllen)), sllen, PS_MPI_DOUBLE, REMOTE_PROC_ID,
                        ((NUM_SYNC_LAYER * (adj_ids)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))]) +
                         ((NUM_SYNC_LAYER - 1) - fieldid1)),
                        comm, NULL);
          }
        }
      }
      ((v_offset)[i] = ((v_offset)[i] + (sllen * numvec)));
    }
    for (i = 0; i < num_data; i++) {

      // defined from class Field3D_Seq


      long numvec = ((data + i))->numvec;


      long *adj_processes = ((data + i))->adj_processes;


      //====================Field3D_Seq
      int tid;

      for (tid = 0; (tid < numvec); tid++) {
        long adj_proc_id = (adj_processes)[((tid * NUM_SYNC_LAYER) + fieldid)];


        if ((adj_proc_id == (adj_processes)[((tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2))])) {
          continue;

        } else {
          PS_MPI_Wait(((rqst)[i] + ((tid * NUM_SYNC_LAYER) + fieldid)), NULL);
        }
      }
    }
  }
  for (i = 0; i < num_data; i++) {

    // defined from class Field3D_Seq


    void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;


    //====================Field3D_Seq
    cuda_pscmc_mem_sync_h2d((swap_layer_pscmc)[0]);

    Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one((data + i), 0);
  }
  return 0;
}

int sync_main_data_d2h(Field3D_MPI *pthis) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  long i = 0;

  for (i = 0; i < num_runtime; i++) {

    // defined from class Field3D_Seq


    void *main_data = ((data + i))->main_data;


    //====================Field3D_Seq
    cuda_pscmc_mem_sync_d2h(main_data);
  }
  return 0;
}
int sync_main_data_h2d(Field3D_MPI *pthis) {

  // defined from class Field3D_MPI
  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  //====================Field3D_MPI
  long i = 0;

  for (i = 0; i < num_runtime; i++) {

    // defined from class Field3D_Seq


    void *main_data = ((data + i))->main_data;


    //====================Field3D_Seq
    cuda_pscmc_mem_sync_h2d(main_data);
  }
  return 0;
}

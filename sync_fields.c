#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <assert.h>

#include <stddef.h>

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

#include "mpifields.h"

/* USENCCL Precompute self/same-rank recv mapping.  
   adj_ids/adj_processes/adj_local_tid never change after init. */
static void build_local_recv_cache(Field3D_Seq *data, long num_runtime, long cur_rank) {
  long numvec = data->numvec;
  long *adjp = data->adj_processes;
  long *adjl = data->adj_local_tid;
  for (int fid = 0; fid < NUM_SYNC_LAYER; fid++) {
    if (fid == NUM_SYNC_LAYER / 2) continue;
    int fid1 = NUM_SYNC_LAYER - 1 - fid;
    long n = 0;
    for (long tid = 0; tid < numvec; tid++) {
      long ap = adjp[tid * NUM_SYNC_LAYER + fid1];
      if (ap == adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)]) n++;
      else if (ap / num_runtime == cur_rank) n++;
    }
    data->local_recv_count[fid] = n;
    if (n == 0) continue;
    data->local_recv_tid[fid]  = (long *)malloc(n * sizeof(long));
    data->local_recv_src[fid]  = (long *)malloc(n * sizeof(long));
    data->local_recv_peer[fid] = (int  *)malloc(n * sizeof(int));
    long k = 0;
    for (long tid = 0; tid < numvec; tid++) {
      long ap = adjp[tid * NUM_SYNC_LAYER + fid1];
      long t0 = adjl[tid * NUM_SYNC_LAYER + fid1];
      if (ap == adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)]) {
        data->local_recv_tid[fid][k]  = tid;
        data->local_recv_src[fid][k]  = t0;
        data->local_recv_peer[fid][k] = -1;
        k++;
      } else if (ap / num_runtime == cur_rank) {
        data->local_recv_tid[fid][k]  = tid;
        data->local_recv_src[fid][k]  = t0;
        data->local_recv_peer[fid][k] = (int)(ap % num_runtime);
        k++;
      }
    }
  }
  data->cache_valid = 1;
}
/* USENCCL end */

int merge_ovlp_mpi_field(Field3D_MPI *pthis) {

  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  long *sync_layer_len = (pthis)->sync_layer_len;


  long i = 0;

  long num_data = num_runtime;
  /* USENCCL */
  for (i = 0; i < num_data; i++)
    if (!data[i].cache_valid)
      build_local_recv_cache(&data[i], num_runtime, pthis->cur_rank);
  /* USENCCL end */
  size_t all_sync_len[num_data];
  size_t v_offset[num_data];
  for (i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one((data + i), 1);

    long xlen = ((data + i))->xlen;
    long ylen = ((data + i))->ylen;
    long zlen = ((data + i))->zlen;
    long xblock = ((data + i))->xblock;
    long yblock = ((data + i))->yblock;
    long zblock = ((data + i))->zblock;
    long numvec = ((data + i))->numvec;
    int num_ele = ((data + i))->num_ele;

    ((v_offset)[i] = 0);
    ((all_sync_len)[i] = (numvec * (num_ele * ((xblock * (yblock * zblock)) - (xlen * (ylen * zlen))))));
  }
  int fieldid;

  /* USENCCL: field exchange via NCCL  */
  ncclGroupStart();
  for (fieldid = 0; (fieldid < NUM_SYNC_LAYER); fieldid++) {
    if ((fieldid == (NUM_SYNC_LAYER / 2))) {
      continue;
    }

    size_t recv_offset[num_data];
    for (i = 0; i < num_data; i++) {
      recv_offset[i] = v_offset[i];
    }

    for (i = 0; i < num_data; i++) {
      cudaSetDevice(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;

      cuda_pscmc_mem *sync_mem = (cuda_pscmc_mem *)(sync_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);

      int tid;

      long sllen = (sync_layer_len)[fieldid];

      /* sends sorted by adj_ids[tid*27+fieldid] (receiver subdomain ID) for NCCL order match */
      {
        long send_count = 0;
        for (tid = 0; tid < numvec; tid++) {
          long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid];
          if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
          if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
          send_count++;
        }
        char *sent = (char *)alloca(numvec);
        memset(sent, 0, numvec);
        for (long pass = 0; pass < send_count; pass++) {
          long best_tid = -1, best_key = -1;
          for (tid = 0; tid < numvec; tid++) {
            if (sent[tid]) continue;
            long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid];
            if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
            if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
            long key = (adj_ids)[(tid * NUM_SYNC_LAYER) + fieldid];
            if (best_tid == -1 || key < best_key) { best_tid = tid; best_key = key; }
          }
          sent[best_tid] = 1;
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid];
          ncclSend(sync_d_data + (v_offset)[i] + best_tid * sllen, sllen, ncclDouble,
                   peer, pthis->nccl_comm[i], 0);
        }
      }
    }
    for (i = 0; i < num_data; i++) {
      cudaSetDevice(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;
      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;
      long *adj_local_tid = ((data + i))->adj_local_tid;

      cuda_pscmc_mem *sync_mem = (cuda_pscmc_mem *)(sync_layer_pscmc[0]);
      cuda_pscmc_mem *swap_mem = (cuda_pscmc_mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = (double *)(swap_mem->d_data);

      (swap_d_data = (swap_d_data + (all_sync_len)[i]));
      int tid;

      int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);

      double *t1;
      double *t0;

      long sllen = (sync_layer_len)[fieldid1];

      /* self/same-rank recvs: iterate precomputed list */
      {
        long *lr_tid  = data[i].local_recv_tid[fieldid];
        long *lr_src  = data[i].local_recv_src[fieldid];
        int  *lr_peer = data[i].local_recv_peer[fieldid];
        long  lr_n    = data[i].local_recv_count[fieldid];
        for (long k = 0; k < lr_n; k++) {
          long _t = lr_tid[k], _s = lr_src[k];
          int  _p = lr_peer[k];
          if (_p < 0)
            cudaMemcpy(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + _t * sllen,
                       sync_d_data + (recv_offset)[i] + _s * sllen,
                       sizeof(double) * sllen, cudaMemcpyDeviceToDevice);
          else {
            cuda_pscmc_mem *sm = (cuda_pscmc_mem *)(data[_p].sync_layer_pscmc[0]);
            cudaMemcpyPeer(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + _t * sllen,
                           data[i].cuda_device,
                           ((double *)(sm->d_data)) + (recv_offset)[_p] + _s * sllen,
                           data[_p].cuda_device, sizeof(double) * sllen);
          }
        }
      }

      /* remote recvs sorted by adj_ids[tid*27+13] (receiver subdomain ID) for NCCL order match */
      {
        long recv_count = 0;
        for (tid = 0; tid < numvec; tid++) {
          long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid1];
          if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
          if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
          recv_count++;
        }
        char *recvd = (char *)alloca(numvec);
        memset(recvd, 0, numvec);
        for (long pass = 0; pass < recv_count; pass++) {
          long best_tid = -1, best_key = -1;
          for (tid = 0; tid < numvec; tid++) {
            if (recvd[tid]) continue;
            long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid1];
            if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
            if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
            long key = (adj_ids)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)];
            if (best_tid == -1 || key < best_key) { best_tid = tid; best_key = key; }
          }
          recvd[best_tid] = 1;
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid1];
          ncclRecv(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + best_tid * sllen,
                   sllen, ncclDouble, peer, pthis->nccl_comm[i], 0);
        }
      }
      ((v_offset)[i] = ((recv_offset)[i] + (sllen * numvec)));
    }
  }
  ncclGroupEnd(); /* USENCCL end */
  for (i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    cudaError_t sync_err = cudaDeviceSynchronize();
    if (sync_err != cudaSuccess) {
      fprintf(stderr, "cudaDeviceSynchronize failed in merge: err=%s runtime=%ld dev=%d\n",
              cudaGetErrorString(sync_err), i, data[i].cuda_device);
      assert(0);
    }
  }

  for (i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);

    void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

    Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one((data + i), 0);
  }
  return 0;
}

int sync_ovlp_mpi_field(Field3D_MPI *pthis) {

  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  long *sync_layer_len = (pthis)->sync_layer_len;


  long i = 0;

  long num_data = num_runtime;
  /* USENCCL */
  for (i = 0; i < num_data; i++)
    if (!data[i].cache_valid)
      build_local_recv_cache(&data[i], num_runtime, pthis->cur_rank);
  /* USENCCL end */
  size_t all_sync_len[num_data];
  size_t v_offset[num_data];
  for (i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one((data + i), 1);

    long xlen = ((data + i))->xlen;
    long ylen = ((data + i))->ylen;
    long zlen = ((data + i))->zlen;
    long xblock = ((data + i))->xblock;
    long yblock = ((data + i))->yblock;
    long zblock = ((data + i))->zblock;
    long numvec = ((data + i))->numvec;
    int num_ele = ((data + i))->num_ele;

    ((v_offset)[i] = 0);
    ((all_sync_len)[i] = (numvec * (num_ele * ((xblock * (yblock * zblock)) - (xlen * (ylen * zlen))))));
  }
  int fieldid;

  /* USENCCL: field exchange via NCCL (replaces MPI) */
  ncclGroupStart();
  for (fieldid = 0; (fieldid < NUM_SYNC_LAYER); fieldid++) {
    if ((fieldid == (NUM_SYNC_LAYER / 2))) {
      continue;
    }

    size_t recv_offset[num_data];
    for (i = 0; i < num_data; i++) {
      recv_offset[i] = v_offset[i];
    }

    for (i = 0; i < num_data; i++) {
      cudaSetDevice(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;

      cuda_pscmc_mem *sync_mem = (cuda_pscmc_mem *)(sync_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);

      int tid;

      long sllen = (sync_layer_len)[fieldid];

      /* sends sorted by adj_ids[tid*27+fieldid] (receiver subdomain ID) for NCCL order match */
      {
        long send_count = 0;
        for (tid = 0; tid < numvec; tid++) {
          long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid];
          if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
          if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
          send_count++;
        }
        char *sent = (char *)alloca(numvec);
        memset(sent, 0, numvec);
        for (long pass = 0; pass < send_count; pass++) {
          long best_tid = -1, best_key = -1;
          for (tid = 0; tid < numvec; tid++) {
            if (sent[tid]) continue;
            long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid];
            if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
            if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
            long key = (adj_ids)[(tid * NUM_SYNC_LAYER) + fieldid];
            if (best_tid == -1 || key < best_key) { best_tid = tid; best_key = key; }
          }
          sent[best_tid] = 1;
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid];
          ncclSend(sync_d_data + (v_offset)[i] + best_tid * sllen, sllen, ncclDouble,
                   peer, pthis->nccl_comm[i], 0);
        }
      }
    }
    for (i = 0; i < num_data; i++) {
      cudaSetDevice(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;
      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;
      long *adj_local_tid = ((data + i))->adj_local_tid;

      cuda_pscmc_mem *sync_mem = (cuda_pscmc_mem *)(sync_layer_pscmc[0]);
      cuda_pscmc_mem *swap_mem = (cuda_pscmc_mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = (double *)(swap_mem->d_data);

      (swap_d_data = (swap_d_data + (all_sync_len)[i]));
      int tid;

      int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);

      double *t1;
      double *t0;

      long sllen = (sync_layer_len)[fieldid1];

      /* self/same-rank recvs: iterate precomputed list */
      {
        long *lr_tid  = data[i].local_recv_tid[fieldid];
        long *lr_src  = data[i].local_recv_src[fieldid];
        int  *lr_peer = data[i].local_recv_peer[fieldid];
        long  lr_n    = data[i].local_recv_count[fieldid];
        for (long k = 0; k < lr_n; k++) {
          long _t = lr_tid[k], _s = lr_src[k];
          int  _p = lr_peer[k];
          if (_p < 0)
            cudaMemcpy(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + _t * sllen,
                       sync_d_data + (recv_offset)[i] + _s * sllen,
                       sizeof(double) * sllen, cudaMemcpyDeviceToDevice);
          else {
            cuda_pscmc_mem *sm = (cuda_pscmc_mem *)(data[_p].sync_layer_pscmc[0]);
            cudaMemcpyPeer(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + _t * sllen,
                           data[i].cuda_device,
                           ((double *)(sm->d_data)) + (recv_offset)[_p] + _s * sllen,
                           data[_p].cuda_device, sizeof(double) * sllen);
          }
        }
      }

      /* remote recvs sorted by adj_ids[tid*27+13] (receiver subdomain ID) for NCCL order match */
      {
        long recv_count = 0;
        for (tid = 0; tid < numvec; tid++) {
          long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid1];
          if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
          if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
          recv_count++;
        }
        char *recvd = (char *)alloca(numvec);
        memset(recvd, 0, numvec);
        for (long pass = 0; pass < recv_count; pass++) {
          long best_tid = -1, best_key = -1;
          for (tid = 0; tid < numvec; tid++) {
            if (recvd[tid]) continue;
            long p = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid1];
            if (p == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) continue;
            if ((p / (pthis)->num_runtime) == (pthis)->cur_rank) continue;
            long key = (adj_ids)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)];
            if (best_tid == -1 || key < best_key) { best_tid = tid; best_key = key; }
          }
          recvd[best_tid] = 1;
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid1];
          ncclRecv(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + best_tid * sllen,
                   sllen, ncclDouble, peer, pthis->nccl_comm[i], 0);
        }
      }
      ((v_offset)[i] = ((recv_offset)[i] + (sllen * numvec)));
    }
  }
  ncclGroupEnd(); 
  /* USENCCL end */
  for (i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    cudaError_t sync_err = cudaDeviceSynchronize();
    if (sync_err != cudaSuccess) {
      fprintf(stderr, "cudaDeviceSynchronize failed in sync: err=%s runtime=%ld dev=%d\n",
              cudaGetErrorString(sync_err), i, data[i].cuda_device);
      assert(0);
    }
  }

  for (i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);

    void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

    Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one((data + i), 0);
  }
  return 0;
}

int sync_main_data_d2h(Field3D_MPI *pthis) {

  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  long i = 0;

  for (i = 0; i < num_runtime; i++) {
    cudaSetDevice(data[i].cuda_device);

    void *main_data = ((data + i))->main_data;

    cuda_pscmc_mem_sync_d2h(main_data);
  }
  return 0;
}
int sync_main_data_h2d(Field3D_MPI *pthis) {

  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;


  long i = 0;

  for (i = 0; i < num_runtime; i++) {
    cudaSetDevice(data[i].cuda_device);

    void *main_data = ((data + i))->main_data;

    cuda_pscmc_mem_sync_h2d(main_data);
  }
  return 0;
}

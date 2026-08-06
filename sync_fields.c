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

void copy_between_devices(double *dst, int dst_dev, const double *src, int src_dev, size_t bytes) {
  if (bytes == 0) {
    return;
  }

  if (dst_dev == src_dev) {
    cudaSetDevice(dst_dev);
    cudaError_t err = cudaMemcpy(dst, src, bytes, cudaMemcpyDeviceToDevice);
    ERROPT(err, "cudaMemcpyDeviceToDevice failed in overlap copy");
    return;
  }

  cudaSetDevice(dst_dev);
  cudaError_t err = cudaMemcpyPeer(dst, dst_dev, src, src_dev, bytes);
  if (err == cudaSuccess) {
    return;
  }

  cudaGetLastError();
  void *host_buf = malloc(bytes);
  assert(host_buf);

  cudaSetDevice(src_dev);
  err = cudaMemcpy(host_buf, src, bytes, cudaMemcpyDeviceToHost);
  ERROPT(err, "cudaMemcpyDeviceToHost fallback failed in overlap copy");

  cudaSetDevice(dst_dev);
  err = cudaMemcpy(dst, host_buf, bytes, cudaMemcpyHostToDevice);
  ERROPT(err, "cudaMemcpyHostToDevice fallback failed in overlap copy");

  free(host_buf);
}

int merge_ovlp_mpi_field(Field3D_MPI *pthis) {

  Field3D_Seq *data = (pthis)->data;

  long num_runtime = (pthis)->num_runtime;

  long *sync_layer_len = (pthis)->sync_layer_len;


  long i = 0;

  long num_data = num_runtime;

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

      /* self and same-rank recvs (not part of NCCL group ordering) */
      for (tid = 0; tid < numvec; tid++) {
        long adj_proc_id = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid1];
        int REMOTE_PROC_ID = (adj_proc_id / (pthis)->num_runtime);
        if (adj_proc_id == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) {
          long t0id = (adj_local_tid)[(tid * NUM_SYNC_LAYER) + fieldid1];
          copy_between_devices(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + tid * sllen,
                               data[i].cuda_device,
                               sync_d_data + (recv_offset)[i] + t0id * sllen,
                               data[i].cuda_device, sizeof(double) * sllen);
        } else if (REMOTE_PROC_ID == (pthis)->cur_rank) {
          long src_runtime = (adj_proc_id % (pthis)->num_runtime);
          int src_dev = data[src_runtime].cuda_device;
          cuda_pscmc_mem *src_sync_mem = (cuda_pscmc_mem *)(((data + src_runtime)->sync_layer_pscmc)[0]);
          double *src_sync = (double *)(src_sync_mem->d_data);
          long src_tid = (adj_local_tid)[(tid * NUM_SYNC_LAYER) + fieldid1];
          copy_between_devices(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + tid * sllen,
                               data[i].cuda_device,
                               src_sync + (recv_offset)[src_runtime] + (src_tid * sllen),
                               src_dev, sizeof(double) * sllen);
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

      /* self and same-rank recvs (not part of NCCL group ordering) */
      for (tid = 0; tid < numvec; tid++) {
        long adj_proc_id = (adj_processes)[(tid * NUM_SYNC_LAYER) + fieldid1];
        int REMOTE_PROC_ID = (adj_proc_id / (pthis)->num_runtime);
        if (adj_proc_id == (adj_processes)[(tid * NUM_SYNC_LAYER) + (NUM_SYNC_LAYER / 2)]) {
          long t0id = (adj_local_tid)[(tid * NUM_SYNC_LAYER) + fieldid1];
          copy_between_devices(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + tid * sllen,
                               data[i].cuda_device,
                               sync_d_data + (recv_offset)[i] + t0id * sllen,
                               data[i].cuda_device, sizeof(double) * sllen);
        } else if (REMOTE_PROC_ID == (pthis)->cur_rank) {
          long src_runtime = (adj_proc_id % (pthis)->num_runtime);
          int src_dev = data[src_runtime].cuda_device;
          cuda_pscmc_mem *src_sync_mem = (cuda_pscmc_mem *)(((data + src_runtime)->sync_layer_pscmc)[0]);
          double *src_sync = (double *)(src_sync_mem->d_data);
          long src_tid = (adj_local_tid)[(tid * NUM_SYNC_LAYER) + fieldid1];
          copy_between_devices(swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + tid * sllen,
                               data[i].cuda_device,
                               src_sync + (recv_offset)[src_runtime] + (src_tid * sllen),
                               src_dev, sizeof(double) * sllen);
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

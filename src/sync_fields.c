#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include <assert.h>

#include <stddef.h>

#include "pubdefs.h"

#include "kernel_includes.h"

#include "mpifields.h"

typedef struct {
  long key;
  long tid;
} SyncOrderEntry;

static int cmp_sync_order_entry(const void *a, const void *b) {
  const SyncOrderEntry *ea = (const SyncOrderEntry *)a;
  const SyncOrderEntry *eb = (const SyncOrderEntry *)b;
  if (ea->key < eb->key) return -1;
  if (ea->key > eb->key) return 1;
  if (ea->tid < eb->tid) return -1;
  if (ea->tid > eb->tid) return 1;
  return 0;
}

static void enqueue_local_recv_copies(Field3D_Seq *data, long data_id, int fieldid,
                                      size_t *recv_offset, long numvec, long sllen,
                                      double *swap_d_data, double *sync_d_data) {
  long *lr_tid  = data[data_id].local_recv_tid[fieldid];
  long *lr_src  = data[data_id].local_recv_src[fieldid];
  int  *lr_peer = data[data_id].local_recv_peer[fieldid];
  long  lr_n    = data[data_id].local_recv_count[fieldid];
  long k = 0;
  while (k < lr_n) {
    long dst0 = lr_tid[k];
    long src0 = lr_src[k];
    int peer = lr_peer[k];
    long run = 1;
    while (k + run < lr_n &&
           lr_peer[k + run] == peer &&
           lr_tid[k + run] == dst0 + run &&
           lr_src[k + run] == src0 + run) {
      run++;
    }

    double *dst = swap_d_data - (recv_offset[data_id] + (sllen * numvec)) + dst0 * sllen;
    size_t bytes = sizeof(double) * sllen * run;
    int err;
    if (peer < 0) {
      double *src = sync_d_data + recv_offset[data_id] + src0 * sllen;
      err = sympic_copy_local_async(dst, src, bytes);
    } else {
      SymPIC_Device_Mem *sm = (SymPIC_Device_Mem *)(data[peer].sync_layer_pscmc[0]);
      double *src = ((double *)(sm->d_data)) + recv_offset[peer] + src0 * sllen;
      err = sympic_copy_peer_async(dst, data[data_id].cuda_device,
                                   src, data[peer].cuda_device, bytes);
    }
    if (err != 0) {
      fprintf(stderr, "local recv copy failed: err=%s dst_runtime=%ld peer=%d bytes=%zu\n",
              sympic_device_error_string(err), data_id, peer, bytes);
      assert(0);
    }
    k += run;
  }
}

/* USENCCL Precompute self/same-rank recv mapping.
   adj_ids/adj_processes/adj_local_tid never change after init. */
static void build_local_recv_cache(Field3D_Seq *data, long num_runtime, long cur_rank) {
  long numvec = data->numvec;
  long *adjp = data->adj_processes;
  long *adji = data->adj_ids;
  long *adjl = data->adj_local_tid;
  for (int fid = 0; fid < NUM_SYNC_LAYER; fid++) {
    if (fid == NUM_SYNC_LAYER / 2) continue;
    int fid1 = NUM_SYNC_LAYER - 1 - fid;
    long n = 0, ns = 0, nr = 0;
    for (long tid = 0; tid < numvec; tid++) {
      long ap = adjp[tid * NUM_SYNC_LAYER + fid1];
      if (ap == adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)]) n++;
      else if (ap / num_runtime == cur_rank) n++;

      ap = adjp[tid * NUM_SYNC_LAYER + fid];
      if (ap != adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)] &&
          ap / num_runtime != cur_rank)
        ns++;

      ap = adjp[tid * NUM_SYNC_LAYER + fid1];
      if (ap != adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)] &&
          ap / num_runtime != cur_rank)
        nr++;
    }
    data->local_recv_count[fid] = n;
    data->remote_send_count[fid] = ns;
    data->remote_recv_count[fid] = nr;
    if (n > 0) {
      data->local_recv_tid[fid]  = (long *)malloc(n * sizeof(long));
      data->local_recv_src[fid]  = (long *)malloc(n * sizeof(long));
      data->local_recv_peer[fid] = (int  *)malloc(n * sizeof(int));
    }
    if (ns > 0)
      data->remote_send_tid[fid] = (long *)malloc(ns * sizeof(long));
    if (nr > 0)
      data->remote_recv_tid[fid] = (long *)malloc(nr * sizeof(long));

    SyncOrderEntry *send_order = ns ? (SyncOrderEntry *)malloc(ns * sizeof(SyncOrderEntry)) : NULL;
    SyncOrderEntry *recv_order = nr ? (SyncOrderEntry *)malloc(nr * sizeof(SyncOrderEntry)) : NULL;
    long k = 0;
    long ks = 0;
    long kr = 0;
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

      ap = adjp[tid * NUM_SYNC_LAYER + fid];
      if (ap != adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)] &&
          ap / num_runtime != cur_rank) {
        send_order[ks].key = adji[tid * NUM_SYNC_LAYER + fid];
        send_order[ks].tid = tid;
        ks++;
      }

      ap = adjp[tid * NUM_SYNC_LAYER + fid1];
      if (ap != adjp[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)] &&
          ap / num_runtime != cur_rank) {
        recv_order[kr].key = adji[tid * NUM_SYNC_LAYER + (NUM_SYNC_LAYER / 2)];
        recv_order[kr].tid = tid;
        kr++;
      }
    }

    if (ns > 0) {
      qsort(send_order, ns, sizeof(SyncOrderEntry), cmp_sync_order_entry);
      for (long x = 0; x < ns; x++) data->remote_send_tid[fid][x] = send_order[x].tid;
      free(send_order);
    }
    if (nr > 0) {
      qsort(recv_order, nr, sizeof(SyncOrderEntry), cmp_sync_order_entry);
      for (long x = 0; x < nr; x++) data->remote_recv_tid[fid][x] = recv_order[x].tid;
      free(recv_order);
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
    sympic_set_device(data[i].cuda_device);
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
  sympic_comm_group_start();
  for (fieldid = 0; (fieldid < NUM_SYNC_LAYER); fieldid++) {
    if ((fieldid == (NUM_SYNC_LAYER / 2))) {
      continue;
    }

    size_t recv_offset[num_data];
    for (i = 0; i < num_data; i++) {
      recv_offset[i] = v_offset[i];
    }

    for (i = 0; i < num_data; i++) {
      sympic_set_device(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;
      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;

      SymPIC_Device_Mem *sync_mem = (SymPIC_Device_Mem *)(sync_layer_pscmc[0]);
      SymPIC_Device_Mem *swap_mem = (SymPIC_Device_Mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = (double *)(swap_mem->d_data);

      (swap_d_data = (swap_d_data + (all_sync_len)[i]));

      int tid;

      long sllen = (sync_layer_len)[fieldid];

      /* self/same-rank recvs: async copies on default stream, enqueued BEFORE
         NCCL sends so they do not wait for peer arrival */
      {
        int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);
        long sllen1 = (sync_layer_len)[fieldid1];
        enqueue_local_recv_copies(data, i, fieldid, recv_offset, numvec,
                                  sllen1, swap_d_data, sync_d_data);
      }

      /* sends sorted by adj_ids[tid*27+fieldid] (receiver subdomain ID) for NCCL order match */
      {
        long send_count = data[i].remote_send_count[fieldid];
        long *send_tid = data[i].remote_send_tid[fieldid];
        for (long pass = 0; pass < send_count; pass++) {
          long best_tid = send_tid[pass];
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid];
          sympic_comm_send_double(sync_d_data + (v_offset)[i] + best_tid * sllen,
                                  sllen, peer, pthis->device_comm[i]);
        }
      }
    }
    for (i = 0; i < num_data; i++) {
      sympic_set_device(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;
      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;
      long *adj_local_tid = ((data + i))->adj_local_tid;

      SymPIC_Device_Mem *sync_mem = (SymPIC_Device_Mem *)(sync_layer_pscmc[0]);
      SymPIC_Device_Mem *swap_mem = (SymPIC_Device_Mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = (double *)(swap_mem->d_data);

      (swap_d_data = (swap_d_data + (all_sync_len)[i]));
      int tid;

      int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);

      double *t1;
      double *t0;

      long sllen = (sync_layer_len)[fieldid1];

      /* remote recvs sorted by adj_ids[tid*27+13] (receiver subdomain ID) for NCCL order match */
      {
        long recv_count = data[i].remote_recv_count[fieldid];
        long *recv_tid = data[i].remote_recv_tid[fieldid];
        for (long pass = 0; pass < recv_count; pass++) {
          long best_tid = recv_tid[pass];
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid1];
          sympic_comm_recv_double(
              swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + best_tid * sllen,
              sllen, peer, pthis->device_comm[i]);
        }
      }
      ((v_offset)[i] = ((recv_offset)[i] + (sllen * numvec)));
    }
  }
  sympic_comm_group_end(); /* USENCCL end */
  for (i = 0; i < num_data; i++) {
    sympic_set_device(data[i].cuda_device);
    int sync_err = sympic_device_synchronize();
    if (sync_err != 0) {
      fprintf(stderr, "sympic_device_synchronize failed in merge: err=%s runtime=%ld dev=%d\n",
              sympic_device_error_string(sync_err), i, data[i].cuda_device);
      assert(0);
    }
  }

  for (i = 0; i < num_data; i++) {
    sympic_set_device(data[i].cuda_device);

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
    sympic_set_device(data[i].cuda_device);
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
  sympic_comm_group_start();
  for (fieldid = 0; (fieldid < NUM_SYNC_LAYER); fieldid++) {
    if ((fieldid == (NUM_SYNC_LAYER / 2))) {
      continue;
    }

    size_t recv_offset[num_data];
    for (i = 0; i < num_data; i++) {
      recv_offset[i] = v_offset[i];
    }

    for (i = 0; i < num_data; i++) {
      sympic_set_device(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;
      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;

      SymPIC_Device_Mem *sync_mem = (SymPIC_Device_Mem *)(sync_layer_pscmc[0]);
      SymPIC_Device_Mem *swap_mem = (SymPIC_Device_Mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = (double *)(swap_mem->d_data);

      (swap_d_data = (swap_d_data + (all_sync_len)[i]));

      int tid;

      long sllen = (sync_layer_len)[fieldid];

      /* self/same-rank recvs: async copies on default stream, enqueued BEFORE
         NCCL sends so they do not wait for peer arrival */
      {
        int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);
        long sllen1 = (sync_layer_len)[fieldid1];
        enqueue_local_recv_copies(data, i, fieldid, recv_offset, numvec,
                                  sllen1, swap_d_data, sync_d_data);
      }

      /* sends sorted by adj_ids[tid*27+fieldid] (receiver subdomain ID) for NCCL order match */
      {
        long send_count = data[i].remote_send_count[fieldid];
        long *send_tid = data[i].remote_send_tid[fieldid];
        for (long pass = 0; pass < send_count; pass++) {
          long best_tid = send_tid[pass];
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid];
          sympic_comm_send_double(sync_d_data + (v_offset)[i] + best_tid * sllen,
                                  sllen, peer, pthis->device_comm[i]);
        }
      }
    }
    for (i = 0; i < num_data; i++) {
      sympic_set_device(data[i].cuda_device);

      long numvec = ((data + i))->numvec;

      void **sync_layer_pscmc = ((data + i))->sync_layer_pscmc;
      void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

      long *adj_ids = ((data + i))->adj_ids;
      long *adj_processes = ((data + i))->adj_processes;
      long *adj_local_tid = ((data + i))->adj_local_tid;

      SymPIC_Device_Mem *sync_mem = (SymPIC_Device_Mem *)(sync_layer_pscmc[0]);
      SymPIC_Device_Mem *swap_mem = (SymPIC_Device_Mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = (double *)(swap_mem->d_data);

      (swap_d_data = (swap_d_data + (all_sync_len)[i]));
      int tid;

      int fieldid1 = ((NUM_SYNC_LAYER - 1) - fieldid);

      double *t1;
      double *t0;

      long sllen = (sync_layer_len)[fieldid1];

      /* remote recvs sorted by adj_ids[tid*27+13] (receiver subdomain ID) for NCCL order match */
      {
        long recv_count = data[i].remote_recv_count[fieldid];
        long *recv_tid = data[i].remote_recv_tid[fieldid];
        for (long pass = 0; pass < recv_count; pass++) {
          long best_tid = recv_tid[pass];
          long peer = (adj_processes)[(best_tid * NUM_SYNC_LAYER) + fieldid1];
          sympic_comm_recv_double(
              swap_d_data - ((recv_offset)[i] + (sllen * numvec)) + best_tid * sllen,
              sllen, peer, pthis->device_comm[i]);
        }
      }
      ((v_offset)[i] = ((recv_offset)[i] + (sllen * numvec)));
    }
  }
  sympic_comm_group_end();
  /* USENCCL end */
  for (i = 0; i < num_data; i++) {
    sympic_set_device(data[i].cuda_device);
    int sync_err = sympic_device_synchronize();
    if (sync_err != 0) {
      fprintf(stderr, "sympic_device_synchronize failed in sync: err=%s runtime=%ld dev=%d\n",
              sympic_device_error_string(sync_err), i, data[i].cuda_device);
      assert(0);
    }
  }

  for (i = 0; i < num_data; i++) {
    sympic_set_device(data[i].cuda_device);

    void **swap_layer_pscmc = ((data + i))->swap_layer_pscmc;

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
#ifdef SYMPIC_CUDA
    cuda_pscmc_mem_sync_d2h(main_data);
#elif defined(SYMPIC_MAPU)
    mapu_pscmc_mem_sync_d2h(main_data);
#endif

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
#ifdef SYMPIC_CUDA
    cuda_pscmc_mem_sync_h2d(main_data);
#elif defined(SYMPIC_MAPU)
    mapu_pscmc_mem_sync_h2d(main_data);
#endif

  }
  return 0;
}

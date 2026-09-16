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

#include "local_halo_copy.h"

typedef struct {
  long key;
  long tid;
} SyncOrderEntry;

/* USENCCL: one entry per remote field-halo segment.  Entries are grouped by
   peer so each peer gets a single packed ncclSend/ncclRecv per phase. */
typedef struct {
  int peer;
  int phase;
  long key;
  long tid;
  long src_offset;
  long dst_offset;
  long len;
} FieldHaloEntry;

static int cmp_sync_order_entry(const void *a, const void *b) {
  const SyncOrderEntry *ea = (const SyncOrderEntry *)a;
  const SyncOrderEntry *eb = (const SyncOrderEntry *)b;
  if (ea->key < eb->key) return -1;
  if (ea->key > eb->key) return 1;
  if (ea->tid < eb->tid) return -1;
  if (ea->tid > eb->tid) return 1;
  return 0;
}

static int cmp_field_halo_entry(const void *a, const void *b) {
  const FieldHaloEntry *ea = (const FieldHaloEntry *)a;
  const FieldHaloEntry *eb = (const FieldHaloEntry *)b;
  if (ea->peer < eb->peer) return -1;
  if (ea->peer > eb->peer) return 1;
  if (ea->phase < eb->phase) return -1;
  if (ea->phase > eb->phase) return 1;
  if (ea->key < eb->key) return -1;
  if (ea->key > eb->key) return 1;
  if (ea->tid < eb->tid) return -1;
  if (ea->tid > eb->tid) return 1;
  return 0;
}

static void device_malloc_or_die(void **ptr, size_t bytes, int device_id,
                                 const char *name) {
  cudaError_t err = cudaMalloc(ptr, bytes);
  if (err != cudaSuccess) {
    fprintf(stderr, "cudaMalloc %s failed: err=%s dev=%d bytes=%zu\n",
            name, cudaGetErrorString(err), device_id, bytes);
    assert(0);
  }
}

static void copy_h2d_or_die(void *dst, const void *src, size_t bytes,
                            int device_id, const char *name) {
  cudaError_t err = cudaMemcpy(dst, src, bytes, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    fprintf(stderr, "cudaMemcpy %s failed: err=%s dev=%d bytes=%zu\n",
            name, cudaGetErrorString(err), device_id, bytes);
    assert(0);
  }
}

static void alloc_copy_long_array(long **dst_d, const long *src, long count,
                                  int device_id, const char *name) {
  if (count == 0) {
    *dst_d = NULL;
    return;
  }
  device_malloc_or_die((void **)dst_d, (size_t)count * sizeof(long), device_id,
                       name);
  copy_h2d_or_die(*dst_d, src, (size_t)count * sizeof(long), device_id, name);
}

static void init_field_halo_plan_members(Field3D_Seq *pthis) {
  pthis->field_halo_send_seg_count = 0;
  pthis->field_halo_recv_seg_count = 0;
  pthis->field_halo_send_src_d = NULL;
  pthis->field_halo_send_dst_d = NULL;
  pthis->field_halo_send_len_d = NULL;
  pthis->field_halo_recv_src_d = NULL;
  pthis->field_halo_recv_dst_d = NULL;
  pthis->field_halo_recv_len_d = NULL;
  pthis->field_halo_send_peer_count = 0;
  pthis->field_halo_recv_peer_count = 0;
  pthis->field_halo_send_peer = NULL;
  pthis->field_halo_recv_peer = NULL;
  pthis->field_halo_send_peer_offset = NULL;
  pthis->field_halo_recv_peer_offset = NULL;
  pthis->field_halo_send_peer_count_elems = NULL;
  pthis->field_halo_recv_peer_count_elems = NULL;
  pthis->field_halo_send_buf = NULL;
  pthis->field_halo_recv_buf = NULL;
  pthis->field_halo_send_total_elems = 0;
  pthis->field_halo_recv_total_elems = 0;
}

static void finalize_field_halo_plan(Field3D_Seq *data,
                                     FieldHaloEntry *entries,
                                     long entry_count, int is_send,
                                     const char *debug_name) {
  int device_id = data->cuda_device;
  long *src = NULL;
  long *dst = NULL;
  long *len = NULL;
  int *peer = NULL;
  long *peer_offset = NULL;
  long *peer_count = NULL;
  int peer_count_n = 0;
  long total = 0;

  if (entry_count > 0) {
    qsort(entries, entry_count, sizeof(FieldHaloEntry), cmp_field_halo_entry);

    src = (long *)malloc((size_t)entry_count * sizeof(long));
    dst = (long *)malloc((size_t)entry_count * sizeof(long));
    len = (long *)malloc((size_t)entry_count * sizeof(long));
    assert(src && dst && len);

    for (long i = 0; i < entry_count; i++) {
      if (i == 0 || entries[i].peer != entries[i - 1].peer) peer_count_n++;
    }
    peer = (int *)malloc((size_t)peer_count_n * sizeof(int));
    peer_offset = (long *)malloc((size_t)peer_count_n * sizeof(long));
    peer_count = (long *)malloc((size_t)peer_count_n * sizeof(long));
    assert(peer && peer_offset && peer_count);

    int pidx = -1;
    for (long i = 0; i < entry_count; i++) {
      if (i == 0 || entries[i].peer != entries[i - 1].peer) {
        pidx++;
        peer[pidx] = entries[i].peer;
        peer_offset[pidx] = total;
        peer_count[pidx] = 0;
      }
      src[i] = entries[i].src_offset;
      dst[i] = total;
      if (!is_send) {
        src[i] = total;
        dst[i] = entries[i].dst_offset;
      }
      len[i] = entries[i].len;
      total += entries[i].len;
      peer_count[pidx] += entries[i].len;
    }
  }

  cudaSetDevice(device_id);
  if (is_send) {
    data->field_halo_send_seg_count = entry_count;
    data->field_halo_send_peer_count = peer_count_n;
    data->field_halo_send_peer = peer;
    data->field_halo_send_peer_offset = peer_offset;
    data->field_halo_send_peer_count_elems = peer_count;
    data->field_halo_send_total_elems = total;
    alloc_copy_long_array(&data->field_halo_send_src_d, src, entry_count,
                          device_id, "field_halo_send_src");
    alloc_copy_long_array(&data->field_halo_send_dst_d, dst, entry_count,
                          device_id, "field_halo_send_dst");
    alloc_copy_long_array(&data->field_halo_send_len_d, len, entry_count,
                          device_id, "field_halo_send_len");
    if (total > 0)
      device_malloc_or_die((void **)&data->field_halo_send_buf,
                           (size_t)total * sizeof(double), device_id,
                           "field_halo_send_buf");
  } else {
    data->field_halo_recv_seg_count = entry_count;
    data->field_halo_recv_peer_count = peer_count_n;
    data->field_halo_recv_peer = peer;
    data->field_halo_recv_peer_offset = peer_offset;
    data->field_halo_recv_peer_count_elems = peer_count;
    data->field_halo_recv_total_elems = total;
    alloc_copy_long_array(&data->field_halo_recv_src_d, src, entry_count,
                          device_id, "field_halo_recv_src");
    alloc_copy_long_array(&data->field_halo_recv_dst_d, dst, entry_count,
                          device_id, "field_halo_recv_dst");
    alloc_copy_long_array(&data->field_halo_recv_len_d, len, entry_count,
                          device_id, "field_halo_recv_len");
    if (total > 0)
      device_malloc_or_die((void **)&data->field_halo_recv_buf,
                           (size_t)total * sizeof(double), device_id,
                           "field_halo_recv_buf");
  }

  if (getenv("SYMPIC_FIELD_HALO_DEBUG")) {
    fprintf(stderr,
            "field_halo_plan rank=%ld dev=%d %s segs=%ld peers=%d elems=%ld\n",
            data->global_pid, device_id, debug_name, entry_count,
            peer_count_n, total);
    for (int i = 0; i < peer_count_n; i++) {
      fprintf(stderr,
              "field_halo_plan rank=%ld dev=%d %s peer=%d offset=%ld elems=%ld\n",
              data->global_pid, device_id, debug_name, peer[i],
              peer_offset[i], peer_count[i]);
    }
  }

  free(src);
  free(dst);
  free(len);
}

static void build_field_halo_plan(Field3D_Seq *data,
                                  const long *sync_layer_len) {
  init_field_halo_plan_members(data);

  long numvec = data->numvec;
  long layer_offset[NUM_SYNC_LAYER];
  long all_sync_len = 0;
  for (int fid = 0; fid < NUM_SYNC_LAYER; fid++) {
    if (fid == NUM_SYNC_LAYER / 2) {
      layer_offset[fid] = -1;
      continue;
    }
    layer_offset[fid] = all_sync_len;
    all_sync_len += sync_layer_len[fid] * numvec;
  }

  long send_entries_n = 0;
  long recv_entries_n = 0;
  for (int fid = 0; fid < NUM_SYNC_LAYER; fid++) {
    if (fid == NUM_SYNC_LAYER / 2) continue;
    send_entries_n += data->remote_send_count[fid];
    recv_entries_n += data->remote_recv_count[fid];
  }

  FieldHaloEntry *send_entries =
      send_entries_n ? (FieldHaloEntry *)malloc((size_t)send_entries_n *
                                                sizeof(FieldHaloEntry)) : NULL;
  FieldHaloEntry *recv_entries =
      recv_entries_n ? (FieldHaloEntry *)malloc((size_t)recv_entries_n *
                                                sizeof(FieldHaloEntry)) : NULL;
  assert((send_entries_n == 0 || send_entries) &&
         (recv_entries_n == 0 || recv_entries));

  long si = 0;
  long ri = 0;
  for (int fid = 0; fid < NUM_SYNC_LAYER; fid++) {
    if (fid == NUM_SYNC_LAYER / 2) continue;
    int fid1 = NUM_SYNC_LAYER - 1 - fid;
    long send_len = sync_layer_len[fid];
    long recv_len = sync_layer_len[fid1];

    for (long pass = 0; pass < data->remote_send_count[fid]; pass++) {
      long tid = data->remote_send_tid[fid][pass];
      send_entries[si].peer = (int)data->adj_processes[tid * NUM_SYNC_LAYER + fid];
      send_entries[si].phase = fid;
      send_entries[si].key = data->adj_ids[tid * NUM_SYNC_LAYER + fid];
      send_entries[si].tid = tid;
      send_entries[si].src_offset = layer_offset[fid] + tid * send_len;
      send_entries[si].dst_offset = 0;
      send_entries[si].len = send_len;
      si++;
    }

    for (long pass = 0; pass < data->remote_recv_count[fid]; pass++) {
      long tid = data->remote_recv_tid[fid][pass];
      recv_entries[ri].peer = (int)data->adj_processes[tid * NUM_SYNC_LAYER + fid1];
      recv_entries[ri].phase = fid;
      recv_entries[ri].key = data->adj_ids[tid * NUM_SYNC_LAYER + NUM_SYNC_LAYER / 2];
      recv_entries[ri].tid = tid;
      recv_entries[ri].src_offset = 0;
      recv_entries[ri].dst_offset =
          all_sync_len - layer_offset[fid] - recv_len * numvec + tid * recv_len;
      recv_entries[ri].len = recv_len;
      ri++;
    }
  }

  assert(si == send_entries_n);
  assert(ri == recv_entries_n);
  finalize_field_halo_plan(data, send_entries, send_entries_n, 1, "send");
  finalize_field_halo_plan(data, recv_entries, recv_entries_n, 0, "recv");

  free(send_entries);
  free(recv_entries);
}
/* USENCCL end */

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
    cudaError_t err;
    if (peer < 0) {
      double *src = sync_d_data + recv_offset[data_id] + src0 * sllen;
      err = cudaMemcpyAsync(dst, src, bytes, cudaMemcpyDeviceToDevice, 0);
    } else {
      cuda_pscmc_mem *sm = (cuda_pscmc_mem *)(data[peer].sync_layer_pscmc[0]);
      double *src = ((double *)(sm->d_data)) + recv_offset[peer] + src0 * sllen;
      err = cudaMemcpyPeerAsync(dst, data[data_id].cuda_device,
                                src, data[peer].cuda_device, bytes, 0);
    }
    if (err != cudaSuccess) {
      fprintf(stderr, "local recv copy failed: err=%s dst_runtime=%ld peer=%d bytes=%zu\n",
              cudaGetErrorString(err), data_id, peer, bytes);
      assert(0);
    }
    k += run;
  }
}

static void launch_local_recv_kernel(Field3D_Seq *data, long data_id, int fieldid,
                                     size_t *recv_offset, long numvec, long sllen,
                                     double *swap_d_data, double *sync_d_data) {
  long lr_n = data[data_id].local_recv_count[fieldid];
  if (lr_n <= 0) return;
  launch_local_halo_copy(swap_d_data, sync_d_data,
                         data[data_id].local_recv_tid_d[fieldid],
                         data[data_id].local_recv_src_d[fieldid],
                         lr_n, sllen, numvec, recv_offset[data_id]);
}

/* USENCCL Precompute self/same-rank recv mapping.
   adj_ids/adj_processes/adj_local_tid never change after init. */
static void build_local_recv_cache(Field3D_Seq *data, long num_runtime,
                                   long cur_rank, const long *sync_layer_len) {
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
    if (n > 0) {
      cudaSetDevice(data->cuda_device);
      cudaError_t err = cudaMalloc((void **)&data->local_recv_tid_d[fid], n * sizeof(long));
      if (err != cudaSuccess) {
        fprintf(stderr, "cudaMalloc local_recv_tid_d failed: err=%s dev=%d n=%ld\n",
                cudaGetErrorString(err), data->cuda_device, n);
        assert(0);
      }
      err = cudaMalloc((void **)&data->local_recv_src_d[fid], n * sizeof(long));
      if (err != cudaSuccess) {
        fprintf(stderr, "cudaMalloc local_recv_src_d failed: err=%s dev=%d n=%ld\n",
                cudaGetErrorString(err), data->cuda_device, n);
        assert(0);
      }
      err = cudaMemcpy(data->local_recv_tid_d[fid], data->local_recv_tid[fid],
                       n * sizeof(long), cudaMemcpyHostToDevice);
      if (err != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy local_recv_tid_d failed: err=%s dev=%d n=%ld\n",
                cudaGetErrorString(err), data->cuda_device, n);
        assert(0);
      }
      err = cudaMemcpy(data->local_recv_src_d[fid], data->local_recv_src[fid],
                       n * sizeof(long), cudaMemcpyHostToDevice);
      if (err != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy local_recv_src_d failed: err=%s dev=%d n=%ld\n",
                cudaGetErrorString(err), data->cuda_device, n);
        assert(0);
      }
    }
  }
  data->cache_valid = 1;
  build_field_halo_plan(data, sync_layer_len);
}
/* USENCCL end */

/* USENCCL: enqueue all self/same-rank field copies across every layer, in
   layer order, before the packed remote exchange is posted. */
static void enqueue_all_local_field_copies(Field3D_MPI *pthis,
                                           const size_t *all_sync_len) {
  Field3D_Seq *data = pthis->data;
  long num_data = pthis->num_runtime;
  long num_runtime = pthis->num_runtime;
  long *sync_layer_len = pthis->sync_layer_len;

  for (int fieldid = 0; fieldid < NUM_SYNC_LAYER; fieldid++) {
    if (fieldid == NUM_SYNC_LAYER / 2) continue;

    size_t *recv_offset = (size_t *)malloc((size_t)num_data * sizeof(size_t));
    assert(recv_offset);
    for (long i = 0; i < num_data; i++) {
      size_t offset = 0;
      for (int fid = 0; fid < fieldid; fid++) {
        if (fid == NUM_SYNC_LAYER / 2) continue;
        offset += (size_t)sync_layer_len[fid] * (size_t)data[i].numvec;
      }
      recv_offset[i] = offset;
    }

    for (long i = 0; i < num_data; i++) {
      cudaSetDevice(data[i].cuda_device);
      long numvec = data[i].numvec;
      void **sync_layer_pscmc = data[i].sync_layer_pscmc;
      void **swap_layer_pscmc = data[i].swap_layer_pscmc;
      cuda_pscmc_mem *sync_mem = (cuda_pscmc_mem *)(sync_layer_pscmc[0]);
      cuda_pscmc_mem *swap_mem = (cuda_pscmc_mem *)(swap_layer_pscmc[0]);
      double *sync_d_data = (double *)(sync_mem->d_data);
      double *swap_d_data = ((double *)(swap_mem->d_data)) + all_sync_len[i];
      int fieldid1 = NUM_SYNC_LAYER - 1 - fieldid;
      long sllen1 = sync_layer_len[fieldid1];
      if (num_runtime == 1)
        launch_local_recv_kernel(data, i, fieldid, recv_offset, numvec,
                                 sllen1, swap_d_data, sync_d_data);
      else
        enqueue_local_recv_copies(data, i, fieldid, recv_offset, numvec,
                                  sllen1, swap_d_data, sync_d_data);
    }
    free(recv_offset);
  }
}

/* USENCCL: packed field-halo exchange.  All remote segments are gathered into
   contiguous per-peer buffers (one ncclSend/ncclRecv per peer and phase),
   which collapses the many small per-segment messages of the old loop. */
static void exchange_remote_field_halo(Field3D_MPI *pthis,
                                       const size_t *all_sync_len) {
  Field3D_Seq *data = pthis->data;
  long num_data = pthis->num_runtime;

  enqueue_all_local_field_copies(pthis, all_sync_len);

  for (long i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    cuda_pscmc_mem *sync_mem =
        (cuda_pscmc_mem *)(data[i].sync_layer_pscmc[0]);
    if (data[i].field_halo_send_seg_count > 0) {
      launch_field_halo_pack(
          data[i].field_halo_send_buf, (const double *)sync_mem->d_data,
          data[i].field_halo_send_src_d, data[i].field_halo_send_dst_d,
          data[i].field_halo_send_len_d, data[i].field_halo_send_seg_count);
    }
  }

  ncclGroupStart();
  for (long i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    for (int p = 0; p < data[i].field_halo_recv_peer_count; p++) {
      long count = data[i].field_halo_recv_peer_count_elems[p];
      if (count == 0) continue;
      int peer = data[i].field_halo_recv_peer[p];
      long offset = data[i].field_halo_recv_peer_offset[p];
      ncclRecv(data[i].field_halo_recv_buf + offset, count, ncclDouble, peer,
               pthis->nccl_comm[i], 0);
    }
  }
  for (long i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    for (int p = 0; p < data[i].field_halo_send_peer_count; p++) {
      long count = data[i].field_halo_send_peer_count_elems[p];
      if (count == 0) continue;
      int peer = data[i].field_halo_send_peer[p];
      long offset = data[i].field_halo_send_peer_offset[p];
      ncclSend(data[i].field_halo_send_buf + offset, count, ncclDouble, peer,
               pthis->nccl_comm[i], 0);
    }
  }
  ncclGroupEnd();

  for (long i = 0; i < num_data; i++) {
    cudaSetDevice(data[i].cuda_device);
    cuda_pscmc_mem *swap_mem =
        (cuda_pscmc_mem *)(data[i].swap_layer_pscmc[0]);
    if (data[i].field_halo_recv_seg_count > 0) {
      launch_field_halo_unpack(
          (double *)swap_mem->d_data, data[i].field_halo_recv_buf,
          data[i].field_halo_recv_src_d, data[i].field_halo_recv_dst_d,
          data[i].field_halo_recv_len_d, data[i].field_halo_recv_seg_count);
    }
  }
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
      build_local_recv_cache(&data[i], num_runtime, pthis->cur_rank,
                             sync_layer_len);
  /* USENCCL end */
  size_t all_sync_len[num_data];
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

    ((all_sync_len)[i] = (numvec * (num_ele * ((xblock * (yblock * zblock)) - (xlen * (ylen * zlen))))));
  }

  /* USENCCL: packed field exchange via NCCL */
  exchange_remote_field_halo(pthis, all_sync_len);
  /* USENCCL end */
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
      build_local_recv_cache(&data[i], num_runtime, pthis->cur_rank,
                             sync_layer_len);
  /* USENCCL end */
  size_t all_sync_len[num_data];
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

    ((all_sync_len)[i] = (numvec * (num_ele * ((xblock * (yblock * zblock)) - (xlen * (ylen * zlen))))));
  }

  /* USENCCL: packed field exchange via NCCL */
  exchange_remote_field_halo(pthis, all_sync_len);
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

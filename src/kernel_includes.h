#ifndef KERNEL_INCLUDES_H
#define KERNEL_INCLUDES_H

#include <stddef.h>
#include "pubdefs.h"

#ifdef SYMPIC_CUDA
#include "cuda_/cuda_pscmc_inc.h"
#include "cuda_/general_partial_sort.kernel_inc.h"
#include "cuda_/geo_yeefdtd.kernel_inc.h"
#include "cuda_/inner_split_pass.kernel_inc.h"
#include "cuda_/mergefields.kernel_inc.h"
#include "cuda_/miniblas.kernel_inc.h"
#include "cuda_/move_back.kernel_inc.h"
#include "cuda_/particle_iter.kernel_inc.h"
#include "cuda_/local_halo_copy.kernel_runtime.h"
#include "cuda_yeefdtd.h"
#endif

#ifdef SYMPIC_MAPU
#include <maps_runtime.h>
#include "mapu_/mapu_pscmc.h"
#include "mapu_/init_particle_gpu.kernel_runtime.h"
#include "mapu_/local_halo_copy.kernel_runtime.h"
#include "mapu_/inner_split_pass.kernel_runtime.h"
#include "mapu_/general_partial_sort.kernel_runtime.h"
#include "mapu_sort_one_grid_6_dispatch.h"
#include "mapu_/geo_yeefdtd.kernel_runtime.h"
#include "mapu_/mergefields.kernel_runtime.h"
#include "mapu_/miniblas.kernel_runtime.h"
#include "mapu_/move_back.kernel_runtime.h"
#include "mapu_/particle_iter.kernel_runtime.h"
#endif

#ifdef SYMPIC_CUDA
typedef cuda_pscmc_mem SymPIC_Device_Mem;
#elif defined(SYMPIC_MAPU)
typedef mapu_pscmc_mem SymPIC_Device_Mem;
#endif

static inline void sympic_set_device(int device_id) {
#ifdef SYMPIC_CUDA
  cudaSetDevice(device_id);
#elif defined(SYMPIC_MAPU)
  mapsSetDevice(device_id);
#endif
}

static inline void sympic_enable_peer_access(int device_id, int peer_device_id) {
  int can_access = 0;
#ifdef SYMPIC_CUDA
  cudaDeviceCanAccessPeer(&can_access, device_id, peer_device_id);
  if (can_access) cudaDeviceEnablePeerAccess(peer_device_id, 0);
#elif defined(SYMPIC_MAPU)
  mapsDeviceCanAccessPeer(&can_access, device_id, peer_device_id);
  if (can_access) mapsDeviceEnablePeerAccess(peer_device_id, 0);
#endif
}

static inline int sympic_copy_local_async(void *dst, const void *src,
                                          size_t bytes) {
#ifdef SYMPIC_CUDA
  return (int)cudaMemcpyAsync(dst, src, bytes, cudaMemcpyDeviceToDevice, 0);
#elif defined(SYMPIC_MAPU)
  return (int)mapsMemcpyAsync(dst, src, bytes, mapsMemcpyDeviceToDevice, 0);
#endif
}

static inline int sympic_copy_peer_async(void *dst, int dst_device,
                                         const void *src, int src_device,
                                         size_t bytes) {
#ifdef SYMPIC_CUDA
  return (int)cudaMemcpyPeerAsync(dst, dst_device, src, src_device, bytes, 0);
#elif defined(SYMPIC_MAPU)
  return (int)mapsMemcpyPeerAsync(dst, dst_device, src, src_device, bytes, 0);
#endif
}

static inline void sympic_copy_peer(void *dst, int dst_device, const void *src,
                                    int src_device, size_t bytes) {
#ifdef SYMPIC_CUDA
  cudaMemcpyPeer(dst, dst_device, src, src_device, bytes);
#elif defined(SYMPIC_MAPU)
  mapsMemcpyPeer(dst, dst_device, src, src_device, bytes);
#endif
}

static inline int sympic_device_synchronize(void) {
#ifdef SYMPIC_CUDA
  return (int)cudaDeviceSynchronize();
#elif defined(SYMPIC_MAPU)
  return (int)mapsDeviceSynchronize();
#endif
}

static inline const char *sympic_device_error_string(int error) {
#ifdef SYMPIC_CUDA
  return cudaGetErrorString((cudaError_t)error);
#elif defined(SYMPIC_MAPU)
  return mapsGetErrorString((mapsError_t)error);
#endif
}

static inline void sympic_mem_sync_d2h(void *mem) {
#ifdef SYMPIC_CUDA
  cuda_pscmc_mem_sync_d2h((cuda_pscmc_mem *)mem);
#elif defined(SYMPIC_MAPU)
  mapu_pscmc_mem_sync_d2h((mapu_pscmc_mem *)mem);
#endif
}

static inline void sympic_mem_sync_h2d(void *mem) {
#ifdef SYMPIC_CUDA
  cuda_pscmc_mem_sync_h2d((cuda_pscmc_mem *)mem);
#elif defined(SYMPIC_MAPU)
  mapu_pscmc_mem_sync_h2d((mapu_pscmc_mem *)mem);
#endif
}

static inline int sympic_device_malloc(void **ptr, size_t bytes) {
#ifdef SYMPIC_CUDA
  return (int)cudaMalloc(ptr, bytes);
#elif defined(SYMPIC_MAPU)
  return (int)mapsMalloc(ptr, bytes);
#endif
}

static inline int sympic_copy_h2d(void *dst, const void *src, size_t bytes) {
#ifdef SYMPIC_CUDA
  return (int)cudaMemcpy(dst, src, bytes, cudaMemcpyHostToDevice);
#elif defined(SYMPIC_MAPU)
  return (int)mapsMemcpy(dst, src, bytes, mapsMemcpyHostToDevice);
#endif
}

/* single-kernel gather for self halo copies; replaces per-segment
   cudaMemcpyAsync/mapsMemcpyAsync enqueue (the old self_copy hotspot) */
static inline void sympic_launch_local_halo_copy(double *dst_base,
                                                 const double *src_base,
                                                 const long *dst_tid_d,
                                                 const long *src_tid_d,
                                                 long ncopy, long sllen,
                                                 long numvec, size_t recv_offset,
                                                 int device_id) {
#ifdef SYMPIC_CUDA
  cuda_local_halo_copy_launch(dst_base, src_base, dst_tid_d, src_tid_d, ncopy,
                              sllen, numvec, recv_offset, device_id);
#elif defined(SYMPIC_MAPU)
  mapu_local_halo_copy_launch(dst_base, src_base, dst_tid_d, src_tid_d, ncopy,
                              sllen, numvec, recv_offset, device_id);
#endif
}

static inline void sympic_launch_field_halo_pack(double *dst_base,
                                                 const double *src_base,
                                                 const long *src_off_d,
                                                 const long *dst_off_d,
                                                 const long *len_d,
                                                 long nseg,
                                                 int device_id) {
#ifdef SYMPIC_CUDA
  cuda_field_halo_pack_launch(dst_base, src_base, src_off_d, dst_off_d, len_d,
                              nseg, device_id);
#elif defined(SYMPIC_MAPU)
  mapu_field_halo_pack_launch(dst_base, src_base, src_off_d, dst_off_d, len_d,
                              nseg, device_id);
#endif
}

static inline void sympic_launch_field_halo_unpack(double *dst_base,
                                                   const double *src_base,
                                                   const long *src_off_d,
                                                   const long *dst_off_d,
                                                   const long *len_d,
                                                   long nseg,
                                                   int device_id) {
#ifdef SYMPIC_CUDA
  cuda_field_halo_unpack_launch(dst_base, src_base, src_off_d, dst_off_d,
                                len_d, nseg, device_id);
#elif defined(SYMPIC_MAPU)
  mapu_field_halo_unpack_launch(dst_base, src_base, src_off_d, dst_off_d,
                                len_d, nseg, device_id);
#endif
}

static inline void sympic_comm_get_unique_id(SymPIC_Device_UniqueId *id) {
#ifdef SYMPIC_CUDA
  ncclGetUniqueId(id);
#elif defined(SYMPIC_MAPU)
  macclGetUniqueId(id);
#endif
}

static inline void sympic_comm_group_start(void) {
#ifdef SYMPIC_CUDA
  ncclGroupStart();
#elif defined(SYMPIC_MAPU)
  macclGroupStart();
#endif
}

static inline void sympic_comm_group_end(void) {
#ifdef SYMPIC_CUDA
  ncclGroupEnd();
#elif defined(SYMPIC_MAPU)
  macclGroupEnd();
#endif
}

static inline void sympic_comm_init_rank(SymPIC_Device_Comm *comm, int nranks,
                                         SymPIC_Device_UniqueId id, int rank) {
#ifdef SYMPIC_CUDA
  ncclCommInitRank(comm, nranks, id, rank);
#elif defined(SYMPIC_MAPU)
  macclCommInitRank(comm, nranks, id, rank);
#endif
}

static inline void sympic_comm_destroy(SymPIC_Device_Comm comm) {
#ifdef SYMPIC_CUDA
  ncclCommDestroy(comm);
#elif defined(SYMPIC_MAPU)
  macclCommDestroy(comm);
#endif
}

static inline void sympic_comm_send_int(const int *buffer, size_t count,
                                        int peer, SymPIC_Device_Comm comm) {
#ifdef SYMPIC_CUDA
  ncclSend(buffer, count, ncclInt, peer, comm, 0);
#elif defined(SYMPIC_MAPU)
  macclSend(buffer, count, macclInt, peer, comm, 0);
#endif
}

static inline void sympic_comm_recv_int(int *buffer, size_t count, int peer,
                                        SymPIC_Device_Comm comm) {
#ifdef SYMPIC_CUDA
  ncclRecv(buffer, count, ncclInt, peer, comm, 0);
#elif defined(SYMPIC_MAPU)
  macclRecv(buffer, count, macclInt, peer, comm, 0);
#endif
}

static inline void sympic_comm_send_double(const double *buffer, size_t count,
                                           int peer, SymPIC_Device_Comm comm) {
#ifdef SYMPIC_CUDA
  ncclSend(buffer, count, ncclDouble, peer, comm, 0);
#elif defined(SYMPIC_MAPU)
  macclSend(buffer, count, macclDouble, peer, comm, 0);
#endif
}

static inline void sympic_comm_recv_double(double *buffer, size_t count,
                                           int peer, SymPIC_Device_Comm comm) {
#ifdef SYMPIC_CUDA
  ncclRecv(buffer, count, ncclDouble, peer, comm, 0);
#elif defined(SYMPIC_MAPU)
  macclRecv(buffer, count, macclDouble, peer, comm, 0);
#endif
}

#endif

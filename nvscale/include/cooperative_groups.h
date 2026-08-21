/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE header.
 * It maps a subset of SCALE/MAPS/Aurora APIs to NVIDIA CUDA for local
 * compilation and functional bring-up.
 */
#pragma once

#include "scale.h"

namespace cooperative_groups {

struct arrival_token {};

namespace details {
static constexpr unsigned int grid_group_id = 1;
static constexpr unsigned int thread_block_id = 2;
static constexpr unsigned int cluster_group_id = 3;
} // namespace details

class thread_block;
class cluster_group;
class grid_group;

class thread_group {
public:
  __device__ thread_group() : type_(0) {}
  __device__ thread_group(const thread_block &) : type_(details::thread_block_id) {}
  __device__ thread_group(const cluster_group &) : type_(details::cluster_group_id) {}
  __device__ thread_group(const grid_group &) : type_(details::grid_group_id) {}

  __device__ unsigned long long size() const { return num_threads(); }
  __device__ unsigned long long num_threads() const;
  __device__ unsigned long long thread_rank() const;
  __device__ void sync() const;
  __device__ unsigned int get_type() const { return type_; }

private:
  unsigned int type_;
};

class thread_block {
public:
  static constexpr unsigned int id = details::thread_block_id;
  __device__ void sync() const { __syncthreads(); }
  __device__ arrival_token barrier_arrive() const { return {}; }
  __device__ void barrier_wait(arrival_token &&) const { __syncthreads(); }
  __device__ unsigned int thread_rank() const {
    return threadIdx.x + blockDim.x * (threadIdx.y + blockDim.y * threadIdx.z);
  }
  __device__ dim3 group_index() const { return blockIdx; }
  __device__ dim3 thread_index() const { return threadIdx; }
  __device__ dim3 dim_threads() const { return blockDim; }
  __device__ dim3 group_dim() const { return blockDim; }
  __device__ unsigned int num_threads() const {
    return blockDim.x * blockDim.y * blockDim.z;
  }
  __device__ unsigned int size() const { return num_threads(); }
};

__device__ static inline thread_block this_thread_block() { return {}; }

/*
 * Pre-sm_90 CUDA cannot implement Aurora cluster DSM. Each CUDA block is
 * exposed as a one-block cluster so non-DSM code remains functionally valid.
 */
class cluster_group {
public:
  static constexpr unsigned int id = details::cluster_group_id;
  __device__ void sync() const { __syncthreads(); }
  __device__ unsigned int thread_rank() const {
    return this_thread_block().thread_rank();
  }
  __device__ unsigned int block_rank() const { return 0; }
  __device__ unsigned int num_threads() const { return blockDim.x * blockDim.y * blockDim.z; }
  __device__ unsigned int num_blocks() const { return 1; }
  __device__ dim3 dim_threads() const { return blockDim; }
  __device__ dim3 dim_blocks() const { return dim3(1, 1, 1); }
  __device__ dim3 block_index() const { return dim3(0, 0, 0); }
  __device__ unsigned int query_shared_rank(const void *) const { return 0; }
  template <typename T>
  __device__ T *map_shared_rank(T *addr, int) const { return addr; }
  __device__ unsigned int size() const { return num_threads(); }
};

__device__ static inline cluster_group this_cluster() { return {}; }

class grid_group {
public:
  static constexpr unsigned int id = details::grid_group_id;
  __device__ unsigned long long thread_rank() const {
    return (unsigned long long)this_thread_block().thread_rank() +
           (unsigned long long)block_rank() * blockDim.x * blockDim.y * blockDim.z;
  }
  __device__ unsigned long long block_rank() const {
    return blockIdx.x + (unsigned long long)gridDim.x *
           (blockIdx.y + (unsigned long long)gridDim.y * blockIdx.z);
  }
  __device__ unsigned long long cluster_rank() const { return block_rank(); }
  __device__ unsigned long long num_threads() const {
    return num_blocks() * blockDim.x * blockDim.y * blockDim.z;
  }
  __device__ unsigned long long num_blocks() const {
    return (unsigned long long)gridDim.x * gridDim.y * gridDim.z;
  }
  __device__ unsigned long long num_clusters() const { return num_blocks(); }
  __device__ dim3 dim_blocks() const { return gridDim; }
  __device__ dim3 dim_clusters() const { return gridDim; }
  __device__ dim3 block_index() const { return blockIdx; }
  __device__ dim3 cluster_index() const { return blockIdx; }
  __device__ unsigned long long size() const { return num_threads(); }
  __device__ dim3 group_dim() const { return gridDim; }
};

__device__ static inline grid_group this_grid() { return {}; }

__device__ inline unsigned long long thread_group::num_threads() const {
  if (type_ == details::grid_group_id) return grid_group{}.num_threads();
  if (type_ == details::cluster_group_id) return cluster_group{}.num_threads();
  if (type_ == details::thread_block_id) return thread_block{}.num_threads();
  return 0;
}

__device__ inline unsigned long long thread_group::thread_rank() const {
  if (type_ == details::grid_group_id) return grid_group{}.thread_rank();
  if (type_ == details::cluster_group_id) return cluster_group{}.thread_rank();
  if (type_ == details::thread_block_id) return thread_block{}.thread_rank();
  return 0;
}

__device__ inline void thread_group::sync() const {
  if (type_ == details::grid_group_id) {
    /* SCALE grid sync is not reproduced by NVScale. */
    __threadfence();
  } else if (type_ == details::cluster_group_id) {
    cluster_group{}.sync();
  } else if (type_ == details::thread_block_id) {
    thread_block{}.sync();
  }
}

template <class GroupT>
__device__ static inline void sync(GroupT const &g) {
  g.sync();
}

template <class GroupT>
__device__ static inline auto thread_rank(GroupT const &g)
    -> decltype(g.thread_rank()) {
  return g.thread_rank();
}

template <class GroupT>
__device__ static inline auto group_size(GroupT const &g)
    -> decltype(g.num_threads()) {
  return g.num_threads();
}

} // namespace cooperative_groups

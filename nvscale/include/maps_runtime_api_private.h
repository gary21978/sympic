/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE header.
 * It maps a subset of SCALE/MAPS/Aurora APIs to NVIDIA CUDA for local
 * compilation and functional bring-up.
 */
#pragma once

#include "maps_runtime.h"

typedef struct apcProfilingCounters {
  uint64_t ape_specified_kernel_selected_warp_cnt;
  uint64_t ape_specified_kernel_stall_warp_cnt;
  uint64_t ape_warppool_empty_cnt;
  uint64_t warp_cnt;
  uint64_t ape_eligible_warp_cnt;
  uint64_t ape_cluster_barrier_stall_cnt;
  uint64_t ape_cluster_barrier_resume_cnt;
} apcProfilingCounters;

typedef struct apcKernelProfilingData {
  struct apcProfilingCounters apc_profiling;
  uint64_t event_timestamp[16];
} apcKernelProfilingData;

static inline mapsError_t mapsStartKernelProfiling(
    mapsStream_t stream, uint32_t apcMask, uint32_t *kernelIds,
    uint32_t *workgroupIds, uint32_t *warpIds) {
  (void)stream;
  (void)apcMask;
  (void)kernelIds;
  (void)workgroupIds;
  (void)warpIds;
  return mapsSuccess;
}

static inline mapsError_t mapsReadKernelProfiling(mapsStream_t stream,
                                                  uint32_t apcMask,
                                                  void *kernelProfData) {
  (void)stream;
  (void)apcMask;
  if (kernelProfData) {
    memset(kernelProfData, 0, sizeof(apcKernelProfilingData) * 32);
  }
  return mapsSuccess;
}

static inline mapsError_t mapsReadKernelProfilingDev(mapsStream_t stream,
                                                     uint32_t apcMask,
                                                     void *devProfData) {
  (void)stream;
  (void)apcMask;
  return devProfData ? mapsMemset(devProfData, 0,
                                  sizeof(apcKernelProfilingData) * 32)
                     : mapsSuccess;
}

static inline mapsError_t mapsStopKernelProfiling(mapsStream_t stream,
                                                  uint32_t apcMask) {
  (void)stream;
  (void)apcMask;
  return mapsSuccess;
}

static inline mapsError_t mapsRecordKernelPerfTime(mapsStream_t stream,
                                                   int enable) {
  (void)stream;
  (void)enable;
  return mapsSuccess;
}

static inline mapsError_t mapsGetKernelPerfTime(mapsStream_t stream,
                                                uint64_t *ns,
                                                uint64_t *cycle) {
  (void)stream;
  if (ns) *ns = 0;
  if (cycle) *cycle = 0;
  return mapsSuccess;
}

static inline mapsError_t mapsSetProfilerBufferEx(void *devBuffer,
                                                  mapsStream_t stream = 0) {
  (void)devBuffer;
  (void)stream;
  return mapsSuccess;
}

static inline mapsError_t mapsStartRunningPerfCnt(int group, uint32_t apcMask) {
  (void)group;
  (void)apcMask;
  return mapsSuccess;
}

static inline mapsError_t mapsReadRunningPerfCnt(int group, uint32_t apcMask,
                                                 uint64_t *counts) {
  (void)group;
  (void)apcMask;
  if (counts) {
    for (int i = 0; i < 32; ++i) counts[i] = 0;
  }
  return mapsSuccess;
}

static inline mapsError_t mapsStopRunningPerfCnt(int group, uint32_t apcMask) {
  (void)group;
  (void)apcMask;
  return mapsSuccess;
}

/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE header.
 * It maps a subset of SCALE/MAPS/Aurora APIs to NVIDIA CUDA for local
 * compilation and functional bring-up.
 */
#pragma once

#include <cuda_runtime.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
#define NVSC_DPARM(x) = x
#else
#define NVSC_DPARM(x)
#endif

typedef cudaError_t mapsError_t;
typedef cudaStream_t mapsStream_t;
typedef cudaEvent_t mapsEvent_t;
typedef int mapsDevice_t;
typedef cudaDeviceProp mapsDeviceProp_t;
typedef enum cudaMemcpyKind mapsMemcpyKind;
typedef enum cudaMemoryType mapsMemoryType;
typedef struct mapsArray *mapsArray_t;
typedef const struct mapsArray *mapsArray_const_t;

typedef void (*mapsStreamCallback_t)(mapsStream_t stream, mapsError_t status,
                                     void *userData);
typedef void (*mapsHostFn_t)(void *userData);

typedef struct mapsUUID_t {
  char bytes[16];
} mapsUUID;

typedef struct mapsPitchedPtr {
  void *ptr;
  size_t pitch;
  size_t xsize;
  size_t ysize;
} mapsPitchedPtr;

typedef struct mapsExtent {
  size_t width;
  size_t height;
  size_t depth;
} mapsExtent;

typedef struct mapsPos {
  size_t x;
  size_t y;
  size_t z;
} mapsPos;

typedef struct mapsMemcpy3DParms {
  mapsArray_t srcArray;
  struct mapsPos srcPos;
  struct mapsPitchedPtr srcPtr;
  mapsArray_t dstArray;
  struct mapsPos dstPos;
  struct mapsPitchedPtr dstPtr;
  struct mapsExtent extent;
  enum cudaMemcpyKind kind;
} mapsMemcpy3DParms;

typedef enum mapsStreamCaptureMode {
  mapsStreamCaptureModeGlobal = 0,
  mapsStreamCaptureModeThreadLocal,
  mapsStreamCaptureModeRelaxed
} mapsStreamCaptureMode;

typedef enum mapsStreamCaptureStatus {
  mapsStreamCaptureStatusNone = 0,
  mapsStreamCaptureStatusActive,
  mapsStreamCaptureStatusInvalidated
} mapsStreamCaptureStatus;

typedef enum mapsDeviceP2PAttr {
  mapsDevP2PAttrPerformanceRank = 0,
  mapsDevP2PAttrAccessSupported,
  mapsDevP2PAttrNativeAtomicSupported,
  mapsDevP2PAttrMapsArrayAccessSupported
} mapsDeviceP2PAttr;

typedef enum mapsLaunchAttributeID {
  mapsLaunchAttributeIgnore = 0,
  mapsLaunchAttributeCooperative = 1,
  mapsLaunchAttributeClusterDimension = 2,
  mapsLaunchAttributeSmq = 3,
  mapsLaunchAttributeConcurrencyThread = 999
} mapsLaunchAttributeID;

typedef union mapsLaunchAttributeValue {
  char pad[64];
  int cooperative;
  struct {
    unsigned int x;
    unsigned int y;
    unsigned int z;
  } clusterDim;
  int concurrencyThread;
  int smqEnable;
} mapsLaunchAttributeValue;

typedef struct mapsLaunchAttribute_st {
  mapsLaunchAttributeID id;
  char pad[8 - sizeof(mapsLaunchAttributeID)];
  mapsLaunchAttributeValue val;
} mapsLaunchAttribute;

typedef struct mapsLaunchConfig_st {
  dim3 gridDim;
  dim3 blockDim;
  size_t dynamicSmemBytes;
  mapsStream_t stream;
  mapsLaunchAttribute *attrs;
  unsigned int numAttrs;
} mapsLaunchConfig_t;

typedef enum mapsDeviceAttribute_t {
  mapsDeviceAttributeMaxThreadsPerBlock = cudaDevAttrMaxThreadsPerBlock,
  mapsDeviceAttributeMaxBlockDimX = cudaDevAttrMaxBlockDimX,
  mapsDeviceAttributeMaxBlockDimY = cudaDevAttrMaxBlockDimY,
  mapsDeviceAttributeMaxBlockDimZ = cudaDevAttrMaxBlockDimZ,
  mapsDeviceAttributeMaxGridDimX = cudaDevAttrMaxGridDimX,
  mapsDeviceAttributeMaxGridDimY = cudaDevAttrMaxGridDimY,
  mapsDeviceAttributeMaxGridDimZ = cudaDevAttrMaxGridDimZ,
  mapsDeviceAttributeMaxSharedMemoryPerBlock = cudaDevAttrMaxSharedMemoryPerBlock,
  mapsDeviceAttributeWarpSize = cudaDevAttrWarpSize,
  mapsDeviceAttributeMultiprocessorCount = cudaDevAttrMultiProcessorCount,
  mapsDeviceAttributeClockRate = cudaDevAttrClockRate,
  mapsDeviceAttributeMemoryClockRate = cudaDevAttrMemoryClockRate,
  mapsDeviceAttributeMemoryBusWidth = cudaDevAttrGlobalMemoryBusWidth,
  mapsDeviceAttributeComputeCapabilityMajor = cudaDevAttrComputeCapabilityMajor,
  mapsDeviceAttributeComputeCapabilityMinor = cudaDevAttrComputeCapabilityMinor,
  mapsDeviceAttributeConcurrentKernels = cudaDevAttrConcurrentKernels,
  mapsDeviceAttributeAsyncEngineCount = cudaDevAttrAsyncEngineCount,
  mapsDeviceAttributeUnifiedAddressing = cudaDevAttrUnifiedAddressing,
  mapsDeviceAttributeManagedMemory = cudaDevAttrManagedMemory,
  mapsDeviceAttributeCooperativeLaunch = cudaDevAttrCooperativeLaunch,
  mapsDeviceAttributeMaxThreadsPerMultiProcessor =
      cudaDevAttrMaxThreadsPerMultiProcessor,
  mapsDeviceAttributeMaxBlocksPerMultiProcessor =
      cudaDevAttrMaxBlocksPerMultiprocessor
} mapsDeviceAttribute_t;

typedef enum mapsLimit_t {
  mapsLimitStackSize = cudaLimitStackSize,
  mapsLimitPrintfFifoSize = cudaLimitPrintfFifoSize,
  mapsLimitMallocHeapSize = cudaLimitMallocHeapSize
} mapsLimit_t;

#define mapsSuccess cudaSuccess
#define mapsErrorNotReady cudaErrorNotReady
#define mapsErrorInvalidValue cudaErrorInvalidValue
#define mapsErrorMemoryAllocation cudaErrorMemoryAllocation
#define mapsErrorInvalidDevice cudaErrorInvalidDevice
#define mapsErrorNoDevice cudaErrorNoDevice
#define mapsErrorNotSupported cudaErrorNotSupported
#define mapsErrorUnknown cudaErrorUnknown

#define mapsMemcpyHostToHost cudaMemcpyHostToHost
#define mapsMemcpyHostToDevice cudaMemcpyHostToDevice
#define mapsMemcpyDeviceToHost cudaMemcpyDeviceToHost
#define mapsMemcpyDeviceToDevice cudaMemcpyDeviceToDevice
#define mapsMemcpyDefault cudaMemcpyDefault

#define mapsHostAllocDefault cudaHostAllocDefault
#define mapsHostAllocPortable cudaHostAllocPortable
#define mapsHostAllocMapped cudaHostAllocMapped
#define mapsHostAllocWriteCombined cudaHostAllocWriteCombined
#define mapsMemAttachGlobal cudaMemAttachGlobal
#define mapsMemAttachHost cudaMemAttachHost
#define mapsStreamDefault cudaStreamDefault
#define mapsStreamNonBlocking cudaStreamNonBlocking
#define mapsEventDefault cudaEventDefault
#define mapsEventBlockingSync cudaEventBlockingSync
#define mapsEventDisableTiming cudaEventDisableTiming
#define mapsEventInterprocess cudaEventInterprocess
#define mapsStreamPerThread cudaStreamPerThread
#define mapsStreamLegacy cudaStreamLegacy

static inline struct mapsPitchedPtr make_mapsPitchedPtr(void *d, size_t p,
                                                        size_t xsz,
                                                        size_t ysz) {
  struct mapsPitchedPtr s = {d, p, xsz, ysz};
  return s;
}

static inline struct mapsPos make_mapsPos(size_t x, size_t y, size_t z) {
  struct mapsPos p = {x, y, z};
  return p;
}

static inline struct mapsExtent make_mapsExtent(size_t w, size_t h, size_t d) {
  struct mapsExtent e = {w, h, d};
  return e;
}

static inline mapsError_t mapsInit(unsigned int flags) {
  (void)flags;
  return cudaFree(0);
}
static inline mapsError_t mapsSetDevice(int device) {
  return cudaSetDevice(device);
}
static inline mapsError_t mapsGetDevice(int *device) {
  return cudaGetDevice(device);
}
static inline mapsError_t mapsGetDeviceCount(int *count) {
  return cudaGetDeviceCount(count);
}
static inline mapsError_t mapsGetDeviceProperties(mapsDeviceProp_t *prop,
                                                  int device) {
  return cudaGetDeviceProperties(prop, device);
}
static inline mapsError_t mapsDeviceGetAttribute(int *pi,
                                                 mapsDeviceAttribute_t attr,
                                                 int device) {
  return cudaDeviceGetAttribute(pi, (cudaDeviceAttr)attr, device);
}
static inline mapsError_t mapsDeviceSynchronize(void) {
  return cudaDeviceSynchronize();
}
static inline mapsError_t mapsDeviceReset(void) { return cudaDeviceReset(); }
static inline mapsError_t mapsDriverGetVersion(int *version) {
  return cudaDriverGetVersion(version);
}
static inline mapsError_t mapsRuntimeGetVersion(int *version) {
  return cudaRuntimeGetVersion(version);
}
static inline mapsError_t mapsDeviceGetPCIBusId(char *pciBusId, int len,
                                                int device) {
  return cudaDeviceGetPCIBusId(pciBusId, len, device);
}
static inline mapsError_t mapsDeviceCanAccessPeer(int *canAccessPeer,
                                                  int device, int peerDevice) {
  return cudaDeviceCanAccessPeer(canAccessPeer, device, peerDevice);
}
static inline mapsError_t mapsDeviceEnablePeerAccess(int peerDevice,
                                                     unsigned int flags) {
  return cudaDeviceEnablePeerAccess(peerDevice, flags);
}
static inline mapsError_t mapsDeviceSetLimit(enum mapsLimit_t limit,
                                             size_t value) {
  return cudaDeviceSetLimit((cudaLimit)limit, value);
}

static inline mapsError_t mapsMalloc(void **ptr, size_t size) {
  return cudaMalloc(ptr, size);
}
static inline mapsError_t mapsMemAlloc(void **ptr, size_t size) {
  return cudaMalloc(ptr, size);
}
static inline mapsError_t mapsMallocManaged(
    void **ptr, size_t size, unsigned int flags NVSC_DPARM(mapsMemAttachGlobal)) {
  return cudaMallocManaged(ptr, size, flags);
}
static inline mapsError_t mapsMemAllocManaged(
    void **ptr, size_t size, unsigned int flags NVSC_DPARM(mapsMemAttachGlobal)) {
  return cudaMallocManaged(ptr, size, flags);
}
static inline mapsError_t mapsMallocPitch(void **ptr, size_t *pitch,
                                          size_t width, size_t height) {
  return cudaMallocPitch(ptr, pitch, width, height);
}
static inline mapsError_t mapsMemAllocPitch(void **ptr, size_t *pitch,
                                            size_t width, size_t height) {
  return cudaMallocPitch(ptr, pitch, width, height);
}
static inline mapsError_t mapsFree(void *ptr) { return cudaFree(ptr); }
static inline mapsError_t mapsMemFree(void *ptr) { return cudaFree(ptr); }
static inline mapsError_t mapsMemGetInfo(size_t *freeBytes,
                                         size_t *totalBytes) {
  return cudaMemGetInfo(freeBytes, totalBytes);
}

static inline mapsError_t mapsHostAlloc(void **ptr, size_t size,
                                        unsigned int flags) {
  return cudaHostAlloc(ptr, size, flags);
}
static inline mapsError_t mapsHostMalloc(void **ptr, size_t size,
                                         unsigned int flags
                                             NVSC_DPARM(mapsHostAllocDefault)) {
  return cudaHostAlloc(ptr, size, flags);
}
static inline mapsError_t mapsMallocHost(void **ptr, size_t size) {
  return cudaMallocHost(ptr, size);
}
static inline mapsError_t mapsMemAllocHost(void **ptr, size_t size) {
  return cudaMallocHost(ptr, size);
}
static inline mapsError_t mapsMemHostAlloc(void **ptr, size_t size,
                                           unsigned int flags) {
  return cudaHostAlloc(ptr, size, flags);
}
static inline mapsError_t mapsFreeHost(void *ptr) { return cudaFreeHost(ptr); }
static inline mapsError_t mapsHostFree(void *ptr) { return cudaFreeHost(ptr); }
static inline mapsError_t mapsMemFreeHost(void *ptr) {
  return cudaFreeHost(ptr);
}
static inline mapsError_t mapsHostGetDevicePointer(void **devPtr, void *hstPtr,
                                                   unsigned int flags) {
  return cudaHostGetDevicePointer(devPtr, hstPtr, flags);
}

static inline mapsError_t mapsMemcpy(void *dst, const void *src, size_t count,
                                     mapsMemcpyKind kind) {
  return cudaMemcpy(dst, src, count, kind);
}
static inline mapsError_t mapsMemcpyAsync(void *dst, const void *src,
                                          size_t count, mapsMemcpyKind kind,
                                          mapsStream_t stream NVSC_DPARM(0)) {
  return cudaMemcpyAsync(dst, src, count, kind, stream);
}
static inline mapsError_t mapsMemcpy2D(void *dst, size_t dpitch,
                                       const void *src, size_t spitch,
                                       size_t width, size_t height,
                                       mapsMemcpyKind kind) {
  return cudaMemcpy2D(dst, dpitch, src, spitch, width, height, kind);
}
static inline mapsError_t mapsMemcpy2DAsync(
    void *dst, size_t dpitch, const void *src, size_t spitch, size_t width,
    size_t height, mapsMemcpyKind kind, mapsStream_t stream NVSC_DPARM(0)) {
  return cudaMemcpy2DAsync(dst, dpitch, src, spitch, width, height, kind,
                           stream);
}
static inline mapsError_t mapsMemcpyToSymbol(
    const void *symbol, const void *src, size_t count, size_t offset NVSC_DPARM(0),
    mapsMemcpyKind kind NVSC_DPARM(mapsMemcpyHostToDevice)) {
  return cudaMemcpyToSymbol(symbol, src, count, offset, kind);
}
static inline mapsError_t mapsMemset(void *dst, int value, size_t count) {
  return cudaMemset(dst, value, count);
}
static inline mapsError_t mapsMemsetAsync(void *dst, int value, size_t count,
                                          mapsStream_t stream NVSC_DPARM(0)) {
  return cudaMemsetAsync(dst, value, count, stream);
}

static inline mapsError_t mapsStreamCreate(mapsStream_t *stream
#ifdef __cplusplus
                                           ,
                                           bool useQfc = true
#endif
) {
#ifdef __cplusplus
  (void)useQfc;
#endif
  return cudaStreamCreate(stream);
}
static inline mapsError_t mapsStreamCreateWithFlags(mapsStream_t *stream,
                                                    unsigned int flags
#ifdef __cplusplus
                                                    ,
                                                    bool useQfc = true
#endif
) {
#ifdef __cplusplus
  (void)useQfc;
#endif
  return cudaStreamCreateWithFlags(stream, flags);
}
static inline mapsError_t mapsStreamCreateWithPriority(mapsStream_t *stream,
                                                       unsigned int flags,
                                                       int priority
#ifdef __cplusplus
                                                       ,
                                                       bool useQfc = true
#endif
) {
#ifdef __cplusplus
  (void)useQfc;
#endif
  return cudaStreamCreateWithPriority(stream, flags, priority);
}
static inline mapsError_t mapsStreamDestroy(mapsStream_t stream) {
  return cudaStreamDestroy(stream);
}
static inline mapsError_t mapsStreamQuery(mapsStream_t stream) {
  return cudaStreamQuery(stream);
}
static inline mapsError_t mapsStreamSynchronize(mapsStream_t stream) {
  return cudaStreamSynchronize(stream);
}
static inline mapsError_t mapsStreamWaitEvent(mapsStream_t stream,
                                              mapsEvent_t event,
                                              unsigned int flags NVSC_DPARM(0)) {
  return cudaStreamWaitEvent(stream, event, flags);
}
static inline mapsError_t mapsStreamAddCallback(mapsStream_t stream,
                                                mapsStreamCallback_t callback,
                                                void *userData,
                                                unsigned int flags) {
  return cudaStreamAddCallback(stream, callback, userData, flags);
}
static inline mapsError_t mapsLaunchHostFunc(mapsStream_t stream,
                                             mapsHostFn_t fn, void *userData) {
  return cudaLaunchHostFunc(stream, fn, userData);
}
static inline mapsError_t mapsLaunchKernel(const void *functionAddress,
                                           dim3 gridDim, dim3 blockDim,
                                           void **args,
                                           size_t sharedMemBytes NVSC_DPARM(0),
                                           mapsStream_t stream NVSC_DPARM(0)) {
  return cudaLaunchKernel(functionAddress, gridDim, blockDim, args,
                          sharedMemBytes, stream);
}
static inline mapsError_t mapsLaunchKernelExc(const mapsLaunchConfig_t *config,
                                              const void *functionAddress,
                                              void **args) {
  return cudaLaunchKernel(functionAddress, config->gridDim, config->blockDim,
                          args, config->dynamicSmemBytes, config->stream);
}

static inline mapsError_t mapsEventCreate(mapsEvent_t *event) {
  return cudaEventCreate(event);
}
static inline mapsError_t mapsEventCreateWithFlags(mapsEvent_t *event,
                                                   unsigned int flags) {
  return cudaEventCreateWithFlags(event, flags);
}
static inline mapsError_t mapsEventRecord(mapsEvent_t event,
                                          mapsStream_t stream NVSC_DPARM(0)) {
  return cudaEventRecord(event, stream);
}
static inline mapsError_t mapsEventDestroy(mapsEvent_t event) {
  return cudaEventDestroy(event);
}
static inline mapsError_t mapsEventSynchronize(mapsEvent_t event) {
  return cudaEventSynchronize(event);
}
static inline mapsError_t mapsEventQuery(mapsEvent_t event) {
  return cudaEventQuery(event);
}
static inline mapsError_t mapsEventElapsedTime(float *ms, mapsEvent_t start,
                                               mapsEvent_t stop) {
  return cudaEventElapsedTime(ms, start, stop);
}
static inline mapsError_t mapsEventElapsedTimeEx(float *ms, uint64_t *cycle,
                                                 mapsEvent_t start,
                                                 mapsEvent_t stop) {
  mapsError_t err = cudaEventElapsedTime(ms, start, stop);
  if (cycle) {
    *cycle = (uint64_t)(*ms * 1000000.0f);
  }
  return err;
}

static inline mapsError_t mapsGetLastError(void) { return cudaGetLastError(); }
static inline const char *mapsGetErrorString(mapsError_t err) {
  return cudaGetErrorString(err);
}
static inline const char *mapsGetErrorName(mapsError_t err) {
  return cudaGetErrorName(err);
}

static inline mapsError_t mapsMemobjGetPhysicalAddress(void *ptr,
                                                       uint64_t *address) {
  *address = (uint64_t)ptr;
  return cudaSuccess;
}
static inline mapsError_t mapsMemobjGetDevMemGpupaEx(void *ptr, void **pa) {
  *pa = ptr;
  return cudaSuccess;
}
static inline mapsError_t mapsGetSymbolAddress(void **devicePtr,
                                               const void *symbol) {
  return cudaGetSymbolAddress(devicePtr, symbol);
}

static inline mapsError_t mapsGetApcMask(int device, uint32_t *mask) {
  int smCount = 0;
  mapsError_t err =
      cudaDeviceGetAttribute(&smCount, cudaDevAttrMultiProcessorCount, device);
  *mask = (err == cudaSuccess && smCount > 0) ? 0xffffffffu : 0u;
  return err;
}
static inline mapsError_t mapsSetEnv(const char *name, const char *value) {
  return setenv(name, value, 1) == 0 ? cudaSuccess : cudaErrorUnknown;
}
static inline mapsError_t mapsCtxSynchronize(void) {
  return cudaDeviceSynchronize();
}
static inline mapsError_t mapsStreamTestNop(mapsStream_t stream,
                                            uint32_t qfcMode NVSC_DPARM(0)) {
  (void)stream;
  (void)qfcMode;
  return cudaSuccess;
}
static inline mapsError_t mapsThreadExchangeStreamCaptureMode(
    enum mapsStreamCaptureMode *mode) {
  (void)mode;
  return cudaSuccess;
}
static inline mapsError_t mapsCfgUpdateEx(int nargs, uint32_t args[],
                                          int nevents, void *e_addrs[],
                                          uint32_t write_values[],
                                          uint32_t wait_values[],
                                          mapsStream_t stream) {
  (void)nargs;
  (void)args;
  (void)nevents;
  (void)e_addrs;
  (void)write_values;
  (void)wait_values;
  (void)stream;
  return cudaErrorNotSupported;
}

#undef NVSC_DPARM

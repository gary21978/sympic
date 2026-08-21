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
struct mapsArray {};
typedef struct mapsArray *mapsArray_t;
typedef const struct mapsArray *mapsArray_const_t;
typedef struct imapsCtx_t *mapsCtx_t;
typedef struct imapsModule_t *mapsModule_t;
typedef struct imapsModuleSymbol_t *mapsFunction_t;
typedef struct imapsMemPoolHandle_t *mapsMemPool_t;

typedef void (*mapsStreamCallback_t)(mapsStream_t stream, mapsError_t status,
                                     void *userData);
typedef void (*mapsHostFn_t)(void *userData);

typedef struct mapsUUID_t {
  char bytes[16];
} mapsUUID;
typedef mapsUUID mapsUUID_t;

#define maps_IPC_HANDLE_SIZE 64
typedef struct mapsIpcMemHandle_st {
  char reserved[maps_IPC_HANDLE_SIZE];
} mapsIpcMemHandle_t;
typedef struct mapsIpcEventHandle_st {
  char reserved[maps_IPC_HANDLE_SIZE];
} mapsIpcEventHandle_t;

typedef enum mapsMemoryAdvise {
  mapsMemAdviseSetReadMostly = 1,
  mapsMemAdviseUnsetReadMostly = 2,
  mapsMemAdviseSetPreferredLocation = 3,
  mapsMemAdviseUnsetPreferredLocation = 4,
  mapsMemAdviseSetAccessedBy = 5,
  mapsMemAdviseUnsetAccessedBy = 6,
  mapsMemAdviseSetCoarseGrain = 100,
  mapsMemAdviseUnsetCoarseGrain = 101
} mapsMemoryAdvise;

typedef enum mapsMemRangeCoherencyMode {
  mapsMemRangeCoherencyModeFineGrain = 0,
  mapsMemRangeCoherencyModeCoarseGrain = 1,
  mapsMemRangeCoherencyModeIndeterminate = 2
} mapsMemRangeCoherencyMode;

typedef enum mapsMemRangeAttribute {
  mapsMemRangeAttributeReadMostly = 1,
  mapsMemRangeAttributePreferredLocation = 2,
  mapsMemRangeAttributeAccessedBy = 3,
  mapsMemRangeAttributeLastPrefetchLocation = 4,
  mapsMemRangeAttributeCoherencyMode = 100
} mapsMemRangeAttribute;

typedef enum mapsMemPoolAttr {
  mapsMemPoolReuseFollowEventDependencies = 0x1,
  mapsMemPoolReuseAllowOpportunistic = 0x2,
  mapsMemPoolReuseAllowInternalDependencies = 0x3,
  mapsMemPoolAttrReleaseThreshold = 0x4,
  mapsMemPoolAttrReservedMemCurrent = 0x5,
  mapsMemPoolAttrReservedMemHigh = 0x6,
  mapsMemPoolAttrUsedMemCurrent = 0x7,
  mapsMemPoolAttrUsedMemHigh = 0x8
} mapsMemPoolAttr;

typedef enum mapsMemLocationType {
  mapsMemLocationTypeInvalid = 0,
  mapsMemLocationTypeDevice = 1
} mapsMemLocationType;

typedef struct mapsMemLocation {
  mapsMemLocationType type;
  int id;
} mapsMemLocation;

typedef enum mapsMemAccessFlags {
  mapsMemAccessFlagsProtNone = 0,
  mapsMemAccessFlagsProtRead = 1,
  mapsMemAccessFlagsProtReadWrite = 3
} mapsMemAccessFlags;

typedef struct mapsMemAccessDesc {
  mapsMemLocation location;
  mapsMemAccessFlags flags;
} mapsMemAccessDesc;

typedef enum mapsMemAllocationType {
  mapsMemAllocationTypeInvalid = 0x0,
  mapsMemAllocationTypePinned = 0x1,
  mapsMemAllocationTypeMax = 0x7fffffff
} mapsMemAllocationType;

typedef enum mapsMemAllocationHandleType {
  mapsMemHandleTypeNone = 0x0,
  mapsMemHandleTypePosixFileDescriptor = 0x1,
  mapsMemHandleTypeWin32 = 0x2,
  mapsMemHandleTypeWin32Kmt = 0x4
} mapsMemAllocationHandleType;

typedef struct mapsMemPoolProps {
  mapsMemAllocationType allocType;
  mapsMemAllocationHandleType handleTypes;
  mapsMemLocation location;
  void *win32SecurityAttributes;
  unsigned char reserved[64];
} mapsMemPoolProps;

typedef struct mapsMemPoolPtrExportData {
  unsigned char reserved[64];
} mapsMemPoolPtrExportData;

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

typedef enum mapsPointer_attribute {
  MAPS_POINTER_ATTRIBUTE_CONTEXT = 1,
  MAPS_POINTER_ATTRIBUTE_MEMORY_TYPE = 2,
  MAPS_POINTER_ATTRIBUTE_DEVICE_POINTER = 3,
  MAPS_POINTER_ATTRIBUTE_HOST_POINTER = 4,
  MAPS_POINTER_ATTRIBUTE_P2P_TOKENS = 5,
  MAPS_POINTER_ATTRIBUTE_SYNC_MEMOPS = 6,
  MAPS_POINTER_ATTRIBUTE_BUFFER_ID = 7,
  MAPS_POINTER_ATTRIBUTE_IS_MANAGED = 8,
  MAPS_POINTER_ATTRIBUTE_DEVICE_ORDINAL = 9,
  MAPS_POINTER_ATTRIBUTE_IS_LEGACY_MAPS_IPC_CAPABLE = 10,
  MAPS_POINTER_ATTRIBUTE_RANGE_START_ADDR = 11,
  MAPS_POINTER_ATTRIBUTE_RANGE_SIZE = 12,
  MAPS_POINTER_ATTRIBUTE_MAPPED = 13,
  MAPS_POINTER_ATTRIBUTE_ALLOWED_HANDLE_TYPES = 14,
  MAPS_POINTER_ATTRIBUTE_IS_GPU_DIRECT_RDMA_CAPABLE = 15,
  MAPS_POINTER_ATTRIBUTE_ACCESS_FLAGS = 16,
  MAPS_POINTER_ATTRIBUTE_MEMPOOL_HANDLE = 17
} mapsPointer_attribute;

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

/* Names from the MAPS header that do not have one-to-one CUDA enum values. */
#define mapsDeviceAttributeUnused ((mapsDeviceAttribute_t)-1)
#define mapsDeviceAttributeMaxThreadsDim mapsDeviceAttributeMaxBlockDimX
#define mapsDeviceAttributeTotalGlobalMem ((mapsDeviceAttribute_t)1001)
#define mapsDeviceAttributeSharedMemPerBlockOptin ((mapsDeviceAttribute_t)1002)
#define mapsDeviceAttributeReservedSharedMemPerBlock ((mapsDeviceAttribute_t)1003)
#define mapsDeviceAttributeMaxPitch ((mapsDeviceAttribute_t)1004)
#define mapsDeviceAttributeTextureAlignment ((mapsDeviceAttribute_t)1005)
#define mapsDeviceAttributeTexturePitchAlignment ((mapsDeviceAttribute_t)1006)
#define mapsDeviceAttributeTotalConstantMemory ((mapsDeviceAttribute_t)1007)
#define mapsDeviceAttributeL2CacheSize ((mapsDeviceAttribute_t)1008)
#define mapsDeviceAttributeMaxRegistersPerBlock ((mapsDeviceAttribute_t)1009)
#define mapsDeviceAttributeMaxRegistersPerMultiprocessor ((mapsDeviceAttribute_t)1010)
#define mapsDeviceAttributeSharedMemPerMultiprocessor ((mapsDeviceAttribute_t)1011)
#define mapsDeviceAttributeComputeMode ((mapsDeviceAttribute_t)1012)
#define mapsDeviceAttributeIntegrated ((mapsDeviceAttribute_t)1013)
#define mapsDeviceAttributeCanMapHostMemory ((mapsDeviceAttribute_t)1014)
#define mapsDeviceAttributeEccEnabled ((mapsDeviceAttribute_t)1015)
#define mapsDeviceAttributePciBusId ((mapsDeviceAttribute_t)1016)
#define mapsDeviceAttributePciDeviceId ((mapsDeviceAttribute_t)1017)
#define mapsDeviceAttributePciDomainID ((mapsDeviceAttribute_t)1018)
#define mapsDeviceAttributeTccDriver ((mapsDeviceAttribute_t)1019)
#define mapsDeviceAttributeMaxSharedMemoryPerMultiprocessor ((mapsDeviceAttribute_t)1020)
#define mapsDeviceAttributeSingleToDoublePrecisionPerfRatio ((mapsDeviceAttribute_t)1021)
#define mapsDeviceAttributeStreamPrioritiesSupported ((mapsDeviceAttribute_t)1022)
#define mapsDeviceAttributeGlobalL1CacheSupported ((mapsDeviceAttribute_t)1023)
#define mapsDeviceAttributeLocalL1CacheSupported ((mapsDeviceAttribute_t)1024)
#define mapsDeviceAttributeCooperativeMultiDeviceLaunch ((mapsDeviceAttribute_t)1025)
#define mapsDeviceAttributeHostNativeAtomicSupported ((mapsDeviceAttribute_t)1026)
#define mapsDeviceAttributeConcurrentManagedAccess ((mapsDeviceAttribute_t)1027)
#define mapsDeviceAttributePageableMemoryAccess ((mapsDeviceAttribute_t)1028)
#define mapsDeviceAttributeDirectManagedMemAccessFromHost ((mapsDeviceAttribute_t)1029)
#define mapsDeviceAttributeComputePreemptionSupported ((mapsDeviceAttribute_t)1030)
#define mapsDeviceAttributeCanUseHostPointerForRegisteredMem ((mapsDeviceAttribute_t)1031)
#define mapsDeviceAttributeCanUseStreamWaitValue ((mapsDeviceAttribute_t)1032)
#define mapsDeviceAttributeCooperativeMultiDeviceUnmatchedFunc ((mapsDeviceAttribute_t)1033)
#define mapsDeviceAttributeCooperativeMultiDeviceUnmatchedGridDim ((mapsDeviceAttribute_t)1034)
#define mapsDeviceAttributeCooperativeMultiDeviceUnmatchedBlockDim ((mapsDeviceAttribute_t)1035)
#define mapsDeviceAttributeCooperativeMultiDeviceUnmatchedSharedMem ((mapsDeviceAttribute_t)1036)
#define mapsDeviceAttributeVirtualMemoryManagementSupported ((mapsDeviceAttribute_t)1037)
#define mapsDeviceAttributeMemoryPoolsSupported ((mapsDeviceAttribute_t)1038)
#define mapsDeviceAttributeMemoryPoolSupportedHandleTypes ((mapsDeviceAttribute_t)1039)
#define mapsDeviceAttributeAccessPolicyMaxWindowSize ((mapsDeviceAttribute_t)1040)
#define mapsDeviceAttributePersistingL2CacheMaxSize ((mapsDeviceAttribute_t)1041)
#define mapsDeviceAttributePageableMemoryAccessUsesHostPageTables ((mapsDeviceAttribute_t)1042)
#define mapsDeviceAttributeMultiGpuBoardGroupID ((mapsDeviceAttribute_t)1043)
#define mapsDeviceAttributeIsMultiGpuBoard ((mapsDeviceAttribute_t)1044)
#define mapsDeviceAttributeUuid ((mapsDeviceAttribute_t)1045)
#define mapsDeviceAttributeLuid ((mapsDeviceAttribute_t)1046)
#define mapsDeviceAttributeLuidDeviceNodeMask ((mapsDeviceAttribute_t)1047)
#define mapsDeviceAttributePhysicalMultiProcessorCount ((mapsDeviceAttribute_t)1048)
#define mapsDeviceAttributeWallClockRate ((mapsDeviceAttribute_t)1049)
#define mapsDeviceAttributeArch ((mapsDeviceAttribute_t)1050)
#define mapsDeviceAttributeName ((mapsDeviceAttribute_t)1051)
#define mapsDeviceAttributeIsLargeBar ((mapsDeviceAttribute_t)1052)
#define mapsDeviceAttributeFineGrainSupport ((mapsDeviceAttribute_t)1053)
#define mapsDeviceAttributeAsicRevision ((mapsDeviceAttribute_t)1054)
#define mapsDeviceAttributeImageSupport ((mapsDeviceAttribute_t)1055)
#define mapsDeviceAttributeHdpMemFlushCntl ((mapsDeviceAttribute_t)1056)
#define mapsDeviceAttributeHdpRegFlushCntl ((mapsDeviceAttribute_t)1057)
#define mapsDeviceAttributeGcnArch ((mapsDeviceAttribute_t)1058)
#define mapsDeviceAttributeGcnArchName ((mapsDeviceAttribute_t)1059)
#define mapsDeviceAttributeGPUDirectRDMASupported ((mapsDeviceAttribute_t)1060)
#define mapsDeviceAttributeHostRegisterSupported ((mapsDeviceAttribute_t)1061)
#define mapsDeviceAttributeKernelExecTimeout ((mapsDeviceAttribute_t)1062)
#define mapsDeviceAttributeDeviceOverlap ((mapsDeviceAttribute_t)1063)
#define mapsDeviceAttributeSurfaceAlignment ((mapsDeviceAttribute_t)1064)
#define mapsDeviceAttributeCudaCompatibleBegin ((mapsDeviceAttribute_t)2000)
#define mapsDeviceAttributeCudaCompatibleEnd ((mapsDeviceAttribute_t)2999)
#define mapsDeviceAttributeAmdSpecificBegin ((mapsDeviceAttribute_t)3000)
#define mapsDeviceAttributeAmdSpecificEnd ((mapsDeviceAttribute_t)3999)
#define mapsDeviceAttributeVendorSpecificBegin ((mapsDeviceAttribute_t)4000)

#define mapsMemoryTypeUnregistered cudaMemoryTypeUnregistered
#define mapsMemoryTypeHost cudaMemoryTypeHost
#define mapsMemoryTypeDevice cudaMemoryTypeDevice
#define mapsMemoryTypeManaged cudaMemoryTypeManaged
#define mapsMemoryTypeArray ((mapsMemoryType)10)
#define mapsMemoryTypeUnified mapsMemoryTypeManaged

#define mapsLimitRange ((mapsLimit_t)3)

#define mapsSuccess cudaSuccess
#define mapsErrorNotReady cudaErrorNotReady
#define mapsErrorInvalidValue cudaErrorInvalidValue
#define mapsErrorMemoryAllocation cudaErrorMemoryAllocation
#define mapsErrorInvalidDevice cudaErrorInvalidDevice
#define mapsErrorNoDevice cudaErrorNoDevice
#define mapsErrorNotSupported cudaErrorNotSupported
#define mapsErrorUnknown cudaErrorUnknown
#define mapsErrorInvalidConfiguration cudaErrorInvalidConfiguration
#define mapsErrorInvalidDeviceFunction cudaErrorInvalidDeviceFunction
#define mapsErrorInvalidDevicePointer cudaErrorInvalidDevicePointer
#define mapsErrorInvalidMemcpyDirection cudaErrorInvalidMemcpyDirection
#define mapsErrorInvalidSymbol cudaErrorInvalidSymbol
#define mapsErrorLaunchFailure cudaErrorLaunchFailure
#define mapsErrorLaunchOutOfResources cudaErrorLaunchOutOfResources
#define mapsErrorLaunchTimeOut cudaErrorLaunchTimeout
#define mapsErrorNoBinaryForGpu cudaErrorNoKernelImageForDevice
#define mapsErrorNotInitialized cudaErrorInitializationError
#define mapsErrorPeerAccessAlreadyEnabled cudaErrorPeerAccessAlreadyEnabled
#define mapsErrorPeerAccessNotEnabled cudaErrorPeerAccessNotEnabled
#define mapsErrorPeerAccessUnsupported cudaErrorPeerAccessUnsupported
#define mapsErrorPriorLaunchFailure cudaErrorPriorLaunchFailure
#define mapsErrorUnsupportedLimit cudaErrorUnsupportedLimit
#define mapsErrorIllegalAddress cudaErrorIllegalAddress
#define mapsErrorAssert cudaErrorAssert
#define mapsErrorOperatingSystem cudaErrorOperatingSystem
#define mapsErrorIllegalState cudaErrorIllegalState
#define mapsErrorInvalidContext cudaErrorIncompatibleDriverContext
#define mapsErrorContextIsDestroyed cudaErrorContextIsDestroyed
#define mapsErrorStreamCaptureUnsupported cudaErrorStreamCaptureUnsupported
#define mapsErrorStreamCaptureInvalidated cudaErrorStreamCaptureInvalidated
#define mapsErrorStreamCaptureMerge cudaErrorStreamCaptureMerge
#define mapsErrorStreamCaptureUnmatched cudaErrorStreamCaptureUnmatched
#define mapsErrorStreamCaptureUnjoined cudaErrorStreamCaptureUnjoined
#define mapsErrorStreamCaptureIsolation cudaErrorStreamCaptureIsolation
#define mapsErrorStreamCaptureImplicit cudaErrorStreamCaptureImplicit
#define mapsErrorCapturedEvent cudaErrorCapturedEvent
#define mapsErrorStreamCaptureWrongThread cudaErrorStreamCaptureWrongThread
#define mapsErrorGraphExecUpdateFailure cudaErrorGraphExecUpdateFailure
#define mapsErrorInvalidHandle cudaErrorInvalidResourceHandle
#define mapsErrorOutOfMemory cudaErrorMemoryAllocation
#define mapsErrorNotFound cudaErrorNotFound
#define mapsErrorAlreadyAcquired cudaErrorNotSupported
#define mapsErrorAlreadyMapped cudaErrorNotSupported
#define mapsErrorArrayIsMapped cudaErrorNotSupported
#define mapsErrorContextAlreadyCurrent cudaErrorNotSupported
#define mapsErrorContextAlreadyInUse cudaErrorNotSupported
#define mapsErrorDeinitialized cudaErrorCudartUnloading
#define mapsErrorECCNotCorrectable cudaErrorECCUncorrectable
#define mapsErrorFileNotFound cudaErrorFileNotFound
#define mapsErrorHostMemoryAlreadyRegistered cudaErrorHostMemoryAlreadyRegistered
#define mapsErrorHostMemoryNotRegistered cudaErrorHostMemoryNotRegistered
#define mapsErrorInvalidGraphicsContext cudaErrorNotSupported
#define mapsErrorInvalidImage cudaErrorInvalidKernelImage
#define mapsErrorInvalidKernelFile cudaErrorInvalidKernelImage
#define mapsErrorInvalidPitchValue cudaErrorInvalidPitchValue
#define mapsErrorInvalidSource cudaErrorNotSupported
#define mapsErrorMapFailed cudaErrorMapBufferObjectFailed
#define mapsErrorMissingConfiguration cudaErrorMissingConfiguration
#define mapsErrorNotMapped cudaErrorNotSupported
#define mapsErrorNotMappedAsArray cudaErrorNotSupported
#define mapsErrorNotMappedAsPointer cudaErrorNotSupported
#define mapsErrorProfilerAlreadyStarted cudaErrorProfilerAlreadyStarted
#define mapsErrorProfilerAlreadyStopped cudaErrorProfilerAlreadyStopped
#define mapsErrorProfilerDisabled cudaErrorProfilerDisabled
#define mapsErrorProfilerNotInitialized cudaErrorProfilerNotInitialized
#define mapsErrorRuntimeMemory cudaErrorMemoryAllocation
#define mapsErrorRuntimeOther cudaErrorUnknown
#define mapsErrorSetOnActiveProcess cudaErrorSetOnActiveProcess
#define mapsErrorSharedObjectInitFailed cudaErrorSharedObjectInitFailed
#define mapsErrorSharedObjectSymbolNotFound cudaErrorSharedObjectSymbolNotFound
#define mapsErrorTbd cudaErrorNotSupported
#define mapsErrorUnmapFailed cudaErrorUnmapBufferObjectFailed
#define mapsErrorCooperativeLaunchTooLarge cudaErrorCooperativeLaunchTooLarge

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
static inline mapsError_t mapsMalloc3D(mapsPitchedPtr *pitchedDevPtr,
                                       mapsExtent extent) {
  cudaExtent cuda_extent = make_cudaExtent(extent.width, extent.height,
                                           extent.depth);
  cudaPitchedPtr cuda_ptr;
  mapsError_t err = cudaMalloc3D(&cuda_ptr, cuda_extent);
  if (err == cudaSuccess) {
    pitchedDevPtr->ptr = cuda_ptr.ptr;
    pitchedDevPtr->pitch = cuda_ptr.pitch;
    pitchedDevPtr->xsize = cuda_ptr.xsize;
    pitchedDevPtr->ysize = cuda_ptr.ysize;
  }
  return err;
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
static inline mapsError_t mapsHostRegister(void *ptr, size_t size,
                                           unsigned int flags) {
  return cudaHostRegister(ptr, size, flags);
}
static inline mapsError_t mapsMemAllocAsync(void **ptr, size_t size,
                                            mapsStream_t stream) {
#if defined(CUDART_VERSION) && CUDART_VERSION >= 11020
  return cudaMallocAsync(ptr, size, stream);
#else
  (void)stream;
  return cudaMalloc(ptr, size);
#endif
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
static inline mapsError_t mapsMemcpy3D(const struct mapsMemcpy3DParms *p) {
  cudaMemcpy3DParms cp = {};
  cp.srcArray = (cudaArray_t)p->srcArray;
  cp.srcPos = make_cudaPos(p->srcPos.x, p->srcPos.y, p->srcPos.z);
  cp.srcPtr = make_cudaPitchedPtr(p->srcPtr.ptr, p->srcPtr.pitch,
                                  p->srcPtr.xsize, p->srcPtr.ysize);
  cp.dstArray = (cudaArray_t)p->dstArray;
  cp.dstPos = make_cudaPos(p->dstPos.x, p->dstPos.y, p->dstPos.z);
  cp.dstPtr = make_cudaPitchedPtr(p->dstPtr.ptr, p->dstPtr.pitch,
                                  p->dstPtr.xsize, p->dstPtr.ysize);
  cp.extent = make_cudaExtent(p->extent.width, p->extent.height,
                              p->extent.depth);
  cp.kind = p->kind;
  return cudaMemcpy3D(&cp);
}
static inline mapsError_t mapsMemcpy3DAsync(
    const struct mapsMemcpy3DParms *p, mapsStream_t stream NVSC_DPARM(0)) {
  cudaMemcpy3DParms cp = {};
  cp.srcArray = (cudaArray_t)p->srcArray;
  cp.srcPos = make_cudaPos(p->srcPos.x, p->srcPos.y, p->srcPos.z);
  cp.srcPtr = make_cudaPitchedPtr(p->srcPtr.ptr, p->srcPtr.pitch,
                                  p->srcPtr.xsize, p->srcPtr.ysize);
  cp.dstArray = (cudaArray_t)p->dstArray;
  cp.dstPos = make_cudaPos(p->dstPos.x, p->dstPos.y, p->dstPos.z);
  cp.dstPtr = make_cudaPitchedPtr(p->dstPtr.ptr, p->dstPtr.pitch,
                                  p->dstPtr.xsize, p->dstPtr.ysize);
  cp.extent = make_cudaExtent(p->extent.width, p->extent.height,
                              p->extent.depth);
  cp.kind = p->kind;
  return cudaMemcpy3DAsync(&cp, stream);
}
static inline mapsError_t mapsMemcpyToSymbol(
    const void *symbol, const void *src, size_t count, size_t offset NVSC_DPARM(0),
    mapsMemcpyKind kind NVSC_DPARM(mapsMemcpyHostToDevice)) {
  return cudaMemcpyToSymbol(symbol, src, count, offset, kind);
}
static inline mapsError_t mapsMemcpyFromSymbol(
    void *dst, const void *symbol, size_t count, size_t offset NVSC_DPARM(0),
    mapsMemcpyKind kind NVSC_DPARM(mapsMemcpyDeviceToHost)) {
  return cudaMemcpyFromSymbol(dst, symbol, count, offset, kind);
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
static inline mapsError_t mapsStreamGetDevice(mapsStream_t stream,
                                              mapsDevice_t *device) {
  (void)stream;
  return cudaGetDevice(device);
}
static inline mapsError_t mapsExtStreamCreateWithCUMask(
    mapsStream_t *stream, uint32_t cuMaskSize, const uint32_t *cuMask) {
  (void)cuMaskSize;
  (void)cuMask;
  return cudaStreamCreate(stream);
}
static inline mapsError_t mapsStreamBeginCapture(
    mapsStream_t stream, enum mapsStreamCaptureMode mode) {
  return cudaStreamBeginCapture(stream, (cudaStreamCaptureMode)mode);
}
static inline mapsError_t mapsStreamEndCapture(mapsStream_t stream,
                                               void **graph) {
  return cudaStreamEndCapture(stream, (cudaGraph_t *)graph);
}
static inline mapsError_t mapsStreamWaitValue32(mapsStream_t stream,
                                                void *addr, uint32_t value,
                                                unsigned int flags) {
  (void)stream;
  (void)addr;
  (void)value;
  (void)flags;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsStreamWaitValue64(mapsStream_t stream,
                                                void *addr, uint64_t value,
                                                unsigned int flags) {
  (void)stream;
  (void)addr;
  (void)value;
  (void)flags;
  return cudaErrorNotSupported;
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
static inline mapsError_t mapsGetSymbolSize(size_t *size, const void *symbol) {
  return cudaGetSymbolSize(size, symbol);
}

#ifdef __cplusplus
template <typename Symbol>
static inline mapsError_t mapsMemcpyToSymbol(
    const Symbol &symbol, const void *src, size_t count, size_t offset = 0,
    mapsMemcpyKind kind = mapsMemcpyHostToDevice) {
  return cudaMemcpyToSymbol(symbol, src, count, offset, kind);
}
template <typename Symbol>
static inline mapsError_t mapsMemcpyFromSymbol(
    void *dst, const Symbol &symbol, size_t count, size_t offset = 0,
    mapsMemcpyKind kind = mapsMemcpyDeviceToHost) {
  return cudaMemcpyFromSymbol(dst, symbol, count, offset, kind);
}
template <typename Symbol>
static inline mapsError_t mapsGetSymbolAddress(void **devicePtr,
                                               const Symbol &symbol) {
  return cudaGetSymbolAddress(devicePtr, symbol);
}
template <typename Symbol>
static inline mapsError_t mapsGetSymbolSize(size_t *size,
                                            const Symbol &symbol) {
  return cudaGetSymbolSize(size, symbol);
}
#endif

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
static inline mapsError_t mapsCtxCreate(mapsCtx_t *ctx, unsigned int flags,
                                        mapsDevice_t device) {
  (void)ctx;
  (void)flags;
  (void)device;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsCtxSetCurrent(mapsCtx_t ctx) {
  (void)ctx;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsCtxGetCurrent(mapsCtx_t *ctx) {
  if (ctx) *ctx = NULL;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsCtxDestroy(mapsCtx_t ctx) {
  (void)ctx;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsIpcGetMemHandle(mapsIpcMemHandle_t *handle,
                                              void *devPtr) {
  (void)handle;
  (void)devPtr;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsIpcOpenMemHandle(void **devPtr,
                                               mapsIpcMemHandle_t handle,
                                               unsigned int flags) {
  (void)devPtr;
  (void)handle;
  (void)flags;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsIpcCloseMemHandle(void *devPtr) {
  (void)devPtr;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsIpcGetEventHandle(mapsIpcEventHandle_t *handle,
                                                mapsEvent_t event) {
  (void)handle;
  (void)event;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsIpcOpenEventHandle(mapsEvent_t *event,
                                                 mapsIpcEventHandle_t handle) {
  (void)event;
  (void)handle;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsDevReset(uint32_t resetType,
                                       int32_t *resetStatus) {
  (void)resetType;
  if (resetStatus) *resetStatus = 0;
  return cudaDeviceReset();
}
static inline mapsError_t mapsApc32FwUpdateEx(void) {
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsGetAsidEx(uint32_t *asid) {
  if (asid) *asid = 0;
  return cudaErrorNotSupported;
}
static inline mapsError_t mapsGetAmmuBaseAddrEx(uint64_t *addr) {
  if (addr) *addr = 0;
  return cudaErrorNotSupported;
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

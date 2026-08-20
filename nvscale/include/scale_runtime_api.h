/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE header.
 * It maps a subset of SCALE/MAPS/Aurora APIs to NVIDIA CUDA for local
 * compilation and functional bring-up.
 */
#pragma once

#include "scale.h"

typedef cudaError_t scaleError_t;
typedef cudaStream_t scaleStream_t;
typedef cudaEvent_t scaleEvent_t;
typedef enum cudaMemcpyKind scaleMemcpyKind;

#define scaleSuccess cudaSuccess
#define scaleMemcpyHostToHost cudaMemcpyHostToHost
#define scaleMemcpyHostToDevice cudaMemcpyHostToDevice
#define scaleMemcpyDeviceToHost cudaMemcpyDeviceToHost
#define scaleMemcpyDeviceToDevice cudaMemcpyDeviceToDevice
#define scaleMemcpyDefault cudaMemcpyDefault

static inline scaleError_t scaleSetDevice(int device) {
  return cudaSetDevice(device);
}
static inline scaleError_t scaleStreamCreate(scaleStream_t *stream) {
  return cudaStreamCreate(stream);
}
static inline scaleError_t scaleStreamDestroy(scaleStream_t stream) {
  return cudaStreamDestroy(stream);
}
static inline scaleError_t scaleStreamSynchronize(scaleStream_t stream) {
  return cudaStreamSynchronize(stream);
}
static inline scaleError_t scaleEventCreate(scaleEvent_t *event) {
  return cudaEventCreate(event);
}
static inline scaleError_t scaleEventRecord(scaleEvent_t event,
                                            scaleStream_t stream) {
  return cudaEventRecord(event, stream);
}
static inline scaleError_t scaleEventSynchronize(scaleEvent_t event) {
  return cudaEventSynchronize(event);
}
static inline scaleError_t scaleEventDestroy(scaleEvent_t event) {
  return cudaEventDestroy(event);
}
static inline scaleError_t scaleEventElapsedTime(float *ms, scaleEvent_t start,
                                                 scaleEvent_t end) {
  return cudaEventElapsedTime(ms, start, end);
}
static inline scaleError_t scaleMalloc(void **ptr, size_t size) {
  return cudaMalloc(ptr, size);
}
static inline scaleError_t scaleFree(void *ptr) { return cudaFree(ptr); }
static inline scaleError_t scaleMemcpy(void *dst, const void *src, size_t count,
                                       enum cudaMemcpyKind kind) {
  return cudaMemcpy(dst, src, count, kind);
}
static inline scaleError_t scaleMemcpyAsync(void *dst, const void *src,
                                            size_t count,
                                            enum cudaMemcpyKind kind,
                                            scaleStream_t stream) {
  return cudaMemcpyAsync(dst, src, count, kind, stream);
}

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

#ifndef _LIBSCALECXX_DEVICE_VISIBILITY
#define _LIBSCALECXX_DEVICE_VISIBILITY __device__ static inline
#endif
#ifndef _LIBSCALECXX_INLINE_VISIBILITY
#define _LIBSCALECXX_INLINE_VISIBILITY static inline
#endif
#ifndef _LIBSCALECXX_GSV_VISIBILITY
#define _LIBSCALECXX_GSV_VISIBILITY
#endif
#ifndef SCALERTAPI
#define SCALERTAPI
#endif
#ifndef __scalert_builtin__
#define __scalert_builtin__
#endif
#ifndef __device_builtin__
#define __device_builtin__
#endif

#ifndef __DDR
#define __DDR
#endif
#ifndef __ptr64
#define __ptr64
#endif
#ifndef KERNEL_M
#define KERNEL_M
#endif
#ifndef KERNEL_S
#define KERNEL_S
#endif
#ifndef __mem0__
#define __mem0__
#endif
#ifndef __mem1__
#define __mem1__
#endif
#ifndef __mem2__
#define __mem2__
#endif
#ifndef __mem3__
#define __mem3__
#endif
#ifndef __mem4__
#define __mem4__
#endif
#ifndef __mem5__
#define __mem5__
#endif
#ifndef __fix0__
#define __fix0__
#endif
#ifndef __fix1__
#define __fix1__
#endif
#ifndef __fix2__
#define __fix2__
#endif
#ifndef __fix3__
#define __fix3__
#endif
#ifndef __fix4__
#define __fix4__
#endif
#ifndef __fix5__
#define __fix5__
#endif
#ifndef MPU_SYNC
#define MPU_SYNC() do { } while (0)
#endif

typedef struct scale_dlhm_base_addr_t {
  unsigned core_id;
  unsigned mem0_ptr;
  unsigned mem1_ptr;
  unsigned mem2_ptr;
  unsigned mem3_ptr;
  unsigned mem4_ptr;
} scale_dlhm_base_addr_t;

__device__ static inline void __aurora_s_getStatB(void) {}
__device__ static inline void __aurora_s_fenceI(void) {}
__device__ static inline void __aurora_s_fenceD(void) { __threadfence(); }
__device__ static inline int __aurora_s_getStat(void) { return 0; }
__device__ static inline int __aurora_s_callmCounter(unsigned int) { return 0; }
__device__ static inline void __aurora_s_delay(void) {}
__device__ static inline void __aurora_s_startCounter(int) {}
__device__ static inline void __aurora_s_stopCounter(void) {}
__device__ static inline int __aurora_s_readCounter(int) { return 0; }

__device__ static inline void scale_set_dlhm_base_addr(scale_dlhm_base_addr_t *) {}
__device__ static inline void scale_set_persistent_base(unsigned *) {}
__device__ static inline void scale_set_tempx_base(unsigned *) {}

struct __align__(64) v16fp32 {
  float lane[16];
  __host__ __device__ float &operator[](int i) { return lane[i]; }
  __host__ __device__ const float &operator[](int i) const { return lane[i]; }
};
struct __align__(64) v16s32 {
  int lane[16];
  __host__ __device__ int &operator[](int i) { return lane[i]; }
  __host__ __device__ const int &operator[](int i) const { return lane[i]; }
};
struct __align__(64) v16u32 {
  unsigned int lane[16];
  __host__ __device__ unsigned int &operator[](int i) { return lane[i]; }
  __host__ __device__ const unsigned int &operator[](int i) const {
    return lane[i];
  }
};
struct __align__(64) v32s16 {
  short lane[32];
};
struct __align__(64) v32u16 {
  unsigned short lane[32];
};
struct __align__(64) v64s8 {
  signed char lane[64];
};
struct __align__(64) v64u8 {
  unsigned char lane[64];
};
struct __align__(32) v8s32 {
  int lane[8];
};
struct __align__(16) v4s32 {
  int lane[4];
};
struct __align__(128) v32s32 {
  int lane[32];
};

struct __align__(64) v8fp64 {
  double lane[8];

  __host__ __device__ double &operator[](int i) { return lane[i]; }
  __host__ __device__ const double &operator[](int i) const { return lane[i]; }
  __host__ __device__ operator v16s32() const {
    v16s32 r = {};
#pragma unroll
    for (int i = 0; i < 8; ++i) {
      r.lane[2 * i] = (int)lane[i];
      r.lane[2 * i + 1] = 0;
    }
    return r;
  }
};

enum APEID {
  APE0 = 0,
  APE1 = 1,
  APE2 = 2,
  APE3 = 3,
};

enum APCID {
  APC0 = 0,
  APC1 = 1,
  APC2 = 2,
  APC3 = 3,
  APC4 = 4,
  APC5 = 5,
  APC6 = 6,
  APC7 = 7,
};

__device__ static inline void *addressof(unsigned, void *sym) { return sym; }
__device__ static inline void *addressof(unsigned, void *sym, unsigned) {
  return sym;
}

__host__ __device__ static inline v8fp64 scale_make_v8fp64(double x) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) {
    r.lane[i] = x;
  }
  return r;
}

__host__ __device__ static inline v8fp64 operator+(v8fp64 a, v8fp64 b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) r.lane[i] = a.lane[i] + b.lane[i];
  return r;
}
__host__ __device__ static inline v8fp64 operator-(v8fp64 a, v8fp64 b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) r.lane[i] = a.lane[i] - b.lane[i];
  return r;
}
__host__ __device__ static inline v8fp64 operator*(v8fp64 a, v8fp64 b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) r.lane[i] = a.lane[i] * b.lane[i];
  return r;
}
__host__ __device__ static inline v8fp64 operator/(v8fp64 a, v8fp64 b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) r.lane[i] = a.lane[i] / b.lane[i];
  return r;
}
__host__ __device__ static inline v8fp64 operator-(v8fp64 a) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; ++i) r.lane[i] = -a.lane[i];
  return r;
}

__host__ __device__ static inline v8fp64 operator+(double a, v8fp64 b) {
  return scale_make_v8fp64(a) + b;
}
__host__ __device__ static inline v8fp64 operator+(v8fp64 a, double b) {
  return a + scale_make_v8fp64(b);
}
__host__ __device__ static inline v8fp64 operator-(double a, v8fp64 b) {
  return scale_make_v8fp64(a) - b;
}
__host__ __device__ static inline v8fp64 operator-(v8fp64 a, double b) {
  return a - scale_make_v8fp64(b);
}
__host__ __device__ static inline v8fp64 operator*(double a, v8fp64 b) {
  return scale_make_v8fp64(a) * b;
}
__host__ __device__ static inline v8fp64 operator*(v8fp64 a, double b) {
  return a * scale_make_v8fp64(b);
}
__host__ __device__ static inline v8fp64 operator/(double a, v8fp64 b) {
  return scale_make_v8fp64(a) / b;
}
__host__ __device__ static inline v8fp64 operator/(v8fp64 a, double b) {
  return a / scale_make_v8fp64(b);
}

__host__ __device__ static inline v16u32 operator+(v16u32 a, v16u32 b) {
  v16u32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] + b.lane[i];
  return r;
}
__host__ __device__ static inline v16u32 operator-(v16u32 a, v16u32 b) {
  v16u32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] - b.lane[i];
  return r;
}
__host__ __device__ static inline v16u32 operator*(v16u32 a, v16u32 b) {
  v16u32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] * b.lane[i];
  return r;
}
__host__ __device__ static inline v16s32 operator+(v16s32 a, v16s32 b) {
  v16s32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] + b.lane[i];
  return r;
}
__host__ __device__ static inline v16s32 operator-(v16s32 a, v16s32 b) {
  v16s32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] - b.lane[i];
  return r;
}
__host__ __device__ static inline v16s32 operator*(v16s32 a, v16s32 b) {
  v16s32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] * b.lane[i];
  return r;
}
__host__ __device__ static inline v16fp32 operator+(v16fp32 a, v16fp32 b) {
  v16fp32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] + b.lane[i];
  return r;
}
__host__ __device__ static inline v16fp32 operator-(v16fp32 a, v16fp32 b) {
  v16fp32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] - b.lane[i];
  return r;
}
__host__ __device__ static inline v16fp32 operator*(v16fp32 a, v16fp32 b) {
  v16fp32 r;
#pragma unroll
  for (int i = 0; i < 16; ++i) r.lane[i] = a.lane[i] * b.lane[i];
  return r;
}

template <typename Group, typename Barrier>
__device__ static inline void memcpy_async(Group, void *dst, const void *src,
                                           uint64_t bytes, Barrier &) {
  memcpy(dst, src, (size_t)bytes);
}

__device__ static inline void memcpy_ddr(void *dst, const void *src,
                                         uint64_t bytes) {
  memcpy(dst, src, (size_t)bytes);
}
__device__ static inline void memcpy_ddr2dm(void *dst, const void *src,
                                            uint64_t bytes) {
  memcpy(dst, src, (size_t)bytes);
}
__device__ static inline void memcpy_dm2ddr(void *dst, const void *src,
                                            uint64_t bytes) {
  memcpy(dst, src, (size_t)bytes);
}
__device__ static inline void memset_ddr(void *dst, int value, uint64_t bytes) {
  memset(dst, value, (size_t)bytes);
}

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
#ifndef __host_DDR
#define __host_DDR
#endif
#ifndef __host_ptr64
#define __host_ptr64
#endif
#ifndef __GLOBAL
#define __GLOBAL
#endif
#ifndef KERNEL_M
#define KERNEL_M
#endif
#ifndef KERNEL_S
#define KERNEL_S
#endif
#ifndef MPU_ENTRY
#define MPU_ENTRY
#endif
#ifndef MPU_FUNC
#define MPU_FUNC
#endif
#ifndef KERNEL
#define KERNEL
#endif
#ifndef APC_PUBLIC
#define APC_PUBLIC
#endif
#ifndef MPU_FUNC_PTR
#define MPU_FUNC_PTR
#endif
#ifndef async_call
#define async_call
#endif
#ifndef sync_call
#define sync_call
#endif
#ifndef async_enqueue
#define async_enqueue
#endif
#ifndef __prefetch_size__
#define __prefetch_size__(size_kib)
#endif
#ifndef __prefetch__
#define __prefetch__
#endif
#ifndef __busy__
#define __busy__
#endif
#ifndef __temp__
#define __temp__
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
#ifndef __MEM0
#define __MEM0
#endif
#ifndef __MEM1
#define __MEM1
#endif
#ifndef __MEM2
#define __MEM2
#endif
#ifndef __MEM3
#define __MEM3
#endif
#ifndef __MEM4
#define __MEM4
#endif
#ifndef __MEM5
#define __MEM5
#endif
#ifndef __acc__
#define __acc__
#endif
#ifndef __residency__
#define __residency__
#endif
#ifndef __macc0__
#define __macc0__ __mem0__ __acc__
#endif
#ifndef __macc1__
#define __macc1__ __mem1__ __acc__
#endif
#ifndef __macc2__
#define __macc2__ __mem2__ __acc__
#endif
#ifndef __macc3__
#define __macc3__ __mem3__ __acc__
#endif
#ifndef __macc4__
#define __macc4__ __mem4__ __acc__
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
#ifndef __input_persistent
#define __input_persistent
#endif
#ifndef __output_persistent
#define __output_persistent
#endif
#ifndef __DM
#define __DM
#endif
#ifndef __DM0
#define __DM0
#endif
#ifndef __DM1
#define __DM1
#endif
#ifndef __DM2
#define __DM2
#endif
#ifndef __DM3
#define __DM3
#endif
#ifndef __DM4
#define __DM4
#endif
#ifndef __DM5
#define __DM5
#endif
#ifndef __DM6
#define __DM6
#endif
#ifndef __DM7
#define __DM7
#endif
#ifndef __DM8
#define __DM8
#endif
#ifndef __DM9
#define __DM9
#endif
#ifndef __DM10
#define __DM10
#endif
#ifndef __DM11
#define __DM11
#endif
#ifndef __DM12
#define __DM12
#endif
#ifndef __DM13
#define __DM13
#endif
#ifndef __DM14
#define __DM14
#endif
#ifndef __DM15
#define __DM15
#endif
#ifndef __DM16
#define __DM16
#endif
#ifndef __DM17
#define __DM17
#endif
#ifndef __DM18
#define __DM18
#endif
#ifndef __DM19
#define __DM19
#endif
#ifndef __DM20
#define __DM20
#endif
#ifndef __DM21
#define __DM21
#endif
#ifndef __DM22
#define __DM22
#endif
#ifndef __DM23
#define __DM23
#endif
#ifndef __BARRIER
#define __BARRIER
#endif
#ifndef __SM_BARRIER
#define __SM_BARRIER
#endif
#ifndef __DDR_BARRIER
#define __DDR_BARRIER
#endif
#ifndef SECTION_ADDR
#define SECTION_ADDR(x)
#endif
#ifndef ADDRESS
#define ADDRESS(x)
#endif
#ifndef OBTAIN_MPU_CYCLE
#define OBTAIN_MPU_CYCLE(id)
#endif
#ifndef memid
#define memid(x) (0)
#endif
#ifndef VECTOR_8_ELEMENTS
#define VECTOR_8_ELEMENTS(x) {x, x, x, x, x, x, x, x}
#endif
#ifndef VECTOR_16_ELEMENTS
#define VECTOR_16_ELEMENTS(x) {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}
#endif
#ifndef VECTOR_32_ELEMENTS
#define VECTOR_32_ELEMENTS(x)                                                \
  {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x,   \
   x, x, x, x, x, x, x, x}
#endif
#ifndef VECTOR_64_ELEMENTS
#define VECTOR_64_ELEMENTS(x)                                                \
  {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x,   \
   x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x,   \
   x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}
#endif
#ifndef VECTOR_8x2_ELEMENTS
#define VECTOR_8x2_ELEMENTS(x, y)                                            \
  {x, y, x, y, x, y, x, y, x, y, x, y, x, y, x, y}
#endif
#ifndef MPU_SYNC
#define MPU_SYNC() do { __threadfence_block(); } while (0)
#endif

/* Aurora's extended scheduler state has no NVIDIA hardware equivalent. */
#define warpEntryIdx ((unsigned int)threadIdx.x)
#define warpGroupIdx ((unsigned int)blockIdx.x)
#define curCoreId ((unsigned int)threadIdx.x)
#define curWarpInfo ((void *)0)
#define curWorkGroupInfo ((void *)0)
#define callmArgsIdxPtr ((volatile unsigned *)0)
#define callmArgsBuffPtr ((void *)0)
#define printfBuffer ((char *)0)
#define dmaParalAddr 0u
#define scaleThreadId                                                      \
  ((int)(threadIdx.x + blockDim.x *                                       \
         (threadIdx.y + blockDim.y *                                      \
          (threadIdx.z + blockDim.z *                                     \
           (blockIdx.x + gridDim.x *                                      \
            (blockIdx.y + gridDim.y * blockIdx.z))))))
#define scaleAsId 0u
static __device__ __constant__ dim3 clusterDim = {1, 1, 1};

__device__ static inline void nvscale_syncthreads(void) { __syncthreads(); }
__device__ static inline void nvscale_syncthreads(bool wait_async) {
  if (wait_async) __threadfence_block();
  __syncthreads();
}
#define __syncthreads(...) nvscale_syncthreads(__VA_ARGS__)

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
  __host__ __device__ short &operator[](int i) { return lane[i]; }
  __host__ __device__ const short &operator[](int i) const { return lane[i]; }
};
struct __align__(64) v32u16 {
  unsigned short lane[32];
  __host__ __device__ unsigned short &operator[](int i) { return lane[i]; }
  __host__ __device__ const unsigned short &operator[](int i) const {
    return lane[i];
  }
};
struct __align__(64) v64s8 {
  signed char lane[64];
  __host__ __device__ signed char &operator[](int i) { return lane[i]; }
  __host__ __device__ const signed char &operator[](int i) const {
    return lane[i];
  }
};
struct __align__(64) v64u8 {
  unsigned char lane[64];
  __host__ __device__ unsigned char &operator[](int i) { return lane[i]; }
  __host__ __device__ const unsigned char &operator[](int i) const {
    return lane[i];
  }
};
struct __align__(64) v8s64 {
  long long lane[8];
  __host__ __device__ long long &operator[](int i) { return lane[i]; }
  __host__ __device__ const long long &operator[](int i) const {
    return lane[i];
  }
};
struct __align__(64) v8u64 {
  unsigned long long lane[8];
  __host__ __device__ unsigned long long &operator[](int i) { return lane[i]; }
  __host__ __device__ const unsigned long long &operator[](int i) const {
    return lane[i];
  }
};
struct __align__(32) v8s32 {
  int lane[8];
  __host__ __device__ int &operator[](int i) { return lane[i]; }
  __host__ __device__ const int &operator[](int i) const { return lane[i]; }
};
struct __align__(16) v4s32 {
  int lane[4];
  __host__ __device__ int &operator[](int i) { return lane[i]; }
  __host__ __device__ const int &operator[](int i) const { return lane[i]; }
};
struct __align__(128) v32s32 {
  int lane[32];
  __host__ __device__ int &operator[](int i) { return lane[i]; }
  __host__ __device__ const int &operator[](int i) const { return lane[i]; }
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

#define NVSC_DEFINE_VEC(name, type, count, align_bytes)                      \
  struct __align__(align_bytes) name {                                       \
    type lane[count];                                                        \
    __host__ __device__ type &operator[](int i) { return lane[i]; }          \
    __host__ __device__ const type &operator[](int i) const { return lane[i]; } \
  }

NVSC_DEFINE_VEC(v32u32, unsigned int, 32, 128);
NVSC_DEFINE_VEC(v64s16, short, 64, 128);
NVSC_DEFINE_VEC(v64u16, unsigned short, 64, 128);
NVSC_DEFINE_VEC(v32fp32, float, 32, 128);
NVSC_DEFINE_VEC(v16s64, long long, 16, 128);
NVSC_DEFINE_VEC(v16u64, unsigned long long, 16, 128);
NVSC_DEFINE_VEC(v16fp64, double, 16, 128);
NVSC_DEFINE_VEC(v4s64, long long, 4, 32);
NVSC_DEFINE_VEC(v4u64, unsigned long long, 4, 32);
NVSC_DEFINE_VEC(v4f64, double, 4, 32);
NVSC_DEFINE_VEC(v8u32, unsigned int, 8, 32);
NVSC_DEFINE_VEC(v8f32, float, 8, 32);
NVSC_DEFINE_VEC(v16s16, short, 16, 32);
NVSC_DEFINE_VEC(v16u16, unsigned short, 16, 32);
NVSC_DEFINE_VEC(v32s8, signed char, 32, 32);
NVSC_DEFINE_VEC(v32u8, unsigned char, 32, 32);
NVSC_DEFINE_VEC(v2s64, long long, 2, 16);
NVSC_DEFINE_VEC(v2u64, unsigned long long, 2, 16);
NVSC_DEFINE_VEC(v2f64, double, 2, 16);
NVSC_DEFINE_VEC(v4u32, unsigned int, 4, 16);
NVSC_DEFINE_VEC(v4f32, float, 4, 16);
NVSC_DEFINE_VEC(v8s16, short, 8, 16);
NVSC_DEFINE_VEC(v8u16, unsigned short, 8, 16);
NVSC_DEFINE_VEC(v16s8, signed char, 16, 16);
NVSC_DEFINE_VEC(v16u8, unsigned char, 16, 16);
NVSC_DEFINE_VEC(v64fp16, unsigned short, 64, 128);
NVSC_DEFINE_VEC(v32fp16, unsigned short, 32, 64);
NVSC_DEFINE_VEC(v32bf16, unsigned short, 32, 64);

#undef NVSC_DEFINE_VEC

typedef v16s32 v16i32;
typedef v32s16 v32i16;
typedef v64s8 v64i8;
typedef v16s32 v16ip32;
typedef v64i8 v64fp8e4;
typedef v64i8 v64fp8e5;
typedef float __tf32;
typedef v16s32 v16tf32;
typedef v16s32 anyv512ty;
typedef v4f64 v4fp64;
typedef v8f32 v8fp32;
typedef v2f64 v2fp64;
typedef v4f32 v4fp32;
typedef v16s32 vec512_t;
typedef v32s32 v32ip32;
typedef v32s32 anyv1024ty;

typedef unsigned char __fp8_storage_t;
typedef struct __fp8e4 {
  __fp8_storage_t val;
} __fp8e4;
typedef struct __fp8e5 {
  __fp8_storage_t val;
} __fp8e5;

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

template <typename T>
__device__ static inline T *addressof(unsigned, T *sym) { return sym; }
template <typename T>
__device__ static inline T *addressof(unsigned, T *sym, unsigned) {
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

__device__ static inline void *memcpy_ddr(void *dst, const void *src,
                                         uint64_t bytes) {
  return memcpy(dst, src, (size_t)bytes);
}
__device__ static inline void *memcpy_ddr2dm(void *dst, const void *src,
                                            uint64_t bytes) {
  return memcpy(dst, src, (size_t)bytes);
}
__device__ static inline void *memcpy_dm2ddr(void *dst, const void *src,
                                            uint64_t bytes) {
  return memcpy(dst, src, (size_t)bytes);
}
__device__ static inline void *memset_ddr(void *dst, int value,
                                         uint64_t bytes) {
  return memset(dst, value, (size_t)bytes);
}

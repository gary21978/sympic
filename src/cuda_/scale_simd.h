/* SCALE v8fp64 SIMD emulation for nvcc (real SCALE toolchain supplies v8fp64) */
#ifndef SCALE_SIMD_H
#define SCALE_SIMD_H

#ifndef V8FP64_EMULATED
#define V8FP64_EMULATED 1
struct v8fp64 {
  double v[8];
};
#endif

__device__ __forceinline__ v8fp64 vbroadcast(double s) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = s;
  }
  return r;
}

__device__ __forceinline__ v8fp64 operator+(const v8fp64 &a, const v8fp64 &b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = a.v[i] + b.v[i];
  }
  return r;
}

__device__ __forceinline__ v8fp64 operator-(const v8fp64 &a, const v8fp64 &b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = a.v[i] - b.v[i];
  }
  return r;
}

__device__ __forceinline__ v8fp64 operator*(const v8fp64 &a, const v8fp64 &b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = a.v[i] * b.v[i];
  }
  return r;
}

__device__ __forceinline__ v8fp64 operator/(const v8fp64 &a, const v8fp64 &b) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = a.v[i] / b.v[i];
  }
  return r;
}

__device__ __forceinline__ v8fp64 operator-(const v8fp64 &a) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = -a.v[i];
  }
  return r;
}

__device__ __forceinline__ v8fp64 operator+(const v8fp64 &a, double b) {
  return a + vbroadcast(b);
}
__device__ __forceinline__ v8fp64 operator+(double a, const v8fp64 &b) {
  return vbroadcast(a) + b;
}
__device__ __forceinline__ v8fp64 operator-(const v8fp64 &a, double b) {
  return a - vbroadcast(b);
}
__device__ __forceinline__ v8fp64 operator-(double a, const v8fp64 &b) {
  return vbroadcast(a) - b;
}
__device__ __forceinline__ v8fp64 operator*(const v8fp64 &a, double b) {
  return a * vbroadcast(b);
}
__device__ __forceinline__ v8fp64 operator*(double a, const v8fp64 &b) {
  return vbroadcast(a) * b;
}
__device__ __forceinline__ v8fp64 operator/(const v8fp64 &a, double b) {
  return a / vbroadcast(b);
}
__device__ __forceinline__ v8fp64 operator/(double a, const v8fp64 &b) {
  return vbroadcast(a) / b;
}

__device__ __forceinline__ v8fp64 geo_floor_simd(v8fp64 a) {
  v8fp64 r;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    r.v[i] = floor(a.v[i]);
  }
  return r;
}

__device__ __forceinline__ double vreduce_add(v8fp64 a) {
  double s = 0.0;
#pragma unroll
  for (int i = 0; i < 8; i++) {
    s += a.v[i];
  }
  return s;
}

#endif /* SCALE_SIMD_H */

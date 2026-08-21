# NVScale Compatibility Plugin

`nvscale` is a CUDA-backed compatibility layer for building SCALE/MAPS/Aurora
source files on NVIDIA GPUs when the internal SCALE compiler is unavailable.

This directory is intentionally project-neutral. It provides headers and CMake
helpers only; repository-specific build wiring should live outside this
directory.

## Contents

- `include/`: compatibility headers that map a subset of SCALE, MAPS, and
  Aurora APIs to CUDA/C++.
- `cmake/NVScale.cmake`: reusable CMake helpers for compiling SCALE-like source
  files as CUDA translation units.
- `bin/nvscale-nvcc`: optional `nvcc` wrapper that injects this include tree.

The headers are shim headers, not official SmartLogic SCALE headers. Each file
has a banner at the top so accidental inclusion is easy to identify. The
compatibility target is source-level functional validation, not Aurora timing,
memory-placement, or scheduling equivalence.

## Programming Guide Coverage

| SCALE surface | NVIDIA mapping |
|---|---|
| `__DDR`, `__ptr64`, `KERNEL_S`, `KERNEL_M` | CUDA address/function qualifiers collapse to CUDA's unified device model |
| `__mem0__`...`__mem4__`, `__fix*__`, `__acc__`, `__residency__` | Accepted for compilation; NVIDIA chooses physical storage/banks |
| `async_call`, `sync_call`, `async_enqueue`, `MPU_FUNC_PTR` | Direct CUDA device calls; queue and SPU/MPU overlap are not reproduced |
| `scale::barrier`, `memcpy_async`, `__syncthreads(true)` | Synchronous device copy plus CUDA block/thread fences |
| thread/block/grid cooperative groups | CUDA index and block synchronization semantics |
| cluster cooperative group | One-block fallback cluster; cross-block DSM is not emulated |
| MAPS allocation/copy/stream/event/symbol APIs | CUDA Runtime API |
| `v8fp64`, `v16fp32`, integer vector containers | 64-byte aligned lane structs with common arithmetic |

The shim intentionally exposes unsupported Aurora behavior as documented
fallbacks. Code whose correctness depends on C-mode concurrent threads,
specific DM banks, asynchronous MPU queues, or cluster distributed shared
memory still requires the real SCALE toolchain and Aurora hardware.

## CMake Usage

```cmake
list(APPEND CMAKE_MODULE_PATH "/path/to/nvscale/cmake")
include(NVScale)

nvscale_add_scale_library(my_scale_kernels
  SOURCES kernel_runtime.sc host_adapter.cpp
  INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
```

Set `NVSCALE_CUDA_ARCH` to a numeric architecture such as `75`, `86`, or `89`:

```sh
cmake -S . -B build -DNVSCALE_CUDA_ARCH=86
cmake --build build -j
```

## Wrapper Usage

```sh
nvscale/bin/nvscale-nvcc -arch=sm_86 -c kernel_runtime.sc -o kernel_runtime.o
```

The wrapper passes `-x cu`, relaxed constexpr, extended lambda support, and
`-I<nvscale>/include` to `nvcc`.

## Compatibility Test

The guide-surface smoke test compiles and runs representative language,
barrier, cooperative-group, vector, and MAPS symbol APIs:

```sh
bash nvscale/tests/run.sh
```

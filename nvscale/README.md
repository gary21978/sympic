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
has a banner at the top so accidental inclusion is easy to identify.

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

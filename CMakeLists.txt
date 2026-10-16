cmake_minimum_required(VERSION 3.18)

# ============================================================
# 0. 后端选择（必须在 project() 之前决定启用哪些语言）
# ============================================================
option(SYMPIC_CUDA "Use CUDA backend" OFF)
option(SYMPIC_MAPU "Use MAPU backend" OFF)
option(SYMPIC_NVSCALE "Build the MAPU backend through NVScale" OFF)
option(SYMPIC_MICROCODE "Use PushJ microcode for the MAPU backend" OFF)
set(SYMPIC_PUSHJ_WORKERS "4" CACHE STRING "PushJ SPU workers per block (1, 2 or 4)")
set_property(CACHE SYMPIC_PUSHJ_WORKERS PROPERTY STRINGS 1 2 4)
if(NOT SYMPIC_PUSHJ_WORKERS MATCHES "^(1|2|4)$")
    message(FATAL_ERROR "SYMPIC_PUSHJ_WORKERS must be 1, 2 or 4")
endif()
if(SYMPIC_MICROCODE AND NOT SYMPIC_MAPU)
    message(FATAL_ERROR "SYMPIC_MICROCODE requires SYMPIC_MAPU=ON")
endif()


set(SYMPIC_BACKEND_COUNT 0)
foreach(_backend SYMPIC_CUDA SYMPIC_MAPU SYMPIC_NVSCALE)
    if(${_backend})
        math(EXPR SYMPIC_BACKEND_COUNT "${SYMPIC_BACKEND_COUNT}+1")
    endif()
endforeach()
if(NOT SYMPIC_BACKEND_COUNT EQUAL 1)
    message(FATAL_ERROR "Select exactly one backend: SYMPIC_CUDA, SYMPIC_MAPU, or SYMPIC_NVSCALE")
endif()

if(SYMPIC_CUDA OR SYMPIC_NVSCALE)
    project(sympic LANGUAGES C CXX CUDA)
elseif(SYMPIC_MAPU)
    project(sympic LANGUAGES C CXX)
endif()

# 只有CUDA编译才使用compile_commands.json
if(SYMPIC_CUDA)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# 1. 全局输出目录设置
# ============================================================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ============================================================
# 2. 查找外部依赖包
# ============================================================
find_package(MPI REQUIRED)
if(SYMPIC_CUDA OR SYMPIC_NVSCALE)
    find_package(CUDAToolkit REQUIRED)
    find_library(NCCL_LIBRARY NAMES nccl REQUIRED)

    # ============================================================
    # 3. CUDA 相关选项与默认值
    # ============================================================
    option(CUDA_SOURCE_PROFILE "Enable nvcc -lineinfo for Nsight Compute source profiling" OFF)
    option(CUDA_PTXAS_VERBOSE  "Enable nvcc -Xptxas -v (print regs/stack/spills)" OFF)
    option(CUDA_DUMP_CUBIN     "Dump cubin for inner_split_pass.kernel.cu" OFF)
    set(CUDA_ARCH "sm_86" CACHE STRING "CUDA arch, e.g. sm_75, sm_86")
endif()

if(SYMPIC_NVSCALE)
    set(NVSCALE_ROOT "/home/cheney/Projects/MaPU/toolchain/nvscale" CACHE PATH "NVScale root")
    list(APPEND CMAKE_MODULE_PATH "${NVSCALE_ROOT}/cmake")
    include(NVScale)
elseif(SYMPIC_MAPU)

    # 填写scale编程需要的环境
    set(USE_SCALE_EXT_0001 ON)
    if(DEFINED ENV{TOOLCHAIN_DIR})
        set(SCALE_TOOLCHAIN_PATH $ENV{TOOLCHAIN_DIR})
    elseif(DEFINED ENV{SCALE_TOOLCHAIN_ROOT})
        message(STATUS "SCALE_TOOLCHAIN_ROOT is defined $ENV{SCALE_TOOLCHAIN_ROOT}")
        set(SCALE_TOOLCHAIN_PATH $ENV{SCALE_TOOLCHAIN_ROOT})
    elseif(DEFINED ENV{MAPU_ROOT})
        set(SCALE_TOOLCHAIN_PATH "$ENV{MAPU_ROOT}/toolchain")
    else()
        message(FATAL_ERROR "Scale toolchain is not set, please set ENV VAR \"TOOLCHAIN_DIR\", \"SCALE_TOOLCHAIN_ROOT\", or \"MAPU_ROOT\"")
    endif()

    # The scale cmake module path must be appended before enabling scale language
    set(SCALE_CMAKE_PATH ${SCALE_TOOLCHAIN_PATH}/cmake)
    if(NOT EXISTS ${SCALE_CMAKE_PATH})
        message(FATAL_ERROR "Scale cmake module path '${SCALE_CMAKE_PATH}' does not exist, please use toolchain version after 202507031905")
    endif()
    list(APPEND CMAKE_MODULE_PATH ${SCALE_CMAKE_PATH})
    set(SCALE_IGNORE_TOOLCHAIN_WARNING OFF)
    set(USE_MAPS_UMD ON)
    include(scale_config)
    enable_language(SCALE)

    set(MACCL_ROOT "$ENV{MACCL_ROOT}" CACHE PATH
        "MACCL installation prefix (must contain include/maccl.h and lib/libmaccl.so)")
    find_path(MACCL_INCLUDE_DIR maccl.h
        HINTS
            "${MACCL_ROOT}/include"
            "${SCALE_TOOLCHAIN_PATH}/include/maccl_include"
        REQUIRED)
    find_library(MACCL_LIBRARY NAMES maccl
        HINTS
            "${MACCL_ROOT}/lib"
            "${SCALE_TOOLCHAIN_PATH}/lib"
            "${SCALE_TOOLCHAIN_PATH}/../demo/build/lib"
        REQUIRED)
    find_path(MAPS_INCLUDE_DIR maps_runtime.h
        HINTS
            "${MACCL_ROOT}/include"
            "${MACCL_ROOT}/include/maps"
            "${SCALE_TOOLCHAIN_PATH}/../include"
            "${SCALE_TOOLCHAIN_PATH}/../include/maps"
            "${SCALE_TOOLCHAIN_PATH}/include/maps_include"
        REQUIRED)
    find_library(MAPS_LIBRARY NAMES maps
        HINTS
            "${MACCL_ROOT}/lib"
            "${SCALE_TOOLCHAIN_PATH}/../lib"
            "${SCALE_TOOLCHAIN_PATH}/lib"
            "${SCALE_TOOLCHAIN_PATH}/../maps-umd/lib"
        REQUIRED)
endif()

# ============================================================
# 4. 全局编译/链接标志
# ============================================================
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g -ffast-math -ffunction-sections")

if(SYMPIC_CUDA OR SYMPIC_NVSCALE)
    # 从 CUDA_ARCH 解析数值架构，例如 sm_86 -> 86
    if(CUDA_ARCH MATCHES "^sm_([0-9]+)$")
        set(CMAKE_CUDA_ARCHITECTURES ${CMAKE_MATCH_1})
    else()
        message(FATAL_ERROR "CUDA_ARCH must be like sm_75 or sm_86, got '${CUDA_ARCH}'")
    endif()

    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -O2")
    if(CUDA_SOURCE_PROFILE)
        set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -lineinfo")
    endif()
    if(CUDA_PTXAS_VERBOSE)
        set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xptxas -v")
    endif()
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")

# ============================================================
# 5. 后端宏与库名（传递给 src/CMakeLists.txt）
# ============================================================
if(SYMPIC_CUDA)
    add_compile_definitions(SYMPIC_CUDA)
    set(SYMPIC_BACKEND_LIB sympic_cuda_backend)
    set(SYMPIC_BACKEND_DIR cuda_)
else()
    # SYMPIC_MAPU 与 SYMPIC_NVSCALE 共用 mapu_ 源码：NVScale 在 CUDA 上验证
    # MaPU kernel（保持 MAPU 侧源码接口，提供 CUDA/NCCL 后端的 MAPS/MACCL shim）
    add_compile_definitions(SYMPIC_MAPU)
    set(SYMPIC_BACKEND_LIB sympic_mapu_backend)
    set(SYMPIC_BACKEND_DIR mapu_)
endif()

# ============================================================
# 6. 源码目录
# ============================================================
add_subdirectory(src)

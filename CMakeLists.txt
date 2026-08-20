cmake_minimum_required(VERSION 3.18)

# ============================================================
# 0. 后端选择（必须在 project() 之前决定启用哪些语言）
# ============================================================
option(SYMPIC_CUDA "Use CUDA backend" OFF)
option(SYMPIC_MAPU "Use MAPU backend" OFF)


if(NOT SYMPIC_CUDA AND NOT SYMPIC_MAPU)
    message(FATAL_ERROR "Please select one backend: -DSYMPIC_CUDA=ON or -DSYMPIC_MAPU=ON")
endif()
if(SYMPIC_CUDA AND SYMPIC_MAPU)
    message(FATAL_ERROR "SYMPIC_CUDA and SYMPIC_MAPU are mutually exclusive")
endif()

if(SYMPIC_CUDA)
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
if(SYMPIC_CUDA)
    find_package(CUDAToolkit REQUIRED)

    # ============================================================
    # 3. CUDA 相关选项与默认值
    # ============================================================
    option(CUDA_SOURCE_PROFILE "Enable nvcc -lineinfo for Nsight Compute source profiling" OFF)
    option(CUDA_PTXAS_VERBOSE  "Enable nvcc -Xptxas -v (print regs/stack/spills)" OFF)
    option(CUDA_DUMP_CUBIN     "Dump cubin for inner_split_pass.kernel.cu" OFF)
    set(CUDA_ARCH "sm_86" CACHE STRING "CUDA arch, e.g. sm_75, sm_86")
elseif(SYMPIC_MAPU)

    # 填写scale编程需要的环境
    set(USE_SCALE_EXT_0001 ON)
    if(DEFINED ENV{TOOLCHAIN_DIR})
    set(SCALE_TOOLCHAIN_PATH $ENV{TOOLCHAIN_DIR})
    elseif(DEFINED ENV{SCALE_TOOLCHAIN_ROOT})
        message("SCALE_TOOLCHAIN_ROOT is defined ${SCALE_TOOLCHAIN_ROOT}")
    set(SCALE_TOOLCHAIN_PATH $ENV{SCALE_TOOLCHAIN_ROOT})
    else()
        message(FATAL_ERROR "Scale toolchain is not set, please set ENV VAR \"TOOLCHAIN_DIR\" or \"SCALE_TOOLCHAIN_ROOT\" to the directory of \"toolchain\"")
    return()
    endif()

    # The scale cmake module path must be appended before enabling scale language
    set(SCALE_CMAKE_PATH ${SCALE_TOOLCHAIN_PATH}/cmake)
    if(NOT EXISTS ${SCALE_CMAKE_PATH})
        message(FATAL_ERROR "SCALE_CMAKE_PATH {SCALE_CMAKE_PATH} is not exists, please use toolchain version after 202507031905")
    endif()
    list(APPEND CMAKE_MODULE_PATH ${SCALE_CMAKE_PATH})
    set(SCALE_IGNORE_TOOLCHAIN_WARNING OFF)
    set(USE_MAPS_UMD ON)
    include(scale_config)
    enable_language(SCALE)
endif()

# ============================================================
# 4. 全局编译/链接标志
# ============================================================
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g -ffast-math -ffunction-sections")

if(SYMPIC_CUDA)
    # 从 CUDA_ARCH 解析数值架构，例如 sm_86 -> 86
    if(CUDA_ARCH MATCHES "^sm_([0-9]+)$")
        set(CMAKE_CUDA_ARCHITECTURES ${CMAKE_MATCH_1})
    else()
        message(FATAL_ERROR "CUDA_ARCH must be like sm_75 or sm_86, got '${CUDA_ARCH}'")
    endif()

    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -O3")
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
    set(SYMPIC_BACKEND_LIB cuda_yeefdtd)
    set(SYMPIC_BACKEND_DIR cuda_)
elseif(SYMPIC_MAPU)
    add_compile_definitions(SYMPIC_MAPU)
    set(SYMPIC_BACKEND_LIB mapu_yeefdtd)
    set(SYMPIC_BACKEND_DIR mapu_)
endif()

# ============================================================
# 6. 源码目录
# ============================================================
add_subdirectory(src)

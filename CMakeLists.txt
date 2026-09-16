cmake_minimum_required(VERSION 3.18)
project(sympic LANGUAGES C CUDA)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ============================================================
# 0. 全局输出目录设置
# ============================================================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ============================================================
# 1. 查找外部依赖包
# ============================================================
find_package(MPI REQUIRED)
find_package(CUDAToolkit REQUIRED)

# ============================================================
# 2. 选项与默认值（对应脚本中的环境变量/参数）
# ============================================================
option(CUDA_SOURCE_PROFILE "Enable nvcc -lineinfo for Nsight Compute source profiling" OFF)
option(CUDA_PTXAS_VERBOSE  "Enable nvcc -Xptxas -v (print regs/stack/spills)" OFF)
option(CUDA_DUMP_CUBIN     "Dump cubin for inner_split_pass.kernel.cu" OFF)
set(CUDA_ARCH "sm_86" CACHE STRING "CUDA arch, e.g. sm_75, sm_86")

# ============================================================
# 3. 全局编译/链接标志
# ============================================================
# 根目录 C 文件（主机代码）
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g -ffast-math -ffunction-sections")

# CUDA 文件
set(CMAKE_CUDA_ARCHITECTURES 86)
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -O3 --default-stream per-thread")
if(CUDA_SOURCE_PROFILE)
    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -lineinfo")
endif()
if(CUDA_PTXAS_VERBOSE)
    set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xptxas -v")
endif()

# 链接标志
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--gc-sections")
link_directories(/usr/local/cuda/lib64)

# ============================================================
# 4. 通用 include 目录
# ============================================================
include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/cgapsio
    ${CMAKE_SOURCE_DIR}/src/cscheme
    ${CMAKE_SOURCE_DIR}/src/cuda_
    /usr/local/cuda/include
)

# ============================================================
# 5. 子目录
# ============================================================
add_subdirectory(src/smallmpi)
add_subdirectory(src/cgapsio)
add_subdirectory(src/cscheme)
add_subdirectory(src/cuda_)

# ============================================================
# 6. 主机代码（根目录 .c 文件）
# ============================================================
set(HOST_SOURCES
    src/space_filling_curve.c
    src/init_adjoint_relation.c
    src/init_field3d_mpi.c
    src/genrand.c
    src/init_particle.c
    src/sort_particle.c
    src/run_particle.c
    src/run_particle_call_fun.c
    src/mpifields.c
    src/blas_shell.c
    src/sync_fields.c
    src/mpi_fieldio.c
    src/seqfields.c
    src/main.c
    src/cfgcst.c
)

add_executable(sympic ${HOST_SOURCES})
target_link_libraries(sympic PRIVATE
    cgapsio
    cscheme
    smallmpi
    cuda_yeefdtd
    CUDA::cudart
    CUDA::cuda_driver
    MPI::MPI_C
    /usr/lib/x86_64-linux-gnu/libnccl.so
)

# ============================================================
# 7. 头文件依赖（yeefdtd.h 需要先生成）
# ============================================================
add_dependencies(sympic cuda_yeefdtd_h)

# ============================================================
# 8. cubin dump 支持（对应 --dump-cubin）
# ============================================================
if(CUDA_DUMP_CUBIN)
    set(CUBIN_OUT ${CMAKE_BINARY_DIR}/inner_split_pass.kernel.${CUDA_ARCH}.cubin)
    add_custom_command(
        OUTPUT ${CUBIN_OUT}
        COMMAND nvcc -O3 -arch=${CUDA_ARCH} -lineinfo
                -I${CMAKE_SOURCE_DIR}/src -I/usr/local/cuda/include
                -cubin ${CMAKE_SOURCE_DIR}/src/cuda_/inner_split_pass.kernel.cu
                -o ${CUBIN_OUT}
        DEPENDS src/cuda_/inner_split_pass.kernel.cu
        COMMENT "Dumping cubin for inner_split_pass.kernel.cu"
    )
    add_custom_target(dump_cubin ALL DEPENDS ${CUBIN_OUT})
endif()

# ============================================================
# 9. install / clean 等辅助
# ============================================================
set_property(DIRECTORY PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
    "${CMAKE_BINARY_DIR}/cuda_yeefdtd.h"
    "${CMAKE_BINARY_DIR}/small_mpi_preproc.c"
)

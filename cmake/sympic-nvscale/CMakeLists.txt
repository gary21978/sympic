cmake_minimum_required(VERSION 3.22)
project(sympic_nvscale LANGUAGES C CXX CUDA)

get_filename_component(DEFAULT_SYMPIC_SOURCE_DIR
  "${CMAKE_CURRENT_LIST_DIR}/../.." ABSOLUTE)
set(SYMPIC_SOURCE_DIR "${DEFAULT_SYMPIC_SOURCE_DIR}" CACHE PATH
    "Path to the sympic-mapu source tree")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

option(SYMPIC_MAPU "Build MAPU sources through the NVScale compatibility layer" ON)
option(SYMPIC_CUDA "Reserved for the native CUDA backend; must stay OFF here" OFF)
if(NOT SYMPIC_MAPU)
  message(FATAL_ERROR "NVScale build requires -DSYMPIC_MAPU=ON")
endif()
if(SYMPIC_CUDA)
  message(FATAL_ERROR "NVScale build compiles MAPU sources; use -DSYMPIC_CUDA=OFF")
endif()

set(NVSCALE_CUDA_ARCH "86" CACHE STRING
    "Numeric CUDA architecture, for example 75, 86, or 89")
option(NVSCALE_USE_CUDA_CLUSTER
    "Preserve CUDA/Hopper __cluster_dims__ instead of compiling it away" OFF)

set(MAPU_ROOT "$ENV{MAPU_ROOT}" CACHE PATH
    "Shared MaPU root containing toolchain/nvscale")
if(MAPU_ROOT)
  set(DEFAULT_NVSCALE_ROOT "${MAPU_ROOT}/toolchain/nvscale")
else()
  set(DEFAULT_NVSCALE_ROOT "${SYMPIC_SOURCE_DIR}/nvscale")
endif()

set(NVSCALE_ROOT "${DEFAULT_NVSCALE_ROOT}" CACHE PATH
    "Shared NVScale compatibility layer")
if(NOT EXISTS "${NVSCALE_ROOT}/cmake/NVScale.cmake")
  message(FATAL_ERROR
    "NVScale compatibility layer not found: ${NVSCALE_ROOT}/cmake/NVScale.cmake. "
    "Set MAPU_ROOT or NVSCALE_ROOT.")
endif()

list(APPEND CMAKE_MODULE_PATH "${NVSCALE_ROOT}/cmake")
include(NVScale)

find_package(MPI REQUIRED)
find_library(NCCL_LIBRARY NAMES nccl REQUIRED)

set(SYMPIC_NVSCALE_COMPILE_DEFINITIONS
  SYMPIC_MAPU
  SYMPIC_USE_NCCL
)

include_directories(
  "${SYMPIC_SOURCE_DIR}/src"
  "${SYMPIC_SOURCE_DIR}/src/cgapsio"
  "${SYMPIC_SOURCE_DIR}/src/cscheme"
  "${SYMPIC_SOURCE_DIR}/src/mapu_"
)

add_subdirectory("${SYMPIC_SOURCE_DIR}/src/smallmpi" "${CMAKE_BINARY_DIR}/smallmpi")
add_subdirectory("${SYMPIC_SOURCE_DIR}/src/cgapsio" "${CMAKE_BINARY_DIR}/cgapsio")
add_subdirectory("${SYMPIC_SOURCE_DIR}/src/cscheme" "${CMAKE_BINARY_DIR}/cscheme")

file(GLOB MAPU_RUNTIME_SRC CONFIGURE_DEPENDS
  "${SYMPIC_SOURCE_DIR}/src/mapu_/*.kernel_runtime.sc")

nvscale_add_scale_library(mapu_yeefdtd
  SOURCES
    ${MAPU_RUNTIME_SRC}
    "${SYMPIC_SOURCE_DIR}/src/mapu_/mapu_pscmc.cpp"
)
target_compile_definitions(mapu_yeefdtd PUBLIC
  ${SYMPIC_NVSCALE_COMPILE_DEFINITIONS}
)

file(GLOB HOST_SOURCES CONFIGURE_DEPENDS "${SYMPIC_SOURCE_DIR}/src/*.c")
add_executable(sympic
  ${HOST_SOURCES}
)
target_compile_definitions(sympic PRIVATE
  ${SYMPIC_NVSCALE_COMPILE_DEFINITIONS}
)
target_link_libraries(sympic PRIVATE
  cgapsio
  cscheme
  smallmpi
  mapu_yeefdtd
  MPI::MPI_C
  CUDA::cudart
  CUDA::cuda_driver
  ${NCCL_LIBRARY}
)

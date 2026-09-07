cmake_minimum_required(VERSION 3.12)
project(blas)

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
  message(FATAL_ERROR "Fail to load SCALE_CMAKE_PATH {SCALE_CMAKE_PATH}, please use toolchain version after 202507031905")
endif()
list(APPEND CMAKE_MODULE_PATH ${SCALE_CMAKE_PATH})
set(SCALE_IGNORE_TOOLCHAIN_WARNING OFF)
set(USE_MAPS_UMD ON)
include(scale_config)

enable_language(CXX)
enable_language(SCALE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# SCALE source files
file(GLOB sc_sources "${CMAKE_CURRENT_SOURCE_DIR}/*.sc")
set(sc_sources ${sc_sources})

add_library(sc_objects OBJECT ${sc_sources})
target_compile_options(sc_objects PRIVATE
  "-I${CMAKE_CURRENT_SOURCE_DIR}"
  ${CMAKE_SCALE_COMPILE_FLAGS}
  "SHELL:-Xarch_host -fPIC -O2"
)

# Executable
add_executable(blas
	$<TARGET_OBJECTS:sc_objects>
)

# Link maps runtime library
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_SCALE_LINK_FLAGS}")

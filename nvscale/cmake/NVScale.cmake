include_guard(GLOBAL)

get_filename_component(NVSCALE_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." ABSOLUTE)

set(NVSCALE_CUDA_ARCH "86" CACHE STRING
    "Numeric CUDA architecture used by NVScale, for example 75, 86, or 89")

find_package(CUDAToolkit REQUIRED)

if(NOT CMAKE_CUDA_COMPILER)
  enable_language(CUDA)
endif()

set(CMAKE_CUDA_ARCHITECTURES "${NVSCALE_CUDA_ARCH}" CACHE STRING
    "CUDA architectures" FORCE)

macro(_nvscale_parse_args out_prefix)
  set(options)
  set(one_value_args)
  set(multi_value_args SOURCES INCLUDE_DIRS LIBRARIES COMPILE_DEFINITIONS COMPILE_OPTIONS)
  cmake_parse_arguments(${out_prefix}
    "${options}" "${one_value_args}" "${multi_value_args}" ${ARGN})
  if(NOT ${out_prefix}_SOURCES)
    message(FATAL_ERROR "NVScale target requires SOURCES")
  endif()
endmacro()

function(_nvscale_configure_target target)
  target_include_directories(${target} PUBLIC "${NVSCALE_ROOT}/include")
  target_compile_definitions(${target} PUBLIC __SCALE_ARCH__)
  target_compile_options(${target} PRIVATE
    $<$<COMPILE_LANGUAGE:CUDA>:-x cu --expt-relaxed-constexpr --extended-lambda -Wno-deprecated-gpu-targets>
  )
  target_link_libraries(${target} PUBLIC CUDA::cudart)
endfunction()

function(nvscale_mark_scale_sources)
  if(ARGC GREATER 0)
    set_source_files_properties(${ARGV} PROPERTIES LANGUAGE CUDA)
  endif()
endfunction()

function(nvscale_add_scale_library target)
  _nvscale_parse_args(NVS ${ARGN})
  nvscale_mark_scale_sources(${NVS_SOURCES})
  add_library(${target} ${NVS_SOURCES})
  _nvscale_configure_target(${target})
  if(NVS_INCLUDE_DIRS)
    target_include_directories(${target} PUBLIC ${NVS_INCLUDE_DIRS})
  endif()
  if(NVS_LIBRARIES)
    target_link_libraries(${target} PUBLIC ${NVS_LIBRARIES})
  endif()
  if(NVS_COMPILE_DEFINITIONS)
    target_compile_definitions(${target} PUBLIC ${NVS_COMPILE_DEFINITIONS})
  endif()
  if(NVS_COMPILE_OPTIONS)
    target_compile_options(${target} PRIVATE ${NVS_COMPILE_OPTIONS})
  endif()
endfunction()

function(nvscale_add_scale_executable target)
  _nvscale_parse_args(NVS ${ARGN})
  nvscale_mark_scale_sources(${NVS_SOURCES})
  add_executable(${target} ${NVS_SOURCES})
  _nvscale_configure_target(${target})
  if(NVS_INCLUDE_DIRS)
    target_include_directories(${target} PUBLIC ${NVS_INCLUDE_DIRS})
  endif()
  if(NVS_LIBRARIES)
    target_link_libraries(${target} PUBLIC ${NVS_LIBRARIES})
  endif()
  if(NVS_COMPILE_DEFINITIONS)
    target_compile_definitions(${target} PUBLIC ${NVS_COMPILE_DEFINITIONS})
  endif()
  if(NVS_COMPILE_OPTIONS)
    target_compile_options(${target} PRIVATE ${NVS_COMPILE_OPTIONS})
  endif()
endfunction()

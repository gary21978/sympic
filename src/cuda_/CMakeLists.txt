file(GLOB CUDA_RUNTIME_SRC *.kernel_runtime.cu)
set(CUDA_PSCMC_SRC cuda_pscmc.c)

add_library(cuda_yeefdtd STATIC
    ${CUDA_RUNTIME_SRC}
    ${CUDA_PSCMC_SRC}
    init_particle_gpu.cu
    local_halo_copy.cu
)
set_target_properties(cuda_yeefdtd PROPERTIES
    CUDA_SEPARABLE_COMPILATION OFF
    POSITION_INDEPENDENT_CODE ON
)

file(GLOB CUDA_HEADERS *.kernel_runtime.h)
list(APPEND CUDA_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/cuda_pscmc.h)
set(CUDA_YEEFDTD_H ${CMAKE_BINARY_DIR}/cuda_yeefdtd.h)
add_custom_command(
    OUTPUT ${CUDA_YEEFDTD_H}
    COMMAND cat ${CUDA_HEADERS} > ${CUDA_YEEFDTD_H}
    DEPENDS ${CUDA_HEADERS}
    COMMENT "Generating cuda_yeefdtd.h"
)
add_custom_target(cuda_yeefdtd_h DEPENDS ${CUDA_YEEFDTD_H})
add_dependencies(cuda_yeefdtd cuda_yeefdtd_h)

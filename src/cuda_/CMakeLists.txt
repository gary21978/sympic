file(GLOB CUDA_RUNTIME_SRC *.kernel_runtime.cu)
set(CUDA_PSCMC_SRC cuda_pscmc.c)

add_library(cuda_yeefdtd STATIC
    ${CUDA_RUNTIME_SRC}
    ${CUDA_PSCMC_SRC}
)
set_target_properties(cuda_yeefdtd PROPERTIES
    CUDA_SEPARABLE_COMPILATION OFF
    POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(cuda_yeefdtd PRIVATE CUDA::cudart)

# file(GLOB CUDA_HEADERS *.kernel_runtime.h)
# list(APPEND CUDA_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/cuda_pscmc.h)
# set(CUDA_YEEFDTD_H ${CMAKE_BINARY_DIR}/cuda_yeefdtd.h)
# add_custom_command(
#     OUTPUT ${CUDA_YEEFDTD_H}
#     COMMAND cat ${CUDA_HEADERS} > ${CUDA_YEEFDTD_H}
#     DEPENDS ${CUDA_HEADERS}
#     COMMENT "Generating cuda_yeefdtd.h"
# )
# add_custom_target(cuda_yeefdtd_h DEPENDS ${CUDA_YEEFDTD_H})
# add_dependencies(cuda_yeefdtd cuda_yeefdtd_h)

# ============================================================
# cubin dump 支持
# ============================================================
if(CUDA_DUMP_CUBIN)
    # 把 CUDA 头文件目录列表转换成 -I 参数串
    set(CUDA_INCLUDE_FLAGS "")
    foreach(_dir IN LISTS CUDA_TOOLKIT_INCLUDE_DIRECTORIES)
        string(APPEND CUDA_INCLUDE_FLAGS " -I${_dir}")
    endforeach()

    set(CUBIN_OUT ${CMAKE_BINARY_DIR}/inner_split_pass.kernel.${CUDA_ARCH}.cubin)
    add_custom_command(
        OUTPUT ${CUBIN_OUT}
        COMMAND nvcc -O3 -arch=${CUDA_ARCH} -lineinfo
                -I${CMAKE_CURRENT_SOURCE_DIR}
                -I${CMAKE_CURRENT_SOURCE_DIR}/..
                ${CUDA_INCLUDE_FLAGS}
                -cubin ${CMAKE_CURRENT_SOURCE_DIR}/inner_split_pass.kernel.cu
                -o ${CUBIN_OUT}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/inner_split_pass.kernel.cu
        COMMENT "Dumping cubin for inner_split_pass.kernel.cu"
    )
    add_custom_target(dump_cubin ALL DEPENDS ${CUBIN_OUT})
endif()

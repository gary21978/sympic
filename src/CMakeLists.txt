# ============================================================
# 4. 通用 include 目录
# ============================================================
include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/cgapsio
    ${CMAKE_CURRENT_SOURCE_DIR}/cscheme
    ${SYMPIC_BACKEND_DIR}
)

# ============================================================
# 5. 子目录
# ============================================================
add_subdirectory(smallmpi)
add_subdirectory(cgapsio)
add_subdirectory(cscheme)
add_subdirectory(${SYMPIC_BACKEND_DIR})

# ============================================================
# 6. 主机代码（src 目录 .c 文件）
# ============================================================
file(GLOB HOST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_executable(sympic ${HOST_SOURCES})

set(SYMPIC_LINK_LIBS
    cgapsio
    cscheme
    smallmpi
    ${SYMPIC_BACKEND_LIB}
    MPI::MPI_C
)
if(SYMPIC_CUDA OR SYMPIC_NVSCALE)
    list(APPEND SYMPIC_LINK_LIBS CUDA::cudart CUDA::cuda_driver ${NCCL_LIBRARY})
    if(SYMPIC_NVSCALE)
        # nvscale builds compile with SYMPIC_MAPU, so the comm layer resolves
        # to maccl; the toolchain ships libmaccl in <NVSCALE_ROOT>/../lib
        find_library(MACCL_LIBRARY NAMES maccl
            HINTS "${NVSCALE_ROOT}/../lib" "${NVSCALE_ROOT}/lib"
            REQUIRED)
        list(APPEND SYMPIC_LINK_LIBS ${MACCL_LIBRARY})
    endif()
elseif(SYMPIC_MAPU)
    target_include_directories(sympic PRIVATE
        ${SCALE_TOOLCHAIN_PATH}/../maps-umd/include
        ${SCALE_TOOLCHAIN_PATH}/include/maps_include
        ${MACCL_INCLUDE_DIR}
    )

    list(APPEND SYMPIC_LINK_LIBS
        ${SCALE_TOOLCHAIN_PATH}/lib/scale/release/libscalehost.so
        ${SCALE_TOOLCHAIN_PATH}/../maps-umd/lib/libmaps.so
        ${MACCL_LIBRARY}
    )


endif()

target_link_libraries(sympic PRIVATE ${SYMPIC_LINK_LIBS})


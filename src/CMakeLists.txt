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

set(CMAKE_EXECUTABLE_SUFFIX ".out")
add_executable(sympic ${HOST_SOURCES})

set(SYMPIC_LINK_LIBS
    cgapsio
    cscheme
    smallmpi
    ${SYMPIC_BACKEND_LIB}
    MPI::MPI_C
)
if(SYMPIC_CUDA)
    list(APPEND SYMPIC_LINK_LIBS CUDA::cudart CUDA::cuda_driver)
endif()

target_link_libraries(sympic PRIVATE ${SYMPIC_LINK_LIBS})





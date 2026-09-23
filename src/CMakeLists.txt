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
file(GLOB HOST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

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
elseif(SYMPIC_MAPU)
    target_include_directories(sympic PRIVATE
        ${MAPS_INCLUDE_DIR}
        ${MACCL_INCLUDE_DIR}
    )

    # maps-umd 头文件在 C 编译单元里直接用 bool，需要 stdbool.h
    target_compile_options(sympic PRIVATE -include stdbool.h)
    # maps_runtime_api.h 以 C++ 语义在头文件里定义 const 全局变量
    # （C 里是外部链接，每个编译单元一份 → 重定义）。这些是值恒定的
    # 常量，链接侧放行是安全的；上游修复应在头文件加 static。
    target_link_options(sympic PRIVATE -Wl,--allow-multiple-definition)

    # libscalehost 依赖 scale_comgr，其 LLVM/lld 动态库不在 DT_NEEDED 链里，
    # 由最终链接显式闭合（工具链把 LLVM 部署为 llvm_dynamic 下的动态库）
    file(GLOB MAPU_LLVM_LIBS "${SCALE_TOOLCHAIN_PATH}/lib/aurora/release/llvm_dynamic/*.so")
    list(APPEND SYMPIC_LINK_LIBS
        ${SCALE_TOOLCHAIN_PATH}/lib/scale/release/libscalehost.so
        ${MAPS_LIBRARY}
        ${MACCL_LIBRARY}
        ${MAPU_LLVM_LIBS}
    )

    target_link_options(sympic PRIVATE
        -Wl,-rpath-link,${SCALE_TOOLCHAIN_PATH}/lib/system
    )


endif()

target_link_libraries(sympic PRIVATE ${SYMPIC_LINK_LIBS})




add_library(mapu_pscmc SHARED mapu_pscmc.cpp)

target_include_directories(mapu_pscmc PRIVATE 
  ${SCALE_TOOLCHAIN_PATH}/../maps-umd/include
)

target_link_libraries(mapu_pscmc PRIVATE
  ${SCALE_TOOLCHAIN_PATH}/lib/scale/release/libscalehost.so
  ${SCALE_TOOLCHAIN_PATH}/../maps-umd/lib/libmaps.so
)


file(GLOB MAPU_RUNTIME_SRC *.kernel_runtime.sc)
add_library(mapu_yeefdtd SHARED
    ${MAPU_RUNTIME_SRC}
)

target_link_libraries(mapu_yeefdtd PUBLIC mapu_pscmc)

target_compile_options(mapu_yeefdtd PRIVATE
	${CMAKE_SCALE_COMPILE_FLAGS}
	-fPIC
    "-w"
    )

set_target_properties(mapu_yeefdtd PROPERTIES LINKER_LANGUAGE "SCALE")

target_link_options(mapu_yeefdtd PRIVATE
	--scale-link
	-L${CMAKE_CURRENT_SOURCE_DIR}
	-L${LIBSTDCPP_PATH}
	-L${HOST_DEFAULT_KERNEL_LIB_PATH}
	)


# file(GLOB MAPU_HEADERS *.kernel_runtime.h)
# list(APPEND MAPU_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/mapu_pscmc.h)
# set(MAPU_YEEFDTD_H ${CMAKE_BINARY_DIR}/mapu_yeefdtd.h)
# add_custom_command(
#     OUTPUT ${MAPU_YEEFDTD_H}
#     COMMAND cat ${MAPU_HEADERS} > ${MAPU_YEEFDTD_H}
#     DEPENDS ${MAPU_HEADERS}
#     COMMENT "Generating mapu_yeefdtd.h"
# )
# add_custom_target(mapu_yeefdtd_h DEPENDS ${MAPU_YEEFDTD_H})
# add_dependencies(mapu_yeefdtd mapu_yeefdtd_h)
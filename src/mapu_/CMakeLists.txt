

add_library(mapu_pscmc STATIC mapu_pscmc.cpp)

if(SYMPIC_NVSCALE)
  target_include_directories(mapu_pscmc PRIVATE "${NVSCALE_ROOT}/include")
  target_compile_definitions(mapu_pscmc PRIVATE __SCALE_ARCH__)
  target_link_libraries(mapu_pscmc PRIVATE CUDA::cudart)
else()
  target_include_directories(mapu_pscmc PRIVATE ${MAPS_INCLUDE_DIR})
  target_compile_options(mapu_pscmc PRIVATE -fPIC)
  target_link_libraries(mapu_pscmc PRIVATE
    ${SCALE_TOOLCHAIN_PATH}/lib/aurora/release/libscalehost.so
    ${MAPS_LIBRARY}
  )
endif()

file(GLOB MAPU_RUNTIME_SRC CONFIGURE_DEPENDS *.kernel_runtime.sc)
if(SYMPIC_NVSCALE)
  nvscale_add_scale_library(mapu_yeefdtd
    SOURCES ${MAPU_RUNTIME_SRC}
    INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/.."
    LIBRARIES mapu_pscmc
    COMPILE_OPTIONS -Xcompiler=-fPIC -w -O2
  )
else()
  add_library(mapu_yeefdtd SHARED ${MAPU_RUNTIME_SRC})

target_link_libraries(mapu_yeefdtd PUBLIC
	mapu_pscmc
)

set_target_properties(mapu_yeefdtd PROPERTIES LINKER_LANGUAGE "SCALE")
target_link_options(mapu_yeefdtd PRIVATE --scale-link -L${SCALE_TOOLCHAIN_PATH}/lib)


target_compile_options(mapu_yeefdtd PRIVATE
	-fPIC
  -w
	-fscale-spu-masight
	-fscale-mpu-masight
	-O2
)
endif()



add_library(mapu_pscmc STATIC mapu_pscmc.cpp)

if(SYMPIC_NVSCALE)
  target_include_directories(mapu_pscmc PRIVATE "${NVSCALE_ROOT}/include")
  target_compile_definitions(mapu_pscmc PRIVATE __SCALE_ARCH__)
  target_link_libraries(mapu_pscmc PRIVATE CUDA::cudart)
else()
  target_include_directories(mapu_pscmc PRIVATE ${SCALE_TOOLCHAIN_PATH}/../include)
  target_link_libraries(mapu_pscmc PRIVATE
    ${SCALE_TOOLCHAIN_PATH}/lib/scale/release/libscalehost.so
    ${SCALE_TOOLCHAIN_PATH}/../lib/libmaps.so
  )
endif()

# add_library(sortModule OBJECT general_partial_sort.kernel_runtime.sc)
# add_library(yeefdtdModule OBJECT geo_yeefdtd.kernel_runtime.sc)
# add_library(splitPassModule OBJECT inner_split_pass.kernel_runtime.sc)
# add_library(mergeModule OBJECT mergefields.kernel_runtime.sc)
# add_library(miniblasModule OBJECT miniblas.kernel_runtime.sc)
# add_library(moveBackModule OBJECT move_back.kernel_runtime.sc)
# add_library(particle OBJECT particle_iter.kernel_runtime.sc)

# foreach(module sortModule yeefdtdModule splitPassModule mergeModule miniblasModule moveBackModule particle)
# 	target_compile_options(${module} PRIVATE
# 		-fPIC
#     	-w
# 		-fscale-spu-masight
# 		-fscale-mpu-masight
# 	)
# endforeach()

# add_library(mapu_yeefdtd SHARED
# 	$<TARGET_OBJECTS:sortModule>
# 	$<TARGET_OBJECTS:yeefdtdModule>
# 	$<TARGET_OBJECTS:splitPassModule>
# 	$<TARGET_OBJECTS:mergeModule>
# 	$<TARGET_OBJECTS:miniblasModule>
# 	$<TARGET_OBJECTS:moveBackModule>
# 	$<TARGET_OBJECTS:particle>
# )

# # masight options---------------------------------------------------------------------------#

# target_compile_options(yeefdtdModule PRIVATE
# 	-fscale-spu-masight
# 	-fscale-mpu-masight
# )

# #-------------------------------------------------------------------------------------------#

# target_link_libraries(mapu_yeefdtd PUBLIC
# 	mapu_pscmc
# 	${SCALE_TOOLCHAIN_PATH}/../lib/libmasight_core.a
# )

file(GLOB MAPU_RUNTIME_SRC *.kernel_runtime.sc)
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
	${SCALE_TOOLCHAIN_PATH}/../lib/libmasight_core.a
)

set_target_properties(mapu_yeefdtd PROPERTIES LINKER_LANGUAGE "SCALE")
target_link_options(mapu_yeefdtd PRIVATE --scale-link)


target_compile_options(mapu_yeefdtd PRIVATE
	-fPIC
  -w
	-fscale-spu-masight
	-fscale-mpu-masight
	-O2
)
endif()



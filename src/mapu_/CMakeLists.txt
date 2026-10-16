

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
  nvscale_add_scale_library(sympic_mapu_backend
    SOURCES ${MAPU_RUNTIME_SRC}
    INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/.."
    LIBRARIES mapu_pscmc
    COMPILE_OPTIONS -Xcompiler=-fPIC -w -O2
  )
else()
  add_library(sympic_mapu_backend OBJECT ${MAPU_RUNTIME_SRC})

target_link_libraries(sympic_mapu_backend PUBLIC
	mapu_pscmc
)

set_target_properties(sympic_mapu_backend PROPERTIES LINKER_LANGUAGE "SCALE")
target_link_options(sympic_mapu_backend PRIVATE --scale-link -L${SCALE_TOOLCHAIN_PATH}/lib)


target_compile_options(sympic_mapu_backend PRIVATE
	-fPIC
  -w
	-O2
)
endif()


# Optional frozen PushJ path; default remains the portable C++/SCALE baseline.
if(SYMPIC_MICROCODE)
  find_package(Python3 REQUIRED COMPONENTS Interpreter)
  execute_process(
    COMMAND "${Python3_EXECUTABLE}" "${CMAKE_SOURCE_DIR}/scripts/pushj_mpu_launcher.py"
            --verify-source-tree "${CMAKE_SOURCE_DIR}"
    RESULT_VARIABLE _pushj_verify_status OUTPUT_VARIABLE _pushj_verify_out ERROR_VARIABLE _pushj_verify_err)
  if(NOT _pushj_verify_status EQUAL 0)
    message(FATAL_ERROR "Frozen PushJ source verification failed: ${_pushj_verify_out}${_pushj_verify_err}")
  endif()
  set_property(SOURCE inner_split_pass.kernel_runtime.sc APPEND PROPERTY
    COMPILE_DEFINITIONS MICROCODE=1 SYMPIC_PUSHJ_WORKERS=${SYMPIC_PUSHJ_WORKERS})
  target_compile_options(sympic_mapu_backend PRIVATE
    -fno-scale-spu-masight -fno-scale-mpu-masight)
  file(GLOB PUSHJ_ASSEMBLY CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/pushj_frozen/*.m.asm")
  set_property(SOURCE inner_split_pass.kernel_runtime.sc APPEND PROPERTY OBJECT_DEPENDS
    "${PUSHJ_ASSEMBLY};${CMAKE_CURRENT_SOURCE_DIR}/pushj_frozen/freeze.json;${CMAKE_SOURCE_DIR}/scripts/pushj_mpu_launcher.py;${CMAKE_SOURCE_DIR}/scripts/pushj_asm.py")
  set_property(TARGET sympic_mapu_backend PROPERTY RULE_LAUNCH_COMPILE
    "\"${Python3_EXECUTABLE}\" \"${CMAKE_SOURCE_DIR}/scripts/pushj_mpu_launcher.py\" --")
endif()

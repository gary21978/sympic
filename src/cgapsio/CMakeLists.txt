add_library(cgapsio STATIC cgapsio.c)
target_compile_definitions(cgapsio PRIVATE cgapsio_MAIN_PROC)
target_compile_options(cgapsio PRIVATE -O2 -fPIC -std=c89 -UNDEBUG)
target_link_libraries(cgapsio PRIVATE MPI::MPI_C)

add_executable(gapsio2to0 main2.c)
target_link_libraries(gapsio2to0 PRIVATE cgapsio MPI::MPI_C)

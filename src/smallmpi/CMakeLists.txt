add_library(smallmpi STATIC small_mpi.c)
set_target_properties(smallmpi PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(smallmpi PRIVATE MPI::MPI_C)

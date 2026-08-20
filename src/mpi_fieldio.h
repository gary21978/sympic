#include "pubdefs.h"

int init_parallel_file_for_mpi_fields(Field3D_MPI *pthis, Gaps_IO_DataFile *gid, char *pName, int64_t time_step,
                                      int version, int num_reduce_proc);
int write_parallel_file_for_mpi_fields(Field3D_MPI *pthis, Gaps_IO_DataFile *gid, int64_t timestep);
int mpi_field_write_to_file(Field3D_MPI *pthis, Gaps_IO_DataFile *pgid, long num_timestep);

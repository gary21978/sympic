#include <stdio.h>
#include "smallmpi/small_mpi.h"

int PS_MPI_Barrier(PS_MPI_Comm comm) {
  return MPI_Barrier(comm);
}

int PS_MPI_Bcast(void *buffer, int count, PS_MPI_Datatype datatype, int root, PS_MPI_Comm comm) {
  return MPI_Bcast(buffer, count, datatype, root, comm);
}

int PS_MPI_Comm_rank(PS_MPI_Comm comm, int *rank) {
  return MPI_Comm_rank(comm, rank);
}

int PS_MPI_Comm_size(PS_MPI_Comm comm, int *size) {
  return MPI_Comm_size(comm, size);
}

int PS_MPI_Finalize(void) {
  return MPI_Finalize();
}

int PS_MPI_Init(int *argc, char ***argv) {
  return MPI_Init(argc, argv);
}

int PS_MPI_Send(void *buf, int count, PS_MPI_Datatype datatype, int dest, int tag, PS_MPI_Comm comm) {
  return MPI_Send(buf, count, datatype, dest, tag, comm);
}

int PS_MPI_Recv(void *buf, int count, PS_MPI_Datatype datatype, int source, int tag, PS_MPI_Comm comm,
                PS_MPI_Status *status) {
  PS_MPI_Status s0;
  if (!status) {
    status = &s0;
  }
  return MPI_Recv(buf, count, datatype, source, tag, comm, status);
}

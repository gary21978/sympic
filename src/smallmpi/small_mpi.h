#ifndef SMALL_MPI_H
#define SMALL_MPI_H

#include <mpi.h>

#define PS_MPI_CHAR       MPI_CHAR
#define PS_MPI_INT        MPI_INT
#define PS_MPI_DOUBLE     MPI_DOUBLE
#define PS_MPI_FLOAT      MPI_FLOAT
#define PS_MPI_LONG       MPI_LONG
#define PS_MPI_LONG_LONG  MPI_LONG_LONG
#define PS_MPI_COMM_WORLD MPI_COMM_WORLD

typedef MPI_Comm     PS_MPI_Comm;
typedef MPI_Datatype PS_MPI_Datatype;
typedef MPI_Request  PS_MPI_Request;
typedef MPI_Status   PS_MPI_Status;
typedef MPI_Op       PS_MPI_Op;

int PS_MPI_Abort(PS_MPI_Comm comm, int errorcode);
int PS_MPI_Barrier(PS_MPI_Comm comm);
int PS_MPI_Bcast(void *buffer, int count, PS_MPI_Datatype datatype, int root,
                 PS_MPI_Comm comm);
int PS_MPI_Comm_rank(PS_MPI_Comm comm, int *rank);
int PS_MPI_Comm_size(PS_MPI_Comm comm, int *size);
int PS_MPI_Finalize(void);
int PS_MPI_Gather(void *sendbuf, int sendcount, PS_MPI_Datatype sendtype,
                  void *recvbuf, int recvcount, PS_MPI_Datatype recvtype, int root,
                  PS_MPI_Comm comm);
int PS_MPI_Get_processor_name(char *name, int *resultlen);
int PS_MPI_Init(int *argc, char ***argv);
int PS_MPI_Send(void *buf, int count, PS_MPI_Datatype datatype, int dest, int tag,
                PS_MPI_Comm comm);
int PS_MPI_Isend(void *buf, int count, PS_MPI_Datatype datatype, int dest, int tag,
                 PS_MPI_Comm comm, PS_MPI_Request *request);
int PS_MPI_Recv(void *buf, int count, PS_MPI_Datatype datatype, int source,
                int tag, PS_MPI_Comm comm, PS_MPI_Status *status);
int PS_MPI_Reduce(void *buf, void *recvbuf, int count, PS_MPI_Datatype datatype,
                  PS_MPI_Op op, int root, PS_MPI_Comm comm);
int PS_MPI_Sendrecv(void *sendbuf, int sendcount, PS_MPI_Datatype sendtype,
                    int dest, int sendtag, void *recvbuf, int recvcount,
                    PS_MPI_Datatype recvtype, int source, int recvtag,
                    PS_MPI_Comm comm, PS_MPI_Status *status);
int PS_MPI_Wait(PS_MPI_Request *request, PS_MPI_Status *status);

#endif /* SMALL_MPI_H */

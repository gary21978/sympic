#ifndef MPI_REL_H
#define MPI_REL_H
#include <mpi.h>
#include "basic.h"

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

typedef struct {
  Field3D_Seq *data;
  long num_runtime;
  PS_MPI_Comm comm;
  long cur_rank;
  long num_mpi_process;
  long sync_layer_len[NUM_SYNC_LAYER];
  PS_MPI_Request **rqst;
  //One_Particle_Collection *particles;
  int num_spec;
  double damp_vars;
} Field3D_MPI;

#endif

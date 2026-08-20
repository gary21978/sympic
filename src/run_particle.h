#include "pubdefs.h"

int cuda_dump_ene_num(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double Deltat);
int dump_ene_num_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double dt);
int dump_ene_num_mpi(Particle_in_Cell_MPI *pthis, double dt0);

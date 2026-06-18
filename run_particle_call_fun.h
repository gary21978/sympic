#include "pubdefs.h"

int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(One_Particle_Collection *pthis, Field3D_Seq *fieldE,
                                                         Field3D_Seq *fieldB, Field3D_Seq *fieldB1, Field3D_Seq *FoutJ,
                                                         double Mass0_lst_fix, double Charge0_lst_fix, double Deltat,
                                                         double Tori_X0, double r0, double MIN_R0, double Q0, double b0,
                                                         double zmid, int SPEC, int NUM_SPEC);
int One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(One_Particle_Collection *pthis, Field3D_Seq *fieldE,
                                                    Field3D_Seq *fieldB, Field3D_Seq *fieldB1, Field3D_Seq *FoutJ,
                                                    double Mass0_lst_fix, double Charge0_lst_fix, double Deltat,
                                                    double Tori_X0, double r0, double MIN_R0, double Q0, double b0,
                                                    double zmid, int spec, int num_spec);
int MPI_geo_nr_Bfield_pushJ_vlo(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                Field3D_MPI *fieldB1, Field3D_MPI *FoutJ, double *Mass0, double *Charge0, double Deltat,
                                double Tori_X0, double r0, double MIN_R0, double Q0, double b0, double zmid);

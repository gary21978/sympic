#include "pubdefs.h"

void init_Field3D_MPI_from_new_num_ele(Field3D_MPI *pthis, Field3D_MPI *f, int new_num_ele);
void init_Field3D_MPI_from(Field3D_MPI *pthis, Field3D_MPI *f);
void reinit_Field3D_MPI(Field3D_MPI *pthis, int new_num_ele);
int init_Field3D_MPI_ALL(Field3D_MPI *pthis, Field3D_Seq *sample_field, long n_hilbert, int ndim, int adjoint_type,
                         long *tids, int64_t *local_tid_array, int *cd_types, int *dev_nums, int *cd_performances,
                         long num_runtime, PS_MPI_Comm comm, long cur_rank, long num_mpi_process);
void init_external_field3d_E_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                            double r_z_rat, double random_rate);
void init_external_field3d_E_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                       double r_z_rat);
void init_external_field3d_B_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                            double r_z_rat, double random_rate);
void init_external_field3d_B_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                       double r_z_rat);
void init_external_field3d_E0_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                             double r_z_rat, double random_rate);
void init_external_field3d_B0_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                             double r_z_rat, double random_rate);
void init_external_field3d_FILTER_E_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                                   double r_z_rat, double random_rate);
void init_external_field3d_FILTER_E_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                              double r_z_rat);
void init_external_field3d_FILTER_E(Field3D_MPI *pthis);
void init_external_field3d_FILTER_B_2d_extend_rand(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                                   double r_z_rat, double random_rate);
void init_external_field3d_FILTER_B_2d_extend(Field3D_MPI *pthis, int reduce_dim, double r_x_rat, double r_y_rat,
                                              double r_z_rat);
void init_external_field3d_FILTER_B(Field3D_MPI *pthis);
int test_set_mainland(Field3D_MPI *pthis, double val);

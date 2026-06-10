#include "pubdefs.h"

int c_split_pass_x(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                   double Deltat);
int openmp_split_pass_x(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                        double Deltat);
int cuda_split_pass_x(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                      double Deltat);
int split_pass_x_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                     double dt);
int split_pass_x_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_abs_charge(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_split_pass_x_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_split_pass_x_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int split_pass_x_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int split_pass_x_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                   double Deltat);
int openmp_split_pass_y(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                        double Deltat);
int cuda_split_pass_y(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                      double Deltat);
int split_pass_y_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                     double dt);
int split_pass_y_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_abs_charge(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_split_pass_y_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_split_pass_y_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int split_pass_y_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int split_pass_y_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                   double Deltat);
int openmp_split_pass_z(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                        double Deltat);
int cuda_split_pass_z(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                      double Deltat);
int split_pass_z_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                     double dt);
int split_pass_z_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_abs_charge(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_split_pass_z_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_split_pass_z_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int split_pass_z_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int split_pass_z_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_vlo(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                       double Deltat);
int openmp_split_pass_x_vlo(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double Deltat);
int cuda_split_pass_x_vlo(One_Particle_Collection *pthis, int SPEC,
                          int NUM_SPEC, double Deltat);
int split_pass_x_vlo_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                         double dt);
int split_pass_x_vlo_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int openmp_split_pass_x_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int cuda_split_pass_x_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int split_pass_x_vlo_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double dt);
int split_pass_x_vlo_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_vlo(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                       double Deltat);
int openmp_split_pass_y_vlo(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double Deltat);
int cuda_split_pass_y_vlo(One_Particle_Collection *pthis, int SPEC,
                          int NUM_SPEC, double Deltat);
int split_pass_y_vlo_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                         double dt);
int split_pass_y_vlo_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int openmp_split_pass_y_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int cuda_split_pass_y_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int split_pass_y_vlo_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double dt);
int split_pass_y_vlo_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_vlo(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                       double Deltat);
int openmp_split_pass_z_vlo(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double Deltat);
int cuda_split_pass_z_vlo(One_Particle_Collection *pthis, int SPEC,
                          int NUM_SPEC, double Deltat);
int split_pass_z_vlo_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                         double dt);
int split_pass_z_vlo_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int openmp_split_pass_z_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int cuda_split_pass_z_vlo_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int split_pass_z_vlo_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double dt);
int split_pass_z_vlo_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_nopush(One_Particle_Collection *pthis, int SPEC,
                          int NUM_SPEC, double Deltat);
int openmp_split_pass_x_nopush(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int cuda_split_pass_x_nopush(One_Particle_Collection *pthis, int SPEC,
                             int NUM_SPEC, double Deltat);
int split_pass_x_nopush_all(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double dt);
int split_pass_x_nopush_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_nopush_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int openmp_split_pass_x_nopush_abs_charge(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int cuda_split_pass_x_nopush_abs_charge(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int split_pass_x_nopush_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double dt);
int split_pass_x_nopush_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_nopush(One_Particle_Collection *pthis, int SPEC,
                          int NUM_SPEC, double Deltat);
int openmp_split_pass_y_nopush(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int cuda_split_pass_y_nopush(One_Particle_Collection *pthis, int SPEC,
                             int NUM_SPEC, double Deltat);
int split_pass_y_nopush_all(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double dt);
int split_pass_y_nopush_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_nopush_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int openmp_split_pass_y_nopush_abs_charge(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int cuda_split_pass_y_nopush_abs_charge(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int split_pass_y_nopush_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double dt);
int split_pass_y_nopush_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_nopush(One_Particle_Collection *pthis, int SPEC,
                          int NUM_SPEC, double Deltat);
int openmp_split_pass_z_nopush(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int cuda_split_pass_z_nopush(One_Particle_Collection *pthis, int SPEC,
                             int NUM_SPEC, double Deltat);
int split_pass_z_nopush_all(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double dt);
int split_pass_z_nopush_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_nopush_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int openmp_split_pass_z_nopush_abs_charge(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int cuda_split_pass_z_nopush_abs_charge(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int split_pass_z_nopush_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double dt);
int split_pass_z_nopush_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_split_pass_x_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_split_pass_x_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int split_pass_x_vlo_nopush_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int split_pass_x_vlo_nopush_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double Deltat);
int openmp_split_pass_x_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int cuda_split_pass_x_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int split_pass_x_vlo_nopush_abs_charge_all(One_Particle_Collection *pthis,
                                           int SPEC, int NUM_SPEC, double dt);
int split_pass_x_vlo_nopush_abs_charge_mpi(Particle_in_Cell_MPI *pthis,
                                           double dt0);
int c_split_pass_y_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_split_pass_y_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_split_pass_y_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int split_pass_y_vlo_nopush_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int split_pass_y_vlo_nopush_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double Deltat);
int openmp_split_pass_y_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int cuda_split_pass_y_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int split_pass_y_vlo_nopush_abs_charge_all(One_Particle_Collection *pthis,
                                           int SPEC, int NUM_SPEC, double dt);
int split_pass_y_vlo_nopush_abs_charge_mpi(Particle_in_Cell_MPI *pthis,
                                           double dt0);
int c_split_pass_z_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_split_pass_z_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_split_pass_z_vlo_nopush(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int split_pass_z_vlo_nopush_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int split_pass_z_vlo_nopush_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double Deltat);
int openmp_split_pass_z_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int cuda_split_pass_z_vlo_nopush_abs_charge(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int split_pass_z_vlo_nopush_abs_charge_all(One_Particle_Collection *pthis,
                                           int SPEC, int NUM_SPEC, double dt);
int split_pass_z_vlo_nopush_abs_charge_mpi(Particle_in_Cell_MPI *pthis,
                                           double dt0);
int c_split_pass_E_particle_vlo(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double Deltat);
int openmp_split_pass_E_particle_vlo(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double Deltat);
int cuda_split_pass_E_particle_vlo(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int split_pass_E_particle_vlo_all(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double dt);
int split_pass_E_particle_vlo_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_E_particle_vlo_abs_charge(One_Particle_Collection *pthis,
                                           int SPEC, int NUM_SPEC,
                                           double Deltat);
int openmp_split_pass_E_particle_vlo_abs_charge(One_Particle_Collection *pthis,
                                                int SPEC, int NUM_SPEC,
                                                double Deltat);
int cuda_split_pass_E_particle_vlo_abs_charge(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int split_pass_E_particle_vlo_abs_charge_all(One_Particle_Collection *pthis,
                                             int SPEC, int NUM_SPEC, double dt);
int split_pass_E_particle_vlo_abs_charge_mpi(Particle_in_Cell_MPI *pthis,
                                             double dt0);
int c_split_pass_E_particle(One_Particle_Collection *pthis, int SPEC,
                            int NUM_SPEC, double Deltat);
int openmp_split_pass_E_particle(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int cuda_split_pass_E_particle(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int split_pass_E_particle_all(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double dt);
int split_pass_E_particle_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_E_particle_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int openmp_split_pass_E_particle_abs_charge(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int cuda_split_pass_E_particle_abs_charge(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int split_pass_E_particle_abs_charge_all(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double dt);
int split_pass_E_particle_abs_charge_mpi(Particle_in_Cell_MPI *pthis,
                                         double dt0);
int c_dump_ene_num(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                   double Deltat);
int openmp_dump_ene_num(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                        double Deltat);
int cuda_dump_ene_num(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                      double Deltat);
int dump_ene_num_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                     double dt);
int dump_ene_num_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_dump_ene_num_abs_charge(One_Particle_Collection *pthis, int SPEC,
                              int NUM_SPEC, double Deltat);
int openmp_dump_ene_num_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int cuda_dump_ene_num_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double Deltat);
int dump_ene_num_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                int NUM_SPEC, double dt);
int dump_ene_num_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_calculate_rho(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                    double Deltat);
int openmp_calculate_rho(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                         double Deltat);
int cuda_calculate_rho(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                       double Deltat);
int calculate_rho_all(One_Particle_Collection *pthis, int SPEC, int NUM_SPEC,
                      double dt);
int calculate_rho_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_calculate_rho_abs_charge(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int openmp_calculate_rho_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double Deltat);
int cuda_calculate_rho_abs_charge(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int calculate_rho_abs_charge_all(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double dt);
int calculate_rho_abs_charge_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_small_grids(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int openmp_split_pass_x_small_grids(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double Deltat);
int cuda_split_pass_x_small_grids(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int split_pass_x_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double dt);
int split_pass_x_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_small_grids(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int openmp_split_pass_y_small_grids(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double Deltat);
int cuda_split_pass_y_small_grids(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int split_pass_y_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double dt);
int split_pass_y_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_small_grids(One_Particle_Collection *pthis, int SPEC,
                               int NUM_SPEC, double Deltat);
int openmp_split_pass_z_small_grids(One_Particle_Collection *pthis, int SPEC,
                                    int NUM_SPEC, double Deltat);
int cuda_split_pass_z_small_grids(One_Particle_Collection *pthis, int SPEC,
                                  int NUM_SPEC, double Deltat);
int split_pass_z_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                 int NUM_SPEC, double dt);
int split_pass_z_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int openmp_split_pass_x_sg2_small_grids(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_x_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                      int NUM_SPEC, double Deltat);
int split_pass_x_sg2_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double dt);
int split_pass_x_sg2_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int openmp_split_pass_y_sg2_small_grids(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_y_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                      int NUM_SPEC, double Deltat);
int split_pass_y_sg2_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double dt);
int split_pass_y_sg2_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int openmp_split_pass_z_sg2_small_grids(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_z_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                      int NUM_SPEC, double Deltat);
int split_pass_z_sg2_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double dt);
int split_pass_z_sg2_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_vlo_small_grids(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int openmp_split_pass_x_vlo_small_grids(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_x_vlo_small_grids(One_Particle_Collection *pthis, int SPEC,
                                      int NUM_SPEC, double Deltat);
int split_pass_x_vlo_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double dt);
int split_pass_x_vlo_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_y_vlo_small_grids(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int openmp_split_pass_y_vlo_small_grids(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_y_vlo_small_grids(One_Particle_Collection *pthis, int SPEC,
                                      int NUM_SPEC, double Deltat);
int split_pass_y_vlo_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double dt);
int split_pass_y_vlo_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_z_vlo_small_grids(One_Particle_Collection *pthis, int SPEC,
                                   int NUM_SPEC, double Deltat);
int openmp_split_pass_z_vlo_small_grids(One_Particle_Collection *pthis,
                                        int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_z_vlo_small_grids(One_Particle_Collection *pthis, int SPEC,
                                      int NUM_SPEC, double Deltat);
int split_pass_z_vlo_small_grids_all(One_Particle_Collection *pthis, int SPEC,
                                     int NUM_SPEC, double dt);
int split_pass_z_vlo_small_grids_mpi(Particle_in_Cell_MPI *pthis, double dt0);
int c_split_pass_x_vlo_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int openmp_split_pass_x_vlo_sg2_small_grids(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int cuda_split_pass_x_vlo_sg2_small_grids(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int split_pass_x_vlo_sg2_small_grids_all(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double dt);
int split_pass_x_vlo_sg2_small_grids_mpi(Particle_in_Cell_MPI *pthis,
                                         double dt0);
int c_split_pass_y_vlo_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int openmp_split_pass_y_vlo_sg2_small_grids(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int cuda_split_pass_y_vlo_sg2_small_grids(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int split_pass_y_vlo_sg2_small_grids_all(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double dt);
int split_pass_y_vlo_sg2_small_grids_mpi(Particle_in_Cell_MPI *pthis,
                                         double dt0);
int c_split_pass_z_vlo_sg2_small_grids(One_Particle_Collection *pthis, int SPEC,
                                       int NUM_SPEC, double Deltat);
int openmp_split_pass_z_vlo_sg2_small_grids(One_Particle_Collection *pthis,
                                            int SPEC, int NUM_SPEC,
                                            double Deltat);
int cuda_split_pass_z_vlo_sg2_small_grids(One_Particle_Collection *pthis,
                                          int SPEC, int NUM_SPEC,
                                          double Deltat);
int split_pass_z_vlo_sg2_small_grids_all(One_Particle_Collection *pthis,
                                         int SPEC, int NUM_SPEC, double dt);
int split_pass_z_vlo_sg2_small_grids_mpi(Particle_in_Cell_MPI *pthis,
                                         double dt0);
int c_split_pass_x_vlo_sg2_nopush_small_grids(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int openmp_split_pass_x_vlo_sg2_nopush_small_grids(
    One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_x_vlo_sg2_nopush_small_grids(One_Particle_Collection *pthis,
                                                 int SPEC, int NUM_SPEC,
                                                 double Deltat);
int split_pass_x_vlo_sg2_nopush_small_grids_all(One_Particle_Collection *pthis,
                                                int SPEC, int NUM_SPEC,
                                                double dt);
int split_pass_x_vlo_sg2_nopush_small_grids_mpi(Particle_in_Cell_MPI *pthis,
                                                double dt0);
int c_split_pass_y_vlo_sg2_nopush_small_grids(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int openmp_split_pass_y_vlo_sg2_nopush_small_grids(
    One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_y_vlo_sg2_nopush_small_grids(One_Particle_Collection *pthis,
                                                 int SPEC, int NUM_SPEC,
                                                 double Deltat);
int split_pass_y_vlo_sg2_nopush_small_grids_all(One_Particle_Collection *pthis,
                                                int SPEC, int NUM_SPEC,
                                                double dt);
int split_pass_y_vlo_sg2_nopush_small_grids_mpi(Particle_in_Cell_MPI *pthis,
                                                double dt0);
int c_split_pass_z_vlo_sg2_nopush_small_grids(One_Particle_Collection *pthis,
                                              int SPEC, int NUM_SPEC,
                                              double Deltat);
int openmp_split_pass_z_vlo_sg2_nopush_small_grids(
    One_Particle_Collection *pthis, int SPEC, int NUM_SPEC, double Deltat);
int cuda_split_pass_z_vlo_sg2_nopush_small_grids(One_Particle_Collection *pthis,
                                                 int SPEC, int NUM_SPEC,
                                                 double Deltat);
int split_pass_z_vlo_sg2_nopush_small_grids_all(One_Particle_Collection *pthis,
                                                int SPEC, int NUM_SPEC,
                                                double dt);
int split_pass_z_vlo_sg2_nopush_small_grids_mpi(Particle_in_Cell_MPI *pthis,
                                                double dt0);
int split_pass_x_mpi_shell_nouse(Particle_in_Cell_MPI *pthis, double dt0);
int split_pass_y_mpi_shell_nouse(Particle_in_Cell_MPI *pthis, double dt0);
int split_pass_z_mpi_shell_nouse(Particle_in_Cell_MPI *pthis, double dt0);
int split_pass_x_mpi_multi_runtime(Particle_in_Cell_MPI *pthis, double dt0);
int split_pass_y_mpi_multi_runtime(Particle_in_Cell_MPI *pthis, double dt0);
int split_pass_z_mpi_multi_runtime(Particle_in_Cell_MPI *pthis, double dt0);
int split_pass_x_nopush_mpi_multi_runtime(Particle_in_Cell_MPI *pthis,
                                          double dt0);
int split_pass_y_nopush_mpi_multi_runtime(Particle_in_Cell_MPI *pthis,
                                          double dt0);
int split_pass_z_nopush_mpi_multi_runtime(Particle_in_Cell_MPI *pthis,
                                          double dt0);

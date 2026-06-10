#include "pubdefs.h"

int MPI_choose_pusher_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                           Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                           Field3D_MPI *FoutJ, double *pmass, double *pchg,
                           double deltat, double tx0, double slove_err,
                           int mask);
int set_pusher_torix0_solveerr_and_mask(Particle_in_Cell_MPI *fv,
                                        void *puser_fun, double tori_x0,
                                        double solve_err, int mask,
                                        int use_tori);
int nonlin_fun_shell_for_mask(Field3D_MPI *pthis, Field3D_MPI *x,
                              Particle_in_Cell_MPI *fv);
int nonlin_fun_midp_vlasov_maxwell(Field3D_MPI *pthis, Field3D_MPI *x,
                                   Particle_in_Cell_MPI *fv);
int nonlin_fun_cur_min_curlB(Field3D_MPI *pthis, Field3D_MPI *x,
                             Particle_in_Cell_MPI *fv);
int one_step_calc_current(Field3D_MPI *pthis, Field3D_MPI *x,
                          Particle_in_Cell_MPI *fv);
int Jacobi_x(Field3D_MPI *pthis, Field3D_MPI *dx, Particle_in_Cell_MPI **fv);
int gen_jac_mat_x(Field3D_MPI *pthis, Field3D_MPI *dx,
                  Particle_in_Cell_MPI **fv);
int init_jfnk_newton_space(jfnk_newton_space *pthis, Field3D_MPI *x,
                           linear_operator_mpi oscc, double newton_solve_err,
                           double solve_err, int zmax, int newton_zmax,
                           double epsl, void *fv);
int jfnk_newton_simple_mpi(jfnk_newton_space *pthis, Field3D_MPI *inx);
int jfnk_newton_init_parameters(jfnk_newton_space *pthis, int N_l, int N_M,
                                double *pmass, double *pcharge);

#include "pubdefs.h"

int c_One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_ngeo_gc(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_nr_Bfield_pushJ(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_nr_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_nr(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_z_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_y_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_x_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_E_particle_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_E_particle(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_z_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_z(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_y_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_y(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_x_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_split_pass_x(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_relng_1st_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_rel_1st_bwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_rel_1st_fwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_relng_1st_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_rel_1st_bwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_rel_1st_fwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_rel_1st_bwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_geo_rel_1st_fwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_ngeo_gc(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_nr_Bfield_pushJ(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_nr_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_nr(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_z_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_y_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_x_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_E_particle_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_E_particle(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_z_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_z(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_y_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_y(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_x_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_split_pass_x(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_relng_1st_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_rel_1st_bwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_rel_1st_fwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_relng_1st_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_rel_1st_bwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_rel_1st_fwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_rel_1st_bwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_geo_rel_1st_fwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_ngeo_gc(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_nr_Bfield_pushJ(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_nr_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_nr(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_z_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_y_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_x_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_E_particle_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_E_particle(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_z_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_z(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_y_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_y(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_x_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_split_pass_x(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_relng_1st_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_rel_1st_bwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_rel_1st_fwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_relng_1st_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_rel_1st_bwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_rel_1st_fwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_rel_1st_bwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_geo_rel_1st_fwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int SPEC, int NUM_SPEC);
int One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec);
int MPI_geo_nr_Bfield_pushJ_nopush_par_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double r0, double MIN_R0, double Q0,
    double b0, double zmid, int mask);
int MPI_geo_nr_Bfield_pushJ_nopush_par(Particle_in_Cell_MPI *pthis,
                                       Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                       Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
                                       double *Mass0, double *Charge0,
                                       double Deltat, double Tori_X0, double r0,
                                       double MIN_R0, double Q0, double b0,
                                       double zmid);
int One_Particle_Collection_geo_nr_Bfield_pushJ_nopush_par_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec);
int MPI_geo_nr_Bfield_pushJ_nopush_par_vlo_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double r0, double MIN_R0, double Q0,
    double b0, double zmid, int mask);
int MPI_geo_nr_Bfield_pushJ_nopush_par_vlo(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double r0, double MIN_R0, double Q0,
    double b0, double zmid);
int One_Particle_Collection_ngeo_gc(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec);
int MPI_ngeo_gc_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                     Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                     Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                     double Deltat, double Tori_X0, double r0, double MIN_R0,
                     double Q0, double b0, double zmid, int mask);
int MPI_ngeo_gc(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                Field3D_MPI *fieldB, Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
                double *Mass0, double *Charge0, double Deltat, double Tori_X0,
                double r0, double MIN_R0, double Q0, double b0, double zmid);
int One_Particle_Collection_geo_nr_Bfield_pushJ_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec);
int MPI_geo_nr_Bfield_pushJ_vlo_mask(Particle_in_Cell_MPI *pthis,
                                     Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                     Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
                                     double *Mass0, double *Charge0,
                                     double Deltat, double Tori_X0, double r0,
                                     double MIN_R0, double Q0, double b0,
                                     double zmid, int mask);
int MPI_geo_nr_Bfield_pushJ_vlo(Particle_in_Cell_MPI *pthis,
                                Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
                                double *Mass0, double *Charge0, double Deltat,
                                double Tori_X0, double r0, double MIN_R0,
                                double Q0, double b0, double zmid);
int One_Particle_Collection_geo_nr_Bfield_pushJ(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec);
int MPI_geo_nr_Bfield_pushJ_mask(Particle_in_Cell_MPI *pthis,
                                 Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                 Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
                                 double *Mass0, double *Charge0, double Deltat,
                                 double Tori_X0, double r0, double MIN_R0,
                                 double Q0, double b0, double zmid, int mask);
int MPI_geo_nr_Bfield_pushJ(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                            Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                            Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                            double Deltat, double Tori_X0, double r0,
                            double MIN_R0, double Q0, double b0, double zmid);
int One_Particle_Collection_geo_nr_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double r0,
    double MIN_R0, double Q0, double b0, double zmid, int spec, int num_spec);
int MPI_geo_nr_vlo_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                        Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                        Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                        double Deltat, double Tori_X0, double r0, double MIN_R0,
                        double Q0, double b0, double zmid, int mask);
int MPI_geo_nr_vlo(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                   Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                   Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                   double Deltat, double Tori_X0, double r0, double MIN_R0,
                   double Q0, double b0, double zmid);
int One_Particle_Collection_geo_nr(One_Particle_Collection *pthis,
                                   Field3D_Seq *fieldE, Field3D_Seq *fieldB,
                                   Field3D_Seq *fieldB1, Field3D_Seq *FoutJ,
                                   double Mass0_lst_fix, double Charge0_lst_fix,
                                   double Deltat, double Tori_X0, double r0,
                                   double MIN_R0, double Q0, double b0,
                                   double zmid, int spec, int num_spec);
int MPI_geo_nr_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                    Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                    Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                    double Deltat, double Tori_X0, double r0, double MIN_R0,
                    double Q0, double b0, double zmid, int mask);
int MPI_geo_nr(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
               Field3D_MPI *fieldB, Field3D_MPI *fieldB1, Field3D_MPI *FoutJ,
               double *Mass0, double *Charge0, double Deltat, double Tori_X0,
               double r0, double MIN_R0, double Q0, double b0, double zmid);
int One_Particle_Collection_split_pass_z_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_z_vlo_sg2_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *LFoutJ, Field3D_MPI *FoutEN, double *Mass, double *Charge,
    double Deltat, int mask);
int MPI_split_pass_z_vlo_sg2_small_grids(Particle_in_Cell_MPI *pthis,
                                         Field3D_MPI *fieldE,
                                         Field3D_MPI *fieldB,
                                         Field3D_MPI *LFoutJ,
                                         Field3D_MPI *FoutEN, double *Mass,
                                         double *Charge, double Deltat);
int One_Particle_Collection_split_pass_y_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_y_vlo_sg2_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *LFoutJ, Field3D_MPI *FoutEN, double *Mass, double *Charge,
    double Deltat, int mask);
int MPI_split_pass_y_vlo_sg2_small_grids(Particle_in_Cell_MPI *pthis,
                                         Field3D_MPI *fieldE,
                                         Field3D_MPI *fieldB,
                                         Field3D_MPI *LFoutJ,
                                         Field3D_MPI *FoutEN, double *Mass,
                                         double *Charge, double Deltat);
int One_Particle_Collection_split_pass_x_vlo_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *LFoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_x_vlo_sg2_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *LFoutJ, Field3D_MPI *FoutEN, double *Mass, double *Charge,
    double Deltat, int mask);
int MPI_split_pass_x_vlo_sg2_small_grids(Particle_in_Cell_MPI *pthis,
                                         Field3D_MPI *fieldE,
                                         Field3D_MPI *fieldB,
                                         Field3D_MPI *LFoutJ,
                                         Field3D_MPI *FoutEN, double *Mass,
                                         double *Charge, double Deltat);
int One_Particle_Collection_split_pass_E_particle_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_E_particle_vlo_mask(Particle_in_Cell_MPI *pthis,
                                       Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                       Field3D_MPI *FoutJ, Field3D_MPI *FoutEN,
                                       double *Mass, double *Charge,
                                       double Deltat, int mask);
int MPI_split_pass_E_particle_vlo(Particle_in_Cell_MPI *pthis,
                                  Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                  Field3D_MPI *FoutJ, Field3D_MPI *FoutEN,
                                  double *Mass, double *Charge, double Deltat);
int One_Particle_Collection_split_pass_E_particle(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_E_particle_mask(Particle_in_Cell_MPI *pthis,
                                   Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                   Field3D_MPI *FoutJ, Field3D_MPI *FoutEN,
                                   double *Mass, double *Charge, double Deltat,
                                   int mask);
int MPI_split_pass_E_particle(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                              Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                              Field3D_MPI *FoutEN, double *Mass, double *Charge,
                              double Deltat);
int One_Particle_Collection_split_pass_z_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_z_vlo_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                              Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                              Field3D_MPI *FoutEN, double *Mass, double *Charge,
                              double Deltat, int mask);
int MPI_split_pass_z_vlo(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                         Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                         Field3D_MPI *FoutEN, double *Mass, double *Charge,
                         double Deltat);
int One_Particle_Collection_split_pass_z(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_z_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                          Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                          Field3D_MPI *FoutEN, double *Mass, double *Charge,
                          double Deltat, int mask);
int MPI_split_pass_z(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                     Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                     Field3D_MPI *FoutEN, double *Mass, double *Charge,
                     double Deltat);
int One_Particle_Collection_split_pass_y_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_y_vlo_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                              Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                              Field3D_MPI *FoutEN, double *Mass, double *Charge,
                              double Deltat, int mask);
int MPI_split_pass_y_vlo(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                         Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                         Field3D_MPI *FoutEN, double *Mass, double *Charge,
                         double Deltat);
int One_Particle_Collection_split_pass_y(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_y_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                          Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                          Field3D_MPI *FoutEN, double *Mass, double *Charge,
                          double Deltat, int mask);
int MPI_split_pass_y(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                     Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                     Field3D_MPI *FoutEN, double *Mass, double *Charge,
                     double Deltat);
int One_Particle_Collection_split_pass_x_vlo(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_x_vlo_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                              Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                              Field3D_MPI *FoutEN, double *Mass, double *Charge,
                              double Deltat, int mask);
int MPI_split_pass_x_vlo(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                         Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                         Field3D_MPI *FoutEN, double *Mass, double *Charge,
                         double Deltat);
int One_Particle_Collection_split_pass_x(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, Field3D_Seq *FoutEN, double Mass_lst_fix,
    double Charge_lst_fix, double Deltat, int spec, int num_spec);
int MPI_split_pass_x_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                          Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                          Field3D_MPI *FoutEN, double *Mass, double *Charge,
                          double Deltat, int mask);
int MPI_split_pass_x(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                     Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                     Field3D_MPI *FoutEN, double *Mass, double *Charge,
                     double Deltat);
int One_Particle_Collection_relng_1st_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_relng_1st_sg2_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err, int mask);
int MPI_relng_1st_sg2_small_grids(Particle_in_Cell_MPI *pthis,
                                  Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                  Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ,
                                  double *Mass0, double *Charge0, double Deltat,
                                  double Tori_X0, double Solve_Err);
int One_Particle_Collection_geo_rel_1st_bwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_geo_rel_1st_bwd_sg2_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err, int mask);
int MPI_geo_rel_1st_bwd_sg2_small_grids(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err);
int One_Particle_Collection_geo_rel_1st_fwd_sg2_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_geo_rel_1st_fwd_sg2_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err, int mask);
int MPI_geo_rel_1st_fwd_sg2_small_grids(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err);
int One_Particle_Collection_relng_1st_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_relng_1st_small_grids_mask(Particle_in_Cell_MPI *pthis,
                                   Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                   Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ,
                                   double *Mass0, double *Charge0,
                                   double Deltat, double Tori_X0,
                                   double Solve_Err, int mask);
int MPI_relng_1st_small_grids(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                              Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                              Field3D_MPI *LFoutJ, double *Mass0,
                              double *Charge0, double Deltat, double Tori_X0,
                              double Solve_Err);
int One_Particle_Collection_geo_rel_1st_bwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_geo_rel_1st_bwd_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err, int mask);
int MPI_geo_rel_1st_bwd_small_grids(Particle_in_Cell_MPI *pthis,
                                    Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ,
                                    double *Mass0, double *Charge0,
                                    double Deltat, double Tori_X0,
                                    double Solve_Err);
int One_Particle_Collection_geo_rel_1st_fwd_small_grids(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *LFoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_geo_rel_1st_fwd_small_grids_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ, double *Mass0, double *Charge0,
    double Deltat, double Tori_X0, double Solve_Err, int mask);
int MPI_geo_rel_1st_fwd_small_grids(Particle_in_Cell_MPI *pthis,
                                    Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                    Field3D_MPI *fieldB1, Field3D_MPI *LFoutJ,
                                    double *Mass0, double *Charge0,
                                    double Deltat, double Tori_X0,
                                    double Solve_Err);
int One_Particle_Collection_geo_rel_1st_bwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_geo_rel_1st_bwd_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                             Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                             Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                             double Deltat, double Tori_X0, double Solve_Err,
                             int mask);
int MPI_geo_rel_1st_bwd(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                        Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                        Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                        double Deltat, double Tori_X0, double Solve_Err);
int One_Particle_Collection_geo_rel_1st_fwd(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *fieldB1, Field3D_Seq *FoutJ, double Mass0_lst_fix,
    double Charge0_lst_fix, double Deltat, double Tori_X0, double Solve_Err,
    int spec, int num_spec);
int MPI_geo_rel_1st_fwd_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                             Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                             Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                             double Deltat, double Tori_X0, double Solve_Err,
                             int mask);
int MPI_geo_rel_1st_fwd(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                        Field3D_MPI *fieldB, Field3D_MPI *fieldB1,
                        Field3D_MPI *FoutJ, double *Mass0, double *Charge0,
                        double Deltat, double Tori_X0, double Solve_Err);
int c_One_Particle_Collection_krook_collision_remove_small_speed(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int SPEC, int NUM_SPEC);
int c_One_Particle_Collection_krook_collision_test(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_krook_collision_remove_small_speed(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_krook_collision_test(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_krook_collision_remove_small_speed(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_krook_collision_test(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int SPEC, int NUM_SPEC);
int One_Particle_Collection_krook_collision_remove_small_speed(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int spec, int num_spec);
int MPI_krook_collision_remove_small_speed_mask(
    Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE, Field3D_MPI *fieldB,
    Field3D_MPI *FoutJ, double *Mass0, double *Charge0, double Deltat,
    double mu_freq, int mask);
int MPI_krook_collision_remove_small_speed(Particle_in_Cell_MPI *pthis,
                                           Field3D_MPI *fieldE,
                                           Field3D_MPI *fieldB,
                                           Field3D_MPI *FoutJ, double *Mass0,
                                           double *Charge0, double Deltat,
                                           double mu_freq);
int One_Particle_Collection_krook_collision_test(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, double mu_freq, int spec, int num_spec);
int MPI_krook_collision_test_mask(Particle_in_Cell_MPI *pthis,
                                  Field3D_MPI *fieldE, Field3D_MPI *fieldB,
                                  Field3D_MPI *FoutJ, double *Mass0,
                                  double *Charge0, double Deltat,
                                  double mu_freq, int mask);
int MPI_krook_collision_test(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                             Field3D_MPI *fieldB, Field3D_MPI *FoutJ,
                             double *Mass0, double *Charge0, double Deltat,
                             double mu_freq);
int c_One_Particle_Collection_boris_yee(One_Particle_Collection *pthis,
                                        Field3D_Seq *fieldE,
                                        Field3D_Seq *fieldB, Field3D_Seq *FoutJ,
                                        double Mass0_lst_fix,
                                        double Charge0_lst_fix, double Deltat,
                                        int SPEC, int NUM_SPEC);
int openmp_One_Particle_Collection_boris_yee(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, int SPEC, int NUM_SPEC);
int cuda_One_Particle_Collection_boris_yee(
    One_Particle_Collection *pthis, Field3D_Seq *fieldE, Field3D_Seq *fieldB,
    Field3D_Seq *FoutJ, double Mass0_lst_fix, double Charge0_lst_fix,
    double Deltat, int SPEC, int NUM_SPEC);
int One_Particle_Collection_boris_yee(One_Particle_Collection *pthis,
                                      Field3D_Seq *fieldE, Field3D_Seq *fieldB,
                                      Field3D_Seq *FoutJ, double Mass0_lst_fix,
                                      double Charge0_lst_fix, double Deltat,
                                      int spec, int num_spec);
int MPI_boris_yee_mask(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                       Field3D_MPI *fieldB, Field3D_MPI *FoutJ, double *Mass0,
                       double *Charge0, double Deltat, int mask);
int MPI_boris_yee(Particle_in_Cell_MPI *pthis, Field3D_MPI *fieldE,
                  Field3D_MPI *fieldB, Field3D_MPI *FoutJ, double *Mass0,
                  double *Charge0, double Deltat);

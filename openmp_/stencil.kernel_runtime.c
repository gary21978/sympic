#include <omp.h>

#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "openmp_pscmc_inc.h"

#include "stencil.kernel_inc.h"

int  openmp_Yee_FDTD_W04_2_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_W04_2_struct *  kerstr ){
	return  0 ;
}
void  openmp_Yee_FDTD_W04_2_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_W04_2_struct ));
}
int  openmp_Yee_FDTD_W04_2_get_num_compute_units (openmp_Yee_FDTD_W04_2_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_Yee_FDTD_W04_2_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_Yee_FDTD_W04_2_exec (openmp_Yee_FDTD_W04_2_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;

	int  yid ;

	int  numt = 	omp_get_num_threads (  )
 ;

	int  tid = 	omp_get_thread_num (  )
 ;

	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 )
 )
 / numt )
 ;

	int  ymin = 	(  tid * ysingle )
 ;

	int  ymax = 	(  	(  1 + tid )
 * ysingle )
 ;

	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen )
 ; (yid = 	(  yid + numt )
))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen )
 ; (xid = 	(  xid + 1 )
))
	{
	openmp_Yee_FDTD_W04_2_scmc_kernel ( 	( kerstr )->outEB
 , 	( kerstr )->inEB
 , (	( kerstr )->y_cpu_core
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->DT
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_outEB (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_inEB (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_numvec (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_XLEN (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_YLEN (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_ovlp (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_xblock (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_yblock (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_zblock (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_num_ele (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_2_scmc_set_parameter_DT (openmp_Yee_FDTD_W04_2_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_W04_1_struct *  kerstr ){
	return  0 ;
}
void  openmp_Yee_FDTD_W04_1_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_W04_1_struct ));
}
int  openmp_Yee_FDTD_W04_1_get_num_compute_units (openmp_Yee_FDTD_W04_1_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_Yee_FDTD_W04_1_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_Yee_FDTD_W04_1_exec (openmp_Yee_FDTD_W04_1_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;

	int  yid ;

	int  numt = 	omp_get_num_threads (  )
 ;

	int  tid = 	omp_get_thread_num (  )
 ;

	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 )
 )
 / numt )
 ;

	int  ymin = 	(  tid * ysingle )
 ;

	int  ymax = 	(  	(  1 + tid )
 * ysingle )
 ;

	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen )
 ; (yid = 	(  yid + numt )
))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen )
 ; (xid = 	(  xid + 1 )
))
	{
	openmp_Yee_FDTD_W04_1_scmc_kernel ( 	( kerstr )->outEB
 , 	( kerstr )->inEB
 , (	( kerstr )->y_cpu_core
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->DT
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_outEB (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_inEB (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_numvec (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_XLEN (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_YLEN (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_ovlp (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_xblock (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_yblock (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_zblock (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_num_ele (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_1_scmc_set_parameter_DT (openmp_Yee_FDTD_W04_1_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_init (openmp_pscmc_env *  pe ,openmp_Yee_FDTD_W04_0_struct *  kerstr ){
	return  0 ;
}
void  openmp_Yee_FDTD_W04_0_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_Yee_FDTD_W04_0_struct ));
}
int  openmp_Yee_FDTD_W04_0_get_num_compute_units (openmp_Yee_FDTD_W04_0_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_Yee_FDTD_W04_0_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_Yee_FDTD_W04_0_exec (openmp_Yee_FDTD_W04_0_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

#pragma omp parallel
{
	int  xid ;

	int  yid ;

	int  numt = 	omp_get_num_threads (  )
 ;

	int  tid = 	omp_get_thread_num (  )
 ;

	int  ysingle = 	(  	(  scmc_internal_g_ylen + 	(  numt - 1 )
 )
 / numt )
 ;

	int  ymin = 	(  tid * ysingle )
 ;

	int  ymax = 	(  	(  1 + tid )
 * ysingle )
 ;

	for ((yid = tid) ; 	(  yid < scmc_internal_g_ylen )
 ; (yid = 	(  yid + numt )
))
	{
	for ((xid = 0) ; 	(  xid < scmc_internal_g_xlen )
 ; (xid = 	(  xid + 1 )
))
	{
	openmp_Yee_FDTD_W04_0_scmc_kernel ( 	( kerstr )->outEB
 , 	( kerstr )->inEB
 , (	( kerstr )->y_cpu_core
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->DT
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_outEB (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->outEB
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_inEB (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inEB
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_y_cpu_core (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->y_cpu_core
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_numvec (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_XLEN (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_YLEN (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_ZLEN (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_ovlp (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_xblock (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_yblock (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_zblock (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_num_ele (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_Yee_FDTD_W04_0_scmc_set_parameter_DT (openmp_Yee_FDTD_W04_0_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->DT
 = pm->d_data);
}

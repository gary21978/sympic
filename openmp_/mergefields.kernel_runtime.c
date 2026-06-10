#include <omp.h>

#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "openmp_pscmc_inc.h"

#include "mergefields.kernel_inc.h"

int  openmp_merge_ovlp_m2o_once_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_m2o_once_struct *  kerstr ){
	return  0 ;
}
void  openmp_merge_ovlp_m2o_once_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_m2o_once_struct ));
}
int  openmp_merge_ovlp_m2o_once_get_num_compute_units (openmp_merge_ovlp_m2o_once_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_merge_ovlp_m2o_once_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_merge_ovlp_m2o_once_exec (openmp_merge_ovlp_m2o_once_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_m2o_once_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp0
 , 	( kerstr )->vecovlp1
 , 	( kerstr )->vecovlp2
 , 	( kerstr )->vecovlp3
 , 	( kerstr )->vecovlp4
 , 	( kerstr )->vecovlp5
 , 	( kerstr )->vecovlp6
 , 	( kerstr )->vecovlp7
 , 	( kerstr )->vecovlp8
 , 	( kerstr )->vecovlp9
 , 	( kerstr )->vecovlp10
 , 	( kerstr )->vecovlp11
 , 	( kerstr )->vecovlp12
 , 	( kerstr )->vecovlp14
 , 	( kerstr )->vecovlp15
 , 	( kerstr )->vecovlp16
 , 	( kerstr )->vecovlp17
 , 	( kerstr )->vecovlp18
 , 	( kerstr )->vecovlp19
 , 	( kerstr )->vecovlp20
 , 	( kerstr )->vecovlp21
 , 	( kerstr )->vecovlp22
 , 	( kerstr )->vecovlp23
 , 	( kerstr )->vecovlp24
 , 	( kerstr )->vecovlp25
 , 	( kerstr )->vecovlp26
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecmain (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp0 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp0
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp1 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp1
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp2 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp2
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp3 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp3
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp4 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp4
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp5 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp5
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp6 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp6
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp7 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp7
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp8 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp8
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp9 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp9
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp10 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp10
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp11 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp11
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp12 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp12
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp14 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp14
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp15 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp15
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp16 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp16
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp17 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp17
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp18 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp18
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp19 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp19
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp20 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp20
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp21 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp21
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp22 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp22
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp23 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp23
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp24 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp24
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp25 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp25
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp26 (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp26
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_numvec (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_num_ele (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_xblock (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_yblock (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_zblock (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_once_scmc_set_parameter_ovlp (openmp_merge_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ){
	return  0 ;
}
void  openmp_merge_ovlp_m2o_all_in_one_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_m2o_all_in_one_struct ));
}
int  openmp_merge_ovlp_m2o_all_in_one_get_num_compute_units (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_merge_ovlp_m2o_all_in_one_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_merge_ovlp_m2o_all_in_one_exec (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_m2o_all_in_one_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlps
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlps
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp (openmp_merge_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_m2o_struct *  kerstr ){
	return  0 ;
}
void  openmp_merge_ovlp_m2o_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_m2o_struct ));
}
int  openmp_merge_ovlp_m2o_get_num_compute_units (openmp_merge_ovlp_m2o_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_merge_ovlp_m2o_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_merge_ovlp_m2o_exec (openmp_merge_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_m2o_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp
 , (	( kerstr )->ovlpindex
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_vecmain (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_vecovlp (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_ovlpindex (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_numvec (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_num_ele (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_xblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_yblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_zblock (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_merge_ovlp_m2o_scmc_set_parameter_ovlp (openmp_merge_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_o2m_once_struct *  kerstr ){
	return  0 ;
}
void  openmp_merge_ovlp_o2m_once_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_o2m_once_struct ));
}
int  openmp_merge_ovlp_o2m_once_get_num_compute_units (openmp_merge_ovlp_o2m_once_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_merge_ovlp_o2m_once_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_merge_ovlp_o2m_once_exec (openmp_merge_ovlp_o2m_once_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_o2m_once_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp0
 , 	( kerstr )->vecovlp1
 , 	( kerstr )->vecovlp2
 , 	( kerstr )->vecovlp3
 , 	( kerstr )->vecovlp4
 , 	( kerstr )->vecovlp5
 , 	( kerstr )->vecovlp6
 , 	( kerstr )->vecovlp7
 , 	( kerstr )->vecovlp8
 , 	( kerstr )->vecovlp9
 , 	( kerstr )->vecovlp10
 , 	( kerstr )->vecovlp11
 , 	( kerstr )->vecovlp12
 , 	( kerstr )->vecovlp14
 , 	( kerstr )->vecovlp15
 , 	( kerstr )->vecovlp16
 , 	( kerstr )->vecovlp17
 , 	( kerstr )->vecovlp18
 , 	( kerstr )->vecovlp19
 , 	( kerstr )->vecovlp20
 , 	( kerstr )->vecovlp21
 , 	( kerstr )->vecovlp22
 , 	( kerstr )->vecovlp23
 , 	( kerstr )->vecovlp24
 , 	( kerstr )->vecovlp25
 , 	( kerstr )->vecovlp26
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecmain (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp0 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp0
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp1 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp1
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp2 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp2
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp3 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp3
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp4 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp4
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp5 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp5
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp6 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp6
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp7 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp7
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp8 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp8
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp9 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp9
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp10 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp10
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp11 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp11
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp12 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp12
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp14 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp14
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp15 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp15
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp16 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp16
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp17 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp17
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp18 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp18
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp19 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp19
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp20 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp20
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp21 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp21
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp22 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp22
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp23 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp23
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp24 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp24
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp25 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp25
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp26 (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp26
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_numvec (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_num_ele (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_xblock (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_yblock (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_zblock (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_once_scmc_set_parameter_ovlp (openmp_merge_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ){
	return  0 ;
}
void  openmp_merge_ovlp_o2m_all_in_one_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_o2m_all_in_one_struct ));
}
int  openmp_merge_ovlp_o2m_all_in_one_get_num_compute_units (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_merge_ovlp_o2m_all_in_one_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_merge_ovlp_o2m_all_in_one_exec (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_o2m_all_in_one_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlps
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlps
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp (openmp_merge_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_init (openmp_pscmc_env *  pe ,openmp_merge_ovlp_o2m_struct *  kerstr ){
	return  0 ;
}
void  openmp_merge_ovlp_o2m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_merge_ovlp_o2m_struct ));
}
int  openmp_merge_ovlp_o2m_get_num_compute_units (openmp_merge_ovlp_o2m_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_merge_ovlp_o2m_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_merge_ovlp_o2m_exec (openmp_merge_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_merge_ovlp_o2m_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp
 , (	( kerstr )->ovlpindex
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_vecmain (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_vecovlp (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_ovlpindex (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_numvec (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_num_ele (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_xblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_yblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_zblock (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_merge_ovlp_o2m_scmc_set_parameter_ovlp (openmp_merge_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_m2o_once_struct *  kerstr ){
	return  0 ;
}
void  openmp_sync_ovlp_m2o_once_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_m2o_once_struct ));
}
int  openmp_sync_ovlp_m2o_once_get_num_compute_units (openmp_sync_ovlp_m2o_once_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sync_ovlp_m2o_once_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sync_ovlp_m2o_once_exec (openmp_sync_ovlp_m2o_once_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_m2o_once_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp0
 , 	( kerstr )->vecovlp1
 , 	( kerstr )->vecovlp2
 , 	( kerstr )->vecovlp3
 , 	( kerstr )->vecovlp4
 , 	( kerstr )->vecovlp5
 , 	( kerstr )->vecovlp6
 , 	( kerstr )->vecovlp7
 , 	( kerstr )->vecovlp8
 , 	( kerstr )->vecovlp9
 , 	( kerstr )->vecovlp10
 , 	( kerstr )->vecovlp11
 , 	( kerstr )->vecovlp12
 , 	( kerstr )->vecovlp14
 , 	( kerstr )->vecovlp15
 , 	( kerstr )->vecovlp16
 , 	( kerstr )->vecovlp17
 , 	( kerstr )->vecovlp18
 , 	( kerstr )->vecovlp19
 , 	( kerstr )->vecovlp20
 , 	( kerstr )->vecovlp21
 , 	( kerstr )->vecovlp22
 , 	( kerstr )->vecovlp23
 , 	( kerstr )->vecovlp24
 , 	( kerstr )->vecovlp25
 , 	( kerstr )->vecovlp26
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecmain (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp0 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp0
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp1 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp1
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp2 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp2
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp3 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp3
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp4 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp4
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp5 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp5
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp6 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp6
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp7 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp7
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp8 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp8
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp9 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp9
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp10 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp10
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp11 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp11
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp12 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp12
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp14 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp14
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp15 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp15
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp16 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp16
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp17 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp17
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp18 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp18
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp19 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp19
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp20 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp20
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp21 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp21
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp22 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp22
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp23 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp23
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp24 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp24
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp25 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp25
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp26 (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp26
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_numvec (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_num_ele (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_xblock (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_yblock (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_zblock (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_once_scmc_set_parameter_ovlp (openmp_sync_ovlp_m2o_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ){
	return  0 ;
}
void  openmp_sync_ovlp_m2o_all_in_one_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_m2o_all_in_one_struct ));
}
int  openmp_sync_ovlp_m2o_all_in_one_get_num_compute_units (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sync_ovlp_m2o_all_in_one_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sync_ovlp_m2o_all_in_one_exec (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_m2o_all_in_one_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlps
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlps
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp (openmp_sync_ovlp_m2o_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_m2o_struct *  kerstr ){
	return  0 ;
}
void  openmp_sync_ovlp_m2o_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_m2o_struct ));
}
int  openmp_sync_ovlp_m2o_get_num_compute_units (openmp_sync_ovlp_m2o_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sync_ovlp_m2o_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sync_ovlp_m2o_exec (openmp_sync_ovlp_m2o_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_m2o_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp
 , (	( kerstr )->ovlpindex
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_vecmain (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_vecovlp (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_ovlpindex (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_numvec (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_num_ele (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_xblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_yblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_zblock (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_sync_ovlp_m2o_scmc_set_parameter_ovlp (openmp_sync_ovlp_m2o_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_o2m_once_struct *  kerstr ){
	return  0 ;
}
void  openmp_sync_ovlp_o2m_once_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_o2m_once_struct ));
}
int  openmp_sync_ovlp_o2m_once_get_num_compute_units (openmp_sync_ovlp_o2m_once_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sync_ovlp_o2m_once_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sync_ovlp_o2m_once_exec (openmp_sync_ovlp_o2m_once_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_o2m_once_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp0
 , 	( kerstr )->vecovlp1
 , 	( kerstr )->vecovlp2
 , 	( kerstr )->vecovlp3
 , 	( kerstr )->vecovlp4
 , 	( kerstr )->vecovlp5
 , 	( kerstr )->vecovlp6
 , 	( kerstr )->vecovlp7
 , 	( kerstr )->vecovlp8
 , 	( kerstr )->vecovlp9
 , 	( kerstr )->vecovlp10
 , 	( kerstr )->vecovlp11
 , 	( kerstr )->vecovlp12
 , 	( kerstr )->vecovlp14
 , 	( kerstr )->vecovlp15
 , 	( kerstr )->vecovlp16
 , 	( kerstr )->vecovlp17
 , 	( kerstr )->vecovlp18
 , 	( kerstr )->vecovlp19
 , 	( kerstr )->vecovlp20
 , 	( kerstr )->vecovlp21
 , 	( kerstr )->vecovlp22
 , 	( kerstr )->vecovlp23
 , 	( kerstr )->vecovlp24
 , 	( kerstr )->vecovlp25
 , 	( kerstr )->vecovlp26
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecmain (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp0 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp0
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp1 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp1
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp2 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp2
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp3 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp3
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp4 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp4
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp5 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp5
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp6 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp6
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp7 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp7
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp8 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp8
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp9 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp9
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp10 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp10
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp11 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp11
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp12 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp12
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp14 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp14
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp15 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp15
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp16 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp16
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp17 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp17
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp18 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp18
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp19 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp19
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp20 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp20
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp21 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp21
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp22 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp22
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp23 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp23
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp24 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp24
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp25 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp25
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp26 (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp26
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_numvec (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_num_ele (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_xblock (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_yblock (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_zblock (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_once_scmc_set_parameter_ovlp (openmp_sync_ovlp_o2m_once_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ){
	return  0 ;
}
void  openmp_sync_ovlp_o2m_all_in_one_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_o2m_all_in_one_struct ));
}
int  openmp_sync_ovlp_o2m_all_in_one_get_num_compute_units (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sync_ovlp_o2m_all_in_one_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sync_ovlp_o2m_all_in_one_exec (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_o2m_all_in_one_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlps
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlps
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp (openmp_sync_ovlp_o2m_all_in_one_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_init (openmp_pscmc_env *  pe ,openmp_sync_ovlp_o2m_struct *  kerstr ){
	return  0 ;
}
void  openmp_sync_ovlp_o2m_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sync_ovlp_o2m_struct ));
}
int  openmp_sync_ovlp_o2m_get_num_compute_units (openmp_sync_ovlp_o2m_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sync_ovlp_o2m_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sync_ovlp_o2m_exec (openmp_sync_ovlp_o2m_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sync_ovlp_o2m_scmc_kernel ( 	( kerstr )->vecmain
 , 	( kerstr )->vecovlp
 , (	( kerstr )->ovlpindex
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_vecmain (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecmain
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_vecovlp (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->vecovlp
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_ovlpindex (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlpindex
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_numvec (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_num_ele (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_xblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_yblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_zblock (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_sync_ovlp_o2m_scmc_set_parameter_ovlp (openmp_sync_ovlp_o2m_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_yee_local_init (openmp_pscmc_env *  pe ,openmp_yee_local_struct *  kerstr ){
	return  0 ;
}
void  openmp_yee_local_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_yee_local_struct ));
}
int  openmp_yee_local_get_num_compute_units (openmp_yee_local_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_yee_local_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_yee_local_exec (openmp_yee_local_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_yee_local_scmc_kernel ( 	( kerstr )->inout
 , (	( kerstr )->numvec
)[0] , (	( kerstr )->num_ele
)[0] , (	( kerstr )->xblock
)[0] , (	( kerstr )->yblock
)[0] , (	( kerstr )->zblock
)[0] , (	( kerstr )->ovlp
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_yee_local_scmc_set_parameter_inout (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inout
 = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_numvec (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_num_ele (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->num_ele
 = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_xblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xblock
 = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_yblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->yblock
 = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_zblock (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->zblock
 = pm->d_data);
}
int  openmp_yee_local_scmc_set_parameter_ovlp (openmp_yee_local_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}

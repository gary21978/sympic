#include <omp.h>

#include <stdio.h>

#include <stdlib.h>

#include "local_header.h"

#include "openmp_pscmc_inc.h"

#include "general_partial_sort.kernel_inc.h"

int  openmp_cu_swap_r_8_init (openmp_pscmc_env *  pe ,openmp_cu_swap_r_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_cu_swap_r_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_cu_swap_r_8_struct ));
}
int  openmp_cu_swap_r_8_get_num_compute_units (openmp_cu_swap_r_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_cu_swap_r_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_cu_swap_r_8_exec (openmp_cu_swap_r_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_cu_swap_r_8_scmc_kernel ( 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->cu_cache_length
)[0] , (	( kerstr )->the_dir_num
)[0] , (	( kerstr )->XYZLEN
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_cu_swap_r_8_scmc_set_parameter_cu_cache (openmp_cu_swap_r_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_cu_swap_r_8_scmc_set_parameter_cu_xyzw (openmp_cu_swap_r_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_cu_swap_r_8_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_r_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_cu_swap_r_8_scmc_set_parameter_cu_cache_length (openmp_cu_swap_r_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_cu_swap_r_8_scmc_set_parameter_the_dir_num (openmp_cu_swap_r_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->the_dir_num
 = pm->d_data);
}
int  openmp_cu_swap_r_8_scmc_set_parameter_XYZLEN (openmp_cu_swap_r_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XYZLEN
 = pm->d_data);
}
int  openmp_cu_swap_l_8_init (openmp_pscmc_env *  pe ,openmp_cu_swap_l_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_cu_swap_l_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_cu_swap_l_8_struct ));
}
int  openmp_cu_swap_l_8_get_num_compute_units (openmp_cu_swap_l_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_cu_swap_l_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_cu_swap_l_8_exec (openmp_cu_swap_l_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_cu_swap_l_8_scmc_kernel ( 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->cu_cache_length
)[0] , (	( kerstr )->the_dir_num
)[0] , (	( kerstr )->XYZLEN
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_cu_swap_l_8_scmc_set_parameter_cu_cache (openmp_cu_swap_l_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_cu_swap_l_8_scmc_set_parameter_cu_xyzw (openmp_cu_swap_l_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_cu_swap_l_8_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_l_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_cu_swap_l_8_scmc_set_parameter_cu_cache_length (openmp_cu_swap_l_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_cu_swap_l_8_scmc_set_parameter_the_dir_num (openmp_cu_swap_l_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->the_dir_num
 = pm->d_data);
}
int  openmp_cu_swap_l_8_scmc_set_parameter_XYZLEN (openmp_cu_swap_l_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XYZLEN
 = pm->d_data);
}
int  openmp_cu_swap_r_6_init (openmp_pscmc_env *  pe ,openmp_cu_swap_r_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_cu_swap_r_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_cu_swap_r_6_struct ));
}
int  openmp_cu_swap_r_6_get_num_compute_units (openmp_cu_swap_r_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_cu_swap_r_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_cu_swap_r_6_exec (openmp_cu_swap_r_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_cu_swap_r_6_scmc_kernel ( 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->cu_cache_length
)[0] , (	( kerstr )->the_dir_num
)[0] , (	( kerstr )->XYZLEN
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_cu_swap_r_6_scmc_set_parameter_cu_cache (openmp_cu_swap_r_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_cu_swap_r_6_scmc_set_parameter_cu_xyzw (openmp_cu_swap_r_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_cu_swap_r_6_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_r_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_cu_swap_r_6_scmc_set_parameter_cu_cache_length (openmp_cu_swap_r_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_cu_swap_r_6_scmc_set_parameter_the_dir_num (openmp_cu_swap_r_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->the_dir_num
 = pm->d_data);
}
int  openmp_cu_swap_r_6_scmc_set_parameter_XYZLEN (openmp_cu_swap_r_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XYZLEN
 = pm->d_data);
}
int  openmp_cu_swap_l_6_init (openmp_pscmc_env *  pe ,openmp_cu_swap_l_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_cu_swap_l_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_cu_swap_l_6_struct ));
}
int  openmp_cu_swap_l_6_get_num_compute_units (openmp_cu_swap_l_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_cu_swap_l_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_cu_swap_l_6_exec (openmp_cu_swap_l_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_cu_swap_l_6_scmc_kernel ( 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->cu_cache_length
)[0] , (	( kerstr )->the_dir_num
)[0] , (	( kerstr )->XYZLEN
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_cu_swap_l_6_scmc_set_parameter_cu_cache (openmp_cu_swap_l_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_cu_swap_l_6_scmc_set_parameter_cu_xyzw (openmp_cu_swap_l_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_cu_swap_l_6_scmc_set_parameter_adjoint_vec_pids (openmp_cu_swap_l_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_cu_swap_l_6_scmc_set_parameter_cu_cache_length (openmp_cu_swap_l_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_cu_swap_l_6_scmc_set_parameter_the_dir_num (openmp_cu_swap_l_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->the_dir_num
 = pm->d_data);
}
int  openmp_cu_swap_l_6_scmc_set_parameter_XYZLEN (openmp_cu_swap_l_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XYZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_vlo_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_z_vlo_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_z_vlo_8_struct ));
}
int  openmp_sort_one_grid_z_vlo_8_get_num_compute_units (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_z_vlo_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_z_vlo_8_exec (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_z_vlo_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_z_vlo_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_z_vlo_8_struct ));
}
int  openmp_gpu_sort_one_grid_z_vlo_8_get_num_compute_units (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_z_vlo_8_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_z_vlo_8_exec (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_z_vlo_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_8_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_z_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_vlo_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_y_vlo_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_y_vlo_8_struct ));
}
int  openmp_sort_one_grid_y_vlo_8_get_num_compute_units (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_y_vlo_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_y_vlo_8_exec (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_y_vlo_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_y_vlo_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_y_vlo_8_struct ));
}
int  openmp_gpu_sort_one_grid_y_vlo_8_get_num_compute_units (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_y_vlo_8_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_y_vlo_8_exec (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_y_vlo_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_8_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_y_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_vlo_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_x_vlo_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_x_vlo_8_struct ));
}
int  openmp_sort_one_grid_x_vlo_8_get_num_compute_units (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_x_vlo_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_x_vlo_8_exec (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_x_vlo_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_x_vlo_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_x_vlo_8_struct ));
}
int  openmp_gpu_sort_one_grid_x_vlo_8_get_num_compute_units (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_x_vlo_8_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_x_vlo_8_exec (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_x_vlo_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_8_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_x_vlo_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_z_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_z_8_struct ));
}
int  openmp_sort_one_grid_z_8_get_num_compute_units (openmp_sort_one_grid_z_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_z_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_z_8_exec (openmp_sort_one_grid_z_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_z_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_numvec (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_z_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_z_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_z_8_struct ));
}
int  openmp_gpu_sort_one_grid_z_8_get_num_compute_units (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_z_8_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_z_8_exec (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_z_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_8_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_z_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_y_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_y_8_struct ));
}
int  openmp_sort_one_grid_y_8_get_num_compute_units (openmp_sort_one_grid_y_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_y_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_y_8_exec (openmp_sort_one_grid_y_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_y_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_numvec (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_y_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_y_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_y_8_struct ));
}
int  openmp_gpu_sort_one_grid_y_8_get_num_compute_units (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_y_8_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_y_8_exec (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_y_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_8_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_y_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_x_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_x_8_struct ));
}
int  openmp_sort_one_grid_x_8_get_num_compute_units (openmp_sort_one_grid_x_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_x_8_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_x_8_exec (openmp_sort_one_grid_x_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_x_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_numvec (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_x_8_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_x_8_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_x_8_struct ));
}
int  openmp_gpu_sort_one_grid_x_8_get_num_compute_units (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_x_8_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_x_8_exec (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_x_8_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_8_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_x_8_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_vlo_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_z_vlo_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_z_vlo_6_struct ));
}
int  openmp_sort_one_grid_z_vlo_6_get_num_compute_units (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_z_vlo_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_z_vlo_6_exec (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_z_vlo_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_z_vlo_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_z_vlo_6_struct ));
}
int  openmp_gpu_sort_one_grid_z_vlo_6_get_num_compute_units (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_z_vlo_6_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_z_vlo_6_exec (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_z_vlo_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_vlo_6_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_z_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_vlo_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_y_vlo_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_y_vlo_6_struct ));
}
int  openmp_sort_one_grid_y_vlo_6_get_num_compute_units (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_y_vlo_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_y_vlo_6_exec (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_y_vlo_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_y_vlo_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_y_vlo_6_struct ));
}
int  openmp_gpu_sort_one_grid_y_vlo_6_get_num_compute_units (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_y_vlo_6_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_y_vlo_6_exec (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_y_vlo_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_vlo_6_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_y_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_vlo_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_x_vlo_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_x_vlo_6_struct ));
}
int  openmp_sort_one_grid_x_vlo_6_get_num_compute_units (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_x_vlo_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_x_vlo_6_exec (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_x_vlo_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_x_vlo_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_x_vlo_6_struct ));
}
int  openmp_gpu_sort_one_grid_x_vlo_6_get_num_compute_units (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_x_vlo_6_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_x_vlo_6_exec (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_x_vlo_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_vlo_6_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_x_vlo_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_z_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_z_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_z_6_struct ));
}
int  openmp_sort_one_grid_z_6_get_num_compute_units (openmp_sort_one_grid_z_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_z_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_z_6_exec (openmp_sort_one_grid_z_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_z_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_inoutput (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_xyzw (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_cu_cache (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_XLEN (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_YLEN (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_ZLEN (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_ovlp (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_numvec (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_z_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_z_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_z_6_struct ));
}
int  openmp_gpu_sort_one_grid_z_6_get_num_compute_units (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_z_6_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_z_6_exec (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_z_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_z_6_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_z_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_y_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_y_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_y_6_struct ));
}
int  openmp_sort_one_grid_y_6_get_num_compute_units (openmp_sort_one_grid_y_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_y_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_y_6_exec (openmp_sort_one_grid_y_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_y_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_inoutput (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_xyzw (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_cu_cache (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_XLEN (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_YLEN (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_ZLEN (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_ovlp (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_numvec (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_y_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_y_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_y_6_struct ));
}
int  openmp_gpu_sort_one_grid_y_6_get_num_compute_units (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_y_6_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_y_6_exec (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_y_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_y_6_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_y_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_init (openmp_pscmc_env *  pe ,openmp_sort_one_grid_x_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_sort_one_grid_x_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_sort_one_grid_x_6_struct ));
}
int  openmp_sort_one_grid_x_6_get_num_compute_units (openmp_sort_one_grid_x_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_sort_one_grid_x_6_get_xlen (){
	return  IDX_OPT_MAX ;
}
int  openmp_sort_one_grid_x_6_exec (openmp_sort_one_grid_x_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_sort_one_grid_x_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_inoutput (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_xyzw (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_cu_cache (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_XLEN (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_YLEN (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_ZLEN (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_ovlp (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_numvec (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length (openmp_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_init (openmp_pscmc_env *  pe ,openmp_gpu_sort_one_grid_x_6_struct *  kerstr ){
	return  0 ;
}
void  openmp_gpu_sort_one_grid_x_6_get_struct_len (size_t *  len ){
((len)[0] = sizeof(openmp_gpu_sort_one_grid_x_6_struct ));
}
int  openmp_gpu_sort_one_grid_x_6_get_num_compute_units (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ){
	return  	omp_get_max_threads (  )
 ;
}
int  openmp_gpu_sort_one_grid_x_6_get_xlen (){
	return  32 ;
}
int  openmp_gpu_sort_one_grid_x_6_exec (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,long  scmc_internal_g_xlen ,long  scmc_internal_g_ylen ){

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
	openmp_gpu_sort_one_grid_x_6_scmc_kernel ( 	( kerstr )->inoutput
 , 	( kerstr )->xyzw
 , 	( kerstr )->cu_cache
 , 	( kerstr )->cu_xyzw
 , 	( kerstr )->adjoint_vec_pids
 , (	( kerstr )->XLEN
)[0] , (	( kerstr )->YLEN
)[0] , (	( kerstr )->ZLEN
)[0] , (	( kerstr )->ovlp
)[0] , (	( kerstr )->numvec
)[0] , (	( kerstr )->grid_cache_len
)[0] , (	( kerstr )->cu_cache_length
)[0] , yid , scmc_internal_g_ylen )
;
}
}
}	return  0 ;
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_inoutput (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->inoutput
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_xyzw (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_xyzw (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_xyzw
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_adjoint_vec_pids (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->adjoint_vec_pids
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_XLEN (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->XLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_YLEN (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->YLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_ZLEN (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ZLEN
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_ovlp (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->ovlp
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_numvec (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->numvec
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_grid_cache_len (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->grid_cache_len
 = pm->d_data);
}
int  openmp_gpu_sort_one_grid_x_6_scmc_set_parameter_cu_cache_length (openmp_gpu_sort_one_grid_x_6_struct *  kerstr ,openmp_pscmc_mem *  pm ){
(	( kerstr )->cu_cache_length
 = pm->d_data);
}

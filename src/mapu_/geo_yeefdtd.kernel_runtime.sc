#include "local_header.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "geo_yeefdtd.kernel_runtime.h"


#include "geo_yeefdtd.kernel.inc"
#define VEC_WIDTH 8
    static int dump_kernel_variables = 0;

    extern long _pscmc_mapu_global_dump_kernel_variables, _pscmc_mapu_global_dump_times;

    int mapu_YEE_CURL_R_init(mapu_pscmc_env *pe, mapu_YEE_CURL_R_struct *kerstr)
    {
        ((kerstr)->pe = pe);
        return 0;
    }
    void mapu_YEE_CURL_R_get_struct_len(size_t *len)
    {
        ((len)[0] = sizeof(mapu_YEE_CURL_R_struct));
    }
    int mapu_YEE_CURL_R_get_xlen()
    {
        return 1;
    }
    int mapu_YEE_CURL_R_get_num_compute_units(mapu_YEE_CURL_R_struct *kerstr)
    {
        return 4;
    }
    int mapu_YEE_CURL_R_exec(mapu_YEE_CURL_R_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
    {

        mapsSetDevice((kerstr->pe)->device_id);

        
        MAPU_LONG XLEN_val = kerstr->XLEN->h_data[0];
        MAPU_LONG YLEN_val = kerstr->YLEN->h_data[0];
        MAPU_LONG ZLEN_val = kerstr->ZLEN->h_data[0];
        MAPU_LONG numvec_val = kerstr->numvec->h_data[0];

        MAPU_LONG X_segments = (XLEN_val + VEC_WIDTH - 1) / VEC_WIDTH;
        MAPU_LONG total_threads = numvec_val * YLEN_val * ZLEN_val * X_segments;

        int block_size = 128;
        MAPU_LONG grid_size = (total_threads + block_size - 1) / block_size;

     
        dim3 grid((unsigned int)grid_size, 1, 1);
        mapu_YEE_CURL_R<<<grid, block_size>>>(((__DDR double *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->inoutE1->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR double *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->inB0->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR int *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->xoffset->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR int *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->yoffset->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), ((__DDR int *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->zoffset->d_data , & (__d_data_address_tmp2) );
__d_data_address_tmp2; })), (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0]);
       
        
        (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_inoutE1(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->inoutE1 = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_inB0(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->inB0 = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_xoffset(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->xoffset = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_yoffset(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->yoffset = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_zoffset(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->zoffset = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_y_cpu_core(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->y_cpu_core = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_numvec(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->numvec = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_XLEN(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->XLEN = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_YLEN(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->YLEN = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_ZLEN(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->ZLEN = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_ovlp(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->ovlp = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_xblock(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->xblock = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_yblock(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->yblock = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_zblock(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->zblock = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_num_ele(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->num_ele = pm);
        return 0;
    }
    int mapu_YEE_CURL_R_scmc_set_parameter_DT(mapu_YEE_CURL_R_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->DT = pm);
        return 0;
    }
    
    int mapu_GEO_YEE_CURL_L_init(mapu_pscmc_env *pe, mapu_GEO_YEE_CURL_L_struct *kerstr)
    {
        ((kerstr)->pe = pe);
        return 0;
    }
    void mapu_GEO_YEE_CURL_L_get_struct_len(size_t *len)
    {
        ((len)[0] = sizeof(mapu_GEO_YEE_CURL_L_struct));
    }
    int mapu_GEO_YEE_CURL_L_get_xlen()
    {
        return 1;
    }
    int mapu_GEO_YEE_CURL_L_get_num_compute_units(mapu_GEO_YEE_CURL_L_struct *kerstr)
    {
        return 4;
    }
    int mapu_GEO_YEE_CURL_L_exec(mapu_GEO_YEE_CURL_L_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
    {
        mapsSetDevice((kerstr->pe)->device_id);

        MAPU_LONG XLEN_val = kerstr->XLEN->h_data[0];
        MAPU_LONG YLEN_val = kerstr->YLEN->h_data[0];
        MAPU_LONG ZLEN_val = kerstr->ZLEN->h_data[0];
        MAPU_LONG numvec_val = kerstr->numvec->h_data[0];

        MAPU_LONG X_segments = (XLEN_val + VEC_WIDTH - 1) / VEC_WIDTH;
        MAPU_LONG total_threads = numvec_val * YLEN_val * ZLEN_val * X_segments;

        int block_size = 128;
        MAPU_LONG grid_size = (total_threads + block_size - 1) / block_size;

        dim3 grid((unsigned int)grid_size, 1, 1);
        mapu_GEO_YEE_CURL_L<<<grid, block_size>>>(((__DDR double *)({
    	 uint64_t  __d_data_address_tmp2 ;
    	mapsMemobjGetPhysicalAddress ( kerstr->inoutE1->d_data , & (__d_data_address_tmp2) );
    __d_data_address_tmp2; })), ((__DDR double *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->inB0->d_data , & (__d_data_address_tmp2) );
    __d_data_address_tmp2; })), ((__DDR int *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->xoffset->d_data , & (__d_data_address_tmp2) );
    __d_data_address_tmp2; })), ((__DDR int *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->yoffset->d_data , & (__d_data_address_tmp2) );
    __d_data_address_tmp2; })), ((__DDR int *)({
	 uint64_t  __d_data_address_tmp2 ;
	mapsMemobjGetPhysicalAddress ( kerstr->zoffset->d_data , & (__d_data_address_tmp2) );
    __d_data_address_tmp2; })), (((MAPU_LONG *)kerstr->y_cpu_core->h_data))[0], (((MAPU_LONG *)kerstr->numvec->h_data))[0], (((MAPU_LONG *)kerstr->XLEN->h_data))[0], (((MAPU_LONG *)kerstr->YLEN->h_data))[0], (((MAPU_LONG *)kerstr->ZLEN->h_data))[0], (((int *)kerstr->ovlp->h_data))[0], (((MAPU_LONG *)kerstr->xblock->h_data))[0], (((MAPU_LONG *)kerstr->yblock->h_data))[0], (((MAPU_LONG *)kerstr->zblock->h_data))[0], (((int *)kerstr->num_ele->h_data))[0], (((double *)kerstr->DT->h_data))[0], (((double *)kerstr->DELTA_Z->h_data))[0], (((double *)kerstr->DELTA_Y->h_data))[0], (((double *)kerstr->DELTA_X->h_data))[0], (((double *)kerstr->x0->h_data))[0]);
 

        (_pscmc_mapu_global_dump_times = (_pscmc_mapu_global_dump_times + 1));
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_inoutE1(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->inoutE1 = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_inB0(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->inB0 = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_xoffset(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->xoffset = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_yoffset(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->yoffset = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_zoffset(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->zoffset = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_y_cpu_core(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->y_cpu_core = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_numvec(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->numvec = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_XLEN(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->XLEN = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_YLEN(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->YLEN = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_ZLEN(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->ZLEN = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_ovlp(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->ovlp = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_xblock(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->xblock = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_yblock(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->yblock = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_zblock(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->zblock = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_num_ele(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->num_ele = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DT(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->DT = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Z(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->DELTA_Z = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_Y(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->DELTA_Y = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_DELTA_X(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->DELTA_X = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_x0(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->x0 = pm);
        return 0;
    }
    int mapu_GEO_YEE_CURL_L_scmc_set_parameter_r0(mapu_GEO_YEE_CURL_L_struct *kerstr, mapu_pscmc_mem *pm)
    {
        mapsSetDevice((kerstr->pe)->device_id);
        (kerstr->r0 = pm);
        return 0;
    }
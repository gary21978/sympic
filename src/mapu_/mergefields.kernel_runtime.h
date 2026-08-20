#pragma once
#include "mapu_pscmc.h"

typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp0;
	mapu_pscmc_mem *vecovlp1;
	mapu_pscmc_mem *vecovlp2;
	mapu_pscmc_mem *vecovlp3;
	mapu_pscmc_mem *vecovlp4;
	mapu_pscmc_mem *vecovlp5;
	mapu_pscmc_mem *vecovlp6;
	mapu_pscmc_mem *vecovlp7;
	mapu_pscmc_mem *vecovlp8;
	mapu_pscmc_mem *vecovlp9;
	mapu_pscmc_mem *vecovlp10;
	mapu_pscmc_mem *vecovlp11;
	mapu_pscmc_mem *vecovlp12;
	mapu_pscmc_mem *vecovlp14;
	mapu_pscmc_mem *vecovlp15;
	mapu_pscmc_mem *vecovlp16;
	mapu_pscmc_mem *vecovlp17;
	mapu_pscmc_mem *vecovlp18;
	mapu_pscmc_mem *vecovlp19;
	mapu_pscmc_mem *vecovlp20;
	mapu_pscmc_mem *vecovlp21;
	mapu_pscmc_mem *vecovlp22;
	mapu_pscmc_mem *vecovlp23;
	mapu_pscmc_mem *vecovlp24;
	mapu_pscmc_mem *vecovlp25;
	mapu_pscmc_mem *vecovlp26;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_merge_ovlp_m2o_once_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlps;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_merge_ovlp_m2o_all_in_one_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp;
	mapu_pscmc_mem *ovlpindex;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_merge_ovlp_m2o_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp0;
	mapu_pscmc_mem *vecovlp1;
	mapu_pscmc_mem *vecovlp2;
	mapu_pscmc_mem *vecovlp3;
	mapu_pscmc_mem *vecovlp4;
	mapu_pscmc_mem *vecovlp5;
	mapu_pscmc_mem *vecovlp6;
	mapu_pscmc_mem *vecovlp7;
	mapu_pscmc_mem *vecovlp8;
	mapu_pscmc_mem *vecovlp9;
	mapu_pscmc_mem *vecovlp10;
	mapu_pscmc_mem *vecovlp11;
	mapu_pscmc_mem *vecovlp12;
	mapu_pscmc_mem *vecovlp14;
	mapu_pscmc_mem *vecovlp15;
	mapu_pscmc_mem *vecovlp16;
	mapu_pscmc_mem *vecovlp17;
	mapu_pscmc_mem *vecovlp18;
	mapu_pscmc_mem *vecovlp19;
	mapu_pscmc_mem *vecovlp20;
	mapu_pscmc_mem *vecovlp21;
	mapu_pscmc_mem *vecovlp22;
	mapu_pscmc_mem *vecovlp23;
	mapu_pscmc_mem *vecovlp24;
	mapu_pscmc_mem *vecovlp25;
	mapu_pscmc_mem *vecovlp26;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_merge_ovlp_o2m_once_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlps;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_merge_ovlp_o2m_all_in_one_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp;
	mapu_pscmc_mem *ovlpindex;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_merge_ovlp_o2m_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp0;
	mapu_pscmc_mem *vecovlp1;
	mapu_pscmc_mem *vecovlp2;
	mapu_pscmc_mem *vecovlp3;
	mapu_pscmc_mem *vecovlp4;
	mapu_pscmc_mem *vecovlp5;
	mapu_pscmc_mem *vecovlp6;
	mapu_pscmc_mem *vecovlp7;
	mapu_pscmc_mem *vecovlp8;
	mapu_pscmc_mem *vecovlp9;
	mapu_pscmc_mem *vecovlp10;
	mapu_pscmc_mem *vecovlp11;
	mapu_pscmc_mem *vecovlp12;
	mapu_pscmc_mem *vecovlp14;
	mapu_pscmc_mem *vecovlp15;
	mapu_pscmc_mem *vecovlp16;
	mapu_pscmc_mem *vecovlp17;
	mapu_pscmc_mem *vecovlp18;
	mapu_pscmc_mem *vecovlp19;
	mapu_pscmc_mem *vecovlp20;
	mapu_pscmc_mem *vecovlp21;
	mapu_pscmc_mem *vecovlp22;
	mapu_pscmc_mem *vecovlp23;
	mapu_pscmc_mem *vecovlp24;
	mapu_pscmc_mem *vecovlp25;
	mapu_pscmc_mem *vecovlp26;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_sync_ovlp_m2o_once_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlps;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_sync_ovlp_m2o_all_in_one_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp;
	mapu_pscmc_mem *ovlpindex;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_sync_ovlp_m2o_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp0;
	mapu_pscmc_mem *vecovlp1;
	mapu_pscmc_mem *vecovlp2;
	mapu_pscmc_mem *vecovlp3;
	mapu_pscmc_mem *vecovlp4;
	mapu_pscmc_mem *vecovlp5;
	mapu_pscmc_mem *vecovlp6;
	mapu_pscmc_mem *vecovlp7;
	mapu_pscmc_mem *vecovlp8;
	mapu_pscmc_mem *vecovlp9;
	mapu_pscmc_mem *vecovlp10;
	mapu_pscmc_mem *vecovlp11;
	mapu_pscmc_mem *vecovlp12;
	mapu_pscmc_mem *vecovlp14;
	mapu_pscmc_mem *vecovlp15;
	mapu_pscmc_mem *vecovlp16;
	mapu_pscmc_mem *vecovlp17;
	mapu_pscmc_mem *vecovlp18;
	mapu_pscmc_mem *vecovlp19;
	mapu_pscmc_mem *vecovlp20;
	mapu_pscmc_mem *vecovlp21;
	mapu_pscmc_mem *vecovlp22;
	mapu_pscmc_mem *vecovlp23;
	mapu_pscmc_mem *vecovlp24;
	mapu_pscmc_mem *vecovlp25;
	mapu_pscmc_mem *vecovlp26;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_sync_ovlp_o2m_once_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlps;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_sync_ovlp_o2m_all_in_one_struct;
typedef struct
{
	mapu_pscmc_env *pe;
	mapu_pscmc_mem *vecmain;
	mapu_pscmc_mem *vecovlp;
	mapu_pscmc_mem *ovlpindex;
	mapu_pscmc_mem *numvec;
	mapu_pscmc_mem *num_ele;
	mapu_pscmc_mem *xblock;
	mapu_pscmc_mem *yblock;
	mapu_pscmc_mem *zblock;
	mapu_pscmc_mem *ovlp;
} mapu_sync_ovlp_o2m_struct;

#ifdef __cplusplus
    extern "C" {
#endif

int mapu_merge_ovlp_m2o_once_init(mapu_pscmc_env *pe,
                                  mapu_merge_ovlp_m2o_once_struct *kerstr);
void mapu_merge_ovlp_m2o_once_get_struct_len(size_t *len);
int mapu_merge_ovlp_m2o_once_get_xlen();

int mapu_merge_ovlp_m2o_once_exec(mapu_merge_ovlp_m2o_once_struct *kerstr,
                                  long scmc_internal_g_xlen,
                                  long scmc_internal_g_ylen);

int mapu_merge_ovlp_m2o_all_in_one_init(
    mapu_pscmc_env *pe, mapu_merge_ovlp_m2o_all_in_one_struct *kerstr);
void mapu_merge_ovlp_m2o_all_in_one_get_struct_len(size_t *len);
int mapu_merge_ovlp_m2o_all_in_one_get_xlen();

int mapu_merge_ovlp_m2o_all_in_one_exec(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);

int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    mapu_merge_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_m2o_init(mapu_pscmc_env *pe,
                             mapu_merge_ovlp_m2o_struct *kerstr);
void mapu_merge_ovlp_m2o_get_struct_len(size_t *len);

int mapu_merge_ovlp_o2m_once_init(mapu_pscmc_env *pe,
                                  mapu_merge_ovlp_o2m_once_struct *kerstr);
void mapu_merge_ovlp_o2m_once_get_struct_len(size_t *len);

int mapu_merge_ovlp_o2m_once_scmc_set_parameter_yblock(
    mapu_merge_ovlp_o2m_once_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_once_scmc_set_parameter_zblock(
    mapu_merge_ovlp_o2m_once_struct *kerstr, mapu_pscmc_mem *pm);

int mapu_merge_ovlp_o2m_all_in_one_init(
    mapu_pscmc_env *pe, mapu_merge_ovlp_o2m_all_in_one_struct *kerstr);
void mapu_merge_ovlp_o2m_all_in_one_get_struct_len(size_t *len);
int mapu_merge_ovlp_o2m_all_in_one_get_xlen();

int mapu_merge_ovlp_o2m_all_in_one_exec(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    mapu_merge_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_merge_ovlp_o2m_init(mapu_pscmc_env *pe,
                             mapu_merge_ovlp_o2m_struct *kerstr);
void mapu_merge_ovlp_o2m_get_struct_len(size_t *len);

int mapu_sync_ovlp_m2o_once_init(mapu_pscmc_env *pe,
                                 mapu_sync_ovlp_m2o_once_struct *kerstr);
void mapu_sync_ovlp_m2o_once_get_struct_len(size_t *len);

int mapu_sync_ovlp_m2o_all_in_one_init(
    mapu_pscmc_env *pe, mapu_sync_ovlp_m2o_all_in_one_struct *kerstr);
void mapu_sync_ovlp_m2o_all_in_one_get_struct_len(size_t *len);
int mapu_sync_ovlp_m2o_all_in_one_get_xlen();

int mapu_sync_ovlp_m2o_all_in_one_exec(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(
    mapu_sync_ovlp_m2o_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_m2o_init(mapu_pscmc_env *pe,
                            mapu_sync_ovlp_m2o_struct *kerstr);
void mapu_sync_ovlp_m2o_get_struct_len(size_t *len);

int mapu_sync_ovlp_o2m_once_init(mapu_pscmc_env *pe,
                                 mapu_sync_ovlp_o2m_once_struct *kerstr);
void mapu_sync_ovlp_o2m_once_get_struct_len(size_t *len);

int mapu_sync_ovlp_o2m_all_in_one_init(
    mapu_pscmc_env *pe, mapu_sync_ovlp_o2m_all_in_one_struct *kerstr);
void mapu_sync_ovlp_o2m_all_in_one_get_struct_len(size_t *len);
int mapu_sync_ovlp_o2m_all_in_one_get_xlen();

int mapu_sync_ovlp_o2m_all_in_one_exec(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen,
    long scmc_internal_g_ylen);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(
    mapu_sync_ovlp_o2m_all_in_one_struct *kerstr, mapu_pscmc_mem *pm);
int mapu_sync_ovlp_o2m_init(mapu_pscmc_env *pe,
                            mapu_sync_ovlp_o2m_struct *kerstr);
void mapu_sync_ovlp_o2m_get_struct_len(size_t *len);

#ifdef __cplusplus
    }
#endif
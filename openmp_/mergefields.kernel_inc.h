typedef struct { 
	double *  vecmain ;

	double *  vecovlp0 ;

	double *  vecovlp1 ;

	double *  vecovlp2 ;

	double *  vecovlp3 ;

	double *  vecovlp4 ;

	double *  vecovlp5 ;

	double *  vecovlp6 ;

	double *  vecovlp7 ;

	double *  vecovlp8 ;

	double *  vecovlp9 ;

	double *  vecovlp10 ;

	double *  vecovlp11 ;

	double *  vecovlp12 ;

	double *  vecovlp14 ;

	double *  vecovlp15 ;

	double *  vecovlp16 ;

	double *  vecovlp17 ;

	double *  vecovlp18 ;

	double *  vecovlp19 ;

	double *  vecovlp20 ;

	double *  vecovlp21 ;

	double *  vecovlp22 ;

	double *  vecovlp23 ;

	double *  vecovlp24 ;

	double *  vecovlp25 ;

	double *  vecovlp26 ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp0_len ;

	long  vecovlp1_len ;

	long  vecovlp2_len ;

	long  vecovlp3_len ;

	long  vecovlp4_len ;

	long  vecovlp5_len ;

	long  vecovlp6_len ;

	long  vecovlp7_len ;

	long  vecovlp8_len ;

	long  vecovlp9_len ;

	long  vecovlp10_len ;

	long  vecovlp11_len ;

	long  vecovlp12_len ;

	long  vecovlp14_len ;

	long  vecovlp15_len ;

	long  vecovlp16_len ;

	long  vecovlp17_len ;

	long  vecovlp18_len ;

	long  vecovlp19_len ;

	long  vecovlp20_len ;

	long  vecovlp21_len ;

	long  vecovlp22_len ;

	long  vecovlp23_len ;

	long  vecovlp24_len ;

	long  vecovlp25_len ;

	long  vecovlp26_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_merge_ovlp_m2o_once_struct;
void  openmp_merge_ovlp_m2o_once_scmc_kernel (double *  vecmain ,double *  vecovlp0 ,double *  vecovlp1 ,double *  vecovlp2 ,double *  vecovlp3 ,double *  vecovlp4 ,double *  vecovlp5 ,double *  vecovlp6 ,double *  vecovlp7 ,double *  vecovlp8 ,double *  vecovlp9 ,double *  vecovlp10 ,double *  vecovlp11 ,double *  vecovlp12 ,double *  vecovlp14 ,double *  vecovlp15 ,double *  vecovlp16 ,double *  vecovlp17 ,double *  vecovlp18 ,double *  vecovlp19 ,double *  vecovlp20 ,double *  vecovlp21 ,double *  vecovlp22 ,double *  vecovlp23 ,double *  vecovlp24 ,double *  vecovlp25 ,double *  vecovlp26 ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlps ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlps_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_merge_ovlp_m2o_all_in_one_struct;
void  openmp_merge_ovlp_m2o_all_in_one_scmc_kernel (double *  vecmain ,double *  vecovlps ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp ;

	int *  ovlpindex ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp_len ;

	long  ovlpindex_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_merge_ovlp_m2o_struct;
void  openmp_merge_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp0 ;

	double *  vecovlp1 ;

	double *  vecovlp2 ;

	double *  vecovlp3 ;

	double *  vecovlp4 ;

	double *  vecovlp5 ;

	double *  vecovlp6 ;

	double *  vecovlp7 ;

	double *  vecovlp8 ;

	double *  vecovlp9 ;

	double *  vecovlp10 ;

	double *  vecovlp11 ;

	double *  vecovlp12 ;

	double *  vecovlp14 ;

	double *  vecovlp15 ;

	double *  vecovlp16 ;

	double *  vecovlp17 ;

	double *  vecovlp18 ;

	double *  vecovlp19 ;

	double *  vecovlp20 ;

	double *  vecovlp21 ;

	double *  vecovlp22 ;

	double *  vecovlp23 ;

	double *  vecovlp24 ;

	double *  vecovlp25 ;

	double *  vecovlp26 ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp0_len ;

	long  vecovlp1_len ;

	long  vecovlp2_len ;

	long  vecovlp3_len ;

	long  vecovlp4_len ;

	long  vecovlp5_len ;

	long  vecovlp6_len ;

	long  vecovlp7_len ;

	long  vecovlp8_len ;

	long  vecovlp9_len ;

	long  vecovlp10_len ;

	long  vecovlp11_len ;

	long  vecovlp12_len ;

	long  vecovlp14_len ;

	long  vecovlp15_len ;

	long  vecovlp16_len ;

	long  vecovlp17_len ;

	long  vecovlp18_len ;

	long  vecovlp19_len ;

	long  vecovlp20_len ;

	long  vecovlp21_len ;

	long  vecovlp22_len ;

	long  vecovlp23_len ;

	long  vecovlp24_len ;

	long  vecovlp25_len ;

	long  vecovlp26_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_merge_ovlp_o2m_once_struct;
void  openmp_merge_ovlp_o2m_once_scmc_kernel (double *  vecmain ,double *  vecovlp0 ,double *  vecovlp1 ,double *  vecovlp2 ,double *  vecovlp3 ,double *  vecovlp4 ,double *  vecovlp5 ,double *  vecovlp6 ,double *  vecovlp7 ,double *  vecovlp8 ,double *  vecovlp9 ,double *  vecovlp10 ,double *  vecovlp11 ,double *  vecovlp12 ,double *  vecovlp14 ,double *  vecovlp15 ,double *  vecovlp16 ,double *  vecovlp17 ,double *  vecovlp18 ,double *  vecovlp19 ,double *  vecovlp20 ,double *  vecovlp21 ,double *  vecovlp22 ,double *  vecovlp23 ,double *  vecovlp24 ,double *  vecovlp25 ,double *  vecovlp26 ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlps ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlps_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_merge_ovlp_o2m_all_in_one_struct;
void  openmp_merge_ovlp_o2m_all_in_one_scmc_kernel (double *  vecmain ,double *  vecovlps ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp ;

	int *  ovlpindex ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp_len ;

	long  ovlpindex_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_merge_ovlp_o2m_struct;
void  openmp_merge_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp0 ;

	double *  vecovlp1 ;

	double *  vecovlp2 ;

	double *  vecovlp3 ;

	double *  vecovlp4 ;

	double *  vecovlp5 ;

	double *  vecovlp6 ;

	double *  vecovlp7 ;

	double *  vecovlp8 ;

	double *  vecovlp9 ;

	double *  vecovlp10 ;

	double *  vecovlp11 ;

	double *  vecovlp12 ;

	double *  vecovlp14 ;

	double *  vecovlp15 ;

	double *  vecovlp16 ;

	double *  vecovlp17 ;

	double *  vecovlp18 ;

	double *  vecovlp19 ;

	double *  vecovlp20 ;

	double *  vecovlp21 ;

	double *  vecovlp22 ;

	double *  vecovlp23 ;

	double *  vecovlp24 ;

	double *  vecovlp25 ;

	double *  vecovlp26 ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp0_len ;

	long  vecovlp1_len ;

	long  vecovlp2_len ;

	long  vecovlp3_len ;

	long  vecovlp4_len ;

	long  vecovlp5_len ;

	long  vecovlp6_len ;

	long  vecovlp7_len ;

	long  vecovlp8_len ;

	long  vecovlp9_len ;

	long  vecovlp10_len ;

	long  vecovlp11_len ;

	long  vecovlp12_len ;

	long  vecovlp14_len ;

	long  vecovlp15_len ;

	long  vecovlp16_len ;

	long  vecovlp17_len ;

	long  vecovlp18_len ;

	long  vecovlp19_len ;

	long  vecovlp20_len ;

	long  vecovlp21_len ;

	long  vecovlp22_len ;

	long  vecovlp23_len ;

	long  vecovlp24_len ;

	long  vecovlp25_len ;

	long  vecovlp26_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_sync_ovlp_m2o_once_struct;
void  openmp_sync_ovlp_m2o_once_scmc_kernel (double *  vecmain ,double *  vecovlp0 ,double *  vecovlp1 ,double *  vecovlp2 ,double *  vecovlp3 ,double *  vecovlp4 ,double *  vecovlp5 ,double *  vecovlp6 ,double *  vecovlp7 ,double *  vecovlp8 ,double *  vecovlp9 ,double *  vecovlp10 ,double *  vecovlp11 ,double *  vecovlp12 ,double *  vecovlp14 ,double *  vecovlp15 ,double *  vecovlp16 ,double *  vecovlp17 ,double *  vecovlp18 ,double *  vecovlp19 ,double *  vecovlp20 ,double *  vecovlp21 ,double *  vecovlp22 ,double *  vecovlp23 ,double *  vecovlp24 ,double *  vecovlp25 ,double *  vecovlp26 ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlps ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlps_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_sync_ovlp_m2o_all_in_one_struct;
void  openmp_sync_ovlp_m2o_all_in_one_scmc_kernel (double *  vecmain ,double *  vecovlps ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp ;

	int *  ovlpindex ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp_len ;

	long  ovlpindex_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_sync_ovlp_m2o_struct;
void  openmp_sync_ovlp_m2o_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp0 ;

	double *  vecovlp1 ;

	double *  vecovlp2 ;

	double *  vecovlp3 ;

	double *  vecovlp4 ;

	double *  vecovlp5 ;

	double *  vecovlp6 ;

	double *  vecovlp7 ;

	double *  vecovlp8 ;

	double *  vecovlp9 ;

	double *  vecovlp10 ;

	double *  vecovlp11 ;

	double *  vecovlp12 ;

	double *  vecovlp14 ;

	double *  vecovlp15 ;

	double *  vecovlp16 ;

	double *  vecovlp17 ;

	double *  vecovlp18 ;

	double *  vecovlp19 ;

	double *  vecovlp20 ;

	double *  vecovlp21 ;

	double *  vecovlp22 ;

	double *  vecovlp23 ;

	double *  vecovlp24 ;

	double *  vecovlp25 ;

	double *  vecovlp26 ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp0_len ;

	long  vecovlp1_len ;

	long  vecovlp2_len ;

	long  vecovlp3_len ;

	long  vecovlp4_len ;

	long  vecovlp5_len ;

	long  vecovlp6_len ;

	long  vecovlp7_len ;

	long  vecovlp8_len ;

	long  vecovlp9_len ;

	long  vecovlp10_len ;

	long  vecovlp11_len ;

	long  vecovlp12_len ;

	long  vecovlp14_len ;

	long  vecovlp15_len ;

	long  vecovlp16_len ;

	long  vecovlp17_len ;

	long  vecovlp18_len ;

	long  vecovlp19_len ;

	long  vecovlp20_len ;

	long  vecovlp21_len ;

	long  vecovlp22_len ;

	long  vecovlp23_len ;

	long  vecovlp24_len ;

	long  vecovlp25_len ;

	long  vecovlp26_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_sync_ovlp_o2m_once_struct;
void  openmp_sync_ovlp_o2m_once_scmc_kernel (double *  vecmain ,double *  vecovlp0 ,double *  vecovlp1 ,double *  vecovlp2 ,double *  vecovlp3 ,double *  vecovlp4 ,double *  vecovlp5 ,double *  vecovlp6 ,double *  vecovlp7 ,double *  vecovlp8 ,double *  vecovlp9 ,double *  vecovlp10 ,double *  vecovlp11 ,double *  vecovlp12 ,double *  vecovlp14 ,double *  vecovlp15 ,double *  vecovlp16 ,double *  vecovlp17 ,double *  vecovlp18 ,double *  vecovlp19 ,double *  vecovlp20 ,double *  vecovlp21 ,double *  vecovlp22 ,double *  vecovlp23 ,double *  vecovlp24 ,double *  vecovlp25 ,double *  vecovlp26 ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlps ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlps_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_sync_ovlp_o2m_all_in_one_struct;
void  openmp_sync_ovlp_o2m_all_in_one_scmc_kernel (double *  vecmain ,double *  vecovlps ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  vecmain ;

	double *  vecovlp ;

	int *  ovlpindex ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  vecmain_len ;

	long  vecovlp_len ;

	long  ovlpindex_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_sync_ovlp_o2m_struct;
void  openmp_sync_ovlp_o2m_scmc_kernel (double *  vecmain ,double *  vecovlp ,int  ovlpindex ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );
typedef struct { 
	double *  inout ;

	long *  numvec ;

	int *  num_ele ;

	long *  xblock ;

	long *  yblock ;

	long *  zblock ;

	int *  ovlp ;

	long  inout_len ;

	long  numvec_len ;

	long  num_ele_len ;

	long  xblock_len ;

	long  yblock_len ;

	long  zblock_len ;

	long  ovlp_len ;

} openmp_yee_local_struct;
void  openmp_yee_local_scmc_kernel (double *  inout ,long  numvec ,int  num_ele ,long  xblock ,long  yblock ,long  zblock ,int  ovlp ,long  yid_kernel ,long  __ylen_kernel );

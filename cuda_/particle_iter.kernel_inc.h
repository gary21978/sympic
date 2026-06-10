typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_dump_ene_num_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_calculate_rho_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass0;

  cuda_pscmc_mem *Charge0;

  cuda_pscmc_mem *Deltat;

  cuda_pscmc_mem *mu_freq;

} cuda_krook_collision_test_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass0;

  cuda_pscmc_mem *Charge0;

  cuda_pscmc_mem *Deltat;

  cuda_pscmc_mem *mu_freq;

} cuda_krook_collision_remove_small_speed_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass0;

  cuda_pscmc_mem *Charge0;

  cuda_pscmc_mem *Deltat;

} cuda_boris_yee_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_E_particle_vlo_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_E_particle_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_vlo_sg2_nopush_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_vlo_sg2_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_vlo_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_sg2_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_vlo_nopush_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_vlo_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_nopush_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_z_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_vlo_sg2_nopush_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_vlo_sg2_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_vlo_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_sg2_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_vlo_nopush_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_vlo_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_nopush_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_y_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_vlo_sg2_nopush_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_vlo_sg2_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_vlo_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_sg2_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *LFoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_small_grids_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_vlo_nopush_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_vlo_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_nopush_struct;
typedef struct {
  cuda_pscmc_env *pe;

  cuda_pscmc_mem *inoutput;

  cuda_pscmc_mem *xyzw;

  cuda_pscmc_mem *cu_cache;

  cuda_pscmc_mem *cu_xyzw;

  cuda_pscmc_mem *fieldE;

  cuda_pscmc_mem *fieldB;

  cuda_pscmc_mem *FoutJ;

  cuda_pscmc_mem *FoutEN;

  cuda_pscmc_mem *XLEN;

  cuda_pscmc_mem *YLEN;

  cuda_pscmc_mem *ZLEN;

  cuda_pscmc_mem *ovlp;

  cuda_pscmc_mem *numvec;

  cuda_pscmc_mem *num_ele;

  cuda_pscmc_mem *grid_cache_len;

  cuda_pscmc_mem *cu_cache_length;

  cuda_pscmc_mem *Mass;

  cuda_pscmc_mem *Charge;

  cuda_pscmc_mem *SPEC;

  cuda_pscmc_mem *NUM_SPEC;

  cuda_pscmc_mem *DELTA_X;

  cuda_pscmc_mem *DELTA_Y;

  cuda_pscmc_mem *DELTA_Z;

  cuda_pscmc_mem *Deltat;

} cuda_split_pass_x_struct;

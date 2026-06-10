typedef struct {
  double *outEB;

  double *inEB;

  long *y_cpu_core;

  long *numvec;

  long *XLEN;

  long *YLEN;

  long *ZLEN;

  int *ovlp;

  long *xblock;

  long *yblock;

  long *zblock;

  int *num_ele;

  double *DT;

  long outEB_len;

  long inEB_len;

  long y_cpu_core_len;

  long numvec_len;

  long XLEN_len;

  long YLEN_len;

  long ZLEN_len;

  long ovlp_len;

  long xblock_len;

  long yblock_len;

  long zblock_len;

  long num_ele_len;

  long DT_len;

} c_Yee_FDTD_W04_2_struct;
void c_Yee_FDTD_W04_2_scmc_kernel(double *outEB, double *inEB, long y_cpu_core,
                                  long numvec, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long xblock, long yblock,
                                  long zblock, int num_ele, double DT,
                                  long yid_kernel, long __ylen_kernel);
typedef struct {
  double *outEB;

  double *inEB;

  long *y_cpu_core;

  long *numvec;

  long *XLEN;

  long *YLEN;

  long *ZLEN;

  int *ovlp;

  long *xblock;

  long *yblock;

  long *zblock;

  int *num_ele;

  double *DT;

  long outEB_len;

  long inEB_len;

  long y_cpu_core_len;

  long numvec_len;

  long XLEN_len;

  long YLEN_len;

  long ZLEN_len;

  long ovlp_len;

  long xblock_len;

  long yblock_len;

  long zblock_len;

  long num_ele_len;

  long DT_len;

} c_Yee_FDTD_W04_1_struct;
void c_Yee_FDTD_W04_1_scmc_kernel(double *outEB, double *inEB, long y_cpu_core,
                                  long numvec, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long xblock, long yblock,
                                  long zblock, int num_ele, double DT,
                                  long yid_kernel, long __ylen_kernel);
typedef struct {
  double *outEB;

  double *inEB;

  long *y_cpu_core;

  long *numvec;

  long *XLEN;

  long *YLEN;

  long *ZLEN;

  int *ovlp;

  long *xblock;

  long *yblock;

  long *zblock;

  int *num_ele;

  double *DT;

  long outEB_len;

  long inEB_len;

  long y_cpu_core_len;

  long numvec_len;

  long XLEN_len;

  long YLEN_len;

  long ZLEN_len;

  long ovlp_len;

  long xblock_len;

  long yblock_len;

  long zblock_len;

  long num_ele_len;

  long DT_len;

} c_Yee_FDTD_W04_0_struct;
void c_Yee_FDTD_W04_0_scmc_kernel(double *outEB, double *inEB, long y_cpu_core,
                                  long numvec, long XLEN, long YLEN, long ZLEN,
                                  int ovlp, long xblock, long yblock,
                                  long zblock, int num_ele, double DT,
                                  long yid_kernel, long __ylen_kernel);

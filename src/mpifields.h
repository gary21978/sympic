#include "pubdefs.h"

int set_Field3D_Seq(Field3D_Seq *pthis, void *pe, double delta_x, double delta_y, double delta_z, long xlen, long ylen,
                    long zlen, long numvec, int ovlp, int num_ele, int CD_type, long x_num_thread_block,
                    long y_num_thread_block, long z_num_thread_block, long global_pid);

#ifdef SYMPIC_CUDA
int cuda_alloc_Field3D_Seq(Field3D_Seq *pthis, int is_init_kernels);
int cuda_Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int cuda_Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int cuda_Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int cuda_Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int cuda_Field3D_Seq_YEE_CURL_R(Field3D_Seq *pthis, Field3D_Seq *inB0, double DT);
int cuda_Field3D_Seq_GEO_YEE_CURL_L(Field3D_Seq *pthis, Field3D_Seq *inB0, double x0, double DELTA_X, double DELTA_Y,
                                    double DELTA_Z, double DT);
#endif

#ifdef SYMPIC_MAPU
int mapu_alloc_Field3D_Seq(Field3D_Seq *pthis, int is_init_kernels);
int mapu_Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int mapu_Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int mapu_Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int mapu_Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int mapu_Field3D_Seq_YEE_CURL_R(Field3D_Seq *pthis, Field3D_Seq *inB0, double DT);
int mapu_Field3D_Seq_GEO_YEE_CURL_L(Field3D_Seq *pthis, Field3D_Seq *inB0, double x0, double DELTA_X, double DELTA_Y,
                                    double DELTA_Z, double DT);
#endif


int alloc_Field3D_Seq(Field3D_Seq *pthis, int is_init_kernels);
int Field3D_Seq_ovlp_merge_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int Field3D_Seq_ovlp_merge_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int Field3D_Seq_ovlp_sync_ovlp_m2o_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int Field3D_Seq_ovlp_sync_ovlp_o2m_all_in_one(Field3D_Seq *pthis, int is_sync_layer);
int Field3D_Seq_YEE_CURL_R(Field3D_Seq *pthis, Field3D_Seq *inB0, double DT);
int MPI_YEE_CURL_R(Field3D_MPI *pthis, Field3D_MPI *inB0, double DT);
int Field3D_Seq_GEO_YEE_CURL_L(Field3D_Seq *pthis, Field3D_Seq *inB0, double x0, double DELTA_X, double DELTA_Y,
                               double DELTA_Z, double DT);
int MPI_GEO_YEE_CURL_L(Field3D_MPI *pthis, Field3D_MPI *inB0, double x0, double DELTA_X, double DELTA_Y, double DELTA_Z,
                       double DT);

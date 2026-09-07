#include "basic.h"

#ifdef __cplusplus
extern "C"{
#endif

void init_seq(Field3D_Seq* x_ptr, Field3D_Seq* y_ptr, int rank, long long* len, int ovlp, int elenum, int vecnum);
void reinit_seq(Field3D_Seq* x_ptr, Field3D_Seq* y_ptr);
void reinity_seq(Field3D_Seq* y_ptr);
void reinit_enlargey_seq(Field3D_Seq* x_ptr, Field3D_Seq* y_ptr);
#ifdef __cplusplus
}
#endif
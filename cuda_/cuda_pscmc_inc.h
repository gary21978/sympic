#ifndef cuda_PSCMC_CUDA_INC

#define cuda_PSCMC_CUDA_INC
#include <assert.h>

#include <cuda_runtime.h>

#ifndef PSCMC_TYPES

#define PSCMC_TYPES

typedef enum {
  PS_INT_NUM,
  PS_LONG_NUM,
  PS_FLOAT_NUM,
  PS_DOUBLE_NUM,
  PS_CHAR,
  PS_SHORT_NUM
} pscmc_data_types;

#else

#endif

#define ERROPT(err, x)                                                         \
  {                                                                            \
    if (err != cudaSuccess) {                                                  \
      fprintf(stderr, "Error:%s\n%s\n", cudaGetErrorString(err), x);           \
      assert(0);                                                               \
    }                                                                          \
  }
typedef struct {
  int device_id;

  int num_dev;

} cuda_pscmc_env;
typedef struct {
  char *h_data;

  char *d_data;

  char *d_one_mem;

  int type;

  size_t len;

  cuda_pscmc_env *pe;

  int type_len;

} cuda_pscmc_mem;
int cuda_pscmc_env_init(cuda_pscmc_env *pe, int dev_num, void *fv);
int cuda_pscmc_mem_sync_d2h(cuda_pscmc_mem *pm);
int cuda_pscmc_mem_sync_h2d(cuda_pscmc_mem *pm);
void *cuda_pscmc_get_h_data(cuda_pscmc_mem *pm, void **h_data);
size_t cuda_pscmc_mem_get_num(cuda_pscmc_mem *pm);
int cuda_pscmc_mem_destroy(cuda_pscmc_mem *pm);
int cuda_pscmc_mem_init(cuda_pscmc_env *, cuda_pscmc_mem *pm, int type,
                        size_t len);

#else

#endif

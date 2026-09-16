#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <math.h>

#include <alloca.h>

#include "local_header.h"

#include <assert.h>

#include <cuda_runtime.h>

typedef enum { PS_INT_NUM, PS_LONG_NUM, PS_FLOAT_NUM, PS_DOUBLE_NUM, PS_CHAR, PS_SHORT_NUM };

#define ERROPT(err, x)                                                                                                 \
  {                                                                                                                    \
    if (err != cudaSuccess) {                                                                                          \
      fprintf(stderr, "Error:%s\n%s\n", cudaGetErrorString(err), x);                                                   \
      assert(0);                                                                                                       \
    }                                                                                                                  \
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
int cuda_pscmc_mem_init(cuda_pscmc_env *, cuda_pscmc_mem *pm, int type, size_t len);
void *cuda_pscmc_get_h_data(cuda_pscmc_mem *pm, void **h_data) {
  if (h_data != NULL) {
    ((h_data)[0] = pm->h_data);
  }

  return pm->h_data;
}
int cuda_pscmc_get_env_len(size_t *l) {
  ((l)[0] = sizeof(cuda_pscmc_env));
  return 0;
}
int cuda_pscmc_mem_init(cuda_pscmc_env *pe, cuda_pscmc_mem *pm, int type, size_t len) {
  cudaSetDevice((pe)->device_id);
  int err;


  (pm->len = len);
  (pm->pe = pe);
  if (len == 0) {
    (len = 1);
  }

  size_t datasize;

  if (type == PS_INT_NUM) {
    (datasize = (len * sizeof(int)));

  } else {
    if (type == PS_LONG_NUM) {
      (datasize = (len * sizeof(long)));

    } else {
      if (type == PS_FLOAT_NUM) {
        (datasize = (len * sizeof(float)));

      } else {
        if (type == PS_DOUBLE_NUM) {
          (datasize = (len * sizeof(double)));

        } else {
          if (type == PS_SHORT_NUM) {
            (datasize = (len * sizeof(short)));

          } else {
            if (type == PS_CHAR) {
              (datasize = (len * sizeof(char)));

            } else {
              fprintf(stderr, "Error: unknown type in init_pscmc_mem: type=%d\n", type);
              (datasize = len);
            }
          }
        }
      }
    }
  }

  (pm->type_len = (datasize / len));
  (pm->h_data = malloc(datasize));
  if (pm->len > 0) {
    cudaMalloc(&(pm->d_data), datasize);
    (err = cudaGetLastError());
    ERROPT(err, "Failed to alloc cuda memory");
  }

  return 0;
}
int cuda_pscmc_mem_destroy(cuda_pscmc_mem *pm) {
  cudaSetDevice((pm->pe)->device_id);
  free(pm->h_data);
  if (pm->len > 0) {
    cudaFree(pm->d_data);
  }

  return 0;
}
int cuda_pscmc_mem_sync_h2d(cuda_pscmc_mem *pm) {
  cudaSetDevice((pm->pe)->device_id);
  int err;


  if (pm->len > 0) {
    cudaMemcpy(pm->d_data, pm->h_data, (pm->len * pm->type_len), cudaMemcpyHostToDevice);
    (err = cudaGetLastError());
    ERROPT(err, "Failed to write to cuda memory");
  }

  return 0;
}
int cuda_pscmc_mem_sync_d2h(cuda_pscmc_mem *pm) {
  int err;


  cudaSetDevice((pm->pe)->device_id);
  if (pm->len > 0) {
    cudaMemcpy(pm->h_data, pm->d_data, (pm->len * pm->type_len), cudaMemcpyDeviceToHost);
    (err = cudaGetLastError());
    ERROPT(err, "Failed to write to host memory");
  }

  return 0;
}
int cuda_pscmc_env_init(cuda_pscmc_env *pe, int dev_num, void *fv) {
  int err;


  cudaSetDevice(dev_num);
  (pe->device_id = dev_num);
  (err = cudaGetLastError());
  ERROPT(err, "failed to set the device");
  return 0;
}

#pragma once

typedef enum
{
	PS_INT_NUM,
	PS_LONG_NUM,
	PS_FLOAT_NUM,
	PS_DOUBLE_NUM,
	PS_CHAR,
	PS_SHORT_NUM
} pscmc_data_types;


#define ERROPT(err, x)                                                     \
	{                                                                      \
		if (err != cudaSuccess)                                            \
		{                                                                  \
			fprintf(stderr, "Error:%s\n%s\n", cudaGetErrorString(err), x); \
			assert(0);                                                     \
		}                                                                  \
	}
typedef struct
{
	int device_id;
	int num_dev;
} mapu_pscmc_env;
typedef struct
{
	char *h_data;
	char *d_data;
	char *d_one_mem;
	int type;
	size_t len;
	mapu_pscmc_env *pe;
	int type_len;
} mapu_pscmc_mem;


#ifdef __cplusplus
extern "C" {
#endif

int mapu_pscmc_mem_sync_d2h(mapu_pscmc_mem *pm);
int mapu_pscmc_mem_sync_h2d(mapu_pscmc_mem *pm);
void *mapu_pscmc_get_h_data(mapu_pscmc_mem *pm, void **h_data);
size_t mapu_pscmc_mem_get_num(mapu_pscmc_mem *pm);
int mapu_pscmc_mem_destroy(mapu_pscmc_mem *pm);
int mapu_pscmc_mem_init(mapu_pscmc_env *, mapu_pscmc_mem *pm, int type, size_t len);
int mapu_pscmc_get_local_len();
int mapu_pscmc_get_env_len(size_t *l);
int mapu_pscmc_flush(mapu_pscmc_env *pe);
int mapu_pscmc_mem_init(mapu_pscmc_env *pe, mapu_pscmc_mem *pm, int type, size_t len);
int mapu_pscmc_env_init(mapu_pscmc_env *pe, int dev_num, void *fv);

#ifdef __cplusplus
}
#endif

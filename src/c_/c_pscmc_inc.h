
#ifndef c_PSCMC_C_INC

#define c_PSCMC_C_INC

#ifndef PSCMC_TYPES

#define PSCMC_TYPES

typedef enum
{
	PS_INT_NUM,
	PS_LONG_NUM,
	PS_FLOAT_NUM,
	PS_DOUBLE_NUM,
	PS_CHAR,
	PS_SHORT_NUM
} pscmc_data_types;

#else

#endif
typedef struct
{
	int num_threads;
} c_pscmc_env;
typedef struct
{
	char *d_data;
	char *h_data;
	int type;
	size_t len;
} c_pscmc_mem;
int c_pscmc_env_init(c_pscmc_env *pe, int dev_num, void *fv);
int c_pscmc_mem_sync_d2h(c_pscmc_mem *pm);
int c_pscmc_mem_sync_h2d(c_pscmc_mem *pm);
void *c_pscmc_get_h_data(c_pscmc_mem *pm, void **h_data);
size_t c_pscmc_mem_get_num(c_pscmc_mem *pm);
int c_pscmc_mem_destroy(c_pscmc_mem *pm);
int c_pscmc_mem_init(c_pscmc_env *, c_pscmc_mem *pm, int type, size_t len);

#else

#endif

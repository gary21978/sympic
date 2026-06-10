	#ifndef   openmp_PSCMC_OMP_INC    
		
#define openmp_PSCMC_OMP_INC
	#ifndef   PSCMC_TYPES    
		
#define PSCMC_TYPES

typedef enum {PS_INT_NUM,PS_LONG_NUM,PS_FLOAT_NUM,PS_DOUBLE_NUM,PS_CHAR,PS_SHORT_NUM} pscmc_data_types;

	#else
		
	 #endif

typedef struct { 
	int  num_threads ;

} openmp_pscmc_env;
typedef struct { 
	char *  d_data ;

	char *  h_data ;

	int  type ;

	size_t  len ;

} openmp_pscmc_mem;
int  openmp_pscmc_env_init (openmp_pscmc_env *  pe ,int  dev_num ,void *  fv );
int  openmp_pscmc_mem_sync_d2h (openmp_pscmc_mem *  pm );
int  openmp_pscmc_mem_sync_h2d (openmp_pscmc_mem *  pm );
void *  openmp_pscmc_get_h_data (openmp_pscmc_mem *  pm ,void * *  h_data );
size_t  openmp_pscmc_mem_get_num (openmp_pscmc_mem *  pm );
int  openmp_pscmc_mem_destroy (openmp_pscmc_mem *  pm );
int  openmp_pscmc_mem_init (openmp_pscmc_env  * ,openmp_pscmc_mem *  pm ,int  type ,size_t  len );

	#else
		
	 #endif


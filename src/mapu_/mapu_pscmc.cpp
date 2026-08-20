#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <alloca.h>
#include <maps_runtime.h>
#include "mapu_pscmc.h"


extern "C"
{

	long _pscmc_mapu_global_dump_kernel_variables = 0;

	long _pscmc_mapu_global_dump_times = 0;

	int mapu_pscmc_get_local_len()
	{
		return 1;
	}
	void *mapu_pscmc_get_h_data(mapu_pscmc_mem *pm, void **h_data)
	{
		if ((h_data != NULL))
		{
			h_data[0] = pm->h_data;
		}
		return pm->h_data;
	}
	int mapu_pscmc_get_env_len(size_t *l)
	{
		l[0] = sizeof(mapu_pscmc_env);
		return 0;
	}
	int mapu_pscmc_flush(mapu_pscmc_env *pe)
	{
		mapsDeviceSynchronize();
		return 0;
	}
	int mapu_pscmc_mem_init(mapu_pscmc_env *pe, mapu_pscmc_mem *pm, int type, size_t len)
	{
		mapsSetDevice((pe)->device_id);
		int err;
		int *perr = &(err);
		(pm->len = len);
		(pm->pe = pe);

		if (len == 0)
		{
			len = 1;
		}
		
		size_t datasize;

		if ((type == PS_INT_NUM))
		{
			datasize = len * sizeof(int);
		}
		else
		{
			if (type == PS_LONG_NUM)
			{
				(datasize = (len * sizeof(long)));
			}
			else
			{

				if (type == PS_FLOAT_NUM)
				{
					datasize = len * sizeof(float);
				}
				else
				{

					if (type == PS_DOUBLE_NUM)
					{
						datasize = len * sizeof(double);
					}
					else
					{

						if (type == PS_SHORT_NUM)
						{
							datasize = len * sizeof(short);
						}
						else
						{

							if (type == PS_CHAR)
							{
								datasize = len * sizeof(char);
							}
							else
							{
								fprintf(stderr, "Error: unknown type in init_pscmc_mem: type=%d\n", type);
								(datasize = len);
							}
						}
					}
				}
			}
		}
		pm->type_len = datasize / len;
		pm->h_data = (char *)malloc(datasize);

		if ((pm->len > 0))
		{
			mapsMalloc(((void **)&(pm->d_data)), datasize);
		}
		
		return 0;
	}
	int mapu_pscmc_mem_destroy(mapu_pscmc_mem *pm)
	{
		mapsSetDevice((pm->pe)->device_id);
		free(pm->h_data);

		if (pm->len > 0)
		{
			mapsFree(pm->d_data);
		}
		
		return 0;
	}
	int mapu_pscmc_mem_sync_h2d(mapu_pscmc_mem *pm)
	{
		mapsSetDevice((pm->pe)->device_id);
		int err;
		int *perr = &(err);

		if (pm->len > 0)
		{
			mapsMemcpy(pm->d_data, pm->h_data, (pm->len * pm->type_len), mapsMemcpyHostToDevice);
		}
		
		return 0;
	}
	int mapu_pscmc_mem_sync_d2h(mapu_pscmc_mem *pm)
	{
		int err;
		int *perr = &(err);
		mapsSetDevice((pm->pe)->device_id);

		if ((pm->len > 0))
		{
			{
				mapsMemcpy(pm->h_data, pm->d_data, (pm->len * pm->type_len), mapsMemcpyDeviceToHost);
			}
		}
		
		return 0;
	}
	int mapu_pscmc_env_init(mapu_pscmc_env *pe, int dev_num, void *fv)
	{
		int err;
		int *perr = &(err);
		mapsSetDevice(dev_num);
		(pe->device_id = dev_num);
		return 0;
	}
	size_t mapu_pscmc_mem_get_num(mapu_pscmc_mem *pm)
	{
		return pm->len;
	}
}

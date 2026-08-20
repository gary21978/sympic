#include <stdio.h>
#include <stdlib.h>
#include "local_header.h"
#include "c_pscmc_inc.h"
#include "mergefields.kernel_inc.h"
static int dump_kernel_variables = 0;

extern long _pscmc_c_global_dump_kernel_variables, _pscmc_c_global_dump_times;
int c_merge_ovlp_m2o_once_init(c_pscmc_env *pe, c_merge_ovlp_m2o_once_struct *kerstr)
{
	return 0;
}
void c_merge_ovlp_m2o_once_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_merge_ovlp_m2o_once_struct));
}
int c_merge_ovlp_m2o_once_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_merge_ovlp_m2o_once_get_num_compute_units(c_merge_ovlp_m2o_once_struct *kerstr)
{
	return 1;
}
int c_merge_ovlp_m2o_once_exec(c_merge_ovlp_m2o_once_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp0_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp0_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp1_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp1_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp2_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp2_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp3_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp3_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp4_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp4_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp5_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp5_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp6_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp6_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp7_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp7_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp8_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp8_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp9_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp9_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp10_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp10_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp11_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp11_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp12_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp12_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp14_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp14_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp15_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp15_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp16_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp16_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp17_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp17_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp18_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp18_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp19_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp19_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp20_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp20_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp21_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp21_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp22_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp22_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp23_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp23_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp24_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp24_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp25_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp25_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp26_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp26_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_merge_ovlp_m2o_once_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1, (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4, (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7, (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10, (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14, (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17, (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20, (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23, (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp0_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp0_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp1_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp1_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp2_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp2_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp3_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp3_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp4_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp4_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp5_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp5_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp6_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp6_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp7_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp7_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp8_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp8_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp9_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp9_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp10_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp10_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp11_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp11_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp12_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp12_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp14_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp14_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp15_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp15_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp16_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp16_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp17_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp17_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp18_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp18_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp19_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp19_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp20_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp20_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp21_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp21_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp22_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp22_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp23_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp23_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp24_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp24_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp25_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp25_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_vecovlp26_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp26_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_once_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecmain(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp0(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp0 = pm->d_data);
	((kerstr)->vecovlp0_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp1(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp1 = pm->d_data);
	((kerstr)->vecovlp1_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp2(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp2 = pm->d_data);
	((kerstr)->vecovlp2_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp3(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp3 = pm->d_data);
	((kerstr)->vecovlp3_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp4(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp4 = pm->d_data);
	((kerstr)->vecovlp4_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp5(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp5 = pm->d_data);
	((kerstr)->vecovlp5_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp6(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp6 = pm->d_data);
	((kerstr)->vecovlp6_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp7(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp7 = pm->d_data);
	((kerstr)->vecovlp7_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp8(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp8 = pm->d_data);
	((kerstr)->vecovlp8_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp9(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp9 = pm->d_data);
	((kerstr)->vecovlp9_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp10(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp10 = pm->d_data);
	((kerstr)->vecovlp10_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp11(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp11 = pm->d_data);
	((kerstr)->vecovlp11_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp12(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp12 = pm->d_data);
	((kerstr)->vecovlp12_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp14(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp14 = pm->d_data);
	((kerstr)->vecovlp14_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp15(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp15 = pm->d_data);
	((kerstr)->vecovlp15_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp16(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp16 = pm->d_data);
	((kerstr)->vecovlp16_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp17(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp17 = pm->d_data);
	((kerstr)->vecovlp17_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp18(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp18 = pm->d_data);
	((kerstr)->vecovlp18_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp19(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp19 = pm->d_data);
	((kerstr)->vecovlp19_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp20(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp20 = pm->d_data);
	((kerstr)->vecovlp20_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp21(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp21 = pm->d_data);
	((kerstr)->vecovlp21_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp22(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp22 = pm->d_data);
	((kerstr)->vecovlp22_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp23(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp23 = pm->d_data);
	((kerstr)->vecovlp23_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp24(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp24 = pm->d_data);
	((kerstr)->vecovlp24_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp25(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp25 = pm->d_data);
	((kerstr)->vecovlp25_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_vecovlp26(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp26 = pm->d_data);
	((kerstr)->vecovlp26_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_numvec(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_num_ele(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_xblock(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_yblock(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_zblock(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_merge_ovlp_m2o_once_scmc_set_parameter_ovlp(c_merge_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_init(c_pscmc_env *pe, c_merge_ovlp_m2o_all_in_one_struct *kerstr)
{
	return 0;
}
void c_merge_ovlp_m2o_all_in_one_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_merge_ovlp_m2o_all_in_one_struct));
}
int c_merge_ovlp_m2o_all_in_one_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_merge_ovlp_m2o_all_in_one_get_num_compute_units(c_merge_ovlp_m2o_all_in_one_struct *kerstr)
{
	return 1;
}
int c_merge_ovlp_m2o_all_in_one_exec(c_merge_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_vecovlps_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlps_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_merge_ovlp_m2o_all_in_one_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_vecovlps_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlps_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_all_in_one_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlps = pm->d_data);
	((kerstr)->vecovlps_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_merge_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(c_merge_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_merge_ovlp_m2o_init(c_pscmc_env *pe, c_merge_ovlp_m2o_struct *kerstr)
{
	return 0;
}
void c_merge_ovlp_m2o_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_merge_ovlp_m2o_struct));
}
int c_merge_ovlp_m2o_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_merge_ovlp_m2o_get_num_compute_units(c_merge_ovlp_m2o_struct *kerstr)
{
	return 1;
}
int c_merge_ovlp_m2o_exec(c_merge_ovlp_m2o_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_vecovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_ovlpindex_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlpindex_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_merge_ovlp_m2o_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0], ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_vecovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_ovlpindex_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlpindex_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_m2o_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_merge_ovlp_m2o_scmc_set_parameter_vecmain(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_vecovlp(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp = pm->d_data);
	((kerstr)->vecovlp_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_ovlpindex(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlpindex = pm->d_data);
	((kerstr)->ovlpindex_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_numvec(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_num_ele(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_xblock(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_yblock(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_zblock(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_merge_ovlp_m2o_scmc_set_parameter_ovlp(c_merge_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_merge_ovlp_o2m_once_init(c_pscmc_env *pe, c_merge_ovlp_o2m_once_struct *kerstr)
{
	return 0;
}
void c_merge_ovlp_o2m_once_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_merge_ovlp_o2m_once_struct));
}
int c_merge_ovlp_o2m_once_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_merge_ovlp_o2m_once_get_num_compute_units(c_merge_ovlp_o2m_once_struct *kerstr)
{
	return 1;
}
int c_merge_ovlp_o2m_once_exec(c_merge_ovlp_o2m_once_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp0_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp0_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp1_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp1_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp2_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp2_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp3_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp3_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp4_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp4_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp5_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp5_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp6_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp6_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp7_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp7_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp8_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp8_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp9_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp9_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp10_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp10_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp11_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp11_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp12_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp12_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp14_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp14_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp15_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp15_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp16_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp16_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp17_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp17_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp18_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp18_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp19_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp19_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp20_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp20_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp21_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp21_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp22_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp22_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp23_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp23_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp24_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp24_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp25_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp25_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp26_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp26_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_merge_ovlp_o2m_once_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1, (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4, (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7, (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10, (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14, (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17, (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20, (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23, (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp0_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp0_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp1_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp1_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp2_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp2_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp3_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp3_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp4_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp4_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp5_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp5_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp6_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp6_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp7_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp7_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp8_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp8_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp9_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp9_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp10_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp10_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp11_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp11_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp12_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp12_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp14_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp14_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp15_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp15_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp16_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp16_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp17_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp17_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp18_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp18_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp19_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp19_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp20_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp20_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp21_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp21_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp22_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp22_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp23_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp23_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp24_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp24_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp25_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp25_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_vecovlp26_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp26_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_once_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecmain(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp0(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp0 = pm->d_data);
	((kerstr)->vecovlp0_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp1(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp1 = pm->d_data);
	((kerstr)->vecovlp1_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp2(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp2 = pm->d_data);
	((kerstr)->vecovlp2_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp3(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp3 = pm->d_data);
	((kerstr)->vecovlp3_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp4(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp4 = pm->d_data);
	((kerstr)->vecovlp4_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp5(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp5 = pm->d_data);
	((kerstr)->vecovlp5_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp6(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp6 = pm->d_data);
	((kerstr)->vecovlp6_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp7(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp7 = pm->d_data);
	((kerstr)->vecovlp7_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp8(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp8 = pm->d_data);
	((kerstr)->vecovlp8_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp9(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp9 = pm->d_data);
	((kerstr)->vecovlp9_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp10(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp10 = pm->d_data);
	((kerstr)->vecovlp10_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp11(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp11 = pm->d_data);
	((kerstr)->vecovlp11_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp12(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp12 = pm->d_data);
	((kerstr)->vecovlp12_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp14(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp14 = pm->d_data);
	((kerstr)->vecovlp14_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp15(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp15 = pm->d_data);
	((kerstr)->vecovlp15_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp16(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp16 = pm->d_data);
	((kerstr)->vecovlp16_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp17(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp17 = pm->d_data);
	((kerstr)->vecovlp17_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp18(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp18 = pm->d_data);
	((kerstr)->vecovlp18_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp19(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp19 = pm->d_data);
	((kerstr)->vecovlp19_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp20(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp20 = pm->d_data);
	((kerstr)->vecovlp20_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp21(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp21 = pm->d_data);
	((kerstr)->vecovlp21_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp22(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp22 = pm->d_data);
	((kerstr)->vecovlp22_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp23(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp23 = pm->d_data);
	((kerstr)->vecovlp23_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp24(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp24 = pm->d_data);
	((kerstr)->vecovlp24_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp25(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp25 = pm->d_data);
	((kerstr)->vecovlp25_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_vecovlp26(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp26 = pm->d_data);
	((kerstr)->vecovlp26_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_numvec(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_num_ele(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_xblock(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_yblock(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_zblock(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_merge_ovlp_o2m_once_scmc_set_parameter_ovlp(c_merge_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_init(c_pscmc_env *pe, c_merge_ovlp_o2m_all_in_one_struct *kerstr)
{
	return 0;
}
void c_merge_ovlp_o2m_all_in_one_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_merge_ovlp_o2m_all_in_one_struct));
}
int c_merge_ovlp_o2m_all_in_one_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_merge_ovlp_o2m_all_in_one_get_num_compute_units(c_merge_ovlp_o2m_all_in_one_struct *kerstr)
{
	return 1;
}
int c_merge_ovlp_o2m_all_in_one_exec(c_merge_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_vecovlps_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlps_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_merge_ovlp_o2m_all_in_one_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_vecovlps_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlps_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_all_in_one_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlps = pm->d_data);
	((kerstr)->vecovlps_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_merge_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(c_merge_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_merge_ovlp_o2m_init(c_pscmc_env *pe, c_merge_ovlp_o2m_struct *kerstr)
{
	return 0;
}
void c_merge_ovlp_o2m_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_merge_ovlp_o2m_struct));
}
int c_merge_ovlp_o2m_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_merge_ovlp_o2m_get_num_compute_units(c_merge_ovlp_o2m_struct *kerstr)
{
	return 1;
}
int c_merge_ovlp_o2m_exec(c_merge_ovlp_o2m_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_vecovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_ovlpindex_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlpindex_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_merge_ovlp_o2m_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0], ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_vecovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_ovlpindex_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlpindex_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_merge_ovlp_o2m_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_merge_ovlp_o2m_scmc_set_parameter_vecmain(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_vecovlp(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp = pm->d_data);
	((kerstr)->vecovlp_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_ovlpindex(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlpindex = pm->d_data);
	((kerstr)->ovlpindex_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_numvec(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_num_ele(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_xblock(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_yblock(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_zblock(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_merge_ovlp_o2m_scmc_set_parameter_ovlp(c_merge_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_sync_ovlp_m2o_once_init(c_pscmc_env *pe, c_sync_ovlp_m2o_once_struct *kerstr)
{
	return 0;
}
void c_sync_ovlp_m2o_once_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_sync_ovlp_m2o_once_struct));
}
int c_sync_ovlp_m2o_once_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_sync_ovlp_m2o_once_get_num_compute_units(c_sync_ovlp_m2o_once_struct *kerstr)
{
	return 1;
}
int c_sync_ovlp_m2o_once_exec(c_sync_ovlp_m2o_once_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp0_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp0_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp1_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp1_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp2_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp2_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp3_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp3_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp4_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp4_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp5_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp5_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp6_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp6_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp7_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp7_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp8_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp8_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp9_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp9_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp10_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp10_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp11_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp11_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp12_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp12_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp14_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp14_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp15_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp15_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp16_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp16_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp17_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp17_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp18_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp18_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp19_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp19_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp20_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp20_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp21_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp21_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp22_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp22_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp23_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp23_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp24_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp24_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp25_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp25_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp26_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp26_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_sync_ovlp_m2o_once_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1, (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4, (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7, (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10, (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14, (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17, (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20, (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23, (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp0_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp0_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp1_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp1_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp2_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp2_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp3_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp3_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp4_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp4_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp5_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp5_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp6_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp6_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp7_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp7_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp8_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp8_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp9_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp9_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp10_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp10_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp11_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp11_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp12_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp12_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp14_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp14_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp15_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp15_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp16_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp16_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp17_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp17_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp18_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp18_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp19_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp19_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp20_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp20_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp21_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp21_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp22_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp22_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp23_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp23_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp24_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp24_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp25_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp25_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_vecovlp26_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp26_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_once_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecmain(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp0(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp0 = pm->d_data);
	((kerstr)->vecovlp0_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp1(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp1 = pm->d_data);
	((kerstr)->vecovlp1_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp2(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp2 = pm->d_data);
	((kerstr)->vecovlp2_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp3(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp3 = pm->d_data);
	((kerstr)->vecovlp3_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp4(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp4 = pm->d_data);
	((kerstr)->vecovlp4_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp5(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp5 = pm->d_data);
	((kerstr)->vecovlp5_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp6(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp6 = pm->d_data);
	((kerstr)->vecovlp6_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp7(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp7 = pm->d_data);
	((kerstr)->vecovlp7_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp8(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp8 = pm->d_data);
	((kerstr)->vecovlp8_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp9(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp9 = pm->d_data);
	((kerstr)->vecovlp9_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp10(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp10 = pm->d_data);
	((kerstr)->vecovlp10_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp11(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp11 = pm->d_data);
	((kerstr)->vecovlp11_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp12(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp12 = pm->d_data);
	((kerstr)->vecovlp12_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp14(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp14 = pm->d_data);
	((kerstr)->vecovlp14_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp15(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp15 = pm->d_data);
	((kerstr)->vecovlp15_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp16(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp16 = pm->d_data);
	((kerstr)->vecovlp16_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp17(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp17 = pm->d_data);
	((kerstr)->vecovlp17_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp18(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp18 = pm->d_data);
	((kerstr)->vecovlp18_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp19(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp19 = pm->d_data);
	((kerstr)->vecovlp19_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp20(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp20 = pm->d_data);
	((kerstr)->vecovlp20_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp21(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp21 = pm->d_data);
	((kerstr)->vecovlp21_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp22(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp22 = pm->d_data);
	((kerstr)->vecovlp22_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp23(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp23 = pm->d_data);
	((kerstr)->vecovlp23_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp24(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp24 = pm->d_data);
	((kerstr)->vecovlp24_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp25(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp25 = pm->d_data);
	((kerstr)->vecovlp25_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_vecovlp26(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp26 = pm->d_data);
	((kerstr)->vecovlp26_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_numvec(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_num_ele(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_xblock(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_yblock(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_zblock(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_sync_ovlp_m2o_once_scmc_set_parameter_ovlp(c_sync_ovlp_m2o_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_init(c_pscmc_env *pe, c_sync_ovlp_m2o_all_in_one_struct *kerstr)
{
	return 0;
}
void c_sync_ovlp_m2o_all_in_one_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_sync_ovlp_m2o_all_in_one_struct));
}
int c_sync_ovlp_m2o_all_in_one_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_sync_ovlp_m2o_all_in_one_get_num_compute_units(c_sync_ovlp_m2o_all_in_one_struct *kerstr)
{
	return 1;
}
int c_sync_ovlp_m2o_all_in_one_exec(c_sync_ovlp_m2o_all_in_one_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_vecovlps_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlps_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_sync_ovlp_m2o_all_in_one_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_vecovlps_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlps_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_all_in_one_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecmain(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_vecovlps(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlps = pm->d_data);
	((kerstr)->vecovlps_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_numvec(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_num_ele(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_xblock(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_yblock(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_zblock(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_sync_ovlp_m2o_all_in_one_scmc_set_parameter_ovlp(c_sync_ovlp_m2o_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_sync_ovlp_m2o_init(c_pscmc_env *pe, c_sync_ovlp_m2o_struct *kerstr)
{
	return 0;
}
void c_sync_ovlp_m2o_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_sync_ovlp_m2o_struct));
}
int c_sync_ovlp_m2o_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_sync_ovlp_m2o_get_num_compute_units(c_sync_ovlp_m2o_struct *kerstr)
{
	return 1;
}
int c_sync_ovlp_m2o_exec(c_sync_ovlp_m2o_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_vecovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_ovlpindex_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlpindex_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_sync_ovlp_m2o_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0], ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_vecovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_ovlpindex_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlpindex_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_m2o_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_sync_ovlp_m2o_scmc_set_parameter_vecmain(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_vecovlp(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp = pm->d_data);
	((kerstr)->vecovlp_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_ovlpindex(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlpindex = pm->d_data);
	((kerstr)->ovlpindex_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_numvec(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_num_ele(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_xblock(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_yblock(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_zblock(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_sync_ovlp_m2o_scmc_set_parameter_ovlp(c_sync_ovlp_m2o_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_sync_ovlp_o2m_once_init(c_pscmc_env *pe, c_sync_ovlp_o2m_once_struct *kerstr)
{
	return 0;
}
void c_sync_ovlp_o2m_once_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_sync_ovlp_o2m_once_struct));
}
int c_sync_ovlp_o2m_once_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_sync_ovlp_o2m_once_get_num_compute_units(c_sync_ovlp_o2m_once_struct *kerstr)
{
	return 1;
}
int c_sync_ovlp_o2m_once_exec(c_sync_ovlp_o2m_once_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp0_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp0_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp1_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp1_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp2_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp2_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp3_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp3_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp4_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp4_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp5_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp5_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp6_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp6_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp7_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp7_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp8_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp8_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp9_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp9_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp10_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp10_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp11_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp11_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp12_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp12_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp14_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp14_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp15_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp15_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp16_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp16_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp17_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp17_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp18_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp18_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp19_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp19_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp20_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp20_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp21_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp21_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp22_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp22_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp23_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp23_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp24_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp24_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp25_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp25_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp26_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp26_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_sync_ovlp_o2m_once_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp0, (kerstr)->vecovlp1, (kerstr)->vecovlp2, (kerstr)->vecovlp3, (kerstr)->vecovlp4, (kerstr)->vecovlp5, (kerstr)->vecovlp6, (kerstr)->vecovlp7, (kerstr)->vecovlp8, (kerstr)->vecovlp9, (kerstr)->vecovlp10, (kerstr)->vecovlp11, (kerstr)->vecovlp12, (kerstr)->vecovlp14, (kerstr)->vecovlp15, (kerstr)->vecovlp16, (kerstr)->vecovlp17, (kerstr)->vecovlp18, (kerstr)->vecovlp19, (kerstr)->vecovlp20, (kerstr)->vecovlp21, (kerstr)->vecovlp22, (kerstr)->vecovlp23, (kerstr)->vecovlp24, (kerstr)->vecovlp25, (kerstr)->vecovlp26, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp0_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp0_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp0, write_len, sizeof((kerstr->vecovlp0)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp1_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp1_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp1, write_len, sizeof((kerstr->vecovlp1)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp2_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp2_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp2, write_len, sizeof((kerstr->vecovlp2)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp3_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp3_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp3, write_len, sizeof((kerstr->vecovlp3)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp4_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp4_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp4, write_len, sizeof((kerstr->vecovlp4)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp5_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp5_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp5, write_len, sizeof((kerstr->vecovlp5)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp6_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp6_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp6, write_len, sizeof((kerstr->vecovlp6)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp7_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp7_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp7, write_len, sizeof((kerstr->vecovlp7)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp8_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp8_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp8, write_len, sizeof((kerstr->vecovlp8)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp9_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp9_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp9, write_len, sizeof((kerstr->vecovlp9)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp10_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp10_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp10, write_len, sizeof((kerstr->vecovlp10)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp11_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp11_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp11, write_len, sizeof((kerstr->vecovlp11)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp12_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp12_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp12, write_len, sizeof((kerstr->vecovlp12)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp14_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp14_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp14, write_len, sizeof((kerstr->vecovlp14)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp15_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp15_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp15, write_len, sizeof((kerstr->vecovlp15)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp16_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp16_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp16, write_len, sizeof((kerstr->vecovlp16)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp17_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp17_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp17, write_len, sizeof((kerstr->vecovlp17)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp18_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp18_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp18, write_len, sizeof((kerstr->vecovlp18)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp19_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp19_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp19, write_len, sizeof((kerstr->vecovlp19)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp20_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp20_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp20, write_len, sizeof((kerstr->vecovlp20)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp21_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp21_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp21, write_len, sizeof((kerstr->vecovlp21)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp22_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp22_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp22, write_len, sizeof((kerstr->vecovlp22)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp23_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp23_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp23, write_len, sizeof((kerstr->vecovlp23)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp24_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp24_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp24, write_len, sizeof((kerstr->vecovlp24)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp25_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp25_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp25, write_len, sizeof((kerstr->vecovlp25)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_vecovlp26_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp26_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp26, write_len, sizeof((kerstr->vecovlp26)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_once_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecmain(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp0(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp0 = pm->d_data);
	((kerstr)->vecovlp0_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp1(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp1 = pm->d_data);
	((kerstr)->vecovlp1_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp2(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp2 = pm->d_data);
	((kerstr)->vecovlp2_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp3(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp3 = pm->d_data);
	((kerstr)->vecovlp3_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp4(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp4 = pm->d_data);
	((kerstr)->vecovlp4_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp5(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp5 = pm->d_data);
	((kerstr)->vecovlp5_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp6(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp6 = pm->d_data);
	((kerstr)->vecovlp6_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp7(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp7 = pm->d_data);
	((kerstr)->vecovlp7_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp8(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp8 = pm->d_data);
	((kerstr)->vecovlp8_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp9(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp9 = pm->d_data);
	((kerstr)->vecovlp9_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp10(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp10 = pm->d_data);
	((kerstr)->vecovlp10_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp11(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp11 = pm->d_data);
	((kerstr)->vecovlp11_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp12(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp12 = pm->d_data);
	((kerstr)->vecovlp12_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp14(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp14 = pm->d_data);
	((kerstr)->vecovlp14_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp15(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp15 = pm->d_data);
	((kerstr)->vecovlp15_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp16(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp16 = pm->d_data);
	((kerstr)->vecovlp16_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp17(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp17 = pm->d_data);
	((kerstr)->vecovlp17_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp18(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp18 = pm->d_data);
	((kerstr)->vecovlp18_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp19(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp19 = pm->d_data);
	((kerstr)->vecovlp19_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp20(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp20 = pm->d_data);
	((kerstr)->vecovlp20_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp21(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp21 = pm->d_data);
	((kerstr)->vecovlp21_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp22(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp22 = pm->d_data);
	((kerstr)->vecovlp22_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp23(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp23 = pm->d_data);
	((kerstr)->vecovlp23_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp24(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp24 = pm->d_data);
	((kerstr)->vecovlp24_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp25(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp25 = pm->d_data);
	((kerstr)->vecovlp25_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_vecovlp26(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp26 = pm->d_data);
	((kerstr)->vecovlp26_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_numvec(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_num_ele(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_xblock(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_yblock(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_zblock(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_sync_ovlp_o2m_once_scmc_set_parameter_ovlp(c_sync_ovlp_o2m_once_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_init(c_pscmc_env *pe, c_sync_ovlp_o2m_all_in_one_struct *kerstr)
{
	return 0;
}
void c_sync_ovlp_o2m_all_in_one_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_sync_ovlp_o2m_all_in_one_struct));
}
int c_sync_ovlp_o2m_all_in_one_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_sync_ovlp_o2m_all_in_one_get_num_compute_units(c_sync_ovlp_o2m_all_in_one_struct *kerstr)
{
	return 1;
}
int c_sync_ovlp_o2m_all_in_one_exec(c_sync_ovlp_o2m_all_in_one_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_vecovlps_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlps_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_sync_ovlp_o2m_all_in_one_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlps, ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_vecovlps_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlps_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlps, write_len, sizeof((kerstr->vecovlps)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_all_in_one_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecmain(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_vecovlps(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlps = pm->d_data);
	((kerstr)->vecovlps_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_numvec(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_num_ele(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_xblock(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_yblock(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_zblock(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_sync_ovlp_o2m_all_in_one_scmc_set_parameter_ovlp(c_sync_ovlp_o2m_all_in_one_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}
int c_sync_ovlp_o2m_init(c_pscmc_env *pe, c_sync_ovlp_o2m_struct *kerstr)
{
	return 0;
}
void c_sync_ovlp_o2m_get_struct_len(size_t *len)
{
	((len)[0] = sizeof(c_sync_ovlp_o2m_struct));
}
int c_sync_ovlp_o2m_get_xlen()
{
	return IDX_OPT_MAX;
}
int c_sync_ovlp_o2m_get_num_compute_units(c_sync_ovlp_o2m_struct *kerstr)
{
	return 1;
}
int c_sync_ovlp_o2m_exec(c_sync_ovlp_o2m_struct *kerstr, long scmc_internal_g_xlen, long scmc_internal_g_ylen)
{
	{

		if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
		{
			{
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_vecmain_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecmain_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_vecovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->vecovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_ovlpindex_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlpindex_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_numvec_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->numvec_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_num_ele_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->num_ele_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_xblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->xblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_yblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->yblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_zblock_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->zblock_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
					fclose(fp);
				}
				{
					char fname[256];
					snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_ovlp_before_exec", _pscmc_c_global_dump_times);
					FILE *fp = fopen(fname, "wb");
					size_t write_len = kerstr->ovlp_len;

					if ((write_len <= 0))
					{
						{
							(write_len = 1);
						}
					}
					else
					{
						{
							0;
						}
					}
					fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
					fclose(fp);
				}
			}
		}
		else
		{
			{
				0;
			}
		}
		int yid;
		int numt = 1;
		int tid = 0;
		int ysingle = ((scmc_internal_g_ylen + (numt - 1)) / numt);
		int ymin = (tid * ysingle);
		int ymax = ((1 + tid) * ysingle);
		for ((yid = ymin); ((yid < ymax) && (yid < scmc_internal_g_ylen)); (yid = (yid + 1)))
		{
			c_sync_ovlp_o2m_scmc_kernel((kerstr)->vecmain, (kerstr)->vecovlp, ((kerstr)->ovlpindex)[0], ((kerstr)->numvec)[0], ((kerstr)->num_ele)[0], ((kerstr)->xblock)[0], ((kerstr)->yblock)[0], ((kerstr)->zblock)[0], ((kerstr)->ovlp)[0], yid, scmc_internal_g_ylen);
		}
	}
	if ((dump_kernel_variables || _pscmc_c_global_dump_kernel_variables))
	{
		{
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_vecmain_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecmain_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecmain, write_len, sizeof((kerstr->vecmain)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_vecovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->vecovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->vecovlp, write_len, sizeof((kerstr->vecovlp)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_ovlpindex_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlpindex_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlpindex, write_len, sizeof((kerstr->ovlpindex)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_numvec_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->numvec_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->numvec, write_len, sizeof((kerstr->numvec)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_num_ele_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->num_ele_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->num_ele, write_len, sizeof((kerstr->num_ele)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_xblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->xblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->xblock, write_len, sizeof((kerstr->xblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_yblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->yblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->yblock, write_len, sizeof((kerstr->yblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_zblock_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->zblock_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->zblock, write_len, sizeof((kerstr->zblock)[0]), fp);
				fclose(fp);
			}
			{
				char fname[256];
				snprintf(fname, 256, "Debug_%d_c_sync_ovlp_o2m_ovlp_after_exec", _pscmc_c_global_dump_times);
				FILE *fp = fopen(fname, "wb");
				size_t write_len = kerstr->ovlp_len;

				if ((write_len <= 0))
				{
					{
						(write_len = 1);
					}
				}
				else
				{
					{
						0;
					}
				}
				fwrite(kerstr->ovlp, write_len, sizeof((kerstr->ovlp)[0]), fp);
				fclose(fp);
			}
		}
	}
	else
	{
		{
			0;
		}
	}
	(_pscmc_c_global_dump_times = (_pscmc_c_global_dump_times + 1));
	return 0;
}
int c_sync_ovlp_o2m_scmc_set_parameter_vecmain(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecmain = pm->d_data);
	((kerstr)->vecmain_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_vecovlp(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->vecovlp = pm->d_data);
	((kerstr)->vecovlp_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_ovlpindex(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlpindex = pm->d_data);
	((kerstr)->ovlpindex_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_numvec(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->numvec = pm->d_data);
	((kerstr)->numvec_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_num_ele(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->num_ele = pm->d_data);
	((kerstr)->num_ele_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_xblock(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->xblock = pm->d_data);
	((kerstr)->xblock_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_yblock(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->yblock = pm->d_data);
	((kerstr)->yblock_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_zblock(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->zblock = pm->d_data);
	((kerstr)->zblock_len = pm->len);
}
int c_sync_ovlp_o2m_scmc_set_parameter_ovlp(c_sync_ovlp_o2m_struct *kerstr, c_pscmc_mem *pm)
{
	((kerstr)->ovlp = pm->d_data);
	((kerstr)->ovlp_len = pm->len);
}

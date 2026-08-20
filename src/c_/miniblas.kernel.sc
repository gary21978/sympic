#define IDX_OPT_MAX 1
void c_blas_axpy_scmc_kernel(double *y, double *x, double a, long y_cpu_core, long numvec, long XLEN, long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele, long scmc_internal_g_idy, long scmc_internal_g_ylen)
{
    const long pscmc_compute_unit_id = 0;
    const long pscmc_num_compute_units = 1;
    const long __idx = 0;
    const long __idy = scmc_internal_g_idy;
    const long __xlen = 1;
    const long __ylen = scmc_internal_g_ylen;
    const long __global_idx = (__idx + (__idy * __xlen));
    long local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    long local_ymin = (__idy * local_ynum);
    long local_ymax = ((1 + __idy) * local_ynum);
    long xb = xblock;
    long yb = yblock;
    long zb = zblock;
    long blk_all_len = (xb * (yb * (zb * num_ele)));
    if ((local_ymax >= numvec))
    {
        {
            (local_ymax = numvec);
        }
    }
    else
    {
        {
            0;
        }
    }
    double reduce_tmp_arr[IDX_OPT_MAX];
    double reduce_tmp = 0.00000000000000000e+00;
    {
        long i;
        for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        {

            if ((blk_all_len <= 1))
            {
                {
                    double fast_y[1];
                    {
                        {
                            long inner_step;
                            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1)))
                            {
                                {
                                    long inner_g;
                                    for ((inner_g = 0); (inner_g < blk_all_len); (inner_g = (inner_g + 1)))
                                    {
                                        ((fast_y)[((inner_step * blk_all_len) + inner_g)] = ((y + (i * blk_all_len)))[((inner_step * blk_all_len) + inner_g)]);
                                    }
                                }
                            }
                        }
                    }
                    double fast_x[1];
                    {
                        {
                            long inner_step;
                            for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1)))
                            {
                                {
                                    long inner_g;
                                    for ((inner_g = 0); (inner_g < blk_all_len); (inner_g = (inner_g + 1)))
                                    {
                                        ((fast_x)[((inner_step * blk_all_len) + inner_g)] = ((x + (i * blk_all_len)))[((inner_step * blk_all_len) + inner_g)]);
                                    }
                                }
                            }
                        }
                    }
                    {
                        long xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                long xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        long xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            {
                                                long realidx;
                                                for ((realidx = 0); (realidx < (num_ele * XLEN)); (realidx = (realidx + 1)))
                                                {
                                                    ((fast_y)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)] = ((fast_y)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)] + (a * (fast_x)[((0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))) + realidx)])));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    {
                        long inner_step;
                        for ((inner_step = 0); (inner_step < 1); (inner_step = (inner_step + 1)))
                        {
                            {
                                long inner_g;
                                for ((inner_g = 0); (inner_g < blk_all_len); (inner_g = (inner_g + 1)))
                                {
                                    (((y + (i * blk_all_len)))[((inner_step * blk_all_len) + inner_g)] = (fast_y)[((inner_step * blk_all_len) + inner_g)]);
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                {
                    {
                        long xyzz;
                        for ((xyzz = 0); (xyzz < ZLEN); (xyzz = (xyzz + 1)))
                        {
                            {
                                long xyzy;
                                for ((xyzy = 0); (xyzy < YLEN); (xyzy = (xyzy + 1)))
                                {
                                    {
                                        long xyzx;
                                        for ((xyzx = 0); (xyzx < 1); (xyzx = (xyzx + 1)))
                                        {
                                            long blk_offset_t1 = (blk_all_len * i);
                                            long blk_offset = ((blk_all_len * i) + (0 + (num_ele * (ovlp + (xb * ((xyzy + ovlp) + (yb * (xyzz + ovlp))))))));
                                            {
                                                long g = 0;
                                                for (g = 0; ((__idx + (g * __xlen)) < (XLEN * num_ele)); g++)
                                                {
                                                    long realidx = (__idx + (g * __xlen));
                                                    ((y)[(blk_offset + realidx)] = ((y)[(blk_offset + realidx)] + (a * (x)[(blk_offset + realidx)])));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void c_blas_yiszero_synced_scmc_kernel(double *y, long y_cpu_core, long numvec, long XLEN, long YLEN, long ZLEN, int ovlp, long xblock, long yblock, long zblock, int num_ele, long scmc_internal_g_idy, long scmc_internal_g_ylen)
{
    const long pscmc_compute_unit_id = 0;
    const long pscmc_num_compute_units = 1;
    const long __idx = 0;
    const long __idy = scmc_internal_g_idy;
    const long __xlen = 1;
    const long __ylen = scmc_internal_g_ylen;
    const long __global_idx = (__idx + (__idy * __xlen));
    long local_ynum = (((numvec - 1) / y_cpu_core) + 1);
    const long LOCAL_CACHE_LEN = 128;
    long local_ymin = (__idy * local_ynum);
    long local_ymax = ((1 + __idy) * local_ynum);
    long xb = xblock;
    long yb = yblock;
    long zb = zblock;
    long blk_all_len = (xb * (yb * (zb * num_ele)));

    if ((local_ymax >= numvec))
    {
        {
            (local_ymax = numvec);
        }
    }
    else
    {
        {
            0;
        }
    }
    double zeros[128];
    long lg = 0;
    for ((lg = 0); ((lg + __idx) < LOCAL_CACHE_LEN); (lg = (lg + __xlen)))
    {
        ((zeros)[(lg + __idx)] = 0);
    }
    {
        long i;
        for ((i = local_ymin); (i < local_ymax); (i = (i + 1)))
        {
            long blk_offset_t1 = (blk_all_len * i);
            long j = 0;
            for ((j = 0); (j < blk_all_len); (j = (j + LOCAL_CACHE_LEN)))
            {
                int numcp = ((((j + LOCAL_CACHE_LEN) < blk_all_len)) ? (({ LOCAL_CACHE_LEN; })) : (({ (blk_all_len - j); })));
                {
                    long Gll_P9918;
                    for ((Gll_P9918 = 0); (Gll_P9918 < numcp); (Gll_P9918 = (Gll_P9918 + 1)))
                    {
                        (((y + (blk_offset_t1 + j)))[Gll_P9918] = (zeros)[Gll_P9918]);
                    }
                }
            }
        }
    }
}
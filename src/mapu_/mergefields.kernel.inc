#define MAPU_LONG long long

/*
1. 主网格边界数据就是mirror单元中的数据
2. overlap缓冲区就是把mirror单元中的数据收集起来，准备发送给相邻进程
3. overlap->main: 表示接受缓冲区中的信息覆盖到虚拟单元中
4. main->overlap: 表示mirror单元中的数据拷贝到发送缓冲区中
*/

__global__ void mapu_sync_ovlp_o2m(__DDR double *vecmain, __DDR double *vecovlp,
                                   int ovlpindex, MAPU_LONG numvec, int num_ele,
                                   MAPU_LONG xblock, MAPU_LONG yblock,
                                   MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));

  __mem1__ MAPU_LONG i;
  i = 0;

  __mem1__ MAPU_LONG local_ynum;
  local_ynum = (numvec - 1) / __ylen + 1;
  __mem1__ MAPU_LONG local_ymin;
  local_ymin = __idy * local_ynum;
  __mem1__ MAPU_LONG local_ymax;
  local_ymax = (1 + __idy) * local_ynum;
  __mem1__ MAPU_LONG xb;
  xb = xblock;
  __mem1__ MAPU_LONG yb;
  yb = yblock;
  __mem1__ MAPU_LONG zb;
  zb = zblock;
  __mem1__ MAPU_LONG blk_all_len;
  blk_all_len = (xb * (yb * (zb * num_ele)));

  local_ymax = local_ymax >= numvec ? numvec : local_ymax;

  __mem1__ int xlo;
  xlo = (ovlpindex % 3);
  __mem1__ int ylo;
  ylo = ((ovlpindex / 3) % 3);
  __mem1__ int zlo;
  zlo = ((ovlpindex / 3) / 3);
  __mem1__ int field_xmi;
  field_xmi = ovlp;
  __mem1__ int field_ymi;
  field_ymi = ovlp;
  __mem1__ int field_zmi;
  field_zmi = ovlp;
  __mem1__ MAPU_LONG field_xma;
  field_xma = (xb - ovlp);
  __mem1__ MAPU_LONG field_yma;
  field_yma = (yb - ovlp);
  __mem1__ MAPU_LONG field_zma;
  field_zma = (zb - ovlp);

  if (xlo == 0) {
    field_xmi = 0;
    field_xma = (ovlp + 0);
  } else if (xlo == 2) {
    field_xmi = xb - ovlp;
    field_xma = xb;
  }

  if (ylo == 0) {
    field_ymi = 0;
    field_yma = ovlp;
  } else if (ylo == 2) {
    field_ymi = yb - ovlp;
    field_yma = yb;
  }

  if (zlo == 0) {
    field_zmi = 0;
    field_zma = ovlp;
  } else if (zlo == 2) {
    field_zmi = zb - ovlp;
    field_zma = zb;
  }

  __mem1__ MAPU_LONG ovlpxma;
  ovlpxma = field_xma - field_xmi;

  __mem1__ MAPU_LONG ovlpyma;
  ovlpyma = field_yma - field_ymi;

  __mem1__ MAPU_LONG ovlpzma;
  ovlpzma = field_zma - field_zmi;

  __mem1__ MAPU_LONG ovlpalllen;
  ovlpalllen = ovlpxma * (ovlpyma * (ovlpzma * num_ele));

  for (i = local_ymin; i < local_ymax; i++) {
    __mem1__ MAPU_LONG xyzz;
    for (xyzz = 0; xyzz < ovlpzma; xyzz++) {

      __mem1__ MAPU_LONG xyzy;
      for (xyzy = 0; xyzy < ovlpyma; xyzy++) {
        __mem1__ MAPU_LONG xyzx;
        for (xyzx = 0; xyzx < ovlpxma; xyzx++) {
          __mem1__ MAPU_LONG lxyzx;
          lxyzx = xyzx + field_xmi;

          __mem1__ MAPU_LONG lxyzy;
          lxyzy = xyzy + field_ymi;

          __mem1__ MAPU_LONG lxyzz;
          lxyzz = xyzz + field_zmi;

          __mem1__ MAPU_LONG g;
          for (g = 0; __idx + g * __xlen < num_ele; g++) {
            __mem1__ MAPU_LONG realidx;
            realidx = __idx + g * __xlen;
            vecmain[i * blk_all_len +
                    (realidx +
                     (num_ele * (lxyzx + (xb * (lxyzy + yb * lxyzz)))))] =
                vecovlp[((i * ovlpalllen) +
                         (realidx +
                          (num_ele *
                           (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))];
          }
        }
      }
    }
  }
#endif
}

__global__ void
mapu_sync_ovlp_o2m_all_in_one(__DDR double *vecmain, __DDR double *vecovlps,
                              MAPU_LONG numvec, int num_ele, MAPU_LONG xblock,
                              MAPU_LONG yblock, MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__

  // 当前线程的当地编号
  const MAPU_LONG __idx = 0;

  // 当前block的全局编号
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));

  // 单个block中thread的总数
  const MAPU_LONG __xlen = 1;

  // block的总数
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);

  // 当前线程的全局编号（实际上就是block的编号）
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem1__ size_t v_offset;
  v_offset = 0;

  __mem1__ MAPU_LONG ovlpindex;
  for (ovlpindex = 0; ovlpindex < 27; ovlpindex++) {
    if (ovlpindex == 13) {
      continue;
    } else {
      __mem1__ __DDR double *vecovlp;
      vecovlp = (vecovlps + v_offset);

      __mem1__ MAPU_LONG i;
      i = 0;

      __mem1__ MAPU_LONG local_ynum;

      // numvec是总共有多少个cu的意思，local_ynum表示每个block需要处理的cu个数
      local_ynum = (numvec - 1) / __ylen + 1;

      // 当前block处理的起始偏移cu编号
      __mem1__ MAPU_LONG local_ymin;
      local_ymin = __idy * local_ynum;

      // 当前block处理的结束偏移cu编号
      __mem1__ MAPU_LONG local_ymax;
      local_ymax = (1 + __idy) * local_ynum;

      // 单个cu中，x方向的网格厚度（单元个数）
      __mem1__ MAPU_LONG xb;
      xb = xblock;

      __mem1__ MAPU_LONG yb;
      yb = yblock;

      __mem1__ MAPU_LONG zb;
      zb = zblock;

      // 计算一个cu总共多少个数据
      __mem1__ MAPU_LONG blk_all_len;
      blk_all_len = xb * yb * zb * num_ele;

      local_ymax = local_ymax >= numvec ? numvec : local_ymax;

      // 计算当前ghost方向的位置
      __mem1__ int xlo;
      xlo = (ovlpindex % 3);

      __mem1__ int ylo;
      ylo = ((ovlpindex / 3) % 3);

      __mem1__ int zlo;
      zlo = ((ovlpindex / 3) / 3);

      __mem1__ int field_xmi;
      field_xmi = ovlp;

      __mem1__ int field_ymi;
      field_ymi = ovlp;

      __mem1__ int field_zmi;
      field_zmi = ovlp;

      __mem1__ MAPU_LONG field_xma;
      field_xma = (xb - ovlp);

      __mem1__ MAPU_LONG field_yma;
      field_yma = (yb - ovlp);

      __mem1__ MAPU_LONG field_zma;
      field_zma = (zb - ovlp);

      if (xlo == 0) {
        field_xmi = 0;
        field_xma = ovlp;
      } else if (xlo == 2) {
        field_xmi = xb - ovlp;
        field_xma = xb;
      }

      if (ylo == 0) {
        field_ymi = 0;
        field_yma = ovlp;
      } else if (ylo == 2) {
        field_ymi = yb - ovlp;
        field_yma = yb;
      }

      if (zlo == 0) {
        field_zmi = 0;
        field_zma = ovlp;
      } else if (zlo == 2) {
        field_zmi = zb - ovlp;
        field_zma = zb;
      }

      __mem1__ MAPU_LONG ovlpxma;
      ovlpxma = (field_xma - field_xmi);

      __mem1__ MAPU_LONG ovlpyma;
      ovlpyma = (field_yma - field_ymi);

      __mem1__ MAPU_LONG ovlpzma;
      ovlpzma = (field_zma - field_zmi);

      __mem1__ MAPU_LONG ovlpalllen;

      // 获得当前方向的
      ovlpalllen = ovlpxma * (ovlpyma * (ovlpzma * num_ele));

      // i表示cu序号，
      for (i = local_ymin; i < local_ymax; i++) {
        __mem1__ MAPU_LONG xyzz;
        for (xyzz = 0; xyzz < ovlpzma; xyzz++) {
          __mem1__ MAPU_LONG xyzy;
          for (xyzy = 0; xyzy < ovlpyma; xyzy++) {
            __mem1__ MAPU_LONG xyzx;
            for (xyzx = 0; xyzx < ovlpxma; xyzx++) {
              __mem1__ MAPU_LONG lxyzx;
              lxyzx = xyzx + field_xmi;
              __mem1__ MAPU_LONG lxyzy;
              lxyzy = xyzy + field_ymi;
              __mem1__ MAPU_LONG lxyzz;
              lxyzz = xyzz + field_zmi;

              __mem1__ MAPU_LONG g;
              for (g = 0; __idx + g * __xlen < num_ele; g++) {
                __mem1__ MAPU_LONG realidx;
                realidx = (__idx + (g * __xlen));

                // i * blk_all_len（该block的偏移首地址） +
                // realidx(一个单元的第几个数据分量) + num_ele * (lxyzx + xb *
                // (lxyzy + yb * lxyzz));
                vecmain[(i * blk_all_len) +
                        (realidx +
                         (num_ele * (lxyzx + (xb * (lxyzy + (yb * lxyzz))))))] =
                    vecovlp[(i * ovlpalllen) +
                            (realidx +
                             (num_ele *
                              (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz))))))];
              }
            }
          }
        }
      }
      v_offset += ovlpalllen * numvec;
    }
  }
#endif
}

__global__ void mapu_sync_ovlp_o2m_once(
    __DDR double *vecmain, __DDR double *vecovlp0, __DDR double *vecovlp1,
    __DDR double *vecovlp2, __DDR double *vecovlp3, __DDR double *vecovlp4,
    __DDR double *vecovlp5, __DDR double *vecovlp6, __DDR double *vecovlp7,
    __DDR double *vecovlp8, __DDR double *vecovlp9, __DDR double *vecovlp10,
    __DDR double *vecovlp11, __DDR double *vecovlp12, __DDR double *vecovlp14,
    __DDR double *vecovlp15, __DDR double *vecovlp16, __DDR double *vecovlp17,
    __DDR double *vecovlp18, __DDR double *vecovlp19, __DDR double *vecovlp20,
    __DDR double *vecovlp21, __DDR double *vecovlp22, __DDR double *vecovlp23,
    __DDR double *vecovlp24, __DDR double *vecovlp25, __DDR double *vecovlp26,
    MAPU_LONG numvec, int num_ele, MAPU_LONG xblock, MAPU_LONG yblock,
    MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));

  __mem0__ __DDR double *vecovlps[27];
  vecovlps[0] = vecovlp0;
  vecovlps[1] = vecovlp1;
  vecovlps[2] = vecovlp2;
  vecovlps[3] = vecovlp3;
  vecovlps[4] = vecovlp4;
  vecovlps[5] = vecovlp5;
  vecovlps[6] = vecovlp6;
  vecovlps[7] = vecovlp7;
  vecovlps[8] = vecovlp8;
  vecovlps[9] = vecovlp9;
  vecovlps[10] = vecovlp10;
  vecovlps[11] = vecovlp11;
  vecovlps[12] = vecovlp12;
  vecovlps[13] = NULL;
  vecovlps[14] = vecovlp14;
  vecovlps[15] = vecovlp15;
  vecovlps[16] = vecovlp16;
  vecovlps[17] = vecovlp17;
  vecovlps[18] = vecovlp18;
  vecovlps[19] = vecovlp19;
  vecovlps[20] = vecovlp20;
  vecovlps[21] = vecovlp21;
  vecovlps[22] = vecovlp22;
  vecovlps[23] = vecovlp23;
  vecovlps[24] = vecovlp24;
  vecovlps[25] = vecovlp25;
  vecovlps[26] = vecovlp26;

  __mem1__ MAPU_LONG ovlpindex;
  for (ovlpindex = 0; ovlpindex < 27; ovlpindex++) {
    if ((ovlpindex == 13)) {
      continue;
    } else {
      __mem1__ __DDR double *vecovlp;
      vecovlp = vecovlps[ovlpindex];

      __mem1__ MAPU_LONG i;
      i = 0;

      __mem1__ MAPU_LONG local_ynum;
      local_ynum = (((numvec - 1) / __ylen) + 1);

      __mem1__ MAPU_LONG local_ymin;
      local_ymin = (__idy * local_ynum);

      __mem1__ MAPU_LONG local_ymax;
      local_ymax = ((1 + __idy) * local_ynum);

      __mem1__ MAPU_LONG xb;
      xb = xblock;

      __mem1__ MAPU_LONG yb;
      yb = yblock;

      __mem1__ MAPU_LONG zb;
      zb = zblock;

      __mem1__ MAPU_LONG blk_all_len;
      blk_all_len = (xb * (yb * (zb * num_ele)));

      local_ymax = local_ymax >= numvec ? numvec : local_ymax;

      __mem1__ int xlo;
      xlo = (ovlpindex % 3);
      __mem1__ int ylo;
      ylo = ((ovlpindex / 3) % 3);
      __mem1__ int zlo;
      zlo = ((ovlpindex / 3) / 3);
      __mem1__ int field_xmi;
      field_xmi = ovlp;
      __mem1__ int field_ymi;
      field_ymi = ovlp;
      __mem1__ int field_zmi;
      field_zmi = ovlp;
      __mem1__ MAPU_LONG field_xma;
      field_xma = (xb - ovlp);
      __mem1__ MAPU_LONG field_yma;
      field_yma = (yb - ovlp);
      __mem1__ MAPU_LONG field_zma;
      field_zma = (zb - ovlp);

      if (xlo == 0) {
        field_xmi = 0;
        field_xma = ovlp;
      } else if (xlo == 2) {
        field_xmi = xb - ovlp;
        field_xma = xb;
      }

      if (ylo == 0) {
        field_ymi = 0;
        field_yma = ovlp;
      } else if (ylo == 2) {
        field_ymi = yb - ovlp;
        field_yma = yb;
      }

      if (zlo == 0) {
        field_zmi = 0;
        field_zma = ovlp;
      } else if (zlo == 2) {
        field_zmi = zb - ovlp;
        field_zma = zb;
      }

      __mem1__ MAPU_LONG ovlpxma;
      ovlpxma = (field_xma - field_xmi);

      __mem1__ MAPU_LONG ovlpyma;
      ovlpyma = (field_yma - field_ymi);

      __mem1__ MAPU_LONG ovlpzma;
      ovlpzma = (field_zma - field_zmi);

      __mem1__ MAPU_LONG ovlpalllen;
      ovlpalllen = ovlpxma * (ovlpyma * (ovlpzma * num_ele));

      for (i = local_ymin; i < local_ymax; i++) {
        __mem1__ MAPU_LONG xyzz;
        for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
          __mem1__ MAPU_LONG xyzy;
          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            __mem1__ MAPU_LONG xyzx;
            for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
              __mem1__ MAPU_LONG lxyzx;
              lxyzx = (xyzx + field_xmi);
              __mem1__ MAPU_LONG lxyzy;
              lxyzy = (xyzy + field_ymi);
              __mem1__ MAPU_LONG lxyzz;
              lxyzz = (xyzz + field_zmi);

              __mem1__ MAPU_LONG g;
              for (g = 0; __idx + g * __xlen < num_ele; g++) {
                __mem1__ MAPU_LONG realidx;
                realidx = (__idx + (g * __xlen));
                ((vecmain)[(
                     (i * blk_all_len) +
                     (realidx +
                      (num_ele * (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                     (vecovlp)[(
                         (i * ovlpalllen) +
                         (realidx +
                          (num_ele *
                           (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))]);
              }
            }
          }
        }
      }
    }
  }

#endif
}

__global__ void mapu_sync_ovlp_m2o(__DDR double *vecmain, __DDR double *vecovlp,
                                   int ovlpindex, MAPU_LONG numvec, int num_ele,
                                   MAPU_LONG xblock, MAPU_LONG yblock,
                                   MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__

  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));

  __mem1__ MAPU_LONG i;
  i = 0;

  __mem1__ MAPU_LONG local_ynum;
  local_ynum = (((numvec - 1) / __ylen) + 1);

  __mem1__ MAPU_LONG local_ymin;
  local_ymin = (__idy * local_ynum);

  __mem1__ MAPU_LONG local_ymax;
  local_ymax = ((1 + __idy) * local_ynum);

  __mem1__ MAPU_LONG xb;
  xb = xblock;

  __mem1__ MAPU_LONG yb;
  yb = yblock;

  __mem1__ MAPU_LONG zb;
  zb = zblock;

  __mem1__ MAPU_LONG blk_all_len;
  blk_all_len = xb * (yb * (zb * num_ele));

  local_ymax = local_ymax >= numvec ? numvec : local_ymax;

  __mem1__ int xlo;
  xlo = (ovlpindex % 3);
  __mem1__ int ylo;
  ylo = ((ovlpindex / 3) % 3);
  __mem1__ int zlo;
  zlo = ((ovlpindex / 3) / 3);
  __mem1__ int field_xmi;
  field_xmi = ovlp;
  __mem1__ int field_ymi;
  field_ymi = ovlp;
  __mem1__ int field_zmi;
  field_zmi = ovlp;
  __mem1__ MAPU_LONG field_xma;
  field_xma = (xb - ovlp);
  __mem1__ MAPU_LONG field_yma;
  field_yma = (yb - ovlp);
  __mem1__ MAPU_LONG field_zma;
  field_zma = (zb - ovlp);

  if (xlo == 0) {
    field_xmi = ovlp;
    field_xma = ovlp + ovlp;
  } else if (xlo == 2) {
    field_xmi = xb - (ovlp + ovlp);
    field_xma = xb - ovlp;
  }

  if (ylo == 0) {
    field_ymi = ovlp;
    field_yma = (ovlp + ovlp);
  } else if (ylo == 2) {
    field_ymi = yb - (ovlp + ovlp);
    field_yma = yb - ovlp;
  }

  if ((zlo == 0)) {
    field_zmi = ovlp;
    field_zma = ovlp + ovlp;
  } else if (zlo == 2) {
    field_zmi = zb - (ovlp + ovlp);
    field_zma = zb - ovlp;
  }

  __mem1__ MAPU_LONG ovlpxma;
  ovlpxma = (field_xma - field_xmi);

  __mem1__ MAPU_LONG ovlpyma;
  ovlpyma = (field_yma - field_ymi);

  __mem1__ MAPU_LONG ovlpzma;
  ovlpzma = (field_zma - field_zmi);

  __mem1__ MAPU_LONG ovlpalllen;
  ovlpalllen = ovlpxma * (ovlpyma * (ovlpzma * num_ele));

  for (i = local_ymin; i < local_ymax; i++) {
    __mem1__ MAPU_LONG xyzz;
    for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {

      __mem1__ MAPU_LONG xyzy;
      for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
        __mem1__ MAPU_LONG xyzx;
        for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
          __mem1__ MAPU_LONG lxyzx;
          lxyzx = (xyzx + field_xmi);
          __mem1__ MAPU_LONG lxyzy;
          lxyzy = (xyzy + field_ymi);
          __mem1__ MAPU_LONG lxyzz;
          lxyzz = (xyzz + field_zmi);

          lxyzx = (lxyzx < ovlp || lxyzx >= xb - ovlp) ? ovlp : lxyzx;
          lxyzy = (lxyzy < ovlp || lxyzy >= yb - ovlp) ? ovlp : lxyzy;
          lxyzz = (lxyzz < ovlp || lxyzz >= zb - ovlp) ? ovlp : lxyzz;

          __mem1__ MAPU_LONG g;
          g = 0;
          for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
            __mem1__ MAPU_LONG realidx;
            realidx = (__idx + (g * __xlen));
            ((vecovlp)[((i * ovlpalllen) +
                        (realidx +
                         (num_ele *
                          (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                 (vecmain)[(
                     (i * blk_all_len) +
                     (realidx +
                      (num_ele * (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
          }
        }
      }
    }
  }
#endif
}

__global__ void
mapu_sync_ovlp_m2o_all_in_one(__DDR double *vecmain, __DDR double *vecovlps,
                              MAPU_LONG numvec, int num_ele, MAPU_LONG xblock,
                              MAPU_LONG yblock, MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem1__ size_t v_offset;
  v_offset = 0;
  {
    __mem1__ MAPU_LONG ovlpindex;
    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if ((ovlpindex == 13)) {
        {
          continue;
        }
      } else {
        __mem1__ __DDR double *vecovlp;
        vecovlp = (vecovlps + v_offset);
        __mem1__ MAPU_LONG i;
        i = 0;
        __mem1__ MAPU_LONG local_ynum;
        local_ynum = (((numvec - 1) / __ylen) + 1);
        __mem1__ MAPU_LONG local_ymin;
        local_ymin = (__idy * local_ynum);
        __mem1__ MAPU_LONG local_ymax;
        local_ymax = ((1 + __idy) * local_ynum);
        __mem1__ MAPU_LONG xb;
        xb = xblock;
        __mem1__ MAPU_LONG yb;
        yb = yblock;
        __mem1__ MAPU_LONG zb;
        zb = zblock;
        __mem1__ MAPU_LONG blk_all_len;
        blk_all_len = (xb * (yb * (zb * num_ele)));

        local_ymax = local_ymax >= numvec ? numvec : local_ymax;

        __mem1__ int xlo;
        xlo = (ovlpindex % 3);
        __mem1__ int ylo;
        ylo = ((ovlpindex / 3) % 3);
        __mem1__ int zlo;
        zlo = ((ovlpindex / 3) / 3);
        __mem1__ int field_xmi;
        field_xmi = ovlp;
        __mem1__ int field_ymi;
        field_ymi = ovlp;
        __mem1__ int field_zmi;
        field_zmi = ovlp;
        __mem1__ MAPU_LONG field_xma;
        field_xma = (xb - ovlp);
        __mem1__ MAPU_LONG field_yma;
        field_yma = (yb - ovlp);
        __mem1__ MAPU_LONG field_zma;
        field_zma = (zb - ovlp);

        if (xlo == 0) {
          field_xmi = ovlp;
          field_xma = ovlp + ovlp;
        } else if (xlo == 2) {
          field_xmi = xb - (ovlp + ovlp);
          field_xma = xb - ovlp;
        }

        if (ylo == 0) {
          field_ymi = ovlp;
          field_yma = ovlp + ovlp;
        } else if (ylo == 2) {
          field_ymi = yb - (ovlp + ovlp);
          field_yma = yb - ovlp;
        }

        if (zlo == 0) {
          field_zmi = ovlp;
          field_zma = ovlp + ovlp;
        } else if (zlo == 2) {
          field_zmi = zb - (ovlp + ovlp);
          field_zma = zb - ovlp;
        }
        __mem1__ MAPU_LONG ovlpxma;
        ovlpxma = (field_xma - field_xmi);
        __mem1__ MAPU_LONG ovlpyma;
        ovlpyma = (field_yma - field_ymi);
        __mem1__ MAPU_LONG ovlpzma;
        ovlpzma = (field_zma - field_zmi);
        __mem1__ MAPU_LONG ovlpalllen;
        ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
        for ((i = local_ymin); (i < local_ymax); i++) {
          __mem1__ MAPU_LONG xyzz;
          for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
            __mem1__ MAPU_LONG xyzy;
            for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
              __mem1__ MAPU_LONG xyzx;
              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                __mem1__ MAPU_LONG lxyzx;
                lxyzx = (xyzx + field_xmi);
                __mem1__ MAPU_LONG lxyzy;
                lxyzy = (xyzy + field_ymi);
                __mem1__ MAPU_LONG lxyzz;
                lxyzz = (xyzz + field_zmi);

                lxyzx = (lxyzx < ovlp || lxyzx >= xb - ovlp) ? ovlp : lxyzx;
                lxyzy = (lxyzy < ovlp || lxyzy >= yb - ovlp) ? ovlp : lxyzy;
                lxyzz = (lxyzz < ovlp || lxyzz >= zb - ovlp) ? ovlp : lxyzz;

                __mem1__ MAPU_LONG g;
                g = 0;
                for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                  __mem1__ MAPU_LONG realidx;
                  realidx = (__idx + (g * __xlen));
                  ((vecovlp)[(
                       (i * ovlpalllen) +
                       (realidx +
                        (num_ele *
                         (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                       (vecmain)[(
                           (i * blk_all_len) +
                           (realidx +
                            (num_ele *
                             (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
                }
              }
            }
          }
        }
        v_offset = v_offset + (ovlpalllen * numvec);
      }
    }
  }
#endif
}
__global__ void mapu_sync_ovlp_m2o_once(
    __DDR double *vecmain, __DDR double *vecovlp0, __DDR double *vecovlp1,
    __DDR double *vecovlp2, __DDR double *vecovlp3, __DDR double *vecovlp4,
    __DDR double *vecovlp5, __DDR double *vecovlp6, __DDR double *vecovlp7,
    __DDR double *vecovlp8, __DDR double *vecovlp9, __DDR double *vecovlp10,
    __DDR double *vecovlp11, __DDR double *vecovlp12, __DDR double *vecovlp14,
    __DDR double *vecovlp15, __DDR double *vecovlp16, __DDR double *vecovlp17,
    __DDR double *vecovlp18, __DDR double *vecovlp19, __DDR double *vecovlp20,
    __DDR double *vecovlp21, __DDR double *vecovlp22, __DDR double *vecovlp23,
    __DDR double *vecovlp24, __DDR double *vecovlp25, __DDR double *vecovlp26,
    MAPU_LONG numvec, int num_ele, MAPU_LONG xblock, MAPU_LONG yblock,
    MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem0__ __DDR double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);
  {
    __mem1__ MAPU_LONG ovlpindex;
    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {

      if ((ovlpindex == 13)) {
        {
          continue;
        }
      } else {

        __mem1__ __DDR double *vecovlp;
        vecovlp = (vecovlps)[ovlpindex];
        __mem1__ MAPU_LONG i;
        i = 0;
        __mem1__ MAPU_LONG local_ynum;
        local_ynum = (((numvec - 1) / __ylen) + 1);
        __mem1__ MAPU_LONG local_ymin;
        local_ymin = (__idy * local_ynum);
        __mem1__ MAPU_LONG local_ymax;
        local_ymax = ((1 + __idy) * local_ynum);
        __mem1__ MAPU_LONG xb;
        xb = xblock;
        __mem1__ MAPU_LONG yb;
        yb = yblock;
        __mem1__ MAPU_LONG zb;
        zb = zblock;
        __mem1__ MAPU_LONG blk_all_len;
        blk_all_len = (xb * (yb * (zb * num_ele)));

        local_ymax = local_ymax >= numvec ? numvec : local_ymax;
        __mem1__ int xlo;
        xlo = (ovlpindex % 3);
        __mem1__ int ylo;
        ylo = ((ovlpindex / 3) % 3);
        __mem1__ int zlo;
        zlo = ((ovlpindex / 3) / 3);
        __mem1__ int field_xmi;
        field_xmi = ovlp;
        __mem1__ int field_ymi;
        field_ymi = ovlp;
        __mem1__ int field_zmi;
        field_zmi = ovlp;
        __mem1__ MAPU_LONG field_xma;
        field_xma = (xb - ovlp);
        __mem1__ MAPU_LONG field_yma;
        field_yma = (yb - ovlp);
        __mem1__ MAPU_LONG field_zma;
        field_zma = (zb - ovlp);

        if (xlo == 0) {
          field_xmi = ovlp;
          field_xma = ovlp + ovlp;
        } else if (xlo == 2) {
          field_xmi = xb - (ovlp + ovlp);
          field_xma = xb - ovlp;
        }

        if (ylo == 0) {
          field_ymi = ovlp;
          field_yma = ovlp + ovlp;
        } else if (ylo == 2) {
          field_ymi = yb - (ovlp + ovlp);
          field_yma = yb - ovlp;
        }

        if (zlo == 0) {
          field_zmi = ovlp;
          field_zma = ovlp + ovlp;
        } else if (zlo == 2) {
          field_zmi = zb - (ovlp + ovlp);
          field_zma = zb - ovlp;
        }

        __mem1__ MAPU_LONG ovlpxma;
        ovlpxma = (field_xma - field_xmi);
        __mem1__ MAPU_LONG ovlpyma;
        ovlpyma = (field_yma - field_ymi);
        __mem1__ MAPU_LONG ovlpzma;
        ovlpzma = (field_zma - field_zmi);
        __mem1__ MAPU_LONG ovlpalllen;
        ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
        for ((i = local_ymin); (i < local_ymax); i++) {
          __mem1__ MAPU_LONG xyzz;
          for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
            __mem1__ MAPU_LONG xyzy;
            for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
              __mem1__ MAPU_LONG xyzx;
              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                __mem1__ MAPU_LONG lxyzx;
                lxyzx = (xyzx + field_xmi);
                __mem1__ MAPU_LONG lxyzy;
                lxyzy = (xyzy + field_ymi);
                __mem1__ MAPU_LONG lxyzz;
                lxyzz = (xyzz + field_zmi);

                lxyzx = (lxyzx < ovlp || lxyzx >= xb - ovlp) ? ovlp : lxyzx;
                lxyzy = (lxyzy < ovlp || lxyzy >= yb - ovlp) ? ovlp : lxyzy;
                lxyzz = (lxyzz < ovlp || lxyzz >= zb - ovlp) ? ovlp : lxyzz;

                __mem1__ MAPU_LONG g;
                g = 0;
                for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                  __mem1__ MAPU_LONG realidx;
                  realidx = (__idx + (g * __xlen));
                  ((vecovlp)[(
                       (i * ovlpalllen) +
                       (realidx +
                        (num_ele *
                         (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                       (vecmain)[(
                           (i * blk_all_len) +
                           (realidx +
                            (num_ele *
                             (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
                }
              }
            }
          }
        }
      }
    }
  }
#endif
}

__global__ void mapu_merge_ovlp_o2m(__DDR double *vecmain,
                                    __DDR double *vecovlp, int ovlpindex,
                                    MAPU_LONG numvec, int num_ele,
                                    MAPU_LONG xblock, MAPU_LONG yblock,
                                    MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ MAPU_LONG local_ynum;
  local_ynum = (((numvec - 1) / __ylen) + 1);
  __mem1__ MAPU_LONG local_ymin;
  local_ymin = (__idy * local_ynum);
  __mem1__ MAPU_LONG local_ymax;
  local_ymax = ((1 + __idy) * local_ynum);
  __mem1__ MAPU_LONG xb;
  xb = xblock;
  __mem1__ MAPU_LONG yb;
  yb = yblock;
  __mem1__ MAPU_LONG zb;
  zb = zblock;
  __mem1__ MAPU_LONG blk_all_len;
  blk_all_len = (xb * (yb * (zb * num_ele)));

  local_ymax = local_ymax >= numvec ? numvec : local_ymax;
  __mem1__ int xlo;
  xlo = (ovlpindex % 3);
  __mem1__ int ylo;
  ylo = ((ovlpindex / 3) % 3);
  __mem1__ int zlo;
  zlo = ((ovlpindex / 3) / 3);
  __mem1__ int field_xmi;
  field_xmi = ovlp;
  __mem1__ int field_ymi;
  field_ymi = ovlp;
  __mem1__ int field_zmi;
  field_zmi = ovlp;
  __mem1__ MAPU_LONG field_xma;
  field_xma = (xb - ovlp);
  __mem1__ MAPU_LONG field_yma;
  field_yma = (yb - ovlp);
  __mem1__ MAPU_LONG field_zma;
  field_zma = (zb - ovlp);

  if (xlo == 0) {
    field_xmi = ovlp;
    field_xma = (ovlp + ovlp);
  } else if (xlo == 2) {
    field_xmi = xb - (ovlp + ovlp);
    field_xma = xb - ovlp;
  }

  if (ylo == 0) {
    field_ymi = ovlp;
    field_yma = (ovlp + ovlp);
  } else if (ylo == 2) {
    field_ymi = yb - (ovlp + ovlp);
    field_yma = yb - ovlp;
  }

  if (zlo == 0) {
    field_zmi = ovlp;
    field_zma = (ovlp + ovlp);
  } else if (zlo == 2) {
    field_zmi = zb - (ovlp + ovlp);
    field_zma = zb - ovlp;
  }
  __mem1__ MAPU_LONG ovlpxma;
  ovlpxma = (field_xma - field_xmi);
  __mem1__ MAPU_LONG ovlpyma;
  ovlpyma = (field_yma - field_ymi);
  __mem1__ MAPU_LONG ovlpzma;
  ovlpzma = (field_zma - field_zmi);
  __mem1__ MAPU_LONG ovlpalllen;
  ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
  for ((i = local_ymin); (i < local_ymax); i++) {
    __mem1__ MAPU_LONG xyzz;
    for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
      __mem1__ MAPU_LONG xyzy;
      for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
        __mem1__ MAPU_LONG xyzx;
        for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
          __mem1__ MAPU_LONG lxyzx;
          lxyzx = (xyzx + field_xmi);
          __mem1__ MAPU_LONG lxyzy;
          lxyzy = (xyzy + field_ymi);
          __mem1__ MAPU_LONG lxyzz;
          lxyzz = (xyzz + field_zmi);

          lxyzx = (lxyzx < ovlp || lxyzx >= xb - ovlp) ? ovlp : lxyzx;
          lxyzy = (lxyzy < ovlp || lxyzy >= yb - ovlp) ? ovlp : lxyzy;
          lxyzz = (lxyzz < ovlp || lxyzz >= zb - ovlp) ? ovlp : lxyzz;

          __mem1__ MAPU_LONG g;
          g = 0;
          for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
            __mem1__ MAPU_LONG realidx;
            realidx = (__idx + (g * __xlen));
            ((vecmain)[(
                 (i * blk_all_len) +
                 (realidx +
                  (num_ele * (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                 ((vecmain)[(
                      (i * blk_all_len) +
                      (realidx +
                       (num_ele * (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] +
                  (vecovlp)[(
                      (i * ovlpalllen) +
                      (realidx +
                       (num_ele *
                        (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))]));
          }
        }
      }
    }
  }
#endif
}

__global__ void
mapu_merge_ovlp_o2m_all_in_one(__DDR double *vecmain, __DDR double *vecovlps,
                               MAPU_LONG numvec, int num_ele, MAPU_LONG xblock,
                               MAPU_LONG yblock, MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem1__ size_t v_offset;
  v_offset = 0;
  {
    __mem1__ MAPU_LONG ovlpindex;
    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {

      if ((ovlpindex == 13)) {
        {
          continue;
        }
      } else {
        __mem1__ __DDR double *vecovlp;
        vecovlp = (vecovlps + v_offset);
        __mem1__ MAPU_LONG i;
        i = 0;
        __mem1__ MAPU_LONG local_ynum;
        local_ynum = (((numvec - 1) / __ylen) + 1);
        __mem1__ MAPU_LONG local_ymin;
        local_ymin = (__idy * local_ynum);
        __mem1__ MAPU_LONG local_ymax;
        local_ymax = ((1 + __idy) * local_ynum);
        __mem1__ MAPU_LONG xb;
        xb = xblock;
        __mem1__ MAPU_LONG yb;
        yb = yblock;
        __mem1__ MAPU_LONG zb;
        zb = zblock;
        __mem1__ MAPU_LONG blk_all_len;
        blk_all_len = (xb * (yb * (zb * num_ele)));

        local_ymax = local_ymax >= numvec ? numvec : local_ymax;

        __mem1__ int xlo;
        xlo = (ovlpindex % 3);
        __mem1__ int ylo;
        ylo = ((ovlpindex / 3) % 3);
        __mem1__ int zlo;
        zlo = ((ovlpindex / 3) / 3);
        __mem1__ int field_xmi;
        field_xmi = ovlp;
        __mem1__ int field_ymi;
        field_ymi = ovlp;
        __mem1__ int field_zmi;
        field_zmi = ovlp;
        __mem1__ MAPU_LONG field_xma;
        field_xma = (xb - ovlp);
        __mem1__ MAPU_LONG field_yma;
        field_yma = (yb - ovlp);
        __mem1__ MAPU_LONG field_zma;
        field_zma = (zb - ovlp);

        if (xlo == 0) {
          field_xmi = ovlp;
          field_xma = ovlp + ovlp;
        } else if (xlo == 2) {
          field_xmi = xb - (ovlp + ovlp);
          field_xma = xb - ovlp;
        }

        if (ylo == 0) {
          field_ymi = ovlp;
          field_yma = ovlp + ovlp;
        } else if (ylo == 2) {
          field_ymi = yb - (ovlp + ovlp);
          field_yma = yb - ovlp;
        }

        if (zlo == 0) {
          field_zmi = ovlp;
          field_zma = ovlp + ovlp;
        } else if (zlo == 2) {
          field_zmi = zb - (ovlp + ovlp);
          field_zma = zb - ovlp;
        }
        __mem1__ MAPU_LONG ovlpxma;
        ovlpxma = (field_xma - field_xmi);
        __mem1__ MAPU_LONG ovlpyma;
        ovlpyma = (field_yma - field_ymi);
        __mem1__ MAPU_LONG ovlpzma;
        ovlpzma = (field_zma - field_zmi);
        __mem1__ MAPU_LONG ovlpalllen;
        ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
        for ((i = local_ymin); (i < local_ymax); i++) {
          __mem1__ MAPU_LONG xyzz;
          for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
            __mem1__ MAPU_LONG xyzy;
            for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
              __mem1__ MAPU_LONG xyzx;
              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                __mem1__ MAPU_LONG lxyzx;
                lxyzx = (xyzx + field_xmi);
                __mem1__ MAPU_LONG lxyzy;
                lxyzy = (xyzy + field_ymi);
                __mem1__ MAPU_LONG lxyzz;
                lxyzz = (xyzz + field_zmi);

                lxyzx = (lxyzx < ovlp || lxyzx >= xb - ovlp) ? ovlp : lxyzx;
                lxyzy = (lxyzy < ovlp || lxyzy >= yb - ovlp) ? ovlp : lxyzy;
                lxyzz = (lxyzz < ovlp || lxyzz >= zb - ovlp) ? ovlp : lxyzz;

                {
                  __mem1__ MAPU_LONG g;
                  g = 0;
                  for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                    __mem1__ MAPU_LONG realidx;
                    realidx = (__idx + (g * __xlen));
                    ((vecmain)[((i * blk_all_len) +
                                (realidx +
                                 (num_ele *
                                  (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                         ((vecmain)[(
                              (i * blk_all_len) +
                              (realidx +
                               (num_ele *
                                (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] +
                          (vecovlp)[(
                              (i * ovlpalllen) +
                              (realidx +
                               (num_ele *
                                (xyzx +
                                 (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))]));
                  }
                }
              }
            }
          }
        }
        (v_offset = (v_offset + (ovlpalllen * numvec)));
      }
    }
  }
#endif
}

__global__ void mapu_merge_ovlp_o2m_once(
    __DDR double *vecmain, __DDR double *vecovlp0, __DDR double *vecovlp1,
    __DDR double *vecovlp2, __DDR double *vecovlp3, __DDR double *vecovlp4,
    __DDR double *vecovlp5, __DDR double *vecovlp6, __DDR double *vecovlp7,
    __DDR double *vecovlp8, __DDR double *vecovlp9, __DDR double *vecovlp10,
    __DDR double *vecovlp11, __DDR double *vecovlp12, __DDR double *vecovlp14,
    __DDR double *vecovlp15, __DDR double *vecovlp16, __DDR double *vecovlp17,
    __DDR double *vecovlp18, __DDR double *vecovlp19, __DDR double *vecovlp20,
    __DDR double *vecovlp21, __DDR double *vecovlp22, __DDR double *vecovlp23,
    __DDR double *vecovlp24, __DDR double *vecovlp25, __DDR double *vecovlp26,
    MAPU_LONG numvec, int num_ele, MAPU_LONG xblock, MAPU_LONG yblock,
    MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem0__ __DDR double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);
  {
    __mem1__ MAPU_LONG ovlpindex;
    for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
      if ((ovlpindex == 13)) {
        continue;
      } else {
        __mem1__ __DDR double *vecovlp;
        vecovlp = (vecovlps)[ovlpindex];
        __mem1__ MAPU_LONG i;
        i = 0;
        __mem1__ MAPU_LONG local_ynum;
        local_ynum = (((numvec - 1) / __ylen) + 1);
        __mem1__ MAPU_LONG local_ymin;
        local_ymin = (__idy * local_ynum);
        __mem1__ MAPU_LONG local_ymax;
        local_ymax = ((1 + __idy) * local_ynum);
        __mem1__ MAPU_LONG xb;
        xb = xblock;
        __mem1__ MAPU_LONG yb;
        yb = yblock;
        __mem1__ MAPU_LONG zb;
        zb = zblock;
        __mem1__ MAPU_LONG blk_all_len;
        blk_all_len = (xb * (yb * (zb * num_ele)));

        local_ymax = local_ymax >= numvec ? numvec : local_ymax;
        __mem1__ int xlo;
        xlo = (ovlpindex % 3);
        __mem1__ int ylo;
        ylo = ((ovlpindex / 3) % 3);
        __mem1__ int zlo;
        zlo = ((ovlpindex / 3) / 3);
        __mem1__ int field_xmi;
        field_xmi = ovlp;
        __mem1__ int field_ymi;
        field_ymi = ovlp;
        __mem1__ int field_zmi;
        field_zmi = ovlp;
        __mem1__ MAPU_LONG field_xma;
        field_xma = (xb - ovlp);
        __mem1__ MAPU_LONG field_yma;
        field_yma = (yb - ovlp);
        __mem1__ MAPU_LONG field_zma;
        field_zma = (zb - ovlp);

        if (xlo == 0) {
          field_xmi = ovlp;
          field_xma = ovlp + ovlp;
        } else if (xlo == 2) {
          field_xmi = xb - (ovlp + ovlp);
          field_xma = xb - ovlp;
        }

        if (ylo == 0) {
          field_ymi = ovlp;
          field_yma = ovlp + ovlp;
        } else if (ylo == 2) {
          field_ymi = yb - (ovlp + ovlp);
          field_yma = yb - ovlp;
        }

        if (zlo == 0) {
          field_zmi = ovlp;
          field_zma = ovlp + ovlp;
        } else if (zlo == 2) {
          field_zmi = zb - (ovlp + ovlp);
          field_zma = zb - ovlp;
        }
        __mem1__ MAPU_LONG ovlpxma;
        ovlpxma = (field_xma - field_xmi);
        __mem1__ MAPU_LONG ovlpyma;
        ovlpyma = (field_yma - field_ymi);
        __mem1__ MAPU_LONG ovlpzma;
        ovlpzma = (field_zma - field_zmi);
        __mem1__ MAPU_LONG ovlpalllen;
        ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
        for ((i = local_ymin); (i < local_ymax); i++) {
          __mem1__ MAPU_LONG xyzz;
          for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
            __mem1__ MAPU_LONG xyzy;
            for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
              __mem1__ MAPU_LONG xyzx;
              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                __mem1__ MAPU_LONG lxyzx;
                lxyzx = (xyzx + field_xmi);
                __mem1__ MAPU_LONG lxyzy;
                lxyzy = (xyzy + field_ymi);
                __mem1__ MAPU_LONG lxyzz;
                lxyzz = (xyzz + field_zmi);

                lxyzx = (lxyzx < ovlp || lxyzx >= xb - ovlp) ? ovlp : lxyzx;
                lxyzy = (lxyzy < ovlp || lxyzy >= yb - ovlp) ? ovlp : lxyzy;
                lxyzz = (lxyzz < ovlp || lxyzz >= zb - ovlp) ? ovlp : lxyzz;

                __mem1__ MAPU_LONG g;
                g = 0;
                for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                  __mem1__ MAPU_LONG realidx;
                  realidx = (__idx + (g * __xlen));
                  ((vecmain)[(
                       (i * blk_all_len) +
                       (realidx +
                        (num_ele * (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] =
                       ((vecmain)[(
                            (i * blk_all_len) +
                            (realidx +
                             (num_ele *
                              (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))] +
                        (vecovlp)[((i * ovlpalllen) +
                                   (realidx +
                                    (num_ele *
                                     (xyzx + (ovlpxma *
                                              (xyzy + (ovlpyma * xyzz)))))))]));
                }
              }
            }
          }
        }
      }
    }
  }
#endif
}

__global__ void mapu_merge_ovlp_m2o(__DDR double *vecmain,
                                    __DDR double *vecovlp, int ovlpindex,
                                    MAPU_LONG numvec, int num_ele,
                                    MAPU_LONG xblock, MAPU_LONG yblock,
                                    MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem1__ MAPU_LONG i;
  i = 0;
  __mem1__ MAPU_LONG local_ynum;
  local_ynum = (((numvec - 1) / __ylen) + 1);
  __mem1__ MAPU_LONG local_ymin;
  local_ymin = (__idy * local_ynum);
  __mem1__ MAPU_LONG local_ymax;
  local_ymax = ((1 + __idy) * local_ynum);
  __mem1__ MAPU_LONG xb;
  xb = xblock;
  __mem1__ MAPU_LONG yb;
  yb = yblock;
  __mem1__ MAPU_LONG zb;
  zb = zblock;
  __mem1__ MAPU_LONG blk_all_len;
  blk_all_len = (xb * (yb * (zb * num_ele)));

  local_ymax = local_ymax >= numvec ? numvec : local_ymax;
  __mem1__ int xlo;
  xlo = (ovlpindex % 3);
  __mem1__ int ylo;
  ylo = ((ovlpindex / 3) % 3);
  __mem1__ int zlo;
  zlo = ((ovlpindex / 3) / 3);
  __mem1__ int field_xmi;
  field_xmi = ovlp;
  __mem1__ int field_ymi;
  field_ymi = ovlp;
  __mem1__ int field_zmi;
  field_zmi = ovlp;
  __mem1__ MAPU_LONG field_xma;
  field_xma = (xb - ovlp);
  __mem1__ MAPU_LONG field_yma;
  field_yma = (yb - ovlp);
  __mem1__ MAPU_LONG field_zma;
  field_zma = (zb - ovlp);

  if (xlo == 0) {
    (field_xmi = 0);
    (field_xma = (ovlp + 0));
  } else {

    if ((xlo == 2)) {
      (field_xmi = (xb - (ovlp + 0)));
      (field_xma = (xb - 0));
    }
  }

  if (ylo == 0) {
    (field_ymi = 0);
    (field_yma = (ovlp + 0));
  } else {

    if ((ylo == 2)) {
      (field_ymi = (yb - (ovlp + 0)));
      (field_yma = (yb - 0));
    }
  }

  if ((zlo == 0)) {
    (field_zmi = 0);
    (field_zma = (ovlp + 0));
  } else {

    if ((zlo == 2)) {
      (field_zmi = (zb - (ovlp + 0)));
      (field_zma = (zb - 0));
    }
  }
  __mem1__ MAPU_LONG ovlpxma;
  ovlpxma = (field_xma - field_xmi);
  __mem1__ MAPU_LONG ovlpyma;
  ovlpyma = (field_yma - field_ymi);
  __mem1__ MAPU_LONG ovlpzma;
  ovlpzma = (field_zma - field_zmi);
  __mem1__ MAPU_LONG ovlpalllen;
  ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
  for ((i = local_ymin); (i < local_ymax); i++) {
    {
      __mem1__ MAPU_LONG xyzz;
      for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
        {
          __mem1__ MAPU_LONG xyzy;
          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            {
              __mem1__ MAPU_LONG xyzx;
              for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
                __mem1__ MAPU_LONG lxyzx;
                lxyzx = (xyzx + field_xmi);
                __mem1__ MAPU_LONG lxyzy;
                lxyzy = (xyzy + field_ymi);
                __mem1__ MAPU_LONG lxyzz;
                lxyzz = (xyzz + field_zmi);

                if (0) {
                  {

                    if (((lxyzx < ovlp) || (lxyzx >= (xb - ovlp)))) {
                      {
                        (lxyzx = ovlp);
                      }
                    } else {
                      {
                        0;
                      }
                    }

                    if (((lxyzy < ovlp) || (lxyzy >= (yb - ovlp)))) {
                      {
                        (lxyzy = ovlp);
                      }
                    } else {
                      {
                        0;
                      }
                    }

                    if (((lxyzz < ovlp) || (lxyzz >= (zb - ovlp)))) {
                      {
                        (lxyzz = ovlp);
                      }
                    } else {
                      {
                        0;
                      }
                    }
                  }
                } else {
                  {
                    0;
                  }
                }
                {
                  __mem1__ MAPU_LONG g;
                  g = 0;
                  for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                    __mem1__ MAPU_LONG realidx;
                    realidx = (__idx + (g * __xlen));
                    ((vecovlp)[(
                         (i * ovlpalllen) +
                         (realidx +
                          (num_ele *
                           (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                         (vecmain)[(
                             (i * blk_all_len) +
                             (realidx +
                              (num_ele *
                               (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
#endif
}

__global__ void
mapu_merge_ovlp_m2o_all_in_one(__DDR double *vecmain, __DDR double *vecovlps,
                               MAPU_LONG numvec, int num_ele, MAPU_LONG xblock,
                               MAPU_LONG yblock, MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem1__ size_t v_offset;
  v_offset = 0;

  __mem1__ MAPU_LONG ovlpindex;
  for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
    if ((ovlpindex == 13)) {
      continue;
    } else {
      __mem1__ __DDR double *vecovlp;
      vecovlp = (vecovlps + v_offset);
      __mem1__ MAPU_LONG i;
      i = 0;
      __mem1__ MAPU_LONG local_ynum;
      local_ynum = (((numvec - 1) / __ylen) + 1);
      __mem1__ MAPU_LONG local_ymin;
      local_ymin = (__idy * local_ynum);
      __mem1__ MAPU_LONG local_ymax;
      local_ymax = ((1 + __idy) * local_ynum);
      __mem1__ MAPU_LONG xb;
      xb = xblock;
      __mem1__ MAPU_LONG yb;
      yb = yblock;
      __mem1__ MAPU_LONG zb;
      zb = zblock;
      __mem1__ MAPU_LONG blk_all_len;
      blk_all_len = (xb * (yb * (zb * num_ele)));

      local_ymax = local_ymax >= numvec ? numvec : local_ymax;
      __mem1__ int xlo;
      xlo = (ovlpindex % 3);
      __mem1__ int ylo;
      ylo = ((ovlpindex / 3) % 3);
      __mem1__ int zlo;
      zlo = ((ovlpindex / 3) / 3);
      __mem1__ int field_xmi;
      field_xmi = ovlp;
      __mem1__ int field_ymi;
      field_ymi = ovlp;
      __mem1__ int field_zmi;
      field_zmi = ovlp;
      __mem1__ MAPU_LONG field_xma;
      field_xma = (xb - ovlp);
      __mem1__ MAPU_LONG field_yma;
      field_yma = (yb - ovlp);
      __mem1__ MAPU_LONG field_zma;
      field_zma = (zb - ovlp);

      if (xlo == 0) {
        field_xmi = 0;
        field_xma = ovlp;
      } else if (xlo == 2) {
        field_xmi = xb - ovlp;
        field_xma = xb;
      }

      if (ylo == 0) {
        field_ymi = 0;
        field_yma = ovlp;
      } else if (ylo == 2) {
        field_ymi = yb - ovlp;
        field_yma = yb;
      }

      if (zlo == 0) {
        field_zmi = 0;
        field_zma = ovlp;
      } else if (zlo == 2) {
        field_zmi = zb - ovlp;
        field_zma = zb;
      }
      __mem1__ MAPU_LONG ovlpxma;
      ovlpxma = (field_xma - field_xmi);
      __mem1__ MAPU_LONG ovlpyma;
      ovlpyma = (field_yma - field_ymi);
      __mem1__ MAPU_LONG ovlpzma;
      ovlpzma = (field_zma - field_zmi);
      __mem1__ MAPU_LONG ovlpalllen;
      ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
      for ((i = local_ymin); (i < local_ymax); i++) {
        __mem1__ MAPU_LONG xyzz;
        for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {
          __mem1__ MAPU_LONG xyzy;
          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {
            __mem1__ MAPU_LONG xyzx;
            for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
              __mem1__ MAPU_LONG lxyzx;
              lxyzx = (xyzx + field_xmi);
              __mem1__ MAPU_LONG lxyzy;
              lxyzy = (xyzy + field_ymi);
              __mem1__ MAPU_LONG lxyzz;
              lxyzz = (xyzz + field_zmi);

              __mem1__ MAPU_LONG g;
              g = 0;
              for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                __mem1__ MAPU_LONG realidx;
                realidx = (__idx + (g * __xlen));
                ((vecovlp)[(
                     (i * ovlpalllen) +
                     (realidx +
                      (num_ele *
                       (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                     (vecmain)[((i * blk_all_len) +
                                (realidx +
                                 (num_ele *
                                  (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
              }
            }
          }
        }
      }
      (v_offset = (v_offset + (ovlpalllen * numvec)));
    }
  }
#endif
}

__global__ void mapu_merge_ovlp_m2o_once(
    __DDR double *vecmain, __DDR double *vecovlp0, __DDR double *vecovlp1,
    __DDR double *vecovlp2, __DDR double *vecovlp3, __DDR double *vecovlp4,
    __DDR double *vecovlp5, __DDR double *vecovlp6, __DDR double *vecovlp7,
    __DDR double *vecovlp8, __DDR double *vecovlp9, __DDR double *vecovlp10,
    __DDR double *vecovlp11, __DDR double *vecovlp12, __DDR double *vecovlp14,
    __DDR double *vecovlp15, __DDR double *vecovlp16, __DDR double *vecovlp17,
    __DDR double *vecovlp18, __DDR double *vecovlp19, __DDR double *vecovlp20,
    __DDR double *vecovlp21, __DDR double *vecovlp22, __DDR double *vecovlp23,
    __DDR double *vecovlp24, __DDR double *vecovlp25, __DDR double *vecovlp26,
    MAPU_LONG numvec, int num_ele, MAPU_LONG xblock, MAPU_LONG yblock,
    MAPU_LONG zblock, int ovlp) {

#ifdef __SCALE_ARCH__
  const MAPU_LONG __idx = 0;
  const MAPU_LONG __idy = (blockIdx.x + (blockIdx.y * gridDim.x));
  const MAPU_LONG __xlen = 1;
  const MAPU_LONG __ylen = (gridDim.x * gridDim.y);
  const MAPU_LONG __global_idx = (__idx + (__idy * __xlen));
  __mem0__ __DDR double *vecovlps[27];
  ((vecovlps)[0] = vecovlp0);
  ((vecovlps)[1] = vecovlp1);
  ((vecovlps)[2] = vecovlp2);
  ((vecovlps)[3] = vecovlp3);
  ((vecovlps)[4] = vecovlp4);
  ((vecovlps)[5] = vecovlp5);
  ((vecovlps)[6] = vecovlp6);
  ((vecovlps)[7] = vecovlp7);
  ((vecovlps)[8] = vecovlp8);
  ((vecovlps)[9] = vecovlp9);
  ((vecovlps)[10] = vecovlp10);
  ((vecovlps)[11] = vecovlp11);
  ((vecovlps)[12] = vecovlp12);
  ((vecovlps)[13] = NULL);
  ((vecovlps)[14] = vecovlp14);
  ((vecovlps)[15] = vecovlp15);
  ((vecovlps)[16] = vecovlp16);
  ((vecovlps)[17] = vecovlp17);
  ((vecovlps)[18] = vecovlp18);
  ((vecovlps)[19] = vecovlp19);
  ((vecovlps)[20] = vecovlp20);
  ((vecovlps)[21] = vecovlp21);
  ((vecovlps)[22] = vecovlp22);
  ((vecovlps)[23] = vecovlp23);
  ((vecovlps)[24] = vecovlp24);
  ((vecovlps)[25] = vecovlp25);
  ((vecovlps)[26] = vecovlp26);

  __mem1__ MAPU_LONG ovlpindex;
  for ((ovlpindex = 0); (ovlpindex < 27); (ovlpindex = (ovlpindex + 1))) {
    if ((ovlpindex == 13)) {
      continue;
    } else {
      __mem1__ __DDR double *vecovlp;
      vecovlp = (vecovlps)[ovlpindex];
      __mem1__ MAPU_LONG i;
      i = 0;
      __mem1__ MAPU_LONG local_ynum;
      local_ynum = (((numvec - 1) / __ylen) + 1);
      __mem1__ MAPU_LONG local_ymin;
      local_ymin = (__idy * local_ynum);
      __mem1__ MAPU_LONG local_ymax;
      local_ymax = ((1 + __idy) * local_ynum);
      __mem1__ MAPU_LONG xb;
      xb = xblock;
      __mem1__ MAPU_LONG yb;
      yb = yblock;
      __mem1__ MAPU_LONG zb;
      zb = zblock;
      __mem1__ MAPU_LONG blk_all_len;
      blk_all_len = (xb * (yb * (zb * num_ele)));

      local_ymax = local_ymax >= numvec ? numvec : local_ymax;
      __mem1__ int xlo;
      xlo = (ovlpindex % 3);
      __mem1__ int ylo;
      ylo = ((ovlpindex / 3) % 3);
      __mem1__ int zlo;
      zlo = ((ovlpindex / 3) / 3);
      __mem1__ int field_xmi;
      field_xmi = ovlp;
      __mem1__ int field_ymi;
      field_ymi = ovlp;
      __mem1__ int field_zmi;
      field_zmi = ovlp;
      __mem1__ MAPU_LONG field_xma;
      field_xma = (xb - ovlp);
      __mem1__ MAPU_LONG field_yma;
      field_yma = (yb - ovlp);
      __mem1__ MAPU_LONG field_zma;
      field_zma = (zb - ovlp);

      if (xlo == 0) {
        field_xmi = 0;
        field_xma = ovlp;
      } else if (xlo == 2) {
        field_xmi = xb - ovlp;
        field_xma = xb;
      }

      if (ylo == 0) {
        field_ymi = 0;
        field_yma = ovlp;
      } else if (ylo == 2) {
        field_ymi = yb - ovlp;
        field_yma = yb;
      }

      if (zlo == 0) {
        field_zmi = 0;
        field_zma = ovlp;
      } else if (zlo == 2) {
        field_zmi = zb - ovlp;
        field_zma = zb;
      }

      __mem1__ MAPU_LONG ovlpxma;
      ovlpxma = (field_xma - field_xmi);
      __mem1__ MAPU_LONG ovlpyma;
      ovlpyma = (field_yma - field_ymi);
      __mem1__ MAPU_LONG ovlpzma;
      ovlpzma = (field_zma - field_zmi);
      __mem1__ MAPU_LONG ovlpalllen;
      ovlpalllen = (ovlpxma * (ovlpyma * (ovlpzma * num_ele)));
      for ((i = local_ymin); (i < local_ymax); i++) {

        __mem1__ MAPU_LONG xyzz;
        for ((xyzz = 0); (xyzz < ovlpzma); (xyzz = (xyzz + 1))) {

          __mem1__ MAPU_LONG xyzy;
          for ((xyzy = 0); (xyzy < ovlpyma); (xyzy = (xyzy + 1))) {

            __mem1__ MAPU_LONG xyzx;
            for ((xyzx = 0); (xyzx < ovlpxma); (xyzx = (xyzx + 1))) {
              __mem1__ MAPU_LONG lxyzx;
              lxyzx = (xyzx + field_xmi);
              __mem1__ MAPU_LONG lxyzy;
              lxyzy = (xyzy + field_ymi);
              __mem1__ MAPU_LONG lxyzz;
              lxyzz = (xyzz + field_zmi);

              __mem1__ MAPU_LONG g;
              g = 0;
              for (g = 0; ((__idx + (g * __xlen)) < num_ele); g++) {
                __mem1__ MAPU_LONG realidx;
                realidx = (__idx + (g * __xlen));
                ((vecovlp)[(
                     (i * ovlpalllen) +
                     (realidx +
                      (num_ele *
                       (xyzx + (ovlpxma * (xyzy + (ovlpyma * xyzz)))))))] =
                     (vecmain)[((i * blk_all_len) +
                                (realidx +
                                 (num_ele *
                                  (lxyzx + (xb * (lxyzy + (yb * lxyzz)))))))]);
              }
            }
          }
        }
      }
    }
  }
#endif
}
/* local_header.h 把 log 重定义为整数截断的 mapu_log_df；
 * Box-Muller 需要真实自然对数，这里恢复标准 log（floor 未使用）。
 * 真实 scale 工具链：设备目标用 aurora 数学库的全局 log/cos（唯一），
 * host 目标上 libm 与 aurora 头文件重复声明导致裸 log/cos 二义，
 * 因此 host 侧走 std:: 命名空间。 */
#ifdef log
#undef log
#endif
#ifdef __SCALE_ARCH__
#define INIT_LOG(x) log(x)
#define INIT_COS(x) cos(x)
#define INIT_SQRT(x) sqrt(x)
#else
/* host 侧 libstdc++ 与 aurora 头文件在 std 里注入了同签名 cos/log，
 * 走 clang 内建函数绕过重载决议 */
#define INIT_LOG(x) __builtin_log(x)
#define INIT_COS(x) __builtin_cos(x)
#define INIT_SQRT(x) __builtin_sqrt(x)
#endif

__device__ static unsigned long long init_particle_splitmix64(unsigned long long *state) {
  unsigned long long z = (*state += 0x9e3779b97f4a7c15ULL);
  z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
  z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
  return z ^ (z >> 31);
}

__device__ static double init_particle_uniform01(unsigned long long *state) {
  unsigned long long x = init_particle_splitmix64(state);
  return ((x >> 11) + 1.0) * (1.0 / 9007199254740993.0);
}

__device__ static double init_particle_normal(unsigned long long *state, double mean,
                                              double sigma) {
  double u1 = init_particle_uniform01(state);
  double u2 = init_particle_uniform01(state);
  return sigma * INIT_SQRT(-2.0 * INIT_LOG(u1)) * INIT_COS(6.28318530717958647692 * u2) + mean;
}

__global__ void mapu_init_non_uni_particle_gpu(__DDR double *inoutput, __DDR int *xyzw,
                                               __DDR int *cu_xyzw, long xlen, long ylen, long zlen,
                                               long numvec, long grid_cache_len, int grid_load,
                                               int ptlen, double vt, double vmax, double vx0,
                                               double vy0, double vz0, double tempx, double tempy,
                                               double tempz, unsigned long long seed) {
  size_t idx = (size_t)blockIdx.x * (size_t)blockDim.x + (size_t)threadIdx.x;
  size_t cells = (size_t)xlen * (size_t)ylen * (size_t)zlen * (size_t)numvec;
  size_t total = cells * (size_t)grid_load;
  if (idx >= total)
    return;

  long l = (long)(idx % (size_t)grid_load);
  size_t cell_id = idx / (size_t)grid_load;
  long local = (long)(cell_id % ((size_t)xlen * (size_t)ylen * (size_t)zlen));
  long cur_pcid = (long)(cell_id / ((size_t)xlen * (size_t)ylen * (size_t)zlen));
  long xyzx = local % xlen;
  long xyzy = (local / xlen) % ylen;
  long xyzz = local / (xlen * ylen);

  size_t cell_offset = (size_t)cur_pcid * (size_t)xlen * (size_t)ylen * (size_t)zlen;
  cell_offset += (size_t)(xyzx + xlen * (xyzy + ylen * xyzz));
  xyzw[4 * cell_offset] = grid_load;

  __DDR double *xyzvs = inoutput + (size_t)cur_pcid * ((size_t)xlen * (size_t)ylen * (size_t)zlen) *
                                       (size_t)(6 * grid_cache_len);
  xyzvs += (size_t)(6 * grid_cache_len) * (size_t)(xyzx + xlen * (xyzy + ylen * xyzz));
  xyzvs += (size_t)l * (size_t)ptlen;

  unsigned long long state = seed ^ ((unsigned long long)idx + 1ULL) * 0xd1b54a32d192ed03ULL;
  xyzvs[0] = (double)xyzx + init_particle_uniform01(&state);
  xyzvs[1] = (double)xyzy + init_particle_uniform01(&state);
  xyzvs[2] = (double)xyzz + init_particle_uniform01(&state);

  double vx, vy, vz;
  do {
    vx = init_particle_normal(&state, vx0, tempx * vt);
    vy = init_particle_normal(&state, vy0, tempy * vt);
    vz = init_particle_normal(&state, vz0, tempz * vt);
  } while ((vx * vx + vy * vy + vz * vz) >= vmax);

  xyzvs[3] = vx;
  xyzvs[4] = vy;
  xyzvs[5] = vz;
}

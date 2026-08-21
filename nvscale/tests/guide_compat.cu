/*
 * NVScale Compatibility Shim
 * --------------------------
 * This is NOT an official SmartLogic SCALE source file.
 * It checks the documented SCALE language and runtime compatibility surface.
 */
#include <aurora.h>
#include <cooperative_groups.h>
#include <maps_runtime.h>
#include <scale/barrier>

__device__ int guide_device_symbol[4] = {0, 0, 0, 0};
__constant__ int guide_constant_symbol[4] = {1, 2, 3, 4};

__device__ KERNEL_M int guide_mpu_add(int a, int b) MPU_FUNC_PTR {
  return a + b;
}

__DM0 int guide_dm0_storage;
__DM23 int guide_dm23_storage;
__input_persistent int guide_input_persistent;
__output_persistent int guide_output_persistent;
__BARRIER int guide_barrier_storage;
__host_DDR int *guide_host_ddr_ptr;
ADDRESS(guide_section) int guide_addressed_storage;

__device__ void guide_compile_surface() {
  v32u32 v0 = {};
  v64s16 v1 = {};
  v64u16 v2 = {};
  v32fp32 v3 = {};
  v16s64 v4 = {};
  v16u64 v5 = {};
  v16fp64 v6 = {};
  v4fp64 v7 = {};
  v8fp32 v8 = {};
  v2fp64 v9 = {};
  v4fp32 v10 = {};
  v32bf16 v11 = {};
  anyv512ty v12 = {};
  anyv1024ty v13 = {};
  vec512_t v14 = {};
  v64fp8e4 v15 = {};
  __fp8e4 fp8 = {};
  int sink = (int)v0[0] + (int)v1[0] + (int)v2[0] + (int)v3[0] +
             (int)v4[0] + (int)v5[0] + (int)v6[0] + (int)v7[0] +
             (int)v8[0] + (int)v9[0] + (int)v10[0] + (int)v11[0] +
             (int)v12[0] + (int)v13[0] + (int)v14[0] + (int)v15[0] +
             (int)fp8.val;
  if (sink == -1) asm volatile("");
  (void)curWarpInfo;
  (void)curWorkGroupInfo;
  (void)callmArgsIdxPtr;
  (void)callmArgsBuffPtr;
  (void)printfBuffer;
  (void)dmaParalAddr;
}

static void guide_host_compile_surface() {
  mapsMemLocation loc = {mapsMemLocationTypeDevice, 0};
  mapsMemAccessDesc access = {loc, mapsMemAccessFlagsProtReadWrite};
  mapsMemPoolProps props = {};
  mapsMemPoolPtrExportData export_data = {};
  mapsIpcMemHandle_t ipc_mem = {};
  mapsIpcEventHandle_t ipc_event = {};
  mapsMemoryAdvise advise = mapsMemAdviseSetReadMostly;
  mapsMemRangeAttribute attr = mapsMemRangeAttributeCoherencyMode;
  mapsMemRangeCoherencyMode coherency = mapsMemRangeCoherencyModeFineGrain;
  mapsDeviceAttribute_t dev_attr = mapsDeviceAttributeTotalGlobalMem;
  mapsMemoryType memory_type = mapsMemoryTypeUnified;
  volatile int sink = access.flags + props.location.id + export_data.reserved[0] +
                      ipc_mem.reserved[0] + ipc_event.reserved[0] + advise +
                      attr + coherency + dev_attr + memory_type;
  (void)sink;
}

__global__ void __prefetch_size__(4) guide_kernel(__DDR int *output) {
  __mem0__ int local[4];
  __macc1__ int accumulated[4];
  __mem2__ __residency__ int resident[4];
  __shared__ __fix0__ int shared[4];

  auto block = cooperative_groups::this_thread_block();
  auto cluster = cooperative_groups::this_cluster();
  auto grid = cooperative_groups::this_grid();
  cooperative_groups::thread_group generic_group = block;
  generic_group.sync();
  using barrier_t = scale::barrier<scale::thread_scope_block>;
  __shared__ barrier_t barrier;
  if (threadIdx.x == 0) init(&barrier, block.size());
  block.sync();
  guide_compile_surface();

  memcpy_async(block, local, guide_constant_symbol,
               scale::aligned_size_t<4>(sizeof(local)), barrier);
  barrier.arrive_and_wait();

  int mpu_value = sync_call guide_mpu_add(local[threadIdx.x], 10);
  async_call guide_mpu_add(0, 0);
  async_enqueue guide_mpu_add(0, 0);
  accumulated[threadIdx.x] = mpu_value;
  resident[threadIdx.x] = scaleThreadId + scaleAsId;
  shared[threadIdx.x] = accumulated[threadIdx.x] + resident[threadIdx.x];
  block.sync();

  int *same_shared = cluster.map_shared_rank(shared, 0);
  output[grid.thread_rank()] = same_shared[threadIdx.x] +
                               (int)cluster.block_rank() +
                               (int)clusterDim.x;
}

int main() {
  guide_host_compile_surface();
  int host_symbol[4] = {3, 4, 5, 6};
  int copied_symbol[4] = {};
  int *output = nullptr;
  void *symbol_address = nullptr;
  size_t symbol_size = 0;

  if (mapsMemcpyToSymbol(guide_device_symbol, host_symbol,
                         sizeof(host_symbol)) != mapsSuccess ||
      mapsMemcpyFromSymbol(copied_symbol, guide_device_symbol,
                           sizeof(copied_symbol)) != mapsSuccess ||
      mapsGetSymbolAddress(&symbol_address, guide_device_symbol) != mapsSuccess ||
      mapsGetSymbolSize(&symbol_size, guide_device_symbol) != mapsSuccess ||
      symbol_address == nullptr || symbol_size != sizeof(guide_device_symbol)) {
    return 1;
  }

  if (mapsMalloc((void **)&output, 4 * sizeof(int)) != mapsSuccess) return 2;
  guide_kernel<<<1, 4>>>(output);
  mapsError_t error = mapsDeviceSynchronize();
  mapsFree(output);
  if (error != mapsSuccess) return 3;

  for (int i = 0; i < 4; ++i) {
    if (copied_symbol[i] != host_symbol[i]) return 4;
  }
  return 0;
}

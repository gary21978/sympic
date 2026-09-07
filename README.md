# 1. 编译代码

编译mpu代码需要进入模拟器环境
bash build.sh mapu  

编译cuda代码不能进入模拟器环境
bash build.sh cuda

使用 NVIDIA GPU 对 MAPU/SCALE 源码做 NVScale 功能验证：

```bash
export NVSCALE_ROOT=/home/cheney/Projects/MaPU/toolchain/nvscale
export NVSCALE_CUDA_ARCH=89
bash build.sh nvscale
```

NVScale 只验证源码兼容性和数值结果，不模拟 Aurora 的 DM 分区、DMA 重叠、MPU 调度或时序行为。



# 2. 运行算例cuda/mapu

脚本run.sh使用方法
bash ./run.sh (算例名称)
bash ./run.sh case/demo-8
bash ./run.sh case/demo-64

使用run.sh运行脚本的时候在build/test/目录中会生成结果目录test_npy/,
如果case中缺少对应的参考结果，可将cuda模式下生成的结果目录test_npy/，改名为result_npy,放到对应的case目录下面


如果case目录下面已经有了结果result_npy，可使用脚本./compare.sh，它会先调用run.sh跑出结果test_npy，然后与result_npy做数值对比，输出比对结果
bash ./compare.sh (算例名称)
bash ./compare.sh case/demo-8
bash ./compare.sh case/demo-64

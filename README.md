# 1. 编译代码

## 1.1 模拟器编译

模拟器编译分两层：

- 宿主机负责启动 QEMU/gem5 环境；
- 真正的编译在虚拟机里完成。

宿主机上一键进入模拟器并编译

```bash
./build.sh simulator
```

`build.sh simulator` 会自动做下面这些事：

```bash
cd /pathtodriver/pciemu/release
./start_emu.sh -T # dual device
```

然后进入 QEMU，执行：

```bash
modprobe maps

sleep 240 # 等待 fabric manager 完成
cat /run/sl-fabricmanager/LINKS # 确认cat /run/sl-fabricmanager/LINKS输出不为空

cd /home/emu/pathtosympic
export SCALE_TOOLCHAIN_ROOT=/opt/maps/toolchain
export TOOLCHAIN_DIR=/opt/maps/toolchain
export MACCL_ROOT=/opt/maps
./build.sh mapu
```

## 1.2 本地 MAPU 编译

`mapu` 是本地 MAPS 编译模式。它不会自动启动 QEMU，也不会自动 SSH 进入 guest。

```bash
./build.sh mapu
```

如果这条命令是在宿主机上执行，它就是宿主机本地快速编译；如果是在虚拟机里执行，它就是虚拟机内使用 `/opt/maps` 的本地编译。

不要把宿主机上的 `build.sh mapu` 和完整模拟器流程混用。完整模拟器流程请用：

```bash
./build.sh simulator
```

## 1.3 CUDA 编译

```bash
./build.sh cuda
```

## 1.4 NVScale 编译验证

使用 GPU 对 SCALE 源码做 NVScale 功能验证：

```bash
export NVSCALE_ROOT=/pathtonvscale
export NVSCALE_CUDA_ARCH=89
./build.sh nvscale
```

NVScale 只验证源码兼容性和数值结果，不模拟 Aurora 的 DM 分区、DMA 重叠、MPU 调度或时序行为。


# 2. 运行算例

`run.sh` 运行算例并生成合并后的 GAPSIO 文件。默认使用单个 MPI rank：

```bash
./run.sh [case]
```

双 rank 运行：

```bash
./run.sh [case] --np 2
```

## 2.1 参考结果

参考结果放在每个算例的 `result_gapsio/` 目录中。

## 2.2 回归比较

先构建比较器：

```bash
cmake -S . -B build
cmake --build build --target compare_gapsio -j
```

然后运行回归测试：

```bash
./compare.sh [case1] [case2] ... [caseN] --build-dir build
```

`compare.sh` 会重新运行算例、合并文件，再和参考文件比较。

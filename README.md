# 1. 编译代码

## 1.1 模拟器编译

模拟器编译分两层：

- 宿主机负责启动 `maps-driver` 里的 QEMU/gem5 环境；
- 真正的 MAPS 编译在虚拟机里完成。

宿主机上一键进入模拟器并编译：

```bash
./build.sh simulator
```

`build.sh simulator` 会自动做下面这些事：

```bash
cd /pathtodriver/pciemu/release
./start_emu.sh -clT
```

然后通过 SSH 进入 QEMU guest，执行：

```bash
modprobe maps

# 关键步骤：等待 fabric manager 建链完成
sleep 240
test -s /run/sl-fabricmanager/LINKS
cat /run/sl-fabricmanager/LINKS

cd /home/emu/Projects/sympic-mapu
export SCALE_TOOLCHAIN_ROOT=/opt/maps/toolchain
export TOOLCHAIN_DIR=/opt/maps/toolchain
export MACCL_ROOT=/opt/maps
bash build.sh mapu
```

`modprobe maps` 之后必须等待大约 4 分钟，并确认：

```bash
cat /run/sl-fabricmanager/LINKS
```

输出不为空，才能继续编译或运行算例。

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

脚本run.sh使用方法
```bash
./run.sh (算例名称)
```

使用run.sh运行脚本的时候在`build/test/`目录中会生成结果目录`test_npy/`,
如果case中缺少对应的参考结果，可将cuda模式下生成的结果目录`test_npy/`，改名为`result_npy`,放到对应的case目录下面。如果case目录下面已经有了结果`result_npy`，可使用脚本`./compare.sh`，它会先调用`run.sh`跑出结果`test_npy`，然后与`result_npy`做数值对比，输出比对结果

```bash
./compare.sh (算例名称)
```

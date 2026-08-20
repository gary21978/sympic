# SymPIC 构建与算例指南

本仓库支持两种构建模式：

- CUDA 原生后端：用 nvcc 编译 `src/cuda_`。
- NVScale 兼容模式：通过本地 `nvscale/` 适配头文件，把 `src/mapu_` 代码
  编译成 CUDA，在 NVIDIA GPU 上做功能验证，无需修改源码。

## 1. 一键编译

```sh
bash build.sh            # 全部编译: CUDA -> build/, NVScale -> build-nvscale/
bash build.sh cuda       # 只编译 CUDA 版本
bash build.sh nvscale    # 只编译 NVScale 版本
bash build.sh --arch 89  # 指定 CUDA 架构 (默认 86)
bash build.sh --clean    # 编译前清空构建目录
```

产物：`build/bin/sympic`、`build/bin/gapsio2to0`、
`build-nvscale/bin/sympic`、`build-nvscale/bin/gapsio2to0`。

`build.sh` 默认复用已有构建目录做增量编译；需要全新重编时加 `--clean`。

## 2. 运行算例

```sh
bash ./run.sh case/demo-8           # 用 CUDA 版本运行, 结果在 build/test/test_npy/
bash ./run.sh case/demo-8 nvscale   # 用 NVScale 版本运行, 结果在 build-nvscale/test/test_npy/
```

`run.sh` 把算例输入链接到 `<build>/test/`，链接 `sympic`、`gapsio2to0`、
`stdlib.scm`、`pygapsio3.py`，运行 `test.ss`，合并 GAPSIO 分片，
最后把结果转成 NumPy 文件写入 `<build>/test/test_npy/`。

## 3. 一键比较结果

```sh
bash ./compare.sh case/demo-8                 # 两个后端都运行: 互相对比, 再与 result_npy 对比
bash ./compare.sh case/demo-8 cuda            # 只运行 cuda, 与 result_npy 对比
bash ./compare.sh case/demo-8 nvscale         # 只运行 nvscale, 与 result_npy 对比
bash ./compare.sh case/demo-8 both --no-run   # 不重新运行, 直接比较已有的 test_npy
```

比较内容：

1. 交叉对比：`build/test/test_npy/` vs `build-nvscale/test/test_npy/`
   （验证 NVScale 兼容层与 CUDA 原生后端结果一致）
2. 参考对比：各后端 vs `case/<case>/result_npy/`（若存在）

对比标准：逐时间步计算 max|Δ| 与相对误差（= max|Δ| / max(|ref|, 1.0)），
默认容差 1e-10。存在差异时 compare.sh 退出码为 1。

## 4. 手动流程

如需单独执行某一步：

```sh
# 只对比两个目录 (不运行算例)
python3 scripts/compare_to_result_npy.py \
  --test-dir build/test/test_npy \
  --ref-dir build-nvscale/test/test_npy

# 只把合并后的 GAPSIO 输出转为 npy
python3 scripts/gapsio_to_npy.py \
  --work-dir build/test \
  --out-dir build/test/test_npy
```

## 5. 管理参考结果

如果 case 目录中没有参考结果，可把某次生成的 `test_npy/` 改名为
`result_npy/` 放进对应 case 目录，之后 `compare.sh` 就会自动做参考对比。

## 附：原生 SCALE/MPU 后端

原生 SCALE/MPU 后端仍可通过 CMake 构建（`-DSYMPIC_MAPU=ON`，见根目录
`CMakeLists.txt`），适用于有内部 SCALE 工具链和模拟器环境的机器；
以上脚本只覆盖 NVIDIA 上的 CUDA / NVScale 工作流。

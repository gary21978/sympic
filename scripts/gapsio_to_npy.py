#!/usr/bin/env python3
"""将当前工作目录下的 GAPSIO v0 合并文件转换为 .npy 文件。

GAPSIO 输出流程：
    sympic (MPI 并行)
        -> 每个 rank 写出 *_PROC_<rank> 数据分片 + *_META_<rank> 元数据
        -> gapsio2to0 合并成分片 -> 单个 GAPSIO v0 文件（如 tmpEB）
        -> 本脚本读取该 v0 文件，每个时间步保存为一个 .npy

典型用法：
    # 在 build/test 目录下运行（合并后的 tmpEB/tmpEN/tmpJ 在此目录）
    cd build/test
    python3 ../../scripts/gapsio_to_npy.py --out-dir ./test_npy

输出文件名格式：
    <out_dir>/<var>_t<t:04d>.npy
    例如：test_npy/tmpEB_t0003.npy
"""
from __future__ import annotations

import argparse
import os
import sys

import numpy as np

# ---------------------------------------------------------------------------
# 脚本路径与仓库路径
# ---------------------------------------------------------------------------
# __file__ 是本脚本自身路径；本脚本位于 <repo>/scripts/，
# 因此 REPO 是脚本所在目录的上一级，用于定位 src/cgapsio/pygapsio3.py。
SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))
REPO = os.path.dirname(SCRIPT_DIR)

# ---------------------------------------------------------------------------
# 定位 pygapsio3
# ---------------------------------------------------------------------------
# pygapsio3.py 可能通过软链接放在工作目录（如 build/test），
# 也可能直接位于仓库源码 src/cgapsio/ 下。按顺序尝试：
#   1. 当前工作目录（cwd）—— run.sh 会把 pygapsio3.py 链接到 build/test
#   2. 本脚本所在目录
#   3. <repo>/src/cgapsio
#   4. <repo>/../src/cgapsio（兼容脚本被放在更深层目录的情况）
_CANDIDATES = [
    os.getcwd(),
    SCRIPT_DIR,
    os.path.join(REPO, "src", "cgapsio"),
    os.path.join(os.path.dirname(REPO), "src", "cgapsio"),
]
for _cand in _CANDIDATES:
    if os.path.isfile(os.path.join(_cand, "pygapsio3.py")):
        sys.path.insert(0, _cand)
        break

# noqa: E402 表示忽略 "import 不在文件顶部" 的 lint 警告，
# 因为我们需要先动态确定 pygapsio3.py 的位置再 import。
from pygapsio3 import (  # noqa: E402
    GAPS_IO_GetNumTimesteps,
    GAPS_IO_Load_TimeStep,
)


def find_merged_variables(work_dir: str) -> list[str]:
    """在工作目录中扫描合并后的 GAPSIO v0 文件。

    识别规则：
        - 是普通文件，不是目录
        - 文件名不包含 _PROC_ 或 _META（排除分片和元数据）
        - 不是 .py 或 .npy
        - 存在对应的 <name>_PROC_0 分片文件（确认它是 sympic 变量）

    返回变量名列表，例如 ['tmpEB', 'tmpEN', 'tmpJ']。
    """
    names = []
    for name in sorted(os.listdir(work_dir)):
        path = os.path.join(work_dir, name)
        if not os.path.isfile(path):
            continue
        # 排除 GAPSIO 分片、元数据、Python 脚本、已生成的 npy
        if "_PROC_" in name or "_META" in name or name.endswith(".py") or name.endswith(".npy"):
            continue
        # 仅保留有 _PROC_0 分片的变量，避免把无关文件（如 README）当成变量
        if os.path.exists(os.path.join(work_dir, f"{name}_PROC_0")):
            names.append(name)
    return names


def convert_variable(var: str, work_dir: str, out_dir: str) -> int:
    """把一个 GAPSIO 变量的所有时间步转成 .npy。

    参数：
        var:       变量名，如 "tmpEB"
        work_dir:  合并后的 GAPSIO 文件所在目录
        out_dir:   输出 .npy 的目录

    返回：写入的 .npy 文件数量。
    """
    path = os.path.join(work_dir, var)
    if not os.path.isfile(path):
        print(f"[skip ] {var}: merged file not found")
        return 0

    # 读取该变量总共有多少个时间步
    nt = int(GAPS_IO_GetNumTimesteps(path))
    if nt <= 0:
        print(f"[skip ] {var}: no timesteps")
        return 0

    written = 0
    for t in range(nt):
        # GAPS_IO_Load_TimeStep 返回的是 Python 列表/数组，转成 np.ndarray 再保存
        arr = np.asarray(GAPS_IO_Load_TimeStep(path, t))
        out_path = os.path.join(out_dir, f"{var}_t{t:04d}.npy")
        np.save(out_path, arr)
        written += 1
    print(f"[write] {var}: {written} timestep(s) -> {out_dir}")
    return written


def main() -> int:
    """命令行入口。"""
    parser = argparse.ArgumentParser(
        description="Convert merged GAPSIO v0 files in the working directory to .npy files."
    )
    parser.add_argument(
        "--work-dir",
        default=os.getcwd(),
        help="包含合并后 GAPSIO 文件的目录（默认：当前工作目录）",
    )
    parser.add_argument(
        "--out-dir",
        required=True,
        help="输出 .npy 的目录（必填）",
    )
    args = parser.parse_args()

    work_dir = os.path.abspath(args.work_dir)
    os.makedirs(args.out_dir, exist_ok=True)

    # 扫描需要转换的变量
    variables = find_merged_variables(work_dir)
    if not variables:
        print(f"[fatal] no merged GAPSIO files found in {work_dir}")
        return 2

    print(f"[info ] work dir: {work_dir}")
    print(f"[info ] variables: {variables}")
    print(f"[info ] output dir: {args.out_dir}\n")

    total = 0
    for var in variables:
        total += convert_variable(var, work_dir, args.out_dir)

    print(f"\n[summary] wrote {total} .npy file(s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())

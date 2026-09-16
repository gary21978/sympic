#!/usr/bin/env python3
"""对比两个目录下的 .npy 参考文件。

使用场景：
    1. 运行 sympic 并生成 GAPSIO 输出
    2. gapsio2to0 合并 + gapsio_to_npy.py 转成 test_npy/*.npy
    3. 用本脚本把 test_npy/ 和参考 result_npy/ 逐时间步对比

典型工作流：
    bash run.sh                                          # 生成 build/test/test_npy/
    cd case/template_cuda
    python3 ../../scripts/compare_to_result_npy.py \
            --test-dir ../../build/test/test_npy \
            --ref-dir ./result_npy

输出说明：
    - max|Δ| : 最大绝对误差，即 max(abs(test - ref))
    - rel    : 相对误差，即 max|Δ| / max(abs(ref), 1.0)
               用 max(abs(ref), 1.0) 作为分母是为了避免参考值为全 0 时除零
    - status : EQUAL（完全相等）、OK（rel < 容差）、DIFF（超差）、
              REF MISSING（参考缺失）、SHAPE MISMATCH（形状不一致）
"""
from __future__ import annotations

import argparse
import glob
import os
import sys
from typing import List, Tuple

import numpy as np

# 默认相对误差容差：1e-10
REL_TOL = 1e-10


def find_variables(npy_dir: str) -> List[str]:
    """扫描目录中所有 *_t*.npy 文件，提取变量名。

    文件名格式必须是 <var>_t<t:04d>.npy，例如 tmpEB_t0003.npy。
    返回去重并排序后的变量名列表，如 ['tmpEB', 'tmpEN', 'tmpJ']。
    """
    names = set()
    for p in glob.glob(os.path.join(npy_dir, "*_t*.npy")):
        basename = os.path.basename(p)
        if "_t" not in basename:
            continue
        # 从 "tmpEB_t0003.npy" 中提取 "tmpEB"
        var = basename[: basename.rfind("_t")]
        names.add(var)
    return sorted(names)


def compare_variable(var: str, test_dir: str, ref_dir: str, rel_tol: float) -> List[Tuple]:
    """对比某个变量在所有时间步上的 test 与 reference。

    返回一个列表，每个元素为：
        (var, timestep, shape_or_None, max_abs_error, rel_error, status)
    """
    rows: List[Tuple] = []
    # 只遍历 test 目录里的文件；参考目录里没有对应文件则记为 REF MISSING
    test_files = sorted(glob.glob(os.path.join(test_dir, f"{var}_t*.npy")))
    for tf in test_files:
        fname = os.path.basename(tf)
        rf = os.path.join(ref_dir, fname)

        # 从文件名 <var>_t####.npy 解析时间步编号
        t_str = fname[fname.rfind("_t") + 2 : -4]
        try:
            t = int(t_str)
        except ValueError:
            # 文件名不符合预期时跳过
            continue

        # 参考文件缺失
        if not os.path.isfile(rf):
            rows.append((var, t, None, float("nan"), float("nan"), "REF MISSING"))
            continue

        a = np.load(tf)  # test 数据
        b = np.load(rf)  # reference 数据

        # 形状不一致则无法逐元素对比
        if a.shape != b.shape:
            rows.append((var, t, (a.shape, b.shape), float("nan"), float("nan"), "SHAPE MISMATCH"))
            continue

        # 计算绝对误差和相对误差
        diff = np.abs(a - b)
        max_abs = float(diff.max())
        scale = max(float(np.max(np.abs(b))), 1.0)  # 防止参考值全为 0
        rel = max_abs / scale

        # 判定状态
        if np.array_equal(a, b):
            status = "EQUAL"
        elif rel < rel_tol:
            status = "OK"
        else:
            status = "DIFF"

        rows.append((var, t, a.shape, max_abs, rel, status))
    return rows


def main() -> int:
    """命令行入口。"""
    parser = argparse.ArgumentParser(
        description="Compare two directories of .npy reference files."
    )
    parser.add_argument(
        "--test-dir",
        required=True,
        help="包含测试 .npy 文件的目录（必填）",
    )
    parser.add_argument(
        "--ref-dir",
        required=True,
        help="包含参考 .npy 文件的目录（必填）",
    )
    parser.add_argument(
        "--rel-tol",
        type=float,
        default=REL_TOL,
        help=f"相对误差容差（默认：{REL_TOL:.1e}）",
    )
    args = parser.parse_args()

    test_dir = os.path.abspath(args.test_dir)
    ref_dir = os.path.abspath(args.ref_dir)

    # 校验输入目录
    if not os.path.isdir(test_dir):
        print(f"[fatal] test directory not found: {test_dir}")
        return 2
    if not os.path.isdir(ref_dir):
        print(f"[fatal] reference directory not found: {ref_dir}")
        return 2

    # 扫描测试目录中的变量
    variables = find_variables(test_dir)
    if not variables:
        print(f"[fatal] no *_t*.npy files found in {test_dir}")
        return 2

    print(f"[info ] test .npy dir: {test_dir}")
    print(f"[info ] ref .npy dir:  {ref_dir}")
    print(f"[info ] relative tolerance: {args.rel_tol:.1e}\n")

    # 打印表头
    header = f"{'variable':<10}{'t':>4}  {'shape':<22}{'max|Δ|':>12}  {'rel':>11}  status"
    print(header)
    print("-" * len(header))

    n_pass = n_fail = n_skip = 0
    bad_items: List[str] = []
    for var in variables:
        for v, t, shape, mxabs, rel, status in compare_variable(var, test_dir, ref_dir, args.rel_tol):
            shape_str = str(shape) if shape is not None else "-"

            if status in ("EQUAL", "OK"):
                line = f"{v:<10}{t:>4}  {shape_str:<22}{mxabs:>12.3e}  {rel:>11.3e}  {status}"
                n_pass += 1
            elif status == "DIFF":
                line = f"{v:<10}{t:>4}  {shape_str:<22}{mxabs:>12.3e}  {rel:>11.3e}  {status}"
                n_fail += 1
                bad_items.append(f"{v}[t={t}] rel={rel:.3e}")
            else:
                line = f"{v:<10}{t:>4}  {shape_str:<22}{'-':>12}  {'-':>11}  {status}"
                n_skip += 1
                bad_items.append(f"{v}[t={t}] {status}")
            print(line)

    print()
    print(f"[summary] pass={n_pass}  fail={n_fail}  skip={n_skip}")
    if n_fail or n_skip:
        print("[summary] failing / skipped items:")
        for item in bad_items:
            print(f"   - {item}")
        return 1

    print(f"[summary] all timesteps agree with {ref_dir} within rel<{args.rel_tol:.0e}")
    return 0


if __name__ == "__main__":
    sys.exit(main())

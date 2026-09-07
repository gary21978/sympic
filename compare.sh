#!/bin/bash
# compare.sh — 完整回归测试：调用 run.sh 运行算例并生成 test_npy/，再与 result_npy/ 对比
# 用法:
#     bash compare.sh <case_directory>
# 例如:
#     bash compare.sh case/template_cuda
#     bash compare.sh /absolute/path/to/case


set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 算例目录为必填参数
if [ "$#" -lt 1 ]; then
    echo "[fatal] missing case directory argument"
    echo "usage: bash $0 <case_directory>"
    exit 1
fi

# 解析算例目录：支持相对路径（基于 repo 根）或绝对路径
CASE_DIR="$1"
if [[ "${CASE_DIR}" = /* ]]; then
    CASE_DIR_ABS="${CASE_DIR}"
else
    CASE_DIR_ABS="${SCRIPT_DIR}/${CASE_DIR}"
fi

if [ ! -d "${CASE_DIR_ABS}" ]; then
    echo "[fatal] case directory not found: ${CASE_DIR_ABS}"
    exit 1
fi
if [ ! -f "${CASE_DIR_ABS}/test.ss" ]; then
    echo "[fatal] test.ss not found in ${CASE_DIR_ABS}"
    exit 1
fi

# 1. 运行算例并生成 test_npy/
bash "${SCRIPT_DIR}/run.sh" "${CASE_DIR}"

echo ""
echo "--- 对比 .npy 结果 ---"
REF_NPY_DIR="${CASE_DIR_ABS}/result_npy"
if [ ! -d "${REF_NPY_DIR}" ]; then
    echo "[warn ] reference npy directory not found: ${REF_NPY_DIR}"
    echo "[warn ] skip comparison"
else
    python3 "${SCRIPT_DIR}/scripts/compare_to_result_npy.py" \
        --test-dir "${SCRIPT_DIR}/build/test/test_npy" \
        --ref-dir "${REF_NPY_DIR}"
fi

echo ""
echo "=== 全部测试流程结束 ==="

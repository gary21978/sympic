#!/bin/bash
# compare.sh — 一键比较结果: 运行算例并对比 CUDA / NVScale 输出
# 用法:
#   bash compare.sh <case>                # 两个后端都运行: 互相对比, 再与 result_npy 对比
#   bash compare.sh <case> cuda           # 只运行 cuda, 与 result_npy 对比
#   bash compare.sh <case> nvscale        # 只运行 nvscale, 与 result_npy 对比
#   bash compare.sh <case> both --no-run  # 不重新运行, 直接比较已有的 test_npy

set -uo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

usage() {
    cat <<'EOF'
用法:
  bash compare.sh <case>                # 两个后端都运行: 互相对比, 再与 result_npy 对比
  bash compare.sh <case> cuda           # 只运行 cuda, 与 result_npy 对比
  bash compare.sh <case> nvscale        # 只运行 nvscale, 与 result_npy 对比
  bash compare.sh <case> both --no-run  # 不重新运行, 直接比较已有的 test_npy
EOF
}

if [ "$#" -lt 1 ]; then
    echo "[fatal] missing case directory argument"
    usage
    exit 1
fi

CASE_DIR="$1"
BACKEND="both"
NO_RUN=0

for arg in "${@:2}"; do
    case "${arg}" in
        cuda|nvscale|both) BACKEND="${arg}" ;;
        --no-run)          NO_RUN=1 ;;
        -h|--help)         usage; exit 0 ;;
        *)
            echo "[fatal] unknown argument: ${arg}"
            usage
            exit 1
            ;;
    esac
done

# 解析算例目录：支持相对路径（基于 repo 根）或绝对路径
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

# 参与比较的后端列表
MODES=()
if [ "${BACKEND}" != "nvscale" ]; then MODES+=(cuda); fi
if [ "${BACKEND}" != "cuda" ]; then MODES+=(nvscale); fi

build_dir() {
    if [ "$1" = "cuda" ]; then
        echo "${SCRIPT_DIR}/build"
    else
        echo "${SCRIPT_DIR}/build-nvscale"
    fi
}

FAIL=0

# 1. 运行算例（或检查现成结果）
for m in "${MODES[@]}"; do
    NPY_DIR="$(build_dir "$m")/test/test_npy"
    if [ "${NO_RUN}" -eq 1 ]; then
        if [ ! -d "${NPY_DIR}" ]; then
            echo "[fatal] 没有现成结果: ${NPY_DIR}"
            echo "请先执行: bash ${SCRIPT_DIR}/run.sh ${CASE_DIR} ${m}"
            exit 1
        fi
        echo "=== 使用现成结果 (${m}): ${NPY_DIR} ==="
    else
        echo ""
        echo "========== 运行算例 (${m}) =========="
        if ! bash "${SCRIPT_DIR}/run.sh" "${CASE_DIR}" "${m}"; then
            echo "[fatal] run.sh 失败 (${m})"
            FAIL=1
        fi
    fi
done

echo ""

# 2. 两个后端互相对比
if [ "${#MODES[@]}" -eq 2 ]; then
    CUDA_NPY="$(build_dir cuda)/test/test_npy"
    NVSCALE_NPY="$(build_dir nvscale)/test/test_npy"
    if [ -d "${CUDA_NPY}" ] && [ -d "${NVSCALE_NPY}" ]; then
        echo "--- 交叉对比: cuda vs nvscale ---"
        if ! python3 "${SCRIPT_DIR}/scripts/compare_to_result_npy.py" \
            --test-dir "${CUDA_NPY}" \
            --ref-dir "${NVSCALE_NPY}"; then
            FAIL=1
        fi
        echo ""
    else
        echo "[warn ] 缺少 ${CUDA_NPY} 或 ${NVSCALE_NPY}, 跳过交叉对比"
    fi
fi

# 3. 与参考结果 result_npy 对比
REF_NPY_DIR="${CASE_DIR_ABS}/result_npy"
if [ -d "${REF_NPY_DIR}" ]; then
    for m in "${MODES[@]}"; do
        NPY_DIR="$(build_dir "$m")/test/test_npy"
        if [ ! -d "${NPY_DIR}" ]; then
            continue
        fi
        echo "--- 参考对比: ${m} vs result_npy ---"
        if ! python3 "${SCRIPT_DIR}/scripts/compare_to_result_npy.py" \
            --test-dir "${NPY_DIR}" \
            --ref-dir "${REF_NPY_DIR}"; then
            FAIL=1
        fi
        echo ""
    done
else
    echo "[warn ] 未找到参考结果目录: ${REF_NPY_DIR}, 跳过参考对比"
fi

echo "=== 比较结束 ==="
if [ "${FAIL}" -ne 0 ]; then
    echo "=== 存在差异或失败项, 请检查上方输出 ==="
    exit 1
fi
echo "=== 全部结果一致 ==="

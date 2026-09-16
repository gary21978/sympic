#!/bin/bash
# compare.sh — 完整回归测试：调用 run.sh 运行算例并生成 test_npy/，再与 result_npy/ 对比
# 用法:
#     bash compare.sh [case_directory ...] [--build-dir <目录>]
# 例如:
#     bash compare.sh
#     bash compare.sh case/nh3
#     bash compare.sh case/nh3 case/demo-64 --build-dir build


set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

BUILD_DIR_ARG="${SYMPIC_BUILD_DIR:-}"
CASES=()
while [[ $# -gt 0 ]]; do
    case "$1" in
        --build-dir)
            if [[ $# -lt 2 ]]; then
                echo "[fatal] --build-dir missing argument" >&2
                exit 1
            fi
            BUILD_DIR_ARG="$2"
            shift 2
            ;;
        -h|--help)
            echo "usage: bash $0 [case_directory ...] [--build-dir <dir>]"
            exit 0
            ;;
        *)
            CASES+=("$1")
            shift
            ;;
    esac
done

if [[ ${#CASES[@]} -eq 0 ]]; then
    CASES=("case/nh3")
fi

if [[ -n "${BUILD_DIR_ARG}" ]]; then
    if [[ "${BUILD_DIR_ARG}" = /* ]]; then
        BUILD_DIR="${BUILD_DIR_ARG}"
    else
        BUILD_DIR="${SCRIPT_DIR}/${BUILD_DIR_ARG}"
    fi
elif [[ -d "${SCRIPT_DIR}/build" ]]; then
    BUILD_DIR="${SCRIPT_DIR}/build"
elif [[ -f "${SCRIPT_DIR}/.sympic-last-build" ]]; then
    BUILD_DIR="$(head -n 1 "${SCRIPT_DIR}/.sympic-last-build")"
else
    BUILD_DIR="${SCRIPT_DIR}/build-cuda"
fi

TOTAL_FAIL=0
for CASE_DIR in "${CASES[@]}"; do
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

    echo ""
    echo "=== Compare case: ${CASE_DIR} ==="
    bash "${SCRIPT_DIR}/run.sh" "${CASE_DIR}" --build-dir "${BUILD_DIR}"

    echo ""
    echo "--- 对比 .npy 结果 ---"
    REF_NPY_DIR="${CASE_DIR_ABS}/result_npy"
    if [ ! -d "${REF_NPY_DIR}" ]; then
        echo "[warn ] reference npy directory not found: ${REF_NPY_DIR}"
        echo "[warn ] skip comparison"
    else
        if ! python3 "${SCRIPT_DIR}/scripts/compare_to_result_npy.py" \
            --test-dir "${BUILD_DIR}/test/test_npy" \
            --ref-dir "${REF_NPY_DIR}"; then
            TOTAL_FAIL=$((TOTAL_FAIL + 1))
        fi
    fi
done

if [[ ${TOTAL_FAIL} -eq 0 ]]; then
    echo ""
    echo "=== all pass ==="
else
    echo ""
    echo "=== ${TOTAL_FAIL} case(s) failed ==="
    exit 1
fi

echo ""
echo "=== 全部测试流程结束 ==="

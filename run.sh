#!/bin/bash
# run.sh — 准备测试环境、运行 sympic 算例，并生成 test_npy/
# 用法:
#     bash run.sh <case_directory>
# 例如:
#     bash run.sh case/template_cuda
#     bash run.sh /absolute/path/to/case


_ORIGINAL_ARGS=("$@")
set --

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source ${SCRIPT_DIR}/scripts/env.sh
source ${VM_DRIVER_DIR}/maps-umd/setup_env.sh

export MALOG_STDOUT_LEVEL="error"
export MALOG_SIMPLE_FILE_LEVEL="error"
export MALOG_LEVEL="error"
export MAPS_API_LOG_ALWAYS=0

set -- "${_ORIGINAL_ARGS[@]}"
unset _ORIGINAL_ARGS

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"
TEST_DIR="${BUILD_DIR}/test"

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

echo "=== 使用算例目录: ${CASE_DIR_ABS} ==="
echo ""
echo "=== 1. 创建并清空测试目录 ==="
mkdir -p "${TEST_DIR}"
rm -rf "${TEST_DIR:?}"/*

echo "=== 2. 链接算例文件 ==="
for f in "${CASE_DIR_ABS}/"*; do
    [ -e "$f" ] || continue
    name=$(basename "$f")
    # 不链接参考结果目录和测试输出目录，run.sh 会自己生成 test_npy/
    if [ "${name}" = "result_npy" ] || [ "${name}" = "test_npy" ]; then
        continue
    fi
    ln -sf "$f" "${TEST_DIR}/${name}"
done

echo "=== 3. 链接可执行文件 ==="
ln -sf "${BUILD_DIR}/bin/sympic"     "${TEST_DIR}/sympic"
ln -sf "${BUILD_DIR}/bin/gapsio2to0" "${TEST_DIR}/gapsio2to0"

echo "=== 4. 链接 cscheme 标准库 ==="
ln -sf "${SCRIPT_DIR}/src/stdlib.scm"    "${TEST_DIR}/stdlib.scm"

echo "=== 5. 链接 pygapsio3.py ==="
ln -sf "${SCRIPT_DIR}/src/cgapsio/pygapsio3.py" "${TEST_DIR}/pygapsio3.py"



echo ""
echo "=== 测试环境准备完成，开始运行测试 ==="
echo "目录: ${TEST_DIR}"
echo ""

cd "${TEST_DIR}"
echo "--- 运行 sympic ---"
export STDLIB="${TEST_DIR}/stdlib.scm"
export OMP_NUM_THREADS=1
mpirun --allow-run-as-root --oversubscribe -n 1 "${TEST_DIR}/sympic" test.ss 

echo ""
echo "--- 合并 GAPSIO 分片 ---"
for var in tmpEB tmpEN tmpJ; do
    if ls "${var}_PROC_"* 1>/dev/null 2>&1; then
        rm -f "${var}"
        mpirun --allow-run-as-root --oversubscribe -n 1 "${TEST_DIR}/gapsio2to0" ${var}_PROC_* "${var}"
    else
        echo "[warn ] no PROC shards for ${var}"
    fi
done

echo ""
echo "--- 转换为 .npy ---"
rm -f "${TEST_DIR}/test_npy"
mkdir -p "${TEST_DIR}/test_npy"
python3 "${SCRIPT_DIR}/scripts/gapsio_to_npy.py" --work-dir "${TEST_DIR}" --out-dir "${TEST_DIR}/test_npy"

echo ""
echo "=== 算例运行结束 ==="
echo "输出分片目录: ${TEST_DIR}"
echo "转换后的 .npy 目录: ${TEST_DIR}/test_npy"

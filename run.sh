#!/bin/bash

set -euo pipefail


# ---------- 默认值 ----------
ENABLE_MASIGHT=0
CASE_PATH=""          # 必填：算例路径

# ---------- 用法说明 ----------
usage() {
    cat <<EOF
用法: $0 <算例路径> [--masight]

参数:
  <算例路径>     必填，算例所在目录的路径
  --masight     可选，启用 masight 性能分析工具
  -h, --help    显示本帮助信息

示例:
  $0 /data/cases/demo01
  $0 /data/cases/demo01 --masight
EOF
}

# ---------- 参数解析 ----------
while [[ $# -gt 0 ]]; do
    case "$1" in
        --masight)
            ENABLE_MASIGHT=1
            shift
            ;;
        -h|--help)
            usage
            exit 0
            ;;
        -*)
            echo "错误: 未知选项 '$1'" >&2
            usage >&2
            exit 1
            ;;
        *)
            if [[ -z "$CASE_PATH" ]]; then
                CASE_PATH="$1"
            else
                echo "错误: 多余的参数 '$1'" >&2
                usage >&2
                exit 1
            fi
            shift
            ;;
    esac
done

# ---------- 必填参数校验 ----------
if [[ -z "$CASE_PATH" ]]; then
    echo "错误: 缺少必填参数 <算例路径>" >&2
    usage >&2
    exit 1
fi

if [[ ! -d "$CASE_PATH" ]]; then
    echo "错误: 算例路径不存在或不是目录: $CASE_PATH" >&2
    exit 1
fi

export MALOG_STDOUT_LEVEL="error"
export MALOG_SIMPLE_FILE_LEVEL="error"
export MALOG_LEVEL="error"
export MAPS_API_LOG_ALWAYS=0
export SCALE_TOOLCHAIN_ROOT=/opt/maps/toolchain

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"
TEST_DIR="${BUILD_DIR}/test"

# 解析算例目录：支持相对路径（基于 repo 根）或绝对路径
if [[ "${CASE_PATH}" = /* ]]; then
    CASE_DIR_ABS="${CASE_PATH}"
else
    CASE_DIR_ABS="${SCRIPT_DIR}/${CASE_PATH}"
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
ln -sf "${BUILD_DIR}/bin/sympic.out"     "${TEST_DIR}/sympic.out"
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

if [[ $ENABLE_MASIGHT -eq 1 ]]; then
    echo "[run.sh] 已启用 masight 性能分析，算例路径: $CASE_DIR_ABS"
    macu -w 0 --spu --mpu --mpu-reserved-count 16 --output test_perf.json ${TEST_DIR}/sympic.out test.ss -G 8 -B 4 -N 65536
else
    echo "[run.sh] 正常运行，算例路径: $CASE_DIR_ABS"
    mpirun --allow-run-as-root --oversubscribe -n 1 "${TEST_DIR}/sympic.out" test.ss
fi

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

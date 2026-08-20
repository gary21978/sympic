#!/bin/bash
# build.sh — 创建/清空 build 目录并编译
# 用法: bash build.sh


_ORIGINAL_ARGS=("$@")
set --

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source ${SCRIPT_DIR}/scripts/env.sh
source ${VM_DRIVER_DIR}/maps-umd/setup_env.sh

set -- "${_ORIGINAL_ARGS[@]}"
unset _ORIGINAL_ARGS



set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"

if [ "$#" -lt 1 ]; then 
    echo "[fatal] missing build mode argument"
    echo "usage: bash $0 [cuda|mapu]"
    exit 1
fi

MODE="$1"
case "${MODE}" in
    cuda)
        CMAKE_FLAGS="-DSYMPIC_CUDA=ON -DSYMPIC_MAPU=OFF"
        ;;
    mapu)
        CMAKE_FLAGS="-DSYMPIC_CUDA=OFF -DSYMPIC_MAPU=ON"

        ;;
    *)
        echo "[fatal] unknown build mode: ${MODE}"
        echo "usage: bash $0 [cuda|mapu]"
        exit 1
        ;;    
esac

echo "===构建模式: ${MODE} ==="
echo "===CMake flags: ${CMAKE_FLAGS} ==="

echo "=== 1. 创建 build 目录 ==="
mkdir -p "${BUILD_DIR}"

echo "=== 2. 清空 build 目录 ==="
rm -rf "${BUILD_DIR:?}"/*

echo "=== 3. 运行 cmake ==="
cd "${BUILD_DIR}"


cmake .. ${CMAKE_FLAGS}

echo "=== 4. 执行 make -j16 > build.log 2>&1 ==="
make -j16

echo ""
echo "=== 构建完成 ==="

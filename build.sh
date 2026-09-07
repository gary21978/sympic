#!/bin/bash
# build.sh — 创建/清空对应后端 build 目录并编译
# 用法: bash build.sh [cuda|mapu|nvscale]



set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"


export SCALE_TOOLCHAIN_ROOT=/opt/maps/toolchain


if [ "$#" -lt 1 ]; then 
    echo "[fatal] missing build mode argument"
    echo "usage: bash $0 [cuda|mapu|nvscale]"
    exit 1
fi

MODE="$1"
case "${MODE}" in
    cuda)
        BUILD_DIR="${SCRIPT_DIR}/build-cuda"
        CMAKE_FLAGS="-DSYMPIC_CUDA=ON -DSYMPIC_MAPU=OFF"
        ;;
    mapu)
        BUILD_DIR="${SCRIPT_DIR}/build-mapu"
        CMAKE_FLAGS="-DSYMPIC_CUDA=OFF -DSYMPIC_MAPU=ON"

        ;;
    nvscale)
        BUILD_DIR="${SCRIPT_DIR}/build-nvscale"
        NVSCALE_ROOT="${NVSCALE_ROOT:-/home/cheney/Projects/MaPU/toolchain/nvscale}"
        NVSCALE_CUDA_ARCH="${NVSCALE_CUDA_ARCH:-89}"
        CMAKE_FLAGS="-DSYMPIC_CUDA=OFF -DSYMPIC_MAPU=OFF -DSYMPIC_NVSCALE=ON -DNVSCALE_ROOT=${NVSCALE_ROOT} -DNVSCALE_CUDA_ARCH=${NVSCALE_CUDA_ARCH} -DCUDA_ARCH=sm_${NVSCALE_CUDA_ARCH}"
        ;;
    *)
        echo "[fatal] unknown build mode: ${MODE}"
        echo "usage: bash $0 [cuda|mapu|nvscale]"
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
echo "${BUILD_DIR}" > "${SCRIPT_DIR}/.sympic-last-build"
echo "=== 当前默认运行目录: ${BUILD_DIR} ==="

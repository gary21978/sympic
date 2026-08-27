#!/bin/bash
# build.sh — 一键编译 CUDA 与 NVScale 版本
#
# 用法:
#   bash build.sh               # 编译全部: cuda -> build/, nvscale -> build-nvscale/
#   bash build.sh cuda          # 只编译 CUDA 版本
#   bash build.sh nvscale       # 只编译 NVScale 版本
#
# 选项:
#   --arch <n>    CUDA 架构 (默认 86, 即 sm_86)
#   --jobs <n>    并行编译数 (默认 nproc)
#   --clean       编译前清空构建目录
#   --cuda-cluster  NVScale 保留 CUDA/Hopper __cluster_dims__ (需要 sm_90+)

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

ARCH="${CUDA_ARCH:-86}"
JOBS="$(nproc)"
CLEAN=0
CUDA_CLUSTER="${NVSCALE_USE_CUDA_CLUSTER:-OFF}"
BUILD_CUDA=0
BUILD_NVSCALE=0

usage() {
    cat <<'EOF'
用法:
  bash build.sh               # 编译全部: cuda -> build/, nvscale -> build-nvscale/
  bash build.sh cuda          # 只编译 CUDA 版本
  bash build.sh nvscale       # 只编译 NVScale 版本

选项:
  --arch <n>    CUDA 架构 (默认 86, 即 sm_86)
  --jobs <n>    并行编译数 (默认 nproc)
  --clean       编译前清空构建目录
  --cuda-cluster  NVScale 保留 CUDA/Hopper __cluster_dims__ (需要 sm_90+)
EOF
}

while [ "$#" -gt 0 ]; do
    case "$1" in
        cuda)    BUILD_CUDA=1 ;;
        nvscale) BUILD_NVSCALE=1 ;;
        all)     BUILD_CUDA=1; BUILD_NVSCALE=1 ;;
        --arch)  ARCH="$2"; shift ;;
        --jobs|-j) JOBS="$2"; shift ;;
        --clean) CLEAN=1 ;;
        --cuda-cluster) CUDA_CLUSTER=ON ;;
        -h|--help) usage; exit 0 ;;
        *)
            echo "[fatal] 未知参数: $1" >&2
            usage >&2
            exit 1
            ;;
    esac
    shift
done

if ! [[ "${ARCH}" =~ ^[0-9]+$ ]]; then
    echo "[fatal] --arch 必须是数字, 例如 86" >&2
    exit 1
fi

# 无参数默认全部编译
if [ "${BUILD_CUDA}" -eq 0 ] && [ "${BUILD_NVSCALE}" -eq 0 ]; then
    BUILD_CUDA=1
    BUILD_NVSCALE=1
fi

build_cuda() {
    local dir="${SCRIPT_DIR}/build"
    echo ""
    echo "========== 编译 CUDA 版本 (arch=sm_${ARCH}) -> ${dir} =========="
    if [ "${CLEAN}" -eq 1 ]; then
        echo "=== 清空构建目录 ==="
        rm -rf "${dir:?}"/*
    fi
    cmake -S "${SCRIPT_DIR}" -B "${dir}" \
        -DSYMPIC_CUDA=ON -DSYMPIC_MAPU=OFF \
        -DCUDA_ARCH="sm_${ARCH}"
    cmake --build "${dir}" -j"${JOBS}"
    echo "=== CUDA 版本编译完成 ==="
    ls -l "${dir}/bin/sympic" "${dir}/bin/gapsio2to0"
}

build_nvscale() {
    local dir="${SCRIPT_DIR}/build-nvscale"
    echo ""
    echo "========== 编译 NVScale 版本 (arch=${ARCH}) -> ${dir} =========="
    if [ "${CLEAN}" -eq 1 ]; then
        echo "=== 清空构建目录 ==="
        rm -rf "${dir:?}"/*
    fi
    cmake -S "${SCRIPT_DIR}/cmake/sympic-nvscale" -B "${dir}" \
        -DSYMPIC_SOURCE_DIR="${SCRIPT_DIR}" \
        -DNVSCALE_CUDA_ARCH="${ARCH}" \
        -DNVSCALE_USE_CUDA_CLUSTER="${CUDA_CLUSTER}"
    cmake --build "${dir}" -j"${JOBS}"
    echo "=== NVScale 版本编译完成 ==="
    ls -l "${dir}/bin/sympic" "${dir}/bin/gapsio2to0"
}

echo "=== SymPIC 一键编译: arch=${ARCH} jobs=${JOBS} clean=${CLEAN} ==="
if [ "${BUILD_CUDA}" -eq 1 ]; then
    build_cuda
fi
if [ "${BUILD_NVSCALE}" -eq 1 ]; then
    build_nvscale
fi

echo ""
echo "=== 全部编译完成 ==="

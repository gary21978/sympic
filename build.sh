#!/bin/bash
# build.sh — 创建/清空 build 目录并编译
# 用法: bash build.sh

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"

echo "=== 1. 创建 build 目录 ==="
mkdir -p "${BUILD_DIR}"

echo "=== 2. 清空 build 目录 ==="
rm -rf "${BUILD_DIR:?}"/*

echo "=== 3. 运行 cmake ==="
cd "${BUILD_DIR}"
cmake ..

echo "=== 4. 执行 make ==="
make -j6

echo ""
echo "=== 构建完成 ==="

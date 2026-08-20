#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "${SCRIPT_DIR}/.." && pwd)"
BUILD_DIR="${1:-${ROOT_DIR}/build-nvscale}"
CUDA_ARCH="${CUDA_ARCH:-86}"
JOBS="${BUILD_JOBS:-$(nproc)}"

cmake -S "${ROOT_DIR}/cmake/sympic-nvscale" -B "${BUILD_DIR}" \
  -DSYMPIC_SOURCE_DIR="${ROOT_DIR}" \
  -DNVSCALE_CUDA_ARCH="${CUDA_ARCH}"
cmake --build "${BUILD_DIR}" -j"${JOBS}"


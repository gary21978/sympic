#!/bin/bash
set -euo pipefail

TEST_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
NVSCALE_DIR="$(cd "${TEST_DIR}/.." && pwd)"
OUTPUT="${TMPDIR:-/tmp}/nvscale-guide-compat-${USER:-user}"

"${NVSCALE_DIR}/bin/nvscale-nvcc" -std=c++14 -arch=sm_86 \
  "${TEST_DIR}/guide_compat.cu" -o "${OUTPUT}"
"${OUTPUT}"
unlink "${OUTPUT}"

echo "NVScale guide compatibility test passed"

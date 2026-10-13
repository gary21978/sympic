#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
./compare_gapsio --test-dir result --ref-dir "$1" \
  2>&1 | tee result/compare.log

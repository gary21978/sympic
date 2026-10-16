#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"
OUT="${1:-validation/dual-pushj}"
OUT="$(mkdir -p "$(dirname "$OUT")" && cd "$(dirname "$OUT")" && pwd)/$(basename "$OUT")"

# Build and run the two-device baseline path first.
bash build.sh mapu-baseline
cmake --build build-mapu-baseline --target compare_gapsio --parallel 8
bash run.sh case/dual --np 2 --build-dir build-mapu-baseline
mkdir -p "$OUT"
rm -rf "$OUT/baseline"
cp -a build-mapu-baseline/test "$OUT/baseline"

# Build frozen PushJ and run the same dual-device workload through it.
bash build.sh mapu-pushj
bash run.sh case/dual --np 2 --build-dir build-mapu-pushj
rm -rf "$OUT/pushj"
cp -a build-mapu-pushj/test "$OUT/pushj"

# Compare all merged field/current files with the baseline result.
build-mapu-pushj/bin/compare_gapsio --test-dir "$OUT/pushj" --ref-dir "$OUT/baseline"
echo "Simulator baseline and PushJ runs completed; outputs: $OUT"

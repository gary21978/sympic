#!/bin/bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR_ARG="${SYMPIC_BUILD_DIR:-}"
CASE_PATH=""
MPI_RANKS=1

# Keep only GAPSIO output;
while [[ $# -gt 0 ]]; do
  case "$1" in
    --np) MPI_RANKS="$2"; shift 2;;
    --build-dir) BUILD_DIR_ARG="$2"; shift 2;;
    -h|--help) echo "usage: $0 CASE [--np N] [--build-dir DIR]"; exit 0;;
    *)
      [[ -z "$CASE_PATH" ]] || { echo "extra argument: $1" >&2; exit 2; }
      CASE_PATH="$1"
      shift
      ;;
  esac
done

# The case path may be relative to the repository or absolute.
[[ -n "$CASE_PATH" ]] || { echo "case is required" >&2; exit 2; }
[[ "$CASE_PATH" = /* ]] && CASE="$CASE_PATH" || CASE="$SCRIPT_DIR/$CASE_PATH"

# Select the build directory: explicit argument > last-build record > default directories.
if [[ -n "$BUILD_DIR_ARG" ]]; then
  [[ "$BUILD_DIR_ARG" = /* ]] && BUILD="$BUILD_DIR_ARG" || BUILD="$SCRIPT_DIR/$BUILD_DIR_ARG"
elif [[ -f "$SCRIPT_DIR/.sympic-last-build" ]]; then
  BUILD="$(head -n1 "$SCRIPT_DIR/.sympic-last-build")"
elif [[ -d "$SCRIPT_DIR/build-nvscale" ]]; then
  BUILD="$SCRIPT_DIR/build-nvscale"
else
  BUILD="$SCRIPT_DIR/build-cuda"
fi

# Clear the shared test directory to prevent stale shards from being reused.
TEST="$BUILD/test"
rm -rf "${TEST:?}"
mkdir -p "$TEST"

# Link case input files; reference-result directories are excluded.
for f in "$CASE"/*; do
  [[ -e "$f" ]] || continue
  n="$(basename "$f")"
  [[ "$n" == result_npy || "$n" == result_gapsio || "$n" == test_npy ]] && continue
  ln -sf "$f" "$TEST/$n"
done

# Link the executable and the Scheme standard library.
ln -sf "$BUILD/bin/sympic" "$TEST/sympic"
ln -sf "$BUILD/bin/gapsio2to0" "$TEST/gapsio2to0"
ln -sf "$SCRIPT_DIR/src/stdlib.scm" "$TEST/stdlib.scm"

cd "$TEST"
export STDLIB="$TEST/stdlib.scm"
export OMP_NUM_THREADS=1
export SYMPIC_INIT_PARTICLE_GPU_FAST=1

mpirun --allow-run-as-root --oversubscribe \
  -n "$MPI_RANKS" "$TEST/sympic" test.ss

# Merge MPI/GAPSIO shards for each variable into one GAPSIO v0 file.
for var in tmpEB tmpEN tmpJ; do
  if compgen -G "${var}_PROC_*" >/dev/null; then
    rm -f "$var"
    mpirun --allow-run-as-root --oversubscribe \
      -n 1 "$TEST/gapsio2to0" ${var}_PROC_* "$var"
  fi
done

echo "[done] merged GAPSIO files are in $TEST"

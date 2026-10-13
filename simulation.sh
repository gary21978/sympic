#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
BASE="$PWD"
NP="${1:?usage: ./simulation.sh NP INPUT.ss}"
INPUT="$BASE/${2:?missing INPUT.ss}"
[[ -f "$INPUT" ]] || { echo "Missing input: $INPUT" >&2; exit 1; }
export STDLIB="$BASE/stdlib.scm"
export OMP_NUM_THREADS=1 INIT_FAST=1
export MALOG_FORCE_LEVEL=error
export MALOG_LEVEL=scalehost=error
export MALOG_SIMPLE_FILE_LEVEL=scalehost=error
mkdir -p result
cd result
mpirun --allow-run-as-root --oversubscribe -n "$NP" \
  "$BASE/sympic" "$INPUT" 2>&1 | tee run.log

"$BASE/gapsio2to0" tmpEB_PROC_* tmpEB
"$BASE/gapsio2to0" tmpEN_PROC_* tmpEN
"$BASE/gapsio2to0" tmpJ_PROC_* tmpJ

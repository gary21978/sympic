#!/bin/bash
set -euo pipefail
export CPATH="${CPATH:+$CPATH:}./"
make all_dirs_prev -j8 && make all_dirs -j8 && make -j8

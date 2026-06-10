#!/bin/bash
# allCleanBuild_cuda.sh — 纯 C/CUDA 构建：不删 .c/.cu/.h，不调用 SCMC/PSCMC
# 设备后端仍编 c_/openmp_/cuda_ 三个静态库（主机 .c 链接期需要 c_* / openmp_* 符号）；
# 算例 GET_DEV_TYPE=2 时运行时只走 cuda_*。仅改 CUDA 内核时可用：./allCleanBuild_cuda.sh rebuild_cuda
#
# Integrated source profiling (Nsight Compute Source view):
#   ./allCleanBuild_cuda.sh --profile rebuild_cuda
#   → nvcc -lineinfo on cuda_ (no -G). Then profile the main kernel, e.g.:
#   ncu --set full -k cuda_geo_nr_Bfield_pushJ_vlo -o my_profile_report \
#       mpirun --oversubscribe -n 1 ./sympic runCases/template_cuda/test.ss
#   Open my_profile_report.ncu-rep → Source → inner_split_pass.kernel.cu

###用法示例：
# 仅重编 cuda_（推荐，改内核后）
# ./allCleanBuild_cuda.sh --profile rebuild_cuda --no-regression
# 全量 clean + 重编
# ./allCleanBuild_cuda.sh --profile all --no-regression
#
# 所有输出写入项目根目录 build.log（同时打印到终端）:
#   ./allCleanBuild_cuda.sh rebuild_cuda 2>&1 | tee build.log   # 等价于脚本内置 tee

set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$ROOT"
export CPATH="${CPATH:+$CPATH:}./"
BUILD_LOG="${ROOT}/build.log"

CUDA_SOURCE_PROFILE="${CUDA_SOURCE_PROFILE:-0}"
CUDA_PTXAS_VERBOSE="${CUDA_PTXAS_VERBOSE:-0}"
CUDA_ARCH="${CUDA_ARCH:-}"
CUDA_DUMP_CUBIN="${CUDA_DUMP_CUBIN:-0}"
ACTION=""
SKIP_REGRESSION=0

usage() {
  cat <<EOF
usage: $0 [--profile] [--ptxas-verbose] [--arch sm_86] [--dump-cubin] [clean|rebuild|rebuild_cuda|regression|all]
       $0 [--profile] [--ptxas-verbose] rebuild_cuda --no-regression

  --profile, -p     Build cuda_ with nvcc -lineinfo for Nsight Compute source mapping
                    (CUDA_SOURCE_PROFILE=1). Do not use -G; optimizations stay on.
  --ptxas-verbose   Add nvcc flag: -Xptxas -v (prints regs/stack/spills per kernel)
  --arch <sm_xy>    Override CUDA arch for nvcc (default from cuda_/RUNTIME_SPEC.mk)
  --dump-cubin      Build a standalone cubin for cuda_/inner_split_pass.kernel.cu and
                    dump SASS + resource usage to runCases/profile-<timestamp>/

  all               — clean + full rebuild + template_cuda regression (default)
  rebuild           — full device rebuild + regression
  rebuild_cuda      — cuda_ only + relink + regression (needs existing c_/openmp_ .a)
  regression        — copy template_cuda, run_gpu, merge_and_compare only
  --no-regression   — skip template_cuda regression (only with rebuild/rebuild_cuda/all)
EOF
}

parse_args() {
  while [[ $# -gt 0 ]]; do
    case "$1" in
      --profile|-p|profile)
        CUDA_SOURCE_PROFILE=1
        ;;
      --ptxas-verbose|--ptxas|-vptxas)
        CUDA_PTXAS_VERBOSE=1
        ;;
      --arch)
        shift
        CUDA_ARCH="${1:-}"
        if [[ -z "${CUDA_ARCH}" ]]; then
          echo "error: --arch requires an argument like sm_86" >&2
          exit 1
        fi
        ;;
      --dump-cubin)
        CUDA_DUMP_CUBIN=1
        ;;
      --no-regression)
        SKIP_REGRESSION=1
        ;;
      clean|rebuild|rebuild_cuda|regression|all)
        if [[ -n "$ACTION" ]]; then
          echo "error: duplicate action '$1'" >&2
          usage
          exit 1
        fi
        ACTION="$1"
        ;;
      -h|--help|help)
        usage
        exit 0
        ;;
      *)
        echo "error: unknown argument '$1'" >&2
        usage
        exit 1
        ;;
    esac
    shift
  done
  ACTION="${ACTION:-all}"
}

export_cuda_profile() {
  if [[ "${CUDA_SOURCE_PROFILE:-0}" == "1" ]]; then
    export CUDA_SOURCE_PROFILE=1
    echo "=== CUDA source profiling build: nvcc -lineinfo (CUDA_SOURCE_PROFILE=1) ==="
  fi
}

export_cuda_flags() {
  if [[ "${CUDA_PTXAS_VERBOSE:-0}" == "1" ]]; then
    export CUDA_PTXAS_VERBOSE=1
    echo "=== CUDA ptxas verbose: -Xptxas -v (CUDA_PTXAS_VERBOSE=1) ==="
  fi
  if [[ -n "${CUDA_ARCH:-}" ]]; then
    export CUDA_ARCH
    echo "=== CUDA arch override: CUDA_ARCH=${CUDA_ARCH} ==="
  fi
}

dump_inner_split_cubin() {
  if [[ "${CUDA_DUMP_CUBIN:-0}" != "1" ]]; then
    return 0
  fi
  command -v nvcc >/dev/null 2>&1 || { echo "error: nvcc not found" >&2; return 1; }
  command -v cuobjdump >/dev/null 2>&1 || { echo "error: cuobjdump not found" >&2; return 1; }

  local ts
  ts="$(date +%Y%m%d_%H%M%S)"
  local out_dir="${ROOT}/runCases/profile-${ts}"
  mkdir -p "${out_dir}"

  local arch="${CUDA_ARCH:-}"
  if [[ -z "${arch}" ]]; then
    # Keep consistent with cuda_/RUNTIME_SPEC.mk default.
    arch="sm_75"
  fi

  local cubin="${out_dir}/inner_split_pass.kernel.${arch}.cubin"
  local sass="${out_dir}/inner_split_pass.kernel.${arch}.sass"
  local res="${out_dir}/inner_split_pass.kernel.${arch}.resource.txt"
  local regs="${out_dir}/inner_split_pass.kernel.${arch}.regs.txt"

  echo "=== dump cubin/sass/resource (arch=${arch}) ==="
  echo ">>> nvcc -O3 -arch=${arch} -lineinfo -cubin cuda_/inner_split_pass.kernel.cu -o ${cubin}"
  nvcc -O3 -arch="${arch}" -lineinfo \
    -I"${ROOT}" -I/usr/local/cuda/include \
    -cubin "${ROOT}/cuda_/inner_split_pass.kernel.cu" \
    -o "${cubin}"

  echo ">>> cuobjdump --dump-sass ${cubin} > ${sass}"
  cuobjdump --dump-sass "${cubin}" > "${sass}"

  echo ">>> cuobjdump --dump-resource-usage ${cubin} > ${res}"
  cuobjdump --dump-resource-usage "${cubin}" > "${res}"

  # This is NOT exact reg count; it's the max register index observed in SASS.
  echo ">>> extract register names (R*) to ${regs}"
  grep -oE 'R[0-9]+' "${sass}" | sort -t'R' -k2 -n | tail -50 > "${regs}" || true

  echo "=== dumped ==="
  echo "  cubin: ${cubin}"
  echo "  sass : ${sass}"
  echo "  res  : ${res}"
  echo "  regs : ${regs}"
}

print_ncu_hint() {
  if [[ "${CUDA_SOURCE_PROFILE:-0}" != "1" ]]; then
    return 0
  fi
  cat <<EOF

=== Nsight Compute (integrated source profiling) ===
Profile the main kernel (example from runCases/template_cuda):
  cd ${ROOT}/runCases/template_cuda
  ncu --set full -k cuda_geo_nr_Bfield_pushJ_vlo -o my_profile_report \\
      mpirun --oversubscribe -n 1 ${ROOT}/sympic test.ss

Open my_profile_report.ncu-rep in Nsight Compute UI → Source → inner_split_pass.kernel.cu
→ pushJ_vlo_K3_deposit_writeback_* for line-level metrics inside the main loop.

EOF
}

do_clean() {
  echo "=== clean (native) ==="
  echo ">>> make clean"
  make clean
  rm -rf .deps
  rm -f c_yeefdtd.a openmp_yeefdtd.a cuda_yeefdtd.a \
    c_yeefdtd.h openmp_yeefdtd.h cuda_yeefdtd.h
  for d in c_ openmp_ cuda_; do
    if [ -d "$d" ]; then
      echo ">>> make -C $d clean"
      make -C "$d" clean
    fi
  done
  echo ">>> make -C smallmpi clean"
  make -C smallmpi clean
  echo ">>> make -C cgapsio clean"
  make -C cgapsio clean
}

do_rebuild() {
  echo "=== rebuild (full: c_ + openmp_ + cuda_) ==="
  echo ">>> make all_dirs_prev -j8"
  make all_dirs_prev -j8
  echo ">>> make all_dirs -j8"
  make all_dirs -j8
  echo ">>> make -j8 sympic"
  make -j8 sympic
  ls -la sympic
  print_ncu_hint
}

do_rebuild_cuda() {
  echo "=== rebuild_cuda (cuda_ only + relink sympic) ==="
  test -f c_yeefdtd.a && test -f openmp_yeefdtd.a || {
    echo "error: need c_yeefdtd.a and openmp_yeefdtd.a — run full rebuild first" >&2
    return 1
  }
  echo ">>> make -C cuda_ -j8"
  make -C cuda_ -j8
  echo ">>> make -j8 sympic"
  make -j8 sympic
  ls -la sympic
  print_ncu_hint
}

do_regression() {
  echo "=== regression (template_cuda) ==="
  local run_cases="${ROOT}/runCases"
  local template="${run_cases}/template_cuda"
  local case_name
  case_name="cuda_$(date +%Y%m%d_%H%M%S)"
  local case_dir="${run_cases}/${case_name}"

  if [[ ! -d "$template" ]]; then
    echo "error: missing template dir: $template" >&2
    return 1
  fi
  if [[ ! -x "${ROOT}/sympic" ]]; then
    echo "error: sympic not found — run rebuild first" >&2
    return 1
  fi

  export STDLIB="${ROOT}/stdlib.scm"
  export OMP_NUM_THREADS="${OMP_NUM_THREADS:-1}"

  cd "$run_cases"
  echo "[regression] copy template_cuda -> ${case_name}"
  cp -a "$template" "$case_dir"
  cd "$case_dir"

  echo "[regression] run_gpu.sh in $(pwd)"
  echo ">>> bash ./run_gpu.sh"
  bash ./run_gpu.sh

  echo "[regression] merge_and_compare.py"
  echo ">>> python3 ./merge_and_compare.py"
  python3 ./merge_and_compare.py
  local rc=$?
  echo "[regression] case_dir=${case_dir} exit=${rc}"
  return "$rc"
}

parse_args "$@"
export_cuda_profile
export_cuda_flags

# 每次运行覆盖 build.log，后续 stdout/stderr 同时写入终端与 build.log
echo "=== allCleanBuild_cuda.sh $(date -Iseconds) action=${ACTION} CUDA_SOURCE_PROFILE=${CUDA_SOURCE_PROFILE} CUDA_PTXAS_VERBOSE=${CUDA_PTXAS_VERBOSE} CUDA_ARCH=${CUDA_ARCH:-default} CUDA_DUMP_CUBIN=${CUDA_DUMP_CUBIN} ===" | tee "$BUILD_LOG"
exec > >(tee -a "$BUILD_LOG") 2>&1

case "$ACTION" in
  clean)         do_clean ;;
  rebuild)
    do_rebuild
    dump_inner_split_cubin
    if [[ "$SKIP_REGRESSION" == "0" ]]; then do_regression; fi
    ;;
  rebuild_cuda)
    do_rebuild_cuda
    dump_inner_split_cubin
    if [[ "$SKIP_REGRESSION" == "0" ]]; then do_regression; fi
    ;;
  regression)    do_regression ;;
  all)
    do_clean
    do_rebuild
    dump_inner_split_cubin
    if [[ "$SKIP_REGRESSION" == "0" ]]; then do_regression; fi
    ;;
  *)
    usage
    exit 1
    ;;
esac

#!/usr/bin/env bash
set -euo pipefail
nh=${1:?usage: ./run_case.sh <nh> <ngpu> [run_name]}
ngpu=${2:?usage: ./run_case.sh <nh> <ngpu> [run_name]}
run_name=${3:-nh${nh}_g${ngpu}}
case "$nh" in
  4) case_file=/data/chenli/perf/prof_nh4_s5_rt1_c2500.ss ;;
  5) case_file=/data/chenli/perf/prof_nh5_s5_rt1_c5000.ss ;;
  6) case_file=/data/chenli/perf/prof_nh6_s5_rt1_c10000.ss ;;
  *) echo "unsupported nh=$nh; supported: 4,5,6" >&2; exit 2 ;;
esac
gpus=$(seq -s, 0 $((ngpu - 1)))
export OMP_NUM_THREADS=1
export CUDA_VISIBLE_DEVICES="$gpus"
export SYMPIC_INIT_PARTICLE_GPU_FAST=1
export SYMPIC_PROFILE_TIMING=1
mpirun_bin=/usr/mpi/gcc/openmpi-4.1.7a1/bin/mpirun
root=$(cd "$(dirname "$0")" && pwd)
bin=$root/build/bin/sympic
stdlib=$root/stdlib.scm
run_dir=$root/runs/$run_name
mkdir -p "$run_dir"
cd "$run_dir"
echo "version=MPI nh=$nh ngpu=$ngpu CUDA_VISIBLE_DEVICES=$CUDA_VISIBLE_DEVICES"
echo "case=$case_file"
echo "log=$run_dir/run.log"
STDLIB="$stdlib" "$mpirun_bin" -n "$ngpu" "$bin" "$case_file" > run.log 2>&1
python3 ../../../parse_five_profile.py run.log

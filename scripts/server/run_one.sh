#!/usr/bin/env bash
set -euo pipefail
version=${1:?usage: ./run_one.sh <MPI|NCCL|MACCL> <nh> <ngpu> [run_name]}
nh=${2:?usage: ./run_one.sh <MPI|NCCL|MACCL> <nh> <ngpu> [run_name]}
ngpu=${3:?usage: ./run_one.sh <MPI|NCCL|MACCL> <nh> <ngpu> [run_name]}
run_name=${4:-nh${nh}_g${ngpu}}
case "$version" in
  MPI|NCCL|MACCL) ;;
  *) echo "unsupported version=$version; supported: MPI, NCCL, MACCL" >&2; exit 2 ;;
esac
root=$(cd "$(dirname "$0")" && pwd)
exec "$root/$version/run_case.sh" "$nh" "$ngpu" "$run_name"

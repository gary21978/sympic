#!/usr/bin/env bash
set -euo pipefail
nh=${1:?usage: ./run_all.sh <nh> <ngpu> [run_tag]}
ngpu=${2:?usage: ./run_all.sh <nh> <ngpu> [run_tag]}
tag=${3:-nh${nh}_g${ngpu}}
root=$(cd "$(dirname "$0")" && pwd)
for version in MPI NCCL MACCL; do
  echo "===== $version nh=$nh ngpu=$ngpu ====="
  "$root/$version/run_case.sh" "$nh" "$ngpu" "$tag"
done

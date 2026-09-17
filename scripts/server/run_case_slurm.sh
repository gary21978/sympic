#!/usr/bin/env bash
# run_case_slurm.sh — 通过 SLURM (sbatch) 启动 NCCL 版 sympic 算例
# 用法: ./run_case_slurm.sh <nh> <ngpu> [run_name]
#
# 与 run_case.sh 相比的变化:
#   1. 不再手动 export CUDA_VISIBLE_DEVICES，改由 SLURM 按 --gres=gpu:N 自动设置
#      (sympic 的选卡逻辑是 dev_id=MPI rank 的逻辑设备号，与 SLURM 分配完全兼容)
#   2. 固定在 super-SYS-821GE-TNHR 节点运行:
#      两节点 /home、/data 均为本地盘无共享存储，节点 2 上没有 ~/Sympic 和算例文件
#   3. 作业内部仍用 mpirun 启动进程:
#      /usr/mpi/gcc/openmpi-4.1.7a1 (NVIDIA HPC SDK) 未编译 PMI/PMIx 支持，
#      且 SLURM 只有 pmi2 插件，srun 直接启动 MPI 程序会失败
#   4. sbatch --wait 阻塞到作业结束并透传退出码，保持与 run_one.sh/run_all.sh 的同步语义
#
# 可用环境变量覆盖默认值:
#   SYMPIC_SLURM_NODE         默认 super-SYS-821GE-TNHR
#   SYMPIC_SLURM_PARTITION    默认 debug
#   SYMPIC_SLURM_TIME         默认 04:00:00
#   SYMPIC_SLURM_CPUS_PER_TASK 默认 2
set -euo pipefail

nh=${1:?usage: ./run_case_slurm.sh <nh> <ngpu> [run_name]}
ngpu=${2:?usage: ./run_case_slurm.sh <nh> <ngpu> [run_name]}
run_name=${3:-nh${nh}_g${ngpu}}

slurm_node=${SYMPIC_SLURM_NODE:-super-SYS-821GE-TNHR}
slurm_partition=${SYMPIC_SLURM_PARTITION:-debug}
slurm_time=${SYMPIC_SLURM_TIME:-04:00:00}
cpus_per_task=${SYMPIC_SLURM_CPUS_PER_TASK:-2}

case "$nh" in
  4) case_file=/data/chenli/perf/nh4.ss ;;
  5) case_file=/data/chenli/perf/nh5.ss ;;
  6) case_file=/data/chenli/perf/nh6.ss ;;
  *) echo "unsupported nh=$nh; supported: 4,5,6" >&2; exit 2 ;;
esac

mpirun_bin=/usr/mpi/gcc/openmpi-4.1.7a1/bin/mpirun
root=$(cd "$(dirname "$0")" && pwd)
bin=$root/build/bin/sympic
stdlib=$root/stdlib.scm
sympic_root=$(cd "$root/.." && pwd)
run_dir=$root/runs/$run_name
mkdir -p "$run_dir"

if [[ ! -x "$bin" ]]; then
  echo "[fatal] executable not found: $bin (run ./build.sh first)" >&2
  exit 1
fi
if [[ ! -r "$case_file" ]]; then
  echo "[fatal] case file not found: $case_file" >&2
  exit 1
fi

# 生成 sbatch 脚本（每次运行重新生成，ngpu/nh 等参数写入其中）
batch_script=$run_dir/job.sbatch
cat > "$batch_script" <<EOF
#!/bin/bash
#SBATCH --job-name=nccl-${run_name}
#SBATCH --partition=${slurm_partition}
#SBATCH -w ${slurm_node}
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=${ngpu}
#SBATCH --cpus-per-task=${cpus_per_task}
#SBATCH --gres=gpu:${ngpu}
#SBATCH --time=${slurm_time}
#SBATCH --output=${run_dir}/slurm-%j.log

set -euo pipefail
# 用系统 a1 mpirun: 清掉 ~/.bashrc 设置的 LD_LIBRARY_PATH, 否则 a1 二进制会加载到自编译
# 4.1.7 的库 (a1 用内部改名版 libevent/hwloc, 符号不兼容, 报 undefined symbol)
unset LD_LIBRARY_PATH || true
cd "${run_dir}"
export OMP_NUM_THREADS=1
export SYMPIC_INIT_PARTICLE_GPU_FAST=1
export SYMPIC_PROFILE_TIMING=1
# 注意: CUDA_VISIBLE_DEVICES 由 SLURM 根据上面的 --gres 自动设置（分配到的 GPU 的逻辑编号）。
# 不要在此处手动覆盖，否则会绕过 SLURM 的 GPU 分配，与其他作业冲突。
echo "version=NCCL nh=${nh} ngpu=${ngpu} nodes=\$SLURM_JOB_NODELIST CUDA_VISIBLE_DEVICES=\$CUDA_VISIBLE_DEVICES"
echo "case=${case_file}"
echo "log=${run_dir}/run.log"
STDLIB="${stdlib}" "${mpirun_bin}" -n "${ngpu}" "${bin}" "${case_file}" > run.log 2>&1
python3 "${sympic_root}/parse_five_profile.py" run.log
EOF

echo "[slurm] submitting ${batch_script}"
rc=0
job_id=$(sbatch --parsable --wait "$batch_script") || rc=$?
job_id=${job_id%%;*}
slurm_log=${run_dir}/slurm-${job_id}.log
echo "[slurm] job=${job_id} log=${slurm_log}"
cat "$slurm_log" 2>/dev/null || true
if [[ $rc -ne 0 ]]; then
  echo "[error] slurm job failed (rc=${rc}); see ${slurm_log} and ${run_dir}/run.log" >&2
  exit "$rc"
fi

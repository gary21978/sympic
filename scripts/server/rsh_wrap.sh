#!/bin/bash
# plm_rsh_agent: rsh 模板只带 PATH/LD_LIBRARY_PATH, 这里把启动器环境的运行变量转发给远端 orted
# - HWLOC_COMPONENTS=-gl: 关 hwloc GL 后端 X11 探测 (防 orted 挂死在 sshd X11 socket)
# - STDLIB/SYMPIC_*/OMP_*: 远端 app 需要的运行变量
# - 远端节点 GPU 集合用 REMOTE_CUDA_VISIBLE_DEVICES 单独指定 (本地节点由 mpirun -x 控制)
args=()
while [ $# -gt 0 ]; do
  case "$1" in
    -i|-o) args+=("$1" "$2"); shift 2 ;;
    *) break ;;
  esac
done
host=$1; shift
fwd=""
for v in HWLOC_COMPONENTS STDLIB SYMPIC_INIT_PARTICLE_GPU_FAST SYMPIC_PROFILE_TIMING OMP_NUM_THREADS NCCL_IB_DISABLE NCCL_IB_HCA NCCL_IB_GID_INDEX NCCL_NET_GDR_LEVEL NCCL_IB_QPS_PER_CONNECTION NCCL_SOCKET_IFNAME NCCL_DEBUG; do
  eval "val=\${$v:-}"
  [ -n "$val" ] && fwd="$fwd export $v=\"$val\";"
done
rv=${REMOTE_CUDA_VISIBLE_DEVICES:-${CUDA_VISIBLE_DEVICES:-}}
[ -n "$rv" ] && fwd="$fwd export CUDA_VISIBLE_DEVICES=\"$rv\";"
exec /usr/bin/ssh "${args[@]}" "$host" "$fwd $*"

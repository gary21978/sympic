#!/bin/bash
# 跨节点 sympic 启动器 (mpirun -H 直启, 绕过 slurm pmi2)
# 默认: 2 GPU/节点 x 2 节点 (nh4 xnode case)
# 8 rank 跨节点示例:
#   XNODE_NGPUS=4 XNODE_GPUS=3,4,5,6 XNODE_GPUS_REMOTE=3,4,5,6 #   XNODE_CASE=/data/chenli/perf/prof_nh4_s5_rt1_c2500_xnode8.ss ./run_cross_sympic.sh
export PATH=/data/chenli/openmpi-4.1.7/bin:/usr/bin:/bin:$PATH
export LD_LIBRARY_PATH=/data/chenli/openmpi-4.1.7/lib
export OMPI_MCA_btl=^openib
export OMPI_MCA_oob_tcp_if_include=10.33.1.0/24
export OMPI_MCA_btl_tcp_if_include=10.33.1.0/24
export HWLOC_COMPONENTS=-gl
export OMPI_MCA_plm_rsh_args="-i /home/chenli/.ssh/id_mpi -o StrictHostKeyChecking=no -o BatchMode=yes"
export OMPI_MCA_plm_rsh_agent=/home/chenli/bin/rsh_wrap.sh
# NCCL: IB/RoCE 配方 (关键三件套)
export NCCL_IB_HCA=mlx5_6
export NCCL_IB_GID_INDEX=3
export NCCL_NET_GDR_LEVEL=0
export NCCL_SOCKET_IFNAME=enp162s0f1np1
export NCCL_DEBUG=WARN
# 运行环境
export OMP_NUM_THREADS=1
export SYMPIC_INIT_PARTICLE_GPU_FAST=1
export SYMPIC_PROFILE_TIMING=1
export STDLIB=/home/chenli/Sympic/NCCL/stdlib.scm
# 每节点 GPU 数 / 本地物理卡 / 远端物理卡 / case 文件 (均可覆盖)
NGPU=${XNODE_NGPUS:-2}
export CUDA_VISIBLE_DEVICES=${XNODE_GPUS:-0,1}
export REMOTE_CUDA_VISIBLE_DEVICES=${XNODE_GPUS_REMOTE:-0,1}
CASE=${XNODE_CASE:-/data/chenli/perf/prof_nh4_s5_rt1_c2500_xnode.ss}
cd /tmp
exec timeout ${XNODE_TIMEOUT:-1800} /data/chenli/openmpi-4.1.7/bin/mpirun --prefix /data/chenli/openmpi-4.1.7   -H super-SYS-821GE-TNHR:$NGPU,super-SYS-821GE-TNHR-2:$NGPU -n $((NGPU*2))   /home/chenli/Sympic/NCCL/build/bin/sympic "$CASE"

#!/bin/bash
# build.sh — 创建/清空对应后端 build 目录并编译
# 用法: bash build.sh [cuda|mapu|simulator|nvscale]



set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

usage() {
    echo "usage: bash $0 [cuda|mapu|simulator|nvscale]"
}

qemu_guest_ssh_port() {
    local config_file="$1"
    if [[ -f "${config_file}" ]]; then
        awk -F: '/^qemu_vm_ssh_port:/ {print $2; exit}' "${config_file}"
    fi
}

qemu_guest_ready() {
    local port="$1"
    [[ -n "${port}" ]] && nc -z 127.0.0.1 "${port}" >/dev/null 2>&1
}

run_guest_build_over_ssh() {
    local ssh_port="$1"
    local guest_cmd="$2"

    if command -v sshpass >/dev/null 2>&1; then
        sshpass -p Linux ssh \
            -o StrictHostKeyChecking=no \
            -o UserKnownHostsFile=/dev/null \
            -p "${ssh_port}" \
            root@127.0.0.1 \
            "bash -lc $(printf '%q' "${guest_cmd}")"
    else
        echo "=== sshpass not found; password is Linux if SSH asks ==="
        ssh \
            -o StrictHostKeyChecking=no \
            -o UserKnownHostsFile=/dev/null \
            -p "${ssh_port}" \
            root@127.0.0.1 \
            "bash -lc $(printf '%q' "${guest_cmd}")"
    fi
}

wait_guest_ssh_login() {
    local ssh_port="$1"
    local attempt

    for attempt in $(seq 1 20); do
        if run_guest_build_over_ssh "${ssh_port}" "true"; then
            return 0
        fi
        echo "=== guest SSH login not ready, retry ${attempt}/20 after 3s ==="
        sleep 3
    done

    echo "[fatal] failed to login simulator guest over SSH"
    exit 1
}

build_in_simulator_guest() {
    local maps_driver_root="${MAPS_DRIVER_ROOT:-/home/cheney/Projects/MaPU/maps-driver}"
    local pciemu_release_dir="${maps_driver_root}/pciemu/release"
    local config_file="${pciemu_release_dir}/config"
    local guest_repo_dir="${GUEST_REPO_DIR:-/home/emu/Projects/sympic-mapu}"
    local ssh_port

    if [[ ! -x "${pciemu_release_dir}/start_emu.sh" ]]; then
        echo "[fatal] missing start_emu.sh: ${pciemu_release_dir}/start_emu.sh"
        exit 1
    fi
    if [[ ! -x "${pciemu_release_dir}/ssh_emu.sh" ]]; then
        echo "[fatal] missing ssh_emu.sh: ${pciemu_release_dir}/ssh_emu.sh"
        exit 1
    fi

    ssh_port="$(qemu_guest_ssh_port "${config_file}")"
    if qemu_guest_ready "${ssh_port}"; then
        echo "=== simulator guest already reachable on SSH port ${ssh_port}; skip start_emu.sh ==="
    else
        echo "=== start simulator guest: ${pciemu_release_dir}/start_emu.sh -clT ==="
        (cd "${pciemu_release_dir}" && ./start_emu.sh -clT)
        ssh_port="$(qemu_guest_ssh_port "${config_file}")"
    fi

    if ! qemu_guest_ready "${ssh_port}"; then
        echo "[fatal] simulator guest SSH is not reachable; try:"
        echo "        cd ${pciemu_release_dir} && ./ssh_emu.sh"
        exit 1
    fi

    echo "=== build inside simulator guest: root@127.0.0.1:${ssh_port}:${guest_repo_dir} ==="
    local guest_cmd
    guest_cmd=$(cat <<'EOF'
set -euo pipefail
modprobe maps
if ! command -v mpicc >/dev/null 2>&1; then
    export DEBIAN_FRONTEND=noninteractive
    if grep -Rqs '172\.10\.113\.50/ubuntu' /etc/apt/sources.list /etc/apt/sources.list.d; then
        cp -a /etc/apt/sources.list /etc/apt/sources.list.pciemu.bak.$(date +%Y%m%d%H%M%S)
        sed -i 's#http://172\.10\.113\.50/ubuntu#http://archive.ubuntu.com/ubuntu#g' /etc/apt/sources.list
    fi
    apt-get -o Acquire::Retries=3 update
    apt-get -o Acquire::Retries=3 install -y openmpi-bin libopenmpi-dev
fi
cd /home/emu/Projects/sympic-mapu
export SCALE_TOOLCHAIN_ROOT=/opt/maps/toolchain
export TOOLCHAIN_DIR=/opt/maps/toolchain
export MACCL_ROOT=/opt/maps
bash build.sh mapu
EOF
)

    wait_guest_ssh_login "${ssh_port}"
    run_guest_build_over_ssh "${ssh_port}" "${guest_cmd}"
}


if [ "$#" -lt 1 ]; then 
    echo "[fatal] missing build mode argument"
    usage
    exit 1
fi

MODE="$1"
case "${MODE}" in
    cuda)
        BUILD_DIR="${SCRIPT_DIR}/build-cuda"
        CMAKE_FLAGS="-DSYMPIC_CUDA=ON -DSYMPIC_MAPU=OFF"
        ;;
    mapu)
        BUILD_DIR="${SCRIPT_DIR}/build-mapu"
        default_toolchain="/opt/maps/toolchain"
        [[ -d "${default_toolchain}" ]] || default_toolchain="/home/cheney/Projects/MaPU/toolchain"
        export SCALE_TOOLCHAIN_ROOT="${SCALE_TOOLCHAIN_ROOT:-${default_toolchain}}"
        CMAKE_FLAGS="-DSYMPIC_CUDA=OFF -DSYMPIC_MAPU=ON"

        ;;
    simulator)
        build_in_simulator_guest
        exit 0
        ;;
    nvscale)
        BUILD_DIR="${SCRIPT_DIR}/build-nvscale"
        NVSCALE_ROOT="${NVSCALE_ROOT:-/home/cheney/Projects/MaPU/toolchain/nvscale}"
        NVSCALE_CUDA_ARCH="${NVSCALE_CUDA_ARCH:-89}"
        CMAKE_FLAGS="-DSYMPIC_CUDA=OFF -DSYMPIC_MAPU=OFF -DSYMPIC_NVSCALE=ON -DNVSCALE_ROOT=${NVSCALE_ROOT} -DNVSCALE_CUDA_ARCH=${NVSCALE_CUDA_ARCH} -DCUDA_ARCH=sm_${NVSCALE_CUDA_ARCH}"
        ;;
    *)
        echo "[fatal] unknown build mode: ${MODE}"
        usage
        exit 1
        ;;    
esac

echo "===构建模式: ${MODE} ==="
if [[ "${MODE}" == "mapu" ]]; then
    echo "===SCALE_TOOLCHAIN_ROOT: ${SCALE_TOOLCHAIN_ROOT} ==="
    echo "===MACCL_ROOT: ${MACCL_ROOT:-} ==="
fi
echo "===CMake flags: ${CMAKE_FLAGS} ==="

echo "=== 1. 创建 build 目录 ==="
mkdir -p "${BUILD_DIR}"

echo "=== 2. 清空 build 目录 ==="
rm -rf "${BUILD_DIR:?}"/*

echo "=== 3. 运行 cmake ==="
cd "${BUILD_DIR}"


cmake .. ${CMAKE_FLAGS}

echo "=== 4. 执行 make -j16 > build.log 2>&1 ==="
make -j16

echo ""
echo "=== 构建完成 ==="
echo "${BUILD_DIR}" > "${SCRIPT_DIR}/.sympic-last-build"
echo "=== 当前默认运行目录: ${BUILD_DIR} ==="

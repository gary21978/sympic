ENV_SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

[ -f "${ENV_SCRIPT_DIR}/env.local.sh" ] && source "${ENV_SCRIPT_DIR}/env.local.sh"

# 未定义则走默认路径
VM_DRIVER_DIR="${VM_DRIVER_DIR:-""}"
HOST_DRIVER_DIR="${HOST_DRIVER_DIR:-""}"


if [ -z "$VM_DRIVER_DIR" ]; then
    echo "错误： 找不到 vm_driver 目录：${VM_DRIVER_DIR}" >&2
    echo "错误： 找不到 host_driver 目录：${HOST_DRIVER_DIR}" >&2
    echo "请在scripts目录中执行：cp env.example.sh env.local.sh, 然后将driver的模拟器实际路径写上" >&2
    exit 1
fi
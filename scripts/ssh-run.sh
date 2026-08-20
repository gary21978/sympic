set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

HOST_PROJ_DIR="$(dirname "$SCRIPT_DIR")"
HOST_PROJ_DIR="$(realpath "$HOST_PROJ_DIR")"

HOME_REAL="$(realpath "$HOME")"
VM_PROJ_DIR="/home/emu/${HOST_PROJ_DIR#"$HOME_REAL"/}"

echo "VM_PROJ_DIR: [${VM_PROJ_DIR}]"
echo "HOST_PROJ_DIR: [${HOST_PROJ_DIR}]"
echo "HOST_DRIVER_DIR: [${HOST_DRIVER_DIR}]"

PORT=$(grep -w 'qemu_vm_ssh_port' ${HOST_DRIVER_DIR}/pciemu/release/config 2>/dev/null | awk -F ':' 'gsub(/[ \t]/,"",$2); {print $2}')
PORT=${PORT:-1111}
echo "使用端口: [$PORT]"
echo "SCRIPT_DIR: [${SCRIPT_DIR}]"

# 等虚拟机 SSH 就绪：最多重试 12 次，每次 5 秒
echo "等待虚拟机 SSH 就绪..."
for i in $(seq 1 12); do
  # 读 SSH banner：必须拿到 "SSH-" 开头才算真就绪
  BANNER=$(timeout 5 bash -c "exec 3<>/dev/tcp/127.0.0.1/$PORT && head -n 1 <&3" 2>/dev/null) || true
  if [[ "$BANNER" == SSH-* ]]; then
    echo "SSH 服务已就绪: $BANNER"
    break
  fi
  echo "等待中... ($i/12)"
  sleep 5
done

if [[ "$BANNER" != SSH-* ]]; then
  echo "错误：等待超时，虚拟机 SSH 未就绪" >&2
  exit 1
fi

# 直连执行远程命令
sshpass -p Linux ssh -n -o StrictHostKeyChecking=no -p "$PORT" root@127.0.0.1 \
  "cd ${VM_PROJ_DIR} &&
   export VM_DRIVER_DIR=${VM_DRIVER_DIR} &&
   export HOST_DRIVER_DIR=${HOST_DRIVER_DIR} &&
   bash ./build.sh mapu &&
   bash ./compare.sh case/demo-8
  "


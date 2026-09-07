set -e

CI_SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source ${CI_SCRIPT_DIR}/env.sh

bash "${HOST_DRIVER_DIR}/pciemu/release/clean_pciemu_runenv.sh"
bash "${HOST_DRIVER_DIR}/pciemu/release/start_emu.sh"
bash ${CI_SCRIPT_DIR}/ssh-run.sh 
bash "${HOST_DRIVER_DIR}/pciemu/release/clean_pciemu_runenv.sh"

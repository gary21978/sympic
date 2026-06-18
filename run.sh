#!/bin/bash
# run_test.sh — 一键准备测试环境并运行算例
# 用法: bash run_test.sh

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"
TEST_DIR="${BUILD_DIR}/test"

echo "=== 1. 创建并清空测试目录 ==="
mkdir -p "${TEST_DIR}"
rm -rf "${TEST_DIR:?}"/*

echo "=== 2. 链接算例文件 ==="
for f in "${SCRIPT_DIR}/runCases/template_cuda/"*; do
    [ -e "$f" ] || continue
    ln -sf "$f" "${TEST_DIR}/$(basename "$f")"
done

echo "=== 3. 链接可执行文件 ==="
ln -sf "${BUILD_DIR}/bin/sympic"     "${TEST_DIR}/sympic"
ln -sf "${BUILD_DIR}/bin/gapsio2to0" "${TEST_DIR}/gapsio2to0"

echo "=== 4. 链接 cscheme 标准库 ==="
ln -sf "${SCRIPT_DIR}/stdlib.scm"    "${TEST_DIR}/stdlib.scm"

echo "=== 5. 链接 pygapsio3.py ==="
ln -sf "${SCRIPT_DIR}/cgapsio/pygapsio3.py" "${TEST_DIR}/pygapsio3.py"

echo "=== 6. 链接参考结果 results_ref ==="
ln -sf "${SCRIPT_DIR}/runCases/results_ref" "${TEST_DIR}/results_ref"

echo "=== 7. 重写 run_gpu.sh ==="
cat > "${TEST_DIR}/run_gpu.sh" << 'EOF'
#!/bin/bash
set -euo pipefail
DIR="$(cd "$(dirname "$0")" && pwd)"
export STDLIB="${DIR}/stdlib.scm"
export OMP_NUM_THREADS=1
mpirun --oversubscribe -n 1 "${DIR}/sympic" test.ss 2>&1 | tee run.log
EOF
chmod +x "${TEST_DIR}/run_gpu.sh"

echo "=== 8. 修改 merge_and_compare.py 路径（自包含） ==="
python3 << PYEOF
import os
path = os.path.join("${TEST_DIR}", "merge_and_compare.py")
with open(path, "r") as f:
    text = f.read()

# 让 CGAPSIO_DIR 和 MERGER 都指向 test 目录内部，实现自包含
text = text.replace(
    'REPO = os.path.abspath(os.path.join(HERE, os.pardir, os.pardir))',
    'REPO = HERE'
)
text = text.replace(
    'CGAPSIO_DIR = os.path.join(REPO, "cgapsio")',
    'CGAPSIO_DIR = HERE'
)
text = text.replace(
    'MERGER = os.path.join(CGAPSIO_DIR, "gapsio2to0")',
    'MERGER = os.path.join(HERE, "gapsio2to0")'
)

with open(path, "w") as f:
    f.write(text)
PYEOF

echo ""
echo "=== 测试环境准备完成，开始运行测试 ==="
echo "目录: ${TEST_DIR}"
echo ""

cd "${TEST_DIR}"
echo "--- 运行 sympic ---"
bash ./run_gpu.sh

echo ""
echo "--- 运行结果对比 ---"
python3 ./merge_and_compare.py

echo ""
echo "=== 全部测试流程结束 ==="

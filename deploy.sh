#!/usr/bin/env bash
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
DEST="${1:-${DEPLOY_DIR:-$HOME/deliverable}}"
MODE="${2:-${DEPLOY_MODE:-mapu}}"
export SCALE_TOOLCHAIN_ROOT="${SCALE_TOOLCHAIN_ROOT:-/opt/maps/toolchain}"
export TOOLCHAIN_DIR="${TOOLCHAIN_DIR:-$SCALE_TOOLCHAIN_ROOT}"
export MACCL_ROOT="${MACCL_ROOT:-/opt/maps}"
if [[ "$MODE" == mapu && ! -d "$SCALE_TOOLCHAIN_ROOT" ]]; then
  echo "[fatal] missing toolchain: $SCALE_TOOLCHAIN_ROOT" >&2; exit 1
fi
mkdir -p "$DEST"
cd "$ROOT"
bash ./build.sh "$MODE"
BUILD_DIR="$ROOT/build-${MODE}"
install -m 0755 "$BUILD_DIR/bin/sympic" "$DEST/sympic"
install -m 0755 "$BUILD_DIR/bin/gapsio2to0" "$DEST/gapsio2to0"
install -m 0755 "$BUILD_DIR/bin/compare_gapsio" "$DEST/compare_gapsio"
install -m 0644 "$ROOT/src/stdlib.scm" "$DEST/stdlib.scm"
[[ -f "$DEST/test.ss" ]] || install -m 0644 "$ROOT/case/dual/test.ss" "$DEST/test.ss"
mkdir -p "$DEST/case"
cp -a "$ROOT/case/." "$DEST/case/"
install -m 0755 "$ROOT/scripts/run_deployed.sh" "$DEST/run.sh"
echo "Deployment complete: $DEST ($MODE)"

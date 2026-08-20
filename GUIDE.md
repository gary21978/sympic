# SymPIC Build And Case Guide

This repository can be built in three practical modes:

- native CUDA backend: compile `src/cuda_` with `nvcc`.
- native SCALE/MPU backend: compile `src/mapu_` with the internal SCALE
  toolchain.
- NVScale compatibility mode: compile `src/mapu_` as CUDA with the local
  `nvscale` shim headers, for NVIDIA GPU functional testing without modifying
  source code.

## Build CUDA Backend

```sh
bash build.sh cuda
```

The output goes to `build/bin/sympic` and `build/bin/gapsio2to0`.

If `build.sh` fails before CMake because the local SCALE environment variables
are not available, either export the variables expected by `scripts/env.sh`, or
invoke CMake directly:

```sh
cmake -S . -B build -DSYMPIC_CUDA=ON -DSYMPIC_MAPU=OFF -DCUDA_ARCH=sm_86
cmake --build build -j
```

## Build Native SCALE/MPU Backend

Set the internal SCALE environment first:

```sh
export TOOLCHAIN_DIR=/path/to/scale/toolchain
export VM_DRIVER_DIR=/path/to/vm_driver
source scripts/env.sh
source "${VM_DRIVER_DIR}/maps-umd/setup_env.sh"
bash build.sh mapu
```

The output also goes to `build/bin/`.

## Build MPU Code With NVScale On NVIDIA

NVScale is a compatibility plugin under `nvscale/`. It maps a subset of
SCALE/MAPS/Aurora APIs to CUDA and keeps all SymPIC-specific wiring outside the
plugin directory.

```sh
CUDA_ARCH=86 bash scripts/build_nvscale.sh
```

The output goes to `build-nvscale/bin/`. The existing `run.sh` and `compare.sh`
look for binaries under `build/bin/`. If no `build/` path is present, expose the
NVScale build like this:

```sh
ln -s build-nvscale build
```

If `build/` already exists, keep it intact and run the executable manually from
`build-nvscale/bin/` inside a prepared case directory.

## Run A Case

For builds available at `build/bin/`:

```sh
bash run.sh case/demo-8
```

`run.sh` copies the case inputs into `build/test/`, links `sympic`,
`gapsio2to0`, `stdlib.scm`, and `pygapsio3.py`, runs `test.ss`, merges GAPSIO
shards, then writes NumPy files to `build/test/test_npy/`.

When running NVScale on a machine without `VM_DRIVER_DIR`, the existing `run.sh`
may stop during environment initialization. Use the same steps manually:

```sh
TEST_DIR=build-nvscale/demo-8-test
mkdir -p "${TEST_DIR}"
for f in case/demo-8/*; do
  name="$(basename "${f}")"
  if [ "${name}" != result_npy ] && [ "${name}" != test_npy ]; then
    ln -sf "$(pwd)/${f}" "${TEST_DIR}/${name}"
  fi
done
ln -sf "$(pwd)/build-nvscale/bin/sympic" "${TEST_DIR}/sympic"
ln -sf "$(pwd)/build-nvscale/bin/gapsio2to0" "${TEST_DIR}/gapsio2to0"
ln -sf "$(pwd)/src/stdlib.scm" "${TEST_DIR}/stdlib.scm"
ln -sf "$(pwd)/src/cgapsio/pygapsio3.py" "${TEST_DIR}/pygapsio3.py"

cd "${TEST_DIR}"
env STDLIB="$(pwd)/stdlib.scm" OMP_NUM_THREADS=1 \
  mpirun --allow-run-as-root --oversubscribe -n 1 ./sympic test.ss
for var in tmpEB tmpEN tmpJ; do
  if ls "${var}_PROC_"* >/dev/null 2>&1; then
    mpirun --allow-run-as-root --oversubscribe -n 1 \
      ./gapsio2to0 ${var}_PROC_* "${var}"
  fi
done

cd ../..
python3 scripts/gapsio_to_npy.py \
  --work-dir "${TEST_DIR}" \
  --out-dir "${TEST_DIR}/test_npy"
```

## Compare Results

For a case with reference files in `result_npy/`:

```sh
bash compare.sh case/demo-8
```

Manual comparison is also possible:

```sh
python3 scripts/compare_to_result_npy.py \
  --test-dir build/test/test_npy \
  --ref-dir case/demo-8/result_npy
```

For the manual NVScale run above, use:

```sh
python3 scripts/compare_to_result_npy.py \
  --test-dir build-nvscale/demo-8-test/test_npy \
  --ref-dir case/demo-8/result_npy
```

Use the same case for CUDA and NVScale/SCALE runs, then compare each generated
`test_npy/` directory against the case reference or against each other.

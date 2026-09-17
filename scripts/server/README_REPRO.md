# SymPIC Three-Version Timing Reproduction

This directory contains three clean source snapshots with the same step-level
timing inserted in `main.c`.

- `cuda_by_tyb_timing`: `/home/cheney/Projects/SymPIC/cuda`, branch `cuda-by-tyb`
- `nccl_timing`: `/home/cheney/Projects/SymPIC/cuda`, branch `nccl`
- `dev_timing`: `/home/cheney/Projects/sympic-mapu`, branch `dev`

Timing is enabled at runtime with:

```bash
SYMPIC_PROFILE_TIMING=1
```

Each timed step prints:

```text
PROFILE_STEP step=<n> total=<s> faraday=<s> ext_add=<s> sync3=<s> zero_j=<s> push_deposit=<s> particle_sort=<s> merge_j=<s> ext_sub=<s> current_add=<s> ampere=<s> bcopy=<s> other=<s>
```

The per-step total is the existing wall-clock `time used`. The listed modules
plus `other` are designed to balance back to `total`.

## Build

On `10.33.1.1`:

```bash
export CC=/usr/mpi/gcc/openmpi-4.1.7a1/bin/mpicc
export CXX=/usr/mpi/gcc/openmpi-4.1.7a1/bin/mpicxx

cd ~/Sympic/cuda_by_tyb_timing
bash build.sh

cd ~/Sympic/nccl_timing
bash build.sh

cd ~/Sympic/dev_timing
bash build.sh cuda
```

The old CUDA tree builds into `build/`. The current dev tree builds into
`build-cuda/` for the CUDA backend.

## Run

Use comma-separated GPU IDs. Do not use `0-7`.

```bash
export OMP_NUM_THREADS=1
export CUDA_VISIBLE_DEVICES=0,1,2,3,4,5,6,7
export SYMPIC_INIT_PARTICLE_GPU_FAST=1
export SYMPIC_PROFILE_TIMING=1
export MPIRUN=/usr/mpi/gcc/openmpi-4.1.7a1/bin/mpirun
```

Run nh4:

```bash
cd ~/Sympic/cuda_by_tyb_timing
mkdir -p runs/nh4
cd runs/nh4
STDLIB=../../stdlib.scm $MPIRUN -n 8 ../../build/bin/sympic /data/chenli/perf/prof_nh4_s5_rt1_c2500.ss > run.log 2>&1

cd ~/Sympic/nccl_timing
mkdir -p runs/nh4
cd runs/nh4
STDLIB=../../stdlib.scm $MPIRUN -n 8 ../../build/bin/sympic /data/chenli/perf/prof_nh4_s5_rt1_c2500.ss > run.log 2>&1

cd ~/Sympic/dev_timing
mkdir -p runs/nh4
cd runs/nh4
STDLIB=../../src/stdlib.scm $MPIRUN -n 8 ../../build-cuda/bin/sympic /data/chenli/perf/prof_nh4_s5_rt1_c2500.ss > run.log 2>&1
```

Run nh5:

```bash
cd ~/Sympic/cuda_by_tyb_timing
mkdir -p runs/nh5
cd runs/nh5
STDLIB=../../stdlib.scm $MPIRUN -n 8 ../../build/bin/sympic /data/chenli/perf/prof_nh5_s5_rt1_c5000.ss > run.log 2>&1

cd ~/Sympic/nccl_timing
mkdir -p runs/nh5
cd runs/nh5
STDLIB=../../stdlib.scm $MPIRUN -n 8 ../../build/bin/sympic /data/chenli/perf/prof_nh5_s5_rt1_c5000.ss > run.log 2>&1

cd ~/Sympic/dev_timing
mkdir -p runs/nh5
cd runs/nh5
STDLIB=../../src/stdlib.scm $MPIRUN -n 8 ../../build-cuda/bin/sympic /data/chenli/perf/prof_nh5_s5_rt1_c5000.ss > run.log 2>&1
```

Run nh6:

```bash
cd ~/Sympic/cuda_by_tyb_timing
mkdir -p runs/nh6
cd runs/nh6
STDLIB=../../stdlib.scm $MPIRUN -n 8 ../../build/bin/sympic /data/chenli/perf/prof_nh6_s5_rt1_c10000.ss > run.log 2>&1

cd ~/Sympic/nccl_timing
mkdir -p runs/nh6
cd runs/nh6
STDLIB=../../stdlib.scm $MPIRUN -n 8 ../../build/bin/sympic /data/chenli/perf/prof_nh6_s5_rt1_c10000.ss > run.log 2>&1

cd ~/Sympic/dev_timing
mkdir -p runs/nh6
cd runs/nh6
STDLIB=../../src/stdlib.scm $MPIRUN -n 8 ../../build-cuda/bin/sympic /data/chenli/perf/prof_nh6_s5_rt1_c10000.ss > run.log 2>&1
```

## Parse

From `~/Sympic`:

```bash
python3 parse_profile_steps.py cuda_by_tyb_timing/runs/nh4/run.log nccl_timing/runs/nh4/run.log dev_timing/runs/nh4/run.log
```

The parser skips step 0 and reports step1-4 averages in milliseconds.

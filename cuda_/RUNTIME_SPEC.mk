RUNTIME   := CUDA
PREFIX    := cuda_
FILEEXT   := cu
D_FILEEXT   := cu
D_CC      := echo
CUDA_ARCH ?= sm_75
H_CC      := nvcc -arch=$(CUDA_ARCH)
CC        := nvcc -arch=$(CUDA_ARCH)
D_CFLAGS    := 
H_CFLAGS    := -O3 -c -I/usr/local/cuda/include
# Source-level Nsight Compute profiling (set CUDA_SOURCE_PROFILE=1 via allCleanBuild_cuda.sh --profile).
# Uses -lineinfo only; do not add -G (disables optimizations and skews profiles).
ifeq ($(CUDA_SOURCE_PROFILE),1)
H_CFLAGS += -lineinfo
endif

# ptxas resource usage (regs / stack / spills) printed during nvcc compilation.
# Enable via: CUDA_PTXAS_VERBOSE=1 ./allCleanBuild_cuda.sh rebuild_cuda --no-regression
ifeq ($(CUDA_PTXAS_VERBOSE),1)
H_CFLAGS += -Xptxas -v
endif


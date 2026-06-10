
DEPDIR := .deps
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

MPI_LINKFLAGS := $(shell mpicc -showme:link)

CC        := mpicc
CFLAGS    := -O2 -g -ffast-math -ffunction-sections -I./ -I./cgapsio -I./cscheme -I/usr/local/cuda/include -std=gnu99 -Wno-incompatible-pointer-types -Wno-implicit-function-declaration -Wno-int-conversion
LD        := mpicc
LDFLAGS   := -lm -fopenmp -Wl,--gc-sections -L/usr/local/cuda/lib64 -lcudart -lcuda -lstdc++
AR        := ar
ARFLAG    := rcs

SOURCES = space_filling_curve.c init_adjoint_relation.c split_shell.c init_field3d_mpi.c genrand.c init_particle.c sort_particle.c checkpoint.c run_particle.c run_particle_call_fun.c pass_xyzzyx.c mpifields.c nonlinear_jfnk.c call_curl_kernel.c blas_shell.c field_sync_h2d_d2h.c sync_fields.c smalllib.c mpi_fieldio.c seqfields.c main.c user_defined_particle_distribution.c

DIRS_PREV = smallmpi cgapsio cscheme
# c_/openmp_ 仍须编入 sympic：主机 .c（mpifields/run_particle/blas_shell 等）在链接期引用 c_* / openmp_* 符号；cyclone 运行时走 CD_type==2 仅用 cuda_*。
DIRS = c_ openmp_ cuda_
DIRS_CUDA = cuda_

HEADERS = $(patsubst %.c,%.h,$(SOURCES))

OBJS = $(patsubst %.c,%.o,$(SOURCES)) cfgcst.o

EXTRA_LIBS = cgapsio/libcgapsio.a cscheme/libcscheme.a smallmpi/libsmallmpi.a c_yeefdtd.a openmp_yeefdtd.a cuda_yeefdtd.a

all: sympic
all_dirs_prev: $(DIRS_PREV)
all_dirs: $(DIRS)
cuda_device: $(DIRS_CUDA)

sympic: $(OBJS) $(EXTRA_LIBS) libsmallmpi.h
	 $(LD) $(OBJS) $(EXTRA_LIBS) -o $@ $(LDFLAGS)

%.o: %.c c_yeefdtd.h libsmallmpi.h cfgcst.h $(DEPDIR)/%.d | $(DEPDIR)
	$(CC) $(CFLAGS) $< -c

libsmallmpi.h:
	@test -f libsmallmpi.h || (echo "missing libsmallmpi.h — restore from git" && exit 1)

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRCS:%.c=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))

$(DIRS_PREV):
	$(MAKE) -C $@

$(DIRS):
	$(MAKE) -C $@

.PHONY: $(DIRS) $(DIRS_PREV) $(DIRS_CUDA) all all_dirs all_dirs_prev cuda_device clean clean_all

clean:
	-rm -f *.o sympic
clean_all:
	-rm -f *.o sympic

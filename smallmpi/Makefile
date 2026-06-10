CC=mpicc

all: libsmallmpi.a

libsmallmpi.a: small_mpi.o
	$(AR) $(ARFLAGS) $@ $<

small_mpi.o: small_mpi.c
	$(CC) $(CPPFLAG) -E $< |sed -e '/^\# /d' -e '/^\ \{0,\}$$/d' | \
	  $(CC) $(CFLAGS) -c -xc - -o $@

clean:
	-rm -f small_mpi.o libsmallmpi.a

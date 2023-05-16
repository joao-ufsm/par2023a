MKL_HOME=/opt/intel/oneapi/mkl/latest

PROGRAM= cholesky-tiled-seq cholesky-tiled-for cholesky-tile-for-opt cholesky-tiled-dataflow

CC=gcc
CFLAGS=-O3 -std=gnu99 -I$(MKL_HOME)/include -fopenmp
LDFLAGS=-L$(MKL_HOME)/lib/intel64 -lmkl_sequential -lmkl_core -lmkl_rt -lpthread -lm -fopenmp
#VERBOSE=-DVERBOSE

all: $(PROGRAM) 

cholesky-tiled-seq: cholesky-tiled-seq.c 
	$(CC) $(CFLAGS) $(VERBOSE) -o $@ $^ $(LDFLAGS)

cholesky-tiled-for: cholesky-tiled-for.c 
	$(CC) $(CFLAGS) $(VERBOSE) -o $@ $^ $(LDFLAGS)

cholesky-tiled-for-opt: cholesky-tiled-for-opt.c 
	$(CC) $(CFLAGS) $(VERBOSE) -o $@ $^ $(LDFLAGS)

cholesky-tiled-dataflow: cholesky-tiled-dataflow.c 
	$(CC) $(CFLAGS) $(VERBOSE) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(PROGRAM) *.o

wipe: clean
	rm -rf *.out *.err

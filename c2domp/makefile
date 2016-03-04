# mwrapdemo makefile for interfacing to a C library, openMP & 2d array version
# Barnett 7/30/15
include ../make.inc

# This is the task run if "make" is done with no arguments ("mexfile" is not
# a file, just a name for a compilation task given below):
default: mexfile

# How to compile your C library function: (-fPIC is needed for linking to MEX)
lib.o: lib.cc makefile
	$(CC) -fPIC -O2 -fopenmp -c lib.cc

# Tell mwrap to make the interface and the name of the final MEX file:
# (note -mb here makes separate .m file for each @ function in the .mw)
gateway.cc: demo.mw makefile
	$(MWRAP) -list -mex gateway -mb demo.mw
	$(MWRAP) -mex gateway -c gateway.cc demo.mw

# How to make MATLAB/MEX compile the interface (whatever libs needed):
mexfile: gateway.cc lib.o makefile
	$(MEX) gateway.cc lib.o -largeArrayDims -lm -lgomp

# Remove the MEX interface, MATLAB caller, and MEX file:
clean:
	rm -f array2d.m array2domp.m gateway.cc *.o *.mex* *~

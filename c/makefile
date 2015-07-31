# mwrapdemo makefile for interfacing to a C library
# Barnett 7/30/15

# Point to your mwrap executable:
MWRAP = ../mwrap-0.33.3/mwrap

# This is the task run if "make" is done with no arguments ("mexfile" is not
# a file, just a name for a compilation task given below):
default: mexfile

# How to compile your C library function: (-fPIC is needed for linking to MEX)
lib.o: lib.c makefile
	gcc -fPIC -O3 -c lib.c

# Tell mwrap to make the interface and the name of the final MEX file:
# Note: -c99complex assumes usual C complex numbers (see MWrap docs)
gateway.c: demo.mw makefile
	$(MWRAP) -c99complex -mex gateway -mb -list demo.mw
	$(MWRAP) -c99complex -mex gateway -c gateway.c demo.mw

# How to make MATLAB/MEX compile the interface (whatever libs needed):
mexfile: gateway.c lib.o makefile
	mex gateway.c lib.o -largeArrayDims -lm

# Remove the MEX interface, MATLAB caller, and MEX file:
clean:
	rm -f myfunc.m gateway.c *.o *.mex* *~

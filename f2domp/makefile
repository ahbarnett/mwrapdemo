# mwrapdemo makefile for interface to Fortran library, openMP & 2d array version
# Barnett 7/31/15

# Point to your mwrap executable:
MWRAP = ../mwrap-0.33.3/mwrap

# This is the task run if "make" is done with no arguments ("mexfile" is not
# a file, just a name for a compilation task given below):
default: mexfile

# How to compile your Fortran library: (-fPIC is needed for linking to MEX)
lib.o: lib.f makefile
	gfortran -fPIC -O2 --openmp -c lib.f

# Tell mwrap to make the interface and the name of the final MEX file:
# (note -mb here makes separate .m file for each @ function in the .mw)
gateway.c: demo.mw makefile
	$(MWRAP) -list -mex gateway -mb demo.mw
	$(MWRAP) -mex gateway -c gateway.c demo.mw

# How to make MATLAB/MEX compile the interface (whatever libs needed):
mexfile: gateway.c lib.o makefile
	mex gateway.c lib.o -largeArrayDims -lgfortran -lm -lgomp

# Remove the MEX interface, MATLAB caller, and MEX file:
clean:
	rm -f array2d.m array2domp.m gateway.c *.o *.mex* *~

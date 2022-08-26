# makefile for tiny single-prec test.

-include ../make.inc

default: matlab

matlab: mwrapfloat.mw
	$(MWRAP) -mex mwrapfloat -c mwrapfloat.cpp -mb mwrapfloat.mw -cppcomplex
	$(MEX) mwrapfloat.cpp -largeArrayDims -output mwrapfloat

clean:
	rm -f *add*.m mwrapfloat.cpp *.o *.mex* *~

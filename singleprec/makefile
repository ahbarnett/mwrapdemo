# makefile for tiny single-prec test.

-include ../make.inc

default: matlab

matlab:
	$(MWRAP) -mex mwrapfloat -c mwrapfloat.cpp -mb mwrapfloat.mw
	$(MEX) mwrapfloat.cpp -largeArrayDims -output mwrapfloat

octave: matlab
	mkoctfile --mex  mwrapfloat.cpp -output mwrapfloat

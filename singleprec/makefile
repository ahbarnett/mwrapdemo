# makefile for tiny single-prec test.

-include ../make.inc

default: matlab

matlab: mwrapfloat.mw
	$(MWRAP) -mex mwrapfloat -c mwrapfloat.cpp -mb mwrapfloat.mw -ccpcomplex
	$(MEX) mwrapfloat.cpp -largeArrayDims -output mwrapfloat

octave: matlab
	mkoctfile --mex  mwrapfloat.cpp -output mwrapfloat

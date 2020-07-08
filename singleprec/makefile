# makefile for tiny single-prec test.

-include ../make.inc

default: matlab

matlab: mwrapfloat.mw
	$(MWRAP) -mex mwrapfloat -c mwrapfloat.cpp -mb mwrapfloat.mw -cppcomplex
	$(MEX) mwrapfloat.cpp -largeArrayDims -output mwrapfloat

octave: matlab
	mkoctfile --mex  mwrapfloat.cpp -output mwrapfloat

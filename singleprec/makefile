# makefile for tiny single-prec test.

-include ../make.inc

default:
	$(MWRAP) -mex mwrapfloat -c mwrapfloat.cpp -mb mwrapfloat.mw
	$(MEX) mwrapfloat.cpp -largeArrayDims -output mwrapfloat

# mwrapdemo makefile. If you want to make Octave not MATLAB, edit your make.inc

default: all

all:
	(cd c; make)
	(cd c2domp; make)
	(cd f; make)
	(cd f2domp; make)
	(cd singleprec; make)	

clean:
	(cd c; make clean)
	(cd c2domp; make clean)
	(cd f; make clean)
	(cd f2domp; make clean)
	(cd singleprec; make clean)	
	rm -f *~

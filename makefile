default:
	(cd c; make)
	(cd c2domp; make)
	(cd f; make)
	(cd f2domp; make)

clean:
	(cd c; make clean)
	(cd c2domp; make clean)
	(cd f; make clean)
	(cd f2domp; make clean)
	rm -f *~

# === Compilers ===


# Uncomment this line for new-style classdef support
# OOFLAG=-DR2008OO

# Uncomment this line for C99 complex support
TESTC99COMPLEX=test_c99_complex

CC=    CL
CXX=   CL
MEX=   mex $(OOFLAG)

# Use the following for 64-bit MEX
# MEX=   mex -largeArrayDims $(OOFLAG)

# Use the following for GNU Octave.
MEX=   mkoctfile --mex

# Location of Win-Flex-Bison compiler (not needed unless you are planning to
# modify the grammar -- the default installation comes with the relevant
# files already in place
WINFLEXBISONPATH=X:\projekte\1510_MatLightTracer\mwrap\win_flex_bison
FLEX=$(WINFLEXBISONPATH)\win_flex
BISON=$(WINFLEXBISONPATH)\win_bison

#-------------------------------------------------------------------------
# Compiler-Flags
#-------------------------------------------------------------------------

CGFLAGS=/nologo /W4 /EHsc
CRFLAGS=/DNDEBUG /ML /Ox
CDFLAGS=

CFLAGS=$(CGFLAGS) $(CDFLAGS)

#-------------------------------------------------------------------------
# Linker-Flags
#-------------------------------------------------------------------------

LGFLAGS=/NOLOGO
LRFLAGS=
LDFLAGS=/DEBUG

LFLAGS=$(LGFLAGS) $(LDFLAGS)


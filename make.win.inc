
# System-dependent settings for makefiles.

# === MEX Compiler ===

# for 32bit version, uncomment following two lines
#MEX="C:\Program Files (x86)\MATLAB\R2014b"\bin\mex
#MFLAGS_PLAT = -compatibleArrayDims

# for 64bit version, uncomment following two lines
MEX="C:\Program Files\MATLAB\R2014b"\bin\mex
MFLAGS_PLAT = -largeArrayDims

# uncomment following lines if desired
#DEBUGFLAG=-g                                 # enable debugging
#OOFLAG=-DR2008OO                             # new-style classdef support
#VERBOSEFLAG=-v COMPFLAGS="$COMPFLAGS -W4"    # verbose compiler output

MFLAGS=$(MFLAGS_PLAT) $(DEBUGFLAG) $(OOFLAG) $(VERBOSEFLAG)




# === MWrap Compiler ===

# Change this to location of your MWrap executable if you don't want to use
# the shipped version. This is either an absolute path, or a path relative to
# each of the four demo subdirectories:

MWRAP=$(MAKEDIR)\..\mwrap-0.33.3\mwrap.exe



# mwrapdemo: simple MWrap examples

  Alex Barnett 7/31/15-8/3/15

[MWrap](http://www.cs.cornell.edu/~bindel/sw/mwrap/) is a super-useful code by David Bindel that turns the horrible pain of writing a MEX interface into a quick automatic procedure. To quote Bindel's introduction,

>From a set of augmented MATLAB script files, MWrap will generate a MEX gateway to desired C/C\++ and FORTRAN function calls and MATLAB function files to access that gateway. MWrap takes care of the details of converting to and from MATLAB's data structures, allocating and freeing temporary storage, handling object upcasts (even in the presence of multiple inheritance), and catching C\++ exceptions. The gateway functions also work with recent versions of Octave when compiled with `mkoctfile --mex.`

The present project contains simple, minimally complete examples showing how to use MWrap to link to a C or Fortran library, pass in and out 1D and 2D arrays, handle complex and Boolean types, and use OpenMP (a big reason to use MEX). These are essential for scientific computing, but I have found require care. The goal is to make the extra layer of complexity that MWrap introduces as clear as possible. Use them as templates for your codes. Basic makefiles are given which also are useful templates. These examples complement Bindel's "foobar" example, and much more elaborate examples, in `mwrap-0.33.3/examples`. Currently they are tested only on linux and Mac.

### Dependencies

[MATLAB](http://www.mathworks.com/products/matlab)  
C and Fortran compilers supporting C99 and OpenMP.
If you are on a Mac system, you need Xcode to use MEX.  
GNU make.  
Optional: [MWrap](http://www.cs.cornell.edu/~bindel/sw/mwrap/), although a distribution of MWrap is included in this repository.

### Getting started

Download this repository either via `git clone` or as zip archive, to a linux or Mac machine. Then

1. Change directory into `mwrap-0.33.3/` and type `make`. This makes the executable `mwrap` for your operating system. If this fails, see the MWrap documentation `mwrap.pdf`, or failing that contact David Bindel, author of MWrap.

1. Go back to the main `mwrapdemo` directory. Copy `make.inc.example` to `make.inc`. Type `mex` from the command line; you should get something like `mex:  nofile name given.` and something mentioning MATLAB. If you don't, then you need to find the path to your mex executable then edit `make.inc` to give this mex location. (Sometimes on a Mac `mex` calls pdftex in which case you have to give the full path to `mex` such as `/Applications/MATLAB_2012a.app/bin/mex`.)

1. Type `make`. This should make all examples in the four directories. If it breaks at some point, don't panic; instead `cd` to each the four directories in turn and type `make`, to see what functionality you can get.

1. From MATLAB, in the main directory, type `testall` which should run four tests, each returning a set of error figures, which should be small. As above, if you weren't able to make all four directories, `cd` to the ones that worked and try `test` in MATLAB.

See the README files in each of the directories for more information.

*Note: both the top-level makefile and top-level tester change directory. If they exist prematurely, you may have to return to the top directory by hand.*

To remove generated/compiled objects, type `make clean` from the top level directory.

### Contents of this repository

`c/` - simple single-thread C example, 1D array, complex, and a Boolean  
`c2domp/` - 2D array, multi-thread OpenMP C example  
`f/` - simple single-thread Fortran example, 1D array, complex, and a Boolean  
`f2domp/` - 2D array, multi-thread OpenMP Fortran example  
`testall.m` - MATLAB script to run all demos  
`makefile` - top-level makefile to compile all demos  
`make.inc.example` - system-specific makefile settings
(copy to `make.inc` and edit that rather than changing this distributed file)  
`mwrap-0.33.3/` - version 0.33 of MWrap included for convenience (you may want to check Bindel's page for a later version). If you don't use this, then you'll need to change the `MWRAP` variable in the makefiles to the location of your `mwrap` executable.  

### My usage notes for MWrap

* The makefiles I include contain useful compilation flags.
* Function names cannot use _ (underscore), even though this is allowable in MATLAB, C, and Fortran. It will fail in a non-informative way if you try this.
* To get mex compilation working on your system you may need to edit `bin/mexopts.sh` in your MATLAB installation directory. On an ubuntu 12.04 system running MATLAB R2012a I needed to add the flag `--openmp` to `LDFLAGS` in the `glnxa64)` case.
* If you want to pass a flag to C, this is as an int. However, Booleans in MATLAB passed directly cause a segfault. They must be converted to doubles. See `c/demo.mw`
* Text output from Fortran `write(*,*)` doesn't seem to make it to the MATLAB terminal, unlike C stdout which does, at least when MATLAB is run with `-nodesktop`. mexPrintf is clumsy but works (see `f/lib.f`).
* The Mac OSX flags require some tweaking: `-lgfortran` may need to be removed. Currently we have problems with `write` in Fortran. Also it seems Xcode doesn't even support OpenMP, so apparently Mac users wanting this will have to install gcc and adjust `mexopts.sh` to point mex to this compiler.

### Other projects showing how to use MWrap

[fmmlib2d](http://www.cims.nyu.edu/cmcl/fmm2dlib/fmm2dlib.html) - Fortran, with makefile for a variety of environments  
[lhelmfs](https://math.dartmouth.edu/~ahb/software/lhelmfs.tgz) - C, Linux environment  

### To do list

* Set up flags on Mac and get `write` working there
* Check this on Windows system; include makefiles


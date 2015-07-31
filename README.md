# mwrapdemo: simple MWrap examples

  Alex Barnett 7/31/15

[MWrap](http://www.cs.cornell.edu/~bindel/sw/mwrap/) is a super-useful code by David Bindel that turns the horrible pain of writing a MEX interface into a quick automatic procedure. To quote Bindel's introduction,

>From a set of augmented MATLAB script files, MWrap will generate a MEX gateway to desired C/C\++ and FORTRAN function calls and MATLAB function files to access that gateway. MWrap takes care of the details of converting to and from MATLAB's data structures, allocating and freeing temporary storage, handling object upcasts (even in the presence of multiple inheritance), and catching C\++ exceptions. The gateway functions also work with recent versions of Octave when compiled with `mkoctfile --mex.`

The present project contains simple, minimally complete examples showing how to use MWrap to link to a C or Fortran library, pass in and out 1D and 2D arrays, handle complex and Boolean types, and use OpenMP (a big reason to use MEX). These are essential for scientific computing, but I have found require care. The goal is to make the extra layer of complexity that MWrap introduces as clear as possible. Use them as templates for your codes. Basic makefiles are given which also are useful templates. These examples complement Bindel's "foobar" example, and much more elaborate examples, in `mwrap-0.33.3/examples`. Currently they are tested only in a Linux/unix environment.

### Contents of this repository

`c/` - simple single-thread C example, 1D array, complex, and a Boolean  
`c2domp/` - 2D array, multi-thread OpenMP C example  
`f/` - simple single-thread Fortran example, 1D array, complex, and a Boolean  
`f2domp/` - 2D array, multi-thread OpenMP Fortran example  
`testall.m` - MATLAB script to run all demos  
`makefile` - top-level makefile to compile all demos  
`mwrap-0.33.3/` - version 0.33 of MWrap included for convenience (you may want to check Bindel's page for a later version). If you don't use this, then you'll need to change the `MWRAP` variable in the makefiles to the location of your `mwrap` executable.  

### My usage notes for MWrap

* The makefiles I include contain useful compilation flags.
* Function names cannot use _ (underscore), even though this is allowable in MATLAB, C, and Fortran. It will fail in a non-informative way if you try this.
* To get mex compilation working on your system you may need to edit `bin/mexopts.sh` in your MATLAB installation directory. On an ubuntu 12.04 system running MATLAB R2012a I needed to add the flag `--openmp` to `LDFLAGS` in the `glnxa64)` case.
* If you want to pass a flag to C, this is as an int. However, Booleans in MATLAB passed directly cause a segfault. They must be converted to doubles. See `c/demo.mw`
* Text output from Fortran write(\*,\*) doesn't seem to make it to the MATLAB terminal, unlike C stdout. mexPrintf is clumsy but works (see `f/lib.f`).

### Other projects showing how to use MWrap

[fmmlib2d](http://www.cims.nyu.edu/cmcl/fmm2dlib/fmm2dlib.html) - Fortran, with makefile for a variety of environments  
[lhelmfs](https://math.dartmouth.edu/~ahb/software/lhelmfs.tgz) - C, Linux environment  

### To do list

* Check this on Mac and Windows systems; include their makefiles


# mwrapdemo: simple MWrap examples for MATLAB calling C/Fortran

  Alex Barnett

[MWrap](https://github.com/zgimbutas/mwrap) is a super-useful code originated by David Bindel that turns the horrible pain of writing a MEX interface into a quick automatic procedure. To quote Bindel's introduction,

>From a set of augmented MATLAB script files, MWrap will generate a MEX gateway to desired C/C\++ and FORTRAN function calls and MATLAB function files to access that gateway. MWrap takes care of the details of converting to and from MATLAB's data structures, allocating and freeing temporary storage, handling object upcasts (even in the presence of multiple inheritance), and catching C\++ exceptions. The gateway functions also work with recent versions of Octave when compiled with `mkoctfile --mex.`

The present project contains simple, minimally complete examples showing how to use MWrap to link to a C or Fortran library, pass in and out 1D and 2D arrays, handle complex and Boolean types, and use OpenMP (a big reason to use MEX). These are essential for scientific computing, but I have found require care. The goal is to make the extra layer of complexity that MWrap introduces as clear as possible. Use them as templates for your codes. Basic makefiles are given which also are useful templates. These examples complement Bindel's "foobar" and other more complicated C++-style examples that may not be obvious to new users. Currently we test only on linux and Mac.

### Dependencies

* [MATLAB](http://www.mathworks.com/products/matlab)  
* [MWrap](https://github.com/zgimbutas/mwrap)  
* C and Fortran compilers supporting C99 and OpenMP  
* GNU make  

If you are on a Mac system, you'll need Xcode to use MATLAB's MEX compiler.

### Getting started

Download this repository either via `git clone` or as zip archive, to a linux or Mac machine. Then

1. Install [MWrap](https://github.com/zgimbutas/mwrap) by following its instruction. Ubunutu/debian users can get an old version via `sudo apt install mwrap`. Create a link, eg via `ln -s /your/mwrap/installation/mwrap /usr/bin/mwrap`, or adjust your `PATH`, so that `mwrap` is in your path. Check via `which mwrap`.

1. Copy `make.inc.example` to `make.inc`, and make any local changes to `make.inc` if needed, as follows.

1. Go back to the main `mwrapdemo` directory. Type `mex` from the command line; you should get something like `mex:  nofile name given.` and something mentioning MATLAB. If you don't, then you need to find the path to your mex executable then edit `make.inc` to make the variable `MEX` point to your mex executable. (Sometimes on a Mac `mex` calls pdftex in which case you have to give the full path to `mex` such as `/Applications/MATLAB_2012a.app/bin/mex`.)

1. Check you have the compilers `gcc` and `gfortran`. If not, adjust the variables `CC` and `FC` respectively in `make.inc` to point to your compilers.

1. Type `make`. This should make all examples in the four directories. If it breaks at some point, don't panic; instead `cd` to each the four directories in turn and try `make`, to see what functionality you can get.

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
`make.inc.example` - system-specific makefile settings (copy to `make.inc` and edit that rather than changing this distributed file)  
`singleprec/` - native float tests (experimental, needs mwrap>=0.33.11, 7/6/20)  


### Other projects showing how to use MWrap

[fmmlib2d](http://www.cims.nyu.edu/cmcl/fmm2dlib/fmm2dlib.html) - Fortran, with makefile for a variety of environments  
[lhelmfs](https://math.dartmouth.edu/~ahb/software/lhelmfs.tgz) - C, Linux environment  


### Usage notes for MWrap (may be obsolete)

* The makefiles I include contain useful compilation flags.
* Function names cannot use _ (underscore), even though this is allowable in MATLAB, C, and Fortran. It will fail in a non-informative way if you try this.
* To get mex compilation working on your system you may need to edit `bin/mexopts.sh` in your MATLAB installation directory. On an ubuntu 12.04 system running MATLAB R2012a I needed to add the flag `--openmp` to `LDFLAGS` in the `glnxa64)` case.
* If you want to pass a flag to C, this is as an int. However, Booleans in MATLAB passed directly cause a segfault. They must be converted to doubles. See `c/demo.mw`
* Text output from Fortran `write(*,*)` doesn't seem to make it to the MATLAB terminal, unlike C stdout which does, at least when MATLAB is run with `-nodesktop`. mexPrintf is clumsy but works (see `f/lib.f`).
* The Mac OSX flags require some tweaking: `-lgfortran` may need to be removed. Currently we have problems with `write` in Fortran. Also it seems Xcode doesn't even support OpenMP, so apparently Mac users wanting this will have to install gcc and adjust `mexopts.sh` to point mex to this compiler.
As an alternative we suggest bypassing mex as the compiler, and using GCC.
Examples are in `{f,c}2domp/makefile.nomex`.


### Problems (updated 2/3/17)

Now with R2016b on ubuntu 14.04 LTS the openmp mex files fail upon execution from MATLAB, with the cryptic error:

`Invalid MEX-file 'mwrapdemo/c2domp/gateway.mexa64': dlopen: cannot load any more object with static TLS.`

This is despite the mex complilation reporting no errors.
Mathworks states that they do not support openmp in MEX files, which defeats the point of them. However [this](http://www.mathworks.com/matlabcentral/answers/125117-openmp-mex-files-static-tls-problem) works as a fix for me, ie I do

`export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libgomp.so.1`

before starting MATLAB, and all is good. This bug is disturbing, and
more info is [here](http://stackoverflow.com/questions/19268293/matlab-error-cannot-open-with-static-tls).


### To do list

* Set up flags on Mac and get `write` working there  
* Check this on Windows system; include makefiles
* Include Octave version (need to not use mexPrintf which octave doens't have?)  


### Acknowledgments

* Nick Carriero for `makefile.nomex` examples for OSX+GCC+MATLAB+OpenMP.

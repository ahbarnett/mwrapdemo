# mwrapdemo: simple MWrap examples for MATLAB/Octave calling C/Fortran

  Alex Barnett

[MWrap](https://github.com/zgimbutas/mwrap) is a super-useful code originated by David Bindel that turns the horrible pain of writing a MEX interface into a quick automatic procedure. Wrapping C/Fortran from MATLAB/Octave becomes a pleasant experience! To quote Bindel's introduction,

>From a set of augmented MATLAB script files, MWrap will generate a MEX gateway to desired C/C\++ and FORTRAN function calls and MATLAB function files to access that gateway. MWrap takes care of the details of converting to and from MATLAB's data structures, allocating and freeing temporary storage, handling object upcasts (even in the presence of multiple inheritance), and catching C\++ exceptions. The gateway functions also work with recent versions of Octave when compiled with `mkoctfile --mex.`

The present project contains simple, minimally complete examples showing how to use MWrap to link to a C or Fortran library, pass in and out 1D and 2D arrays, handle complex, float, and Boolean types, and use OpenMP (a big reason to use MEX). These are essential for scientific computing, but I have found require care. The tutorial goal is to make the extra layer of complexity that MWrap introduces as clear as possible. Use them as templates for your codes. Basic makefiles are given which also are useful templates. (Our examples complement Bindel's "foobar" and other more complicated C++-style examples that may not be obvious to new users.) Currently we test only on linux and Mac.


### Dependencies

* [MATLAB](http://www.mathworks.com/products/matlab) or [Octave](https://octave.org)  
* [MWrap](https://github.com/zgimbutas/mwrap)  
* C and Fortran compilers supporting C99 and OpenMP  
* GNU make  

If you are on a mac OSX system, you'll need Xcode to use MATLAB's MEX compiler.


### Getting started

Download this repository either via `git clone` or as zip archive, to a linux or Mac machine. Then

1. Install [MWrap](https://github.com/zgimbutas/mwrap) by following its instructions. Ubuntu/debian users can get an old version via `sudo apt install mwrap`. Create a link, eg via `ln -s /your-mwrap-installation/mwrap ~/bin/mwrap`, or adjust your `PATH` in `.bashrc` so that `mwrap` is in your path. Check this worked via `which mwrap`.

1. Copy `make.inc.example` to `make.inc`, and make any local changes to `make.inc` if needed. The main one is: decide to switch the `MEX` command to use Octave instead of the default MATLAB.

1. For MATLAB you'll want to check that `mex` is in your path. For Octave you'll want to check that `mkoctfile` is in your path. Update `make.inc` to the correct paths if they need to be. (Sometimes on Mac OSX, `mex` calls pdftex in which case you have to give the full path to `mex` such as `/Applications/MATLAB_2012a.app/bin/mex`.)

1. Check you have the compilers `gcc` and `gfortran`. If not, adjust the variables `CC` and `FC` respectively in `make.inc` to point to your compilers, which have to be compatible (GLIBC, etc) with `mex` and/or `mkoctfile`.

1. Type `make`. This should make all examples in the five directories. If it breaks at some point, don't panic; instead `cd` to each directory in turn and try `make`, to see what functionality you can get.

1. From MATLAB, in the main directory, type `testall` which should run all tests, each returning a set of error figures, which should be small. Or, instead, if you set `make.inc` to use Octave, from the shell do `octave testall.m`. If something breaks, you can go into individual directories and try running `test` in each.

See the README files in each of the directories for more information.

*Note: both the top-level makefile and top-level tester change directory. If they exist prematurely, you may have to return to the top directory by hand.*

To remove generated/compiled objects, type `make clean` from the top level directory. Advisable to do this when switch from MATLAB to Octave.


### Contents of this repository

`c/` - simple single-thread C example, 1D array, complex, and a Boolean  
`c2domp/` - 2D array, multi-thread OpenMP C example  
`f/` - simple single-thread Fortran example, 1D array, complex, and a Boolean  
`f2domp/` - 2D array, multi-thread OpenMP Fortran example  
`singleprec/` - native float tests in C++ (needs mwrap>=0.33.11)  
`testall.m` - MATLAB/Octave script to run all demos  
`makefile` - top-level makefile to compile all demos  
`make.inc.example` - system-specific makefile settings example file (copy to `make.inc` and edit that rather than changing this distributed file)  


### Other projects showing how to use MWrap

[BIE3D time-domain interpolation](https://github.com/ahbarnett/BIE3D/tree/master/timedomainwaveeqn/timeinterp) - Fortran90, linux  
[fmmlib3d](https://github.com/zgimbutas/fmmlib3d/tree/master/matlab) - Fortran, with makefile for a variety of environments  
[lhelmfs](https://math.dartmouth.edu/~ahb/software/lhelmfs.tgz) - C, Linux environment  


### Usage notes for MWrap

* Function names cannot use _ (underscore), even though this is allowable in MATLAB, C, and Fortran. It will fail in a non-informative way if you try this.
* To get mex compilation working on an older system you may need to edit `bin/mexopts.sh` in your MATLAB installation directory. On an ubuntu 12.04 system running MATLAB R2012a I needed to add the flag `--openmp` to `LDFLAGS` in the `glnxa64)` case.
* If you want to pass a flag to C, this is as an int. However, Booleans in MATLAB passed directly cause a segfault. They must be converted to doubles. See `c/demo.mw`
* Text output from Fortran `write(*,*)` now does (as of ubuntu 22.04) seem to make it to the MATLAB terminal, even when MATLAB is run with `-nodesktop`. The clumsy use of mexPrintf failed in Octave and has been removed (8/26/22).
* The Mac OSX flags require some tweaking: `-lgfortran` may need to be removed. Currently we have problems with `write` in Fortran. Also it seems Xcode doesn't even support OpenMP, so apparently Mac users wanting this will have to install gcc and adjust `mexopts.sh` to point mex to this compiler. As an alternative we suggest bypassing mex as the compiler, and using GCC. Examples are in `{f,c}2domp/makefile.nomex`.


### Issues

* Octave 6.4.0 on linux seems not to `cd` correctly in scripts;
I filed https://savannah.gnu.org/bugs/?62961

* old (2/3/17): with R2016b on ubuntu 14.04 LTS the openmp mex files fail upon execution from MATLAB, with the cryptic error:

`Invalid MEX-file 'mwrapdemo/c2domp/gateway.mexa64': dlopen: cannot load any more object with static TLS.`

This is despite the mex complilation reporting no errors.
Mathworks states that they do not support openmp in MEX files, which defeats the point of them. However [this](http://www.mathworks.com/matlabcentral/answers/125117-openmp-mex-files-static-tls-problem) works as a fix for me, ie I do

`export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libgomp.so.1`

before starting MATLAB, and all is good. This bug is disturbing, and
more info is [here](http://stackoverflow.com/questions/19268293/matlab-error-cannot-open-with-static-tls).


### Changelog

* Started 2015.
* 2020: added `singleprec/` to test additions to mwrap.   
* 8/26/22: added Octave compatibility, better docs, flags, singleprec by default.  


### To do list

* Set up flags on Mac and get `write` working there  
* Check this on Windows system; include makefiles  


### Acknowledgments

* Nick Carriero for `makefile.nomex` examples for OSX+GCC+MATLAB+OpenMP.

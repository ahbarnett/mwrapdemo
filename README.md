# mwrapdemo: minimally complete examples for using MWrap

  Alex Barnett 7/30/15

[MWrap](http://www.cs.cornell.edu/~bindel/sw/mwrap/) is a code by David Bindel
that makes MEX interface generation simple. To quote Bindel's introduction,

	From a set of augmented MATLAB script files, MWrap will generate a MEX gateway to desired C/C++ and FORTRAN function calls and MATLAB function files to access that gateway. MWrap takes care of the details of converting to and from MATLAB's data structures, allocating and freeing temporary storage, handling object upcasts (even in the presence of multiple inheritance), and catching C++ exceptions. The gateway functions also work with recent versions of Octave when compiled with `mkoctfile --mex.`

The present project is some simple examples showing how to use MWrap.




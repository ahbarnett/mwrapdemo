% run from mwrapdemo directory, in matlab/octave (whichever make.inc selected)

% Notes:
% * seems to be problem with Octave not updating current working directory,
% hence use addpath('.'), which should not be needed. Doing pwd, which("test")
% shows they are inconsistent in octave 6.4, even after a pause(1).

clear

fprintf('Testing C interfaces...\n')
cd c; addpath('.'); test
cd ../c2domp; addpath('.'); test    % octave seems to need addpath (bug?)
% pwd, which("test")   % debug octave only: inconsistent! (or .mex path fails)

fprintf('\nTesting Fortran interfaces...\n')
cd ../f; addpath('.'); test
cd ../f2domp; addpath('.'); test

fprintf('\nTesting single-precision C++ interfaces...\n')
cd ../singleprec; addpath('.'); test
cd ..

fprintf('Completed all mwrapdemo tests.\n')

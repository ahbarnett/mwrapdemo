% Test script for the C mwrap demo.
% Before using, use "make" to call MWrap then compile the MEX object

N = 1e6;
x = rand(N,1);
y = arraysin1d(x);
fprintf('arraysin1d accuracy test: %.3g\n', norm(y - sin(x)))
% should be small

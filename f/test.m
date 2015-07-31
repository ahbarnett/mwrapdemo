% Test script for the Fortran MWrap demo.
% Before using, use "make" to call MWrap then compile the MEX object

N = 1e6;
x = rand(N,1);
w = 5+4.7i;
flag = true;   % test Boolean
[y z] = myfunc(x,w,flag);
fprintf('myfunc double sin accuracy test: %.3g\n', norm(y - sin(x)))
fprintf('myfunc complex double accuracy test: %.3g\n', norm(z-w^2))
% should be small

% Note write(*,*) output doesn't make it to MATLAB terminal.
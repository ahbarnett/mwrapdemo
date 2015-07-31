% Test script for the C mwrap demo with 2d double arrays and openmp.
% Before using, use "make" to call MWrap then compile the MEX object.

% Code does a billion sin evals in a contrived situation in which OpenMP is
% faster than MATLAB built-in.
% We apply sin to a N-by-N random array, iterating reps times.
reps = 1e7;
N = 10;         % For small array and large reps, vectorized MATLAB
                % isn't efficient, even though its sin is multithreaded and
                % the array fits in cache....
disp('please wait several seconds while we do sin() a billion times...')
x = rand(N,N);
tic; ymat = x; for r=1:reps, ymat = sin(ymat); end
fprintf('MATLAB reps of sin done in %.3g s\n',toc)

tic; y = array2d(x,reps); fprintf('array2d done in %.3g s\n',toc)
fprintf('array2d accuracy test: %.3g\n', norm(y(:) - ymat(:))/max(y(:)))

tic; y = array2domp(x,reps); fprintf('array2domp done in %.3g s\n',toc)
fprintf('array2domp accuracy test: %.3g\n', norm(y(:) - ymat(:))/max(y(:)))

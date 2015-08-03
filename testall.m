% run from mwrapdemo directory
fprintf('Testing C interfaces...\n')
cd c; test
cd ../c2domp; test
fprintf('Testing Fortran interfaces...\n')
cd ../f; test
cd ../f2domp; test
cd ..
fprintf('Completed all mwrapdemo tests.\n')

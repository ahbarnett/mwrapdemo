% test the funcs in mwrapfloat. Barnett & Gimbutas.
format long g
format compact

fprintf('scalar real routines...\n')
c = add(double(1/3),double(1/3)), class(c)

try
c = add(single(1)/3,single(1)/3)   % should error
catch ME
  ME.message
  disp('good')
end

try
c = addf(double(1/3),double(1/3)), class(c)   % should error
catch ME
  ME.message
  disp('good')
end

c = addf(single(1)/3,single(1)/3)   % input as designed, should give single



fprintf('\narray real routines...\n')
c = arradd(double(1/3),double(1/3)), class(c)   % double->double, as mwrap 0.33.3 designed for!

try
c = arradd(single(1)/3,single(1)/3)   % should error
catch ME
  ME.message
  disp('good')
end

try
c = arraddf(double(1/3),double(1/3)), class(c)   % should error
catch ME
  ME.message
  disp('good')
end

c = arraddf(single(1)/3,single(1)/3)   % input as designed, should give single


fprintf('\nscalar complex routines...\n')
z = (1+2i)/3; zf = single(z);
c = addz(z,z), class(c)

try
c = addz(zf,zf)   % should error
catch ME
  ME.message
  disp('good')
end

try
c = addc(z,z), class(c)   % should error
catch ME
  ME.message
  disp('good')
end

c = addc(zf,zf)   % input as designed, should give single

fprintf('\narray complex routines...\n')

try
  c = arraddz(z,z), class(c)     % input as designed, double
catch ME
  ME.message
  disp('****** bad')
end

try
c = arraddz(zf,zf)   % should error
catch ME
  ME.message
  disp('good')
end

try
c = arraddc(z,z), class(c)   % should error
catch ME
  ME.message
  disp('good')
end

try
  c = arraddc(zf,zf)    % input as designed, should give single
catch ME
  ME.message
  disp('****** bad')
end

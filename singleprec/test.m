% test the funcs in mwrapfloat. Barnett & Gimbutas.
format long g
format compact

c = add(double(1/3),double(1/3)), class(c)   % double->double, as mwrap 0.33.3 designed for!

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


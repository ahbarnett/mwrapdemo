% test the funcs in mwrapfloat. Barnett & Gimbutas.
format long g
format compact

c = add(double(1/3),double(1/3)), class(c)   % double->double, as mwrap 0.33.3 designed for!

c = add(single(1)/3,single(1)/3)   % should type-convert and give 1e-7 acc, or catch the error

c = addf(double(1/3),double(1/3)), class(c)   % should type-convert to single, or catch error

c = addf(single(1)/3,single(1)/3)   % input as designed, should give single


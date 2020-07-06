% test the funcs in mwrapfloat

c = add(double(1/3),double(1/3)), class(c)   % double->double, as mwrap 0.33.3 designed for!

c = addf(double(1/3),double(1/3)), class(c)   % should type-convert to single, output single

c = addf(single(1)/3,single(1)/3)   % input as designed, should give single


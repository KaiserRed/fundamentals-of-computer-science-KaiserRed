#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef double dbl;
typedef long double ldbl;

ldbl mach_eps();

dbl func (dbl x);
dbl func_2 (dbl x);
dbl Df(dbl x);
dbl DF_2 (dbl x);
dbl DDF_2 (dbl x);
dbl f (dbl x);
dbl Iteration(dbl f(dbl), dbl a, dbl b);
dbl Newton(dbl func(dbl), dbl a, dbl b);

int main(){
    dbl a = 1, b = 1.5, a2 = 1, b2 = 3;
    assert(fabs(Df(a)) < 1);
    assert(fabs(func_2(a2)*DDF_2(a2)) < pow(DF_2(a2),2));
    printf("Iteration method result for func: %f\n", Iteration(f, a, b));
    printf("Newton method result for func_2: %f\n", Newton(func_2, a2, b2));
    return 0;
}

ldbl mach_eps(){
    ldbl eps = 1;
    while (1 + eps / 2.0 > 1) {
        eps /= 2.0;
    }
    return eps;
}

dbl func (dbl x){
    return (1 - x + sin(x) - log(1+x));
}
dbl func_2 (dbl x){
    return (3*x - 14 + exp(x) - exp(-x));
}
dbl f (dbl x){
    return (1 + sin(x) - log(1+x));
}

dbl Df (dbl x){
    return (cos(x) - (1/(1+x)));
}

dbl DF_2 (dbl x){
    return (3 + exp(x) - exp(-x));
}

dbl DDF_2 (dbl x){
    return (exp(x) - exp(-x));
}

dbl Iteration(dbl f(dbl), dbl a, dbl b){
    ldbl eps = mach_eps ();
    dbl x = a + (b - a) / 2;
    while (fabs(f(x) - x) >= eps){
        x = f(x);
    }
    return x;
}

dbl Newton(dbl func(), dbl a, dbl b){
    ldbl eps = mach_eps ();
    dbl x = a + (b - a) / 2;
    dbl x2 = x - (func(x) / DF_2(x));
    while (fabs(x - x2) >= eps){
        x = x2;
        x2 = x - (func_2(x) / DF_2(x));
    }
    return x2;
}

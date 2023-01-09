#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef double dbl;
typedef long double ldbl;

ldbl mach_eps();

dbl func (dbl x);
dbl Df(dbl x);
dbl f (dbl x);
dbl Iteration(dbl f(dbl), dbl a, dbl b);

int main(){
    dbl a = 1, b = 1.5;
    assert(fabs(Df(a)) < 1);
    printf("Iteration method result for func: %f\n", Iteration(f, a, b));
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

dbl f (dbl x){
    return (1 + sin(x) - log(1+x));
}

dbl Df (dbl x){
    return (-1 + cos(x) - (1/(1+x)));
}

dbl Iteration(dbl f(dbl), dbl a, dbl b){
    ldbl eps = mach_eps ();
    dbl x = a + (b - a)/2;
    while (fabs(f(x) - x) >= eps){
        x = f(x);
    }
    return x;
}

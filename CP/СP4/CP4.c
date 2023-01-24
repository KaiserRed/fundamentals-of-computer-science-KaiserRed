#include <stdio.h>
#include <math.h>

typedef double dbl;
typedef long double ldbl;

ldbl mach_eps();

dbl func (dbl x);
dbl func_2 (dbl x);
dbl Df(dbl x);
dbl DF (dbl x);
dbl DDF (dbl x);
dbl Df_2 (dbl x);
dbl DF_2 (dbl x);
dbl DDF_2 (dbl x);
dbl f (dbl x);
dbl f_2 (dbl x);
dbl Iteration(dbl f(dbl), dbl Df(dbl), dbl a, dbl b);
dbl Newton(dbl func(dbl), dbl DF(dbl), dbl DDF(dbl), dbl a, dbl b);
dbl Dichotomy(dbl func(dbl), dbl a, dbl b);

int main(){
    dbl a = 1, b = 1.5, a2 = 1, b2 = 2;
    printf("Iteration method result for func_2: %f\n", Iteration(f_2, Df_2, a2, b2));
    printf("Newton method result for func_2: %f\n", Newton(func_2, DF_2, DDF_2, a2, b2));
    printf("Dichotomy method result for func_2: %f\n", Dichotomy(func_2, a2, b2));
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
    return (cos(x) - exp(-(x*x)/2) + x - 1);
}

dbl f (dbl x){
    return (1 + sin(x) - log(1+x));
}

dbl f_2 (dbl x){
    return (1 - cos(x) + exp(-(x*x)/2));
}

dbl Df (dbl x){
    return (cos(x) - (1/(1+x)));
}

dbl Df_2 (dbl x){
    return (sin(x) - x*exp(-(x*x)/2));
}

dbl DF (dbl x){
    return (-1 + cos(x) - (1/(1+x)));
}

dbl DDF (dbl x){
    return (-sin(x) + (1 / pow(x+1,2)));
}

dbl DF_2 (dbl x){
    return (-sin(x)+x*exp(-(x*x)/2) + 1);
}

dbl DDF_2 (dbl x){
    return (-cos(x) - (x*x - 1)*exp(-(x*x)/2));
}

dbl Iteration(dbl f(dbl), dbl Df(dbl), dbl a, dbl b){
    ldbl eps = mach_eps ();
    dbl x = a + (b - a) / 2;
    if (fabs(Df(x)) < 1){
        while (fabs(f(x) - x) >= eps){
            x = f(x);
        }
    }
    return x;
}

dbl Newton(dbl func(dbl), dbl DF(dbl), dbl DDF(dbl), dbl a, dbl b){
    ldbl eps = mach_eps ();
    dbl x = a + (b - a) / 2;
    dbl x2 = x - (func(x) / DF(x));
    if (fabs(func(a)*DDF(a)) < pow(DF(a),2)) {
        while (fabs(x - x2) >= eps){
            x = x2;
            x2 = x - (func(x) / DF(x));
        }
        return x2;
    }
    else{
        return NAN;
    }
}

dbl Dichotomy(dbl func(dbl), dbl a, dbl b) {
    ldbl eps = mach_eps ();
    dbl x = (a + b) / 2;
    if (func(a) * func(b) < 0){
        while (fabs(a - b) > eps) {
            x = (a + b) / 2;
            if (func(x) * func(a) < 0) {
                b = x;
            }
            else {
                a = x;
            }
        }
        return x;
    } 
    else {
        return NAN;
    }
}

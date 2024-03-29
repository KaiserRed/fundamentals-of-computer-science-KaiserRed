#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_ITER 100

typedef double dbl;
typedef long double ldbl;

const ldbl k = 10e2;

ldbl mach_eps();
ldbl logfunc(ldbl x);
ldbl logTaylor(ldbl x, int n);
void table (dbl a, dbl b, int n);
 
int main(){
    int n;
    dbl a = -0.2, b = 0.3;
    scanf ("%d", &n);
    table (a, b, n);    
    return 0;
}

void table (dbl a, dbl b, int n){
    ldbl result, delta = (b - a) / n;
    ldbl eps = mach_eps();
    printf("Machine epsilon = %.20Lf\n", eps);
    printf("Taylor for f(x) = (ln(1 + x - 2*x**2))\n");
    printf("------------------------------------------------------------------------------\n");
    printf("     x      |         Taylor          |        function         | iterations |\n");
    printf("______________________________________________________________________________\n");
    for (ldbl x = a; x <= b; x+=delta){
        for (n = 0; n < MAX_ITER; n++){
            result = logTaylor(x,n);
        } 
        printf("| %.6Lf | %.20Lf | %.20Lf |     %d    |\n", x, result, logfunc(x), n);
        result = 0.0;
    }
    printf("___________________________________________________________________________\n");
}
ldbl mach_eps(){
    ldbl eps = 1;
    while (1 + eps / 2.0 > 1) {
        eps /= 2.0;
    }
    return eps;
}

ldbl logfunc(ldbl x){
    return (log(1 + x - 2*x*x));
}

ldbl logTaylor(ldbl x, int n){
    ldbl result = 0, eps = mach_eps();
    ldbl member = x, substruction = 1, mult = 2, sum = 0;
    for (int i = 1; i <= n; ++i){
        substruction = mult - 1;
        mult *= -2;
        sum = substruction * member / i;
        member *= x;
        result += sum;
        //result += (((pow(-1,i+1) * pow(2,i) - 1) * pow(x,i)) / i);
        if (fabs(result) <= (fmax(sqrt(eps) * fabs(result), eps))) {
                break;
            }
        }
    return result;
}

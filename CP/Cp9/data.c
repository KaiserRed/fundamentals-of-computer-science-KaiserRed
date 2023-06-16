#include "data.h"

bool complex_read(complex* z){
    char c;
    if (scanf("%lf%c%lf%c%c", &(z->real), &c, &(z->imaginary), &c, &c) == 5)
        return true;
    return false;
}

bool complex_fread(complex* z, FILE* in){
    char c;
    if (fscanf(in, "%lf%c%lf%c%c", &(z->real), &c, &(z->imaginary), &c, &c) == 5){
        return true;
    }
    return false;
}

bool complex_is_equal(complex z1, complex z2){
    if (z1.real == z2.real && z1.imaginary == z2.imaginary)
        return true;
    return false;
}

bool complex_less(complex z1, complex z2){
    if (z1.real < z2.real)
        return true; 
    if (z1.real == z2.real && z1.imaginary < z2.imaginary)
        return true;
    return false;
}

void complex_print(complex z){
    if (z.real != 0 || z.imaginary !=0)
        printf("%.2lf + %.2lf*i", z.real, z.imaginary);
}

#ifndef _DATA_H
#define _DATA_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_STRING_SIZE 100

typedef struct{
    double real;
    double imaginary;
} complex;

typedef struct{
    complex key;
    char str[MAX_STRING_SIZE];
} line;

bool complex_read(complex*);

bool complex_fread(complex*, FILE*);

bool complex_is_equal(complex, complex);

bool complex_less(complex, complex);

void complex_print(complex);

//void complex_set(complex*, double, double);

#endif
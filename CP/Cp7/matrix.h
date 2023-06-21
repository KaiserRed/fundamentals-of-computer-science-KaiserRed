#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stddef.h>

#include "vector.h"

typedef struct{
    Vector *CIP, *PI, *YE;
    size_t n, m;
} Matrix;

Matrix *matrixCreate();

void matrixDestroy(Matrix *mat);
void matrixClear(Matrix *mat);

bool matrixFread(Matrix *mat, FILE*);

void matrixPrint(Matrix *mat);
void matrixPrintRaw(Matrix *mat);

void matrixSet(Matrix *mat, size_t i, size_t j, double value);

int matrixGet(Matrix *mat, size_t i, size_t j);

void matrixTask(Matrix *mat, int num);
#endif // VECTOR_H
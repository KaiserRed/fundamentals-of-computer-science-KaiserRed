#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double* data;
    size_t capacity, size;
} Vector;

Vector *vectorCreate();

double vectorBack(const Vector *vector, double *value);

size_t vectorCapacity(const Vector *vector);

void vectorClear(Vector *vector);

double *vectorData(const Vector *vector);

double vectorGet(const Vector *vector, size_t index);

bool vectorIsEmpty(const Vector *vector);

double vectorPopBack(Vector *vector);

double vectorPushBack(Vector *vector, double value);

void vectorResize(Vector *vector, size_t newSize);

double vectorSet(Vector *vector, size_t index, double value);

size_t vectorSize(const Vector *vector);

void vectorDestroy(Vector *vector);

void vectorInsert(Vector *vector, size_t index, double value);

void vectorPrint(const Vector *vector);

void vectorPrintDouble(const Vector *vector);
#endif // VECTOR_H
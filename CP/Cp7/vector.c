#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

#include "vector.h"

static size_t newCapacity(size_t capacity);

double vectorBack(const Vector * const vector, double * const value) {
    if (vector->size == 0)
        return EINVAL;
    *value = vector->data[vector->size - 1];
    return 0;
}

size_t vectorCapacity(const Vector * const vector) {
    return vector->capacity;
}

void vectorClear(Vector * const vector) {
    vector->size = 0;
}

Vector *vectorCreate(){
    Vector *vector = malloc(sizeof(Vector));
    vector->size = 0;
    vector->capacity = 1;
    vector->data = malloc(vector->capacity * sizeof(double));
    return vector;
}

double *vectorData(const Vector * const vector) {
    return vector->data;
}

void vectorDestroy(Vector * const vector) {
    free(vector->data);
}

double vectorGet(
    const Vector * const vector,
    const size_t index
) {
    if (vector->size <= index)
        return EINVAL;
    return vector->data[index];
}

bool vectorIsEmpty(const Vector * const vector) {
    return vector->size == 0;
}

double vectorPushBack(Vector * const vector, const double value) {
    assert(vector->capacity >= vector->size);
    if (vector->capacity == vector->size) {
        const size_t capacity = newCapacity(vector->capacity);
        double * const data = realloc(vector->data, capacity * sizeof(double));
        if (data == NULL)
            return errno;
        vector->data = data;
        vector->capacity = capacity;
    }
    assert(vector->capacity > vector->size);

    vector->data[vector->size++] = value;
    return 0;
}


double vectorPopBack(Vector * const vector) {
    if (vector->size == 0)
        return EINVAL;
    --vector->size;
    return 0;
}

void vectorResize(Vector * const vector, const size_t newSize) {
    vector->size = newSize;
    vector->data = realloc(vector->data, sizeof(double) * vector->size);
}

double vectorSet(Vector * const vector, const size_t index, const double value) {
    if (vector->size <= index)
        return EINVAL;
    vector->data[index] = value;
    return 0;
}

size_t vectorSize(const Vector * const vector) {
    return vector->size;
}

static size_t newCapacity(const size_t capacity) {
    if (capacity == 0)
        return 1;
    return capacity <= SIZE_MAX / 2 ? capacity * 2 : SIZE_MAX;
}

void vectorInsert(Vector *vector, size_t index, double value){
    vectorResize(vector, vector->size + 1);
    for (size_t i = (vector->size - 1); i > index; i--){
        vector->data[i] = vector->data[i - 1];
    }
    vector->data[index] = value;
}

void vectorPrint(const Vector *vector){
    for (size_t i = 0; i < vector->size; ++i){
        printf("%-.0lf ", vector->data[i]);
    }
    printf("\n");
}
void vectorPrintDouble(const Vector *vector){
    for (size_t i = 0; i < vector->size; ++i){
        printf("%-.1lf ", vector->data[i]);
    }
    printf("\n");
}
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include "util.h"
#include "vector.h"

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
static inline void *ptrOffset(
    const void * const ptr,
    const ptrdiff_t idx,
    const size_t size
) {
    return (char *) ptr + idx * size;
}

static inline void *ptrIncrement(
    const void * const ptr,
    const size_t size
) {
    return ptrOffset(ptr, 1, size);
}

static inline void *elemAt(
    const void * const ptr,
    const size_t idx,
    const size_t size
) {
    return ptrOffset(ptr, (ptrdiff_t) idx, size);
}

void *binarySearch(
    const void * const key,
    const void *array,
    size_t length,
    const size_t size,
    int (* const compare)(const void *, const void *)
) {
    void *end=elemAt(array,length,size);
    while (length != 0U) {
        const size_t index = length >> 1U;
        void * const middle = elemAt(array, index, size);
        const int result = compare(key, middle);
        if (result <= 0)
            length = index;
        else {
            array = ptrIncrement(middle, size);
            length -= index + 1U;
        }
    }
    if (array!=end && compare(key,array)==0) return (void*)array;
    return NULL;
}


int bubbleSort(
    Data ** array,
    const size_t length,
    const size_t size 
) {    
    Data ** result = malloc(size);
    for (size_t i = 0; i <= length; ++i) {
        size_t prev_re = 0;
        for (size_t k = 0; k < length; ++k){
            size_t j = 0, re = 0;
            while (array[k]->key[j] != '+'){
                re = re * 10 + (array[k]->key[j] - '0'); // - 48
                ++j;
            }
            if (prev_re > re){
                memcpy(elemAt(result,0,size),elemAt(array,k-1,size),size);
                memcpy(elemAt(array,k-1,size),elemAt(array,k,size),size);
                memcpy(elemAt(array,k,size),elemAt(result,0,size),size);


            }
            else
                prev_re = re;
        }
    }
    free(result);
    return 0;
}

void reverse(
    const void *array,
    size_t length,
    const size_t size
) {
    for (size_t i = 0 ; i < length>>1; ++i) {
        void *temp = malloc(size);
        memcpy(temp,elemAt(array, i, size),size);
        memcpy(elemAt(array, i, size),elemAt(array, length-i-1, size),size);
        memcpy(elemAt(array, length-i-1, size),temp,size);
        free(temp);
    }
}

void *lowerBound(
    const void * const key,
    const void *array,
    size_t length,
    const size_t size,
    int (* const compare)(const void *, const void *)
) {
    while (length != 0U) {
        const size_t index = length >> 1U;
        void * const middle = elemAt(array, index, size);
        const int result = compare(key, middle);
        if (result <= 0)
            length = index;
        else {
            array = ptrIncrement(middle, size);
            length -= index + 1U;
        }
    }
    return (void *) array;
}

void *upperBound(
    const void * const key,
    const void *array,
    size_t length,
    const size_t size,
    int (* const compare)(const void *, const void *)
) {
    while (length != 0U) {
        const size_t index = length >> 1U;
        void * const middle = elemAt(array, index, size);
        const int result = compare(key, middle);
        if (result >= 0) {
            array = ptrIncrement(middle, size);
            length -= index + 1U;
        }
        else 
            length = index;
    }
    return (void *) array;
}

Pair equalRange(
    const void * const key,
    const void *array,
    size_t length,
    const size_t size,
    int (* const compare)(const void *, const void *)
) {
    void *first = lowerBound(key,array,length,size,compare);
    void *second = upperBound(key,first,length-(((char*)first-(char*)array)/size),size,compare);
    return (Pair){.first = first, .second = second};
}
/*
Обязательно: equal_range, lower_bound, upper_bound
Карма +1: сортирока бинарным деревом (АВЛ)
*/
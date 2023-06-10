#ifndef _DATA_H
#define _DATA_H

#include <stdio.h>
#include <stdbool.h>

#define KEY_SIZE (16U)

typedef struct{
    char key[KEY_SIZE];
    char data[];
} Data;

int cmpData(const void * const a, const void * const b);

int cmpStrWithData(const void * const a, const void * const b);

#endif
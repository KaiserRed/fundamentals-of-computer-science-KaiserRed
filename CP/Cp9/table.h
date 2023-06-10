#ifndef _TABLE_H
#define _TABLE_H

#include <stdio.h>
#include <stdbool.h>
#include "vector.h"

char *inputString(FILE* fp);

void read(Vector * vtable);

void print_table(
    Data ** table,
    const size_t length
);

void print_binary_Search(
    Data ** table,
    const size_t length
);

#endif
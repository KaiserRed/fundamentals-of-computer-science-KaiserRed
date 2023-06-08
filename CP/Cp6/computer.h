#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <stdbool.h>

#define STR_SIZE 32

typedef struct{
    char surname[STR_SIZE];
    unsigned cpu_num;
    char cpu_type[STR_SIZE];
    float memory;   //RAM
    unsigned hdd_num;
    char hdd_type[STR_SIZE];
    float hdd_size;
    char os[STR_SIZE];
} computer;

void select(
    long long p,
    bool (*get)(computer *, const void *),
    void (*put)(const computer *, const void *),
    void *data
);

#endif

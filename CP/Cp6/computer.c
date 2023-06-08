#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "computer.h"

void select(
    long long p,
    bool (*get)(computer *, const void *),
    void (*put)(const computer *, const void *),
    void *data
){ 
    computer comp;
    while (get(&comp, data)){
        if (p == 1 && comp.cpu_num >= 6 && comp.hdd_size >= 2)
            put(&comp, data);
        else if (p == 0 && comp.cpu_num < 6 && comp.hdd_size < 2)
                    put(&comp, data);
        else if (p == 2)
            put(&comp, data);
    }
}
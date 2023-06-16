#ifndef _TABLE_H
#define _TABLE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int tableFread(line*, FILE*);
void tablePrint(line*, int);
void bubbleSort(line*, int);
void binarySearch(line*, int, complex);
void lowerBound(line*, int, complex);
void upperBound(line*, int, complex);
void tableReverse(line*, int);
void tableRandom(line*, int);

//lowerBound
//upperBound
//equalRange

#endif
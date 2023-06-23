# **Отчёт по курсовой работе № 7** по курсу "Алгоритмы и структуры данных"

<b>Студент группы:</b> <ins>М80-108Б-22 Галкин Алексей Дмитриевич, № по списку 3</ins> 

<b>Контакты e-mail:</b> <ins>alexgalkin2004@mail.ru</ins>

<b>Работа выполнена:</b> «20» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5</ins>

<b>Отчет сдан</b> «21» <ins>июня<ins> 2023</ins> г., <b>итоговая оценка</b> <ins> (отлично)</ins>

<b>Подпись преподавателя:</b> ________________  

## 1. Тема
Разряженные матрицы
## 2. Цель работы
Составить программу на языке Си с процедурами и/или функциями для обработки прямоугольных разреженных матриц с
элементами целого (группы 6, 8), вещественного (группы 2-5), или комплексного (группы 1, 7) типов.
## 3. Задание (Вариант №3)
Вариант схемы размещения матрицы: Три вектора.    
Найти элемент матрицы, ближайший к заданному значению. Разделить на него элементы строки и столбца, на
пересечении которых он расположен. Если таких элементов несколько, обработать все.
## 4. Оборудование
<b>Процессор:</b> 11th Gen Intel(R) Core (TM) i7-11370H 3.30GHz<br/>
<b>ОП: 16ГБ <br/>
<b>Монитор: 2880x1800 <br/>
## 5. Програмное обеспечение
<b>Опереционная система семейства: Linux Mint 21.1 Vera<br/>
<b>Интерпретатор команд:</b> bash, версия 5.1.16<br/>
<b>Система программирования:</b> --, версия --<br/>  
<b>Редактор текстов:</b> Vim, Visual Studio Code<br/>
<b>Утилиты операционной системы:</b> gcc,cat<br/>
<b>Прикладные системы и программы:</b>--<br/>
<b>Местанохождение и имена файлов программ и данных на домашнем компьютере:</b> home/alexey<br/>

## 6. Идея, метод, алгоритм   
1. Реализуем вектор
2. Реализуем матрицу
Преобразование происходит в 3 этапа:    
1. Находим элементы, ближайшие к заданному значению через разницу. Если разница между элементом матрицы и заданного значения минимальна, то берём это число
2. Делим элементы, находящиеся в том же столбце, что и найденное число   
3. Делим элементы, находящиеся в той же строчке, что и найденное число     
## 7. Сценарий выполнения работы
vector.h     
```
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

void vectorPushBack(Vector *vector, double value);

void vectorResize(Vector *vector, size_t newSize);

double vectorSet(Vector *vector, size_t index, double value);

size_t vectorSize(const Vector *vector);

void vectorDestroy(Vector *vector);

void vectorInsert(Vector *vector, size_t index, double value);

void vectorPrint(const Vector *vector);

void vectorPrintDouble(const Vector *vector);

#endif // VECTOR_H
```
vector.c    
```
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

#include "vector.h"

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
    free(vector);
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

void vectorPushBack(Vector * const vector, const double value) {
    vectorResize(vector, vector->size + 1);
    vectorSet(vector, vector->size - 1, value);
}


double vectorPopBack(Vector * const vector) {
    if (vector->size == 0)
        return EINVAL;
    --vector->size;
    return 0;
}

void vectorResize(Vector * const vector, const size_t newSize) {
    vector->size = newSize;
    if (newSize > vector->capacity){
        vector->capacity = newSize;
        vector->data = realloc(vector->data, sizeof(double) * vector->capacity);
    }
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
```
matrix.h    
```
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

double matrixGet(Matrix *mat, size_t i, size_t j);

void matrixTask(Matrix *mat, int num);
#endif // VECTOR_H
```
matrix.c     
```
#include "matrix.h"
#include <limits.h>
#include <assert.h>


Matrix *matrixCreate(){
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->CIP = vectorCreate();
    matrix->PI = vectorCreate();
    matrix->YE = vectorCreate();
    matrix->n = 0;
    matrix->m = 0;
    return matrix;
}

void matrixClear(Matrix *mat){
    mat->n = 0;
    mat->m = 0;
    vectorClear(mat->CIP);
    vectorClear(mat->PI);
    vectorClear(mat->YE);
}

void matrixDestroy(Matrix *mat){
    mat->n = 0;
    mat->m = 0;
    vectorDestroy(mat->CIP);
    vectorDestroy(mat->PI);
    vectorDestroy(mat->YE);
    free(mat);
}

bool matrixFread(Matrix *mat, FILE* in){
    if (!in) exit(EXIT_FAILURE);
    int n, m = 0;
    fscanf(in, "%d %d", &m, &n);
    Vector *cip = mat->CIP, *pi = mat->PI, *ye = mat->YE;
    matrixClear(mat);
    mat->n = n;
    mat->m = m;
    for (int i = 0; i < n; ++i){
        vectorPushBack(cip, (int)vectorSize(pi));
        for (int j = 1; j <= m; ++j){
            double el = 0;
            fscanf(in, "%lf", &el);
            if (el != 0){
                vectorPushBack(pi, j);
                vectorPushBack(ye, el);
            }
        }
    }
    vectorPushBack(pi, 0);
    fclose(in);
    return true;
}

void matrixPrint(Matrix *mat){
    int n = mat->n;
    int m = mat->m;
    for (int i = 0; i < n; ++i){
        int ptr = 1;
        int curRowPi = mat->CIP->data[i];
        int nextRowPi;
        if (i == n - 1)
            nextRowPi = (int)(vectorSize(mat->PI) - 1);
        else
            nextRowPi = mat->CIP->data[i + 1];
        while (curRowPi != nextRowPi){
            int curColumn = mat->PI->data[curRowPi];
            double curValue = mat->YE->data[curRowPi];
            while (ptr != curColumn){
                printf("0\t");
                ++ptr;
            }
            printf("%-.1lf\t", curValue);
            ++ptr;
            ++curRowPi;
        }
        while (ptr != (m +1)){
            printf("0\t");
            ++ptr;
        }
        putchar('\n');
    }
}

void matrixPrintRaw(Matrix *mat){
    printf("%ldx%ld\n", mat->m, mat->n);
    printf("CIP: ");
    vectorPrint(mat->CIP);
    printf("PI: ");
    vectorPrint(mat->PI);
    printf("YE: ");
    vectorPrintDouble(mat->YE);
}

void matrixSet(Matrix *mat, size_t i, size_t j, double value){
    int n = mat->n;
    int curRowPi = mat->CIP->data[i];
    int nextRowPi;
    if ((int)i == (n - 1)) {
        nextRowPi = (int)(vectorSize(mat->PI) - 1);
    } else {
        nextRowPi = mat->CIP->data[i + 1];
    }
    if (curRowPi == nextRowPi) {
        j++;
        vectorInsert(mat->PI, curRowPi, (int)j);
        vectorInsert(mat->YE, curRowPi, value);
        for (size_t k = i + 1;(int)k < n;k++)
            mat->CIP->data[k]++;
    } else {
        j++;
        while ((int)j > mat->PI->data[curRowPi] && curRowPi != nextRowPi) {
            curRowPi++;
        }
        if ((int)j == mat->PI->data[curRowPi] && curRowPi != nextRowPi) {
            if (value == 0) {
                mat->PI->size--;
                mat->YE->size--;
                for (int k = curRowPi;(size_t)k < mat->PI->size;k++) {
                    mat->PI->data[k] = mat->PI->data[k + 1];
                    mat->YE->data[k] = mat->YE->data[k + 1];
                }
                for (int k = i + 1;(size_t)k < mat->n;k++) 
                    mat->CIP->data[k]--;
            } else {
                mat->YE->data[curRowPi] = value;
            }
        }
        else {
            vectorInsert(mat->PI, curRowPi, j);
            vectorInsert(mat->YE, curRowPi, value);
            for (size_t k = i + 1;(int)k < n;k++)
                mat->CIP->data[k]++;
        }
    }
}

double matrixGet(Matrix *mat, size_t i, size_t j){
    double result = 0;
    int curRowPi = mat->CIP->data[i];
    int nextRowPi;
    if (i == (mat->n - 1)) {
        nextRowPi = (int)(vectorSize(mat->PI) - 1);
    } else {
        nextRowPi = mat->CIP->data[i + 1];
    }
    j++;
    for (;curRowPi != nextRowPi;curRowPi++) {
        if (mat->PI->data[curRowPi] == (int)j)
            result = mat->YE->data[curRowPi];
    }
    return result;
}

void matrixTask(Matrix *mat, int num){
    Vector *rows = vectorCreate();
    Vector *columns = vectorCreate();
    int n = mat->n;
    int diff = INT_MAX;
    double nearNum = 0;
    for (int i = 0; i < n; ++i){
        int ptr = 1;
        int curRowPi = mat->CIP->data[i];
        int nextRowPi;
        if (i == n - 1)
            nextRowPi = (int)(vectorSize(mat->PI) - 1);
        else
            nextRowPi = mat->CIP->data[i + 1];
        while (curRowPi != nextRowPi){
            int curColumn = mat->PI->data[curRowPi];
            int curValue = mat->YE->data[curRowPi];
            if (diff > abs(curValue - num)){
                vectorClear(rows);
                vectorClear(columns);
                vectorPushBack(columns, curColumn - 1);
                vectorPushBack(rows, curRowPi + 1);
                diff = abs(curValue - num);
                nearNum = curValue;
            }
            else if (diff == abs(curValue - num)){
                vectorPushBack(columns, curColumn - 1);
                vectorPushBack(rows, curRowPi + 1);
            }
            ++ptr;
            ++curRowPi;
        }
    }
    printf("Nearest number: %f\n", nearNum);

    int lenCIP = mat->CIP->size;
    for (int i = 0; i < (int)vectorSize(rows);++i){
        for (int j = 0; j < (int)mat->PI->size;++j){
            if (mat->PI->data[j] - 1  == vectorGet(columns, i) && mat->YE->data[j] != nearNum){
                mat->YE->data[j] = mat->YE->data[j] / nearNum; 
            }
        }
        int curRowPi = vectorGet(rows, i);
        int j = 0;
        int next = 0, prev = 0;
        while (mat->CIP->data[j] < curRowPi){
            ++j;
            next = mat->CIP->data[j];
            if (j != 0)
                prev = mat->CIP->data[j - 1];
            if (j > (int)mat->CIP->size){
                next = mat->YE->size;
                prev = mat->CIP->data[lenCIP - 1];
                break;
            } 
        }
        while (prev != next){
            if (mat->YE->data[prev] != nearNum && mat->YE->data[prev] != 0)
                mat->YE->data[prev] = mat->YE->data[prev] / nearNum; 
            ++prev;
        }
    }  
    vectorDestroy(rows);
    vectorDestroy(columns);
}

```
main.c
```
#include "matrix.h"
#include <limits.h>
#include <assert.h>


Matrix *matrixCreate(){
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->CIP = vectorCreate();
    matrix->PI = vectorCreate();
    matrix->YE = vectorCreate();
    matrix->n = 0;
    matrix->m = 0;
    return matrix;
}

void matrixClear(Matrix *mat){
    mat->n = 0;
    mat->m = 0;
    vectorClear(mat->CIP);
    vectorClear(mat->PI);
    vectorClear(mat->YE);
}

void matrixDestroy(Matrix *mat){
    mat->n = 0;
    mat->m = 0;
    vectorDestroy(mat->CIP);
    vectorDestroy(mat->PI);
    vectorDestroy(mat->YE);
    free(mat);
}

bool matrixFread(Matrix *mat, FILE* in){
    if (!in) exit(EXIT_FAILURE);
    int n, m = 0;
    fscanf(in, "%d %d", &m, &n);
    Vector *cip = mat->CIP, *pi = mat->PI, *ye = mat->YE;
    matrixClear(mat);
    mat->n = n;
    mat->m = m;
    for (int i = 0; i < n; ++i){
        vectorPushBack(cip, (int)vectorSize(pi));
        for (int j = 1; j <= m; ++j){
            double el = 0;
            fscanf(in, "%lf", &el);
            if (el != 0){
                vectorPushBack(pi, j);
                vectorPushBack(ye, el);
            }
        }
    }
    vectorPushBack(pi, 0);
    fclose(in);
    return true;
}

void matrixPrint(Matrix *mat){
    int n = mat->n;
    int m = mat->m;
    for (int i = 0; i < n; ++i){
        int ptr = 1;
        int curRowPi = mat->CIP->data[i];
        int nextRowPi;
        if (i == n - 1)
            nextRowPi = (int)(vectorSize(mat->PI) - 1);
        else
            nextRowPi = mat->CIP->data[i + 1];
        while (curRowPi != nextRowPi){
            int curColumn = mat->PI->data[curRowPi];
            double curValue = mat->YE->data[curRowPi];
            while (ptr != curColumn){
                printf("0\t");
                ++ptr;
            }
            printf("%-.1lf\t", curValue);
            ++ptr;
            ++curRowPi;
        }
        while (ptr != (m +1)){
            printf("0\t");
            ++ptr;
        }
        putchar('\n');
    }
}

void matrixPrintRaw(Matrix *mat){
    printf("%ldx%ld\n", mat->m, mat->n);
    printf("CIP: ");
    vectorPrint(mat->CIP);
    printf("PI: ");
    vectorPrint(mat->PI);
    printf("YE: ");
    vectorPrintDouble(mat->YE);
}

void matrixSet(Matrix *mat, size_t i, size_t j, double value){
    int n = mat->n;
    int curRowPi = mat->CIP->data[i];
    int nextRowPi;
    if ((int)i == (n - 1)) {
        nextRowPi = (int)(vectorSize(mat->PI) - 1);
    } else {
        nextRowPi = mat->CIP->data[i + 1];
    }
    if (curRowPi == nextRowPi) {
        j++;
        vectorInsert(mat->PI, curRowPi, (int)j);
        vectorInsert(mat->YE, curRowPi, value);
        for (size_t k = i + 1;(int)k < n;k++)
            mat->CIP->data[k]++;
    } else {
        j++;
        while ((int)j > mat->PI->data[curRowPi] && curRowPi != nextRowPi) {
            curRowPi++;
        }
        if ((int)j == mat->PI->data[curRowPi] && curRowPi != nextRowPi) {
            if (value == 0) {
                mat->PI->size--;
                mat->YE->size--;
                for (int k = curRowPi;(size_t)k < mat->PI->size;k++) {
                    mat->PI->data[k] = mat->PI->data[k + 1];
                    mat->YE->data[k] = mat->YE->data[k + 1];
                }
                for (int k = i + 1;(size_t)k < mat->n;k++) 
                    mat->CIP->data[k]--;
            } else {
                mat->YE->data[curRowPi] = value;
            }
        }
        else {
            vectorInsert(mat->PI, curRowPi, j);
            vectorInsert(mat->YE, curRowPi, value);
            for (size_t k = i + 1;(int)k < n;k++)
                mat->CIP->data[k]++;
        }
    }
}

int matrixGet(Matrix *mat, size_t i, size_t j){
    int result = 0;
    int curRowPi = mat->CIP->data[i];
    int nextRowPi;
    if (i == (mat->n - 1)) {
        nextRowPi = (int)(vectorSize(mat->PI) - 1);
    } else {
        nextRowPi = mat->CIP->data[i + 1];
    }
    j++;
    for (;curRowPi != nextRowPi;curRowPi++) {
        if (mat->PI->data[curRowPi] == (int)j)
            result = mat->YE->data[curRowPi];
    }
    return result;
}

void matrixTask(Matrix *mat, int num){
    Vector *rows = vectorCreate();
    Vector *columns = vectorCreate();
    int n = mat->n;
    int diff = INT_MAX;
    double nearNum = 0;
    for (int i = 0; i < n; ++i){
        int ptr = 1;
        int curRowPi = mat->CIP->data[i];
        int nextRowPi;
        if (i == n - 1)
            nextRowPi = (int)(vectorSize(mat->PI) - 1);
        else
            nextRowPi = mat->CIP->data[i + 1];
        while (curRowPi != nextRowPi){
            int curColumn = mat->PI->data[curRowPi];
            int curValue = mat->YE->data[curRowPi];
            if (diff > abs(curValue - num)){
                vectorClear(rows);
                vectorClear(columns);
                vectorPushBack(columns, curColumn - 1);
                vectorPushBack(rows, curRowPi + 1);
                diff = abs(curValue - num);
                nearNum = curValue;
            }
            else if (diff == abs(curValue - num)){
                vectorPushBack(columns, curColumn - 1);
                vectorPushBack(rows, curRowPi + 1);
            }
            ++ptr;
            ++curRowPi;
        }
    }
    printf("Nearest number: %f\n", nearNum);
    for (int i = 0; i < (int)vectorSize(columns);++i){
        for (int j = 0; j < (int)mat->PI->size;++j){
            if (mat->PI->data[j] - 1 == vectorGet(columns, i)){
                mat->YE->data[j] = mat->YE->data[j] / nearNum; 
            }
        }
    }
    int lenCIP = mat->CIP->size;
    for (int i = 0; i < (int)vectorSize(rows);++i){
        int curRowPi = vectorGet(rows, i);
        int j = 0;
        int next = 0, prev = 0;
        while (mat->CIP->data[j] < curRowPi){
            ++j;
            next = mat->CIP->data[j];
            prev = mat->CIP->data[j - 1];
            if (j > (int)mat->CIP->size){
                next = mat->YE->size;
                prev = mat->CIP->data[lenCIP - 1];
                break;
            }
            
        }
        while (prev != next){
            if (mat->YE->data[prev]!= nearNum / 2)    
                mat->YE->data[prev] = mat->YE->data[prev] / nearNum; 
            ++prev;
        }
    }
    vectorDestroy(rows);
    vectorDestroy(columns);
}

```
Makefile
```
CC=gcc
RM=rm -fr
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=
SOURCES=main.c matrix.c vector.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

debug: CFLAGS+=-Og -g
debug: all

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE)
```
t2.txt
```
7 7
1 0 2 3 0 0 0
0 0 30 1 0 0 0
0 0 0 0 0 0 0
1 2 3 4 5 0 0
0 0 0 0 0 0 3
0 0 0 0 -1 0 0
2 0 3 0 0 0 0
```
t3.txt
```
3 4 
0 0 1
6 2 0
0 0 0
3 4 9
```
Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
### 8. **Протокол**
```
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp7$ make clean all
rm -fr *.o main
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c main.c -o main.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c matrix.c -o matrix.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c vector.c -o vector.o
gcc  main.o matrix.o vector.o  -o main
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp7$ valgrind --leak-check=full ./main
==16957== Memcheck, a memory error detector
==16957== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==16957== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==16957== Command: ./main
==16957== 
Type filename: t3.txt
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
1
1.0	0	1.0	
6.0	2.0	0	
0	7.0	1.0	
3.0	0	9.0	
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
2
3x4
CIP: 0 2 4 6 
PI: 1 3 1 2 2 3 1 3 0 
YE: 1.0 1.0 6.0 2.0 7.0 1.0 3.0 9.0 
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
4
0 0
1.0
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
3
0 0
5
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
1
5.0	0	1.0	
6.0	2.0	0	
0	7.0	1.0	
3.0	0	9.0	
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
2
3x4
CIP: 0 2 4 6 
PI: 1 3 1 2 2 3 1 3 0 
YE: 5.0 1.0 6.0 2.0 7.0 1.0 3.0 9.0 
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
5
2
Nearest number: 2.000000
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
5
5
Nearest number: 5.000000
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
1
5.0	0	0.2	
0.6	2.0	0	
0	3.5	1.0	
0.6	0	9.0	
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
2
3x4
CIP: 0 2 4 6 
PI: 1 3 1 2 2 3 1 3 0 
YE: 5.0 0.2 0.6 2.0 3.5 1.0 0.6 9.0 
1. Print matrix	 2. Print CIP, PI, YE	 3. Set	 4. Get	 5. Task	 6. Exit
6
==16957== 
==16957== HEAP SUMMARY:
==16957==     in use at exit: 0 bytes in 0 blocks
==16957==   total heap usage: 37 allocs, 37 frees, 7,584 bytes allocated
==16957== 
==16957== All heap blocks were freed -- no leaks are possible
==16957== 
==16957== For lists of detected and suppressed errors, rerun with: -s
==16957== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alexey@alexey-Yoga-Slim-7-Pro-14IHU5:~/code/fundamentals-of-computer-science-KaiserRed/CP/Cp7$ 

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 20.06.23 | 17:00 | Выполнение лабораторной работы | - | - |    
## 10. Замечания автора по существу работы
По ходу защиты лабораторной работы было дано задание из Codeforces:     
Защита с Codeforces (div 3)     
[1843A](https://codeforces.com/contest/1843/submission/210376318)     
[1843C](https://codeforces.com/contest/1843/submission/210424772)    
Дорешка     
[1843B](https://codeforces.com/contest/1810/submission/206597805)    

## 11. Выводы
Были получены навыки написания эффективных программ для обработки разряженных матриц. Были отработаны навыки работы с файлами, динамическими структурами и указателями в Си. 
<b>Подпись студента:</b> ____________________

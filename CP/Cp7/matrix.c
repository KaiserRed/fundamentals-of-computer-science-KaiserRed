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
                //vectorSet(mat->YE, prev, mat->YE->data[prev] / nearNum);
                mat->YE->data[prev] = mat->YE->data[prev] / nearNum; 
            ++prev;
        }
    }  
    vectorDestroy(rows);
    vectorDestroy(columns);
}

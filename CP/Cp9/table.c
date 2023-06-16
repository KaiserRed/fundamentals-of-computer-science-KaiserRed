#include "table.h"

int tableFread(line table[], FILE* in){
    int i = 0;
    while (!feof(in)){
        complex_fread(&(table[i].key), in);
        fgets(table[i].str, MAX_STRING_SIZE, in);
        ++i;
    }
    return i;
}
void tablePrint(line table[], int size){
    for (int i = 0; i < size; ++i){
        complex_print(table[i].key);
        printf(" %s", table[i].str);
    }
}
void swap(line* l1, line* l2){
    line tmp = *l1;
    *l1 = *l2;
    *l2 = tmp;
}
void bubbleSort(line table[], int size){
    for (int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - 1; ++j){
            if (complex_less(table[j+1].key, table[j].key)){
                swap(table + j, table + j + 1);
            }
        }
    }
}

void binarySearch(line table[], int size, complex k){
    int left = 0, right = size, mid;
    while(left < right){
        mid = left + (right - left) / 2;

        if(complex_less(k, table[mid].key)) right = mid;
        else left = mid + 1;
    }

    if(complex_is_equal(table[--right].key, k)){
        complex_print(k);
        printf("  %s\n", table[right].str);
    }
    else{
        printf("Key not found\n");
    }
}

void lowerBound(line table[], int N, complex k){
    int mid, low = 0, high = N;
    while (low < high){
        mid = low + (high - low) / 2;
        if (complex_less(k, table[mid].key) || complex_is_equal(k, table[mid].key))
            high = mid;
        else
            low = mid + 1;
    }
    if (low < N && complex_less(table[low].key, k))
        low++;
    complex_print(table[low].key);
}

void upperBound(line table[], int N, complex k){
    int mid, low = 0, high = N;
    while (low < high){
        mid = low + (high - low) / 2;
        if (complex_less(k, table[mid].key))
            high = mid;
        else
            low = mid + 1;
    }
    if (low < N && (complex_less(table[low].key, k)))
        low++;
    complex_print(table[low].key);
}

void tableReverse(line table[], int size){
    for(int i = 0; i < size / 2; ++i){
        swap(table + i, table + size - 1 - i);
    }
}

void tableRandom(line table[], int size){
    for(int  i = 0; i < size; ++i){
        int j = rand() % size;
        swap(table +i, table + j);
    }
}

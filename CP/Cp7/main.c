#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"
#include "matrix.h"

int main(){
    int choose, g = 1;
    Matrix *mat = matrixCreate();
    char filename[40];
    printf("Type filename: ");
    scanf("%s", filename);
    FILE *in=fopen(filename,"r");
    if (!matrixFread(mat, in))
        exit(EXIT_FAILURE);
    while(g){
        printf("1. Print matrix\t 2. Print CIP, PI, YE\t 3. Set\t 4. Get\t 5. Task\t 6. Exit\n");
        scanf("%d", &choose);
        switch(choose){
            case 1: {
                matrixPrint(mat);
                break;
            }
            case 2: {
                matrixPrintRaw(mat);                
                break;
            }
            case 3: { 
                size_t i, j;
                int value;
                scanf("%lu %lu %d", &i, &j, &value);
                matrixSet(mat, i, j, value);
                break;
            }
            case 4: {
                size_t i, j;
                scanf("%lu %lu", &i, &j);
                printf("%d\n", matrixGet(mat, i, j));
                break;
            }
            case 5: {
                int value;
                scanf("%d", &value);
                matrixTask(mat, value);
                break;
            }
            case 6: {
                g = 0;
                break;
            }
            default: {
                printf("Wrong command\n");
            }
        }
    }
    return 0;
}

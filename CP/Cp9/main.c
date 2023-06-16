#include "table.h"
#include "data.h"

#include <stdlib.h>

int main(){
    FILE *in=fopen("file.txt","r");
    if (!in) exit(EXIT_FAILURE);
    line* table = (line*)malloc(MAX_STRING_SIZE*sizeof(line));
    int size = tableFread(table, in);
    int choose, g = 1;
    while(g){
        printf("\n1. Print table\t 2. Bubble sort\t 3. Random\t 4. Reverse\t 5. BinarySearch\t 6. lowerBound\t 7. upperBound\t 8. equalRange\t 9. Exit\n");
        scanf("%d", &choose);
        switch(choose){
            case 1: {
                tablePrint(table, size);
                break;
            }
            case 2: {
                printf("\nBefore:\n");
                tablePrint(table, size);
                bubbleSort(table, size);
                printf("\nAfter:\n");
                tablePrint(table, size);
                break;
            }
            case 3: { 
                tableRandom(table, size);
                break;
            }
            case 4: {
                tableReverse(table, size);
                break;
            }
            case 5: {
                complex z;
                complex_read(&z);
                binarySearch(table, size, z);
                break;
            }
            case 6: {
                complex z;
                complex_read(&z);
                lowerBound(table, size, z);
                break;
            }
            case 7: {
                complex z;
                complex_read(&z);
                upperBound(table, size, z);
                break;
            }
            case 8: {
                complex z;
                complex_read(&z);    
                lowerBound(table, size, z);
                printf("\t");
                upperBound(table, size, z);
                break;
            }
            case 9: {
                g = 0;
                break;
            }
            default: {
                printf("Wrong command\n");
            }
        }
    }
    fclose(in);
    free(table);
    return 0;
}

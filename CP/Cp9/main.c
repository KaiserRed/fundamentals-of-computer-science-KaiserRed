#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vector.h"
#include "util.h"
#include "string.h"
#include "data.h"
#include "table.h"


int main() {
    Vector vtable;
    vectorCreate(&vtable);
    read(&vtable);  
    Data ** table = vectorData(&vtable);
    size_t lines_count = vectorSize(&vtable);
    int choose, g = 1;
    while (g) {
        printf("1. Print table\t 2. Bubble sort\t 3. Reverse\t 4. Binary search\t5. Equal_range\t 6. Lower_bound\t 7. Upper_bound\t 8. Exit \n");
        scanf("%d", &choose);
        switch (choose) {
            case 1: {
                print_table(table,lines_count);
                break;
            }
            case 2: {
                printf("Table before sort\n");
                print_table(table,lines_count);
                printf("Table after sort\n");
                bubbleSort(table, lines_count,sizeof(Data*)); 
                print_table(table,lines_count);
                break;
            }
            case 3: {
                reverse(table,lines_count,sizeof(Data*));
                break;
            }
            case 4: {
                print_binary_Search(table, lines_count);
                break;
            }
            case 5: {
                Pair res = equalRange(&(char*){"0+2i"},table,lines_count,sizeof(Data*),cmpData);
                printf("%s, %s\n",(*(Data**)res.first)->data,(*(Data**)res.second)->data);
                break;
            }
            case 6: {
                printf("%s\n",(*(Data**)lowerBound(&(char*){"0+2i"},table,lines_count,sizeof(Data*),cmpData))->data);
                break;
            }
            case 7: {
                printf("%s\n",(*(Data**)upperBound(&(char*){"0+2i"},table,lines_count,sizeof(Data*),cmpData))->data);
                break;
            }              
            case 8: {
                g = 0;
                break;
            }
            default: {
                printf("Wrong answer\n");
            }
        }
    }
    vectorDestroy(&vtable);
    return 0;
}

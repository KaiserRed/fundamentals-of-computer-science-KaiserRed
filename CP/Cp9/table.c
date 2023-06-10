#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "vector.h"
#include "util.h"
#include "string.h"
#include "data.h"
#include "table.h"


char *inputString(FILE* fp){
    size_t size = 16;
    char *str;
    int ch;
    size_t len = 0;
    str = malloc(size);
    if (!str) return str;
    while((ch=fgetc(fp)) != '\n'){
        if (ch == EOF) {
            if (len==0) {
                free(str);
                return NULL;
            }
            else break;
        };
        str[len++]=ch;
        if(len==size) {
            str = realloc(str, size*=2);
            if (!str) return str;
        }
    }
    str[len++]='\0';
    return realloc(str, len);
}
void read(Vector * vtable){
    FILE *table_txt=fopen("file.txt","r");
    if (!table_txt) exit(EXIT_FAILURE);
    char *str;
    for (;;) {
        str = inputString(table_txt);
        if (!str) break;
        char *val;
        size_t i = 0;
        bool comma_is_found=false;
        while (str[i]!='\0') {
            if (str[i]==';' && i < KEY_SIZE) {
                str[i]='\0';
                val = str+i+1;
                comma_is_found = true;
                break;
            }
            ++i;
        }
        if (!comma_is_found) exit(EXIT_FAILURE);
        char *key = str;
        size_t val_size = strlen(val)+1;
        size_t real_key_size = strlen(key)+1;
        Data *line = malloc(sizeof(Data)+val_size);
        memcpy(line->key,key,real_key_size);
        memcpy(line->data,val,val_size);
        vectorPushBack(vtable, line);
        free(str);
    }
    fclose(table_txt);

}
void print_table(
    Data ** table,
    const size_t length
){
    for (size_t i=0;i < length;++i){
        printf("%s %s\n",table[i]->key,table[i]->data);
    }
    printf("---------\n");
}

void print_binary_Search(
    Data ** table,
    const size_t length
) {
    for (;;) {
        char *str;
        str = inputString(stdin);
        if (!str) break;
        Data **res = binarySearch(&str,table,length,sizeof(Data*),cmpStrWithData);
        if (str[0] == '.'){ 
            printf("\n");
            break;
        }
        else if (!res)  printf("\n");
        else {
            Data **end = table + length;
            while (res != end && cmpStrWithData(&str, res) == 0) {
                printf("%s %s\n", (*res)->key,(*res)->data);
                ++res;
            }
        }
        free(str);
    }
}
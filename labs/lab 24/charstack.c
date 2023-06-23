#include "charstack.h"
#include <errno.h>

stack* NewCharStack(int capacity){
    stack* pt =  (stack*)malloc(sizeof(stack));
    
    pt -> maxsize = capacity;
    pt -> top = -1;
    pt -> items = (char*)malloc(capacity*sizeof(char));
    memset(pt -> items, 0, capacity);

    return pt;
}

void CharPush(stack* pt, char x){
    if(pt -> top == pt -> maxsize - 1){
        printf("stack overflow");
        return;
    }

    pt -> items[++(pt -> top)] = x;
}

void CharPop(stack* pt){
    if(pt -> top == -1){
        return;
    }

    pt->top--;
}

char CharTop(stack* pt){
    if(!(pt -> top == -1)){
        return pt -> items[pt -> top];
    } 
    return EINVAL; 
}

void FreeCharStack(stack* st){
    free(st -> items);
    free(st);
}

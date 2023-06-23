#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef __CharStack_h__
#define __CharStack_h__


struct CharStack {
    int maxsize;
    int top;
    char* items;
};

typedef struct CharStack stack;

stack* NewCharStack(int capacity);

void CharPush(stack* pt, char x);

void CharPop(stack* pt);

char CharTop(stack* pt);

void FreeCharStack(stack* st);

#endif

#ifndef _Stack_H_
#define _Stack_H_

#include "types.h"

typedef struct {
    int size;
    T data[100];
} Stack;

void Create(Stack* s);
bool Empty(Stack* s);
int Size(Stack* s);
bool Push(Stack* s, T t);
bool Pop(Stack* s);
T Top(Stack* s);
void Destroy(Stack* s);
void Input(Stack* s);
void Output(Stack* s);

#endif
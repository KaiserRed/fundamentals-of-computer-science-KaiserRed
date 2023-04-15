#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#include "stack.h"

void Merge(Stack* s1, Stack* s2, Stack* s){
    Stack merged;
    Create(&merged);
    while (!Empty(s1) && !Empty(s2)){
        if (Top(s1) > Top(s2)){
            Push(&merged, Top(s2));
            Pop(s2);
        }
        else{
            Push(&merged, Top(s1));
            Pop(s1);

        }
    }
    while (!Empty(s1)){
            Push(&merged, Top(s1));
            Pop(s1);
    }
    while (!Empty(s2)){
            Push(&merged, Top(s2));
            Pop(s2);
    }
        while (!Empty(&merged)){
            Push(s, Top(&merged));
            Pop(&merged);
    }
    Destroy(s1);
    Destroy(s2);
    Destroy(&merged);
}

void Sort(Stack* s){
    Stack s1;
    Stack s2;
    Create(&s1);
    Create(&s2);
    while (s->size != 0){
        if (s->size % 2 == 0){
            Push(&s1, Top(s));
            Pop(s);
        }
        else {
            Push(&s2, Top(s));
            Pop(s);
        }
    }
    if (Size(&s1) > 1)
        Sort(&s1);
    if (Size(&s2) > 1)
        Sort(&s2);
    Merge(&s1, &s2, s);
}
#include "nodestack.h"
#include <errno.h>

NodeStack* NewNodeStack(int capacity){
    NodeStack* st = (NodeStack*)malloc(sizeof(NodeStack));

    st -> maxsize = capacity;
    st -> top = -1;
    st -> items = (Node**)malloc(capacity*sizeof(Node*));

    return st; 
}

void NodePush(NodeStack* st, Node* x){
    if(st -> top == st -> maxsize - 1){
        return;
    }

    st -> items[++(st -> top)] = x;
}

void NodePop(NodeStack* st){
    if(st -> top == -1){
        return;
    }

    st->top--;
}

Node* NodeTop(NodeStack* st){
    //if(st -> top != -1){
    return st -> items[st -> top];
    //}
    //return EINVAL;
}

void FreeNodeStack(NodeStack* st){
    free(st -> items);
    free(st);
}


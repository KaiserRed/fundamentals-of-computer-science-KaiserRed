#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#ifndef __NodeStack_h__
#define __NodeStack_h__

struct NodeStack{
    int maxsize;
    int top;
    Node** items;
};

typedef struct NodeStack NodeStack;

NodeStack* NewNodeStack(int capacity);

void NodePush(NodeStack* st, Node* x);

void NodePop(NodeStack* st);

Node* NodeTop(NodeStack* st);

void FreeNodeStack(NodeStack* st);
#endif


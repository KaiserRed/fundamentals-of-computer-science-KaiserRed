#include<stdio.h>
#include<stdlib.h>
#ifndef __Node_h__
#define __Node_h__

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* NewNode(int a, Node* left, Node* right);

Node* NewNumberNode(int a);

#endif

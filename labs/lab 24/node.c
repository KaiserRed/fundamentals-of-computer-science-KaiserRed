#include "node.h"

Node* NewNode(int a, Node* left, Node* right){
    Node* root = (Node*)malloc(sizeof(Node));

    root -> left = left;
    root -> right = right;
    root -> data = a;
    return root;
}

Node* NewNumberNode(int a){
    Node* root = (Node*)malloc(sizeof(Node));

    root -> left = NULL;
    root -> right = NULL;
    root -> data = a;
    return root;
}

#include "extree.h"
#include <stdbool.h>

int main(){
    char* infix = (char*)malloc(50*sizeof(char));
    printf(" Input math expression: ");
    scanf("%s", infix);
    printf("%s\n", infix);

    stack* operands = NewCharStack(50);
    stack* operations = NewCharStack(50);
    ToRPN(infix, operands, operations);
    free(infix);

    printf("Postfix:%s\n", operands -> items);
    
    Node* root = ConstructExTree(operands -> items);
    FreeCharStack(operands);
    FreeCharStack(operations);

    PrintTree(root, 0);
    
    Node** queue = (Node**)malloc(50*sizeof(Node*));
    queue[0] = root;
    Node** ancestor = (Node**)malloc(50*sizeof(Node*));
    ancestor[0] = NULL;
    char* ancFlag = (char*)malloc(50*sizeof(char));
    ancFlag[0] = 'k';
    Solution(&root, queue, ancestor, ancFlag);
    free(queue);
    free(ancestor);
    free(ancFlag);

    printf("Math expression after: ");
    PrintInfixExpression(root);
    printf("\n");
    printf("Tree: \n");
    PrintTree(root, 0);

    FreeSubTree(root);
}


#ifndef __ExTree_h__
#define __ExTree_h__
#include <stdbool.h>
#include "charstack.h"
#include "nodestack.h"

bool IsOperator(int a);

bool IsOperand(int a);

bool IsPriority(char top, char a);

void ToRPN(char* infix, stack* postfix, stack* operations);

Node* ConstructExTree(char* postfix);

Node* ToLeft(Node* tree);

Node* ToRight(Node* tree);

void FreeSubTree(Node* root);

void Solution(Node** root, Node** queue, Node** ancestors, char* ancFlag);

void PrintInfixExpression(Node* root);

void PrintTree(Node* root, int depth);

#endif

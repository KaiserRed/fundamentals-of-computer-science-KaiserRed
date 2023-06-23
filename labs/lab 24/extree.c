#include "extree.h"
#include <ctype.h>

bool IsOperator(int a){
    if(a < 0 || a > 127) return false;
    return (char)a == '+' || (char)a == '-' || (char)a == '/' || (char)a == '*' || (char)a == '^' ;
}

bool IsOperand(int a){
    if(IsOperator(a)) return false;
    if((char)a == '(' || (char)a == ')') return false;
    return true;
}

bool IsPriority(char top, char a){
    if(top == '^') return false;

    if(a == '^') return true;

    if (top == '*' || top == '/') return false;

    if(a == '+' || a == '-') return false;

    return true;
}

void ToRPN(char* infix, stack* postfix, stack* operations){
    int i = 0;
    while(infix[i] != '\0'){

        if(IsOperand(infix[i])){
            CharPush(postfix, infix[i]);
        } 
        else if (IsOperator(infix[i])){
            if(operations -> top == -1 || CharTop(operations) == '('){
                CharPush(operations, infix[i]);
            }
            else if(IsPriority(CharTop(operations), infix[i])){
                CharPush(operations, infix[i]);
            }
            else {
                while(CharTop(operations) != '(' && operations->top != -1 &&  !IsPriority(CharTop(operations), infix[i])){
                    CharPush(postfix, CharTop(operations));
                    CharPop(operations);
                }
                CharPush(operations, infix[i]);
            }
        }
        else if(infix[i] == '('){
            CharPush(operations, infix[i]);
        }
        else if (infix[i] == ')'){
            while(CharTop(operations) != '('){
                CharPush(postfix, CharTop(operations));
                CharPop(operations);
            }
            CharPop(operations);
        }
        i++;
    }

    while(operations -> top != -1){
        CharPush(postfix, CharTop(operations));
        CharPop(operations);
    }
}

Node* ConstructExTree(char* postfix){
    if(strlen(postfix) == 0){
        return NULL;
    }

    NodeStack* s = NewNodeStack(50);//

    for(int i = 0; i < (int)strlen(postfix); ++i){
        if(IsOperator(postfix[i])){
            Node* x = NodeTop(s);
            NodePop(s);
            Node* y = NodeTop(s);
            NodePop(s);

            Node* node = NewNode(postfix[i], y, x);
            NodePush(s, node);
        }
        else{
            NodePush(s, NewNumberNode(postfix[i]));
        }
    }

    Node* res = NodeTop(s);
    FreeNodeStack(s);

    return res;
}

Node* ToLeft(Node* tree){
    if(tree -> left != NULL) return tree -> left;
    return NULL;
}

Node* ToRight(Node* tree){
    if (tree -> right != NULL) return tree -> right;
    return NULL;
}

bool MakeFraction(Node* tree, char* numerator, char* denominator, int* numInd, int* denomInd, bool flag){
    if((char)tree -> data == '/'){
    
        if(IsOperand((char)tree -> left -> data) && flag == true){
            numerator[(*numInd)++] = (char)tree -> left -> data;
        }

        else if(IsOperand((char)tree -> left -> data) && flag == false){
            denominator[(*denomInd)++] = (char)tree -> left -> data;
        }

        if(IsOperand((char)tree -> right -> data) && flag == true){
            denominator[(*denomInd)++] = (char)tree -> right -> data;
        }

        else if(IsOperand((char)tree -> right -> data) && flag == false){
            numerator[(*numInd)++] = (char)tree -> right -> data;
        }

        if(IsOperator(tree -> left -> data)){
            if(MakeFraction(ToLeft(tree), numerator, denominator, numInd, denomInd, flag) == false) 
                return false;
        }

        if (IsOperator(tree -> right -> data)){
            if(MakeFraction(ToRight(tree), numerator, denominator, numInd, denomInd, !flag) == false) 
                return false;
        }

    }

    else if((char)tree -> data == '*'){

        if(IsOperand((char)tree -> left -> data) && flag == true){
            numerator[(*numInd)++] = (char)tree -> left -> data;
        }

        if(IsOperand((char)tree -> right -> data) && flag == true){
            numerator[(*numInd)++] = (char)tree -> right -> data;
        }

        if(IsOperand((char)tree -> left -> data) && flag == false){
            denominator[(*denomInd)++] = (char)tree -> left -> data;
        }

        if(IsOperand((char)tree -> right -> data) && flag == false){
            denominator[(*denomInd)++] = (char)tree -> right -> data;
        }

        if(IsOperator(tree -> left -> data)){
            if(MakeFraction(ToLeft(tree), numerator, denominator, numInd, denomInd, flag) == false) 
                return false;
        }

        if (IsOperator(tree -> right -> data)){
            if(MakeFraction(ToRight(tree), numerator, denominator, numInd, denomInd, flag) == false) 
                return false;
        }


    }

    else return false;

    return true;
}

void MakeDivision(char**  numerator, char** denominator){
    for(int i = 0; i < (int)strlen(*denominator); ++i){
        char a = (*denominator)[i];
        if(isalpha(a)){
            for(int j = 0; j < (int)strlen(*numerator); ++j){
                if((*numerator)[j] == a) {
                    (*numerator)[j] = '&';
                    (*denominator)[i] = '&'; 
                    break;
                }
            }
        }
        if(isdigit(a)){
            int num1 = (int)(a -'0');
            for(int j = 0; j < (int)strlen(*numerator); ++j){
                if(isdigit((*numerator)[j])){
                    int num2 = (int)((*numerator)[j] - '0');
                    if(num2 % num1 == 0){
                        (*numerator)[j] = (char)(num2 / num1 + 48);
                        (*denominator)[i] = '&';
                        break;
                    }
                }
            }
        }
    }

    int resInd = 0;
    char* numeratorRes = (char*)malloc(50);
    memset(numeratorRes, 0, 50);
    for(int i = 0; i < (int)strlen(*numerator); ++i){
        if((*numerator)[i] != '&' && (*numerator)[i] != '1') {numeratorRes[resInd++] = (*numerator)[i];numeratorRes[resInd++] = '*';}
    }

    if(resInd > 0 && numeratorRes[--resInd] == '*') numeratorRes[resInd] = '\0';

    resInd = 0;
    char* denominatorRes = (char*)malloc(50);
    memset(denominatorRes, 0, 50);
    if(strlen(*denominator) != 0){
        for(int i = 0; i < (int)strlen(*denominator); ++i){
        if((*denominator)[i] != '&' && (*denominator)[i] != '1') {denominatorRes[resInd++] = (*denominator)[i];denominatorRes[resInd++] = '*';}
        }

        if (resInd > 0 && denominatorRes[--resInd] == '*') denominatorRes[resInd] = '\0';
        
        memset(*denominator, 0, strlen(*denominator));
        
        for(int i = 0; i < (int)strlen(denominatorRes); ++i){
            (*denominator)[i] = denominatorRes[i];
        }
    }
    
    memset(*numerator, 0, strlen(*numerator));
    for(int i = 0; i < (int)strlen(numeratorRes); ++i){
        (*numerator)[i] = numeratorRes[i];
    }
    
    free(numeratorRes);
    free(denominatorRes);
}

bool CheckEmptyString(char* str){
    return strlen(str) == 0;
}

char* ConcateNumAndDenom(char* numerator, char* denominator){
    if(strlen(numerator) == 0) numerator[0] = '1';
    if(strlen(numerator) > 1){
        for(int i = strlen(numerator) - 1; i >= 0; --i){
            numerator[i+1] = numerator[i];
        }
        numerator[0] = '(';
        numerator = strcat(numerator, ")");
    } 
    if(strlen(denominator) > 1){
        for(int i = strlen(denominator) - 1; i >= 0; --i){
            denominator[i+1] = denominator[i];
        }
        denominator[0] = '(';
        denominator = strcat(denominator, ")");
    }

    char* fraction = NULL   ; 
    if(strlen(denominator) != 0){
        fraction = strcat(numerator, "/");
        fraction = strcat(fraction, denominator);
    }
    else{
        fraction = numerator;
    }

    return fraction;
}

void FreeSubTree(Node* root){
    if(root == NULL) return;
    FreeSubTree(root -> left);
    FreeSubTree(root -> right);
    free(root);
}

void Solution(Node** root, Node** queue, Node** ancestors, char* ancFlag){
    int start = 0;
    int end = 1;

    while(start < end){
        Node* tmp = queue[start];
        Node* anc = ancestors[start];
        char flag = ancFlag[start++];

        if((char)tmp -> data == '/' || (char)tmp -> data == '*'){

            char* numerator = (char*)malloc(50*sizeof(char));//
            char* denominator = (char*)malloc(50*sizeof(char));//
            memset(denominator, 0, 50);
            memset(numerator, 0, 50);
            int numInd = 0;
            int denomInd = 0;
            bool error = MakeFraction(tmp, numerator, denominator, &numInd, &denomInd, true);
            char* fraction;
            if(error != false) {
                MakeDivision(&numerator, &denominator);
                fraction = ConcateNumAndDenom(numerator, denominator);
            }
            stack* operands = NewCharStack(50);
            stack* operations = NewCharStack(50);
            ToRPN(fraction, operands, operations);
            char* postfix = operands -> items;

            Node* newRoot = ConstructExTree(postfix);
            FreeCharStack(operands);
            FreeCharStack(operations);
            if(tmp == *root){
                *root = newRoot;
                FreeSubTree(tmp);
                tmp = newRoot;
            }
            else{
                if(flag == 'l'){
                    (anc) -> left = newRoot;
                    FreeSubTree(tmp);
                    tmp = newRoot;
                }
                else if (flag == 'r'){
                    (anc) -> right = newRoot;
                    FreeSubTree(tmp);
                    tmp = newRoot;
                }
            }
            free(numerator);
            free(denominator);

        }
        if(tmp -> left != NULL){
            queue[end] = tmp -> left;
            ancestors[end] = tmp;
            ancFlag[end++] = 'l';
            queue[end] = tmp -> right;
            ancestors[end] = tmp;
            ancFlag[end++] = 'r';
        }
    }
}

void PrintInfixExpression(Node* root){
    if(root == NULL) return;

    if(IsOperator(root -> data)) printf("(");

    PrintInfixExpression(ToLeft(root));
    printf("%c", root -> data);
    PrintInfixExpression(ToRight(root));

    if(IsOperator(root -> data)) printf(")");
}

void PrintTree(Node* root, int depth){
    if(root == NULL) return;
    
    PrintTree(root -> right, depth+1);

    for(int i = 0; i < depth; ++i){
        printf("  ");
    }
    
    printf("%c\n", root -> data);
    PrintTree(root -> left, depth+1);
    
}

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "minleaf.h"

void min_leaf(float t, int x, float m[]){
    if (x < m[1]){
        m[0] = t;
    }
}
 
void task(node *t, int x, float m[]){
    if (t == NULL) {
        return;
    }
    if (t->son == NULL)
        min_leaf(t->value, x, m);
    task(t->son, x + 1, m);
    task(t->brother, x, m);
}
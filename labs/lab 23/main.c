#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "tree.h"
#include "minleaf.h"
int main() {
    Tree *t = NULL;
    int choose, g = 1;
    while (g) {
        printf("1. Create tree\t 2. Add node to tree\t 3. Delete node from tree\t 4. Task\t 5. Pre_Order\t6. Post_Order\t 7. Exit \n");
        scanf("%d", &choose);
        switch (choose) {
            case 1: {
                printf("Write tree's root\n");
                float f;
                scanf("%f", &f);
                t = create_tree(f);
                break;
            }
            case 2: {
                printf("Write tree node value\n");
                float f, par_f;
                scanf("%f", &f);
                printf("Write parent value\n");
                scanf("%f", &par_f);
                add_node_in_tree(t, par_f, f);
                break;
            }
            case 3: {
                printf("Write tree node value\n");
                float f;
                scanf("%f", &f);
                delete_node(t, f);
                break;
            }
            case 4: {
                float m[] = {0, INT_MAX};
                task(t->root, 0, m);
                printf("%-.2f\n", m[0]);
                break;
            }
            case 5: {
                preOrder(t->root, 0);
                break;
            }
            case 6: {
                postOrder(t->root);
                break;
            }
            case 7: {
                g = 0;
                break;
            }
            default: {
                printf("Wrong answer\n");
            }
        }
    }
    delete(t->root);
    free(t);
    return 0;
}
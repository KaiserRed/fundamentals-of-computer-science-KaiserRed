#include <stdio.h>
#include "list.h"

int main(void) {
    List b;
    listCreate(&b);
    listPushFront(&b, 4);
    listPushBack(&b, 9);
    listPushFront(&b, 1);
    listPushBack(&b, 10);
    printf("Size = %ld\n", listSize(&b));
    printList(&b);
    ListIterator i = listIteratorBegin(&b);
    listIteratorNext(&i);
    printf("\tSet 99 in 2\n");
    listIteratorSet(&i, 99);
    printList(&b);
    printf("\tSwap k-1 and k+1. k = 2\n");
    task(&b, 2);
    printList(&b);
    i = listIteratorBegin(&b);
    listIteratorNext(&i);
    printf("\tInsert after 2\n");
    listIteratorAfterInsert(&b, &i, 1);
    printList(&b);
    listIteratorRemove(&b, &i);
    printList(&b);
    printf("Head  = %d\n", listFront(&b));
    printf("Tail = %d\n", listBack(&b));
    printList(&b);
    printf("\tSwap k-1 and k+1. k = 3\n");
    task(&b, 3);
    printList(&b);
    listDestroy(&b);
}
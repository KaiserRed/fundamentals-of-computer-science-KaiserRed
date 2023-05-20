#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "types.h"
#include "list.h"

void listCreate(List * const list) {
    *list = (List) { .head = NULL, .tail = NULL, .size = 0 };
}

int listFront(const List * const list) {
    if (list->size == 0)
        return EINVAL;
    return list->head->data;
}

int listBack(const List * const list) {
    if (list->size == 0)
        return EINVAL;
    return list->tail->data;
}

void listDestroy(List * const list) {
    while (listSize(list) != 0){
        listPopFront(list);
    }
} 

int listPushBack(List * const list, const dbl value) {
    ListNode *node = malloc(sizeof(ListNode));
    if (node == NULL)
        return errno;
    *node = (ListNode) {.next = NULL, .data = value };
    if (list->size == 0)
        list->head = list->tail = node;
    else
        list->tail = list->tail->next = node;
    ++list->size;
    return 0;
}

int listPushFront(List * const list, const dbl value) {
    ListNode *node = malloc(sizeof(ListNode));
    if (node == NULL)
        return errno;
    *node = (ListNode) {.next = list->head, .data = value };
    if (list->size == 0)
        list->head = list->tail = node;
    else
        list->head = node;
    ++list->size;
    return 0;
}

int listPopFront(List * const list) {
    if (list->size == 0)
        return EINVAL;    
    ListNode * const node = list->head;
    list->head = list->head->next;
    free(node);
    if (list->head == NULL)
        list->tail = NULL;
    --list->size;
    return 0;
}

size_t listSize(const List * const list) {
    return list->size;
}

ListIterator listIteratorBegin(List *list) {
    return (ListIterator) { .node = list->head};
}

ListIterator listIteratorEnd(List *list) {
    return (ListIterator) { .node = list->tail};
}

int listIteratorAfterInsert(List *list, ListIterator *i, dbl value) {
    ListNode *temp = malloc(sizeof(ListNode));
    if (temp == NULL)
        return errno;
    temp->data = value;
    temp->next = i->node->next;
    i->node->next = temp;
    ++list->size;
    return 0;
}

int listIteratorRemove(List *list, ListIterator *i) {
    ListNode *temp = i->node->next;
    i->node->next = temp->next;
    free(temp);
    --list->size;
    return 0;
}

ListIterator *listIteratorNext(ListIterator* i) {    
    i->node = i->node->next;
    return i;
}


int listIteratorGet(const ListIterator* i) {
    return i->node->data;
}

void listIteratorSet(const ListIterator* i, dbl value) {
    i->node->data = value;
}

bool listIsEmpty(const List * const list) {
    return list->size == 0;
}

bool listIteratorEqual(const ListIterator* lhs, const ListIterator* rhs){
    return lhs->node == rhs->node;
}

bool listIteratorNotEqual(const ListIterator* lhs, const ListIterator* rhs){
    return lhs->node != rhs->node;
}

void printList(List *list){
    for (ListIterator i = listIteratorBegin(list), end = listIteratorEnd(list); listIteratorNotEqual(&i,&end); listIteratorNext(&i))
        printf("%d\t",listIteratorGet(&i));
    ListIterator i = listIteratorEnd(list);
    printf("%d\n",listIteratorGet(&i));

}

void task(List *list, int k){
    int t = 0;
    ListIterator i;
    int left = 0, right = 0;
    for (i = listIteratorBegin(list); t != k+1 ; listIteratorNext(&i)){
        ++t;
        if (t == k - 1)
            left = listIteratorGet(&i);
        if (t == k + 1){
            right = listIteratorGet(&i);
            listIteratorSet(&i, left);
        }
    }
    t = 0;
    for (i = listIteratorBegin(list); t != k ; listIteratorNext(&i)){
        ++t;
        if (t == k - 1){
            listIteratorSet(&i, right);       
        }
    }
    left = right = 0;

}


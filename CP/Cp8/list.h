#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

#include "types.h"


typedef struct ListNode {
    struct ListNode *next;
    dbl data;
} ListNode;

typedef struct {
    ListNode *head, *tail;
    size_t size;
} List;

typedef struct {
    ListNode *node;
} ListIterator;

void listCreate(List *list);

int listFront(const List * const list);

int listBack(const List * const list);

void listClear(List *list);

bool listIsEmpty(const List *list);

ListIterator listIteratorBegin(List *list);

ListIterator listIteratorEnd(List *list);

int listIteratorAfterInsert(List *list, ListIterator *i, dbl value);

int listIteratorRemove(List *list, ListIterator *i);

ListIterator *listIteratorNext(ListIterator* i);

int listIteratorGet(const ListIterator* i);

void listIteratorSet(const ListIterator* i, dbl value);

bool listIteratorEqual(const ListIterator* lhs, const ListIterator* rhs);

bool listIteratorNotEqual(const ListIterator* lhs, const ListIterator* rhs);

int listPopFront(List *list);

int listPushBack(List *list, dbl value);

int listPushFront(List *list, dbl value);

size_t listSize(const List *list);

void listDestroy(List *list);

void printList(List *list);

bool task(List *list, int k);

#endif // LIST_H
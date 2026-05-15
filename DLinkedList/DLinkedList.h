#include <stdio.h>
#include <stdlib.h>

typedef struct pointType { 
    int data;
    struct pointType* prev;
    struct pointType* next;
} PointType;

typedef struct dLinkedList {
    PointType head;
    int size;
} DLinkedList;

extern DLinkedList* createDLinkedList();
extern void destroyDLinkedList(DLinkedList* dl);
extern int insertFirstDLinkedList(DLinkedList* dl, int data);
extern int insertLastDLinkedList(DLinkedList* dl, int data);
extern int insertAtDLinkedList(DLinkedList* dl, int at, int data);
extern int deleteAtDLinkedList(DLinkedList* dl, int at);
extern void printDLinkedList(DLinkedList* dl);
extern int sizeDLinkedList(DLinkedList* dl);
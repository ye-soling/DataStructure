#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
    int data;
    struct pointType* next;
} PointType;

typedef struct linkedList {
    struct pointType* head;
    int size;
} LinkedList;

extern LinkedList* createLinkedList();
extern int destroyLinkedList(LinkedList* li);
extern int isEmptyLinkedList(LinkedList* li);
extern int sizeLinkedList(LinkedList* li);
extern LinkedList* insertFirstLinkedList(LinkedList* li, int data);
extern LinkedList* insertLastLinkedList(LinkedList* li, int data);
extern LinkedList* insertAtLinkedList(LinkedList* li, int at, int data);
extern int deleteAtLinkedList(LinkedList* li, int at);
extern void printLinkedList(LinkedList* li);
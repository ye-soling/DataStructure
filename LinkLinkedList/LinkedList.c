#include "LinkedList.h"

LinkedList* createLinkedList() {
    struct linkedList* r;
    r = (struct linkedList*)malloc(sizeof(struct linkedList));

    r->head = (struct pointType*)NULL;
    r->size = 0;

    return r;
}

int destroyLinkedList(LinkedList* li) {
    struct pointType* nptr, *mptr;
    for (nptr = li->head; nptr != NULL; nptr = mptr) {
        mptr = nptr->next;
        free(nptr);
    }

    free(li);

    return 1;
}

int isEmptyLinkedList(LinkedList* li) {
    return (li->size == 0);
}

LinkedList* insertFirstLinkedList(LinkedList* li, int data) {
    PointType* ptr = (PointType*)malloc(sizeof(PointType));
    ptr->data = data;

    ptr->next = li->head;
    li->head = ptr;
    li->size++;   // 리스트 크기 증가
 
    return li;
}

LinkedList* insertLastLinkedList(LinkedList* li, int data) {
    PointType* nPtr = (PointType*)malloc(sizeof(PointType));

    nPtr->data = data;
    nPtr->next = NULL;

    if (li->head == NULL) {
        li->head = nPtr;
    }
    else {
        PointType* ptr = li->head;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = nPtr;
    }

    li->size++;

    return li;
}

// 특정 위치에 추가 
LinkedList* insertAtLinkedList(LinkedList* li, int at, int data) {
    if (at < 0 || at > li->size) {

        printf("추가할 위치가 올바르지 않습니다.\n");

        return li;
    }

    // 맨 앞에 추가
    if (at == 0) {

        return insertFirstLinkedList(li, data);
    }

    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    nPtr->data = data;

    PointType* ptr = li->head;

    // 추가할 위치 이전 위치까지 이동
    for (int i = 0; i < at - 1; i++) {

        ptr = ptr->next;
    }

    nPtr->next = ptr->next;
    ptr->next = nPtr;

    li->size++;

    return li;
}

// 특정 위치 삭제
int deleteAtLinkedList(LinkedList* li, int at) {

    if (at < 0 || at >= li->size) {
        printf("삭제할 위치가 올바르지 않습니다.\n");

        return -1;
    }

    PointType* dPtr;

    int deletedData;

    if (at == 0) {
        dPtr = li->head;
        li->head = dPtr->next;
    }
    else {
        PointType* ptr = li->head;

        for (int i = 0; i < at - 1; i++) {

            ptr = ptr->next;
        }
        dPtr = ptr->next;
        ptr->next = dPtr->next;
    }

    deletedData = dPtr->data;

    free(dPtr);

    li->size--;  // 리스트 크기 감소

    return deletedData;
}

void printLinkedList(LinkedList* li) {
    PointType* current = li->head;

    printf("\n전체 리스트 목록\n");

    if (current == NULL) {

        printf("리스트가 비어있습니다.\n");

        return;
    }

    while (current != NULL) {

        printf("%d ", current->data);

        current = current->next;
    }

    printf("\n");
}

int sizeLinkedList(LinkedList* li) {
    return li->size;
}
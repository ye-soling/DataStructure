#include "DLinkedList.h"

DLinkedList* createDLinkedList() {
    DLinkedList* temp = (DLinkedList*)malloc(sizeof(DLinkedList));
    temp->head.next = &(temp->head);
    temp->head.prev = &(temp->head);
    temp->size = 0;

    return temp;
}

void destroyDLinkedList(DLinkedList* dl) {
    while (dl->size != 0) {
        deleteAtDLinkedList(dl, 0);
    }

    free(dl);
}

int insertFirstDLinkedList(DLinkedList* dl, int data) {
    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    nPtr->data = data;

    nPtr->prev = &(dl->head);
    nPtr->next = dl->head.next;
    dl->head.next->prev = nPtr;
    dl->head.next = nPtr;

    dl->size++;   // 리스트 크기 증가

    return 1;
}

int insertLastDLinkedList(DLinkedList* dl, int data) {
    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    nPtr->data = data;

    nPtr->next = &(dl->head);
    nPtr->prev = dl->head.prev;
    dl->head.prev->next = nPtr;
    dl->head.prev = nPtr;

    dl->size++;

    return 1;
}

// 특정 위치에 추가
int insertAtDLinkedList(DLinkedList* dl, int at, int data) {
    if (at < 0 || at > dl->size) {
        return 0;
    }

    // 맨 앞에 추가
    if (at == 0) {
        return insertFirstDLinkedList(dl, data);
    }

    // 맨 뒤에 추가
    if (at == dl->size) {
        return insertLastDLinkedList(dl, data);
    }

    PointType* nPtr = (PointType*)malloc(sizeof(PointType));
    PointType* current = dl->head.next;
    nPtr->data = data;

    // 추가할 위치까지 이동
    for (int i = 0; i < at; i++) {
        current = current->next;
    }

    nPtr->prev = current->prev;
    nPtr->next = current;
    current->prev->next = nPtr;
    current->prev = nPtr;

    dl->size++;

    return 1;
}

int deleteAtDLinkedList(DLinkedList* dl, int at) {

    if (dl->size == 0) {
        printf("리스트가 비어있습니다.\n");
        return -1;
    }

    if (at < 0 || at >= dl->size) {
        printf("잘못된 위치입니다.\n");
        return -1;
    }

    PointType* current = dl->head.next;

    // 삭제할 위치까지 이동
    for (int i = 0; i < at; i++) {
        current = current->next;
    }

    int deletedData = current->data;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);

    dl->size--;   // 리스트 크기 감소

    return deletedData;
}

void printDLinkedList(DLinkedList* dl) {

    PointType* current = dl->head.next;

    printf("\n전체 리스트 목록\n");

    if (dl->size == 0) {

        printf("리스트가 비어있습니다.\n");

        return;
    }

    while (current != &(dl->head)) {

        printf("%d ", current->data);

        current = current->next;
    }

    printf("\n");
}

int sizeDLinkedList(DLinkedList* li) {
    return li->size;
}
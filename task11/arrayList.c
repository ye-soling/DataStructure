#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

arrayList* createArrayList(int size) {
    arrayList* al = (arrayList*)malloc(sizeof(arrayList));
    al->data = (elementArrayList*)malloc(sizeof(elementArrayList) * size);
    al->size = 0;
    al->capacity = size;
    return al;
}

void destroyArrayList(arrayList* al) {
    free(al->data);
    free(al);
}

int isEmptyArrayList(arrayList* al) {
    return (al->size == 0);
}

int isFullArrayList(arrayList* al) {
    return (al->size == al->capacity);
}

int sizeArrayList(arrayList* al) {
    return al->size;
}

// insert (🔥 수정됨)
int insertArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos > al->size) return 0;

    // 공간 부족 시 확장
    if (isFullArrayList(al)) {
        al->capacity *= 2;
        al->data = (elementArrayList*)realloc(
            al->data,
            sizeof(elementArrayList) * al->capacity
        );
    }

    // 뒤로 밀기
    for (int i = al->size; i > pos; i--) {
        al->data[i] = al->data[i - 1];
    }

    al->data[pos] = item;
    al->size++;

    return 1;
}

// delete
elementArrayList deleteArrayList(arrayList* al, int pos) {
    elementArrayList fail = {0, 0};

    if (pos < 0 || pos >= al->size) {
        return fail;
    }

    elementArrayList item = al->data[pos];

    for (int i = pos; i < al->size - 1; i++) {
        al->data[i] = al->data[i + 1];
    }

    al->size--;

    return item;
}

// clear
int initArrayList(arrayList* al) {
    al->size = 0;
    return 1;
}


int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
    if (pos < 0 || pos >= al->size) return 0;

    al->data[pos] = item;
    return 1;
}
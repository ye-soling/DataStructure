#include <stdio.h>

#include "arrayList.h"

// 전치 행렬 함수
void transpose(arrayList* origin, arrayList** result, int* moveCount) {
    *result = createArrayList(origin->capacity);
    *moveCount = 0;

    for (int i = 0; i < origin->size; i++) {
        elementArrayList item = origin->data[i];

        elementArrayList newItem;
        newItem.row = item.col;
        newItem.col = item.row;
        newItem.value = item.value;

        insertArrayList(*result, (*result)->size, newItem);
        (*moveCount)++;
    }
}

int main() {
    arrayList* matrix = createArrayList(20);
    elementArrayList item;

    // 희소행렬 초기화 (0이 아닌 값 20개) 
    int values[20][3] = {
        {0,1,4}, {1,3,8}, {2,9,3}, {3,0,7}, {4,5,9},
        {5,4,11}, {6,1,2}, {7,8,4}, {8,9,1}, {9,1,10},
        {0,3,11}, {1,1,12}, {2,5,17}, {3,4,14}, {4,0,15},
        {5,3,16}, {6,7,17}, {7,2,28}, {8,6,19}, {9,6,20}
    };

    for (int i = 0; i < 20; i++) {
        item.row = values[i][0];
        item.col = values[i][1];
        item.value = values[i][2];

        insertArrayList(matrix, matrix->size, item);
    }

    // 희소 행렬 출력
    printf("희소 행렬:\n");
    for (int i = 0; i < matrix->size; i++) {
        printf("(%d, %d, %d)\t",
               matrix->data[i].row,
               matrix->data[i].col,
               matrix->data[i].value);

        if ((i + 1) % 4 == 0) printf("\n");
    }

    int moveCount = 0;
    arrayList* trans = NULL;
    transpose(matrix, &trans, &moveCount);

    // 전치 행렬 출력 
    printf("\n전치 행렬:\n");
    for (int i = 0; i < trans->size; i++) {
        printf("(%d, %d, %d)\t",
               trans->data[i].row,
               trans->data[i].col,
               trans->data[i].value);

        if ((i + 1) % 4 == 0) printf("\n");
    }

    // 데이터 이동 횟수 출력 
    printf("\n데이터 이동 횟수: %d\n", moveCount);

    destroyArrayList(matrix);
    destroyArrayList(trans);

    return 0;
}
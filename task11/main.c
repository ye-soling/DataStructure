#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayList.h"

// 다항식 항 추가 (같은 지수가 이미 존재하면 계수를 합산 / 없으면 리스트 끝에 새 항 삽입)
// coef, expo 형태의 항을 리스트에 저장
void addTerm(arrayList* list, int coef, int expo) {
    for (int i = 0; i < sizeArrayList(list); i++) {
        if (list->data[i].expo == expo) {
            list->data[i].coef += coef;
            return;
        }
    }

    elementArrayList item = {coef, expo};
    insertArrayList(list, sizeArrayList(list), item);
}

// 문자열 파싱 (ex: 3X^2+2X^1+1X^0 -> 3x²+2x+1) : 더하기 연산자 기준으로 분리 
void parsePolynomial(char* str, arrayList* list) {
    char* token = strtok(str, "+");

    while (token != NULL) {
        int coef, expo;
        sscanf(token, "%dX^%d", &coef, &expo);
        addTerm(list, coef, expo);
        token = strtok(NULL, "+");
    }
}

// 다항식 곱셈 (계수: 곱셈, 지수: 덧셈)
void multiply(arrayList* A, arrayList* B, arrayList* result) {
    for (int i = 0; i < sizeArrayList(A); i++) {
        for (int j = 0; j < sizeArrayList(B); j++) {
            int coef = A->data[i].coef * B->data[j].coef;
            int expo = A->data[i].expo + B->data[j].expo;
            addTerm(result, coef, expo);
        }
    }
}

// 출력 (리스트에 저장된 모든 항)
void printPolynomial(arrayList* list) {
    for (int i = 0; i < sizeArrayList(list); i++) {
        printf("%dX^%d", list->data[i].coef, list->data[i].expo);
        if (i != sizeArrayList(list) - 1) printf("+");
    }
    printf("\n");
}

int main() {
    arrayList* A = createArrayList(10);
    arrayList* B = createArrayList(10);
    arrayList* result = createArrayList(10);

    char poly1[100], poly2[100];

    printf("1번째 다항식: ");
    scanf("%s", poly1);

    printf("2번째 다항식: ");
    scanf("%s", poly2);

    parsePolynomial(poly1, A);
    parsePolynomial(poly2, B);

    multiply(A, B, result);

    printf("곱셈 결과: ");
    printPolynomial(result);

    destroyArrayList(A);
    destroyArrayList(B);
    destroyArrayList(result);

    return 0;
}
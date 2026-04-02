#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 50

int main() {
    int arr[n];

    srand(time(NULL));

    // 배열 채우기 (1 ~ n 사이 값)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }

    // 처음 -> 끝 출력
    printf("처음 -> 끝 :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 끝 -> 처음 출력
    printf("\n끝 -> 처음:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 총합, 최대값, 최소값
    int sum = 0;
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }

    printf("\n총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    return 0;
}
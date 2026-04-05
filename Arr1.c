#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;

    printf("정수 N을 입력하세요: ");
    scanf("%d", &n);

    // 배열 생성
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    // 배열 채우기 (0 ~ n 사이 값)
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % (n + 1);
    }

    // 처음 -> 끝 출력
    printf("처음 -> 끝 :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 끝 -> 처음 출력
    printf("\n끝 -> 처음:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // 총합, 최대값, 최소값
    int sum = 0;
    int max = *(arr);
    int min = *(arr);

    for (int i = 0; i < n; i++) {
        int val = *(arr + i);
        sum += val;
        if (val > max) max = val;
        if (val < min) min = val;
    }

    printf("\n총합: %d\n", sum);
    printf("최대값: %d\n", max);
    printf("최소값: %d\n", min);

    free(arr);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("홀수 n을 입력하세요: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
    printf("홀수만 입력하세요.\n");
    return 1;
    }

    // 동적 2차원 배열 생성 (1차원으로 할당)
    int *arr = (int *)malloc(n * n * sizeof(int));

    // 배열 0으로 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(arr + i * n + j) = 0;
        }
    }

    int num = 1;
    int i = 0;
    int j = n / 2;

    // 마방진 채우기
    while (num <= n * n) {
        *(arr + i * n + j) = num;

        int next_i = (i - 1 + n) % n;
        int next_j = (j + 1) % n;

        if (*(arr + next_i * n + next_j) != 0) {
            i = (i + 1) % n;
        } else {
            i = next_i;
            j = next_j;
        }
        num++;
    }

    // 배열 출력
    printf("\n[마방진]\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d", *(arr + i * n + j));
        }
        printf("\n");
    }

    // 가로 합
    printf("\n[가로 합]\n");
    for (i = 0; i < n; i++) {
        int sum = 0;
        for (j = 0; j < n; j++) {
            sum += *(arr + i * n + j);
        }
        printf("%d 행: %d\n", i + 1, sum);
    }

    // 세로 합
    printf("\n[세로 합]\n");
    for (j = 0; j < n; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += *(arr + i * n + j);
        }
        printf("%d 열: %d\n", j + 1, sum);
    }

    // 대각선 합
    int d1 = 0, d2 = 0;
    for (i = 0; i < n; i++) {
        d1 += *(arr + i * n + i);
        d2 += *(arr + i * n + (n - 1 - i));
    }

    printf("\n[대각선 합]\n");
    printf("왼 위 -> 오 아래 대각선: %d\n", d1);
    printf("오 위 -> 왼 아래 대각선: %d\n", d2);

    free(arr);

    return 0;
}
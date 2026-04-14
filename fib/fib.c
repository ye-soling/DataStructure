#include <stdio.h>
#include <time.h>

// 순환적 피보나치
long long fibonacci_iter(int n) {
    if (n == 1 || n == 2) return 1;
    long long f1 = 1, f2 = 1, f3;
    for (int i = 3; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f2;
}

// 재귀적 피보나치
long long fibonacci_rec(int n) {
    if (n == 1 || n == 2) return 1;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main() {
    int N;
    printf("정수(N)을 입력하세요: ");
    scanf("%d", &N);

    printf("N | fib_순환| fib_재귀| 순환_수행| 재귀_수행\n");

    for (int i = 1; i <= N; i++) {

        // 순환
        clock_t start_iter = clock();
        long long fib_iter = fibonacci_iter(i);
        clock_t end_iter = clock();
        double time_iter = (double)(end_iter - start_iter) / CLOCKS_PER_SEC;

        // 재귀
        clock_t start_rec = clock();
        long long fib_rec = fibonacci_rec(i);
        clock_t end_rec = clock();
        double time_rec = (double)(end_rec - start_rec) / CLOCKS_PER_SEC;

        printf("%d |    %lld    |    %lld    | %.6f | %.6f\n", i, fib_iter, fib_rec, time_iter, time_rec);
    } 

    return 0;
}
#include <stdio.h>
#include <time.h>

// GCD 함수
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    for (int n = 5; n <= 40; n++) {
        int fn = fib(n);
        int fn1 = fib(n - 1);

        clock_t start = clock();

        // 반복해서 실행 시간 늘리기 (핵심 ⭐)
        for (int i = 0; i < 10000; i++) {
            gcd(fn, fn1);
        }

        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d %f\n", n, time_taken);
    }
    return 0;
}

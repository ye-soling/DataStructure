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

// 반복 피보나치 
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

// 재귀 피보나치 
int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
    for (int n = 5; n <= 40; n++) {

        int fn = fib_recursive(n);
        int fn1 = fib_recursive(n - 1);

        // GCD 시간 측정
        clock_t start1 = clock();

        for (int i = 0; i < 10000; i++) {
            gcd(fn, fn1);
        }

        clock_t end1 = clock();
        double gcd_time = (double)(end1 - start1) / CLOCKS_PER_SEC;

        // Fibonacci (재귀) 시간 측정
        clock_t start2 = clock();

        fib_recursive(n);

        clock_t end2 = clock();
        double fib_time = (double)(end2 - start2) / CLOCKS_PER_SEC;

        printf(" n = %d |  GCD: %f  |  Fib(rec): %f\n", n, gcd_time, fib_time);
    } 

    return 0;
}
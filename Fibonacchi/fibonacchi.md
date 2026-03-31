# 피보나치 기반 GCD 복잡도 분석

## 1
피보나치 수열 F(n)에 대해 GCD(F(n), F(n-1))을 계산하며 실행 시간을 측정하고
유클리드 호제법의 시간 복잡도 O(log n)를 검증한다.
또한 재귀 방식의 피보나치 수열 실행 시간을 함께 측정하여 O(2ⁿ) 시간복잡도를 비교 및 검증한다.

---

## 2
- n을 5부터 증가시키며 반복 수행
- 각 n에 대해 F(n), F(n-1)을 계산
- GCD(F(n), F(n-1)) 수행 시간 측정
- time.h의 clock() 함수를 이용하여 CPU 실행 시간을 측정

---

## 3. 실행 코드

```
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

        int fn = fib(n);
        int fn1 = fib(n - 1);

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
```

## 4. 실행 결과 

```
 n = 5  |  GCD: 0.000510  |  Fib(rec): 0.000001
 n = 6  |  GCD: 0.000546  |  Fib(rec): 0.000001
 n = 7  |  GCD: 0.000660  |  Fib(rec): 0.000002
 n = 8  |  GCD: 0.000786  |  Fib(rec): 0.000000
 n = 9  |  GCD: 0.000769  |  Fib(rec): 0.000000
 n = 10 |  GCD: 0.000877  |  Fib(rec): 0.000003
 n = 11 |  GCD: 0.000967  |  Fib(rec): 0.000003
 n = 12 |  GCD: 0.001121  |  Fib(rec): 0.000004
 n = 13 |  GCD: 0.000934  |  Fib(rec): 0.000006
 n = 14 |  GCD: 0.001129  |  Fib(rec): 0.000007
 n = 15 |  GCD: 0.001261  |  Fib(rec): 0.000010
 n = 16 |  GCD: 0.001433  |  Fib(rec): 0.000016
 n = 17 |  GCD: 0.001540  |  Fib(rec): 0.000028
 n = 18 |  GCD: 0.001831  |  Fib(rec): 0.000042
 n = 19 |  GCD: 0.001823  |  Fib(rec): 0.000057
 n = 20 |  GCD: 0.001695  |  Fib(rec): 0.000100
 n = 21 |  GCD: 0.001738  |  Fib(rec): 0.000146
 n = 22 |  GCD: 0.001938  |  Fib(rec): 0.000236
 n = 23 |  GCD: 0.002106  |  Fib(rec): 0.000381
 n = 24 |  GCD: 0.002248  |  Fib(rec): 0.000600
 n = 25 |  GCD: 0.001924  |  Fib(rec): 0.000883
 n = 26 |  GCD: 0.002102  |  Fib(rec): 0.001409
 n = 27 |  GCD: 0.002237  |  Fib(rec): 0.002124
 n = 28 |  GCD: 0.002051  |  Fib(rec): 0.003165
 n = 29 |  GCD: 0.002068  |  Fib(rec): 0.004689
 n = 30 |  GCD: 0.001983  |  Fib(rec): 0.007026
 n = 31 |  GCD: 0.001865  |  Fib(rec): 0.010001
 n = 32 |  GCD: 0.001751  |  Fib(rec): 0.013971
 n = 33 |  GCD: 0.001531  |  Fib(rec): 0.020114
 n = 34 |  GCD: 0.001611  |  Fib(rec): 0.031142
 n = 35 |  GCD: 0.001508  |  Fib(rec): 0.049761
 n = 36 |  GCD: 0.001572  |  Fib(rec): 0.080532
 n = 37 |  GCD: 0.001706  |  Fib(rec): 0.130042
 n = 38 |  GCD: 0.001647  |  Fib(rec): 0.210248
 n = 39 |  GCD: 0.001859  |  Fib(rec): 0.339015
 n = 40 |  GCD: 0.001756  |  Fib(rec): 0.548607
```

## 5. 그래프 이미지
<img src="graph.png" width="600">


이 그래프는 n에 따른 GCD와 재귀 피보나치 함수의 실행 시간을 나타낸 것이다.

(구글 스프레드 시트에서 그래프 제작)
로그 스케일을 적용한 결과, 재귀 피보나치 함수의 실행 시간은 직선 형태로 증가하는 것을 확인할 수 있다.
피보나치 수열이 지수적 증가(O(2ⁿ))를 따르기 때문이다.

반면, GCD 알고리즘은 완만한 증가를 보이며, 이는 시간복잡도가 O(log n)임을 나타낸다.

따라서 그래프를 통해 두 알고리즘의 시간복잡도 차이를 확인할 수 있다.

---

## 6-1. 결과 분석
n이 증가함에 따라 실행 시간이 전반적으로 증가한다.  
전체적으로 완만한 증가 형태를 보이며, 이는 유클리드 호제법의 시간 복잡도가 O(log n)임을 확인할 수 있다.  

또한, 재귀 방식의 피보나치 수열의 실행 시간은 n이 증가함에 따라 급격히 증가하는 것을 확인할 수 있다.  
특히 n이 증가할수록 실행 시간이 급격히 증가하는 경향을 확인할 수 있다.  
이는 동일한 계산이 반복되는 구조로 인해 시간복잡도가 O(2ⁿ)에 가까운 지수적 증가를 보이기 때문이다.

## 6-2. Big-O 검증
본 실행 결과를 통해 GCD 알고리즘은 O(log n)의 시간복잡도를 가지며, 
재귀 피보나치 함수는 O(2ⁿ)의 시간복잡도를 가지는 것을 확인할 수 있다.

따라서 이론적으로 분석한 시간복잡도가 실제 실행 시간 증가 패턴과 일치함을 검증할 수 있다.
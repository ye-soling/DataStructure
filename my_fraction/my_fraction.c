#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_fraction.h"

// 최대공약수
static int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return abs(a);
}

// 기약분수
Fraction reduce(Fraction f) {
    int g = gcd(f.numerator, f.denominator);

    f.numerator /= g;
    f.denominator /= g;

    // 분모는 항상 양수
    if (f.denominator < 0) {
        f.numerator *= -1;
        f.denominator *= -1;
    }

    return f;
}

// 문자열 → 분수 (분수 / 정수 / 소수 모두 지원)
Fraction parseFraction(const char* str) {
    Fraction f;

    // 분수 형태 
    if (strchr(str, '/')) {
        sscanf(str, "%d/%d", &f.numerator, &f.denominator);
    }

    // 소수 형태
    else if (strchr(str, '.')) {
        double value = atof(str);

        int denom = 1000000; // 정밀도 (1e6)
        int numer = (int)(value * denom);

        f.numerator = numer;
        f.denominator = denom;
    }

    // 정수 형태
    else {
        f.numerator = atoi(str);
        f.denominator = 1;
    }

    return reduce(f); // 기약분수 변환
}

// 출력
void printFraction(Fraction f) {
    f = reduce(f);

    if (f.denominator == 1) {
        printf("%d\n", f.numerator);    //분모가 1이면 정수로 출력
    } else {
        printf("%d/%d\n", f.numerator, f.denominator);
    }
}

// 덧셈
Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return reduce(result);
}

// 뺄셈
Fraction sub(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    return reduce(result);
}

// 곱셈
Fraction multiple(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    return reduce(result);
}

// 나눗셈
Fraction divide(Fraction a, Fraction b) {
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    return reduce(result);
}
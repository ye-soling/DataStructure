#ifndef MY_FRACTION_H
#define MY_FRACTION_H

typedef struct {
    int numerator;
    int denominator;
} Fraction;

// 생성 및 변환
Fraction parseFraction(const char* str);
void printFraction(Fraction f);

// 연산
Fraction add(Fraction a, Fraction b);
Fraction sub(Fraction a, Fraction b);
Fraction multiple(Fraction a, Fraction b);
Fraction divide(Fraction a, Fraction b);

// 기약분수
Fraction reduce(Fraction f);

#endif
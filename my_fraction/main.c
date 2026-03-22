#include <stdio.h>
#include "my_fraction.h"

int main() {
    char f1_str[20], f2_str[20];
    char op;

    printf("입력 "); 
    scanf("%s %c %s", f1_str, &op, f2_str);

    Fraction f1 = parseFraction(f1_str);
    Fraction f2 = parseFraction(f2_str);
    Fraction result;

    if (op == '+') {
        result = add(f1, f2);
    }
    else if (op == '-') {
        result = sub(f1, f2);
    }
    else if (op == '*') {
        result = multiply(f1, f2);
    }
    else if (op == '/') {
        result = divide(f1, f2);
    }

    printFraction(result);
    printf("\n");

    return 0;
}
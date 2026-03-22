#include "my_math.h"

int gcd(int a, int b) {
    int temp;

    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
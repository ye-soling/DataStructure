#include <stdio.h>
#include "my_math.h"

int main() {
    int a, b;
    printf("입력 "); 
    scanf("%d %d", &a, &b);

    printf("GCD: %d, LCM: %d\n", gcd(a, b), lcm(a, b));

    return 0;
}
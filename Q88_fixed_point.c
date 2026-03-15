#include <stdio.h>

int main() {
    double input;
    short fixed;

    printf("입력값: ");
    scanf("%lf", &input);
    fixed = (short)(input * 256);

    for(int i = 15; i >= 0; i--) {
        printf("%d", (fixed >> i) & 1);

        if(i == 8) printf(".");
    }

    printf("\n");

    return 0;
}
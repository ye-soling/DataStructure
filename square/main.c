#include <stdio.h>
#include "../my_fraction/my_fraction.h"
#include "../my_math/my_math.h"

int main(int c, char** v) {
    // 인자 개수 체크
    if (c != 3) {
        printf("Usage: %s <width> <height>\n", v[0]);
        return 1;
    }

    // 입력 문자열을 Fraction으로 변환
    Fraction width = parseFraction(v[1]);   
    Fraction height = parseFraction(v[2]);  

    // 둘레: 2 * (width + height)
    Fraction perimeter = multiply((Fraction){2, 1}, add(width, height));
    perimeter = reduce(perimeter);

    // 넓이: width * height
    Fraction area = multiply(width, height);
    area = reduce(area);

    // 결과
    printf("Perimeter: ");
    printFraction(perimeter);
    printf(", Area: ");
    printFraction(area);
    printf("\n");
    
    return 0;
}
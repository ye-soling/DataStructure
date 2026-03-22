#include <stdio.h>
#include "../my_fraction/my_fraction.h"
#include "../my_math/my_math.h"

int main(int c, char** v) {
    // 인자 개수 체크 (프로그램 이름 + 가로 + 세로)
    if (c != 3) {
        printf("Usage: %s <width> <height>\n", v[0]);
        return 1;
    }

    // 입력 문자열을 Fraction으로 변환
    Fraction width = parseFraction(v[1]);   // "3/7" -> Fraction
    Fraction height = parseFraction(v[2]);  // "4/9" -> Fraction

    // 둘레 계산: 2 * (width + height)
    Fraction perimeter = multiple((Fraction){2, 1}, add(width, height));
    perimeter = reduce(perimeter);

    // 넓이 계산: width * height
    Fraction area = multiple(width, height);
    area = reduce(area);

    // 결과 출력
    printf("Perimeter: ");
    printFraction(perimeter);
    printf(", Area: ");
    printFraction(area);
    printf("\n");

    return 0;
}
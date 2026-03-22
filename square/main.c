#include <stdio.h>
#include <stdlib.h>
#include "my_fraction.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: %s 3/7 4/9\n", argv[0]);
        return 1;
    }

    Fraction width = parseFraction(argv[1]);
    Fraction height = parseFraction(argv[2]);

    Fraction sum = add(width, height);
    Fraction two = {2, 1};
    Fraction perimeter = multiple(sum, two);

    Fraction area = multiple(width, height);

    printf("Perimeter: %d/%d, Area: %d/%d\n",
           perimeter.numerator, perimeter.denominator,
           area.numerator, area.denominator);

    return 0;
}
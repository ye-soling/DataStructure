#include <stdio.h>

int main()
{
    float input;
    printf("입력: ");
    scanf("%f", &input);

    unsigned int value = *(unsigned int*)&input;

    printf("출력: ");

    //부호
    printf("%d/", (value >> 31) & 1);

    //지수 8비트
    for (int i = 30; i >= 23; i--)
    {
        printf("%d", (value >> i) & 1);

        if (i == 27) printf(" ");
    }

    printf("/");

    //가수 23비트
    int count = 0;

    for (int i = 22; i >= 0; i--)
    {
        printf("%d", (value >> i) & 1);

        count++;

        if (count == 4 && i != 0)
        {
            printf(" ");
            count = 0;
        }
    }

    printf("\n");

    return 0;
}
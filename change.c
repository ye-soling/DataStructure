#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char str[200];

    printf("입력: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    printf("출력: %s", str);

    return 0;
}
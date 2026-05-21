#include <stdio.h>
#include <stdlib.h>

#include "LinkedStack.h"

int main() {

    LinkedStack* browser = createLinkedStack();

    int menu; 
    char url[100];  // URL 입력 저장 배열

    while (1) {

        printf("\n스택 메뉴\n");

        printf("1. URL 추가\n");
        printf("2. URL 제거\n");
        printf("3. 스택 확인\n");

        printf("메뉴를 선택하세요: ");
        scanf("%d", &menu);

        switch (menu) {

        // URL 추가
        case 1:

            printf("URL 입력: ");
            scanf("%s", url);

            pushLinkedStack(browser, url);   // 스택에 URL 추가

            printf("현재 창: %s\n",
                peekLinkedStack(browser));

            break;

        // URL 제거
        case 2: {

            char* removed = popLinkedStack(browser);   // 스택에 URL 추가

            if (removed == NULL) {
                printf("브라우저가 비어있습니다.\n");
            }

            else {

                printf("이탈: %s\n", removed);

                free(removed);

                if (emptyLinkedStack(browser)) {

                    printf("브라우저가 종료되었습니다.\n");

                    destroyLinkedStack(browser);    // 전체 메모리 해제

                    return 0;
                }

                else {

                    printf("현재 창: %s\n",
                        peekLinkedStack(browser));
                }
            }

            break;
        }

        // 현재 창 확인
        case 3:

            if (emptyLinkedStack(browser)) {
                printf("현재 창이 없습니다.\n");
            }

            else {
                printf("현재 창: %s\n",
                    peekLinkedStack(browser));
            }

            break;

        default:

            printf("잘못된 메뉴 입력입니다.\n");
        }
    }
}
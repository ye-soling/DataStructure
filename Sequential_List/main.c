#include <stdio.h>
#include "arrayList.h"

int main() {
    arrayList* list = createArrayList(100);

    if (sizeArrayList(list) == 0) {
        printf("Create ok\n");
    }

    int menu, pos, value;
    elementArrayList item;

    while (1) {
        printf("\n메뉴 \n");
        printf("1. 추가 (insert)\n");
        printf("2. 삭제 (delete)\n");
        printf("3. 변경 (replace)\n");
        printf("4. 출력 (print)\n");
        printf("5. 모두 삭제 (clear)\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("위치와 값을 입력하세요: ");
            scanf("%d %d", &pos, &value);

            if (value <= 0) {
                printf("양의 정수만 입력하세요.\n");
                break;
            }

            item.value = value;
            item.row = item.col = 0;

            if (insertArrayList(list, pos, item))
                printf("추가 완료\n");
            else
                printf("추가 실패\n");
            break;

        case 2:
            printf("삭제할 위치를 입력하세요: ");
            scanf("%d", &pos);

            if (deleteArrayList(list, pos).value != -1)
                printf("삭제 완료\n");
            else
                printf("삭제 실패\n");
            break;

        case 3:
            printf("위치와 변경할 값을 입력하세요: ");
            scanf("%d %d", &pos, &value);

            if (value <= 0) {
                printf("양의 정수만 입력 가능합니다.\n");
                break;
            }

            item.value = value;
            item.row = item.col = 0;

            if (replaceItemArrayList(list, pos, item))
                printf("변경 완료\n");
            else
                printf("변경 실패\n");
            break;

        case 4:
            printArrayList(list);
            break;

        case 5:
            initArrayList(list);
            printf("리스트 초기화 완료\n");
            break;

        case 0:
            destroyArrayList(list);
            printf("프로그램을 종료합니다.\n");
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}
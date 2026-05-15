#include "LinkedList.h"

int main() {

    LinkedList* list = createLinkedList();

    int menu;   // 메뉴 저장
    int data;
    int index;  // 위치 저장
    int deletedValue;   // 삭제된 정수 저장  

    while (1) {

        printf("\n연결 리스트 메뉴\n");
        printf("1. 맨 앞에 추가\n");
        printf("2. 맨 뒤에 추가\n");
        printf("3. 특정 위치에 추가\n");
        printf("4. 특정 위치 삭제\n");
        printf("5. 전체 목록 출력\n");
        printf("6. 리스트 크기 확인\n");
        printf("0. 종료\n");

        printf("\n메뉴를 선택하세요: ");
        scanf("%d", &menu);

        switch (menu) {

        // 맨 앞에 추가
        case 1:
            printf("맨 앞에 추가할 정수: ");
            scanf("%d", &data);

            insertFirstLinkedList(list, data);

            break;

        // 맨 뒤에 추가 
        case 2:
            printf("맨 뒤에 추가할 정수: ");
            scanf("%d", &data);

            insertLastLinkedList(list, data);

            break;
        
        // 특정 위치에 추가
        case 3:
            printf("추가할 위치: ");
            scanf("%d", &index);

            printf("추가할 정수: ");
            scanf("%d", &data);

            insertAtLinkedList(list, index, data);

            break;

        // 특정 위치 삭제
        case 4:
            printf("삭제할 위치: ");
            scanf("%d", &index);

            deletedValue = deleteAtLinkedList(list, index);

            if (deletedValue != -1) {
                printf("삭제된 수: %d\n", deletedValue);
            }

            break;

        // 전체 리스트 출력
        case 5:
            printLinkedList(list);

            break;

        // 리스트 크기 확인
        case 6:
            printf("리스트 크기: %d\n",
                sizeLinkedList(list));

            break;

        // 프로그램 종료
        case 0:
            destroyLinkedList(list);

            printf("프로그램을 종료합니다.\n");

            return 0;

        default:
            printf("잘못된 메뉴입니다.\n");
        }
    }
}
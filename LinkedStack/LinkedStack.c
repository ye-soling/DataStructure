#include "LinkedStack.h"

LinkedStack* createLinkedStack() {
    LinkedStack* s = (LinkedStack*)malloc(sizeof(LinkedStack));
    s->head = NULL;
    s->size = 0;

    return s;
}

void destroyLinkedStack(LinkedStack* s) {

    while (!emptyLinkedStack(s)) {
        char* temp = popLinkedStack(s);  //pop 데이터 제거
        free(temp);
    }

    free(s);
}

int emptyLinkedStack(LinkedStack* s) {  // 스택이 비어있는지 확인

    return s->size == 0;
}

int fullLinkedStack(LinkedStack* s) {

    return 0;
}

// 스택에 URl 추가
int pushLinkedStack(LinkedStack* s, stackElement item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = (char*)malloc(strlen(item) + 1);
    strcpy(temp->data, item);
    temp->next = s->head;
    s->head = temp;
    s->size++;   // 스택 크기 증가
    return 1;
}

// 스택에서 URL 제거 (pop)
stackElement popLinkedStack(LinkedStack* s) {

    if (emptyLinkedStack(s)) {

        return NULL;
    }

    Node* temp = s->head;  // 제거할 노드 저장
    char* data = temp->data;
    s->head = temp->next;

    free(temp);
    s->size--;   // 스택 크기 감소

    return data;
}

// 현재 브라우저 창 URl 확인
stackElement peekLinkedStack(LinkedStack* s) {

    if (emptyLinkedStack(s)) {

        return NULL;
    }

    return s->head->data;
}

void printLinkedStack(LinkedStack* s) {
    Node* temp = s->head;

    printf("\nstack\n");

    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}
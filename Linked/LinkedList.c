#include "LinkedList.h"

LinkedList* createLinkedList() {
	struct linkedList* r;
	r = (struct linkedList*)malloc(sizeof(struct linkedList));

	r->head = (struct pointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(LinkedList* li) {
	struct pointType* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}

	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	*ptr = item;

	ptr->next = li->head;
	li->head = ptr;
	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	printf("LinkedList:\n");

	for (int i = 0; i < li->size; i++) {
		printf("[%d] x:%d, y:%d, next:%x\n", 
			i, current->x, current->y, current->next);

		current = current->next;
	}
}

LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = li->head;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;
	nPtr->next = NULL;

	ptr->next = nPtr;

	li->size++;

	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;
		
		// 첫번째 위치를 삭제하는 경우
		if (at == 0) {
			PointType* fPtr = li->head;
			li->head = fPtr->next;
			free(fPtr);
		}

		// 중간 또는 마지막 위치를 삭제하는 경우
		else {

			PointType* nPtr = li->head; // 삭제할 위치의 이전 위치를 가리킬 포인터

			// 삭제할 위치의 이전 위치까지 이동
			for (int i = 0; i < at - 1; i++) {
				nPtr = nPtr->next;
			}

			PointType* fPtr = nPtr->next; // 삭제할 위치 저장
			nPtr->next = fPtr->next;
			free(fPtr);
		}
		li->size--; // 연결 리스트 크기 감소 : 노드를 삭제했으므로 연결리스트의 크기도 같이 감소
	}
	return li;  // 수정된 리스트 반환
}

/* 
for문이 먼저 실행되어 nPtr이 삭제할 위치까지 이동함
이 상태에서 nPtr->next를 삭제하기 때문에 실제 삭제할 위치가 아닌 다음 위치가 삭제됨
따라서 삭제할 노드의 이전 위치까지만 이동하도록 수정하여 실제 원하는 위치가 삭제되도록 수정
*/
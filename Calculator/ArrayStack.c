#include "ArrayStack.h"

ArrayStack* createArrayStack(int size, stackType type) {
	ArrayStack* re = (ArrayStack*)malloc(sizeof(ArrayStack));
	re->data = (stackElement*)malloc(sizeof(stackElement) * size);
	re->top = -1;
	re->size = size;
	re->type = type;

	return re;
}

int emptyArrayStack(ArrayStack* s) {
	return s->top == -1;
}

int fullArrayStack(ArrayStack* s) {   
	return s->top == s->size - 1;
}

int pushArrayStack(ArrayStack* s, stackElement item) {
	if (fullArrayStack(s)) {
		return 0;
	}

	s->top++;   // top 증가 

	if (s->type == CHARACTER) {     // 문자형 stack
		s->data[s->top].operator = item.operator;
	}
	else if (s->type == INTEGER) {  // 정수형 stack
		s->data[s->top].value = item.value;
	}

	return 1;
}

stackElement popArrayStack(ArrayStack* s) {
    stackElement temp;

	if (emptyArrayStack(s)) {
		temp.operator = 0;
		return temp;
	}

	temp = s->data[s->top];
	s->top--;   //top 감소

	return temp;
}

stackElement peekArrayStack(ArrayStack* s) {

	return s->data[s->top];
}

int printArrayStack(ArrayStack* s) {

	printf("Stack: ");

	if (emptyArrayStack(s)) {

		printf("\n");
		return 1;
	}

	for (int i = 0; i <= s->top; i++) {

		if (s->type == CHARACTER) {   // 문자형 stack
			printf("%c ", s->data[i].operator);
		}
		else if (s->type == INTEGER) {  // 정수형 stack

			printf("%d ",s->data[i].value);
		}
	}

	printf("\n");

	return 1;
}
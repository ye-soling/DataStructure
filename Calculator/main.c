#include "calculator.h"

int main() {

	char sample[100];
	char postfix[100];

	printf("입력: ");
	fgets(sample, sizeof(sample), stdin);

	infixToPostfix(sample, postfix);
	evalPostfix(postfix);

	return 0;
}
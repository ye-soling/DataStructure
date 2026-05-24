#include "calculator.h"
#include "ArrayStack.h"

int infixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	printf("Transform:\n");

	for (int i = 0; infix[i] != '\0'; i++) {
		if (infix[i] == ' ') {    // 공백은 무시
			continue;
		}

		if (infix[i] >= '0' &&
			infix[i] <= '9') {

			postfix[j] = infix[i];
			j++;

			postfix[j] = ' ';
			j++;
		}

		else if (infix[i] == '+' || infix[i] == '-' ||
			infix[i] == '*' || infix[i] == '/') {

			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);

				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					stackElement temp = popArrayStack(opStack);

					postfix[j] = temp.operator;
					j++;

					postfix[j] = ' ';
					j++;
				}

				else {
					break;
				}
			}

			stackElement newOp;
			newOp.operator = infix[i];

			pushArrayStack(opStack, newOp);
		}

		// ( 는 그대로 스택에 저장
		else if (infix[i] == '(') {
			stackElement temp;
			temp.operator = '(';

			pushArrayStack(opStack, temp);
		}

		// ) 는 '(' 가 나올 때까지 pop
		else if (infix[i] == ')') {

			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = popArrayStack(opStack);

				// '(' 만나면 종료
				if (prevOp.operator == '(') {
					break;
				}

				postfix[j] = prevOp.operator;
				j++;

				postfix[j] = ' ';
				j++;
			}
		}

		printf("- Postfix: ");

		for (int k = 0; k < j; k++) {
			printf("%c", postfix[k]);
		}

		printf("| ");

		printArrayStack(opStack);
	}

	// 스택에 남아있는 연산자 모두 postfix에 추가
	while (!emptyArrayStack(opStack)) {
		stackElement temp = popArrayStack(opStack);

		postfix[j] = temp.operator;
		j++;

		postfix[j] = ' ';
		j++;

		printf("- Postfix: ");

		for (int k = 0; k < j; k++) {
			printf("%c", postfix[k]);
		}

		printf("| ");

		printArrayStack(opStack);
	}

	postfix[j] = '\0';

	printf("\n- Result: %s\n", postfix);

	return 1;
}

// 후위 표기식을 계산하는 함수
int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);

	int i = 0;

	printf("\nEval:\n");
	printf("- Postfix: %s\n", postfix);

	while (postfix[i] != '\0') {

		if (postfix[i] == ' ') {    // 공백은 무시
			i++;
			continue;
		}

		// 숫자인 경우 
		if (postfix[i] >= '0' &&
			postfix[i] <= '9') {

			stackElement temp;

			temp.value = postfix[i] - '0';  // 문자 -> 정수 변환

			pushArrayStack(valueStack, temp); 

			printf("- Current: %c | ", postfix[i]);

			printArrayStack(valueStack);
		}

		// 연산자인 경우
		else if (postfix[i] == '+' || postfix[i] == '-' ||
			postfix[i] == '*' || postfix[i] == '/') {

			int i1 = popArrayStack(valueStack).value;
			int i2 = popArrayStack(valueStack).value;

			stackElement result;

			// 연산 수행
			if (postfix[i] == '+') {
				result.value = i2 + i1;
			}

			else if (postfix[i] == '-') {
				result.value = i2 - i1;
			}

			else if (postfix[i] == '*') {
				result.value = i2 * i1;
			}

			else if (postfix[i] == '/') {
				result.value = i2 / i1;
			}

			// 결과 push
			pushArrayStack(valueStack, result);

			printf("- Current: %c | ", postfix[i]);

			printArrayStack(valueStack);
		}

		i++;
	}

	// 최종 결과 pop
	stackElement finalResult = popArrayStack(valueStack);

	printf("\n- Result: %d\n", finalResult.value);

	return finalResult.value;
}

// 연산자 우선순위를 반환 
int precedence(char op) {

	switch (op)
	{
	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;

	case '(':
		return 0;

	default:
		return 0;
	}
}
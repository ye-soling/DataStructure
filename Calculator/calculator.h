#include <stdio.h>
#include <stdlib.h>

extern int infixToPostfix(char* infix, char* postfix);
extern int evalPostfix(char* postfix);
extern int precedence(char op);  // 우선순위를 반환하는 함수
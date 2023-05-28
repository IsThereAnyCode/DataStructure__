#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef struct {
	int stack[MAX_STACK_SIZE];
	int top;
}Stack;

void initialize(Stack* S) {
	S->top = -1;
}
int is_full(Stack* S) {
	return (S->top == MAX_STACK_SIZE - 1);
}
int is_empty(Stack* S) {
	return (S->top == -1);
}
void push(Stack* S, int item) {
	if (is_full(S)) {
		fprintf(stderr, "스택 포화 에러\n"); return;
	}
	else S->stack[++(S->top)] = item;
}
int pop(Stack* S) {
	if (is_empty(S)) {
		fprintf(stderr, "스택 공백 에러\n"); exit(1);
	}
	else return S->stack[(S->top)--];
}
int peek(Stack* S) {
	if (is_empty(S)) {
		fprintf(stderr, "스택 공백 에러\n"); return -1;
	}
	else return S->stack[S->top];
}
int prec(char op) {
	switch (op) {
	case'(':
	case')':
		return 0;
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
		return 2;
	}
	return -1;
}

void infix_to_postfix(char infix[]) {
	int i = 0;
	char* str = NULL;
	char symbol, top_op;
	Stack* S = (Stack*)malloc(sizeof(Stack));
	initialize(S);
	size_t len = strlen(infix);
	for (i = 0; i < len; i++) {
		symbol = infix[i];
		switch (symbol) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!is_empty(S) && (prec(symbol) <= prec(peek(S))))printf("%c", pop(S));
			push(S, symbol); break;
		case '(':
			push(S, symbol); break;
		case ')':
			top_op = pop(S);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(S);
			}
			break;
		default:
			printf("%c", symbol); break;
		}
		while (!is_empty(S)) printf("%c", pop(S));
	}	
}

int evalPostfix(char* exp) {
	int opr1, opr2, value;
	// char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
	size_t length = strlen(exp);
	char symbol;
	Stack* S = (Stack*)malloc(sizeof(Stack));
	initialize(S);

	for (int i = 0; i < length; i++) {
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/') {
			value = symbol - '0';
			push(S, value);
		}
		else {
			opr2 = pop(S);
			opr1 = pop(S);
			// 변수 opr1과 opr2에 대해 symbol에 저장된 연산자를 연산
			switch (symbol) {
			case '+': push(S, opr1 + opr2); break;
			case '-': push(S, opr1 - opr2); break;
			case '*': push(S, opr1 * opr2); break;
			case '/': push(S, opr1 / opr2); break;
			}
		}
	}
	// 수식 exp에 대한 처리를 마친 후 스택에 남아 있는 결과값을 pop하여 변환
	return pop(S);
}

int main(void)
{
	int result;
	char* exp = (char*)"(9*3)-(9/3)";
	printf("infix : %s\n", exp); getchar();
	printf("postfix: ");
	infix_to_postfix(exp);
	printf("\n"); getchar();
	result = evalPostfix((char*)"93*93/-");
	printf("postfix 결과값 = %d\n", result); getchar();
	return 0;
}
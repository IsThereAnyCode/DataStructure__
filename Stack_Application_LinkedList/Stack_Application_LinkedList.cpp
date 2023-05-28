#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initialize(Stack* S) {
    S->top = NULL;
}

int is_empty(Stack* S) {
    return (S->top == NULL);
}

void push(Stack* S, int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = S->top;
    S->top = newNode;
}

int pop(Stack* S) {
    if (is_empty(S)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    int result = S->top->data;
    Node* temp = S->top;
    S->top = S->top->next;
    free(temp);
    return result;
}

int peek(Stack* S) {
    if (is_empty(S)) {
        fprintf(stderr, "스택 공백 에러\n");
        return -1;
    }
    return S->top->data;
}

int prec(char op) {
    switch (op) {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infix_to_postfix(char infix[]) {
    int i = 0;
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
            while (!is_empty(S) && (prec(symbol) <= prec(peek(S))))
                printf("%c", pop(S));
            push(S, symbol);
            break;
        case '(':
            push(S, symbol);
            break;
        case ')':
            top_op = pop(S);
            while (top_op != '(') {
                printf("%c", top_op);
                top_op = pop(S);
            }
            break;
        default:
            printf("%c", symbol);
            break;
        }
    }
    while (!is_empty(S)) printf("%c", pop(S));
}

int evalPostfix(char* exp) {
    int opr1, opr2, value;
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
            switch (symbol) {
            case '+': push(S, opr1 + opr2); break;
            case '-': push(S, opr1 - opr2); break;
            case '*': push(S, opr1 * opr2); break;
            case '/': push(S, opr1 / opr2); break;
            }
        }
    }
    // 수식 exp에// 대한 처리를 마친 후 스택에 남아 있는 결과값을 pop하여 반환
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
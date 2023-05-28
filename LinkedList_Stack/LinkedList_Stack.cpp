#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {  // 연결 리스트의 노드 구조체
    element data;
    struct ListNode* link;
} ListNode;

typedef struct {
    ListNode* top;
} LinkedListStack;

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty(LinkedListStack* stack) {
    if (stack->top == NULL) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(LinkedListStack* stack, element item) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));  // 새로운 노드 생성
    temp->data = item;
    temp->link = stack->top;  // 새로운 노드가 기존의 top 노드를 가리킴
    stack->top = temp;  // 새로운 노드가 새로운 top 노드가 됨
}

// 스택의 top에 원소를 삭제하는 연산
element pop(LinkedListStack* stack) {
    if (isStackEmpty(stack)) {
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else {
        ListNode* temp = stack->top;  // top 노드를 임시로 저장
        element item = temp->data;
        stack->top = stack->top->link;  // top을 다음 노드로 변경
        free(temp);  // 기존의 top 노드 메모리 해제
        return item;
    }
}

// 스택의 top 원소를 검색하는 연산
element peek(LinkedListStack* stack) {
    if (isStackEmpty(stack)) {
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else return stack->top->data;
}

// 스택의 원소를 출력하는 연산
void printStack(LinkedListStack* stack) {
    ListNode* p = stack->top;
    printf("\n STACK [");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("]");
}

int main(void) {
    LinkedListStack stack = { NULL };  // 빈 스택으로 초기화

    element item;
    printf("\n"" 연결리스트 스택 연산**\n");
    printStack(&stack);
    push(&stack, 1);  printStack(&stack);  // 1 삽입
    push(&stack, 2);  printStack(&stack);  // 2 삽입
    push(&stack, 3);  printStack(&stack);  // 3 삽입

    item = peek(&stack);  printStack(&stack);  // 현재 top의 원소 출력
    printf("\t peek => %d", item);

    item = pop(&stack);  printStack(&stack);  // 삭제
    printf("\t pop => %d", item);

    item = pop(&stack);  printStack(&stack);  // 삭제
    printf("\t pop => %d", item);

    item = pop(&stack);  printStack(&stack);  // 삭제
    printf("\t pop => %d", item);

    getchar();

    return 0;
}

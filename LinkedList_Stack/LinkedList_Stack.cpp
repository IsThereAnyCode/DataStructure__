#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {  // ���� ����Ʈ�� ��� ����ü
    element data;
    struct ListNode* link;
} ListNode;

typedef struct {
    ListNode* top;
} LinkedListStack;

// ������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty(LinkedListStack* stack) {
    if (stack->top == NULL) return 1;
    else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ����
void push(LinkedListStack* stack, element item) {
    ListNode* temp = (ListNode*)malloc(sizeof(ListNode));  // ���ο� ��� ����
    temp->data = item;
    temp->link = stack->top;  // ���ο� ��尡 ������ top ��带 ����Ŵ
    stack->top = temp;  // ���ο� ��尡 ���ο� top ��尡 ��
}

// ������ top�� ���Ҹ� �����ϴ� ����
element pop(LinkedListStack* stack) {
    if (isStackEmpty(stack)) {
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else {
        ListNode* temp = stack->top;  // top ��带 �ӽ÷� ����
        element item = temp->data;
        stack->top = stack->top->link;  // top�� ���� ���� ����
        free(temp);  // ������ top ��� �޸� ����
        return item;
    }
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek(LinkedListStack* stack) {
    if (isStackEmpty(stack)) {
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else return stack->top->data;
}

// ������ ���Ҹ� ����ϴ� ����
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
    LinkedListStack stack = { NULL };  // �� �������� �ʱ�ȭ

    element item;
    printf("\n"" ���Ḯ��Ʈ ���� ����**\n");
    printStack(&stack);
    push(&stack, 1);  printStack(&stack);  // 1 ����
    push(&stack, 2);  printStack(&stack);  // 2 ����
    push(&stack, 3);  printStack(&stack);  // 3 ����

    item = peek(&stack);  printStack(&stack);  // ���� top�� ���� ���
    printf("\t peek => %d", item);

    item = pop(&stack);  printStack(&stack);  // ����
    printf("\t pop => %d", item);

    item = pop(&stack);  printStack(&stack);  // ����
    printf("\t pop => %d", item);

    item = pop(&stack);  printStack(&stack);  // ����
    printf("\t pop => %d", item);

    getchar();

    return 0;
}

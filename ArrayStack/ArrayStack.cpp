#include <stdio.h>
#define STACK_SIZE 100	
typedef int element;		// ���� ����(element)�� �ڷ����� int�� ����
element stack[STACK_SIZE];	// 1���� �迭 ���� ����
int top = -1;

//������ ���� �������� Ȯ���ϴ� ����
int isStackEmpty()
{
	if (top == -1) return 1;
	else return 0;
}
// ������ ��ȭ �������� Ȯ���ϴ� ����
int isStackFull()
{
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}
// ������ top�� ���Ҹ� �����ϴ� ����
void push(element item)
{
	if (isStackFull())			// ������ ��ȭ ������ ���
	{
		printf("\n\n Stack is FULL! \n");
		return;
	}
	else stack[++top] = item;	// top�� ������Ų �� ���� top�� ���� ���� ����
}
// ������ top�� ���Ҹ� �����ϴ� ����
element pop(element item)
{
	if (isStackEmpty())			// ������ ���� ������ ���
	{
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];	// ���� top�� ���Ҹ� ������ �� top ����
}
// ������ top ���Ҹ� �˻��ϴ� ����
element peek()
{
	if (isStackEmpty())			// ������ ���� ������ ���
	{
		printf("\n\n Stack is Empty!!\n");
		return NULL;
	}
	else return stack[top];		// ���� top�� ���� Ȯ��
}
// ������ ���Ҹ� ����ϴ� ����
void printStack()
{
	int i;
	printf("\n STACK [");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("]");
}

int main(void)
{
	element item;
	printf("\n"" ���� ���� ����**\n");
	printStack();
	push(1);	printStack();	// 1 ����
	push(2);	printStack();	// 2 ����
	push(3);	printStack();	// 3 ����

	item = peek();	printStack();	// ���� top�� ���� ���
	printf("\t peek => %d", item);

	item = pop(item);	printStack();	// ����
	printf("\t pop => %d", item);

	item = pop(item);	printStack();	// ����
	printf("\t pop => %d", item);

	item = pop(item);	printStack();	// ����
	printf("\t pop => %d", item);

	getchar(); return 0;
}
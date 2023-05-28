#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[10];
	struct ListNode* link;
} Node;

typedef struct {
	Node* head;
}LinkedList;

LinkedList* createLinkedList(void)
{
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
	if (L == NULL)
		return NULL;
	L->head = NULL;
	return L;
}

void printLinkedList(LinkedList* L)
{
	Node* p;
	printf("Linked List L = (");
	p = L->head;
	while (p!= NULL)
	{
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertNodeAsFirst(LinkedList* L, char* data)
{
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return;
	strcpy_s(N->data, sizeof(N->data), data);
	N->link = L->head;
	L->head = N;
}

void insertNodeAsMiddle(LinkedList* L, Node* preN, char* data)
{
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return;
	strcpy_s(N->data, sizeof(N->data), data);
	if (L->head == NULL) { N->link = NULL; L->head = N; }
	else if (preN == NULL) { N->link = L->head; L->head = N; }
	else { N->link = preN->link; preN->link = N; }
}

void insertNodeAsLast(LinkedList* L, char* data)
{
	Node* temp;
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return;
	strcpy_s(N->data, sizeof(N->data), data);
	N->link = NULL;
	if (L->head == NULL) { L->head = N; return; }
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;
	temp->link = N;
}

Node* findNode(LinkedList* L, char* data)
{
	Node* p = L->head;
	while (p->link == NULL)
	{
		if (p->data == data)
			return p;
		else
			p = p->link;
	}
}

int main(void)
{
	LinkedList* L = createLinkedList();
	printf("����Ʈ �����ϱ�: \n\n\n");
	insertNodeAsFirst(L, (char*)"������"); printLinkedList(L); printf("\n");
	insertNodeAsLast(L, (char*)"�ݿ���"); printLinkedList(L); printf("\n");
	getchar();

	printf("����Ʈ�� ��� �����ϱ�: \n\n\n");
	Node* N = findNode(L, (char*)"������");		// ������ ��尡 ��ȯ�� �ȴ�.
	insertNodeAsMiddle(L, N, (char*)"������"); printLinkedList(L); printf("\n");
	getchar();

	return 0;
}
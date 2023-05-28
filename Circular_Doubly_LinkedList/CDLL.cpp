#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct CDLL_Node {
	Element data;
	struct CDLL_Node* prevN;
	struct CDLL_Node* nextN;
} Node;

Node* createNode(Element data)
{
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return NULL;
	N->data = data;
	N->prevN = NULL; N->nextN = NULL;
	return N;
}

void destroyNode(Node* N)
{
	free(N);
}

void appendNode(Node** head, Node* N)
{
	if ((*head) == NULL) {
		*head = N;
		(*head)->nextN = *head; (*head)->prevN = *head;
	}
	else {
		Node* tail = (*head)->prevN;
		tail->nextN->prevN = N; tail->nextN = N;
		N->nextN = (*head); N->prevN = tail;
	}
}

void insertAfter(Node* currentN, Node* N)
{
	N->nextN = currentN->nextN; N->prevN = currentN;
	currentN->nextN->prevN = N; currentN->nextN = N;
}

void removeNode(Node** head, Node* removeN)
{
	if ((*head) == removeN) {
		(*head)->prevN->nextN = removeN->nextN;
		(*head)->nextN->prevN = removeN->prevN;
		*head = removeN->nextN;
		removeN->prevN = NULL; removeN->nextN = NULL;
	}
}

Node* getNodeAt(Node* head, int location)
{
	Node* currentN = head;
	while (currentN != NULL && (--location) >= 0)
		currentN = currentN->nextN;
	return currentN;
}

int getNodeCount(Node* head)
{
	unsigned int count = 0;
	Node* currentN = head;

	while (currentN != NULL) {
		currentN = currentN->nextN;
		count++;
		if (currentN == head) break;
	}
	return count;
}

void printNode(Node* N)
{
	if (N->prevN == NULL) printf("Prev: NULL");
	else printf("Prev: %d", N->prevN->data);
	printf(" Current: %d ", N->data);

	if (N->nextN == NULL) printf("Next: NULL\n");
	else printf("Next :%d\n", N->nextN->data);
}

int main(void)
{
	int i = 0; int count = 0;
	Node* L = NULL; Node* N = NULL; Node* currentN = NULL;
	for (i = 0; i < 5; i++) {
		N = createNode(i);
		appendNode(&L, N);
	}
	count = getNodeCount(L);
	for (i = 0; i < count; i++) {
		currentN = getNodeAt(L, i);
		printf("List[%d] : %d\n", i, currentN->data);
	}
	printf("\nInserting 3000 After [2]...\n\n");
	currentN = getNodeAt(L, 2);
	N = createNode(3000);
	insertAfter(currentN, N);
	count = getNodeCount(L);
	for (i = 0; i < count * 2; i++) {
		if (i == 0)currentN = L;
		else currentN = currentN->nextN;
		printf("List[%d] : %d\n", i, currentN->data);
	}
	printf("\nDestroying List...\n");
	count = getNodeCount(L);
	for (i = 0; i < count; i++) {
		currentN = getNodeAt(L, 0);
		if (currentN != NULL) {
			removeNode(&L, currentN);
			destroyNode(currentN);
		}
	}
	return 0;
}
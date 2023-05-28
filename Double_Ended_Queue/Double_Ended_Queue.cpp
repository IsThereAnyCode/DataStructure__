#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct DequeNode {
	element data;
	struct DequeNode* llink;
	struct DequeNode* rlink;
} Node;
typedef struct Deque {
	struct DequeNode* front;
	struct DequeNode* rear;
} Deque;

Deque* createQueue()
{
	Deque* DQ = (Deque*)malloc(sizeof(Deque));
	if (DQ == NULL) return NULL;
	DQ->front = NULL; DQ->rear = NULL;
	return DQ;
}
int isEmpty(Deque* DQ)
{
	return (DQ->front == NULL || DQ->rear == NULL);
}
void insertFront(Deque* DQ, element item)
{
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return;
	N->data = item;
	if (isEmpty(DQ)) {
		DQ->front = N; DQ->rear = N;
		N->rlink = NULL; N->llink = NULL;
	}
	else {	// 삽입
		DQ->front->llink = N;
		N->rlink = DQ->front;
		N->llink = NULL;
		DQ->front = N;
	}
}
void insertRear(Deque* DQ, element item)
{
	Node* N = (Node*)malloc(sizeof(Node));
	if (N == NULL) return;
	N->data = item;
	if (isEmpty(DQ)) {
		DQ->front = N; DQ->rear = N;
		N->rlink = NULL; N->llink = NULL;
	}
	else {	// 삽입
		DQ->rear->rlink = N;
		N->rlink = NULL;
		N->llink = DQ->rear;
		DQ->rear = N;
	}
}
element deleteFront(Deque* DQ)
{
	Node* remove = DQ->front;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = remove->data;
		if (DQ->front->rlink == NULL) {		// 노드가 없을 때
			DQ->front = NULL; DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;	// 삭제 연산
			DQ->front->llink = NULL;
		}
		free(remove);
		return item;
	}
}
element deleteRear(Deque* DQ)
{
	Node* remove = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = remove->data;
		if (DQ->rear->llink == NULL) {		// 노드가 없을 때
			DQ->rear = NULL; DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;	// 삭제 연산
			DQ->rear->rlink = NULL;
		}
		free(remove);
		return item;
	}
}
element peekFront(Deque* DQ)
{
	if (isEmpty(DQ)) return 0;
	else return (DQ->front->data);
}
element peekRear(Deque* DQ)
{
	if (isEmpty(DQ)) return 0;
	else return (DQ->rear->data);
}
void printDeque(Deque* DQ)
{
	Node* ptr = DQ->front;
	printf("Deque: [");
	while (ptr) {
		printf("%3c", ptr->data);
		ptr = ptr->rlink;
	}
	printf(" ] \n");
}
int main(void)
{
	Deque* DQ = createQueue();
	printDeque(DQ);
	insertFront(DQ, 'A'); printDeque(DQ);		// A
	insertFront(DQ, 'B'); printDeque(DQ);		// B A
	insertRear(DQ, 'C'); printDeque(DQ);		// B A C
	getchar();

	element data = deleteFront(DQ); printDeque(DQ);	// A C
	data = deleteRear(DQ); printDeque(DQ);			// A
	getchar();

	insertRear(DQ, 'D'); printDeque(DQ);			// A D
	insertFront(DQ, 'E'); printDeque(DQ);			// E A D
	insertFront(DQ, 'F'); printDeque(DQ);			// F E A D
	getchar();

	printf("\n");
	data = peekFront(DQ); printf(" front item: %c\n", data);	// F
	data = peekRear(DQ); printf(" rear item: %c\n", data);		// D
	getchar();

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 4
typedef char element;
typedef struct CircularQueue {
	element queue[BUFLEN];
	int front, rear;
} Queue;

Queue* createQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->front = -1;	// front 초깃값 설정
	q->rear = -1;	// rear 초깃값 설정
	return q;
}
int isEmpty(Queue* CQ)
{
	return (CQ->front == CQ->rear);
}
int isFull(Queue* CQ)
{
	return (((CQ->rear + 1) % BUFLEN) == CQ->front);
}
void enQueue(Queue* CQ, element item)
{
	if (isFull(CQ)) return;
	else {
		CQ->rear = (CQ->rear + 1) % BUFLEN;
		CQ->queue[CQ->rear] = item;
	}
}
element deQueue(Queue* CQ)
{
	if (isEmpty(CQ)) return '\0';
	else {
		CQ->front = (CQ->front + 1) % BUFLEN;
		return CQ->queue[CQ->front];
	}
}
element peek(Queue* CQ)
{
	if (isEmpty(CQ)) return '\0';
	else return CQ->queue[(CQ->front + 1) % BUFLEN];
}
void printQueue(Queue* CQ)
{
	int first = (CQ->front + 1) % BUFLEN;
	int last = (CQ->rear + 1) % BUFLEN;
	printf("원형 큐: [");
	int i = first;
	while (i != last) {
		printf("%3c", CQ->queue[i]);
		i = (i + 1) % BUFLEN;
	}
	printf(" ]\n");
}

int main(void)
{
	Queue* CQ = createQueue();
	element data;

	printQueue(CQ);
	enQueue(CQ, 'A'); printQueue(CQ);
	enQueue(CQ, 'B'); printQueue(CQ);
	enQueue(CQ, 'C'); printQueue(CQ);

	data = peek(CQ); printf("peek item: %c\n", data);

	deQueue(CQ);	printQueue(CQ);
	deQueue(CQ);	printQueue(CQ);
	deQueue(CQ);	printQueue(CQ);

	enQueue(CQ, 'D'); printQueue(CQ);
	enQueue(CQ, 'E'); printQueue(CQ);

	free(CQ);

	return 0;
}
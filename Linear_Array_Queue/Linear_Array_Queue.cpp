#include <stdio.h>
#include <stdlib.h>

#define BUFLEN 4
typedef char element;
typedef struct LinearQueue {
    element queue[BUFLEN];
    int front, rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

int isEmpty(Queue* q) {
    return (q->front == q->rear);
}

int isFull(Queue* q) {
    return (q->rear == BUFLEN);
}

void enQueue(Queue* q, element item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    else {
        q->queue[q->rear++] = item;
    }
}

element deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return '\0';
    }
    else {
        return q->queue[q->front++];
    }
}

element peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return '\0';
    }
    else {
        return q->queue[q->front];
    }
}

void printQueue(Queue* q) {
    printf("Linear Queue: [");
    for (int i = q->front; i < q->rear; i++) {
        printf("%3c", q->queue[i]);
    }
    printf(" ]\n");
}

int main(void) {
    Queue* q = createQueue();
    element data;

    printQueue(q);
    enQueue(q, 'A'); printQueue(q);
    enQueue(q, 'B'); printQueue(q);
    enQueue(q, 'C'); printQueue(q);

    data = peek(q); printf("peek item: %c\n", data);

    deQueue(q);    printQueue(q);
    deQueue(q);    printQueue(q);
    deQueue(q);    printQueue(q);

    enQueue(q, 'D'); printQueue(q);
    enQueue(q, 'E'); printQueue(q);

    free(q);

    return 0;
}
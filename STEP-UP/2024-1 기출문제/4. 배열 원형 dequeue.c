#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

void initQueue(struct CircularQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct CircularQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct CircularQueue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue *queue, int value) {
    if (isFull(queue)) {
        printf("Full\n");
        return;
    } else if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->items[queue->rear] = value;
}

int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Empty\n");
        return -1;
    } else if (queue->front == queue->rear) {
        int value = queue->items[queue->front];
        queue->front = -1;
        queue->rear = -1;
        return value;
    } else {
        int value = queue->items[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        return value;
    }
}

void display(struct CircularQueue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Empty\n");
        return;
    }
    i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d ", queue->items[i]);
    printf("\n");
}

int main() {
    struct CircularQueue queue;
    int i, num;
    initQueue(&queue);
    for (i = 0; i < 5; i++) {
        scanf("%d", &num);
        enqueue(&queue, num);
    }
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    enqueue(&queue, 60);
    enqueue(&queue, 70);
    display(&queue);
    return 0;
}

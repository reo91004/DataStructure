#include <stdio.h>

#define SIZE 6

int queue[SIZE];
int front = -1, rear = -1;

int checkFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) {
        return 1;
    }
    return 0;
}

int checkEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int value) {
    if (checkFull()) {
        printf("오버플로우 상태\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }
}

int dequeue() {
    int variable;
    if (checkEmpty()) {
        printf("언더플로우 상태\n");
        return -1;
    } else {
        variable = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        return variable;
    }
}

void display() {
    int i;
    if (checkEmpty())
        printf("비어 있음\n");
    else {
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d \n", queue[i]);
        }
        printf("%d \n", queue[i]);
    }
}

int main() {
    enqueue(15);
    enqueue(20);
    display();
    dequeue();
    display();

    dequeue();
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7); // 오버플로우 상태
    display();
    return 0;
}

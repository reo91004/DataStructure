#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("\n언더플로우\n");
        return -1;
    } else {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("\n큐가 비어 있습니다.\n");
    } else {
        struct node *temp = front;
        while (temp) {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    dequeue();
    dequeue();
    display();
    return 0;
}

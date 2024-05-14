#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("메모리 할당 실패\n");
        return;
    }
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
        printf("큐가 비어 있습니다.\n");
        return -1;
    } else {
        struct Node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        if (front == NULL) {
            rear = NULL;
        }
        return temp_data;
    }
}

void display() {
    if (front == NULL) {
        printf("큐가 비어 있습니다.\n");
        return;
    } else {
        struct Node *temp = front;
        printf("큐의 요소: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int i, num;
    printf("큐에 삽입할 세 개의 요소를 입력하세요: ");
    for (i = 1; i <= 3; i++) {
        scanf("%d", &num);
        enqueue(num);
    }

    dequeue();
    display();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// 정수형 단일 연결 리스트의 노드 구조체 정의
struct Node {
    int data;
    struct Node *next;
};

// 새로운 노드를 생성하는 함수
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 정렬된 단일 연결 리스트에 값을 삽입하는 함수
void insertSorted(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    // 리스트가 비어있거나 첫 번째 노드의 값보다 클 경우
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // 중간에 노드를 삽입해야 할 경우
    struct Node *current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// 연결 리스트를 출력하는 함수
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // 초기 리스트 생성 (오름차순으로 정렬되어 있음)
    insertSorted(&head, 10);
    insertSorted(&head, 20);
    insertSorted(&head, 30);
    insertSorted(&head, 40);

    int value;
    scanf("%d", &value); // 삽입할 값 입력

    // 사용자로부터 입력 받은 값을 리스트에 삽입
    insertSorted(&head, value);

    printList(head);

    return 0;
}
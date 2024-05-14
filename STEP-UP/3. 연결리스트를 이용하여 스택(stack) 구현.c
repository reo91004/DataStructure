#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} stack;

stack *top = NULL;

void push(int);
int pop();
void print_s();

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print_s();

    pop();
    pop();
    print_s();
}

void push(int data) {
    stack *new_node = (stack *)malloc(sizeof(stack));

    if (new_node == NULL) {
        printf("스택이 가득 찼습니다!");
        exit(1);
    }

    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop() {
    stack *del;
    int value;

    if (top == NULL) {
        printf("스택이 비어 있습니다!");
        exit(1);
    }

    value = top->data;
    del = top;
    top = top->next;
    free(del);

    return value;
}

void print_s() {
    stack *i = top;

    while (i != NULL) {
        printf("%d \n", i->data);
        i = i->next;
    }
    printf("\n");
}

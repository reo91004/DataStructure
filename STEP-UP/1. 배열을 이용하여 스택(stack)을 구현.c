#include <stdio.h>

#define SIZE 100

int stack[SIZE], choice, top;

void push(int x);
int pop(void);
void display(void);

int main() {
    top = -1;

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();

    pop();
    pop();
    display();

    return 0;
}

void push(int x) {
    if (top >= SIZE - 1)
        printf("\n\tSTACK is overflow");
    else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    if (top <= -1) {
        printf("\n\tStack is underflow");
    } else {
        top--;
        return stack[top + 1];
    }
}

void display() {
    int i;
    if (top >= 0) {
        for (i = top; i >= 0; i--)
            printf("%d \n", stack[i]);
        printf("\n");
    } else {
        printf("\nThe STACK is empty");
    }
}

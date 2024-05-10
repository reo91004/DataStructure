#include <iostream>

#define MAX 100 // 스택 최대 크기
typedef int element; // 데이터 자료형
element stack[MAX]; // 배열 선언 (스택)
int top = -1;

// 공백 상태 검출
bool is_empty() { 
    return (top == -1);
}

// 포화 상태 검출
bool is_full() {
    return (top == MAX - 1);
}

// 삽입
void push(element item) { 
    if (is_full()) {
        fprintf(stderr, "스택 포화\n"); // 에러 메세지 출력
        return;
    }

    stack[++top] = item;
}

// 삭제
element pop() {
    if (is_empty()) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }

    return stack[top--];
}

// 피크
element peek() {
    if (is_empty()) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }

    return stack[top];
}

int main() {
    push(1);
    push(2);
    push(3);
    std::cout << pop() << "\n";
    std::cout << pop() << "\n";
    std::cout << pop() << "\n";

    return 0;

}
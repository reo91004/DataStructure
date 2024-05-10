#include <iostream>

#define MAX 100 // 스택 최대 크기
typedef int element; // 데이터 자료형
typedef struct {
    element data[MAX];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

// 공백 상태 검출
bool is_empty(StackType *s) { 
    return (s->top == -1);
}

// 포화 상태 검출
bool is_full(StackType *s) {
    return (s->top == MAX - 1);
}

// 삽입
void push(StackType *s, element item) { 
    if (is_full(s)) {
        fprintf(stderr, "스택 포화\n"); // 에러 메세지 출력
        return;
    }

    s->data[++(s->top)] = item;
}

// 삭제
element pop(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }

    return s->data[(s->top)--];
}

// 피크
element peek(StackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }

    return s->data[(s->top)];
}

int main() {
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    std::cout << pop(&s) << "\n";
    std::cout << pop(&s) << "\n";
    std::cout << pop(&s) << "\n";

    return 0;

}
#include <iostream>
#include <string>

using namespace std;

#define MAX 100        // 스택 최대 크기
typedef char element;  // 데이터 자료형
typedef struct {
    element data[MAX];
    int top;
} StackType;

void init_stack(StackType *s) { s->top = -1; }

// 공백 상태 검출
bool s_is_empty(StackType *s) { return (s->top == -1); }

// 포화 상태 검출
bool is_full(StackType *s) { return (s->top == MAX - 1); }

// 삽입
void push(StackType *s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화\n");  // 에러 메세지 출력
        return;
    }

    s->data[++(s->top)] = item;
}

// 삭제
element pop(StackType *s) {
    if (s_is_empty(s)) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }

    return s->data[(s->top)--];
}

// 피크
element peek(StackType *s) {
    if (s_is_empty(s)) {
        fprintf(stderr, "스택 공백\n");
        exit(1);
    }

    return s->data[(s->top)];
}

bool solution(string text) {
    StackType s;
    init_stack(&s);

    for (int i = 0; i < text.length(); ++i) {
        switch (text[i]) {
            case '(':
            case '[':
            case '{':
                push(&s, text[i]);
                break;
            case ')':
            case ']':
            case '}':
                if (s_is_empty(&s))
                    return false;
                else {
                    char pre = pop(&s);
                    if ((pre == '(' && text[i] != ')') ||
                        (pre == '[' && text[i] != ']') ||
                        (pre == '{' && text[i] != '}'))
                        return false;
                }
                break;
        }
    }
}

int main() {
    string text;
    cin >> text;

    if (solution(text))
        cout << "성공";
    else
        cout << "실패";

    return 0;
}
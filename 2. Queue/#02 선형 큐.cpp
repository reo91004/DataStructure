#include <iostream>

using namespace std;

#define MAX 5

typedef int element;
// front는 큐에서 앞쪽 요소에서 앞 위치, rear는 뒤 요소 위치
typedef struct {
    int front;
    int rear;
    element data[MAX];
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->rear = 1;
    q->front = -1;
}

void queue_print(QueueType *q) {
    for (int i = 0; i < MAX; ++i) {
        // i가 front보다 작으면 출력할 것이 없음, rear보다 크면 출력할 것이 없음.
        if (i <= q->front || i > q->rear)
            cout << " | ";
        else
            cout << q->data[i] << " | ";
    }

    cout << "\n";
}

bool is_full(QueueType *q) {
    if (q->rear == MAX - 1)
        return true;
    else
        return false;
}

bool q_is_empty(QueueType *q) {
    if (q->rear == MAX - 1)
        return true;
    else
        return false;
}

void enqueue(QueueType *q, int item) {
    if (is_full(q)) {
        error("큐가 포화상태입니다.");
        exit(1);
    }
    
    // rear가 마지막 부분 위치이므로 ++을 시켜준 다음 넣는다.
    q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q) {
    if (q_is_empty(q)) {
        error("큐가 공백상태입니다.");
        exit(1);
    }

    // 가장 앞에 있는 요소를 빼야 하므로 front를 증가시켜 준 다음 해당 위치 요소 삭제
    int item = q->data[++(q->front)];
    return item;
}
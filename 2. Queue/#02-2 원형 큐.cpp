#include <iostream>

using namespace std;

#define MAX 5

typedef int element;
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
    q->front = q->rear = 0;
}

// 나머지 연산 이용해서 full 판정
bool is_full(QueueType *q) {
    return ((q->rear + 1) % MAX == q->front);
}

// 같으면 항상 공백, 즉 항상 원형 큐에서 하나는 남겨놓아야 함
bool q_is_empty(QueueType *q) {
    return (q->front == q->rear);
}

void queue_print(QueueType *q) {
    cout << "QUEUE (front = " << q->front << " " << "rear = " << q->rear << ") ";
    if (!q_is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX;
            cout << q->data[i] << " | ";
            // 만약 i가 q->rear이랑 같다진다면 원형 큐의 끝임
            if (i == q->rear)
                break;
        } while (i != q->front); // 사실 걸일 일이 없는듯?
    }
    
    cout << "\n";
}

void enqueue(QueueType *q, int item) {
    if (is_full(q))
        error("큐가 포화상태입니다.");
    
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = item;
}

int dequeue(QueueType *q) {
    if (q_is_empty(q)) {
        error("큐가 공백상태입니다.");
        exit(1);
    }

    q->front = (q->front + 1) % MAX;
    return q->data[q->front];
}

int main() {
    QueueType q;
    int element;

    init_queue(&q);
    cout << "데이터 추가 단계\n";
    while (!is_full(&q)) {
        cout << "정수를 입력하세요 : ";
        cin >> element;
        enqueue(&q, element);
        queue_print(&q);
    }
    cout << "큐는 포화상태입니다.\n\n";
    cout << "큐 삭제 단계\n";
    while (!q_is_empty(&q)) {
        element = dequeue(&q);
        cout << "꺼내진 정수 : " << element << "\n";
        queue_print(&q);
    }
}
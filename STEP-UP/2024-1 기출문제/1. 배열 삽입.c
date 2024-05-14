#include <stdio.h>

int insertElement(int arr[], int size, int element, int capacity) {
    int i;
    if (size >= capacity) {
        printf("배열이 가득 찼습니다.\n");
        return size;
    }
    for (i = size - 1; i >= 0 && arr[i] > element; i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = element;
    return size + 1;
}

int main() {
    int arr[10] = {1, 2, 4, 5}; // 배열 선언 및 초기화, 10은 배열의 최대 용량
    int size, element, capacity;

    size = 4;
    capacity = 10; // 배열의 최대 용량

    printf("삽입할 원소를 입력하세요: ");
    scanf("%d", &element);

    // 새 원소 삽입
    size = insertElement(arr, size, element, capacity);

    // 결과 출력
    printf("결과: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

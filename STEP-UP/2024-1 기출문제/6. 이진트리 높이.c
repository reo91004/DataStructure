#include <stdio.h>
#include <stdlib.h>

// 이진 트리의 노드 구조체 정의
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 새로운 이진 트리 노드를 생성하는 함수
struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 트리에 데이터를 삽입하는 함수
struct TreeNode *insertNode(struct TreeNode *root, int data) {
    if (root == NULL) {
        return createNode(data); // 노드가 비어있으면 새로운 노드를 생성하여 반환
    } else {
        // 데이터가 작으면 왼쪽 서브트리로 이동
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        }
        // 데이터가 크면 오른쪽 서브트리로 이동
        else if (data > root->data) {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// 이진 트리의 높이를 계산하는 함수
int treeHeight(struct TreeNode *root) {
    if (root == NULL) {
        return 0; // 노드가 없으면 높이는 0
    } else {
        // 왼쪽 서브트리와 오른쪽 서브트리의 높이를 비교하여 더 큰 값을 반환
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

int main() {
    struct TreeNode *root = NULL;
    int data, height;

    // 사용자로부터 5개의 데이터 입력받아 이진 트리에 삽입
    for (int i = 0; i < 5; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // 이진 트리의 높이 계산
    height = treeHeight(root);

    printf("%d", height);

    return 0;
}

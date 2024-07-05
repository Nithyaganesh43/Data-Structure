#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int findMin(Node* node) {
    if (node == NULL) {
        printf("The tree is empty.\n");
        return -1;
    }
    while (node->left != NULL) {
        node = node->left;

    }
    return node->data;
}

int findMax(Node* node) {
    if (node == NULL) {
        printf("The tree is empty.\n");
        return -1;
    }
    while (node->right != NULL) {
        node = node->right;
    }
    return node->data;
}

int main() {
    Node* root = create(5);
    root->left = create(4);
    root->right = create(6);
    root->left->left = create(2);
    root->right->right = create(7);

    int minElement = findMin(root);
    int maxElement = findMax(root);

    printf("Minimum element in the BST: %d\n", minElement);
    printf("Maximum element in the BST: %d\n", maxElement);

    return 0;
}

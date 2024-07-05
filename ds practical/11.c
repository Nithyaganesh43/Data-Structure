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
 

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxHeight(Node* node) {
    if (node == NULL) {
        return -1;
    } else {
        int leftHeight = maxHeight(node->left);
        int rightHeight = maxHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

int main() { 
     Node* root = create(1);
    root->left = create(5);
    root->right = create(3);
    root->left->left = create(2);
    root->left->right = create(4);

    int height = maxHeight(root);
    printf("Maximum height of the tree: %d\n", height);

    return 0;
}


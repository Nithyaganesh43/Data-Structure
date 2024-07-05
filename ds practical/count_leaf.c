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
int count=0;
void getLeafCount(Node* root) {
    if (root == NULL) {
        return;
    }
    else {
        getLeafCount(root->left);
        if(root->left==NULL && root->right==NULL)count++;
        getLeafCount(root->right);
    }
}

int main() {
    Node* root = create(1);
    root->left = create(5);
    root->right = create(3);
    root->left->left = create(2);
    root->left->right = create(4);
getLeafCount(root);
    printf("Number of leaf nodes: %d\n", count);

    return 0;
}

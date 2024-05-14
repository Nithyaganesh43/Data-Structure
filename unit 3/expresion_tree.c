#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> //
// Structure for expression tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new expression tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build an expression tree from an infix expression
struct TreeNode* buildExpressionTree(char infix[], int start, int end) {
    struct TreeNode* stack[100];
    int top = -1;

    for (int i = start; i <= end; i++) {
        if (infix[i] == '(') {
            int j = i + 1;
            int count = 1;
            while (count != 0) {
                if (infix[j] == '(')
                    count++;
                else if (infix[j] == ')')
                    count--;
                j++;
            }
            i++;
            struct TreeNode* node = buildExpressionTree(infix, i, j - 2);
            stack[++top] = node;
            i = j - 1;
        } else if (isalnum(infix[i])) {
            struct TreeNode* node = createNode(infix[i]);
            stack[++top] = node;
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            struct TreeNode* right = stack[top--];
            struct TreeNode* left = stack[top--];
            struct TreeNode* node = createNode(infix[i]);
            node->left = left;
            node->right = right;
            stack[++top] = node;
        }
    }
    return stack[top];
}

// Function to traverse and print the expression tree in infix notation
void infixTraversal(struct TreeNode* root) {
    if (root != NULL) {
        if (root->left || root->right) {
            printf("(");
            infixTraversal(root->left);
            printf(" %c ", root->data);
            infixTraversal(root->right);
            printf(")");
        } else {
            printf("%c", root->data);
        }
    }
}

// Function to traverse and print the expression tree in prefix (preorder) notation
void prefixTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c", root->data);
        prefixTraversal(root->left);
        prefixTraversal(root->right);
    }
}

// Function to traverse and print the expression tree in postfix (postorder) notation
void postfixTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postfixTraversal(root->left);
        postfixTraversal(root->right);
        printf("%c", root->data);
    }
}

// Function to free memory allocated for the expression tree
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    int len = strlen(infix);
    struct TreeNode* root = buildExpressionTree(infix, 0, len - 1);

    printf("Infix expression: ");
    infixTraversal(root);
    printf("\n");

    printf("Prefix expression: ");
    prefixTraversal(root);
    printf("\n");

    printf("Postfix expression: ");
    postfixTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}

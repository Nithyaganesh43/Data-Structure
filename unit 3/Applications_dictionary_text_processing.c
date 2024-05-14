#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct TreeNode {
    char word[100];
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(char* word) {
    TreeNode* newNode = malloc(sizeof(TreeNode));
    if (newNode) {
        strcpy(newNode->word, word);
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

TreeNode* insert(TreeNode* root, char* word) {
    if (!root) return createNode(word);
    int cmp = strcmp(word, root->word);
    if (cmp < 0) root->left = insert(root->left, word);
    else if (cmp > 0) root->right = insert(root->right, word);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%s\n", root->word);
        inorderTraversal(root->right);
    }
}

int search(TreeNode* root, char* word) {
    while (root) {
        int cmp = strcmp(word, root->word);
        if (cmp == 0) return 1; // Found
        else if (cmp < 0) root = root->left;
        else root = root->right;
    }
    return 0; // Not found
}

void toLowercase(char* word) {
    for (; *word; ++word) *word = tolower(*word);
}

int main() {
    TreeNode* root = NULL;
    char word[100];

    while (1) {
        printf("> ");
        if (scanf("%99s", word) != 1) {
            printf("Invalid input.\n");
            return EXIT_FAILURE;
        }
        if (!strcmp(word, "exit")) break;
        toLowercase(word);
        root = insert(root, word);
    }

    printf("\nDictionary (in alphabetical order):\n");
    inorderTraversal(root);

    printf("\nEnter a word to search in the dictionary: ");
    if (scanf("%99s", word) != 1) {
        printf("Invalid input.\n");
        return EXIT_FAILURE;
    }
    toLowercase(word);
    if (search(root, word)) printf("%s is found in the dictionary.\n", word);
    else printf("%s is not found in the dictionary.\n", word);

    return 0;
}

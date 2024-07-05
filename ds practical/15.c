#include <stdio.h>
#include <stdlib.h>

// Define a structure for BST node
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find minimum element in BST
Node* findMin(Node* node) {
    if (node == NULL) {
        return NULL; // Tree is empty
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to find maximum element in BST
Node* findMax(Node* node) {
    if (node == NULL) {
        return NULL; // Tree is empty
    }
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

// Function to delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root; // Tree is empty or node not found
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }else { // Node to be deleted found
        // Case 1: Node with no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node with only one child
        if (root->left == NULL) { // Only right child
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) { // Only left child
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        Node* temp = findmax(root->right); // Find the minimum node in the right subtree
        root->data = temp->data; // Copy the inorder successor's data to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to search for a node in BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function for inorder traversal of BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal of BST
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal of BST
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to free memory allocated for the tree nodes
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBST Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Inorder Traversal\n");
        printf("7. Preorder Traversal\n");
        printf("8. Postorder Traversal\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("%d found in the tree.\n", data);
                } else {
                    printf("%d not found in the tree.\n", data);
                }
                break;
            case 4:
                if (root != NULL) {
                    Node* minNode = findMin(root);
                    printf("Minimum element in the BST: %d\n", minNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 5:
                if (root != NULL) {
                    Node* maxNode = findMax(root);
                    printf("Maximum element in the BST: %d\n", maxNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 6:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 7:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 8:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 9:
                freeTree(root);
                printf("BST memory freed. Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid menu option.\n");
        }
    }

    return 0;
}

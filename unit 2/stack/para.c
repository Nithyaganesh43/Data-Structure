#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for a node in the linked list
struct Node {
    char data;
    struct Node* next;
};

// Global variable for the top of the linked list
struct Node* top = NULL;

// Function to check if the linked list is empty
bool isEmpty() {
    return top == NULL;
}

// Function to push a new node onto the linked list
void push(char item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

// Function to pop a node from the linked list
void pop() {
    if (isEmpty()) {
        printf("stack underflow\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = top;
    top = temp->next;
    free(temp);
    return ;
}

// Function to check if parentheses are balanced using linked list
bool para(char infix[]) {
    int i;
    char symbol;
    int len = strlen(infix);
    
    for (i = 0; i < len; i++) {
        symbol = infix[i];
        if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            if (isEmpty()) {
                return false; // Unbalanced parentheses
            } else {
                pop();
            }
        }
    }
    
    return isEmpty(); // Check if linked list is empty after processing all symbols
}

int main() {
    char infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    if (para(infix)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    
    return 0;
}

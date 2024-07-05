#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push a node to the circular linked list
void push(struct Node** tail_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*tail_ref == NULL) {
        new_node->next = new_node;
        *tail_ref = new_node;
    } else {
        new_node->next = (*tail_ref)->next;
        (*tail_ref)->next = new_node;
    }
}

// Function to print nodes in a given circular linked list
void printList(struct Node* tail) {
    if (tail == NULL) return;

    struct Node* temp = tail->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

// Function to reverse the singly circular linked list
struct Node* reverse(struct Node* tail) {
    if (tail == NULL || (tail)->next == tail) return tail;

    struct Node *prev = tail, *curt = tail->next, *next;
  
    while(curt!=tail){
        next = curt->next;
        curt->next=prev;
        prev=curt;
        curt=next;
    }next=next->next;
    curt->next=prev;
    return next;
}

// Driver program to test above functions
int main() {
    struct Node* tail = NULL;

    // Add nodes to the list
    push(&tail, 12);
    push(&tail, 56);
    push(&tail, 2);
    push(&tail, 11);

    printf("Original List: \n");
    printList(tail);

    tail=reverse(tail);

    printf("Reversed List: \n");
    printList(tail);

    return 0;
}
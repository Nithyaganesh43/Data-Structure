#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly circular linked list
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
void swap(struct node **a,struct node **b){
    struct node *temp=*a;
    *a=*b;
    *b=temp;
}
// Function to reverse a doubly circular linked list
struct node* reverse_DCLL(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
struct node* tempH=head;
struct node* tempT=head->prev;
while(tempH!=tempT){
    swap(&(tempH->next),&(tempH->prev));
    tempH=tempH->prev;
}swap(&(tempH->next),&(tempH->prev));//swap tail
return tempT;
}

// Function to print the doubly circular linked list
void print_DCLL(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

// Function to create a new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int main() {
    // Creating a sample doubly circular linked list
    struct node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->prev = head->next->next;

    printf("Original list: ");
    print_DCLL(head);

    // Reversing the list
    head = reverse_DCLL(head);
    printf("Reversed list: ");
    print_DCLL(head);

    return 0;
}

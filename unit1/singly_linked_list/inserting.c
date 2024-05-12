#include <stdlib.h>
#include <stdio.h>

// Define a node structure for the linked list
struct node {
    int data;
    struct node *next;
};

// Function to display the elements of the linked list
void display(struct node *head){
    if(head == NULL)
        return;
    
    printf("\nCurrent elements: ");
    struct node *temp = head;
    
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to create a new node with given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to append a node at the start of the linked list
void append_start(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to append a node at the end of the linked list
void append_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to append a node at a specific position in the linked list
void append_position(struct node **head, int data, int pos) {
    if (pos == 1) {
        append_start(head, data);
        return;
    }
    struct node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position exceeds the length of the list. Appending at the end.\n");
        append_end(head, data);
    } else {
        struct node *new_node = create_node(data);
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int main() {
    int data, option, pos;
    struct node *head = NULL;
    
    while (1) {
        printf("\nEnter the data for node %d: ", head ? head->data + 1 : 1);
        scanf("%d", &data);
        
        printf("1. Starting\n2. End\n3. Position\nWhere to insert (1/2/3): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                append_start(&head, data);
                break;
            case 2:
                append_end(&head, data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                append_position(&head, data, pos);
                break;
            default:
                printf("Invalid option\n");
        }
        
        display(head);
    }
    
    return 0;
}

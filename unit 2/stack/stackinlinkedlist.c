#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* delete_at_beg(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

int main() {
    // Example usage
    struct node *head = NULL; // Initialize an empty list
    // Code to populate the list goes here

    // Deleting node from the beginning of the list
    head = delete_at_beg(head);

    // Code to print or use the updated list goes here

    return 0;
}

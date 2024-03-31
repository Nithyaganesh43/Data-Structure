#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void display(struct node *head) {
    printf("\nCurrent elements: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *create_node(int data) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

int append_start(struct node **headAddress, int data) {
    struct node *nn = create_node(data);
    if (nn == NULL)
        return 0;

    nn->next = *headAddress;
    *headAddress = nn;
    return 1;
}

int append_end(struct node **headAddress, int data) {
    struct node *nn = create_node(data);
    if (nn == NULL)
        return 0;

    if (*headAddress == NULL) {
        *headAddress = nn;
        return 1;
    }

    struct node *temp = *headAddress;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
    return 1;
}

int delete_first(struct node **headAddress) {
    if (*headAddress == NULL)
        return 0;

    struct node *temp = *headAddress;
    *headAddress = (*headAddress)->next;
    free(temp);
    return 1;
}

int delete_end(struct node **headAddress) {
    if (*headAddress == NULL)
        return 0;

    struct node *temp = *headAddress;
    struct node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    free(temp);
    return 1;
}

int delete_position(struct node **headAddress, int position) {
    if (*headAddress == NULL || position <= 0)
        return 0;

    struct node *temp = *headAddress;
    struct node *prev = NULL;

    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return 0;

    if (prev != NULL)
        prev->next = temp->next;
    else
        *headAddress = temp->next;

    free(temp);
    return 1;
}

int main() {
    int data, n;
    struct node *head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &data);
        printf("\n1. Start\n2. End\n\nWhere to insert (1/2): ");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                append_start(&head, data);
                break;
            case 2:
                append_end(&head, data);
                break;
            default:
                printf("Invalid option. Please choose 1 or 2.\n");
                i--; // Repeat this iteration
                continue;
        }
        display(head);
    }

    // Test delete functions
    printf("\nTesting delete functions:\n");
    printf("\nDeleted first node: %s\n", delete_first(&head) ? "Success" : "Failure");
    display(head);

    printf("\nDeleted last node: %s\n", delete_end(&head) ? "Success" : "Failure");
    display(head);

    int position;
    printf("\nEnter the position to delete: ");
    scanf("%d", &position);
    printf("Deleted node at position %d: %s\n", position, delete_position(&head, position) ? "Success" : "Failure");
    display(head);

    return 0;
}

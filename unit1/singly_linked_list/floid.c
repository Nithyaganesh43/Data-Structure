#include <stdio.h>
#include <stdlib.h>

// Definition for a linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect and remove cycle
// Detect cycle in linked list by using Floyd's cycle detection algorithm
void removeCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return;
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Detect cycle using Floyd's cycle detection algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet, there's a cycle
        if (slow == fast)
            break;
    }

    // If no cycle found, return
    if (slow != fast)
        return;

    // Move slow to head and advance both slow and fast at the same pace until they meet again
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    // Remove the cycle by setting the next of the node where the cycle starts to NULL
    fast->next = NULL;
}

// Function to print the linked list
// Print the linked list elements
void printList(struct ListNode *head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Helper function to create a new linked list node
// Create a new node with the given value
struct ListNode* newNode(int val) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = val;
    temp->next = NULL;
    return temp;
}

// Driver code
// Main function
int main() {
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; // Creating a cycle: 4->2

    printf("Original Linked List: 1 2 3 4 2 3 4 ....2 3 4 2 3 4\n");


    // Remove cycle if present
    // Call removeCycle function to remove cycle if exists
    removeCycle(head);

    printf("\nLinked List after removing cycle:\n");
   printList(head);

    return 0;
}

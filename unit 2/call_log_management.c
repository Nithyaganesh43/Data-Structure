#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLS 100

typedef struct {
    char caller_name[50];
    char caller_number[15];
    int duration_minutes;
} CallLogEntry;

typedef struct {
    CallLogEntry entries[MAX_CALLS];
    int front, rear;
} CallLogQueue;

void initQueue(CallLogQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(CallLogQueue *q) {
    return (q->front == -1);
}

int isQueueFull(CallLogQueue *q) {
    return ((q->rear + 1) % MAX_CALLS == q->front);
}

void enqueue(CallLogQueue *q, CallLogEntry entry) {
    if (!isQueueFull(q)) {
        if (isQueueEmpty(q))
            q->front = 0;
        q->rear = (q->rear + 1) % MAX_CALLS;
        q->entries[q->rear] = entry;
        printf("Call logged successfully.\n");
    } else {
        printf("Call log is full. Cannot add more calls.\n");
    }
}

CallLogEntry dequeue(CallLogQueue *q) {
    CallLogEntry entry;
    if (!isQueueEmpty(q)) {
        entry = q->entries[q->front];
        if (q->front == q->rear)
            initQueue(q);
        else
            q->front = (q->front + 1) % MAX_CALLS;
    } else {
        printf("Call log is empty.\n");
        strcpy(entry.caller_name, "");
        strcpy(entry.caller_number, "");
        entry.duration_minutes = 0;
    }
    return entry;
}

void displayCallLog(CallLogQueue *q) {
    if (!isQueueEmpty(q)) {
        printf("Call Log:\n");
        printf("Name\t\tNumber\t\tDuration (min)\n");
        int i = q->front;
        do {
            printf("%s\t\t%s\t\t%d\n", q->entries[i].caller_name, q->entries[i].caller_number, q->entries[i].duration_minutes);
            i = (i + 1) % MAX_CALLS;
        } while (i != (q->rear + 1) % MAX_CALLS);
    } else {
        printf("Call log is empty.\n");
    }
}

int main() {
    int choice;
    char name[50];
    char number[15];
    int duration;

    CallLogQueue call_queue;
    initQueue(&call_queue);

    do {
        printf("\n1. Add Call\n");
        printf("2. Process Call\n");
        printf("3. Display Call Log\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter caller's name: ");
                scanf("%s", name);
                printf("Enter caller's number: ");
                scanf("%s", number);
                printf("Enter call duration (minutes): ");
                scanf("%d", &duration);
                CallLogEntry new_entry;
                strcpy(new_entry.caller_name, name);
                strcpy(new_entry.caller_number, number);
                new_entry.duration_minutes = duration;
                enqueue(&call_queue, new_entry);
                break;
            case 2:
                if (!isQueueEmpty(&call_queue)) {
                    CallLogEntry processed_call = dequeue(&call_queue);
                    printf("Processed call:\n");
                    printf("Name: %s\n", processed_call.caller_name);
                    printf("Number: %s\n", processed_call.caller_number);
                    printf("Duration: %d\n", processed_call.duration_minutes);
                } else {
                    printf("Call log is empty.\n");
                }
                break;
            case 3:
                displayCallLog(&call_queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

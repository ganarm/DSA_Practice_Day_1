// Q.5 ha run krun bagha aadhi expected ans det he ka aas 

#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum number of tickets in the queue

int tickets[MAX];
int front = 0;
int rear = -1;
int count = 0;

int isFull() {
    return count == MAX;
}

int isEmpty() {
    return count == 0;
}

void submitTicket(int ticket) {
    if (isFull()) {
        printf("Queue is full. Cannot submit new ticket.\n");
        return;
    }
    rear = (rear + 1) % MAX;
    tickets[rear] = ticket;
    count++;
    printf("Ticket %d submitted successfully.\n", ticket);
}

void processTicket() {
    if (isEmpty()) {
        printf("Queue is empty. No tickets to process.\n");
        return;
    }
    printf("Processing ticket %d.\n", tickets[front]);
    front = (front + 1) % MAX;
    count--;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current queue status:\n");
    int i = front;
    for (int c = 0; c < count; c++) {
        printf("Ticket %d\n", tickets[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice, ticket;

    while (1) {
        printf("\n1. Submit Ticket\n2. Process Ticket\n3. Display Queue\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ticket number to submit: ");
                scanf("%d", &ticket);
                submitTicket(ticket);
                break;
            case 2:
                processTicket();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

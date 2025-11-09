#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

void enQueue(int element) {
    if (isFull())
        printf("\nQueue is full!! (Overflow)\n");
    else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d\n", element);
    }
}

int deQueue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty!! (Underflow)\n");
        return -1;
    } else {
        element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d\n", element);
        return element;
    }
}

void display() {
    int i;
    if (isEmpty())
        printf("\nEmpty Queue\n");
    else {
        printf("\nFront -> %d", front);
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE)
            printf("%d ", items[i]);
        printf("%d ", items[i]);
        printf("\nRear -> %d\n", rear);
    }
}

int main() {
    int choice, value;
    printf("\n--- Circular Queue Operations ---\n");

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            enQueue(value);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting...\n");
            return 0;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

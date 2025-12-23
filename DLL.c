#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lptr;
    struct node *rptr;
};

struct node *head = NULL;

void insertFront(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->lptr = NULL;
    newnode->rptr = head;

    if (head != NULL) {
        head->lptr = newnode;
    }
    head = newnode;
}

void insertRear(int val) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->rptr = NULL;

    if (head == NULL) {
        newnode->lptr = NULL;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->rptr != NULL) {
        temp = temp->rptr;
    }
    temp->rptr = newnode;
    newnode->lptr = temp;
}


void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = head->rptr;
    if (head != NULL) {
        head->lptr = NULL;
    }
    printf("Deleted from front: %d\n", temp->data);
    free(temp);
}


void deleteRear() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    while (temp->rptr != NULL) {
        temp = temp->rptr;
    }
    if (temp->lptr != NULL) {
        temp->lptr->rptr = NULL;
    } else {
        head = NULL; // only one node
    }
    printf("Deleted from rear: %d\n", temp->data);
    free(temp);
}


void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->rptr;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

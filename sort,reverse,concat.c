#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* insert(struct node *head, int value) {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL)
        return newnode;

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    return head;
}

void display(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


struct node* sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}


struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}


int main() {
    struct node *head1 = NULL, *head2 = NULL;
    int n, value, i;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    printf("\nEnter number of elements in List 2: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    printf("\nList 1:\n");
    display(head1);

    head1 = sort(head1);
    printf("\nSorted List 1:\n");
    display(head1);

    head1 = reverse(head1);
    printf("\nReversed List 1:\n");
    display(head1);

    head1 = concatenate(head1, head2);
    printf("\nAfter Concatenation:\n");
    display(head1);

    return 0;
}

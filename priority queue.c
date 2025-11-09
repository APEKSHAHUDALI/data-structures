

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert_by_priority(int data);
void delete_by_priority(int data);
void create();
void check(int data);
void display_pqueue();

int pri_que[MAX];
int front, rear;


void create()
{
    front = rear = -1;
}

void insert_by_priority(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow! No more elements can be inserted.");
        return;
    }

    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
    {
        check(data);
    }
    rear++;
}

void check(int data)
{
    int i, j;

    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void delete_by_priority(int data)
{
    int i;

    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty! No elements to delete.");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
            pri_que[i] = -99;
            rear--;

            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("\n%d not found in queue to delete.", data);
}

void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nPriority Queue elements are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", pri_que[i]);
    }
    printf("\n");
}

int main()
{
    int n, ch;

    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - Display queue elements");
    printf("\n4 - Exit");

    create();

    while (1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted: ");
            scanf("%d", &n);
            insert_by_priority(n);
            break;

        case 2:
            printf("\nEnter value to delete: ");
            scanf("%d", &n);
            delete_by_priority(n);
            break;

        case 3:
            display_pqueue();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}

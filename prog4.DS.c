#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int a[MAX];
int rear=-1,front=-1;
void insert()
{
    int item;
    if (rear==MAX-1)
    {
        printf("Queue Overflow");
    }
    else
    {
        if (front==-1)
            front=0;
        printf("Insert the element in queue:");
        scanf("%d",&item);
        rear=rear+1;
        a[rear]=item;
    }
}
void delete()
{
    if (front==-1 || front>rear)
    {
        printf("Underflow");
    }
    else
    {
        printf("Deleted:%d\n",a[front]);
        front+=1;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is:");
        for(i=front;i<=rear;i++)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("1,insert, 2.delete, 3.display, 4.exit\n");
        printf("enter a choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("invalid choice\n");
        }
    }
}



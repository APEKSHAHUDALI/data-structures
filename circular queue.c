#include<stdio.h>
#define SIZE 5
int item[SIZE];
int front=-1,rear=-1;
 int isFull()
 {
    if((front==rear+1) || (front==0 && rear==SIZE-1))
    {
        return 1;
    }
    return 0;
 }

 int (isEmpty())
 {
    if(front==-1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int element)
{
    if(isFull())
    {
        printf("\n Queue is full!\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        rear=(rear+1)%SIZE;
        item[rear]=element;
        printf("\n inserted -> %d\n",element);
    }
}

int dequeue()
{
    int element;
    if(isEmpty())
    {
        printf("\n Queue is empty\n");
        return(-1);
    }
    else
    {
        front=(front+1)%SIZE;
    }
    printf("\n Deleted element -> %d\n",element);
    return(element);
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("\n Front->%d",front);
        printf("\n Items->");
        for(i=front;i!=rear; i=(i+1)%SIZE)
        {
            printf("%d",item[i]);
        }
        printf("%d",item[i]);
        printf("\n Rear->%d\n",rear);
    }
}

 int main()
 {

     int ch,value;
     printf("\n circular queue operation\n");
     while(1){
        printf("\n 1.insert  2.delete   3.display   4.exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enetr value to insert:");
                   scanf("%d",&value);
                   enqueue(value);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:printf("\n exiting\n");
                   return 0;

            default:printf("\n Invalid choice\n");
        }
     }
     return 0;
 }





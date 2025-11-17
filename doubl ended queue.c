#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define size 10
int q[size];
int rear=0,front=0;

void enqueueRear()
{
int val;
char ch;
if(front==size/2)
{

    printf("\nqueue is full");
    return;
}
do
{
    printf("\nEnter the value to be inserted:");
    scanf("%d",&val);
    q[front]=val;
    front++;
    printf("Do you want to continue insertion Y/N: ");
    ch=getch();
}while(ch=='y' || ch=='Y');


}
void enqueueFront()
{

    int val;
    char ch;
    if(front==size/2)
    {
        printf("\nQueue is full");
        return;
    }
    do
    {
        printf("\nEnter the value to be inserted:");
        scanf("%d",&val);
        rear--;
        q[rear]=val;
        printf("Do you want to continue insertion Y/N:");
        ch=getch();
    }while(ch=='y'|| ch=='Y');
    }

int dequeueRear()
{

    int deleted;
    if(front==rear){
        printf("\nQueue is empty");
        return 0;
    }
    front--;
    deleted=q[front];
    return deleted;
}
int dequeueFront()
{

    int deleted;
    if(front==rear)
    {

        printf("\nQueue is empty\n");
        return 0;

    }
    deleted=q[rear];
    rear++;
    return deleted;

}
void display()
{

    int i;
    if(front==rear)
    {

        printf("\nQueue is Empty");

    }
    else{
        printf("\nThe queue elements are:");
        for(i=rear;i<front;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}
int main()
{
    char ch;
    int ch1,ch2,val;
    printf("\n-----Type of Double Ended Queue-----\n");
    do
    {

        printf("\n1.Input-restricted deque\n");
        printf("2.Output-restricted deque\n");
        printf("\nEnter your choice of Queue Type: ");
        scanf("%d",&ch1);
        switch(ch1)
        {

            case 1:printf("\n--select the operation---\n");
            printf("\n1.Insert\n2.Delete from rear\n3de.delete from front\n4.Display\n");
            do{
                printf("\nenter your choice for theoperation in input-restricted deque:");
                scanf("%d",&ch2);
                switch(ch2)
                {

                case 1:
                    enqueueRear();
                    display();
                    break;
                case 2:
                    val=dequeueRear();
                    printf("\nThe value deleted is %d ",val);
                    display();
                    break;
                case 3:
                    val=dequeueFront();
                    printf("\nThe value deleted is %d",val);
                    display();
                    break;
                case 4:
                    display();
                    break;
                    default:printf("Wrong choice");

                }
                printf("\nDo you want to perform another operation(Y/N): ");
                scanf("%c",&ch);

            }while(ch=='y' || ch=='Y');
            break;
                case 2:
                    printf("\nSelect the operation\n");
                    printf("\n1.Insert at Rear\n2.Insert at Front\n3.Delete\n4.Display\n");
                    do
                    {
                        printf("\nEnter your choice for the operation: ");
                        scanf("%d",&ch2);
                        switch(ch2)
                        {

                            case 1:enqueueRear();
                            display();
                            break;
                            case 2:enqueueFront();
                            display();
                            break;
                            case 3:val=dequeueFront();
                            printf("\nThe value deleted is %d",val);
                            display();
                            break;
                            case 4:display();
                            break;
                            default:printf("wrong choice");
                        }
                        printf("\nDo you want to perform another operation (Y/N):");
                        ch=getch();
                    }while(ch=='y'||ch=="Y");
                    getch();
                    break;
        }
        printf("\n Do you want to continue(Y/N);");
        ch=getch();

    }while(ch=='y'||ch=='Y');

}

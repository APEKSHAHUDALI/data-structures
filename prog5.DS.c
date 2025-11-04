#include<stdio.h>
void towers(int n,char frompeg,char topeg,char auxpeg);

int main()
{
    int n;
    printf("Enter no. of disks\n");
    scanf("%d",&n);
    printf("\nThe seq of moves:\n");
    towers(n,'A','c','B');
    return 0;
}
void towers(int n,char frompeg,char topeg,char auxpeg)
{
    if(n==1)
    {
        printf("\n move disk 1 from %c to %c\n",frompeg,topeg);
        return;
    }
    towers(n-1,frompeg,auxpeg,topeg);
    printf("\nMove disk from %c to %c\n ",n,frompeg,topeg);
    towers(n-1,auxpeg,topeg,frompeg);
}

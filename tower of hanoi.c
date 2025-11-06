#include <stdio.h>

void towers(int num, char fromPeg, char toPeg, char auxPeg);

int main()
{
    int num;

    printf("Enter the number of disks: ");
    scanf("%d", &num);

    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towers(num, 'A', 'C', 'B');  // Move disks from A to C using B as helper

    return 0;
}

void towers(int num, char fromPeg, char toPeg, char auxPeg)
{
    if (num == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c", fromPeg, toPeg);
        return;
    }
    towers(num - 1, fromPeg, auxPeg, toPeg);
    printf("\nMove disk %d from peg %c to peg %c", num, fromPeg, toPeg);
    towers(num - 1, auxPeg, toPeg, fromPeg);
}

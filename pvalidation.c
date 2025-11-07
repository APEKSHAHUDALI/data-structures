#include<stdio.h>
#include<string.h>
int pValidation(char str[]){
    int i,top=-1;
    char s[20];
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='('|| str[i]=='['|| str[i]=='{')
            s[++top]=str[i];
        else if(str[i]==')' &&s[top]=='(')
            top--;
        else if(str[i]=='}' &&s[top]=='{')
            top--;
        else
            return 0;
    }
    if(top==-1)
        return 1;
    return 0;
    }
void main()
{
    char str[20];
    printf("\n enter a seq of paranthesis:");
    scanf("%s",str);
    if(pValidation(str))
        printf("\n Paranthesis sucessfully validated");
    else
        printf("\n invalid parenthesis sequence");
}


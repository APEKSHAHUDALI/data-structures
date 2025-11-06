#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void pushChar(char item);
char popChar();
int isFull();
int isEmpty();

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    for (i = 0; i < strlen(str); i++) {
        pushChar(str[i]);
    }

    for (i = 0; i < strlen(str); i++) {
        str[i] = popChar();
    }

    printf("Reversed String: %s\n", str);

    return 0;
}

void pushChar(char item) {
    if (isFull()) {
        printf("Stack is FULL! Cannot push '%c'\n", item);
        return;
    }
    top++;
    stack[top] = item;
}

char popChar() {
    if (isEmpty()) {
        printf("Stack is EMPTY!\n");
        return '\0';
    }
    char item = stack[top];
    top--;
    return item;
}

int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

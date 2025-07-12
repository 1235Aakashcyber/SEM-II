// This program converts the infix equation to postfix form using stacks

#include <stdio.h>
#include <ctype.h> //To use isalnum function
#define max 20

int top = -1;
char stack[max];

void push(char value);
char pop();
int priority(char input);
int isoperator(char c);

int main() {
    char input[50];
    char out;
    printf("Enter the equation: ");
    fgets(input, 50, stdin);
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            printf("%c", input[i]);
        } else if (input[i] == '(') {
            push(input[i]);
        } else if (input[i] == ')') {
            while ((out = pop()) != '(') {
                printf("%c", out);
            }
        } else if (isoperator(input[i])) {
            while (top != -1 && priority(stack[top]) >= priority(input[i])) {
                printf("%c", pop());
            }
            push(input[i]);
        }
    }
    while (top != -1) {
        printf("%c", pop());
    }
    return 0;
}

//push definition
void push(char value) {
    if (top == (max - 1)) {
        printf("Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

//pop definition
char pop() {
    if (top == -1) {
        printf("Underflow\n");
        return '\0';
    }
    return stack[top--];
}

//priority definition
int priority(char input) {
    if (input == '(' || input == ')') {
        return 0;
    }
    if (input == '+' || input == '-') {
        return 1;
    }
    if (input == '*' || input == '/' || input == '%') {
        return 2;
    }
    return -1; // For invalid characters
}

//isoperator definition
int isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

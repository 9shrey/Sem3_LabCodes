#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack data structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to return the top element of the stack without popping it
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top];
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to determine the precedence of an operator
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    i = j = 0;

    int length = strlen(infix);

    // Reverse the infix expression
    for (i = length - 1; i >= 0; i--) {
        char token = infix[i];

        if (token >= '0' && token <= '9') {
            prefix[j++] = token;
        } else if (token == ')') {
            push(&stack, token);
        } else if (token == '(') {
            while (!isEmpty(&stack) && peek(&stack) != ')') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the ')'
        } else if (isOperator(token)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(token)) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
    }

    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    // Reverse the prefix expression to get the final result
    prefix[j] = '\0';
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}

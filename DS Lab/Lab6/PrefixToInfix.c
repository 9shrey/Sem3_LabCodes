#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
    int top;
    char items[MAX_SIZE];
};
void initialize(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, char item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top];
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack stack;
    initialize(&stack);
    int i, j;
    i = j = 0;
    int length = strlen(infix);
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
            pop(&stack);
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
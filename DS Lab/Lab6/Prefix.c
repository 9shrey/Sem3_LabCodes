#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "prefix.h"

int evaluate(char x, int op1, int op2) {
    if (x == '+')
        return (op1 + op2);
    if (x == '-')
        return (op1 - op2);
    if (x == '*')
        return (op1 * op2);
    if (x == '/')
        return (op1 / op2);
    if (x == '%')
        return (op1 % op2);
}

void init(stack *s) {
    s->top = -1;
}

int empty(stack *s) {
    if (s->top == -1)
        return (1);
    return (0);
}

int full(stack *s) {
    if (s->top == MAX - 1)
        return (1);
    return (0);
}

void push(stack *s, int x) {
    s->top = s->top + 1;
    s->data[s->top] = x;
}

int pop(stack *s) {
    int x;
    x = s->data[s->top];
    s->top = s->top - 1;
    return (x);
}

int main() {
    stack s;
    char x;
    int op1, op2, val;
    init(&s);
    printf("Enter the expression (e.g., + * + 5 9 / 3 7): ");

    char A[100];
    int k = 0;
    while ((x = getchar()) != '\n') {
        if (!isspace(x)) {
            A[k] = x;
            k++;
        }
    }
    A[k] = '\0';

    int i = 0; // Read the expression from left to right
    while (A[i] != '\0') {
        if (isdigit(A[i]) || (A[i] == '-' && isdigit(A[i + 1]))) {
            int operand = 0;
            int negative = 1;

            if (A[i] == '-') {
                negative = -1;
                i++;
            }

            while (A[i] != ' ' && A[i] != '\0') {
                operand = operand * 10 + (A[i] - '0');
                i++;
            }
            push(&s, operand * negative);
        } else if (A[i] != ' ') {
            op1 = pop(&s);
            op2 = pop(&s);
            val = evaluate(A[i], op1, op2);
            push(&s, val);
            i++;
        } else {
            i++;
        }
    }

    val = pop(&s);
    printf("\nValue of expression = %d\n", val);
    return 0;
}

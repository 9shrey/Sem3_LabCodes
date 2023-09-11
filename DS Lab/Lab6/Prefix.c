#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "prefix.h"

int main() {
    stack s;
    char x;
    int op1, op2, val;
    init(&s);
    printf("Enter the expression (e.g., +*+59/3 7): ");
    
    char A[100];
    int k = 0;
    while ((x = getchar()) != '\n') {
        if (!isspace(x)) {
            A[k] = x;
            k++;
        }
    }
    A[k] = '\0';
    
    int i = strlen(A) - 1;
    while (i >= 0) {
        if (isdigit(A[i])) {
            int operand = 0;
            while (i >= 0 && isdigit(A[i])) {
                operand = operand * 10 + (A[i] - '0');
                i--;
            }
            push(&s, operand);
        } else if (A[i] != ' ') {
            op1 = pop(&s);
            op2 = pop(&s);
            val = evaluate(A[i], op1, op2);
            push(&s, val);
        } else {
            i--;
        }
    }

    val = pop(&s);
    printf("\nValue of expression = %d\n", val);
    return 0;
}

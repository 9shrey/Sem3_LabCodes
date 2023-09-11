// prefix.h

#ifndef PREFIX_H
#define PREFIX_H

#define MAX 20

typedef struct {
    int data[MAX];
    int top;
} stack;

void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *, int);
int evaluate(char x, int op1, int op2);

#endif  // PREFIX_H

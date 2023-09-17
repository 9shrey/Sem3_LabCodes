#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_LENGTH 100

typedef struct stack{
    char a[MAX_LENGTH];
    int top;
} stack;

bool isEmpty(stack *s){
    if(s->top==-1) return true;
    else return false;
}

void push(stack *s, char x){
    s->top++;
    s->a[s->top]=x;
}

char pop(stack *s){
    return s->a[s->top--];
}

bool isOperand(char x){
    if(x>='0' && x<='9' || x>='a' && x<='z' || x>='A' && x<='Z'){
        return true;
    }
    else return false;
}

bool isOperator(char x){
    if(x=='^' || x=='/' || x=='*' || x=='+' || x=='-'){
        return true;
    }
    else return false;
}

int precedence(char x){
    if(x=='^') return 3;
    else if(x=='/' || x=='*') return 2;
    else if(x=='+' || x=='-') return 1;
    else return -1;
}

void infixToPostfix(stack *s, char exp[MAX_LENGTH]){
    for(int i=0; i<strlen(exp); i++){

        if(isOperand(exp[i])){
            printf("%c", exp[i]);
        }

        else if(exp[i]=='(') push(s, exp[i]);

        else if(exp[i]==')'){
            while(!isEmpty(s) && s->a[s->top] != '(') printf("%c", pop(s));
            if(!isEmpty(s)) pop(s);
        }
        
    else{
        while(!isEmpty(s) && precedence(s->a[s->top])>=precedence(exp[i])){
            printf("%c", pop(s));
        }
        push(s, exp[i]);
    }

    }
    while(s->top>0){
        printf("%c", pop(s));
    }
}

int main(){
    stack *s = malloc(sizeof(stack));
    printf("Enter Infix expression: ");
    char exp[MAX_LENGTH];
    scanf(" %s", exp);
    printf("Postfix converted expression: ");
    infixToPostfix(s, exp);
    return 0;
}
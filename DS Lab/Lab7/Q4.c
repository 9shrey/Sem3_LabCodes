#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 3

typedef struct stack {
    int a[MAX];
    int top;
} stack;

bool isFull(stack *s){
    return (s->top==MAX-1);
}

void push(stack *s, int element){
    s->a[++s->top]=element;
}

int pop(stack *s){
    return s->a[s->top--];
}

int main(){
    stack *s1 = (stack*)malloc(sizeof(stack));
    stack *s2 = (stack*)malloc(sizeof(stack));
    s1->top=s2->top=-1;

    while (true){
        printf("\n1. Enqueue \n2. Dequeue \n3. Exit \nChoice: ");
        int choice;
        scanf("%d", &choice);

        if(choice==1){
            if(!isFull(s1)){
                printf("Enter element: ");
                int element;
                scanf("%d", &element);
                s1->a[++s1->top]=element;

                for(int i=0; i<=s1->top; i++){
                    printf("%d ", s1->a[i]);
                }
                printf("\n");
            }

            else{
                printf("\nStack Overflow!!\n");
            }
        }

        else if(choice==2){

            if(s2->top==-1){
                while(s1->top!=-1){
                    push(s2, pop(s1));
                }
            }
            if(s2->top!=-1){
                printf("\nDequeued %d\n", pop(s2));
            }

            else{
                printf("\nStack Underflow!!\n");
            }
        }

        else if(choice==3){
            break;
        }

        else break;
    }
}
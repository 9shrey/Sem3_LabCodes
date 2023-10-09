#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 3
typedef struct queue{
    int front;
    int rear;
    char a[MAX];
} queue;

bool isFull(queue *q){
    return ((q->front)%MAX==(q->rear+1)%MAX || ((q->rear)==MAX-1 && q->front==0));
}

bool isEmpty(queue *q){
    return ((q->front==-1));
}

void insertcq(queue *q, char element){
    if(q->front==-1) q->front=0;
    q->a[(++q->rear)%MAX]=element;
}

char deletecq(queue *q){
    char c;
    c=q->a[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front=q->front+1;
    }
    return c;

}

void display(queue *q){
    if(isEmpty(q)) return;
    int i=0;
    printf("\n");
    for(i=((q->front)); i!=((q->rear)); i=(i+1)%MAX){
        printf("%c " ,q->a[i]);
    }
    printf("%c " ,q->a[q->rear]);
    printf("\n");
}

int main(){
    queue *q = (queue*)malloc(sizeof(queue));
    q->front=q->rear=-1;
    while(true){
        printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \nChoice: ");
        int choice;
        scanf("%d", &choice);
        if(choice==1){
            if(!isFull(q)){
                printf("Enter element: ");
                char element;
                scanf(" %c", &element);
                insertcq(q, element);
            }
            else printf("\nQueue full!!\n");
        }
        else if(choice==2){
            if(!isEmpty(q)){
                printf("\nDeleted %c from the queue\n", deletecq(q));
            }
            else printf("\nQueue Emnpty!!\n");
        }
        else if(choice==3){
            if(!isEmpty(q)) display(q);
            else printf("Queue Empty!!\n");
        }
        else if(choice==4){
            break;
        }
        else printf("\nInvalid choice!!\n");
    }
    free(q);
    return 0;
}
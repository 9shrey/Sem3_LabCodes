#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void insert(node **head){
    printf("Enter element: ");
    int element;
    scanf("%d", &element);
    if(!*head){
        *head=(node*)(malloc(sizeof(node)));
        (*head)->data=element;
        (*head)->next=NULL;
    }
    else{
        node *temp=(node*)malloc(sizeof(node));
        temp->data=element;
        node *p = *head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->next=NULL;
    }
}

int delete(node **head){
    node *p=*head;
    *head=p->next;
    int element = p->data;
    free(p);
    return element;
}

void display(node *p){
    printf("\nQueue: ");
    do{
        printf("%d --> ", p->data);
        p=p->next;
    } while (p!=NULL);
    printf("/");
    
}

int main(){
    node *head = NULL;
    printf("1. Insert \n2. Delete \n3. Display \n4. Exit");
    while(true){
        printf("\nChoice: ");
        int choice;
        scanf("%d", &choice);
        if(choice==1){
            insert(&head);
        }

        else if(choice==2){
            if (head==NULL){
                printf("\nQueue Empty!!\n");
                continue;
            }
            printf("\nDeleted %d\n", delete(&head));
        }

        else if(choice==3){
            if (head==NULL){
                printf("\nQueue Empty!!\n");
                continue;
            }
            display(head);
        }

        else if(choice==4){
            break;
        }

        else printf("\nEnter a valid choice!!\n");
    }
}

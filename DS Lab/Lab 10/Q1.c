#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	int data;
	struct node *rlink;
	struct node *llink;
} node;

void insertLeft(node **head){
	printf("Enter element: ");
	int element;
	scanf("%d", &element);

	if(*head==NULL){
		*head=(node*)(malloc(sizeof(node)));
		(*head)->llink=NULL;
		(*head)->rlink=NULL;
		(*head)->data=element;
		return;
	}

	node *p=*head;

	node *temp=(node*)malloc(sizeof(node));
	temp->data=element;
	p->llink=temp;
	temp->rlink=p;
	temp->llink=NULL;
	(*head)=temp;
}

void insertRight(node **head){
	printf("Enter element: ");
	int element;
	scanf("%d", &element);

	if(*head==NULL){
		*head=(node*)(malloc(sizeof(node)));
		(*head)->llink=NULL;
		(*head)->rlink=NULL;
		(*head)->data=element;
		return;
	}

	node *p=*head;
	while(p->rlink!=NULL){
		p=p->rlink;
	}

	node *temp=(node*)malloc(sizeof(node));
	temp->data=element;
	p->rlink=temp;
	temp->llink=p;
	temp->rlink=NULL;
}

int deleteLeft(node **head){
	node *temp=*head;
	int i;
	if((*head)->rlink==NULL){
		i = (*head)->data;
		free(*head);
		return i;
	}

	i=(temp)->data;
	*head=(*head)->rlink;
	(*head)->llink=NULL;
	free(temp);
	return i;
}

int deleteRight(node **head){
	node *p=*head;
	int i;
	if((*head)->rlink==NULL){
		i = (*head)->data;
		free(*head);
		return i;
	}

	while(p->rlink!=NULL){
		p=p->rlink;
	}

	node *temp=p->llink;
	i = p->data;
	temp->rlink=NULL;
	free(p);
	return i;
}

void display(node **head){

	if(*head==NULL){
		printf("Empty List!!");
		return;
	}

	node *p=*head;
	while(p!=NULL){
		printf("%d ", p->data);
		p=p->rlink;
	}
	printf("\n");
}

int main(){
	node *head=NULL;
	printf("\n1. Insert Left \n2. Insert Right \n3. Delete Left \n4. Delete Right \n5. Disply \n6. Exit\n");

	while(true){
		printf("\nChoice: ");
		int choice;
		scanf("%d", &choice);

		if(choice==1){
			insertLeft(&head);
		}

		else if(choice==2){
			insertRight(&head);
		}

		else if(choice==3){
			printf("Deleted %d\n", deleteLeft(&head));
		}

		else if(choice==4){
			printf("Deleted %d\n", deleteRight(&head));
		}

		else if(choice==5){
			display(&head);
		}

		else if(choice==6){
			break;
		}

		else printf("Enter valid choice!!\n");
	}

	return 0;
}
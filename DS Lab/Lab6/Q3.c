#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 3

typedef struct stack{
	int topL;
	int topR;
	int a[MAX_SIZE];
} stack;

bool isFull(stack *s){
	if(s->topL+1==s->topR || s->topR-1==s->topL || s->topL==MAX_SIZE-1 || s->topR==0){
		return true;
	}
	else return false;
}

bool isEmptyLeft(stack *s){
	if(s->topL==-1){
		return true;
	}
	else return false;
}

bool isEmptyRight(stack *s){
	if(s->topR==MAX_SIZE){
		return true;
	}
	else return false;
}

void pushLeft(stack *s){
	printf("enter element: ");
	int element;
	scanf("%d", &element);
	s->topL+=1;
	s->a[s->topL]=element;
}

void pushRight(stack *s){
	printf("enter element: ");
	int element;
	scanf("%d", &element);
	s->topR-=1;
	s->a[s->topR]=element;
}

void popLeft(stack *s){
	printf("Popped %d\n", s->topL);
	s->a[s->topL]=0;
	s->topL--;
}

void popRight(stack *s){
	printf("Popped %d\n", s->topR);
	s->a[s->topR]=0;
	s->topR++;
}

void displayLeft(stack *s){
	printf("displaying left stack\n");
	for(int i=0; i<=s->topL; i++){
		printf("%d ", s->a[i]);
	}
	printf("\n");
}

void displayRight(stack *s){
	printf("displaying right stack\n");
	for(int i=MAX_SIZE-1; i>=s->topR; i--){
		printf("%d ", s->a[i]);
	}
	printf("\n");
}

int main(){
	stack *s = malloc(sizeof(stack));
	s->topL=-1;
	s->topR=MAX_SIZE;
	while(true){
		printf("\n1. Push left\n");
		printf("2. Push right\n");
		printf("3. Pop left\n");
		printf("4. Pop right\n");
		printf("5. Display left\n");
		printf("6. Dispay right\n");
		printf("7. Exit\n");
		printf("Enter option: ");
		int choice;
		scanf("%d", &choice);

		if(choice==1){
			if(!isFull(s)){
				pushLeft(s);
			}
			else printf("Stack overflow!!\n");
		}
		else if (choice==2){
			if(!isFull(s)){
				pushRight(s);
			}
			else printf("Stack overflow!!\n");
		}
		else if(choice==3){
			if(!isEmptyLeft(s)){
				popLeft(s);
			}
			else printf("stack underflow!!\n");
		}
		else if(choice==4){
			if(!isEmptyRight(s)){
				popRight(s);
			}
			else printf("stack underflow!!\n");
		}
		else if(choice==5){
			displayLeft(s);
		}
		else if(choice==6){
			displayRight(s);
		}
		else if(choice==7){
			break;
		}
		else printf("Select a valid option!!\n");
	}

	free(s);
	return 0;
}
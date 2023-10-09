#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 5

typedef struct queue{
	int frontL, rearL, frontR, rearR;
	int lMax, rMax;
	int a[MAX_SIZE];
} queue;

bool isFullLeft(queue *q){
	return((q->rearL+1)%(q->lMax)==(q->frontL) || (q->rearL==q->lMax && q->frontL==0));
}

bool isEmptyLeft(queue *q){
	return (q->rearL==-1);
}

bool isFullRight(queue *q){
	return((q->rearR+1)%(q->rMax)==(q->frontR) || (q->rearR==MAX_SIZE && q->frontR==q->lMax));
}

bool isEmptyRight(queue *q){
	return (q->rearR==q->rMax);
}

void insertLeft(queue *q, int element){
	if(q->frontL==-1) q->frontL=0;
	q->a[++q->rearL]=element;
}

void insertRight(queue *q, int element){
	if(q->frontR==q->lMax-1) q->frontR++;
	q->rearR++;
	q->a[q->rearR]=element;
}

int deleteLeft(queue *q){
	int i;
	i=q->a[q->frontL];
	if(q->frontL==q->rearL){
		q->frontL=q->rearL=-1;
	}
	else{
		q->frontL++;
	}
	return i;
}

int deleteRight(queue *q){
	int i;
	i=q->a[q->frontR];
	if(q->frontR==q->rearR){
		q->frontR=q->rearR=-1;
	}
	else{
		q->frontR++;
	}
	return i;
}

void displayLeft(queue *q){
	for(int i=q->frontL; i<=q->rearL; i++){
		printf("%d ", q->a[i]);
	}
	printf("\n");
}

void displayRight(queue *q){
	for(int i=q->frontR; i<=q->rearR; i++){
		printf("%d ", q->a[i]);
	}
	printf("\n");
}

int main(){
	queue *q = (queue*)malloc(sizeof(queue));

	q->lMax = MAX_SIZE%2!=0 ? MAX_SIZE/2 : MAX_SIZE/2; //2
	q->rMax = MAX_SIZE%2!=0 ? MAX_SIZE/2+1 : MAX_SIZE/2; //3

	q->rearL=-1; q->frontL=-1; q->rearR=q->lMax-1; q->frontR=q->lMax-1;

	while(true){
		printf("\n1. Insert Left \n2. Delete Left \n3. Display Left \n4. Insert Right \n5. Delete Right \n6. Display Right \n7. Exit \nEnter Choice: ");
		int choice;
		scanf("%d", &choice);


		if(choice==1){
			if(isFullLeft(q)==false){
				int element;
				printf("Enter element: ");
				scanf("%d", &element);

				insertLeft(q, element);
			}
			else printf("\nLeft Queue Full!!\n");
		}

		else if(choice==2){
			if(isEmptyLeft(q)==false){
				printf("Deleted %d\n", deleteLeft(q));

			}
			else printf("\nLeft Queue is Empty!!\n");		
		}

		else if(choice==3){
			displayLeft(q);
		}

		else if(choice==4){
			if(isFullRight(q)==false){
				int element;
				printf("Enter element: ");
				scanf("%d", &element);

				insertRight(q, element);
			}
			else printf("\nRight Queue Full!!\n");
		}

		else if(choice==5){
			if(isEmptyRight(q)==false){
				printf("Deleted %d\n", deleteRight(q));

			}	
			else printf("\nRight Queue is Empty!!\n");
		}
		
		else if(choice==6){
			displayRight(q);
		}

		else if(choice==7){
			break;
		}

		else{
			printf("\nPlease select a valid option!!\n");
		}
	}

	free(q);
	return 0;
}
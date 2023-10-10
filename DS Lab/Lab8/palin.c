#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
	char a[50];
	int front;
	int rear;
	int front1;
	int n;
}queue;
bool isfull(queue *q){
	if((q->rear+1)%q->n==q->front){
		return true;
	}
	else{
		return false;
	}
}
bool isempty(queue *q){
	if(q->front1==1){
		return true;
	}
	else{
		return false;
	}
}
void insert(queue *q,char ele){
	if(!isfull(q)){
		q->rear=(q->rear+1)%q->n;
		q->a[q->rear]=ele;
	}
	else{
		printf("Queue full\n");
	}
}
char delete(queue *q){
	if(!isempty(q)){
		q->front1=(q->front1-1+q->n)%q->n;
		return q->a[q->front1];
	}
	else{
		printf("Queue Empty\n");
		return '\0';
	}
}
int main(){
	int count=1;
	queue *q=malloc(sizeof(queue));
	q->rear=0;q->front=0;q->front1=0;
	printf("enter string length + 1\n");
	scanf("%d",&q->n);
	printf("enter string\n");
	char str[50];
	scanf("%s",str);
	for(int i=0;i<q->n-1;i++){
		insert(q,str[i]);
	}
	for(int i=1;i<=q->n-1;i++){
		if(q->a[i]!=delete(q)){
			count=0;
			break;
		}
	}
	if(count==1){
		printf("palindrome\n");
	}	
	else{
		printf("not a palindrome\n");
	}
	return 0;
}
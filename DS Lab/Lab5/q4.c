#include <stdio.h>
# define MAX 20
# define true 1
# define false 0
/* Structure definition */
typedef struct{
	char item[MAX]; int top;
}stack;
#include <stdio.h>
void push(stack *ps,int x);
int pop(stack *ps);
int isempty(stack *ps);
void display(stack *ps);

void main(){
	stack stack;
    int arr[100];
    printf("Enter the number of elements");
    int n;
    scanf("%d", &n);
    for(int i =0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int k;
    printf("input k");
    scanf("%d",&k);
	int i=1;
	push(&stack,arr[0]);
    while(i<n){
		if(arr[i]>((&stack)->item[(&stack)->top])&&k>0){
			pop(&stack);
			k--;
		}else{
			push(&stack,arr[i]);
			i++;
		}

	}

	display(&stack);
}

void push(stack *ps,int x){
	if (ps->top!=MAX-1){
		ps->top++;
		ps->item[ps->top]=x;
	}
}


int pop(stack *ps){
	if(!isempty(ps))
		return(ps->item[ps->top--]);
}


int isempty(stack *ps){
	if (ps->top==-1)
		return(true);
	else
		return(false);
}
void display(stack *ps){
	printf("The stack is \n");
	stack *proto = ps;
	int arr[100];
	int i=0;
	while(!isempty(proto)){
		arr[i] = pop(proto);
		//printf("%d ",pop(proto));
		i++;
	}
	for(int j=i-2;j>=0;j--){
		printf("%d \t",arr[j]);
	}

}

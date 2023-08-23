#include <stdio.h>
#include <stdlib.h>
int Smallest(int *p,int n){
int min=p[0];
for(int i=1;i<n;i++){
	if(p[i]<min)
		min=p[i];
}
return min;
}
void main()
{
int i,*p,n;
printf("Enter size of array: ");
scanf("%d", &n);
p=(int*)calloc((n+1),sizeof(int)); //Dynamic Memory Allocation
printf("Enter the elements: ");
for(i=0;i<n;i++){
scanf("%d", &p[i]);}
int min=Smallest(p,n);
printf("Smallest value is %d\n", min);
}

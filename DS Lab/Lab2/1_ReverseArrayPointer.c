#include <stdio.h>
#include <stdlib.h>
void Rev(int *a,int l){
for(int i=0;i<l/2;i++)
{ int b;
b=*(a+i);
*(a+i)=*(a+l-i-1);
*(a+l-i-1)=b;
}
}
int main()
{
int i,n,a[20];
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter elements: ");
for(i=0;i<n;i++){
scanf("%d", &a[i]);}
Rev(a,n); //Passing pointer to a function (Lab2 Q3a)
printf("The reversed array is:\n");
for(int i=0;i<n;i++){
printf("%d\n",a[i])}
}

#include <stdio.h>
int* Largest(int *p,int *q){
if(*p>*q)
return p; //Returning Pointer From Function (Lab2 Q3b)
else
return q; //Returning Pointer From Function (Lab2 Q3b)
}
void main()
{
int a,b,*p,*q,*largest,**answer;
p=&a;
q=&b;
printf("Enter two numbers: ");
scanf("%d %d",p,q);
largest=Largest(p,q);
answer=&largest; //Using Pointer to Pointer (Lab2 Q3c)
printf("The largest numeber is: %d\n",**answer);
}

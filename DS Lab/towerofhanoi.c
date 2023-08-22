#include<stdio.h>
 int count=0;
void towerofhanoi(int n, char source, char destination, char auxiliary){

	
if(n==1)
{printf("disk number %d moved from %c to %c\n", n, source, destination);
count++;
return;}
if(n>1)
{
	towerofhanoi(n-1,source, auxiliary,destination);
	printf("disk number %d moved from %c to %c\n", n, source, destination);
	count++;
	towerofhanoi(n-1, auxiliary, destination, source);
	

}


}

void main()
{
	int n;char a,b,c;
	printf("enter disk number:\n");
	scanf("%d",&n);

	a='X';
	b='Y';
	c='Z';


	towerofhanoi(n,a,c,b);
	printf("Number of moves:%d\n",count);

}

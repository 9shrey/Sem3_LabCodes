#include<stdio.h>
#include<string.h>

int palin(char str1[],int lowindex,int highindex)
{
  if(lowindex>=highindex)
  {
  	return 1;
  }
  else{
  	if(str1[lowindex]== str1[highindex])
  	palin(str1, lowindex+1,highindex-1);

  }
}



void main()
{
	char a[100]; int n,m;


	printf("Enter your string:\n");
	scanf("%s",a);


	m=palin(a,0,strlen(a)-1);
	
if (m==1)
{
	printf("string is palindrome!\n");
}
else{
	printf("string is NOT palindrome!\n");
}

}

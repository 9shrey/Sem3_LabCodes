#include<stdio.h>
#include<string.h>

void copy(char str1[],char str2[],int index)
{
   if (str1[index]=='\0'){
   	return ; 
   }
   else{
   	str2[index]=str1[index];
   	copy(str1,str2, index+1);
   }
}



void main()
{
	char a[100],b[100]; int n;

	printf("Enter your string:\n");
	scanf("%s",a);

	copy(a,b,0);

printf("%s\n",b);
}

#include<stdio.h>
int main()
{
	int a[100],i,key,n;
	printf("Enter length of array: ");
	scanf("%d",&n);
	printf("Enter elements of array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter element to search: ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
			printf("Found element at position: %d",i+1);
	}
	return 0;
}
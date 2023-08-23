#include<stdio.h>
int main()
{
	int a[100],i,j,k,n,sum;
	printf("state the length of the array: ");
	scanf("%d",&n);
	printf("Input elements in array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if(i!=k && j!=k && i!=k)
				{
					sum=a[i]+a[j]+a[k];
					if(sum==0)
					{
						printf("%d %d %d",a[i],a[j],a[k]);
						printf("\n");
					}
				}
			}
		}
	}
	return 0;
}
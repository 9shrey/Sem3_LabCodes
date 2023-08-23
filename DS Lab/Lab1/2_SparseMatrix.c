#include<stdio.h>
int main()
{
	int a[100][100],i,j,n,numzeros=0;
	float k;
	printf("state the dimensions of the array n and m: ");
	scanf("%d %d",&n,&m);
	printf("Input elements in array: ");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d\t",a[i][j]);
			if(a[i][j]==0)
				numzeros+=1;	
		}
		printf("\n");
	}
	k=n*m/2;
	if(numzeros>k)
		printf("Sparse Matrix");
	if(k>numzeros)
		printf("Not a Sparse Matrix");
	return 0;
}

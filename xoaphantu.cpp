#include<stdio.h>
int main()
{
	int i,j,k=0,n;
	printf("nhap so phan tu cua day: ");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++)
	{
		printf("nhap a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++)
	{
		if (a[i]%5==0)
		{
			k++;
			for (j=i;j<n;j++)
			a[j]=a[j+1];
			i--;
		}
	}
	for (i=0;i<n-k;i++)
	{
		printf("a[%d]= %d ",i,a[i]);
	}
return 0;
}

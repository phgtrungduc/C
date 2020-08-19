#include<stdio.h>
int main()
{
	int a[100],c[100],l[100];
	int n,i,j=0,k=0;
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	for (i=0;i<n;i++)
	{
		if (a[i]%2==0)
		{
			c[j]=a[i];
			j++;
		}
		else 
		{                                
			l[k]=a[i];
			k++;
		}
	}
	printf("mang so chan la:\n");
	for (i=0;i<j;i++)
	{
		printf("%d   ",c[i]);
	}
	printf("\nmang so le la:\n");
	for (i=0;i<k;i++)
	{
		printf("%d   ",l[i]);
	}
	return 0;
}

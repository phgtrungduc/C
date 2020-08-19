#include<stdio.h>
int main()
{
	int i,n,j,k;
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++)
	{
		printf("nhap a[%d]= \n",i);
		scanf("%d",&a[i]);
	}
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (a[i]<a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		if(a[i]!=a[0]) 
		{
			printf("gia tri lon thu hai cua day la: %d",a[i]);
			break;
		}
	}
	return 0;
}

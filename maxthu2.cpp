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
	int max1=a[0],max2=a[0];
	for (i=0;i<n;i++)
	{
		if (a[i]>max1) max1=a[i];
	}
	for (i=0;i<n;i++)
	{
		if (a[i]>max2&&a[i]<max1) max2=a[i];
	}
	printf("gia tri lon thu hai cua mang la: %d",max2);
	return 0;
}

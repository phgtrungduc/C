#include<stdio.h>
int main()
{
	int i=0,a[100],n=0;
	do
	{
		printf("nhap mang");
		scanf("%d",&a[i]);
		i++;n++;
	} while(1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k=0,n,t;
	printf("nhap so phan tu cua day: ");
	scanf("%d",&n);	
	int a[n];
	for (i=0;i<n;i++)
	{
		printf("nhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	printf("%d",i);
	for (i=0;i<n-1;i++)
	for (j=i;j<n;j++)
	{
		if (a[i]>a[j])
		{
			k=a[i];
			a[i]=a[j];
			a[j]=k;
		}
	}
	printf("nhap phan tu can chen: ");
    scanf("%d",&t);
    i=n;
    while ((i>0)&&a[i-1]>t)
    {
    	a[i]=a[i-1];
    	i--;
	}
	a[i]=t;
	for (i=0;i<n+1;i++)
	{
		printf("a[%d] = %d ",i,a[i]);
	}
   
	
return 0;	
}

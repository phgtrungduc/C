#include<stdio.h>
int fibo(int n)
{
	int a[n],i;
	a[0]=a[1]=1;
	for (i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
return a[n-1];
}
int main()
{
	int n,i=0;
	printf("nhap so phan tu: ");
	scanf("%d",&n);
    while (fibo(i)<n) 
	{
		printf("%d ",fibo(i));
		i++;
	}
return 0;
}

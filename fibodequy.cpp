#include<stdio.h>
int fibo(int n)
{
if (n==0||n==1) return 1;
else return fibo(n-1)+fibo(n-2);
}
int main()
{
	int n;
	printf("nhap vi tri can tim: ");
	scanf("%d",&n);
	printf("fibo[%d] la %d",n,fibo(n));
	return 0;
}

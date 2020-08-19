#include<stdio.h>
int sohoanhao(int n)
{
	int i,s=0;
	for (i=1;i<n;i++)
	{
		if (n%i==0) s=s+i;
	}
if (s==n) return 1; else return 0;
}
int main()
{

int n,i;
printf("nhap n: ");
scanf("%d",&n);
for (i=1;i<n;i++)
{
   if (sohoanhao(i)==1) printf("%d\n",i);
}
return 0;
}


#include<stdio.h>
int main()
{
	int n,i;
	printf("nhap n: ");
	scanf("%d",&n);
	int a[n];
	a[0]=a[1]=1;
	for (i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
    }
 for (i=0;i<n;i++)
 {
 
 printf("a[%d]=%d ",i,a[i]);
}
return 0;

}

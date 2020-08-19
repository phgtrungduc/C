#include<stdio.h>
#include<math.h>
int main()
{
	int n,i=0,k=0;
	printf("nhap so can tach: ");
	scanf("%d",&n);
	while (pow(10,i) <= n)
	{
	i++;
	k++;
    }
		int a[k];
	for (i=0;i<k;i++)
	{
        a[i]= n /(pow(10,i));	
	}
	for (i=k-1;i>=0;i--)
	{
        printf("a[%d] = %d ",i,a[i]);
	}
	return 0;
}


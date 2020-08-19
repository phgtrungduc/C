#include<stdio.h>
int main()
{
	int n,m=0,t=0,i=0,j=0,k;
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int a[n],b[100],c[100];
	for (i=0;i<n;i++)
	{
		printf("nhap a[%d]: \n",i);
		scanf("%d",&a[i]);
	    if (a[i]>0) 
	    {
	    	b[j]=a[i];
	    	j++;
		}
		else if (a[i]<0)
		{
			c[m]=a[i];
			m++;
		}
	}
	for (i=0;i<j;i++)
	{
		printf("b[%d]= %d ",i,b[i]);
	}
	for (i=0;i<m;i++)
	{
		printf("c[%d]= %d ",i,c[i]);
	}
return 0;
}



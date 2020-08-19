#include<stdio.h>
int main()
{
	int n,i,j,k;
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++)
	{
		printf("nhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
    for (i=0;i<n-1;i++)
	for (j=i+1;j<n;j++)
	  {
	  	if (a[i]<a[j])
	  	
		  {
		  	k=a[i];
		  	a[i]=a[j];
		  	a[j]=k;
		  } 
	  }
	for (i=0;i<n;i++)  
	{
	printf("a[%d]= %d ",i,a[i]);
    }   
return 0;
}



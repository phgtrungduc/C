#include<stdio.h>
int main()
{
	int i,j,tg,t=0,a[100],n;
	printf("nhap so phan tu cua mang: ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if (n==1) t=0;
	else 
	{
		for (i=0;i<n-1;i++)
	    for (j=i+1;j<n;j++)
	   {
		if (a[i]>a[j])
		{
			tg=a[i];
			a[i]=a[j];
			a[j]=tg;
		}
	   }
	 for (i=0;i<n-1;i++)
	 {
	 	if (a[i+1]-a[i]>1)
	 	{
	 		t = t + a[i+1]-a[i]-1;
		}
	 }
	}
	printf("so cac so can them la: %d",t);
	return 0;
}

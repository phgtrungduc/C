#include<stdio.h>
#include<math.h>
int ktsonguyento(int n)
{
	int i,k=1;                                                                
	for (i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) 
		{
			k=0;
			break;
		}
		else k=1;
	}
	return k;
}	          


int main()
{
	int i=2,n,dem=0;
	printf("Can tim so nguyen to thu: ");
	scanf("%d",&n);
	while (dem<n)
	{
		if(ktsonguyento(i)==1) dem++;
		i++;
	}
	printf("so nguyen to thu %d la %d",n,i-1);
	return 0;
}

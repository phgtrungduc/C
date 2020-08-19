#include<stdio.h>
int size =4;
void try(int i)
{
	int a[4];
	for (int j=0;j<=1;j++)
	{
		a[i]=j;
		if (i==size-1)
		{
			for (int k=0;k<size;k++)
			{
				printf("%d",a[k]);
			}
		}
		else try(i+1);
	}
}
int main()
{
	try(1);
	return 0;
}

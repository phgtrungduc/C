#include<stdio.h>
int size =3;
void cogang(int i)
{
	int a[4];
	for (int j=0;j<=1;j++)
	{
		a[i]=j;
		if (i==size-1)
		{
			for (int k=0;k<size;k++)
			{
				printf("%d   ",a[k]);
			}
			print("\n");
		}
		else cogang(i+1);
	}
}
int main()
{
	cogang(0);
	return 0;
}

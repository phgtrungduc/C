#include<stdio.h>
int size = 4;
int a[4];
bool check;
void sinhxau()
{
	int i= size;
	while (a[i]==1 && i>0)
	{
		a[i]=0;
		i--;
	}
	if (i==0) check = true;
	else a[i]=1;
}
int main()
{
	for (int i=0;i<size;i++)
	{
		a[i]=0;
	}
	check = false;
	while (check!=true)
	{
		for (int i=0;i<size;i++)
		 {
		sinhxau();
		printf("%d",a[i]);
		
	     }
	     
	}
	
	
	return 0;
}

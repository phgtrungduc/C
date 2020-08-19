#include<stdio.h>
int main()
{
	int a[9][9],i,j;
	FILE *mt;
	mt = fopen("D:\\matran.txt","r+t");
	for (i=0;i<=3;i++)
	for(j=0;j<=3;j++)
	{	
	     fscanf(mt,"%d",&a[i][j]);
	}
	for (i=0;i<=3;i++)
	{
	     for(j=0;j<=3;j++)
	{
		printf("%d ",a[i][j]);
	}
	printf("\n");
    }
	fclose(mt);
return 0;
}

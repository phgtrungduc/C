#include<stdio.h>
#include<conio.h>
int main()
{
	int m,n,i,j;
	printf("nhap so hang: ");
	scanf("%d",&m);
	printf("nhap so cot: ");
	scanf("%d",&n);
	int a[m][n],b[m][n],c[m][n];
	printf("thuc hien nhap ma tran thu nhat:");
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	{
		printf("nhap a[%d][%d]= ",i,j);
		scanf("%d",&a[i][j]);
	}
	printf("thuc hien nhap ma tran thu hai");
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	{
		printf("nhap b[%d][%d]= ",i,j);
		scanf("%d",&b[i][j]);
	}
	
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
    {
    	c[i][j]=a[i][j]+b[i][j];
	}
	printf("tong hai ma tran la:\n");
	for (i=0;i<m;i++)
	{
	     for (j=0;j<n;j++)
	     printf("%5d",c[i][j]); 
         printf("\n");
    }
	getch();
	return 0;
}

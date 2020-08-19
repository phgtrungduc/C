#include<stdio.h>
#include<conio.h>
int main()
{
	int m,n,i,j,p,q,k;
	printf("nhap so hang ma tran thu nhat:  ");
	scanf("%d",&m);
	printf("nhap so cot ma tran thu nhat:  ");
	scanf("%d",&n);
	int a[m][n];
	printf("thuc hien nhap ma tran thu nhat:");
	for (i=0;i<m;i++)
	for (j=0;j<n;j++)
	{
		printf("nhap a[%d][%d]= ",i,j);
		scanf("%d",&a[i][j]);
	}
	printf("so hang ma tran thu hai bang so cot ma tran thu nhat =))\n");
	printf("nhap so cot ma tran thu hai:  ");
	scanf("%d",&p);
	int b[n][p];
	printf("thuc hien nhap ma tran thu hai");
	for (i=0;i<n;i++)
	for (j=0;j<p;j++)
	{
		printf("nhap b[%d][%d]:= ",i,j);
		scanf("%d",&b[i][j]);
	}
	int c[m][p];
	for (i=0;i<m;i++)
	{
		for (j=0;j<p;j++)
		{
		c[i][j]=0;
	    }
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<p;j++)
		{
			for (k=0;k<n;k++)
			{
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
		    }
		}
	}
	for (i=0;i<m;i++)
	{
		for (j=0;j<p;j++)
		{
		printf("%3d",c[i][j]);
	    }
		printf("\n");
	}
	return 0;
}

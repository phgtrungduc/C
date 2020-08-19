#include<stdio.h>
#include<conio.h>
int size=4;
void readfile (int c[100][100])
{
	FILE*giatri;
	giatri= fopen("D:\\Bai6.txt","r+t");
	for (int i=0;i<size;i++)
	for (int j=0;j<size;j++)
	{
		fscanf(giatri,"%d",&c[i][j]);
	}
	fclose(giatri);
}
int main()
{
	int xphang,xpcot;
	int c[100][100];
	readfile(c);
	printf("ma tran tu fie: \n");
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			printf("%d   ",c[i][j]);
		}
		printf("\n");
	}
	printf("nhan enter de bat dau nhap cac gia tri:\n");
	getch();
	printf("nhap hang : ");
	scanf("%d",&xphang);
	printf("nhap cot : ");
	scanf("%d",&xpcot);
	printf("nhu vay ta xuat phat tu o %dx%d",xphang,xpcot);
	//bat dau khoi tao
	int d[100],truoc
return 0;
}

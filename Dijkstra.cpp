#include<stdio.h>
int size = 7;
void trongso(int c[10][10])
{
	FILE *canh;
	canh = fopen("D:\\trongsodij.txt","r+t");
	for (int i=0;i<size;i++)
	for (int j=0;j<size;j++)
	{
		fscanf(canh,"%d",&c[i][j]);
	}
	fclose(canh);
}
int main()
{
	int c[10][10];
	trongso(c);
	//thiet lap xong trong so cua do thi
	int i,j,dem=1;
	int d[10];//mang chua nhan ghi nhan quang duong tu dinh 0 den dinh dang xet
	int truoc[10];//mang ghi nhan dinh ngay truoc dinh dang xet voi quy uoc near[dinh bat dau]= dinh bat dau
	bool check[10];
	for (i=0;i<size;i++)    // khoi tao bat dau tu dinh 0...
	{
		d[i]=c[0][i];
		truoc[i]=0;
		check[i]=false;
	}
	d[0]=0;
	check[0]=true;
	while (dem<size)                                        //bat dau buoc lap
	{
		int min=10000;
		for (i=0;i<size;i++)
		{
			if (check[i]==false&&d[i]<min)
			{
				min=d[i];
				j=i;
			}
		}
		printf("chon dinh thu %d tai buoc lap thu %d\n",dem,j);
		check[j]=true;
		for (i=0;i<size;i++)
		{
			if (check[i]==false&&(d[i]>(d[j]+c[j][i])))
			{
				d[i]=d[j]+c[j][i];
				truoc[i]=j;
			}	
		}
		dem++;
	}
	for (i=0;i<size;i++)
		{
			printf("dinh %d cach dinh xuat phat mot doan la %d, dinh truoc no la %d\n",i,d[i],truoc[i]);
		}
	return 0;
}

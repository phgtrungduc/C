#include<stdio.h>
int size=6;
void trongso(int d[20][20])
{
	FILE*mttrongso;
	mttrongso= fopen("D:\\trongso2.txt","r+t");
	for (int i=1;i<=size;i++)
	for (int j=1;j<=size;j++)
	{
		fscanf(mttrongso,"%d",&d[i][j]);
	}
	fclose(mttrongso);
}
int main()
{
	int canh[20][20],c[20][20],i,j;
	trongso(c);
	//khoi tao xong do thi co trong so
	int d[100],near[100],dem=1;//d la mang chua trong so
	bool stop=false,check[100];
	for (i=0;i<size;i++)
	{
		check[i]=false;
	}
	d[1]=1;
	near[1]=1;
	check[1]=true;//dua dinh 1 vao Vh
	for (i=1;i<=size;i++)
	{
		d[i]=c[1][i];
		near[i]=1;
	}
	
	while (stop==false)
	{
		int min=100000;
		for (i=1;i<=size;i++)
		{
		if(check[i]==false&&d[i]<min) //tim ra dinh co khoang cach ngan nhan den dinh da chon
		{
			min = d[i];
			j=i;
		}
	    }
		check[j]=true;//dua dinh j vao Vh
		dem++;
		if (dem==size)
		{
			stop = true;
		}
		else 
		{
			for (i=1;i<=size;i++)
			{
				if (check[i]==false && d[i]>c[j][i])
				{
					d[i]=c[i][j];
					near[i]=j;
				}
			}
		}
	}
	for(i=1;i<=size;i++)
	{
		printf("%d %d",i,near[i]);
		printf("\n");
	}
	return 0;
}

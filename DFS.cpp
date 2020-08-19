#include<stdio.h>
int ke[20][20],lienthong=0;
int sizeMatrix = 13;
bool chuaxet[100];

void DFS(int u)
{
	int v;
	printf("%d",u+1);
	chuaxet[u] = false;
	for(int v=0;v<sizeMatrix;v++)
	{
		if (ke[v][u] == 1 && chuaxet[v] == true)
		{
			DFS(v);
		}
	}
}

int main()
{
	int i,j;
	
	FILE *canh;
	canh = fopen("D:\\matran.txt","r+t");

	for(i=0;i<sizeMatrix;i++)
	{
		for(j=0;j<sizeMatrix;j++)
		{
			fscanf(canh,"%d",&ke[i][j]);
		}
	}
	
	fclose(canh);
	
	for(i=0;i<sizeMatrix;i++)
	{
		for(j=0;j<sizeMatrix;j++)
		{
			printf ("%d  ",ke[i][j]);
		}
		printf("\n");
	}


	for(i=0;i<sizeMatrix;i++)
    {
    	chuaxet[i]=true;
	}
	
    for(i=0;i<sizeMatrix;i++)
	{
		if(chuaxet[i] == true) 
		{
			
			DFS(i);
			lienthong++;
		}
	}
	printf("so thanh phan lien thong: %d",lienthong);
	
	return 0;
}

#include<stdio.h>
int ke[20][20],size=13,chuaxet[10];
void DFS(int u)
{
	chuaxet[u]=0;
	printf("%d\n",u+1);
	for (int v=0;v<size;v++)
	{
		if (ke[u][v]==1 && chuaxet[v]==1)
		{
			DFS(v);
		}
	}
}
int main()
{
	int i,j,lienthong=0;
	FILE *canh;
    canh = fopen("D:\\matran.txt","r+t");
    for (i=0;i<size;i++)
    for (j=0;j<size;j++)
    {
    	fscanf(canh,"%d",&ke[i][j]);
	}
	fclose(canh);
    printf("ma tran canh cua do thi: \n");
	for (i=0;i<size;i++)
    {
    	for (j=0;j<size;j++)
    	{
    	printf("%d   ",ke[i][j]);
	    }
	    printf("\n");
    }
    for (i=0;i<size;i++)
    {
	      chuaxet[i]=1;
    }
     for (i=0;i<size;i++)
    {
    	if (chuaxet[i]==1)
    	{
		    DFS(i);
		    lienthong++;
      	}
    }
printf("so thanh phan lien thong la: %d",lienthong);
return 0;
}


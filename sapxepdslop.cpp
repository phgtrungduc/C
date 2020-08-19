#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char ds[100][30],s[1000];
	printf("nhap so hoc sinh: ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("nhap ten hoc sinh thu %d\n",i+1);
		fflush(stdin);
		gets(ds[i]);
	}
	for (i=0;i<n;i++)
     for (j=i+1;j<n;j++)
    {
    	if (strcmp(ds[j],ds[i])<0)
    	{
    		strcpy(s,ds[i]);
    		strcpy(ds[i],ds[j]);
    		strcpy(ds[j],s);
		}
	}
	for (i=0;i<n;i++)
	{
		printf("ten hoc sinh thu %d la: ",i+1);
		puts(ds[i]);
		printf("\n");
	}
	return 0;
}


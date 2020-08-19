#include<stdio.h>
#include<string.h>
int main()
{
	int i,k,j;
	char ten[100];
	printf("nhap ten:\n");
	gets(ten);
	k = strlen(ten);
	for (i=0;i<k;i++)
	{
		if ((ten[i]==' ')&&(ten[i+1]==' ')) 
		{
		for (j=i;j<k;j++)
		ten[j]=ten[j+1];
		i--;
	    }
	}
	if (ten[0]==' ') 
	{
		for (i=0;i<k;i++)
		{
			ten[i]= ten [i+1];
		}
	}
	puts(ten);
	return 0;
}

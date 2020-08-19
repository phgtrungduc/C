#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j;
	char a[1000];
	printf("nhap xau: ");
	gets(a);
	n= strlen(a);
	for (i=0;i<n;i++)
	{
		if (a[i]==' ')
		{
			for (j=i;j<n;j++)
			a[j]=a[j+1];
			i--;
		}
	}
for (i=strlen(a)-1;i>=0;i--)
{
	printf("%c",a[i]);
}	
return 0;

	
}

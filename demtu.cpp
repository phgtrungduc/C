#include<stdio.h>
#include<string.h>
int main()
{
	int k,n=0;
	char c[1000];
	printf("nhap xau: ");
	gets(c);
	k= strlen(c);
	printf("%d",k);
	for(int i=0;i<k;i++)
	{
		if ((c[i]==' ')&&(c[i+1]!=' '))
		n++;
	}
printf("so tu trong xau vua nhap la: %d",n);
return 0;
}

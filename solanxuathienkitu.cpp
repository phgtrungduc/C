#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
int main()
{
int n,i;
char c[20];
printf("nhap xau: ");
gets(c);
n= strlen(c);
int dem[27];
for (i=0;i<27;i++)
{
	dem[i]=0;
}
for (i=0;i<27;i++)
{
	if(isalpha(c[i])!=0)
	{
		dem[tolower(c[i])-'a']++;
	}
}

i=0;
while(isalpha(c[i])!=0)
{
	printf("ky tu %c xuat hien %d lan \n",c[i],dem[tolower(c[i])-'a']);
	i++;
}
return 0;
}

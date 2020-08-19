#include<stdio.h>
int main()
{
	int i,j,cao;
	printf("nhap chieu cao: ");
	scanf("%d",&cao);
	for(i=0;i<cao;i++)
	{
	for (j=0;j<cao;j++)
	{
		if ((j==0||j==cao-1)&&(i%2==0))
		printf("*");
		else if ((j==0||j==cao-1)&&(i%2==1))
		printf("#");
		else if ((j==i||j==cao-i-1)&&(i%2==0)&&i<=cao/2)
		printf("*");
		else if ((j==i||j==cao-i-1)&&(i%2==1)&&(i<=cao/2))
		printf("#");
		else printf(" ");
	}
	printf("\n");
}
	return 0;
}

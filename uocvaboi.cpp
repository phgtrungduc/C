#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("nhap hai so a va b: ");
	scanf("%d %d",&a,&b);
	c=a;d=b;
	while(a!=b)
	{
		if (a>b) a=a-b; else b=b-a;
	}
printf("uoc chung nho nhat cua hai so la: %d",a);
printf("\nboi chung cua hai so la: %d",(c*d/a));
return 0;

}

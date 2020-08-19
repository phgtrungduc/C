#include<stdio.h>
float max2(float a,float b)
{
	if (a>b) return a; else return b;
}
int main()
{
	float a,b,k;
	printf("nhap hai so a va b: ");
	scanf("%f",&a);
	scanf("%f",&b);
	k= max2(a,b);
	printf("gia tri max la: %f",k);
	return 0;
}


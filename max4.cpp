#include<stdio.h>
float max2(float a,float b)
{
	if (a>b) return a; else return b;
}
float max4(float a, float b, float c, float d)
{
	return max2(max2(a,b),max2(c,d));
}
int main()
{
	float a,b,c,d;
	printf("nhap a: ");scanf("%f",&a);
	printf("nhap b: ");	scanf("%f",&b);
	printf("nhap c: ");	scanf("%f",&c);
	printf("nhap d: ");	scanf("%f",&d);
	printf("gia tri max la: %f",max4(a,b,c,d));
	return 0;
}


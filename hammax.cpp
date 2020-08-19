#include<stdio.h>
int max2(int a, int b) 
{
    return a > b ? a : b;
}
 
int max3(int a, int b, int c) 
{
    return max2( max2(a, b), c);
}
 
int main()
{
    int a,b,c;
	printf("nhap vao ba so a,b,c \n");
    scanf("%d %d %d",&a,&b,&c);
	printf("So lon nhat la %d \n", max3(a, b, c));
    return 0;
}

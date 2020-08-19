#include<stdio.h>
int main()
{
int a;
do 
{
	printf("nhap so nguyen duong a: ");
	scanf("%d",&a);
}
while(a<0);
printf("dang hex cua so nguyen a la: 0x%x",a);
return 0;
}


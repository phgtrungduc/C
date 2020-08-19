#include<stdio.h>
int thaydoi(int *a){
	*a=10;
}
int main()
{
	int *p;
	int a=5;
	p=&a;
	//thaydoi(p);
	printf("%d",*p);
}

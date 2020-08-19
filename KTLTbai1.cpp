#include<stdio.h>
int main(){
	int a=15,b=20,*p,c;
	p=&a;
	printf("sizeof(*p): %d",sizeof(*p));
	printf("\n");
	printf("sizeof(p):%d ",sizeof(p));
	printf("\n");
	printf("Dia chi ban dau cua p: %d",p);
	c= *++p;
	printf("Dia chi luc sau cua p: %d",p);
	printf("a= %d, b=%d,c= %d",a,b,c);
	return 0;
}

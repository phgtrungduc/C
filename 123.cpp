#include<stdio.h>
#include<stdlib.h>
#include<string>
struct sinhvien{
	struct lon{
		char c;
	}data;
	int a;
};

typedef struct sinhvien SV;
int main(){
//	SV *p,*q;
//	p=(SV *)malloc(sizeof(SV));
//	q=(SV *)malloc(sizeof(SV));
//	p->a=5;
//	p->data.c ='l';
//	q->data.c= 'c';
//	q->a=10;
//	SV *k;
//	k=(SV *)malloc(sizeof(SV));
//	k->data=p->data;
//	p->data=q->data;
//	q->data=k->data;
//	printf("%c",p->data.c);
//	printf("%c",q->data.c);
int b=5,c=6;
int *a=&b;
int **p=&a;
printf("%d",&b);
*p=&b;
printf("\n%d",*p);
return 0;
}


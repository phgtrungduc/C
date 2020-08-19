#include<stdio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 25
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
struct list{
	NODE *head;
	int top;
};
typedef struct list LIST;
void init(LIST &l){
	l.head=NULL;
	l.top=-1;
}
NODE *initnode(int x){
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	p->data=x;
	p->next=NULL;
	return p;
}
void push(LIST &l,NODE *p){
	if(l.top==-1){
		l.head=p;
		l.top++;
	}
	else {
		p->next=l.head;
		l.head=p;
		l.top++;
	}
}
void pop(list &l,int &x){
	if (l.top==-1) printf("\nStack rong");
	else {
		x=l.head->data;
		l.head=l.head->next;
		l.top--;
	}
}
int main(){
	int min=99,n;
	char check;
	LIST l,tg;
	init (l);
	init (tg);
	while(1){
		printf("\nNhap day so: ");
		scanf("%d",&n);
		push(l,initnode(n));
		if (n<min){
			push(tg,initnode(n));
		}
		else {
			NODE *p = initnode(min);
			push(tg,p);
		}
		printf("\nXong chua?");
		fflush(stdin);
		scanf("%c",&check);
		if (check=='y'||check=='Y') break;
	}
	int x;
	pop(tg,x);
	printf("Gia tri nho nhat vua nhap vao: %d",x);
	return 0;
}

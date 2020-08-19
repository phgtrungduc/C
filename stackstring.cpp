#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 25
struct node{
	char *data;
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
NODE *initnode(char x[]){
	NODE *p;
	p = (NODE *)malloc(sizeof(NODE));
	int n= strlen(x);
	p->data = (char *)malloc((n+1)*sizeof(char));
	strcpy(p->data,x);
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
void pop(list &l,char x[]){
	if (l.top==-1) printf("\nStack rong");
	else {
		strcpy(x,l.head->data);
		l.head=l.head->next;
		l.top--;
	}
}
int main(){
	LIST l;
	init(l);
	char c[20];
	char d[20];
	char e[20];
	strcpy(d,"con cac");
	strcpy(e,"an lon");
	NODE *p;
	p=initnode(d);
	push(l,p);
	pop(l,c);
	printf("\n%s",c);
	return 0;
}

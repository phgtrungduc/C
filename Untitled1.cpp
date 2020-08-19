#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct nodequeue{
	char data;
	struct nodequeue *next;
}nodequeue;
typedef struct list{
	nodequeue *head;
	nodequeue *tail;
}list;
void initlist(list &l){
	l.head=NULL;
	l.tail=NULL;
}
nodequeue *initnodequeue(char data){
	nodequeue *p;
	p= (nodequeue*)malloc(sizeof(nodequeue));
	p->data=data;
	p->next=NULL;
}
void insertnode(list &l,nodequeue *p){
	if (l.head==NULL){
		l.head = l.tail = p;
		return;
	}
	if(p->data < l.head->data ){
		p->next = l.head;
		l.head = p;
		return ;
	}
	else if(p->data > l.tail->data){
		l.tail->next=p;
		l.tail=p;
		return ;
	}
	else {
		nodequeue *q=l.head;
		while(q->next!=NULL && p->data > (q->next)->data){
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
	}
}
void putlist(list &l,nodequeue *p){
	p=l.head;
	l.head=l.head->next;
}
void display(list &l){
	nodequeue *p=l.head;
	while(p!=NULL){
		printf("%c",p->data);
		p=p->next;
	}
}
int main(){
	char a[10];
	list l;
	initlist(l);
	strcpy(a,"bcda");
	for (int i=0;i<4;i++){
		nodequeue *p;
		p = initnodequeue(a[i]);
		insertnode(l,p);
	}
	nodequeue *q;
	display(l);
	printf("\n");
	putlist(l,q);
	display(l);
	return 0;
}

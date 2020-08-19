#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int first=0,last=0;
typedef struct nodequeue{
	char data;
	int freq;
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
nodequeue *initnodequeue(char data,int freq){
	nodequeue *p;
	p= (nodequeue*)malloc(sizeof(nodequeue));
	p->data=data;
	p->freq= freq;
	p->next=NULL;
}
void insertqueue(list &l,nodequeue *p){
	if (l.head==NULL){
		l.head = l.tail = p;
		return;
	}
	if(p->freq < l.head->freq ){
		p->next = l.head;
		l.head = p;
		return ;
	}
	else if(p->freq > l.tail->freq){
		l.tail->next=p;
		l.tail=p;
		return ;
	}
	else {
		nodequeue *q=l.head;
		while(q->next!=NULL && p->freq > (q->next)->freq){
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
		printf("phan tu %c xuat hien %d lan",p->data,p->freq);
		printf("\n");
		p=p->next;
	}
}
int sizelist(list &l){
	nodequeue *p=l.head;
	int dem=0;
	while(p!=NULL){
		dem++;
		p=p->next;
	}
	return dem;
}
nodequeue *addnodequeue(nodequeue *p,nodequeue *q){
	nodequeue *r;
	r->data='0';
	r->freq = p->freq+p->freq;
	return r;
}
typedef struct NODE{
	char data;
	int freq;
	struct NODE *left,*right;
}NODE;
NODE *newnode(char a,int freq){
	NODE *p;
	p=(NODE *)malloc(sizeof(NODE));
	p->data=a;
	p->freq-freq;
	p->left=p->right=NULL;
	return p;
}
void copy(NODE *p,nodequeue *q){
	p->data=q->data;
	p->freq=q->freq;
}
void addtree(list &l){
	nodequeue *p,*q,*r;
	NODE *p1,*p2,*q1,*q2;
	while(sizelist(l)>=1){
		putlist(l,p);
		putlist(l,q);
		r=addnodequeue(p,q);
		
	}
}
int main(){
	char a[30];
	int check[26];
	list l;
	initlist(l);
	for (int i=0;i<26;i++){
		check[i]=0;
	}
	printf("Nhap vao chuoi: ");
	gets(a);
	int n =strlen(a);

	for (int i=0;i<n;i++){
		if (a[i]>=97&&a[i]<=122){
			check[a[i]-'a']++;
		}
	}
	for (int i=0;i<26;i++){
		if (check[i]>0){
			nodequeue *p;
			p= initnodequeue(i+'a',check[i]);
			insertqueue(l,p);
		}
	}
	printf("%d",sizelist(l));
	return 0;
}

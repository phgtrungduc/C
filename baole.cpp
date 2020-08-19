#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int dem;
struct node{        //cau truc cua 1 node bao gom data va 1 con tro next 
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *initnode(int x){              
	NODE *p;
	p = (NODE *)malloc(sizeof(struct node));
	if (p==NULL) printf("Cap phat khong thanh cong");
	p->data=x;
	p->next=NULL;
	return p;
}
void add(NODE *&head,int x){
	NODE *p=initnode(x);
	if (head==NULL) head=p; 
	else {
		NODE *q=head;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
	}
}
void printlist(NODE *head){
	NODE *p=head;
	while(p!=NULL){
		printf("%d  ",p->data);
		p=p->next;
	}
}
int main(){
	NODE *head = NULL;
	int a[]={1,5,8,9,7,2,1,4};
	for (int i=0;i<8;i++){
		add(head,a[i]);
	}
	printlist(head);
	return 0;
}

#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int dem;
struct node{        //cau truc cua 1 node bao gom data va 1 con tro next 
	int coso;
	int somu;
	struct node *next;
};
typedef struct node NODE;
NODE *initnode(int coso,int somu){              
	NODE *p;
	p = (NODE *)malloc(sizeof(struct node));
	if (p==NULL) printf("Cap phat khong thanh cong");
	p->coso=coso;
	p->somu=somu;
	p->next=NULL;
	return p;
}
void printdathuc(NODE *head){
	NODE *p=head;
	for(p=head;p!=NULL;p=p->next){
		printf("%d^%d ",p->coso,p->somu);
		if (p->next!=NULL) printf("+");
	}
}
void add(NODE *&head,int coso,int somu){
	NODE *p=initnode(coso,somu);
	if (head==NULL){
		head=p;
	}
	else{
		NODE *q=head;
		while (q->next!=NULL){
			q=q->next;
		}
		q->next=p;
	}
}
void swap(int &x,int &y){
	int tmp=x;
	x=y;
	y=tmp;
}
void sapxepdathuc(NODE *&head){
	for (NODE *p=head;p->next!=NULL;p=p->next){
		for (NODE *q=p->next;q!=NULL;q=q->next){
			if (p->somu<q->somu) {
				swap(p->somu,q->somu);
				swap(p->coso,q->coso);
			}
		}
	}
}
NODE  *congdathuc(NODE *head1,NODE *head2){
	NODE *p=head1;
	NODE *q=head2;
	NODE *head=NULL;
	while(p!=NULL&&q!=NULL){
		if(p->somu>q->somu){
			
		}
	}
}*/
int main(){
	NODE *head=NULL;
	add(head,2,1);
	add(head,2,5);
	add(head,2,4);
	add(head,2,0);
	printdathuc(head);
	printf("\n");
	sapxepdathuc(head);
	printdathuc(head);
	return 0;
}

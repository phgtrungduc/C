#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
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
void printlist(NODE *head){
	NODE *p;
	for(p=head;p!=NULL;p=p->next){
		printf("%d  ",p->data);
	}
}
void printlistnguoc(NODE *head){
	if (head->next!=NULL) printlistnguoc(head->next);
	printf("%d   ",head->data);
	
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
void xoachan(NODE *&head){
	while (head->data%2==0){
		NODE *p=head;
		head=head->next;
		free(p);
	}
	NODE *p=head;
	while(p->next!=NULL){
		NODE *q=p->next;
		if (q->data%2==0){
			p->next=q->next;
			free(q);
		}
		else {
			p=p->next;
		}
	}
}
int demchan(NODE *head){
	NODE *p=head;
	int dem=0;
	while(p!=NULL){
		if ((p->data)%2==0) dem++;
		p=p->next;
	}
	return dem;
}
void daonguoc(NODE *&head){
	if (head==NULL) return ;
	else {
		NODE *after;
		NODE *current;
		while (head->next!=NULL){
			current = head;
			head=head->next;
			current->next=after;
			after = current;
		}
		head->next=current;
	}
}
void xoavitrile(NODE *&head){
	head= head->next;
	NODE *p=head;
	printf("%d ",p->data);
	while (p!=NULL){
		p->next=(p->next)->next;
		p=p->next;
	}
}
void xoavitrichan(NODE *&head){
	NODE *p=head;
	while (p->next!=NULL){
		p->next=(p->next)->next;
		p=p->next;
	}
}
void loaitrung(NODE *&head){
	while (head->data==(head->next)->data){
		head=head->next;
	}
	NODE *p=head;
	while(p->next!=NULL){
		if (p->data==(p->next)->data){
			p->next=(p->next)->next;
		}
		else {
			p=p->next;
		}
	}
}
void xoakey(NODE *&head,int key){
	while (head->data==key){
		head=head->next;
	}
	NODE *p=head;
	while(p->next!=NULL){
		if ((p->next)->data==key){
			p->next=(p->next)->next;
		}
		else {
			p=p->next;
		}
	}
}
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void sapxep(NODE *&head){
	NODE *p,*q;
	for (p=head;p->next!=NULL;p=p->next){
		for (q=p->next;q!=NULL;q=q->next){
			if (p->data > q->data) swap(p->data,q->data);
		}
	}
}
void mergeList(NODE *&tong,NODE *List1,NODE *List2){
	NODE *p=List1;
	NODE *q=List2;
	while (p!=NULL&&q!=NULL){
		if (p->data<q->data){
			add(tong,p->data);
			p=p->next;
		}
		else if (q->data<p->data){
			add(tong,q->data);
			q=q->next;
		}
		else {
			add(tong,p->data);
			q=q->next;
			p=p->next;
		}
	}
	if (p!=NULL){
		add(tong,p->data);
		p=p->next;
	}
	if (q!=NULL){
		add(tong,q->data);
		q=q->next;
	}
}
void selectionsort(NODE *&head){
	NODE *min;
	for (NODE *p=head;p->next!=NULL;p=p->next){
		min = p;
		for (NODE *q=p->next;q!=NULL;q=q->next){
			if (q->data<min->data) min=q;
		}
		swap(min->data,p->data);
	}
}
int minle(NODE *head){
	NODE *p=head;
	int min=999;
	while(p!=NULL){
		if (p->data%2==1&&p->data<min){
			min=p->data;
		}
		p=p->next;
	}
	if (min==999) return 0;
	else return min;
}
void dequyin(NODE *head){
	if(head==NULL) return;
	else dequyin(head->next);
	printf("%d ",head->data);
}
int main(){
//	NODE *head=NULL;
//	add(head,2);
//	add(head,2);
//	add(head,2);
//	add(head,50);
//	add(head,26);
//	add(head,30);
//	add(head,40);
//	add(head,28);
//	add(head,16);
//	add(head,14);
//	add(head,14);
//	dequyin(head);
int a[2][3];
for (int i=0;i<2;i++){
	for (int j=0;j<3;j++){
		scanf("%d",&a[i][j]);
	}
}
int k=2*3;
for (int i=0;i<2;i++){
	for (int j=0;j<3;j++){
		printf("%d  ",*(*(a+i)+j));
	}
}
	return 0;
}


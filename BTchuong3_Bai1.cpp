#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int dem;
struct node{        //cau truc cua 1 node bao gom data va 1 con tro next 
	int data;
	struct node *pNext;
};
typedef struct node NODE;
struct list{        //mot list quan li cac node bao gom con tro head tro den vi tri phan tu dau tien va ptail tro den phan tu cuoi cung
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void init(LIST &l){
	l.pHead=NULL;         //khoi tao danh sach thi con tro head va tail deu bang null
	l.pTail=NULL;
}
NODE *initnode(int x){              
	NODE *p;
	p = (NODE *)malloc(sizeof(struct node));
	if (p==NULL) printf("Cap phat khong thanh cong");
	p->data=x;
	p->pNext=NULL;
	return p;
}
void printlist(LIST l){
	NODE *p;
	for(p=l.pHead;p!=NULL;p=p->pNext){
		printf("%d  ",p->data);
	}
}
void add(LIST &l,int x){
	NODE *p=initnode(x);
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void xoachan(LIST &l){
	while ((l.pHead->data)%2==0) {
		NODE *p=l.pHead->pNext;
		free(l.pHead);
		l.pHead=p;
	}
//	NODE *gancuoi;
	NODE *p =l.pHead;
	while ((p->pNext)!=NULL){
//		if(p->pNext==l.pHead) gancuoi=p;
		if(((p->pNext)->data)%2==0){
			NODE *q= p->pNext;
			p->pNext=q->pNext;
			free(q);
		}
		else {
			p=p->pNext;   //phai them dieu kien else vi trong truong hop 2 so chan lien tiep se bi bo qua 1 so
		}
	}
/*	if ((l.pTail->data)%2==0){
	//	free(l.pTail);
		l.pTail=gancuoi;
	}*/
}
int demchan(LIST l){
	NODE *p=l.pHead;
	int dem=0;
	while (p!=NULL){
		if ((p->data)%2==0){
			dem++;
		}
		p=p->pNext;
	}
	return dem;
}
int demle(LIST l){
	NODE *p=l.pHead;
	int dem=0;
	while (p!=NULL){
		if ((p->data)%2!=0){
			dem++;
		}
		p=p->pNext;
	}
	return dem;
}
int main(){
	LIST l;
	init(l);
	add(l,20);
	add(l,40);
	add(l,60);
	add(l,1);
	add(l,2);
	add(l,4);
	add(l,5);
	add(l,8);
	add(l,9);
	add(l,10);
	add(l,32);
	add(l,40);	
	printlist(l);
	printf("co tat ca %d so chan",demchan(l));
	xoachan(l);
	printf("\n");
	printlist(l);
	printf("co tat ca %d so chan",demchan(l));
	return 0;
}

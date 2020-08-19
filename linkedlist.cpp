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
int size(LIST l){
	int dem;
	for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
		dem ++;
	}
	return dem;
}
void printlist(LIST l){
	NODE *p;
	for(p=l.pHead;p!=NULL;p=p->pNext){
		printf("%d  ",p->data);
	}
}
void addfirst(LIST &l,NODE *p){
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else{
		p->pNext= l.pHead;
		l.pHead=p;
	}
}
void addlast(LIST &l,NODE *p){
	if (l.pHead==NULL){
		l.pHead=l.pTail=p;
	}
	else{
		l.pTail->pNext=p;
		l.pTail=p;
	}
}
void add(LIST &l,int data,int posi){
	int count =0;
	NODE *tg;
	NODE *p =initnode(data);
	if (posi>size(l)) printf("\nvi tri nhap vao chua ton tai trong danh sach");
	else if (posi==-1) addfirst(l,p);
	else if(posi==-2) addlast(l,p);
	else{
		for (NODE *k=l.pHead;k!=NULL;k=k->pNext){
			if(count==posi) {
				tg=k;
			}
			count ++;
		}
		p->pNext= tg->pNext;
		tg->pNext= p;
	} 
}
void remove(LIST &l,int pos){
	if(pos >size(l)) printf("\nVi tri nhap vao lon hon so luong phan tu");
	else {
		NODE *tg;
		if(pos==0){    //xoa o dau danh sach
			tg = l.pHead;
		    for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
		    	if (p=l.pHead->pNext) {
					l.pHead=p;
					break;
				}
			}
			free(tg);
	    }
	    else if (pos==dem-1){   // xoa o cuoi danh sach
		    for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
		    	if (p->pNext==l.pTail) {
		    		tg = l.pTail;
					l.pTail=p;
					p->pNext=NULL;
					break;
				}
			}
			free(tg);
		}   
		else {         //xoa o vi tri bat ki
			int count =0;
		    NODE *pre,*tg,*tmp;
			for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
		    	if (count ==pos-1){
		    		pre = p;
				}
				if (count ==pos){
					tg = p;
				}
				if (count ==pos+1){
					tmp = p;
				}
				count ++;
			}
			pre->pNext=tmp;
			free(tg);
		}
	}
}
void del(LIST &l){
	NODE *tg=l.pHead;
	while(tg!=NULL){
		NODE *p=tg;
		tg=tg->pNext;
		free(p);
	}
}
void find(LIST &l,int data){
	NODE *p;
	int count =0,check=0;
	for (p=l.pHead;p!=NULL;p=p->pNext){
		if(p->data==data) {
			printf("\n Phan tu co gia tri %d nam o vi tri thu %d trong day",data,count);
			check =1;
		}
		count++;
	}
	if (check==0) printf("Phan tu khong co trong danh sach");
	getch();
}
void clone(LIST &s1,LIST &l){
	del(s1);
	for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
		NODE *tmp;
		tmp= initnode(p->data);
		addlast(s1,tmp);
	}
}
void append(LIST &l,LIST &s1){
	l.pTail->pNext=s1.pHead;
	l.pTail=s1.pTail;
}
void reverse(LIST &l){
	NODE *current,*parent;
	parent = l.pHead;
	current = l.pHead->pNext;
	l.pHead= current->pNext;
	parent->pNext=NULL;
	current->pNext=parent;
	while(l.pHead->pNext!=NULL){
		parent=current;
		current=l.pHead;
		l.pHead=l.pHead->pNext;
		current->pNext=parent;
	}	
	l.pHead->pNext=current;
}
void swap(int &a,int &b){
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
/*void sort(LIST &l,int type){
	int min = l.pHead->data;
	if (type==1){
		for (NODE *p=l.pHead;p!=NULL;p=p->pNext){
				if (p->data > k->data){
				min=p->data;
				}
			}
		}
	}
	else if (type==2){
		for (NODE *p=l.pHead;p!=l.pTail;p=p->pNext){
			for (NODE *k=p->pNext;k!=NULL;k=k->pNext){
				if (p->data < k->data){
				swap(p->data,k->data);
				}
			}
		}
	}
	
}*/
void menu(LIST &l){
	int luachon;
	char check='n';
	while(1){
		system("cls");
		printf("\n===================================NHAP VAO LUA CHON=========================================");
		printf("                                     \n1,Them node vao danh sach");
		printf("                                     \n2,Them node vao o vi tri bat ki");
		printf("                                     \n3,Xoa phan tu o vi tri bat ki");
		printf("                                     \n4,Tim phan tu");
		printf("                                     \n5,Tao list clone");
		printf("                                     \n6,Noi list S1 vao list ban dau");
		printf("                                     \n7,Dao nguoc list ban dau");
		printf("                                     \n8,Sap xep list ban dau");
		printf("                                     \n9,Giai phong bo nho cho danh sach");
		printf("                                     \n10,In danh sach lien ket don");
		printf("                                     \n11,Thoat");
		printf("                                     \nNhap tu 1-11 de lua chon, nhan phim khac de thoat\n");
		scanf("%d",&luachon);
		if (luachon==1){
			int x;
			printf("Nhap gia tri so nguyen: ");
			scanf("%d",&x);
			NODE *p=initnode(x);
		    addlast(l,p);
		}
		else if (luachon==2){
			int x,vitri;
			printf("Nhap gia tri so nguyen can them: ");
			scanf("%d",&x);
			printf("Nhap vi tri can them vao: ");
			scanf("%d",&vitri);
			add(l,x,vitri);
		}
		else if (luachon==3){
			int n;
			printf("\nNhap vao vi tri can xoa: ");
			scanf("%d",&n);
			remove(l,n);
		}
		else if(luachon==4){
			int n;
			printf("Nhap vao gia tri can tim: ");
			scanf("%d",&n);
			find(l,n);
		}
		else if (luachon==5){
			LIST s1;
			init(s1);
			clone(s1,l);
			printf("\nList clone tao ra la :\n");
			printlist(s1);
			getch();
		}
		else if (luachon==6){  //xem lai
			LIST s1;
			NODE *p;
			int x,n;
			printf("\nKhoi tao list s1");
			init(s1);
			printf("\nSo luong phan tu cua list la: ");
			scanf("%d",&n);
			for (int i=0;i<n;i++){
				printf("\nNhap gia tri node thu %d: ",i);
				scanf("%d",&x);
				p= initnode(x);
				addlast(s1,p);
			}
			printf("\nList s1 da nhap vao la: ");
			printlist(s1);
			append(l,s1);
			printf("\nDanh sach sau khi noi la: ");
			printlist(l);
			getch();
		}
		else if(luachon==7){
			reverse(l);
			printf("\nDa dao nguoc danh sach");
			getch();
		}
		else if(luachon==8){
			int chon;
			printf("Lua chon kieu sap xep");
			printf("\n1,Sap xep tang dan");
			printf("\n2,Sap xep giam dan\n");
			scanf("%d",&chon);
		//	sort(l,chon);
			printf("\nDanh sach da duoc sap xep");
			getch();
		}
		else if(luachon==9){
			del(l);
			printf("\nDa giai phong");
			getch();
		}
		else if(luachon==10){
			printlist(l);
			getch();
		}
		else {
			printf("Chac chan thoat chu? (Y/N) ");
			fflush(stdin);
			scanf("%c",&check);
			if(check=='Y'||check=='y') break;
		}
	}
}
int main(){
	LIST l;
	init (l);
	menu(l);
	printf("\nSo luong node trong danh sach la : %d",size(l));
	return 0;
}

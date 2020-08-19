#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sinhvien{
	struct hoso{
		char ml[10];
		char ht[35];
		long shsv;
		int diem;
	}data;
	struct sinhvien *next;
};

typedef struct sinhvien SV;
SV *newsv(char ml[],char ht[],long shsv,int diem){
	SV *p;
	p=(SV *)malloc(sizeof(SV));
	strcpy(p->data.ml,ml);
	strcpy(p->data.ht,ht);
	p->data.shsv=shsv;
	p->data.diem=diem;
	p->next=NULL;
	return p;
}
void themsinhvien(SV *&head){
	char ml[10];
	char ht[35];
	long shsv;
	int diem;
	printf("Nhap ma lop: ");
	fflush(stdin);
	gets(ml);
	printf("\nNhap ho ten: ");
	fflush(stdin);
	gets(ht);
	printf("\nNhap shsv: ");
	fflush(stdin);
	scanf("%d",&shsv);
	printf("\nNhap diem: ");
	scanf("%d",&diem);
	SV *p= newsv(ml,ht,shsv,diem);

	if (head==NULL){
		head=p;
	}
	else {
		SV *q=head;
		while(q->next!=NULL) q=q->next;
		q->next=p;
	}
}
void swap(SV *p,SV *q){
	SV *k;
	k =(SV *)malloc(sizeof(SV));
	k->data=p->data;
	p->data=q->data;
	q->data=k->data;
}
void sapxepdanhsach(SV *head){
	for (SV *p=head;p->next!=NULL;p=p->next){
		for (SV *q=p->next;q!=NULL;q=q->next){
			if (strcmp(q->data.ml,p->data.ml)<0) swap(p,q);
		}
	}
}
void indanhsach(SV *head){
	int n=0;
	SV *p=head;
	printf("\nSTT          Ma Lop          Ho va ten           Shsv      Diem");
	while (p!=NULL){
	printf("\n%-12d %-15s %-19s %-9d %d",n+1,p->data.ml,p->data.ht,p->data.shsv,p->data.diem);
	n++;
	p=p->next;
	}
}
int main(){
	SV *head=NULL;
	int chon;
	char thoat;
	while (1){
		printf("\n===================Lua chon=====================");
		printf("\n1,Them sinh vien");
		printf("\n2,In danh sach");
		printf("\n3,Sap xep danh sach");
		printf("\n4,Thoat\n");
		scanf("%d",&chon);
		if (chon==1) themsinhvien(head);
		else if (chon==2) indanhsach(head);
		else if (chon==3) sapxepdanhsach(head);
		else {
			printf("\nThoat nhe?(y/n)");
		    fflush(stdin);
			scanf("%c",&thoat);
			if (thoat =='y'||thoat=='Y') break;
		}
		printf("\nTiep tuc chu?(y/n): ");
		fflush(stdin);
		scanf("%c",&chon);
		if (chon=='n'||chon=='N') break;
	}

	return 0;
}


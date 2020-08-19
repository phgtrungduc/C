#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char **ds,tg,ht[50];
int n=0,ts=50;
void bosung();
void sapxep();
void inds();
void sapxepVN();
int main(){
	char ch;
	while (1){
		system("cls");
		printf("\n \n \n \n");
		printf("\n                   QUAN LY SINH VIEN");
		printf("\n                   1. Bo sung danh sach");
		printf("\n                   2. Sap xep danh sach");
		printf("\n                   3. Sap xep kieu Viet Nam");
		printf("\n                   4. In danh sach");
		printf("\n                   Bam 1-4 de chon, nhan phim khac de thoat");
		fflush(stdin);
		ch=getch();
		if (ch =='1') bosung();
		else if (ch=='2') sapxep();
		else if (ch=='3') sapxepVN();
		else if (ch=='4') inds();
		else {
			printf("\n Chan roi a? Y/...");
			fflush(stdin);
  			ch = getch();
			if (ch=='Y'|| ch=='y') break;
		}
	}
	return 0;
}
void bosung(){
	while (n<1000){
		printf("\nNhap ho va ten sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(ht);
		if (ht[0]=='\0') break;
		ds[n]= new char *[strlen(ht)+1];
		strcpy(ds[n],ht);
		n++;
		if (n==ts){
			char **ds2;
			ts+=50;
			ds2= new char *[ts];
			for (int i=0;i>n;i++){
			ds2[i]=ds[i];	
			}
			delete[]ds;
			ds= ds2;
		}
	}
}
void sapxep(){
	int i,j,k;
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++){
		if (strcmp(hoten[i],hoten[j])>0){
			strcpy(tg,ds[i]);
			strcpy(ds[i],ds[j]);
			strcpy(ds[j],tg);
		}
		}
	}
	printf("\n Danh sach da sap xep xong!");
	getch();
}
void inds(){
	int i;
	printf("\nDanh sach da nhap: ");
	for (i=0;i<n;i++){
		printf("\n %s ",hoten[i]);
	}
	getch();
}
int namepos(char *s){
	int i=strlen(s);
	while(s[i]==' ') i--;
	while (s[i]!=' ') i--;
	return i+1;
}
void sapxepVN(){
	int i,j,dai,dem;
	char tg[30];
    for (i=0;i<n-1;i++){
    	for (j=i+1;j<n;j++){
    		if (strcmp((hoten[i]+tenpos(hoten[i])),(hoten[j]+tenpos(hoten[j])))>0){
    			strcpy(tg,hoten[i]);
    			strcpy(hoten[i],hoten[j]);
    			strcpy(hoten[j],tg);
			}
			else if (strcmp((hoten[i]+tenpos(hoten[i])),(hoten[j]+tenpos(hoten[j])))==0){
				if (strcmp(hoten[i],hoten[j])>0){
				strcpy(tg,hoten[i]);
    			strcpy(hoten[i],hoten[j]);
    			strcpy(hoten[j],tg);
				}
			}
		}	
	}
	printf("\nDanh sach da sap xep xong theo kieu tieng Viet");
}

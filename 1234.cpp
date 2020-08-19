#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
int n=0;
char **ds=(char **)malloc(100*sizeof(char **)); 
char *daoten(char *s){
	int k= strlen(s);
	int n;
	char *p;
	p = (char *)malloc(30*sizeof(char));
	int i;
	for (i=k-1;i>=0;i--){
		if (s[i]==' ') {
			n=i;
			break;
		}
	}
	if (i==-1){
		strcpy(p,s);
	}
	else {
		int dem=0;
		for (int j=n+1;j<k;j++){
			p[dem]=s[j];
			dem++;
		}
		p[dem]=' ';
		dem++;
		for (int j=0;j<n;j++){
			p[dem]=s[j];
			dem++;
		}
		p[dem]='\0';
	}
	return p;
}
void them(){
	while(n<100){
		ds[n]=(char *)malloc(50*sizeof(char));
	printf("Nhap ten sinh vien thu %d: ",n+1);
	fflush(stdin);
	gets(ds[n]);
	if (ds[n][0]=='\0') break;
	n++;
	}
}
void sapxep(){
	char s[50],p[50],tg[50];
	for (int i=0;i<n-1;i++){
		for (int j=i+1;j<n;j++){
			strcpy(s,daoten(ds[i]));
			strcpy(p,daoten(ds[j]));
			if (strcmp(p,s)<0) {
				strcpy(tg,ds[i]);
				strcpy(ds[i],ds[j]);
				strcpy(ds[j],tg);
			}
		}
	}
	printf("\nsap xep xong roi ne!");

}
void indanhsach(){
	for (int i=0;i<n;i++){
		puts(ds[i]);
	}
	getch();
}
int main(){
	int chon;
	char check;
	while (1){
		printf("==============================LUA CHON=========================");
		printf("\n1,Them vao danh sach");
		printf("\n2,Sap xep danh sach");
		printf("\n3,In danh sach");
		printf("\n4,thoat");
		printf("\nNhap vao lua chon:  ");
		scanf("%d",&chon);
		if(chon==1) them();
		else if (chon==2) sapxep();
		else if(chon==3) indanhsach();
		else if (chon==4) {
			printf("chac chan thoat chu? (y/n) ");
			fflush(stdin);
			scanf("%c",&check);
			if (check=='y'||check=='Y') break;
		}
		printf("Tiep tuc khong? ");
		fflush(stdin);
		scanf("%c",&check);
		if (check=='n'||check=='N') break;
	}
	return 0;
}

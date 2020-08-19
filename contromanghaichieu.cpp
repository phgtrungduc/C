#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
char **p= (char **)malloc(100*30*sizeof(char));   
char *tg= (char *) malloc(30*sizeof(char));
int n=0;
void bosung();
void sapxep();
void inds();
int main(){
	char ch;
	while (1){
		system("cls");
		printf("\n \n \n \n");
		printf("\n                   QUAN LY SINH VIEN");
		printf("\n                   1. Bo sung danh sach");
		printf("\n                   2. Sap xep danh sach");
		printf("\n                   3. In danh sach");
		printf("\n                   Bam 1-3 de chon, nhan phim khac de thoat");
		fflush(stdin);
		ch=getch();
		if (ch =='1') bosung();
		else if (ch=='2') sapxep();
		else if (ch=='3') inds();
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
	while (n<100){
		printf("\nNhap ho va ten dem sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(p[n]);
		if (p[n][0]=='\0') break;
		n++;
	}
}
void sapxep(){
	int i,j,k;
	for (i=0;i<n-1;i++){
		for (j=i+1;j<n;j++){
		if (strcmp(p[i],p[j])>0){
			strcpy(tg,p[i]);
			strcpy(p[j],tg);
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
		printf("\n %s ",*(p+i));
	}
	getch();
}

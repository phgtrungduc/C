//chua mo file, tim hieu mo file ghi file va luu file
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int ts=100;
FILE *f;
char **ds,**gt,**clas,**stnum,**birth;
int num;
char *tg=(char *)malloc (50*sizeof(char));
char ht[50];
int n=0,nold=0;

struct SV{
	char hoten[100];
	char lop[10];
	char gioitinh[5];
	char mssv[10];
	char sinhnhat[10];
}sv1;
void bosung();
void inds();
void sapxepVN();
int main(){
	char ch;
	int i = 0;
	f=fopen("D://em.txt","rb");
	if (f!=NULL){
		fseek(f,0 , 2);
		n = ftell(f)/sizeof(SV);
		ts = 50*(n/50+1);
		ds = (char**)malloc(ts*sizeof(char*));
		gt = (char**)malloc(ts*sizeof(char*));
		clas = (char**)malloc(ts*sizeof(char*));
		stnum = (char**)malloc(ts*sizeof(char*));
		birth = (char**)malloc(ts*sizeof(char*));
		nold = n;
		fseek(f, 0, 0);
		while(fread((&sv1),sizeof(SV),1,f)) {
			ds[i] = (char *)malloc((strlen(sv1.hoten)+1)*sizeof(char));
			strcpy(ds[i],sv1.hoten);
			clas[i] = (char *)malloc((strlen(sv1.lop)+1)*sizeof(char));
			strcpy(clas[i],sv1.lop);
			gt[i] = (char *)malloc((strlen(sv1.gioitinh)+1)*sizeof(char));
			strcpy(gt[i],sv1.gioitinh);
			stnum[i] = (char *)malloc((strlen(sv1.mssv)+1)*sizeof(char));
			strcpy(stnum[i],sv1.mssv);
			birth[i] = (char *)malloc((strlen(sv1.sinhnhat)+1)*sizeof(char));
			strcpy(birth[i],sv1.sinhnhat);
			i++;
		}
	}
	else {
		ds = (char**)malloc(ts*sizeof(char*));
		gt = (char**)malloc(ts*sizeof(char*));
		clas = (char**)malloc(ts*sizeof(char*));
		stnum = (char**)malloc(ts*sizeof(char*));
		birth = (char**)malloc(ts*sizeof(char*));
	}
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
		else if (ch=='2') sapxepVN();
		else if(ch=='3') inds();
		else {
			printf("\n Chan roi a? Y/...");
			fflush(stdin);
  			ch = getch();
			if (ch=='Y'|| ch=='y') break;
		}
	}
if (n != nold) {
		f=fopen("D://em.txt","wb");
		for(int i = 0; i< n; i++) {
			strcpy(sv1.hoten, ds[i]);
		//	free(ds[i]);
			strcpy(sv1.lop, clas[i]);
		//	free(clas[i]);
			strcpy(sv1.gioitinh, gt[i]);
		//	free(gt[i]);
			strcpy(sv1.mssv, stnum[i]);
		//	free(stnum[i]);
			strcpy(sv1.sinhnhat, birth[i]);
		//	free(birth[i]);
			fwrite(&sv1, sizeof(sv1), 1, f);
		}
		fclose(f);
	}
	else for(i = 0; i < n; i++) {
		free(ds[i]);
		free(clas[i]);
		free(gt[i]);
		free(stnum[i]);
		free(birth[i]);
	}
	free(ds);
	return 0;
}
void bosung(){
	while (1){
		printf("\nNhap ho va ten dem sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(sv1.hoten);
		if (sv1.hoten[0] =='\0') break;
		ds[n]= (char *)malloc((strlen(sv1.hoten)+1)*sizeof(char));	
		ds[n]=sv1.hoten;
		printf("\nNhap lop sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(sv1.lop);
		clas[n]= (char *)malloc((strlen(sv1.lop)+1)*sizeof(char));	
		strcpy(clas[n],sv1.lop);
		printf("\nNhap gioi tinh sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(sv1.gioitinh);
		gt[n]= (char *)malloc((strlen(sv1.gioitinh)+3)*sizeof(char));	
		strcpy(gt[n],sv1.gioitinh);
		printf("\nNhap mssv sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(sv1.mssv);
		stnum[n]= (char *)malloc((strlen(sv1.mssv)+1)*sizeof(char));	
		strcpy(stnum[n],sv1.mssv);
		printf("\nNhap sinh nhat sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(sv1.sinhnhat);
		birth[n]= (char *)malloc((strlen(sv1.sinhnhat)+1)*sizeof(char));	
		strcpy(birth[n],sv1.sinhnhat);
		n++;
     	if(n==ts){
     		ts*=2;
		    ds = (char**)realloc(ds,ts*sizeof(char*));
		    clas = (char**)realloc(clas,ts*sizeof(char*));
		    gt = (char**)realloc(gt,ts*sizeof(char*));
		    stnum= (char**)realloc(stnum,ts*sizeof(char*));
		    birth = (char**)realloc(birth,ts*sizeof(char*));
		}
	}
}
void sapxep(){
	int i,j,k;
	for (i=0;i<n-1;i++){
		for (j=i+1;j<n;j++){
		if (strcmp(ds[i],ds[j])>0){
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
		printf("\n %s ",ds[i]);
	}
	getch();
}
int namepos(char *s){
	int i= strlen(s);
	while (s[i]==' '&&i>-1) i--;   // phai cho >-1 vi voi truong hop ten SV chi co 1 ten: vi du nhu: dong, duc ... thi ham namepos nay tra ve gia tri sai
	while (s[i]!=' '&&i>-1) i--;
	return i+1;
}
void sapxepVN(){
	int i,j,dai,dem;
	char tg[30];
    for (i=0;i<n-1;i++){
    	for (j=i+1;j<n;j++){
    		if (strcmp((ds[i]+namepos(ds[i])),(ds[j]+namepos(ds[j])))>0){
    			strcpy(tg,ds[i]);
    			strcpy(ds[i],ds[j]);
    			strcpy(ds[j],tg);
			}
			else if (strcmp((ds[i]+namepos(ds[i])),(ds[j]+namepos(ds[j])))==0){
				if (strcmp(ds[i],ds[j])>0){
				strcpy(tg,ds[i]);
    			strcpy(ds[i],ds[j]);
    			strcpy(ds[j],tg);
				}
			}
		}	
	}
	printf("\nDanh sach da sap xep xong");
}

.//chua mo file, tim hieu mo file ghi file va luu file
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
char **ds;
char *tg=(char *)malloc (50*sizeof(char));
FILE *f;
char ht[50];
int n=0,ts=100,nold =0;
void bosung();
void inds();
void sapxepVN();
struct SV{
	char hoten[50];
} sv1;
int main(){
	char ch;
	f = fopen("D://tep.txt","rb");
	if (f!=NULL){
		fseek(f,2,0);
		n= ftell(f)/sizeof(sv1);
		nold = n;
		fseek(f,0,0);
		ts= 50*(n/50+1);
		ds = (char **) malloc(ts*sizeof(char));
		for (int i=0;i<n;i++){
			fread(&sv1,sizeof(sv1),1,f);
			ds[i]=(char *)malloc(strlen(sv1.hoten)+1);
			strcpy(ds[i],sv1.hoten);
		}
	}
	else ds= (char **)malloc(ts*sizeof(char));
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
	if (nold!=n){
		f= fopen("D://tep.txt","rb");
		for (int i=0;i<n;i++){
		strcpy(sv1.hoten,ds[i]);
		free(ds);
		fwrite(&sv1,sizeof(sv1),1,f);
		}
		fclose(f);
	}
	else {
		for (int i=0;i<n;i++) free(ds[i]);
	    free(ds);
	    fclose(f);
	}
	return 0;
}
void bosung(){
	while (n<100){
		printf("\nNhap ho va ten dem sinh vien thu %d: ",n+1);
		fflush(stdin);
		gets(ht);
		if (ht[0] =='\0') break;
		ds[n]= (char *)malloc((strlen(ht)+1)*sizeof(char));	
		strcpy(ds[n],ht);
		n++;
     	if(n==ts){
		ts*=2;
		realloc(ds,ts*sizeof(char));
		}
	}
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
	getch();
}

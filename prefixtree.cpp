#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tnode{
	int endofword;
	struct tnode *child[26];
};
typedef struct tnode NODE;
NODE *newnode(){
	NODE *p;
	p= (NODE *)malloc(sizeof(NODE));
	for (int i=0;i<26;i++){
		p->child[i]=NULL;
	}
	return p;
}
int checkword(NODE *root,char x[]){
	int n = strlen(x);
	NODE *p=root;
	for (int i=0;i<n;i++){
		if (p->child[x[i]-'a']==NULL) {
			return 0;
		}
		else p=p->child[x[i]-'a'];
	}
	return 1;
}
void addword(NODE *root,char x[]){
	NODE *p=root;
	int n=strlen(x);
	int index;
	for (int i=0;i<n;i++){
		index = x[i]-'a';
		if(p->child[index]==NULL){
			p->child[index]=newnode();
		}
		p=p->child[index];
	}
	p->endofword=1;
}	
int check=0;
int j=0;
void suggest(NODE *root,char a[],char b[3][100],int level){
	if (checkword(root,a)==0) return;
	int n=strlen(a);
	NODE *p=root;
	if (check==3) return ;
	if(level<n){
		for (int i=0;i<n;i++){
			if(p->child[a[i]-'a']) p=p->child[a[i]-'a'];
			for (int j=0;j<3;j++){
				b[j][i]=a[i];
			}
		}
		level=n;
	}
	if(p->endofword==1){
		b[j][level]='\0';
		check++;
		j++;
		level =n;
		return ;
	}
	for (int i=0;i<26;i++){
		if (p->child[i]) {
			b[j][level] = i + 'a'; 
            suggest(p->child[i],a,b, level + 1); 
		}
	}
}

int main(){
	int dem=0,dem2=0;
	NODE *root;
	root = newnode();//tao ra goc
	char tg[30];
	char **tudien;
	tudien = (char **)malloc(15000*sizeof(char*));
	FILE *f;
	f=fopen("D://tudien.txt","r+");
	if (f==NULL){
		printf("Mo file tu dien khong thanh cong");
	}
	else {
		int i=0;
		while(feof(f)==0){
			fscanf(f,"%s",&tg);
			int n = strlen(tg);
			tudien[i]= (char *)malloc((n+1)*sizeof(char));
			strcpy(tudien[i],tg);
			i++;
		}
		dem=i;
		fclose(f);
	}
	for (int i=0;i<dem;i++){    //them tu tu dien vao cay
		addword(root,tudien[i]);
	}
	char **vanban;
	vanban = (char **)malloc(100*sizeof(char *));
	f =fopen("D://vanban.txt","r+");
	if (f==NULL){
		printf("Mo file van ban khong thanh cong");
	}
	else {
		int i=0;
		while(feof(f)==0){
			fscanf(f,"%s",&tg);
			int n = strlen(tg);
			vanban[i]= (char *)malloc((n+1)*sizeof(char));
			strcpy(vanban[i],tg);
			i++;
		}
		dem2=i;
		fclose(f);
	}
	NODE *root2;
	root2=newnode();
	for (int i=0;i<dem2;i++){
		addword(root2,vanban[i]);
	}
	char b[3][100];
	char c[3][100];
	char a[100];
	strcpy(a,"hel");
	suggest(root,a,b,0);
	printf("%s",b[0]);
	printf("\n");
	printf("%s",b[1]);
	printf("\n");
	printf("%s",b[2]);
	printf("\n");
/*	printf("%s",c[0]);
	printf("\n");
	printf("%s",c[1]);*/
	return 0;
}


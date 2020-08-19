#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void copy(char *p,char *dest){
	int n = strlen(dest);
	for (int i=0;i<=n;i++){
		p[i]=dest[i];
	}
}
void swap(char *s,char *p){
	char *tg;
	tg = (char *)malloc(50*sizeof(char));
	strcpy(tg,s);
	strcpy(s,p);
	strcpy(p,tg);
}
int main(){
	char *a = (char *)malloc(15*sizeof(char));
	char *b= (char *)malloc(15*sizeof(char));
	gets(a);
	gets(b);
	swap(a,b);
	puts(a);
	puts(b);
	return 0;
}

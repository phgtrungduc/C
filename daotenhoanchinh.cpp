#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *daoten(char *s){
	int n=strlen(s);
	n--;
	while (s[n]==' '){
		n--;
	}
	int dem;
	int i;
	for (i=n;i>=0;i--){
		if (s[i]==' ') {
			dem=i;
			break;
		}
	}
	char *p=(char *)malloc(30*sizeof(char));
	if (i==-1){
		strcpy(p,s);
	}
	else {
		int j=0;
		for (int i=dem+1;i<=n;i++){
			p[j]=s[i];
			j++;
		}
		p[j]=' ';
		j++;
		for (int i=0;i<dem;i++){
			p[j]=s[i];
			j++;
		}
		p[j]='\0';
	}
	return p;
}
int main(){
	char *s,*p;
	s= (char *)malloc(30*sizeof(char));
	p= (char *)malloc(30*sizeof(char));
	gets(s);
	gets(p);
	puts(daoten(s));
	puts(daoten(p));
	return 0;
}

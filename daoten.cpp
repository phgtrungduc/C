#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
int main(){
	int a=5;
	float b=9.5;
	int c=a+b;
	printf("%d",c);
	return 0;
}

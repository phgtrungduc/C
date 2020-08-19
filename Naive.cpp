#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int naiveal(char *a,int n,char *b,int m){
	for (int i=0;i<=n-m;i++){
		int j=0;
		for(j=0;j<m;j++){
			if (b[j]!=a[i+j]) break;
		}
		if (j==m) return 1;
	}
	return 0;
}
int main(){
	char *a,*b;
	a=(char *)malloc(30*sizeof(char));
	b=(char *)malloc(30*sizeof(char));
	gets(a);
	gets(b);
	int n=strlen(a);
	int m=strlen(b);
	if (naiveal(a,n,b,m)) printf("tim thay ");
	else printf("khong tim thay");
	return 0;
}

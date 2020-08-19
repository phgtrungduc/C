#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int check(char *a,char *b){
	if (strlen(a)!=strlen(b)) return 0;
	int n=strlen(a);
	int index[n],dem=0;
	for (int i=0;i<n;i++){
		if (a[i]!=b[i]) {
			index[dem]=i;
			dem++;
		}
	}
	if (dem!=2) return 0;
	else {
		if (a[index[0]]==b[index[1]]&&a[index[1]]==b[index[0]]) return 1;
		else return 0;
	}
}
int main(){
	char *a,*b;
	a = (char *)malloc(30*sizeof(char));
	b= (char *)malloc(30*sizeof(char));
	fflush(stdin);
	gets(a);
	fflush(stdin);
	gets(b);
	if (check(a,b)) printf("thoa man");
	else printf("khong thoa man");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void check(char *s,char key){
	int size= strlen(s);
	s[size]=key;
	int i=0;
	while (s[i]!=key&&i<=size){
		i++;
	}
	if (i<size) printf("tim thay");
	else printf("khong thay");
}
int main(){
	char *p;
	p=(char *)malloc(30*sizeof(char));
	gets(p);
	char key;
	printf("Nhap key: ");
	scanf("%c",&key);
	check(p,key);
	return 0;
}

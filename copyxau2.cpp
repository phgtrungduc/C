#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void copyxau(char *s,char *p){
	s = (char *)malloc((strlen(p)+1)*sizeof(char));
	strcpy(s,p);
}
int main(){
//	char *a=(char *)malloc(30*sizeof(char));
//	gets(a);
//	char *p;
//	copyxau(p,a);
//	puts(a);
//	printf("%d",strlen(a));
void *p;
int x=5;
p=&x;
printf("%d ",*(int *)p);
	return 0;
}

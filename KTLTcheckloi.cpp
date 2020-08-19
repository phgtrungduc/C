#include<stdio.h>
int main(){
	char s[10];
	int i;
	for (i=0;(s[i]=getchar())!='\n'&&i<9;i++);
	s[i]='\0';
	puts(s);
	return 0;
}

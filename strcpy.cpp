#include<stdio.h>
#include<string.h>
int main(){
	char a[100],b[100];
	printf("\n Nhap chuoi a:");
	fflush(stdin);
	gets(a);
	strcpy(b,strchr(a,'c')); 
	puts(b);
	return 0;
}

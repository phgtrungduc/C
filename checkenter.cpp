#include<stdio.h>
int main(){
	char a[10];
	int n=0,i;
	while (1){
		printf("Nhap a[%d]= ",n);
		fflush(stdin);
		gets(a[i]);
		if (a[i]== '\0') break;
		else n++;
	}
	printf("%d",n);
	return 0;
}

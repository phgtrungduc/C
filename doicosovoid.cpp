#include<stdio.h>
void chuyencoso(int base,int number){
	char deohieu[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	if (number<=0) return ;
	chuyencoso(base,number/base);
	printf("%c",deohieu[number%base]);
}
void chuyencoso2(int base,int number){
	char deohieu[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	char a[100];
	int dem=0;
	while (number!=0){
		a[dem++]=deohieu[number%base];
		number=number/base;
	}
	dem--;
	for (int i=dem ;i>=0;i--){
		printf("%c",a[i]);
	}
}
int main(){
	chuyencoso2(2,11);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int concac(int i){
	static int j=5;
	j=j+i;
	return j;
}
int main(){
	printf("%d  ",concac(2));
	printf("%d  ",concac(3));
	return 0;
}

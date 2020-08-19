#include<stdio.h>
int tohop(int chap,int n){
	if (chap==0) return 1;
	else if (chap==1) return n;
	else if (n==chap) return 1;
	else return (tohop(chap-1,n-1)+tohop(chap,n-1));
}
int main(){
	printf("%d",tohop(3,15));
	return 0;
}

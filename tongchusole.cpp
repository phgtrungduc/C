#include<stdio.h>
int tongchusole(int n){
	if (n==0) return 0;
	if (n<0) n=-n;
	else {
		if (n%2==0) return tongchusole(n/10);
		else return n%10+tongchusole(n/10);
	}
}
int tongchusole2(int n){
	int tong=0;
	while (n!=0){
		int a = n %10;
		if (n%2!=0) tong = tong + n%10;
		n = n /10; 
	}
	return tong;
}
int main(){
	printf("%d ",tongchusole2(1234579));
}

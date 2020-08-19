#include<stdio.h>
int so(int n){
	if (n<4) return n;
	else return (so(n-3)+so(n-2)+so(n-1)); 
}
/*int tong(int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong += so(i);
	}
	return tong;
}*/
int tong (int n){
	int h1=1,h2=2,h3=3,h=0,tong =6;
	if (n==1) return 1;
	else if(n==2) return 2;
	else if (n==3) return 6;
	else {
		for (int i=4;i<=n;i++){
			h=h1+h2+h3;
			tong = tong +h;
			h1=h2;
			h2=h3;
			h3=h;
		}
		return tong;
	}
}
int main(){
	printf("%d",tong(6));
	return 0;
}

#include<stdio.h>
int y(int n);
int x(int n){
	if (n>0&&n<=5) return n;
	else {
		return y(n-1)+x(n-2)+y(n-3)+x(n-4)+y(n-5);
	}
}
int y(int n){
	if (n>0&&n<=5) return 2*n;
	else {
		return x(n-1)+y(n-2)+x(n-3)+y(n-4)+x(n-5);
	}
}
int y1(int n);
int x1(int n){
	int a[6];
	if (n>0&&n<=5) return n;
	else {
		a[1]=1;a[2]=2;a[3]=3;a[4]=4;a[5]=5;
		for (int i=6;i<=n;i++){
			a[i%6]=y1(i-1)+a[(i-2)%6]+y1(i-3)+a[(i-4)%6]+y1(i-5);
		}                                     
	}
	return a[n%6];
}
int y1(int n){
	int a[6];
	if (n>0&&n<=5) return 2*n;
	else {
		a[1]=2;a[2]=4;a[3]=6;a[4]=8;a[5]=10;
		for (int i=6;i<=n;i++){
			a[i%6]=x1(i-1)+a[(i-2)%6]+x1(i-3)+a[(i-4)%6]+x1(i-5);
		}                                     
	}
	return a[n%6];
}
int main(){
	printf("%d  ",x(10));
	printf("%d  ",y(10));
	printf("%d  ",x1(10));
	printf("%d  ",y1(10));
	return 0;
}

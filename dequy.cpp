#include<stdio.h>
int H(int n){
	if (n<3) return n;
	else return (2*H(n-1)*H(n-2));
}
/*int tong(int n){
	int tong=0;
	for (int i=1;i<=n;i++){
		tong +=H(i);
	}
	return tong;
}*/

int tong(int n){
	int h[3];
	h[0]=1;
	h[1]=2;
	h[2]=0;
	int tong=0;
	if (n==1) return 1;
	else if (n==2) return 3;
	else {
		for (int i=3;i<=n;i++){
			h[(i-1)%3]=2*h[(i-2)%3]*h[(i-3)%3];
			tong = tong +h[k];
		}
		return tong;
	}
}
int main(){
	printf("%d",tong(5));
}

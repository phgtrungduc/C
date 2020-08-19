#include<stdio.h>
int so(int n){
	if (n>0&&n<=3) return n;
	else return so(n-1)+so(n-2)+so(n-3);
}
int tong(int n){
	int ton=0;
	for (int i=1;i<=n;i++){
		ton=ton+so(i);
	}
	return ton;
}
int tong2(int n){
	if (n<=0) return 0;
	else if (n==1) return 1;
	else if (n==2) return 3;
	else if (n==3) return 6;
	else {
		int k1=1,k2=2,k3=3,k,ton=6;
		for (int i=4;i<=n;i++){
			k=k1+k2+k3;
			ton = ton+k;
			k1=k2;
			k2=k3;
			k3=k;
		}
		return ton;
	}
}
int tong3(int n){
	if (n<=0) return 0;
	else if (n==1) return 1;
	else if (n==2) return 3;
	else if (n==3) return 6;
	else {
		int k[4];
		int ton=6;
		k[1]=1;k[2]=2;k[3]=3;
		for (int i=4;i<=n;i++){
			k[i%4]=k[(i-1)%4]+k[(i-2)%4]+k[(i-3)%4];
			ton = ton + k[i%4];
		}
		return ton;
	}
}
int main(){
	printf("%d  \n",tong(9));
	printf("%d  \n",tong2(9));
	printf("%d  ",tong3(9));
	return 0;
}

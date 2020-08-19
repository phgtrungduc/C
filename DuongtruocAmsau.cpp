#include<stdio.h>
int a[]={-9,10,2,5,-3,-8,7,-6};
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void doicho(int L,int R){
	while (a[L]>0&&L<R) L++;
	while (a[R]<0&&R>L) R--;
	printf("L=%d  ",L);
	printf("R=%d  ",R);
	swap(a[L],a[R]);
	if (L<R)doicho(L,R);
}
int main(){
	int L=0;int R=7;
	doicho(L,R);
	for (int i=0;i<8;i++){
		printf("%d  ",a[i]);
	}
	return 0;
}

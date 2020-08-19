#include<stdio.h>
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}
void heapify(int a[],int n,int i){
	int L=2*i+1;
	int R=2*i+2;
	int max = i;
	if (L<n&&a[L]>a[max]) {
		max = L;
	}
	if (R<n&&a[R]>a[max]) {
		max = R;
	}
	if (max !=i){
		swap(a[max],a[i]);
		heapify(a,n,max);
	}
}
void maxheap(int a[],int n){
	for (int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
}
void add(int a[],int n,int value){
	a[n]=value;
	maxheap(a,n+1);
}
int main(){
	int a[]={1,5,3,9,8,20,15,17,60,35,90,12,85,36,74,100};
	int n=(sizeof(a)/sizeof(int));
	maxheap(a,n);
	for (int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	add(a,n,200);
	printf("\n");
	for (int i=0;i<n+1;i++){
		printf("%d  ",a[i]);
	}
	return 0;
}

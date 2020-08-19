#include<stdio.h>
void insertionsort(int a[],int size){
	for (int i=1;i<size;i++){
		int key=a[i];
		int j=i-1;
		while (j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main(){
	int a[]={4,3,2,10,12,1,5,6};
	int n=sizeof(a)/sizeof(int);
	insertionsort(a,n);
	for (int i=0;i<n;i++){
		printf("%d   ",a[i]);
	}
	return 0;
}

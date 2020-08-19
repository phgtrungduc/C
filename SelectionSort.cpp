#include<stdio.h>
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void selectionsort(int a[],int size){
	for (int i=0;i<size-1;i++){
		int min =i;
		for (int j=i+1;j<size;j++){
			if (a[j]<a[min]) {
				min=j;
			}
		}
		swap(a[i],a[min]);
	}
}
int main(){
	int a[]={20,7,59,10,12,99,50,53};
	int n= sizeof(a)/sizeof(int);
	selectionsort(a,n);
	for (int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	return 0;
}

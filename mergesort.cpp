#include<stdio.h>
void merge(int a[],int s,int m,int e){
	int n1=m-s+1;
	int n2 =e-m;
	int L[n1];
	int R[n2];
	for (int i=0;i<n1;i++){
		L[i]=a[i+s];
	}
	for (int i=0;i<n2;i++){
		R[i]=a[i+m+1];
	}
	int i=0,j=0,k=s;
	while (i<n1&&j<n2){
		if (L[i]>R[j]){
			a[k]=L[i];
			i++;
			k++;
		}
		else {
			a[k]=R[j];
			j++;
			k++;
		}
	}
	while (i<n1){
		a[k]=L[i];
		i++;
		k++;
	}
	while (j<n2){
		a[k]=R[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int s,int e){
	if (s<e){
		int m=(s+e)/2;
		mergesort(a,s,m);
		mergesort(a,m+1,e);
		merge(a,s,m,e);
	}
}
int main(){
	int a[]={10,5,2,3,9,6,90,8,3,7,4};
	mergesort(a,0,10);
	for (int i=0;i<11;i++){
		printf("%d   ",a[i]);
	}
	return 0;
}


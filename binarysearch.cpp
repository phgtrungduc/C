#include<stdio.h>
int binarysearch(int A[],int key,int s,int e){
	int mid = (e+s)/2;
	if (s>e) return -1;
	if (A[mid]==key) return 1;
	else if (A[mid]<key) return binarysearch(A,key,0,mid-1);
	else return binarysearch(A,key,mid+1,e);
	
}
int main(){
	int a[5];
	for (int i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	if (binarysearch(a,5,0,5)==1) printf("co");
	else printf("khong");
	return 0;
}

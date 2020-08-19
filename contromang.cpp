#include<stdio.h>
int main(){
	int i,n,a[100];
	int *pa;
	pa=&a[0];
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("Nhap a[%d]= ",i);
		scanf("%d",(pa+i));
	}
	for (i=0;i<n;i++){
		printf("%d",a[i]);
	}
	return 0;
}

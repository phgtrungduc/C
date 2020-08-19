#include<stdio.h>
int main(){
	int n,i,j,k,maxsum,sum;
	printf("Nhap so phan tu cua day: ");
	scanf("%d",&n);
	int a[n];
	for (i=0;i<n;i++){
		printf("nhap a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	printf("Day da nhap la:\n");
	for (i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	for (i=0;i<n;i++){
		for(j=i;j<n;j++){
			sum = 0;
			for (k=i;k<=j;k++){
				sum=sum+a[k];
				if (sum > maxsum) {
					maxsum = sum;
				}
			}
		}
	}
	printf("Gia tri cuc dai la: %d",maxsum);
	return 0;
}

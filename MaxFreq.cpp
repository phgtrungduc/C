#include<stdio.h>
int maxfreq(int A[],int n){
	int xuathien[n];
	int daxet[n];
	for (int i=0;i<n;i++){
		daxet[i]=0;
		xuathien[i]=0;
	}
	for (int i=0;i<n-1;i++){
		if (daxet[i]==0){
			daxet[i]=1;
			for (int j=i+1;j<n;j++){
				if (A[j]==A[i]) xuathien[i]++;
			}
		}
	}
	int max=0;
	for (int i=1;i<n;i++ ){
		if (xuathien[i]>xuathien[max]) max = i;
	}
	return A[max];
}
int main(){
	int A[]={1,2,2,1,2,1,2};
	printf("%d",maxfreq(A,7));
	return 0;
}

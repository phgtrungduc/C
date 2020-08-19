#include<stdio.h>
void swap(int &a,int &b){
	int tg=a;
	a=b;
	b=tg;
}
int main(){
	int a[]={1,2,3,4,5,6,7,90,13};
	int n = sizeof(a)/sizeof(int);
	int check=1;
	int k=0;
	while(check==1){
		check =0;
		for (int i=0;i<n-1;i++){
			if(a[i]<a[i+1]) {
				swap(a[i],a[i+1]);
				check=1;
			}
		}
		printf("lan thu %d\n",k);
		k++;
	}
	for (int i=0;i<n;i++){
		printf("%d   ",a[i]);
	}
	return 0;
}

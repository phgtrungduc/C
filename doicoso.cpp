#include<stdio.h>
#include<math.h>
int dem=0;
int nhiphan(int n){
	if(n==0) {
		return 0;
	}
	return pow(10,level)*nhiphan(level-1,n/2);
}
int main(){
	int a[10];
	nhiphan(a,0,11);
	for (int i=dem;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0;
}

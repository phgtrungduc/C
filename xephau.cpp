#include<stdio.h>
#include<math.h>
int n,count;
int a[20];
int ghinhan(){
	int i;
	count++;
	printf("%i ",a[i]);
	printf("\n");
}
int UCVh(int j,int k){
	int i;
	for (i=1;i<k;i++){
		if ((j==a[i])||(fabs(j-a[i])==k-i)) return 0;
		return 1;
	}
}
int hau(int i){
	int j;
	for (j=1;j<=n;j++){
		if(UCVh(j,i)){
			a[i]=j;
			if(i==n) ghinhan();
			else hau(i+1);
		}
	}
}
int main(){
	printf("Input n= ");
	scanf("%i",&n);
	printf("\n========================ket qua====================");
	count =0;
	hau(1);
	if(count ==0) printf("\n Chiu");
	return 0;
}

#include<stdio.h>
#include<math.h>
int main(){
	int m,n,S=0;
	printf("Nhap: ");
	scanf("%d",&n);
	scanf("%d",&m);
	for (int i=2;i<=n;i++){
		if (m%i==0&&n%i==0){
			S=S+i;
		}
	}
	printf("%d",S);
	return 0;
}

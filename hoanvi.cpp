#include<stdio.h>
int n;
int a[3],b[3];
void init(){
	printf("\nNhap vao n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		b[i]=1;
	}
}
void ghinhan(){
	printf("\nPhuong an ghi nhan:\n");
	for (int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
void tryi(int k){
	for (int i=0;i<n;i++){
		if(b[i]==1) {
			a[k]=i;
			b[i]=0;
			if (k==n-1) ghinhan();
		    else tryi(k+1);
		    printf("\n k= %d",k);
		    printf("\ni= %d",i);
		    b[i]=1;
		}
    }
}
int main(){
	init();
	tryi(0);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int dem=0;
int *diff(int *a,int*b,int n,int m){
	int *c=(int *)malloc((n+m)*sizeof(int));
	for (int i=0;i<n;i++){
		int j=0;
		for (j=0;j<m;j++){
			if(a[i]==b[j]) break;
		}
		if (j==m) {
			c[dem]=a[i];
			dem++;
		}
	}
		for (int i=0;i<m;i++){
		int j=0;
		for (j=0;j<n;j++){
			if(b[i]==a[j]) break;
		}
		if (j==m) {
			c[dem]=b[i];
			dem++;
		}
	}
	return c;
}
int main(){
	int *a=(int *)malloc(5*sizeof(int));
	int *b=(int *)malloc(5*sizeof(int));
	for (int i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<5;i++){
		scanf("%d",&b[i]);
	}
	int *c = diff(a,b,5,5);
	for (int i=0;i<dem;i++){
		if(c[i]!=0) printf("%d  ",c[i]);
	}
	return 0;
}

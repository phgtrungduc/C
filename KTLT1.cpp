#include<stdio.h>
#include<stdlib.h>
int *emyeu(int *a,int *b,int sizea,int sizeb,int &dem){
	int size = (sizea > sizeb)?sizea:sizeb;
	int check;
	int *c = (int *)malloc(size*sizeof(int));
	for (int i=0;i<sizea;i++){
		check =0;
		for (int j=0;j<sizeb;j++){
			if (a[i]==b[j]) {
				check=1;
				break;
			}
			//if (check==1) break;
		}
		if (check==0) {
			c[dem]=a[i];
			dem++;
		}
	}
	for (int i=0;i<sizeb;i++){
		check =0;
		for (int j=0;j<sizea;j++){
			if (b[i]==a[j]) {
				check=1;
				break;
			}
		//	if (check==1) break;
		}
		if (check==0) {
			c[dem]=b[i];
			dem++;
		}
	}
	return c;
}
int main(){
	int *a,*b;
	int dem=0;
	a= (int *)malloc(5*sizeof(int));
	b =(int *)malloc(6*sizeof(int));
	for (int i=0;i<5;i++){
		printf("Nhap a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	for (int i=0;i<6;i++){
		printf("Nhap b[%d]= ",i);
		scanf("%d",&b[i]);
	}
	int *c= emyeu(a,b,5,6,dem);
	printf("%d",dem);
	for (int i=0;i<dem;i++){
		printf("%d\n",c[i]);
	}
	return 0;
}

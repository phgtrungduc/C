#include<stdio.h>
#include<stdlib.h>
void capphat(char *x){
	x = (char *)malloc(20*sizeof(char));
}
void  bitchange(int &x, int n) {
 x &=  ~(1 << (n - 1));
}
void sw(int *a, int *b) {
    *a ^=*b;
    *b ^=*a;
    *a ^=*b;
}
int main(){
	/*int **data;
	data = (int **)malloc(3*sizeof(int*));
	for (int i=0;i<3;i++){
		data[i]=(int *)malloc(5*sizeof(int));
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<5;j++){
			printf("a[%d][%d]= ",i,j);
			scanf("%d",&data[i][j]);
		}
	}
	for (int i=0;i<3;i++){
		for (int j=0;j<5;j++){
			printf("%d ",data[i][j]);
		}
		printf("\n");
	}
	for (int i=0;i<3;i++){
		free(data[i]);
	}
	free(data);*/
	/*int a=5,b=6;
	int *p=&a,*q=&b;
	a ^=b;
	printf("%d %d\n",a,b);
	b ^=a;
	printf("%d %d\n",a,b);
	a ^=b;
	printf("%d %d\n",a,b);*/
	int a[3][2];
	for(int i=0;i<3;i++){
		for (int j=0;j<2;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<3;i++){
		for (int j=0;j<2;j++){
			printf("%d   ",a[i][j]);
		}
		printf("\n");
	}
	printf("%d",a[3]);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct matran{
	int cot;
	int hang;
	int **p;
} MT;
void capphat(MT &a){
	printf("\nNhap so hang: ");
	scanf("%d",&a.hang);
	printf("\nNhap so cot: ");
	scanf("%d",&a.cot);
	a.p = (int **)malloc(a.hang*sizeof(int *));
	for (int i=0;i<a.hang;i++){
		a.p[i]=(int *)malloc(a.cot*sizeof(int));
	}
}
void nhapmatran(MT &a){
	for (int i=0;i<a.hang;i++){
		for (int j=0;j<a.cot;j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d",&a.p[i][j]);
		}
	}
}
void inmatran(MT a){
	for (int i=0;i<a.hang;i++){
		for (int j=0;j<a.cot;j++){
			printf("%d  ",a.p[i][j]);
		}
		printf("\n");
	}
}
MT operator + (MT a,MT &b){
	for (int i=0;i<a.hang;i++){
		for (int j=0;j<a.cot;j++){
			b.p[i][j]=a.p[i][j];
		}
	}
}
int abc(){
	
}
int main(){
//	int a=3,b=5;// 0010 0101 1000
	char *ch;
	ch= (char *)malloc(30*sizeof(char));
	gets(ch);
	ch[0] = ch[0]-('A'-'a');
	puts(ch);
	return 0;
}

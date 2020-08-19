#include<stdio.h>
#include<stdlib.h>
int main(){
	int phantu,i,*p,ar,*pp;
	*p=ar;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d",&phantu);
	p= (int*)malloc(phantu*(sizeof(int)));
	for (i=0;i<5;i++){
		printf("nhap phan tu thu %d: ",(i+1));
		scanf("%d",(p+i));
	}
//	realloc(p,phantu+1);
//	*(p+phantu)=200;
	for (i=0;i<5;i++){
		printf("phan tu thu %d la: %d\n",i+1,*(p+i));
	}
	printf("%d",sizeof(ar)/sizeof(ar[0]));
	free(p);
	return 0;
}

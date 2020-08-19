#include<stdio.h>
#include<math.h>
typedef struct matran{
	int hang;
	int cot;
	int **data;
}MT;
void capphat(MT &mt){
	mt.data= (int **)malloc(hang*sizeof(int));
	for (int i=0;i<mt.hang;i++){
		mt.data[i]=(int *)malloc(cot*sizeof(int));
	}
}
MT operator + (MT a,MT b){
	MT tong;
	tong.cot= a.cot;
	tong.hang=a.hang;
	capphat(tong);
	for (int i=0;i<a.hang;i++){
		for (int j=0;j<a.cot;j++){
			
		}
	}
	return tg;
}
void display(SP a){
	printf("so phuc do la : %f.i + %f",a.ao,a.thuc);
}
int main()
{
	SP a,b,tong;
	a.thuc = 5;
	a.ao=6;
	b.thuc=10;
	b.ao=11;
	printf("\nTong cua so phuc: ");
	display(a);
	printf("\nva so phuc: ");
	display(b);
	tong = a+b;
	display(tong);
	return 0;
}


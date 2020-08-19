#include<stdio.h>
struct sophuc
{
	float phanthuc;
	float phanao;
};
int main()
{
	struct sophuc sp1,sp2;
	printf("nhap phan thuc cho so phuc 1\n");
	scanf("%f",&sp1.phanthuc);
	printf("nhap phan ao cho so thuc 1\n");
	scanf("%f",&sp1.phanao);
	printf("so phuc da nhap la %f + i.%f",sp1.phanthuc,sp1.phanao);
	return 0;
}

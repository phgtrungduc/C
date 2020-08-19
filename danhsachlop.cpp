#include<stdio.h>
struct lopsinhvien
{
	char ten[100];
	int diem,tuoi;
};
int main()
{
	int n,i;
	printf("Nhap so sinh vien can: ");
	scanf("%d",&n);
	struct lopsinhvien sv[n];
	for (i=0;i<n;i++)
	{
		printf("Nhap thong tin sinh vien thu %d",i+1);
		printf("\nNhap ten sinh vien thu %d: ",i+1);
		fflush(stdin);
		gets(sv[i].ten);
		fflush(stdin);
		printf("\nNhap tuoi sinh vien thu %d: ",i+1);
		scanf("%d",&sv[i].tuoi);
		fflush(stdin);
		printf("\nNhap diem sinh vien thu %d: ",i+1);
		scanf("%d",&sv[i].diem);
		fflush(stdin);
	}
	printf("============DANH SACH SINH VIEN================");
	printf("\nHO VA TEN           TUOI          DIEM");
	printf("\n");
	for (i=0;i<n;i++)
	{
		printf("%-24s %-19f %d\n",sv[i].ten,sv[i].diem,sv[i].tuoi);
	}
	return 0;
}

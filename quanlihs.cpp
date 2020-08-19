#include <stdio.h>
#include <conio.h>
#include <string.h>


int main()
{
	typedef struct
	{
		char Hoten[40];
		float Diem;
		char Loai[10];
	} Hoso;
	Hoso hs[30];
	int n;
	printf("Nhap so hoc sinh:");
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		printf("HOC SINH THU %d:",i+1);
		printf("\nNhap ten hoc sinh:");
		gets(hs[i].Hoten);
		do{
			printf("\nNhap diem hoc sinh:");
			scanf("%f",&hs[i].Diem);
		}
		while (hs[i].Diem<0 || hs[i].Diem>10);
		if (hs[i].Diem < 5.0) strcpy(hs[i].Loai,"Khong dat");
			if (hs[i].Diem <= 6.0) strcpy(hs[i].Loai,"Trung binh");
				if (hs[i].Diem <= 8.0) strcpy(hs[i].Loai,"Kha");
					if (hs[i].Diem <= 10.0) strcpy(hs[i].Loai,"Gioi");
	}
	printf("\n            XEP LOAI VAN HOA");
	printf("\n  HO VA TEN        DIEM        XEP LOAI");
	for (int i=0; i<n; i++)
		printf("\n%c-19.%f-31.%c",hs[i].Hoten,hs[i].Diem,hs[i].Loai);
	return 0;
}

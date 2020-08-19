#include<stdio.h>
#include<string.h>
struct Hoso
{
	char HoTen[40];
	float Diem;
	char Loai[20];
};
int main()
{
	int i,n;
	printf("nhap so hoc sinh: ");
	scanf("%d",&n);
	struct Hoso hs[n];
	for (i=0;i<n;i++)
	{
		printf("nhap ten cua hoc sinh thu %d: \n",i+1);
		fflush(stdin);
		gets(hs[i].HoTen);
		printf("nhap tdiem cua hoc sinh thu %d: \n",i+1);
		scanf("%f",&hs[i].Diem);
	}
	for (i=0;i<n;i++)
	{
		if((hs[i].Diem==9)||(hs[i].Diem==10)) strcpy(hs[i].Loai,"Gioi");
		else if((hs[i].Diem==8)||(hs[i].Diem==7)) strcpy(hs[i].Loai,"Kha");
		else if((hs[i].Diem==6)||(hs[i].Diem==5)) strcpy(hs[i].Loai,"Trung binh");
		else strcpy(hs[i].Loai,"k dat");
	}
		printf("=============XEP LOAI VAN HOA===============\n");
		printf("HO VA TEN                DIEM                LOAI\n");
		for(i=0;i<n;i++)	
		{
		printf("%-24s %-19f %s\n",hs[i].HoTen,hs[i].Diem,hs[i].Loai);
	    }

	return 0;
	
}

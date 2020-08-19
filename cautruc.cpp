#include <stdio.h>
struct Hoso
{
    char HoTen[40];
    float Diem;
    char Loai[10];
};
int main()
{
Hoso cac;
float k;
printf("nhap ten\n");
gets(cac.HoTen);
printf("nhap diem \n");
scanf("%f",&cac.Diem);
/*k= cac.Diem;
if (k==9||k==10) cac.Loai = 'Gioi';
if (k==8||k==7) cac.Loai = 'Kha';
if (k==6||k==5) cac.Loai = 'TB';
else cac.Loai= 'k dat';*/
printf("                XEP LOAI VAN HOA                    \n");
printf("HO VA TEN            DIEM           XEP LOAI\n");
printf("%-20c %-10f %-10f",cac.HoTen,cac.Diem,cac.Loai );
return 0;
}

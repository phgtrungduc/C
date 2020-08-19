#include <stdio.h>
#include <conio.h>
 
int main()
{
    float a, b, c;
    int isTriangle = 1;
    do
    {
        printf("\nNhap a: ");
        scanf("%f", &a);
        printf("\nNhap b: ");
        scanf("%f", &b);
        printf("\nNhap c: ");
        scanf("%f", &c);
    }
    while (a <= 0 || b <= 0 || c <= 0);
 
    if((a + b <= c) || (a + c <= b) || (b + c <= a))
        isTriangle = 0;
 
    if(isTriangle==1)
        printf("\nDay la tam giac");
    else
        printf("\nDay khong phai la tam giac");
    return 0;
}

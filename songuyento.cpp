#include<stdio.h>
#include<math.h>
int main()
{
int n,i,k=0;
printf("nhap n: ");
scanf("%d",&n);
for(i=2;i<sqrt(n);i++)
{
	if(n%i==0) 
	{
		k=1;
		break;
	}
	else k=0;
}
if (k==1) printf("n khong phai la so nguyen to");
else printf("n la so nguyen to");
return 0;
}

